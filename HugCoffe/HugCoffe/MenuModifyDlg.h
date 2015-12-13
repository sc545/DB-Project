#pragma once
#include "afxwin.h"


// CMenuModifyDlg ��ȭ �����Դϴ�.

class CMenuModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuModifyDlg)

public:
	CMenuModifyDlg(CWnd* pParent = NULL, CString name = NULL, LONG price = NULL, LONG id = NULL, int selectedMenu = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMenuModifyDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MENU_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editMenuName;
	CEdit m_editMenuPrice;
	CString m_strMenuName;
	LONG m_lMenuPrice;
	LONG m_lMenuId;
	afx_msg void OnClickedButtonMenuOk();
	int m_iSelectedMenu;
	afx_msg void OnClickedButtonMenuCancel();
};
