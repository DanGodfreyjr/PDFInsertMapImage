// Demo.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonBrowser.h"
#include "Demo.h"


// CDemo

IMPLEMENT_DYNCREATE(CDemo, CView)

CDemo::CDemo()
{
//	m_csURl = _T("");
}

CDemo::~CDemo()
{
}

BEGIN_MESSAGE_MAP(CDemo, CView)
END_MESSAGE_MAP()


// CDemo drawing

void CDemo::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CDemo diagnostics

#ifdef _DEBUG
void CDemo::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDemo::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDemo message handlers
void CDemo::PreSubclassWindow() 
{	
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CRect rect;
	GetClientRect(&rect);

	m_Navigation.Create(NULL,NULL,(WS_CHILD | WS_VISIBLE ),rect,this,0x47842,NULL);
//	m_Navigation.Navigate2(L"about:blank", NULL, NULL);
}

void CDemo::SetURL(CString csURL)
{
//	m_csURl = csURL;
}

void CDemo::Navigation2URL(CString csURL)
{
	m_Navigation.Navigate2(csURL, NULL, NULL);
} 

void CDemo::GoBack()
{
	m_Navigation.GoBack();
}

void CDemo::GoForward()
{
	m_Navigation.GoForward();
}

void CDemo::Refresh()
{
	m_Navigation.Refresh();
}