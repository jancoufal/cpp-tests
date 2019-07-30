// debugDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <Windows.h>
#include <tchar.h>

typedef enum _PROCESSINFOCLASS {
	ProcessBasicInformation,
	ProcessQuotaLimits,
	ProcessIoCounters,
	ProcessVmCounters,
	ProcessTimes,
	ProcessBasePriority,
	ProcessRaisePriority,
	ProcessDebugPort,
	ProcessExceptionPort,
	ProcessAccessToken,
	ProcessLdtInformation,
	ProcessLdtSize,
	ProcessDefaultHardErrorMode,
	ProcessIoPortHandlers,          // Note: this is kernel mode only
	ProcessPooledUsageAndLimits,
	ProcessWorkingSetWatch,
	ProcessUserModeIOPL,
	ProcessEnableAlignmentFaultFixup,
	ProcessPriorityClass,
	ProcessWx86Information,
	ProcessHandleCount,
	ProcessAffinityMask,
	ProcessPriorityBoost,
	ProcessDeviceMap,
	ProcessSessionInformation,
	ProcessForegroundInformation,
	ProcessWow64Information,
	ProcessImageFileName,
	ProcessLUIDDeviceMapsEnabled,
	ProcessBreakOnTermination,
	ProcessDebugObjectHandle,
	ProcessDebugFlags,
	ProcessHandleTracing,
	ProcessIoPriority,
	ProcessExecuteFlags,
	ProcessTlsInformation,
	ProcessCookie,
	ProcessImageInformation,
	ProcessCycleTime,
	ProcessPagePriority,
	ProcessInstrumentationCallback,
	ProcessThreadStackAllocation,
	ProcessWorkingSetWatchEx,
	ProcessImageFileNameWin32,
	ProcessImageFileMapping,
	ProcessAffinityUpdateMode,
	ProcessMemoryAllocationMode,
	ProcessGroupInformation,
	ProcessTokenVirtualizationEnabled,
	ProcessConsoleHostProcess,
	ProcessWindowInformation,
	MaxProcessInfoClass             // MaxProcessInfoClass should always be the last enum
} PROCESSINFOCLASS;

typedef NTSTATUS(WINAPI *PFN_NtQueryInformationProcess)(
	__in HANDLE ProcessHandle,
	__in PROCESSINFOCLASS ProcessInformationClass,
	__out PVOID ProcessInformation,
	__in ULONG ProcessInformationLength,
	__out_opt PULONG ReturnLength
	);

#define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

int main()
{
	HMODULE ntDll = ::LoadLibrary(_T("ntdll.dll"));

	if (ntDll != INVALID_HANDLE_VALUE)
	{
		PFN_NtQueryInformationProcess _NtQueryInformationProcess = (PFN_NtQueryInformationProcess)::GetProcAddress(ntDll, "NtQueryInformationProcess");

		if (_NtQueryInformationProcess)
		{
			DWORD_PTR resultVar;
			NTSTATUS ntStatus = _NtQueryInformationProcess(::GetCurrentProcess(), ProcessDebugPort, &resultVar, sizeof(resultVar), NULL);

			if (NT_SUCCESS(ntStatus))
			{
				bool debuggerDetected = (resultVar != 0);

				_tprintf(_T("Debugging? %s.\n"), debuggerDetected ? _T("Yes") : _T("No"));
			}

		}
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
