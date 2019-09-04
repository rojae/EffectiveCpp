#include<iostream>

/*
 * Made Person : rojae
 * Made date : 2019.09.04
 * define의 비효율적인 면을 알아보자
 * 실제로 동작시키면 예상치 못한 동작 발생
 * 심지어 호출 횟수만큼 사본이 생기게 된다.
 */
#define CALL_WITH_MAX(a,b) ((a) > (b) ? (a) : (b))

int main(){
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	CALL_WITH_MAX(++a, b+10);
	std::cout << a << b;
	return 0;
}
