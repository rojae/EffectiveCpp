/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- Code description ---
 *  상수 멤버 함수를 통한 객체 지정과
 *  일반적인 객체 지정의 겹치는 부분을
 *  최소화하기 위해서 const_cast와 static_cast를 사용하자
 */
#include<iostream>

class TextBook{
		public:
				TextBook(std::string s)
				{	text.assign(s);			}

				// 상수 멤버 함수를 통해  const로 지정
				const char& operator[](std::size_t position) const
				{
						// do something..	
						return text[position];	
				}

				// 일반적인 객체 지정
				char& operator[](std::size_t position)
				{	
						// static_cast를 통해서 형 변환 이후
						// const char& operator[](size_t position) const를 통하여 작업 실행
						// 이후 const_cast를 통해서 const를 제거한다.
						return const_cast<char &> ( static_cast<const TextBook&> (*this)[position]); 	
				}

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

