/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_DOCCALLS_H
#define FPD_DOCCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_docImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_docTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_docImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_docTempl.h"

//----------_V1----------
//*****************************
/* Doc HFT functions */
//*****************************

#define FPDDocNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocNewSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocNewSEL, _gPID)))

#define FPDDocDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocDestroySELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocDestroySEL, _gPID)))

#define FPDDocOpen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocOpenSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocOpenSEL, _gPID)))

#define FPDDocOpenMemDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocOpenMemDocumentSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocOpenMemDocumentSEL, _gPID)))

#define FPDDocStartProgressiveLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocStartProgressiveLoadSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocStartProgressiveLoadSEL, _gPID)))

#define FPDDocContinueLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocContinueLoadSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocContinueLoadSEL, _gPID)))

#define FPDDocClose (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocCloseSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocCloseSEL, _gPID)))

#define FPDDocGetRoot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetRootSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetRootSEL, _gPID)))

#define FPDDocGetInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetInfoSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetInfoSEL, _gPID)))

#define FPDDocGetID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetIDSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetIDSEL, _gPID)))

#define FPDDocGetPageCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetPageCountSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetPageCountSEL, _gPID)))

#define FPDDocGetPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetPageSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetPageSEL, _gPID)))

#define FPDDocGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetPageIndexSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetPageIndexSEL, _gPID)))

#define FPDDocGetUserPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetUserPermissionsSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetUserPermissionsSEL, _gPID)))

#define FPDDocIsOwner (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocIsOwnerSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocIsOwnerSEL, _gPID)))

#define FPDDocIsFormStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocIsFormStreamSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocIsFormStreamSEL, _gPID)))

#define FPDDocLoadFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadFontSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadFontSEL, _gPID)))

#define FPDDocLoadColorSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadColorSpaceSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadColorSpaceSEL, _gPID)))

#define FPDDocLoadPattern (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadPatternSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadPatternSEL, _gPID)))

#define FPDDocLoadImageF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadImageFSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadImageFSEL, _gPID)))

#define FPDDocLoadFontFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadFontFileSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadFontFileSEL, _gPID)))

#define FPDDocGetInfoObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetInfoObjNumSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetInfoObjNumSEL, _gPID)))

#define FPDDocGetRootObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetRootObjNumSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetRootObjNumSEL, _gPID)))

#define FPDDocEnumPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocEnumPagesSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocEnumPagesSEL, _gPID)))

#define FPDDocNewEnumPageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocNewEnumPageHandlerSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocNewEnumPageHandlerSEL, _gPID)))

#define FPDDocDeleteEnumPageHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocDeleteEnumPageHandlerSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocDeleteEnumPageHandlerSEL, _gPID)))

#define FPDDocSetRootObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocSetRootObjNumSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocSetRootObjNumSEL, _gPID)))

#define FPDDocSetInfoObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocSetInfoObjNumSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocSetInfoObjNumSEL, _gPID)))

#define FPDDocSetID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocSetIDSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocSetIDSEL, _gPID)))

#define FPDDocAddWindowsFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocAddWindowsFontSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocAddWindowsFontSEL, _gPID)))

#define FPDDocAddWindowsFontW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocAddWindowsFontWSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocAddWindowsFontWSEL, _gPID)))

#define FPDDocAddStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocAddStandardFontSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocAddStandardFontSEL, _gPID)))

#define FPDDocBuildResourceList (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocBuildResourceListSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocBuildResourceListSEL, _gPID)))

#define FPDDocCreateNewPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocCreateNewPageSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocCreateNewPageSEL, _gPID)))

#define FPDDocDeletePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocDeletePageSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocDeletePageSEL, _gPID)))

#define FPDDocConvertIndirectObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocConvertIndirectObjectsSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocConvertIndirectObjectsSEL, _gPID)))

#define FPDDocGetPageContentModify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetPageContentModifySELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetPageContentModifySEL, _gPID)))

#define FPDDocQuickSearch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocQuickSearchSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocQuickSearchSEL, _gPID)))

#define FPDDocReloadPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocReloadPagesSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocReloadPagesSEL, _gPID)))

#define FPDDocLoadDoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocLoadDocSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocLoadDocSEL, _gPID)))

#define FPDDocGetIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetIndirectObjectSEL, _gPID)))

#define FPDDocGetIndirectType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetIndirectTypeSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetIndirectTypeSEL, _gPID)))

#define FPDDocAddIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocAddIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocAddIndirectObjectSEL, _gPID)))

#define FPDDocReleaseIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocReleaseIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocReleaseIndirectObjectSEL, _gPID)))

#define FPDDocDeleteIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocDeleteIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocDeleteIndirectObjectSEL, _gPID)))

#define FPDDocImportIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocImportIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocImportIndirectObjectSEL, _gPID)))

#define FPDDocImportExternalObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocImportExternalObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocImportExternalObjectSEL, _gPID)))

#define FPDDocInsertIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocInsertIndirectObjectSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocInsertIndirectObjectSEL, _gPID)))

#define FPDDocGetLastobjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetLastobjNumSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetLastobjNumSEL, _gPID)))

#define FPDDocReloadFileStreams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocReloadFileStreamsSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocReloadFileStreamsSEL, _gPID)))

#define FPDDocGetStartPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetStartPositionSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetStartPositionSEL, _gPID)))

#define FPDDocGetNextAssoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetNextAssocSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetNextAssocSEL, _gPID)))

#define FPDDocIsModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocIsModifiedSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocIsModifiedSEL, _gPID)))

#define FPDDocClearModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocClearModifiedSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocClearModifiedSEL, _gPID)))

#define FPDDocSave (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocSaveSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocSaveSEL, _gPID)))

#define FPDDocGetParser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetParserSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetParserSEL, _gPID)))

#define FPDDocCheckSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocCheckSignatureSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocCheckSignatureSEL, _gPID)))

#define FPDDocGenerateFileID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGenerateFileIDSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGenerateFileIDSEL, _gPID)))

#define FPDDocGetReviewType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetReviewTypeSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetReviewTypeSEL, _gPID)))

#define FPDDocIsPortfolio (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocIsPortfolioSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocIsPortfolioSEL, _gPID)))

#define FPDDocRemoveUR3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocRemoveUR3SELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocRemoveUR3SEL, _gPID)))

#define FPDDocAddFXFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocAddFXFontSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocAddFXFontSEL, _gPID)))

#define FPDDocGetIndirectObjsCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocGetIndirectObjsCountSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocGetIndirectObjsCountSEL, _gPID)))

#define FPDDocSave2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocSave2SELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocSave2SEL, _gPID)))

#define FPDDocInsertDocumentAtPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocInsertDocumentAtPosSELPROTO)FRCOREROUTINE(FPDDocSEL,FPDDocInsertDocumentAtPosSEL, _gPID)))

//*****************************
/* NameTree HFT functions */
//*****************************

#define FPDNameTreeNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeNewSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeNewSEL, _gPID)))

#define FPDNameTreeNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeNew2SELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeNew2SEL, _gPID)))

#define FPDNameTreeDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeDestroySELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeDestroySEL, _gPID)))

#define FPDNameTreeLookupValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeLookupValueSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeLookupValueSEL, _gPID)))

#define FPDNameTreeLookupValueByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeLookupValueByNameSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeLookupValueByNameSEL, _gPID)))

#define FPDNameTreeLookupNamedDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeLookupNamedDestSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeLookupNamedDestSEL, _gPID)))

#define FPDNameTreeSetValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeSetValueSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeSetValueSEL, _gPID)))

#define FPDNameTreeGetIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeGetIndexSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeGetIndexSEL, _gPID)))

#define FPDNameTreeRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeRemoveSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeRemoveSEL, _gPID)))

#define FPDNameTreeGetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeGetCountSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeGetCountSEL, _gPID)))

#define FPDNameTreeGetRoot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDNameTreeGetRootSELPROTO)FRCOREROUTINE(FPDNameTreeSEL,FPDNameTreeGetRootSEL, _gPID)))

//*****************************
/* Bookmark HFT functions */
//*****************************

#define FPDBookmarkNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkNewSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkNewSEL, _gPID)))

#define FPDBookmarkDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkDestroySELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkDestroySEL, _gPID)))

#define FPDBookmarkIsVaild (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkIsVaildSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkIsVaildSEL, _gPID)))

#define FPDBookmarkGetColorRef (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetColorRefSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetColorRefSEL, _gPID)))

#define FPDBookmarkGetFontStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetFontStyleSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetFontStyleSEL, _gPID)))

#define FPDBookmarkGetTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetTitleSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetTitleSEL, _gPID)))

#define FPDBookmarkGetDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetDestSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetDestSEL, _gPID)))

#define FPDBookmarkGetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetActionSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetActionSEL, _gPID)))

