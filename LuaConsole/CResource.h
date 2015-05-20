#include "CScriptMain.h"

#ifndef RESOURCECLASS_H
#define RESOURCECLASS_H



class CResource {
public: 
	CResource(const char* resName, const char* resPath);
	~CResource();

	void LoadResource();

private:

	CScriptMain* m_rVM;

	const char* m_resourceName;
	const char* m_resourcePath;

};

#endif