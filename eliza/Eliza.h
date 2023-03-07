#ifndef __ELIZA__H__
#define __ELIZA__H__

#pragma warning(disable:4786)

#include "recorder.h"
#include "strings.h"
#include <windows.h>
#include <direct.h>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <list>
#include <stack>
#include <ctime>

#define PAUSE(x) Sleep(x);


struct data {
	vstring keywords;
	vstring contexts;
	vstring responses;
	vstring cmd;
};

struct transpos {
	std::string verbP1;
	std::string verbP2;
};

struct correction {
	std::string verbP1;
	std::string verbP2;
};



class Eliza {
	Tokenizer tok;

public:
	Eliza () 
		: m_bQuitProgram(0), linePos(2), m_bNewData(0), 
		m_bLearning(0), m_nUserRepeatCount(0) 
	{
		srand((unsigned int) time(NULL));
		read_time_delay(time_delay);
	}

	~Eliza () 
	{};

	void load_data();
	void save_data();

	void respond();

	void preProcessInput();
	void preProcessResponse();

	void memorise_input();
	void get_input();

	void start();
	
	void print_response();
	void print_database_content();
	void save_unknown_sentences();

	bool quit() const {  
		return m_bQuitProgram; 
	}

	bool learn() const {
		return m_bNewData;
	}

private:
	void saveTopic(const vstring vList, const std::string sSymbol);
	void saveComment(const string comment);
	void saveTransposTable();
	void saveKeyWords();

	bool transpose( std::string &str ) const;
	void transpose_sentence( std::string &str );

	void correct_sentence( std::string &str ) const;

	void handleRepetition( vstring &vList );
	void handleUserRepetition();
	void handleUnknownSentence();

	void verify_context(vstring vContext);

	void print_current_data();

	void find_keyword();
	void find_response();

	void execute();
	
	void dump_data();
	void selectResponse( vstring v );
	void extract_suffix();

	void clear();
	
	bool bot_repeat() const;

	bool null_input() const {
		return m_sInput.length() == 0;
	}

	bool user_repeat() const {
		return (m_sInput.length() > 0 && m_sInput == m_sPrevInput);
	}

	bool bot_understand() const {
		return response_list.size() > 0;
	}

	void reset_repeat_count() {
		m_nUserRepeatCount = 0;
	}

	void save_prev_response() {
		m_sPrevResponse = m_sResponse;
	}

	void save_prev_input() {
		m_sPrevInput = m_sInput;
	}

	void save_prev_responses() {
		if(m_sResponse.length() > 0) {
			previous_responses.push(m_sResponse);
		}
	}

	void check_quit_message() {
		if(m_sResponse.find("BYE") != std::string::npos) {
			m_bQuitProgram = 1;
		}
	}

	void simulate_thinking() {
		PAUSE(700 + rand() % 3000);
	}

	bool is_template(std::string str) {
		return (str.find("*") != std::string::npos ||
			str.find("@") != std::string::npos);
	}

	void findSymbol(std::string str) {
		m_sSymbol.erase();
		if(str.find("*") != std::string::npos) {
			m_sSymbol = "*";
		} else if(str.find("@") != std::string::npos) {
			m_sSymbol = "@";
		}
	}

	bool isGoodKey(const std::string key, const std::string bkey, int pos, int bestp) const;

private:
	std::stack<std::string>		previous_responses;
	std::list<std::string>		extendedResponseList;
	std::vector<transpos>		transpos_list;
	std::vector<correction>		correction_list;
	
	std::stack<std::string>		memory;
	
	std::vector<data>			database;
	std::vector<double>			time_delay;
	
	std::fstream				scriptfile;
	data						current_data;
	correction					current_correction;
	
	std::string					m_sInput;
	std::string					m_sResponse;
	std::string					m_sPrevInput;
	std::string					m_sKeyWord;
	std::string					m_sSuffix;
	std::string					m_sPrevResponse;
	std::string					m_sCommand;
	std::string					m_sSymbol;
	vstring						nullResponse;
	vstring						myResponse;
	vstring						noKeyWord;
	vstring						topicChanger;
	vstring						subjectRecall;
	vstring						unknownSentences;
	vstring						inputRepeat;
	vstring						keyword_list;
	vstring						response_list;
	vstring						previous_inputs;
	vstring						command_list;
	vstring						comments;
	vstring						signOn;
	unsigned int				linePos;
	unsigned int				m_nUserRepeatCount;
	unsigned int				m_nCorrectionNum;
	unsigned int				m_nTransPosNum;
	bool						m_bGoodContext;
	bool						m_bQuitProgram;
	bool						m_bLearning;
	bool						m_bNewData;

};


#endif