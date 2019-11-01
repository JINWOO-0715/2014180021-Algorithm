//퀵정렬
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int quick_sort(int arr[], int left, int right)
{
	int base = arr[right];
	int i = left - 1, j;
	for (j = left; j < right; j++) {
		if (arr[j] < base)
		{
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	++i;
	swap(&arr[i], &arr[right]);

	return i;
}
int qucik_search(int arr[], int left, int right, int k)
{
	if (left < right)
	{
		int t = quick_sort(arr, left, right);
		if (t == k)
			return arr[t];
		else if (t > k)
			qucik_search(arr, left, t - 1, k);
		else
			qucik_search(arr, t + 1, right, k);
	}
}

int main()
{
	int arr[10] = { 0, };
	printf("배열 \n");
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 999;

	for (int i = 0; i < 10; i++)
		printf(" %d ", arr[i]);

	printf("\n");

	int num;
	while (1)
	{
		printf("작은 숫자 찾기 원하는 숫자입력 : \n");
		scanf("%d", &num);
		printf("작은 숫자 %d \n", qucik_search(arr, 0, 9, num+1));
	}

}


/* 하노이탑
#include<stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
if (n == 1)
printf("원판 1을 %c 에서 %c으로 옮긴다 \n", from, to);
else {
hanoi_tower(n - 1, from, to, tmp);
printf("원판 %d 를 %c에서 %c으로 옮긴다 \n", n, from, to);
hanoi_tower(n - 1, tmp, from, to);
}
}

int main()
{
hanoi_tower(4, 'A', 'B', 'C');

return 0;
}*/