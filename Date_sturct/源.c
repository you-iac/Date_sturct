//#include"Date_Struct.h"
#include<stdlib.h>
#include<stdio.h>
/*
5 3
46 23 26 24 10
5 4 3
*/

typedef struct node {
	int Date[1000];
	int max;
} HTree;
void swp(int* P, int* Q);
void creat(HTree* H, int n);
void Print(HTree* H, int m);
main()
{
	HTree H;
	int n = 0, m = 0, i = 0;
	scanf_s("%d %d", &n, &m);
	creat(&H, n);
	Print(&H, m);
}

void creat(HTree* H, int n)
{
	int i = 0, BUFF = 0;
	H->Date[0] = -9999999;
	H->max = 0;
	for (i = 1; i <= n; i++) {
		H->max++;
		BUFF = H->max;
		scanf_s("%d", &H->Date[BUFF]);

		while (H->Date[BUFF] < H->Date[BUFF/2]) {
			swp(&H->Date[BUFF], &H->Date[BUFF / 2]);
			BUFF /= 2;
		}
	}
}

void Print(HTree* H, int m)
{
	int i = 0, BUFF = 0;
	for (i = 0; i < m; i++) {
		scanf_s("%d", &BUFF);
		while (BUFF != 0) {
			printf("%d ", H->Date[BUFF]);
			BUFF /= 2;
		}printf("\n");
	}
}

void swp(int* P, int* Q)
{
	*P = *P + *Q;
	*Q = *P - *Q;
	*P = *P - *Q;
}
