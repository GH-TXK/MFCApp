#pragma once
#include "PROP01.h"
#include "PROPP02.h"
#include "PROP03.h"



// CMyPropertySheet

class CMyPropertySheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CMyPropertySheet)

public:
	CMyPropertySheet(UINT nIDCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	CMyPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd = nullptr, UINT iSelectPage = 0);
	virtual ~CMyPropertySheet();

public:
	PROP_01 prop1;
	PROPP_02 prop2;
	PROP_03 prop3;
protected:
	DECLARE_MESSAGE_MAP()
};


