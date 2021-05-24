// RibbonBrowser.h : main header file for the RibbonBrowser DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CRibbonBrowserApp
// See RibbonBrowser.cpp for the implementation of this class
//

class CRibbonBrowserApp : public CWinApp
{
public:
	CRibbonBrowserApp();

public:
//	static FS_DIBitmap LoadBitmapFromPNG(UINT uID);

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