#define FPDBookmarkGetDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetDictionarySELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetDictionarySEL, _gPID)))

#define FPDBookmarkGetFirstChild (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetFirstChildSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetFirstChildSEL, _gPID)))

#define FPDBookmarkGetNextSibling (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDBookmarkGetNextSiblingSELPROTO)FRCOREROUTINE(FPDBookmarkSEL,FPDBookmarkGetNextSiblingSEL, _gPID)))

//*****************************
/* Dest HFT functions */
//*****************************

#define FPDDestNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestNewSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestNewSEL, _gPID)))

#define FPDDestDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestDestroySELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestDestroySEL, _gPID)))

#define FPDDestGetRemoteName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetRemoteNameSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetRemoteNameSEL, _gPID)))

#define FPDDestGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetPageIndexSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetPageIndexSEL, _gPID)))

#define FPDDestGetPageObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetPageObjNumSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetPageObjNumSEL, _gPID)))

#define FPDDestGetZoomMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetZoomModeSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetZoomModeSEL, _gPID)))

#define FPDDestGetParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetParamSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetParamSEL, _gPID)))

#define FPDDestGetPDFObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDestGetPDFObjectSELPROTO)FRCOREROUTINE(FPDDestSEL,FPDDestGetPDFObjectSEL, _gPID)))

//*****************************
/* OCContext HFT functions */
//*****************************

#define FPDOCContextNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextNewSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextNewSEL, _gPID)))

#define FPDOCContextDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextDestroySELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextDestroySEL, _gPID)))

#define FPDOCContextGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextGetDocumentSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextGetDocumentSEL, _gPID)))

#define FPDOCContextGetUsageType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextGetUsageTypeSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextGetUsageTypeSEL, _gPID)))

#define FPDOCContextCheckOCGVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextCheckOCGVisibleSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextCheckOCGVisibleSEL, _gPID)))

#define FPDOCContextResetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextResetOCContextSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextResetOCContextSEL, _gPID)))

#define FPDOCContextSetOCGState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCContextSetOCGStateSELPROTO)FRCOREROUTINE(FPDOCContextSEL,FPDOCContextSetOCGStateSEL, _gPID)))

//*****************************
/* OCGroup HFT functions */
//*****************************

#define FPDOCGroupNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupNewSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupNewSEL, _gPID)))

#define FPDOCGroupDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupDestroySELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupDestroySEL, _gPID)))

#define FPDOCGroupGetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetNameSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetNameSEL, _gPID)))

#define FPDOCGroupSetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetNameSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupSetNameSEL, _gPID)))

#define FPDOCGroupHasIntent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupHasIntentSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupHasIntentSEL, _gPID)))

#define FPDOCGroupGetCreatorInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetCreatorInfoSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetCreatorInfoSEL, _gPID)))

#define FPDOCGroupGetLanguageInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetLanguageInfoSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetLanguageInfoSEL, _gPID)))

#define FPDOCGroupGetExportState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetExportStateSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetExportStateSEL, _gPID)))

#define FPDOCGroupGetZoomRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetZoomRangeSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetZoomRangeSEL, _gPID)))

#define FPDOCGroupGetPrintInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetPrintInfoSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetPrintInfoSEL, _gPID)))

#define FPDOCGroupGetViewState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetViewStateSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetViewStateSEL, _gPID)))

#define FPDOCGroupGetUserType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetUserTypeSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetUserTypeSEL, _gPID)))

#define FPDOCGroupGetPageElementType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetPageElementTypeSELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetPageElementTypeSEL, _gPID)))

#define FPDOCGroupGetDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupGetDictionarySELPROTO)FRCOREROUTINE(FPDOCGroupSEL,FPDOCGroupGetDictionarySEL, _gPID)))

//*****************************
/* OCGroupSet HFT functions */
//*****************************

#define FPDOCGroupSetNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetNewSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetNewSEL, _gPID)))

#define FPDOCGroupSetDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetDestroySELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetDestroySEL, _gPID)))

#define FPDOCGroupSetCountElements (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetCountElementsSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetCountElementsSEL, _gPID)))

#define FPDOCGroupSetIsSubGroupSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetIsSubGroupSetSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetIsSubGroupSetSEL, _gPID)))

#define FPDOCGroupSetGetGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetGetGroupSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetGetGroupSEL, _gPID)))

#define FPDOCGroupSetGetSubGroupSet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetGetSubGroupSetSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetGetSubGroupSetSEL, _gPID)))

#define FPDOCGroupSetFindGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetFindGroupSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetFindGroupSEL, _gPID)))

#define FPDOCGroupSetGetSubGroupSetName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCGroupSetGetSubGroupSetNameSELPROTO)FRCOREROUTINE(FPDOCGroupSetSEL,FPDOCGroupSetGetSubGroupSetNameSEL, _gPID)))

//*****************************
/* OCNotify HFT functions */
//*****************************

#define FPDOCNotifyFPD_OCNotifyNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCNotifyFPD_OCNotifyNewSELPROTO)FRCOREROUTINE(FPDOCNotifySEL,FPDOCNotifyFPD_OCNotifyNewSEL, _gPID)))

#define FPDOCNotifyFPD_OCNotifyDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCNotifyFPD_OCNotifyDestroySELPROTO)FRCOREROUTINE(FPDOCNotifySEL,FPDOCNotifyFPD_OCNotifyDestroySEL, _gPID)))

//*****************************
/* OCProperties HFT functions */
//*****************************

#define FPDOCPropertiesNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesNewSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesNewSEL, _gPID)))

#define FPDOCPropertiesDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesDestroySELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesDestroySEL, _gPID)))

#define FPDOCPropertiesGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesGetDocumentSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesGetDocumentSEL, _gPID)))

#define FPDOCPropertiesGetOCGroups (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesGetOCGroupsSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesGetOCGroupsSEL, _gPID)))

#define FPDOCPropertiesIsOCGroup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesIsOCGroupSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesIsOCGroupSEL, _gPID)))

#define FPDOCPropertiesRetrieveOCGPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesRetrieveOCGPagesSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesRetrieveOCGPagesSEL, _gPID)))

#define FPDOCPropertiesIsOCGInPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesIsOCGInPageSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesIsOCGInPageSEL, _gPID)))

#define FPDOCPropertiesGetOCGroupOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesGetOCGroupOrderSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesGetOCGroupOrderSEL, _gPID)))

#define FPDOCPropertiesCountConfigs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesCountConfigsSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesCountConfigsSEL, _gPID)))

#define FPDOCPropertiesGetConfig (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesGetConfigSELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesGetConfigSEL, _gPID)))

#define FPDOCPropertiesAddOCNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesAddOCNotifySELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesAddOCNotifySEL, _gPID)))

#define FPDOCPropertiesRemoveOCNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDOCPropertiesRemoveOCNotifySELPROTO)FRCOREROUTINE(FPDOCPropertiesSEL,FPDOCPropertiesRemoveOCNotifySEL, _gPID)))

//*****************************
/* LWinParam HFT functions */
//*****************************

#define FPDLWinParamNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamNewSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamNewSEL, _gPID)))

#define FPDLWinParamDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamDestroySELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamDestroySEL, _gPID)))

#define FPDLWinParamGetFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamGetFileNameSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamGetFileNameSEL, _gPID)))

#define FPDLWinParamSetFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamSetFileNameSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamSetFileNameSEL, _gPID)))

#define FPDLWinParamGetDefaultDirectory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamGetDefaultDirectorySELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamGetDefaultDirectorySEL, _gPID)))

#define FPDLWinParamSetDefaultDirectory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamSetDefaultDirectorySELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamSetDefaultDirectorySEL, _gPID)))

#define FPDLWinParamGetOperation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamGetOperationSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamGetOperationSEL, _gPID)))

#define FPDLWinParamSetOperation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamSetOperationSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamSetOperationSEL, _gPID)))

#define FPDLWinParamGetParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamGetParamSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamGetParamSEL, _gPID)))

#define FPDLWinParamSetParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamSetParamSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamSetParamSEL, _gPID)))

#define FPDLWinParamGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLWinParamGetDictSELPROTO)FRCOREROUTINE(FPDLWinParamSEL,FPDLWinParamGetDictSEL, _gPID)))

//*****************************
/* ActionFields HFT functions */
//*****************************

#define FPDActionFieldsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsNewSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsNewSEL, _gPID)))

#define FPDActionFieldsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsDestroySELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsDestroySEL, _gPID)))

#define FPDActionFieldsGetFieldsCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsGetFieldsCountSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsGetFieldsCountSEL, _gPID)))

#define FPDActionFieldsGetAllFields (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsGetAllFieldsSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsGetAllFieldsSEL, _gPID)))

#define FPDActionFieldsGetField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsGetFieldSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsGetFieldSEL, _gPID)))

#define FPDActionFieldsInsertField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsInsertFieldSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsInsertFieldSEL, _gPID)))

#define FPDActionFieldsRemoveField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsRemoveFieldSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsRemoveFieldSEL, _gPID)))

