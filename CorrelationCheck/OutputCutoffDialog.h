#if !defined(AFX_OUTPUTCUTOFFDIALOG_H__3F68F34F_0FC4_4CBA_BAF0_3145687BD716__INCLUDED_)
#define AFX_OUTPUTCUTOFFDIALOG_H__3F68F34F_0FC4_4CBA_BAF0_3145687BD716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <vector>
using namespace std;

// OutputCutoffDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputCutoffDialog dialog
struct OptionNode{
	int nPropertyDim;
	int	nHits;
	int nNumberIndex;
	float* pfCutoff;
	bool bCorrelation;
	bool bPolarization;
	bool bpValue;
	bool brValue;
	float fpValue;
	bool bDetailed;
	bool bBrief;
	bool bRescaled;
	bool bPearson;
	bool bSpearman;
	float fRescaleFactor;
};

class COutputCutoffDialog : public CDialog
{
// Construction
public:
	OptionNode GetOptions();
	COutputCutoffDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COutputCutoffDialog)
	enum { IDD = IDD_OutputCutOffDialog };
	float	m_fChargCutoff;
	float	m_fBetaCarbonCutoff;
	float	m_fHydrophobicityCutoff;
	float	m_fVolumeCutoff;
	float	m_fProlineCutoff;
	float	m_fCysteinCutoff;
	float	m_fAromaticity;
	float	m_fpValue;
	BOOL	m_bPolarization;
	BOOL	m_bCorrelation;
	bool	m_bBrief;
	bool	m_bDetailed;
	bool	m_bRescaled;
	bool	m_bpValue;
	bool	m_brValue;
	int		m_nHits;
	int		m_nNumberIndex;
	float	m_fClustering;
	float	m_fRescaleFactor;
	bool    m_bPearson;
	bool	m_bSpearman;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputCutoffDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COutputCutoffDialog)
	afx_msg void OnPolarization();
	afx_msg void OnBUTTON1Brief();
	afx_msg void OnBUTTON2Detailed();
	afx_msg void OnBUTTON3Rescale();
	afx_msg void Onpvalue();
	afx_msg void OnRadiorValue();
	afx_msg void OnMethodPolarization();
	afx_msg void OnbPearson();
	afx_msg void OnbSpearman();
	afx_msg void OnRADIO3Brief();
	afx_msg void OnRADIO4Detailed();
	afx_msg void OnCHECK1Rescale();
	afx_msg void OnCHECK2DetailedOutput();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTCUTOFFDIALOG_H__3F68F34F_0FC4_4CBA_BAF0_3145687BD716__INCLUDED_)
