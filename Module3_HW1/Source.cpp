#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include <Windows.h>

void main()
{

	setlocale(LC_ALL, "Rus");

	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int tn = 0;

start:
	printf("task number:\t");
	scanf("%d", &tn);

	switch (tn)
	{
	case 1:
	{
		int h, m, s;
		h = 0 + rand() % 24;
		m = 0 + rand() % 60;
		s = 0 + rand() % 60;
		printf("\n%d hours %d minutes %d seconds\n\n", h, m, s);
		
		s = h * 3600 + m * 60 + s;
		SetConsoleTextAttribute(hConsole, 13);
		printf("%d seconds passed\n\n", s);
		SetConsoleTextAttribute(hConsole, 15);
	}
	break;
	case 2:
	{
		int m, d;
		m = 1 + rand() % 12;
		d = 1 + rand() % 30;
		printf("\nmonth:%d\t day:%d\n\n", m, d);

		SetConsoleTextAttribute(hConsole, 2);
		printf("%d days passed\n\n", d = (m-1) * 30 + d);
		SetConsoleTextAttribute(hConsole, 15);
	}
	break;
	case 3:
	{
		int m, d;
		m = 1 + rand() % 12;
		if ((m < 8 && m % 2 != 0) || (m >= 8 && m % 2 == 0))
			d = 1 + rand() % 31;
		else
			d = 1 + rand() % 30;
		printf("\nmonth: %d day: %d\n\n", m, d);

		if (m % 2 == 0)
			d = (m - 1) / 2 * (30 + 31) + d + 31;
		else
			d = (m - 1) / 2 * (30 + 31) + d;

		SetConsoleTextAttribute(hConsole, 6);
		printf("%d days passed\n\n", d);
		SetConsoleTextAttribute(hConsole, 15);
	}
	break;
	case 4:
	{
		int n = 10 + rand() % 90;
		printf("\n%d\n\n", n);
		printf("first digit: %d \nlast digit: %d\n\n", n / 10, n % 10);
	}
	break;
	case 5:
	{
		int m1, m2, m3, min;
		m1 = -1000 + rand() % 5000;
		m2 = -1000 + rand() % 5000;
		m3 = -1000 + rand() % 5000;
		printf("\n%d %d %d\n\n", m1, m2, m3);

		if (m1 < m2)
			min = m1;
		else
			min = m2;
		if (m3 < min)
			min = m3;
		printf("minimum: %d\n\n", min);
	}
	break;
	case 6:
	{
		int m, n;
		m = 1 + rand() % 10;
		n = 1 + rand() % 100;
		printf("\nm=%d \tn=%d\n\n", m, n);

		if (n%m == 0)
			printf("âòîðîå ÷èñëî êðàòíî ïåðâîìó\n\n");
		else
			printf("âòîðîå ÷èñëî íå êðàòíî ïåðâîìó\n\n");
	}
	break;
	default:
		printf("\nerror: no tasks\n\n");
	}
	goto start;
}
