#pragma once


// CCustomerInsertDlg 대화 상자입니다.

class CCustomerInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerInsertDlg)

public:
	CCustomerInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CCustomerInsertDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CUSTOMER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonCustomerInsert();
	CString m_strCusName;
	CString m_strCusPhone;
	afx_msg void OnClickedButtonCustomerInsertCancel();
};
