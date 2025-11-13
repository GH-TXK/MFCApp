#pragma once
#include "afxdialogex.h"


// PROP_01 对话框

class PROP_01 : public CPropertyPage
{
	DECLARE_DYNAMIC(PROP_01)

public:
	PROP_01();
	virtual ~PROP_01();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROP_01 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_lang;
	virtual BOOL OnInitDialog();
};
