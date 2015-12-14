#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// COrderInsertDlg 대화 상자입니다.

class COrderInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderInsertDlg)

public:
	COrderInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COrderInsertDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ORDER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_cbBeverage;
	CComboBox m_cbSize;
	CComboBox m_cbHotIce;
	CComboBox m_cbSide;
	CString m_strCusId;
	CListCtrl m_listOrder;
	CString m_strPrice;
	CButton m_checkPoint;
	CString m_strPoint;
	CString m_strTotalPrice;
	CString m_strSavePoint;
};
