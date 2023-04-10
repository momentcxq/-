 // mouseView.cpp : implementation of the CMouseView class
//

#include "stdafx.h"
#include "mouse.h"

#include "mouseDoc.h"
#include "mouseView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMouseView

IMPLEMENT_DYNCREATE(CMouseView, CView)

BEGIN_MESSAGE_MAP(CMouseView, CView)
	//{{AFX_MSG_MAP(CMouseView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMouseView construction/destruction

CMouseView::CMouseView()
{
	// TODO: add construction code here

}

CMouseView::~CMouseView()
{
}

BOOL CMouseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMouseView drawing

void CMouseView::OnDraw(CDC* pDC)
{
	CMouseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMouseView diagnostics

#ifdef _DEBUG
void CMouseView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseDoc* CMouseView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseDoc)));
	return (CMouseDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMouseView message handlers

void CMouseView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 20, "WM_MOUSEMOVE");
	wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	dc.TextOut(200, 20, str);

	CView::OnMouseMove(nFlags, point);
}

void CMouseView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 40, "WM_LBUTTONDOWN");
	wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	dc.TextOut(200, 40, str);

	CView::OnLButtonDown(nFlags, point);
}

void CMouseView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//char str[50];
	CClientDC dc(this);
	//dc.TextOut(20, 60, "WM_LBUTTONUP");
	//wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	//dc.TextOut(200, 60, str);
	dc.TextOut(point.x, point.y, "ÄãºÃ");

	CView::OnLButtonUp(nFlags, point);
}

void CMouseView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	SetCapture();

	//char str[50];
	CClientDC dc(this);
	//dc.TextOut(20, 100, "WM_RBUTTONDOWN");
	//wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	//dc.TextOut(200, 100, str);
	dc.TextOut(point.x, point.y, "ÔÙ");

	CView::OnRButtonDown(nFlags, point);
}

void CMouseView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	ReleaseCapture();

	//char str[50];
	CClientDC dc(this);
	//dc.TextOut(20, 120, "WM_RBUTTONUP");
	//wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	//dc.TextOut(200, 120, str);
	dc.TextOut(point.x, point.y, "¼û");
	
	CView::OnRButtonUp(nFlags, point);
}

void CMouseView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 160, "WM_LBUTTONDBLCLK");
	wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	dc.TextOut(200, 160, str);

	CView::OnLButtonDblClk(nFlags, point);
}

void CMouseView::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	char str[50];
	CClientDC dc(this);
	dc.TextOut(20, 180, "WM_RBUTTONDBLCLK");
	wsprintf(str, "X: %d    Y: %d   ", point.x, point.y);
	dc.TextOut(200, 180, str);

	CView::OnRButtonDblClk(nFlags, point);
}
