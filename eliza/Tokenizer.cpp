#include "tokenizer.h"

void Tokenizer::setString( string str ) {
	buffer = str; // initialising buffer
	currentPosition = buffer.begin();
}

void Tokenizer::setDelim( string str ) {
	delim = str; // initialising delimiter variable
}

void Tokenizer::resetPosition(void) {
	currentPosition = buffer.begin();
}

void Tokenizer::setPosition( int pos ) {
	int thisPos = 0;
	while( thisPos <= pos && firstToken() != "" ) {
		thisPos++;
	}
}

bool Tokenizer::isDelim( char c ) {
	return delim.find(c) != string::npos;
}

void Tokenizer::skipDelim(void) {
	string::iterator iter = currentPosition;
	for( ; isDelim(*iter); ++iter )
		;
	currentPosition = iter;
}

string Tokenizer::currentToken(void) {
	return thisToken;
}

string Tokenizer::firstToken(void) {
	thisToken.erase();
	skipDelim();
	string::iterator iter = currentPosition;
	for( ; *iter && !isDelim(*iter); iter++ ) {
		thisToken += *iter;
	}
	(*iter == NULL) ?
		(currentPosition = iter) : (currentPosition = ++iter);
	return thisToken;
}

// token that comes after the first token
string Tokenizer::nextToken(void) {
	if(firstToken() != "") {
		return firstToken();
	}
	return thisToken;
}

string Tokenizer::lastToken(void) {
	string theLastToken;
	while(firstToken() != "") {
		theLastToken = thisToken;
	}
	return theLastToken;
}

int Tokenizer::countTokens(void) {
	// reset position before starting to count tokens
	resetPosition();
	int tokenNumber;
	for( tokenNumber = 0; firstToken() != ""; tokenNumber++ );
	// resets position back once finished
	resetPosition(); 
	return tokenNumber;
}

int Tokenizer::getTokenNumber( string str ) {
	setString(str);
	return countTokens();
}

// removes unwanted characters from a string
void Tokenizer::cleanString( char *str ) {
	string _str;
	vstring temp;
	tokenize(temp);
	int vec_size = temp.size();
	for( int i = 0; i < vec_size; i++ ) {
		_str += temp[i] + " ";
	}
	_str.erase( _str.length() - 1, 1 );
	strcpy(str, _str.c_str());
}

void Tokenizer::cleanString( string &str ) {
	setString(str);
	string _str;
	vstring temp;
	tokenize(temp);
	int vec_size = temp.size();
	for( int i = 0; i < vec_size; i++ ) {
		_str += temp[i] + " ";
	}
	_str.erase( _str.length() - 1, 1 );
	str = _str;
}

// tokenize's the string completely
// and puts the tokens into a vector
void Tokenizer::tokenize( vstring &v ) {
	if(buffer.length() == 0) {
		return;
	}
	// reset position before starting to tokenize
	resetPosition();
	for( ; firstToken() != ""; v.push_back(thisToken))
		;
	resetPosition();
}

void Tokenizer::tokenize(string str, vstring &v) {
	setString(str); tokenize(v);
}

void Tokenizer::cleanString(string &str, string delim) {
	setDelim(delim); cleanString(str);
}




	
