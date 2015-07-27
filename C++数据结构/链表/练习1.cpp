// 对一批整型数组中的数据建立一个有序的链表。

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
  cout << "请输入" << endl;
  input(head);
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
  return 0;                                             //重复输入了，会返回0
}

void input(node *head) {
  node *p,*q;
  p = head;
  cin >> p->index;
  q = new node;
  p->link = q;
  p = q;  
  cin >> p->index;
  p->link = NULL;                                         //这里还有点问题，输入前两个的时候只是按输入顺序输入，而不是按序列，但我不想再搞了 = =
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




