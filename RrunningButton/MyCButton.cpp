// MyCButton.cpp: 实现文件
//

#include "pch.h"
#include "RrunningButton.h"
#include "MyCButton.h"


// MyCButton

IMPLEMENT_DYNAMIC(MyCButton, CButton)

MyCButton::MyCButton()
{

}

MyCButton::~MyCButton()
{
}


BEGIN_MESSAGE_MAP(MyCButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// MyCButton 消息处理程序



void MyCButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	ShowWindow(SW_HIDE); // 隐藏按钮
	if (m_CButton != nullptr)
	{
		m_CButton->ShowWindow(SW_SHOW); // 显示另一个按钮
	}
	CButton::OnMouseMove(nFlags, point);
}
