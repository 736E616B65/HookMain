#ifndef __HOOK_MAIN_H__
#define __HOOK_MAIN_H__

#include <Windows.h>
#include <tchar.h>

typedef void (*PFN_HOOKSTART)();
typedef void (*PFN_HOOKSTOP)();

class LoadDllHook
{
private:
	HMODULE			hDll		= NULL;
	PFN_HOOKSTART	HookStart	= NULL;
	PFN_HOOKSTOP	HookStop	= NULL;

public:
	LoadDllHook(char[]);
	void Install();
	void UnInstall();
	~LoadDllHook();
};
#endif