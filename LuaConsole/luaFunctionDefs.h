#pragma once

namespace luaFunctionDefs {

	/*
		\brief Used to output informations in console
	*/
	int outputServerLog(lua_State* lVM) {

		const char* str = lua_tostring(lVM, -1);
		
		printf("[OUTPUT] %s\n", str);

		lua_pushboolean(lVM, 1);

		return 1;
	}

}



class CElementFunctionDefs {
public: 
	static void	LoadFunctions		(lua_State* lVM);

	static int createElement		(lua_State* lVM);

	static int setElementData		(lua_State* lVM);
	static int getElementData		(lua_State* lVM);


};
#include <Windows.h>

void CElementFunctionDefs::LoadFunctions(lua_State* lVM) {

	lua_pushcfunction(lVM, CElementFunctionDefs::createElement);
	lua_setglobal(lVM, "createElement");

	lua_pushcfunction(lVM, CElementFunctionDefs::setElementData);
	lua_setglobal(lVM, "setElementData");

	printf("ElementFunctions loaded!\n");
}



int CElementFunctionDefs::createElement(lua_State* lVM) {
	//element createElement(string elementType)
	std::string eleType = lua_tostring(lVM, -1);

	printf("createElement: %s\n", eleType.c_str());
	

	void* ud = lua_newuserdata(lVM, sizeof(void*));

	lua_pushlightuserdata(lVM, ud);
	lua_pushvalue(lVM, -2);
	//lua_rawset(lVM, -4);


	return 1;
}


int CElementFunctionDefs::setElementData(lua_State* lVM) {
	
	void* ud = lua_touserdata(lVM, -3);
	std::string udIndex = lua_tostring(lVM, -2);
	std::string udValue = lua_tostring(lVM, -1);

	printf("setElementData Values: \nElement: %s\nIndex: %s\nValue: %s\n", ud, udIndex.c_str(), udValue.c_str());
	printf("bool setElementData(element '%s', index '%s', value '%s')", ud, udIndex.c_str(), udValue.c_str());

	if (lua_type(lVM, -3) == LUA_TUSERDATA) {
		printf("!!!Userdata found!!!\n");
	}

	return 1;
}