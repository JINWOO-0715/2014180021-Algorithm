#include<stdio.h>


#define v 6

int parent[v]; // �� ������ �θ� ��� 
int num[v]; //�� ������ ũ��

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		parent[i] = -1;
		num[i] = -1;
	}
}

int set_find(int point)
{
	int p, s, i = -1; //p�� �θ� ��� 

	// ��Ʈ������ �ݺ��Ѵ� .p�� -1�̸� �ݺ����� �����Ѵ�
	for ( i = point; (p = parent[i]) >= 0; i = p);
	s = i; //��Ʈ��Ʈ ������ s�� ����
	// ��� ��带 i�� ��ȸ �θ� s(��Ʈ���)�� �ǵ��� �����Ѵ�
	for (i = point; (p = parent[i]) >= 0; i = p)
		parent[i] = s;

	return s; //��� ����� �θ��� ��Ʈ�� ��ȯ�Ѵ�
}

void set_union(int p1, int p2)
{
	if (num[p1] < num[p2])
	{
		parent[p1] = p2;
		num[p2] += num[p1];

	}
	else
	{
		parent[p2] = p1;
		num[p1] += num[p2];
	}
}
int graph[][v]= {
{0,8,2,0,4,0},
{8,0,4,1,0,2},
{2,4,0,0,3,7},
{0,1,0,0,0,1},
{4,0,3,0,0,9},
{0,2,7,1,9,0}};

// �� ��������� ����ġ ������������ ���� �Ѵ� 
void find_min() {
	int E[2][v]; // �ӽ� ���� 
	int k=0, l=0;
	for (int i = 0; i < v; i++)
	{
		for (int j = i+1; j < v; j++)
		{
			if (graph[i][j] != 0)
			{
				E[k][l] = 
			}
		}
		printf(" \n ");
	}


}


int main() {
	find_min();
}