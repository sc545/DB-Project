// OrderInsertDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "OrderInsertDlg.h"
#include "afxdialogex.h"
#include "tblBeverage.h"
#include "tblSide.h"
#include "OrderCustomerSelectDlg.h"
#include "tblCustomer.h"


// COrderInsertDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(COrderInsertDlg, CDialogEx)

COrderInsertDlg::COrderInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COrderInsertDlg::IDD, pParent)
	, m_strCusId(_T(""))
	, m_strPrice(_T(""))
	, m_strPoint(_T(""))
	, m_strTotalPrice(_T(""))
	, m_strSavePoint(_T(""))
	, m_iBeverageCurSel(0)
	, m_iSideCurSel(0)
	, m_strBeverage(_T(""))
	, m_strSize(_T(""))
	, m_strHotIce(_T(""))
	, m_strSide(_T(""))
	, m_nExtraCharge(0)
	, m_iSelectedItem(0)
	, m_lPrice(0)
	, m_lTotalPrice(0)
	, m_lPoint(0)
	, m_iCusId(0)
	, m_lSavePoint(0)
{

}

COrderInsertDlg::~COrderInsertDlg()
{
}
BOOL COrderInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�
	//m_editCusName.SetLimitText(19);
	//m_editCusPhone.SetLimitText(11);

	m_cbBeverage.SetCurSel(0);
	m_cbSize.SetCurSel(0);
	m_cbHotIce.SetCurSel(0);
	m_cbSide.SetCurSel(0);
	m_strBeverage = _T("-");
	m_strSize = _T("-");
	m_strHotIce = _T("-");
	m_strSide = _T("-");

	((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(FALSE);

	CtblBeverage<CtblBeverageSelectAccessor> selectBeverage;
	CtblSide<CtblSideSelectAccessor> selectSide;

	if(selectBeverage.OpenAll() == S_OK){
		while(selectBeverage.MoveNext() == S_OK){
			m_cbBeverage.AddString(selectBeverage.m_bev_name);
		}
	}else{
		AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
	}
	
	if(selectSide.OpenAll() == S_OK){
		while(selectSide.MoveNext() == S_OK){
			m_cbSide.AddString(selectSide.m_side_name);
		}
	}else{
		AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
	}

	LV_COLUMN lvColumn;
	LPWSTR list[5] = {_T("����"), _T("������"), _T("Hot&Ice"), _T("���̵�"), _T("����")};
	int nWidth[5] = {90, 70, 70, 90, 90};

	for(int i=0; i<5; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listOrder.InsertColumn(i, &lvColumn);
	}
	m_listOrder.SetExtendedStyle(m_listOrder.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

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
	ON_BN_CLICKED(ID_BUTTON_ORDER_INSERT, &COrderInsertDlg::OnClickedButtonOrderInsert)
	ON_BN_CLICKED(ID_BUTTON_ORDER_DELETE, &COrderInsertDlg::OnClickedButtonOrderDelete)
	ON_CBN_SELCHANGE(IDC_COMBO_BEVERAGE, &COrderInsertDlg::OnSelchangeComboBeverage)
	ON_CBN_SELCHANGE(IDC_COMBO_SIZE, &COrderInsertDlg::OnSelchangeComboSize)
	ON_CBN_SELCHANGE(IDC_COMBO_HOT_ICE, &COrderInsertDlg::OnSelchangeComboHotIce)
	ON_CBN_SELCHANGE(IDC_COMBO_SIDE, &COrderInsertDlg::OnSelchangeComboSide)
	ON_BN_CLICKED(ID_BUTTON_ORDER_OK, &COrderInsertDlg::OnClickedButtonOrderOk)
	ON_BN_CLICKED(ID_BUTTON_ORDER_CANCEL, &COrderInsertDlg::OnClickedButtonOrderCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnItemchangedListOrderList)
	ON_NOTIFY(LVN_INSERTITEM, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnInsertitemListOrderList)
	ON_NOTIFY(LVN_DELETEITEM, IDC_LIST_ORDER_LIST, &COrderInsertDlg::OnDeleteitemListOrderList)
	ON_BN_CLICKED(ID_BUTTON_CUSTOMER_SELECT, &COrderInsertDlg::OnBnClickedButtonCustomerSelect)
	ON_BN_CLICKED(IDC_CHECK_POINT, &COrderInsertDlg::OnBnClickedCheckPoint)
	ON_EN_CHANGE(IDC_EDIT_POINT, &COrderInsertDlg::OnEnChangeEditPoint)
END_MESSAGE_MAP()


// COrderInsertDlg �޽��� ó�����Դϴ�.


void COrderInsertDlg::OnClickedButtonOrderInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CtblBeverage<CtblBeverageSelectWhereNameAccessor> selectWhereNameBeverage;
	CtblSide<CtblSideSelectWhereNameAccessor> selectWhereNameSide;
	int nCount;
	LV_ITEM lvItem;
	CString str;
	int price = 0;

	nCount = m_listOrder.GetItemCount();
	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;
	lvItem.iSubItem = 0;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strBeverage;
	m_listOrder.InsertItem(&lvItem);
				
	wcscpy_s((wchar_t*)selectWhereNameBeverage.m_bev_name, 20, (const wchar_t*)m_strBeverage.GetBuffer(m_strBeverage.GetLength()));
	selectWhereNameBeverage.m_dwbev_nameLength = wcslen((const wchar_t*)m_strBeverage.GetBuffer(m_strBeverage.GetLength()))*2;
	selectWhereNameBeverage.m_dwbev_nameStatus = DBSTATUS_S_OK;

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;		
	lvItem.iSubItem = 1;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strSize;
	m_listOrder.SetItem(&lvItem);

	lvItem.mask = LVIF_TEXT;
	lvItem.iItem = nCount;
	lvItem.iSubItem = 2;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strHotIce;
	m_listOrder.SetItem(&lvItem);

	lvItem.mask = LVIF_TEXT;				
	lvItem.iItem = nCount;
	lvItem.iSubItem = 3;
	lvItem.pszText = (LPWSTR)(LPCTSTR)m_strSide;
	m_listOrder.SetItem(&lvItem);

	wcscpy_s((wchar_t*)selectWhereNameSide.m_side_name, 20, (const wchar_t*)m_strSide.GetBuffer(m_strSide.GetLength()));
	selectWhereNameSide.m_dwside_nameLength= wcslen((const wchar_t*)m_strSide.GetBuffer(m_strSide.GetLength()))*2;
	selectWhereNameSide.m_dwside_nameStatus = DBSTATUS_S_OK;

	switch (m_cbSize.GetCurSel()){
	case 0:
	case 2:
		break;
	case 1:
		m_nExtraCharge -= 500;
		break;
	case 3:
		m_nExtraCharge += 500;
		break;
	}
	if(m_cbHotIce.GetCurSel() == 2){
		m_nExtraCharge +=500;
	}
	

	if(selectWhereNameBeverage.OpenAll() == S_OK){
		if(selectWhereNameBeverage.MoveNext() == S_OK){
			price = selectWhereNameBeverage.m_bev_price;
			price += m_nExtraCharge;
			str.Format(_T("%d"), price);
		}
	}else{
		AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
	}

	if(selectWhereNameSide.OpenAll() == S_OK){
		if(selectWhereNameSide.MoveNext() == S_OK){
			price += selectWhereNameSide.m_side_price;
			str.Format(_T("%d"), price);
		}
	}else{
		AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
	}

	lvItem.mask = LVIF_TEXT;				
	lvItem.iItem = nCount;
	lvItem.iSubItem = 4;
	str.Format(_T("%d"), price);
	lvItem.pszText = (LPWSTR)(LPCTSTR)str;
	m_listOrder.SetItem(&lvItem);

	m_lPrice += price;
	str.Format(_T("%ld"), m_lPrice);
	m_strPrice = str;
	m_lTotalPrice = m_lPrice - m_lPoint;
	str.Format(_T("%ld"), m_lTotalPrice);
	m_strTotalPrice = str;
	m_lSavePoint = m_lTotalPrice*(0.1L);
	str.Format(_T("%ld"), m_lSavePoint);
	m_strSavePoint = str;
	UpdateData(FALSE);

	m_nExtraCharge = 0;
	
}


void COrderInsertDlg::OnClickedButtonOrderDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_listOrder.DeleteItem(m_iSelectedItem);
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(FALSE);

}


void COrderInsertDlg::OnSelchangeComboBeverage()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_cbBeverage.GetCurSel() == 0 && m_cbSide.GetCurSel() == 0){
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
		m_strBeverage = _T("-");
		m_strSize = _T("-");
		m_strHotIce = _T("-");
		m_cbSize.EnableWindow(FALSE);
		m_cbHotIce.EnableWindow(FALSE);
	}else{
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(TRUE);
		if(m_cbBeverage.GetCurSel() == 0){
			m_strBeverage = _T("-");
			m_strSize = _T("-");
			m_strHotIce = _T("-");
			m_cbSize.EnableWindow(FALSE);
			m_cbHotIce.EnableWindow(FALSE);
		}else{
			m_cbBeverage.GetLBText(m_cbBeverage.GetCurSel(), m_strBeverage);
			m_strSize = _T("�̵��");
			m_strHotIce = _T("Hot");
			m_cbSize.EnableWindow(TRUE);
			m_cbHotIce.EnableWindow(TRUE);
		}
	
	}
}


