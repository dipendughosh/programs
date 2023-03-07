#include "strings.h"

// trim the left character of a given string
void trimLeft(string &str, char c) {
	int pos;
	for(pos = 0; str[pos] == c; ++pos)
		;
	str.erase( 0, pos );
}

// trim the right character of a given string
void trimRight(string &str, char c) {
	int pos = str.length();
	if( pos == 0 ) return;
	for(--pos; str[pos] == c; --pos)
		;
	str.erase(++pos, str.length() - pos);
}

// trim all left and right characters that is specified by
// the string "characters"
void trimLR(string &str, string characters) {
	int len = characters.length();
	for(int i = 0; i < len; ++i) {
		trimLeft( str, characters[i] );
		trimRight( str, characters[i] );
	}
}

// removes a substring from a given string
bool remove(string &str, string substr) {
	int pos = str.find(substr);
	if(pos != string::npos) {
		str.erase( pos, substr.length());
	}
	return (pos != string::npos);
}

// replace a substring by another substring
bool replace(string &str, string oldsubstr, string newsubstr) {
	int pos = str.find(oldsubstr);
	if( pos != string::npos ) {
		remove( str, oldsubstr );
		str.insert( pos, newsubstr );
	}
	return (pos != string::npos);
}

void UpperCase( string &str ) {
	int len = str.length();
	for( int i = 0; i < len; i++ ) {
		if ( str[i] >= 'a' && str[i] <= 'z' ) {
			str[i] -= 'a' - 'A';
		}
	}
}

void LowerCase( string &str ) {
	int len = str.length();
	for( int i = 0; i < len; i++ ) {
		if ( str[i] >= 'A' && str[i] <= 'Z' ) {
			str[i] += 'a' - 'A';
		}
	}
}
