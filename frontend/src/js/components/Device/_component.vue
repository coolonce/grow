<template>
	<div class="device-component">

		<loader ref="loader"></loader>

		<header>
	        <div class="container">
	            <div class="title">
	                <h1 class="h1">Статистика: <span>{{ device.label }} ({{ device.name_owner }})</span></h1>
	                <div class="close_statistic" @click="back">
	                    <img class="normal" src="/img/close_statistic.png" alt="">
	                    <img class="hover" src="/img/close_statistic_hover.png" alt="">
	                </div>
	            </div>
	        </div>
	    </header>

	    <section class="statistics">
	        <div class="container">
	            <div class="statistics_change">
	                <div class="element">
	                    <span>Ч-сть обновления данных:</span>
	                    <selector v-model="filter.update" :options="dictionary.update"></selector>
	                </div>
	                <div class="element">
	                    <span>Ч-сть полива линии 1:</span>
	                    <selector v-model="filter.line1" :options="dictionary.line"></selector>
	                </div>
	                <div class="element">
	                    <span>Ч-сть полива линии 2:</span>
	                    <selector v-model="filter.line2" :options="dictionary.line"></selector>
	                </div>
	                <div class="element">
	                    <span>Ч-сть фотографирования:</span>
	                    <selector v-model="filter.photo" :options="dictionary.photo"></selector>
	                </div>
	                <div class="element">
	                    <span>культура 1:</span>
	                    <input v-model="filter.culture1" type="text">
	                </div>
	                <div class="element">
	                    <span>культура 2:</span>
	                    <input v-model="filter.culture2" type="text">
	                </div>
	                <div class="element">
	                    <span>сорт 1:</span>
	                    <input v-model="filter.sort1" type="text">
	                </div>
	                <div class="element">
	                    <span>сорт 2:</span>
	                    <input v-model="filter.sort2" type="text">
	                </div>
	            </div>
	        </div>
	    </section>

	    <section class="main main_statistics">
	        <div class="container">
	            <div class="table">
	                <div class="table_box">
	                    <div class="left_column table_item">
	                        <div class="row">Время/Дата/День:</div>
	                        <div v-for="sensor in sensors" class="row">
	                        	{{ sensor.name }}
	                        </div>
	                        <div class="row">Фото:</div>
	                        <div class="row">Комментарий:</div>
	                    </div>
	                    <div class="table_content table_item">
	                        <div v-for="date in dates" class="column">
	                            <div class="row">
	                                {{ date }}
	                            </div>
	                            <div v-for="sensor in sensors" class="row text_center" v-loading="!hasSensorValue(sensor, date)">
	                            	{{ getSensorValue(sensor, date) }}
	                            </div>
	                            <div class="row">
	                                <a href="/img/img1.jpg" data-fancybox="gallery" class="image_overlay">
	                                    <img src="/img/img1.jpg" alt="">
	                                </a>
	                            </div>
	                            <div class="row">
	                                <p class="comment_text">
	                                    {{ device.comment }}
	                                </p>
	                            </div>
	                        </div>
	                        <button type="button" class="arrow slide_right">
	                        	<img src="/img/arrow_right.png" alt="">
	                        </button>
	                    </div>
	                </div>
	            </div>
	        </div>
	    </section>

	</div>
</template>
<script type="text/javascript">
	import Device from 'class/Device';
	import { DateTime } from 'luxon';

	export default {
		props: {
			id: {
				default: 0
			}
		},
		data() {
			return {
				dictionary: {
					update: _.map(_.range(1, 6), value => {
						return 'Показатель ' + value;
					}),
					line: _.map(_.range(1, 6), value => {
						return 'Показатель ' + value;
					}),
					photo: _.map(_.range(1, 6), value => {
						return 'Показатель ' + value;
					})
				},
				filter: {
					update: null,
					line1: null,
					line2: null,
					photo: null,
					culture1: null,
					culture2: null,
					sort1: null,
					sort2: null
				},
				device: new Device(),
				data: []
			};
		},
		computed: {
			sensors() {
				return this.device.sensors;
			},
			dates() {
				return _.sortBy(_.uniq(_.map(this.data, 'date_add')));
			}
		},
		methods: {
			back() {
				this.$router.push({ name: 'home' });
			},
			getSensorValue(sensor, date_add) {
				return _.get(_.find(this.data, { sensor_id: sensor.id, date_add }), 'data');
			},
			hasSensorValue(sensor, date_add) {
				return _.findIndex(this.data, { sensor_id: sensor.id, date_add }) > -1;
			},
			loadSensorsData() {

				this.data.splice(0);

				Promise.all(
					_.map(this.sensors, sensor => {
						return api.getSensorStat(this.device, sensor)
							.then(data => {
								_.each(data, item => {
									this.data.push(_.merge(item, {
										date_add: DateTime.fromHTTP(item.date_add).toFormat('dd.MM.yyyy')
									}));
								});
							});
					})
				).then(results => {

					this.data = _.uniqBy(this.data, item => item.sensor_id + '_' + item.date_add);

					_.each(this.sensors, sensor => {
						_.each(this.dates, date_add => {
							if (! this.hasSensorValue(sensor, date_add)) {
								this.data.push({
									device_id: this.device.id,
									sensor_id: sensor.id,
									data: null,
									date_add
								});
							}
						});
					});
				});
			}
		},
		mounted() {

			this.$refs.loader.show();

			this.device.fetch(this.id)
				.then(device => {
					this.$refs.loader.hide();
					this.loadSensorsData();
				});
		}
	};
</script>