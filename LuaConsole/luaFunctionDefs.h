#pragma once
#include "CLuaCommon.h"
#include "CDefs.h"
#include "CScriptArgStreamer.h"
using namespace std;

class CScriptLog;

class CFunctionDefs: public CDefs{
public:

	static CScriptLog* m_scriptLog;

	static void	LoadFunctions		(lua_State* lVM);

	static int createElement		(lua_State* lVM);

	static int setElementData		(lua_State* lVM);
	static int getElementData		(lua_State* lVM);
	static int outputServerLog		(lua_State* lVM);

	
};
