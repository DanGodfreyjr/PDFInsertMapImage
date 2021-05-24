/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_DOCCALLS_H
#define FR_DOCCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_DOCEXPT_H
#include "fr_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_docImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_docTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_docImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_docTempl.h"

//----------_V1----------
//*****************************
/* Doc HFT functions */
//*****************************

#define FRDocOpenFromFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromFileSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromFileSEL, _gPID)))

#define FRDocOpenFromPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromPDDocSEL, _gPID)))

#define FRDocFromPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocFromPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocFromPDDocSEL, _gPID)))

#define FRDocClose (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCloseSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCloseSEL, _gPID)))

#define FRDocGetPDDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPDDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPDDocSEL, _gPID)))

#define FRDocSetCustomSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCustomSecuritySELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCustomSecuritySEL, _gPID)))

#define FRDocDoSave (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveSEL, _gPID)))

#define FRDocDoSaveAs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAsSEL, _gPID)))

#define FRDocSetChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetChangeMarkSEL, _gPID)))

#define FRDocGetChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetChangeMarkSEL, _gPID)))

#define FRDocClearChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocClearChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocClearChangeMarkSEL, _gPID)))

#define FRDocWillInsertPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocWillInsertPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocWillInsertPagesSEL, _gPID)))

#define FRDocDidInsertPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDidInsertPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDidInsertPagesSEL, _gPID)))

#define FRDocWillDeletePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocWillDeletePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocWillDeletePagesSEL, _gPID)))

#define FRDocDidDeletePages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDidDeletePagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDidDeletePagesSEL, _gPID)))

#define FRDocWillRotatePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocWillRotatePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocWillRotatePageSEL, _gPID)))

#define FRDocDidRotatePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDidRotatePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDidRotatePageSEL, _gPID)))

#define FRDocWillResizePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocWillResizePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocWillResizePageSEL, _gPID)))

#define FRDocDidResizePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDidResizePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDidResizePageSEL, _gPID)))

#define FRDocDoPrint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPrintSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPrintSEL, _gPID)))

#define FRDocPrintPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocPrintPagesSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocPrintPagesSEL, _gPID)))

#define FRDocPrintSetup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocPrintSetupSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocPrintSetupSEL, _gPID)))

#define FRDocCountDocViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCountDocViewsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCountDocViewsSEL, _gPID)))

#define FRDocGetDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocViewSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocViewSEL, _gPID)))

#define FRDocGetCurrentDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentDocViewSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentDocViewSEL, _gPID)))

#define FRDocGetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPermissionsSEL, _gPID)))

#define FRDocSetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetPermissionsSEL, _gPID)))

#define FRDocGetFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetFilePathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetFilePathSEL, _gPID)))

#define FRDocSetCurSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCurSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCurSelectionSEL, _gPID)))

#define FRDocAddToCurrentSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocAddToCurrentSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocAddToCurrentSelectionSEL, _gPID)))

#define FRDocRemoveFromSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveFromSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveFromSelectionSEL, _gPID)))

#define FRDocGetCurSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurSelectionSEL, _gPID)))

#define FRDocGetCurSelectionType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurSelectionTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurSelectionTypeSEL, _gPID)))

#define FRDocShowSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocShowSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocShowSelectionSEL, _gPID)))

#define FRDocClearSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocClearSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocClearSelectionSEL, _gPID)))

#define FRDocDeleteSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDeleteSelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDeleteSelectionSEL, _gPID)))

#define FRDocCopySelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCopySelectionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCopySelectionSEL, _gPID)))

#define FRDocSetCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCurCaptureSEL, _gPID)))

#define FRDocGetCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurCaptureSEL, _gPID)))

#define FRDocGetCurCaptureType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurCaptureTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurCaptureTypeSEL, _gPID)))

#define FRDocReleaseCurCapture (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReleaseCurCaptureSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReleaseCurCaptureSEL, _gPID)))

#define FRDocSetMenuEnableByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetMenuEnableByNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetMenuEnableByNameSEL, _gPID)))

#define FRDocGetParser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetParserSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetParserSEL, _gPID)))

#define FRDocGetPDFCreator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPDFCreatorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPDFCreatorSEL, _gPID)))

#define FRDocDoPrintSilently (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPrintSilentlySELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPrintSilentlySEL, _gPID)))

