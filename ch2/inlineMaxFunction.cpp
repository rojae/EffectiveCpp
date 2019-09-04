#include<iostream>

/*
 * Made person: rojae
 * Made date : 2019.09.04
 * inline template 함수를 사용하여 중복을 줄이고
 * 형 변환이 자유롭도록 하자
 */

template<typename T> inline T callWithMax(const T& a, const T& b);


int main(){
		int a = 5, b = 0;
		std::cout << "Max :" << callWithMax(a,b) << '\n';
		std::cout << "Max :" << callWithMax(5.1, 0.1) << '\n';
		std::cout << a << b;
		return 0;
}

template<typename T> inline T callWithMax(const T& a, const T& b){
	return (a > b)? a : b;
}
