import axios from 'axios';
import Device from 'class/Device';

export default class Api {

	/**
	 * Конструктор
	 */
	constructor(attributes) {
		_.each(attributes, (value, key) => {
			this[key] = value;
		});
	}

	/**
	 * Выполнение запроса к api
	 */
	request(config) {
		return axios.request(_.merge({
			baseURL: this.baseUrl,
			method: 'get',
		    responseType: 'json',
		    headers: {
		        'Accept': 'application/json',
		        'Content-Type': 'application/json'
		    }
		}, config));
	}

	/**
	 * Выполнение GET запроса
	 */
	get(url) {
		return this.request({ url });
	}

	/**
	 * Выполнение POST запроса
	 */
	post(url, data) {
		return this.request({ url, data, method: 'post' });
	}

	/**
	 * Получение списка устройств
	 */
	getDevices() {
		return this.get('device')
			.then(({ data }) => {
				return _.map(data, attributes => new Device(attributes));
			});
	}

	/**
	 * Получение параметров конкретного устройства по его идентификатору
	 */
	getDevice(id) {

		id = parseInt(id);

		return this.getDevices()
			.then(devices => {
				return _.find(devices, { id });
			});
	}

	/**
	 * Получение списка датчиков
	 */
	getSensors() {
		return this.get('sensor')
			.then(({ data }) => data);
	}

	/**
	 * Получение текущих данных конкретного датчика
	 */
	getSensorCurrent(device, sensor) {

		const device_id = device.id;
		const sensor_id = sensor.id;

		return this.get('/data/' + device_id + '/' + sensor_id)
			.then(({ data }) => {
				return _.merge({ device_id, sensor_id }, _.first(data));
			});
	}

	/**
	 * Получение статистики за промежуток времени по конкретному датчику
	 */
	getSensorStat(device, sensor) {

		const device_id = device.id;
		const sensor_id = sensor.id;

		return this.get('/data_all/' + device_id + '/' + sensor_id)
			.then(({ data }) => {

				data = _.castArray(data);

				data = _.filter(data, item => {
					return !! item.date_add;
				});

				data = _.map(data, item => {
					return _.merge({ device_id, sensor_id }, item);
				});

				return data;
			});
	}

	/**
	 * Изменить наименование устройства
	 */
	setName(device, { name }) {

		const device_id = device.id;
		const comment = device.comment;

		return this.post('/device/' + device_id, { name, comment })
			.then(response => {
				device.name = name;
				return response;
			});
	}

	/**
	 * Изменить комментарий к устройству
	 */
	setComment(device, { comment }) {

		const device_id = device.id;
		const name = device.name_owner;
		
		return this.post('/device/' + device_id, { name, comment })
			.then(response => {
				device.comment = comment;
				return response;
			});
	}

	setIndicator(device, { type, value }) {
		return Promise.resolve();
	}

};