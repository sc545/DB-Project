// GoodsSelectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "GoodsSelectDlg.h"
#include "afxdialogex.h"
#include "tblGoods.h"


// CGoodsSelectDlg 대화 상자입니다.

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

	// 다이얼로그 초기화 코드 작성

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


// CGoodsSelectDlg 메시지 처리기입니다.



void CGoodsSelectDlg::OnClickedButtonGoodsCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	
	selectWhereNameGoods.CloseAll();
	
}


void CGoodsSelectDlg::OnClickedButtonGoodsOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnInitialUpdateList();
}
