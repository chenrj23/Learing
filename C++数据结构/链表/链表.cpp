
#include "iostream"
using namespace  std;

struct node
{
	int data;
	node *link;

};

node *createNode(int n)
{
	node *head, *p, *q;
	if (n <= 0)
		return NULL;
	head = new node;
	p = head;
	cout << "input data" << endl;
	for (int i = 0; i < (n - 1); i++)
	{
		cin >> p->data;
		q = new node;
		p->link = q;
		p = q;
	}
	cin >> p->data;
	p->link = NULL;
	return head;
}

node *reverseNode(node *head)
{
	node *h, *p;
	h = NULL;
	while (head != NULL)
	{
		p = head;
		head = head->link;
		p->link = h;
		h = p;
	}
	return h;
}

node *insertNode(node *head, int index)
{
	node *p, *q;
	p = head;
	for (int i = index; i >= 2; i--)
	{
		p = p->link;
	}
	q = new node;
	cout << "please input data" << endl;
	cin >> q->data;
	q->link = p->link;
	p->link = q;
	return head;
}

int sizeNode(node *head)
{
	int i = 0;
	while (head != NULL)
	{
		head = head->link;
		i++;
	}
	return i;
}

node *deleteNode(node *head, int index)
{
	node *p, *q;
	if (index < 1 || index > sizeNode(head)) return head;
	if (index == 1)
	{
		p = head;
		head = head->link;
		delete p;
		return head;
	}
	p = head;
	q = p->link;
	for (int j = 0; j <= (index - 3); j++)
	{
		p = p->link;
		q = q->link;
	}
	p->link = q->link;
	delete q;
	return head;
}


void showNode(node *head)
{
	node	*p;
	p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->link;
	}


}


void main()
{
	int n;
	node *head;
	cout << "please input number" << endl;
	cin >> n;
	head = createNode(n);
	showNode(head);
	//cout << "reverseNode"<< endl;
	//head = reverseNode(head);
	//showNode(head);
	//cout << "please input the delete index";
	//cin >> n;
	//head = deleteNode(head, n);
	//showNode(head);
	cout << "insert node index" << endl;
	cin >> n;
	head = insertNode(head, n);
	showNode(head);

}