#define FRDocGetTextSelectTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetTextSelectToolSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetTextSelectToolSEL, _gPID)))

#define FRDocGetDocumentType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocumentTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocumentTypeSEL, _gPID)))

#define FRDocCanSecurityMethodBeModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCanSecurityMethodBeModifiedSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCanSecurityMethodBeModifiedSEL, _gPID)))

#define FRDocUpdateSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocUpdateSecurityMethodSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocUpdateSecurityMethodSEL, _gPID)))

#define FRDocIsEncrypted (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsEncryptedSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsEncryptedSEL, _gPID)))

#define FRDocRemoveSecurityMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocRemoveSecurityMethodSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocRemoveSecurityMethodSEL, _gPID)))

#define FRDocEnableRunScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocEnableRunScriptSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocEnableRunScriptSEL, _gPID)))

#define FRDocIsEnableRunScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsEnableRunScriptSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsEnableRunScriptSEL, _gPID)))

#define FRDocChangeDocShowTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocChangeDocShowTitleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocChangeDocShowTitleSEL, _gPID)))

#define FRDocIsMemoryDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsMemoryDocSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsMemoryDocSEL, _gPID)))

#define FRDocGetCurrentSecurityMethodName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentSecurityMethodNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentSecurityMethodNameSEL, _gPID)))

#define FRDocGetCurrentWndProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCurrentWndProviderSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCurrentWndProviderSEL, _gPID)))

#define FRDocSetCurrentWndProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCurrentWndProviderSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCurrentWndProviderSEL, _gPID)))

#define FRDocGetWndProviderByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetWndProviderByNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetWndProviderByNameSEL, _gPID)))

#define FRDocGetReviewType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetReviewTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetReviewTypeSEL, _gPID)))

#define FRDocSetReviewType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetReviewTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetReviewTypeSEL, _gPID)))

#define FRDocSetAppPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetAppPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetAppPermissionsSEL, _gPID)))

#define FRDocGetAppPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetAppPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetAppPermissionsSEL, _gPID)))

#define FRDocGetAppPermissionsII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetAppPermissionsIISELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetAppPermissionsIISEL, _gPID)))

#define FRDocGetPermissionsII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetPermissionsIISELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetPermissionsIISEL, _gPID)))

#define FRDocGetMergedPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetMergedPermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetMergedPermissionsSEL, _gPID)))

#define FRDocKillFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocKillFocusAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocKillFocusAnnotSEL, _gPID)))

#define FRDocSetPropertiesPDFVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetPropertiesPDFVersionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetPropertiesPDFVersionSEL, _gPID)))

#define FRDocSetPropertiesFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetPropertiesFilePathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetPropertiesFilePathSEL, _gPID)))

#define FRDocDoSaveAs2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSaveAs2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSaveAs2SEL, _gPID)))

#define FRDocShowSaveProgressCancelButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocShowSaveProgressCancelButtonSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocShowSaveProgressCancelButtonSEL, _gPID)))

#define FRDocSetInputPasswordProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetInputPasswordProcSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetInputPasswordProcSEL, _gPID)))

#define FRDocCheckInDocumentOLE (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCheckInDocumentOLESELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCheckInDocumentOLESEL, _gPID)))

#define FRDocIsShowInBrowser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsShowInBrowserSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsShowInBrowserSEL, _gPID)))

#define FRDocGetUIParentWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetUIParentWndSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetUIParentWndSEL, _gPID)))

#define FRDocGetDocFrameHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocFrameHandlerSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocFrameHandlerSEL, _gPID)))

#define FRDocCreateNewViewByWndProvider (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocCreateNewViewByWndProviderSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocCreateNewViewByWndProviderSEL, _gPID)))

#define FRDocLoadAnnots (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocLoadAnnotsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocLoadAnnotsSEL, _gPID)))

#define FRDocGetDocShowTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetDocShowTitleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetDocShowTitleSEL, _gPID)))

#define FRDocDoSave2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoSave2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoSave2SEL, _gPID)))

#define FRDocResetDocTitleColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocResetDocTitleColorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocResetDocTitleColorSEL, _gPID)))

#define FRDocSetDocTitleColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetDocTitleColorSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetDocTitleColorSEL, _gPID)))

#define FRDocGetOriginalType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetOriginalTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetOriginalTypeSEL, _gPID)))

