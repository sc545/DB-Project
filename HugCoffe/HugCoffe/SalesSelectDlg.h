#pragma once
#include "afxwin.h"


// CSalesSelectDlg 대화 상자입니다.

class CSalesSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSalesSelectDlg)

public:
	CSalesSelectDlg(CWnd* pParent = NULL, CListCtrl* list = NULL);   // 표준 생성자입니다.
	virtual ~CSalesSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_SALES_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editSalesOption;
	CString m_strSalesOption;
	CListCtrl* m_listSales;
	afx_msg void OnClickedButtonSalesOk();
	afx_msg void OnClickedButtonSalesCancel();
};
