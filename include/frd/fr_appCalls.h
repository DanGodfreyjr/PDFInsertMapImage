/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_APPCALLS_H
#define FR_APPCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_APPEXPT_H
#include "fr_appExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_appimpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_appTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_appimpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_appTempl.h"

//----------_V1----------
//*****************************
/* Tool HFT functions */
//*****************************

#define FRToolNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolNewSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolNewSEL, _gPID)))

#define FRToolRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolReleaseSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolReleaseSEL, _gPID)))

#define FRToolGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolGetNameSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolGetNameSEL, _gPID)))

#define FRToolSetAssociatedMousePtHandlerType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolSetAssociatedMousePtHandlerTypeSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolSetAssociatedMousePtHandlerTypeSEL, _gPID)))

#define FRToolSetAssociatedSelectionHandlerType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRToolSetAssociatedSelectionHandlerTypeSELPROTO)FRCOREROUTINE(FRToolSEL,FRToolSetAssociatedSelectionHandlerTypeSEL, _gPID)))

//*****************************
/* App HFT functions */
//*****************************

#define FRAppGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNameSEL, _gPID)))

#define FRAppGetVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetVersionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetVersionSEL, _gPID)))

#define FRAppGetAppTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAppTitleSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAppTitleSEL, _gPID)))

#define FRAppGetAppDataPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAppDataPathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAppDataPathSEL, _gPID)))

#define FRAppCanQuit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCanQuitSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCanQuitSEL, _gPID)))

#define FRAppCountToolbars (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountToolbarsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountToolbarsSEL, _gPID)))

#define FRAppGetToolBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolBarSEL, _gPID)))

#define FRAppGetToolBarByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolBarByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolBarByNameSEL, _gPID)))

#define FRAppGetMenuBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMenuBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMenuBarSEL, _gPID)))

#define FRAppShowMenuBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowMenuBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowMenuBarSEL, _gPID)))

#define FRAppRegisterTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterToolSEL, _gPID)))

#define FRAppGetToolByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolByNameSEL, _gPID)))

#define FRAppCountTools (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountToolsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountToolsSEL, _gPID)))

#define FRAppGetToolByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolByIndexSEL, _gPID)))

#define FRAppSetActiveTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetActiveToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetActiveToolSEL, _gPID)))

#define FRAppGetActiveTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetActiveToolSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetActiveToolSEL, _gPID)))

#define FRAppRegisterPreferencePageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPreferencePageHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPreferencePageHandlerSEL, _gPID)))

#define FRAppAddPreferencePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddPreferencePageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddPreferencePageSEL, _gPID)))

#define FRAppRegisterDocPropertyPageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDocPropertyPageHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDocPropertyPageHandlerSEL, _gPID)))

#define FRAppAddDocPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddDocPropertyPageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddDocPropertyPageSEL, _gPID)))

#define FRAppRegisterNavPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterNavPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterNavPanelViewSEL, _gPID)))

#define FRAppRegisterAppEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterAppEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterAppEventHandlerSEL, _gPID)))

#define FRAppCountDocsOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountDocsOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountDocsOfPDDocSEL, _gPID)))

#define FRAppGetDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetDocOfPDDocSEL, _gPID)))

#define FRAppGetActiveDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetActiveDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetActiveDocOfPDDocSEL, _gPID)))

#define FRAppSetActiveDocOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetActiveDocOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetActiveDocOfPDDocSEL, _gPID)))

#define FRAppRegisterDocHandlerOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDocHandlerOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDocHandlerOfPDDocSEL, _gPID)))

#define FRAppIsFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsFullScreenSEL, _gPID)))

#define FRAppShowFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowFullScreenSEL, _gPID)))

#define FRAppEndFullScreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppEndFullScreenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppEndFullScreenSEL, _gPID)))

#define FRAppGetMousePos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMousePosSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMousePosSEL, _gPID)))

#define FRAppModalWindowIsOpen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppModalWindowIsOpenSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppModalWindowIsOpenSEL, _gPID)))

#define FRAppRegisterSecurityHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSecurityHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSecurityHandlerSEL, _gPID)))

#define FRAppUnRegisterSecurityHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterSecurityHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterSecurityHandlerSEL, _gPID)))

#define FRAppGetPassphrase (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetPassphraseSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetPassphraseSEL, _gPID)))

#define FRAppRegisterContentProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterContentProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterContentProviderSEL, _gPID)))

#define FRAppGetMainFrameWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainFrameWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainFrameWndSEL, _gPID)))

#define FRAppAddUndoRedoItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddUndoRedoItemSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddUndoRedoItemSEL, _gPID)))

#define FRAppRegisterPageHandlerOfPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPageHandlerOfPDDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPageHandlerOfPDDocSEL, _gPID)))

#define FRAppRegisterForContextMenuAddition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterForContextMenuAdditionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterForContextMenuAdditionSEL, _gPID)))

#define FRAppRegisterSelectionHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSelectionHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSelectionHandlerSEL, _gPID)))

#define FRAppUnRegisterSelectionHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterSelectionHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterSelectionHandlerSEL, _gPID)))

#define FRAppRegisterCaptureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterCaptureHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterCaptureHandlerSEL, _gPID)))

#define FRAppUnRegisterCaptureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterCaptureHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterCaptureHandlerSEL, _gPID)))

#define FRAppRegistryGetProfilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetProfilePathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetProfilePathSEL, _gPID)))

#define FRAppRegistryWriteInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteIntSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteIntSEL, _gPID)))

#define FRAppRegistryWriteBinary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteBinarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteBinarySEL, _gPID)))

#define FRAppRegistryWriteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryWriteStringSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryWriteStringSEL, _gPID)))

#define FRAppRegistryGetInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetIntSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetIntSEL, _gPID)))

#define FRAppRegistryGetBinary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetBinarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetBinarySEL, _gPID)))

#define FRAppRegistryGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetStringSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetStringSEL, _gPID)))

#define FRAppRegistryGetEntryCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetEntryCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetEntryCountSEL, _gPID)))

#define FRAppRegistryGetEntryName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetEntryNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetEntryNameSEL, _gPID)))

#define FRAppRegistryRemoveSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryRemoveSectionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryRemoveSectionSEL, _gPID)))

#define FRAppRegistryRemoveEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryRemoveEntrySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryRemoveEntrySEL, _gPID)))

#define FRAppGetGEModule (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetGEModuleSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetGEModuleSEL, _gPID)))

#define FRAppGetModuleMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetModuleMgrSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetModuleMgrSEL, _gPID)))

#define FRAppCreateAnEmptyFrameWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateAnEmptyFrameWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateAnEmptyFrameWndSEL, _gPID)))

#define FRAppIsRunEmbedded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsRunEmbeddedSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsRunEmbeddedSEL, _gPID)))

#define FRAppRegisterExtraPrintInfoProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterExtraPrintInfoProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterExtraPrintInfoProviderSEL, _gPID)))

#define FRAppIsRibbonMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsRibbonModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsRibbonModeSEL, _gPID)))

#define FRAppGetStartMenuOfTabbedToobarMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetStartMenuOfTabbedToobarModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetStartMenuOfTabbedToobarModeSEL, _gPID)))

#define FRAppRegisterTaskPaneView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterTaskPaneViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterTaskPaneViewSEL, _gPID)))

#define FRAppShowTaskPane (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowTaskPaneSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowTaskPaneSEL, _gPID)))

#define FRAppGetTaskPaneWndHandleByDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetTaskPaneWndHandleByDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetTaskPaneWndHandleByDocSEL, _gPID)))

#define FRAppCommandLineHasSwitch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineHasSwitchSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineHasSwitchSEL, _gPID)))

#define FRAppCommandLineGetSafeArgument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetSafeArgumentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetSafeArgumentSEL, _gPID)))

#define FRAppCommandLineGetArgument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetArgumentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetArgumentSEL, _gPID)))

#define FRAppCommandLineGetArgumentCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCommandLineGetArgumentCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCommandLineGetArgumentCountSEL, _gPID)))

#define FRAppRegisterWinMSGHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterWinMSGHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterWinMSGHandlerSEL, _gPID)))

#define FRAppGetRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileListSEL, _gPID)))

#define FRAppAddFileToRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileToRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileToRecentFileListSEL, _gPID)))

#define FRAppClearRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppClearRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppClearRecentFileListSEL, _gPID)))

#define FRAppRegisterSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterSecurityMethodSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterSecurityMethodSEL, _gPID)))

#define FRAppPopDocPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppPopDocPropertyPageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppPopDocPropertyPageSEL, _gPID)))

#define FRAppCountDocPropertyPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountDocPropertyPagesSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountDocPropertyPagesSEL, _gPID)))

#define FRAppCheckModuleLicense (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCheckModuleLicenseSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCheckModuleLicenseSEL, _gPID)))

#define FRAppRegisterOwnerFileType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterOwnerFileTypeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterOwnerFileTypeSEL, _gPID)))

#define FRAppRegistryGetKeyCounts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetKeyCountsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetKeyCountsSEL, _gPID)))

#define FRAppRegistryGetKeyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegistryGetKeyNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegistryGetKeyNameSEL, _gPID)))

#define FRAppGetRibbonBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBarSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBarSEL, _gPID)))

#define FRAppGetRibbonBarBackGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBarBackGroundColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBarBackGroundColorSEL, _gPID)))

#define FRAppGetRibbonBarBtnBackGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBarBtnBackGroundColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBarBtnBackGroundColorSEL, _gPID)))

#define FRAppLoadLibrary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppLoadLibrarySELPROTO)FRCOREROUTINE(FRAppSEL,FRAppLoadLibrarySEL, _gPID)))

#define FRAppIsCurDocShowInBrowser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsCurDocShowInBrowserSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsCurDocShowInBrowserSEL, _gPID)))

#define FRAppRemoveFileFromRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRemoveFileFromRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRemoveFileFromRecentFileListSEL, _gPID)))

#define FRAppCreateCustomRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateCustomRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateCustomRecentFileListSEL, _gPID)))

#define FRAppRemoveFileFromCustomRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRemoveFileFromCustomRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRemoveFileFromCustomRecentFileListSEL, _gPID)))

#define FRAppAddFileToCustomRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileToCustomRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileToCustomRecentFileListSEL, _gPID)))

#define FRAppClearCustomRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppClearCustomRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppClearCustomRecentFileListSEL, _gPID)))

#define FRAppRegisterMousePtHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterMousePtHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterMousePtHandlerSEL, _gPID)))

#define FRAppUnRegisterMousePtHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterMousePtHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterMousePtHandlerSEL, _gPID)))

#define FRAppIsLicenseValidOrInTrial (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsLicenseValidOrInTrialSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsLicenseValidOrInTrialSEL, _gPID)))

#define FRAppShowPreferenceDlg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowPreferenceDlgSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowPreferenceDlgSEL, _gPID)))

#define FRAppUndoRedoIsEditing (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUndoRedoIsEditingSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUndoRedoIsEditingSEL, _gPID)))

#define FRAppUndoRedoBeginEdit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUndoRedoBeginEditSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUndoRedoBeginEditSEL, _gPID)))

#define FRAppUndoRedoEndEdit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUndoRedoEndEditSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUndoRedoEndEditSEL, _gPID)))

#define FRAppRegisterWndProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterWndProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterWndProviderSEL, _gPID)))

#define FRAppUnRegisterWndProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterWndProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterWndProviderSEL, _gPID)))

#define FRAppGetEditionType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetEditionTypeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetEditionTypeSEL, _gPID)))

#define FRAppGetRecentFileListSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileListSizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileListSizeSEL, _gPID)))

#define FRAppGetModuleFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetModuleFileNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetModuleFileNameSEL, _gPID)))

#define FRAppGetToolbarLocked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetToolbarLockedSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetToolbarLockedSEL, _gPID)))

#define FRAppSetToolbarLocked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetToolbarLockedSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetToolbarLockedSEL, _gPID)))

#define FRAppRegisterCmdMsgEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterCmdMsgEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterCmdMsgEventHandlerSEL, _gPID)))

#define FRAppUnRegisterCmdMsgEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppUnRegisterCmdMsgEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppUnRegisterCmdMsgEventHandlerSEL, _gPID)))

#define FRAppRemoveTaskPanelByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRemoveTaskPanelByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRemoveTaskPanelByNameSEL, _gPID)))

#define FRAppDisableAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDisableAllPanelSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDisableAllPanelSEL, _gPID)))

#define FRAppIsDisableAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsDisableAllPanelSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsDisableAllPanelSEL, _gPID)))

#define FRAppGetPageContextMenuPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetPageContextMenuPosSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetPageContextMenuPosSEL, _gPID)))

#define FRAppOnCmdMsgByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppOnCmdMsgByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppOnCmdMsgByNameSEL, _gPID)))

#define FRAppSetOwnUndoMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetOwnUndoModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetOwnUndoModeSEL, _gPID)))

#define FRAppExitOwnUndoMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppExitOwnUndoModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppExitOwnUndoModeSEL, _gPID)))

#define FRAppRegisterActionHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterActionHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterActionHandlerSEL, _gPID)))

#define FRAppRedrawRecentFileList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRedrawRecentFileListSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRedrawRecentFileListSEL, _gPID)))

#define FRAppSetCustomRecentFileListLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetCustomRecentFileListLabelSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetCustomRecentFileListLabelSEL, _gPID)))

#define FRAppSetCustomRecentFileListItemBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetCustomRecentFileListItemBitmapSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetCustomRecentFileListItemBitmapSEL, _gPID)))

#define FRAppSetCustomRecentFileListMaxSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetCustomRecentFileListMaxSizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetCustomRecentFileListMaxSizeSEL, _gPID)))

#define FRAppSetCustomRecentFileListItemTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetCustomRecentFileListItemTitleSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetCustomRecentFileListItemTitleSEL, _gPID)))

#define FRAppSetCustomRecentFileListItemTooltip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetCustomRecentFileListItemTooltipSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetCustomRecentFileListItemTooltipSEL, _gPID)))

#define FRAppGetCustomRecentFileListItemCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetCustomRecentFileListItemCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetCustomRecentFileListItemCountSEL, _gPID)))

#define FRAppIsRTLLanguage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsRTLLanguageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsRTLLanguageSEL, _gPID)))

#define FRAppGetOEMVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetOEMVersionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetOEMVersionSEL, _gPID)))

#define FRAppRegisterDataCollectionHadler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDataCollectionHadlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDataCollectionHadlerSEL, _gPID)))

#define FRAppGetUIParentWndByTaskPane (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetUIParentWndByTaskPaneSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetUIParentWndByTaskPaneSEL, _gPID)))

#define FRAppAdvWndSetCustomize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAdvWndSetCustomizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAdvWndSetCustomizeSEL, _gPID)))

#define FRAppGetAdvWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetAdvWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetAdvWndSEL, _gPID)))

#define FRAppShowAdvWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppShowAdvWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppShowAdvWndSEL, _gPID)))

#define FRAppRegisterPOEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPOEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPOEventHandlerSEL, _gPID)))

#define FRAppCreateBlankDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateBlankDocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateBlankDocSEL, _gPID)))

#define FRAppGetLocalFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetLocalFontNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetLocalFontNameSEL, _gPID)))

#define FRAppReLoadStartPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppReLoadStartPageSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppReLoadStartPageSEL, _gPID)))

#define FRAppSetRecentFileListImageByExt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetRecentFileListImageByExtSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetRecentFileListImageByExtSEL, _gPID)))

#define FRAppGetCurMeasurementUnits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetCurMeasurementUnitsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetCurMeasurementUnitsSEL, _gPID)))

#define FRAppGetNavPanelViewByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelViewByNameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelViewByNameSEL, _gPID)))

#define FRAppGetNavPanelNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelNameByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelNameByIndexSEL, _gPID)))

#define FRAppGetNavPanelCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetNavPanelCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetNavPanelCountSEL, _gPID)))

#define FRAppGetStartAppMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetStartAppModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetStartAppModeSEL, _gPID)))

#define FRAppRestartProcess (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRestartProcessSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRestartProcessSEL, _gPID)))

#define FRAppGetStatusBarBkGroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetStatusBarBkGroundColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetStatusBarBkGroundColorSEL, _gPID)))

#define FRAppGetStatusBarBkGroundPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetStatusBarBkGroundPathSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetStatusBarBkGroundPathSEL, _gPID)))

#define FRAppCountAllTypesVisibleDocuments (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCountAllTypesVisibleDocumentsSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCountAllTypesVisibleDocumentsSEL, _gPID)))

#define FRAppAddFileToCustomRecentFileList2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileToCustomRecentFileList2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileToCustomRecentFileList2SEL, _gPID)))

#define FRAppRegisterRibbonRecentFileEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterRibbonRecentFileEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterRibbonRecentFileEventHandlerSEL, _gPID)))

#define FRAppDestroyRibbonRecentFileEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDestroyRibbonRecentFileEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDestroyRibbonRecentFileEventHandlerSEL, _gPID)))

#define FRAppSetMetadataOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetMetadataOptionSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetMetadataOptionSEL, _gPID)))

#define FRAppSetSubscriptionProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetSubscriptionProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetSubscriptionProviderSEL, _gPID)))

#define FRAppDestroySubscriptionProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDestroySubscriptionProviderSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDestroySubscriptionProviderSEL, _gPID)))

#define FRAppGetKeyfileStartAndExpireDate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetKeyfileStartAndExpireDateSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetKeyfileStartAndExpireDateSEL, _gPID)))

#define FRAppGetRibbonCategoryColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonCategoryColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonCategoryColorSEL, _gPID)))

#define FRAppGetRibbonElementColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonElementColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonElementColorSEL, _gPID)))

#define FRAppGetRibbonBaseBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBaseBorderColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBaseBorderColorSEL, _gPID)))

#define FRAppGetRecentFolderListSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFolderListSizeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFolderListSizeSEL, _gPID)))

#define FRAppCreateEmptyFrameViewEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateEmptyFrameViewEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateEmptyFrameViewEventHandlerSEL, _gPID)))

#define FRAppDestroyEmptyFrameViewEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppDestroyEmptyFrameViewEventHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppDestroyEmptyFrameViewEventHandlerSEL, _gPID)))

#define FRAppCreateAnEmptyFrameWnd2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCreateAnEmptyFrameWnd2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCreateAnEmptyFrameWnd2SEL, _gPID)))

#define FRAppIsReadMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsReadModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsReadModeSEL, _gPID)))

#define FRAppExitReadMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppExitReadModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppExitReadModeSEL, _gPID)))

#define FRAppGetCurrentChildFrm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetCurrentChildFrmSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetCurrentChildFrmSEL, _gPID)))

#define FRAppCollectDocActionData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCollectDocActionDataSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCollectDocActionDataSEL, _gPID)))

#define FRAppActiveChildFrame (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppActiveChildFrameSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppActiveChildFrameSEL, _gPID)))

#define FRAppCollectNormalData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCollectNormalDataSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCollectNormalDataSEL, _gPID)))

#define FRAppSetMainframeShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetMainframeShowSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetMainframeShowSEL, _gPID)))

#define FRAppGetMainframeShow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainframeShowSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainframeShowSEL, _gPID)))

#define FRAppGetRibbonTooltipBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonTooltipBorderColorSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonTooltipBorderColorSEL, _gPID)))

#define FRAppGetRecentFileIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRecentFileIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRecentFileIndexSEL, _gPID)))

#define FRAppFZipUnzip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppFZipUnzipSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppFZipUnzipSEL, _gPID)))

#define FRAppIsJSEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsJSEnabledSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsJSEnabledSEL, _gPID)))

#define FRAppSetEnableJS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppSetEnableJSSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppSetEnableJSSEL, _gPID)))

#define FRAppCollectNormalData2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCollectNormalData2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCollectNormalData2SEL, _gPID)))

#define FRAppCollectBitmapData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppCollectBitmapDataSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppCollectBitmapDataSEL, _gPID)))

#define FRAppIsNeedCollectData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsNeedCollectDataSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsNeedCollectDataSEL, _gPID)))

#define FRAppIsFipsMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsFipsModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsFipsModeSEL, _gPID)))

#define FRAppAddNavPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddNavPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddNavPanelViewSEL, _gPID)))

#define FRAppReleaseNavPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppReleaseNavPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppReleaseNavPanelViewSEL, _gPID)))

#define FRAppAddFileAttachment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddFileAttachmentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddFileAttachmentSEL, _gPID)))

#define FRAppOpenFileAttachment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppOpenFileAttachmentSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppOpenFileAttachmentSEL, _gPID)))

#define FRAppIsPDF2Doc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsPDF2DocSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsPDF2DocSEL, _gPID)))

#define FRAppConvertToPDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppConvertToPDFSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppConvertToPDFSEL, _gPID)))

#define FRAppRegisterPDFAPluginHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterPDFAPluginHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterPDFAPluginHandlerSEL, _gPID)))

#define FRAppConvertToPDFA (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppConvertToPDFASELPROTO)FRCOREROUTINE(FRAppSEL,FRAppConvertToPDFASEL, _gPID)))

#define FRAppAddLog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddLogSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddLogSEL, _gPID)))

#define FRAppIsReaderOnlyMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsReaderOnlyModeSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsReaderOnlyModeSEL, _gPID)))

#define FRAppGetMainFrameWndCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainFrameWndCountSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainFrameWndCountSEL, _gPID)))

#define FRAppGetMainFrameWndByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetMainFrameWndByIndexSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetMainFrameWndByIndexSEL, _gPID)))

#define FRAppGetModelessParentWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetModelessParentWndSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetModelessParentWndSEL, _gPID)))

#define FRAppIsMainfrmActivating (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppIsMainfrmActivatingSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppIsMainfrmActivatingSEL, _gPID)))

#define FRAppGetRibbonBar2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetRibbonBar2SELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetRibbonBar2SEL, _gPID)))

