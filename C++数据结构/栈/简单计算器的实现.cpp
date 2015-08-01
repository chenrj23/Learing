#include  <iostream>

#define MAXN 100
using namespace std;


char mid_e[MAXN], pos_e[MAXN];
int v = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26];

//pos_e[]Ҫ��������飬int  *p_y���������ս��
//c�������ڼ�����ַ���x�м������ʱ������y����ָ������ʱ�ĵ���
//j��k��zָ���������ʱ����

int  evaluate(char  pos_e[], int  *p_y)
{ 
	int stack[MAXN], top, i, j, k, x, y, z;
	char c;
	top = -1;
	i = 0;
	c = pos_e[0];
	while (c != '\0')
	{
		if (islower(c))
			stack[++top] = v[c - 'a'];
		else
			switch (c)
			{
			case '+':
				x = stack[top--];
				stack[top] += x;
				break;
			case '-':
				x = stack[top--];
				stack[top] -= x;
				break;
			case '*': 
				x = stack[top--];
				stack[top] *= x;
				break;
			case '/':
				x = stack[top--];
				stack[top] /= x;
				break;
			case '^':
				x = stack[top--];
				y = stack[top];
				if (y == 0)  return(1);
				if (x == 0) stack[top] = 1;
				else
				{
					if (x > 0) j = x;
					else  j = -x;
					for (z = 1, k = 1; k <= j; k++)
						z *= y;
					if (x < 0) z = 1 / z;
					stack[top] = z;
				}
				break;
			default: return(1);
			}
		c = pos_e[++i];
	}
			if (top>0) return(1);
		*p_y = stack[top];
		return(0);
}





int icp(char c)
{
	switch (c) {
		case '^': return(4);
		case '*':
		case '/': return(2);
		case '+':
		case '-': return(1);
	}
}

int  isp(char c)
{
	switch (c)
	{
		case '^': return(3);
		case '*':
		case '/': return(2);
		case '+':
		case '-': return(1);
		case '(': return(0);
		case '$': return(-1);
	}
}

int mid_to_pos(char  mid_e[], char  pos_e[])
{
	char stack[MAXN], c;
	int top, i, j;
	stack[0] = '$';
	top = 0;
	j = 0;
	i = 0;
	c = mid_e[0];
	while (c != '\0')
	{
		if (islower(c))
			pos_e[j++] = c;
		else
			switch (c)
			{
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				while (icp(c) <= isp(stack[top])) {
					pos_e[j++] = stack[top--];
				}
				stack[++top] = c;
				break;
			case  '(':
				stack[++top] = c;
				break;
			case  ')':
				while (stack[top] != ')') {
					pos_e[j++] = stack[top--];
				}
				top--;
				break;
			default:
				return 1;
			}
		c = mid_e[++i];
	}
	while (top > 0) {                 //��󶼳�ջ
		pos_e[j++] = stack[top--];
	}

	pos_e[j] = '\0';
	return 0;
}
