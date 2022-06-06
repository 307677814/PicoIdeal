package xyz.hsinyuwang.cloud.controller;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;
import xyz.hsinyuwang.cloud.domain.AjaxResult;
import xyz.hsinyuwang.cloud.domain.entity.SysUser;
import xyz.hsinyuwang.cloud.domain.model.LoginUser;
import xyz.hsinyuwang.cloud.service.ISysUserService;
import xyz.hsinyuwang.cloud.utils.BaseUserInfo;
import xyz.hsinyuwang.cloud.utils.MD5Utils;
import xyz.hsinyuwang.cloud.utils.TokenUtils;

@RestController
public class SysLoginController extends BaseController {

    @Autowired
    private TokenUtils tokenUtils;

    @Autowired
    private ISysUserService sysUserService;

    @PostMapping("/login")
    public AjaxResult login(@RequestBody SysUser sysUser) {
        String password = sysUser.getPassword();
        sysUser = sysUserService.selectSysUserByUserName(sysUser.getUserName());
        if (sysUser == null) {
            return AjaxResult.error("用户名不存在");
        }
        if (!sysUser.getPassword().equals(MD5Utils.getMD5Str(password))) {
            return AjaxResult.error("密码错误");
        }
        sysUser.setPassword("");
        return AjaxResult.success(tokenUtils.createToken(sysUser));
    }

    @PostMapping("/logout")
    public AjaxResult logout() {
        tokenUtils.delLoginUser(getLoginUser().getUuid());
        return AjaxResult.success(BaseUserInfo.get());
    }

    @PostMapping("/getInfo")
    public AjaxResult getInfo() {
        return AjaxResult.success(getLoginUser());
    }

}
