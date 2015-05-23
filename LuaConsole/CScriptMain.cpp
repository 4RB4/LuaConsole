#include "CScriptMain.h"
#include "luaFunctionDefs.h"

CScriptMain::CScriptMain(const char* resName, const char* resPath){
	printf("Starting resource '%s'\n", resName);
	//Initialize everything to setup Lua VM
	m_resource_Name = resName;
	m_resource_Dir = resPath;

	initVM();
}



int CScriptMain::bindFunctions() {

	CFunctionDefs::LoadFunctions(m_lVM);

	return 0;
};




void CScriptMain::initVM() {
	//Setup VM
	m_lVM = luaL_newstate();
	luaL_openlibs(m_lVM);

	
	bindFunctions();


	loadScriptsIntoBuffer();
	runScriptsFromBuffer();
}



int CScriptMain::loadScriptsIntoBuffer() {
	printf("Loading scripts...(Directory: %s)\n\n", m_resource_Dir);
	//Loading scripts from meta.xml
	//PLACEHOLDER

	
	const char* fileNames[2];

	fileNames[0] = "script.lua";
	fileNames[1] = "test.lua";



	for (int i = 0; i < m_resource_scriptFilesCount; i++) {
		m_resource_scriptFiles[i] = std::string(m_resource_Dir) + fileNames[i];
	};




	return 0;
}


int CScriptMain::runScriptsFromBuffer() {

	for (int i = 0; i < m_resource_scriptFilesCount; i++) {

		//printf("%s\n", m_resource_scriptFiles[i].c_str());
		if (luaL_loadfile(m_lVM, m_resource_scriptFiles[i].c_str()) == 0) {
			lua_pcall(m_lVM, 0, LUA_MULTRET, 0);
		}
		else {
			std::string errRes = lua_tostring(m_lVM, -1);
			printf("SCRIPT ERROR: %s\n", errRes.c_str());
		}





	}


	return 0;
}