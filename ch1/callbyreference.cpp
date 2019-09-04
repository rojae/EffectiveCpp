#include<iostream>

void addOne(int &x);

int main(){
		int value;
		std::cout << "Insert any number" << '\n';
		std::cin >> value;
		addOne(value);
		return 0;
}

void addOne(int &x){
		x++;
		std::cout << x << '\n';
}