void COrderInsertDlg::OnSelchangeComboSize()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_cbSize.GetCurSel() == 1){
		m_strSize = _T("����");
	}else if(m_cbSize.GetCurSel() == 2){
		m_strSize = _T("�̵��");
	}else if(m_cbSize.GetCurSel() == 3){
		m_strSize = _T("����");
	}else{
		m_strSize = _T("�̵��");
	}
}


void COrderInsertDlg::OnSelchangeComboHotIce()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_cbHotIce.GetCurSel() == 1){
		m_strHotIce = _T("Hot");
	}else if(m_cbHotIce.GetCurSel() == 2){
		m_strHotIce = _T("Ice");
	}else{
		m_strHotIce = _T("Hot");
	}
}


void COrderInsertDlg::OnSelchangeComboSide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_cbBeverage.GetCurSel() == 0 && m_cbSide.GetCurSel() == 0){
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(FALSE);
		m_strSide = _T("-");
	}else{
		((CButton*)GetDlgItem(ID_BUTTON_ORDER_INSERT))->EnableWindow(TRUE);
		if(m_cbSide.GetCurSel() == 0){
			m_strSide = _T("-");
		}else{
			m_cbSide.GetLBText(m_cbSide.GetCurSel(), m_strSide);
		}
	}
}


void COrderInsertDlg::OnClickedButtonOrderOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.


}


