#include "CScriptError.h"

CScriptError::CScriptError(lua_State* lVM):
m_lVM(lVM)
{
	//Constructor
}

CScriptError::~CScriptError() {
	//Destructor
}


const char* CScriptError::what() const throw(){
	const char* e = lua_tostring(m_lVM, -1);
	if (e == NULL)
		e = "An error occured!";
	return e;
}