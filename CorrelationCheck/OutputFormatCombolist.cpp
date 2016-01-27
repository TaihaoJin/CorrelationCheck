// OutputFormatCombolist.cpp : implementation file
//

#include "stdafx.h"
#include "PolarizationProfile.h"
#include "OutputFormatCombolist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputFormatCombolist

IMPLEMENT_DYNCREATE(COutputFormatCombolist, CComboBox)

COutputFormatCombolist::COutputFormatCombolist()
{
	EnableAutomation();
	
	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	
	AfxOleLockApp();
}

COutputFormatCombolist::~COutputFormatCombolist()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}

void COutputFormatCombolist::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CComboBox::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(COutputFormatCombolist, CComboBox)
	//{{AFX_MSG_MAP(COutputFormatCombolist)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COutputFormatCombolist, CComboBox)
	//{{AFX_DISPATCH_MAP(COutputFormatCombolist)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOutputFormatCombolist to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {5C08CFBC-A93B-466F-A667-11ECF13364AB}
static const IID IID_IOutputFormatCombolist =
{ 0x5c08cfbc, 0xa93b, 0x466f, { 0xa6, 0x67, 0x11, 0xec, 0xf1, 0x33, 0x64, 0xab } };

BEGIN_INTERFACE_MAP(COutputFormatCombolist, CComboBox)
	INTERFACE_PART(COutputFormatCombolist, IID_IOutputFormatCombolist, Dispatch)
END_INTERFACE_MAP()

// {BA9D362A-387A-4880-BDFE-DE819AD3276E}
IMPLEMENT_OLECREATE(COutputFormatCombolist, "PolarizationProfile.OutputFormatComboli", 0xba9d362a, 0x387a, 0x4880, 0xbd, 0xfe, 0xde, 0x81, 0x9a, 0xd3, 0x27, 0x6e)

/////////////////////////////////////////////////////////////////////////////
// COutputFormatCombolist message handlers
