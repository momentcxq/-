// PrintAppDoc.cpp : implementation of the CPrintAppDoc class
//

#include "stdafx.h"
#include "PrintApp.h"
 
#include "PrintAppDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintAppDoc

IMPLEMENT_DYNCREATE(CPrintAppDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintAppDoc, CDocument)
	//{{AFX_MSG_MAP(CPrintAppDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintAppDoc construction/destruction

CPrintAppDoc::CPrintAppDoc()
{
	// TODO: add one-time construction code here

}

CPrintAppDoc::~CPrintAppDoc()
{
}

BOOL CPrintAppDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPrintAppDoc serialization

void CPrintAppDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPrintAppDoc diagnostics

#ifdef _DEBUG
void CPrintAppDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintAppDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPrintAppDoc commands
