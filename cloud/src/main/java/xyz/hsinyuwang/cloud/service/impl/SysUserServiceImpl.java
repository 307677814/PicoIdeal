package xyz.hsinyuwang.cloud.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import xyz.hsinyuwang.cloud.domain.entity.SysUser;
import xyz.hsinyuwang.cloud.mapper.SysUserMapper;
import xyz.hsinyuwang.cloud.service.ISysUserService;
import xyz.hsinyuwang.cloud.utils.MD5Utils;

/**
 * 用户Service业务层处理
 *
 * @author hsinyuwang
 * @date 2022-05-28
 */
@Service
public class SysUserServiceImpl implements ISysUserService {
    @Autowired
    private SysUserMapper sysUserMapper;

    /**
     * 查询用户
     *
     * @param userId 用户主键
     * @return 用户
     */
    @Override
    public SysUser selectSysUserByUserId(Long userId) {
        return sysUserMapper.selectSysUserByUserId(userId);
    }

    /**
     * 查询用户
     *
     * @param userName 用户名称
     * @return 用户
     */
    public SysUser selectSysUserByUserName(String userName) {
        return sysUserMapper.selectSysUserByUserName(userName);
    }

    /**
     * 查询用户列表
     *
     * @param sysUser 用户
     * @return 用户
     */
    @Override
    public List<SysUser> selectSysUserList(SysUser sysUser) {
        return sysUserMapper.selectSysUserList(sysUser);
    }

    /**
     * 新增用户
     *
     * @param sysUser 用户
     * @return 结果
     */
    @Override
    public int insertSysUser(SysUser sysUser) {
        sysUser.setPassword(MD5Utils.getMD5Str(sysUser.getPassword()));
        return sysUserMapper.insertSysUser(sysUser);
    }

    /**
     * 修改用户
     *
     * @param sysUser 用户
     * @return 结果
     */
    @Override
    public int updateSysUser(SysUser sysUser) {
        sysUser.setPassword(MD5Utils.getMD5Str(sysUser.getPassword()));
        return sysUserMapper.updateSysUser(sysUser);
    }

    /**
     * 批量删除用户
     *
     * @param userIds 需要删除的用户主键
     * @return 结果
     */
    @Override
    public int deleteSysUserByUserIds(Long[] userIds) {
        return sysUserMapper.deleteSysUserByUserIds(userIds);
    }

    /**
     * 删除用户信息
     *
     * @param userId 用户主键
     * @return 结果
     */
    @Override
    public int deleteSysUserByUserId(Long userId) {
        return sysUserMapper.deleteSysUserByUserId(userId);
    }
}
