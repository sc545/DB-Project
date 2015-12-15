// OrderCustomerSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderCustomerSelectDlg.h"
#include "afxdialogex.h"
#include "tblCustomer.h"

// COrderCustomerSelectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COrderCustomerSelectDlg, CDialogEx)

COrderCustomerSelectDlg::COrderCustomerSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderCustomerSelectDlg::IDD, pParent)
	, m_strCusOption(_T(""))
	, m_iCusOptionCurSel(0)
	, m_lCusId(0)
{

}

BOOL COrderCustomerSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성]
	CtblCustomer<CtblCustomerSelectAccessor> selectCustomer;

	LV_COLUMN lvColumn;
	LPWSTR list[6] = {_T("고객번호"), _T("이름"), _T("전화번호"), _T("포인트")};
	int nWidth[4] = {70, 80, 100, 80};

	for(int i=0; i<4; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCustomer.InsertColumn(i, &lvColumn);
	}

	m_listCustomer.SetExtendedStyle(m_listCustomer.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

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

	m_editCusOption.SetLimitText(19);
	m_cbCusOption.SetCurSel(0);
	
	((CButton*)GetDlgItem(ID_BUTTON_CUSTOMER_SELECT_OK))->EnableWindow(FALSE);

	return TRUE;
}

COrderCustomerSelectDlg::~COrderCustomerSelectDlg()
{
}

void COrderCustomerSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CUSTOMER_OPTION, m_cbCusOption);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_OPTION, m_editCusOption);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_OPTION, m_strCusOption);
	DDX_Control(pDX, IDC_LIST_CUSTOMER, m_listCustomer);
}


BEGIN_MESSAGE_MAP(COrderCustomerSelectDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_CUSTOMER_OPTION, &COrderCustomerSelectDlg::OnSelchangeComboCustomerOption)
	ON_COMMAND(ID_BUTTON_CUSTOMER_OK, &COrderCustomerSelectDlg::OnButtonCustomerOk)
	ON_COMMAND(ID_BUTTON_CUSTOMER_CANCEL, &COrderCustomerSelectDlg::OnButtonCustomerCancel)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT, &COrderCustomerSelectDlg::OnClickedButtonCustomerSelect)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT_ALL, &COrderCustomerSelectDlg::OnClickedButtonCustomerSelectAll)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT_OK, &COrderCustomerSelectDlg::OnClickedButtonCustomerSelectOk)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT_CANCEL, &COrderCustomerSelectDlg::OnClickedButtonCustomerSelectCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_CUSTOMER, &COrderCustomerSelectDlg::OnItemchangedListCustomer)
END_MESSAGE_MAP()


// COrderCustomerSelectDlg 메시지 처리기입니다.


void COrderCustomerSelectDlg::OnInitialUpdateList(void)
{
	m_listCustomer.DeleteAllItems();
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
				nCount = m_listCustomer.GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWhereNameCustomer.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer.InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameCustomer.m_cus_name;
				m_listCustomer.SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameCustomer.m_cus_phone;
				m_listCustomer.SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;				
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWhereNameCustomer.m_cus_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer.SetItem(&lvItem);
			}

		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}else if(m_iCusOptionCurSel == 2){
		wcscpy_s((wchar_t*)selectWherePhoneCustomer.m_cus_phone, 13, (const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()));
		selectWherePhoneCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusOption.GetBuffer(m_strCusOption.GetLength()))*2;
		selectWherePhoneCustomer.m_dwcus_phoneStatus = DBSTATUS_S_OK;

		if(selectWherePhoneCustomer.OpenAll() == S_OK){
			while(selectWherePhoneCustomer.MoveNext() == S_OK){
				nCount = m_listCustomer.GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWherePhoneCustomer.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer.InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePhoneCustomer.m_cus_name;
				m_listCustomer.SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWherePhoneCustomer.m_cus_phone;
				m_listCustomer.SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;				
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWherePhoneCustomer.m_cus_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listCustomer.SetItem(&lvItem);
			}
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	
	selectWhereNameCustomer.CloseAll();
	selectWherePhoneCustomer.CloseAll();
}


void COrderCustomerSelectDlg::OnSelchangeComboCustomerOption()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_iCusOptionCurSel = m_cbCusOption.GetCurSel();
	if(m_iCusOptionCurSel == 1){
		m_editCusOption.SetLimitText(19);
	}else if(m_iCusOptionCurSel == 2){
		m_editCusOption.SetLimitText(11);
	}
}


void COrderCustomerSelectDlg::OnButtonCustomerOk()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.


}


void COrderCustomerSelectDlg::OnButtonCustomerCancel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
}


void COrderCustomerSelectDlg::OnClickedButtonCustomerSelect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(m_iCusOptionCurSel == 0){
		AfxMessageBox(_T("옵션을 선택 해주세요!!"));
	}else{
		OnInitialUpdateList();
	}
}


void COrderCustomerSelectDlg::OnClickedButtonCustomerSelectAll()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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


void COrderCustomerSelectDlg::OnClickedButtonCustomerSelectOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(m_lCusId);
}


void COrderCustomerSelectDlg::OnClickedButtonCustomerSelectCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}


void COrderCustomerSelectDlg::OnItemchangedListCustomer(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lCusId = _wtol(m_listCustomer.GetItemText(pNMLV->iItem, 0));
	((CButton*)GetDlgItem(ID_BUTTON_CUSTOMER_SELECT_OK))->EnableWindow(TRUE);
	*pResult = 0;
}
