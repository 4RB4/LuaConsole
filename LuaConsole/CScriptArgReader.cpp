#include "CScriptArgReader.h"


CScriptArgReader::CScriptArgReader(lua_State* lVM) :
m_lVM(lVM)
{
	//Constructor
}


CScriptArgReader::~CScriptArgReader() {
	//Deconstrucor
}


//Reading functions

void CScriptArgReader::getString(std::string Value, const char* defaultValue = NULL) {

}

void CScriptArgReader::getNumber(int Value, int defaultValue) {

}

void CScriptArgReader::getBool(bool Value, const bool defaultValue) {

}

void CScriptArgReader::getArgument() {

}

