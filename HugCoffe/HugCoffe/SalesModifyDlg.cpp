// SalesModifyDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "SalesModifyDlg.h"
#include "afxdialogex.h"
#include "tblSales.h"


// CSalesModifyDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CSalesModifyDlg, CDialogEx)

CSalesModifyDlg::CSalesModifyDlg(CWnd* pParent /*=NULL*/, LONG total, LONG num, CString date)   // ǥ�� �������Դϴ�.
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


// CSalesModifyDlg �޽��� ó�����Դϴ�.


void CSalesModifyDlg::OnClickedButtonSalesOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
	CtblSales<CtblSalesUpdateAccessor> updateSales;
	m_editSalesTotal.GetWindowTextW(m_strSalesTotal);
	m_editSalesNum.GetWindowTextW(m_strSalesNum);
	if(m_strSalesTotal.GetLength()>21){
		AfxMessageBox(_T("�ٽ� �Է����ּ���!!"));
	}else if(m_strSalesTotal.GetLength()<1){
		AfxMessageBox(_T("�ٽ� �Է����ּ���!!"));
	}else if(m_strSalesNum.GetLength()>13){
		AfxMessageBox(_T("�ٽ� �Է����ּ���!!"));
	}else if(m_strSalesNum.GetLength()<1){
		AfxMessageBox(_T("�ٽ� �Է����ּ���!!"));
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
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}
	updateSales.CloseAll();
}


void CSalesModifyDlg::OnClickedButtonSalesCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
