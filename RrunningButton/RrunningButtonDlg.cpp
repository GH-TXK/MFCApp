
// RrunningButtonDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "RrunningButton.h"
#include "RrunningButtonDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyPropertySheet.h"


// CRrunningButtonDlg 对话框



CRrunningButtonDlg::CRrunningButtonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RRUNNINGBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRrunningButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Button_left);
	DDX_Control(pDX, IDC_BUTTON2, m_Button_right);
}

BEGIN_MESSAGE_MAP(CRrunningButtonDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CRrunningButtonDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRrunningButtonDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CRrunningButtonDlg 消息处理程序

BOOL CRrunningButtonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	TRACE("Dialog initialized.\n");

	// TODO: 在此添加额外的初始化代码

	m_Button_left.m_CButton = &m_Button_right;
	m_Button_right.m_CButton = &m_Button_left;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRrunningButtonDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRrunningButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CRrunningButtonDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE("You clicked the exit button!\n");
	
}

void CRrunningButtonDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//PROP_01* page01 = new PROP_01;
	//page01->Create(IDD_PROP_01, this);
	//page01->ShowWindow(SW_SHOW);
	CMyPropertySheet propSheet(_T("Settings"), this);
	propSheet.SetWizardMode();
	if (ID_WIZFINISH == propSheet.DoModal())
	{
		TRACE("Wizard finished successfully.\n");
		CString msg = _T("收集结果：\n");
		msg += _T("语言选择：");
		switch (propSheet.prop1.m_lang)
		{
		default:-1;
			break;
		case 0:
			msg += _T("简体中文\n");
			break;
		case 1:
			msg += _T("English\n");
			break;
		case 2:
			msg += _T("日本語\n");
			break;
		}
		msg += propSheet.prop1.m_listbox_string + _T("\n");
		msg += _T("选项：\n");
		msg += propSheet.prop3.m_combo1 + _T("\n");
		MessageBox(msg, _T("结果"), MB_OK | MB_ICONINFORMATION);
	};


}
