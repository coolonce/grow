require('./boot');

/**
 * Директивы
 */

import LoadingDirective from 'directives/loading';

Vue.directive('loading', LoadingDirective);

/**
 * Статические компоненты
 */

import Loader from 'components/Loader';
import Modal from 'components/Modal';
import Selector from 'components/Selector';
import DeviceComment from 'components/DeviceComment';
import DeviceName from 'components/DeviceName';
import DeviceIndicator from 'components/DeviceIndicator';

Vue.component('loader', Loader);
Vue.component('modal', Modal);
Vue.component('selector', Selector);
Vue.component('device-comment', DeviceComment);
Vue.component('device-name', DeviceName);
Vue.component('device-indicator', DeviceIndicator);

/**
 * Ресайзинг таблиц
 */

import TableMixin from 'mixins/table';

Vue.mixin(TableMixin);

/**
 * Роутинг
 */

import App from 'components/App';
import Home from 'components/Home';
import Device from 'components/Device';

const router = new VueRouter({
    mode: 'history',
    routes: [
		{
			path: '/device/:id',
			name: 'device',
			component: Device,
			props: true
		},
        {
        	path: '/',
        	name: 'home',
        	component: Home
        },
        {
            path: '*',
            redirect: '/'
        }
    ]
});

/**
 * Инициализация приложения
 */

const app = new Vue({
	el: '#app',
	template: '<App />',
	components: { App },
    router
});