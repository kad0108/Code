# Todolist [demo](https://kad0108.github.io/Code/VueJS/Todolist)

> A Vue.js project

#### [Webpack](http://www.jianshu.com/p/42e11515c10f#)

package.json文件是npm说明文件，```npm init```自动创建。貌似package.json文件中不能加注释。

[什么是source maps ](http://www.ruanyifeng.com/blog/2013/01/javascript_source_map.html) 提供对应编译文件和源文件的方法，方便压缩代码后进行调试。在webpack.config.js文件中的devtool属性配置。

webpack.config.js是webpack的配置文件，包含入口文件路径和打包文件路径。

打包命令package文件中配置后，可以使用配置的命令```npm start```，也可以直接```webpack```打包。

安装webpack-dev-server时需要的webpack版本不存在，解决方法```npm install --save-dev webpack-dev-server@1.9.0```，运行server的命令为```webpack-dev-server```，webpack的本地服务器基于nodejs搭建，默认端口8080。

Loaders是webpack中对各种格式的文件进行处理。eg: scss to css, es6 to es5, json to js等。

配置json-loader： ```npm install --save-dev json-loader```，这个好像得在项目目录下执行才好使。在webpack.config.js文件中的module属性配置。

配置babel：babel的配置选项放在".babelrc"文件中。

配置css-loader： ```npm install --save-dev style-loader css-loader```，这里还有点问题，先留着。

#### Vue+Webpack

使用vue-cli官方提供的命令行工具：

```bash
# 全局安装 vue-cli
$ npm install --global vue-cli
# 创建一个基于 webpack 模板的新项目
$  vue init webpack my-project
# 安装依赖，走你
$ cd my-project
$ npm install
$ npm run dev
```

* vue的template中的```export default{}```编译时会自动生成new Vue({})

* index.html中应该是默认调用src/main.js这个文件

* main.js中```import App from './App'```引入的就是App.vue这个文件，import是ES6的语法，等价于```var App = require('./App')```

* ```npm install```安装的依赖包是node_modules这个文件，```import Vue from vue```就在这个目录下

* vue中注册的组件命名是驼峰的写法，在html中会转换为小写和横杠的写法

* ```.vue```文件就是一个组件：```template + script + style```，组件的data必须是函数，```data () {}```是ES6的语法，相当于```data: function(){}```

* run的时候一路enter下来的结果就是eslint语法检查太严格了。。。

* 父组件向子组件传数据```props```，子组件向父组件传数据```$emit(触发事件)```

  ​