#define FPDActionFieldsGetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionFieldsGetActionSELPROTO)FRCOREROUTINE(FPDActionFieldsSEL,FPDActionFieldsGetActionSEL, _gPID)))

//*****************************
/* Action HFT functions */
//*****************************

#define FPDActionNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionNewSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionNewSEL, _gPID)))

#define FPDActionNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionNew2SELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionNew2SEL, _gPID)))

#define FPDActionNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionNew3SELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionNew3SEL, _gPID)))

#define FPDActionDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionDestroySELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionDestroySEL, _gPID)))

#define FPDActionGetTypeName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetTypeNameSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetTypeNameSEL, _gPID)))

#define FPDActionGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetTypeSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetTypeSEL, _gPID)))

#define FPDActionGetDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetDestSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetDestSEL, _gPID)))

#define FPDActionSetDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetDestSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetDestSEL, _gPID)))

#define FPDActionGetFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetFilePathSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetFilePathSEL, _gPID)))

#define FPDActionSetFilePath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetFilePathSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetFilePathSEL, _gPID)))

#define FPDActionGetNewWindow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetNewWindowSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetNewWindowSEL, _gPID)))

#define FPDActionSetNewWindow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetNewWindowSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetNewWindowSEL, _gPID)))

#define FPDActionGetWinParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetWinParamSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetWinParamSEL, _gPID)))

#define FPDActionSetWinParam (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetWinParamSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetWinParamSEL, _gPID)))

#define FPDActionGetURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetURISELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetURISEL, _gPID)))

#define FPDActionSetURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetURISELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetURISEL, _gPID)))

#define FPDActionGetMouseMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetMouseMapSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetMouseMapSEL, _gPID)))

#define FPDActionSetMouseMap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetMouseMapSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetMouseMapSEL, _gPID)))

#define FPDActionGetWidgets (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetWidgetsSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetWidgetsSEL, _gPID)))

#define FPDActionGetHideStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetHideStatusSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetHideStatusSEL, _gPID)))

#define FPDActionSetHideStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetHideStatusSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetHideStatusSEL, _gPID)))

#define FPDActionGetNameAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetNameActionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetNameActionSEL, _gPID)))

#define FPDActionSetNameAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetNameActionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetNameActionSEL, _gPID)))

#define FPDActionGetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetFlagsSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetFlagsSEL, _gPID)))

#define FPDActionSetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetFlagsSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetFlagsSEL, _gPID)))

#define FPDActionGetJavaScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetJavaScriptSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetJavaScriptSEL, _gPID)))

#define FPDActionSetJavaScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetJavaScriptSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetJavaScriptSEL, _gPID)))

#define FPDActionSetJavaScriptW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetJavaScriptWSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetJavaScriptWSEL, _gPID)))

#define FPDActionCountRenditions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionCountRenditionsSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionCountRenditionsSEL, _gPID)))

#define FPDActionGetRendition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetRenditionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetRenditionSEL, _gPID)))

#define FPDActionInsertRendition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionInsertRenditionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionInsertRenditionSEL, _gPID)))

#define FPDActionRemoveRendition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionRemoveRenditionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionRemoveRenditionSEL, _gPID)))

#define FPDActionGetAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetAnnotSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetAnnotSEL, _gPID)))

#define FPDActionSetAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetAnnotSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetAnnotSEL, _gPID)))

#define FPDActionGetOperationType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetOperationTypeSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetOperationTypeSEL, _gPID)))

#define FPDActionSetOperationType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetOperationTypeSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetOperationTypeSEL, _gPID)))

#define FPDActionGetSoundStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetSoundStreamSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetSoundStreamSEL, _gPID)))

#define FPDActionGetVolume (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetVolumeSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetVolumeSEL, _gPID)))

#define FPDActionIsSynchronous (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionIsSynchronousSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionIsSynchronousSEL, _gPID)))

#define FPDActionIsRepeat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionIsRepeatSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionIsRepeatSEL, _gPID)))

#define FPDActionIsMixPlay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionIsMixPlaySELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionIsMixPlaySEL, _gPID)))

#define FPDActionCountOCGStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionCountOCGStatesSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionCountOCGStatesSEL, _gPID)))

#define FPDActionGetOCGStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetOCGStatesSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetOCGStatesSEL, _gPID)))

#define FPDActionInsertOCGStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionInsertOCGStatesSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionInsertOCGStatesSEL, _gPID)))

#define FPDActionReplaceOCGStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionReplaceOCGStatesSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionReplaceOCGStatesSEL, _gPID)))

#define FPDActionRemoveOCGStates (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionRemoveOCGStatesSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionRemoveOCGStatesSEL, _gPID)))

#define FPDActionIsStatePreserved (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionIsStatePreservedSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionIsStatePreservedSEL, _gPID)))

#define FPDActionSetStatePreserved (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionSetStatePreservedSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionSetStatePreservedSEL, _gPID)))

#define FPDActionGetSubActionsCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetSubActionsCountSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetSubActionsCountSEL, _gPID)))

#define FPDActionGetSubAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetSubActionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetSubActionSEL, _gPID)))

#define FPDActionInsertSubAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionInsertSubActionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionInsertSubActionSEL, _gPID)))

#define FPDActionRemoveSubAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionRemoveSubActionSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionRemoveSubActionSEL, _gPID)))

#define FPDActionRemoveAllSubActions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionRemoveAllSubActionsSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionRemoveAllSubActionsSEL, _gPID)))

#define FPDActionGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDActionGetDictSELPROTO)FRCOREROUTINE(FPDActionSEL,FPDActionGetDictSEL, _gPID)))

//*****************************
/* AAction HFT functions */
//*****************************

#define FPDAActionNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionNewSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionNewSEL, _gPID)))

#define FPDAActionDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionDestroySELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionDestroySEL, _gPID)))

#define FPDAActionActionExist (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionActionExistSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionActionExistSEL, _gPID)))

#define FPDAActionGetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionGetActionSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionGetActionSEL, _gPID)))

#define FPDAActionSetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionSetActionSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionSetActionSEL, _gPID)))

#define FPDAActionRemoveAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionRemoveActionSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionRemoveActionSEL, _gPID)))

#define FPDAActionGetStartPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionGetStartPosSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionGetStartPosSEL, _gPID)))

#define FPDAActionGetNextAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionGetNextActionSELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionGetNextActionSEL, _gPID)))

#define FPDAActionGetDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAActionGetDictionarySELPROTO)FRCOREROUTINE(FPDAActionSEL,FPDAActionGetDictionarySEL, _gPID)))

//*****************************
/* DocJSActions HFT functions */
//*****************************

#define FPDDocJSActionsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsNewSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsNewSEL, _gPID)))

#define FPDDocJSActionsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsDestroySELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsDestroySEL, _gPID)))

#define FPDDocJSActionsCountJSActions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsCountJSActionsSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsCountJSActionsSEL, _gPID)))

#define FPDDocJSActionsGetJSAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsGetJSActionSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsGetJSActionSEL, _gPID)))

#define FPDDocJSActionsGetJSAction2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsGetJSAction2SELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsGetJSAction2SEL, _gPID)))

#define FPDDocJSActionsSetJSAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsSetJSActionSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsSetJSActionSEL, _gPID)))

#define FPDDocJSActionsFindJSAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsFindJSActionSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsFindJSActionSEL, _gPID)))

#define FPDDocJSActionsRemoveJSAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsRemoveJSActionSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsRemoveJSActionSEL, _gPID)))

#define FPDDocJSActionsGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDocJSActionsGetDocumentSELPROTO)FRCOREROUTINE(FPDDocJSActionsSEL,FPDDocJSActionsGetDocumentSEL, _gPID)))

//*****************************
/* FileSpec HFT functions */
//*****************************

#define FPDFileSpecNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecNewSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecNewSEL, _gPID)))

#define FPDFileSpecNewFromObj (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecNewFromObjSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecNewFromObjSEL, _gPID)))

#define FPDFileSpecDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecDestroySELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecDestroySEL, _gPID)))

#define FPDFileSpecIsURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecIsURLSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecIsURLSEL, _gPID)))

#define FPDFileSpecGetFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecGetFileNameSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecGetFileNameSEL, _gPID)))

#define FPDFileSpecGetFileStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecGetFileStreamSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecGetFileStreamSEL, _gPID)))

#define FPDFileSpecSetFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecSetFileNameSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecSetFileNameSEL, _gPID)))

#define FPDFileSpecSetEmbeddedFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFileSpecSetEmbeddedFileSELPROTO)FRCOREROUTINE(FPDFileSpecSEL,FPDFileSpecSetEmbeddedFileSEL, _gPID)))

//*****************************
/* MediaPlayer HFT functions */
//*****************************

#define FPDMediaPlayerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerNewSELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerNewSEL, _gPID)))

#define FPDMediaPlayerNewFromDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerNewFromDictSELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerNewFromDictSEL, _gPID)))

#define FPDMediaPlayerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerDestroySELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerDestroySEL, _gPID)))

#define FPDMediaPlayerGetSoftwareURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerGetSoftwareURISELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerGetSoftwareURISEL, _gPID)))

#define FPDMediaPlayerSetSoftwareURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerSetSoftwareURISELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerSetSoftwareURISEL, _gPID)))

#define FPDMediaPlayerGetOSArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerGetOSArraySELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerGetOSArraySEL, _gPID)))

#define FPDMediaPlayerSetOSArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDMediaPlayerSetOSArraySELPROTO)FRCOREROUTINE(FPDMediaPlayerSEL,FPDMediaPlayerSetOSArraySEL, _gPID)))

//*****************************
/* Rendition HFT functions */
//*****************************

#define FPDRenditionNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionNewSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionNewSEL, _gPID)))

#define FPDRenditionNewFromDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionNewFromDictSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionNewFromDictSEL, _gPID)))

#define FPDRenditionDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionDestroySELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionDestroySEL, _gPID)))

#define FPDRenditionHasMediaClip (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionHasMediaClipSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionHasMediaClipSEL, _gPID)))

#define FPDRenditionGetRenditionName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetRenditionNameSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetRenditionNameSEL, _gPID)))

#define FPDRenditionSetRenditionName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetRenditionNameSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetRenditionNameSEL, _gPID)))

#define FPDRenditionGetMediaClipName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaClipNameSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaClipNameSEL, _gPID)))

#define FPDRenditionSetMediaClipName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMediaClipNameSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMediaClipNameSEL, _gPID)))

#define FPDRenditionGetMediaClipFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaClipFileSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaClipFileSEL, _gPID)))

#define FPDRenditionSetMediaClipFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMediaClipFileSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMediaClipFileSEL, _gPID)))

#define FPDRenditionGetMediaClipContentType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaClipContentTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaClipContentTypeSEL, _gPID)))

#define FPDRenditionSetMediaClipContentType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMediaClipContentTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMediaClipContentTypeSEL, _gPID)))

#define FPDRenditionGetPermission (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetPermissionSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetPermissionSEL, _gPID)))

#define FPDRenditionSetPermission (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetPermissionSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetPermissionSEL, _gPID)))

#define FPDRenditionGetMediaDescriptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaDescriptionsSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaDescriptionsSEL, _gPID)))

#define FPDRenditionSetMediaDescriptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMediaDescriptionsSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMediaDescriptionsSEL, _gPID)))

#define FPDRenditionGetMediaBaseURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaBaseURLSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaBaseURLSEL, _gPID)))

#define FPDRenditionSetMediaBaseURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMediaBaseURLSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMediaBaseURLSEL, _gPID)))

#define FPDRenditionCountMediaPlayers (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionCountMediaPlayersSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionCountMediaPlayersSEL, _gPID)))

#define FPDRenditionGetMediaPlayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMediaPlayerSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMediaPlayerSEL, _gPID)))

#define FPDRenditionAddMediaPlayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionAddMediaPlayerSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionAddMediaPlayerSEL, _gPID)))

#define FPDRenditionRemoveMediaPlayer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionRemoveMediaPlayerSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionRemoveMediaPlayerSEL, _gPID)))

#define FPDRenditionGetVolumn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetVolumnSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetVolumnSEL, _gPID)))

#define FPDRenditionSetVolumn (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetVolumnSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetVolumnSEL, _gPID)))

#define FPDRenditionIsControlBarVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionIsControlBarVisibleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionIsControlBarVisibleSEL, _gPID)))

#define FPDRenditionEnableControlBarVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionEnableControlBarVisibleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionEnableControlBarVisibleSEL, _gPID)))

#define FPDRenditionGetFitStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFitStyleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFitStyleSEL, _gPID)))

#define FPDRenditionSetFitStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFitStyleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFitStyleSEL, _gPID)))

#define FPDRenditionGetDuration (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetDurationSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetDurationSEL, _gPID)))

#define FPDRenditionSetDuration (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetDurationSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetDurationSEL, _gPID)))

#define FPDRenditionAutoPlay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionAutoPlaySELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionAutoPlaySEL, _gPID)))

#define FPDRenditionEnableAutoPlay (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionEnableAutoPlaySELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionEnableAutoPlaySEL, _gPID)))

#define FPDRenditionRepeatCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionRepeatCountSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionRepeatCountSEL, _gPID)))

#define FPDRenditionSetRepeatCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetRepeatCountSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetRepeatCountSEL, _gPID)))

#define FPDRenditionGetWindowStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetWindowStatusSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetWindowStatusSEL, _gPID)))

#define FPDRenditionSetWindowStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetWindowStatusSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetWindowStatusSEL, _gPID)))

#define FPDRenditionGetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetBackgroundColorSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetBackgroundColorSEL, _gPID)))

#define FPDRenditionSetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetBackgroundColorSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetBackgroundColorSEL, _gPID)))

#define FPDRenditionGetBackgroundOpacity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetBackgroundOpacitySELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetBackgroundOpacitySEL, _gPID)))

#define FPDRenditionSetBackgroundOpacity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetBackgroundOpacitySELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetBackgroundOpacitySEL, _gPID)))

#define FPDRenditionGetMonitor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetMonitorSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetMonitorSEL, _gPID)))

#define FPDRenditionSetMonitor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetMonitorSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetMonitorSEL, _gPID)))

#define FPDRenditionGetFloatingWindowSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowSizeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowSizeSEL, _gPID)))

#define FPDRenditionSetFloatingWindowSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowSizeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowSizeSEL, _gPID)))

#define FPDRenditionGetFloatingWindowRelativeType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowRelativeTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowRelativeTypeSEL, _gPID)))

#define FPDRenditionSetFloatingWindowRelativeType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowRelativeTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowRelativeTypeSEL, _gPID)))

#define FPDRenditionGetFloatingWindowPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowPositionSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowPositionSEL, _gPID)))

#define FPDRenditionSetFloatingWindowPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowPositionSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowPositionSEL, _gPID)))

#define FPDRenditionGetFloatingWindowOffscreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowOffscreenSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowOffscreenSEL, _gPID)))

#define FPDRenditionSetFloatingWindowOffscreen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowOffscreenSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowOffscreenSEL, _gPID)))

#define FPDRenditionHasFloatingWindowTitleBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionHasFloatingWindowTitleBarSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionHasFloatingWindowTitleBarSEL, _gPID)))

#define FPDRenditionEnableFloatingWindowTitleBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionEnableFloatingWindowTitleBarSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionEnableFloatingWindowTitleBarSEL, _gPID)))

#define FPDRenditionHasFloatingWindowCloseButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionHasFloatingWindowCloseButtonSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionHasFloatingWindowCloseButtonSEL, _gPID)))

#define FPDRenditionEnableFloatingWindowCloseButton (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionEnableFloatingWindowCloseButtonSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionEnableFloatingWindowCloseButtonSEL, _gPID)))

#define FPDRenditionGetFloatingWindowResizeType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowResizeTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowResizeTypeSEL, _gPID)))

#define FPDRenditionSetFloatingWindowResizeType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowResizeTypeSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowResizeTypeSEL, _gPID)))

#define FPDRenditionGetFloatingWindowTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionGetFloatingWindowTitleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionGetFloatingWindowTitleSEL, _gPID)))

#define FPDRenditionSetFloatingWindowTitle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDRenditionSetFloatingWindowTitleSELPROTO)FRCOREROUTINE(FPDRenditionSEL,FPDRenditionSetFloatingWindowTitleSEL, _gPID)))

//*****************************
/* Link HFT functions */
//*****************************

#define FPDLinkNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkNewSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkNewSEL, _gPID)))

#define FPDLinkDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkDestroySELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkDestroySEL, _gPID)))

#define FPDLinkGetLinkAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkGetLinkAtPointSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkGetLinkAtPointSEL, _gPID)))

#define FPDLinkCountLinks (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkCountLinksSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkCountLinksSEL, _gPID)))

#define FPDLinkGetLink (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkGetLinkSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkGetLinkSEL, _gPID)))

#define FPDLinkGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkGetRectSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkGetRectSEL, _gPID)))

#define FPDLinkGetDest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkGetDestSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkGetDestSEL, _gPID)))

#define FPDLinkGetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDLinkGetActionSELPROTO)FRCOREROUTINE(FPDLinkSEL,FPDLinkGetActionSEL, _gPID)))

//*****************************
/* Annot HFT functions */
//*****************************

#define FPDAnnotNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotNewSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotNewSEL, _gPID)))

#define FPDAnnotDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotDestroySELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotDestroySEL, _gPID)))

#define FPDAnnotGetAnnotDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetAnnotDictSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetAnnotDictSEL, _gPID)))

#define FPDAnnotGetSubType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetSubTypeSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetSubTypeSEL, _gPID)))

