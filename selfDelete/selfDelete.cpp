// selfDelete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <tchar.h>

int main()
{
	PROCESS_INFORMATION	pi;
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	LPTSTR szSuffix;
	TCHAR szAppName[MAX_PATH + 1];
	TCHAR szAppName0[MAX_PATH + 1];

	// Need to wait a bit before the parent ends
	::Sleep(500);

	// Cut the ":0" suffix, if present
	::GetModuleFileName(NULL, szAppName, MAX_PATH);
	szSuffix = _tcsstr(szAppName, _T(":0"));
	if (szSuffix != NULL)
		*szSuffix = 0;

	// Try to delete non-stream file. If fails, do it from ADS
	if (!::DeleteFile(szAppName)) {
		_stprintf_s(szAppName0, MAX_PATH, _T("%s:0"), szAppName);
		::CopyFile(szAppName, szAppName0, FALSE);
		::CreateProcess(NULL, szAppName0, 0, 0, 0, 0, 0, 0, &si, &pi);
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
