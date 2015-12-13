// MenuModifyDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "MenuModifyDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// CMenuModifyDlg ��ȭ �����Դϴ�.

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

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�

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


// CMenuModifyDlg �޽��� ó�����Դϴ�.


void CMenuModifyDlg::OnClickedButtonMenuOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CtblBeverage<CtblBeverageUpdateAccessor> updateBeverage;
	CtblSide<CtblSideUpdateAccessor> updateSide;
	m_editMenuName.GetWindowTextW(m_strMenuName);
	CString str;
	m_editMenuPrice.GetWindowTextW(str);
	m_lMenuPrice = _wtol(str);

	if(m_iSelectedMenu == 0){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("�޴��̸��� �Է����ּ���!!"));
		}else if(str.GetLength()<1){
			AfxMessageBox(_T("�޴������� �Է����ּ���!!"));
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
				AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
			}
		}
	}
	if(m_iSelectedMenu == 1){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("�޴��̸��� �Է����ּ���!!"));
		}else if(str.GetLength()<1){
			AfxMessageBox(_T("�޴������� �Է����ּ���!!"));
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
				AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
			}
		}
	}
	updateBeverage.CloseAll();
	updateSide.CloseAll();
}


void CMenuModifyDlg::OnClickedButtonMenuCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
