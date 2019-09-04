#include<vector>
#include<iostream>


// 나열자 둔갑술을 사용해보자

class Player{
		private:
				enum {maxUser = 10};
				std::vector<int> score;
		public:
				void insertScore(int &v){
					if(score.size() > maxUser-1){
							std::cout << "Max player" << '\n';
							return;
					}
					score.push_back(v);
				}
				void getAllScore(){
						std::cout << "Current Player :"
								<< score.size() << '\n';
						for(int i = 0; i < score.size(); i++){
								std::cout << score[i] << '\n';
						}
				}
};
