#pragma once
#include "afxwin.h"


// CGoodsModifyDlg ��ȭ �����Դϴ�.

class CGoodsModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsModifyDlg)

public:
	CGoodsModifyDlg(CWnd* pParent = NULL, LONG id = NULL, CString name = NULL, LONG num = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGoodsModifyDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_GOODS_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editGoodsName;
//	CString m_strGoodsName;
	CString m_strGoodsName;
	CEdit m_editGoodsNum;
	LONG m_lGoodsNum;
	LONG m_lGoodsId;
	afx_msg void OnClickedButtonGoodsOk();
	afx_msg void OnClickedButtonGoodsCancel();
};
