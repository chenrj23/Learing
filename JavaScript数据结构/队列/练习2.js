// 使用前面完成的Deque类来判断一个给定单词是否为回文

function isPalindrome(word) {
    var s = new Deque();
    for (var i = 0; i < word.length; ++i) {
        s.enqueueLeft(word[i]);
    }
    var rword = "";
    while (!s.empty) {
        rword += s.dequeueLeft();
    }
    if (word == rword) {
        return true;
    }
    else {
        return false;
    }
}

var word = "hello";
if (isPalindrome(word)) {
    print(word + " is a palindrome.");
}
else {
    print(word + " is not a palindrome.");
}
word = "racecar"
if (isPalindrome(word)) {
    print(word + " is a palindrome.");
}
else {
    print(word + " is not a palindrome.");
}


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
