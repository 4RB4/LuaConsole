#pragma once
#ifndef SCRIPTMAIN_H
#define SCRIPTMAIN_H

#include "CLuaCommon.h"
#include "luaFunctionDefs.h"
/*
	CScriptMain Class
	Constructs LuaVM, loads script files into buffer and runs it
*/
class CPackage;

class CScriptMain{
public:
	CScriptMain(const char*, const char*, CPackage*);
	~CScriptMain() {
		if (m_lVM)
			lua_close(m_lVM);
	};

	void initVM();

	int bindFunctions();


	int loadScriptsIntoBuffer();
	int runScriptsFromBuffer();


protected: 

	std::string m_Package_scriptFiles[2];
	int m_Package_scriptFilesCount = sizeof(m_Package_scriptFiles) / sizeof(*m_Package_scriptFiles);

	const char* m_Package_Name;
	const char* m_Package_Dir;
	CPackage*	m_Package_Root;

	lua_State* m_lVM;
};




#endif