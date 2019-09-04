/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- Code description ---
 *  기본 생성자 및 대입 생성자를 만들어보자
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

Score::Score(const int& theKorean, const int& theEnglish, const int& theMath){
	korean = theKorean;
	english = theEnglish;
	math = theMath;
}

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

Student::Student(const std::string& theName, const std::string& theAddress, const std::list<Score>& theScoreList){
	name = theName;
	address = theAddress;
	scoreList = theScoreList;
	id = 0;
}

void Student::ShowInfo(){
		std::cout << name << ' ' << address << ' ';
		scoreList.front().ShowScore();
}
