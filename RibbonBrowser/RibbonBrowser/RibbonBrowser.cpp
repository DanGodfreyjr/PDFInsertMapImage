/*********************************************************************

 Copyright (C) 2013 Foxit Corporation
 All rights reserved.

 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.

 ---------------------------------------------------------------------

RibbonBrowser.cpp

 - Defines the entry point for the DLL application, the entry point is PlugInMain.

*********************************************************************/

#include "stdafx.h"
#include "RibbonBrowser.h"
#include "Demo.h"
#include "RecentList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: If this DLL is dynamically linked against the MFC DLLs,
//		any functions exported from this DLL which call into
//		MFC must have the AFX_MANAGE_STATE macro added at the
//		very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

// CRibbonBrowserApp

BEGIN_MESSAGE_MAP(CRibbonBrowserApp, CWinApp)
END_MESSAGE_MAP()


// CRibbonBrowserApp construction

CRibbonBrowserApp::CRibbonBrowserApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CRibbonBrowserApp object

CRibbonBrowserApp theApp;

/** 
	This sample gives an explanation about how to use the ribbon element.
*/

// CRibbonBrowserApp initialization
#define FLAG_BACKWARD 1
#define FLAG_FORWARD  2
#define FLAG_REFRESH  3

CDemo* pDemo = NULL;
CStringArray saUrlList;
FR_RibbonStyleListBox ribbonstyleUrlList;

class ClientData
{
public:
	int nButtonFlag;
	BOOL bEnableFlag;
};

ClientData* pBackward = NULL;
ClientData* pForward = NULL;
ClientData* pRefresh = NULL;

BOOL bFlag = FALSE;

BOOL CRibbonBrowserApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//从资源中加载PNG图片
FS_FileRead gFileReadCallbacks = {0};

typedef struct _png_clientdata_
{
	BYTE* pData;
	DWORD dwSize;
}PNGCLIENTDATA;

FS_BOOL OnFileReadBlock(FS_LPVOID clientData, void* buffer, FS_DWORD offset, FS_DWORD size)
{
	PNGCLIENTDATA* pClientData = (PNGCLIENTDATA*)clientData;
	memcpy(buffer, pClientData->pData+offset, size);	
	return TRUE;
}

FS_DWORD OnFileGetSize(FS_LPVOID clientData)
{
	PNGCLIENTDATA* pClientData = (PNGCLIENTDATA*)clientData;
	return pClientData->dwSize;
}

void OnFileRelease(FS_LPVOID clientData)
{
	PNGCLIENTDATA* pClientData = (PNGCLIENTDATA*)clientData;
	delete pClientData;
	pClientData = NULL;
}

FS_DIBitmap _gLoadBitmapFromPNG(UINT uID)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	HINSTANCE hInstOld=AfxGetResourceHandle();
	AfxSetResourceHandle(AfxGetInstanceHandle());
	HRSRC hRes = ::FindResource(AfxGetInstanceHandle(), MAKEINTRESOURCE(uID), _T("PNG"));
	if (hRes == NULL) return NULL;
	DWORD dwLength = ::SizeofResource(AfxGetInstanceHandle(), hRes);
	HGLOBAL hGlobal = ::LoadResource(AfxGetInstanceHandle(), hRes);
	if (hGlobal == NULL) return NULL;
	LPVOID pData = ::LockResource(hGlobal);
	if (pData == NULL) return NULL;
	AfxSetResourceHandle(hInstOld);

	PNGCLIENTDATA* pClientData = new PNGCLIENTDATA;
	memset(pClientData, 0, sizeof(PNGCLIENTDATA));
	pClientData->pData = (BYTE*)pData;
	pClientData->dwSize = dwLength;

	memset(&gFileReadCallbacks, 0, sizeof(FS_FileRead));
	gFileReadCallbacks.lStructSize = sizeof(FS_FileRead);
	gFileReadCallbacks.clientData = (LPVOID)pClientData;
	gFileReadCallbacks.FSFileRead_Release = &OnFileRelease;
	gFileReadCallbacks.FSFileRead_ReadBlock = &OnFileReadBlock;
	gFileReadCallbacks.FSFileRead_GetSize = &OnFileGetSize;
	
	FS_FileReadHandler fileHandler = FSFileReadHandlerNew(gFileReadCallbacks);
	FS_DIBitmap bmp = FSDIBitmapLoadFromPNGIcon2(fileHandler);
	
	return bmp;
}

