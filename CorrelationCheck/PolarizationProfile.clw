; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COutputCutoffDialog
LastTemplate=CComboBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PolarizationProfile.h"
LastPage=0

ClassCount=8
Class1=CPolarizationProfileApp
Class2=CPolarizationProfileDoc
Class3=CPolarizationProfileView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_POLARITYPE
Resource2=IDD_ABOUTBOX
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_MAINFRAME
Class7=COutputCutoffDialog
Class8=COutputFormatCombolist
Resource4=IDD_OutputCutOffDialog

[CLS:CPolarizationProfileApp]
Type=0
HeaderFile=PolarizationProfile.h
ImplementationFile=PolarizationProfile.cpp
Filter=N

[CLS:CPolarizationProfileDoc]
Type=0
HeaderFile=PolarizationProfileDoc.h
ImplementationFile=PolarizationProfileDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_EDIT_PASTE

[CLS:CPolarizationProfileView]
Type=0
HeaderFile=PolarizationProfileView.h
ImplementationFile=PolarizationProfileView.cpp
Filter=C
LastObject=ID_ANALYSIS_TESTNR
BaseClass=CEditView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=PolarizationProfile.cpp
ImplementationFile=PolarizationProfile.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_POLARITYPE]
Type=1
Class=CPolarizationProfileView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_OPENMULTIPLEALIGNMENTFILE
Command4=ID_FILE_CLOSE
Command5=ID_FILE_SAVE
Command6=ID_FILE_SAVE_AS
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=ID_WINDOW_NEW
Command19=ID_WINDOW_CASCADE
Command20=ID_WINDOW_TILE_HORZ
Command21=ID_WINDOW_ARRANGE
Command22=ID_ANALYSIS_TESTNR
Command23=ID_APP_ABOUT
CommandCount=23

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_OutputCutOffDialog]
Type=1
Class=COutputCutoffDialog
ControlCount=37
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT3,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT6,edit,1350631552
Control15=Aromaticity,static,1342308352
Control16=IDC_EDIT7,edit,1350631552
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_EDIT8,edit,1350631552
Control21=IDC_pvalue,button,1342177289
Control22=IDC_Radio_rValue,button,1342177289
Control23=IDC_STATIC,static,1342308352
Control24=IDC_EDIT9,edit,1350631552
Control25=IDC_STATIC,static,1342308352
Control26=IDC_EDIT10,edit,1350631552
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_EDIT11,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_EDIT12,edit,1350631552
Control32=IDC_bPearson,button,1342177289
Control33=IDC_bSpearman,button,1342177289
Control34=IDC_GroupBox_CorrelationMethod,button,1342177287
Control35=IDC_CHECK1_Rescale,button,1342242819
Control36=IDC_Group_OutputOptions,button,1342177287
Control37=IDC_CHECK2_Detailed,button,1342242819

[CLS:COutputCutoffDialog]
Type=0
HeaderFile=OutputCutoffDialog.h
ImplementationFile=OutputCutoffDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_CHECK2_Detailed

[CLS:COutputFormatCombolist]
Type=0
HeaderFile=OutputFormatCombolist.h
ImplementationFile=OutputFormatCombolist.cpp
BaseClass=CComboBox
Filter=W

