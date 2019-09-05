/*
 * Made person: rojae
 * Made date: 2019.09.05
 * --- code description ---
 *	복사 생성자는 어떻게 만들어지는가
 *  작성하지 않았기 때문에 아래와 같이 자동으로 생성된다
 *  NamedObject(const NamedObject& other) 
 *  	: nameValue(other.nameValue), objectValue(other.objectValue) { }
 */

#include<iostream>

template<typename T>
class NamedObject {
	   	public: 
				NamedObject(const char *name, const T& value);
			   	NamedObject(const std::string& name, const T& value);
	   	private: 
				std::string nameValue;
			   	T objectValue; 
};

