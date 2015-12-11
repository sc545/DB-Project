#pragma once


// CHugCoffeFormDlg 대화 상자입니다.

class CHugCoffeFormDlg : public CDialog
{
	DECLARE_DYNAMIC(CHugCoffeFormDlg)

public:
	CHugCoffeFormDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CHugCoffeFormDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HUGCOFFE_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
