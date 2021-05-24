/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_BARCALLS_H
#define FR_BARCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_BAREXPT_H
#include "fr_barExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_barImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_barTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_barImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_barTempl.h"

//----------_V1----------
//*****************************
/* ToolButton HFT functions */
//*****************************

#define FRToolButtonNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonNewSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonNewSEL, _gPID)))

#define FRToolButtonRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonReleaseSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonReleaseSEL, _gPID)))

#define FRToolButtonGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonGetNameSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonGetNameSEL, _gPID)))

#define FRToolButtonGetLabelText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonGetLabelTextSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonGetLabelTextSEL, _gPID)))

#define FRToolButtonSetLabelText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetLabelTextSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetLabelTextSEL, _gPID)))

#define FRToolButtonSetHelpText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetHelpTextSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetHelpTextSEL, _gPID)))

#define FRToolButtonSetIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetIconSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetIconSEL, _gPID)))

#define FRToolButtonIsSeparator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonIsSeparatorSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonIsSeparatorSEL, _gPID)))

#define FRToolButtonIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonIsVisibleSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonIsVisibleSEL, _gPID)))

#define FRToolButtonSetExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetExecuteProcSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetExecuteProcSEL, _gPID)))

#define FRToolButtonSetEnableProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetEnableProcSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetEnableProcSEL, _gPID)))

#define FRToolButtonSetMarkedProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetMarkedProcSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetMarkedProcSEL, _gPID)))

#define FRToolButtonSetDropDownProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetDropDownProcSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetDropDownProcSEL, _gPID)))

#define FRToolButtonGetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonGetClientDataSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonGetClientDataSEL, _gPID)))

#define FRToolButtonExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonExecuteProcSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonExecuteProcSEL, _gPID)))

#define FRToolButtonSetFlyoutToolBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetFlyoutToolBarSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetFlyoutToolBarSEL, _gPID)))

#define FRToolButtonGetMapId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonGetMapIdSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonGetMapIdSEL, _gPID)))

#define FRToolButtonSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolButtonSetClientDataSELPROTO)FRCOREROUTINE(FRToolButtonSEL,FRToolButtonSetClientDataSEL, _gPID)))

//*****************************
/* ToolBar HFT functions */
//*****************************

#define FRToolBarNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarNewSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarNewSEL, _gPID)))

#define FRToolBarNewFlyout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarNewFlyoutSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarNewFlyoutSEL, _gPID)))

#define FRToolBarRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarReleaseSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarReleaseSEL, _gPID)))

#define FRToolBarGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarGetNameSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarGetNameSEL, _gPID)))

#define FRToolBarCountButtons (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarCountButtonsSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarCountButtonsSEL, _gPID)))

#define FRToolBarGetButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarGetButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarGetButtonSEL, _gPID)))

#define FRToolBarGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarGetTitleSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarGetTitleSEL, _gPID)))

#define FRToolBarSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarSetTitleSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarSetTitleSEL, _gPID)))

#define FRToolBarGetButtonByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarGetButtonByNameSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarGetButtonByNameSEL, _gPID)))

#define FRToolBarAddButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarAddButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarAddButtonSEL, _gPID)))

#define FRToolBarInsertButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarInsertButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarInsertButtonSEL, _gPID)))

#define FRToolBarShowToolBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarShowToolBarSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarShowToolBarSEL, _gPID)))

#define FRToolBarHideToolBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarHideToolBarSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarHideToolBarSEL, _gPID)))

#define FRToolBarShowToolButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarShowToolButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarShowToolButtonSEL, _gPID)))

#define FRToolBarHideToolButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarHideToolButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarHideToolButtonSEL, _gPID)))

#define FRToolBarRemoveButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarRemoveButtonSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarRemoveButtonSEL, _gPID)))

#define FRToolBarUpdateButtonStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarUpdateButtonStatesSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarUpdateButtonStatesSEL, _gPID)))

#define FRToolBarIsFlyOutToolbar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarIsFlyOutToolbarSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarIsFlyOutToolbarSEL, _gPID)))

#define FRToolBarSetMenuTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarSetMenuTitleSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarSetMenuTitleSEL, _gPID)))

#define FRToolBarSetDefaultToolbar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarSetDefaultToolbarSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarSetDefaultToolbarSEL, _gPID)))

#define FRToolBarHideButtonInBrowser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarHideButtonInBrowserSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarHideButtonInBrowserSEL, _gPID)))

#define FRToolBarIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarIsVisibleSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarIsVisibleSEL, _gPID)))

#define FRToolBarIsDisable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarIsDisableSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarIsDisableSEL, _gPID)))

#define FRToolBarSetDisable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarSetDisableSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarSetDisableSEL, _gPID)))

#define FRToolBarDock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolBarDockSELPROTO)FRCOREROUTINE(FRToolBarSEL,FRToolBarDockSEL, _gPID)))

//*****************************
/* MessageBar HFT functions */
//*****************************

#define FRMessageBarCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarCreateSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarCreateSEL, _gPID)))

#define FRMessageBarDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarDestroySELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarDestroySEL, _gPID)))

#define FRMessageBarShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarShowSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarShowSEL, _gPID)))

#define FRMessageBarIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarIsVisibleSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarIsVisibleSEL, _gPID)))

#define FRMessageBarSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetTextSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetTextSEL, _gPID)))

#define FRMessageBarSetBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetBitmapSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetBitmapSEL, _gPID)))

#define FRMessageBarAddButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarAddButtonSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarAddButtonSEL, _gPID)))

#define FRMessageBarSetButtonAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetButtonAlignmentSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetButtonAlignmentSEL, _gPID)))

#define FRMessageBarSetButtonDropDownProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetButtonDropDownProcSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetButtonDropDownProcSEL, _gPID)))

#define FRMessageBarSetButtonExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetButtonExecuteProcSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetButtonExecuteProcSEL, _gPID)))

#define FRMessageBarSetButtonHelpText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetButtonHelpTextSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetButtonHelpTextSEL, _gPID)))

#define FRMessageBarEnableButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarEnableButtonSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarEnableButtonSEL, _gPID)))

#define FRMessageBarSetButtonPressed (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetButtonPressedSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetButtonPressedSEL, _gPID)))

#define FRMessageBarSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetClientDataSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetClientDataSEL, _gPID)))

#define FRMessageBarAddButtonImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarAddButtonImageSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarAddButtonImageSEL, _gPID)))

#define FRMessageBarGetButtonImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarGetButtonImageSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarGetButtonImageSEL, _gPID)))

#define FRMessageBarChangeButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarChangeButtonSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarChangeButtonSEL, _gPID)))

#define FRMessageBarIsButtonEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarIsButtonEnableSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarIsButtonEnableSEL, _gPID)))

#define FRMessageBarCountVisibleMessageBars (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarCountVisibleMessageBarsSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarCountVisibleMessageBarsSEL, _gPID)))

#define FRMessageBarGetVisibleMessageBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarGetVisibleMessageBarSELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarGetVisibleMessageBarSEL, _gPID)))

#define FRMessageBarSetBitmap2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarSetBitmap2SELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarSetBitmap2SEL, _gPID)))

#define FRMessageBarAddButton2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarAddButton2SELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarAddButton2SEL, _gPID)))

#define FRMessageBarAddButtonImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRMessageBarAddButtonImage2SELPROTO)FRCOREROUTINE(FRMessageBarSEL,FRMessageBarAddButtonImage2SEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//*****************************
/* TabBand HFT functions */
//*****************************

#define FRTabBandGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGetSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGetSEL, _gPID)))

#define FRTabBandGetTabWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGetTabWndSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGetTabWndSEL, _gPID)))

#define FRTabBandGetActiveTabWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGetActiveTabWndSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGetActiveTabWndSEL, _gPID)))

#define FRTabBandGetTabsNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGetTabsNumSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGetTabsNumSEL, _gPID)))

