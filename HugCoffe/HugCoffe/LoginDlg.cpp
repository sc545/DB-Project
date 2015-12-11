// LoginDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "LoginDlg.h"
#include "afxdialogex.h"
#include "admin.h"


// CLoginDlg 대화 상자입니다.

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


// CLoginDlg 메시지 처리기입니다.


void CLoginDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	Cadmin<CadminSelectAccessor> selectAdmin;
	if(selectAdmin.OpenAll() == S_OK){
		if(selectAdmin.MoveFirst() == S_OK){
			if(selectAdmin.m_id == m_strId){
				if(selectAdmin.m_pass == m_strPass){
					EndDialog(1);
				}else{
					AfxMessageBox(_T("비밀번호가 틀립니다!!"));
				}
			}else{
				AfxMessageBox(_T("존재하지 않는 아이디입니다!!"));
			}
		}else{
			AfxMessageBox(_T("쿼리 결과가 없습니다!!"));
		}
	}else{
		AfxMessageBox(_T("데이터베이스 접속 실패!!"));
	}
	selectAdmin.CloseAll();
}

void CLoginDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("프로그램종료"));
	EndDialog(0);
}
