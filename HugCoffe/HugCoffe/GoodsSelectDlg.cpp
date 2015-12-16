// GoodsSelectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "GoodsSelectDlg.h"
#include "afxdialogex.h"
#include "tblGoods.h"


// CGoodsSelectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGoodsSelectDlg, CDialogEx)

CGoodsSelectDlg::CGoodsSelectDlg(CWnd* pParent /*=NULL*/, CListCtrl* listCtrl)
	: CDialogEx(CGoodsSelectDlg::IDD, pParent)
	, m_listGoods(listCtrl)
	, m_strGoodsOption(_T(""))
{

}

CGoodsSelectDlg::~CGoodsSelectDlg()
{
}

BOOL CGoodsSelectDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�

	return TRUE;
}

void CGoodsSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_GOODS_OPTION, m_strGoodsOption);
}


BEGIN_MESSAGE_MAP(CGoodsSelectDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_GOODS_CANCEL, &CGoodsSelectDlg::OnClickedButtonGoodsCancel)
	ON_BN_CLICKED(ID_BUTTON_GOODS_OK, &CGoodsSelectDlg::OnClickedButtonGoodsOk)
END_MESSAGE_MAP()


// CGoodsSelectDlg �޽��� ó�����Դϴ�.



void CGoodsSelectDlg::OnClickedButtonGoodsCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}


void CGoodsSelectDlg::OnInitialUpdateList(void)
{
	m_listGoods->DeleteAllItems();
	CtblGoods<CtblGoodsSelectWhereNameAccessor> selectWhereNameGoods;
	int nCount;
	LV_ITEM lvItem;
	CString strCount;

	UpdateData(TRUE);
	m_strGoodsOption = m_strGoodsOption.Trim();
	wcscpy_s((wchar_t*)selectWhereNameGoods.m_goods_name, 20, (const wchar_t*)m_strGoodsOption.GetBuffer(m_strGoodsOption.GetLength()));
		selectWhereNameGoods.m_dwgoods_nameLength = wcslen((const wchar_t*)m_strGoodsOption.GetBuffer(m_strGoodsOption.GetLength()))*2;
		selectWhereNameGoods.m_dwgoods_nameStatus = DBSTATUS_S_OK;

		if(selectWhereNameGoods.OpenAll() == S_OK){
			while(selectWhereNameGoods.MoveNext() == S_OK){
				nCount = m_listGoods->GetItemCount();
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 0;
				strCount.Format(_T("%d"), selectWhereNameGoods.m_goods_id);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listGoods->InsertItem(&lvItem);
				
				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 1;
				lvItem.pszText = (LPWSTR)(LPCTSTR)selectWhereNameGoods.m_goods_name;
				m_listGoods->SetItem(&lvItem);

				lvItem.mask = LVIF_TEXT;
				lvItem.iItem = nCount;
				lvItem.iSubItem = 2;
				strCount.Format(_T("%d"), selectWhereNameGoods.m_goods_num);
				lvItem.pszText = (LPWSTR)(LPCTSTR)strCount;
				m_listGoods->SetItem(&lvItem);
			}
			EndDialog(1);
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	
	selectWhereNameGoods.CloseAll();
	
}


void CGoodsSelectDlg::OnClickedButtonGoodsOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnInitialUpdateList();
}
