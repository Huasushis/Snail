
// snailDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "snail.h"
#include "snailDlg.h"
#include "afxdialogex.h"
#include "qq.h"
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int Type;
qq slide;
CString window;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CsnailDlg 对话框

BEGIN_DHTML_EVENT_MAP(CsnailDlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()


CsnailDlg::CsnailDlg(CWnd* pParent /*=nullptr*/)
	: CDHtmlDialog(IDD_SNAIL_DIALOG, IDR_HTML_SNAIL_DIALOG, pParent)
	, edit_7(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsnailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, radio_1);
	DDX_Control(pDX, IDC_RADIO2, radio_2);
	DDX_Control(pDX, edit2, edit_2);
	DDX_Control(pDX, edit1, edit_1);
	DDX_Control(pDX, edit3, edit_3);
	DDX_Control(pDX, edit4, edit_4);
	DDX_Control(pDX, edit5, edit_5);
	DDX_Control(pDX, edit6, edit_6);
	DDX_Control(pDX, spin1, spin_1);
	DDX_Text(pDX, edit7, edit_7);
}

BEGIN_MESSAGE_MAP(CsnailDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_BN_CLICKED(IDC_RADIO1, &CsnailDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CsnailDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(btnstart, &CsnailDlg::OnBnClickedbtnstart)
	ON_NOTIFY(UDN_DELTAPOS, spin1, &CsnailDlg::OnDeltaposspin1)
	ON_BN_CLICKED(IDC_BUTTON1, &CsnailDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CsnailDlg 消息处理程序

BOOL CsnailDlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	//ShowWindow(SW_MINIMIZE);

	// TODO: 在此添加额外的初始化代码
	CheckRadioButton(IDC_RADIO1, IDC_RADIO2, IDC_RADIO1);
	Type = 0;
	edit_1.SetWindowText(_T("请输入刷屏内容"));
	edit_2.SetWindowText(_T("1"));
	edit_3.SetWindowText(_T("1"));
	edit_4.SetWindowText(_T("100"));
	edit_5.SetWindowText(_T("1"));
	edit_6.SetWindowText(_T("群聊名称"));
	edit_7 = _T("0");
	
	
	spin_1.SetBuddy(GetDlgItem(edit7));
	spin_1.SetRange(0, 5000);

	ShellExecute(NULL, "open", "check.exe", NULL, NULL, SW_HIDE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CsnailDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CsnailDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CsnailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CsnailDlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CsnailDlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}

void CsnailDlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	Type = 0;
}


void CsnailDlg::OnBnClickedRadio2()
{
	Type = 1;
	// TODO: 在此添加控件通知处理程序代码
}


void CsnailDlg::OnBnClickedbtnstart()
{
	try {
		GetDlgItemText(edit6, window);
		UpdateData(true);
		CString s;
		double op;
		op = wcstod(edit_7.AllocSysString(), NULL);
		if (op > 5000) op = 5000;
		s.Format(_T("%.1f"), op);
		edit_7 = s;
		UpdateData(false);
		slide.init(string(window));
		if (Type==0)
		{
			CString times, word, tmp;
			edit_2.GetWindowText(times);
			if (stoll(string(times)) > 900000)
			{
				times = _T("900000");
				edit_2.SetWindowText(times);
			}
			long long tTimes = stoll(string(times));
			edit_1.GetWindowText(word);
			for (long long i = 0; i < tTimes; i++)
			{
				slide.init(string(window));
				
				UpdateData(true);
				CString s;
				double op;
				op = wcstod(edit_7.AllocSysString(), NULL);
				if (op > 5000) op = 5000;
				s.Format(_T("%.1f"), op);
				edit_7 = s;
				UpdateData(false);

				UpdateData(true);
				slide.send(string(word));
				Sleep(wcstod(edit_7.AllocSysString(), NULL));
				UpdateData(false);
			}
		}
		else
		{
			CString start, end, mult,tmp;
			edit_3.GetWindowText(start);
			edit_4.GetWindowText(end);
			edit_5.GetWindowText(mult);
			if (stoll(string(start)) > 900000)
			{
				start = _T("900000");
				edit_3.SetWindowText(start);
			}
			if (stoll(string(end)) > 900000)
			{
				end = _T("900000");
				edit_4.SetWindowText(end);
			}
			if (stoll(string(mult)) > 900000)
			{
				mult = _T("900000");
				edit_5.SetWindowText(mult);
			}
			long long sstart = stoll(string(start)),
				eend = stoll(string(end)),
				mmult = stoll(string(mult));
			mmult = abs(mmult);
			if (eend < sstart) mmult = -mmult;
			for (long long i = sstart; 
				sstart > eend && i >= eend || sstart < eend && i <= eend;
				i += mmult)
			{
				slide.init(string(window));

				UpdateData(true);
				CString s;
				double op;
				op = wcstod(edit_7.AllocSysString(), NULL);
				if (op > 5000) op = 5000;
				s.Format(_T("%.1f"), op);
				edit_7 = s;
				UpdateData(false);

				UpdateData(true);
				slide.send(to_string(i));
				Sleep(wcstod(edit_7.AllocSysString(), NULL));
				UpdateData(false);
			}
		}

	}
	catch (...)
	{
		MessageBox("Failed", "Notice", MB_OK | MB_ICONERROR);
	}
	// TODO: 在此添加控件通知处理程序代码

}


void CsnailDlg::OnDeltaposspin1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CString s;
	if (pNMUpDown->iDelta == -1)
	{
		double op;
		op = wcstod(edit_7.AllocSysString(), NULL) - 1;
		s.Format(_T("%.1f"), op);
	}
	else if (pNMUpDown->iDelta == 1)
	{
		double op;
		op = wcstod(edit_7.AllocSysString(), NULL) + 1;
		s.Format(_T("%.1f"), op);
	}
	edit_7 = s;
	UpdateData(false);
	*pResult = 0;
}


void CsnailDlg::OnBnClickedButton1()
{
	ShellExecute(NULL, NULL, _T("https://huasushis.github.io/zh-cn/softwares/snail/snail-1-0/video.mp4"), 
		NULL, NULL, SW_SHOWNORMAL);
	MessageBox("Successfully Opened!", "Notice", MB_OK | MB_ICONINFORMATION);
	
	// TODO: 在此添加控件通知处理程序代码
}
