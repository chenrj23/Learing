Array.matrix = function(numrows, numcols, initial) {
    var arr = [];
    for (var i = 0; i < numrows; ++i) {
        var columns = [];
        for (var j = 0; j < numcols; ++j) {
            columns[j] = initial;
        }
    arr[i] = columns;
    }
    return arr;
}
/*修改本章前面出现过的weeklyTemps对象，使它可以使用一个二维数组来存储每月的有用数据。
增加一些方法用以显示月平均数、具体某一周平均数和所有周的平均数*/

/*原weeklyTemps对象
function weekTemps() {
    this.dataStore = [];
    this.add = add;
    this.average = average;
}
function add(temp) {
    this.dataStore.push(temp);
}
function average() {
    var total = 0;
    for (var i = 0; i < this.dataStore.length; ++i) {
        total += this.dataStore[i];
    }
    return total / this.dataStore.length;
}*/



function monthTemps() {
    this.dataStore = new Array.matrix(52,0,0) ;
    this.add = add;
    this.averageMonth = averageMonth;
    this.averageWeek = averageWeek;
    this.averageTheWeek = averageTheWeek;
}

function add(weeks,temp) {
    this.dataStore[weeks-1].push(temp);
}
function averageMonth() {
    var weekList = [],
        temp = [],
        list = []

    weekList = this.averageWeek()
    for (var i = 0; i < weekList.length; i++) {
      temp += weekList[i]
      if (i%4 == 0) {
        list.push(temp/4)
        temp = 0
      };
    };

    return list;
}
function averageWeek() {
    var list = []
    for (var i = 0; i < this.dataStore.length; i++) {
      list.push(theMonthTemps.averageTheWeek(i+1))
    };
    return list;
}
function averageTheWeek(week){
    var total = 0;
    week = week -1;
    for (var i = 0; i < this.dataStore[week].length; ++i) {
        total += this.dataStore[week][i];
    }
    return parseInt(total / this.dataStore[week].length);
}   


theMonthTemps = new monthTemps

for (var i = 0; i < theMonthTemps.dataStore.length; i++) {
  for(var j = 0, length2 = 7; j < length2; j++){
    theMonthTemps.add(i+1,parseInt(Math.random()*100))
  }
};

print(theMonthTemps.averageMonth())
print(theMonthTemps.averageWeek())
print(typeof(theMonthTemps.averageTheWeek(1)))


