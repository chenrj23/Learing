
  // 删除整型数链表中所有奇数结点（偶数结点）
  // 在练习1的基础上  增加了一个deleteEven函数
#include "iostream"

using namespace std;

struct node
{
  int index;
  node *link;
};


void main() {
  node *head;
  head = new node;
  head->index = 0;
  head->link = NULL;
  cout << "请输入"<<endl;
  input(head);
  output(head);
  head = deleteEven(head);
  cout << "去除偶数后：" << endl;
  output(head);
}

int insert(node *head,int  index) {
  node *temp, *p;
  p = head;
  temp = new node;
  temp->link = NULL;
  temp->index = index;
  while (p != NULL) {
    if (p->index < index && (p->link == NULL ||p->link->index > index ))
    {
      temp->link = p->link;
      p->link = temp;
      return 1;
    }
    p = p->link;
  }
  return 0;
}

void input(node *head) {
  node *p,*q;
  p = head;
  cin >> p->index;
  q = new node;
  p->link = q;
  p = q;  
  cin >> p->index;
  p->link = NULL;
  int in;
  cin >> in;
  while (in) {
    if (!insert( head, in)) cout << "ERROR";
    cin >> in;
  }
}

void output(node *head) {
  node *p;
  p = head;
  while (p != NULL) {
    cout << p->index;
    p = p->link;
  }
}

 node *deleteEven(node *head) {
  node *p, *temp;
  while (head->index % 2 == 0)
  {
    temp = head;
    head = head->link;
    delete temp;
  }
  p = head;
  temp = p->link;
  while (temp!=NULL)
  {
    if (temp->index % 2 == 0) {
      p->link = temp->link;
      delete temp;
      temp = p->link;
    }
    else {
      temp = temp->link;
      p = p->link;
    }
  }
  return head;
}

