#include "HookMain.h"

#define DEF_HOOK_START	"HookStart"
#define DEF_HOOK_STOP	"HookStop"

LoadDllHook::LoadDllHook(char DllName[])
{
	hDll = LoadLibraryA(DllName);
	if (hDll == NULL)
	{
		exit(GetLastError());
	}

	HookStart	= (PFN_HOOKSTART)GetProcAddress(hDll, DEF_HOOK_START);
	HookStop	= (PFN_HOOKSTOP)GetProcAddress(hDll, DEF_HOOK_STOP);
}

void LoadDllHook::Install()
{
	HookStart();
}

void LoadDllHook::UnInstall()
{
	HookStop();
}

LoadDllHook::~LoadDllHook()
{
	FreeLibrary(hDll);
}