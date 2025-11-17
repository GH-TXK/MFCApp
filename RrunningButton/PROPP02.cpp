// PROPP02.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "afxdialogex.h"
#include "PROPP02.h"
#include "MyPropertySheet.h"


// PROPP_02 对话框

IMPLEMENT_DYNAMIC(PROPP_02, CPropertyPage)

PROPP_02::PROPP_02()
	: CPropertyPage(IDD_PROPP_02)
{
	memset(m_check, 0, sizeof(m_check));
}

PROPP_02::~PROPP_02()
{
}

void PROPP_02::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_check[0]);
	DDX_Check(pDX, IDC_CHECK2, m_check[1]);
	DDX_Check(pDX, IDC_CHECK3, m_check[2]);
	DDX_Check(pDX, IDC_CHECK4, m_check[3]);
}


BEGIN_MESSAGE_MAP(PROPP_02, CPropertyPage)
END_MESSAGE_MAP()


// PROPP_02 消息处理程序

BOOL PROPP_02::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CMyPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

LRESULT PROPP_02::OnWizardNext()
{
	// TODO: 在此添加专用代码和/或调用基类
	UpdateData();
	BOOL at_least_one_checked = FALSE;
	for (int i = 0; i < 4; ++i)
	{
		if (m_check[i])
		{
			at_least_one_checked = TRUE;
			break;
		}
	}
	if(!at_least_one_checked)
	{
		AfxMessageBox(_T("Please select at least one option to proceed."));
		return -1; // Prevent moving to the next page
	}
	return CPropertyPage::OnWizardNext();
}
