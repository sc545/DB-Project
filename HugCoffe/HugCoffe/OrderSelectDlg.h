#pragma once
#include "afxwin.h"


// COrderSelectDlg 대화 상자입니다.

class COrderSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderSelectDlg)

public:
	COrderSelectDlg(CWnd* pParent = NULL, CListCtrl* list = NULL);   // 표준 생성자입니다.
	virtual ~COrderSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ORDER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl* m_listOrder;
	CComboBox m_cbOrderOption;
	CString m_strOrderOption;
	afx_msg void OnSelchangeComboOrderOption();
	afx_msg void OnClickedButtonOrderOk();
	afx_msg void OnClickedButtonOrderCancel();
	int m_iOrderOptionCurSel;
	void OnInitialUpdateList(void);
};
