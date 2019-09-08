/*
 * Made person: rojae
 * Made date: 2019.09.08
 * --- code description ---
 *  가상 소멸자와 가상 함수를 사용했을 때를 알아본다.
 *  사용했을 때 파생 클래스 소멸자 및 함수가 정상적으로 동작한다는 것을 알 수 있다.
 */
#include<iostream>
#include<unistd.h>

class Base{
		public:
				Base(){
						std::cout << "Base class Create" << '\n';
				}
				virtual ~Base(){
						std::cout << "Base class delete" << '\n';
				}
				virtual void what(){
						std::cout << "Base's what" << '\n';
				}
};

class Derived1 : public Base{
		public:
				Derived1(): Base(){
						std::cout << "Derived1 class Create" << '\n';
				}
				~Derived1(){
						std::cout << "Derived1 class delete" << '\n';
				}
				void what(){
						std::cout << "Derived1 what" << '\n';
				}
};

class Derived2 : public Base{
		public:
				Derived2(): Base(){
						std::cout << "Derived2 class Create" << '\n';
				}
				~Derived2(){
						std::cout << "Derived2 class delete" << '\n';
				}
				void what(){
						std::cout << "Derived2 what" << '\n';
				}
};

int main(){
		Base* p1 = new Derived1;
		Base* p2 = new Derived2;
		p1->what();
		p2->what();
		delete p1;
		delete p2;

		return 0;
}
