// CustomerSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "CustomerSelectDlg.h"
#include "afxdialogex.h"
#include "tblCustomer.h"


// CCustomerSelectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCustomerSelectDlg, CDialogEx)

CCustomerSelectDlg::CCustomerSelectDlg(CWnd* pParent /*=NULL*/, CListCtrl* listCtrl)
	: CDialogEx(CCustomerSelectDlg::IDD, pParent)
	, m_strCusOption(_T(""))
	, m_iCusOptionCurSel(0)
{
	m_listCustomer = listCtrl;
}

CCustomerSelectDlg::~CCustomerSelectDlg()
{
}

BOOL CCustomerSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	m_editCusOption.SetLimitText(19);
	m_cbCusOption.SetCurSel(0);

	return TRUE;
}

void CCustomerSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CUSTOMER_OPTION, m_cbCusOption);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_OPTION, m_strCusOption);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_OPTION, m_editCusOption);
}


BEGIN_MESSAGE_MAP(CCustomerSelectDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_CUSTOMER_OPTION, &CCustomerSelectDlg::OnSelchangeComboCustomerOption)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_OK, &CCustomerSelectDlg::OnClickedButtonCustomerOk)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_CANCEL, &CCustomerSelectDlg::OnClickedButtonCustomerCancel)
END_MESSAGE_MAP()


// CCustomerSelectDlg 메시지 처리기입니다.


void CCustomerSelectDlg::OnSelchangeComboCustomerOption()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_iCusOptionCurSel = m_cbCusOption.GetCurSel();
	if(m_iCusOptionCurSel == 1){
		m_editCusOption.SetLimitText(19);
	}else if(m_iCusOptionCurSel == 2){
		m_editCusOption.SetLimitText(11);
	}
}


void CCustomerSelectDlg::OnClickedButtonCustomerOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_iCusOptionCurSel == 0){
		AfxMessageBox(_T("옵션을 선택 해주세요!!"));
	}else{
		OnInitialUpdateList();
	}
	
}


void CCustomerSelectDlg::OnInitialUpdateList()
{
	m_listCustomer->DeleteAllItems();
	CtblCustomer<CtblCustomerSelectWhereNameAccessor> selectWhereNameCustomer;
	CtblCustomer<CtblCustomerSelectWherePhoneAccessor> selectWherePhoneCustomer;
	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	UpdateData(TRUE);
	m_strCusOption = m_strCusOption.Trim();
	if(m_iCusOptionCurSel == 1){
		wcscpy_s((wchar_t*)selectWhereNameCustomer.m_cus_name, 20, (const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()));
		selectWhereNameCustomer.m_dwcus_nameLength = wcslen((const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()))*2;
		selectWhereNameCustomer.m_dwcus_nameStatus = DBSTATUS_S_OK;

		if(selectWhereNameCustomer.OpenAll() == S_OK){
			while(selectWhereNameCustomer.MoveNext() == S_OK){
				nCount = m_listCustomer->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWhereNameCustomer.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameCustomer.m_cus_name;
				m_listCustomer->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameCustomer.m_cus_phone;
				m_listCustomer->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;				
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWhereNameCustomer.m_cus_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}else if(m_iCusOptionCurSel == 2){
		wcscpy_s((wchar_t*)selectWherePhoneCustomer.m_cus_phone, 13, (const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()));
		selectWherePhoneCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()))*2;
		selectWherePhoneCustomer.m_dwcus_phoneStatus = DBSTATUS_S_OK;

		if(selectWherePhoneCustomer.OpenAll() == S_OK){
			while(selectWherePhoneCustomer.MoveNext() == S_OK){
				nCount = m_listCustomer->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWherePhoneCustomer.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePhoneCustomer.m_cus_name;
				m_listCustomer->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePhoneCustomer.m_cus_phone;
				m_listCustomer->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;				
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWherePhoneCustomer.m_cus_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	
	selectWhereNameCustomer.CloseAll();
	selectWherePhoneCustomer.CloseAll();

	
}


void CCustomerSelectDlg::OnClickedButtonCustomerCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
