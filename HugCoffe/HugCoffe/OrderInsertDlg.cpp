// OrderInsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderInsertDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"
#include "OrderCustomerSelectDlg.h"
#include "tblCustomer.h"
#include "tblOrder.h"
#include "tblOrder_Beverage.h"
#include "tblOrder_Side.h"

// COrderInsertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COrderInsertDlg, CDialogEx)

COrderInsertDlg::COrderInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderInsertDlg::IDD, pParent)
	, m_strCusId(_T(""))
	, m_strPrice(_T(""))
	, m_strPoint(_T(""))
	, m_strTotalPrice(_T(""))
	, m_strSavePoint(_T(""))
	, m_iBeverageCurSel(0)
	, m_iSideCurSel(0)
	, m_strBeverage(_T(""))
	, m_strSize(_T(""))
	, m_strHotIce(_T(""))
	, m_strSide(_T(""))
	, m_nExtraCharge(0)
	, m_iSelectedItem(0)
	, m_lPrice(0)
	, m_lTotalPrice(0)
	, m_lPoint(0)
	, m_iCusId(0)
	, m_lSavePoint(0)
	, m_lOrderId(0)
{

}

COrderInsertDlg::~COrderInsertDlg()
{
}
BOOL COrderInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	//m_editCusName.SetLimitText(19);
	//m_editCusPhone.SetLimitText(11);

	m_cbBeverage.SetCurSel(0);
	m_cbSize.SetCurSel(0);
	m_cbHotIce.SetCurSel(0);
	m_cbSide.SetCurSel(0);
	m_strBeverage = _T("-");
	m_strSize = _T("-");
	m_strHotIce = _T("-");
	m_strSide = _T("-");

	((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_OK))->EnableWindow(FALSE);

	CtblBeverage<CtblBeverageSelectAccessor> selectBeverage;
	CtblSide<CtblSideSelectAccessor> selectSide;
	CtblOrder<CtblOrderSelectAccessor> selectOrder;

	if(selectOrder.OpenAll() == S_OK){
		while(selectOrder.MoveNext() == S_OK){
			if(selectOrder.m_order_id > m_lOrderId)
				m_lOrderId = selectOrder.m_order_id;
		}
		++m_lOrderId;
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	if(selectBeverage.OpenAll() == S_OK){
		while(selectBeverage.MoveNext() == S_OK){
			m_cbBeverage.AddString(selectBeverage.m_bev_name);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}
	
	if(selectSide.OpenAll() == S_OK){
		while(selectSide.MoveNext() == S_OK){
			m_cbSide.AddString(selectSide.m_side_name);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	LV_COLUMN lvColumn;
	LPWSTR list[5] = {_T("음료"), _T("사이즈"), _T("Hot&Ice"), _T("사이드"), _T("가격")};
	int nWidth[5] = {90, 70, 70, 90, 90};

	for(int i=0; i<5; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listOrder.InsertColumn(i, &lvColumn);
	}
	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;
}
void COrderInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_BEVERAGE, m_cbBeverage);
	DDX_Control(pDX, IDC_COMBO_SIZE, m_cbSize);
	DDX_Control(pDX, IDC_COMBO_HOT_ICE, m_cbHotIce);
	DDX_Control(pDX, IDC_COMBO_SIDE, m_cbSide);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_ID, m_strCusId);
	DDX_Control(pDX, IDC_LIST_ORDER_LIST, m_listOrder);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_strPrice);
	DDX_Control(pDX, IDC_CHECK_POINT, m_checkPoint);
	DDX_Text(pDX, IDC_EDIT_POINT, m_strPoint);
	DDX_Text(pDX, IDC_EDIT_TOTAL_PRICE, m_strTotalPrice);
	DDX_Text(pDX, IDC_EDIT_SAVE_POINT, m_strSavePoint);
}


