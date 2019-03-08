<template>
	<div class="modal modal-component">
		<div class="close_modal" @click="hide">
			<img src="/img/close_modal.png" alt="">
		</div>
        <div class="title">
        	<span>{{ title }}</span>
        </div>
        <div class="modal_content">
        	<slot></slot>
        </div>
	</div>
</template>
<script type="text/javascript">
	export default {
		props: {
			title: String
		},
		data() {
			return {
				overlay: $('<div class="overlay" />')
			};
		},
		methods: {
			show() {

				const $el = $(this.$el);
				const $overlay = this.overlay;

				$overlay.fadeIn(400, function() {
		            $el.show().animate({ opacity: 1 });
		        });
			},
			open() {
				this.show();
			},
			hide() {

				const $el = $(this.$el);
				const $overlay = this.overlay;

				$el.animate({ opacity: 0 }, function() {
		        	$el.hide();
		            $overlay.fadeOut(400);
		        });
			},
			close() {
				this.hide();
			}
		},
		mounted() {

			$('body').append( this.overlay );

			this.overlay.on('click', this.hide);
		}
	};
</script>