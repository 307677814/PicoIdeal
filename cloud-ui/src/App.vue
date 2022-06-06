<template>
  <div id="app">
    <router-view />
  </div>
</template>

<script>
export default {
  name: "app",
};
</script>

<style>
@import "assets/styles/transition.scss";

html,
body,
#app {
  margin: 0;
  padding: 0;
  height: 100%;
  width: 100%;
}

.app-container {
  padding: 20px;
}

.el-table__header {
  margin-top: 20px;
}

.el-table__header th {
  background: #F8F8F9 !important;
  color: #000000 !important;
}

.el-menu--popup {
  min-width: 120px !important;
}

.el-form-item__label {
  font-weight: 600;
}
</style>
