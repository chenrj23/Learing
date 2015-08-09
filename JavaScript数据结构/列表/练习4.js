function List() {
    this.listSize = 0;
    this.pos = 0;
    this.dataStore = []; //初始化一个空数组来保存列表元素
    this.clear = clear;
    this.find = find;
    this.toString = toString;
    this.insert = insert;
    this.append = append;
    this.remove = remove;
    this.front = front;
    this.end = end;
    this.prev = prev;
    this.next = next;
    this.length = length;
    this.currPos = currPos;
    this.moveTo = moveTo;
    this.getElement = getElement;
    this.contains = contains;
}
function append(element) {
    this.dataStore[this.listSize++] = element;
}
function find(element) {
    for (var i = 0; i < this.dataStore.length; ++i) {
        if (this.dataStore[i] == element) {
            return i;
        }
    }
    return -1;
}
function remove(element) {
    var foundAt = this.find(element);
    if (foundAt > -1) {
        this.dataStore.splice(foundAt,1);
        --this.listSize;
        return true;
    }
    return false;
}
function length() {
    return this.listSize;
}
function toString() {
    return this.dataStore;
}
function insert(element, after) {
    var insertPos = this.find(after);
    if (insertPos > -1) {
        this.dataStore.splice(insertPos+1, 0, element);
        ++this.listSize;
        return true;
    }
    return false;
}
function clear() {
    delete this.dataStore;
    this.dataStore.length = 0;
    this.listSize = this.pos = 0;
}
function contains(element) {
    for (var i = 0; i < this.dataStore.length; ++i) {
        if (this.dataStore[i] == element) {
            return true;
        }
    }
    return false;
}
function front() {
    this.pos = 0;
}
function end() {
    this.pos = this.listSize-1;
}
function prev() {
    if (this.pos > 0) {
        --this.pos;
    }
}
function next() {
    if (this.pos <= this.listSize-1) {
        ++this.pos;
    }
}
function currPos() {
    return this.pos;
}
function moveTo(position) {
    this.pos = position;
}
function getElement() {
    return this.dataStore[this.pos];
}


//以上基本类


function createArr(file) {
    var arr = read(file).split("\n");
    for (var i = 0; i < arr.length; ++i) {
        arr[i] = arr[i].trim();
    }
    return arr;
}

function Customer(name, movie) {
    this.name = name;
    this.movie = movie;
}

var movieList = new List();
var customers = new List();


function displayList(list) {
    for (list.front(); list.currPos() < list.length(); list.next()) {
        if (list.getElement() instanceof Customer) {
            print(list.getElement()["name"] + ", " + 
                  list.getElement()["movie"]);
        }
        else {
            print(list.getElement());
        }
    }
}

//原代码
// function checkOut(name, movie, filmList, customerList) {
//     if (movieList.contains(movie)) {
//         var c = new Customer(name, movie);
//         customerList.append(c);
//         filmList.remove(movie);
//     }
//     else {
//         print(movie + " is not available.");
//     }
// }
//以下新代码

var borrowedList = new List;

function checkOut(name, movie, filmList, borrowedList) {
    print("The borrowed movie List\n");
    displayList(borrowedList)
    if (movieList.contains(movie)) {
        var c = new Customer(name, movie);
        borrowedList.append(c);
        filmList.remove(movie);
    }
    else {
        print(movie + " is not available.");
    }
}


