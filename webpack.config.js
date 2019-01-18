const Path = require('path');
const CleanWebpackPlugin = require('clean-webpack-plugin');
const CopyWebpackPlugin = require('copy-webpack-plugin');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
    entry: {
        app: Path.resolve(__dirname, './build/hud/index.js')
    },
    output: {
        path: Path.join(__dirname, './dist'),
        filename: 'js/[name].js'
    },
    plugins: [
        new CleanWebpackPlugin(['dist'], {
            root: Path.resolve(__dirname, './')
        }),
        new CopyWebpackPlugin([{
            from: Path.resolve(__dirname, './assets'),
            to: 'assets'
        }]),
        new HtmlWebpackPlugin({
            template: Path.resolve(__dirname, './src/hud/index.html')
        })
    ]
};
