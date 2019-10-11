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

	while (i <= mid && j <= right) // �ε��� ã�� 
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
	int temp = i > mid ? j : i; // ������ ä���� ã�� (�߰����� ������ ���� ũ�� ������)
	while (k <= right)
	{
		arr2[k++] = arr[temp++]; //ã�� ��ġ�� �ӽ� �迭���� �־����
	}
	for (int i = left; i <= right; i++)
		arr[i] = arr2[i];// arr�� arr2���� �־��ش� .
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
	printf("���� �� \n");
	print_arry(arr, n);
	printf("���� �� \n");
	partition(0, 19);
	print_arry(arr, n);

	int a = 0;

}