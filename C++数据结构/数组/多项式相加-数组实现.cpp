#include <iostream>

using namespace std;

struct TREM
{
	int c;
	int e;
	TREM *link;
};

TERM *input() {
	TERM *head, *p, *q;
	head = new TERM;
	p = head;
	while (cin >> p->e) {
		cin >> p->c;
		q = new TERM;
		p->link = q;
	}
	return head;
}

void output(TERM *head) {
	TERM *p;
	p = head;
	while (p->link != NULL) {
		cout << "+" << p->c << "(" << p->e << ")";
		p = p->link;
	}
	{

	}
}



void main() {
	TERM *head;
	head = input()
	output(head);
}