#define FPDAnnotGetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetFlagsSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetFlagsSEL, _gPID)))

#define FPDAnnotGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetRectSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetRectSEL, _gPID)))

#define FPDAnnotDrawAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotDrawAppearanceSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotDrawAppearanceSEL, _gPID)))

#define FPDAnnotDrawInContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotDrawInContextSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotDrawInContextSEL, _gPID)))

#define FPDAnnotClearCachedAP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotClearCachedAPSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotClearCachedAPSEL, _gPID)))

#define FPDAnnotDrawBorder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotDrawBorderSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotDrawBorderSEL, _gPID)))

#define FPDAnnotCountIRTNotes (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotCountIRTNotesSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotCountIRTNotesSEL, _gPID)))

#define FPDAnnotGetIRTNote (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetIRTNoteSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetIRTNoteSEL, _gPID)))

#define FPDAnnotGetAPForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotGetAPFormSELPROTO)FRCOREROUTINE(FPDAnnotSEL,FPDAnnotGetAPFormSEL, _gPID)))

//*****************************
/* AnnotList HFT functions */
//*****************************

#define FPDAnnotListNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListNewSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListNewSEL, _gPID)))

#define FPDAnnotListDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListDestroySELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListDestroySEL, _gPID)))

#define FPDAnnotListDisplayAnnots (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListDisplayAnnotsSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListDisplayAnnotsSEL, _gPID)))

#define FPDAnnotListDisplayAnnotsEx (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListDisplayAnnotsExSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListDisplayAnnotsExSEL, _gPID)))

#define FPDAnnotListGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListGetAtSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListGetAtSEL, _gPID)))

#define FPDAnnotListCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListCountSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListCountSEL, _gPID)))

#define FPDAnnotListGetIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListGetIndexSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListGetIndexSEL, _gPID)))

#define FPDAnnotListRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListRemoveAllSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListRemoveAllSEL, _gPID)))

#define FPDAnnotListReplace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListReplaceSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListReplaceSEL, _gPID)))

#define FPDAnnotListInsert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListInsertSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListInsertSEL, _gPID)))

#define FPDAnnotListRemove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListRemoveSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListRemoveSEL, _gPID)))

#define FPDAnnotListRemoveTemp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListRemoveTempSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListRemoveTempSEL, _gPID)))

#define FPDAnnotListMoveToFirst (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListMoveToFirstSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListMoveToFirstSEL, _gPID)))

#define FPDAnnotListMoveToLast (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListMoveToLastSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListMoveToLastSEL, _gPID)))

#define FPDAnnotListMoveTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListMoveToSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListMoveToSEL, _gPID)))

#define FPDAnnotListGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListGetDocumentSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListGetDocumentSEL, _gPID)))

#define FPDAnnotListSetFixedIconParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListSetFixedIconParamsSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListSetFixedIconParamsSEL, _gPID)))

#define FPDAnnotListGetAnnotMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListGetAnnotMatrixSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListGetAnnotMatrixSEL, _gPID)))

#define FPDAnnotListGetAnnotRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDAnnotListGetAnnotRectSELPROTO)FRCOREROUTINE(FPDAnnotListSEL,FPDAnnotListGetAnnotRectSEL, _gPID)))

//*****************************
/* DefaultAppearance HFT functions */
//*****************************

#define FPDDefaultAppearanceNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceNewSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceNewSEL, _gPID)))

#define FPDDefaultAppearanceDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceDestroySELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceDestroySEL, _gPID)))

#define FPDDefaultAppearanceHasFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceHasFontSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceHasFontSEL, _gPID)))

#define FPDDefaultAppearanceGetFontString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetFontStringSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetFontStringSEL, _gPID)))

#define FPDDefaultAppearanceGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetFontSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetFontSEL, _gPID)))

#define FPDDefaultAppearanceSetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceSetFontSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceSetFontSEL, _gPID)))

#define FPDDefaultAppearanceHasColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceHasColorSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceHasColorSEL, _gPID)))

#define FPDDefaultAppearanceGetColorString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetColorStringSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetColorStringSEL, _gPID)))

#define FPDDefaultAppearanceGetColorInclueCMYK (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetColorInclueCMYKSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetColorInclueCMYKSEL, _gPID)))

#define FPDDefaultAppearanceGetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetColorSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetColorSEL, _gPID)))

#define FPDDefaultAppearanceSetColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceSetColorSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceSetColorSEL, _gPID)))

#define FPDDefaultAppearanceHasTextMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceHasTextMatrixSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceHasTextMatrixSEL, _gPID)))

#define FPDDefaultAppearanceGetTextMatrixString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetTextMatrixStringSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetTextMatrixStringSEL, _gPID)))

#define FPDDefaultAppearanceGetTextMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceGetTextMatrixSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceGetTextMatrixSEL, _gPID)))

#define FPDDefaultAppearanceSetTextMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDDefaultAppearanceSetTextMatrixSELPROTO)FRCOREROUTINE(FPDDefaultAppearanceSEL,FPDDefaultAppearanceSetTextMatrixSEL, _gPID)))

//*****************************
/* FormNotify HFT functions */
//*****************************

#define FPDFormNotifyNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormNotifyNewSELPROTO)FRCOREROUTINE(FPDFormNotifySEL,FPDFormNotifyNewSEL, _gPID)))

#define FPDFormNotifyDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormNotifyDestroySELPROTO)FRCOREROUTINE(FPDFormNotifySEL,FPDFormNotifyDestroySEL, _gPID)))

//*****************************
/* InterForm HFT functions */
//*****************************

#define FPDInterFormNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormNewSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormNewSEL, _gPID)))

#define FPDInterFormDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormDestroySELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormDestroySEL, _gPID)))

#define FPDInterFormEnableUpdateAP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormEnableUpdateAPSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormEnableUpdateAPSEL, _gPID)))

#define FPDInterFormUpdatingAPEnabled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormUpdatingAPEnabledSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormUpdatingAPEnabledSEL, _gPID)))

#define FPDInterFormGenerateNewResourceName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGenerateNewResourceNameSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGenerateNewResourceNameSEL, _gPID)))

#define FPDInterFormAddSystemDefaultFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddSystemDefaultFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddSystemDefaultFontSEL, _gPID)))

#define FPDInterFormAddSystemFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddSystemFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddSystemFontSEL, _gPID)))

#define FPDInterFormAddSystemFontW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddSystemFontWSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddSystemFontWSEL, _gPID)))

#define FPDInterFormAddStandardFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddStandardFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddStandardFontSEL, _gPID)))

#define FPDInterFormGetNativeFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetNativeFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetNativeFontSEL, _gPID)))

#define FPDInterFormGetNativeFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetNativeFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetNativeFont2SEL, _gPID)))

#define FPDInterFormAddNativeFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddNativeFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddNativeFontSEL, _gPID)))

#define FPDInterFormAddNativeFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddNativeFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddNativeFont2SEL, _gPID)))

#define FPDInterFormValidateFieldName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormValidateFieldNameSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormValidateFieldNameSEL, _gPID)))

#define FPDInterFormValidateFieldName2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormValidateFieldName2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormValidateFieldName2SEL, _gPID)))

#define FPDInterFormValidateFieldName3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormValidateFieldName3SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormValidateFieldName3SEL, _gPID)))

#define FPDInterFormNewField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormNewFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormNewFieldSEL, _gPID)))

#define FPDInterFormNewControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormNewControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormNewControlSEL, _gPID)))

#define FPDInterFormCountFields (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountFieldsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountFieldsSEL, _gPID)))

#define FPDInterFormGetField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFieldSEL, _gPID)))

#define FPDInterFormGetAllFieldNames (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetAllFieldNamesSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetAllFieldNamesSEL, _gPID)))

#define FPDInterFormIsValidFormField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormIsValidFormFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormIsValidFormFieldSEL, _gPID)))

#define FPDInterFormGetFieldByDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFieldByDictSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFieldByDictSEL, _gPID)))

#define FPDInterFormCountControls (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountControlsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountControlsSEL, _gPID)))

#define FPDInterFormGetControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetControlSEL, _gPID)))

#define FPDInterFormIsValidFormControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormIsValidFormControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormIsValidFormControlSEL, _gPID)))

#define FPDInterFormCountPageControls (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountPageControlsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountPageControlsSEL, _gPID)))

#define FPDInterFormGetPageControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetPageControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetPageControlSEL, _gPID)))

#define FPDInterFormGetControlAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetControlAtPointSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetControlAtPointSEL, _gPID)))

#define FPDInterFormGetControlByDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetControlByDictSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetControlByDictSEL, _gPID)))

#define FPDInterFormRenameField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRenameFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRenameFieldSEL, _gPID)))

#define FPDInterFormRenameField2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRenameField2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRenameField2SEL, _gPID)))

#define FPDInterFormRenameControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRenameControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRenameControlSEL, _gPID)))

#define FPDInterFormDeleteField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormDeleteFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormDeleteFieldSEL, _gPID)))

#define FPDInterFormDeleteField2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormDeleteField2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormDeleteField2SEL, _gPID)))

#define FPDInterFormDeleteControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormDeleteControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormDeleteControlSEL, _gPID)))

#define FPDInterFormCountInternalFields (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountInternalFieldsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountInternalFieldsSEL, _gPID)))

#define FPDInterFormGetInternalField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetInternalFieldSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetInternalFieldSEL, _gPID)))

#define FPDInterFormGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetDocumentSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetDocumentSEL, _gPID)))

#define FPDInterFormGetFormDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormDictSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormDictSEL, _gPID)))

#define FPDInterFormNeedConstructAP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormNeedConstructAPSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormNeedConstructAPSEL, _gPID)))

#define FPDInterFormNeedConstructAP2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormNeedConstructAP2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormNeedConstructAP2SEL, _gPID)))

#define FPDInterFormCountFieldsInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountFieldsInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountFieldsInCalculationOrderSEL, _gPID)))

#define FPDInterFormGetFieldInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFieldInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFieldInCalculationOrderSEL, _gPID)))

#define FPDInterFormFindFieldInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormFindFieldInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormFindFieldInCalculationOrderSEL, _gPID)))

#define FPDInterFormInsertFieldInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormInsertFieldInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormInsertFieldInCalculationOrderSEL, _gPID)))

#define FPDInterFormMoveFieldInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormMoveFieldInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormMoveFieldInCalculationOrderSEL, _gPID)))

#define FPDInterFormRemoveFieldInCalculationOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRemoveFieldInCalculationOrderSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRemoveFieldInCalculationOrderSEL, _gPID)))

#define FPDInterFormCountFormFonts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCountFormFontsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCountFormFontsSEL, _gPID)))

#define FPDInterFormGetFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormFontSEL, _gPID)))

#define FPDInterFormGetFormFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormFont2SEL, _gPID)))

#define FPDInterFormGetFormFont3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormFont3SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormFont3SEL, _gPID)))

#define FPDInterFormGetNativeFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetNativeFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetNativeFormFontSEL, _gPID)))

#define FPDInterFormGetNativeFormFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetNativeFormFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetNativeFormFont2SEL, _gPID)))

#define FPDInterFormFindFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormFindFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormFindFormFontSEL, _gPID)))

#define FPDInterFormFindFormFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormFindFormFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormFindFormFont2SEL, _gPID)))

#define FPDInterFormFindFormFont3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormFindFormFont3SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormFindFormFont3SEL, _gPID)))

#define FPDInterFormAddFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddFormFontSEL, _gPID)))

#define FPDInterFormAddNativeFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddNativeFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddNativeFormFontSEL, _gPID)))

#define FPDInterFormAddNativeFormFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddNativeFormFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddNativeFormFont2SEL, _gPID)))

#define FPDInterFormRemoveFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRemoveFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRemoveFormFontSEL, _gPID)))

#define FPDInterFormRemoveFormFont2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormRemoveFormFont2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormRemoveFormFont2SEL, _gPID)))

#define FPDInterFormGetDefaultAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetDefaultAppearanceSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetDefaultAppearanceSEL, _gPID)))

#define FPDInterFormSetDefaultAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormSetDefaultAppearanceSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormSetDefaultAppearanceSEL, _gPID)))

#define FPDInterFormGetDefaultFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetDefaultFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetDefaultFormFontSEL, _gPID)))

#define FPDInterFormSetDefaultFormFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormSetDefaultFormFontSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormSetDefaultFormFontSEL, _gPID)))

#define FPDInterFormGetFormAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormAlignmentSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormAlignmentSEL, _gPID)))

#define FPDInterFormSetFormAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormSetFormAlignmentSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormSetFormAlignmentSEL, _gPID)))

#define FPDInterFormCheckRequiredFields (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormCheckRequiredFieldsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormCheckRequiredFieldsSEL, _gPID)))

#define FPDInterFormExportToFDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormExportToFDFSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormExportToFDFSEL, _gPID)))

#define FPDInterFormExportToFDF2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormExportToFDF2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormExportToFDF2SEL, _gPID)))

#define FPDInterFormImportFromFDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormImportFromFDFSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormImportFromFDFSEL, _gPID)))

#define FPDInterFormResetForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormResetFormSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormResetFormSEL, _gPID)))

#define FPDInterFormResetForm2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormResetForm2SELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormResetForm2SEL, _gPID)))

#define FPDInterFormReloadForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormReloadFormSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormReloadFormSEL, _gPID)))

#define FPDInterFormGetFormNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetFormNotifySELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetFormNotifySEL, _gPID)))

#define FPDInterFormSetFormNotify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormSetFormNotifySELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormSetFormNotifySEL, _gPID)))

#define FPDInterFormGetPageWithWidget (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormGetPageWithWidgetSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormGetPageWithWidgetSEL, _gPID)))

#define FPDInterFormIsUpdated (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormIsUpdatedSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormIsUpdatedSEL, _gPID)))

#define FPDInterFormClearUpdatedFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormClearUpdatedFlagSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormClearUpdatedFlagSEL, _gPID)))

#define FPDInterFormFixPageFields (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormFixPageFieldsSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormFixPageFieldsSEL, _gPID)))

#define FPDInterFormAddControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDInterFormAddControlSELPROTO)FRCOREROUTINE(FPDInterFormSEL,FPDInterFormAddControlSEL, _gPID)))

//*****************************
/* FormField HFT functions */
//*****************************

#define FPDFormFieldGetFullName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFullNameSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFullNameSEL, _gPID)))

#define FPDFormFieldGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetTypeSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetTypeSEL, _gPID)))

#define FPDFormFieldGetFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFlagsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFlagsSEL, _gPID)))

#define FPDFormFieldGetInterForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetInterFormSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetInterFormSEL, _gPID)))

#define FPDFormFieldGetFieldDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFieldDictSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFieldDictSEL, _gPID)))

#define FPDFormFieldResetField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldResetFieldSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldResetFieldSEL, _gPID)))

#define FPDFormFieldCountControls (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldCountControlsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldCountControlsSEL, _gPID)))

#define FPDFormFieldGetControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetControlSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetControlSEL, _gPID)))

#define FPDFormFieldGetControlIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetControlIndexSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetControlIndexSEL, _gPID)))

#define FPDFormFieldGetFieldType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFieldTypeSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFieldTypeSEL, _gPID)))

#define FPDFormFieldGetAdditionalAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetAdditionalActionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetAdditionalActionSEL, _gPID)))

#define FPDFormFieldSetAdditionalAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetAdditionalActionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetAdditionalActionSEL, _gPID)))

#define FPDFormFieldGetAlternateName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetAlternateNameSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetAlternateNameSEL, _gPID)))

#define FPDFormFieldSetAlternateName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetAlternateNameSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetAlternateNameSEL, _gPID)))

#define FPDFormFieldSetAlternateNameW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetAlternateNameWSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetAlternateNameWSEL, _gPID)))

#define FPDFormFieldGetMappingName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetMappingNameSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetMappingNameSEL, _gPID)))

#define FPDFormFieldSetMappingName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetMappingNameSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetMappingNameSEL, _gPID)))

#define FPDFormFieldSetMappingNameW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetMappingNameWSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetMappingNameWSEL, _gPID)))

#define FPDFormFieldGetFieldFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFieldFlagsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFieldFlagsSEL, _gPID)))

#define FPDFormFieldSetFieldFlags (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetFieldFlagsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetFieldFlagsSEL, _gPID)))

#define FPDFormFieldGetDefaultStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetDefaultStyleSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetDefaultStyleSEL, _gPID)))

#define FPDFormFieldSetDefaultStyle (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetDefaultStyleSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetDefaultStyleSEL, _gPID)))

#define FPDFormFieldGetRichTextString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetRichTextStringSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetRichTextStringSEL, _gPID)))

#define FPDFormFieldSetRichTextString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetRichTextStringSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetRichTextStringSEL, _gPID)))

#define FPDFormFieldSetRichTextStringW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetRichTextStringWSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetRichTextStringWSEL, _gPID)))

#define FPDFormFieldGetValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetValueSEL, _gPID)))

#define FPDFormFieldGetDefaultValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetDefaultValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetDefaultValueSEL, _gPID)))

#define FPDFormFieldSetValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetValueSEL, _gPID)))

#define FPDFormFieldSetDefaultValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetDefaultValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetDefaultValueSEL, _gPID)))

#define FPDFormFieldGetMaxLen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetMaxLenSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetMaxLenSEL, _gPID)))

#define FPDFormFieldSetMaxLen (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetMaxLenSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetMaxLenSEL, _gPID)))

