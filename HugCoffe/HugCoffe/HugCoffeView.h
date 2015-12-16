
// HugCoffeView.h : CHugCoffeView Ŭ������ �������̽�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"


class CHugCoffeView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CHugCoffeView();
	DECLARE_DYNCREATE(CHugCoffeView)

public:
	enum{ IDD = IDD_HUGCOFFE_FORM };

// Ư���Դϴ�.
public:
	CHugCoffeDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CHugCoffeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl m_tabSelection;
	CListCtrl m_listCustomer;
	afx_msg void OnClickedButtonInsert();
	int m_iCurSel;
	CListCtrl m_listMenu1;
	CListCtrl m_listMenu2;
	CListCtrl m_listOrder;
	CListCtrl m_listGoods;
	CListCtrl m_listSales;
	void OnInitialUpdateList(void);
	int m_nSelectedItem;
	afx_msg void OnItemchangedListCustomer(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strCusName;
	CString m_strCusPhone;
	afx_msg void OnClickedButtonModify();
	LONG m_lCusId;
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonSelect();
	afx_msg void OnItemchangedListMenu1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnItemchangedListMenu2(NMHDR *pNMHDR, LRESULT *pResult);
	LONG m_lMenuId;
//	LONG m_lMenu2Id;
	CString m_strMenuName;
	LONG m_lMenuPrice;
	int m_iSelectedMenu;
	afx_msg void OnItemchangedListOrder(NMHDR *pNMHDR, LRESULT *pResult);
	int m_iOrderId;
	LONG m_lPoint;
	int m_iGoodsId;
	afx_msg void OnItemchangedListGoods(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strGoodsName;
	LONG m_lGoodsNum;
	CString m_strSalesDate;
	LONG m_lSalesTotal;
	LONG m_lSalesNum;
	afx_msg void OnItemchangedListSales(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // HugCoffeView.cpp�� ����� ����
inline CHugCoffeDoc* CHugCoffeView::GetDocument() const
   { return reinterpret_cast<CHugCoffeDoc*>(m_pDocument); }
#endif