#define FRTabBandCloseTabWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandCloseTabWndSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandCloseTabWndSEL, _gPID)))

#define FRTabBandGetActiveTab (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGetActiveTabSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGetActiveTabSEL, _gPID)))

#define FRTabBandSetActiveTab (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandSetActiveTabSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandSetActiveTabSEL, _gPID)))

#define FRTabBandRegisterAddBtnHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandRegisterAddBtnHandlerSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandRegisterAddBtnHandlerSEL, _gPID)))

#define FRTabBandSetTabTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandSetTabTitleSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandSetTabTitleSEL, _gPID)))

#define FRTabBandSetTabIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandSetTabIconSELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandSetTabIconSEL, _gPID)))

#define FRTabBandGet2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTabBandGet2SELPROTO)FRCOREROUTINE(FRTabBandSEL,FRTabBandGet2SEL, _gPID)))

//----------_V5----------
//*****************************
/* RibbonBar HFT functions */
//*****************************

#define FRRibbonBarAddCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddCategorySELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddCategorySEL, _gPID)))

#define FRRibbonBarAddRibbonContextCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddRibbonContextCategorySELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddRibbonContextCategorySEL, _gPID)))

#define FRRibbonBarActivateContextCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarActivateContextCategorySELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarActivateContextCategorySEL, _gPID)))

#define FRRibbonBarShowContextCategories (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarShowContextCategoriesSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarShowContextCategoriesSEL, _gPID)))

#define FRRibbonBarGetCategoryCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarGetCategoryCountSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarGetCategoryCountSEL, _gPID)))

#define FRRibbonBarGetCategoryByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarGetCategoryByIndexSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarGetCategoryByIndexSEL, _gPID)))

#define FRRibbonBarGetCategoryByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarGetCategoryByNameSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarGetCategoryByNameSEL, _gPID)))

#define FRRibbonBarAddAsQAT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddAsQATSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddAsQATSEL, _gPID)))

#define FRRibbonBarAddToTabs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddToTabsSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddToTabsSEL, _gPID)))

#define FRRibbonBarAddHidden (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddHiddenSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddHiddenSEL, _gPID)))

#define FRRibbonBarAddBackStageViewItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddBackStageViewItemSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddBackStageViewItemSEL, _gPID)))

#define FRRibbonBarGetBackStageViewItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarGetBackStageViewItemSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarGetBackStageViewItemSEL, _gPID)))

#define FRRibbonBarSelectBackStageViewItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarSelectBackStageViewItemSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarSelectBackStageViewItemSEL, _gPID)))

#define FRRibbonBarAddButtonToAddPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddButtonToAddPlaceSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddButtonToAddPlaceSEL, _gPID)))

#define FRRibbonBarCloseFilePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarCloseFilePageSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarCloseFilePageSEL, _gPID)))

#define FRRibbonBarFindElementByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarFindElementByNameSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarFindElementByNameSEL, _gPID)))

#define FRRibbonBarIsBackStageViewActive (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarIsBackStageViewActiveSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarIsBackStageViewActiveSEL, _gPID)))

#define FRRibbonBarRecalcLayout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarRecalcLayoutSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarRecalcLayoutSEL, _gPID)))

#define FRRibbonBarGetActiveCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarGetActiveCategorySELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarGetActiveCategorySEL, _gPID)))

#define FRRibbonBarSetActiveCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarSetActiveCategorySELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarSetActiveCategorySEL, _gPID)))

#define FRRibbonBarSetActiveCategory2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarSetActiveCategory2SELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarSetActiveCategory2SEL, _gPID)))

#define FRRibbonBarIsMinimize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarIsMinimizeSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarIsMinimizeSEL, _gPID)))

#define FRRibbonBarAddCaptionButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddCaptionButtonSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddCaptionButtonSEL, _gPID)))

#define FRRibbonBarRegisterFilePageEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarRegisterFilePageEventHandlerSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarRegisterFilePageEventHandlerSEL, _gPID)))

#define FRRibbonBarDestroyFilePageEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarDestroyFilePageEventHandlerSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarDestroyFilePageEventHandlerSEL, _gPID)))

#define FRRibbonBarAddCategory2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarAddCategory2SELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarAddCategory2SEL, _gPID)))

#define FRRibbonBarShowButtonInAddPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarShowButtonInAddPlaceSELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarShowButtonInAddPlaceSEL, _gPID)))

#define FRRibbonBarUpdateCmdUI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBarUpdateCmdUISELPROTO)FRCOREROUTINE(FRRibbonBarSEL,FRRibbonBarUpdateCmdUISEL, _gPID)))

//*****************************
/* RibbonCategory HFT functions */
//*****************************

#define FRRibbonCategorySetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetTitleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetTitleSEL, _gPID)))

#define FRRibbonCategoryGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetTitleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetTitleSEL, _gPID)))

#define FRRibbonCategorySetContextTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetContextTitleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetContextTitleSEL, _gPID)))

#define FRRibbonCategoryGetContextTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetContextTitleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetContextTitleSEL, _gPID)))

#define FRRibbonCategorySetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetKeySELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetKeySEL, _gPID)))

#define FRRibbonCategoryGetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetKeySELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetKeySEL, _gPID)))

#define FRRibbonCategorySetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetVisibleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetVisibleSEL, _gPID)))

#define FRRibbonCategoryGetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetVisibleSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetVisibleSEL, _gPID)))

#define FRRibbonCategoryAddPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryAddPanelSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryAddPanelSEL, _gPID)))

#define FRRibbonCategoryGetPanelCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetPanelCountSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetPanelCountSEL, _gPID)))

#define FRRibbonCategoryGetPanelByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetPanelByIndexSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetPanelByIndexSEL, _gPID)))

#define FRRibbonCategoryGetPanelByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetPanelByNameSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetPanelByNameSEL, _gPID)))

#define FRRibbonCategoryGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetNameSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetNameSEL, _gPID)))

#define FRRibbonCategoryShowInQATCustomizeToolsDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryShowInQATCustomizeToolsDlgSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryShowInQATCustomizeToolsDlgSEL, _gPID)))

#define FRRibbonCategoryCopyPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryCopyPanelSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryCopyPanelSEL, _gPID)))

#define FRRibbonCategoryRecalcLayout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryRecalcLayoutSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryRecalcLayoutSEL, _gPID)))

#define FRRibbonCategoryAddPanel2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryAddPanel2SELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryAddPanel2SEL, _gPID)))

#define FRRibbonCategoryAddDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryAddDialogSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryAddDialogSEL, _gPID)))

#define FRRibbonCategoryPreTranslateMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryPreTranslateMessageSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryPreTranslateMessageSEL, _gPID)))

#define FRRibbonCategoryAddDialogToRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryAddDialogToRightSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryAddDialogToRightSEL, _gPID)))

#define FRRibbonCategoryGetPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetPosSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetPosSEL, _gPID)))

#define FRRibbonCategorySetPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetPosSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetPosSEL, _gPID)))

#define FRRibbonCategorySetHighlight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategorySetHighlightSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategorySetHighlightSEL, _gPID)))

#define FRRibbonCategoryGetHighlightColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCategoryGetHighlightColorSELPROTO)FRCOREROUTINE(FRRibbonCategorySEL,FRRibbonCategoryGetHighlightColorSEL, _gPID)))

//*****************************
/* RibbonPanel HFT functions */
//*****************************

#define FRRibbonPanelAddElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelAddElementSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelAddElementSEL, _gPID)))

#define FRRibbonPanelChangeElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelChangeElementTypeSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelChangeElementTypeSEL, _gPID)))

#define FRRibbonPanelAddElementToGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelAddElementToGroupSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelAddElementToGroupSEL, _gPID)))

#define FRRibbonPanelSetLaunchButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetLaunchButtonSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetLaunchButtonSEL, _gPID)))

#define FRRibbonPanelCopyElementToPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelCopyElementToPanelSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelCopyElementToPanelSEL, _gPID)))

#define FRRibbonPanelSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetTitleSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetTitleSEL, _gPID)))

#define FRRibbonPanelGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetTitleSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetTitleSEL, _gPID)))

#define FRRibbonPanelSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetVisibleSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetVisibleSEL, _gPID)))

#define FRRibbonPanelGetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetVisibleSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetVisibleSEL, _gPID)))

#define FRRibbonPanelGetElementByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetElementByNameSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetElementByNameSEL, _gPID)))

#define FRRibbonPanelGetElementCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetElementCountSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetElementCountSEL, _gPID)))

#define FRRibbonPanelGetElementByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetElementByIndexSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetElementByIndexSEL, _gPID)))

#define FRRibbonPanelSetPanelImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetPanelImageSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetPanelImageSEL, _gPID)))

#define FRRibbonPanelGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelGetNameSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelGetNameSEL, _gPID)))

#define FRRibbonPanelShowInQATCustomizeToolsDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelShowInQATCustomizeToolsDlgSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelShowInQATCustomizeToolsDlgSEL, _gPID)))

#define FRRibbonPanelSetImageInitProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetImageInitProcSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetImageInitProcSEL, _gPID)))

#define FRRibbonPanelSetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetKeySELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetKeySEL, _gPID)))

#define FRRibbonPanelAddDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelAddDialogSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelAddDialogSEL, _gPID)))

#define FRRibbonPanelPreTranslateMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelPreTranslateMessageSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelPreTranslateMessageSEL, _gPID)))

#define FRRibbonPanelEnableAddToCustomizeDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelEnableAddToCustomizeDlgSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelEnableAddToCustomizeDlgSEL, _gPID)))

#define FRRibbonPanelSetShowDefaultButtonAtLast (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPanelSetShowDefaultButtonAtLastSELPROTO)FRCOREROUTINE(FRRibbonPanelSEL,FRRibbonPanelSetShowDefaultButtonAtLastSEL, _gPID)))

//*****************************
/* RibbonElement HFT functions */
//*****************************

#define FRRibbonElementAddSubItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementAddSubItemSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementAddSubItemSEL, _gPID)))

#define FRRibbonElementSetExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetExecuteProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetExecuteProcSEL, _gPID)))

#define FRRibbonElementSetComputeEnabledProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetComputeEnabledProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetComputeEnabledProcSEL, _gPID)))

#define FRRibbonElementSetComputeMarkedProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetComputeMarkedProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetComputeMarkedProcSEL, _gPID)))

#define FRRibbonElementDoExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementDoExecuteProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementDoExecuteProcSEL, _gPID)))

#define FRRibbonElementIsEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementIsEnabledSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementIsEnabledSEL, _gPID)))

#define FRRibbonElementIsMarked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementIsMarkedSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementIsMarkedSEL, _gPID)))

#define FRRibbonElementSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetClientDataSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetClientDataSEL, _gPID)))

#define FRRibbonElementGetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetClientDataSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetClientDataSEL, _gPID)))

#define FRRibbonElementSetAccel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetAccelSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetAccelSEL, _gPID)))

#define FRRibbonElementGetAccel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetAccelSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetAccelSEL, _gPID)))

#define FRRibbonElementSetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetKeySELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetKeySEL, _gPID)))

#define FRRibbonElementGetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetKeySELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetKeySEL, _gPID)))

#define FRRibbonElementSetTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetTooltipSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetTooltipSEL, _gPID)))

#define FRRibbonElementGetTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetTooltipSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetTooltipSEL, _gPID)))

#define FRRibbonElementSetDescription (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetDescriptionSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetDescriptionSEL, _gPID)))

#define FRRibbonElementGetDescription (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetDescriptionSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetDescriptionSEL, _gPID)))

#define FRRibbonElementSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetTitleSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetTitleSEL, _gPID)))

#define FRRibbonElementGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetTitleSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetTitleSEL, _gPID)))

#define FRRibbonElementSetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetImageSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetImageSEL, _gPID)))

#define FRRibbonElementAddChangeImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementAddChangeImageSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementAddChangeImageSEL, _gPID)))

#define FRRibbonElementChangeImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementChangeImageSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementChangeImageSEL, _gPID)))

#define FRRibbonElementSetTooltipImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetTooltipImageSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetTooltipImageSEL, _gPID)))

#define FRRibbonElementSetTooltipImageII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetTooltipImageIISELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetTooltipImageIISEL, _gPID)))

#define FRRibbonElementSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetVisibleSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetVisibleSEL, _gPID)))

#define FRRibbonElementGetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetVisibleSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetVisibleSEL, _gPID)))

#define FRRibbonElementRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementRemoveSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementRemoveSEL, _gPID)))

#define FRRibbonElementGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetTypeSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetTypeSEL, _gPID)))

#define FRRibbonElementGetOriginalID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetOriginalIDSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetOriginalIDSEL, _gPID)))

#define FRRibbonElementGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetNameSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetNameSEL, _gPID)))

#define FRRibbonElementGetSubItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetSubItemCountSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetSubItemCountSEL, _gPID)))

#define FRRibbonElementFindSubElementByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementFindSubElementByIndexSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementFindSubElementByIndexSEL, _gPID)))

#define FRRibbonElementGetSubElementByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetSubElementByNameSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetSubElementByNameSEL, _gPID)))

#define FRRibbonElementCopyElementAsSubItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementCopyElementAsSubItemSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementCopyElementAsSubItemSEL, _gPID)))

#define FRRibbonElementGetCorrespondingButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetCorrespondingButtonSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetCorrespondingButtonSEL, _gPID)))

#define FRRibbonElementSetAsSubElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetAsSubElementSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetAsSubElementSEL, _gPID)))

#define FRRibbonElementSetImplicitLargeBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetImplicitLargeBitmapSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetImplicitLargeBitmapSEL, _gPID)))

#define FRRibbonElementSetShowMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetShowModeSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetShowModeSEL, _gPID)))

#define FRRibbonElementSetDropdownProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetDropdownProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetDropdownProcSEL, _gPID)))

#define FRRibbonElementGetClientRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetClientRectSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetClientRectSEL, _gPID)))

#define FRRibbonElementGetWindowRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetWindowRectSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetWindowRectSEL, _gPID)))

#define FRRibbonElementShowInQATCustomizeToolsDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementShowInQATCustomizeToolsDlgSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementShowInQATCustomizeToolsDlgSEL, _gPID)))

#define FRRibbonElementSetImageInitProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetImageInitProcSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetImageInitProcSEL, _gPID)))

#define FRRibbonElementGetButtonMapId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetButtonMapIdSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetButtonMapIdSEL, _gPID)))

#define FRRibbonElementSetBackstageViewTabElementKeepState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetBackstageViewTabElementKeepStateSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetBackstageViewTabElementKeepStateSEL, _gPID)))

#define FRRibbonElementIsBackstageViewTabElementKeepState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementIsBackstageViewTabElementKeepStateSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementIsBackstageViewTabElementKeepStateSEL, _gPID)))

#define FRRibbonElementSetSelectOnly (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementSetSelectOnlySELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementSetSelectOnlySEL, _gPID)))

#define FRRibbonElementGetCategoryName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetCategoryNameSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetCategoryNameSEL, _gPID)))

#define FRRibbonElementGetPanelName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonElementGetPanelNameSELPROTO)FRCOREROUTINE(FRRibbonElementSEL,FRRibbonElementGetPanelNameSEL, _gPID)))

//*****************************
/* RibbonButton HFT functions */
//*****************************

