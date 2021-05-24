/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_PAGECALLS_H
#define FPD_PAGECALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_pageImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_pageTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_pageImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_pageTempl.h"

//----------_V1----------
//*****************************
/* Page HFT functions */
//*****************************

#define FPDPageNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageNewSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageNewSEL, _gPID)))

#define FPDPageDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageDestroySELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageDestroySEL, _gPID)))

#define FPDPageContinueParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageContinueParseSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageContinueParseSEL, _gPID)))

#define FPDPageGetParseState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetParseStateSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetParseStateSEL, _gPID)))

#define FPDPageIsParsed (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageIsParsedSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageIsParsedSEL, _gPID)))

#define FPDPageEstimateParseProgress (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageEstimateParseProgressSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageEstimateParseProgressSEL, _gPID)))

#define FPDPageGetFirstObjectPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetFirstObjectPositionSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetFirstObjectPositionSEL, _gPID)))

#define FPDPageGetLastObjectPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetLastObjectPositionSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetLastObjectPositionSEL, _gPID)))

#define FPDPageGetNextObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetNextObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetNextObjectSEL, _gPID)))

#define FPDPageGetPrevObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPrevObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPrevObjectSEL, _gPID)))

#define FPDPageGetObjectAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetObjectAtSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetObjectAtSEL, _gPID)))

#define FPDPageCountObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageCountObjectsSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageCountObjectsSEL, _gPID)))

#define FPDPageGetObjectIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetObjectIndexSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetObjectIndexSEL, _gPID)))

#define FPDPageGetObjectByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetObjectByIndexSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetObjectByIndexSEL, _gPID)))

#define FPDPageReplaceObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageReplaceObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageReplaceObjectSEL, _gPID)))

#define FPDPageInsertObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageInsertObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageInsertObjectSEL, _gPID)))

#define FPDPageRemoveObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRemoveObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageRemoveObjectSEL, _gPID)))

#define FPDPageMoveObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageMoveObjectSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageMoveObjectSEL, _gPID)))

#define FPDPageDebugOutput (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageDebugOutputSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageDebugOutputSEL, _gPID)))

#define FPDPageTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageTransformSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageTransformSEL, _gPID)))

#define FPDPageBackgroundAlphaNeeded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageBackgroundAlphaNeededSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageBackgroundAlphaNeededSEL, _gPID)))

#define FPDPageCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageCalcBoundingBoxSEL, _gPID)))

#define FPDPageGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetDictSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetDictSEL, _gPID)))

#define FPDPageGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetDocumentSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetDocumentSEL, _gPID)))

#define FPDPageRealizeResource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageRealizeResourceSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageRealizeResourceSEL, _gPID)))

#define FPDPageFindCSName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageFindCSNameSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageFindCSNameSEL, _gPID)))

#define FPDPageFindFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageFindFontNameSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageFindFontNameSEL, _gPID)))

#define FPDPageLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageLoadSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageLoadSEL, _gPID)))

#define FPDPageStartParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageStartParseSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageStartParseSEL, _gPID)))

#define FPDPageParseContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageParseContentSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageParseContentSEL, _gPID)))

#define FPDPageGetDisplayMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetDisplayMatrixSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetDisplayMatrixSEL, _gPID)))

#define FPDPageGetPageWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageWidthSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageWidthSEL, _gPID)))

#define FPDPageGetPageHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageHeightSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageHeightSEL, _gPID)))

#define FPDPageGetPageBBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageBBoxSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageBBoxSEL, _gPID)))

#define FPDPageGetPageMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageMatrixSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageMatrixSEL, _gPID)))

#define FPDPageGetPageAttr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageAttrSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageAttrSEL, _gPID)))

#define FPDPageGetRenderCache (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetRenderCacheSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetRenderCacheSEL, _gPID)))

#define FPDPageClearRenderCache (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageClearRenderCacheSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageClearRenderCacheSEL, _gPID)))

#define FPDPageGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGenerateContentSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGenerateContentSEL, _gPID)))

#define FPDPageGetPageText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageTextSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageTextSEL, _gPID)))

#define FPDPageGetPageText_Unicode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetPageText_UnicodeSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetPageText_UnicodeSEL, _gPID)))

#define FPDPageNewContentGenerator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageNewContentGeneratorSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageNewContentGeneratorSEL, _gPID)))

#define FPDPageDestroyContentGenerator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageDestroyContentGeneratorSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageDestroyContentGeneratorSEL, _gPID)))

#define FPDPageStartGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageStartGenerateContentSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageStartGenerateContentSEL, _gPID)))

#define FPDPageContinueGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageContinueGenerateContentSELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageContinueGenerateContentSEL, _gPID)))

#define FPDPageGetResourcesDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageGetResourcesDictionarySELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageGetResourcesDictionarySEL, _gPID)))

#define FPDPageSetResourcesDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDPageSetResourcesDictionarySELPROTO)FRCOREROUTINE(FPDPageSEL,FPDPageSetResourcesDictionarySEL, _gPID)))

