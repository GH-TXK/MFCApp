
// RrunningButtonDlg.h: 头文件
//
#include "MyCButton.h"
#pragma once


// CRrunningButtonDlg 对话框
class CRrunningButtonDlg : public CDialogEx
{
// 构造
public:

	CRrunningButtonDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RRUNNINGBUTTON_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	MyCButton m_Button_left;
	MyCButton m_Button_right;
};
