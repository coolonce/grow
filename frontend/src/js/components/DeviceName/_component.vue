<template>
	<modal ref="modal" class="device-name-component" id="modal_change_name" title="Изменить название">
		<div class="element">
			<input v-model="name" type="text" placeholder="Введите название" required />
        </div>
        <button type="button" class="add_table" @click="submit">Сохранить</button>
	</modal>
</template>
<script type="text/javascript">
	export default {
		data() {
			return {
				device: null,
				name: null
			};
		},
		methods: {
			open(device) {
				this.device = device;
				this.$refs.modal.show();
			},
			close() {
				this.$refs.modal.hide();
			},
			submit() {

				const device = this.device;
				const name = this.name;
				
				api.setName(device, { name })
					.then(response => {
						this.close();
					});
			}
		}
	};
</script>