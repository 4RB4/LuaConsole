#pragma once

#include "CScriptLog.h"

class CDefs {
public:

	CDefs() {
		static CScriptLog m_ScriptLog;
	};
	~CDefs() {

	};

protected:
	
	static CScriptLog* m_ScriptLog;
};