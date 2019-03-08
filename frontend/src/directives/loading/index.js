import './styles.css';

const handle = function(el, binding, vnode) {
    if (typeof binding.value == 'undefined' || binding.value) {
        $(el).addClass('loading');
    } else {
        $(el).removeClass('loading');
    }
};

export default {
    bind: handle,
    update: handle
};