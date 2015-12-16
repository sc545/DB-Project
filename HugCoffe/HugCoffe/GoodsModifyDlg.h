#pragma once
#include "afxwin.h"


// CGoodsModifyDlg 대화 상자입니다.

class CGoodsModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsModifyDlg)

public:
	CGoodsModifyDlg(CWnd* pParent = NULL, LONG id = NULL, CString name = NULL, LONG num = NULL);   // 표준 생성자입니다.
	virtual ~CGoodsModifyDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_GOODS_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
