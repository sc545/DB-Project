// SalesModifyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "SalesModifyDlg.h"
#include "afxdialogex.h"
#include "tblSales.h"


// CSalesModifyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSalesModifyDlg, CDialogEx)

CSalesModifyDlg::CSalesModifyDlg(CWnd* pParent /*=NULL*/, LONG total, LONG num, CString date)   // 표준 생성자입니다.
	: CDialogEx(CSalesModifyDlg::IDD, pParent)
	, m_strSalesDate(date)
{
	CString str;
	str.Format(_T("%ld"), total);
	m_strSalesTotal = str;
	str.Format(_T("%ld"), num);
	m_strSalesNum = str;
}

CSalesModifyDlg::~CSalesModifyDlg()
{
}

BOOL CSalesModifyDlg::OnInitDialog(){
	CDialog::OnInitDialog();
	
	m_editSalesTotal.SetWindowTextW(m_strSalesTotal);
	m_editSalesNum.SetWindowTextW(m_strSalesNum);
	

	return TRUE;
}
void CSalesModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SALES_NUM, m_editSalesNum);
	DDX_Text(pDX, IDC_EDIT_SALES_NUM, m_strSalesNum);
	DDX_Control(pDX, IDC_EDIT_SALES_TOTAL, m_editSalesTotal);
	DDX_Text(pDX, IDC_EDIT_SALES_TOTAL, m_strSalesTotal);
}


BEGIN_MESSAGE_MAP(CSalesModifyDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_SALES_OK, &CSalesModifyDlg::OnClickedButtonSalesOk)
	ON_BN_CLICKED(ID_BUTTON_SALES_CANCEL, &CSalesModifyDlg::OnClickedButtonSalesCancel)
END_MESSAGE_MAP()


// CSalesModifyDlg 메시지 처리기입니다.


void CSalesModifyDlg::OnClickedButtonSalesOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	CtblSales<CtblSalesUpdateAccessor> updateSales;
	m_editSalesTotal.GetWindowTextW(m_strSalesTotal);
	m_editSalesNum.GetWindowTextW(m_strSalesNum);
	if(m_strSalesTotal.GetLength()>21){
		AfxMessageBox(_T("다시 입력해주세요!!"));
	}else if(m_strSalesTotal.GetLength()<1){
		AfxMessageBox(_T("다시 입력해주세요!!"));
	}else if(m_strSalesNum.GetLength()>13){
		AfxMessageBox(_T("다시 입력해주세요!!"));
	}else if(m_strSalesNum.GetLength()<1){
		AfxMessageBox(_T("다시 입력해주세요!!"));
	}else{
		wcscpy_s((wchar_t*)updateSales.m_sales_date, 11, (const wchar_t*)m_strSalesDate.GetBuffer(m_strSalesDate.GetLength()));
		updateSales.m_dwsales_dateLength = wcslen((const wchar_t*)m_strSalesDate.GetBuffer(m_strSalesDate.GetLength()))*2;
		updateSales.m_dwsales_dateStatus = DBSTATUS_S_OK;

		updateSales.m_sales_total = _wtol(m_strSalesTotal);
		updateSales.m_dwsales_totalStatus = DBSTATUS_S_OK;

		updateSales.m_sales_num = _wtol(m_strSalesNum);
		updateSales.m_dwsales_numStatus = DBSTATUS_S_OK;

		if(updateSales.OpenAll() == S_OK){
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	updateSales.CloseAll();
}


void CSalesModifyDlg::OnClickedButtonSalesCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