#define FRAppRefreshLayerPanelView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRefreshLayerPanelViewSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRefreshLayerPanelViewSEL, _gPID)))

#define FRAppRegisterDRMSecurityHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppRegisterDRMSecurityHandlerSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppRegisterDRMSecurityHandlerSEL, _gPID)))

#define FRAppAddECMFileDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppAddECMFileDialogSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppAddECMFileDialogSEL, _gPID)))
#define FRAppECMFileDialogAddMenuItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppECMFileDialogAddMenuItemSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppECMFileDialogAddMenuItemSEL, _gPID)))
#define FRAppECMFileDialogItemSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppECMFileDialogItemSelectedSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppECMFileDialogItemSelectedSEL, _gPID)))
#define FRAppGetECMFileDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAppGetECMFileDialogSELPROTO)FRCOREROUTINE(FRAppSEL,FRAppGetECMFileDialogSEL, _gPID)))

//*****************************
/* Language HFT functions */
//*****************************

#define FRLanguageCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageCreateSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageCreateSEL, _gPID)))

#define FRLanguageRelease (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageReleaseSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageReleaseSEL, _gPID)))

#define FRLanguageChange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageChangeSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageChangeSEL, _gPID)))

#define FRLanguageGetCurrentID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageGetCurrentIDSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageGetCurrentIDSEL, _gPID)))

#define FRLanguageTranslateMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateMenuSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateMenuSEL, _gPID)))

#define FRLanguageTranslateDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateDialogSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateDialogSEL, _gPID)))

#define FRLanguageLoadString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageLoadStringSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageLoadStringSEL, _gPID)))

#define FRLanguageLoadVersionRes (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageLoadVersionResSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageLoadVersionResSEL, _gPID)))

#define FRLanguageGetLocalLangName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageGetLocalLangNameSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageGetLocalLangNameSEL, _gPID)))

#define FRLanguageTranslateDialog2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageTranslateDialog2SELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageTranslateDialog2SEL, _gPID)))

#define FRLanguageModifyLogFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageModifyLogFontSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageModifyLogFontSEL, _gPID)))

#define FRLanguageFormatEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageFormatExSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageFormatExSEL, _gPID)))

#define FRLanguageJSPluginGetMessage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRLanguageJSPluginGetMessageSELPROTO)FRCOREROUTINE(FRLanguageSEL,FRLanguageJSPluginGetMessageSEL, _gPID)))

//*****************************
/* UIProgress HFT functions */
//*****************************

#define FRUIProgressCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressCreateSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressCreateSEL, _gPID)))

#define FRUIProgressSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetTextSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetTextSEL, _gPID)))

#define FRUIProgressSetRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetRangeSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetRangeSEL, _gPID)))

#define FRUIProgressSetCurrValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressSetCurrValueSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressSetCurrValueSEL, _gPID)))

#define FRUIProgressPeekAndPump (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressPeekAndPumpSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressPeekAndPumpSEL, _gPID)))

#define FRUIProgressIsCancelled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressIsCancelledSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressIsCancelledSEL, _gPID)))

#define FRUIProgressGetCurrentValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressGetCurrentValueSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressGetCurrentValueSEL, _gPID)))

#define FRUIProgressDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressDestroySELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressDestroySEL, _gPID)))

#define FRUIProgressDoCancel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressDoCancelSELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressDoCancelSEL, _gPID)))

#define FRUIProgressCreate2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRUIProgressCreate2SELPROTO)FRCOREROUTINE(FRUIProgressSEL,FRUIProgressCreate2SEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* Internal HFT functions */
//*****************************

#define FRInternalDoPrintCommentSummary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalDoPrintCommentSummarySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalDoPrintCommentSummarySEL, _gPID)))

#define FRInternalOptimizerModuleFlatDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalOptimizerModuleFlatDocumentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalOptimizerModuleFlatDocumentSEL, _gPID)))

#define FRInternalGlobalWndOpenPassWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGlobalWndOpenPassWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGlobalWndOpenPassWordSEL, _gPID)))

#define FRInternalGlobalWndCheckFileSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGlobalWndCheckFileSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGlobalWndCheckFileSizeSEL, _gPID)))

#define FRInternalOpenCertifiedPDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalOpenCertifiedPDFSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalOpenCertifiedPDFSEL, _gPID)))

#define FRInternalPWLWndCreationParamNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamNewSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetFontMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetFontMapSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetFontMapSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetFontIndexSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetFlagSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetFlagSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetFontSizeSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetTextColorSEL, _gPID)))

#define FRInternalPWLWndCreationParamSetTextColorII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetTextColorIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetTextColorIISEL, _gPID)))

#define FRInternalPWLWndCreationParamSetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamSetRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamSetRectSEL, _gPID)))

#define FRInternalPWLWndCreationParamDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndCreationParamDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndCreationParamDestroySEL, _gPID)))

#define FRInternalPWLWndEditNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditNewSEL, _gPID)))

#define FRInternalPWLWndEditSetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditSetTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditSetTextColorSEL, _gPID)))

#define FRInternalPWLWndEditSetTextColorII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditSetTextColorIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditSetTextColorIISEL, _gPID)))

#define FRInternalPWLWndEditSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditSetTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditSetTextSEL, _gPID)))

#define FRInternalPWLWndEditGetContentRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditGetContentRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditGetContentRectSEL, _gPID)))

#define FRInternalPWLWndEditGeneratePageObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditGeneratePageObjectsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditGeneratePageObjectsSEL, _gPID)))

#define FRInternalPWLWndEditGeneratePageObjectsII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditGeneratePageObjectsIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditGeneratePageObjectsIISEL, _gPID)))

#define FRInternalPWLWndEditDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalPWLWndEditDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalPWLWndEditDestroySEL, _gPID)))

#define FRInternalSetReviewJS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetReviewJSSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetReviewJSSEL, _gPID)))

#define FRInternalGetReviewJS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetReviewJSSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetReviewJSSEL, _gPID)))

#define FRInternalRemoveReviewJS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRemoveReviewJSSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRemoveReviewJSSEL, _gPID)))

#define FRInternalExportAnnotToXFDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalExportAnnotToXFDFSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalExportAnnotToXFDFSEL, _gPID)))

#define FRInternalImprotAnnotFromXFDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalImprotAnnotFromXFDFSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalImprotAnnotFromXFDFSEL, _gPID)))

#define FRInternalEnableAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEnableAnnotSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEnableAnnotSEL, _gPID)))

#define FRInternalDeleteAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalDeleteAnnotSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalDeleteAnnotSEL, _gPID)))

#define FRInternalUpdateAnnotAuthor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalUpdateAnnotAuthorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalUpdateAnnotAuthorSEL, _gPID)))

#define FRInternalUpdateAnnotAuthor2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalUpdateAnnotAuthor2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalUpdateAnnotAuthor2SEL, _gPID)))

#define FRInternalSetIcommentsAnnotNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetIcommentsAnnotNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetIcommentsAnnotNotifySEL, _gPID)))

#define FRInternalRemoveIcommentsAnnotNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRemoveIcommentsAnnotNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRemoveIcommentsAnnotNotifySEL, _gPID)))

#define FRInternalShowChildScrollBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalShowChildScrollBarSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalShowChildScrollBarSEL, _gPID)))

#define FRInternalChangeZoomScaleInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalChangeZoomScaleInfoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalChangeZoomScaleInfoSEL, _gPID)))

#define FRInternalAdvEditing (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalAdvEditingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalAdvEditingSEL, _gPID)))

#define FRInternalToolbarModuleGetSysFontFaceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalToolbarModuleGetSysFontFaceNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalToolbarModuleGetSysFontFaceNameSEL, _gPID)))

#define FRInternalWordPlaceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceNewSEL, _gPID)))

#define FRInternalWordPlaceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceDestroySEL, _gPID)))

#define FRInternalWordPlaceSetDefault (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceSetDefaultSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceSetDefaultSEL, _gPID)))

#define FRInternalWordPlaceEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceEqualSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceEqualSEL, _gPID)))

#define FRInternalWordPlaceWordCmp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceWordCmpSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceWordCmpSEL, _gPID)))

#define FRInternalWordPlaceLineCmp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceLineCmpSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceLineCmpSEL, _gPID)))

#define FRInternalWordPlaceSecCmp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceSecCmpSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceSecCmpSEL, _gPID)))

#define FRInternalWordPlaceSetSectionIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceSetSectionIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceSetSectionIndexSEL, _gPID)))

#define FRInternalWordPlaceGetSectionIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceGetSectionIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceGetSectionIndexSEL, _gPID)))

#define FRInternalWordPlaceSetLineIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceSetLineIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceSetLineIndexSEL, _gPID)))

#define FRInternalWordPlaceGetLineIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceGetLineIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceGetLineIndexSEL, _gPID)))

#define FRInternalWordPlaceSetWordIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceSetWordIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceSetWordIndexSEL, _gPID)))

#define FRInternalWordPlaceGetWordIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPlaceGetWordIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPlaceGetWordIndexSEL, _gPID)))

#define FRInternalWordRangeNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeNewSEL, _gPID)))

#define FRInternalWordRangeDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeDestroySEL, _gPID)))

#define FRInternalWordRangeSetDefault (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeSetDefaultSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeSetDefaultSEL, _gPID)))

#define FRInternalWordRangeSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeSetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeSetSEL, _gPID)))

#define FRInternalWordRangeSetBeginPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeSetBeginPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeSetBeginPosSEL, _gPID)))

#define FRInternalWordRangeSetEndPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeSetEndPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeSetEndPosSEL, _gPID)))

#define FRInternalWordRangeIsExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeIsExistSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeIsExistSEL, _gPID)))

#define FRInternalWordRangeEqual (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeEqualSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeEqualSEL, _gPID)))

#define FRInternalWordRangeSwapWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeSwapWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeSwapWordPlaceSEL, _gPID)))

#define FRInternalWordRangeGetBeginPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeGetBeginPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeGetBeginPosSEL, _gPID)))

#define FRInternalWordRangeGetEndPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordRangeGetEndPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordRangeGetEndPosSEL, _gPID)))

#define FRInternalSecPropsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsNewSEL, _gPID)))

#define FRInternalSecPropsNewII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsNewIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsNewIISEL, _gPID)))

#define FRInternalSecPropsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsDestroySEL, _gPID)))

#define FRInternalSecPropsSetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsSetLineLeadingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsSetLineLeadingSEL, _gPID)))

#define FRInternalSecPropsGetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsGetLineLeadingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsGetLineLeadingSEL, _gPID)))

#define FRInternalSecPropsSetLineIndent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsSetLineIndentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsSetLineIndentSEL, _gPID)))

#define FRInternalSecPropsGetLineIndent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsGetLineIndentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsGetLineIndentSEL, _gPID)))

#define FRInternalSecPropsSetAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsSetAlignmentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsSetAlignmentSEL, _gPID)))

#define FRInternalSecPropsGetAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsGetAlignmentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsGetAlignmentSEL, _gPID)))

#define FRInternalSecPropsSetSoftReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsSetSoftReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsSetSoftReturnSEL, _gPID)))

#define FRInternalSecPropsGetSoftReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsGetSoftReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsGetSoftReturnSEL, _gPID)))

#define FRInternalSecPropsSetRTL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsSetRTLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsSetRTLSEL, _gPID)))

#define FRInternalSecPropsGetRTL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSecPropsGetRTLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSecPropsGetRTLSEL, _gPID)))

#define FRInternalWordPropsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsNewSEL, _gPID)))

#define FRInternalWordPropsNewII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsNewIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsNewIISEL, _gPID)))

#define FRInternalWordPropsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsDestroySEL, _gPID)))

#define FRInternalWordPropsSetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetFontIndexSEL, _gPID)))

#define FRInternalWordPropsGetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetFontIndexSEL, _gPID)))

#define FRInternalWordPropsSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetFontSizeSEL, _gPID)))

#define FRInternalWordPropsGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetFontSizeSEL, _gPID)))

#define FRInternalWordPropsSetWordColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetWordColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetWordColorSEL, _gPID)))

#define FRInternalWordPropsGetWordColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetWordColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetWordColorSEL, _gPID)))

#define FRInternalWordPropsSetStrokeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetStrokeColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetStrokeColorSEL, _gPID)))

#define FRInternalWordPropsGetStrokeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetStrokeColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetStrokeColorSEL, _gPID)))

#define FRInternalWordPropsSetScriptType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetScriptTypeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetScriptTypeSEL, _gPID)))

#define FRInternalWordPropsGetScriptType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetScriptTypeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetScriptTypeSEL, _gPID)))

#define FRInternalWordPropsSetWordStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetWordStyleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetWordStyleSEL, _gPID)))

#define FRInternalWordPropsGetWordStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetWordStyleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetWordStyleSEL, _gPID)))

#define FRInternalWordPropsSetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetCharSpaceSEL, _gPID)))

#define FRInternalWordPropsGetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetCharSpaceSEL, _gPID)))

#define FRInternalWordPropsSetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetHorzScaleSEL, _gPID)))

#define FRInternalWordPropsGetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetHorzScaleSEL, _gPID)))

#define FRInternalWordPropsSetXOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetXOffsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetXOffsetSEL, _gPID)))

#define FRInternalWordPropsGetXOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetXOffsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetXOffsetSEL, _gPID)))

#define FRInternalWordPropsSetYOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetYOffsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetYOffsetSEL, _gPID)))

#define FRInternalWordPropsGetYOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetYOffsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetYOffsetSEL, _gPID)))

#define FRInternalWordPropsSetRenderingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetRenderingModeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetRenderingModeSEL, _gPID)))

#define FRInternalWordPropsGetRenderingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetRenderingModeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetRenderingModeSEL, _gPID)))

#define FRInternalWordPropsSetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetClientDataSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetClientDataSEL, _gPID)))

#define FRInternalWordPropsGetClientData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetClientDataSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetClientDataSEL, _gPID)))

#define FRInternalWordPropsSetLineWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetLineWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetLineWidthSEL, _gPID)))

#define FRInternalWordPropsGetLineWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetLineWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetLineWidthSEL, _gPID)))

#define FRInternalWordPropsSetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetWordSpaceSEL, _gPID)))

#define FRInternalWordPropsGetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetWordSpaceSEL, _gPID)))

#define FRInternalWordPropsSetCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetCharCodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetCharCodeSEL, _gPID)))

#define FRInternalWordPropsGetCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetCharCodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetCharCodeSEL, _gPID)))

#define FRInternalWordPropsSetAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsSetAlphaSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsSetAlphaSEL, _gPID)))

#define FRInternalWordPropsGetAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordPropsGetAlphaSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordPropsGetAlphaSEL, _gPID)))

#define FRInternalWordNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordNewSEL, _gPID)))

#define FRInternalWordDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordDestroySEL, _gPID)))

#define FRInternalWordSetWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWordSEL, _gPID)))

#define FRInternalWordGetWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWordSEL, _gPID)))

#define FRInternalWordSetWordDisplay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWordDisplaySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWordDisplaySEL, _gPID)))

#define FRInternalWordGetWordDisplay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWordDisplaySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWordDisplaySEL, _gPID)))

#define FRInternalWordSetBidiOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetBidiOrderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetBidiOrderSEL, _gPID)))

#define FRInternalWordGetBidiOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetBidiOrderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetBidiOrderSEL, _gPID)))

#define FRInternalWordSetCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetCharsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetCharsetSEL, _gPID)))

#define FRInternalWordGetCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetCharsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetCharsetSEL, _gPID)))

#define FRInternalWordSetWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWordPlaceSEL, _gPID)))

#define FRInternalWordGetWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWordPlaceSEL, _gPID)))

#define FRInternalWordSetWordPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWordPointSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWordPointSEL, _gPID)))

#define FRInternalWordGetWordPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWordPointSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWordPointSEL, _gPID)))

#define FRInternalWordSetAscent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetAscentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetAscentSEL, _gPID)))

#define FRInternalWordGetAscent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetAscentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetAscentSEL, _gPID)))

#define FRInternalWordSetDescent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetDescentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetDescentSEL, _gPID)))

#define FRInternalWordGetDescent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetDescentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetDescentSEL, _gPID)))

#define FRInternalWordSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWidthSEL, _gPID)))

#define FRInternalWordGetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWidthSEL, _gPID)))

#define FRInternalWordSetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetFontIndexSEL, _gPID)))

#define FRInternalWordGetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetFontIndexSEL, _gPID)))

#define FRInternalWordSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetFontSizeSEL, _gPID)))

#define FRInternalWordGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetFontSizeSEL, _gPID)))

#define FRInternalWordSetWordProps (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordSetWordPropsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordSetWordPropsSEL, _gPID)))

#define FRInternalWordGetWordProps (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWordGetWordPropsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWordGetWordPropsSEL, _gPID)))

#define FRInternalLineNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineNewSEL, _gPID)))

#define FRInternalLineDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineDestroySEL, _gPID)))

#define FRInternalLineSetStartWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetStartWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetStartWordPlaceSEL, _gPID)))

#define FRInternalLineGetStartWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetStartWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetStartWordPlaceSEL, _gPID)))

#define FRInternalLineSetEndWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetEndWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetEndWordPlaceSEL, _gPID)))

#define FRInternalLineGetEndWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetEndWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetEndWordPlaceSEL, _gPID)))

#define FRInternalLineSetOriginalPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetOriginalPositionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetOriginalPositionSEL, _gPID)))

#define FRInternalLineGetOriginalPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetOriginalPositionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetOriginalPositionSEL, _gPID)))

#define FRInternalLineSetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetWidthSEL, _gPID)))

#define FRInternalLineGetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetWidthSEL, _gPID)))

#define FRInternalLineSetAscent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetAscentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetAscentSEL, _gPID)))

#define FRInternalLineGetAscent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetAscentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetAscentSEL, _gPID)))

#define FRInternalLineSetDescent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineSetDescentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineSetDescentSEL, _gPID)))

#define FRInternalLineGetDescent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLineGetDescentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLineGetDescentSEL, _gPID)))

#define FRInternalSectionNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionNewSEL, _gPID)))

#define FRInternalSectionDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionDestroySEL, _gPID)))

#define FRInternalSectionSetStartWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionSetStartWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionSetStartWordPlaceSEL, _gPID)))

#define FRInternalSectionGetStartWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionGetStartWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionGetStartWordPlaceSEL, _gPID)))

#define FRInternalSectionSetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionSetRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionSetRectSEL, _gPID)))

#define FRInternalSectionGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionGetRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionGetRectSEL, _gPID)))

#define FRInternalSectionSetSectionProperties (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionSetSectionPropertiesSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionSetSectionPropertiesSEL, _gPID)))

#define FRInternalSectionGetSectionProperties (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionGetSectionPropertiesSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionGetSectionPropertiesSEL, _gPID)))

#define FRInternalSectionSetWordProperties (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionSetWordPropertiesSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionSetWordPropertiesSEL, _gPID)))

#define FRInternalSectionGetWordProperties (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSectionGetWordPropertiesSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSectionGetWordPropertiesSEL, _gPID)))

#define FRInternalVTIteratorNextWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorNextWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorNextWordSEL, _gPID)))

#define FRInternalVTIteratorPrevWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorPrevWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorPrevWordSEL, _gPID)))

#define FRInternalVTIteratorNextLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorNextLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorNextLineSEL, _gPID)))

#define FRInternalVTIteratorPrevLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorPrevLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorPrevLineSEL, _gPID)))

#define FRInternalVTIteratorNextSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorNextSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorNextSectionSEL, _gPID)))

#define FRInternalVTIteratorPrevSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorPrevSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorPrevSectionSEL, _gPID)))

#define FRInternalVTIteratorGetWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorGetWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorGetWordSEL, _gPID)))

#define FRInternalVTIteratorSetWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorSetWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorSetWordSEL, _gPID)))

#define FRInternalVTIteratorGetLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorGetLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorGetLineSEL, _gPID)))

#define FRInternalVTIteratorGetSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorGetSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorGetSectionSEL, _gPID)))

#define FRInternalVTIteratorSetSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorSetSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorSetSectionSEL, _gPID)))

#define FRInternalVTIteratorSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorSetAtSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorSetAtSEL, _gPID)))

#define FRInternalVTIteratorSetAtII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorSetAtIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorSetAtIISEL, _gPID)))

#define FRInternalVTIteratorGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorGetAtSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorGetAtSEL, _gPID)))

#define FRInternalVTIteratorGetDisplayWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVTIteratorGetDisplayWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVTIteratorGetDisplayWordSEL, _gPID)))

#define FRInternalVariableTextNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextNewSEL, _gPID)))

#define FRInternalVariableTextDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextDestroySEL, _gPID)))

#define FRInternalVariableTextProviderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextProviderNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextProviderNewSEL, _gPID)))

#define FRInternalVariableTextProviderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextProviderDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextProviderDestroySEL, _gPID)))

#define FRInternalVariableTextSetProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetProviderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetProviderSEL, _gPID)))

#define FRInternalVariableTextGetIterator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetIteratorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetIteratorSEL, _gPID)))

#define FRInternalVariableTextSetPlateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetPlateRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetPlateRectSEL, _gPID)))

#define FRInternalVariableTextIsVerticalWriting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsVerticalWritingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsVerticalWritingSEL, _gPID)))

#define FRInternalVariableTextSetAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetAlignmentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetAlignmentSEL, _gPID)))

#define FRInternalVariableTextSetPasswordChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetPasswordCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetPasswordCharSEL, _gPID)))

#define FRInternalVariableTextSetLimitChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetLimitCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetLimitCharSEL, _gPID)))

#define FRInternalVariableTextSetCharArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetCharArraySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetCharArraySEL, _gPID)))

#define FRInternalVariableTextSetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetCharSpaceSEL, _gPID)))

#define FRInternalVariableTextSetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetWordSpaceSEL, _gPID)))

#define FRInternalVariableTextSetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetHorzScaleSEL, _gPID)))

#define FRInternalVariableTextSetMultiLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetMultiLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetMultiLineSEL, _gPID)))

#define FRInternalVariableTextSetAutoReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetAutoReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetAutoReturnSEL, _gPID)))

#define FRInternalVariableTextSetAutoFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetAutoFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetAutoFontSizeSEL, _gPID)))

#define FRInternalVariableTextSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetFontSizeSEL, _gPID)))

#define FRInternalVariableTextSetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetLineLeadingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetLineLeadingSEL, _gPID)))

#define FRInternalVariableTextSetRichText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetRichTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetRichTextSEL, _gPID)))

#define FRInternalVariableTextSetDirectionRTL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetDirectionRTLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetDirectionRTLSEL, _gPID)))

#define FRInternalVariableTextInitialize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextInitializeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextInitializeSEL, _gPID)))

#define FRInternalVariableTextIsValid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsValidSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsValidSEL, _gPID)))

#define FRInternalVariableTextIsRichText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsRichTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsRichTextSEL, _gPID)))

#define FRInternalVariableTextRearrangeAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextRearrangeAllSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextRearrangeAllSEL, _gPID)))

#define FRInternalVariableTextRearrangePart (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextRearrangePartSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextRearrangePartSEL, _gPID)))

#define FRInternalVariableTextResetAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextResetAllSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextResetAllSEL, _gPID)))

#define FRInternalVariableTextSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSetTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSetTextSEL, _gPID)))

#define FRInternalVariableTextInsertWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextInsertWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextInsertWordSEL, _gPID)))

#define FRInternalVariableTextInsertSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextInsertSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextInsertSectionSEL, _gPID)))

#define FRInternalVariableTextInsertText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextInsertTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextInsertTextSEL, _gPID)))

#define FRInternalVariableTextDeleteWords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextDeleteWordsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextDeleteWordsSEL, _gPID)))

#define FRInternalVariableTextDeleteWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextDeleteWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextDeleteWordSEL, _gPID)))

#define FRInternalVariableTextBackSpaceWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextBackSpaceWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextBackSpaceWordSEL, _gPID)))

#define FRInternalVariableTextGetPlateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetPlateRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetPlateRectSEL, _gPID)))

#define FRInternalVariableTextGetContentRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetContentRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetContentRectSEL, _gPID)))

#define FRInternalVariableTextGetTotalWords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetTotalWordsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetTotalWordsSEL, _gPID)))

#define FRInternalVariableTextGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetFontSizeSEL, _gPID)))

#define FRInternalVariableTextGetAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetAlignmentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetAlignmentSEL, _gPID)))

#define FRInternalVariableTextGetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetWordSpaceSEL, _gPID)))

#define FRInternalVariableTextGetPasswordChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetPasswordCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetPasswordCharSEL, _gPID)))

#define FRInternalVariableTextGetCharArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetCharArraySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetCharArraySEL, _gPID)))

#define FRInternalVariableTextGetLimitChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetLimitCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetLimitCharSEL, _gPID)))

#define FRInternalVariableTextIsMultiLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsMultiLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsMultiLineSEL, _gPID)))

#define FRInternalVariableTextIsAutoReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsAutoReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsAutoReturnSEL, _gPID)))

#define FRInternalVariableTextGetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetHorzScaleSEL, _gPID)))

#define FRInternalVariableTextGetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetCharSpaceSEL, _gPID)))

#define FRInternalVariableTextGetBeginWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetBeginWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetBeginWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetEndWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetEndWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetEndWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetPrevWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetPrevWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetPrevWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetNextWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetNextWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetNextWordPlaceSEL, _gPID)))

#define FRInternalVariableTextSearchWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextSearchWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextSearchWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetUpWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetUpWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetUpWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetDownWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetDownWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetDownWordPlaceSEL, _gPID)))

#define FRInternalVariableTextGetLineBeginPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetLineBeginPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetLineBeginPlaceSEL, _gPID)))

#define FRInternalVariableTextGetLineEndPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetLineEndPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetLineEndPlaceSEL, _gPID)))

#define FRInternalVariableTextGetSectionBeginPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetSectionBeginPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetSectionBeginPlaceSEL, _gPID)))

#define FRInternalVariableTextGetSectionEndPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextGetSectionEndPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextGetSectionEndPlaceSEL, _gPID)))

#define FRInternalVariableTextUpdateWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextUpdateWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextUpdateWordPlaceSEL, _gPID)))

#define FRInternalVariableTextAjustLineHeader (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextAjustLineHeaderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextAjustLineHeaderSEL, _gPID)))

#define FRInternalVariableTextWordPlaceToWordIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextWordPlaceToWordIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextWordPlaceToWordIndexSEL, _gPID)))

#define FRInternalVariableTextWordIndexToWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextWordIndexToWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextWordIndexToWordPlaceSEL, _gPID)))

#define FRInternalVariableTextIsSectionComplexScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsSectionComplexScriptSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsSectionComplexScriptSEL, _gPID)))

#define FRInternalVariableTextIsVerticalFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalVariableTextIsVerticalFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalVariableTextIsVerticalFontSEL, _gPID)))

#define FRInternalEditFontMapGetDocFontMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetDocFontMapSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetDocFontMapSEL, _gPID)))

#define FRInternalEditFontMapEncodeFontAlias (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapEncodeFontAliasSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapEncodeFontAliasSEL, _gPID)))

#define FRInternalEditFontMapGetFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFontNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFontNameSEL, _gPID)))

#define FRInternalEditFontMapGetCharset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetCharsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetCharsetSEL, _gPID)))

#define FRInternalEditFontMapGetFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFXFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFXFontSEL, _gPID)))

#define FRInternalEditFontMapGetPDFFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetPDFFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetPDFFontSEL, _gPID)))

#define FRInternalEditFontMapGetCharWidthF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetCharWidthFSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetCharWidthFSEL, _gPID)))

#define FRInternalEditFontMapCharCodeFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapCharCodeFromUnicodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapCharCodeFromUnicodeSEL, _gPID)))

#define FRInternalEditFontMapGlyphFromCharCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGlyphFromCharCodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGlyphFromCharCodeSEL, _gPID)))

#define FRInternalEditFontMapCharSetFromUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapCharSetFromUnicodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapCharSetFromUnicodeSEL, _gPID)))

#define FRInternalEditFontMapGetFontIndexByUnicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFontIndexByUnicodeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFontIndexByUnicodeSEL, _gPID)))

#define FRInternalEditFontMapGetFontIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFontIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFontIndexSEL, _gPID)))

#define FRInternalIsEmbedded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsEmbeddedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsEmbeddedSEL, _gPID)))

#define FRInternalSetFXFMEditFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetFXFMEditFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetFXFMEditFontSEL, _gPID)))

#define FRInternalGlyphFromCharCode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGlyphFromCharCode2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGlyphFromCharCode2SEL, _gPID)))

#define FRInternalEditFontMapAddFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapAddFXFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapAddFXFontSEL, _gPID)))

#define FRInternalEditFontMapAddPDFFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapAddPDFFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapAddPDFFontSEL, _gPID)))

#define FRInternalEditFontMapGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetDocumentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetDocumentSEL, _gPID)))

#define FRInternalEditFontMapLoadAllFontByDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapLoadAllFontByDictSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapLoadAllFontByDictSEL, _gPID)))

#define FRInternalEditFontMapCheckCharacterIsSupported (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapCheckCharacterIsSupportedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapCheckCharacterIsSupportedSEL, _gPID)))

#define FRInternalEditFontMapGetStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetStandardFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetStandardFontSEL, _gPID)))

#define FRInternalEditFontMapIsExternalEmbedFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapIsExternalEmbedFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapIsExternalEmbedFontSEL, _gPID)))

#define FRInternalEditIteratorNextWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorNextWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorNextWordSEL, _gPID)))

#define FRInternalEditIteratorNextLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorNextLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorNextLineSEL, _gPID)))

#define FRInternalEditIteratorNextSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorNextSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorNextSectionSEL, _gPID)))

#define FRInternalEditIteratorPrevWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorPrevWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorPrevWordSEL, _gPID)))

#define FRInternalEditIteratorPrevLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorPrevLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorPrevLineSEL, _gPID)))

#define FRInternalEditIteratorPrevSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorPrevSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorPrevSectionSEL, _gPID)))

#define FRInternalEditIteratorGetWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetWordSEL, _gPID)))

#define FRInternalEditIteratorGetDisplayWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetDisplayWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetDisplayWordSEL, _gPID)))

#define FRInternalEditIteratorGetLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetLineSEL, _gPID)))

#define FRInternalEditIteratorGetSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetSectionSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetSectionSEL, _gPID)))

#define FRInternalEditIteratorSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorSetAtSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorSetAtSEL, _gPID)))

#define FRInternalEditIteratorSetAtII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorSetAtIISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorSetAtIISEL, _gPID)))

#define FRInternalEditIteratorGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetAtSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetAtSEL, _gPID)))

#define FRInternalEditIteratorGetEdit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIteratorGetEditSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIteratorGetEditSEL, _gPID)))

#define FRInternalEditNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditNewSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditNewSEL, _gPID)))

#define FRInternalEditDel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDelSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDelSEL, _gPID)))

#define FRInternalEditSetFontMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetFontMapSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetFontMapSEL, _gPID)))

#define FRInternalEditSetVTProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetVTProviderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetVTProviderSEL, _gPID)))

#define FRInternalEditSetNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetNotifySEL, _gPID)))

#define FRInternalEditSetOprNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetOprNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetOprNotifySEL, _gPID)))

#define FRInternalEditGetIterator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetIteratorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetIteratorSEL, _gPID)))

#define FRInternalEditGetVariableText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetVariableTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetVariableTextSEL, _gPID)))

#define FRInternalEditGetFontMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetFontMapSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetFontMapSEL, _gPID)))

#define FRInternalEditInitialize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditInitializeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditInitializeSEL, _gPID)))

#define FRInternalEditSetPlateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetPlateRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetPlateRectSEL, _gPID)))

#define FRInternalEditSetScrollPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetScrollPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetScrollPosSEL, _gPID)))

#define FRInternalEditIsVerticalWriting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsVerticalWritingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsVerticalWritingSEL, _gPID)))

#define FRInternalEditSetAlignmentH (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetAlignmentHSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetAlignmentHSEL, _gPID)))

#define FRInternalEditSetAlignmentV (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetAlignmentVSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetAlignmentVSEL, _gPID)))

#define FRInternalEditSetPasswordChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetPasswordCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetPasswordCharSEL, _gPID)))

#define FRInternalEditSetLimitChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetLimitCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetLimitCharSEL, _gPID)))

#define FRInternalEditSetCharArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetCharArraySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetCharArraySEL, _gPID)))

#define FRInternalEditSetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetCharSpaceSEL, _gPID)))

#define FRInternalEditSetWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetWordSpaceSEL, _gPID)))

#define FRInternalEditSetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetHorzScaleSEL, _gPID)))

#define FRInternalEditSetLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetLineLeadingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetLineLeadingSEL, _gPID)))

#define FRInternalEditSetMultiLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetMultiLineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetMultiLineSEL, _gPID)))

#define FRInternalEditSetAutoReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetAutoReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetAutoReturnSEL, _gPID)))

#define FRInternalEditSetAutoFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetAutoFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetAutoFontSizeSEL, _gPID)))

#define FRInternalEditSetAutoScroll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetAutoScrollSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetAutoScrollSEL, _gPID)))

#define FRInternalEditSetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetFontSizeSEL, _gPID)))

#define FRInternalEditSetTextOverflow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetTextOverflowSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetTextOverflowSEL, _gPID)))

#define FRInternalSetDirectionRTL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetDirectionRTLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetDirectionRTLSEL, _gPID)))

#define FRInternalEditIsRichText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsRichTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsRichTextSEL, _gPID)))

#define FRInternalEditSetRichText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextSEL, _gPID)))

#define FRInternalEditSetRichTextFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextFontSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextFontSEL, _gPID)))

#define FRInternalSetRichTextIsBold (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetRichTextIsBoldSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetRichTextIsBoldSEL, _gPID)))

#define FRInternalSetRichTextIsItalic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetRichTextIsItalicSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetRichTextIsItalicSEL, _gPID)))

#define FRInternalEditSetRichFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichFontSizeSEL, _gPID)))

#define FRInternalEditSetRichTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextColorSEL, _gPID)))

#define FRInternalEditSetRichTextStrokeColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextStrokeColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextStrokeColorSEL, _gPID)))

#define FRInternalEditSetRichRenderingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichRenderingModeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichRenderingModeSEL, _gPID)))

#define FRInternalEditSetRichTextScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextScriptSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextScriptSEL, _gPID)))

#define FRInternalEditSetRichTextUnderline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextUnderlineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextUnderlineSEL, _gPID)))

#define FRInternalEditSetRichTextCrossout (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextCrossoutSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextCrossoutSEL, _gPID)))

#define FRInternalEditSetRichTextCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextCharSpaceSEL, _gPID)))

#define FRInternalEditSetRichTextWordSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextWordSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextWordSpaceSEL, _gPID)))

#define FRInternalEditSetRichTextHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextHorzScaleSEL, _gPID)))

#define FRInternalEditSetRichTextLineLeading (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextLineLeadingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextLineLeadingSEL, _gPID)))

#define FRInternalEditSetRichTextLineIndent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextLineIndentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextLineIndentSEL, _gPID)))

#define FRInternalEditSetRichTextAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextAlignmentSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextAlignmentSEL, _gPID)))

#define FRInternalEditSetRichTextSoftReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextSoftReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextSoftReturnSEL, _gPID)))

#define FRInternalEditSetSel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetSelSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetSelSEL, _gPID)))

#define FRInternalEditGetSel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSelSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSelSEL, _gPID)))

#define FRInternalEditSelectAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSelectAllSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSelectAllSEL, _gPID)))

#define FRInternalEditSelectNone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSelectNoneSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSelectNoneSEL, _gPID)))

#define FRInternalEditGetCaret (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetCaretSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetCaretSEL, _gPID)))

#define FRInternalEditGetCaretWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetCaretWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetCaretWordPlaceSEL, _gPID)))

#define FRInternalEditGetSelText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSelTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSelTextSEL, _gPID)))

#define FRInternalEditGetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetTextSEL, _gPID)))

#define FRInternalEditGetRichTextXML (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetRichTextXMLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetRichTextXMLSEL, _gPID)))

#define FRInternalEditIsSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsSelectedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsSelectedSEL, _gPID)))

#define FRInternalEditGetScrollPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetScrollPosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetScrollPosSEL, _gPID)))

#define FRInternalEditGetPlateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetPlateRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetPlateRectSEL, _gPID)))

#define FRInternalEditGetContentRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetContentRectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetContentRectSEL, _gPID)))

#define FRInternalEditGetVisibleWordRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetVisibleWordRangeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetVisibleWordRangeSEL, _gPID)))

#define FRInternalEditGetWholeWordRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetWholeWordRangeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetWholeWordRangeSEL, _gPID)))

#define FRInternalEditGetSelectWordRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSelectWordRangeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSelectWordRangeSEL, _gPID)))

#define FRInternalEditOnMouseDown (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnMouseDownSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnMouseDownSEL, _gPID)))

#define FRInternalEditOnMouseMove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnMouseMoveSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnMouseMoveSEL, _gPID)))

#define FRInternalEditOnVK_UP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_UPSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_UPSEL, _gPID)))

#define FRInternalEditOnVK_DOWN (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_DOWNSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_DOWNSEL, _gPID)))

#define FRInternalEditOnVK_LEFT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_LEFTSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_LEFTSEL, _gPID)))

#define FRInternalEditOnVK_RIGHT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_RIGHTSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_RIGHTSEL, _gPID)))

#define FRInternalEditOnVK_HOME (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_HOMESELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_HOMESEL, _gPID)))

#define FRInternalEditOnVK_END (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditOnVK_ENDSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditOnVK_ENDSEL, _gPID)))

#define FRInternalEditSetText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetTextSEL, _gPID)))

#define FRInternalEditSetRichTextByXML (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetRichTextByXMLSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetRichTextByXMLSEL, _gPID)))

#define FRInternalEditInsertWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditInsertWordSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditInsertWordSEL, _gPID)))

#define FRInternalEditInsertReturn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditInsertReturnSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditInsertReturnSEL, _gPID)))

#define FRInternalEditInsertText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditInsertTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditInsertTextSEL, _gPID)))

#define FRInternalEditBackspace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditBackspaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditBackspaceSEL, _gPID)))

#define FRInternalEditDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDeleteSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDeleteSEL, _gPID)))

#define FRInternalEditClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditClearSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditClearSEL, _gPID)))

#define FRInternalEditRedo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditRedoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditRedoSEL, _gPID)))

#define FRInternalEditUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditUndoSEL, _gPID)))

#define FRInternalEditSetCaret (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetCaretSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetCaretSEL, _gPID)))

#define FRInternalEditPaint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditPaintSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditPaintSEL, _gPID)))

#define FRInternalEditEnableRefresh (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditEnableRefreshSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditEnableRefreshSEL, _gPID)))

#define FRInternalEditRefreshWordRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditRefreshWordRangeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditRefreshWordRangeSEL, _gPID)))

#define FRInternalEditEnableUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditEnableUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditEnableUndoSEL, _gPID)))

#define FRInternalEditEnableNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditEnableNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditEnableNotifySEL, _gPID)))

#define FRInternalEditEnableOprNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditEnableOprNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditEnableOprNotifySEL, _gPID)))

#define FRInternalEditWordPlaceToWordIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditWordPlaceToWordIndexSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditWordPlaceToWordIndexSEL, _gPID)))

#define FRInternalEditWordIndexToWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditWordIndexToWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditWordIndexToWordPlaceSEL, _gPID)))

#define FRInternalEditGetLineBeginPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetLineBeginPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetLineBeginPlaceSEL, _gPID)))

#define FRInternalEditGetLineEndPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetLineEndPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetLineEndPlaceSEL, _gPID)))

#define FRInternalEditGetSectionBeginPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSectionBeginPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSectionBeginPlaceSEL, _gPID)))

#define FRInternalEditGetSectionEndPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSectionEndPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSectionEndPlaceSEL, _gPID)))

#define FRInternalEditSearchWordPlace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSearchWordPlaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSearchWordPlaceSEL, _gPID)))

#define FRInternalEditGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetFontSizeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetFontSizeSEL, _gPID)))

#define FRInternalEditGetPasswordChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetPasswordCharSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetPasswordCharSEL, _gPID)))

#define FRInternalEditGetCharArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetCharArraySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetCharArraySEL, _gPID)))

#define FRInternalEditGetHorzScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetHorzScaleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetHorzScaleSEL, _gPID)))

#define FRInternalEditGetCharSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetCharSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetCharSpaceSEL, _gPID)))

#define FRInternalEditGetRangeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetRangeTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetRangeTextSEL, _gPID)))

#define FRInternalEditIsTextFull (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsTextFullSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsTextFullSEL, _gPID)))

#define FRInternalEditCanUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditCanUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditCanUndoSEL, _gPID)))

#define FRInternalEditCanRedo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditCanRedoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditCanRedoSEL, _gPID)))

#define FRInternalEditResetUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditResetUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditResetUndoSEL, _gPID)))

#define FRInternalEditIsModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsModifiedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsModifiedSEL, _gPID)))

#define FRInternalEditGetTotalWords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetTotalWordsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetTotalWordsSEL, _gPID)))

#define FRInternalEditAddUndoItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditAddUndoItemSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditAddUndoItemSEL, _gPID)))

#define FRInternalBeginGroupUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalBeginGroupUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalBeginGroupUndoSEL, _gPID)))

#define FRInternalEndGroupUndo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEndGroupUndoSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEndGroupUndoSEL, _gPID)))

#define FRInternalEditSaveLineOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSaveLineOffsetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSaveLineOffsetSEL, _gPID)))

#define FRInternalEditGetEditAppearanceStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetEditAppearanceStreamSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetEditAppearanceStreamSEL, _gPID)))

#define FRInternalEditGetRichEditAppearanceStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetRichEditAppearanceStreamSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetRichEditAppearanceStreamSEL, _gPID)))

#define FRInternalEditGetSelectAppearanceStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetSelectAppearanceStreamSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetSelectAppearanceStreamSEL, _gPID)))

#define FRInternalEditDrawEdit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDrawEditSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDrawEditSEL, _gPID)))

#define FRInternalEditDrawUnderline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDrawUnderlineSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDrawUnderlineSEL, _gPID)))

#define FRInternalEditDrawRichEdit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDrawRichEditSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDrawRichEditSEL, _gPID)))

#define FRInternalEditGeneratePageObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGeneratePageObjectsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGeneratePageObjectsSEL, _gPID)))

#define FRInternalEditGenerateRichPageObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGenerateRichPageObjectsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGenerateRichPageObjectsSEL, _gPID)))

#define FRInternalEditGenerateUnderlineObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGenerateUnderlineObjectsSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGenerateUnderlineObjectsSEL, _gPID)))

#define FRInternalEditGetRichTextPlainText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetRichTextPlainTextSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetRichTextPlainTextSEL, _gPID)))

#define FRInternalGetTouchup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetTouchupSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetTouchupSEL, _gPID)))

#define FRInternalBeginEditTextObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalBeginEditTextObjectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalBeginEditTextObjectSEL, _gPID)))

#define FRInternalEndEditTextObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEndEditTextObjectSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEndEditTextObjectSEL, _gPID)))

#define FRInternalEmailUtilSendMailUseConfig (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEmailUtilSendMailUseConfigSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEmailUtilSendMailUseConfigSEL, _gPID)))

#define FRInternalEmailUtilShowAddressBook (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEmailUtilShowAddressBookSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEmailUtilShowAddressBookSEL, _gPID)))

#define FRInternalIsKeyAndTrialValid (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsKeyAndTrialValidSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsKeyAndTrialValidSEL, _gPID)))

