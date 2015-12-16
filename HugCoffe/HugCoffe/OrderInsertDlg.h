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
	afx_msg void OnClickedButtonOrderInsert();
	afx_msg void OnClickedButtonOrderDelete();
	int m_iBeverageCurSel;
	int m_iSideCurSel;
	afx_msg void OnSelchangeComboBeverage();
	afx_msg void OnSelchangeComboSize();
	afx_msg void OnSelchangeComboHotIce();
	afx_msg void OnSelchangeComboSide();
	CString m_strBeverage;
	CString m_strSize;
	CString m_strHotIce;
	CString m_strSide;
	int m_nExtraCharge;
	afx_msg void OnClickedButtonOrderOk();
	afx_msg void OnClickedButtonOrderCancel();
	afx_msg void OnItemchangedListOrderList(NMHDR *pNMHDR, LRESULT *pResult);
	int m_iSelectedItem;
	afx_msg void OnInsertitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeleteitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult);
	LONG m_lPrice;
	LONG m_lTotalPrice;
	LONG m_lPoint;
	afx_msg void OnBnClickedButtonCustomerSelect();
	int m_iCusId;
	afx_msg void OnBnClickedCheckPoint();
	afx_msg void OnEnChangeEditPoint();
	LONG m_lSavePoint;
	LONG m_lOrderId;
//	int m_nSelectedItem;
};
