
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
#include "tblBeverage.h"
#include "MenuInsertDlg.h"
#include "tblSide.h"
#include "MenuModifyDlg.h"
#include "MenuSelectDlg.h"
#include "OrderInsertDlg.h"
#include "tblOrder.h"
#include "OrderModifyDlg.h"
#include "tblOrder_Beverage.h"
#include "tblOrder_Side.h"
#include "OrderSelectDlg.h"
#include "GoodsInsertDlg.h"
#include "tblGoods.h"
#include "GoodsModifyDlg.h"
#include "GoodsSelectDlg.h"
#include "tblSales.h"
#include "SalesModifyDlg.h"
#include "SalesSelectDlg.h"

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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_MENU1, &CHugCoffeView::OnItemchangedListMenu1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_MENU2, &CHugCoffeView::OnItemchangedListMenu2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ORDER, &CHugCoffeView::OnItemchangedListOrder)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_GOODS, &CHugCoffeView::OnItemchangedListGoods)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_SALES, &CHugCoffeView::OnItemchangedListSales)
END_MESSAGE_MAP()

// CHugCoffeView 생성/소멸

CHugCoffeView::CHugCoffeView()
	: CFormView(CHugCoffeView::IDD)
	, m_iCurSel(0)
	, m_nSelectedItem(0)
	, m_strCusName(_T(""))
	, m_strCusPhone(_T(""))
	, m_lCusId(0)
	, m_lMenuId(0)
	, m_strMenuName(_T(""))
	, m_lMenuPrice(0)
	, m_iSelectedMenu(0)
	, m_iOrderId(0)
	, m_lPoint(0)
	, m_iGoodsId(0)
	, m_strGoodsName(_T(""))
	, m_lGoodsNum(0)
	, m_strSalesDate(_T(""))
	, m_lSalesTotal(0)
	, m_lSalesNum(0)
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
	LPWSTR list1[3] = {_T("음료번호"), _T("음료이름"), _T("음료가격")};
	int nWidth1[3] = {100, 100, 150};

	for(int i=0; i<3; i++){
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
	LPWSTR list3[6] = {_T("주문번호"), _T("사용 포인트"), _T("총 주문액"), _T("적립 포인트"), _T("주문날짜"), _T("고객번호")};
	int nWidth3[6] = {100, 100, 100, 100, 100, 100};

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
	LPWSTR list4[3] = {_T("물품번호"), _T("물품명") , _T("수량")};
	int nWidth4[3] = {100, 100, 100};

	for(int i=0; i<3; i++){
		lvColumn4.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn4.fmt = LVCFMT_CENTER;
		lvColumn4.pszText = list4[i];
		lvColumn4.iSubItem = i;
		lvColumn4.cx = nWidth4[i];
		m_listGoods.InsertColumn(i, &lvColumn4);
	}

	m_listGoods.SetExtendedStyle(m_listGoods.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	LV_COLUMN lvColumn5;
	LPWSTR list5[3] = {_T("날짜"), _T("총매출액"), _T("총주문건")};
	int nWidth5[3] = {100, 100, 100};

	for(int i=0; i<3; i++){
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

		m_listMenu1.DeleteAllItems();
		m_listMenu2.DeleteAllItems();
		OnInitialUpdateList();

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

		m_listOrder.DeleteAllItems();
		OnInitialUpdateList();

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

		m_listGoods.DeleteAllItems();
		OnInitialUpdateList();

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

		m_listCustomer.DeleteAllItems();
		OnInitialUpdateList();

		break;
	}	
	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
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
	}else if(m_iCurSel == 1){
		CMenuInsertDlg CMenuInsertDlg;
		if(CMenuInsertDlg.DoModal() == 1){
			OnInitialUpdateList();
		}
	}else if(m_iCurSel == 2){
		COrderInsertDlg COrderInsertDlg;
		if(COrderInsertDlg.DoModal() == 1){
			OnInitialUpdateList();
		}
	}
	else if(m_iCurSel == 3){
		CGoodsInsertDlg CGoodsInsertDlg;
		if(CGoodsInsertDlg.DoModal() == 1){
			OnInitialUpdateList();
		}
	}else if(m_iCurSel == 4){
		if(MessageBox(_T("매출을 등록 하시겠습니까?"), _T("매출등록"), MB_OKCANCEL) == IDOK){
			CtblSales<CtblSalesSelectWhereDateAccessor> selectWhereDateSales;
			SYSTEMTIME time;
			GetLocalTime(&time);
			CString strCurTime;
			//strCurTime.Format(_T("%d.%d.%d.%d.%d.%d"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
			strCurTime.Format(_T("%d-%d-%d"), time.wYear, time.wMonth, time.wDay);

			wcscpy_s((wchar_t*)selectWhereDateSales.m_sales_date, 11, (const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()));
			selectWhereDateSales.m_dwsales_dateLength = wcslen((const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()))*2;
			selectWhereDateSales.m_dwsales_dateStatus = DBSTATUS_S_OK;

			if(selectWhereDateSales.OpenAll() == S_OK){
				if(selectWhereDateSales.MoveNext() == S_OK){
					CtblSales<CtblSalesInsertAccessor> insertSales;
					wcscpy_s((wchar_t*)insertSales.m_sales_date, 11, (const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()));
					insertSales.m_dwsales_dateLength = wcslen((const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()))*2;
					insertSales.m_dwsales_dateStatus = DBSTATUS_S_OK;

					if(insertSales.OpenAll() == S_OK){

					}else{
						AfxMessageBox(_T("데이터베이스 접속 실패!!"));
					}
				}else{
					CtblSales<CtblSalesInsertAccessor> insertSales;
					wcscpy_s((wchar_t*)insertSales.m_sales_date, 11, (const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()));
					insertSales.m_dwsales_dateLength = wcslen((const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()))*2;
					insertSales.m_dwsales_dateStatus = DBSTATUS_S_OK;

					if(insertSales.OpenAll() == S_OK){

					}else{
						AfxMessageBox(_T("데이터베이스 접속 실패!!"));
					}
				}

			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}

			OnInitialUpdateList();
		}else{

		}
	}
}


