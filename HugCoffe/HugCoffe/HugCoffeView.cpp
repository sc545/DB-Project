
// HugCoffeView.cpp : CHugCoffeView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "HugCoffe.h"
#endif

#include "HugCoffeDoc.h"
#include "HugCoffeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHugCoffeView

IMPLEMENT_DYNCREATE(CHugCoffeView, CFormView)

BEGIN_MESSAGE_MAP(CHugCoffeView, CFormView)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SELECTION, &CHugCoffeView::OnTcnSelchangeTab3)
END_MESSAGE_MAP()

// CHugCoffeView ����/�Ҹ�

CHugCoffeView::CHugCoffeView()
	: CFormView(CHugCoffeView::IDD)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CHugCoffeView::~CHugCoffeView()
{
}

void CHugCoffeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SELECTION, m_tabSelection);
	DDX_Control(pDX, IDC_LIST, m_listCtrl);
}

BOOL CHugCoffeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CHugCoffeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	TC_ITEM tabItem;
	LPWSTR tabName[5] = {_T("������"),_T("�޴�����"),_T("�ֹ�����"),_T("��ǰ����"),_T("�������")};
	
	for(int i=0; i<5; i++){
		tabItem.mask =TCIF_TEXT;
		tabItem.pszText = tabName[i];
		m_tabSelection.InsertItem(i,&tabItem);

	}

	LV_COLUMN lvColumn;
	LPWSTR list[4] = {_T("����ȣ"), _T("�̸�"), _T("��ȭ��ȣ"), _T("����Ʈ")};
	int nWidth[4] = {100, 100, 150, 100};

	for(int i=0; i<4; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCtrl.InsertColumn(i, &lvColumn);
	}

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	
}


// CHugCoffeView ����

#ifdef _DEBUG
void CHugCoffeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CHugCoffeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CHugCoffeDoc* CHugCoffeView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHugCoffeDoc)));
	return (CHugCoffeDoc*)m_pDocument;
}
#endif //_DEBUG


// CHugCoffeView �޽��� ó����


void CHugCoffeView::OnTcnSelchangeTab3(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
	
	

	int nSelection = m_tabSelection.GetCurSel();
	LV_COLUMN lvColumn;
	LPWSTR list[6];
	int lastColumn = 0;
	int nWidth[6];
	switch (nSelection){
	case 0:
		//GetDlgItem(IDC_BUTTON_CUS
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("�����"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("������"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("������"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("���˻�"));
		list[0] = _T("����ȣ");list[1] = _T("�̸�");list[2] = _T("��ȭ��ȣ");list[3] = _T("����Ʈ");
		lastColumn=4;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;
		break;
	case 1:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("�޴����"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("�޴�����"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("�޴�����"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("�޴��˻�"));
		list[0] = _T("�޴���ȣ");list[1] = _T("�̸�");list[2] = _T("����");list[3] = _T("������");list[4] = _T("Hot & Ice");
		lastColumn=5;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;nWidth[4] = 100;
		break;
	case 2:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("�ֹ����"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("�ֹ�����"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("�ֹ�����"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("�ֹ��˻�"));
		list[0] = _T("�ֹ���ȣ");list[1] = _T("����");list[2] = _T("���̵�");list[3] = _T("�ֹ���¥");list[4] = _T("���ֹ���");list[5] = _T("����ȣ");
		lastColumn=6;
		nWidth[0] = 100;nWidth[1] = 100;nWidth[2] = 150;nWidth[3] = 100;nWidth[4] = 100;nWidth[5] = 100;
		break;
	case 3:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("��ǰ���"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("��ǰ����"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("��ǰ����"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("��ǰ�˻�"));
		list[0] = _T("��ǰ��ȣ");list[1] = _T("����");
		lastColumn=2;
		nWidth[0] = 100;nWidth[1] = 100;
		break;
	case 4:
		GetDlgItem(IDC_BUTTON_INSERT)->SetWindowText(_T("������"));
		GetDlgItem(IDC_BUTTON_MODIFY)->SetWindowText(_T("�������"));
		GetDlgItem(IDC_BUTTON_DELETE)->SetWindowText(_T("�������"));
		GetDlgItem(IDC_BUTTON_SELECT)->SetWindowText(_T("����˻�"));
		list[0] = _T("��¥");list[1] = _T("�Ѹ����");
		lastColumn=2;
		nWidth[0] = 100;nWidth[1] = 100;
		break;
	}
	
	
	

	for(int i=0; i<lastColumn; i++){
		lvColumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		lvColumn.fmt = LVCFMT_CENTER;
		lvColumn.pszText = list[i];
		lvColumn.iSubItem = i;
		lvColumn.cx = nWidth[i];
		m_listCtrl.DeleteColumn(i);
		m_listCtrl.InsertColumn(i, &lvColumn);
		if(i == lastColumn-1)
			for(int j=lastColumn; j<6; j++)
				m_listCtrl.DeleteColumn(j);
	}
	

	m_listCtrl.SetExtendedStyle(m_listCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
}
