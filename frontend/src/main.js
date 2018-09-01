// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
//import $ from './assets/other/libs/jquery/dist/jquery.min.js'
//import fancyBox from 'vue-fancybox';

require('./assets/other/css/main.css')
require('./assets/other/libs/fancybox-master/jquery.fancybox.min.css')


import Mousewheel from '../public/libs/jquery-mousewheel-master/jquery.mousewheel.min.js'
import Fancybox from '../public/libs/fancybox-master/jquery.fancybox.min.js'
import Common from '../public/js/common.js'

Vue.use(Fancybox)
Vue.use(Mousewheel)
Vue.use(Common)

Vue.config.productionTip = false

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  components: { App },
  template: '<App/>'
})
