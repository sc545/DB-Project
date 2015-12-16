#pragma once
#include "afxwin.h"


// CSalesModifyDlg 대화 상자입니다.

class CSalesModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSalesModifyDlg)

public:
	CSalesModifyDlg(CWnd* pParent = NULL,	LONG total = NULL, LONG num = NULL, CString date = NULL);   // 표준 생성자입니다.
	virtual ~CSalesModifyDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_SALES_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editSalesNum;
	CString m_strSalesNum;
	CEdit m_editSalesTotal;
	CString m_strSalesTotal;
	afx_msg void OnClickedButtonSalesOk();
	afx_msg void OnClickedButtonSalesCancel();
	CString m_strSalesDate;
};
