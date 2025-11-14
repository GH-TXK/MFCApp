// PROP01.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "afxdialogex.h"
#include "PROP01.h"


// PROP_01 对话框

IMPLEMENT_DYNAMIC(PROP_01, CPropertyPage)

PROP_01::PROP_01()
	: CPropertyPage(IDD_PROP_01)
	, m_lang(FALSE)
{

}

PROP_01::~PROP_01()
{
}

void PROP_01::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//DDX_Radio(pDX, IDC_RADIO1, m_lang);
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
