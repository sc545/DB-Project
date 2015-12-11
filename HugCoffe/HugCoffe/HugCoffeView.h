
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
//	CListBox m_list;
	CListCtrl m_listCtrl;
	afx_msg void OnClickedButtonInsert();
	int m_iCurSel;
};

#ifndef _DEBUG  // HugCoffeView.cpp�� ����� ����
inline CHugCoffeDoc* CHugCoffeView::GetDocument() const
   { return reinterpret_cast<CHugCoffeDoc*>(m_pDocument); }
#endif

