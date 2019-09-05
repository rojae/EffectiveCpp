/*
 * Made person: rojae
 * Made date: 2019.09.05
 * --- code description ---
 *  생성자, 소멸자, 복사 생성자가 저절로 생겨난다
 */

#include<iostream>

class Empty{
	// empty class 
};

int main(){
		Empty e1;
		Empty e2(e1);
		e2 = e1;
		return 0;
}
