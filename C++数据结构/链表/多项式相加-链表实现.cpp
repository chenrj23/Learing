
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

int  compare(TERM *a, TERM *b)              //ǰ��С�ں��߷��� -1��ǰ�ߴ��ں��߷��� 1��������ȷ��� 0.
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
	cout << "������A����ʽ";
	aHead = input();
	cout << "������B����ʽ";
	bHead = input();
	cHead = polyAdd(aHead, bHead);
	cout << "A����ʽ:";
	output(aHead);
	cout << endl;
	cout << "B����ʽ:";
	output(bHead);
	cout << endl;
	cout << "C����ʽ:";
	output(cHead);
}