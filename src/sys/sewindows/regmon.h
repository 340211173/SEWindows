#pragma once

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

NTSTATUS sw_register_init(PDRIVER_OBJECT pDriverObject);
NTSTATUS sw_register_uninit(PDRIVER_OBJECT pDriverObject);
NTSTATUS sw_get_current_user(WCHAR *srcPath, int len);
int sw_regisster_make_path(WCHAR * path, ULONG lenstr);