void CHugCoffeView::OnInitialUpdateList(void)
{
	m_listCustomer.DeleteAllItems();
	m_listMenu1.DeleteAllItems();
	m_listMenu2.DeleteAllItems();
	m_listOrder.DeleteAllItems();
	m_listGoods.DeleteAllItems();
	m_listSales.DeleteAllItems();
	CtblCustomer<CtblCustomerSelectAccessor> selectCustomer;
	CtblBeverage<CtblBeverageSelectAccessor> selectBeverage;
	CtblSide<CtblSideSelectAccessor> selectSide;
	CtblOrder<CtblOrderSelectAccessor> selectOrder;
	CtblGoods<CtblGoodsSelectAccessor> selectGoods;
	CtblSales<CtblSalesSelectAccessor> selectSales;
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
	if(selectBeverage.OpenAll() == S_OK){
		while(selectBeverage.MoveNext() == S_OK){
			nCount = m_listMenu1.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			strCount.Format(_T("%d"), selectBeverage.m_bev_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listMenu1.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectBeverage.m_bev_name;
			m_listMenu1.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			strCount.Format(_T("%d"), selectBeverage.m_bev_price);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listMenu1.SetItem(&lvItem);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}
	if(selectSide.OpenAll() == S_OK){
		while(selectSide.MoveNext() == S_OK){
			nCount = m_listMenu2.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			strCount.Format(_T("%d"), selectSide.m_side_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listMenu2.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectSide.m_side_name;
			m_listMenu2.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			strCount.Format(_T("%d"), selectSide.m_side_price);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listMenu2.SetItem(&lvItem);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	if(selectOrder.OpenAll() == S_OK){
		while(selectOrder.MoveNext() == S_OK){
			nCount = m_listOrder.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			strCount.Format(_T("%d"), selectOrder.m_order_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listOrder.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			strCount.Format(_T("%d"), selectOrder.m_order_used_point);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listOrder.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			strCount.Format(_T("%d"), selectOrder.m_order_price);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listOrder.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 3;
			strCount.Format(_T("%d"), selectOrder.m_order_save_point);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listOrder.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 4;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectOrder.m_order_date;
			m_listOrder.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 5;
			strCount.Format(_T("%d"), selectOrder.m_cus_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listOrder.SetItem(&lvItem);

		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	if(selectGoods.OpenAll() == S_OK){
		while(selectGoods.MoveNext() == S_OK){
			nCount = m_listGoods.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			strCount.Format(_T("%d"), selectGoods.m_goods_id);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listGoods.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectGoods.m_goods_name;
			m_listGoods.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			strCount.Format(_T("%d"), selectGoods.m_goods_num);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listGoods.SetItem(&lvItem);


		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	if(selectSales.OpenAll() == S_OK){
		while(selectSales.MoveNext() == S_OK){
			nCount = m_listSales.GetItemCount();
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 0;
			lvItem.pszText = (LPWSTR)(LPCTSTR)selectSales.m_sales_date;
			m_listSales.InsertItem(&lvItem);
				
			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 1;
			strCount.Format(_T("%d"), selectSales.m_sales_total);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listSales.SetItem(&lvItem);

			lvItem.mask = LVIF_TEXT;
			lvItem.iItem = nCount;
			lvItem.iSubItem = 2;
			strCount.Format(_T("%d"), selectSales.m_sales_num);
			lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
			m_listSales.SetItem(&lvItem);


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
	}else if(m_iCurSel == 1){
		CMenuModifyDlg CMenuModifyDlg(NULL, m_strMenuName, m_lMenuPrice, m_lMenuId, m_iSelectedMenu);
		if(CMenuModifyDlg.DoModal() == 1){
			OnInitialUpdateList();
			((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		}
	}else if(m_iCurSel == 2){
		COrderModifyDlg COrderModifyDlg(NULL, m_iOrderId);
		if(COrderModifyDlg.DoModal() == 1){
			OnInitialUpdateList();
			((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		}
	}else if(m_iCurSel == 3){
		CGoodsModifyDlg CGoodsModifyDlg(NULL, m_iGoodsId, m_strGoodsName, m_lGoodsNum);
		if(CGoodsModifyDlg.DoModal() == 1){
			OnInitialUpdateList();
			((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(FALSE);
		}
	}else if(m_iCurSel == 4){
		CSalesModifyDlg CSalesModifyDlg(NULL, m_lSalesTotal, m_lSalesNum, m_strSalesDate);
		if(CSalesModifyDlg.DoModal() == 1){
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
	}else if(m_iCurSel == 1){
		if(m_iSelectedMenu == 0){
			if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("메뉴삭제"), MB_OKCANCEL) == IDOK){
				CtblBeverage<CtblBeverageDeleteAccessor> deleteBeverage;
				deleteBeverage.m_bev_id = m_lMenuId;
				deleteBeverage.m_dwbev_idStatus = DBSTATUS_S_OK;
				if(deleteBeverage.OpenAll() == S_OK){
					OnInitialUpdateList();
					((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!"));
				}
			}else{

			}
		}else if(m_iSelectedMenu == 1){
			if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("메뉴삭제"), MB_OKCANCEL) == IDOK){
				CtblSide<CtblSideDeleteAccessor> deleteSide;
				deleteSide.m_side_id = m_lMenuId;
				deleteSide.m_dwside_idStatus = DBSTATUS_S_OK;
				if(deleteSide.OpenAll() == S_OK){
					OnInitialUpdateList();
					((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!"));
				}
			}else{

			}
		}
	}else if(m_iCurSel == 2){
		if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("주문삭제"), MB_OKCANCEL) == IDOK){
			CtblOrder_Beverage<CtblOrder_BeverageDeleteAccessor> deleteOrderBeverage;
			CtblOrder_Side<CtblOrder_SideDeleteAccessor> deleteOrderSide;
			CtblCustomer<CtblCustomerUpdatePointAccessor> updatePointCustomer;

			deleteOrderBeverage.m_order_id = m_iOrderId;
			deleteOrderBeverage.m_dworder_idStatus = DBSTATUS_S_OK;
			deleteOrderSide.m_order_id = m_iOrderId;
			deleteOrderSide.m_dworder_idStatus = DBSTATUS_S_OK;

			if(deleteOrderBeverage.OpenAll() == S_OK){

			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!1"));
			}
			if(deleteOrderSide.OpenAll() == S_OK){

			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!2"));
			}

			CtblOrder<CtblOrderDeleteAccessor> deleteOrder;
			deleteOrder.m_order_id = m_iOrderId;
			deleteOrder.m_dworder_idStatus = DBSTATUS_S_OK;
			if(deleteOrder.OpenAll() == S_OK){
				OnInitialUpdateList();
				((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!3"));
			}

			// 고객 포인트 차감
			if(m_lCusId != 0){

				updatePointCustomer.m_cus_id = m_lCusId;
				updatePointCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;

				updatePointCustomer.m_cus_point = -m_lPoint;
				updatePointCustomer.m_dwcus_pointStatus = DBSTATUS_S_OK;

				if(updatePointCustomer.OpenAll() == S_OK){

				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!"));
				}	
			}
			
			
		}else{

		}
	}else if(m_iCurSel == 3){
		if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("물품삭제"), MB_OKCANCEL) == IDOK){
			CtblGoods<CtblGoodsDeleteAccessor> deleteGoods;
			deleteGoods.m_goods_id = m_iGoodsId;
			deleteGoods.m_dwgoods_idStatus = DBSTATUS_S_OK;
			if(deleteGoods.OpenAll() == S_OK){
				OnInitialUpdateList();
				((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}else{

		}
	}else if(m_iCurSel == 4){
		if(MessageBox(_T("정말로 삭제 하시겠습니까?"), _T("매출삭제"), MB_OKCANCEL) == IDOK){
			CtblSales<CtblSalesDeleteAccessor> deleteSales;
			wcscpy_s((wchar_t*)deleteSales.m_sales_date, 20, (const wchar_t*)m_strSalesDate.GetBuffer(m_strSalesDate.GetLength()));
			deleteSales.m_dwsales_dateLength = wcslen((const wchar_t*)m_strSalesDate.GetBuffer(m_strSalesDate.GetLength()))*2;
			deleteSales.m_dwsales_dateStatus = DBSTATUS_S_OK;
			if(deleteSales.OpenAll() == S_OK){
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
	}else if(m_iCurSel == 1){
		if(m_iSelectedMenu == 0){
			CMenuSelectDlg CMenuSelectDlg(NULL, &m_listMenu1, &m_listMenu2);
			if(CMenuSelectDlg.DoModal() == 1){

			}
		}else{

		}
	}else if(m_iCurSel == 2){
		COrderSelectDlg COrderSelectDlg(NULL, &m_listOrder);
		if(COrderSelectDlg.DoModal() == 1){
			
		}
	}
	else if(m_iCurSel == 3){
		CGoodsSelectDlg CGoodsSelectDlg(NULL, &m_listGoods);
		if(CGoodsSelectDlg.DoModal() == 1){
			
		}
	}else if(m_iCurSel == 4){
		CSalesSelectDlg CSalesSelectDlg(NULL, &m_listSales);
		if(CSalesSelectDlg.DoModal() == 1){
			
		}
	}
}


void CHugCoffeView::OnItemchangedListMenu1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;
	m_iSelectedMenu = 0;
	m_lMenuId = _wtol(m_listMenu1.GetItemText(m_nSelectedItem, 0));
	m_strMenuName = m_listMenu1.GetItemText(m_nSelectedItem, 1);
	m_lMenuPrice = _wtol(m_listMenu1.GetItemText(m_nSelectedItem, 2));

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void CHugCoffeView::OnItemchangedListMenu2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;
	m_iSelectedMenu = 1;
	m_lMenuId = _wtol(m_listMenu2.GetItemText(m_nSelectedItem, 0));
	m_strMenuName = m_listMenu2.GetItemText(m_nSelectedItem, 1);
	m_lMenuPrice = _wtol(m_listMenu2.GetItemText(m_nSelectedItem, 2));

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void CHugCoffeView::OnItemchangedListOrder(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;
	m_iOrderId = _wtol(m_listOrder.GetItemText(m_nSelectedItem, 0));
	m_lCusId = _wtol(m_listOrder.GetItemText(m_nSelectedItem, 5));
	m_lPoint = _wtol(m_listOrder.GetItemText(m_nSelectedItem, 3));

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void CHugCoffeView::OnItemchangedListGoods(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;
	m_iGoodsId = _wtol(m_listGoods.GetItemText(m_nSelectedItem, 0));
	m_strGoodsName = m_listGoods.GetItemText(m_nSelectedItem, 1);
	m_lGoodsNum = _wtol(m_listGoods.GetItemText(m_nSelectedItem, 2));

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void CHugCoffeView::OnItemchangedListSales(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nSelectedItem = pNMLV->iItem;
	m_strSalesDate = m_listSales.GetItemText(m_nSelectedItem, 0);
	m_lSalesTotal = _wtol(m_listSales.GetItemText(m_nSelectedItem, 1));
	m_lSalesNum = _wtol(m_listSales.GetItemText(m_nSelectedItem, 2));

	((CButton*)GetDlgItem(IDC_BUTTON_MODIFY))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}
