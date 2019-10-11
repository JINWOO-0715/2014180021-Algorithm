#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <math.h>
POINT min_pair_l ;//�ֱ����� ���� ����
POINT min_pair_r;//�ֱ����� ���� ����
double min = -1;


void swap(POINT p[], int a, int b)
{
	POINT tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;

}
double distance_of_point(POINT p1,POINT p2)
{
	int a = p2.x - p1.x;
	int b = p2.y - p1.y;
	double c = sqrt((a * a) + (b * b));
	if (min == -1 || c < min)
	{
		min = c;
		min_pair_l = p1;
		min_pair_r = p2;


	}
	return c;

}

double Closest_pair(POINT* p, int left, int right, int size)
{
	// ���� ó�� 2~ 3���϶� ���ֽð�
	if (size > 4)
	{
		int mid = (left + right) / 2;

		double distange_range;
		double point_left, point_right;

		// ���� �� ������ �Ÿ� �ĺ��� �ΰ� �̸� ������ ����

		POINT tmp[30];// �ӽ� ���� ���� 
		do


	}

}

int partition(POINT p[] ,int left , int right )
{
	int pivot = p[left].x;
	int low = left + 1;
	int high = right;
	while (low <= high)
	{
		while (pivot >= p[low].x && low <= right)
		{
			low++;

		}
		while (pivot <= p[high].x && high >= (left+1))
		{
			high--;;

		}
		if (low <= high)
		{
			swap(p, low, high);
		}
	}
	swap(p, left, high);
	return high;

}
void quick_sort(POINT p[], int left, int right)
{
	if (left <= right) {
		int pivot = partition(p, left, right);
		quick_sort(p, left, pivot - 1);
		quick_sort(p, pivot +1, right);
	}
}
int main()
{

	POINT point[30] = { {316, 353}, {253, 857}, {743, 851}, {183, 998},
	{262, 439}, {330, 732},
	{418, 232}, {856, 448}, {596, 658}, {266, 100}, {890, 793}, {665, 864}, {238, 657}, {636, 731}, {735, 606},
	{562, 203}, {492, 701}, {306, 393}, {798, 939}, {921, 176}, {637, 780}, {620, 975}, {718, 94}, {887, 749}, {756, 560},
	{525, 805}, {229, 29}, {352, 570}, {670, 589}, {644, 821} };
	printf(" x���� ���� ��\n ");
	for (int i = 0; i < 20; i++)
	{
		printf("%d %d \n", point[i].x, point[i].y);
	}
	quick_sort(point, 0, 20 - 1);
	
	printf(" x���� ���� ��\n ");

	for (int i = 0; i < 20; i++)
	{
		printf("%d %d %f \n", point[i].x, point[i].y, distance_of_point(point[i], point[i + 1]));
	}
}