BEGIN_MESSAGE_MAP(COrderInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_ORDER_INSERT, &COrderInsertDlg::OnClickedButtonOrderInsert)
	ON_BN_CLICKED(ID_BUTTON_ORDER_DELETE, &COrderInsertDlg::OnClickedButtonOrderDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_BEVERAGE, &COrderInsertDlg::OnSelchangeComboBeverage)
	ON_CBN_SELCHANGE(IDC_COMBO_SIZE, &COrderInsertDlg::OnSelchangeComboSize)
	ON_CBN_SELCHANGE(IDC_COMBO_HOT_ICE, &COrderInsertDlg::OnSelchangeComboHotIce)
	ON_CBN_SELCHANGE(IDC_COMBO_SIDE, &COrderInsertDlg::OnSelchangeComboSide)
	ON_BN_CLICKED(ID_BUTTON_ORDER_OK, &COrderInsertDlg::OnClickedButtonOrderOk)
	ON_BN_CLICKED(ID_BUTTON_ORDER_CANCEL, &COrderInsertDlg::OnClickedButtonOrderCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnItemchangedListOrderList)
	ON_NOTIFY(LVN_INSERTITEM, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnInsertitemListOrderList)
	ON_NOTIFY(LVN_DELETEITEM, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnDeleteitemListOrderList)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT, &COrderInsertDlg::OnBnClickedButtonCustomerSelect)
	ON_BN_CLICKED(IDC_CHECK_POINT, &COrderInsertDlg::OnBnClickedCheckPoint)
	ON_EN_CHANGE(IDC_EDIT_POINT, &COrderInsertDlg::OnEnChangeEditPoint)
END_MESSAGE_MAP()


// COrderInsertDlg 메시지 처리기입니다.


void COrderInsertDlg::OnClickedButtonOrderInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CtblBeverage<CtblBeverageSelectWhereNameAccessor> selectWhereNameBeverage;
	CtblSide<CtblSideSelectWhereNameAccessor> selectWhereNameSide;
	int nCount;
	LV_ITEM lvItem;
	CString str;
	int price = 0;
	UpdateData();
	nCount = m_listOrder.GetItemCount();
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;
	lvItem.iSubItem = 0;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strBeverage;
	m_listOrder.InsertItem(&lvItem);
				
	wcscpy_s((wchar_t*)selectWhereNameBeverage.m_bev_name, 20, (const wchar_t*)m_strBeverage.GetBuffer(m_strBeverage.GetLength()));
	selectWhereNameBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strBeverage.GetBuffer(m_strBeverage.GetLength()))*2;
	selectWhereNameBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;		
	lvItem.iSubItem = 1;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strSize;
	m_listOrder.SetItem(&lvItem);

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;
	lvItem.iSubItem = 2;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strHotIce;
	m_listOrder.SetItem(&lvItem);

	lvItem.mask = LVIF_TEXT;				
	lvItem.iItem = nCount;
	lvItem.iSubItem = 3;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strSide;
	m_listOrder.SetItem(&lvItem);

	wcscpy_s((wchar_t*)selectWhereNameSide.m_side_name, 20, (const wchar_t*)m_strSide.GetBuffer(m_strSide.GetLength()));
	selectWhereNameSide.m_dwside_nameLength= wcslen((const wchar_t*)m_strSide.GetBuffer(m_strSide.GetLength()))*2;
	selectWhereNameSide.m_dwside_nameStatus = DBSTATUS_S_OK;

	switch (m_cbSize.GetCurSel()){
	case 0:
	case 2:
		break;
	case 1:
		m_nExtraCharge -= 500;
		break;
	case 3:
		m_nExtraCharge += 500;
		break;
	}
	if(m_cbHotIce.GetCurSel() == 2){
		m_nExtraCharge +=500;
	}
	

	if(selectWhereNameBeverage.OpenAll() == S_OK){
		if(selectWhereNameBeverage.MoveNext() == S_OK){
			price = selectWhereNameBeverage.m_bev_price;
			price += m_nExtraCharge;
			str.Format(_T("%d"), price);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	if(selectWhereNameSide.OpenAll() == S_OK){
		if(selectWhereNameSide.MoveNext() == S_OK){
			price += selectWhereNameSide.m_side_price;
			str.Format(_T("%d"), price);
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}

	lvItem.mask = LVIF_TEXT;				
	lvItem.iItem = nCount;
	lvItem.iSubItem = 4;
	str.Format(_T("%d"), price);
	lvItem.pszText = (LPWSTR)(LPCTSTR)str;
	m_listOrder.SetItem(&lvItem);

	m_lPrice += price;
	str.Format(_T("%ld"), m_lPrice);
	m_strPrice = str;
	m_lTotalPrice = m_lPrice - m_lPoint;
	str.Format(_T("%ld"), m_lTotalPrice);
	m_strTotalPrice = str;

	if(m_strCusId.Compare(_T("")) != 0 && m_strCusId.Compare(_T(" "))){
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
	}
	UpdateData(FALSE);

	m_nExtraCharge = 0;
	
}


void COrderInsertDlg::OnClickedButtonOrderDelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listOrder.DeleteItem(m_iSelectedItem);
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(FALSE);

}


void COrderInsertDlg::OnSelchangeComboBeverage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_cbBeverage.GetCurSel() == 0 && m_cbSide.GetCurSel() == 0){
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
		m_strBeverage = _T("-");
		m_strSize = _T("-");
		m_strHotIce = _T("-");
		m_cbSize.EnableWindow(FALSE);
		m_cbHotIce.EnableWindow(FALSE);
		m_cbBeverage.EnableWindow(TRUE);
		m_cbSide.EnableWindow(TRUE);
	}else{
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(TRUE);
		if(m_cbBeverage.GetCurSel() == 0){
			m_strBeverage = _T("-");
			m_strSize = _T("-");
			m_strHotIce = _T("-");
			m_cbSize.EnableWindow(FALSE);
			m_cbHotIce.EnableWindow(FALSE);
			m_cbSide.EnableWindow(TRUE);
		}else{
			m_cbBeverage.GetLBText(m_cbBeverage.GetCurSel(), m_strBeverage);
			m_strSize = _T("미디움");
			m_strHotIce = _T("Hot");
			m_cbSize.EnableWindow(TRUE);
			m_cbHotIce.EnableWindow(TRUE);
			m_cbSide.EnableWindow(FALSE);
		}
	
	}
}