#define FRRibbonButtonGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonButtonGetElementSELPROTO)FRCOREROUTINE(FRRibbonButtonSEL,FRRibbonButtonGetElementSEL, _gPID)))

#define FRRibbonButtonSetDefaultCommand (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonButtonSetDefaultCommandSELPROTO)FRCOREROUTINE(FRRibbonButtonSEL,FRRibbonButtonSetDefaultCommandSEL, _gPID)))

#define FRRibbonButtonSetAlwaysShowDescription (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonButtonSetAlwaysShowDescriptionSELPROTO)FRCOREROUTINE(FRRibbonButtonSEL,FRRibbonButtonSetAlwaysShowDescriptionSEL, _gPID)))

#define FRRibbonButtonSetButtonPopupWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonButtonSetButtonPopupWndSELPROTO)FRCOREROUTINE(FRRibbonButtonSEL,FRRibbonButtonSetButtonPopupWndSEL, _gPID)))

#define FRRibbonButtonCloseButtonPopupWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonButtonCloseButtonPopupWndSELPROTO)FRCOREROUTINE(FRRibbonButtonSEL,FRRibbonButtonCloseButtonPopupWndSEL, _gPID)))

//*****************************
/* RibbonEdit HFT functions */
//*****************************

#define FRRibbonEditGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditGetElementSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditGetElementSEL, _gPID)))

#define FRRibbonEditGetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditGetTextSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditGetTextSEL, _gPID)))

#define FRRibbonEditSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditSetTextSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditSetTextSEL, _gPID)))

#define FRRibbonEditEnableSpinButtons (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditEnableSpinButtonsSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditEnableSpinButtonsSEL, _gPID)))

#define FRRibbonEditSetSearchMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditSetSearchModeSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditSetSearchModeSEL, _gPID)))

#define FRRibbonEditSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditSetWidthSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditSetWidthSEL, _gPID)))

#define FRRibbonEditGetHWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditGetHWndSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditGetHWndSEL, _gPID)))

#define FRRibbonEditSetTextFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditSetTextFlagSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditSetTextFlagSEL, _gPID)))

#define FRRibbonEditSetFocus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonEditSetFocusSELPROTO)FRCOREROUTINE(FRRibbonEditSEL,FRRibbonEditSetFocusSEL, _gPID)))

//*****************************
/* RibbonLabel HFT functions */
//*****************************

#define FRRibbonLabelGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonLabelGetElementSELPROTO)FRCOREROUTINE(FRRibbonLabelSEL,FRRibbonLabelGetElementSEL, _gPID)))

//*****************************
/* RibbonCheckBox HFT functions */
//*****************************

#define FRRibbonCheckBoxGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCheckBoxGetElementSELPROTO)FRCOREROUTINE(FRRibbonCheckBoxSEL,FRRibbonCheckBoxGetElementSEL, _gPID)))

#define FRRibbonCheckBoxIsChecked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCheckBoxIsCheckedSELPROTO)FRCOREROUTINE(FRRibbonCheckBoxSEL,FRRibbonCheckBoxIsCheckedSEL, _gPID)))

#define FRRibbonCheckBoxSetCheck (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonCheckBoxSetCheckSELPROTO)FRCOREROUTINE(FRRibbonCheckBoxSEL,FRRibbonCheckBoxSetCheckSEL, _gPID)))

//*****************************
/* RibbonRadioButton HFT functions */
//*****************************

#define FRRibbonRadioButtonGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonRadioButtonGetElementSELPROTO)FRCOREROUTINE(FRRibbonRadioButtonSEL,FRRibbonRadioButtonGetElementSEL, _gPID)))

#define FRRibbonRadioButtonIsChecked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonRadioButtonIsCheckedSELPROTO)FRCOREROUTINE(FRRibbonRadioButtonSEL,FRRibbonRadioButtonIsCheckedSEL, _gPID)))

#define FRRibbonRadioButtonSetCheck (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonRadioButtonSetCheckSELPROTO)FRCOREROUTINE(FRRibbonRadioButtonSEL,FRRibbonRadioButtonSetCheckSEL, _gPID)))

//*****************************
/* RibbonComboBox HFT functions */
//*****************************

#define FRRibbonComboBoxGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetElementSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetElementSEL, _gPID)))

#define FRRibbonComboBoxAddItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxAddItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxAddItemSEL, _gPID)))

#define FRRibbonComboBoxInsertItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxInsertItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxInsertItemSEL, _gPID)))

#define FRRibbonComboBoxGetItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetItemCountSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetItemCountSEL, _gPID)))

#define FRRibbonComboBoxGetItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetItemSEL, _gPID)))

#define FRRibbonComboBoxGetCurSel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetCurSelSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetCurSelSEL, _gPID)))

#define FRRibbonComboBoxRemoveAllItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxRemoveAllItemsSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxRemoveAllItemsSEL, _gPID)))

#define FRRibbonComboBoxSelectItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSelectItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSelectItemSEL, _gPID)))

#define FRRibbonComboBoxDeleteItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxDeleteItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxDeleteItemSEL, _gPID)))

#define FRRibbonComboBoxFindItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxFindItemSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxFindItemSEL, _gPID)))

#define FRRibbonComboBoxSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSetWidthSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSetWidthSEL, _gPID)))

#define FRRibbonComboBoxSetEditBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSetEditBoxSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSetEditBoxSEL, _gPID)))

#define FRRibbonComboBoxGetEditText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetEditTextSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetEditTextSEL, _gPID)))

#define FRRibbonComboBoxSetEditText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSetEditTextSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSetEditTextSEL, _gPID)))

#define FRRibbonComboBoxEnableDropDownListResize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxEnableDropDownListResizeSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxEnableDropDownListResizeSEL, _gPID)))

#define FRRibbonComboBoxGetHWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxGetHWndSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxGetHWndSEL, _gPID)))

#define FRRibbonComboBoxSetTextFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSetTextFlagSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSetTextFlagSEL, _gPID)))

#define FRRibbonComboBoxSetFocus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonComboBoxSetFocusSELPROTO)FRCOREROUTINE(FRRibbonComboBoxSEL,FRRibbonComboBoxSetFocusSEL, _gPID)))

//*****************************
/* RibbonFontComboBox HFT functions */
//*****************************

#define FRRibbonFontComboBoxGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetElementSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetElementSEL, _gPID)))

#define FRRibbonFontComboBoxGetItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetItemSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetItemSEL, _gPID)))

#define FRRibbonFontComboBoxGetCurSel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetCurSelSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetCurSelSEL, _gPID)))

#define FRRibbonFontComboBoxSelectItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSelectItemSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSelectItemSEL, _gPID)))

#define FRRibbonFontComboBoxSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSetWidthSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSetWidthSEL, _gPID)))

#define FRRibbonFontComboBoxSetEditBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSetEditBoxSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSetEditBoxSEL, _gPID)))

#define FRRibbonFontComboBoxGetEditText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetEditTextSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetEditTextSEL, _gPID)))

#define FRRibbonFontComboBoxSetEditText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSetEditTextSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSetEditTextSEL, _gPID)))

#define FRRibbonFontComboBoxEnableDropDownListResize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxEnableDropDownListResizeSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxEnableDropDownListResizeSEL, _gPID)))

#define FRRibbonFontComboBoxGetHWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetHWndSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetHWndSEL, _gPID)))

#define FRRibbonFontComboBoxAddFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxAddFontSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxAddFontSEL, _gPID)))

#define FRRibbonFontComboBoxInsertFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxInsertFontSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxInsertFontSEL, _gPID)))

#define FRRibbonFontComboBoxGetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetFontIndexSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetFontIndexSEL, _gPID)))

#define FRRibbonFontComboBoxGetFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetFontNameSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetFontNameSEL, _gPID)))

#define FRRibbonFontComboBoxGetScriptName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetScriptNameSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetScriptNameSEL, _gPID)))

