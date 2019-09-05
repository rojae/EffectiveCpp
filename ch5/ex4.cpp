/*
 * Made person: rojae;
 * Made date: 2019.09.05
 * --- code description ---
 *  복사 대입 연산자가 자동으로 생성되지 않는 경우를 알아본다
 *  결과적으로 컴파일 오류가 발생하게 된다.
 *  참조자나 상수를 품고 있는 객체를 복사 대입하기 위해서는
 *  직접 복사 대입 연산자를 정의해야한다.
 */

#include<iostream>

template<class T> 
class NamedObject { 
		public: 
				// 이 생성자는 이제 상수 타입의 name을 취하지 않는다. 
				// nameValue가 비상수 string의 참조자가 되었기 때문이다. 
				// 또한, 참조할 string을 가져야 하기 때문에 char* 는 없애 버렸다. 
				 NamedObject(std::string& name, const T& value);  
				// operator= 는 선언되지 않았다고 가정 
		private:
						 std::string& nameValue; // 참조자 
						 const T objectValue; // 상수 
};


int main(){
		std::string newDog("newDog");
		std::string oldDog("oldDog");

		NamedObject<int> nw(newDog, 2);
		NamedObject<int> old(oldDog, 22);

		nw = old;
		return 0;
}