void COrderInsertDlg::OnSelchangeComboSize()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_cbSize.GetCurSel() == 1){
		m_strSize = _T("스몰");
	}else if(m_cbSize.GetCurSel() == 2){
		m_strSize = _T("미디움");
	}else if(m_cbSize.GetCurSel() == 3){
		m_strSize = _T("라지");
	}else{
		m_strSize = _T("미디움");
	}
}


void COrderInsertDlg::OnSelchangeComboHotIce()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_cbHotIce.GetCurSel() == 1){
		m_strHotIce = _T("Hot");
	}else if(m_cbHotIce.GetCurSel() == 2){
		m_strHotIce = _T("Ice");
	}else{
		m_strHotIce = _T("Hot");
	}
}


void COrderInsertDlg::OnSelchangeComboSide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_cbBeverage.GetCurSel() == 0 && m_cbSide.GetCurSel() == 0){
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
		m_strSide = _T("-");
		m_cbBeverage.EnableWindow(TRUE);
		m_cbSide.EnableWindow(TRUE);
	}else{
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(TRUE);
		if(m_cbSide.GetCurSel() == 0){
			m_strSide = _T("-");
			m_cbBeverage.EnableWindow(TRUE);
		}else{
			m_cbSide.GetLBText(m_cbSide.GetCurSel(), m_strSide);
			m_cbBeverage.EnableWindow(FALSE);
		}
	}
}


