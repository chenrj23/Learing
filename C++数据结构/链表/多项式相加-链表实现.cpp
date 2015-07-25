
#include <iostream>

using namespace std;

struct TERM
{
	int c;
	int e;
	TERM *link;
};

TERM *input() {
	TERM *head, *p, *q;
	head = new TERM;
	p = head;
	p->link = NULL;
	cin >> p->e;
	if (p->e == 0) return head;
	cin >> p->c;
	while (1) {
		q = new TERM;
		q->link = NULL;
		cin >> q->e;
		if (q->e == 0) break;
		cin >> q->c;
		p->link = q;
		p = p->link;
	}
	return head;
}


TERM *insert(TERM *proC, int cData, int eData) {
	TERM *newNode = new TERM;
	newNode->c = cData;
	newNode->e = eData;
	proC->link = newNode;
	return newNode;
}

int  compare(TERM *a, TERM *b)              //前者小于后者返回 -1，前者大于后者返回 1，两者相等返回 0.
{
	if (a->e == b->e) return 0;
	else if (a > b) return 1;
	else return -1;
}

TERM *polyAdd(TERM *aHead, TERM *bHead) {
	int compared, temp;
	TERM *cHead,*pointA,*pointB, *pointC;
	cHead = new TERM;

	pointA = aHead;
	pointB = bHead;
	pointC = cHead;
	
	while (pointA !=NULL&&pointB !=NULL) {
	compared = compare(pointA, pointB);
	switch (compared)
		{
		case 0: 
			temp = pointA->c + pointB->c;
			pointC = insert(pointC, temp, pointB->e);
			pointA = pointA->link;
			pointB = pointB->link;
			break;
		case -1:
			pointC = insert(pointC, pointB->c, pointB->e);
			pointB = pointB->link;
			break;
		case 1:
			pointC = insert(pointC, pointA->c, pointA->e);
			pointA = pointA->link;
			break;
		}
	}
	while (pointA != NULL)
	{
		pointC = insert(pointC, pointA->c, pointA->e);
		pointA = pointA->link;
	}
	while (pointB != NULL)
	{
		pointC = insert(pointC, pointB->c, pointB->e);
		pointB = pointB->link;
	}

	pointC->link = NULL;
	pointC = cHead;
	cHead = cHead->link;
	delete pointC;
	return cHead;
}

void output(TERM *head) {
	TERM *p;
	p = head;
	while (p != NULL) {
		cout << "+" << p->c << "(" << p->e << ")";
		p = p->link;
	}

}



void main() {
	TERM *aHead, *bHead, *cHead;
	cout << "请输入A多项式";
	aHead = input();
	cout << "请输入B多项式";
	bHead = input();
	cHead = polyAdd(aHead, bHead);
	cout << "A多项式:";
	output(aHead);
	cout << endl;
	cout << "B多项式:";
	output(bHead);
	cout << endl;
	cout << "C多项式:";
	output(cHead);
}