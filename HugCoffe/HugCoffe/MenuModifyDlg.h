#pragma once
#include "afxwin.h"


// CMenuModifyDlg 대화 상자입니다.

class CMenuModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuModifyDlg)

public:
	CMenuModifyDlg(CWnd* pParent = NULL, CString name = NULL, LONG price = NULL, LONG id = NULL, int selectedMenu = NULL);   // 표준 생성자입니다.
	virtual ~CMenuModifyDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MENU_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
