// GoodsModifyDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "GoodsModifyDlg.h"
#include "afxdialogex.h"
#include "tblGoods.h"


// CGoodsModifyDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CGoodsModifyDlg, CDialogEx)

CGoodsModifyDlg::CGoodsModifyDlg(CWnd* pParent /*=NULL*/, LONG id, CString name, LONG num)
	: CDialogEx(CGoodsModifyDlg::IDD, pParent)
	, m_strGoodsName(name)
	, m_lGoodsNum(num)
	, m_lGoodsId(id)
{

}

CGoodsModifyDlg::~CGoodsModifyDlg()
{
}

BOOL CGoodsModifyDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// 다이얼로그 초기화 코드 작성
	m_editGoodsName.SetWindowTextW(m_strGoodsName.Trim());
	CString str;
	str.Format(_T("%ld"), m_lGoodsNum);
	m_editGoodsNum.SetWindowTextW(str);
	m_editGoodsName.SetLimitText(19);
	m_editGoodsNum.SetLimitText(11);

	return TRUE;
}

void CGoodsModifyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GOODS_NAME, m_editGoodsName);
	DDX_Text(pDX, IDC_EDIT_GOODS_NAME, m_strGoodsName);
	DDX_Control(pDX, IDC_EDIT_GOODS_NUM, m_editGoodsNum);
	DDX_Text(pDX, IDC_EDIT_GOODS_NUM, m_lGoodsNum);
}


BEGIN_MESSAGE_MAP(CGoodsModifyDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_GOODS_OK, &CGoodsModifyDlg::OnClickedButtonGoodsOk)
	ON_BN_CLICKED(ID_BUTTON_GOODS_CANCEL, &CGoodsModifyDlg::OnClickedButtonGoodsCancel)
END_MESSAGE_MAP()


// CGoodsModifyDlg 메시지 처리기입니다.


void CGoodsModifyDlg::OnClickedButtonGoodsOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	CtblGoods<CtblGoodsUpdateAccessor> updateGoods;
	/*m_editGoodsName.GetWindowTextW(m_strGoodsName);
	m_editGoodsNum.GetWindowTextW(m_lGoodsNum);*/
	if(m_strGoodsName.GetLength()<1){
		AfxMessageBox(_T("물품명을 입력해주세요!!"));
	}else if(m_lGoodsNum < 1){
		AfxMessageBox(_T("수량을 입력해주세요!!"));
	}else{
		wcscpy_s((wchar_t*)updateGoods.m_goods_name, 20, (const wchar_t*)m_strGoodsName.GetBuffer(m_strGoodsName.GetLength()));
		updateGoods.m_dwgoods_nameLength = wcslen((const wchar_t*)m_strGoodsName.GetBuffer(m_strGoodsName.GetLength()))*2;
		updateGoods.m_dwgoods_nameStatus = DBSTATUS_S_OK;

		updateGoods.m_goods_num = m_lGoodsNum;
		updateGoods.m_dwgoods_numStatus = DBSTATUS_S_OK;

		updateGoods.m_goods_id = m_lGoodsId;
		updateGoods.m_dwgoods_idStatus = DBSTATUS_S_OK;

		if(updateGoods.OpenAll() == S_OK){
			EndDialog(1);
		}else{
			AfxMessageBox(_T("데이터베이스 접속 실패!!"));
		}
	}
	updateGoods.CloseAll();
}


void CGoodsModifyDlg::OnClickedButtonGoodsCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(0);
}
