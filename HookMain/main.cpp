#include "HookMain.h"

#define DEF_DLL_NAME "KeyHook.dll"

int main()
{
	LoadDllHook Hook = LoadDllHook((char*)DEF_DLL_NAME);
	Hook.Install();

	_tprintf(_T("press 'q' to quit!\n"));
	while (_gettch() != 'q');

	Hook.UnInstall();
	return 0;
}