///////////////////////////////////////////////////////////////////////////////
// String Tokenizer class
// This class is a very covenient class for manipulating tokens inside a string.
// It offers many functions for manipulating tokens.
// With all this functions,token manipulations becomes very easy!
// This code is copyrighted, author: Gonzales Cenelia
/////////////////////////////////////////////////////////////////////////
#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__


#pragma warning(disable:4786)

#include <string>
#include <vector>
using std::string;
using std::vector;

typedef vector<string> vstring;


class Tokenizer {
public:
	Tokenizer() {};
	~Tokenizer() {};
	void setPosition( int pos );
	void resetPosition(void);
	void setString( string str );
	void setDelim( string str );
	void cleanString( char *str );
	void cleanString(string &str);
	void cleanString(string &str, string delim);
	void tokenize( vstring &v );
	void tokenize(string str, vstring &v);
	int getTokenNumber( string str );
	int countTokens(void);
	string currentToken(void);
	string firstToken(void);
	string nextToken(void);
	string lastToken(void);
private:
	bool isDelim( char c );
	void skipDelim(void);
	string::iterator currentPosition;
	string thisToken;
	string delim;
	string buffer;
};


#endif


