#ifndef SCRIPTARGREADER_H
#define SCRIPTARGREADER_H

#include "CLuaCommon.h"



/*
	CScriptArgStreamer Class
	Argument handler for C Functions of the given lua_State
*/

class CScriptArgStreamer {
public:
	CScriptArgStreamer(lua_State* lVM) {
		//Constructor

		m_lVM = lVM;
		m_argIndex = -lua_gettop(lVM);
		m_index = 1;
	};
	~CScriptArgStreamer() {
		//Destructor
	};
	
	std::string readString(const char* defaultValue = NULL) {

		std::string Arg;
		int ArgType = lua_type(m_lVM, m_argIndex);
		
		if (ArgType == LUA_TSTRING || ArgType == LUA_TNUMBER) {
			Arg = lua_tostring(m_lVM, m_argIndex);
			
			m_argIndex++;
			m_index++;

			return Arg;
		}
		if (defaultValue) {
			Arg = defaultValue;

			m_argIndex++;
			m_index++;

			return Arg;
		}
		
		
		setError("string", lua_typename(m_lVM, ArgType));

		
		
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



	std::string getError() {
		if (m_error) {
			//Get functionname
			lua_Debug err; 
			lua_getstack(m_lVM, 0, &err);
			lua_getinfo(m_lVM, "n", &err);

			std::string errMsg = std::string("Bad argument @ '") + err.name + ("'[Expected ") + m_errorTypeExpected + (" @ argument ") + std::to_string(m_index) + (", got ") + m_errorTypeGot + ("]");	
			return errMsg;
		}
		return "";
	}

	bool Error() {
		if (m_error)
			return true;
		
		return false;
	}


private:
	lua_State*	m_lVM;
	int			m_argIndex;
	int			m_index;
	const char* m_streamerInstanceFunctionName;

	bool		m_error = false;
	const char*	m_errorTypeExpected;
	const char* m_errorTypeGot;

	void setError(const char* typeExpected, const char* typeGot) {
		m_errorTypeExpected = typeExpected;
		m_errorTypeGot = typeGot;
		m_error = true;
	}

};



#endif