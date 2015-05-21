#ifndef SCRIPTERROR_H
#define SCRIPTERROR_H

#include "CLuaCommon.h"

/*
	CScriptError Class
	Handles errors of the given lua_State
*/

class CScriptError {
public:
		
	CScriptError(lua_State*);
	~CScriptError();

	const char* what();

	virtual const char* what() const throw();

private:
	lua_State* m_lVM;
};







#endif
