export default {
	updated() {

		this.$nextTick(() => {

			const $el = $(this.$el);

			if (! $el.length) {
				return;
			}

			$( '.table_box .left_column .row', $el ).each((index, item) => {

				const $item = $(item);
				const $rows = $( '.table_box .table_content .column', $el ).map(function() {
					return $( '.row:eq(' + index + ')', this );
				});
				const $rowHeights = $rows.map(function() {
					return $(this).height();
				});
				const height = _.max([$item.height(), _.max($rowHeights)]);

				$item.height(height);
				$rows.each(function() {
					$(this).height(height);
				});
			});

		});

	}
};