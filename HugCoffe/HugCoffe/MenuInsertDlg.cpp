// MenuInsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "MenuInsertDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// CMenuInsertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMenuInsertDlg, CDialogEx)

CMenuInsertDlg::CMenuInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMenuInsertDlg::IDD, pParent)
	, m_iSelectedMenu(0)
	, m_strMenuName(_T(""))
	, m_strMenuPrice(_T(""))
{

}

CMenuInsertDlg::~CMenuInsertDlg()
{
}

BOOL CMenuInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	
	((CButton*)GetDlgItem(IDC_RADIO_BEVERAGE))->SetCheck(TRUE);

	return TRUE;
}

void CMenuInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MENU_NAME, m_strMenuName);
	DDX_Text(pDX, IDC_EDIT_MENU_PRICE, m_strMenuPrice);
}


BEGIN_MESSAGE_MAP(CMenuInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_MENU_OK, &CMenuInsertDlg::OnClickedButtonMenuOk)
	ON_COMMAND(IDC_RADIO_BEVERAGE, &CMenuInsertDlg::OnRadioBeverage)
	ON_COMMAND(IDC_RADIO_SIDE, &CMenuInsertDlg::OnRadioSide)
	ON_BN_CLICKED(ID_BUTTON_MENU_CANCEL, &CMenuInsertDlg::OnClickedButtonMenuCancel)
END_MESSAGE_MAP()


// CMenuInsertDlg 메시지 처리기입니다.


void CMenuInsertDlg::OnClickedButtonMenuOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CtblBeverage<CtblBeverageInsertAccessor> insertBeverage;
	CtblSide<CtblSideInsertAccessor> insertSide;

	if(m_iSelectedMenu == 0){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("메뉴이름을 입력해주세요!!"));
		}else if(m_strMenuPrice.GetLength()<1){
			AfxMessageBox(_T("메뉴가격을 입력해주세요!!"));
		}else{
			wcscpy_s((wchar_t*)insertBeverage.m_bev_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			insertBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			insertBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

			insertBeverage.m_bev_price = _wtol(m_strMenuPrice);
			insertBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

			if(insertBeverage.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
	}
	if(m_iSelectedMenu == 1){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("메뉴이름을 입력해주세요!!"));
		}else if(m_strMenuPrice.GetLength()<1){
			AfxMessageBox(_T("메뉴가격을 입력해주세요!!"));
		}else{
			wcscpy_s((wchar_t*)insertSide.m_side_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			insertSide.m_dwside_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			insertSide.m_dwside_nameStatus = DBSTATUS_S_OK;

			insertSide.m_side_price = _wtol(m_strMenuPrice);
			insertSide.m_dwside_priceStatus = DBSTATUS_S_OK;

			if(insertSide.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
	}
	insertBeverage.CloseAll();

}


void CMenuInsertDlg::OnRadioBeverage()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iSelectedMenu = 0;
	((CButton*)GetDlgItem(IDC_RADIO_SIDE))->SetCheck(FALSE);
}


void CMenuInsertDlg::OnRadioSide()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_iSelectedMenu = 1;
	((CButton*)GetDlgItem(IDC_RADIO_BEVERAGE))->SetCheck(FALSE);
}


void CMenuInsertDlg::OnClickedButtonMenuCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
