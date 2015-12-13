// MenuModifyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "MenuModifyDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// CMenuModifyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMenuModifyDlg, CDialogEx)

CMenuModifyDlg::CMenuModifyDlg(CWnd* pParent /*=NULL*/, CString name, LONG price, LONG id, int selectedMenu)
	: CDialogEx(CMenuModifyDlg::IDD, pParent)
	, m_strMenuName(name)
	, m_lMenuPrice(price)
	, m_lMenuId(id)
	, m_iSelectedMenu(selectedMenu)
{

}

CMenuModifyDlg::~CMenuModifyDlg()
{
}

BOOL CMenuModifyDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성

	m_editMenuName.SetWindowTextW(m_strMenuName.Trim());
	CString str;
	str.Format(_T("%ld"), m_lMenuPrice);
	m_editMenuPrice.SetWindowTextW(str);

	return TRUE;
}

void CMenuModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_MENU_NAME, m_editMenuName);
	DDX_Control(pDX, IDC_EDIT_MENU_PRICE, m_editMenuPrice);
}


BEGIN_MESSAGE_MAP(CMenuModifyDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_MENU_OK, &CMenuModifyDlg::OnClickedButtonMenuOk)
	ON_BN_CLICKED(ID_BUTTON_MENU_CANCEL, &CMenuModifyDlg::OnClickedButtonMenuCancel)
END_MESSAGE_MAP()


// CMenuModifyDlg 메시지 처리기입니다.


void CMenuModifyDlg::OnClickedButtonMenuOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CtblBeverage<CtblBeverageUpdateAccessor> updateBeverage;
	CtblSide<CtblSideUpdateAccessor> updateSide;
	m_editMenuName.GetWindowTextW(m_strMenuName);
	CString str;
	m_editMenuPrice.GetWindowTextW(str);
	m_lMenuPrice = _wtol(str);

	if(m_iSelectedMenu == 0){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("메뉴이름을 입력해주세요!!"));
		}else if(str.GetLength()<1){
			AfxMessageBox(_T("메뉴가격을 입력해주세요!!"));
		}else{
			wcscpy_s((wchar_t*)updateBeverage.m_bev_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			updateBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			updateBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

			updateBeverage.m_bev_price = m_lMenuPrice;
			updateBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

			updateBeverage.m_bev_id = m_lMenuId;
			updateBeverage.m_dwbev_idStatus = DBSTATUS_S_OK;

			if(updateBeverage.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
	}
	if(m_iSelectedMenu == 1){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("메뉴이름을 입력해주세요!!"));
		}else if(str.GetLength()<1){
			AfxMessageBox(_T("메뉴가격을 입력해주세요!!"));
		}else{
			wcscpy_s((wchar_t*)updateSide.m_side_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			updateSide.m_dwside_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			updateSide.m_dwside_nameStatus = DBSTATUS_S_OK;

			updateSide.m_side_price = m_lMenuPrice;
			updateSide.m_dwside_priceStatus = DBSTATUS_S_OK;

			updateSide.m_side_id = m_lMenuId;
			updateSide.m_dwside_idStatus = DBSTATUS_S_OK;

			if(updateSide.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("데이터베이스 접속 실패!!"));
			}
		}
	}
	updateBeverage.CloseAll();
	updateSide.CloseAll();
}


void CMenuModifyDlg::OnClickedButtonMenuCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
