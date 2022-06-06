<template>
  <div class="app-header-title">
    <img class="app-logo-img" src="@/assets/images/logo.gif" />
    <span class="app-header-text">PicoIdeal</span>
  </div>
</template>
<script>
export default {
  name: "HeaderTitle",
  data() {
    return {};
  },
};
</script>
<style scoped>
.app-header-title {
  display: flex;
  float: left;
}
.app-logo-img {
  height: 60px;
  width: 60px;
  margin-right: 10px;
}
.app-header-text {
  font-family: "Consolas";
  font-size: 22px;
}
</style>