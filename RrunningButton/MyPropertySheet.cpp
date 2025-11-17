// MyPropertySheet.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "MyPropertySheet.h"


// CMyPropertySheet

IMPLEMENT_DYNAMIC(CMyPropertySheet, CPropertySheet)

CMyPropertySheet::CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&prop1);
	AddPage(&prop2);
	AddPage(&prop3);
}

CMyPropertySheet::CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&prop1);
	AddPage(&prop2);
	AddPage(&prop3);
}

CMyPropertySheet::~CMyPropertySheet()
{
}


BEGIN_MESSAGE_MAP(CMyPropertySheet, CPropertySheet)
END_MESSAGE_MAP()


// CMyPropertySheet 消息处理程序
