#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CCustomerSelectDlg 대화 상자입니다.

class CCustomerSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerSelectDlg)

public:
	CCustomerSelectDlg(CWnd* pParent = NULL, CListCtrl* listCtrl = NULL);   // 표준 생성자입니다.
	virtual ~CCustomerSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CUSTOMER_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
