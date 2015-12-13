#pragma once


// COrderInsertDlg 대화 상자입니다.

class COrderInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderInsertDlg)

public:
	COrderInsertDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COrderInsertDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG_ORDER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
