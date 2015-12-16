// GoodsModifyDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "GoodsModifyDlg.h"
#include "afxdialogex.h"
#include "tblGoods.h"


// CGoodsModifyDlg ��ȭ �����Դϴ�.

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

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�
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


// CGoodsModifyDlg �޽��� ó�����Դϴ�.


void CGoodsModifyDlg::OnClickedButtonGoodsOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
	CtblGoods<CtblGoodsUpdateAccessor> updateGoods;
	/*m_editGoodsName.GetWindowTextW(m_strGoodsName);
	m_editGoodsNum.GetWindowTextW(m_lGoodsNum);*/
	if(m_strGoodsName.GetLength()<1){
		AfxMessageBox(_T("��ǰ���� �Է����ּ���!!"));
	}else if(m_lGoodsNum < 1){
		AfxMessageBox(_T("������ �Է����ּ���!!"));
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
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}
	updateGoods.CloseAll();
}


void CGoodsModifyDlg::OnClickedButtonGoodsCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
