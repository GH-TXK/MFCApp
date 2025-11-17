// PROP03.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "afxdialogex.h"
#include "PROP03.h"
#include "MyPropertySheet.h"


// PROP_03 对话框

IMPLEMENT_DYNAMIC(PROP_03, CPropertyPage)

PROP_03::PROP_03()
	: CPropertyPage(IDD_PROP_03)
	, m_combo1(_T(""))
{

}

PROP_03::~PROP_03()
{
}

void PROP_03::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_combo1);
}


BEGIN_MESSAGE_MAP(PROP_03, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO1, &PROP_03::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// PROP_03 消息处理程序

BOOL PROP_03::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CMyPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}

void PROP_03::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}

BOOL PROP_03::OnWizardFinish()
{
	// TODO: 在此添加专用代码和/或调用基类
	UpdateData();
	if(m_combo1.IsEmpty())
	{
		AfxMessageBox(_T("Please select an item from the combo box."));
		return FALSE; // Prevent finishing the wizard
	}
	return CPropertyPage::OnWizardFinish();
}
