#include <iostream>
#include <vector>
#include <list>
#include "ex4_header.hpp"

int main(){
		std::list<Score> scoreList;
		std::string name, address;
		int korean, english, math;

		std::cout << "... Insert Three score ..." << '\n';
		std::cin >> korean >> english >> math;

		Score score(korean, english, math);
		scoreList.push_back(score);

		std::cout << "... Insert name and Address ..." << '\n';
		std::cin >> name >> address;	


		Student student(name, address, scoreList);
		student.ShowInfo();

		return 0;
}
