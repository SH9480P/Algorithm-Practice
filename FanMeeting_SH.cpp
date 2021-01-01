#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

void revstr(char* a, char* b)
{
	int len = strlen(a);
	for (int i = 0; i < len; i++)
	{
		b[len - i - 1] = a[i];
	}
	b[len] = '\0';

	return;
}

int digitize(char* a)
{
	int ret;
	int len = strlen(a);
	char* num = new char[len + 1];
	num[len] = '\0';
	
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'F')
		{
			num[i] = '0';
		}
		else
		{
			num[i] = '1';
		}
	}
	ret = atoi(num);

	return ret;
}

int main()
{
	char* member = new char[200000];
	char* fan = new char[200000];

	scanf("%s", member);
	scanf("%s", fan);

	char* revmem = new char[strlen(member) + 1];
	revstr(member, revmem);

	int a, b, c, mlen, flen, n, m;

	mlen = strlen(revmem);
	flen = strlen(fan);

	a = digitize(revmem);
	b = digitize(fan);

	c = a * b;

	if (mlen < flen)
	{
		n = flen - mlen + 1;
	}
	else
	{
		n = mlen - flen + 1;
	}

	m = 0;
	while (c != 0)
	{
		if (c % 10 == 1)
		{
			m++;
		}
		c = c / 10;
	}

	printf("%d\n", n - m);
	
	
	
	return 0;
}