#define FRRibbonFontComboBoxSelectItem2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSelectItem2SELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSelectItem2SEL, _gPID)))

#define FRRibbonFontComboBoxRemoveFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxRemoveFontSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxRemoveFontSEL, _gPID)))

#define FRRibbonFontComboBoxRemoveFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxRemoveFont2SELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxRemoveFont2SEL, _gPID)))

#define FRRibbonFontComboBoxGetFontCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxGetFontCountSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxGetFontCountSEL, _gPID)))

#define FRRibbonFontComboBoxSetFocus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonFontComboBoxSetFocusSELPROTO)FRCOREROUTINE(FRRibbonFontComboBoxSEL,FRRibbonFontComboBoxSetFocusSEL, _gPID)))

//*****************************
/* RibbonPaletteButton HFT functions */
//*****************************

#define FRRibbonPaletteButtonGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetElementSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetElementSEL, _gPID)))

#define FRRibbonPaletteButtonAddGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonAddGroupSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonAddGroupSEL, _gPID)))

#define FRRibbonPaletteButtonSetGroupTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetGroupTitleSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetGroupTitleSEL, _gPID)))

#define FRRibbonPaletteButtonSetItemToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetItemToolTipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetItemToolTipSEL, _gPID)))

#define FRRibbonPaletteButtonSetScrollButtonTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetScrollButtonTooltipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetScrollButtonTooltipSEL, _gPID)))

#define FRRibbonPaletteButtonSetMenuButtonTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetMenuButtonTooltipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetMenuButtonTooltipSEL, _gPID)))

#define FRRibbonPaletteButtonGetGroupTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetGroupTitleSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetGroupTitleSEL, _gPID)))

#define FRRibbonPaletteButtonGetItemToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetItemToolTipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetItemToolTipSEL, _gPID)))

#define FRRibbonPaletteButtonGetScrollButtonTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetScrollButtonTooltipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetScrollButtonTooltipSEL, _gPID)))

#define FRRibbonPaletteButtonGetMenuButtonTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetMenuButtonTooltipSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetMenuButtonTooltipSEL, _gPID)))

#define FRRibbonPaletteButtonGetGroupItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetGroupItemCountSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetGroupItemCountSEL, _gPID)))

#define FRRibbonPaletteButtonGetGroupCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetGroupCountSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetGroupCountSEL, _gPID)))

#define FRRibbonPaletteButtonIsGroupNameExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonIsGroupNameExistSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonIsGroupNameExistSEL, _gPID)))

#define FRRibbonPaletteButtonSetButtonMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetButtonModeSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetButtonModeSEL, _gPID)))

#define FRRibbonPaletteButtonSetIconsInRow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetIconsInRowSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetIconsInRowSEL, _gPID)))

#define FRRibbonPaletteButtonEnableResize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonEnableResizeSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonEnableResizeSEL, _gPID)))

#define FRRibbonPaletteButtonGetSelectedItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetSelectedItemSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetSelectedItemSEL, _gPID)))

#define FRRibbonPaletteButtonInsertItemToGroupLast (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonInsertItemToGroupLastSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonInsertItemToGroupLastSEL, _gPID)))

#define FRRibbonPaletteButtonSetDefaultGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetDefaultGroupSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetDefaultGroupSEL, _gPID)))

#define FRRibbonPaletteButtonRemoveGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonRemoveGroupSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonRemoveGroupSEL, _gPID)))

#define FRRibbonPaletteButtonRemoveItemFromGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonRemoveItemFromGroupSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonRemoveItemFromGroupSEL, _gPID)))

#define FRRibbonPaletteButtonSetItemData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetItemDataSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetItemDataSEL, _gPID)))

#define FRRibbonPaletteButtonGetItemData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetItemDataSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetItemDataSEL, _gPID)))

#define FRRibbonPaletteButtonSetGroupItemEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetGroupItemEnableSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetGroupItemEnableSEL, _gPID)))

#define FRRibbonPaletteButtonSetSelectedItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetSelectedItemSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetSelectedItemSEL, _gPID)))

#define FRRibbonPaletteButtonSetRows (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetRowsSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetRowsSEL, _gPID)))

#define FRRibbonPaletteButtonRemoveAllGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonRemoveAllGroupSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonRemoveAllGroupSEL, _gPID)))

#define FRRibbonPaletteButtonSetInitSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetInitSizeSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetInitSizeSEL, _gPID)))

#define FRRibbonPaletteButtonGetItemInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonGetItemInfoSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonGetItemInfoSEL, _gPID)))

#define FRRibbonPaletteButtonSetHighlightItemProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetHighlightItemProcSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetHighlightItemProcSEL, _gPID)))

#define FRRibbonPaletteButtonSetItemAccNameTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonPaletteButtonSetItemAccNameTitleSELPROTO)FRCOREROUTINE(FRRibbonPaletteButtonSEL,FRRibbonPaletteButtonSetItemAccNameTitleSEL, _gPID)))

//*****************************
/* RibbonColorButton HFT functions */
//*****************************

#define FRRibbonColorButtonGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetElementSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetElementSEL, _gPID)))

#define FRRibbonColorButtonEnableAutomaticButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonEnableAutomaticButtonSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonEnableAutomaticButtonSEL, _gPID)))

#define FRRibbonColorButtonSetAutomaticButtonLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetAutomaticButtonLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetAutomaticButtonLabelSEL, _gPID)))

#define FRRibbonColorButtonSetAutomaticButtonToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetAutomaticButtonToolTipSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetAutomaticButtonToolTipSEL, _gPID)))

#define FRRibbonColorButtonEnableOtherButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonEnableOtherButtonSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonEnableOtherButtonSEL, _gPID)))

#define FRRibbonColorButtonSetOtherButtonLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetOtherButtonLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetOtherButtonLabelSEL, _gPID)))

#define FRRibbonColorButtonSetOtherButtonToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetOtherButtonToolTipSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetOtherButtonToolTipSEL, _gPID)))

#define FRRibbonColorButtonGetAutomaticButtonLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetAutomaticButtonLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetAutomaticButtonLabelSEL, _gPID)))

#define FRRibbonColorButtonGetAutomaticButtonToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetAutomaticButtonToolTipSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetAutomaticButtonToolTipSEL, _gPID)))

#define FRRibbonColorButtonGetOtherButtonLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetOtherButtonLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetOtherButtonLabelSEL, _gPID)))

#define FRRibbonColorButtonGetOtherButtonToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetOtherButtonToolTipSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetOtherButtonToolTipSEL, _gPID)))

#define FRRibbonColorButtonAddColorsGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonAddColorsGroupSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonAddColorsGroupSEL, _gPID)))

#define FRRibbonColorButtonAddStandardColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonAddStandardColorSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonAddStandardColorSEL, _gPID)))

#define FRRibbonColorButtonAddAdditionalColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonAddAdditionalColorSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonAddAdditionalColorSEL, _gPID)))

#define FRRibbonColorButtonAddMainColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonAddMainColorSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonAddMainColorSEL, _gPID)))

#define FRRibbonColorButtonSetGroupLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetGroupLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetGroupLabelSEL, _gPID)))

#define FRRibbonColorButtonGetGroupLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetGroupLabelSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetGroupLabelSEL, _gPID)))

#define FRRibbonColorButtonSetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetColorSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetColorSEL, _gPID)))

#define FRRibbonColorButtonGetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonGetColorSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonGetColorSEL, _gPID)))

#define FRRibbonColorButtonSetColumns (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetColumnsSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetColumnsSEL, _gPID)))

#define FRRibbonColorButtonSetColorBoxSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetColorBoxSizeSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetColorBoxSizeSEL, _gPID)))

#define FRRibbonColorButtonSetDefaultCommand (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonSetDefaultCommandSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonSetDefaultCommandSEL, _gPID)))

