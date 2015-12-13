#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMenuSelectDlg ��ȭ �����Դϴ�.

class CMenuSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuSelectDlg)

public:
	CMenuSelectDlg(CWnd* pParent = NULL, CListCtrl* listMenu1 = NULL, CListCtrl* listMenu2 = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMenuSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MENU_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	void OnInitialUpdateList(void);
	CListCtrl* m_listMenu1;
	CListCtrl* m_listMenu2;
	afx_msg void OnRadioBeverage();
	afx_msg void OnRadioSide();
	int m_iSelectedMenu;
	CComboBox m_cbMenuOption;
	afx_msg void OnSelchangeComboMenuOption();
	int m_iMenuOptionCurSel;
	CString m_strMenuOption;
	afx_msg void OnClickedButtonMenuOk();
	afx_msg void OnClickedButtonMenuCancel();
};
