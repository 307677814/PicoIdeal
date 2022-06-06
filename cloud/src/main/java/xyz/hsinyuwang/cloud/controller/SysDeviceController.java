package xyz.hsinyuwang.cloud.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import xyz.hsinyuwang.cloud.domain.AjaxResult;
import xyz.hsinyuwang.cloud.domain.entity.SysDevice;
import xyz.hsinyuwang.cloud.domain.entity.SysProtocol;
import xyz.hsinyuwang.cloud.page.TableDataInfo;
import xyz.hsinyuwang.cloud.service.ISysDeviceService;
import xyz.hsinyuwang.cloud.service.ISysProtocolService;
import xyz.hsinyuwang.cloud.utils.StringUtils;

import java.util.List;

/**
 * 设备Controller
 *
 * @author hsinyuwang
 * @date 2022-05-28
 */
@RestController
@RequestMapping("/device")
public class SysDeviceController extends BaseController {

    @Autowired
    private ISysDeviceService sysDeviceService;

    @Autowired
    private ISysProtocolService sysProtocolService;

    /**
     * 查询设备列表
     */
    @GetMapping("/list")
    public TableDataInfo list(SysDevice sysDevice) {
        if (!getLoginUser().getParentId().equals(0L)) {
            sysDevice.setUserId(getUserId());
        }
        startPage();
        List<SysDevice> list = sysDeviceService.selectSysDeviceList(sysDevice);
        return getDataTable(list);
    }

    /**
     * 获取设备详细信息
     */
    @GetMapping(value = {"/", "/{deviceId}"})
    public AjaxResult getInfo(@PathVariable(value = "deviceId", required = false) Long deviceId) {
        AjaxResult ajax = new AjaxResult();
        SysProtocol sysProtocol = new SysProtocol();
        if (!getLoginUser().getParentId().equals(0L)) {
            sysProtocol.setUserId(getUserId());
        }
        ajax.put("protocols", sysProtocolService.selectSysProtocolList(sysProtocol));
        if (StringUtils.isNotNull(deviceId)) {
            ajax.put(AjaxResult.DATA_TAG, sysDeviceService.selectSysDeviceByDeviceId(deviceId));
        }
        return ajax;
    }

    /**
     * 新增设备
     */
    @PostMapping
    public AjaxResult add(@RequestBody SysDevice sysDevice) {
        sysDevice.setUserId(getUserId());
        return toAjax(sysDeviceService.insertSysDevice(sysDevice));
    }

    /**
     * 修改设备
     */
    @PutMapping
    public AjaxResult edit(@RequestBody SysDevice sysDevice) {
        return toAjax(sysDeviceService.updateSysDevice(sysDevice));
    }

    /**
     * 删除设备
     */
    @DeleteMapping("/{deviceIds}")
    public AjaxResult remove(@PathVariable Long[] deviceIds) {
        return toAjax(sysDeviceService.deleteSysDeviceByDeviceIds(deviceIds));
    }
}
