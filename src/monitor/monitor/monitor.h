#pragma once

#include <Windows.h>
#define  MAXPATHLEN         260        // �ļ�|����|ע�����󳤶�
#define  MAXNAMELEN         64         // �û�����󳤶�

typedef struct _FILE_BASIC_INFORMATION {
	LARGE_INTEGER CreationTime;
	LARGE_INTEGER LastAccessTime;
	LARGE_INTEGER LastWriteTime;
	LARGE_INTEGER ChangeTime;
	ULONG FileAttributes;
} FILE_BASIC_INFORMATION, *PFILE_BASIC_INFORMATION;


#define	NONE_OP		0
#define	PROC_OP		1
#define	REG_OP		2
#define	FILE_OP		3
#define	SERVICE_OP	4

#define	OPTION_TO_JUGE		1
#define	OPTION_TO_NOTIFY	2
#define	OPTION_PROC_EXIT	3
#define	OPTION_TIME_TO_HOOK	4

#define	FILE_READ_DATA_XX		1
#define	FILE_WRITE_DATA_XX		2
#define	FILE_DEL_XX				3
#define	FILE_RENAME_XX			4
#define	FILE_CREATE_XX			5
#define	FILE_SETINFO_XX			6
#define	FILE_EXECUTE_XX			7

#define  OP_PROC_KILL						1  // ɱ������                          
#define  OP_PROC_CREATE_REMOTE_THREAD		2  // Զ���̴̳߳���                     
#define  OP_PROC_READ_PROCESS				3  // ���̶�����             
#define  OP_PROC_WRITE_PROCESS				4  // ����д����  
#define  OP_PROC_CREATE_PROCESS				5  // ���̴�������  
#define  OP_PROC_CHANGE_VM					6  // �޸��ڴ����� 
#define  OP_PROC_SUSPEND_RESUME				7  // �������
#define  OP_THREAD_KILL						8  // ɱ���߳�
#define  OP_THREAD_SUSPEND_RESUME			9  // �ָ��߳�
#define  OP_THREAD_GET_CONTEXT				10  // ��ȡCONTEXT
#define  OP_THREAD_SET_CONTEXT				11  // ����CONTEXT
#define  OP_PROC_DUPHANDLE				    12  // ���ƾ��


#define  OP_REG_READ						1  // ע����
#define  OP_REG_DELETE_VALUE_KEY			3  // ɾ����ֵ
#define  OP_REG_CREATE_KEY                  4  // ������
#define  OP_REG_SET_VALUE_KEY				5  // ���ü�ֵ
#define  OP_REG_RENAME						6  // ������
#define  OP_REG_DELETE_KEY                  7  // ɾ����
#define  OP_REG_SAVE						8  // ����
#define  OP_REG_RESTORE						9 // �ָ�
#define  OP_REG_REPLACE						10 // �滻
#define  OP_REG_LOAD						11 // ����
#define  OP_REG_UNLOAD						12 // ж��

#define  OP_SERVICE_CREATE					1 //��������
#define  OP_SERVICE_DELETE					2 //ɾ������
#define  OP_SERVICE_CHANGE					3 //�޸ķ���
#define  OP_SERVICE_DRIVER					4 //��������

typedef struct _HIPS_RULE_NODE
{
	UCHAR		major_type;
	UCHAR		minor_type;
	UCHAR		is_dir;
	HANDLE		sub_pid;
	union
	{
		HANDLE		obj_pid;
	};
	WCHAR		des_path[MAXPATHLEN];
	union
	{
		FILE_BASIC_INFORMATION	fbi;
		WCHAR		new_name[MAXPATHLEN];
		WCHAR		key_value[MAXPATHLEN];
		WCHAR		service_name[MAXPATHLEN];
	};

} HIPS_RULE_NODE, *PHIPS_RULE_NODE;

typedef SC_HANDLE (WINAPI *fn_CreateServiceW)(
			_In_        SC_HANDLE    hSCManager,
			_In_        LPCWSTR     lpServiceName,
			_In_opt_    LPCWSTR     lpDisplayName,
			_In_        DWORD        dwDesiredAccess,
			_In_        DWORD        dwServiceType,
			_In_        DWORD        dwStartType,
			_In_        DWORD        dwErrorControl,
			_In_opt_    LPCWSTR     lpBinaryPathName,
			_In_opt_    LPCWSTR     lpLoadOrderGroup,
			_Out_opt_   LPDWORD      lpdwTagId,
			_In_opt_    LPCWSTR     lpDependencies,
			_In_opt_    LPCWSTR     lpServiceStartName,
			_In_opt_    LPCWSTR     lpPassword
			);

