//퀵정렬
#include<stdio.h>
void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void quick_sort(int arr[],int left,int right)
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
		quick_sort(arr,left, p-1);
		quick_sort(arr, p+1, right);
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