#pragma once
#include "CScriptArgStreamer.h"
using namespace std;

#include "CDefs.h"



class CFunctionDefs : CDefs {
public: 
	static void	LoadFunctions		(lua_State* lVM);

	static int createElement		(lua_State* lVM);

	static int setElementData		(lua_State* lVM);
	static int getElementData		(lua_State* lVM);
	static int outputServerLog		(lua_State* lVM);


};

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



int CFunctionDefs::createElement(lua_State* lVM) {
	//element createElement(string elementType)
	string eleType = lua_tostring(lVM, -1);

	printf("createElement: %s\n", eleType.c_str());
	

	void* ud = lua_newuserdata(lVM, sizeof(void*));

	lua_pushlightuserdata(lVM, ud);
	lua_pushvalue(lVM, -2);
	//lua_rawset(lVM, -4);


	return 1;
}


int CFunctionDefs::setElementData(lua_State* lVM) {
	
	CScriptArgStreamer argStream(lVM, 3);

	void* ud = lua_touserdata(lVM, -3);
	string udIndex = lua_tostring(lVM, -2);
	string udValue = lua_tostring(lVM, -1);

	printf("bool setElementData(element '%s', index '%s', value '%s')\n", ud, udIndex.c_str(), udValue.c_str());

	if (lua_type(lVM, -3) == LUA_TUSERDATA) {
		printf("!!!Userdata found!!!\n");
	}

	return 1;
}

int CFunctionDefs::outputServerLog(lua_State* lVM) {
	//std::string str;

	CScriptArgStreamer argStreamer(lVM, 1);
	string str = argStreamer.readString();

	argStreamer.getError();

	printf("[OUTPUT] %s\n", str.c_str());

	lua_pushboolean(lVM, 1);

	m_ScriptLog->mail();

	return 1;
}