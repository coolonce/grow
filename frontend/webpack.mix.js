const mix = require('laravel-mix');

const CleanWebpackPlugin = require('clean-webpack-plugin');

mix.setPublicPath('dist');

mix.js('src/js/app.js', 'dist/js');
mix.sass('src/sass/app.scss', 'dist/css');
mix.extract(['vue', 'axios', 'lodash', 'jquery']);

mix.copy('src/index.html', 'dist/');
mix.copy('src/.htaccess', 'dist/.htaccess');
mix.copyDirectory('src/fonts', 'dist/fonts');
mix.copyDirectory('src/img', 'dist/img');

if (mix.inProduction()) {
    mix.version();
}

mix.options({
    polyfills: [
        'Promise'
    ],
    processCssUrls: false
});

mix.webpackConfig({
    resolve: {
        modules: ['node_modules', 'src/js']
    },
    plugins: [
        new CleanWebpackPlugin(['dist/*'])
    ]
});