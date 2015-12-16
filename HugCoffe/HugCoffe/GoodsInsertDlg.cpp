// GoodsInsertDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HugCoffe.h"
#include "GoodsInsertDlg.h"
#include "afxdialogex.h"
#include "tblGoods.h"


// CGoodsInsertDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CGoodsInsertDlg, CDialogEx)

CGoodsInsertDlg::CGoodsInsertDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGoodsInsertDlg::IDD, pParent)
	, m_strGoodsName(_T(""))
	, m_strGoodsNum(_T(""))
{

}

CGoodsInsertDlg::~CGoodsInsertDlg()
{
}

BOOL CGoodsInsertDlg::OnInitDialog(){
	CDialog::OnInitDialog();

	// ���̾�α� �ʱ�ȭ �ڵ� �ۼ�
	m_editGoodsName.SetLimitText(19);
	m_editGoodsNum.SetLimitText(11);

	return TRUE;
}

void CGoodsInsertDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_GOODS_NAME, m_editGoodsName);
	DDX_Text(pDX, IDC_EDIT_GOODS_NAME, m_strGoodsName);
	DDX_Control(pDX, IDC_EDIT_GOODS_NUM, m_editGoodsNum);
	DDX_Text(pDX, IDC_EDIT_GOODS_NUM, m_strGoodsNum);
}


BEGIN_MESSAGE_MAP(CGoodsInsertDlg, CDialogEx)
	ON_BN_CLICKED(ID_BUTTON_GOODS_OK, &CGoodsInsertDlg::OnClickedButtonGoodsOk)
	ON_BN_CLICKED(ID_BUTTON_GOODS_CANCEL, &CGoodsInsertDlg::OnClickedButtonGoodsCancel)
END_MESSAGE_MAP()


// CGoodsInsertDlg �޽��� ó�����Դϴ�.


void CGoodsInsertDlg::OnClickedButtonGoodsOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CtblGoods<CtblGoodsInsertAccessor> insertGoods;
	if(m_strGoodsName.GetLength()<1){
		AfxMessageBox(_T("��ǰ���� �Է����ּ���!!"));
	}else if(m_strGoodsNum.GetLength()<1){
		AfxMessageBox(_T("������ �Է����ּ���!!"));
	}else{
		wcscpy_s((wchar_t*)insertGoods.m_goods_name, 20, (const wchar_t*)m_strGoodsName.GetBuffer(m_strGoodsName.GetLength()));
		insertGoods.m_dwgoods_nameLength = wcslen((const wchar_t*)m_strGoodsName.GetBuffer(m_strGoodsName.GetLength()))*2;
		insertGoods.m_dwgoods_nameStatus = DBSTATUS_S_OK;

		insertGoods.m_goods_num = _wtol(m_strGoodsNum);
		insertGoods.m_dwgoods_numStatus = DBSTATUS_S_OK;

		if(insertGoods.OpenAll() == S_OK){
			EndDialog(1);
		}else{
			AfxMessageBox(_T("�����ͺ��̽� ���� ����!!"));
		}
	}
	insertGoods.CloseAll();
}


void CGoodsInsertDlg::OnClickedButtonGoodsCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EndDialog(0);
}
