/*写一个程序，该程序从一个文本文件中读入名字和电话号码，然后将其存入一个字典。
该程序需包含如下功能：显示单个电话号码、显示所有电话号码、增加新电话号码、
删除电话号码、清空所有电话号码。*/

function Dictionary() {
    this.add = add;
    this.datastore = new Array();
    this.find = find;
    this.remove = remove;
    this.showAll = showAll;
    this.count = count;
    this.clear = clear;
}

function add(key, value) {
    this.datastore[key] = value;
}

function find(key) {
    return this.datastore[key];
}

function remove(key) {
    delete this.datastore[key];
}

function showAll() {
    Object.keys(this.datastore).sort().forEach(function(key){
        print(key + " -> " + this.datastore[key]);
    }, this);
}

function count() {
    var n = 0;
    for(var key in Object.keys(this.datastore)) {
        ++n;
    }
    return n;
}

function clear() {
    Object.keys(this.datastore).forEach(function(key){
        delete this.datastore[key];
    }, this);
}


function createArr(file) {
    var arr = read(file).split("\n");
    for (var i = 0; i < arr.length; ++i) {
        arr[i] = arr[i].trim();
    }
    return arr;
}

//code
var nameArray = [],
    phoneNumberArray = [],
    tpNumberDic = new Dictionary,
    fileArray = createArr('telephoneNumber.txt');

tpNumberDic.findTpNumber = function(name){
  console.log(tpNumberDic.find(name))
}

for(i = 0; i < fileArray.length; i++){
  if(i % 2 === 0){
    nameArray.push(fileArray[i])
  }
  else{
    phoneNumberArray.push(fileArray[i])  

  }
}

for (i = 0; i < nameArray.length ; i++) {
  tpNumberDic.add(nameArray[i],phoneNumberArray[i])
};

//test
tpNumberDic.add("policeman",911)
tpNumberDic.showAll()
tpNumberDic.findTpNumber("home")
tpNumberDic.remove('home')
tpNumberDic.showAll()
tpNumberDic.clear()
tpNumberDic.showAll()