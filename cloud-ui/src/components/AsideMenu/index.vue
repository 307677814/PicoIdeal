<template>
  <el-aside :width="`${asideWidth}px`">
    <div class="app-aside-icon">
      <i :class="foldIcon" @click="handleOpenMenu"></i>
    </div>
    <el-menu
      class="app-aside-menu"
      :collapse="isCollapse"
      router
      :default-active="this.$route.path"
      :unique-opened="true"
    >
      <el-menu-item index="/">
        <i class="el-icon-s-promotion"></i>
        <span slot="title">首页</span>
      </el-menu-item>
      <el-submenu index="/system">
        <template slot="title">
          <i class="el-icon-s-operation"></i>
          <span>系统管理</span>
        </template>
        <el-menu-item index="/system/user">
          <i class="el-icon-user-solid"></i>
          <span slot="title">用户管理</span>
        </el-menu-item>
      </el-submenu>
      <el-submenu index="/product">
        <template slot="title">
          <i class="el-icon-s-marketing"></i>
          <span>产品管理</span>
        </template>
        <el-menu-item index="/product/protocol">
          <i class="el-icon-s-order"></i>
          <span slot="title">协议管理</span>
        </el-menu-item>
        <el-menu-item index="/product/device">
          <i class="el-icon-s-platform"></i>
          <span slot="title">设备管理</span>
        </el-menu-item>
      </el-submenu>
    </el-menu></el-aside
  >
</template>

<script>
export default {
  name: "AsideMenu",
  data() {
    return {
      isCollapse: false,
      foldIcon: "el-icon-s-fold",
      asideWidth: 200,
    };
  },
  methods: {
    handleOpenMenu() {
      if (this.isCollapse) {
        this.foldIcon = "el-icon-s-fold";
        this.asideWidth = 200;
      } else {
        this.foldIcon = "el-icon-s-unfold";
        this.asideWidth = 64;
      }
      this.isCollapse = !this.isCollapse;
    },
  },
};
</script>

<style scoped>
.el-aside {
  transition: width 0.3s;
  overflow-x: hidden;
  box-shadow: 5px 0 10px -5px #cccccc;
  z-index: 2;
}
.el-menu {
  border: 0;
}
.app-aside-icon {
  height: 60px;
  width: 64px;
  position: absolute;
  bottom: 0;
  line-height: 60px;
  text-align: center;
  font-size: 22px;
}
.app-aside-menu:not(.el-menu--collapse) {
  width: 200px;
}
</style>