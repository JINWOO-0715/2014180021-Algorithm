

// ���α׷� �ڵ� 2 �ִ� ����� 

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

	printf("���ڸ� �Է��ϼ��� \n");

	scanf_s("%d", &num1);
	scanf_s("%d", &num2);


	printf("�ִ� ����� : %d \n", Euclid(num1, num2));
}

