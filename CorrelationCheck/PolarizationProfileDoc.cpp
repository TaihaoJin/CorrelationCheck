// PolarizationProfileDoc.cpp : implementation of the CPolarizationProfileDoc class

//



#include "stdafx.h"
#include "PolarizationProfile.h"
#include "PolarizationProfileDoc.h"
#include "Polarization.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileDoc



IMPLEMENT_DYNCREATE(CPolarizationProfileDoc, CDocument)



BEGIN_MESSAGE_MAP(CPolarizationProfileDoc, CDocument)

	//{{AFX_MSG_MAP(CPolarizationProfileDoc)

	ON_COMMAND(ID_OPENMULTIPLEALIGNMENTFILE, OnOpenmultiplealignmentfile)

	//}}AFX_MSG_MAP

END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileDoc construction/destruction



CPolarizationProfileDoc::CPolarizationProfileDoc()

{

	// TODO: add one-time construction code here

}



CPolarizationProfileDoc::~CPolarizationProfileDoc()

{

}



BOOL CPolarizationProfileDoc::OnNewDocument()

{

	if (!CDocument::OnNewDocument())

		return FALSE;



	// TODO: add reinitialization code here

	// (SDI documents will reuse this document)



	return TRUE;

}







/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileDoc serialization



void CPolarizationProfileDoc::Serialize(CArchive& ar)

{

	// CEditView contains an edit control which handles all serialization

	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);

}



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileDoc diagnostics



#ifdef _DEBUG

void CPolarizationProfileDoc::AssertValid() const

{

	CDocument::AssertValid();

}



void CPolarizationProfileDoc::Dump(CDumpContext& dc) const

{

	CDocument::Dump(dc);

}

#endif //_DEBUG



/////////////////////////////////////////////////////////////////////////////

// CPolarizationProfileDoc commands



void CPolarizationProfileDoc::OnOpenmultiplealignmentfile() 

{
	// TODO: Add your command handler code here
	m_cMAlign.ReadMAlign();
	CPolarization aPol(m_cMAlign);
}

