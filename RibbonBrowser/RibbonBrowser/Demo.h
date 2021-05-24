#include "Navigation.h"
#pragma once


// CDemo view

class CDemo : public CView
{
	DECLARE_DYNCREATE(CDemo)

public:
	CDemo();           
	virtual ~CDemo();

public:
	void SetURL(CString csURL);
	void Navigation2URL(CString csURL);
	void GoBack();
	void GoForward();
	void Refresh();
public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void PreSubclassWindow();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private:
//	CString m_csURl;
public:
	CNavigation m_Navigation;

protected:
	DECLARE_MESSAGE_MAP()
};


