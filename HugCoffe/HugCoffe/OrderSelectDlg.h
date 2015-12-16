#pragma once
#include "afxwin.h"


// COrderSelectDlg ��ȭ �����Դϴ�.

class COrderSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderSelectDlg)

public:
	COrderSelectDlg(CWnd* pParent = NULL, CListCtrl* list = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COrderSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ORDER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
