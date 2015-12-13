// OrderInsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderInsertDlg.h"
#include "afxdialogex.h"


// COrderInsertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COrderInsertDlg, CDialogEx)

COrderInsertDlg::COrderInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderInsertDlg::IDD, pParent)
{

}

COrderInsertDlg::~COrderInsertDlg()
{
}

void COrderInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COrderInsertDlg, CDialogEx)
END_MESSAGE_MAP()


// COrderInsertDlg 메시지 처리기입니다.
