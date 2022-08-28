
// snailDlg.h: 头文件
//

#pragma once


// CsnailDlg 对话框
class CsnailDlg : public CDHtmlDialog
{
// 构造
public:
	CsnailDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SNAIL_DIALOG, IDH = IDR_HTML_SNAIL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	HRESULT OnButtonOK(IHTMLElement *pElement);
	HRESULT OnButtonCancel(IHTMLElement *pElement);

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	CButton radio_1;
	CButton radio_2;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedbtnstart();
	CEdit edit_2;
	CEdit edit_1;
	CEdit edit_3;
	CEdit edit_4;
	CEdit edit_5;
	CEdit edit_6;
	CSpinButtonCtrl spin_1;
	CString edit_7;
	afx_msg void OnDeltaposspin1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
};
