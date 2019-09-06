/*
 * Made person: rojae
 * Made date: 2019.09.06
 * --- code description ---
 *  private를 사용하여 자동 복사 생성자 호출을 
 *  막아보자.
 *
 *  HomeForSale의 private에 있는 복사 생성자를 통해서
 *  복사 생성이 금지가 되지만, 이 없이 friend함수를 통해서
 *  복사가 가능해진다.
 *  이 마저도 금지할 수 없을까?
 */

#include<iostream>

class person;

  class HomeForSale{
          public:
                  HomeForSale();
                  HomeForSale(const int& cost) : money(cost)
                  {   };
                  friend person;		// friend 클래스를 선언하여 외부에서 private로 접속이 가능하게 된다
				  // friend로 복사 생성자를 만들었기 때문에 실행이 가능하다
				  friend HomeForSale& HomeForSale(const HomeForSale&);
				  friend void getMoney(HomeForSale& h){
						  std::cout << h.money << '\n';
				  }
          private:
				  // 주석 해제시 private로 선언하였기 때문에 
				  // HomeForSale h3(h1)이 컴파일 오류
    	          // HomeForSale(const HomeForSale&);
	              HomeForSale& operator = (const HomeForSale&);
                  int money;
  };

  class person{
          public:
				  void getMoney(HomeForSale& ob){
						  std::cout << ob.money << '\n';
				  }
          private:
					
  };

int main(){
		HomeForSale h1(100);
		HomeForSale h2(200);

		// 주석을 해제하면 컴파일 오류가 일어난다.
		// HomeForSale에서 private로 복사 생성자를 생성했기 때문에
		HomeForSale h3(h1);
		
		// person p1을 통해서 HomeForSale에 접근이 가능하게 된다
		person p1;
		p1.getMoney(h2);

		return 0;
}
