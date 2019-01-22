<template>
	<modal ref="modal" class="device-comment-component" id="modal_comment" title="Комментарий">
		<div class="element">
            <textarea 
            	v-model="comment"
            	cols="30" 
            	rows="10" 
            	placeholder="Введите комментарий"
            	required 
        	></textarea>
        </div>
        <button type="button" class="add_table" @click="submit">Сохранить</button>
	</modal>
</template>
<script type="text/javascript">
	export default {
		data() {
			return {
				device: null,
				comment: null
			};
		},
		methods: {
			open(device) {
				this.device = device;
				this.comment = device.comment;
				this.$refs.modal.show();
			},
			close() {
				this.$refs.modal.hide();
			},
			submit() {

				const device = this.device;
				const comment = this.comment;
				
				api.setComment(device, { comment })
					.then(response => {
						this.close();
					});
			}
		}
	};
</script>