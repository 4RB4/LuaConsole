#include "CResource.h"

CResource::CResource(const char* resName, const char* resPath)
{
	CScriptMain m_rVM(resName, resPath);
}

CResource::~CResource() {

}