typedef SC_HANDLE (WINAPI *fn_CreateServiceA)(
			_In_        SC_HANDLE    hSCManager,
			_In_        LPCSTR     lpServiceName,
			_In_opt_    LPCSTR     lpDisplayName,
			_In_        DWORD        dwDesiredAccess,
			_In_        DWORD        dwServiceType,
			_In_        DWORD        dwStartType,
			_In_        DWORD        dwErrorControl,
			_In_opt_    LPCSTR     lpBinaryPathName,
			_In_opt_    LPCSTR     lpLoadOrderGroup,
			_Out_opt_   LPDWORD      lpdwTagId,
			_In_opt_    LPCSTR     lpDependencies,
			_In_opt_    LPCSTR     lpServiceStartName,
			_In_opt_    LPCSTR     lpPassword
			);

typedef SC_HANDLE (WINAPI* fn_OpenServiceW)(
				_In_            SC_HANDLE               hSCManager,
				_In_            LPCWSTR                lpServiceName,
				_In_            DWORD                   dwDesiredAccess
				);

typedef SC_HANDLE (WINAPI* fn_OpenServiceA)(
				_In_            SC_HANDLE               hSCManager,
				_In_            LPCSTR                lpServiceName,
				_In_            DWORD                   dwDesiredAccess
				);


typedef BOOL (WINAPI* fn_EndTask)(
			_In_ HWND hWnd,
			_In_ BOOL fShutDown,
			_In_ BOOL fForce
			);

SC_HANDLE WINAPI fake_CreateServiceW(
		_In_        SC_HANDLE    hSCManager,
		_In_        LPCWSTR     lpServiceName,
		_In_opt_    LPCWSTR     lpDisplayName,
		_In_        DWORD        dwDesiredAccess,
		_In_        DWORD        dwServiceType,
		_In_        DWORD        dwStartType,
		_In_        DWORD        dwErrorControl,
		_In_opt_    LPCWSTR     lpBinaryPathName,
		_In_opt_    LPCWSTR     lpLoadOrderGroup,
		_Out_opt_   LPDWORD      lpdwTagId,
		_In_opt_    LPCWSTR     lpDependencies,
		_In_opt_    LPCWSTR     lpServiceStartName,
		_In_opt_    LPCWSTR     lpPassword
		);

SC_HANDLE WINAPI fake_CreateServiceA(
		_In_        SC_HANDLE    hSCManager,
		_In_        LPCSTR     lpServiceName,
		_In_opt_    LPCSTR     lpDisplayName,
		_In_        DWORD        dwDesiredAccess,
		_In_        DWORD        dwServiceType,
		_In_        DWORD        dwStartType,
		_In_        DWORD        dwErrorControl,
		_In_opt_    LPCSTR     lpBinaryPathName,
		_In_opt_    LPCSTR     lpLoadOrderGroup,
		_Out_opt_   LPDWORD      lpdwTagId,
		_In_opt_    LPCSTR     lpDependencies,
		_In_opt_    LPCSTR     lpServiceStartName,
		_In_opt_    LPCSTR     lpPassword
		);

SC_HANDLE WINAPI fake_OpenServiceW(
		_In_            SC_HANDLE               hSCManager,
		_In_            LPCWSTR                lpServiceName,
		_In_            DWORD                   dwDesiredAccess
		);

SC_HANDLE WINAPI fake_OpenServiceA(
		_In_            SC_HANDLE               hSCManager,
		_In_            LPCSTR                lpServiceName,
		_In_            DWORD                   dwDesiredAccess
		);


BOOL WINAPI fake_EndTask(
		_In_ HWND hWnd,
		_In_ BOOL fShutDown,
		_In_ BOOL fForce
		);

extern fn_CreateServiceW	real_CreateServiceW ;
extern fn_CreateServiceA	real_CreateServiceA;
extern fn_OpenServiceW		real_OpenServiceW;
extern fn_OpenServiceA		real_OpenServiceA;
extern fn_EndTask			real_EndTask;