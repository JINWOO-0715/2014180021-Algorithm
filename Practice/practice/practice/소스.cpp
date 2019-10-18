

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct  node
{
	int value;
	node* left_child;
	node* right_child;
};



node* tree_insert(node * root, int value)
{
	if (root == NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->left_child = root->right_child = NULL;
		root->value = value;
		return root;
	}
	else
	{
		if (root->value > value)
		{
			root->left_child = tree_insert(root->left_child, value);
		}
		else
		{
			root->right_child = tree_insert(root->right_child, value);

		}
	}
	return root;
}

node * find_min_node(node *root)
{
	node *tmp = root;
	while (tmp->left_child != NULL)
	{
		tmp = tmp->left_child;
	}
	return tmp;
}
node * tree_delete(node*root,int value)
{
	node* tnode = NULL;
	if (root == NULL)
		return NULL;

	if (root->value > value)
	{
		root->left_child = tree_delete(root->left_child, value);
	}
	else if (root->value < value)
	{
		root->right_child = tree_delete(root->right_child, value);
	}
	else
	{
		if (root->left_child  !=NULL && root->right_child !=NULL)
		{
			tnode = find_min_node(root->right_child);
			root->value = tnode->value;
			root->right_child = tree_delete(root->right_child, tnode->value);
		}
		else
		{
			tnode = (root->left_child == NULL) ? root->left_child : root->right_child;
			free(tnode);
			return tnode;
		}
	}

}
node * tree_search(node* root, int value)
{

}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void Q_sort(int list[], int left, int right)
{
	int p = left;
	int i = left + 1;
	int j = p;

	if (left < right)
	{
		for (; i <= right; i++)
		{
			if (list[p] > list[i])
			{
				swap(&list[j], &list[i]);
			}
		}
		swap(&list[left], &list[j]);
		j = p;
		Q_sort(list, left, p - 1);
		Q_sort(list, p + 1, right);

	}
}
int Q_serach_Partition(int list[], int left, int right)
{
	int p = list[left];
	int h = right;
	int l = left + 1;

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

	swap(&list[h], &list[left]);
	return h;
}
int Q_search(int list[], int left, int right,int num)
{
	int p = Q_serach_Partition(list, left, right);
	if (p == num)
	{
		return list[p];
	}
	else if (p > num)
	{
		Q_search(list, left, p - 1,num);
	}
	else
	{
		Q_search(list, p + 1, right, num);
	}

}
int sorted[5];
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (list[i]<=list[j])
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}
	if (i>mid)
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
	for (l=left;l<=right;l++)
	{
		list[l] = sorted[l];
	}

}
void merge_sorr(int list[], int left, int right)
{
	int mid;
	if (left <right)
	{
		mid = (left + right) / 2;
		merge_sorr(list, left, mid);
		merge_sorr(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
void BST_print_f(node* root)
{
	if (root == NULL)
		return;

	printf("%d ", root->value);
	BST_print_f(root->left_child);
	BST_print_f(root->right_child);

}
void BST_print_c(node* root)
{
	if (root == NULL)
		return;

	BST_print_c(root->left_child);
	printf("%d ", root->value);
	BST_print_c(root->right_child);
}
void BST_print_b(node* root)
{

	if (root == NULL)
		return;
	BST_print_b(root->left_child);
	BST_print_b(root->right_child);
	printf("%d ", root->value);

}

int main()
{
	int arr[20];
	int count = 20;
	srand(time(NULL));

	int num = 0;

	node* root = NULL;
	for (int i = 0; i < 20; i++)
	{
		root = tree_insert(root, rand()%999);
	}
	printf(" 후위 \n");
	BST_print_b(root);
	printf("  \n");

	printf(" 중위 \n");
	BST_print_c(root);
	printf("  \n");

	printf(" 전위 \n");
	BST_print_f(root);
	printf("  \n");
	while (1)
	{
		scanf("%d", &num);
		tree_delete(root, num);
		printf("  \n");
		printf(" 중위 \n");
		BST_print_c(root);

	}

}