void COrderInsertDlg::OnClickedButtonOrderOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CtblOrder<CtblOrderInsertAccessor> insertOrder;
	CtblCustomer<CtblCustomerUpdatePointAccessor> updatePointCustomer;
	
	UpdateData();

	SYSTEMTIME time;
	GetLocalTime(&time);
	CString strCurTime;
	//strCurTime.Format(_T("%d.%d.%d.%d.%d.%d"), time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond);
	strCurTime.Format(_T("%d-%d-%d"), time.wYear, time.wMonth, time.wDay);


	insertOrder.m_order_id = m_lOrderId;
	insertOrder.m_dworder_idStatus = DBSTATUS_S_OK;

	wcscpy_s((wchar_t*)insertOrder.m_order_date, 11, (const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()));
	insertOrder.m_dworder_dateLength = wcslen((const wchar_t*)strCurTime.GetBuffer(strCurTime.GetLength()))*2;
	insertOrder.m_dworder_dateStatus = DBSTATUS_S_OK;

	if(m_checkPoint.GetCheck())
		insertOrder.m_order_used_point = _wtol(m_strPoint);
	else
		insertOrder.m_order_used_point = 0;
	insertOrder.m_dworder_used_pointStatus = DBSTATUS_S_OK;

	insertOrder.m_order_price = _wtol(m_strTotalPrice);
	insertOrder.m_dworder_priceStatus = DBSTATUS_S_OK;

	insertOrder.m_order_save_point = _wtol(m_strSavePoint);
	insertOrder.m_dworder_save_pointStatus = DBSTATUS_S_OK;

	if(m_strCusId.Compare(_T("")) == 0 && m_strCusId.Compare(_T(" ")) == 0){
		insertOrder.m_cus_id = -1;
	}else{
		insertOrder.m_cus_id = _wtol(m_strCusId);

		// 고객 포인트 차감
		if(m_checkPoint.GetCheck()){
			updatePointCustomer.m_cus_id = _wtol(m_strCusId);
			updatePointCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;
			
			updatePointCustomer.m_cus_point = -_wtol(m_strPoint);
			updatePointCustomer.m_dwcus_pointStatus = DBSTATUS_S_OK;

			if(updatePointCustomer.OpenAll() == S_OK){

			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
			updatePointCustomer.CloseAll();
		}
		// 고객 포인트 적립
		updatePointCustomer.m_cus_id = _wtol(m_strCusId);
		updatePointCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;

		updatePointCustomer.m_cus_point = _wtol(m_strSavePoint);
		updatePointCustomer.m_dwcus_pointStatus = DBSTATUS_S_OK;

		if(updatePointCustomer.OpenAll() == S_OK){

		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}


	}
	insertOrder.m_dwcus_idStatus = DBSTATUS_S_OK;

	

	
	int nCount = m_listOrder.GetItemCount();
	CString str;
	if(insertOrder.OpenAll() == S_OK){
		
		for(int i=0;i<nCount; i++){
			CtblOrder_Beverage<CtblOrder_BeverageInsertAccessor> insertOrederBeverage;
			CtblOrder_Side<CtblOrder_SideInsertAccessor> insertOrederSide;
			CtblBeverage<CtblBeverageSelectWhereNameAccessor> selectWhereNameBeverage;
			CtblSide<CtblSideSelectWhereNameAccessor> selectWhereNameSide;

			insertOrederBeverage.m_order_id = m_lOrderId;
			insertOrederBeverage.m_dworder_idStatus = DBSTATUS_S_OK;
			insertOrederSide.m_order_id = m_lOrderId;
			insertOrederSide.m_dworder_idStatus = DBSTATUS_S_OK;

			str = m_listOrder.GetItemText(i, 0);
			// 음료 메뉴 일 경우
			if(str.Compare(_T("-")) != 0){
				wcscpy_s((wchar_t*)selectWhereNameBeverage.m_bev_name, 20, (const wchar_t*)str.GetBuffer(str.GetLength()));
				selectWhereNameBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)str.GetBuffer(str.GetLength()))*2;
				selectWhereNameBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

				if(selectWhereNameBeverage.OpenAll() == S_OK){
					if(selectWhereNameBeverage.MoveNext() == S_OK){
						insertOrederBeverage.m_bev_id = selectWhereNameBeverage.m_bev_id;
						insertOrederBeverage.m_dwbev_idStatus = DBSTATUS_S_OK;
						
						str = m_listOrder.GetItemText(i, 1);
						if(str.Compare(_T("스몰")) == 0){
							insertOrederBeverage.m_bev_size = 0;
						}else if(str.Compare(_T("미디움")) == 0){
							insertOrederBeverage.m_bev_size = 1;
						}else{
							insertOrederBeverage.m_bev_size = 2;
						}
						insertOrederBeverage.m_dwbev_sizeStatus = DBSTATUS_S_OK;

						str = m_listOrder.GetItemText(i, 2);
						if(str.Compare(_T("Hot")) == 0){
							insertOrederBeverage.m_bev_hot_ice = 0;
						}else{
							insertOrederBeverage.m_bev_hot_ice = 1;
						}
						insertOrederBeverage.m_dwbev_hot_iceStatus = DBSTATUS_S_OK;

						
						insertOrederBeverage.m_bev_price = _wtol(m_listOrder.GetItemText(i, 4));
						insertOrederBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

						if(insertOrederBeverage.OpenAll() == S_OK){

						}else{
							AfxMessageBox(_T("데이터베이스 접속 실패!!1"));
						}
					}

				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!2"));
				}



				insertOrederSide.m_side_id = -1;
				insertOrederSide.m_dwside_idStatus = DBSTATUS_S_OK;

				insertOrederSide.m_side_price = 0;
				insertOrederSide.m_dwside_priceStatus = DBSTATUS_S_OK;
						
				if(insertOrederSide.OpenAll() == S_OK){

				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!3"));
				}

			// 사이드 메뉴 일 경우
			}else{
				str = m_listOrder.GetItemText(i, 3);
				wcscpy_s((wchar_t*)selectWhereNameSide.m_side_name, 20, (const wchar_t*)str.GetBuffer(str.GetLength()));
				selectWhereNameSide.m_dwside_nameLength = wcslen((const wchar_t*)str.GetBuffer(str.GetLength()))*2;
				selectWhereNameSide.m_dwside_nameStatus = DBSTATUS_S_OK;

				if(selectWhereNameSide.OpenAll() == S_OK){
					if(selectWhereNameSide.MoveNext() == S_OK){
						insertOrederSide.m_side_id = selectWhereNameSide.m_side_id;
						insertOrederSide.m_dwside_idStatus = DBSTATUS_S_OK;

						insertOrederSide.m_side_price = _wtol(m_listOrder.GetItemText(i, 4));
						insertOrederSide.m_dwside_priceStatus = DBSTATUS_S_OK;
						
						if(insertOrederSide.OpenAll() == S_OK){

						}else{
							AfxMessageBox(_T("데이터베이스 접속 실패!!3"));
						}
					}

				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!4"));
				}


				insertOrederBeverage.m_bev_id = -1;
				insertOrederBeverage.m_dwbev_idStatus = DBSTATUS_S_OK;
						
				insertOrederBeverage.m_bev_size = -1;
				insertOrederBeverage.m_dwbev_sizeStatus = DBSTATUS_S_OK;

				insertOrederBeverage.m_bev_hot_ice = -1;
				insertOrederBeverage.m_dwbev_hot_iceStatus = DBSTATUS_S_OK;

				insertOrederBeverage.m_bev_price = 0;
				insertOrederBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

				if(insertOrederBeverage.OpenAll() == S_OK){

				}else{
					AfxMessageBox(_T("데이터베이스 접속 실패!!1"));
				}
			
				
			}
			

		}

		

	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!5"));
	}
	
	EndDialog(1);

}


