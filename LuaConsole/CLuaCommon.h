#pragma once
#ifndef LUACOMMON_H
#define LUACOMMON_H

/*
Prevent VS to handle security lacks as errors
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
};

//Global stuff


#endif