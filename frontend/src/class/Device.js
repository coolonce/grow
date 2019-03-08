export default class Device {
	
	/**
	 * Конструктор
	 */
	constructor(attributes) {
		this.fill(
			_.merge(this.defaults(), attributes)
		);
	}

	/**
	 * Наименование устройства
	 */
	get label() {
		return 'Устройство #' + this.id;
	}

	/**
	 * Атрибуты по умолчанию
	 */
	defaults() {
		return {
			id: 0,
			date_buy: null,
			name_owner: null,
			sensors: [],
			version: null,
			comment: null
		};
	}

	/**
	 * Заполнение атрибутов
	 */
	fill(attributes) {
		_.each(attributes, (value, key) => {
			if (_.isArray(this[key])) {
				this[key].splice(0);
                _.each( _.isObject(value) ? _.values(value) : _.castArray(value), item => {
                    this[key].push(item);
                });
			} else if (_.isObject(this[key])) {
				_.merge(this[key], value);
			} else {
				this[key] = value;
			}
		});
	}

	/**
	 * Получение атрибутов устройства по его идентификатору
	 */
	fetch(id) {
		return api.getDevice(id)
			.then(attributes => {

				this.fill(attributes);

				return this;
			});
	}
};