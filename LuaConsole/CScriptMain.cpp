#include "CScriptMain.h"

CScriptMain::CScriptMain(const char* packageName, const char* packagePath, CPackage* packageRoot){
	printf("Starting package '%s'\n", packageName);
	//Initialize everything to setup Lua VM
	m_Package_Name = packageName;
	m_Package_Dir = packagePath;
	m_Package_Root = packageRoot;

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
	printf("Loading scripts...(Directory: %s)\n\n", m_Package_Dir);
	//Loading scripts from meta.xml
	//PLACEHOLDER

	
	const char* fileNames[2];

	fileNames[0] = "script.lua";
	fileNames[1] = "test.lua";



	for (int i = 0; i < m_Package_scriptFilesCount; i++) {
		m_Package_scriptFiles[i] = std::string(m_Package_Dir) + fileNames[i];
	};




	return 0;
}


int CScriptMain::runScriptsFromBuffer() {

	for (int i = 0; i < m_Package_scriptFilesCount; i++) {

		//printf("%s\n", m_Package_scriptFiles[i].c_str());
		if (luaL_loadfile(m_lVM, m_Package_scriptFiles[i].c_str()) == 0) {
			lua_pcall(m_lVM, 0, LUA_MULTRET, 0);
			
		}
		else {
			std::string errRes = lua_tostring(m_lVM, -1);
			m_Package_Root->m_scriptLog->logFatalError(m_lVM, errRes);
		}
		
		

	}


	return 0;
}