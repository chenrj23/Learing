/*现实生活中栈的一个例子是佩兹糖果盒。想象一下你有一盒佩兹糖果，
里面塞满了红色、黄色和白色的糖果，但是你不喜欢黄色的糖果。使
用栈（有可能用到多个栈）写一段程序，在不改变盒内其他糖果叠放
顺序的基础上，将黄色糖果移出*/

function reSequence(elements){
  var s = new Stack
  var temp = new Stack
  for(i = 0; i <= elements.length; i++){
    s.push(elements[i])
  }
  while(s.top > 0){
    if(s.peek() != "yellow"){
      temp.push(s.pop())
    }
    else{
      s.pop()  
    }
  }
  while(temp.top > 1){
    print(temp.pop())
  }
}


var elements = ["red","white","yellow","red","white","yellow"]
reSequence(elements)




//Stack类
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