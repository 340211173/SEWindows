#pragma once
                 
#define  OP_PROC_KILL                      1  // ɱ������                          
#define  OP_PROC_CREATE_REMOTE_THREAD      2  // Զ���̴̳߳���                     
#define  OP_PROC_READ_PROCESS              3  // ���̶�����             
#define  OP_PROC_WRITE_PROCESS             4  // ����д����  
#define  OP_PROC_CREATE_PROCESS            5  // ���̴�������  
#define  OP_PROC_CHANGE_VM				   6  // �޸��ڴ����� 


#define PROCESS_TERMINATE                  (0x0001)  
#define PROCESS_CREATE_THREAD              (0x0002)  
#define PROCESS_SET_SESSIONID              (0x0004)  
#define PROCESS_VM_OPERATION               (0x0008)  
#define PROCESS_VM_READ                    (0x0010)  
#define PROCESS_VM_WRITE                   (0x0020)  
#define PROCESS_DUP_HANDLE                 (0x0040)  
#define PROCESS_CREATE_PROCESS             (0x0080)  
#define PROCESS_SET_QUOTA                  (0x0100)  
#define PROCESS_SET_INFORMATION            (0x0200)  
#define PROCESS_QUERY_INFORMATION          (0x0400)  
#define PROCESS_SUSPEND_RESUME             (0x0800)  
#define PROCESS_QUERY_LIMITED_INFORMATION  (0x1000)  


#if (NTDDI_VERSION >= NTDDI_VISTA)
OB_PREOP_CALLBACK_STATUS pre_procopration_callback( PVOID RegistrationContext, POB_PRE_OPERATION_INFORMATION pOperationInformation);
NTSTATUS sw_init_procss(PDRIVER_OBJECT pDriverObj);
NTSTATUS sw_uninit_procss(PDRIVER_OBJECT pDriverObj);
VOID create_process_notity_routine( PEPROCESS Process, HANDLE ProcessId, PPS_CREATE_NOTIFY_INFO CreateInfo);
#endif