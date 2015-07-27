// 创建这样一个对象，它将字母存储在一个数组中，并且用一个方法可以将字母连在一起，显示成一个单词。

function ABC (){
  this.dataStore = []
  this.append = append
  this.display = display
}

function append(){
  var input
  input = readline()
  this.dataStore.push(input)
}

function display(){
  print(this.dataStore.join(""))
}

theABC = new ABC
theABC.append()
theABC.append()
theABC.append()
theABC.display()

/*刚刚谷歌了下。。。。发现了自己把问题想简单了。。。。
题目要求是显示成一个单词，而不只是简单的把字母拼凑在一起。。。。*/