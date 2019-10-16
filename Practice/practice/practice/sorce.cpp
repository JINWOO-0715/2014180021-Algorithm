
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Partition(int list[], int left, int right)
{
	int pivot = list[left]; // 피벗의 위치는 가장 왼쪽에서 시작
	int low = left + 1;
	int high = right;


	while (low <= high) // 교차되기 전까지 반복한다 
	{
		while (pivot >= list[low] && low <= right) // 피벗보다 큰 값을 찾는 과정 
		{
			low++; // low를 오른쪽으로 이동 
		}

		while (pivot <= list[high] && high >= (left + 1)) // 피벗보다 작은 값을 찾는 과정 
		{
			high--; // high를 왼쪽으로 이동
		}

		if (low <= high)// 교차되지 않은 상태이면 스왑 과정 실행 
		{
			swap(&list[low], &list[high]); //low와 high를 스왑 
		}

	}
	swap(&list[left], &list[high]);; // 피벗과 high가 가리키는 대상을 교환 
	return high;  // 옮겨진 피벗의 위치정보를 반환 

}



int QuickSearch(int list[], int left, int right, int k)
{
	int pivot = Partition(list, left, right); // 둘로 나누어서
	if (pivot == k)
		return list[pivot];

	else if (pivot > k)
		QuickSearch(list, left, pivot - 1, k); // 왼쪽 영역을 정렬한다.

	else
		QuickSearch(list, pivot + 1, right, k); // 오른쪽 영역을 정렬한다.
}




void main()
{

	int arr[20] = { 0, };
	printf("배열 \n");
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		arr[i] = rand() % 999;
	
	for (int i = 0; i < 20; i++)
		printf(" %d ", arr[i]);
	printf("\n");

	int num;
	while (1)
	{
		
		for (int i = 0; i < 20; i++)
		{
			printf(" %d ", arr[i]);
		}
		printf("작은 숫자 찾기 원하는 숫자입력 : \n");
		scanf("%d", &num);
		num = num - 1;
		printf("작은 숫자 %d \n", QuickSearch(arr, 0, 19,num));
	}

}
*/


/* 머지소트
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
*/

/*퀵정렬

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int list[],int left, int right)
{
	int p = left;
	int j = p;
	int i = left + 1;

	if (left < right)
	{
		for (; i <= right; i++)
		{
			if (list[i] < list[p])
			{
				j++;
				swap(&list[j], &list[i]);
			}
		}
		swap(&list[left], &list[j]);
		p = j;
		quick_sort(list, left, p - 1);
		quick_sort(list, p + 1, right);
	}

}
void main()
{

	srand(time(NULL));
	int arr[6];
	for (int i = 0; i < 6; i++)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < 6; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf(" \n ");
	quick_sort(arr,0,5);
	for (int i = 0; i < 6; i++)
	{
		printf(" %d ", arr[i]);
	}




}*/


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