FS_BOOL FRAppEmptyFramWndCanClose(FS_LPVOID clientData, HWND wnd)
{
	return TRUE;
}

_fr_emptyframwndnotifies_ WndNotifyer =
{
	sizeof(_fr_emptyframwndnotifies_),
	NULL,
	FRAppEmptyFramWndCanClose
};

//设置编辑框回调函数
void GoToURL(void* clientData)
{
	FR_RibbonBar ribbonBar = FRAppGetRibbonBar(NULL);
	if(ribbonBar == NULL) return;
	FR_RibbonCategory categoryBrowser = NULL;
	categoryBrowser = FRRibbonBarGetCategoryByName(ribbonBar, "Browser");
	if(categoryBrowser == NULL) return;
	FR_RibbonPanel panelNavigation = FRRibbonCategoryGetPanelByName(categoryBrowser, "Navigation");
	if(panelNavigation == NULL) return;
	FR_RibbonElement elementURL = FRRibbonPanelGetElementByName(panelNavigation, "Address");
	if(elementURL == NULL) return;
	void* editURL = FRRibbonElementGetCorrespondingButton(elementURL);

	FS_WideString wsFrameName = FSWideStringNew3((FS_LPCWSTR)L"Ribbon Browser", 15);

	FS_WideString wsAddress = FSWideStringNew();
	FRRibbonEditGetText((FR_RibbonEdit)editURL, &wsAddress);
	
	FS_LPCWSTR szURL = FSWideStringCastToLPCWSTR(wsAddress); 
	CString strAddress;
	strAddress.Format(L"%s", szURL);

	if(!bFlag)//是否第一次创建
	{
		HWND hwnd = FRAppCreateAnEmptyFrameWnd(wsFrameName, TRUE, &WndNotifyer);

		pDemo->SubclassWindow(hwnd);
		if (strAddress.IsEmpty())
		{
			pDemo->Navigation2URL(L"about:blank");
		}
		else
		{
			pDemo->Navigation2URL(strAddress);
		}
		
		pBackward->bEnableFlag = TRUE;
		pForward->bEnableFlag = TRUE;
		pRefresh->bEnableFlag = TRUE;

		bFlag = TRUE;
	}
	else
	{
		pDemo->Navigation2URL(strAddress);
	}
	
	FSWideStringDestroy(wsFrameName);
	FSWideStringDestroy(wsAddress);
}

void RibbonFreeDataProc(void* clientData)
{
	ClientData* pClientData = (ClientData*)clientData;
	if (pClientData)
	{
		delete pClientData;
		pClientData = NULL;
	}
}

//设置向前，向后，刷新按钮回调函数
void OnClick(void* pData)
{
	ClientData* pFlag = (ClientData *)pData;
	switch (pFlag->nButtonFlag)
	{
		case FLAG_BACKWARD:
			pDemo->GoBack();
			break;
		case FLAG_FORWARD:
			pDemo->GoForward();
			break;
		case FLAG_REFRESH:
			pDemo->Refresh();
			break;
	}	
}

/*This optional callback is invoked by Foxit Reader when determining 
*whether or not to enable the tool button.
*/
BOOL IsEnable(void* pData)
{
	ClientData* pFlag = (ClientData*)pData;
	
	if (pFlag->bEnableFlag)
	{
		return TRUE;
	}
	return FALSE;
}

