#pragma once


// CCustomerInsertDlg ��ȭ �����Դϴ�.

class CCustomerInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerInsertDlg)

public:
	CCustomerInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCustomerInsertDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CUSTOMER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonCustomerInsert();
	CString m_strCusName;
	CString m_strCusPhone;
	afx_msg void OnClickedButtonCustomerInsertCancel();
};