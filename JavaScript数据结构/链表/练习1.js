// 实现 advance(n) 方法，使当前节点向前移动 n 个节点
function Node(element) {
   this.element = element;
   this.next = null;
}

function LList() {
   this.head = new Node("head");
   this.find = find;
   this.insert = insert;
   this.display = display;
   this.findPrevious = findPrevious;
   this.remove = remove;
   this.advance = advance;
}

function remove(item) {
   var prevNode = this.findPrevious(item);
   if (!(prevNode.next == null)) {
       prevNode.next = prevNode.next.next;
  }
}

function findPrevious(item) {
   var currNode = this.head;
   while (!(currNode.next == null) &&
           (currNode.next.element != item)) {
       currNode = currNode.next;
    }
    return currNode;
}

function display() {
   var currNode = this.head;
   while (!(currNode.next == null)) {
       print(currNode.next.element);
       currNode = currNode.next;
    }
}

function find(item) {
   var currNode = this.head;
   while (currNode.element != item) {
       currNode = currNode.next;
    }
    return currNode;
}

function insert(newElement, item) {
   var newNode = new Node(newElement);
   var current = this.find(item);
   newNode.next = current.next;
   current.next = newNode;
}
function advance(item, n){
  if (n <= 0) {
    return false
  };
  var preNNode = this.findPrevious(item)
  this.remove(item)
  for(i = 0; i <= n; i++){
    preNNode = this.findPrevious(preNNode.element)
  }
  this.insert(item, preNNode.element)
}

//测试
var cities = new LList();
cities.insert("Conway", "head");
cities.insert("Russellville", "Conway");
cities.insert("Alma", "Russellville");
cities.insert("shanghai", "Alma");
cities.display()
print()
cities.advance("Alma", 1)
cities.display()
print()
cities.advance("Russellville", 1)
cities.display()
