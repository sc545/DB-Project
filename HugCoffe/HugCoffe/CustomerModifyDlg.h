#pragma once
#include "afxwin.h"


// CCustomerModifyDlg ��ȭ �����Դϴ�.

class CCustomerModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerModifyDlg)

public:
	CCustomerModifyDlg(CWnd* pParent = NULL, CString name = NULL, CString phone = NULL, LONG id = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CCustomerModifyDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_CUTOMER_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strCusName;
	CString m_strCusPhone;
	afx_msg void OnClickedButtonCustomerOk();
	CEdit m_editCusName;
	CEdit m_editCusPhone;
	LONG m_lCusId;
	afx_msg void OnClickedButtonCustomerCancel();
};
