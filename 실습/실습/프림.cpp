#include <stdio.h>
#include <limits.h>
#define V 6

int minKey(int key[], bool mstSet[]) // 최소 값을 가진 인덱스 반환 함수 
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int n, int graph[V][V]) // 출력 함수 
{
	int mindist = 0;
	for (int i = 1; i < V; i++)
	{
		printf("간선 : (%d , %d), 거리 : %d \n", parent[i], i, graph[i][parent[i]]);
		mindist += graph[i][parent[i]];
	}
	printf("\n최소거리 : %d\n", mindist);
}

void primMST(int graph[V][V])
{
	int parent[V];  // 지정 정점 6개
	int key[V];   // 키값 6개
	bool mstSet[V]; // 들어갔다 안들어갔다 확인용 

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false; // 키값 초기화 불값 초기화

	key[0] = 0;    // 0번지 본거 표시 
	parent[0] = -1; // 0번지 본거 표시

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey(key, mstSet); // memset 이 0이고 key[]값중 제일 작은거를 돌아가며 인덱스 번호를 반환

		mstSet[u] = true;

		for (int v = 0; v < V; v++) // 최소 값을 찾아내는 과정 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) // 그래프 값이 참이고 memSet중 참인값 그리고 그래프의 키가
				                                                           //최소보다 작다면 
				parent[v] = u, key[v] = graph[u][v];   // parent 
	}

	printMST(parent, V, graph);
}

int main()
{
	int graph[][V] = {
	{0,3,2,0,4,0},
	{3,0,4,1,0,2},
	{2,4,0,0,5,7},
	{0,1,0,0,0,1},
	{4,0,5,0,0,9},
	{0,2,7,1,9,0}
	};
	

	primMST(graph);

	return 0;

}