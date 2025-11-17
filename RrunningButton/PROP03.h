#pragma once
#include "afxdialogex.h"


// PROP_03 对话框

class PROP_03 : public CPropertyPage
{
	DECLARE_DYNAMIC(PROP_03)

public:
	PROP_03();   // 标准构造函数
	virtual ~PROP_03();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROP_03 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
