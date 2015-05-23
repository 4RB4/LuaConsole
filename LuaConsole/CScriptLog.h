
#ifndef SCRIPTLOG_H
#define SCRIPTLOG_H

#include "CLuaCommon.h"

/*
	CScriptLog Class
	Log Handler
*/
class CScriptLog {
public:
	CScriptLog() {
		//Constructor
	}

	~CScriptLog() {
		//Deconstructor
	}

	static int logFatalError(lua_State*, std::string);
	static int logBadArgument(lua_State*, std::string);

};


#endif



