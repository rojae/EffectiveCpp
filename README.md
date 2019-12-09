# Effective_cpp
Effective C++ edition 3을 학습하고 예제 소스코드를 작성한다.


<hr/>

### 블로그 포스팅과 함께 진행
syntax: [Blog Link](https://redcoder.tistory.com/category/C_C%2B%2B%20%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D/Effective%20C%2B%2B
 )

<hr/>

## 목차 & 요약 
>### 1. C++를 언어들의 연합체로 바라보는 안목은 필수
- STL 템플릿 C언어 객체 지향의 C++
- pass by value vs pass by reference
- C style, STL => 값에 의한 참조가 유리하게 작동합니다.
         객체 지향 C++, 템플릿 C++ => 참조자에 의한 전달이 유리해 집니다.

>### 2. #define을 쓰려거든 const enum, inline을 떠올리자
- const를 사용하여 #define으로 생기는 사본을 줄이자
- 클래스 내부에 상수를 선언할 때는 static을 사용하자
- enum을 사용하여 나열자 둔갑술을 써보자
- 함수형 매크로 템플릿 inline함수를 사용하자
      
>### 3. 낌새만 보이면 const를 들이대 보자
- const의 가장 큰 장점은 컴파일러가 변경을 반드시 제지하는 것을 지켜준다는 것이다.
- point const는 4가지가 존재하며 다음과 같다.

> 이는 const가 *(포인터) 전후로 어디에 위치하는지에 따라서 결정이 된다.
```c
char name[] = "rojae";                 // 문자열 선언
char *p = name;                        // 비상수 데이터, 비상수 포인터
const char* p = name;                  // 상수 데이터, 비상수 포인터
char* const p = name;                 // 비상수 데이터, 상수 포인터
const char* const p = name;           // 상수 데이터, 상수 포인터
```
> 해당 멤버 함수가 상수 객체에 호출 가능한 상수 멤버 함수
```c
void print(){
 std::cout << text << '\n';
}

void print() const{
 std::cout << text << '\n';
}
```
- mutable을 사용하자
- 상수 멤버 함수와 단순 멤버 함수의 중복을 줄이는 법

>### 4. 객체를 사용하기 전에 반드시 그 객체를 초기화하자
- 본 제공 타입의 객체는 직접 초기화를 진행한다. 
          (되는 경우도 있고 아닌 경우도 있지만 그냥 모두 초기화하자)

>> 생성자에서 대입을 통한 초기화가 아닌 초기화 리스트를 사용하여 진행하자
        
```c
Score::Score(const int& theKorean, const int& theEnglish, const int& theMath)
       : korean(theKorean), english(theEnglish), math(theMath) {   }
```

- 여러 번역 단위에 존재하는 비지역 정적 객체들의 초기화 순서 문제를 피하기 위해서 설계하자
           이는 비지역 정적 객체를 지역 정적 객체로 바꾸어주면 된다.
```c
Score& score_sample(){
 static Score sc;
 return sc;
}
```
        
   >### 5. C++이 은근슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자
- C++ 자동으로 생성자 소멸자 대입 연산자를 만들 수 있다.
- 개발자가 직접 작성하면 자동 생성은 되지 않는다.
- 복사 생성자는 다음과 같이 자동으로 생성된다.
```c
/*
 * Made person: rojae
 * Made date: 2019.09.05
 * --- code description ---
 *  복사 생성자는 어떻게 만들어지는가
 *  작성하지 않았기 때문에 아래와 같이 자동으로 생성된다
 *  NamedObject(const NamedObject& other) 
 *      : nameValue(other.nameValue), objectValue(other.objectValue) { }
 */
 
#include<iostream>
 
template<typename T>
class NamedObject {
        public:
                NamedObject(const char *name, const T& value);
                NamedObject(const std::string& name, const T& value);
        private:
                std::string nameValue;
                T objectValue;
};

```
- 하지만 자동으로 생성되지 않는 경우도 있다.
1. 기반 클래스에서 private로 복사 대입 연산자를 생성한 경우
    파생 클래스에서 접근이 불가합니다
1. 데이터 멤버가 상수 객체인 경우
    (const는 수정이 불가능 하기 때문에...)
1. 참조자를 사용하는 객체를 복사 대입 하는 경우
    ( 다른 객체까지 영향이 미치기 때문에 컴파일이 거부됩니다 )


>### 6. 컴파일러가 만들어낸 함수가 필요 없으면 이들의 사용을 금해 버리자

> 복사 생성자를 금지하는 방법은 private를 통해서 막는 법이 통상적으로 쓰였다.
```c
  class HomeForSale{
          public:
		   ...
          private:
                  // private로 선언하여 복사 생성을 막는다
                  HomeForSale(const HomeForSale&);
                  HomeForSale& operator = (const HomeForSale&);
                  int money;
  };
```

> 하지만 이는 friend 함수를 통한 접근을 막을 수 없다

> 이는 기반 클래스를 작성하고 제약조건을 주어 금지할 수 있다.
```c
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
                  friend person;        // friend 클래스를 선언하여 외부에서 private로 접속이 가능하게 된다
                  friend HomeForSale& HomeForSale(const HomeForSale&);
          private:
                  // 1차적으로 private에서 복사 생성이 막아진다.
                  // 하지만 막지 않는다면?
                  // friend에서 복사 생성이 실행된다
                  // 하지만 Uncopyable 클래스가 기반 클래스로
                  // 기반 클래스의 private를 통해서 복사 생성이 금지된다 
    	          HomeForSale(const HomeForSale&);
                  HomeForSale& operator = (const HomeForSale&);
                  int money;
  };
```
>### 7. 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자
> 기반 클래스에서 파생된 파생 클래스의 소멸자에 대한 항목이다.
> 기본 클래스 포인터를 통해서 파생 클래스 객체가 삭제될 때 그 기본 클래스에 비가상 소멸자가 있다면
  프로그램 동작은 미정의 사항이다. (대개 파생 클래스 소멸자는 동작하지 않는다)
```c
class Base{
        public:
                Base(){}
                ~Base(){}
};

class Derived1 : public Base{
        public:
                Derived1(): Base(){}
                ~Derived1(){}
};

class Derived2 : public Base{
        public:
                Derived2(): Base(){}
                ~Derived2(){}
};

int main(){
        Base* p1 = new Derived1;
        Base* p2 = new Derived2;
        delete p1;
        delete p2;
        return 0;
}
```
> 이를 해결하기 위해서 virtual을 사용하면 된다.
- 하지만 항상 가상 소멸자를 사용하면 안된다. 
1. STL 컨테이너 타입(string, vector, list, set trl::unordered_map 등등..)
  - 위 타입을 상속 받는 클래스는 가상 소멸자를 사용한 삭제가 불가하다.
    ( 가상 소멸자가 존재하지 않기 때문이다 )
2. 가상 소멸자를 선언하는 것은 그 클래스에 가상 함수가 하나라도 들어 있는 경우에만 한정하자
    ( 클래스 크기 문제 )

