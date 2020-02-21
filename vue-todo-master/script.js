var app = new Vue({
  el: '#app',
  data: {
      todos: [{
        text: "make an app",
        completed: false,
      }, {
        text: "declare victory",
        completed: false,
      }, {
        text: "profit",
        completed: false
      }],
      message: '',
    },
    computed: {
    activeTodos() {
      return this.todos.filter(item => {
        return !item.completed;
      });
    },
  },
    methods: {
  addItem() {
    this.todos.push({text: this.message, completed:false});
    this.message = '';
  },
  deleteItem(item) {
     var index = this.todos.indexOf(item);
     if (index > -1)
       this.todos.splice(index,1);
   },

}


});
