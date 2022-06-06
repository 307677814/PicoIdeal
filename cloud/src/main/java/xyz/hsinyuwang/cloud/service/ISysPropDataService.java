package xyz.hsinyuwang.cloud.service;

import com.alibaba.fastjson.JSONObject;
import xyz.hsinyuwang.cloud.domain.model.PropData;

import java.util.List;

public interface ISysPropDataService {

    public boolean handleDeviceData(Long deviceSn, Long protocolId, JSONObject jsonObject);

    public List<PropData> list(Long deviceSn);
}
