#pragma once


// CMenuInsertDlg ��ȭ �����Դϴ�.

class CMenuInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuInsertDlg)

public:
	CMenuInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMenuInsertDlg();
	virtual BOOL OnInitDialog();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_MENU_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButtonMenuOk();
	afx_msg void OnRadioBeverage();
	afx_msg void OnRadioSide();
	int m_iSelectedMenu;
	CString m_strMenuName;
	CString m_strMenuPrice;
	afx_msg void OnClickedButtonMenuCancel();
};
