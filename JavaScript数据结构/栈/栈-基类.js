function Stack() {
   this.dataStore = [];
   this.top = 0;
   this.push = push;
   this.pop = pop;
   this.peek = peek;
   this.clear = clear;
   this.length = length;
}
function push(element) {
   this.dataStore[this.top++] = element;
}
function peek() {                             //返回栈顶元素
   return this.dataStore[this.top-1];
}
function pop() {                             //返回栈顶元素，并top-1
   return this.dataStore[--this.top];
}
function clear() {
   this.top = 0;
}
function length() {
   return this.top;
}