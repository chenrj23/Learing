function Person(name, sex){
  this.name = name;
  this.sex = sex;
}
var PersonList = new List()

for (i=-0; i <= 10; i++) {
    var temp = new Person(i,"male");
    PersonList.append(temp)
};

function displaySameSex(list, sex){
  list.dataStore.forEach(function(element, index, arry){
    if(element.sex == sex){
      print(element)
    }
  });
}