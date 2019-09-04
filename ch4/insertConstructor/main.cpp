/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- Code description ---
 * 대입 생성자를 사용한 main문
 */

#include <iostream>
#include <vector>
#include <list>
#include "insertConstructor.hpp"

int main(){
		std::list<Score> scoreList;
		std::string name, address;
		int korean, english, math;

		std::cin >> korean >> english >> math;

		Score score(korean, english, math);
		scoreList.push_back(score);

		std::cin >> name >> address;		

		Student student(name, address, scoreList);
		student.ShowInfo();


		return 0;
}
