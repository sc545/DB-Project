// CustomerModifyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "CustomerModifyDlg.h"
#include "afxdialogex.h"
#include "tblCustomer.h"


// CCustomerModifyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCustomerModifyDlg, CDialogEx)

CCustomerModifyDlg::CCustomerModifyDlg(CWnd* pParent /*=NULL*/, CString name, CString phone, LONG id)
	: CDialogEx(CCustomerModifyDlg::IDD, pParent)
	, m_strCusName(name)
	, m_strCusPhone(phone)
	, m_lCusId(id)
{
	
}

CCustomerModifyDlg::~CCustomerModifyDlg()
{
}

BOOL CCustomerModifyDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성

	m_editCusName.SetWindowTextW(m_strCusName.Trim());
	m_editCusPhone.SetWindowTextW(m_strCusPhone.Trim());
	m_editCusPhone.SetLimitText(11);

	return TRUE;
}

void CCustomerModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_NAME, m_editCusName);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_PHONE, m_editCusPhone);

	
}


BEGIN_MESSAGE_MAP(CCustomerModifyDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_OK, &CCustomerModifyDlg::OnClickedButtonCustomerOk)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_CANCEL, &CCustomerModifyDlg::OnClickedButtonCustomerCancel)
END_MESSAGE_MAP()


// CCustomerModifyDlg 메시지 처리기입니다.


void CCustomerModifyDlg::OnClickedButtonCustomerOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	CtblCustomer<CtblCustomerUpdateAccessor> updateCustomer;
	m_editCusName.GetWindowTextW(m_strCusName);
	m_editCusPhone.GetWindowTextW(m_strCusPhone);
	if(m_strCusName.GetLength()>21){
		AfxMessageBox(_T("이름이 너무 깁니다!!"));
	}else if(m_strCusName.GetLength()<1){
		AfxMessageBox(_T("이름을 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()>13){
		AfxMessageBox(_T("핸드폰번호를 다시 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()<1){
		AfxMessageBox(_T("핸드폰번호를 입력해주세요!!"));
	}else{
		wcscpy_s((wchar_t*)updateCustomer.m_cus_name, 20, (const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()));
		updateCustomer.m_dwcus_nameLength = wcslen((const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()))*2;
		updateCustomer.m_dwcus_nameStatus = DBSTATUS_S_OK;

		wcscpy_s((wchar_t*)updateCustomer.m_cus_phone, 13, (const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()));
		updateCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()))*2;
		updateCustomer.m_dwcus_phoneStatus = DBSTATUS_S_OK;

		updateCustomer.m_cus_id = m_lCusId;
		updateCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;

		if(updateCustomer.OpenAll() == S_OK){
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	updateCustomer.CloseAll();

}


void CCustomerModifyDlg::OnClickedButtonCustomerCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
