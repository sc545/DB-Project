#pragma once


// CHugCoffeFormDlg ��ȭ �����Դϴ�.

class CHugCoffeFormDlg : public CDialog
{
	DECLARE_DYNAMIC(CHugCoffeFormDlg)

public:
	CHugCoffeFormDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CHugCoffeFormDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_HUGCOFFE_FORM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
