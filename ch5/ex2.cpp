/*
 * Made person: rojae
 * Made date: 2019.09.05
 * --- code description ---
 *  생성자, 소멸자, 복사 생성자를 작성해보자
 */

#include<iostream>

class Empty{
		public:
				Empty(){
						std::cout << ".... Constructor .... " << '\n';
				}
				Empty(const Empty& rhs){
						std::cout << ".... Copy constructor ...." << '\n';
				}
				~Empty(){
						std::cout << ".... destructor ...." << '\n';
				}
				Empty& operator = (const Empty& rhs){
					std::cout << "Copy insert operator" << '\n';
				}
};

int main(){
		Empty e1;
		Empty e2(e1);
		e2 = e1;
		return 0;
}
