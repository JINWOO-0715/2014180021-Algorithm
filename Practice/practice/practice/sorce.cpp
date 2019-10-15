
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int sorted[10];
void merge(int list[], int left, int mid, int right)
{
	int i, k, j, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}
	
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sorted[k++] = list[l];
		}
	}
	else
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = list[l];
		}
	}
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
int main(void)
{
	int arr[20];
	int count = 20;
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	merge_sort(arr, 0, count - 1);

	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}
}

/*퀵정렬
#include<stdio.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int arr[], int left, int right)
{
	int p = left;
	int  j = p;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (arr[i] < arr[p]) {
				j++;
				swap(&arr[j], &arr[i]);
			}
		}
		swap(&arr[left], &arr[j]);
		p = j;
		quick_sort(arr, left, p - 1);
		quick_sort(arr, p + 1, right);
	}
}*/
/*
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
	int arr[20] = { 0, };
	printf("배열 \n");
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		arr[i] = rand() % 999;
	quick_sort(arr, 0, 19);
	for (int i = 0; i < 20; i++)
		printf(" %d ", arr[i]);

	printf("\n");

	int num;
	while (1)
	{
		printf("작은 숫자 찾기 원하는 숫자입력 : \n");
		scanf("%d", &num);
		printf("작은 숫자 %d \n", qucik_search(arr, 0, 9, num));
	}

}
*/


/*퀵정렬
#include<stdio.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int arr[], int left, int right)
{
	int p = left;
	int  j = p;
	int i = left + 1;

	if (left < right) {
		for (; i <= right; i++) {
			if (arr[i] < arr[p]) {
				j++;
				swap(&arr[j], &arr[i]);
			}
		}
		swap(&arr[left], &arr[j]);
		p = j;
		quick_sort(arr, left, p - 1);
		quick_sort(arr, p + 1, right);
	}
}

int main()
{
	int arr[10] = { 31,8,48,73,11,3,20,29,65,15 };
	printf("퀵 정렬 하기 전 \n");
	for (int i = 0; i < 10; i++)
		printf(" %d ", arr[i]);
	quick_sort(arr, 0, 9);
	printf("\n");
	printf("퀵 정렬 하기 후 \n");
	for (int i = 0; i < 10; i++)
		printf(" %d ", arr[i]);
}
*/




/* 합병 머지 정렬
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>

int arr[20] = { 0, };

int *arr2 = new int[20];
void merge_sort(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) // 인덱스 찾기
	{
		if (arr[i] <= arr[j])
		{
			arr2[k++] = arr[i++];
		}
		else
		{
			arr2[k++] = arr[j++];
		}
	}
	int temp = i > mid ? j : i; // 어디먼저 채울지 찾기 (중간보다 작으면 왼쪽 크면 오른쪽)
	while (k <= right)
	{
		arr2[k++] = arr[temp++]; //찾은 위치로 임시 배열값에 넣어놓기
	}
	for (int i = left; i <= right; i++)
		arr[i] = arr2[i];// arr에 arr2값을 넣어준다 .
}
void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);

		merge_sort(left, right);

	}
}
void print_arry(int arr[], int a)
{

	printf("[%d] \n", arr[a]);
	a++;

	if (a == 20)
	{
		return;
	}
	return print_arry(arr, a);
}


int main()
{

	int n = 0;
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		arr[i] = rand() % 1000;
	}
	printf("정렬 전 \n");
	print_arry(arr, n);
	printf("정렬 후 \n");
	partition(0, 19);
	print_arry(arr, n);

	int a = 0;

}

*/




/* 최대 공약수

#include<stdio.h>

int Euclid(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
	{
		return a;
	}
	a = a - b;

	return Euclid(a, b);
}
int main()
{
	int num1;
	int num2;

	printf("숫자를 입력하세요 \n");

	scanf_s("%d", &num1);
	scanf_s("%d", &num2);


	printf("최대 공약수 : %d \n", Euclid(num1, num2));
}

*/


/*
거스름돈 알고리즘
#include<stdio.h>

void main()
{
	int coin[6] = { 5000,1000,500,100,50,10 };
	int change, i, count[6];

	scanf("%d", &change);

	for (int i=0; i < 6; i++) {

		count[i] = change / coin[i];
		change = change % coin[i];
		printf("%d원 잔돈 : %d개 \n ", coin[i], count[i]);
	}
}*/