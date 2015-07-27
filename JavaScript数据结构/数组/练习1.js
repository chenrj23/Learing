
// 创建一个记录学生成绩的对象，提供一个添加成绩的方法，以及一个显示学生平均成绩的方法。

function grade ()  {
  this.data = []
  this.add = add
  this.average = average
}
function add (temp){
  this.data.push(temp)
}
function average (){
  var total = 0
  for (var i = 0; i < this.data.length; i++) {
    total += this.data[i]
  };
  return total / this.data.length
}

var theGrade = new grade

theGrade.add(80)
theGrade.add(90)
theGrade.add(100)

print(theGrade.average())



