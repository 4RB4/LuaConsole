#pragma once
#ifndef SCRIPTMAIN_H
#define SCRIPTMAIN_H

#include "CLuaCommon.h"

/*
	CScriptMain Class
	Constructs LuaVM, loads script files into buffer and runs it
*/

class CScriptMain {
public:
	CScriptMain(const char* rN, const char* resourcePath);
	~CScriptMain() {
		if (m_lVM)
			lua_close(m_lVM);
	};

	void initVM();

	int bindFunctions();


	int loadScriptsIntoBuffer();
	int runScriptsFromBuffer();


protected: 

	std::string m_resource_scriptFiles[2];
	int m_resource_scriptFilesCount = sizeof(m_resource_scriptFiles) / sizeof(*m_resource_scriptFiles);

	const char* m_resource_Name;
	const char* m_resource_Dir;

	lua_State* m_lVM;


};




#endif