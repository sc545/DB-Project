
// HugCoffeView.h : CHugCoffeView 클래스의 인터페이스
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "afxwin.h"


class CHugCoffeView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CHugCoffeView();
	DECLARE_DYNCREATE(CHugCoffeView)

public:
	enum{ IDD = IDD_HUGCOFFE_FORM };

// 특성입니다.
public:
	CHugCoffeDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~CHugCoffeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // HugCoffeView.cpp의 디버그 버전
inline CHugCoffeDoc* CHugCoffeView::GetDocument() const
   { return reinterpret_cast<CHugCoffeDoc*>(m_pDocument); }
#endif

