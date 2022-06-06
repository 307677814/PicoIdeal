import Vue from 'vue'
import App from './App.vue'
import router from './router'
import store from './store'
import modal from './plugins/modal'
import './plugins/element.js'
import Pagination from "@/components/Pagination";
import { resetForm } from "@/utils/picoIdeal";
import * as echarts from 'echarts'

Vue.component('PaginationTool', Pagination)

Vue.config.productionTip = false
Vue.prototype.$modal = modal
Vue.prototype.resetForm = resetForm
Vue.prototype.echarts = echarts

new Vue({
  router,
  store,
  render: h => h(App)
}).$mount('#app')
