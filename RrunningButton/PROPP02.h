#pragma once
#include "afxdialogex.h"


// PROPP_02 对话框

class PROPP_02 : public CPropertyPage
{
	DECLARE_DYNAMIC(PROPP_02)

public:
	PROPP_02();
	virtual ~PROPP_02();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROPP_02 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
