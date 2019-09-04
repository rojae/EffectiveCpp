#include <iostream>
#include "player.hpp"

/*
 * Made by : rojae
 * Made date : 2019.09.04
 * 나열자 둔갑술을 사용하기 위한 main문
 * 둔갑술은 player.hpp 파일에 존재한다.
 */

int main(){
		int n;
		std::cout << "how many player?" << '\n';
		std::cin >> n;

		Player player;

		for(int i = 0; i < n; i++){
				std::cout << "Insert Player scores :" << '\n';
				int score;
				std::cin >> score;
				player.insertScore(score);
		}
		player.getAllScore();

		return 0;
}
