// PrintApp.h : main header file for the PRINTAPP application
//
 
#if !defined(AFX_PRINTAPP_H__7ED16844_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
#define AFX_PRINTAPP_H__7ED16844_5778_11D1_AB9F_44C1FBC00000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPrintAppApp:
// See PrintApp.cpp for the implementation of this class
//

class CPrintAppApp : public CWinApp
{
public:
	CPrintAppApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintAppApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPrintAppApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTAPP_H__7ED16844_5778_11D1_AB9F_44C1FBC00000__INCLUDED_)
