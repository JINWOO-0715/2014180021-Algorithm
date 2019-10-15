

// 프로그램 코드 2 최대 공약수 

#include<stdio.h>

int Euclid(int a, int b)
{
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
	{
		return a;
	}
	a = a - b;

	return Euclid(a, b);
}
int main()
{
	int num1;
	int num2;

	printf("숫자를 입력하세요 \n");

	scanf_s("%d", &num1);
	scanf_s("%d", &num2);


	printf("최대 공약수 : %d \n", Euclid(num1, num2));
}

