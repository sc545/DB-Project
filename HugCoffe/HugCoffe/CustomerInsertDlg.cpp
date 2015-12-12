// CustomerInsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "CustomerInsertDlg.h"
#include "afxdialogex.h"
#include "tblCustomer.h"


// CCustomerInsertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CCustomerInsertDlg, CDialogEx)

CCustomerInsertDlg::CCustomerInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCustomerInsertDlg::IDD, pParent)
	, m_strCusName(_T(""))
	, m_strCusPhone(_T(""))
{

}

CCustomerInsertDlg::~CCustomerInsertDlg()
{
}

BOOL CCustomerInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성

	m_editCusPhone.SetLimitText(11);

	return TRUE;
}

void CCustomerInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_NAME, m_strCusName);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_PHONE, m_strCusPhone);
	DDX_Control(pDX, IDC_EDIT_CUSTOMER_PHONE, m_editCusPhone);
}


BEGIN_MESSAGE_MAP(CCustomerInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_OK, &CCustomerInsertDlg::OnClickedButtonCustomerOk)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_CANCEL, &CCustomerInsertDlg::OnClickedButtonCustomerCancel)
END_MESSAGE_MAP()


// CCustomerInsertDlg 메시지 처리기입니다.


void CCustomerInsertDlg::OnClickedButtonCustomerOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CtblCustomer<CtblCustomerInsertAccessor> insertCustomer;
	if(m_strCusName.GetLength()>21){
		AfxMessageBox(_T("이름이 너무 깁니다!!"));
	}else if(m_strCusName.GetLength()<1){
		AfxMessageBox(_T("이름을 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()>13){
		AfxMessageBox(_T("핸드폰번호를 다시 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()<1){
		AfxMessageBox(_T("핸드폰번호를 입력해주세요!!"));
	}else{
		wcscpy_s((wchar_t*)insertCustomer.m_cus_name, 20, (const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()));
		insertCustomer.m_dwcus_nameLength = wcslen((const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()))*2;
		insertCustomer.m_dwcus_nameStatus = DBSTATUS_S_OK;

		wcscpy_s((wchar_t*)insertCustomer.m_cus_phone, 13, (const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()));
		insertCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()))*2;
		insertCustomer.m_dwcus_phoneStatus = DBSTATUS_S_OK;

		if(insertCustomer.OpenAll() == S_OK){
			AfxMessageBox(_T("입력 완료!!"));
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	insertCustomer.CloseAll();
	

}


void CCustomerInsertDlg::OnClickedButtonCustomerCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
