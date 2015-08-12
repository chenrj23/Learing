// 实现show()方法，只显示当前节点上的数据。
function Node(element) {
   this.element = element;
   this.next = null;
}

function LList() {
   this.head = new Node("head");
   this.position = this.head;
   this.find = find;
   this.insert = insert;
   this.display = display;
   this.findPrevious = findPrevious;
   this.remove = remove;
   this.show = show;
}
function show(){
  print(this.position.element)
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
    this.position = currNode
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
    this.position = currNode
    return currNode;
}

function insert(newElement, item) {
   var newNode = new Node(newElement);
   var current = this.find(item);
   newNode.next = current.next;
   current.next = newNode;
   this.position = current.next
}

//测试
var cities = new LList();
cities.insert("Conway", "head");
cities.show()
cities.insert("Russellville", "Conway");
cities.insert("Alma", "Russellville");
cities.show()
print()