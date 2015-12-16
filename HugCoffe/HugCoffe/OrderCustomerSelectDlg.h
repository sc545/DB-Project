#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// COrderCustomerSelectDlg ��ȭ �����Դϴ�.

class COrderCustomerSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderCustomerSelectDlg)

public:
	COrderCustomerSelectDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COrderCustomerSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ORDER_CUSTOMER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cbCusOption;
	CEdit m_editCusOption;
	CString m_strCusOption;
	void OnInitialUpdateList(void);
	CListCtrl m_listCustomer;
	afx_msg void OnSelchangeComboCustomerOption();
	int m_iCusOptionCurSel;
	afx_msg void OnButtonCustomerOk();
	afx_msg void OnButtonCustomerCancel();
	afx_msg void OnClickedButtonCustomerSelect();
	afx_msg void OnClickedButtonCustomerSelectAll();
	afx_msg void OnClickedButtonCustomerSelectOk();
	afx_msg void OnClickedButtonCustomerSelectCancel();
	afx_msg void OnItemchangedListCustomer(NMHDR *pNMHDR, LRESULT *pResult);
	LONG m_lCusId;
//	LONG m_lOrderId;
};
