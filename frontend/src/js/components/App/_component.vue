<template>
	<div class="application-component">
		<router-view />
	</div>
</template>
<script type="text/javascript">
	export default {
		mounted() {

			$('body').on('mousewheel', '.table_box .table_content', function(e) {
				this.scrollLeft -= (e.originalEvent.wheelDelta / 120 * 231);
				e.preventDefault();
			});

			$('body').on('click', '.table_box .slide_right', function(e) {
				$(this).closest('.table_content').animate({
		            scrollLeft: '+=231'
		        }, 600);
			});
		}
	};
</script>