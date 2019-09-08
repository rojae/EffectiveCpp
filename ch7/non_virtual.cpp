#include<iostream>
#include<unistd.h>

class Base{
		public:
				Base(){
						std::cout << "Base class Create" << '\n';
				}
				~Base(){
						std::cout << "Base class delete" << '\n';
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
};

class Derived2 : public Base{
		public:
				Derived2(): Base(){
						std::cout << "Derived2 class Create" << '\n';
				}
				~Derived2(){
						std::cout << "Derived2 class delete" << '\n';
				}
};

int main(){
		Base* p1 = new Derived1;
		Base* p2 = new Derived2;
		delete p1;
		delete p2;

		return 0;
}
