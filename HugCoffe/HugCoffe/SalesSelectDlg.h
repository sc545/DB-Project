#pragma once
#include "afxwin.h"


// CSalesSelectDlg ��ȭ �����Դϴ�.

class CSalesSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSalesSelectDlg)

public:
	CSalesSelectDlg(CWnd* pParent = NULL, CListCtrl* list = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CSalesSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_SALES_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editSalesOption;
	CString m_strSalesOption;
	CListCtrl* m_listSales;
	afx_msg void OnClickedButtonSalesOk();
	afx_msg void OnClickedButtonSalesCancel();
};
