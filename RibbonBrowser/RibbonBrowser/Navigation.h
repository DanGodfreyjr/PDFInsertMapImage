#pragma once

#ifdef _WIN32_WCE
#error "CHtmlView is not supported for Windows CE."
#endif 

// CNavigation html view

class CNavigation : public CHtmlView
{
	DECLARE_DYNCREATE(CNavigation)

public:
	CNavigation();          
	virtual ~CNavigation();

public:
	virtual void	PostNcDestroy() {};
//	virtual void PreSubclassWindow();
	virtual void OnNewWindow2(LPDISPATCH* ppDisp, BOOL* Cancel);
//	virtual void OnNavigateComplete2(LPCTSTR strURL);
//	virtual void OnDocumentComplete(LPCTSTR lpszURL);

public:
	virtual void DocumentComplete(LPDISPATCH lpDisp, VARIANT FAR* URL);

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};


