// PolarizationProfileDoc.h : interface of the CPolarizationProfileDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLARIZATIONPROFILEDOC_H__4A9DA700_8A20_4944_B5CA_6C204DD437AD__INCLUDED_)
#define AFX_POLARIZATIONPROFILEDOC_H__4A9DA700_8A20_4944_B5CA_6C204DD437AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MAlign.h"


class CPolarizationProfileDoc : public CDocument
{
protected: // create from serialization only
	CPolarizationProfileDoc();
	DECLARE_DYNCREATE(CPolarizationProfileDoc)
	CMAlign m_cMAlign;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolarizationProfileDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPolarizationProfileDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPolarizationProfileDoc)
	afx_msg void OnOpenmultiplealignmentfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLARIZATIONPROFILEDOC_H__4A9DA700_8A20_4944_B5CA_6C204DD437AD__INCLUDED_)
