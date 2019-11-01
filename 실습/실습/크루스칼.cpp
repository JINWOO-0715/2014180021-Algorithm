#include<stdio.h>


#define v 6

int parent[v]; // 각 정점의 부모 노드 
int num[v]; //각 집합의 크기

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
	int p, s, i = -1; //p는 부모 노드 

	// 루트노드까지 반복한다 .p가 -1이면 반복문을 종료한다
	for ( i = point; (p = parent[i]) >= 0; i = p);
	s = i; //루트노트 정보를 s에 저장
	// 모든 노드를 i로 순회 부모가 s(루트노드)에 되도록 설정한다
	for (i = point; (p = parent[i]) >= 0; i = p)
		parent[i] = s;

	return s; //모든 노드의 부모인 루트를 반환한다
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

// 다 끊어버린다 가중치 오름차순으로 정렬 한다 
void find_min() {
	int E[2][v]; // 임시 저장 
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