//*****************************
/* ParseOptions HFT functions */
//*****************************

#define FPDParseOptionsNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsNewSELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsNewSEL, _gPID)))

#define FPDParseOptionsDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsDestroySELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsDestroySEL, _gPID)))

#define FPDParseOptionsSetTextFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsSetTextFlagSELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsSetTextFlagSEL, _gPID)))

#define FPDParseOptionsSetMarkedContentLoadFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsSetMarkedContentLoadFlagSELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsSetMarkedContentLoadFlagSEL, _gPID)))

#define FPDParseOptionsSetFormGenerateFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsSetFormGenerateFlagSELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsSetFormGenerateFlagSEL, _gPID)))

#define FPDParseOptionsSetInlineImageDecodeFlag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParseOptionsSetInlineImageDecodeFlagSELPROTO)FRCOREROUTINE(FPDParseOptionsSEL,FPDParseOptionsSetInlineImageDecodeFlagSEL, _gPID)))

//*****************************
/* Form HFT functions */
//*****************************

#define FPDFormNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormNewSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormNewSEL, _gPID)))

#define FPDFormDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormDestroySELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormDestroySEL, _gPID)))

#define FPDFormContinueParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormContinueParseSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormContinueParseSEL, _gPID)))

#define FPDFormGetParseState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetParseStateSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetParseStateSEL, _gPID)))

#define FPDFormIsParsed (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormIsParsedSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormIsParsedSEL, _gPID)))

#define FPDFormEstimateParseProgress (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormEstimateParseProgressSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormEstimateParseProgressSEL, _gPID)))

#define FPDFormGetFirstObjectPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetFirstObjectPositionSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetFirstObjectPositionSEL, _gPID)))

#define FPDFormGetLastObjectPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetLastObjectPositionSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetLastObjectPositionSEL, _gPID)))

#define FPDFormGetNextObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetNextObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetNextObjectSEL, _gPID)))

#define FPDFormGetPrevObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetPrevObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetPrevObjectSEL, _gPID)))

#define FPDFormGetObjectAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetObjectAtSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetObjectAtSEL, _gPID)))

#define FPDFormCountObjects (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormCountObjectsSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormCountObjectsSEL, _gPID)))

#define FPDFormGetObjectIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetObjectIndexSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetObjectIndexSEL, _gPID)))

#define FPDFormGetObjectByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetObjectByIndexSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetObjectByIndexSEL, _gPID)))

#define FPDFormReplaceObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormReplaceObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormReplaceObjectSEL, _gPID)))

#define FPDFormInsertObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormInsertObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormInsertObjectSEL, _gPID)))

#define FPDFormRemoveObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormRemoveObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormRemoveObjectSEL, _gPID)))

#define FPDFormMoveObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormMoveObjectSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormMoveObjectSEL, _gPID)))

#define FPDFormDebugOutput (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormDebugOutputSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormDebugOutputSEL, _gPID)))

#define FPDFormTransform (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormTransformSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormTransformSEL, _gPID)))

#define FPDFormBackgroundAlphaNeeded (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormBackgroundAlphaNeededSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormBackgroundAlphaNeededSEL, _gPID)))

#define FPDFormCalcBoundingBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormCalcBoundingBoxSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormCalcBoundingBoxSEL, _gPID)))

#define FPDFormGetDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetDictSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetDictSEL, _gPID)))

#define FPDFormGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetDocumentSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetDocumentSEL, _gPID)))

#define FPDFormRealizeResource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormRealizeResourceSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormRealizeResourceSEL, _gPID)))

#define FPDFormFindCSName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFindCSNameSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormFindCSNameSEL, _gPID)))

#define FPDFormFindFontName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormFindFontNameSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormFindFontNameSEL, _gPID)))

#define FPDFormGetFormStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetFormStreamSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetFormStreamSEL, _gPID)))

#define FPDFormStartParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormStartParseSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormStartParseSEL, _gPID)))

#define FPDFormParseContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormParseContentSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormParseContentSEL, _gPID)))

#define FPDFormClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormCloneSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormCloneSEL, _gPID)))

#define FPDFormGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGenerateContentSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGenerateContentSEL, _gPID)))

#define FPDFormNewContentGenerator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormNewContentGeneratorSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormNewContentGeneratorSEL, _gPID)))

#define FPDFormDestroyContentGenerator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormDestroyContentGeneratorSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormDestroyContentGeneratorSEL, _gPID)))

#define FPDFormStartGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormStartGenerateContentSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormStartGenerateContentSEL, _gPID)))

#define FPDFormContinueGenerateContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormContinueGenerateContentSELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormContinueGenerateContentSEL, _gPID)))

#define FPDFormGetResourcesDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormGetResourcesDictionarySELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormGetResourcesDictionarySEL, _gPID)))

#define FPDFormSetResourcesDictionary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDFormSetResourcesDictionarySELPROTO)FRCOREROUTINE(FPDFormSEL,FPDFormSetResourcesDictionarySEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif