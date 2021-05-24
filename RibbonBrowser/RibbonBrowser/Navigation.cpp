// Navigation.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonBrowser.h"
#include "Navigation.h"
#include "Demo.h"
#include <comdef.h>

extern CStringArray saUrlList;
extern _fr_emptyframwndnotifies_ WndNotifyer;
// CNavigation

IMPLEMENT_DYNCREATE(CNavigation, CHtmlView)

CNavigation::CNavigation()
{

}

CNavigation::~CNavigation()
{
}

void CNavigation::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNavigation, CHtmlView)
END_MESSAGE_MAP()

// CNavigation diagnostics

#ifdef _DEBUG
void CNavigation::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CNavigation::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CNavigation message handlers

/*void CNavigation::OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel)
{
	// TODO: Add your specialized code here and/or call the base class  
	CComPtr<IHTMLDocument2> pHTMLDocument2;  

	m_pBrowserApp->get_Document((IDispatch **)&pHTMLDocument2);  
	if (pHTMLDocument2!=NULL)  
	{  
		CComPtr<IHTMLElement> pIHTMLElement;  
		pHTMLDocument2->get_activeElement(&pIHTMLElement);  

		if (pIHTMLElement!=NULL)  
		{  
			variant_t url;  
			HRESULT hr=pIHTMLElement->getAttribute(L"href", 0, &url);  
			if (SUCCEEDED(hr))  
			{  
				hr=m_pBrowserApp->Navigate2(&url, NULL, NULL, NULL, NULL);  

				url.Clear();  

				if (SUCCEEDED(hr))  
				{  
					*Cancel=TRUE;  
				}  
			}  
		}  
	}    
}*/

void CNavigation::OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel)
{
	FS_WideString wsAddress = FSWideStringNew3((FS_LPCWSTR)L"Ribbon Browser", 15);
	HWND hwnd = FRAppCreateAnEmptyFrameWnd(wsAddress, TRUE, &WndNotifyer);

	CDemo* pNewBrowserView = new CDemo();
	pNewBrowserView->SubclassWindow(hwnd);

	pNewBrowserView->m_Navigation.SetRegisterAsBrowser(TRUE);
	*ppDisp = pNewBrowserView->m_Navigation.GetApplication();

	FSWideStringDestroy(wsAddress);
}

/*void CNavigation::OnNavigateComplete2(LPCTSTR strURL)
{
	CComPtr<IDispatch>   spDisp   =   GetHtmlDocument(); 
	if(spDisp   !=   NULL) 
	{ 
		CComPtr<IHTMLDocument2> doc;
		spDisp->QueryInterface(IID_IHTMLDocument2, reinterpret_cast<void**>(&doc));
		if(doc != NULL)
		{   
			IHTMLWindow2 * pIhtmlwindow2 = NULL;
			doc->get_parentWindow(&pIhtmlwindow2);
			if(pIhtmlwindow2 != NULL)
			{
				//屏蔽javascript脚本错误的javascript脚本
				CString strJavaScriptCode = L"function fnOnError(msg,url,lineno){alert('script error:\\n\\nURL:'+url+'\\n\\nMSG:'+msg +'\\n\\nLine:'+lineno);return true;}window.onerror=fnOnError;";
				BSTR bstrScript = strJavaScriptCode.AllocSysString();
				CString strLanguage("JavaScript");
				BSTR bstrLanguage = strLanguage.AllocSysString();
				long lTime = 1 * 1000;
				long lTimeID = 0;
				VARIANT varLanguage;
				varLanguage.vt = VT_BSTR;
				varLanguage.bstrVal = bstrLanguage;
				VARIANT pRet;
				//把window.onerror函数插入入当前页面中去
				pIhtmlwindow2->execScript(bstrScript, bstrLanguage, &pRet);
				::SysFreeString(bstrScript);
				::SysFreeString(bstrLanguage);
				pIhtmlwindow2->Release();
			}
		}
	}
}*/

void CNavigation::DocumentComplete(LPDISPATCH lpDisp,
	VARIANT FAR* URL)
{
	IUnknown*  pUnk;
	LPDISPATCH lpWBDisp;
	HRESULT    hr;
	
	m_pBrowserApp.QueryInterface(&pUnk);
	ASSERT(pUnk);

	hr = pUnk->QueryInterface(IID_IDispatch, (void**)&lpWBDisp);
	ASSERT(SUCCEEDED(hr));

	if (lpDisp == lpWBDisp )
	{
		// Top-level Window object, so document has been loaded
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

		CString csURL = GetLocationURL();
		FRRibbonEditSetText((FR_RibbonEdit)editURL, (FS_LPCWSTR)(LPCWSTR)csURL);

		CString str = GetLocationName();

		CString csRecentURl = str + L"\n" + csURL;
		saUrlList.Add(csRecentURl);
		//TRACE("Web document is finished downloading\n");
	}

	lpWBDisp->Release();
}