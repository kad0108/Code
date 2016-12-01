<template>
  <div id="app">
    <h1>{{title}}</h1>
    <input v-model="newItem" v-on:keyup.enter="addNew">
    <ul>
      <li v-for="item in items" v-bind:class="{finished: item.isFinished}" v-on:click="toggleFinish(item)">{{item.label}}</li>
    </ul>
    <h1>From component: {{childWords}}</h1>
    <!-- 子组件的click事件触发，执行onClickMe，然后触发from-child事件，执行listenTo -->
    <hello msg='hello' v-on:from-child='listenTo'></hello>
  </div>
</template>

<script>
import Store from './store'
import Hello from './components/Hello'
export default {
  name: 'app',
  data () {
    return {
      title: 'this is a todo list',
      items: Store.fetch(),
      newItem: '',
      childWords: ''
    }
  },
  methods: {
    toggleFinish (item) {
      item.isFinished = !item.isFinished
    },
    addNew () {
      this.items.push({label: this.newItem, isFinished: false})
      this.newItem = ''
    },
    listenTo (msg) {
      this.childWords = msg
    }
  },
  watch: {
    items: {
      handler (items) {
        Store.save(items)
      },
      deep: true // 深度更新 localStorage中的数据对应items变化
    }
  },
  components: {
    Hello
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
.finished{
  text-decoration: underline;
}
li{
  cursor: pointer;
}
</style>
