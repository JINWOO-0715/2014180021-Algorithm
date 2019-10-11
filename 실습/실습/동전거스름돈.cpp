#include<stdio.h>
#include<iostream>


int main()

{
	using namespace std;
	/*  물건을 산다 -> 거스름돈을 받는다 -> 가장 적게 받아야 한다 435000 
	*/
	int price;
	int manwon;
	int chonwon;
	int backwon;
	int sipwon; 
	
	cout << "금액을 입력 하세요" << endl;
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