#define FRRibbonColorButtonIsAutomaticButtonClick (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonColorButtonIsAutomaticButtonClickSELPROTO)FRCOREROUTINE(FRRibbonColorButtonSEL,FRRibbonColorButtonIsAutomaticButtonClickSEL, _gPID)))

//*****************************
/* RibbonSlider HFT functions */
//*****************************

#define FRRibbonSliderGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderGetElementSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderGetElementSEL, _gPID)))

#define FRRibbonSliderSetZoomButtons (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderSetZoomButtonsSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderSetZoomButtonsSEL, _gPID)))

#define FRRibbonSliderSetRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderSetRangeSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderSetRangeSEL, _gPID)))

#define FRRibbonSliderGetRangeMin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderGetRangeMinSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderGetRangeMinSEL, _gPID)))

#define FRRibbonSliderGetRangeMax (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderGetRangeMaxSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderGetRangeMaxSEL, _gPID)))

#define FRRibbonSliderSetPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderSetPosSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderSetPosSEL, _gPID)))

#define FRRibbonSliderGetPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderGetPosSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderGetPosSEL, _gPID)))

#define FRRibbonSliderSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderSetWidthSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderSetWidthSEL, _gPID)))

#define FRRibbonSliderSetStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderSetStyleSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderSetStyleSEL, _gPID)))

#define FRRibbonSliderGetMouseStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonSliderGetMouseStatusSELPROTO)FRCOREROUTINE(FRRibbonSliderSEL,FRRibbonSliderGetMouseStatusSEL, _gPID)))

//*****************************
/* RibbonListButton HFT functions */
//*****************************

#define FRRibbonListButtonGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetElementSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetElementSEL, _gPID)))

#define FRRibbonListButtonAddGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonAddGroupSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonAddGroupSEL, _gPID)))

#define FRRibbonListButtonGetGroupCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetGroupCountSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetGroupCountSEL, _gPID)))

#define FRRibbonListButtonIsGroupNameExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonIsGroupNameExistSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonIsGroupNameExistSEL, _gPID)))

#define FRRibbonListButtonEnableResize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonEnableResizeSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonEnableResizeSEL, _gPID)))

#define FRRibbonListButtonSetGroupTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetGroupTitleSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetGroupTitleSEL, _gPID)))

#define FRRibbonListButtonSetItemToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetItemToolTipSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetItemToolTipSEL, _gPID)))

#define FRRibbonListButtonSetItemTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetItemTitleSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetItemTitleSEL, _gPID)))

#define FRRibbonListButtonGetGroupTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetGroupTitleSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetGroupTitleSEL, _gPID)))

#define FRRibbonListButtonGetItemToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetItemToolTipSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetItemToolTipSEL, _gPID)))

#define FRRibbonListButtonGetItemTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetItemTitleSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetItemTitleSEL, _gPID)))

#define FRRibbonListButtonGetItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetItemCountSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetItemCountSEL, _gPID)))

#define FRRibbonListButtonGetSelectedItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonGetSelectedItemSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonGetSelectedItemSEL, _gPID)))

#define FRRibbonListButtonSetAlignedSide (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetAlignedSideSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetAlignedSideSEL, _gPID)))

#define FRRibbonListButtonSetIconsInRow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetIconsInRowSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetIconsInRowSEL, _gPID)))

#define FRRibbonListButtonSetSelectedItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonListButtonSetSelectedItemSELPROTO)FRCOREROUTINE(FRRibbonListButtonSEL,FRRibbonListButtonSetSelectedItemSEL, _gPID)))

//*****************************
/* RibbonBackStageViewItem HFT functions */
//*****************************

#define FRRibbonBackStageViewItemSetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetTitleSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetTitleSEL, _gPID)))

#define FRRibbonBackStageViewItemAddDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemAddDialogSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemAddDialogSEL, _gPID)))

#define FRRibbonBackStageViewItemAddPropertySheetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemAddPropertySheetPageSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemAddPropertySheetPageSEL, _gPID)))

#define FRRibbonBackStageViewItemRemovePropertySheetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemRemovePropertySheetPageSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemRemovePropertySheetPageSEL, _gPID)))

#define FRRibbonBackStageViewItemAddPropertySheetGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemAddPropertySheetGroupSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemAddPropertySheetGroupSEL, _gPID)))

#define FRRibbonBackStageViewItemSetGroupTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetGroupTitleSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetGroupTitleSEL, _gPID)))

#define FRRibbonBackStageViewItemSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetVisibleSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetVisibleSEL, _gPID)))

#define FRRibbonBackStageViewItemSetDisable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetDisableSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetDisableSEL, _gPID)))

#define FRRibbonBackStageViewItemAddAnchor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemAddAnchorSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemAddAnchorSEL, _gPID)))

#define FRRibbonBackStageViewItemModifiedToRibbonStyleButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemModifiedToRibbonStyleButtonSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemModifiedToRibbonStyleButtonSEL, _gPID)))

#define FRRibbonBackStageViewItemSetPropertyActivePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetPropertyActivePageSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetPropertyActivePageSEL, _gPID)))

#define FRRibbonBackStageViewItemSetPageTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetPageTitleSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetPageTitleSEL, _gPID)))

#define FRRibbonBackStageViewItemIsPropertySheetPageExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemIsPropertySheetPageExistSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemIsPropertySheetPageExistSEL, _gPID)))

#define FRRibbonBackStageViewItemIsDialogExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemIsDialogExistSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemIsDialogExistSEL, _gPID)))

#define FRRibbonBackStageViewItemGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemGetElementSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemGetElementSEL, _gPID)))

#define FRRibbonBackStageViewItemEnablePropertyPageRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemEnablePropertyPageRemoveSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemEnablePropertyPageRemoveSEL, _gPID)))

#define FRRibbonBackStageViewItemRedrawPropertySheet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemRedrawPropertySheetSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemRedrawPropertySheetSEL, _gPID)))

#define FRRibbonBackStageViewItemSetDlgItemMaxSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetDlgItemMaxSizeSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetDlgItemMaxSizeSEL, _gPID)))

#define FRRibbonBackStageViewItemSetPageSelectProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemSetPageSelectProcSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemSetPageSelectProcSEL, _gPID)))

#define FRRibbonBackStageViewItemBCGPreTranslateMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonBackStageViewItemBCGPreTranslateMessageSELPROTO)FRCOREROUTINE(FRRibbonBackStageViewItemSEL,FRRibbonBackStageViewItemBCGPreTranslateMessageSEL, _gPID)))

//*****************************
/* RibbonStyleButton HFT functions */
//*****************************

#define FRRibbonStyleButtonSetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetImageSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetImageSEL, _gPID)))

#define FRRibbonStyleButtonSetAlignStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetAlignStyleSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetAlignStyleSEL, _gPID)))

#define FRRibbonStyleButtonSetImageSide (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetImageSideSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetImageSideSEL, _gPID)))

#define FRRibbonStyleButtonSetFlatStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetFlatStyleSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetFlatStyleSEL, _gPID)))

#define FRRibbonStyleButtonSetVertMargin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetVertMarginSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetVertMarginSEL, _gPID)))

#define FRRibbonStyleButtonGetMFCButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonGetMFCButtonSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonGetMFCButtonSEL, _gPID)))

#define FRRibbonStyleButtonRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonReleaseSELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonReleaseSEL, _gPID)))

#define FRRibbonStyleButtonSetImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleButtonSetImage2SELPROTO)FRCOREROUTINE(FRRibbonStyleButtonSEL,FRRibbonStyleButtonSetImage2SEL, _gPID)))

//*****************************
/* RibbonStyleListBox HFT functions */
//*****************************

#define FRRibbonStyleListBoxAddImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxAddImageSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxAddImageSEL, _gPID)))

#define FRRibbonStyleListBoxAddString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxAddStringSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxAddStringSEL, _gPID)))

#define FRRibbonStyleListBoxAddCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxAddCaptionSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxAddCaptionSEL, _gPID)))

#define FRRibbonStyleListBoxDeleteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxDeleteStringSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxDeleteStringSEL, _gPID)))

#define FRRibbonStyleListBoxInsertString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxInsertStringSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxInsertStringSEL, _gPID)))

#define FRRibbonStyleListBoxGetItemData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxGetItemDataSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxGetItemDataSEL, _gPID)))

#define FRRibbonStyleListBoxSetItemData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxSetItemDataSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxSetItemDataSEL, _gPID)))

#define FRRibbonStyleListBoxGetMFCListBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxGetMFCListBoxSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxGetMFCListBoxSEL, _gPID)))

#define FRRibbonStyleListBoxRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxReleaseSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxReleaseSEL, _gPID)))

#define FRRibbonStyleListBoxAddImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxAddImage2SELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxAddImage2SEL, _gPID)))

#define FRRibbonStyleListBoxEnablePins (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxEnablePinsSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxEnablePinsSEL, _gPID)))

#define FRRibbonStyleListBoxHasPins (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxHasPinsSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxHasPinsSEL, _gPID)))

#define FRRibbonStyleListBoxSetItemPinned (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxSetItemPinnedSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxSetItemPinnedSEL, _gPID)))

#define FRRibbonStyleListBoxGetItemPinnedState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxGetItemPinnedStateSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxGetItemPinnedStateSEL, _gPID)))

#define FRRibbonStyleListBoxIsSeparatorItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxIsSeparatorItemSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxIsSeparatorItemSEL, _gPID)))

#define FRRibbonStyleListBoxRedrawList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxRedrawListSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxRedrawListSEL, _gPID)))

#define FRRibbonStyleListBoxSetClickItemProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxSetClickItemProcSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxSetClickItemProcSEL, _gPID)))

#define FRRibbonStyleListBoxSetClickPinProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxSetClickPinProcSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxSetClickPinProcSEL, _gPID)))

#define FRRibbonStyleListBoxSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxSetClientDataSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxSetClientDataSEL, _gPID)))

#define FRRibbonStyleListBoxClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleListBoxClearSELPROTO)FRCOREROUTINE(FRRibbonStyleListBoxSEL,FRRibbonStyleListBoxClearSEL, _gPID)))

//*****************************
/* RibbonStyleStatic HFT functions */
//*****************************

#define FRRibbonStyleStaticSetImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetImageSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetImageSEL, _gPID)))

#define FRRibbonStyleStaticGetMFCStatic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticGetMFCStaticSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticGetMFCStaticSEL, _gPID)))

#define FRRibbonStyleStaticSetFontStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetFontStyleSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetFontStyleSEL, _gPID)))

#define FRRibbonStyleStaticSetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetTextColorSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetTextColorSEL, _gPID)))

#define FRRibbonStyleStaticSetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetBackgroundColorSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetBackgroundColorSEL, _gPID)))

#define FRRibbonStyleStaticSetTextDrawFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetTextDrawFormatSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetTextDrawFormatSEL, _gPID)))

#define FRRibbonStyleStaticRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticReleaseSELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticReleaseSEL, _gPID)))

#define FRRibbonStyleStaticSetImage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRRibbonStyleStaticSetImage2SELPROTO)FRCOREROUTINE(FRRibbonStyleStaticSEL,FRRibbonStyleStaticSetImage2SEL, _gPID)))

//*****************************
/* FormatTools HFT functions */
//*****************************

#define FRFormatToolsGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetSEL, _gPID)))

#define FRFormatToolsSetEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetEventSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetEventSEL, _gPID)))

#define FRFormatToolsSetFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFontNameSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFontNameSEL, _gPID)))

#define FRFormatToolsSetFontNameFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFontNameFirstSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFontNameFirstSEL, _gPID)))

#define FRFormatToolsSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFontSizeSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFontSizeSEL, _gPID)))

#define FRFormatToolsSetFontSizeFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFontSizeFirstSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFontSizeFirstSEL, _gPID)))

#define FRFormatToolsSetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetTextColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetTextColorSEL, _gPID)))

#define FRFormatToolsSetLineColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetLineColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetLineColorSEL, _gPID)))

#define FRFormatToolsSetFillColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFillColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFillColorSEL, _gPID)))

#define FRFormatToolsSetBold (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetBoldSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetBoldSEL, _gPID)))

#define FRFormatToolsSetItalic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetItalicSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetItalicSEL, _gPID)))

#define FRFormatToolsSetAlign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetAlignSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetAlignSEL, _gPID)))

#define FRFormatToolsSetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetCharSpaceSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetCharSpaceSEL, _gPID)))

#define FRFormatToolsSetCharHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetCharHorzScaleSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetCharHorzScaleSEL, _gPID)))

#define FRFormatToolsSetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetLineLeadingSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetLineLeadingSEL, _gPID)))

#define FRFormatToolsSetSuperScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetSuperScriptSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetSuperScriptSEL, _gPID)))

#define FRFormatToolsSetSubScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetSubScriptSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetSubScriptSEL, _gPID)))

#define FRFormatToolsSetUnderline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetUnderlineSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetUnderlineSEL, _gPID)))

#define FRFormatToolsSetCross (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetCrossSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetCrossSEL, _gPID)))

#define FRFormatToolsSetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetWordSpaceSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetWordSpaceSEL, _gPID)))

#define FRFormatToolsGetFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetFontNameSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetFontNameSEL, _gPID)))

#define FRFormatToolsGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetFontSizeSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetFontSizeSEL, _gPID)))

#define FRFormatToolsGetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetTextColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetTextColorSEL, _gPID)))

#define FRFormatToolsGetLineColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetLineColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetLineColorSEL, _gPID)))

#define FRFormatToolsGetFillColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetFillColorSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetFillColorSEL, _gPID)))

#define FRFormatToolsGetAlign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetAlignSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetAlignSEL, _gPID)))

#define FRFormatToolsGetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetCharSpaceSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetCharSpaceSEL, _gPID)))

#define FRFormatToolsGetCharHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetCharHorzScaleSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetCharHorzScaleSEL, _gPID)))

#define FRFormatToolsGetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetLineLeadingSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetLineLeadingSEL, _gPID)))

#define FRFormatToolsGetUnderline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetUnderlineSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetUnderlineSEL, _gPID)))

#define FRFormatToolsGetCross (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetCrossSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetCrossSEL, _gPID)))

#define FRFormatToolsGetSuperScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetSuperScriptSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetSuperScriptSEL, _gPID)))

#define FRFormatToolsGetSubScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetSubScriptSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetSubScriptSEL, _gPID)))

#define FRFormatToolsIsBold (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsBoldSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsBoldSEL, _gPID)))

#define FRFormatToolsIsItalic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsItalicSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsItalicSEL, _gPID)))

#define FRFormatToolsGetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetWordSpaceSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetWordSpaceSEL, _gPID)))

#define FRFormatToolsIsVisibled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsVisibledSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsVisibledSEL, _gPID)))

#define FRFormatToolsShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsShowSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsShowSEL, _gPID)))

#define FRFormatToolsIsEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsEnabledSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsEnabledSEL, _gPID)))

#define FRFormatToolsEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsEnableSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsEnableSEL, _gPID)))

#define FRFormatToolsIsButtonVisibled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsButtonVisibledSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsButtonVisibledSEL, _gPID)))

#define FRFormatToolsHideButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsHideButtonSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsHideButtonSEL, _gPID)))

#define FRFormatToolsIsButtonEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsIsButtonEnabledSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsIsButtonEnabledSEL, _gPID)))

#define FRFormatToolsEnableButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsEnableButtonSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsEnableButtonSEL, _gPID)))

#define FRFormatToolsSetOwnerFontNameArr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetOwnerFontNameArrSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetOwnerFontNameArrSEL, _gPID)))

