// SalesSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "SalesSelectDlg.h"
#include "afxdialogex.h"
#include "tblSales.h"


// CSalesSelectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSalesSelectDlg, CDialogEx)

CSalesSelectDlg::CSalesSelectDlg(CWnd* pParent /*=NULL*/, CListCtrl* list)
	: CDialogEx(CSalesSelectDlg::IDD, pParent)
	, m_strSalesOption(_T(""))
	, m_listSales(list)
{

}

CSalesSelectDlg::~CSalesSelectDlg()
{
}
BOOL CSalesSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성

	return TRUE;
}
void CSalesSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_SALES_OPTION, m_editSalesOption);
	DDX_Text(pDX, IDC_EDIT_SALES_OPTION, m_strSalesOption);
}


BEGIN_MESSAGE_MAP(CSalesSelectDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_SALES_OK, &CSalesSelectDlg::OnClickedButtonSalesOk)
	ON_BN_CLICKED(ID_BUTTON_SALES_CANCEL, &CSalesSelectDlg::OnClickedButtonSalesCancel)
END_MESSAGE_MAP()


// CSalesSelectDlg 메시지 처리기입니다.


void CSalesSelectDlg::OnClickedButtonSalesOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_listSales->DeleteAllItems();
	CtblSales<CtblSalesSelectWhereDateAccessor> selectWhereDateSales;
	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	UpdateData(TRUE);
	m_strSalesOption = m_strSalesOption.Trim();
	wcscpy_s((wchar_t*)selectWhereDateSales.m_sales_date, 20, (const wchar_t*)m_strSalesOption.GetBuffer(m_strSalesOption.GetLength()));
		selectWhereDateSales.m_dwsales_dateLength = wcslen((const wchar_t*)m_strSalesOption.GetBuffer(m_strSalesOption.GetLength()))*2;
		selectWhereDateSales.m_dwsales_dateStatus = DBSTATUS_S_OK;

		if(selectWhereDateSales.OpenAll() == S_OK){
			while(selectWhereDateSales.MoveNext() == S_OK){
				nCount = m_listSales->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereDateSales.m_sales_date;
				m_listSales->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				strCount.Format(_T("%d"), selectWhereDateSales.m_sales_total);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listSales->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				strCount.Format(_T("%d"), selectWhereDateSales.m_sales_num);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listSales->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	
	selectWhereDateSales.CloseAll();
}


void CSalesSelectDlg::OnClickedButtonSalesCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