#define FRInternalCheckLicense (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCheckLicenseSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCheckLicenseSEL, _gPID)))

#define FRInternalEditIsPunctuation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsPunctuationSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsPunctuationSEL, _gPID)))

#define FRInternalEditIsCJK (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsCJKSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsCJKSEL, _gPID)))

#define FRInternalEditIsLatin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsLatinSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsLatinSEL, _gPID)))

#define FRInternalEditIsNeedToConvertSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditIsNeedToConvertSpaceSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditIsNeedToConvertSpaceSEL, _gPID)))

#define FRInternalGetCustomString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetCustomStringSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetCustomStringSEL, _gPID)))

#define FRInternalEditDestroyNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDestroyNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDestroyNotifySEL, _gPID)))

#define FRInternalEditDestroyOprNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDestroyOprNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDestroyOprNotifySEL, _gPID)))

#define FRInternalSetDocReviewIdentity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetDocReviewIdentitySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetDocReviewIdentitySEL, _gPID)))

#define FRInternalGetDocReviewIdentityName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetDocReviewIdentityNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetDocReviewIdentityNameSEL, _gPID)))

#define FRInternalGetDocReviewIdentityEmail (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetDocReviewIdentityEmailSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetDocReviewIdentityEmailSEL, _gPID)))

#define FRInternalHasVisibleTextObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalHasVisibleTextObjSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalHasVisibleTextObjSEL, _gPID)))

#define FRInternalGetProfStoreManager (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetProfStoreManagerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetProfStoreManagerSEL, _gPID)))

#define FRInternalProfStoreGetString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreGetStringSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreGetStringSEL, _gPID)))

#define FRInternalProfStoreGetInt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreGetIntSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreGetIntSEL, _gPID)))

#define FRInternalProfStoreGetBoolean (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreGetBooleanSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreGetBooleanSEL, _gPID)))

#define FRInternalProfStoreEnumAllKeyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreEnumAllKeyNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreEnumAllKeyNameSEL, _gPID)))

#define FRInternalProfStoreEnumKeyName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreEnumKeyNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreEnumKeyNameSEL, _gPID)))

#define FRInternalProfStoreEnumKeyValueName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreEnumKeyValueNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreEnumKeyValueNameSEL, _gPID)))

#define FRInternalProfStoreEnumKeyValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalProfStoreEnumKeyValueSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalProfStoreEnumKeyValueSEL, _gPID)))

#define FRInternalGWL10NHelperAutoResizeDropWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGWL10NHelperAutoResizeDropWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGWL10NHelperAutoResizeDropWidthSEL, _gPID)))

#define FRInternalGWL10NHelperResetItemDropWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGWL10NHelperResetItemDropWidthSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGWL10NHelperResetItemDropWidthSEL, _gPID)))

#define FRInternalGetActivePopupMenuMessageWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetActivePopupMenuMessageWndSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetActivePopupMenuMessageWndSEL, _gPID)))

#define FRInternalGetPhoneNumber (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetPhoneNumberSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetPhoneNumberSEL, _gPID)))

#define FRInternalGetEditionTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetEditionTitleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetEditionTitleSEL, _gPID)))

#define FRInternalGetEmail (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetEmailSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetEmailSEL, _gPID)))

#define FRInternalEditGetWordLatinSmallLigature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditGetWordLatinSmallLigatureSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditGetWordLatinSmallLigatureSEL, _gPID)))

#define FRInternalGetClonedDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetClonedDocSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetClonedDocSEL, _gPID)))

#define FRInternalEditFontMapReleaseDocFontMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapReleaseDocFontMapSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapReleaseDocFontMapSEL, _gPID)))

#define FRInternalCreateActionWizardHandlerMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCreateActionWizardHandlerMgrSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCreateActionWizardHandlerMgrSEL, _gPID)))

#define FRInternalDestroyActionWizardHandlerMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalDestroyActionWizardHandlerMgrSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalDestroyActionWizardHandlerMgrSEL, _gPID)))

#define FRInternalSetActionWizardHandlerMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetActionWizardHandlerMgrSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetActionWizardHandlerMgrSEL, _gPID)))

#define FRInternalGetActionWizardHandlerMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetActionWizardHandlerMgrSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetActionWizardHandlerMgrSEL, _gPID)))

#define FRInternalCreateActionWizardHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCreateActionWizardHandlerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCreateActionWizardHandlerSEL, _gPID)))

#define FRInternalDestroyActionWizardHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalDestroyActionWizardHandlerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalDestroyActionWizardHandlerSEL, _gPID)))

#define FRInternalRegisterActionWizardHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRegisterActionWizardHandlerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRegisterActionWizardHandlerSEL, _gPID)))

#define FRInternalUnRegisterActionWizardHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalUnRegisterActionWizardHandlerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalUnRegisterActionWizardHandlerSEL, _gPID)))

#define FRInternalActionWizardHandlerGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerGetNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerGetNameSEL, _gPID)))

#define FRInternalActionWizardHandlerGetCommandName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerGetCommandNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerGetCommandNameSEL, _gPID)))

#define FRInternalActionWizardHandlerGetPresetFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerGetPresetFlagSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerGetPresetFlagSEL, _gPID)))

#define FRInternalActionWizardHandlerSetting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerSettingSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerSettingSEL, _gPID)))

#define FRInternalActionWizardHandlerExecute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerExecuteSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerExecuteSEL, _gPID)))

#define FRInternalActionWizardHandlerGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerGetTitleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerGetTitleSEL, _gPID)))

#define FRInternalActionWizardHandlerNeedReopen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerNeedReopenSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerNeedReopenSEL, _gPID)))

#define FRInternalActionWizardHandlerNeedChangeExecuteDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerNeedChangeExecuteDocSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerNeedChangeExecuteDocSEL, _gPID)))

#define FRInternalExportAnnotToXFDF2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalExportAnnotToXFDF2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalExportAnnotToXFDF2SEL, _gPID)))

#define FRInternalImprotAnnotFromXFDF2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalImprotAnnotFromXFDF2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalImprotAnnotFromXFDF2SEL, _gPID)))

#define FRInternalSubscribeShowRibbonUI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSubscribeShowRibbonUISELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSubscribeShowRibbonUISEL, _gPID)))

#define FRInternalSubscribeStartWorkflow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSubscribeStartWorkflowSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSubscribeStartWorkflowSEL, _gPID)))

#define FRInternalSubscribeIsLicenseRevoked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSubscribeIsLicenseRevokedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSubscribeIsLicenseRevokedSEL, _gPID)))

#define FRInternalSubscribeShowFlash (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSubscribeShowFlashSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSubscribeShowFlashSEL, _gPID)))

#define FRInternalCPDFPluginProviderSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCPDFPluginProviderSetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCPDFPluginProviderSetSEL, _gPID)))

#define FRInternalCPDFPluginProviderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCPDFPluginProviderDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCPDFPluginProviderDestroySEL, _gPID)))

#define FRInternalCPDFPluginProviderGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCPDFPluginProviderGetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCPDFPluginProviderGetSEL, _gPID)))

#define FRInternalCPDFPluginProviderShowConnectedPDFAdDialog (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCPDFPluginProviderShowConnectedPDFAdDialogSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCPDFPluginProviderShowConnectedPDFAdDialogSEL, _gPID)))

#define FRInternalGetRemainDays (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetRemainDaysSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetRemainDaysSEL, _gPID)))

#define FRInternalCommentsAnnotSetUpdateServerTime (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCommentsAnnotSetUpdateServerTimeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCommentsAnnotSetUpdateServerTimeSEL, _gPID)))

#define FRInternalGetLicenseSN (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetLicenseSNSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetLicenseSNSEL, _gPID)))

#define FRInternalGetKeyfileType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetKeyfileTypeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetKeyfileTypeSEL, _gPID)))

#define FRInternalGetFormatSymbolString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetFormatSymbolStringSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetFormatSymbolStringSEL, _gPID)))

#define FRInternalGetLocalFormatTimeString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetLocalFormatTimeStringSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetLocalFormatTimeStringSEL, _gPID)))

#define FRInternalConvertToPDFGetFileType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalConvertToPDFGetFileTypeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalConvertToPDFGetFileTypeSEL, _gPID)))

#define FRInternalGetFileFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetFileFilterSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetFileFilterSEL, _gPID)))

#define FRInternalRegisterDocHandlerOfPDDocForActionWizard (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRegisterDocHandlerOfPDDocForActionWizardSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRegisterDocHandlerOfPDDocForActionWizardSEL, _gPID)))

#define FRInternalCommentsAnnotSetIconState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCommentsAnnotSetIconStateSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCommentsAnnotSetIconStateSEL, _gPID)))

#define FRInternalGetAnnotInputFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetAnnotInputFontNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetAnnotInputFontNameSEL, _gPID)))

#define FRInternalIsDisableCPDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsDisableCPDFSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsDisableCPDFSEL, _gPID)))

#define FRInternalRunJSPluginByFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRunJSPluginByFlagSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRunJSPluginByFlagSEL, _gPID)))

#define FRInternalRunJSPluginByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalRunJSPluginByNameSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalRunJSPluginByNameSEL, _gPID)))

#define FRInternalIsJSPanelActivated (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsJSPanelActivatedSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsJSPanelActivatedSEL, _gPID)))

#define FRInternalExpandJSPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalExpandJSPanelSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalExpandJSPanelSEL, _gPID)))

#define FRInternalEditSetDrawNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetDrawNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetDrawNotifySEL, _gPID)))

#define FRInternalEditDestroyDrawNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDestroyDrawNotifySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDestroyDrawNotifySEL, _gPID)))

#define FRInternalEmailUtilRegisterPreSendMailHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEmailUtilRegisterPreSendMailHandlerSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEmailUtilRegisterPreSendMailHandlerSEL, _gPID)))

#define FRInternalGetCurEditonTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetCurEditonTitleSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetCurEditonTitleSEL, _gPID)))

#define FRInternalIsDisableInternet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsDisableInternetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsDisableInternetSEL, _gPID)))

#define FRInternalIsUseSystemSelectionColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsUseSystemSelectionColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsUseSystemSelectionColorSEL, _gPID)))

#define FRInternalEditSetSelBkColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditSetSelBkColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditSetSelBkColorSEL, _gPID)))

#define FRInternalEditDrawRichEdit2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditDrawRichEdit2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditDrawRichEdit2SEL, _gPID)))

#define FRInternalIsJSPluginDisabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsJSPluginDisabledSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsJSPluginDisabledSEL, _gPID)))

#define FRInternalGetAccReadingOrderMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetAccReadingOrderModeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetAccReadingOrderModeSEL, _gPID)))

#define FRInternalIsAccOverrideReadingOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalIsAccOverrideReadingOrderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalIsAccOverrideReadingOrderSEL, _gPID)))

#define FRInternalGetDocAccReadingOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetDocAccReadingOrderSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetDocAccReadingOrderSEL, _gPID)))

#define FRInternalGetDocAccReadingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetDocAccReadingModeSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetDocAccReadingModeSEL, _gPID)))

#define FRInternalSetReadActivateStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetReadActivateStatusSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetReadActivateStatusSEL, _gPID)))

#define FRInternalGetReadActivateStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetReadActivateStatusSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetReadActivateStatusSEL, _gPID)))

#define FRInternalWIPPluginProviderSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWIPPluginProviderSetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWIPPluginProviderSetSEL, _gPID)))

#define FRInternalWIPPluginProviderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWIPPluginProviderDestroySELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWIPPluginProviderDestroySEL, _gPID)))

#define FRInternalWIPPluginProviderGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWIPPluginProviderGetSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWIPPluginProviderGetSEL, _gPID)))

#define FRInternalWIPPluginProviderAllowedPaste (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalWIPPluginProviderAllowedPasteSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalWIPPluginProviderAllowedPasteSEL, _gPID)))

#define FRInternalThemeCheckHCMT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeCheckHCMTSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeCheckHCMTSEL, _gPID)))

#define FRInternalThemeGetTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetTextColorSEL, _gPID)))

#define FRInternalThemeGetDisableTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetDisableTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetDisableTextColorSEL, _gPID)))

#define FRInternalThemeGetHyperlinkTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetHyperlinkTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetHyperlinkTextColorSEL, _gPID)))

#define FRInternalThemeGetSelectedTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetSelectedTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetSelectedTextColorSEL, _gPID)))

#define FRInternalThemeGetButtonTextColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetButtonTextColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetButtonTextColorSEL, _gPID)))

#define FRInternalThemeGetTooltipColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetTooltipColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetTooltipColorSEL, _gPID)))

#define FRInternalThemeGetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalThemeGetBackgroundColorSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalThemeGetBackgroundColorSEL, _gPID)))

#define FRInternalEmailUtilRegisterAttachmentNameModifier (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEmailUtilRegisterAttachmentNameModifierSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEmailUtilRegisterAttachmentNameModifierSEL, _gPID)))

#define FRInternalGetAppSaveAsLocation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetAppSaveAsLocationSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetAppSaveAsLocationSEL, _gPID)))

#define FRInternalLoadJSPlugin (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalLoadJSPluginSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalLoadJSPluginSEL, _gPID)))

#define FRInternalActionWizardHandlerIsEnableExecute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerIsEnableExecuteSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerIsEnableExecuteSEL, _gPID)))

#define FRInternalActionWizardHandlerExecuteDone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalActionWizardHandlerExecuteDoneSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalActionWizardHandlerExecuteDoneSEL, _gPID)))

#define FRInternalEditFontMapGetFontIndexByUnicode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFontIndexByUnicode2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFontIndexByUnicode2SEL, _gPID)))

#define FRInternalEditFontMapGetFontIndex2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalEditFontMapGetFontIndex2SELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalEditFontMapGetFontIndex2SEL, _gPID)))

#define FRInternalCompareGetDifInfos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCompareGetDifInfosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCompareGetDifInfosSEL, _gPID)))

#define FRInternalCompareReleaseDifInfos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCompareReleaseDifInfosSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCompareReleaseDifInfosSEL, _gPID)))

#define FRInternalCompareDrawNoteAP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalCompareDrawNoteAPSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalCompareDrawNoteAPSEL, _gPID)))

#define FRInternalGetCreationDate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetCreationDateSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetCreationDateSEL, _gPID)))

#define FRInternalSetReadStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalSetReadStatusSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalSetReadStatusSEL, _gPID)))

#define FRInternalGetReadStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRInternalGetReadStatusSELPROTO)FRCOREROUTINE(FRInternalSEL,FRInternalGetReadStatusSEL, _gPID)))

//*****************************
/* SpellCheck HFT functions */
//*****************************

#define FRSpellCheckNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckNewSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckNewSEL, _gPID)))

#define FRSpellCheckDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckDestroySELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckDestroySEL, _gPID)))

#define FRSpellCheckCheckWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckCheckWordSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckCheckWordSEL, _gPID)))

#define FRSpellCheckSuggestWords (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckSuggestWordsSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckSuggestWordsSEL, _gPID)))

#define FRSpellCheckIgnore (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckIgnoreSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckIgnoreSEL, _gPID)))

#define FRSpellCheckCheckString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckCheckStringSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckCheckStringSEL, _gPID)))

#define FRSpellCheckAddDic (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSpellCheckAddDicSELPROTO)FRCOREROUTINE(FRSpellCheckSEL,FRSpellCheckAddDicSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//*****************************
/* HTMLMgr HFT functions */
//*****************************

#define FRHTMLMgrGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrGetSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrGetSEL, _gPID)))

#define FRHTMLMgrRegisterHTMLEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrRegisterHTMLEventHandlerSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrRegisterHTMLEventHandlerSEL, _gPID)))

#define FRHTMLMgrOpenHTMLFromNewTab (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrOpenHTMLFromNewTabSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrOpenHTMLFromNewTabSEL, _gPID)))

#define FRHTMLMgrOpenHTMLDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrOpenHTMLDocumentSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrOpenHTMLDocumentSEL, _gPID)))

#define FRHTMLMgrGetActiveHtmlView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrGetActiveHtmlViewSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrGetActiveHtmlViewSEL, _gPID)))

#define FRHTMLMgrRegisterFoxitBrowserEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrRegisterFoxitBrowserEventHandlerSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrRegisterFoxitBrowserEventHandlerSEL, _gPID)))

#define FRHTMLMgrSetFoxitBrowserHome (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrSetFoxitBrowserHomeSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrSetFoxitBrowserHomeSEL, _gPID)))

#define FRHTMLMgrSetFavoritesLink (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrSetFavoritesLinkSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrSetFavoritesLinkSEL, _gPID)))

#define FRHTMLMgrGetHtmlViewFromHandle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrGetHtmlViewFromHandleSELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrGetHtmlViewFromHandleSEL, _gPID)))

#define FRHTMLMgrOpenHTMLFromNewTab2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrOpenHTMLFromNewTab2SELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrOpenHTMLFromNewTab2SEL, _gPID)))

#define FRHTMLMgrOpenHTMLDocument2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRHTMLMgrOpenHTMLDocument2SELPROTO)FRCOREROUTINE(FRHTMLMgrSEL,FRHTMLMgrOpenHTMLDocument2SEL, _gPID)))

//*****************************
/* PanelMgr HFT functions */
//*****************************

#define FRPanelMgrGetPanelMgrFromChildFrm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelMgrFromChildFrmSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelMgrFromChildFrmSEL, _gPID)))

#define FRPanelMgrNewPanelMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrNewPanelMgrSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrNewPanelMgrSEL, _gPID)))

#define FRPanelMgrDeletePanelMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrDeletePanelMgrSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrDeletePanelMgrSEL, _gPID)))

#define FRPanelMgrCreatePanelEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrCreatePanelEventHandlerSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrCreatePanelEventHandlerSEL, _gPID)))

#define FRPanelMgrDestroyPanelEventHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrDestroyPanelEventHandlerSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrDestroyPanelEventHandlerSEL, _gPID)))

#define FRPanelMgrCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrCreateSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrCreateSEL, _gPID)))

#define FRPanelMgrDockToFrameWindow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrDockToFrameWindowSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrDockToFrameWindowSEL, _gPID)))

#define FRPanelMgrAddPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrAddPanelSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrAddPanelSEL, _gPID)))

#define FRPanelMgrShowAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrShowAllPanelSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrShowAllPanelSEL, _gPID)))

#define FRPanelMgrShowPanelByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrShowPanelByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrShowPanelByNameSEL, _gPID)))

#define FRPanelMgrResetAllPanels (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrResetAllPanelsSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrResetAllPanelsSEL, _gPID)))

#define FRPanelMgrGetPanelHwndByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelHwndByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelHwndByNameSEL, _gPID)))

#define FRPanelMgrIsAllPanelHide (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrIsAllPanelHideSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrIsAllPanelHideSEL, _gPID)))

#define FRPanelMgrHasPanelFloating (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrHasPanelFloatingSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrHasPanelFloatingSEL, _gPID)))

#define FRPanelMgrIsPanelHide (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrIsPanelHideSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrIsPanelHideSEL, _gPID)))

#define FRPanelMgrGetParentFrame (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetParentFrameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetParentFrameSEL, _gPID)))

#define FRPanelMgrGetEnabledAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetEnabledAlignmentSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetEnabledAlignmentSEL, _gPID)))

#define FRPanelMgrGetPanelViewByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelViewByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelViewByNameSEL, _gPID)))

#define FRPanelMgrGetPanelNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelNameByIndexSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelNameByIndexSEL, _gPID)))

#define FRPanelMgrGetPanelCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelCountSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelCountSEL, _gPID)))

#define FRPanelMgrGetPanelTabRectByPt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelTabRectByPtSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelTabRectByPtSEL, _gPID)))

#define FRPanelMgrGetPanelTabNameByPt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelTabNameByPtSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelTabNameByPtSEL, _gPID)))

#define FRPanelMgrGetPanelTabRectByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrGetPanelTabRectByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrGetPanelTabRectByNameSEL, _gPID)))

#define FRPanelMgrHidePanelTabByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrHidePanelTabByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrHidePanelTabByNameSEL, _gPID)))

#define FRPanelMgrHasHistory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrHasHistorySELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrHasHistorySEL, _gPID)))

#define FRPanelMgrLockAllPanel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrLockAllPanelSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrLockAllPanelSEL, _gPID)))

#define FRPanelMgrShowPanelByName2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrShowPanelByName2SELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrShowPanelByName2SEL, _gPID)))

#define FRPanelMgrIsPanelSpreadOut (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrIsPanelSpreadOutSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrIsPanelSpreadOutSEL, _gPID)))

#define FRPanelMgrAddPanel2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrAddPanel2SELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrAddPanel2SEL, _gPID)))

#define FRPanelMgrRedockAllFloatToInitial (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrRedockAllFloatToInitialSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrRedockAllFloatToInitialSEL, _gPID)))

#define FRPanelMgrIsPanelFloating (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrIsPanelFloatingSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrIsPanelFloatingSEL, _gPID)))

#define FRPanelMgrShrinkPanelByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPanelMgrShrinkPanelByNameSELPROTO)FRCOREROUTINE(FRPanelMgrSEL,FRPanelMgrShrinkPanelByNameSEL, _gPID)))

//----------_V8----------
//----------_V9----------
//*****************************
/* CloudLoginProvider HFT functions */
//*****************************

#define FRCloudLoginProviderSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderSetSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderSetSEL, _gPID)))

#define FRCloudLoginProviderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderDestroySELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderDestroySEL, _gPID)))

#define FRCloudLoginProviderGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderGetSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderGetSEL, _gPID)))

#define FRCloudLoginProviderIsLogIn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderIsLogInSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderIsLogInSEL, _gPID)))

#define FRCloudLoginProviderSignIn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderSignInSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderSignInSEL, _gPID)))

#define FRCloudLoginProviderSignOut (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderSignOutSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderSignOutSEL, _gPID)))

#define FRCloudLoginProviderGetUserInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCloudLoginProviderGetUserInfoSELPROTO)FRCOREROUTINE(FRCloudLoginProviderSEL,FRCloudLoginProviderGetUserInfoSEL, _gPID)))

//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif