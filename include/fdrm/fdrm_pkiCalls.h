/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FDRM_PKICALLS_H
#define FDRM_PKICALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FDRM_PKIEXPT_H
#include "fdrm_pkiExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fdrm_pkiImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fdrm_pkiTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fdrm_pkiImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fdrm_pkiTempl.h"

//----------_V1----------
//----------_V2----------
//*****************************
/* PKI HFT functions */
//*****************************

#define FDRMPKICreateRsaKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKICreateRsaKeySELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKICreateRsaKeySEL, _gPID)))

#define FDRMPKIRsaEncrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIRsaEncryptSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIRsaEncryptSEL, _gPID)))

#define FDRMPKIRsaDecrypt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIRsaDecryptSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIRsaDecryptSEL, _gPID)))

#define FDRMPKIRsaSign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIRsaSignSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIRsaSignSEL, _gPID)))

#define FDRMPKIVerifyRsaSign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIVerifyRsaSignSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIVerifyRsaSignSEL, _gPID)))

#define FDRMPKICreateDsaKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKICreateDsaKeySELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKICreateDsaKeySEL, _gPID)))

#define FDRMPKIDsaSign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIDsaSignSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIDsaSignSEL, _gPID)))

#define FDRMPKIVerifyDsaSign (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIVerifyDsaSignSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIVerifyDsaSignSEL, _gPID)))

#define FDRMPKIVerifyRsaKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIVerifyRsaKeySELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIVerifyRsaKeySEL, _gPID)))

#define FDRMPKIVerifyDasKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIVerifyDasKeySELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIVerifyDasKeySEL, _gPID)))

#define FDRMPKIGenMD5Digest (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPKIGenMD5DigestSELPROTO)FRCOREROUTINE(FDRMPKISEL,FDRMPKIGenMD5DigestSEL, _gPID)))

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