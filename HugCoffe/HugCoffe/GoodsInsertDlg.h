#pragma once
#include "afxwin.h"


// CGoodsInsertDlg ��ȭ �����Դϴ�.

class CGoodsInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsInsertDlg)

public:
	CGoodsInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGoodsInsertDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_GOODS_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editGoodsName;
	CString m_strGoodsName;
	CEdit m_editGoodsNum;
	CString m_strGoodsNum;
	afx_msg void OnClickedButtonGoodsOk();
	afx_msg void OnClickedButtonGoodsCancel();
};
