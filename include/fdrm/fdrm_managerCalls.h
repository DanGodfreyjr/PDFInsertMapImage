/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FDRM_MANAGERCALLS_H
#define FDRM_MANAGERCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FDRM_MANAGEREXPT_H
#include "fdrm_managerExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fdrm_managerImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fdrm_managerTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fdrm_managerImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fdrm_managerTempl.h"

//----------_V1----------
//----------_V2----------
//*****************************
/* Mgr HFT functions */
//*****************************

#define FDRMMgrCreateDef (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMMgrCreateDefSELPROTO)FRCOREROUTINE(FDRMMgrSEL,FDRMMgrCreateDefSEL, _gPID)))

#define FDRMMgrGetCurrentUse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMMgrGetCurrentUseSELPROTO)FRCOREROUTINE(FDRMMgrSEL,FDRMMgrGetCurrentUseSEL, _gPID)))

#define FDRMMgrSetCurrentUse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMMgrSetCurrentUseSELPROTO)FRCOREROUTINE(FDRMMgrSEL,FDRMMgrSetCurrentUseSEL, _gPID)))

#define FDRMMgrDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMMgrDestroySELPROTO)FRCOREROUTINE(FDRMMgrSEL,FDRMMgrDestroySEL, _gPID)))

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