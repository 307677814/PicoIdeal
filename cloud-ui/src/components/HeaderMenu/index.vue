<template>
  <el-dropdown class="app-header-menu" trigger="click">
    <span class="el-dropdown-link">
      {{ userInfo.userName }}<i class="el-icon-arrow-down el-icon--right"></i>
    </span>
    <el-dropdown-menu slot="dropdown">
      <!-- <el-dropdown-item><i class="el-icon-key"></i>
        <span>修改密码</span>
      </el-dropdown-item> -->
      <el-dropdown-item @click.native="handleLogout">
        <i class="el-icon-back"></i>
        <span>退出登录</span>
      </el-dropdown-item>
    </el-dropdown-menu>
  </el-dropdown>
</template>

<script>
import { logout, getInfo } from "@/api/login";
import { removeToken } from "@/utils/auth";
export default {
  name: "HeaderMenu",
  data() {
    return {
      userInfo: {
        userName: "",
      },
    };
  },
  created() {
    getInfo().then((response) => {
      this.userInfo = response.data;
    });
  },
  methods: {
    handleLogout() {
      logout().then(() => {
        removeToken();
        location.href = "/login";
        this.$modal.msgSuccess("退出成功");
      });
    },
  },
};
</script>

<style scoped>
.app-header-menu {
  float: right;
}

.el-dropdown-link {
  cursor: pointer;
  color: #ffffff;
}
</style>