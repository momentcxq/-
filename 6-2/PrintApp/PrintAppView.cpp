// PrintAppView.cpp : implementation of the CPrintAppView class
//

#include "stdafx.h"
#include "PrintApp.h"

#include "PrintAppDoc.h"
#include "PrintAppView.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView

IMPLEMENT_DYNCREATE(CPrintAppView, CView)

BEGIN_MESSAGE_MAP(CPrintAppView, CView)
	//{{AFX_MSG_MAP(CPrintAppView)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView construction/destruction

CPrintAppView::CPrintAppView()
{
	// TODO: add construction code here

	m_numLines = 25;
}

CPrintAppView::~CPrintAppView()
{
}

BOOL CPrintAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView drawing

void CPrintAppView::OnDraw(CDC* pDC)
{
	CPrintAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

	for(int x=0; x<m_numLines; ++x)
	{
		char str[81];
		wsprintf(str, "This is text line #%d of \
the PrintApp test document.", x+1);
		pDC->TextOut(20, x*m_charHeight, str);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView printing

BOOL CPrintAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation

	return DoPreparePrinting(pInfo);
}

void CPrintAppView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing

	TEXTMETRIC textMetric;
	pDC->GetTextMetrics(&textMetric);
	m_printerCharHeight = textMetric.tmHeight +
		textMetric.tmExternalLeading;

	m_vertRes = pDC->GetDeviceCaps(VERTRES);
	m_linesPerPage = m_vertRes / m_printerCharHeight;
	int numPages = m_numLines / m_linesPerPage + 1;

	pInfo->SetMinPage(1);
	pInfo->SetMaxPage(numPages);
}

void CPrintAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing

}

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView diagnostics

#ifdef _DEBUG
void CPrintAppView::AssertValid() const
{
	CView::AssertValid();
}

void CPrintAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrintAppDoc* CPrintAppView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintAppDoc)));
	return (CPrintAppDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintAppView message handlers

int CPrintAppView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	TEXTMETRIC textMetric;
	CClientDC clientDC(this);
	clientDC.GetTextMetrics(&textMetric);
	m_charHeight = textMetric.tmHeight +
		textMetric.tmExternalLeading;

	return 0;
}

void CPrintAppView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	m_numLines += 25;
	char str[81];
	wsprintf(str, "There are now %d lines in the document.", m_numLines);
	MessageBox(str, "PrintApp", MB_OK | MB_ICONINFORMATION);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}

void CPrintAppView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	m_numLines -= 25;
	if (m_numLines < 0)
		m_numLines = 0;

	char str[81];
	wsprintf(str, "There are now %d lines in the document.", m_numLines);
	MessageBox(str, "PrintApp", MB_OK | MB_ICONINFORMATION);
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}

void CPrintAppView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class

	CView::OnPrepareDC(pDC, pInfo);
}

void CPrintAppView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class

	int startLine = (pInfo->m_nCurPage - 1) *
		m_linesPerPage + 1;
	int endLine = startLine + m_linesPerPage - 1;
	if (endLine > m_numLines)
		endLine = m_numLines;

	int curLine = 0;
	for(int x=startLine; x<=endLine; ++x)
	{
		char str[81];
		wsprintf(str, "This is text line #%d of \
the PrintApp test document.", x);
		pDC->TextOut(20, curLine*m_printerCharHeight,
			str);
		++ curLine;
	}
	//CView::OnPrint(pDC, pInfo);
}
