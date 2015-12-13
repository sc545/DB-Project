// MenuInsertDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "MenuInsertDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// CMenuInsertDlg ��ȭ �����Դϴ�.

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

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�
	
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


// CMenuInsertDlg �޽��� ó�����Դϴ�.


void CMenuInsertDlg::OnClickedButtonMenuOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CtblBeverage<CtblBeverageInsertAccessor> insertBeverage;
	CtblSide<CtblSideInsertAccessor> insertSide;

	if(m_iSelectedMenu == 0){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("�޴��̸��� �Է����ּ���!!"));
		}else if(m_strMenuPrice.GetLength()<1){
			AfxMessageBox(_T("�޴������� �Է����ּ���!!"));
		}else{
			wcscpy_s((wchar_t*)insertBeverage.m_bev_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			insertBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			insertBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

			insertBeverage.m_bev_price = _wtol(m_strMenuPrice);
			insertBeverage.m_dwbev_priceStatus = DBSTATUS_S_OK;

			if(insertBeverage.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
			}
		}
	}
	if(m_iSelectedMenu == 1){
		if(m_strMenuName.GetLength()<1){
			AfxMessageBox(_T("�޴��̸��� �Է����ּ���!!"));
		}else if(m_strMenuPrice.GetLength()<1){
			AfxMessageBox(_T("�޴������� �Է����ּ���!!"));
		}else{
			wcscpy_s((wchar_t*)insertSide.m_side_name, 20, (const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()));
			insertSide.m_dwside_nameLength = wcslen((const wchar_t*)m_strMenuName.GetBuffer(m_strMenuName.GetLength()))*2;
			insertSide.m_dwside_nameStatus = DBSTATUS_S_OK;

			insertSide.m_side_price = _wtol(m_strMenuPrice);
			insertSide.m_dwside_priceStatus = DBSTATUS_S_OK;

			if(insertSide.OpenAll() == S_OK){
				EndDialog(1);
			}else{
				AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
			}
		}
	}
	insertBeverage.CloseAll();

}


void CMenuInsertDlg::OnRadioBeverage()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_iSelectedMenu = 0;
	((CButton*)GetDlgItem(IDC_RADIO_SIDE))->SetCheck(FALSE);
}


void CMenuInsertDlg::OnRadioSide()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_iSelectedMenu = 1;
	((CButton*)GetDlgItem(IDC_RADIO_BEVERAGE))->SetCheck(FALSE);
}


void CMenuInsertDlg::OnClickedButtonMenuCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
