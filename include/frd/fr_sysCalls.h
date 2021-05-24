/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_SYSCALLS_H
#define FR_SYSCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_SYSEXPT_H
#include "fr_sysExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_sysImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_sysTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_sysImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_sysTempl.h"

//----------_V1----------
//*****************************
/* Sys HFT functions */
//*****************************

#define FRSysLoadStandarCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysLoadStandarCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysLoadStandarCursorSEL, _gPID)))

#define FRSysGetCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetCursorSEL, _gPID)))

#define FRSysSetCursor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetCursorSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetCursorSEL, _gPID)))

#define FRSysShowMessageBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysShowMessageBoxSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysShowMessageBoxSEL, _gPID)))

#define FRSysInstallDialogSkinTheme (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysInstallDialogSkinThemeSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysInstallDialogSkinThemeSEL, _gPID)))

#define FRSysInstallDialogScrollBar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysInstallDialogScrollBarSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysInstallDialogScrollBarSEL, _gPID)))

#define FRSysGetSkinCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetSkinCountSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetSkinCountSEL, _gPID)))

#define FRSysGetSkinNameByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysGetSkinNameByIndexSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysGetSkinNameByIndexSEL, _gPID)))

#define FRSysSetActiveSkinByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetActiveSkinByIndexSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetActiveSkinByIndexSEL, _gPID)))

#define FRSysSetActiveSkinByName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRSysSetActiveSkinByNameSELPROTO)FRCOREROUTINE(FRSysSEL,FRSysSetActiveSkinByNameSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* WindowsDIB HFT functions */
//*****************************

#define FRWindowsDIBNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBNewSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBNewSEL, _gPID)))

#define FRWindowsDIBDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBDestroySELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBDestroySEL, _gPID)))

#define FRWindowsDIBGetBitmapInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetBitmapInfoSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetBitmapInfoSEL, _gPID)))

#define FRWindowsDIBLoadFromBuf (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromBufSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromBufSEL, _gPID)))

#define FRWindowsDIBGetDDBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetDDBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetDDBitmapSEL, _gPID)))

#define FRWindowsDIBLoadFromDDB (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromDDBSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromDDBSEL, _gPID)))

#define FRWindowsDIBLoadFromFile (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromFileSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromFileSEL, _gPID)))

#define FRWindowsDIBLoadFromFileII (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromFileIISELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromFileIISEL, _gPID)))

#define FRWindowsDIBLoadDIBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadDIBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadDIBitmapSEL, _gPID)))

#define FRWindowsDIBGetDC (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetDCSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetDCSEL, _gPID)))

#define FRWindowsDIBGetWindowsBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBGetWindowsBitmapSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBGetWindowsBitmapSEL, _gPID)))

#define FRWindowsDIBLoadFromDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBLoadFromDeviceSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBLoadFromDeviceSEL, _gPID)))

#define FRWindowsDIBSetToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRWindowsDIBSetToDeviceSELPROTO)FRCOREROUTINE(FRWindowsDIBSEL,FRWindowsDIBSetToDeviceSEL, _gPID)))

//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif