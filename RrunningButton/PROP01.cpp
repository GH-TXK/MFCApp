// PROP01.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "afxdialogex.h"
#include "PROP01.h"
#include "MyPropertySheet.h"


// PROP_01 对话框

IMPLEMENT_DYNAMIC(PROP_01, CPropertyPage)

PROP_01::PROP_01()
	: CPropertyPage(IDD_PROP_01)
	, m_lang(-1)
	, m_listbox_string(_T(""))
{
	//m_java=FALSE;
}

PROP_01::~PROP_01()
{
}

void PROP_01::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//DDX_Radio(pDX, IDC_RADIO1, m_lang);
	//DDX_Radio(pDX, IDC_RADIO2, m_java);
	//DDX_Control(pDX, IDC_RADIO1, m_lang);
	DDX_Radio(pDX, IDC_RADIO1, m_lang);

	DDX_Control(pDX, IDC_LIST2, m_listbox);
	DDX_LBString(pDX, IDC_LIST2, m_listbox_string);
}


BEGIN_MESSAGE_MAP(PROP_01, CPropertyPage)
END_MESSAGE_MAP()


// PROP_01 消息处理程序

BOOL PROP_01::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	((CListBox *)GetDlgItem(IDC_LIST2))->AddString(_T("简体中文"));
	((CListBox *)GetDlgItem(IDC_LIST2))->AddString(_T("English"));
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

BOOL PROP_01::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CMyPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	((CMyPropertySheet*)GetParent())->GetDlgItem(IDHELP)->ShowWindow(SW_HIDE);
	return CPropertyPage::OnSetActive();
}

LRESULT PROP_01::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类
	UpdateData();
	if(m_lang == -1)
	{
		//AfxMessageBox(_T("请选择语言！"));
		MessageBox(_T("请选择语言1！"), _T("提示"), MB_OK | MB_ICONASTERISK);
		return -1;
	}
	if(m_listbox_string.GetLength() == 0)
	{
		AfxMessageBox(_T("请选择语言2！"));
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}
