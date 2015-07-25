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
	if (_free >= MAXN) return 0;          //���
	poly[_free].c = c;
	poly[_free++].e = e;
	return 1;                             //����
}

int  compare(int a, int b)              //ǰ��С�ں��߷��� -1��ǰ�ߴ��ں��߷��� 1��������ȷ��� 0.
{
	if (a == b) return 0;
	else if (a > b) return 1;
	else return -1;
}
/*
ah,bhΪa��b����ʽ�Ŀ�ʼλ�á�at��btΪ����λ�á�
*p_ch, *p_ct�ֱ�ָ��_free��ʼλ�úͽ���λ�á�
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
		case  0:                                 //ָ��λ��ȣ�ϵ��λ���
				temp = poly[p].c + poly[q].c;
				if (temp) if (!append(temp, poly[p].e)) return 0;
				p++;
				q++;
				break;
		case -1:                                  //����ָ��λ�󣬺���ϵ��λ��ӣ�����index�����һλ
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