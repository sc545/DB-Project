// MenuSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "MenuSelectDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// CMenuSelectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMenuSelectDlg, CDialogEx)

CMenuSelectDlg::CMenuSelectDlg(CWnd* pParent /*=NULL*/, CListCtrl* listMenu1, CListCtrl* listMenu2)
	: CDialogEx(CMenuSelectDlg::IDD, pParent)
	, m_iSelectedMenu(0)
	, m_iMenuOptionCurSel(0)
	, m_strMenuOption(_T(""))
{
	m_listMenu1 = listMenu1;
	m_listMenu2 = listMenu2;
}

CMenuSelectDlg::~CMenuSelectDlg()
{
}

BOOL CMenuSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	/*m_editCusOption.SetLimitText(19);
	m_cbCusOption.SetCurSel(0);*/
	m_cbMenuOption.SetCurSel(0);
	((CButton*)GetDlgItem(IDC_RADIO_BEVERAGE))->SetCheck(TRUE);
	return TRUE;
}
void CMenuSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MENU_OPTION, m_cbMenuOption);
	DDX_Text(pDX, IDC_EDIT_MENU_OPTION, m_strMenuOption);
}


BEGIN_MESSAGE_MAP(CMenuSelectDlg, CDialogEx)
	ON_COMMAND(IDC_RADIO_BEVERAGE, &CMenuSelectDlg::OnRadioBeverage)
	ON_COMMAND(IDC_RADIO_SIDE, &CMenuSelectDlg::OnRadioSide)
	ON_CBN_SELCHANGE(IDC_COMBO_MENU_OPTION, &CMenuSelectDlg::OnSelchangeComboMenuOption)
	ON_BN_CLICKED(ID_BUTTON_MENU_OK, &CMenuSelectDlg::OnClickedButtonMenuOk)
	ON_BN_CLICKED(ID_BUTTON_MENU_CANCEL, &CMenuSelectDlg::OnClickedButtonMenuCancel)
END_MESSAGE_MAP()


// CMenuSelectDlg 메시지 처리기입니다.


