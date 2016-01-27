// OutputCutoffDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PolarizationProfile.h"
#include "OutputCutoffDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// COutputCutoffDialog dialog


COutputCutoffDialog::COutputCutoffDialog(CWnd* pParent /*=NULL*/)
	: CDialog(COutputCutoffDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COutputCutoffDialog)
	m_fChargCutoff = 0.55f;
	m_fBetaCarbonCutoff = 0.55f;
	m_fHydrophobicityCutoff = 0.55f;
	m_fVolumeCutoff = 0.55f;
	m_fProlineCutoff = 0.55f;
	m_fCysteinCutoff = 0.55f;
	m_fAromaticity = 0.55f;
	m_fpValue = 0.05f;
	m_bPolarization = FALSE;
	m_bCorrelation = true;
	m_bBrief=true;
	m_bDetailed=false;
	m_bRescaled=false;
	m_bpValue=false;
	m_brValue=true;
	m_nHits = 2;
	m_nNumberIndex = 6;
	m_fClustering = 0.55f;
	m_fRescaleFactor = 0.3f;
	m_bSpearman=true;
	m_bPearson=false;
	//}}AFX_DATA_INIT
}


void COutputCutoffDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COutputCutoffDialog)
	DDX_Text(pDX, IDC_EDIT1, m_fChargCutoff);
	DDX_Text(pDX, IDC_EDIT2, m_fBetaCarbonCutoff);
	DDX_Text(pDX, IDC_EDIT3, m_fHydrophobicityCutoff);
	DDX_Text(pDX, IDC_EDIT4, m_fVolumeCutoff);
	DDX_Text(pDX, IDC_EDIT5, m_fProlineCutoff);
	DDX_Text(pDX, IDC_EDIT6, m_fCysteinCutoff);
	DDX_Text(pDX, IDC_EDIT7, m_fAromaticity);
	DDX_Text(pDX, IDC_EDIT8, m_fpValue);
//	DDX_Check(pDX, IDC_Correlation, m_bCorrelation);
	DDX_Text(pDX, IDC_EDIT9, m_nHits);
	DDX_Text(pDX, IDC_EDIT10, m_nNumberIndex);
	DDX_Text(pDX, IDC_EDIT11, m_fClustering);
	DDX_Text(pDX, IDC_EDIT12, m_fRescaleFactor);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COutputCutoffDialog, CDialog)
	//{{AFX_MSG_MAP(COutputCutoffDialog)
	ON_BN_CLICKED(IDC_pvalue, Onpvalue)
	ON_BN_CLICKED(IDC_Radio_rValue, OnRadiorValue)
	ON_BN_CLICKED(IDC_bPearson, OnbPearson)
	ON_BN_CLICKED(IDC_bSpearman, OnbSpearman)
//	ON_BN_CLICKED(IDC_RADIO3_Brief, OnRADIO3Brief)
//	ON_BN_CLICKED(IDC_RADIO4_Detailed, OnRADIO4Detailed)
	ON_BN_CLICKED(IDC_CHECK1_Rescale, OnCHECK1Rescale)
	ON_BN_CLICKED(IDC_CHECK2_Detailed, OnCHECK2DetailedOutput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputCutoffDialog message handlers

OptionNode COutputCutoffDialog::GetOptions()
{
	OptionNode aNode;
	float *fCutoff;
	fCutoff=new float[8];
	*(fCutoff+0)=m_fChargCutoff;
	*(fCutoff+1)=m_fBetaCarbonCutoff;
	*(fCutoff+2)=m_fHydrophobicityCutoff;
	*(fCutoff+3)=m_fVolumeCutoff;
	*(fCutoff+4)=m_fProlineCutoff;
	*(fCutoff+5)=m_fCysteinCutoff;
	*(fCutoff+6)=m_fAromaticity;
	*(fCutoff+7)=m_fClustering;
	if(m_fpValue>0.25)
	{
		for(int i=0;i<8;i++)
		{
			*(fCutoff+i)=m_fpValue;
		}
	}
	aNode.pfCutoff=fCutoff;
	aNode.fpValue=m_fpValue;
	aNode.bBrief=m_bBrief;
	aNode.bRescaled=m_bRescaled;
	aNode.bDetailed=m_bDetailed;
	aNode.bPolarization=m_bPolarization;
	aNode.brValue=m_brValue;
	aNode.bpValue=m_bpValue;
	aNode.nHits=m_nHits;
	aNode.nNumberIndex=m_nNumberIndex-1;
	aNode.fRescaleFactor=m_fRescaleFactor;
	aNode.bSpearman=m_bSpearman;
	aNode.bPearson=m_bPearson;
	return aNode;
}

void COutputCutoffDialog::OnPolarization() 
{
	// TODO: Add your control notification handler code here
	m_bPolarization=true;
	m_bCorrelation=false;
	
}

void COutputCutoffDialog::OnBUTTON1Brief() 
{
	// TODO: Add your control notification handler code here
	m_bDetailed=false;
	m_bBrief=true;
}

void COutputCutoffDialog::OnBUTTON2Detailed() 
{
	// TODO: Add your control notification handler code here
	m_bDetailed=true;
	m_bBrief=false;
}

void COutputCutoffDialog::OnBUTTON3Rescale() 
{
	// TODO: Add your control notification handler code here
	m_bRescaled=true;
}

void COutputCutoffDialog::Onpvalue() 
{
	// TODO: Add your control notification handler code here
	m_bpValue=true;
	m_brValue=false;
}

void COutputCutoffDialog::OnRadiorValue() 
{
	// TODO: Add your control notification handler code here
	m_bpValue=false;
	m_brValue=true;
}

void COutputCutoffDialog::OnMethodPolarization() 
{
	// TODO: Add your control notification handler code here
	m_bPolarization=true;
	m_bCorrelation=false;
}

void COutputCutoffDialog::OnbPearson() 
{
	// TODO: Add your control notification handler code here
	m_bPearson=true;
	m_bSpearman=false;
}

void COutputCutoffDialog::OnbSpearman() 
{
	// TODO: Add your control notification handler code here
	m_bSpearman=true;
	m_bPearson=false;
}

void COutputCutoffDialog::OnRADIO3Brief() 
{
	// TODO: Add your control notification handler code here
	
}

void COutputCutoffDialog::OnRADIO4Detailed() 
{
	// TODO: Add your control notification handler code here
	
}

void COutputCutoffDialog::OnCHECK1Rescale() 
{
	// TODO: Add your control notification handler code here
	
}

void COutputCutoffDialog::OnCHECK2DetailedOutput() 
{
	m_bBrief=false;
	m_bDetailed=true;	
}