HWND RibbonBackstageProc(HWND hParentWnd, void* clientData)
{
	CRecentList* pRecentURLList = (CRecentList*)clientData;
	BOOL bResult = pRecentURLList->Create(IDD_RECENTLIST, CWnd::FromHandle(hParentWnd));

	if (!bResult) 
	{
		return NULL;
	}

	ribbonstyleUrlList = (FR_RibbonStyleListBox)FRRibbonBackStageViewItemModifiedToRibbonStyleButton(pRecentURLList->GetDlgItem(IDC_URLLIST),
		IDC_URLLIST, FR_RibbonStyle_ListBox, NULL);

	FS_DIBitmap bitmapInternet = _gLoadBitmapFromPNG(IDB_PNG4);
	int nImageInternet = FRRibbonStyleListBoxAddImage(ribbonstyleUrlList, bitmapInternet);

	CListBox* pMFCListBox = (CListBox*)FRRibbonStyleListBoxGetMFCListBox(ribbonstyleUrlList);
	pMFCListBox->Detach();
	pMFCListBox->Attach(pRecentURLList->GetDlgItem(IDC_URLLIST)->GetSafeHwnd());

	FRRibbonStyleListBoxAddCaption(ribbonstyleUrlList, (FS_LPCWSTR)L"Recent URL");
	
	int nCount = saUrlList.GetCount();
	for (int i=0; i < nCount; i++)
	{	
		FRRibbonStyleListBoxAddString(ribbonstyleUrlList, (FS_LPCWSTR)(LPCWSTR)(saUrlList.GetAt(i)), nImageInternet);
	}
 
	FSDIBitmapDestroy(bitmapInternet);
	return pRecentURLList->GetSafeHwnd();	
}

void RibbonBackstageDestoryProc(void* pDialog, void* clientData)
{
	if(ribbonstyleUrlList)
	{
		FRRibbonStyleListBoxRelease(ribbonstyleUrlList);
	}
	
	CRecentList* pRecentURLList = (CRecentList*)clientData;
	pRecentURLList->DestroyWindow();
}

/********************************************************************/
/* The basic procedure of plug-in.                                   
/********************************************************************/


/* PIExportHFTs
** ------------------------------------------------------
**/
/** 
** Create and Add the extension HFT's.
**
** @return true to continue loading plug-in,
** false to cause plug-in loading to stop.
*/
FS_BOOL PIExportHFTs(void)
{
	return TRUE;
}

/** 
The application calls this function to allow it to
<ul>
<li> Import plug-in supplied HFTs.
<li> Replace functions in the HFTs you're using (where allowed).
<li> Register to receive notification events.
</ul>
*/
FS_BOOL PIImportReplaceAndRegister(void)
{
	return TRUE;
}

/* Plug-ins can use their Initialization procedures to hook into Foxit Reader's 
	 * user interface by adding menu items, toolbar buttons, windows, and so on.
	 * It is also acceptable to modify Foxit Reader's user interface later when the plug-in is running.
	 */
void PILoadMenuBarUI(void* pParentWnd)
{

}

void PIReleaseMenuBarUI(void* pParentWnd)
{

}

void PILoadToolBarUI(void* pParentWnd)
{

}

void PIReleaseToolBarUI(void* pParentWnd)
{

}


