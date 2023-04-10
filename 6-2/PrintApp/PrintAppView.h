// PrintAppView.h : interface of the CPrintAppView class
//
/////////////////////////////////////////////////////////////////////////////
 
#if !defined(AFX_PRINTAPPVIEW_H__7ED1684C_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
#define AFX_PRINTAPPVIEW_H__7ED1684C_5778_11D1_AB9F_44C1FBC00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CPrintAppView : public CView
{
protected: // create from serialization only
	CPrintAppView();
	DECLARE_DYNCREATE(CPrintAppView)

// Attributes
public:
	CPrintAppDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintAppView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	int m_linesPerPage;
	int m_vertRes;
	int m_printerCharHeight;
	int m_charHeight;
	int m_numLines;
	//{{AFX_MSG(CPrintAppView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PrintAppView.cpp
inline CPrintAppDoc* CPrintAppView::GetDocument()
   { return (CPrintAppDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTAPPVIEW_H__7ED1684C_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
