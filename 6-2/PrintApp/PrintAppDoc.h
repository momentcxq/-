// PrintAppDoc.h : interface of the CPrintAppDoc class
//
/////////////////////////////////////////////////////////////////////////////
 
#if !defined(AFX_PRINTAPPDOC_H__7ED1684A_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
#define AFX_PRINTAPPDOC_H__7ED1684A_5778_11D1_AB9F_44C1FBC00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CPrintAppDoc : public CDocument
{
protected: // create from serialization only
	CPrintAppDoc();
	DECLARE_DYNCREATE(CPrintAppDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintAppDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPrintAppDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPrintAppDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTAPPDOC_H__7ED1684A_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
