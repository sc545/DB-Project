// OrderSelectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderSelectDlg.h"
#include "afxdialogex.h"
#include "tblOrder.h"


// COrderSelectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(COrderSelectDlg, CDialogEx)

COrderSelectDlg::COrderSelectDlg(CWnd* pParent /*=NULL*/, CListCtrl* list)
	: CDialogEx(COrderSelectDlg::IDD, pParent)
	, m_listOrder(list)
	, m_strOrderOption(_T(""))
	, m_iOrderOptionCurSel(0)
{

}

COrderSelectDlg::~COrderSelectDlg()
{
}

BOOL COrderSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();


	m_cbOrderOption.SetCurSel(0);

	return TRUE;
}
void COrderSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_ORDER_OPTION, m_cbOrderOption);
	DDX_Text(pDX, IDC_EDIT_ORDER_OPTION, m_strOrderOption);
}


BEGIN_MESSAGE_MAP(COrderSelectDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_ORDER_OPTION, &COrderSelectDlg::OnSelchangeComboOrderOption)
	ON_BN_CLICKED(ID_BUTTON_ORDER_OK, &COrderSelectDlg::OnClickedButtonOrderOk)
	ON_BN_CLICKED(ID_BUTTON_ORDER_CANCEL, &COrderSelectDlg::OnClickedButtonOrderCancel)
END_MESSAGE_MAP()


// COrderSelectDlg �޽��� ó�����Դϴ�.


void COrderSelectDlg::OnSelchangeComboOrderOption()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_iOrderOptionCurSel = m_cbOrderOption.GetCurSel();
}


void COrderSelectDlg::OnClickedButtonOrderOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_iOrderOptionCurSel == 0){
		AfxMessageBox(_T("�ɼ��� ���� ���ּ���!!"));
	}else{
		OnInitialUpdateList();
	}
	
}


void COrderSelectDlg::OnClickedButtonOrderCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}


void COrderSelectDlg::OnInitialUpdateList(void)
{
	m_listOrder->DeleteAllItems();
	CtblOrder<CtblOrderSelectWhereIdAccessor> selectWhereOrderIdOrder;
	CtblOrder<CtblOrderSelectWhereCusIdAccessor> selectWhereCusIdOrder;

	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	UpdateData(TRUE);
	m_strOrderOption = m_strOrderOption.Trim();
	if(m_iOrderOptionCurSel == 1){
		selectWhereOrderIdOrder.m_order_id = _wtol(m_strOrderOption);
		selectWhereOrderIdOrder.m_dworder_idStatus = DBSTATUS_S_OK;

		if(selectWhereOrderIdOrder.OpenAll() == S_OK){
			while(selectWhereOrderIdOrder.MoveNext() == S_OK){
				nCount = m_listOrder->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWhereOrderIdOrder.m_order_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				strCount.Format(_T("%d"), selectWhereOrderIdOrder.m_order_used_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				strCount.Format(_T("%d"), selectWhereOrderIdOrder.m_order_price);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWhereOrderIdOrder.m_order_save_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 4;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereOrderIdOrder.m_order_date;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 5;
				strCount.Format(_T("%d"), selectWhereOrderIdOrder.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}else if(m_iOrderOptionCurSel == 2){
		selectWhereCusIdOrder.m_cus_id = _wtol(m_strOrderOption);
		selectWhereCusIdOrder.m_dwcus_idStatus = DBSTATUS_S_OK;

		if(selectWhereCusIdOrder.OpenAll() == S_OK){
			while(selectWhereCusIdOrder.MoveNext() == S_OK){
				nCount = m_listOrder->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWhereCusIdOrder.m_order_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				strCount.Format(_T("%d"), selectWhereCusIdOrder.m_order_used_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				strCount.Format(_T("%d"), selectWhereCusIdOrder.m_order_price);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 3;
				strCount.Format(_T("%d"), selectWhereCusIdOrder.m_order_save_point);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 4;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereCusIdOrder.m_order_date;
				m_listOrder->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 5;
				strCount.Format(_T("%d"), selectWhereCusIdOrder.m_cus_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listOrder->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}
	
	selectWhereOrderIdOrder.CloseAll();
	selectWhereCusIdOrder.CloseAll();
}
