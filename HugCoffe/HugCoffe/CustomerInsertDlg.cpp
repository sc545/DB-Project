// CustomerInsertDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "CustomerInsertDlg.h"
#include "afxdialogex.h"
#include "tblCustomer.h"


// CCustomerInsertDlg ��ȭ �����Դϴ�.

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

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�

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


// CCustomerInsertDlg �޽��� ó�����Դϴ�.


void CCustomerInsertDlg::OnClickedButtonCustomerOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CtblCustomer<CtblCustomerInsertAccessor> insertCustomer;
	if(m_strCusName.GetLength()>21){
		AfxMessageBox(_T("�̸��� �ʹ� ��ϴ�!!"));
	}else if(m_strCusName.GetLength()<1){
		AfxMessageBox(_T("�̸��� �Է����ּ���!!"));
	}else if(m_strCusPhone.GetLength()>13){
		AfxMessageBox(_T("�ڵ�����ȣ�� �ٽ� �Է����ּ���!!"));
	}else if(m_strCusPhone.GetLength()<1){
		AfxMessageBox(_T("�ڵ�����ȣ�� �Է����ּ���!!"));
	}else{
		wcscpy_s((wchar_t*)insertCustomer.m_cus_name, 20, (const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()));
		insertCustomer.m_dwcus_nameLength = wcslen((const wchar_t*)m_strCusName.GetBuffer(m_strCusName.GetLength()))*2;
		insertCustomer.m_dwcus_nameStatus = DBSTATUS_S_OK;

		wcscpy_s((wchar_t*)insertCustomer.m_cus_phone, 13, (const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()));
		insertCustomer.m_dwcus_phoneLength = wcslen((const wchar_t*)m_strCusPhone.GetBuffer(m_strCusPhone.GetLength()))*2;
		insertCustomer.m_dwcus_phoneStatus = DBSTATUS_S_OK;

		if(insertCustomer.OpenAll() == S_OK){
			AfxMessageBox(_T("�Է� �Ϸ�!!"));
			EndDialog(1);
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}
	insertCustomer.CloseAll();
	

}


void CCustomerInsertDlg::OnClickedButtonCustomerCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
