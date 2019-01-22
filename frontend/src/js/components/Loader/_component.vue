<template>
	<div class="preloader"></div>
</template>
<script type="text/javascript">
	export default {
		methods: {
			show() {
				$(this.$el).fadeIn('slow');
			},
			open() {
				this.show();
			},
			hide() {
				$(this.$el).fadeOut('slow');
			},
			close() {
				this.hide();
			}
		}
	};
</script>