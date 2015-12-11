
// HugCoffeView.cpp : CHugCoffeView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HugCoffe.h"
#endif

#include "HugCoffeDoc.h"
#include "HugCoffeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHugCoffeView

IMPLEMENT_DYNCREATE(CHugCoffeView, CFormView)

BEGIN_MESSAGE_MAP(CHugCoffeView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SELECTION, &CHugCoffeView::OnTcnSelchangeTab3)
END_MESSAGE_MAP()

// CHugCoffeView 생성/소멸

CHugCoffeView::CHugCoffeView()
	: CFormView(CHugCoffeView::IDD)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHugCoffeView::~CHugCoffeView()
{
}

void CHugCoffeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SELECTION, m_tabSelection);
	DDX_Control(pDX, IDC_LIST, m_listCtrl);
}

BOOL CHugCoffeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CHugCoffeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	TC_ITEM tabItem;
	LPWSTR tabName[5] = {_T("고객관리"),_T("메뉴관리"),_T("주문관리"),_T("물품관리"),_T("매출관리")};
	
	for(int i=0; i<5; i++){
		tabItem.mask =TCIF_TEXT;
		tabItem.pszText = tabName[i];
		m_tabSelection.InsertItem(i,&tabItem);

	}

	LV_COLUMN lvColumn;
	LPWSTR list[4] = {_T("고객번호"), _T("이름"), _T("전화번호"), _T("포인트")};
	int nWidth[4] = {100, 100, 150, 100};

	for(int i=0; i<4; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCtrl.InsertColumn(i, &lvColumn);
	}

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	
}


// CHugCoffeView 진단

#ifdef _DEBUG
void CHugCoffeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHugCoffeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHugCoffeDoc* CHugCoffeView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHugCoffeDoc)));
	return (CHugCoffeDoc*)m_pDocument;
}
#endif //_DEBUG


// CHugCoffeView 메시지 처리기


void CHugCoffeView::OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
	
	

	int nSelection = m_tabSelection.GetCurSel();
	LV_COLUMN lvColumn;
	LPWSTR list[6];
	int lastColumn = 0;
	int nWidth[6];
	switch (nSelection){
	case 0:
		//GetDlgItem(IDC_BUTTON_CUS
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("고객등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("고객수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("고객삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("고객검색"));
		list[0] = _T("고객번호");list[1] = _T("이름");list[2] = _T("전화번호");list[3] = _T("포인트");
		lastColumn=4;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;
		break;
	case 1:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("메뉴등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("메뉴수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("메뉴삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("메뉴검색"));
		list[0] = _T("메뉴번호");list[1] = _T("이름");list[2] = _T("가격");list[3] = _T("사이즈");list[4] = _T("Hot & Ice");
		lastColumn=5;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;nWidth[4] = 100;
		break;
	case 2:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("주문등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("주문수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("주문삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("주문검색"));
		list[0] = _T("주문번호");list[1] = _T("음료");list[2] = _T("사이드");list[3] = _T("주문날짜");list[4] = _T("총주문액");list[5] = _T("고객번호");
		lastColumn=6;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;nWidth[4] = 100;nWidth[5] = 100;
		break;
	case 3:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("물품등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("물품수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("물품삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("물품검색"));
		list[0] = _T("물품번호");list[1] = _T("수량");
		lastColumn=2;
		nWidth[0] = 100;nWidth[1] = 100;
		break;
	case 4:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("매출등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("매출수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("매출삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("매출검색"));
		list[0] = _T("날짜");list[1] = _T("총매출액");
		lastColumn=2;
		nWidth[0] = 100;nWidth[1] = 100;
		break;
	}
	
	
	

	for(int i=0; i<lastColumn; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCtrl.DeleteColumn(i);
		m_listCtrl.InsertColumn(i, &lvColumn);
		if(i == lastColumn-1)
			for(int j=lastColumn; j<6; j++)
				m_listCtrl.DeleteColumn(j);
	}
	

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
}
