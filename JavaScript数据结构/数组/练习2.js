/*将一组单词存储在一个数组中，并按正序和倒序分别显示这些单词。*/

function dictionary(){
  this.data = []
  this.ascDisplay = ascDisplay
  this.descDisplay = descDisplay
}
function ascDisplay(){
  print(this.data.sort())
}
function descDisplay(){
    print(this.data.sort().reverse())
}

theDictionary = new dictionary

theDictionary.data = ["break","continue","if"]
theDictionary.ascDisplay()
theDictionary.descDisplay()
