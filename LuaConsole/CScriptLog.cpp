#include "CScriptLog.h"


int CScriptLog::logFatalError(lua_State* lVM, std::string errMsg) {
	printf("FATAL ERROR: Loading script failed: %s\n", errMsg.c_str());

	return 0;
}


int CScriptLog::logBadArgument(lua_State* lVM, std::string errMsg) {
	lua_Debug err;
	lua_getstack(lVM, 1, &err);
	lua_getinfo(lVM, "nSl", &err);
	int cL = err.currentline;
	lua_getinfo(lVM, "s", &err);
	const char* cF = err.source;

	printf("ERROR %s:%s: %s\n", cF, std::to_string(cL).c_str(), errMsg.c_str());

	return 0;
}