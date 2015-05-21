#ifndef SCRIPTARGREADER_H
#define SCRIPTARGREADER_H

#include "CLuaCommon.h"

/*
	CScriptArgReader Class
	Argument handler for C Functions of the given lua_State
*/

class CScriptArgReader {

	CScriptArgReader(lua_State*);
	~CScriptArgReader();

	void getString(std::string, const char*);
	void getNumber(int, const int);
	void getBool(bool, const bool);
	
	void getArgument();

	template<class T>
	void getUserData(T&, T*);


private:
	lua_State* m_lVM;

	int m_argIndex;

};



#endif