// OrderInsertDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderInsertDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"


// COrderInsertDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(COrderInsertDlg, CDialogEx)

COrderInsertDlg::COrderInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderInsertDlg::IDD, pParent)
	, m_strCusId(_T(""))
	, m_strPrice(_T(""))
	, m_strPoint(_T(""))
	, m_strTotalPrice(_T(""))
	, m_strSavePoint(_T(""))
{

}

COrderInsertDlg::~COrderInsertDlg()
{
}
BOOL COrderInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	//m_editCusName.SetLimitText(19);
	//m_editCusPhone.SetLimitText(11);

	CtblBeverage<CtblBeverageSelectAccessor> selectBeverage;

	if(selectBeverage.OpenAll() == S_OK){
		while(selectBeverage.MoveNext()){

		}
	}else{

	}
	

	return TRUE;
}
void COrderInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_BEVERAGE, m_cbBeverage);
	DDX_Control(pDX, IDC_COMBO_SIZE, m_cbSize);
	DDX_Control(pDX, IDC_COMBO_HOT_ICE, m_cbHotIce);
	DDX_Control(pDX, IDC_COMBO_SIDE, m_cbSide);
	DDX_Text(pDX, IDC_EDIT_CUSTOMER_ID, m_strCusId);
	DDX_Control(pDX, IDC_LIST_ORDER_LIST, m_listOrder);
	DDX_Text(pDX, IDC_EDIT_PRICE, m_strPrice);
	DDX_Control(pDX, IDC_CHECK_POINT, m_checkPoint);
	DDX_Text(pDX, IDC_EDIT_POINT, m_strPoint);
	DDX_Text(pDX, IDC_EDIT_TOTAL_PRICE, m_strTotalPrice);
	DDX_Text(pDX, IDC_EDIT_SAVE_POINT, m_strSavePoint);
}


BEGIN_MESSAGE_MAP(COrderInsertDlg, CDialogEx)
END_MESSAGE_MAP()


// COrderInsertDlg 메시지 처리기입니다.
