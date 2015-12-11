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

void CCustomerInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_INSERT_NAME, m_strCusName);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_INSERT_PHONE, m_strCusPhone);
}


BEGIN_MESSAGE_MAP(CCustomerInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_INSERT, &CCustomerInsertDlg::OnClickedButtonCustomerInsert)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_INSERT_CANCEL, &CCustomerInsertDlg::OnClickedButtonCustomerInsertCancel)
END_MESSAGE_MAP()


// CCustomerInsertDlg 메시지 처리기입니다.


void CCustomerInsertDlg::OnClickedButtonCustomerInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CtblCustomer<CtblCustomerInsertAccessor> insertCustomer;
	if(m_strCusName.GetLength()>3){
		AfxMessageBox(_T("3을 초과했습니다!!"));
	}else if(m_strCusName.GetLength()<1){
		AfxMessageBox(_T("이름을 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()>13){
		AfxMessageBox(_T("핸드폰번호를 다시 입력해주세요!!"));
	}else if(m_strCusPhone.GetLength()<1){
		AfxMessageBox(_T("핸드폰번호를 입력해주세요!!"));
	}else{
		wcscpy_s((wchar_t*)insertCustomer.m_cus_name, sizeof((const wchar_t*)m_strCusName), (const wchar_t*)m_strCusName);
		insertCustomer.m_dwcus_nameLength = wcslen((const wchar_t*)m_strCusName)*2;
		insertCustomer.m_dwcus_nameStatus = DBSTATUS_S_OK;

		wcscpy_s((wchar_t*)insertCustomer.m_cus_phone, sizeof((const wchar_t*)m_strCusPhone), (const wchar_t*)m_strCusPhone);
		insertCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusPhone)*2;
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


void CCustomerInsertDlg::OnClickedButtonCustomerInsertCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(1);
}
