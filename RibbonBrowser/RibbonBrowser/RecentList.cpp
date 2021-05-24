// RecentList.cpp : implementation file
//

#include "stdafx.h"
#include "RibbonBrowser.h"
#include "RecentList.h"
#include "afxdialogex.h"


// CRecentList dialog

IMPLEMENT_DYNAMIC(CRecentList, CDialog)

CRecentList::CRecentList(CWnd* pParent /*=NULL*/)
	: CDialog(CRecentList::IDD, pParent)
{
	m_bBrush.CreateSolidBrush(RGB(255, 255, 255));
}

CRecentList::~CRecentList()
{
}

void CRecentList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
//	DDX_Control(pDX, IDC_URLLIST, m_listbox);
}


BEGIN_MESSAGE_MAP(CRecentList, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRecentList message handlers
HBRUSH CRecentList::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return m_bBrush;
}

/*BOOL CRecentList::OnInitDialog()
{
	CDialog::OnInitDialog();

	FR_RibbonStyleListBox pUrlList = (FR_RibbonStyleListBox)FRRibbonBackStageViewItemModifiedToRibbonStyleButton(GetDlgItem(IDC_URLLIST),
		IDC_URLLIST, FR_RibbonStyle_ListBox);

	FS_DIBitmap bitmapInternet = CRibbonBrowserApp::LoadBitmapFromPNG(IDB_PNG4);
	int nImageInternet = FRRibbonStyleListBoxAddImage(pUrlList, bitmapInternet);

	CListBox* pMFCListBox = (CListBox*)FRRibbonStyleListBoxGetMFCListBox(pUrlList);
	pMFCListBox->Detach();
	pMFCListBox->Attach(GetDlgItem(IDC_URLLIST)->GetSafeHwnd());

	FRRibbonStyleListBoxAddCaption(pUrlList, (FS_LPCWSTR)L"Foxit");
	FRRibbonStyleListBoxAddString(pUrlList, (FS_LPCWSTR)L"Forever", nImageInternet);

	FSDIBitmapDestroy(bitmapInternet);
	return TRUE;
}*/
