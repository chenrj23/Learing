/*修改Queue类，形成一个Deque类。这是一个和队列类似的数据结构，
允许从队列两端添加和删除元素，因此也叫双向队列。写一段测试
程序测试该类*/

function Deque() {
    this.dataStore = [];
    this.enqueueLeft = enqueueLeft;
    this.enqueueRight = enqueueRight;
    this.dequeueLeft = dequeueLeft;
    this.dequeueRight = dequeueRight;
    this.front = front;
    this.back = back;
    this.toString = toString;
    this.empty = empty;
}
function enqueueLeft(element) {
    this.dataStore.push(element);
}
function enqueueRight(element){
    this.dataStore.unshift(element)
}
function dequeueLeft(){
    this.dataStore.pop()
}
function dequeueRight() {
    return this.dataStore.shift();
}
function front() {
    return this.dataStore[0];
}
function back() {
    return this.dataStore[this.dataStore.length-1];
}
function toString() {
    var retStr = "";
    for (var i = 0; i < this.dataStore.length; ++i) {
        retStr += this.dataStore[i] + "\n";
    }
    return retStr;
}
function empty() {
    if (this.dataStore.length == 0) {
        return true;
    }
    else {
        return false;
    }
}


var q = new Deque();
q.enqueueLeft("Meredith");
q.enqueueLeft("Cynthia");
q.enqueueLeft("Jennifer");
print(q.toString());
q.dequeueRight();
print(q.toString());
print("Front of queue: " + q.front());
print("Back of queue: " + q.back() + "\n");


q.enqueueRight("Jack");
q.enqueueRight("Mary");
q.enqueueRight("Tom");
print(q.toString());
q.dequeueLeft();
print(q.toString());
print("Front of queue: " + q.front());
print("Back of queue: " + q.back());
