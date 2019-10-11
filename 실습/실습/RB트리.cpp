#include <stdio.h>
#include <stdlib.h>
#define Black 1
#define Red 0
struct Node
{
	int value;
	int color;
	struct Node* parent;
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
		root->color = Black;
		return root;
	}
	else
	{
		if (root->value > value)
		{
			root->leftChild = BST_insert(root->leftChild, value);
			root->leftChild->color = Red;
		}
		else
		{
			root->rightChild = BST_insert(root->rightChild, value);
			root->rightChild->color = Red;
		}

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
void BST_print(Node* root)
{
	if (root == NULL)
		return;



	BST_print(root->leftChild);
	printf("(%d,%d) ", root->value,root->color);
	BST_print(root->rightChild);

}

int main()
{
	root = BST_insert(root, 40);
	root = BST_insert(root, 90);
	root = BST_insert(root, 15);
	root = BST_insert(root, 60);
	root = BST_insert(root, 44);
	root = BST_insert(root, 20);
	root = BST_delete(root, 5);

	BST_print(root);
}