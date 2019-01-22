import Api from 'class/Api';
import config from 'config';

export default new Api({
	baseUrl: _.get(config, 'api.baseUrl')
});