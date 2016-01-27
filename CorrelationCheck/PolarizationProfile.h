// PolarizationProfile.h : main header file for the POLARIZATIONPROFILE application
//

#if !defined(AFX_POLARIZATIONPROFILE_H__74DD8A26_7FF8_49AE_ACD9_204E7A9C9200__INCLUDED_)
#define AFX_POLARIZATIONPROFILE_H__74DD8A26_7FF8_49AE_ACD9_204E7A9C9200__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPolarizationProfileApp:
// See PolarizationProfile.cpp for the implementation of this class
//

class CPolarizationProfileApp : public CWinApp
{
public:
	CPolarizationProfileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolarizationProfileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPolarizationProfileApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLARIZATIONPROFILE_H__74DD8A26_7FF8_49AE_ACD9_204E7A9C9200__INCLUDED_)
