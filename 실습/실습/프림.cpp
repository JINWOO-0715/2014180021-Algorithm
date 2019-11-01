#include <stdio.h>
#include <limits.h>
#define V 6

int minKey(int key[], bool mstSet[]) // �ּ� ���� ���� �ε��� ��ȯ �Լ� 
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int n, int graph[V][V]) // ��� �Լ� 
{
	int mindist = 0;
	for (int i = 1; i < V; i++)
	{
		printf("���� : (%d , %d), �Ÿ� : %d \n", parent[i], i, graph[i][parent[i]]);
		mindist += graph[i][parent[i]];
	}
	printf("\n�ּҰŸ� : %d\n", mindist);
}

void primMST(int graph[V][V])
{
	int parent[V];  // ���� ���� 6��
	int key[V];   // Ű�� 6��
	bool mstSet[V]; // ���� �ȵ��� Ȯ�ο� 

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false; // Ű�� �ʱ�ȭ �Ұ� �ʱ�ȭ

	key[0] = 0;    // 0���� ���� ǥ�� 
	parent[0] = -1; // 0���� ���� ǥ��

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey(key, mstSet); // memset �� 0�̰� key[]���� ���� �����Ÿ� ���ư��� �ε��� ��ȣ�� ��ȯ

		mstSet[u] = true;

		for (int v = 0; v < V; v++) // �ּ� ���� ã�Ƴ��� ���� 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) // �׷��� ���� ���̰� memSet�� ���ΰ� �׸��� �׷����� Ű��
				                                                           //�ּҺ��� �۴ٸ� 
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