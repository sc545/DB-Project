#pragma once
#include "afxwin.h"


// CSalesModifyDlg ��ȭ �����Դϴ�.

class CSalesModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSalesModifyDlg)

public:
	CSalesModifyDlg(CWnd* pParent = NULL,	LONG total = NULL, LONG num = NULL, CString date = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSalesModifyDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SALES_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
