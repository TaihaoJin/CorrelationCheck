// PolarizationProfileView.h : interface of the CPolarizationProfileView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLARIZATIONPROFILEVIEW_H__95106EC6_974C_4E91_8626_E5BE5256DE53__INCLUDED_)
#define AFX_POLARIZATIONPROFILEVIEW_H__95106EC6_974C_4E91_8626_E5BE5256DE53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolarizationProfileView : public CEditView
{
protected: // create from serialization only
	CPolarizationProfileView();
	DECLARE_DYNCREATE(CPolarizationProfileView)

// Attributes
public:
	CPolarizationProfileDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolarizationProfileView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPolarizationProfileView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPolarizationProfileView)
	afx_msg void OnAnalysisTestnr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PolarizationProfileView.cpp
inline CPolarizationProfileDoc* CPolarizationProfileView::GetDocument()
   { return (CPolarizationProfileDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLARIZATIONPROFILEVIEW_H__95106EC6_974C_4E91_8626_E5BE5256DE53__INCLUDED_)
