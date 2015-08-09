function appendSmaller (elementInsert) {
  var result = this.dataStore.every(function(element, index, array){
    return elementInsert < element
  })
  if (result) {
    this.append(elementInsert)
  }
  else{
    return false
  }
}