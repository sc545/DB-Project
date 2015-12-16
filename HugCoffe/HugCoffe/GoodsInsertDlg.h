#pragma once
#include "afxwin.h"


// CGoodsInsertDlg 대화 상자입니다.

class CGoodsInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsInsertDlg)

public:
	CGoodsInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGoodsInsertDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_GOODS_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_editGoodsName;
	CString m_strGoodsName;
	CEdit m_editGoodsNum;
	CString m_strGoodsNum;
	afx_msg void OnClickedButtonGoodsOk();
	afx_msg void OnClickedButtonGoodsCancel();
};
