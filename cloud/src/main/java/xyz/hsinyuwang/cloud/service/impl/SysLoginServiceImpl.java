package xyz.hsinyuwang.cloud.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import xyz.hsinyuwang.cloud.domain.model.LoginUser;
import xyz.hsinyuwang.cloud.mapper.SysUserMapper;
import xyz.hsinyuwang.cloud.service.ISysLoginService;

@Service
public class SysLoginServiceImpl implements ISysLoginService {

    @Autowired
    private SysUserMapper sysUserMapper;

    @Override
    public String login(LoginUser loginUser) {

        return null;
    }
}
