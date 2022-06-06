package xyz.hsinyuwang.cloud.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import xyz.hsinyuwang.cloud.domain.AjaxResult;
import xyz.hsinyuwang.cloud.domain.entity.SysUser;
import xyz.hsinyuwang.cloud.page.TableDataInfo;
import xyz.hsinyuwang.cloud.service.ISysUserService;

/**
 * 用户Controller
 *
 * @author hsinyuwang
 * @date 2022-05-28
 */
@RestController
@RequestMapping("/user")
public class SysUserController extends BaseController {
    @Autowired
    private ISysUserService sysUserService;

    /**
     * 查询用户列表
     */
    @GetMapping("/list")
    public TableDataInfo list(SysUser sysUser) {
        if (!getLoginUser().getParentId().equals(0L)) {
            sysUser.setParentId(getUserId());
        }
        startPage();
        List<SysUser> list = sysUserService.selectSysUserList(sysUser);
        return getDataTable(list);
    }

    /**
     * 获取用户详细信息
     */
    @GetMapping(value = "/{userId}")
    public AjaxResult getInfo(@PathVariable("userId") Long userId) {
        return AjaxResult.success(sysUserService.selectSysUserByUserId(userId));
    }

    /**
     * 新增用户
     */
    @PostMapping
    public AjaxResult add(@RequestBody SysUser sysUser) {
        sysUser.setParentId(getUserId());
        return toAjax(sysUserService.insertSysUser(sysUser));
    }

    /**
     * 修改用户
     */
    @PutMapping
    public AjaxResult edit(@RequestBody SysUser sysUser) {
        return toAjax(sysUserService.updateSysUser(sysUser));
    }

    /**
     * 删除用户
     */
    @DeleteMapping("/{userIds}")
    public AjaxResult remove(@PathVariable Long[] userIds) {
        return toAjax(sysUserService.deleteSysUserByUserIds(userIds));
    }
}
