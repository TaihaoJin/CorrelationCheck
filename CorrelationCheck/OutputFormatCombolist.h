#if !defined(AFX_OUTPUTFORMATCOMBOLIST_H__13759297_14E0_4EC3_BF6D_51AA8C192C32__INCLUDED_)
#define AFX_OUTPUTFORMATCOMBOLIST_H__13759297_14E0_4EC3_BF6D_51AA8C192C32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputFormatCombolist.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputFormatCombolist window

class COutputFormatCombolist : public CComboBox
{
	DECLARE_DYNCREATE(COutputFormatCombolist)

// Construction
public:
	COutputFormatCombolist();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputFormatCombolist)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COutputFormatCombolist();

	// Generated message map functions
protected:
	//{{AFX_MSG(COutputFormatCombolist)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(COutputFormatCombolist)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COutputFormatCombolist)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTFORMATCOMBOLIST_H__13759297_14E0_4EC3_BF6D_51AA8C192C32__INCLUDED_)