#define FPDFormFieldCountSelectedItems (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldCountSelectedItemsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldCountSelectedItemsSEL, _gPID)))

#define FPDFormFieldGetSelectedIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetSelectedIndexSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetSelectedIndexSEL, _gPID)))

#define FPDFormFieldClearSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldClearSelectionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldClearSelectionSEL, _gPID)))

#define FPDFormFieldIsItemSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldIsItemSelectedSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldIsItemSelectedSEL, _gPID)))

#define FPDFormFieldSetItemSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetItemSelectionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetItemSelectionSEL, _gPID)))

#define FPDFormFieldIsItemDefaultSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldIsItemDefaultSelectedSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldIsItemDefaultSelectedSEL, _gPID)))

#define FPDFormFieldSetItemDefaultSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetItemDefaultSelectionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetItemDefaultSelectionSEL, _gPID)))

#define FPDFormFieldGetDefaultSelectedItem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetDefaultSelectedItemSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetDefaultSelectedItemSEL, _gPID)))

#define FPDFormFieldCountOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldCountOptionsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldCountOptionsSEL, _gPID)))

#define FPDFormFieldGetOptionLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetOptionLabelSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetOptionLabelSEL, _gPID)))

#define FPDFormFieldGetOptionValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetOptionValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetOptionValueSEL, _gPID)))

#define FPDFormFieldInsertOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldInsertOptionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldInsertOptionSEL, _gPID)))

#define FPDFormFieldFindOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldFindOptionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldFindOptionSEL, _gPID)))

#define FPDFormFieldFindOptionValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldFindOptionValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldFindOptionValueSEL, _gPID)))

#define FPDFormFieldSetOptionLabel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetOptionLabelSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetOptionLabelSEL, _gPID)))

#define FPDFormFieldSetOptionValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetOptionValueSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetOptionValueSEL, _gPID)))

#define FPDFormFieldDeleteOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldDeleteOptionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldDeleteOptionSEL, _gPID)))

#define FPDFormFieldClearOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldClearOptionsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldClearOptionsSEL, _gPID)))

#define FPDFormFieldCheckControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldCheckControlSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldCheckControlSEL, _gPID)))

#define FPDFormFieldDefaultCheckControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldDefaultCheckControlSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldDefaultCheckControlSEL, _gPID)))

#define FPDFormFieldUpdateUnisonStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldUpdateUnisonStatusSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldUpdateUnisonStatusSEL, _gPID)))

#define FPDFormFieldGetTopVisibleIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetTopVisibleIndexSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetTopVisibleIndexSEL, _gPID)))

#define FPDFormFieldSetTopVisibleIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSetTopVisibleIndexSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSetTopVisibleIndexSEL, _gPID)))

#define FPDFormFieldCountSelectedOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldCountSelectedOptionsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldCountSelectedOptionsSEL, _gPID)))

#define FPDFormFieldGetSelectedOptionIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetSelectedOptionIndexSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetSelectedOptionIndexSEL, _gPID)))

#define FPDFormFieldIsOptionSelected (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldIsOptionSelectedSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldIsOptionSelectedSEL, _gPID)))

#define FPDFormFieldSelectOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldSelectOptionSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldSelectOptionSEL, _gPID)))

#define FPDFormFieldClearSelectedOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldClearSelectedOptionsSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldClearSelectedOptionsSEL, _gPID)))

#define FPDFormFieldGetFontSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFontSizeSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFontSizeSEL, _gPID)))

#define FPDFormFieldGetFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFieldGetFontSELPROTO)FRCOREROUTINE(FPDFormFieldSEL,FPDFormFieldGetFontSEL, _gPID)))

//*****************************
/* IconFit HFT functions */
//*****************************

#define FPDIconFitNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitNewSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitNewSEL, _gPID)))

#define FPDIconFitDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitDestroySELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitDestroySEL, _gPID)))

#define FPDIconFitGetScaleMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitGetScaleMethodSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitGetScaleMethodSEL, _gPID)))

#define FPDIconFitSetScaleMethod (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitSetScaleMethodSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitSetScaleMethodSEL, _gPID)))

#define FPDIconFitIsProportionalScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitIsProportionalScaleSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitIsProportionalScaleSEL, _gPID)))

#define FPDIconFitProportionalScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitProportionalScaleSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitProportionalScaleSEL, _gPID)))

#define FPDIconFitGetIconPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitGetIconPositionSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitGetIconPositionSEL, _gPID)))

#define FPDIconFitSetIconPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitSetIconPositionSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitSetIconPositionSEL, _gPID)))

#define FPDIconFitGetFittingBounds (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitGetFittingBoundsSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitGetFittingBoundsSEL, _gPID)))

#define FPDIconFitSetFittingBounds (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitSetFittingBoundsSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitSetFittingBoundsSEL, _gPID)))

#define FPDIconFitGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDIconFitGetDictSELPROTO)FRCOREROUTINE(FPDIconFitSEL,FPDIconFitGetDictSEL, _gPID)))

//*****************************
/* FormControl HFT functions */
//*****************************

#define FPDFormControlGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetTypeSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetTypeSEL, _gPID)))

#define FPDFormControlGetInterForm (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetInterFormSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetInterFormSEL, _gPID)))

#define FPDFormControlGetField (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetFieldSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetFieldSEL, _gPID)))

#define FPDFormControlGetWidget (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetWidgetSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetWidgetSEL, _gPID)))

#define FPDFormControlGetRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetRectSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetRectSEL, _gPID)))

#define FPDFormControlDrawControl (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlDrawControlSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlDrawControlSEL, _gPID)))

#define FPDFormControlGetCheckedAPState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetCheckedAPStateSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetCheckedAPStateSEL, _gPID)))

#define FPDFormControlGetExportValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetExportValueSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetExportValueSEL, _gPID)))

#define FPDFormControlSetExportValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetExportValueSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetExportValueSEL, _gPID)))

#define FPDFormControlIsChecked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlIsCheckedSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlIsCheckedSEL, _gPID)))

#define FPDFormControlIsDefaultChecked (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlIsDefaultCheckedSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlIsDefaultCheckedSEL, _gPID)))

#define FPDFormControlGetHighlightingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetHighlightingModeSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetHighlightingModeSEL, _gPID)))

#define FPDFormControlSetHighlightingMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetHighlightingModeSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetHighlightingModeSEL, _gPID)))

#define FPDFormControlHasMKEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlHasMKEntrySELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlHasMKEntrySEL, _gPID)))

#define FPDFormControlRemoveMKEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlRemoveMKEntrySELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlRemoveMKEntrySEL, _gPID)))

#define FPDFormControlGetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetRotationSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetRotationSEL, _gPID)))

#define FPDFormControlSetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetRotationSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetRotationSEL, _gPID)))

#define FPDFormControlGetBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetBorderColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetBorderColorSEL, _gPID)))

#define FPDFormControlGetOriginalBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetOriginalBorderColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetOriginalBorderColorSEL, _gPID)))

#define FPDFormControlGetOriginalBorderColor2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetOriginalBorderColor2SELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetOriginalBorderColor2SEL, _gPID)))

#define FPDFormControlSetBorderColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetBorderColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetBorderColorSEL, _gPID)))

#define FPDFormControlGetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetBackgroundColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetBackgroundColorSEL, _gPID)))

#define FPDFormControlGetOriginalBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetOriginalBackgroundColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetOriginalBackgroundColorSEL, _gPID)))

#define FPDFormControlGetOriginalBackgroundColor2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetOriginalBackgroundColor2SELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetOriginalBackgroundColor2SEL, _gPID)))

#define FPDFormControlSetBackgroundColor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetBackgroundColorSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetBackgroundColorSEL, _gPID)))

#define FPDFormControlGetNormalCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetNormalCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetNormalCaptionSEL, _gPID)))

#define FPDFormControlSetNormalCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetNormalCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetNormalCaptionSEL, _gPID)))

#define FPDFormControlSetNormalCaptionW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetNormalCaptionWSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetNormalCaptionWSEL, _gPID)))

#define FPDFormControlGetRolloverCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetRolloverCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetRolloverCaptionSEL, _gPID)))

#define FPDFormControlSetRolloverCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetRolloverCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetRolloverCaptionSEL, _gPID)))

#define FPDFormControlSetRolloverCaptionW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetRolloverCaptionWSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetRolloverCaptionWSEL, _gPID)))

#define FPDFormControlGetDownCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetDownCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetDownCaptionSEL, _gPID)))

#define FPDFormControlSetDownCaption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetDownCaptionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetDownCaptionSEL, _gPID)))

#define FPDFormControlSetDownCaptionW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetDownCaptionWSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetDownCaptionWSEL, _gPID)))

#define FPDFormControlGetNormalIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetNormalIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetNormalIconSEL, _gPID)))

#define FPDFormControlSetNormalIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetNormalIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetNormalIconSEL, _gPID)))

#define FPDFormControlGetRolloverIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetRolloverIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetRolloverIconSEL, _gPID)))

#define FPDFormControlSetRolloverIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetRolloverIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetRolloverIconSEL, _gPID)))

#define FPDFormControlGetDownIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetDownIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetDownIconSEL, _gPID)))

#define FPDFormControlSetDownIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetDownIconSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetDownIconSEL, _gPID)))

#define FPDFormControlGetIconFit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetIconFitSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetIconFitSEL, _gPID)))

#define FPDFormControlSetIconFit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetIconFitSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetIconFitSEL, _gPID)))

#define FPDFormControlGetTextPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetTextPositionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetTextPositionSEL, _gPID)))

#define FPDFormControlSetTextPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetTextPositionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetTextPositionSEL, _gPID)))

#define FPDFormControlGetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetActionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetActionSEL, _gPID)))

#define FPDFormControlSetAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetActionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetActionSEL, _gPID)))

#define FPDFormControlGetAdditionalAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetAdditionalActionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetAdditionalActionSEL, _gPID)))

#define FPDFormControlSetAdditionalAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetAdditionalActionSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetAdditionalActionSEL, _gPID)))

#define FPDFormControlGetDefaultAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetDefaultAppearanceSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetDefaultAppearanceSEL, _gPID)))

#define FPDFormControlSetDefaultAppearance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetDefaultAppearanceSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetDefaultAppearanceSEL, _gPID)))

#define FPDFormControlGetDefaultControlFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetDefaultControlFontSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetDefaultControlFontSEL, _gPID)))

#define FPDFormControlSetDefaultControlFont (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetDefaultControlFontSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetDefaultControlFontSEL, _gPID)))

#define FPDFormControlGetControlAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlGetControlAlignmentSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlGetControlAlignmentSEL, _gPID)))

#define FPDFormControlSetControlAlignment (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormControlSetControlAlignmentSELPROTO)FRCOREROUTINE(FPDFormControlSEL,FPDFormControlSetControlAlignmentSEL, _gPID)))

//*****************************
/* FDFDoc HFT functions */
//*****************************

#define FPDFDFDocNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocNewSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocNewSEL, _gPID)))

#define FPDFDFDocOpenFromFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocOpenFromFileSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocOpenFromFileSEL, _gPID)))

#define FPDFDFDocPareMemory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocPareMemorySELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocPareMemorySEL, _gPID)))

#define FPDFDFDocDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocDestroySELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocDestroySEL, _gPID)))

#define FPDFDFDocWriteFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocWriteFileSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocWriteFileSEL, _gPID)))

#define FPDFDFDocGetRoot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetRootSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetRootSEL, _gPID)))

#define FPDFDFDocGetWin32Path (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetWin32PathSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetWin32PathSEL, _gPID)))

#define FPDFDFDocGetIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetIndirectObjectSEL, _gPID)))

#define FPDFDFDocGetIndirectType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetIndirectTypeSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetIndirectTypeSEL, _gPID)))

#define FPDFDFDocAddIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocAddIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocAddIndirectObjectSEL, _gPID)))

#define FPDFDFDocReleaseIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocReleaseIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocReleaseIndirectObjectSEL, _gPID)))

#define FPDFDFDocDeleteIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocDeleteIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocDeleteIndirectObjectSEL, _gPID)))

#define FPDFDFDocImportIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocImportIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocImportIndirectObjectSEL, _gPID)))

#define FPDFDFDocImportExternalObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocImportExternalObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocImportExternalObjectSEL, _gPID)))

#define FPDFDFDocInsertIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocInsertIndirectObjectSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocInsertIndirectObjectSEL, _gPID)))

#define FPDFDFDocGetLastobjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetLastobjNumSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetLastobjNumSEL, _gPID)))

#define FPDFDFDocReloadFileStreams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocReloadFileStreamsSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocReloadFileStreamsSEL, _gPID)))

#define FPDFDFDocGetStartPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetStartPositionSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetStartPositionSEL, _gPID)))

#define FPDFDFDocGetNextAssoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetNextAssocSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetNextAssocSEL, _gPID)))

#define FPDFDFDocIsModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocIsModifiedSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocIsModifiedSEL, _gPID)))

#define FPDFDFDocClearModified (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocClearModifiedSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocClearModifiedSEL, _gPID)))

#define FPDFDFDocWriteBuf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocWriteBufSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocWriteBufSEL, _gPID)))

#define FPDFDFDocGetAnnotCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetAnnotCountSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetAnnotCountSEL, _gPID)))

#define FPDFDFDocGetAnnotDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetAnnotDictSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetAnnotDictSEL, _gPID)))

#define FPDFDFDocGetAnnotPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocGetAnnotPageIndexSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocGetAnnotPageIndexSEL, _gPID)))

#define FPDFDFDocExportAnnotToPDFPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocExportAnnotToPDFPageSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocExportAnnotToPDFPageSEL, _gPID)))

#define FPDFDFDocImportPDFAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocImportPDFAnnotSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocImportPDFAnnotSEL, _gPID)))

#define FPDFDFDocSetPDFPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFDFDocSetPDFPathSELPROTO)FRCOREROUTINE(FPDFDFDocSEL,FPDFDFDocSetPDFPathSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//*****************************
/* ConnectedInfo HFT functions */
//*****************************

#define FPDConnectedInfoNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoNewSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoNewSEL, _gPID)))

#define FPDConnectedInfoDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoDestroySELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoDestroySEL, _gPID)))

#define FPDConnectedInfoSetId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetIdSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetIdSEL, _gPID)))

#define FPDConnectedInfoGetId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoGetIdSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoGetIdSEL, _gPID)))

#define FPDConnectedInfoIsConnectedPDF (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoIsConnectedPDFSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoIsConnectedPDFSEL, _gPID)))

#define FPDConnectedInfoIsConnectedPDF2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoIsConnectedPDF2SELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoIsConnectedPDF2SEL, _gPID)))

#define FPDConnectedInfoSetTracking (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetTrackingSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetTrackingSEL, _gPID)))

#define FPDConnectedInfoGetTracking (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoGetTrackingSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoGetTrackingSEL, _gPID)))

#define FPDConnectedInfoUpdate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoUpdateSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoUpdateSEL, _gPID)))

#define FPDConnectedInfoSetEncryptOffline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetEncryptOfflineSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetEncryptOfflineSEL, _gPID)))

#define FPDConnectedInfoSetEncryptEnvelope (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetEncryptEnvelopeSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetEncryptEnvelopeSEL, _gPID)))

#define FPDConnectedInfoGetEncryptOffline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoGetEncryptOfflineSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoGetEncryptOfflineSEL, _gPID)))

#define FPDConnectedInfoGetEncryptEnvelope (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoGetEncryptEnvelopeSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoGetEncryptEnvelopeSEL, _gPID)))

#define FPDConnectedInfoSetOpenActionURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetOpenActionURLSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetOpenActionURLSEL, _gPID)))

#define FPDConnectedInfoSetOpenActionURL2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetOpenActionURL2SELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetOpenActionURL2SEL, _gPID)))

#define FPDConnectedInfoCheckSettingOpenAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoCheckSettingOpenActionSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoCheckSettingOpenActionSEL, _gPID)))

#define FPDConnectedInfoDeleteOpenAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoDeleteOpenActionSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoDeleteOpenActionSEL, _gPID)))

#define FPDConnectedInfoSetEndpoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoSetEndpointSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoSetEndpointSEL, _gPID)))

#define FPDConnectedInfoGetEndpoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDConnectedInfoGetEndpointSELPROTO)FRCOREROUTINE(FPDConnectedInfoSEL,FPDConnectedInfoGetEndpointSEL, _gPID)))

//----------_V8----------
//----------_V9----------
//----------_V10----------
//*****************************
/* WrapperDoc HFT functions */
//*****************************

#define FPDWrapperDocNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocNewSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocNewSEL, _gPID)))

#define FPDWrapperDocDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocDestroySELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocDestroySEL, _gPID)))

#define FPDWrapperDocGetWrapperType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocGetWrapperTypeSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocGetWrapperTypeSEL, _gPID)))

#define FPDWrapperDocGetCryptographicFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocGetCryptographicFilterSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocGetCryptographicFilterSEL, _gPID)))

#define FPDWrapperDocGetPayLoadSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocGetPayLoadSizeSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocGetPayLoadSizeSEL, _gPID)))

#define FPDWrapperDocGetPayloadFileName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocGetPayloadFileNameSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocGetPayloadFileNameSEL, _gPID)))

#define FPDWrapperDocStartGetPayload (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocStartGetPayloadSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocStartGetPayloadSEL, _gPID)))

#define FPDWrapperDocContinue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDWrapperDocContinueSELPROTO)FRCOREROUTINE(FPDWrapperDocSEL,FPDWrapperDocContinueSEL, _gPID)))

#ifdef __cplusplus
}
#endif

#endif