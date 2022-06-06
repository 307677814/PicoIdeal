package xyz.hsinyuwang.cloud.controller;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import xyz.hsinyuwang.cloud.domain.AjaxResult;
import xyz.hsinyuwang.cloud.domain.entity.SysCollection;
import xyz.hsinyuwang.cloud.domain.entity.SysDevice;
import xyz.hsinyuwang.cloud.domain.model.QueryData;
import xyz.hsinyuwang.cloud.redis.RedisCache;
import xyz.hsinyuwang.cloud.service.ISysCollectionService;
import xyz.hsinyuwang.cloud.service.ISysDeviceService;
import xyz.hsinyuwang.cloud.service.ISysPropDataService;

import java.util.ArrayList;
import java.util.List;

@RestController
@RequestMapping("/propData")
public class SysPropDataController {

    @Autowired
    private RedisCache redisCache;

    @Autowired
    private ISysPropDataService sysPropDataService;

    @Autowired
    private ISysDeviceService sysDeviceService;

    @Autowired
    private ISysCollectionService sysCollectionService;

    @GetMapping("/list/{deviceSn}")
    public AjaxResult list(@PathVariable("deviceSn") Long deviceSn) {

        return AjaxResult.success(sysPropDataService.list(deviceSn));
    }

    @PostMapping("/history")
    public AjaxResult list(@RequestBody QueryData queryData) {
        List<SysCollection> collections = new ArrayList<>();
        SysDevice sysDevice = sysDeviceService.selectSysDeviceByDeviceSn(queryData.getDeviceSn());
        if (sysDevice == null) {
            return AjaxResult.success(collections);
        }
        collections = sysCollectionService.selectHistoryDataList(queryData);
        return AjaxResult.success(collections);
    }
}
