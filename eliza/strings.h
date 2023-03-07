#ifndef _STRINGS_H_
#define _STRINGS_H_

#include "tokenizer.h"
#include <iostream>
#include <cassert>

void trimLR(string &str, string characters);
void trimLeft(string &str, char c);
void trimRight(string &str, char c);

bool replace(string &str, string oldsubstr, string newsubstr);
bool remove(string &str, string substr);

void UpperCase( string &str );
void LowerCase( string &str );

template<typename T>
void shuffle(T &array, size_t size) {
	for(int i = 0; i < size; ++i) {
		int index = rand() % size;
		std::swap(array[i], array[index]);
	}
}


#endif