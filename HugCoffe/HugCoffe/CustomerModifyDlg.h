#pragma once
#include "afxwin.h"


// CCustomerModifyDlg 대화 상자입니다.

class CCustomerModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomerModifyDlg)

public:
	CCustomerModifyDlg(CWnd* pParent = NULL, CString name = NULL, CString phone = NULL, LONG id = NULL);   // 표준 생성자입니다.
	virtual ~CCustomerModifyDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_CUTOMER_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
