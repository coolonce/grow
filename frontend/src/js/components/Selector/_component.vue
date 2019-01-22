<template>
	<div class="sort_select selector-component">
		<div class="sort_option" @click="openOrClose">
            <span class="text">{{ label }}</span>
            <span class="arrow">
            	<img src="/img/select_button.png" alt="">
            </span>
        </div>
        <ul ref="options" class="sort_options">
            <li v-for="item in items" @click="select(item)">{{ item.label }}</li>
        </ul>
	</div>
</template>
<script type="text/javascript">
	export default {
		model: {
			prop: 'value',
			event: 'input'
		},
		props: {
			options: Array,
			value: {
				default: null
			}
		},
		data() {
			return {
				opened: false
			};
		},
		computed: {
			label() {

				if (_.isObject(this.value)) {
					return _.get(this.value, 'label', this.value);
				}

				return _.get(_.isNull(this.value) ? _.first(this.items) : _.find(this.items, { id: this.value }), 'label', this.value);
			},
			items() {
				return _.map(this.options, item => {
					return _.isObject(item) ? item : { id: item, label: item };
				});
			}
		},
		methods: {
			select(item) {
				this.$emit('input', item.id);
				this.close();
			},
			openOrClose() {
				if (this.opened) {
					this.close();
				} else {
					this.open();
				}
			},
			open() {
				this.opened = true;
				$( this.$refs.options ).fadeIn('slow');
			},
			close() {
				this.opened = false;
				$( this.$refs.options ).fadeOut('slow');
			}
		},
		mounted() {

			const $el = $(this.$el);

			$('body').on('click', (e) => {
				if ( !$el.is(e.target) && $el.has(e.target).length == 0 ) {
					this.close();
				}
			});
		}
	};
</script>