void PILoadRibbonUI(void* pParentWnd)
{
	FR_RibbonBar ribbonBar = FRAppGetRibbonBar(NULL);
	if (NULL == ribbonBar)
	{
		return ;
	}

	FR_RibbonCategory categoryBrowser = FRRibbonBarAddCategory(ribbonBar, "Browser", (FS_LPCWSTR)L"BROWSER");//Add Category
	FR_RibbonPanel panelNavigation = FRRibbonCategoryAddPanel(categoryBrowser, "Navigation", (FS_LPCWSTR)L"Navigation", NULL);//Add Panel

	void* editURL = FRRibbonPanelAddElement(panelNavigation, FR_RIBBON_EDIT, "Address", (FS_LPCWSTR)L"URL: ", 3);//Add edit
	FRRibbonEditSetWidth((FR_RibbonEdit)editURL, 300); //Set Edit width
	FR_RibbonElement elementURL = FRRibbonEditGetElement((FR_RibbonEdit)editURL);

	CRecentList* pRecentURLList = new CRecentList();
	FR_RibbonBackStageViewItem backstageHistory = FRRibbonBarAddBackStageViewItem(ribbonBar, "File_Main_Histoty", (FS_LPCWSTR)L"History", 0);//Add BackStage
	FRRibbonBackStageViewItemAddPropertySheetPage(backstageHistory, (FS_LPCSTR)"History", (FS_LPCWSTR)L"History", NULL, 
		1, RibbonBackstageProc, RibbonBackstageDestoryProc, pRecentURLList);

	//Add Button

	void* buttonBackward = FRRibbonPanelAddElement(panelNavigation, FR_RIBBON_BUTTON, "Backward", (FS_LPCWSTR)L"", 0);//Add Button Backward
	FR_RibbonElement elementBackward = FRRibbonButtonGetElement((FR_RibbonButton)buttonBackward);
	FS_DIBitmap bitmapBackward16 = _gLoadBitmapFromPNG(IDB_PNG1);
	//FS_DIBitmap bitmapBackward32 = FSDIBitmapLoadFromPNGIcon((FS_LPCWSTR)L"res\\BackWard32.png");
	FRRibbonElementSetImage(elementBackward, NULL, bitmapBackward16 );

	void* buttonForward = FRRibbonPanelAddElement(panelNavigation, FR_RIBBON_BUTTON, "Forward", (FS_LPCWSTR)L"", 1);//Add Button Forward
	FR_RibbonElement elementForward = FRRibbonButtonGetElement((FR_RibbonButton)buttonForward);
	FS_DIBitmap bitmapForward16 = _gLoadBitmapFromPNG(IDB_PNG2);
	//	FS_DIBitmap bitmapForward32 = FSDIBitmapLoadFromPNGIcon((FS_LPCWSTR)L"re s\\Forward32.png");
	FRRibbonElementSetImage(elementForward, /*bitmapForward32*/NULL, bitmapForward16);

	void* buttonRefresh = FRRibbonPanelAddElement(panelNavigation, FR_RIBBON_BUTTON, "Refresh", (FS_LPCWSTR)L"", 2);//Add Button Refresh
	FR_RibbonElement elementRefresh = FRRibbonButtonGetElement((FR_RibbonButton)buttonRefresh);
	FS_DIBitmap bitmapRefresh16 = _gLoadBitmapFromPNG(IDB_PNG3);
	//	FS_DIBitmap bitmapRefresh32 = FSDIBitmapLoadFromPNGIcon((FS_LPCWSTR)L"res\\Refresh32.png");
	FRRibbonElementSetImage(elementRefresh, /*bitmapRefresh32*/NULL, bitmapRefresh16);

	pDemo = new CDemo();
	FRRibbonElementSetExecuteProc(elementURL, &GoToURL);//Set Edit CallBack

	//Set Backward ClientData
	pBackward = new ClientData;
	pBackward->nButtonFlag = FLAG_BACKWARD;
	pBackward->bEnableFlag = FALSE;
	FRRibbonElementSetClientData(elementBackward, pBackward, &RibbonFreeDataProc);
	FRRibbonElementSetExecuteProc(elementBackward, &OnClick);
	FRRibbonElementSetComputeEnabledProc(elementBackward, &IsEnable);

	//Set Forward ClientData
	pForward = new ClientData;
	pForward->nButtonFlag = FLAG_FORWARD;
	pForward->bEnableFlag = FALSE;
	FRRibbonElementSetClientData(elementForward, pForward, &RibbonFreeDataProc);
	FRRibbonElementSetExecuteProc(elementForward, &OnClick);
	FRRibbonElementSetComputeEnabledProc(elementForward, &IsEnable);

	//Set Refresh ClientData
	pRefresh = new ClientData;
	pRefresh->nButtonFlag = FLAG_REFRESH;
	pRefresh->bEnableFlag = FALSE;
	FRRibbonElementSetClientData(elementRefresh, pRefresh, &RibbonFreeDataProc);
	FRRibbonElementSetExecuteProc(elementRefresh, &OnClick);
	FRRibbonElementSetComputeEnabledProc(elementRefresh, &IsEnable);

}
void PILoadStatusBarUI(void* pParentWnd)
{

}

/* PIInit
** ------------------------------------------------------
**/
/** 
	The main initialization routine.
	
	@return true to continue loading the plug-in, 
	false to cause plug-in loading to stop.
*/
FS_BOOL PIInit(void)
{	
	return TRUE;
}

/* PIUnload
** ------------------------------------------------------
**/
/** 
	The unload routine.
	Called when your plug-in is being unloaded when the application quits.
	Use this routine to release any system resources you may have
	allocated.

	Returning false will cause an alert to display that unloading failed.
	@return true to indicate the plug-in unloaded.
*/
FS_BOOL PIUnload(void)
{
	return TRUE;
}

