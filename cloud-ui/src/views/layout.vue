<template>
  <el-container>
    <el-header>
      <HeaderTitle></HeaderTitle>
      <HeaderMenu></HeaderMenu>
    </el-header>
    <el-container>
      <AsideMenu></AsideMenu>
      <el-main>
        <Breadcrumb> </Breadcrumb>
        <transition name="fade-transform" mode="out-in">
          <router-view />
        </transition>
      </el-main>
    </el-container>
  </el-container>
</template>

<script>
import HeaderTitle from "@/components/HeaderTitle";
import HeaderMenu from "@/components/HeaderMenu";
import AsideMenu from "@/components/AsideMenu";
import Breadcrumb from "@/components/Breadcrumb";
export default {
  name: "LaoutView",
  components: { HeaderTitle, HeaderMenu, AsideMenu, Breadcrumb },
  data() {
    return {};
  },
  created() {
  },
  methods: {},
};
</script>

<style scoped>
.el-container {
  height: 100%;
}
.el-header {
  background-color: #333333;
  color: #ffffff;
  line-height: 60px;
}
.el-main {
  padding: 0;
  overflow-x: hidden;
}
</style>