void CMenuSelectDlg::OnInitialUpdateList(void)
{
	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	if(m_iSelectedMenu == 0){
		m_listMenu1->DeleteAllItems();
		CtblBeverage<CtblBeverageSelectWhereNameAccessor> selectWhereNameBeverage;
		CtblBeverage<CtblBeverageSelectWherePriceAccessor> selectWherePriceBeverage;
		

		UpdateData(TRUE);
		m_strMenuOption = m_strMenuOption.Trim();
		if(m_iMenuOptionCurSel == 1){
			wcscpy_s((wchar_t*)selectWhereNameBeverage.m_bev_name, 20, (const wchar_t*)m_strMenuOption.GetBuffer(m_strMenuOption.GetLength()));
			selectWhereNameBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strMenuOption.GetBuffer(m_strMenuOption.GetLength()))*2;
			selectWhereNameBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

			if(selectWhereNameBeverage.OpenAll() == S_OK){
				while(selectWhereNameBeverage.MoveNext() == S_OK){
					nCount = m_listMenu1->GetItemCount();
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 0;
					strCount.Format(_T("%d"), selectWhereNameBeverage.m_bev_id);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu1->InsertItem(&lvItem);
				
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 1;
					lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameBeverage.m_bev_name;
					m_listMenu1->SetItem(&lvItem);

					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 2;
					strCount.Format(_T("%d"), selectWhereNameBeverage.m_bev_price);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu1->SetItem(&lvItem);

				}
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}else if(m_iMenuOptionCurSel == 2){
			selectWherePriceBeverage.m_bev_price = _wtol(m_strMenuOption);
			selectWherePriceBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

			if(selectWherePriceBeverage.OpenAll() == S_OK){
				while(selectWherePriceBeverage.MoveNext() == S_OK){
					nCount = m_listMenu1->GetItemCount();
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 0;
					strCount.Format(_T("%d"), selectWherePriceBeverage.m_bev_id);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu1->InsertItem(&lvItem);
				
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 1;
					lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePriceBeverage.m_bev_name;
					m_listMenu1->SetItem(&lvItem);

					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 2;
					strCount.Format(_T("%d"), selectWherePriceBeverage.m_bev_price);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu1->SetItem(&lvItem);

				}
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
		selectWhereNameBeverage.CloseAll();
		selectWherePriceBeverage.CloseAll();
	
	}else if(m_iSelectedMenu == 1){

		m_listMenu2->DeleteAllItems();
		CtblSide<CtblSideSelectWhereNameAccessor> selectWhereNameSide;
		CtblSide<CtblSideSelectWherePriceAccessor> selectWherePriceSide;

		UpdateData(TRUE);
		m_strMenuOption = m_strMenuOption.Trim();
		if(m_iMenuOptionCurSel == 1){
			wcscpy_s((wchar_t*)selectWhereNameSide.m_side_name, 20, (const wchar_t*)m_strMenuOption.GetBuffer(m_strMenuOption.GetLength()));
			selectWhereNameSide.m_dwside_nameLength = wcslen((const wchar_t*)m_strMenuOption.GetBuffer(m_strMenuOption.GetLength()))*2;
			selectWhereNameSide.m_dwside_nameStatus = DBSTATUS_S_OK;

			if(selectWhereNameSide.OpenAll() == S_OK){
				while(selectWhereNameSide.MoveNext() == S_OK){
					nCount = m_listMenu2->GetItemCount();
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 0;
					strCount.Format(_T("%d"), selectWhereNameSide.m_side_id);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu2->InsertItem(&lvItem);
				
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 1;
					lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameSide.m_side_name;
					m_listMenu2->SetItem(&lvItem);

					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 2;
					strCount.Format(_T("%d"), selectWhereNameSide.m_side_price);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu2->SetItem(&lvItem);

				}
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}else if(m_iMenuOptionCurSel == 2){
			selectWherePriceSide.m_side_price = _wtol(m_strMenuOption);
			selectWherePriceSide.m_dwside_priceStatus = DBSTATUS_S_OK;

			if(selectWherePriceSide.OpenAll() == S_OK){
				while(selectWherePriceSide.MoveNext() == S_OK){
					nCount = m_listMenu2->GetItemCount();
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 0;
					strCount.Format(_T("%d"), selectWherePriceSide.m_side_id);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu2->InsertItem(&lvItem);
				
					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 1;
					lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePriceSide.m_side_name;
					m_listMenu2->SetItem(&lvItem);

					lvItem.mask = LVIF_TEXT;
					lvItem.iItem = nCount;
					lvItem.iSubItem = 2;
					strCount.Format(_T("%d"), selectWherePriceSide.m_side_price);
					lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
					m_listMenu2->SetItem(&lvItem);

				}
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
		selectWhereNameSide.CloseAll();
		selectWherePriceSide.CloseAll();
	}
	
	
}


void CMenuSelectDlg::OnRadioBeverage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iSelectedMenu = 0;
	((CButton*)GetDlgItem(IDC_RADIO_SIDE))->SetCheck(FALSE);
}


void CMenuSelectDlg::OnRadioSide()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iSelectedMenu = 1;
	((CButton*)GetDlgItem(IDC_RADIO_BEVERAGE))->SetCheck(FALSE);
}


void CMenuSelectDlg::OnSelchangeComboMenuOption()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_iMenuOptionCurSel = m_cbMenuOption.GetCurSel();
}


void CMenuSelectDlg::OnClickedButtonMenuOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_iMenuOptionCurSel == 0){
		AfxMessageBox(_T("옵션을 선택 해주세요!!"));
	}else{
		OnInitialUpdateList();
	}
}


void CMenuSelectDlg::OnClickedButtonMenuCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
