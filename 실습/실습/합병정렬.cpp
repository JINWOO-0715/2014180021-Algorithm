#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>

int arr[20] = { 0, };

int *arr2 = new int[20];
void merge_sort( int left, int right)
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