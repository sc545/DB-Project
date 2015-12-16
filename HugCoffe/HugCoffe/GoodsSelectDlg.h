#pragma once


// CGoodsSelectDlg 대화 상자입니다.

class CGoodsSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsSelectDlg)

public:
	CGoodsSelectDlg(CWnd* pParent = NULL, CListCtrl* listCtrl = NULL);   // 표준 생성자입니다.
	virtual ~CGoodsSelectDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_GOODS_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonGoodsCancel();
	CListCtrl* m_listGoods;
	void OnInitialUpdateList(void);
	CString m_strGoodsOption;
	afx_msg void OnClickedButtonGoodsOk();
};