#define FRDocSetOriginalType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetOriginalTypeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetOriginalTypeSEL, _gPID)))

#define FRDocSetFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetFocusAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetFocusAnnotSEL, _gPID)))

#define FRDocGenerateUR3Permission (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGenerateUR3PermissionSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGenerateUR3PermissionSEL, _gPID)))

#define FRDocHasRedactAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocHasRedactAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocHasRedactAnnotSEL, _gPID)))

#define FRDocGenerateRedactions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGenerateRedactionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGenerateRedactionsSEL, _gPID)))

#define FRDocReloadPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocReloadPageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocReloadPageSEL, _gPID)))

#define FRDocForbidChangeMark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocForbidChangeMarkSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocForbidChangeMarkSEL, _gPID)))

#define FRDocOpenFromPDDoc2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromPDDoc2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromPDDoc2SEL, _gPID)))

#define FRDocGetCreateDocSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCreateDocSourceSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCreateDocSourceSEL, _gPID)))

#define FRDocSetCreateDocSource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetCreateDocSourceSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetCreateDocSourceSEL, _gPID)))

#define FRDocGetCreateDocSourceFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCreateDocSourceFileNameSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCreateDocSourceFileNameSEL, _gPID)))

#define FRDocParsePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocParsePageSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocParsePageSEL, _gPID)))

#define FRDocIsValidAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsValidAnnotSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsValidAnnotSEL, _gPID)))

#define FRDocIsWillReopen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsWillReopenSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsWillReopenSEL, _gPID)))

#define FRDocOpenFromFile2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocOpenFromFile2SELPROTO)FRCOREROUTINE(FRDocSEL,FRDocOpenFromFile2SEL, _gPID)))

#define FRDocGetSignaturePermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetSignaturePermissionsSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetSignaturePermissionsSEL, _gPID)))

#define FRDocConvertPdfToOtherFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocConvertPdfToOtherFormatSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocConvertPdfToOtherFormatSEL, _gPID)))

#define FRDocDoPassWordEncrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocDoPassWordEncryptSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocDoPassWordEncryptSEL, _gPID)))

#define FRDocIsInProtectedViewMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsInProtectedViewModeSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsInProtectedViewModeSEL, _gPID)))

#define FRDocGetCreateDocSourceFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocGetCreateDocSourceFilePathSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocGetCreateDocSourceFilePathSEL, _gPID)))

#define FRDocIsImageBasedDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsImageBasedDocumentSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsImageBasedDocumentSEL, _gPID)))

#define FRDocSetDocEncrypted (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetDocEncryptedSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetDocEncryptedSEL, _gPID)))

#define FRDocIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocIsVisibleSELPROTO)FRCOREROUTINE(FRDocSEL,FRDocIsVisibleSEL, _gPID)))

#define FRDocSetDRMSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocSetDRMSecuritySELPROTO)FRCOREROUTINE(FRDocSEL,FRDocSetDRMSecuritySEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//*****************************
/* CustomSignature HFT functions */
//*****************************

#define FRCustomSignatureGenerateSignInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGenerateSignInfoSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGenerateSignInfoSEL, _gPID)))

#define FRCustomSignatureGetDefaultServer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetDefaultServerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetDefaultServerSEL, _gPID)))

#define FRCustomSignatureCreateSignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureCreateSignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureCreateSignatureHandlerSEL, _gPID)))

#define FRCustomSignatureRegisterSignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureRegisterSignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureRegisterSignatureHandlerSEL, _gPID)))

#define FRCustomSignatureDestroySignatureHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureDestroySignatureHandlerSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureDestroySignatureHandlerSEL, _gPID)))

#define FRCustomSignatureSetSignatureVerify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureSetSignatureVerifySELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureSetSignatureVerifySEL, _gPID)))

#define FRCustomSignatureGetDocSigatureCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetDocSigatureCountSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetDocSigatureCountSEL, _gPID)))

#define FRCustomSignatureGetSignatureBaseInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureGetSignatureBaseInfoSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureGetSignatureBaseInfoSEL, _gPID)))

#define FRCustomSignatureClearSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRCustomSignatureClearSignatureSELPROTO)FRCOREROUTINE(FRCustomSignatureSEL,FRCustomSignatureClearSignatureSEL, _gPID)))

//----------_V9----------
//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif