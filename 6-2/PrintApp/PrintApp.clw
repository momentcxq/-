; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPrintAppView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PrintApp.h"
LastPage=0

ClassCount=5
Class1=CPrintAppApp
Class2=CPrintAppDoc
Class3=CPrintAppView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CPrintAppApp]
Type=0
HeaderFile=PrintApp.h
ImplementationFile=PrintApp.cpp
Filter=N

[CLS:CPrintAppDoc]
Type=0
HeaderFile=PrintAppDoc.h
ImplementationFile=PrintAppDoc.cpp
Filter=N

[CLS:CPrintAppView]
Type=0
HeaderFile=PrintAppView.h
ImplementationFile=PrintAppView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CPrintAppView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=PrintApp.cpp
ImplementationFile=PrintApp.cpp
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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_APP_ABOUT
CommandCount=5

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
CommandCount=1

