/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_EPUBCALLS_H
#define FPD_EPUBCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_EPUBEXPT_H
#include "fpd_epubExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_epubImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_epubTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_epubImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_epubTempl.h"

//----------_V1----------
//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//*****************************
/* EPUB HFT functions */
//*****************************

#define FPDEPUBOpen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBOpenSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBOpenSEL, _gPID)))

#define FPDEPUBReleaseDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseDocumentSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseDocumentSEL, _gPID)))

#define FPDEPUBClose (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCloseSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCloseSEL, _gPID)))

#define FPDEPUBUnLoadDocPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBUnLoadDocPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBUnLoadDocPageSEL, _gPID)))

#define FPDEPUBLoadPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBLoadPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBLoadPageSEL, _gPID)))

#define FPDEPUBUnloadPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBUnloadPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBUnloadPageSEL, _gPID)))

#define FPDEPUBLoadSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBLoadSectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBLoadSectionSEL, _gPID)))

#define FPDEPUBUnloadSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBUnloadSectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBUnloadSectionSEL, _gPID)))

#define FPDEPUBGetParser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetParserSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetParserSEL, _gPID)))

#define FPDEPUBGetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetPageSEL, _gPID)))

#define FPDEPUBGetDocumentSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetDocumentSectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetDocumentSectionSEL, _gPID)))

#define FPDEPUBCountSections (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCountSectionsSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCountSectionsSEL, _gPID)))

#define FPDEPUBGetSectionIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSectionIndexSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSectionIndexSEL, _gPID)))

#define FPDEPUBCountPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCountPagesSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCountPagesSEL, _gPID)))

#define FPDEPUBGetBookmark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkSEL, _gPID)))

#define FPDEPUBGetNamedDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetNamedDestSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetNamedDestSEL, _gPID)))

#define FPDEPUBReParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReParseSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReParseSEL, _gPID)))

#define FPDEPUBGetPageSection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetPageSectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetPageSectionSEL, _gPID)))

#define FPDEPUBGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetPageRectSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetPageRectSEL, _gPID)))

#define FPDEPUBGetParentBookmark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetParentBookmarkSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetParentBookmarkSEL, _gPID)))

#define FPDEPUBCountSubBookmarks (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCountSubBookmarksSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCountSubBookmarksSEL, _gPID)))

#define FPDEPUBGetSubBookmark (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSubBookmarkSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSubBookmarkSEL, _gPID)))

#define FPDEPUBGetBookmarkStyles (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkStylesSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkStylesSEL, _gPID)))

#define FPDEPUBGetBookmarkTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkTitleSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkTitleSEL, _gPID)))

#define FPDEPUBGetBookmarkExternalDocName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkExternalDocNameSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkExternalDocNameSEL, _gPID)))

#define FPDEPUBGetBookmarkURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkURISELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkURISEL, _gPID)))

#define FPDEPUBGetBookmarkNamedString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetBookmarkNamedStringSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetBookmarkNamedStringSEL, _gPID)))

#define FPDEPUBIsBookmarkOpened (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBIsBookmarkOpenedSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBIsBookmarkOpenedSEL, _gPID)))

#define FPDEPUBCreateTextSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCreateTextSelectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCreateTextSelectionSEL, _gPID)))

#define FPDEPUBReleaseTextSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseTextSelectionSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseTextSelectionSEL, _gPID)))

#define FPDEPUBTextSelectionAttachPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBTextSelectionAttachPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBTextSelectionAttachPageSEL, _gPID)))

#define FPDEPUBTextSelectionReset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBTextSelectionResetSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBTextSelectionResetSEL, _gPID)))

#define FPDEPUBSetSelectStartPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSetSelectStartPosSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSetSelectStartPosSEL, _gPID)))

#define FPDEPUBGetSelectStartPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSelectStartPosSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSelectStartPosSEL, _gPID)))

#define FPDEPUBGetSelectCurPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSelectCurPosSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSelectCurPosSEL, _gPID)))

#define FPDEPUBSelectWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectWordSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectWordSEL, _gPID)))

#define FPDEPUBSelectRectangleText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectRectangleTextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectRectangleTextSEL, _gPID)))

#define FPDEPUBSelectParagraphText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectParagraphTextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectParagraphTextSEL, _gPID)))

#define FPDEPUBSelectNextChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectNextCharSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectNextCharSEL, _gPID)))

#define FPDEPUBSelectPrevChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectPrevCharSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectPrevCharSEL, _gPID)))

#define FPDEPUBSelectNextWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectNextWordSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectNextWordSEL, _gPID)))

#define FPDEPUBSelectPrevWord (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectPrevWordSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectPrevWordSEL, _gPID)))

#define FPDEPUBSelectNextLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectNextLineSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectNextLineSEL, _gPID)))

#define FPDEPUBSelectPrevLine (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBSelectPrevLineSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBSelectPrevLineSEL, _gPID)))

#define FPDEPUBCountSelectRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCountSelectRectsSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCountSelectRectsSEL, _gPID)))

#define FPDEPUBGetSelectRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSelectRectSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSelectRectSEL, _gPID)))

#define FPDEPUBCopySelectText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCopySelectTextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCopySelectTextSEL, _gPID)))

#define FPDEPUBCreateTextSearch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCreateTextSearchSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCreateTextSearchSEL, _gPID)))

#define FPDEPUBReleaseTextSearch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseTextSearchSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseTextSearchSEL, _gPID)))

#define FPDEPUBTextSearchAttachPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBTextSearchAttachPageSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBTextSearchAttachPageSEL, _gPID)))

#define FPDEPUBFindFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBFindFirstSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBFindFirstSEL, _gPID)))

#define FPDEPUBFindNext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBFindNextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBFindNextSEL, _gPID)))

#define FPDEPUBFindPrev (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBFindPrevSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBFindPrevSEL, _gPID)))

#define FPDEPUBGetSearchPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSearchPosSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSearchPosSEL, _gPID)))

#define FPDEPUBCountSearchRects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCountSearchRectsSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCountSearchRectsSEL, _gPID)))

#define FPDEPUBGetSearchRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBGetSearchRectSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBGetSearchRectSEL, _gPID)))

#define FPDEPUBTransfer2DocPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBTransfer2DocPointSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBTransfer2DocPointSEL, _gPID)))

#define FPDEPUBTransfer2DocPointRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBTransfer2DocPointRectSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBTransfer2DocPointRectSEL, _gPID)))

#define FPDEPUBFDEGetPageMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBFDEGetPageMatrixSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBFDEGetPageMatrixSEL, _gPID)))

#define FPDEPUBCreateRenderDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCreateRenderDeviceSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCreateRenderDeviceSEL, _gPID)))

#define FPDEPUBReleaseRenderDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseRenderDeviceSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseRenderDeviceSEL, _gPID)))

#define FPDEPUBRenderDeviceSetClipRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBRenderDeviceSetClipRectSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBRenderDeviceSetClipRectSEL, _gPID)))

#define FPDEPUBCreateRenderContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBCreateRenderContextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBCreateRenderContextSEL, _gPID)))

#define FPDEPUBReleaseRenderContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseRenderContextSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseRenderContextSEL, _gPID)))

#define FPDEPUBRenderContextRendering (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBRenderContextRenderingSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBRenderContextRenderingSEL, _gPID)))

#define FPDEPUBDoRender (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBDoRenderSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBDoRenderSEL, _gPID)))

#define FPDEPUBEpubArgbEncode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBEpubArgbEncodeSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBEpubArgbEncodeSEL, _gPID)))

#define FPDEPUBInitFDEMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBInitFDEMgrSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBInitFDEMgrSEL, _gPID)))

#define FPDEPUBReleaseFDEMgr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDEPUBReleaseFDEMgrSELPROTO)FRCOREROUTINE(FPDEPUBSEL,FPDEPUBReleaseFDEMgrSEL, _gPID)))

//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif