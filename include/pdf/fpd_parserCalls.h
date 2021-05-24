/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FPD_PARSERCALLS_H
#define FPD_PARSERCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "fpd_parserExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fpd_parserImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fpd_parserTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fpd_parserImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fpd_parserTempl.h"

//----------_V1----------
//*****************************
/* Parser HFT functions */
//*****************************

#define FPDParserNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserNewSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserNewSEL, _gPID)))

#define FPDParserDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserDestroySELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserDestroySEL, _gPID)))

#define FPDParserStartParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserStartParseSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserStartParseSEL, _gPID)))

#define FPDParserStartParseW (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserStartParseWSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserStartParseWSEL, _gPID)))

#define FPDParserStartParseFormMem (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserStartParseFormMemSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserStartParseFormMemSEL, _gPID)))

#define FPDParserStartParseCustomFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserStartParseCustomFileSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserStartParseCustomFileSEL, _gPID)))

#define FPDParserCloseParser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserCloseParserSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserCloseParserSEL, _gPID)))

#define FPDParserGetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetPermissionsSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetPermissionsSEL, _gPID)))

#define FPDParserIsOwner (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserIsOwnerSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserIsOwnerSEL, _gPID)))

#define FPDParserSetPassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserSetPasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserSetPasswordSEL, _gPID)))

#define FPDParserGetPassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetPasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetPasswordSEL, _gPID)))

#define FPDParserGetTrailer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetTrailerSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetTrailerSEL, _gPID)))

#define FPDParserGetLastXRefOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetLastXRefOffsetSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetLastXRefOffsetSEL, _gPID)))

#define FPDParserGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetDocumentSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetDocumentSEL, _gPID)))

#define FPDParserCountOtherTrailers (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserCountOtherTrailersSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserCountOtherTrailersSEL, _gPID)))

#define FPDParserGetOtherTrailerByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetOtherTrailerByIndexSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetOtherTrailerByIndexSEL, _gPID)))

#define FPDParserGetRootObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetRootObjNumSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetRootObjNumSEL, _gPID)))

#define FPDParserGetInfoObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetInfoObjNumSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetInfoObjNumSEL, _gPID)))

#define FPDParserGetIDArray (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetIDArraySELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetIDArraySEL, _gPID)))

#define FPDParserGetEncryptDict (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetEncryptDictSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetEncryptDictSEL, _gPID)))

#define FPDParserParseIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserParseIndirectObjectSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserParseIndirectObjectSEL, _gPID)))

#define FPDParserGetLastObjNum (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetLastObjNumSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetLastObjNumSEL, _gPID)))

#define FPDParserIsFormStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserIsFormStreamSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserIsFormStreamSEL, _gPID)))

#define FPDParserReloadFileStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserReloadFileStreamSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserReloadFileStreamSEL, _gPID)))

#define FPDParserDeleteIndirectObject (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserDeleteIndirectObjectSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserDeleteIndirectObjectSEL, _gPID)))

#define FPDParserGetLengthOfVersions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetLengthOfVersionsSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetLengthOfVersionsSEL, _gPID)))

#define FPDParserGetObjectOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetObjectOffsetSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetObjectOffsetSEL, _gPID)))

#define FPDParserGetObjectSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetObjectSizeSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetObjectSizeSEL, _gPID)))

#define FPDParserGetObjectVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetObjectVersionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetObjectVersionSEL, _gPID)))

#define FPDParserGetIndirectBinary (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetIndirectBinarySELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetIndirectBinarySEL, _gPID)))

#define FPDParserParseStreamPos (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserParseStreamPosSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserParseStreamPosSEL, _gPID)))

#define FPDParserParseIndirectObjectsAtRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserParseIndirectObjectsAtRangeSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserParseIndirectObjectsAtRangeSEL, _gPID)))

#define FPDParserGetFileStreamOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetFileStreamOptionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetFileStreamOptionSEL, _gPID)))

#define FPDParserSetFileStreamOption (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserSetFileStreamOptionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserSetFileStreamOptionSEL, _gPID)))

#define FPDParserGetFileAccess (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetFileAccessSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetFileAccessSEL, _gPID)))

#define FPDParserGetFileVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetFileVersionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetFileVersionSEL, _gPID)))

#define FPDParserIsXRefStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserIsXRefStreamSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserIsXRefStreamSEL, _gPID)))

#define FPDParserParseIndirectObjectAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserParseIndirectObjectAtSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserParseIndirectObjectAtSEL, _gPID)))

#define FPDParserStartAsynParse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserStartAsynParseSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserStartAsynParseSEL, _gPID)))

#define FPDParserGetFirstPageNo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetFirstPageNoSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetFirstPageNoSEL, _gPID)))

#define FPDParserGetSecurityPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetSecurityPermissionsSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetSecurityPermissionsSEL, _gPID)))

#define FPDParserIsSecurityOwner (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserIsSecurityOwnerSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserIsSecurityOwnerSEL, _gPID)))

#define FPDParserGetSecurityCryptInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetSecurityCryptInfoSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetSecurityCryptInfoSEL, _gPID)))

#define FPDParserIsMetadataEncryptedBySecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserIsMetadataEncryptedBySecuritySELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserIsMetadataEncryptedBySecuritySEL, _gPID)))

#define FPDParserGetStandardSecurityUserPassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetStandardSecurityUserPasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetStandardSecurityUserPasswordSEL, _gPID)))

#define FPDParserGetStandardSecurityVersion (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetStandardSecurityVersionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetStandardSecurityVersionSEL, _gPID)))

#define FPDParserGetStandardSecurityRevision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetStandardSecurityRevisionSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetStandardSecurityRevisionSEL, _gPID)))

#define FPDParserCheckStandardSecurityPassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserCheckStandardSecurityPasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserCheckStandardSecurityPasswordSEL, _gPID)))

#define FPDParserCheckEmbeddedSecurity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserCheckEmbeddedSecuritySELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserCheckEmbeddedSecuritySEL, _gPID)))

#define FPDParserLoadAttachmentStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserLoadAttachmentStreamSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserLoadAttachmentStreamSEL, _gPID)))

#define FPDParserSetUnicodePassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserSetUnicodePasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserSetUnicodePasswordSEL, _gPID)))

#define FPDParserGetUnicodePassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserGetUnicodePasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserGetUnicodePasswordSEL, _gPID)))

#define FPDParserCheckPassword (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FPDParserCheckPasswordSELPROTO)FRCOREROUTINE(FPDParserSEL,FPDParserCheckPasswordSEL, _gPID)))

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