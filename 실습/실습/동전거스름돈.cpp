#include<stdio.h>
#include<iostream>


int main()

{
	using namespace std;
	/*  ������ ��� -> �Ž������� �޴´� -> ���� ���� �޾ƾ� �Ѵ� 435000 
	*/
	int price;
	int manwon;
	int chonwon;
	int backwon;
	int sipwon; 
	
	cout << "�ݾ��� �Է� �ϼ���" << endl;
	cin >> price;
	if (price > 10000)
	{
		manwon =   price/ 10000;
		if (price - (manwon * 10000) > 5000)
		{
			chonwon = price / 10000;
		}
		chonwon = price - (manwon * 10000);
	}

	cout << manwon;

	

	
}