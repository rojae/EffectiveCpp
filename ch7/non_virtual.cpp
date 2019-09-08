/*
 * Made person: rojae
 * Made date: 2019.09.08
 * --- code description ---
 *  1. 가상 소멸자를 사용했을 때와 아닐 때를 비교한다.
 *  2. 가상 함수를 사용했을 때와 아닐 때를 비교한다.
 *  우선 사용하지 않았을 경우.
 */
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
                void what(){
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

