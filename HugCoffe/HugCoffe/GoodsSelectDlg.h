#pragma once


// CGoodsSelectDlg ��ȭ �����Դϴ�.

class CGoodsSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CGoodsSelectDlg)

public:
	CGoodsSelectDlg(CWnd* pParent = NULL, CListCtrl* listCtrl = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGoodsSelectDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_GOODS_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonGoodsCancel();
	CListCtrl* m_listGoods;
	void OnInitialUpdateList(void);
	CString m_strGoodsOption;
	afx_msg void OnClickedButtonGoodsOk();
};
