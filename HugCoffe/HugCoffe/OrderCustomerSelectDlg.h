#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// COrderCustomerSelectDlg 대화 상자입니다.

class COrderCustomerSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderCustomerSelectDlg)

public:
	COrderCustomerSelectDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COrderCustomerSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ORDER_CUSTOMER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
