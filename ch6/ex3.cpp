/*
 * Made person: rojae
 * Made date: 2019.09.06
 * --- code description ---
 * 이번에는 완벽하게 막아보자
 * private만 사용하면 friend를 통한 접근은
 * 막을 수 없었다.
 * friend를 막을 수 있는 방법은 기반 클래스를 작성하여
 * 복사 생성을 금지하는 법이다.
 */

#include<iostream>


class person;


class Uncopyable {
		protected:
				// 파생된 객체들에 대해
				Uncopyable(){}
				~Uncopyable(){}
		private:
				Uncopyable(const Uncopyable&);
				Uncopyable& operator = (const Uncopyable&);

};

  class HomeForSale: private Uncopyable{
          public:
                  HomeForSale();
                  HomeForSale(const int& cost) : money(cost)
                  {   };
                  friend person;		// friend 클래스를 선언하여 외부에서 private로 접속이 가능하게 된다
				  friend HomeForSale& HomeForSale(const HomeForSale&);
          private:
				  // 1차적으로 private에서 복사 생성이 막아진다.
				  // 하지만 막지 않는다면?
				  // friend에서 복사 생성이 실행된다
				  // 하지만 Uncopyable 클래스가 기반 클래스로
				  // 기반 클래스의 private를 통해서 복사 생성이 금지된다 
    //	          HomeForSale(const HomeForSale&);
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
