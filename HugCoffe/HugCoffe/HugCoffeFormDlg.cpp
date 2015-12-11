// HugCoffeFormDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "HugCoffeFormDlg.h"
#include "afxdialogex.h"


// CHugCoffeFormDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CHugCoffeFormDlg, CDialog)

CHugCoffeFormDlg::CHugCoffeFormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHugCoffeFormDlg::IDD, pParent)
{

}

CHugCoffeFormDlg::~CHugCoffeFormDlg()
{
}

void CHugCoffeFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CHugCoffeFormDlg, CDialog)
END_MESSAGE_MAP()


// CHugCoffeFormDlg 메시지 처리기입니다.
