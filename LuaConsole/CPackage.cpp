#include "CPackage.h"

CPackage::CPackage(const char* packageName, const char* packagePath) :
m_PackageName(packageName),
m_PackagePath(packagePath)
{
	LoadPackage();
}

CPackage::~CPackage() {

}

void CPackage::LoadPackage() {
	//TODO: Loading scripts from meta file

	CScriptMain m_rVM(m_PackageName, m_PackagePath, this);
}