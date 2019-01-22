<template>
	<modal ref="modal" class="device-indicator-component" id="modal" :title="title">
		<div class="element">
            <span>Показатель:</span>
            <input v-model="value" type="text" required />
        </div>
        <div class="element">
            <span>Устройство:</span>
            <selector v-model="device_id" :options="devices"></selector>
        </div>
        <div class="element">
            <button type="button" class="add_table" @click="submit">Добавить</button>
        </div>
	</modal>
</template>
<script type="text/javascript">
	export default {
		props: {
			devices: Array
		},
		data() {
			return {
				value: null,
				type: 'ph',
				device_id: null
			};
		},
		watch: {
			devices(devices) {
				if (! _.find(devices, { id: this.device_id })) {
					this.device_id = _.get(_.first(devices), 'id');
				}
			}
		},
		computed: {
			title() {
				return this.type == 'ph' ? 'Уровень PH' : 'Уровень TDS';
			}
		},
		methods: {
			open(type) {
				this.type = type;
				this.$refs.modal.show();
			},
			close() {
				this.$refs.modal.hide();
			},
			submit() {

				const device = this.device;
				const type = this.type;
				const value = this.value;
				
				api.setIndicator(device, { type, value })
					.then(response => {
						this.close();
					});
			}
		}
	};
</script>