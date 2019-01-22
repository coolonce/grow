<template>
	<div class="home-component">

		<loader ref="loader"></loader>

		<section class="main">
	        <div class="container">
	            <div class="table">
	                <div class="table_box">
	                    <div class="left_column table_item">
	                    	<div class="row">Название:</div>
	                    	<div v-for="sensor in sensors" class="row">
		                    	{{ sensor.name }}
		                    	<button v-if="sensor.id==5" type="button" class="measure" @click="showIndicator('ph')">Измерить</button>
		                    	<button v-if="sensor.id==6" type="button" class="measure" @click="showIndicator('tds')">Измерить</button>
		                    </div>
	                        <div class="row">Фото:</div>
	                        <div class="row">Комментарий:</div>
	                    </div>
	                    <div class="table_content table_item">
	                        <div v-for="device in devices" class="column">
	                            <div class="row">
	                                <button type="button" class="button top" @click="showName(device)">
	                                	<img src="/img/comment_img.png" alt="">
	                                </button>
	                                <a href="javascript:void(0)" class="button bottom" @click.prevent="show(device)">
	                                	<img src="/img/statistics_img.png" alt="">
	                                </a> {{ device.label }} ({{ device.name_owner }})
	                            </div>
	                            <div v-for="sensor in sensors" class="row text_center" v-loading="!hasSensorValue(device, sensor)">
	                            	{{ getSensorValue(device, sensor) }}
	                            </div>
	                            <div class="row">
	                                <a href="/img/img1.jpg" data-fancybox="gallery" class="image_overlay">
	                                    <img src="/img/img1.jpg" alt="">
	                                </a>
	                            </div>
	                            <div class="row">
	                                <button type="button" class="button top" @click="showComment(device)">
	                                	<img src="/img/comment_img.png" alt="">
	                                </button>
	                                <p class="comment_text">{{ device.comment }}</p>
	                            </div>
	                        </div>
	                        <button class="arrow slide_right">
	                        	<img src="/img/arrow_right.png" alt="">
	                        </button>
	                    </div>
	                </div>
	            </div>
	        </div>
	    </section>

	    <device-name ref="name"></device-name>
	    <device-comment ref="comment"></device-comment>
	    <device-indicator ref="indicator" :devices="devices"></device-indicator>

	</div>
</template>
<script type="text/javascript">
	export default {
		data() {
			return {
				devices: [],
				sensors: [],
				data: []
			};
		},
		computed: {
			deviceSensors() {
				return _.orderBy(_.uniqBy(_.flatten(_.map(this.devices, 'sensors')), 'id'), ['id', 'asc']);
			}
		},
		methods: {
			getSensorValue(device, sensor) {
				return _.get(_.find(this.data, { device_id: device.id, sensor_id: sensor.id }), 'data', null);
			},
			hasSensorValue(device, sensor) {
				return _.findIndex(this.data, { device_id: device.id, sensor_id: sensor.id }) > -1;
			},
			loadSensorsData() {

				this.data.splice(0);

				_.each(this.devices, device => {
					_.each(this.sensors, sensor => {
						if (_.find(device.sensors, { id: sensor.id })) {
							api.getSensorCurrent(device, sensor)
								.then(data => {
									this.data.push(data);
								});
						} else {
							this.data.push({
								device_id: device.id,
								sensor_id: sensor.id,
								data: null
							});
						}
					});
				});
			},
			show(device) {
				this.$router.push({ name: 'device', params: { id: device.id } });
			},
			showName(device) {
				this.$refs.name.open(device);
			},
			showComment(device) {
				this.$refs.comment.open(device);
			},
			showIndicator(type) {
				this.$refs.indicator.open(type);
			}
		},
		mounted() {

			this.$refs.loader.show();

			Promise.all([
				api.getDevices(),
				api.getSensors()
			]).then(results => {
				this.devices = results[0];
				this.sensors = results[1];
				this.$refs.loader.hide();
				this.loadSensorsData();
			});
		}
	};
</script>