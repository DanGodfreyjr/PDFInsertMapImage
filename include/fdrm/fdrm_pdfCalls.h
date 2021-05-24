/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FDRM_PDFCALLS_H
#define FDRM_PDFCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FDRM_PDFEXPT_H
#include "fdrm_pdfExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fdrm_pdfImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fdrm_pdfTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fdrm_pdfImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fdrm_pdfTempl.h"

//----------_V1----------
//----------_V2----------
//*****************************
/* PDFSecurityHandler HFT functions */
//*****************************

#define FDRMPDFSecurityHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerNewSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerNewSEL, _gPID)))

#define FDRMPDFSecurityHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerDestroySELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerDestroySEL, _gPID)))

#define FDRMPDFSecurityHandlerInit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerInitSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerInitSEL, _gPID)))

#define FDRMPDFSecurityHandlerGetPermissions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerGetPermissionsSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerGetPermissionsSEL, _gPID)))

#define FDRMPDFSecurityHandlerIsOwner (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerIsOwnerSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerIsOwnerSEL, _gPID)))

#define FDRMPDFSecurityHandlerGetCryptInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerGetCryptInfoSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerGetCryptInfoSEL, _gPID)))

#define FDRMPDFSecurityHandlerSetSubFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerSetSubFilterSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerSetSubFilterSEL, _gPID)))

#define FDRMPDFSecurityHandlerSetIdentityEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerSetIdentityEntrySELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerSetIdentityEntrySEL, _gPID)))

#define FDRMPDFSecurityHandlerGetSubFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerGetSubFilterSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerGetSubFilterSEL, _gPID)))

#define FDRMPDFSecurityHandlerGetIdentityEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerGetIdentityEntrySELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerGetIdentityEntrySEL, _gPID)))

#define FDRMPDFSecurityHandlerSetCryptInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerSetCryptInfoSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerSetCryptInfoSEL, _gPID)))

#define FDRMPDFSecurityHandlerCheckValidity (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerCheckValiditySELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerCheckValiditySEL, _gPID)))

#define FDRMPDFSecurityHandlerCreateCryptoHandler (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSecurityHandlerCreateCryptoHandlerSELPROTO)FRCOREROUTINE(FDRMPDFSecurityHandlerSEL,FDRMPDFSecurityHandlerCreateCryptoHandlerSEL, _gPID)))

//*****************************
/* PDFSchema HFT functions */
//*****************************

#define FDRMPDFSchemaNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaNewSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaNewSEL, _gPID)))

#define FDRMPDFSchemaDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaDestroySELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaDestroySEL, _gPID)))

#define FDRMPDFSchemaLoadSchema (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaLoadSchemaSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaLoadSchemaSEL, _gPID)))

#define FDRMPDFSchemaGetPDFFileSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaGetPDFFileSizeSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaGetPDFFileSizeSEL, _gPID)))

#define FDRMPDFSchemaGetXRefOffset (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaGetXRefOffsetSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaGetXRefOffsetSEL, _gPID)))

#define FDRMPDFSchemaCountPages (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaCountPagesSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaCountPagesSEL, _gPID)))

#define FDRMPDFSchemaGetSchemaInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaGetSchemaInfoSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaGetSchemaInfoSEL, _gPID)))

#define FDRMPDFSchemaGetPageSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPDFSchemaGetPageSizeSELPROTO)FRCOREROUTINE(FDRMPDFSchemaSEL,FDRMPDFSchemaGetPageSizeSEL, _gPID)))

//*****************************
/* EncryptDictRead HFT functions */
//*****************************

#define FDRMEncryptDictReadNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadNewSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadNewSEL, _gPID)))

#define FDRMEncryptDictReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadDestroySELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadDestroySEL, _gPID)))

#define FDRMEncryptDictReadVerify (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadVerifySELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadVerifySEL, _gPID)))

#define FDRMEncryptDictReadGetSubFilter (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetSubFilterSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetSubFilterSEL, _gPID)))

#define FDRMEncryptDictReadGetIssuer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetIssuerSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetIssuerSEL, _gPID)))

#define FDRMEncryptDictReadGetCreator (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetCreatorSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetCreatorSEL, _gPID)))

#define FDRMEncryptDictReadGetFileId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetFileIdSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetFileIdSEL, _gPID)))

#define FDRMEncryptDictReadGetFlowCode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetFlowCodeSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetFlowCodeSEL, _gPID)))

#define FDRMEncryptDictReadGetOrder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetOrderSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetOrderSEL, _gPID)))

#define FDRMEncryptDictReadGetUser (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetUserSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetUserSEL, _gPID)))

#define FDRMEncryptDictReadGetServiceURL (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptDictReadGetServiceURLSELPROTO)FRCOREROUTINE(FDRMEncryptDictReadSEL,FDRMEncryptDictReadGetServiceURLSEL, _gPID)))

//*****************************
/* Encryptor HFT functions */
//*****************************

#define FDRMEncryptorArcFourCryptBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorArcFourCryptBlockSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorArcFourCryptBlockSEL, _gPID)))

#define FDRMEncryptorArcFourSetup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorArcFourSetupSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorArcFourSetupSEL, _gPID)))

#define FDRMEncryptorArcFourCrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorArcFourCryptSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorArcFourCryptSEL, _gPID)))

#define FDRMEncryptorSHA256Start (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorSHA256StartSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorSHA256StartSEL, _gPID)))

#define FDRMEncryptorSHA256Update (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorSHA256UpdateSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorSHA256UpdateSEL, _gPID)))

#define FDRMEncryptorSHA256Finish (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorSHA256FinishSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorSHA256FinishSEL, _gPID)))

#define FDRMEncryptorSHA256DigestGenerate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorSHA256DigestGenerateSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorSHA256DigestGenerateSEL, _gPID)))

#define FDRMEncryptorHashMD5128 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorHashMD5128SELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorHashMD5128SEL, _gPID)))

#define FDRMEncryptorAESSetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorAESSetKeySELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorAESSetKeySEL, _gPID)))

#define FDRMEncryptorAESSetIV (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorAESSetIVSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorAESSetIVSEL, _gPID)))

#define FDRMEncryptorAESDecrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorAESDecryptSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorAESDecryptSEL, _gPID)))

#define FDRMEncryptorAESEncrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorAESEncryptSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorAESEncryptSEL, _gPID)))

#define FDRMEncryptorAESSetKey2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorAESSetKey2SELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorAESSetKey2SEL, _gPID)))

#define FDRMEncryptorMD5Start (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorMD5StartSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorMD5StartSEL, _gPID)))

#define FDRMEncryptorMD5Update (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorMD5UpdateSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorMD5UpdateSEL, _gPID)))

#define FDRMEncryptorMD5Finish (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEncryptorMD5FinishSELPROTO)FRCOREROUTINE(FDRMEncryptorSEL,FDRMEncryptorMD5FinishSEL, _gPID)))

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