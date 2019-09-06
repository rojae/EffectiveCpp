/*
 * Made person: rojae
 * Made date: 2019.09.06
 * --- code description ---
 *  복사 생성자를 호출하지 않기 위해서는
 *  어떻게 해야할까?
 *  우선은 호출되는 경우
 */

#include<iostream>

class HomeForSale{
		// empty class
};


int main(){
	HomeForSale h1;
	HomeForSale h2;
	HomeForSale h3(h1);
	h1 = h2;
	return 0;
}
