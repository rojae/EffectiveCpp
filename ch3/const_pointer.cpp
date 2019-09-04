/*
 *	Made person: rojae
 *	Made date: 2019.09.04
 *	--- Code description --- 
 *	포인터와 const가 만나게 되면
 *	어떠한 결과를 발생시키는지 알아보고
 *	4가지 종류의 const pointer를 알아보자
 */
#include<iostream>

int main(){
		int b = 9;
		const int *a = &b;			// 비상수 포인터, 상수 데이터
									// 포인터가 가르치는 대상이 상수
									
		std::cout << "a :" << *a
			   	<< " b :" << b;

		int c = 9;
		int * const d = &c;			// 상수 포인터, 비상수 데이터
									// 포인터 자체가 상수	

		std::cout << " c :" << c
					<< " d :" << *d;
		//*a = c;						// 상수 데이터이기 때문에 값 변경 불가
		*d = b;

		return 0;
}
