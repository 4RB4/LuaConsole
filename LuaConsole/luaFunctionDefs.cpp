#include "luaFunctionDefs.h"

class CPackage;

void CFunctionDefs::LoadFunctions(lua_State* lVM) {

	lua_pushstring(lVM, "createElement");
	lua_pushcfunction(lVM, CFunctionDefs::createElement);
	lua_setglobal(lVM, "createElement");

	lua_pushstring(lVM, "setElementData");
	lua_pushcfunction(lVM, CFunctionDefs::setElementData);
	lua_setglobal(lVM, "setElementData");

	lua_pushstring(lVM, "outputServerLog");
	lua_pushcfunction(lVM, CFunctionDefs::outputServerLog);
	lua_setglobal(lVM, "outputServerLog");

	//printf("ElementFunctions loaded!\n");
}
/*
	Function definitions
*/

int CFunctionDefs::createElement(lua_State* lVM) {
	//element createElement(string elementType)
	string eleType = lua_tostring(lVM, -1);
	


	void* ud = lua_newuserdata(lVM, sizeof(void*));

	lua_pushlightuserdata(lVM, ud);
	lua_pushvalue(lVM, -2);
	//lua_rawset(lVM, -4);

	return 1;
}

int CFunctionDefs::setElementData(lua_State* lVM) {

	CScriptArgStreamer argStreamer(lVM);
	string arg1 = argStreamer.readString();
	string arg2 = argStreamer.readString();
	string arg3 = argStreamer.readString();

	if (!argStreamer.Error()) {
		printf("bool setElementData(element '%s', index '%s', value '%s')\n", arg1.c_str(), arg2.c_str(), arg3.c_str());

	}
	else {
		g_Package->m_scriptLog->logBadArgument(lVM, argStreamer.getError());
	}

	/*

	if (lua_type(lVM, -3) == LUA_TUSERDATA) {
	printf("!!!Userdata found!!!\n");
	}
	*/
	return 1;
}

int CFunctionDefs::outputServerLog(lua_State* lVM) {
	//std::string str;

	CScriptArgStreamer argStreamer(lVM);
	string str = argStreamer.readString();

	if (!argStreamer.Error()) {


		printf("[OUTPUT] %s\n", str.c_str());
		lua_pushboolean(lVM, 1);
	}
	else {
		g_Package->m_scriptLog->logBadArgument(lVM, argStreamer.getError());
	}
	



	return 1;
}