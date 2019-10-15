#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <math.h>

#define arr_size 30
double min = -1;
POINT *min_pairs = NULL;

void swap(POINT p[], int a, int b) // ����Ʈ�� ���� �����Լ�
{
	POINT tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;

}
double distance_of_point(POINT *p1, POINT *p2) // �Ÿ� ���ϴ� �Լ� 
{
	
	double distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));

	if (min == -1 || distance < min)//�ּ� ���� �����ϴµ� 
	{
		*min_pairs = *p1; // 1�� �� ����
		*(min_pairs + 1) = *p2; // 2�� �� ����
		min = distance; // �ּ� �Ÿ� ����
	}

	return distance;

}

double Closest_pair(POINT* p, int left, int right, int size)
{
	if (size == 2) // ���� 2���϶�
	{
		printf("(%d %d) , (%d,%d) => %f \n", (p + left)->x, (p + left)->y, (p + right)->x, (p + right)->y, distance_of_point(p + left, p + right));
		return distance_of_point(p+left, p + right);// �� ���� �Ÿ��� �׳� ��� �ϸ�ȴ�.

	}
	else if (size == 3) // ���� 3���϶� (�ﰢ�� 3���� ���̸� �� ���Ѵ�)
	{
		double distance_a = distance_of_point(p, p + 1);
		double distance_b = distance_of_point(p + 1, p + 2);
		double distance_c = distance_of_point(p + 2, p);
		double min;
		// ���� ���߿��� �ּҰ��� ��������
		if (distance_a > distance_b)
		{
			printf("(%d %d) , (%d,%d) => %f \n", (p + 1)->x, (p + 1)->y, (p + 2)->x, (p + 2)->y, distance_of_point(p + 1, p + 2));

			min = distance_b;
		}
		else
		{
			printf("(%d %d) , (%d,%d) => %f \n", p->x, p->y, (p + 1)->x, (p + 1)->y, distance_of_point(p, p + 1));
				min = distance_a;
		}

		if (distance_b > distance_c)
		{
			printf("(%d %d) , (%d,%d) => %f \n",  (p + 2)->x, (p + 2)->y, (p + 0)->x, (p + 0)->y, distance_of_point(p + 2, p + 0));
			min = distance_c;
		}
		else
		{
			printf("(%d %d) , (%d,%d) => %f \n", (p + 1)->x, (p + 1)->y, (p + 2)->x, (p + 2)->y, distance_of_point(p + 1, p + 2));
			min = distance_b;
		}
		if (distance_a > distance_c)
		{
			min = distance_c;
			printf("(%d %d) , (%d,%d) => %f \n", (p + 2)->x, (p + 2)->y, (p + 0)->x, (p + 0)->y, distance_of_point(p + 2, p + 0));

		}
		else
		{
			printf("(%d %d) , (%d,%d) => %f \n", p->x, p->y, (p + 1)->x, (p + 1)->y, distance_of_point(p, p + 1));

			min = distance_a;
		}
		return min; // �ﰢ���� ���߿��� �ּҰ��� �������ش�. 
	}
	else // 4�� ���ʹ� 2���� 3���� ���������� ��� �߶��ִµ� 
	{

		int mid = (left + right) / 2; // �߰� ���� ��´�
		double distance_range; // �߰������� ���� ���� 
		double c_right = 0, c_left = 0;  // �߰����� ���� �� ������ ����.

		// ���� �� ������ �Ÿ� �ĺ��� �ΰ� �̸� ������ ���� 

		c_left = Closest_pair(p, left, mid, mid - left + 1); // �߾� ���� ����
		c_right = Closest_pair(p, mid + 1, right, right - mid); // �߾� ���� ������

		if (c_left > c_right) // ������ �ּҰ��� �����Ѵ�.
		{
			distance_range = c_right;
		}
		else
		{
			distance_range = c_left;
		}

		POINT *tmp = (POINT*)malloc(sizeof(POINT)*arr_size);// �߰����� �ӽ� ������ ���� ������ 

		double min_sub = -1;// �ּҰ� ������ ���� ����
		int num = 0;  //�߰� ������ ��

		for (int i = left; i <= right; i++) // 
		{
			if (abs((p + i)->x - (p + mid)->x < distance_range)) // ���밪 p+i��° x - ���밪 p+mid��° x �� �������� �۴ٸ�.
			{
				(tmp + num)->x = (p + i)->x; // �ӽ����庯�� tmp x = p+i�� x
				(tmp + num)->y = (p + i)->y;// �ӽ����庯�� tmp y = p+i�� y
				num++;// ���� ������ ���ڸ� �ø���. 
			}

		}
		

		for (int i = 0; i < num; i++) //�ӽ� ���� �� �� 
		{
			for (int j = i + 1; j < num; j++) 
			{
				if (distance_range > distance_of_point(tmp + i, tmp + j)) // ������ > �ӽ����� ���� tmp+i��°�� tmp+j��° 
				{
					min_sub = distance_of_point(tmp + i, tmp + j); // �ּҰ��� mp+i��°�� tmp+j��°�� �Ÿ��̴�.
					printf("(%d %d) , (%d,%d) => %f\n", (tmp + i)->x, (tmp + i)->y, (tmp + j)->x, (tmp + j)->y, distance_of_point((tmp + i), (tmp + j)));

				}
				else
				{
  					min_sub = distance_range; // �װ� �ƴ϶�� �������� �ּҰ��̴�.
				}

				if (min_sub < distance_range) // ���� �ּҰ� < �������̶�� 
				{
					distance_range = min_sub;// �������� �ּҰ��̰�
					if (min_sub < min) // �ּҰ��� ���� �ּҰ����� �۴ٸ�
					{
						*min_pairs = *(tmp + i); // �ֱ��� ���� ������ = �ӽ� ���� ������ +i��°
						*(min_pairs + 1) = *(tmp + j); // �ֱ��� ���� ������ 2��°���� *(tmp + j)
					}
				}
			}

		}
		
		if (min_sub == -1)
		{
			printf("���� �� CPc�� �������� �ʽ��ϴ�.\n");
		}
		else
		{
				printf("minsub : %lf\n\n", min_sub);
		}


		printf(" �߰� ���� \n");
		printf("distance_range : %lf\n", distance_range);
		for (int i = 0; i < num; i++)
		{

			printf("(%d,%d)", tmp[i].x, tmp[i].y);

		}
		printf("\n");

		free(tmp);
		return distance_range;
	}

}

