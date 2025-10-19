
// MFCPaintView.cpp: CMFCPaintView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCPaint.h"
#endif

#include "MFCPaintDoc.h"
#include "MFCPaintView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCPaintView

IMPLEMENT_DYNCREATE(CMFCPaintView, CView)

BEGIN_MESSAGE_MAP(CMFCPaintView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCPaintView 构造/析构

CMFCPaintView::CMFCPaintView() noexcept
{
	// TODO: 在此处添加构造代码
	m_status = false;
	m_curr = { 0,0 };
	m_start = { 0,0 };
	m_stop = { 0,0 };
}

CMFCPaintView::~CMFCPaintView()
{
}

BOOL CMFCPaintView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCPaintView 绘图

void CMFCPaintView::OnDraw(CDC* pDC)
{
	CMFCPaintDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_SOLID, 100, RGB(0, 255, 0));
	CPen* pen01 = pDC->SelectObject(&pen);
	LOGPEN logpen;
	pen01->GetLogPen(&logpen);
	TRACE("style = %d, color = %08X, width = %d\n", logpen.lopnStyle,logpen.lopnColor,logpen.lopnWidth);
	pen.GetLogPen(&logpen);
	TRACE("style = %d, color = %d, width = %d\n", logpen.lopnStyle, logpen.lopnColor, logpen.lopnWidth);
	if (m_status)
	{
		pDC->MoveTo(m_start);
		pDC->LineTo(m_curr);
	}
	else
	{
		pDC->MoveTo(m_start);
		pDC->LineTo(m_stop);
	}
	pDC->SelectObject(pen01);
	// TODO: 在此处为本机数据添加绘制代码
}

void CMFCPaintView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCPaintView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCPaintView 诊断

#ifdef _DEBUG
void CMFCPaintView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCPaintView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCPaintDoc* CMFCPaintView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCPaintDoc)));
	return (CMFCPaintDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCPaintView 消息处理程序

void CMFCPaintView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_start = point;
	TRACE("m_start: x = %d, y = %d\n", m_start.x, m_start.y);
	m_status = true;
	InvalidateRect(NULL);
	CView::OnLButtonDown(nFlags, point);
}

void CMFCPaintView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_stop = point;
	m_status = false;
	TRACE("m_stop: x = %d, y = %d\n", m_stop.x, m_stop.y);
	CView::OnLButtonUp(nFlags, point);
}	

void CMFCPaintView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_status)
	{
		m_curr = point;
		InvalidateRect(NULL);
	}
	CView::OnMouseMove(nFlags, point);
}
