/**
 * Babel polyfill for IE
 */

require('babel-polyfill');

/**
 * Lodash and Popper
 */

window._ = require('lodash');

/**
 * We'll load jQuery and the Bootstrap jQuery plugin which provides support
 * for JavaScript based Bootstrap features such as modals and tabs. This
 * code may be modified to fit the specific needs of your application.
 */

try {
    window.$ = window.jQuery = require('jquery');
} catch (e) {}

/**
 * We'll load the axios HTTP library which allows us to easily issue requests
 * to our Laravel back-end. This library automatically handles sending the
 * CSRF token as a header based on the value of the "XSRF" token cookie.
 */

window.axios = require('axios');

window.axios.defaults.headers.common['X-Requested-With'] = 'XMLHttpRequest';

/**
 * Fancybox
 */

require('@fancyapps/fancybox');
require('@fancyapps/fancybox/dist/jquery.fancybox.min.css');

/**
 * Register Vue in global
 */

window.Vue = require('vue');

/**
 * Vue routing
 */

import VueRouter from 'vue-router';

window.VueRouter = VueRouter;

Vue.use(VueRouter);

/**
 * Config
 */

import config from 'config';

window.config = config;

/**
 * Api
 */

import api from 'api';

window.api = api;