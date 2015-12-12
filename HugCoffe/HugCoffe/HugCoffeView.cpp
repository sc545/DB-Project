
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
#include "CustomerInsertDlg.h"
#include "tblCustomer.h"
#include "CustomerModifyDlg.h"
#include "CustomerSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHugCoffeView

IMPLEMENT_DYNCREATE(CHugCoffeView, CFormView)

BEGIN_MESSAGE_MAP(CHugCoffeView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SELECTION, &CHugCoffeView::OnTcnSelchangeTab3)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CHugCoffeView::OnClickedButtonInsert)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CUSTOMER, &CHugCoffeView::OnItemchangedListCustomer)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CHugCoffeView::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CHugCoffeView::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_SELECT, &CHugCoffeView::OnClickedButtonSelect)
END_MESSAGE_MAP()

// CHugCoffeView 생성/소멸

CHugCoffeView::CHugCoffeView()
	: CFormView(CHugCoffeView::IDD)
	, m_iCurSel(0)
	, m_nSelectedItem(0)
	, m_strCusName(_T(""))
	, m_strCusPhone(_T(""))
	, m_lCusId(0)
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
	DDX_Control(pDX, IDC_LIST_CUSTOMER, m_listCustomer);
	DDX_Control(pDX, IDC_LIST_MENU1, m_listMenu1);
	DDX_Control(pDX, IDC_LIST_MENU2, m_listMenu2);
	DDX_Control(pDX, IDC_LIST_ORDER, m_listOrder);
	DDX_Control(pDX, IDC_LIST_GOODS, m_listGoods);
	DDX_Control(pDX, IDC_LIST_SALES, m_listSales);
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
	LPWSTR list[6] = {_T("고객번호"), _T("이름"), _T("전화번호"), _T("포인트")};
	int nWidth[4] = {100, 100, 150, 100};

	for(int i=0; i<4; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCustomer.InsertColumn(i, &lvColumn);
	}

	m_listCustomer.SetExtendedStyle(m_listCustomer.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn1;
	LPWSTR list1[5] = {_T("음료번호"), _T("음료이름"), _T("음료가격"), _T("사이즈"), _T("Hot & Ice")};
	int nWidth1[5] = {100, 100, 150, 100, 100};

	for(int i=0; i<5; i++){
		lvColumn1.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn1.fmt = LVCFMT_CENTER;
		lvColumn1.pszText = list1[i];
		lvColumn1.iSubItem = i;
		lvColumn1.cx = nWidth1[i];
		m_listMenu1.InsertColumn(i, &lvColumn1);
	}

	m_listMenu1.SetExtendedStyle(m_listMenu1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn2;
	LPWSTR list2[3] = {_T("사이드번호"), _T("사이드이름"), _T("사이드가격")};
	int nWidth2[3] = {100, 100, 150};

	for(int i=0; i<3; i++){
		lvColumn2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn2.fmt = LVCFMT_CENTER;
		lvColumn2.pszText = list2[i];
		lvColumn2.iSubItem = i;
		lvColumn2.cx = nWidth2[i];
		m_listMenu2.InsertColumn(i, &lvColumn2);
	}

	m_listMenu2.SetExtendedStyle(m_listMenu1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn3;
	LPWSTR list3[6] = {_T("주문번호"), _T("음료"), _T("사이드"), _T("주문날짜"), _T("총주문액"), _T("고객번호")};
	int nWidth3[6] = {100, 100, 150, 100, 100, 100};

	for(int i=0; i<6; i++){
		lvColumn3.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn3.fmt = LVCFMT_CENTER;
		lvColumn3.pszText = list3[i];
		lvColumn3.iSubItem = i;
		lvColumn3.cx = nWidth3[i];
		m_listOrder.InsertColumn(i, &lvColumn3);
	}

	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn4;
	LPWSTR list4[2] = {_T("물품번호"), _T("수량")};
	int nWidth4[2] = {100, 100};

	for(int i=0; i<2; i++){
		lvColumn4.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn4.fmt = LVCFMT_CENTER;
		lvColumn4.pszText = list4[i];
		lvColumn4.iSubItem = i;
		lvColumn4.cx = nWidth4[i];
		m_listGoods.InsertColumn(i, &lvColumn4);
	}

	m_listGoods.SetExtendedStyle(m_listGoods.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn5;
	LPWSTR list5[2] = {_T("날짜"), _T("총매출액")};
	int nWidth5[2] = {100, 100};

	for(int i=0; i<2; i++){
		lvColumn5.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn5.fmt = LVCFMT_CENTER;
		lvColumn5.pszText = list5[i];
		lvColumn5.iSubItem = i;
		lvColumn5.cx = nWidth5[i];
		m_listSales.InsertColumn(i, &lvColumn5);
	}

	m_listSales.SetExtendedStyle(m_listSales.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	

	m_listCustomer.ShowWindow(TRUE);
	m_listMenu1.ShowWindow(FALSE);
	m_listMenu2.ShowWindow(FALSE);
	m_listOrder.ShowWindow(FALSE);
	m_listGoods.ShowWindow(FALSE);
	m_listSales.ShowWindow(FALSE);

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
	
	OnInitialUpdateList();
	
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
	m_iCurSel = m_tabSelection.GetCurSel();
	
	switch (m_iCurSel){
	case 0:
		m_listCustomer.ShowWindow(TRUE);
		m_listMenu1.ShowWindow(FALSE);
		m_listMenu2.ShowWindow(FALSE);
		m_listOrder.ShowWindow(FALSE);
		m_listGoods.ShowWindow(FALSE);
		m_listSales.ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("고객등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("고객수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("고객삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("고객검색"));
		
		m_listCustomer.DeleteAllItems();
		OnInitialUpdateList();
		
		break;
	case 1:
		m_listCustomer.ShowWindow(FALSE);
		m_listMenu1.ShowWindow(TRUE);
		m_listMenu2.ShowWindow(TRUE);
		m_listOrder.ShowWindow(FALSE);
		m_listGoods.ShowWindow(FALSE);
		m_listSales.ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("메뉴등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("메뉴수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("메뉴삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("메뉴검색"));
		break;
	case 2:
		m_listCustomer.ShowWindow(FALSE);
		m_listMenu1.ShowWindow(FALSE);
		m_listMenu2.ShowWindow(FALSE);
		m_listOrder.ShowWindow(TRUE);
		m_listGoods.ShowWindow(FALSE);
		m_listSales.ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("주문등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("주문수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("주문삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("주문검색"));
		break;
	case 3:
		m_listCustomer.ShowWindow(FALSE);
		m_listMenu1.ShowWindow(FALSE);
		m_listMenu2.ShowWindow(FALSE);
		m_listOrder.ShowWindow(FALSE);
		m_listGoods.ShowWindow(TRUE);
		m_listSales.ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("물품등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("물품수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("물품삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("물품검색"));
		break;
	case 4:
		m_listCustomer.ShowWindow(FALSE);
		m_listMenu1.ShowWindow(FALSE);
		m_listMenu2.ShowWindow(FALSE);
		m_listOrder.ShowWindow(FALSE);
		m_listGoods.ShowWindow(FALSE);
		m_listSales.ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("매출등록"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("매출수정"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("매출삭제"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("매출검색"));
		break;
	}	

}


void CHugCoffeView::OnClickedButtonInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

	if(m_iCurSel == 0){
		CCustomerInsertDlg CCustomerInsertDlg;
		if(CCustomerInsertDlg.DoModal() == 1){
			OnInitialUpdateList();
		}
	}
}


void CHugCoffeView::OnInitialUpdateList(void)
{
	m_listCustomer.DeleteAllItems();
	CtblCustomer<CtblCustomerSelectAccessor> selectCustomer;
	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	if(selectCustomer.OpenAll() == S_OK){
		while(selectCustomer.MoveNext() == S_OK){
			nCount = m_listCustomer.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			strCount.Format(_T("%d"), selectCustomer.m_cus_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listCustomer.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectCustomer.m_cus_name;
			m_listCustomer.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectCustomer.m_cus_phone;
			m_listCustomer.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;				
			lvItem.iItem = nCount;
			lvItem.iSubItem = 3;
			strCount.Format(_T("%d"), selectCustomer.m_cus_point);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listCustomer.SetItem(&lvItem);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}
}


void CHugCoffeView::OnItemchangedListCustomer(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;

	m_lCusId = _wtol(m_listCustomer.GetItemText(m_nSelectedItem, 0));
	m_strCusName = m_listCustomer.GetItemText(m_nSelectedItem, 1);
	m_strCusPhone = m_listCustomer.GetItemText(m_nSelectedItem, 2);

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);

	*pResult = 0;
}


void CHugCoffeView::OnClickedButtonModify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

	if(m_iCurSel == 0){
		CCustomerModifyDlg CCustomerModifyDlg(NULL, m_strCusName, m_strCusPhone, m_lCusId);
		if(CCustomerModifyDlg.DoModal() == 1){
			OnInitialUpdateList();
			((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		}
	}
	

}



void CHugCoffeView::OnClickedButtonDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);

	if(m_iCurSel == 0){
		if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("고객삭제"), MB_OKCANCEL) == IDOK){
			CtblCustomer<CtblCustomerDeleteAccessor> deleteCustomer;
			deleteCustomer.m_cus_id = m_lCusId;
			deleteCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;
			if(deleteCustomer.OpenAll() == S_OK){
				OnInitialUpdateList();
				((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}else{

		}
	}
}


void CHugCoffeView::OnClickedButtonSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);

	if(m_iCurSel == 0){
		CCustomerSelectDlg CCustomerSelectDlg(NULL, &m_listCustomer);
		if(CCustomerSelectDlg.DoModal() == 1){
			
		}
	}
}
