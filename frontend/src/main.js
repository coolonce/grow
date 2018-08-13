// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import $ from './assets/other/libs/jquery/dist/jquery.min.js'
import Common from './assets/other/js/common.js'
import Fancybox from './assets/other/libs/fancybox-master/jquery.fancybox.min.js'
import Mousewhell from './assets/other/libs/jquery-mousewheel-master/jquery.mousewheel.min.js'

require('./assets/other/css/main.css')
require('./assets/other/libs/fancybox-master/jquery.fancybox.min.css')


Vue.use(Common)
Vue.config.productionTip = false

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
