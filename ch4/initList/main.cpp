/*
 * Made person: rojae
 * Made date: 2019.09.04
 * --- code description ---
 *  초기화 리스트를 사용한 생성자 사용
 */

#include <iostream>
#include <vector>
#include <list>
#include "initList.hpp"

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
