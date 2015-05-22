#ifndef SCRIPTARGREADER_H
#define SCRIPTARGREADER_H

#include "CLuaCommon.h"
#include "CScriptLog.h"
#include <sstream>


/*
	CScriptArgStreamer Class
	Argument handler for C Functions of the given lua_State
*/

class CScriptArgStreamer {
public:
	CScriptArgStreamer(lua_State* lVM, int args) {
		//Constructor
		m_lVM = lVM;
		m_argIndex = -args;
		m_index = 1;
		extern CScriptLog* g_ScriptLog;
	};
	~CScriptArgStreamer() {
		//Destructor
	};
	
	std::string readString(const char* defaultValue = NULL) {

		std::string Arg;
		int ArgType = lua_type(m_lVM, m_argIndex);
		
		if (ArgType == LUA_TSTRING || ArgType == LUA_TNUMBER) {
			Arg = lua_tostring(m_lVM, m_argIndex);
			printf("STRING");
			return Arg;
		}
		if (defaultValue) {
			Arg = defaultValue;
			return Arg;
		}
		
		
		Error("string", lua_typename(m_lVM, ArgType));

		return Arg;
	}

	void readNumber(int Value, const int defaultValue = NULL) {
		
	};

	void readBool(bool Value, const bool defaultValue) {

	};
	

	template<class T>
	T readArgument(T) {

	};

	template<class T>
	T readUserData(T, T) {

	};


	void Error(const char* typeExpected, const char* typeGot) {
		m_errorTypeExpected = typeExpected;
		m_errorTypeGot = typeGot;
		m_error = true;
	}
	std::string getError() {
		if (m_error) {
			std::string errMsg = std::string("Bad argument @ '") + "functionname" + ("'[Expected '") + m_errorTypeExpected + ("' @ argument ") + std::to_string(m_index) + (", got '") + m_errorTypeGot + ("']!");
			printf(errMsg.c_str());
			
		}
		return "";
	}


private:
	lua_State*	m_lVM;
	int			m_argIndex;
	int			m_index;

	bool		m_error = false;
	const char*	m_errorTypeExpected;
	const char* m_errorTypeGot;

};



#endif