/** PIHandshake
	function provides the initial interface between your plug-in and the application.
	This function provides the callback functions to the application that allow it to 
	register the plug-in with the application environment.

	Required Plug-in handshaking routine:
	
	@param handshakeVersion the version this plug-in works with. 
	@param handshakeData OUT the data structure used to provide the primary entry points for the plug-in. These
	entry points are used in registering the plug-in with the application and allowing the plug-in to register for 
	other plug-in services and offer its own.
	@return true to indicate success, false otherwise (the plug-in will not load).
*/
FS_BOOL PIHandshake(FS_INT32 handshakeVersion, void *handshakeData)
{
	if(handshakeVersion != HANDSHAKE_V0100)
		return FALSE;
	
	/* Cast handshakeData to the appropriate type */
	PIHandshakeData_V0100* pData = (PIHandshakeData_V0100*)handshakeData;
	
	/* Set the name we want to go by */
	pData->PIHDRegisterPlugin(pData, "RibbonBrowser", (FS_LPCWSTR)L"RibbonBrowser");

	

	/* If you export your own HFT, do so in here */
	pData->PIHDSetExportHFTsCallback(pData, &PIExportHFTs);
		
	/*
	** If you import plug-in HFTs, replace functionality, and/or want to register for notifications before
	** the user has a chance to do anything, do so in here.
	*/
	pData->PIHDSetImportReplaceAndRegisterCallback(pData, &PIImportReplaceAndRegister);

	/* Perform your plug-in's initialization in here */
	pData->PIHDSetInitDataCallback(pData, &PIInit);
	PIInitUIProcs initUIProcs;
	INIT_CALLBACK_STRUCT(&initUIProcs, sizeof(PIInitUIProcs));
	initUIProcs.lStructSize = sizeof(PIInitUIProcs);
	initUIProcs.PILoadMenuBarUI = PILoadMenuBarUI;
	initUIProcs.PIReleaseMenuBarUI = PIReleaseMenuBarUI;
	initUIProcs.PILoadToolBarUI = PILoadToolBarUI;
	initUIProcs.PIReleaseToolBarUI = PIReleaseToolBarUI;
	initUIProcs.PILoadRibbonUI = PILoadRibbonUI;
	initUIProcs.PILoadStatusBarUI = PILoadStatusBarUI;
	pData->PIHDSetInitUICallbacks(pData, &initUIProcs);	

	/* Perform any memory freeing or state saving on "quit" in here */
	pData->PIHDSetUnloadCallback(pData, &PIUnload);

	return TRUE;
}

/*Core HFT Manager.*/
FRCoreHFTMgr *_gpCoreHFTMgr = NULL;

/*The plug-in ID*/
void* _gPID = NULL;

/* 
** This routine is called by the host application to set up the plug-in's SDK-provided functionality.
*/
FS_BOOL PISetupSDK(FS_INT32 handshakeVersion, void *sdkData)
{
	if(handshakeVersion != HANDSHAKE_V0100) return FALSE;
	PISDKData_V0100 *pSDKData = (PISDKData_V0100*)sdkData;
	
	/* Get our globals out */
	_gpCoreHFTMgr = pSDKData->PISDGetCoreHFT();

	/* Get PID */
	_gPID = pSDKData->PISDGetPID(sdkData);

	/* Set the plug-in's handshake routine, which is called next by the host application */
	pSDKData->PISDSetHandshakeProc(sdkData, &PIHandshake);

	/* For compatibility purposes, set the plug-in's SDK version, 
	so that Foxit Reader will not load the plug-in whose version is larger than Foxit Reader. */
	pSDKData->PISetSDKVersion(sdkData, SDK_VERSION);

	return TRUE;
}

#ifdef __cplusplus
extern "C" {
#endif


/* The export function of plug-ins */
__declspec(dllexport) FS_BOOL PlugInMain(FS_INT32* handshakeVersion, PISetupSDKProcType* setupProc)
{
	/*
	** handshakeVersion tells us which version of the handshake struct the application has sent us.
	** The version we want to use is returned to the application so it can adjust accordingly.
	*/

	*handshakeVersion = HANDSHAKE_V0100;
	*setupProc = &PISetupSDK;
	return TRUE;
} 


#ifdef __cplusplus
}
#endif