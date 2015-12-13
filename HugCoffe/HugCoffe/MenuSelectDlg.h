#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMenuSelectDlg 대화 상자입니다.

class CMenuSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuSelectDlg)

public:
	CMenuSelectDlg(CWnd* pParent = NULL, CListCtrl* listMenu1 = NULL, CListCtrl* listMenu2 = NULL);   // 표준 생성자입니다.
	virtual ~CMenuSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MENU_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
