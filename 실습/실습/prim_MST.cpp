#include <stdio.h>
#include <limits.h>
#define V 6

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int n, int graph[V][V])
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
	int parent[V]; 
	int key[V];  
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;    
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int v = 0; v < V; v++)

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
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