/*栈可以用来判断一个算术表达式中的括号是否匹配。编写一个函数
，该函数接受一个算术表达式作为参数，返回括号缺失的位置。下
面是一个括号不匹配的算术表达式的例子：2.3 + 23 / 12 + (3.1
  4159\times 0.24。
*/

function matchBracket(words){
  var s = new Stack()
  var rightBracketLoc
  for (var i = words.length; i >= 0; i--) {
    s.push(words[i])
  };
  while(s.length() > 0){
    if(s.pop() == "("){
      rightBracketLoc = s.top
    }
    if(isSymbol(s.peek()) && s.top < rightBracketLoc){
      print("返回括号缺失的位置:" + s.top)
    }
  }  
}
function isSymbol(word){
  switch(word){
    case "+":
      return true
      break;
    case "-":
      return true
      break;
    case "*":
      return true
      break;
    case "/":
      return true
      break;
    default:
      return false
      break;
  }
}

var words = "2.3+23/12+(3.14159*0.24"
print(words)
matchBracket(words)

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