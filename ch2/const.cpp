#include<iostream>

/*
 * Made person: rojae
 * Made date : 2019.09.04
 * const의 사용법을 알아본다
 * 상수형 char 포인터에 주의한다
 */

const char* const userName = "rojae";
const std::string txt("hihi");

int main(){
		std::cout << "UserName :" << userName << '\n'
				<< "Message :" << txt << '\n';
		return 0;
}