void COrderInsertDlg::OnClickedButtonOrderCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}


void COrderInsertDlg::OnItemchangedListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_iSelectedItem = pNMLV->iItem;
	((CButton*)GetDlgItem(ID_BUTTON_ORDER_DELETE))->EnableWindow(TRUE);
	*pResult = 0;
}


void COrderInsertDlg::OnInsertitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	*pResult = 0;
}


void COrderInsertDlg::OnDeleteitemListOrderList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	//@TN
		*pResult = 0;
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_lPrice -= _wtol(m_listOrder.GetItemText(pNMLV->iItem, 4));
	CString str;
	str.Format(_T("%ld"), m_lPrice);
	m_strPrice = str;
	m_lTotalPrice = m_lPrice - m_lPoint;
	str.Format(_T("%ld"), m_lTotalPrice);
	m_strTotalPrice = str;
	m_lSavePoint = m_lTotalPrice*(0.1L);
	str.Format(_T("%ld"), m_lSavePoint);
	m_strSavePoint = str;
	UpdateData(FALSE);
	*pResult = 0;
}


void COrderInsertDlg::OnBnClickedButtonCustomerSelect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	COrderCustomerSelectDlg COrderCustomerSelectDlg;
	CString str;
	m_iCusId = COrderCustomerSelectDlg.DoModal();
	UpdateData();
	if(m_iCusId != 0){
		str.Format(_T("%d"), m_iCusId); 
		m_strCusId = str;
		
		CtblCustomer<CtblCustomerSelectWhereIdAccessor> selectWhereIdCustomer;
		selectWhereIdCustomer.m_cus_id = m_iCusId;
		selectWhereIdCustomer.m_dwcus_idStatus = DBSTATUS_S_OK;
		if(selectWhereIdCustomer.OpenAll() == S_OK){
			if(selectWhereIdCustomer.MoveNext() == S_OK){
				m_lPoint = selectWhereIdCustomer.m_cus_point;
				str.Format(_T("%ld"), m_lPoint);
				m_strPoint = str;
		}
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
		m_checkPoint.SetCheck(FALSE);
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		((CButton*)GetDlgItem(IDC_EDIT_POINT))->EnableWindow(TRUE);
	}else{
		m_strCusId = " ";
		m_checkPoint.SetCheck(FALSE);
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		((CButton*)GetDlgItem(IDC_EDIT_POINT))->EnableWindow(FALSE);
	}
	UpdateData(FALSE);
	
}


void COrderInsertDlg::OnBnClickedCheckPoint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	if(m_checkPoint.GetCheck()){
		UpdateData();
		m_lPoint = _wtol(m_strPoint);
		m_lTotalPrice = m_lPrice - m_lPoint;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}else{
		UpdateData();
		m_lTotalPrice = m_lPrice;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}
}


void COrderInsertDlg::OnEnChangeEditPoint()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

//#1015

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if(m_checkPoint.GetCheck()){
		CString str;

		UpdateData();
		m_lPoint = _wtol(m_strPoint);
		m_lTotalPrice = m_lPrice - m_lPoint;
		str.Format(_T("%ld"), m_lTotalPrice);
		m_strTotalPrice = str;
		m_lSavePoint = m_lTotalPrice*(0.1L);
		str.Format(_T("%ld"), m_lSavePoint);
		m_strSavePoint = str;
		UpdateData(FALSE);
	}

}
