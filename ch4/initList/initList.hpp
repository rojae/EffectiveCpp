/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- code description ---
 *  초기화 리스트를 사용하자
 */
#include<iostream>
#include<list>
class Score{
		public:
				Score() {};
				Score(const int& korean, const int& english, const int& math);
				void ShowScore();

		private:
				int korean;
				int english;
				int math;
};

// 초기화 리스트를 사용하여 초기화와 대입을 
// 한번에 처리하도록 함
// 생성만 할 경우에는 기본생성자
// : korean(), english(), math() {} 로 처리가 가능하다.
Score::Score(const int& theKorean, const int& theEnglish, const int& theMath)
	: korean(theKorean), english(theEnglish), math(theMath)	{	}

void Score::ShowScore(){
	std::cout << korean << ' ' << english << ' ' << math << '\n';	
}

class Student{
		public:
				Student() {};
				Student(const std::string& name, const std::string& address,
								const std::list<Score>& scoreList);
				void ShowInfo();
		private:
				std::string name;
				std::string address;
				std::list<Score> scoreList;
				std::size_t id;
};

// 마찬가지로 사용한 초기화 리스트
Student::Student(const std::string& theName, const std::string& theAddress, const std::list<Score>& theScoreList)
	: name(theName), address(theAddress), scoreList(theScoreList), id(0)
	{};

void Student::ShowInfo(){
		std::cout << name << ' ' << address << ' ';
		scoreList.front().ShowScore();
}
