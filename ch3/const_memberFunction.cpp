/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- Code description ---
 *  const가 붙은 class의 멤버함수는 어떠한 동작을 하는지 확인해본다.
 */
#include<iostream>

class TextBook{
		public:
				TextBook(std::string s)
				{	text.assign(s);			}

				// 상수 멤버 함수를 통해  const로 지정
				const std::string& operator[](std::size_t position) const
				{	return text;	}

				// 일반적인 객체 지정
				std::string& operator[](std::size_t position)
				{	return text;	}

				void print(){
					std::cout << text << '\n';
				}
				void print() const{
					std::cout << text << '\n';
				}

		private:
				std::string text;
};
int main(){
          TextBook tb("Hello");
          std::cout << tb[0] << '\n';
        
          const TextBook ctb("Hello");
          std::cout << ctb[0] << '\n';
 
		  tb[0] = 'J';
		  //ctb[0] = 'J'; 		// const TextBook에 대해서 읽기만 가능하다.

		  tb.print();
		  ctb.print();
		  return 0;
  }

