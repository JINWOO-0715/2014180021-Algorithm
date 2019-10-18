
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int list[], int left, int right)
{
	int p = list[left];
	int l = left + 1;
	int h = right;

	while (l <= h)
	{
		while (p >= list[l] && l <= right)
		{
			l++;
		}
		while (p <= list[h] && h >= (left + 1))
		{
			h--;
		}
		if (l <= h)
		{
			swap(&list[h], &list[l]);
		}
	}
	swap(&list[left], &list[h]);
	return h;
}
int q_serch(int list[], int left, int right,int num)
{
	int p = Partition(list, left, right);
	if (p == num)
	{
		return list[p];
	}
	else if (p > num)
	{
		q_serch(list, left, p - 1, num);
	}
	else
	{
		q_serch(list, p + 1, right, num);
	}

}

void Q_sort(int list[], int left, int right)
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
		Q_sort(list, left, p - 1);
		Q_sort(list, p + 1, right);
	}
}

int sorted[10];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
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
		merge(list, left,mid, right);
	}
}
struct Node
{
	int value;
	struct Node* leftChild;
	struct Node* rightChild;
};

Node* root = NULL;

Node* BST_insert(Node* root, int value)
{
	if (root == NULL)
	{
		root = (Node*)malloc(sizeof(Node));
		root->leftChild = root->rightChild = NULL;
		root->value = value;
		return root;
	}
	else
	{
		if (root->value > value)
			root->leftChild = BST_insert(root->leftChild, value);
		else
			root->rightChild = BST_insert(root->rightChild, value);
	}
	return root;
}
Node* findMinNode(Node* root)
{
	Node* tmp = root;
	while (tmp->leftChild != NULL)
		tmp = tmp->leftChild;
	return tmp;
}
Node* BST_delete(Node* root, int value)
{
	Node* tNode = NULL;
	if (root == NULL)
		return NULL;

	if (root->value > value)
		root->leftChild = BST_delete(root->leftChild, value);
	else if (root->value < value)
		root->rightChild = BST_delete(root->rightChild, value);
	else
	{
		// 자식 노드가 둘 다 있을 경우
		if (root->rightChild != NULL && root->leftChild != NULL)
		{
			tNode = findMinNode(root->rightChild);
			root->value = tNode->value;
			root->rightChild = BST_delete(root->rightChild, tNode->value);
		}
		else
		{
			tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
			free(root);
			return tNode;
		}
	}

	return root;
}
Node* BST_search(Node* root, int value)
{
	if (root == NULL)
		return NULL;

	if (root->value == value)
		return root;
	else if (root->value > value)
		return BST_search(root->leftChild, value);
	else
		return BST_search(root->rightChild, value);
}
void BST_print_f(Node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->value);
	BST_print_f(root->leftChild);
	BST_print_f(root->rightChild);

}
void BST_print_c(Node* root)
{
	if (root == NULL)
		return;

	BST_print_c(root->leftChild);
	printf("%d ", root->value);
	BST_print_c(root->rightChild);
}
void BST_print_b(Node* root)
{

	if (root == NULL)
		return;
	BST_print_b(root->leftChild);
	BST_print_b(root->rightChild);
	printf("%d ", root->value);

}




int main()
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
	Q_sort(arr, 0, 19);
	merge_sort(arr, 0, count - 1);

	for (int i = 0; i < count; i++)
	{
		printf("%d ", arr[i]);
	}

}
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