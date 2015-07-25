#include <iostream>
#define MAXN 100
using namespace std;

struct  TERM
{
	int c;
	int e;
};


int ah = 0,
at = 3,
bh = 4,
bt = 8,
ct ,
_free;
int ch = _free = 9;

TERM poly[MAXN] = { { 5, 4 },{ 3, 2 },{ -7,1 },{ 1,0 },{ 5,4 },{ 4,3 },{ -3,2 },{ 1,1 },{ 5,0 } };


int append(int c, int e)
{
	if (_free >= MAXN) return 0;          //溢出
	poly[_free].c = c;
	poly[_free++].e = e;
	return 1;                             //正常
}

int  compare(int a, int b)              //前者小于后者返回 -1，前者大于后者返回 1，两者相等返回 0.
{
	if (a == b) return 0;
	else if (a > b) return 1;
	else return -1;
}
/*
ah,bh为a，b多项式的开始位置。at，bt为结束位置。
*p_ch, *p_ct分别指向_free开始位置和结束位置。
*/
int polyAdd(int ah,int at, int bh, int bt, int ch)
{
	int compared, q, p, temp;
	p = ah;
	q = bh;
	while (p <= at&&q <= bt)
	{
		compared = compare(poly[p].e, poly[q].e);
		switch (compared)
		{
		case  0:                                 //指数位相等，系数位相加
				temp = poly[p].c + poly[q].c;
				if (temp) if (!append(temp, poly[p].e)) return 0;
				p++;
				q++;
				break;
		case -1:                                  //后者指数位大，后者系数位添加，后者index向后移一位
					if (!append(poly[q].c, poly[q].e)) return 0;
					q++;
					break;
		case 1:
						if (!append(poly[p].c, poly[p].e)) return 0;
						p++;
						break;
		}
	}
	while (p <= at)
	{
		if (!append(poly[p].c, poly[p].e)) return 0;
		p++;
	}
	while (q <= bt)
	{
		if (!append(poly[q].c, poly[q].e)) return 0;
		q++;
	}
	ct = (_free - 1);
	return 1;
}


void outputPoly(int head, int title) {
	while (head <= title)
	{
		cout << "+" << poly[head].c << "(" << poly[head].e << ")";
		head++;
	}
	cout << endl;
}

void main() {
	cout << "A(X)=";
	outputPoly(ah, at);
	cout << "B(X)=";
	outputPoly(bh, bt);
	if (polyAdd(ah, at, bh, bt, ch)) {
		cout << "C(X)=";
		outputPoly(ch, ct);
	} 
	else  cout << "ERROR" << endl;
}