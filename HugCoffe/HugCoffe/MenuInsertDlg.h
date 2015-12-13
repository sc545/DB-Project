#pragma once


// CMenuInsertDlg 대화 상자입니다.

class CMenuInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuInsertDlg)

public:
	CMenuInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMenuInsertDlg();
	virtual BOOL OnInitDialog();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_MENU_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
