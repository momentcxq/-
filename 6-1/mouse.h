 // mouse.h : main header file for the MOUSE application
//

#if !defined(AFX_MOUSE_H__1079D964_1964_11D1_AB9F_504155C10000__INCLUDED_)
#define AFX_MOUSE_H__1079D964_1964_11D1_AB9F_504155C10000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseApp:
// See mouse.cpp for the implementation of this class
//

class CMouseApp : public CWinApp
{
public:
	CMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMouseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSE_H__1079D964_1964_11D1_AB9F_504155C10000__INCLUDED_)
