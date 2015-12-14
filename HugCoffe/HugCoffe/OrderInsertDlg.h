#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// COrderInsertDlg ��ȭ �����Դϴ�.

class COrderInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderInsertDlg)

public:
	COrderInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COrderInsertDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ORDER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
