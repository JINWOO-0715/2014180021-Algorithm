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

int prim_graph[][v] = {
	{0,3,2,0,4,0},
	{3,0,4,1,0,2},
	{2,4,0,0,5,7},
	{0,1,0,0,0,1},
	{4,0,5,0,0,9},
	{0,2,7,1,9,0}

};

void prim(int list[][v] , int num) {

	int From[v] = { 1, };
	int Dist[v] = { 0, };
	int Dist_index;
	int list_index =0;

	int T[2][v];
	
	for (int i = num; i < v; i++)
	{
		int min = 9999;
		for (int j = i+1; j < v; j++)
		{
			From[i] = 0;
			Dist[j] = list[i][j];
			if (Dist[j] < min)
			{
				Dist_index = j;
			}
			Dist[Dist_index] = 0;
			T[0][list_index] = Dist_index;
			T[1][list_index] = i;
		}
	}
	
}

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