int partition(POINT p[], int left, int right) // ���� �Լ� 
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
		while (pivot <= p[high].x && high >= (left + 1))
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
void quick_sort(POINT p[], int left, int right) // ������ 
{
	if (left <= right)
	{
		int pivot = partition(p, left, right);
		quick_sort(p, left, pivot - 1);
		quick_sort(p, pivot + 1, right);
	}
}
int main()
{
	POINT * pair = NULL;// ���� �Է� ���� ������

	pair = (POINT*)malloc(sizeof(POINT)*arr_size); // ������ �����Ҵ�

	min_pairs = (POINT*)malloc(sizeof(POINT)*arr_size * 2); // �������� ���� �����Ҵ�.

	POINT point[arr_size] = { {316, 353}, {253, 857}, {743, 851}, {183, 998}, {262, 439}, {330, 732}, {418, 232}, {856, 448},
	{596, 658}, {266, 100}, {890, 793}, {665, 864}, {238, 657}, {636, 731}, {735, 606}, {562, 203}, {492, 701}, {306, 393},
	{798, 939}, {921, 176}, {637, 780}, {620, 975}, {718, 94}, {887, 749},
	{756, 560}, {525, 805}, {229, 29}, {352, 570}, {670, 589}, {644, 821} }; // �� �Է� 

	quick_sort(point, 0, arr_size - 1); // �� ����Ʈ�� ���� 
	
	printf(" x���� ������ ��\n ");
	int k = 0;
	for (int i = 0; i < 30; i++)
	{
		k++;
		printf(" (%d %d) ", point[i].x, point[i].y);
		if (k % 10 == 1)
		{
			printf("\n ");
		}
	} // ���� ��� 
	for (int i = 0; i < arr_size; i++)
	{
		pair[i].x = point[i].x;
		pair[i].y = point[i].y;
	}
	printf("\n ");

	printf("�ֱ��� �Ÿ� : %lf\n", Closest_pair(pair, 0, 30 - 1, 30)); // �ֱ����� �̿��� ã��

	for (int i = 0; i < 2; i++) // �ֱ����� �̿��� ���
	{
		printf("(%d, %d)\n", (min_pairs + i)->x, (min_pairs + i)->y);
	}
	free(pair);
	free(min_pairs);
	return 0;
}