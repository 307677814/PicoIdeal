package xyz.hsinyuwang.cloud.service.impl;

import com.alibaba.fastjson.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import xyz.hsinyuwang.cloud.domain.AjaxResult;
import xyz.hsinyuwang.cloud.domain.entity.SysCollection;
import xyz.hsinyuwang.cloud.domain.entity.SysDevice;
import xyz.hsinyuwang.cloud.domain.entity.SysProperty;
import xyz.hsinyuwang.cloud.domain.model.PropData;
import xyz.hsinyuwang.cloud.mapper.SysCollectionMapper;
import xyz.hsinyuwang.cloud.mapper.SysDeviceMapper;
import xyz.hsinyuwang.cloud.mapper.SysPropertyMapper;
import xyz.hsinyuwang.cloud.redis.RedisCache;
import xyz.hsinyuwang.cloud.service.ISysPropDataService;
import xyz.hsinyuwang.cloud.utils.DateUtils;
import xyz.hsinyuwang.cloud.utils.PropertyUtils;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

@Service
public class SysPropDataServiceImpl implements ISysPropDataService {

    @Autowired
    private RedisCache redisCache;

    @Autowired
    private SysPropertyMapper sysPropertyMapper;

    @Autowired
    private SysDeviceMapper sysDeviceMapper;

    @Autowired
    private SysCollectionMapper sysCollectionMapper;

    @Override
    public boolean handleDeviceData(Long deviceSn, Long protocolId, JSONObject jsonObject) {
        SysProperty sysProperty = new SysProperty();
        sysProperty.setProtocolId(protocolId);
        List<SysProperty> sysProperties = sysPropertyMapper.selectSysPropertyList(sysProperty);
        if (sysProperties == null) {
            return false;
        }
        List<PropData> propDataList = new ArrayList<>();
        for (SysProperty property : sysProperties) {
            Object value = PropertyUtils.getValue(property, jsonObject);
            if (value != null) {
                PropData propData = new PropData();
                propData.setPropertyKey(property.getPropertyKey());
                propData.setPropertyName(property.getPropertyName());
                propData.setPropertyValue(value);
                propData.setUnit(property.getUnit());
                propData.setCollectionTime(DateUtils.getNowDate());
                propDataList.add(propData);
            } else {
                return false;
            }
        }
        redisCache.setCacheObject("prop_data:" + deviceSn.toString(), propDataList, 10, TimeUnit.MINUTES);
        sysCollectionMapper.insertSysCollection(new SysCollection(deviceSn, jsonObject.toJSONString(), DateUtils.getNowDate()));
        return true;
    }

    @Override
    public List<PropData> list(Long deviceSn) {
        List<PropData> propDataList = new ArrayList<>();
        SysDevice sysDevice = sysDeviceMapper.selectSysDeviceByDeviceSn(deviceSn);
        if (sysDevice == null) {
            return propDataList;
        }
        List<PropData> result = redisCache.getCacheObject("prop_data:" + deviceSn.toString());
        if (result != null) {
            return result;
        }
        SysProperty sysProperty = new SysProperty();
        sysProperty.setProtocolId(sysDevice.getProtocolId());
        List<SysProperty> sysProperties = sysPropertyMapper.selectSysPropertyList(sysProperty);
        if (sysProperties == null) {
            return propDataList;
        }
        for (SysProperty property : sysProperties) {
            PropData propData = new PropData();
            propData.setPropertyKey(property.getPropertyKey());
            propData.setPropertyName(property.getPropertyName());
            propData.setPropertyValue("--");
            propData.setUnit(property.getUnit());
            propData.setCollectionTime(DateUtils.getNowDate());
            propDataList.add(propData);
        }
        return propDataList;
    }
}
