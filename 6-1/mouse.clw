; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMouseView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "mouse.h"
LastPage=0

ClassCount=5
Class1=CMouseApp
Class2=CMouseDoc
Class3=CMouseView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CMouseApp]
Type=0
HeaderFile=mouse.h
ImplementationFile=mouse.cpp
Filter=N

[CLS:CMouseDoc]
Type=0
HeaderFile=mouseDoc.h
ImplementationFile=mouseDoc.cpp
Filter=N

[CLS:CMouseView]
Type=0
HeaderFile=mouseView.h
ImplementationFile=mouseView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMouseView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T



[CLS:CAboutDlg]
Type=0
HeaderFile=mouse.cpp
ImplementationFile=mouse.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_APP_ABOUT
CommandCount=2

