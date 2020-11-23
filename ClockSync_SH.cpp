#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>

void deep_copy(int* arr1, int* arr2, int num)
{
	for (int i = 0; i < num; i++)
	{
		arr2[i] = arr1[i];
	}
}

void control_clock(int clock[], int type)
{
	switch (type)
	{
	case 0:
		clock[0] = (clock[0] + 1) % 4;
		clock[1] = (clock[1] + 1) % 4;
		clock[2] = (clock[2] + 1) % 4;
		break;
	case 1:
		clock[3] = (clock[3] + 1) % 4;
		clock[7] = (clock[7] + 1) % 4;
		clock[9] = (clock[9] + 1) % 4;
		clock[11] = (clock[11] + 1) % 4;
		break;
	case 2:
		clock[4] = (clock[4] + 1) % 4;
		clock[10] = (clock[10] + 1) % 4;
		clock[14] = (clock[14] + 1) % 4;
		clock[15] = (clock[15] + 1) % 4;
		break;
	case 3:
		clock[0] = (clock[0] + 1) % 4;
		clock[4] = (clock[4] + 1) % 4;
		clock[5] = (clock[5] + 1) % 4;
		clock[6] = (clock[6] + 1) % 4;
		clock[7] = (clock[7] + 1) % 4;
		break;
	case 4:
		clock[6] = (clock[6] + 1) % 4;
		clock[7] = (clock[7] + 1) % 4;
		clock[8] = (clock[8] + 1) % 4;
		clock[10] = (clock[10] + 1) % 4;
		clock[12] = (clock[12] + 1) % 4;
		break;
	case 5:
		clock[0] = (clock[0] + 1) % 4;
		clock[14] = (clock[14] + 1) % 4;
		clock[15] = (clock[15] + 1) % 4;
		clock[2] = (clock[2] + 1) % 4;
		break;
	case 6:
		clock[3] = (clock[3] + 1) % 4;
		clock[14] = (clock[14] + 1) % 4;
		clock[15] = (clock[15] + 1) % 4;
		break;
	case 8:
		clock[1] = (clock[1] + 1) % 4;
		clock[2] = (clock[2] + 1) % 4;
		clock[3] = (clock[3] + 1) % 4;
		clock[4] = (clock[4] + 1) % 4;
		clock[5] = (clock[5] + 1) % 4;
		break;
	case 7:
		clock[14] = (clock[14] + 1) % 4;
		clock[4] = (clock[4] + 1) % 4;
		clock[5] = (clock[5] + 1) % 4;
		clock[7] = (clock[7] + 1) % 4;
		clock[15] = (clock[15] + 1) % 4;
		break;
	case 9:
		clock[3] = (clock[3] + 1) % 4;
		clock[4] = (clock[4] + 1) % 4;
		clock[5] = (clock[5] + 1) % 4;
		clock[9] = (clock[9] + 1) % 4;
		clock[13] = (clock[13] + 1) % 4;
		break;
	default:
		break;
	}
}

int check_sync(int clock[])
{
	for (int i = 0; i < 16; i++)
	{
		if (clock[i] != 3)
			return 0;
	}
	return 1;
}

void recursive(int clock[] ,int* res, int cnt, int checklist[])
{
	for (int i = 0; i < 10; i++)
	{
		int tmpclock[16], tmplist[10];
		deep_copy(clock, tmpclock, 16);
		deep_copy(checklist, tmplist, 10);
		if (checklist[i] < 4)
		{
			control_clock(tmpclock, i);
			cnt++;
			tmplist[i]++;
			if (check_sync(tmpclock))
			{
				if (*res > cnt)
					*res = cnt;
				return;
			}
			recursive(tmpclock, res, cnt, tmplist);
		}
	}
}


int main()
{
	int clock[16];
	int checklist[10] = { 0 };
	int c;
	int cnt = 0, result = 30;
	for (int i = 0; i < 16; i++)
	{
		scanf("%d", &c);
		clock[i] = c / 3 - 1;
	}

	recursive(clock, &result, cnt, checklist);

	printf("%d\n", result);
	return 0;
}