void COrderInsertDlg::OnClickedButtonOrderCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}


void COrderInsertDlg::OnItemchangedListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_iSelectedItem = pNMLV->iItem;
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void COrderInsertDlg::OnInsertitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_OK))->EnableWindow(TRUE);
	*pResult = 0;
}


void COrderInsertDlg::OnDeleteitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_lPrice -= _wtol(m_listOrder.GetItemText(pNMLV->iItem, 4));
	CString str;
	str.Format(_T("%ld"), m_lPrice);
	m_strPrice = str;
	m_lTotalPrice = m_lPrice - m_lPoint;
	str.Format(_T("%ld"), m_lTotalPrice);
	m_strTotalPrice = str;

	if(m_strCusId.Compare(_T("")) != 0 && m_strCusId.Compare(_T(" "))){
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
	}
	UpdateData(FALSE);
	
	if(m_listOrder.GetItemCount() == 1){
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_OK))->EnableWindow(FALSE);
	}
	*pResult = 0;
}


void COrderInsertDlg::OnBnClickedButtonCustomerSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	COrderCustomerSelectDlg COrderCustomerSelectDlg;
	CString str;
	m_iCusId = COrderCustomerSelectDlg.DoModal();
	UpdateData();
	if(m_iCusId != 0){
		str.Format(_T("%d"), m_iCusId); 
		m_strCusId = str;
		
		CtblCustomer<CtblCustomerSelectWhereIdAccessor> selectWhereIdCustomer;
		selectWhereIdCustomer.m_cus_id = m_iCusId;
		selectWhereIdCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;
		if(selectWhereIdCustomer.OpenAll() == S_OK){
			if(selectWhereIdCustomer.MoveNext() == S_OK){
				m_lPoint = selectWhereIdCustomer.m_cus_point;
				str.Format(_T("%ld"), m_lPoint);
				m_strPoint = str;
		}
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
		m_checkPoint.SetCheck(FALSE);
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		((CButton*)GetDlgItem(IDC_EDIT_POINT))->EnableWindow(TRUE);
	}else{
		m_strCusId = " ";
		m_checkPoint.SetCheck(FALSE);
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;

		m_strSavePoint = _T("");

		((CButton*)GetDlgItem(IDC_EDIT_POINT))->EnableWindow(FALSE);
	}
	UpdateData(FALSE);
	
}


void COrderInsertDlg::OnBnClickedCheckPoint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	if(m_checkPoint.GetCheck()){
		UpdateData();
		m_lPoint = _wtol(m_strPoint);
		m_lTotalPrice = m_lPrice - m_lPoint;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}else{
		UpdateData();
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}
}


void COrderInsertDlg::OnEnChangeEditPoint()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

//#1015

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_checkPoint.GetCheck()){
		CString str;

		UpdateData();
		m_lPoint = _wtol(m_strPoint);
		m_lTotalPrice = m_lPrice - m_lPoint;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}

}
