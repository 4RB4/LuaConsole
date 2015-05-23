#pragma once
#include "CDefs.h"
#include "CScriptMain.h"

#ifndef PACKAGECLASS_H
#define PACKAGECLASS_H

class CScriptLog;

class CPackage {
public: 
	CPackage(const char*, const char*);
	~CPackage();

	static CScriptLog* m_scriptLog;

private:
	void LoadPackage();

	class CScriptMain* m_rVM;

	const char* m_PackageName;
	const char* m_PackagePath;

};

extern CPackage* g_Package;

#endif