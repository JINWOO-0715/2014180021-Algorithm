#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <math.h>

#define arr_size 30
double min = -1;
POINT *min_pairs = NULL;

void swap(POINT p[], int a, int b) // 퀵소트를 위한 스왑함수
{
	POINT tmp = p[a];
	p[a] = p[b];
	p[b] = tmp;

}
double distance_of_point(POINT *p1, POINT *p2) // 거리 구하는 함수 
{
	
	double distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));

	if (min == -1 || distance < min)//최소 값을 저장하는데 
	{
		*min_pairs = *p1; // 1번 점 저장
		*(min_pairs + 1) = *p2; // 2번 점 저장
		min = distance; // 최소 거리 저장
	}

	return distance;

}

double Closest_pair(POINT* p, int left, int right, int size)
{
	if (size == 2) // 점이 2개일때
	{
		printf("(%d %d) , (%d,%d) => %f \n", (p + left)->x, (p + left)->y, (p + right)->x, (p + right)->y, distance_of_point(p + left, p + right));
		return distance_of_point(p+left, p + right);// 두 점의 거리를 그냥 출력 하면된다.

	}
	else if (size == 3) // 점이 3개일때 (삼각형 3변의 길이를 다 구한다)
	{
		double distance_a = distance_of_point(p, p + 1);
		double distance_b = distance_of_point(p + 1, p + 2);
		double distance_c = distance_of_point(p + 2, p);
		double min;
		// 구한 값중에서 최소값을 리턴하자
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
		return min; // 삼각형의 변중에서 최소값을 리턴해준다. 
	}
	else // 4개 부터는 2개나 3개가 남을때까지 계속 잘라주는데 
	{

		int mid = (left + right) / 2; // 중간 점을 잡는다
		double distance_range; // 중간영역을 위한 변수 
		double c_right = 0, c_left = 0;  // 중간영역 왼쪽 과 오른쪽 변수.

		// 분할 시 최점점 거리 후보로 두고 이를 범위로 잡음 

		c_left = Closest_pair(p, left, mid, mid - left + 1); // 중앙 기준 왼쪽
		c_right = Closest_pair(p, mid + 1, right, right - mid); // 중앙 기준 오른쪽

		if (c_left > c_right) // 범위중 최소값을 저장한다.
		{
			distance_range = c_right;
		}
		else
		{
			distance_range = c_left;
		}

		POINT *tmp = (POINT*)malloc(sizeof(POINT)*arr_size);// 중간영역 임시 저장을 위한 포인터 

		double min_sub = -1;// 최소값 저장을 위한 변수
		int num = 0;  //중간 영역의 수

		for (int i = left; i <= right; i++) // 
		{
			if (abs((p + i)->x - (p + mid)->x < distance_range)) // 절대값 p+i번째 x - 절대값 p+mid번째 x 가 범위보다 작다면.
			{
				(tmp + num)->x = (p + i)->x; // 임시저장변수 tmp x = p+i의 x
				(tmp + num)->y = (p + i)->y;// 임시저장변수 tmp y = p+i의 y
				num++;// 저장 했으니 숫자를 올린다. 
			}

		}
		

		for (int i = 0; i < num; i++) //임시 저장 값 비교 
		{
			for (int j = i + 1; j < num; j++) 
			{
				if (distance_range > distance_of_point(tmp + i, tmp + j)) // 범위값 > 임시저장 변수 tmp+i번째와 tmp+j번째 
				{
					min_sub = distance_of_point(tmp + i, tmp + j); // 최소값은 mp+i번째와 tmp+j번째의 거리이다.
					printf("(%d %d) , (%d,%d) => %f\n", (tmp + i)->x, (tmp + i)->y, (tmp + j)->x, (tmp + j)->y, distance_of_point((tmp + i), (tmp + j)));

				}
				else
				{
  					min_sub = distance_range; // 그게 아니라면 범위값이 최소값이다.
				}

				if (min_sub < distance_range) // 만약 최소값 < 범위값이라면 
				{
					distance_range = min_sub;// 범위값은 최소값이고
					if (min_sub < min) // 최소값이 전역 최소값보다 작다면
					{
						*min_pairs = *(tmp + i); // 최근접 저장 포인터 = 임시 저장 포인터 +i번째
						*(min_pairs + 1) = *(tmp + j); // 최근접 저장 포인터 2번째점은 *(tmp + j)
					}
				}
			}

		}
		
		if (min_sub == -1)
		{
			printf("범위 내 CPc가 존재하지 않습니다.\n");
		}
		else
		{
				printf("minsub : %lf\n\n", min_sub);
		}


		printf(" 중간 범위 \n");
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

int partition(POINT p[], int left, int right) // 분할 함수 
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
void quick_sort(POINT p[], int left, int right) // 퀵정렬 
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
	POINT * pair = NULL;// 점을 입력 받을 포인터

	pair = (POINT*)malloc(sizeof(POINT)*arr_size); // 포인터 동적할당

	min_pairs = (POINT*)malloc(sizeof(POINT)*arr_size * 2); // 최접점쌍 저장 동적할당.

	POINT point[arr_size] = { {316, 353}, {253, 857}, {743, 851}, {183, 998}, {262, 439}, {330, 732}, {418, 232}, {856, 448},
	{596, 658}, {266, 100}, {890, 793}, {665, 864}, {238, 657}, {636, 731}, {735, 606}, {562, 203}, {492, 701}, {306, 393},
	{798, 939}, {921, 176}, {637, 780}, {620, 975}, {718, 94}, {887, 749},
	{756, 560}, {525, 805}, {229, 29}, {352, 570}, {670, 589}, {644, 821} }; // 점 입력 

	quick_sort(point, 0, arr_size - 1); // 점 퀵소트로 정렬 
	
	printf(" x순서 퀵정렬 후\n ");
	int k = 0;
	for (int i = 0; i < 30; i++)
	{
		k++;
		printf(" (%d %d) ", point[i].x, point[i].y);
		if (k % 10 == 1)
		{
			printf("\n ");
		}
	} // 정렬 출력 
	for (int i = 0; i < arr_size; i++)
	{
		pair[i].x = point[i].x;
		pair[i].y = point[i].y;
	}
	printf("\n ");

	printf("최근접 거리 : %lf\n", Closest_pair(pair, 0, 30 - 1, 30)); // 최근접점 이웃쌍 찾기

	for (int i = 0; i < 2; i++) // 최근접점 이웃쌍 출력
	{
		printf("(%d, %d)\n", (min_pairs + i)->x, (min_pairs + i)->y);
	}
	free(pair);
	free(min_pairs);
	return 0;
}