#define FRFormatToolsCleanOwnerFontNameArr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsCleanOwnerFontNameArrSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsCleanOwnerFontNameArrSEL, _gPID)))

#define FRFormatToolsFindFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsFindFontNameSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsFindFontNameSEL, _gPID)))

#define FRFormatToolsCountFontList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsCountFontListSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsCountFontListSEL, _gPID)))

#define FRFormatToolsGetFontListItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetFontListItemSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetFontListItemSEL, _gPID)))

#define FRFormatToolsSetFormatContextTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetFormatContextTitleSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetFormatContextTitleSEL, _gPID)))

#define FRFormatToolsActivateFormatCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsActivateFormatCategorySELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsActivateFormatCategorySEL, _gPID)))

#define FRFormatToolsSetWritingDirection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsSetWritingDirectionSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsSetWritingDirectionSEL, _gPID)))

#define FRFormatToolsGetWritingDirection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetWritingDirectionSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetWritingDirectionSEL, _gPID)))

#define FRFormatToolsGetFontFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsGetFontFaceNameSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsGetFontFaceNameSEL, _gPID)))

#define FRFormatToolsReleaseEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFormatToolsReleaseEventSELPROTO)FRCOREROUTINE(FRFormatToolsSEL,FRFormatToolsReleaseEventSEL, _gPID)))

//*****************************
/* PropertyTools HFT functions */
//*****************************

#define FRPropertyToolsGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsGetSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsGetSEL, _gPID)))

#define FRPropertyToolsSetEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsSetEventSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsSetEventSEL, _gPID)))

#define FRPropertyToolsSetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsSetColorSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsSetColorSEL, _gPID)))

#define FRPropertyToolsSetOpacity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsSetOpacitySELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsSetOpacitySEL, _gPID)))

#define FRPropertyToolsIsVisibled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsIsVisibledSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsIsVisibledSEL, _gPID)))

#define FRPropertyToolsShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsShowSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsShowSEL, _gPID)))

#define FRPropertyToolsIsEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsIsEnabledSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsIsEnabledSEL, _gPID)))

#define FRPropertyToolsEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsEnableSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsEnableSEL, _gPID)))

#define FRPropertyToolsReleaseEvent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPropertyToolsReleaseEventSELPROTO)FRCOREROUTINE(FRPropertyToolsSEL,FRPropertyToolsReleaseEventSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//*****************************
/* FuncBtn HFT functions */
//*****************************

#define FRFuncBtnCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnCreateSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnCreateSEL, _gPID)))

#define FRFuncBtnAddToPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnAddToPanelSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnAddToPanelSEL, _gPID)))

#define FRFuncBtnGetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnGetClientDataSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnGetClientDataSEL, _gPID)))

#define FRFuncBtnSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetClientDataSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetClientDataSEL, _gPID)))

#define FRFuncBtnGetToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnGetToolTipSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnGetToolTipSEL, _gPID)))

#define FRFuncBtnSetToolTip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetToolTipSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetToolTipSEL, _gPID)))

#define FRFuncBtnSetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetNameSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetNameSEL, _gPID)))

#define FRFuncBtnGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnGetNameSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnGetNameSEL, _gPID)))

#define FRFuncBtnSetExecuteProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetExecuteProcSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetExecuteProcSEL, _gPID)))

#define FRFuncBtnSetComputeEnabledProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetComputeEnabledProcSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetComputeEnabledProcSEL, _gPID)))

#define FRFuncBtnSetComputeMarkedProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnSetComputeMarkedProcSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnSetComputeMarkedProcSEL, _gPID)))

#define FRFuncBtnUpdateImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnUpdateImageSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnUpdateImageSEL, _gPID)))

#define FRFuncBtnGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnGetRectSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnGetRectSEL, _gPID)))

#define FRFuncBtnAddToTabBand (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRFuncBtnAddToTabBandSELPROTO)FRCOREROUTINE(FRFuncBtnSEL,FRFuncBtnAddToTabBandSEL, _gPID)))

//*****************************
/* StatusBar HFT functions */
//*****************************

#define FRStatusBarAddWndEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarAddWndExSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarAddWndExSEL, _gPID)))

#define FRStatusBarReset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarResetSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarResetSEL, _gPID)))

#define FRStatusBarSetZoomSliderRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSetZoomSliderRangeSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSetZoomSliderRangeSEL, _gPID)))

#define FRStatusBarSetZoomSliderPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSetZoomSliderPosSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSetZoomSliderPosSEL, _gPID)))

#define FRStatusBarGetZoomSliderPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarGetZoomSliderPosSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarGetZoomSliderPosSEL, _gPID)))

#define FRStatusBarSetZoomPaneText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSetZoomPaneTextSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSetZoomPaneTextSEL, _gPID)))

#define FRStatusBarSetComboBoxPageCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSetComboBoxPageCountSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSetComboBoxPageCountSEL, _gPID)))

#define FRStatusBarSelectComboBoxItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSelectComboBoxItemSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSelectComboBoxItemSEL, _gPID)))

#define FRStatusBarGetComboBoxPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarGetComboBoxPageIndexSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarGetComboBoxPageIndexSEL, _gPID)))

#define FRStatusBarGetComboBoxPageText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarGetComboBoxPageTextSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarGetComboBoxPageTextSEL, _gPID)))

#define FRStatusBarGetBkGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarGetBkGroundColorSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarGetBkGroundColorSEL, _gPID)))

#define FRStatusBarGetBkGroundPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarGetBkGroundPathSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarGetBkGroundPathSEL, _gPID)))

#define FRStatusBarRecalcLayout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarRecalcLayoutSELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarRecalcLayoutSEL, _gPID)))

#define FRStatusBarSetComboBoxPageCount2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSetComboBoxPageCount2SELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSetComboBoxPageCount2SEL, _gPID)))

#define FRStatusBarSelectComboBoxItem2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRStatusBarSelectComboBoxItem2SELPROTO)FRCOREROUTINE(FRStatusBarSEL,FRStatusBarSelectComboBoxItem2SEL, _gPID)))

//----------_V8----------
//----------_V9----------
//*****************************
/* BulbMsgCenter HFT functions */
//*****************************

#define FRBulbMsgCenterAddMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterAddMessageSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterAddMessageSEL, _gPID)))

#define FRBulbMsgCenterShowMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterShowMessageSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterShowMessageSEL, _gPID)))

#define FRBulbMsgCenterSetCheck (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterSetCheckSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterSetCheckSEL, _gPID)))

#define FRBulbMsgCenterSetOpBtnEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterSetOpBtnEnableSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterSetOpBtnEnableSEL, _gPID)))

#define FRBulbMsgCenterIsMessageExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterIsMessageExistSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterIsMessageExistSEL, _gPID)))

#define FRBulbMsgCenterIsOpBtnEnable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterIsOpBtnEnableSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterIsOpBtnEnableSEL, _gPID)))

#define FRBulbMsgCenterSetOpBtnTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterSetOpBtnTitleSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterSetOpBtnTitleSEL, _gPID)))

#define FRBulbMsgCenterSetMessageContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterSetMessageContentSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterSetMessageContentSEL, _gPID)))

#define FRBulbMsgCenterGetButtonRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterGetButtonRectSELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterGetButtonRectSEL, _gPID)))

#define FRBulbMsgCenterAddMessage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterAddMessage2SELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterAddMessage2SEL, _gPID)))

#define FRBulbMsgCenterShowMessage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterShowMessage2SELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterShowMessage2SEL, _gPID)))

#define FRBulbMsgCenterAddMessage3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterAddMessage3SELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterAddMessage3SEL, _gPID)))

#define FRBulbMsgCenterAddMessage4 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRBulbMsgCenterAddMessage4SELPROTO)FRCOREROUTINE(FRBulbMsgCenterSEL,FRBulbMsgCenterAddMessage4SEL, _gPID)))

//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif