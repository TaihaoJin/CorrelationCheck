// PolarizationProfileView.cpp : implementation of the CPolarizationProfileView class

//



#include "stdafx.h"

#include "PolarizationProfile.h"



#include "PolarizationProfileDoc.h"

#include "PolarizationProfileView.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#undef THIS_FILE

static char THIS_FILE[] = __FILE__;

#endif

#include "nr.h"

/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView



IMPLEMENT_DYNCREATE(CPolarizationProfileView, CEditView)



BEGIN_MESSAGE_MAP(CPolarizationProfileView, CEditView)

	//{{AFX_MSG_MAP(CPolarizationProfileView)

	ON_COMMAND(ID_ANALYSIS_TESTNR, OnAnalysisTestnr)
	//}}AFX_MSG_MAP
	// Standard printing commands

	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)

	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)

	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView construction/destruction



CPolarizationProfileView::CPolarizationProfileView()

{

	// TODO: add construction code here



}



CPolarizationProfileView::~CPolarizationProfileView()

{

}



BOOL CPolarizationProfileView::PreCreateWindow(CREATESTRUCT& cs)

{

	// TODO: Modify the Window class or styles here by modifying

	//  the CREATESTRUCT cs



	BOOL bPreCreated = CEditView::PreCreateWindow(cs);

	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping



	return bPreCreated;

}



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView drawing



void CPolarizationProfileView::OnDraw(CDC* pDC)

{

	CPolarizationProfileDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here

}



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView printing



BOOL CPolarizationProfileView::OnPreparePrinting(CPrintInfo* pInfo)

{

	// default CEditView preparation

	return CEditView::OnPreparePrinting(pInfo);

}



void CPolarizationProfileView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)

{

	// Default CEditView begin printing.

	CEditView::OnBeginPrinting(pDC, pInfo);

}



void CPolarizationProfileView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)

{

	// Default CEditView end printing

	CEditView::OnEndPrinting(pDC, pInfo);

}



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView diagnostics



#ifdef _DEBUG

void CPolarizationProfileView::AssertValid() const

{

	CEditView::AssertValid();

}



void CPolarizationProfileView::Dump(CDumpContext& dc) const

{

	CEditView::Dump(dc);

}



CPolarizationProfileDoc* CPolarizationProfileView::GetDocument() // non-debug version is inline

{

	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolarizationProfileDoc)));

	return (CPolarizationProfileDoc*)m_pDocument;

}

#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileView message handlers


void CPolarizationProfileView::OnAnalysisTestnr() 
{
	// TODO: Add your command handler code here
	int i;
	CString sFileName;
	CString sForBuffer;

	FILE *fp;
	CFileDialog aFileDlg( true, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL );
	char* pch="Text files (*.txt)\0*.txt\0\0";
	CString sTitle="Input a txt file";
	aFileDlg.m_ofn.lpstrFilter=pch;
	aFileDlg.m_ofn.lpstrTitle=sTitle;

	vector <double> vectdX, vectdY;
	float dx,dy;
	int nLength=0,nLength0=0;
	if(aFileDlg.DoModal()==IDOK)
	{
		sFileName=aFileDlg.GetPathName();
		fp=fopen(sFileName,"r");
		while(!feof(fp))
		{
			fscanf(fp,"%f%f",&dx,&dy);
			vectdX.push_back(dx);
			vectdY.push_back(dy);
		}
		fclose(fp);
	}



//	Vec_I_DP data1(nSize),data2(nSize);//constant double nr array

	int nSize=vectdX.size();
	DP d, zd, probd, rs, probrs;
	Vec_DP data1(nSize),data2(nSize); //double nr array
	for(i=0;i<nSize;i++)
	{
		data1[i]=vectdX[i];
		data2[i]=vectdY[i];
	}
	NR::spear(data1, data2, d, zd, probd, rs, probrs);
//	fwrite(&m_DataName, sizeof(m_DataName)-1,1,fpEvlOut);	
}
