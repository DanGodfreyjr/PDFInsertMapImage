#pragma once
#include "afxwin.h"


// CRecentList dialog

class CRecentList : public CDialog
{
	DECLARE_DYNAMIC(CRecentList)

public:
	CRecentList(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRecentList();

// Dialog Data
	enum { IDD = IDD_RECENTLIST };

public:
	CBrush m_bBrush;

public:
//	virtual BOOL OnInitDialog();
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
//public: 
//	CListBox m_listbox;
};
