#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCustomerSelectDlg ��ȭ �����Դϴ�.

class CCustomerSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerSelectDlg)

public:
	CCustomerSelectDlg(CWnd* pParent = NULL, CListCtrl* listCtrl = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCustomerSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CUSTOMER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cbCusOption;
	CString m_strCusOption;
	afx_msg void OnSelchangeComboCustomerOption();
	int m_iCusOptionCurSel;
	afx_msg void OnClickedButtonCustomerOk();
	void OnInitialUpdateList(void);
	CListCtrl* m_listCustomer;
	afx_msg void OnClickedButtonCustomerCancel();
	CEdit m_editCusOption;
};
