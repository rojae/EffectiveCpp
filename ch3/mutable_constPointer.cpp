/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- Code description ---
 *  mutable을 사용하여 상수 멤버 함수에서도
 *  수정이 가능하도록 한다.
 */
#include<iostream>

class TextBook{
		public:
				TextBook(std::string s)
				{	text.assign(s);			}

				// 상수 멤버 함수를 통해  const로 지정
				const char& operator[](std::size_t position) const
				{	return text[position];	}

				// 일반적인 객체 지정
				char& operator[](std::size_t position)
				{	return text[position];	}

				void print(){
					std::cout << text << '\n';
				}
				void print() const{
					std::cout << text << '\n';
				}

				std::size_t length() const;

		private:
				std::string text;
				
				// mutable로 선언된 데이터들은 상수 멤버 함수안에서도 수정이 가능하다 (어느 순간이든).
				mutable bool lengthIsValid;
				mutable std::size_t textlength;
};

std::size_t TextBook::length() const{
	if(!lengthIsValid){
			textlength = text.size();
			lengthIsValid = true;
	}
	return textlength;
}
int main(){
          TextBook tb("Hello");
          std::cout << tb[0] << '\n';
        
          const TextBook ctb("Hello");
          std::cout << ctb[0] << '\n';
 
		  tb[0] = 'J';
		  //ctb[0] = 'J'; 		// const TextBook에 대해서 읽기만 가능하다.

		  tb.print();
		  std::cout << tb.length() << '\n';
		  ctb.print();
		  std::cout << ctb.length() << '\n';
		  return 0;
  }

