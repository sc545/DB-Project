// LoginDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "admin.h"


// CLoginDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
	, m_strId(_T(""))
	, m_strPass(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_strId);
	DDX_Text(pDX, IDC_EDIT_PASS, m_strPass);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginDlg �޽��� ó�����Դϴ�.


void CLoginDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	Cadmin<CadminSelectAccessor> selectAdmin;
	if(selectAdmin.OpenAll() == S_OK){
		if(selectAdmin.MoveFirst() == S_OK){
			if(selectAdmin.m_id == m_strId){
				if(selectAdmin.m_pass == m_strPass){
					EndDialog(1);
				}else{
					AfxMessageBox(_T("��й�ȣ�� Ʋ���ϴ�!!"));
				}
			}else{
				AfxMessageBox(_T("�������� �ʴ� ���̵��Դϴ�!!"));
			}
		}else{
			AfxMessageBox(_T("���� ����� �����ϴ�!!"));
		}
	}else{
		AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
	}
	selectAdmin.CloseAll();
}

void CLoginDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("���α׷�����"));
	EndDialog(0);
}
