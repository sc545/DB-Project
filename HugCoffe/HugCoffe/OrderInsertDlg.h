#pragma once


// COrderInsertDlg ��ȭ �����Դϴ�.

class COrderInsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COrderInsertDlg)

public:
	COrderInsertDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COrderInsertDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_ORDER_INSERT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
