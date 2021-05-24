/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FS_BASICCALLS_H
#define FS_BASICCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FS_BASICEXPT_H
#include "fs_basicExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fs_basicImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fs_basicTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fs_basicImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fs_basicTempl.h"

//----------_V1----------
//*****************************
/* ExtensionHFTMgr HFT functions */
//*****************************

#define FSExtensionHFTMgrNewHFT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSExtensionHFTMgrNewHFTSELPROTO)FRCOREROUTINE(FSExtensionHFTMgrSEL,FSExtensionHFTMgrNewHFTSEL, _gPID)))

#define FSExtensionHFTMgrAddHFT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSExtensionHFTMgrAddHFTSELPROTO)FRCOREROUTINE(FSExtensionHFTMgrSEL,FSExtensionHFTMgrAddHFTSEL, _gPID)))

#define FSExtensionHFTMgrGetHFT (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSExtensionHFTMgrGetHFTSELPROTO)FRCOREROUTINE(FSExtensionHFTMgrSEL,FSExtensionHFTMgrGetHFTSEL, _gPID)))

#define FSExtensionHFTMgrReplaceEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSExtensionHFTMgrReplaceEntrySELPROTO)FRCOREROUTINE(FSExtensionHFTMgrSEL,FSExtensionHFTMgrReplaceEntrySEL, _gPID)))

#define FSExtensionHFTMgrGetEntry (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSExtensionHFTMgrGetEntrySELPROTO)FRCOREROUTINE(FSExtensionHFTMgrSEL,FSExtensionHFTMgrGetEntrySEL, _gPID)))

//*****************************
/* AffineMatrix HFT functions */
//*****************************

#define FSAffineMatrixIsScaled (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixIsScaledSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixIsScaledSEL, _gPID)))

#define FSAffineMatrixIs90Rotated (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixIs90RotatedSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixIs90RotatedSEL, _gPID)))

#define FSAffineMatrixGetReverse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixGetReverseSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixGetReverseSEL, _gPID)))

#define FSAffineMatrixTransformPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixTransformPointSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixTransformPointSEL, _gPID)))

#define FSAffineMatrixTransformRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixTransformRectSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixTransformRectSEL, _gPID)))

#define FSAffineMatrixConcat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixConcatSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixConcatSEL, _gPID)))

#define FSAffineMatrixTranslate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixTranslateSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixTranslateSEL, _gPID)))

#define FSAffineMatrixTranslateI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixTranslateISELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixTranslateISEL, _gPID)))

#define FSAffineMatrixScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixScaleSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixScaleSEL, _gPID)))

#define FSAffineMatrixConcatInverse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixConcatInverseSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixConcatInverseSEL, _gPID)))

#define FSAffineMatrixMatchRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixMatchRectSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixMatchRectSEL, _gPID)))

#define FSAffineMatrixGetUnitRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixGetUnitRectSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixGetUnitRectSEL, _gPID)))

#define FSAffineMatrixGetUnitArea (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixGetUnitAreaSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixGetUnitAreaSEL, _gPID)))

#define FSAffineMatrixGetXUnit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixGetXUnitSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixGetXUnitSEL, _gPID)))

#define FSAffineMatrixGetYUnit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixGetYUnitSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixGetYUnitSEL, _gPID)))

#define FSAffineMatrixTransformDistance (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixTransformDistanceSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixTransformDistanceSEL, _gPID)))

#define FSAffineMatrixRotate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSAffineMatrixRotateSELPROTO)FRCOREROUTINE(FSAffineMatrixSEL,FSAffineMatrixRotateSEL, _gPID)))

//*****************************
/* DIBitmap HFT functions */
//*****************************

#define FSDIBitmapNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapNewSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapNewSEL, _gPID)))

#define FSDIBitmapCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCreateSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCreateSEL, _gPID)))

#define FSDIBitmapDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapDestroySELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapDestroySEL, _gPID)))

#define FSDIBitmapGetWidth (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetWidthSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetWidthSEL, _gPID)))

#define FSDIBitmapGetHeight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetHeightSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetHeightSEL, _gPID)))

#define FSDIBitmapGetFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetFormatSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetFormatSEL, _gPID)))

#define FSDIBitmapGetPitch (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetPitchSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetPitchSEL, _gPID)))

#define FSDIBitmapGetPalette (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetPaletteSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetPaletteSEL, _gPID)))

#define FSDIBitmapGetBuffer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetBufferSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetBufferSEL, _gPID)))

#define FSDIBitmapGetScanline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetScanlineSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetScanlineSEL, _gPID)))

#define FSDIBitmapDownSampleScanline (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapDownSampleScanlineSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapDownSampleScanlineSEL, _gPID)))

#define FSDIBitmapTakeOver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapTakeOverSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapTakeOverSEL, _gPID)))

#define FSDIBitmapConvertFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapConvertFormatSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapConvertFormatSEL, _gPID)))

#define FSDIBitmapClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapClearSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapClearSEL, _gPID)))

#define FSDIBitmapGetPixel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetPixelSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetPixelSEL, _gPID)))

#define FSDIBitmapSetPixel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapSetPixelSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapSetPixelSEL, _gPID)))

#define FSDIBitmapLoadChannel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadChannelSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadChannelSEL, _gPID)))

#define FSDIBitmapLoadChannel2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadChannel2SELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadChannel2SEL, _gPID)))

#define FSDIBitmapMultiplyAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapMultiplyAlphaSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapMultiplyAlphaSEL, _gPID)))

#define FSDIBitmapMultiplyAlpha2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapMultiplyAlpha2SELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapMultiplyAlpha2SEL, _gPID)))

#define FSDIBitmapTransferBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapTransferBitmapSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapTransferBitmapSEL, _gPID)))

#define FSDIBitmapTransferMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapTransferMaskSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapTransferMaskSEL, _gPID)))

#define FSDIBitmapCompositeBitmap (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCompositeBitmapSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCompositeBitmapSEL, _gPID)))

#define FSDIBitmapCompositeRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCompositeRectSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCompositeRectSEL, _gPID)))

#define FSDIBitmapGammaAdjust (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGammaAdjustSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGammaAdjustSEL, _gPID)))

#define FSDIBitmapConvertColorScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapConvertColorScaleSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapConvertColorScaleSEL, _gPID)))

#define FSDIBitmapDitherFS (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapDitherFSSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapDitherFSSEL, _gPID)))

#define FSDIBitmapGetBPP (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetBPPSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetBPPSEL, _gPID)))

#define FSDIBitmapIsAlphaMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapIsAlphaMaskSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapIsAlphaMaskSEL, _gPID)))

#define FSDIBitmapHasAlpha (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapHasAlphaSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapHasAlphaSEL, _gPID)))

#define FSDIBitmapIsOpaqueImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapIsOpaqueImageSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapIsOpaqueImageSEL, _gPID)))

#define FSDIBitmapGetPaletteSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetPaletteSizeSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetPaletteSizeSEL, _gPID)))

#define FSDIBitmapGetPaletteArgb (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetPaletteArgbSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetPaletteArgbSEL, _gPID)))

#define FSDIBitmapSetPaletteArgb (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapSetPaletteArgbSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapSetPaletteArgbSEL, _gPID)))

#define FSDIBitmapClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCloneSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCloneSEL, _gPID)))

#define FSDIBitmapCloneConvert (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCloneConvertSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCloneConvertSEL, _gPID)))

#define FSDIBitmapGetAlphaMask (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetAlphaMaskSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetAlphaMaskSEL, _gPID)))

#define FSDIBitmapStretchTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapStretchToSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapStretchToSEL, _gPID)))

#define FSDIBitmapTransformTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapTransformToSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapTransformToSEL, _gPID)))

#define FSDIBitmapSwapXY (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapSwapXYSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapSwapXYSEL, _gPID)))

#define FSDIBitmapFlipImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapFlipImageSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapFlipImageSEL, _gPID)))

#define FSDIBitmapLoadFromPNGIcon (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadFromPNGIconSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadFromPNGIconSEL, _gPID)))

#define FSDIBitmapLoadFromPNGIcon2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadFromPNGIcon2SELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadFromPNGIcon2SEL, _gPID)))

#define FSDIBitmapCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapCopySELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapCopySEL, _gPID)))

#define FSDIBitmapLoadInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadInfoSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadInfoSEL, _gPID)))

#define FSDIBitmapDestroyDIBAttribute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapDestroyDIBAttributeSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapDestroyDIBAttributeSEL, _gPID)))

#define FSDIBitmapGetXDPI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetXDPISELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetXDPISEL, _gPID)))

#define FSDIBitmapGetYDPI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetYDPISELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetYDPISEL, _gPID)))

#define FSDIBitmapGetDPIUnit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetDPIUnitSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetDPIUnitSEL, _gPID)))

#define FSDIBitmapGetExifInfo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapGetExifInfoSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapGetExifInfoSEL, _gPID)))

#define FSDIBitmapLoadFromPNGIcon3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadFromPNGIcon3SELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadFromPNGIcon3SEL, _gPID)))

#define FSDIBitmapLoadFromImage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDIBitmapLoadFromImageSELPROTO)FRCOREROUTINE(FSDIBitmapSEL,FSDIBitmapLoadFromImageSEL, _gPID)))

//*****************************
/* MapPtrToPtr HFT functions */
//*****************************

#define FSMapPtrToPtrNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrNewSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrNewSEL, _gPID)))

#define FSMapPtrToPtrDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrDestroySELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrDestroySEL, _gPID)))

#define FSMapPtrToPtrGetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrGetCountSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrGetCountSEL, _gPID)))

#define FSMapPtrToPtrIsEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrIsEmptySELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrIsEmptySEL, _gPID)))

#define FSMapPtrToPtrLookup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrLookupSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrLookupSEL, _gPID)))

#define FSMapPtrToPtrGetValueAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrGetValueAtSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrGetValueAtSEL, _gPID)))

#define FSMapPtrToPtrSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrSetAtSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrSetAtSEL, _gPID)))

#define FSMapPtrToPtrRemoveKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrRemoveKeySELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrRemoveKeySEL, _gPID)))

#define FSMapPtrToPtrRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrRemoveAllSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrRemoveAllSEL, _gPID)))

#define FSMapPtrToPtrGetStartPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrGetStartPositionSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrGetStartPositionSEL, _gPID)))

#define FSMapPtrToPtrGetNextAssoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrGetNextAssocSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrGetNextAssocSEL, _gPID)))

#define FSMapPtrToPtrGetHashTableSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrGetHashTableSizeSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrGetHashTableSizeSEL, _gPID)))

#define FSMapPtrToPtrInitHashTable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapPtrToPtrInitHashTableSELPROTO)FRCOREROUTINE(FSMapPtrToPtrSEL,FSMapPtrToPtrInitHashTableSEL, _gPID)))

//*****************************
/* PtrArray HFT functions */
//*****************************

#define FSPtrArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayNewSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayNewSEL, _gPID)))

#define FSPtrArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayDestroySELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayDestroySEL, _gPID)))

#define FSPtrArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayGetSizeSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayGetSizeSEL, _gPID)))

#define FSPtrArrayGetUpperBound (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayGetUpperBoundSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayGetUpperBoundSEL, _gPID)))

#define FSPtrArraySetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArraySetSizeSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArraySetSizeSEL, _gPID)))

#define FSPtrArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayRemoveAllSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayRemoveAllSEL, _gPID)))

#define FSPtrArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayGetAtSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayGetAtSEL, _gPID)))

#define FSPtrArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArraySetAtSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArraySetAtSEL, _gPID)))

#define FSPtrArraySetAtGrow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArraySetAtGrowSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArraySetAtGrowSEL, _gPID)))

#define FSPtrArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayAddSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayAddSEL, _gPID)))

#define FSPtrArrayAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayAppendSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayAppendSEL, _gPID)))

#define FSPtrArrayCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayCopySELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayCopySEL, _gPID)))

#define FSPtrArrayGetDataPtr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayGetDataPtrSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayGetDataPtrSEL, _gPID)))

#define FSPtrArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayInsertAtSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayInsertAtSEL, _gPID)))

#define FSPtrArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayRemoveAtSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayRemoveAtSEL, _gPID)))

#define FSPtrArrayInsertNewArrayAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayInsertNewArrayAtSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayInsertNewArrayAtSEL, _gPID)))

#define FSPtrArrayFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPtrArrayFindSELPROTO)FRCOREROUTINE(FSPtrArraySEL,FSPtrArrayFindSEL, _gPID)))

//*****************************
/* ByteArray HFT functions */
//*****************************

#define FSByteArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayNewSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayNewSEL, _gPID)))

#define FSByteArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayDestroySELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayDestroySEL, _gPID)))

#define FSByteArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayGetSizeSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayGetSizeSEL, _gPID)))

#define FSByteArrayGetUpperBound (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayGetUpperBoundSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayGetUpperBoundSEL, _gPID)))

#define FSByteArraySetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArraySetSizeSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArraySetSizeSEL, _gPID)))

#define FSByteArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayRemoveAllSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayRemoveAllSEL, _gPID)))

#define FSByteArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayGetAtSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayGetAtSEL, _gPID)))

#define FSByteArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArraySetAtSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArraySetAtSEL, _gPID)))

#define FSByteArraySetAtGrow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArraySetAtGrowSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArraySetAtGrowSEL, _gPID)))

#define FSByteArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayAddSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayAddSEL, _gPID)))

#define FSByteArrayAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayAppendSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayAppendSEL, _gPID)))

#define FSByteArrayCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayCopySELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayCopySEL, _gPID)))

#define FSByteArrayGetDataPtr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayGetDataPtrSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayGetDataPtrSEL, _gPID)))

#define FSByteArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayInsertAtSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayInsertAtSEL, _gPID)))

#define FSByteArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayRemoveAtSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayRemoveAtSEL, _gPID)))

#define FSByteArrayInsertNewArrayAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayInsertNewArrayAtSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayInsertNewArrayAtSEL, _gPID)))

#define FSByteArrayFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteArrayFindSELPROTO)FRCOREROUTINE(FSByteArraySEL,FSByteArrayFindSEL, _gPID)))

//*****************************
/* WordArray HFT functions */
//*****************************

#define FSWordArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayNewSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayNewSEL, _gPID)))

#define FSWordArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayDestroySELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayDestroySEL, _gPID)))

#define FSWordArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayGetSizeSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayGetSizeSEL, _gPID)))

#define FSWordArrayGetUpperBound (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayGetUpperBoundSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayGetUpperBoundSEL, _gPID)))

#define FSWordArraySetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArraySetSizeSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArraySetSizeSEL, _gPID)))

#define FSWordArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayRemoveAllSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayRemoveAllSEL, _gPID)))

#define FSWordArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayGetAtSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayGetAtSEL, _gPID)))

#define FSWordArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArraySetAtSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArraySetAtSEL, _gPID)))

#define FSWordArraySetAtGrow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArraySetAtGrowSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArraySetAtGrowSEL, _gPID)))

#define FSWordArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayAddSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayAddSEL, _gPID)))

#define FSWordArrayAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayAppendSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayAppendSEL, _gPID)))

#define FSWordArrayCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayCopySELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayCopySEL, _gPID)))

#define FSWordArrayGetDataPtr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayGetDataPtrSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayGetDataPtrSEL, _gPID)))

#define FSWordArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayInsertAtSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayInsertAtSEL, _gPID)))

#define FSWordArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayRemoveAtSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayRemoveAtSEL, _gPID)))

#define FSWordArrayInsertNewArrayAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayInsertNewArrayAtSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayInsertNewArrayAtSEL, _gPID)))

#define FSWordArrayFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWordArrayFindSELPROTO)FRCOREROUTINE(FSWordArraySEL,FSWordArrayFindSEL, _gPID)))

//*****************************
/* DWordArray HFT functions */
//*****************************

#define FSDWordArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayNewSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayNewSEL, _gPID)))

#define FSDWordArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayDestroySELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayDestroySEL, _gPID)))

#define FSDWordArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayGetSizeSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayGetSizeSEL, _gPID)))

#define FSDWordArrayGetUpperBound (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayGetUpperBoundSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayGetUpperBoundSEL, _gPID)))

#define FSDWordArraySetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArraySetSizeSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArraySetSizeSEL, _gPID)))

#define FSDWordArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayRemoveAllSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayRemoveAllSEL, _gPID)))

#define FSDWordArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayGetAtSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayGetAtSEL, _gPID)))

#define FSDWordArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArraySetAtSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArraySetAtSEL, _gPID)))

#define FSDWordArraySetAtGrow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArraySetAtGrowSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArraySetAtGrowSEL, _gPID)))

#define FSDWordArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayAddSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayAddSEL, _gPID)))

#define FSDWordArrayAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayAppendSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayAppendSEL, _gPID)))

#define FSDWordArrayCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayCopySELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayCopySEL, _gPID)))

#define FSDWordArrayGetDataPtr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayGetDataPtrSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayGetDataPtrSEL, _gPID)))

#define FSDWordArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayInsertAtSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayInsertAtSEL, _gPID)))

#define FSDWordArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayRemoveAtSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayRemoveAtSEL, _gPID)))

#define FSDWordArrayInsertNewArrayAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayInsertNewArrayAtSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayInsertNewArrayAtSEL, _gPID)))

#define FSDWordArrayFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSDWordArrayFindSELPROTO)FRCOREROUTINE(FSDWordArraySEL,FSDWordArrayFindSEL, _gPID)))

//*****************************
/* ByteStringArray HFT functions */
//*****************************

#define FSByteStringArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayNewSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayNewSEL, _gPID)))

#define FSByteStringArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayDestroySELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayDestroySEL, _gPID)))

#define FSByteStringArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayGetAtSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayGetAtSEL, _gPID)))

#define FSByteStringArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayGetSizeSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayGetSizeSEL, _gPID)))

#define FSByteStringArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayRemoveAllSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayRemoveAllSEL, _gPID)))

#define FSByteStringArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayAddSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayAddSEL, _gPID)))

#define FSByteStringArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayRemoveAtSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayRemoveAtSEL, _gPID)))

#define FSByteStringArrayAdd2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayAdd2SELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayAdd2SEL, _gPID)))

#define FSByteStringArrayGetDataPtr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSByteStringArrayGetDataPtrSELPROTO)FRCOREROUTINE(FSByteStringArraySEL,FSByteStringArrayGetDataPtrSEL, _gPID)))

//*****************************
/* WideStringArray HFT functions */
//*****************************

#define FSWideStringArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayNewSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayNewSEL, _gPID)))

#define FSWideStringArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayDestroySELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayDestroySEL, _gPID)))

#define FSWideStringArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayGetAtSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayGetAtSEL, _gPID)))

#define FSWideStringArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayGetSizeSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayGetSizeSEL, _gPID)))

#define FSWideStringArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayRemoveAllSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayRemoveAllSEL, _gPID)))

#define FSWideStringArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayAddSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayAddSEL, _gPID)))

#define FSWideStringArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSWideStringArrayRemoveAtSELPROTO)FRCOREROUTINE(FSWideStringArraySEL,FSWideStringArrayRemoveAtSEL, _gPID)))

//*****************************
/* CodeTransformation HFT functions */
//*****************************

#define FSCodeTransformationNameDecode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationNameDecodeSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationNameDecodeSEL, _gPID)))

#define FSCodeTransformationNameEncode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationNameEncodeSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationNameEncodeSEL, _gPID)))

#define FSCodeTransformationEncodeString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationEncodeStringSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationEncodeStringSEL, _gPID)))

#define FSCodeTransformationDecodeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationDecodeTextSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationDecodeTextSEL, _gPID)))

#define FSCodeTransformationDecodeText2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationDecodeText2SELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationDecodeText2SEL, _gPID)))

#define FSCodeTransformationEncodeText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationEncodeTextSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationEncodeTextSEL, _gPID)))

#define FSCodeTransformationFlateEncodeProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationFlateEncodeProcSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationFlateEncodeProcSEL, _gPID)))

#define FSCodeTransformationFlateDecodeProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationFlateDecodeProcSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationFlateDecodeProcSEL, _gPID)))

#define FSCodeTransformationRunLengthDecodeProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationRunLengthDecodeProcSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationRunLengthDecodeProcSEL, _gPID)))

#define FSCodeTransformationRunLengthEncodeProc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationRunLengthEncodeProcSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationRunLengthEncodeProcSEL, _gPID)))

#define FSCodeTransformationMemFree (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationMemFreeSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationMemFreeSEL, _gPID)))

#define FSCodeTransformationBasicModuleA85Encode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationBasicModuleA85EncodeSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationBasicModuleA85EncodeSEL, _gPID)))

#define FSCodeTransformationFlateModuleEncode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationFlateModuleEncodeSELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationFlateModuleEncodeSEL, _gPID)))

#define FSCodeTransformationFlateModuleEncode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSCodeTransformationFlateModuleEncode2SELPROTO)FRCOREROUTINE(FSCodeTransformationSEL,FSCodeTransformationFlateModuleEncode2SEL, _gPID)))

//*****************************
/* FloatRectArray HFT functions */
//*****************************

#define FSFloatRectArrayNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayNewSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayNewSEL, _gPID)))

#define FSFloatRectArrayDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayDestroySELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayDestroySEL, _gPID)))

#define FSFloatRectArrayGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayGetSizeSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayGetSizeSEL, _gPID)))

#define FSFloatRectArrayGetUpperBound (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayGetUpperBoundSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayGetUpperBoundSEL, _gPID)))

#define FSFloatRectArraySetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArraySetSizeSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArraySetSizeSEL, _gPID)))

#define FSFloatRectArrayRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayRemoveAllSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayRemoveAllSEL, _gPID)))

#define FSFloatRectArrayGetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayGetAtSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayGetAtSEL, _gPID)))

#define FSFloatRectArraySetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArraySetAtSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArraySetAtSEL, _gPID)))

#define FSFloatRectArraySetAtGrow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArraySetAtGrowSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArraySetAtGrowSEL, _gPID)))

#define FSFloatRectArrayAdd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayAddSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayAddSEL, _gPID)))

#define FSFloatRectArrayAppend (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayAppendSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayAppendSEL, _gPID)))

#define FSFloatRectArrayCopy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayCopySELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayCopySEL, _gPID)))

#define FSFloatRectArrayInsertAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayInsertAtSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayInsertAtSEL, _gPID)))

#define FSFloatRectArrayRemoveAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayRemoveAtSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayRemoveAtSEL, _gPID)))

#define FSFloatRectArrayInsertNewArrayAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayInsertNewArrayAtSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayInsertNewArrayAtSEL, _gPID)))

#define FSFloatRectArrayFind (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFloatRectArrayFindSELPROTO)FRCOREROUTINE(FSFloatRectArraySEL,FSFloatRectArrayFindSEL, _gPID)))

//*****************************
/* BinaryBuf HFT functions */
//*****************************

#define FSBinaryBufNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufNewSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufNewSEL, _gPID)))

#define FSBinaryBufDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufDestroySELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufDestroySEL, _gPID)))

#define FSBinaryBufClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufClearSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufClearSEL, _gPID)))

#define FSBinaryBufEstimateSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufEstimateSizeSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufEstimateSizeSEL, _gPID)))

#define FSBinaryBufAppendBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufAppendBlockSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufAppendBlockSEL, _gPID)))

#define FSBinaryBufAppendFill (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufAppendFillSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufAppendFillSEL, _gPID)))

#define FSBinaryBufAppendString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufAppendStringSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufAppendStringSEL, _gPID)))

#define FSBinaryBufAppendByte (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufAppendByteSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufAppendByteSEL, _gPID)))

#define FSBinaryBufInsertBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufInsertBlockSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufInsertBlockSEL, _gPID)))

#define FSBinaryBufAttachData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufAttachDataSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufAttachDataSEL, _gPID)))

#define FSBinaryBufCopyData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufCopyDataSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufCopyDataSEL, _gPID)))

#define FSBinaryBufTakeOver (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufTakeOverSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufTakeOverSEL, _gPID)))

#define FSBinaryBufDelete (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufDeleteSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufDeleteSEL, _gPID)))

#define FSBinaryBufGetBuffer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufGetBufferSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufGetBufferSEL, _gPID)))

#define FSBinaryBufGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufGetSizeSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufGetSizeSEL, _gPID)))

#define FSBinaryBufGetByteString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufGetByteStringSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufGetByteStringSEL, _gPID)))

#define FSBinaryBufDetachBuffer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBinaryBufDetachBufferSELPROTO)FRCOREROUTINE(FSBinaryBufSEL,FSBinaryBufDetachBufferSEL, _gPID)))

//*****************************
/* PauseHandler HFT functions */
//*****************************

#define FSPauseHandlerCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPauseHandlerCreateSELPROTO)FRCOREROUTINE(FSPauseHandlerSEL,FSPauseHandlerCreateSEL, _gPID)))

#define FSPauseHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSPauseHandlerDestroySELPROTO)FRCOREROUTINE(FSPauseHandlerSEL,FSPauseHandlerDestroySEL, _gPID)))

//*****************************
/* FileReadHandler HFT functions */
//*****************************

#define FSFileReadHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerNewSELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerNewSEL, _gPID)))

#define FSFileReadHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerDestroySELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerDestroySEL, _gPID)))

#define FSFileReadHandlerGetSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerGetSizeSELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerGetSizeSEL, _gPID)))

#define FSFileReadHandlerReadBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerReadBlockSELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerReadBlockSEL, _gPID)))

#define FSFileReadHandlerNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerNew2SELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerNew2SEL, _gPID)))

#define FSFileReadHandlerNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileReadHandlerNew3SELPROTO)FRCOREROUTINE(FSFileReadHandlerSEL,FSFileReadHandlerNew3SEL, _gPID)))

//*****************************
/* StreamWriteHandler HFT functions */
//*****************************

#define FSStreamWriteHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSStreamWriteHandlerNewSELPROTO)FRCOREROUTINE(FSStreamWriteHandlerSEL,FSStreamWriteHandlerNewSEL, _gPID)))

#define FSStreamWriteHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSStreamWriteHandlerDestroySELPROTO)FRCOREROUTINE(FSStreamWriteHandlerSEL,FSStreamWriteHandlerDestroySEL, _gPID)))

#define FSStreamWriteHandlerWriteBlock (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSStreamWriteHandlerWriteBlockSELPROTO)FRCOREROUTINE(FSStreamWriteHandlerSEL,FSStreamWriteHandlerWriteBlockSEL, _gPID)))

//----------_V2----------
//*****************************
/* Base64Encoder HFT functions */
//*****************************

#define FSBase64EncoderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderNewSELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderNewSEL, _gPID)))

#define FSBase64EncoderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderDestroySELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderDestroySEL, _gPID)))

#define FSBase64EncoderSetEncoder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderSetEncoderSELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderSetEncoderSEL, _gPID)))

#define FSBase64EncoderEncode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderEncodeSELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderEncodeSEL, _gPID)))

#define FSBase64EncoderEncode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderEncode2SELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderEncode2SEL, _gPID)))

#define FSBase64EncoderEncode3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64EncoderEncode3SELPROTO)FRCOREROUTINE(FSBase64EncoderSEL,FSBase64EncoderEncode3SEL, _gPID)))

//*****************************
/* Base64Decoder HFT functions */
//*****************************

#define FSBase64DecoderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderNewSELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderNewSEL, _gPID)))

#define FSBase64DecoderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderDestroySELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderDestroySEL, _gPID)))

#define FSBase64DecoderSetDecoder (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderSetDecoderSELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderSetDecoderSEL, _gPID)))

#define FSBase64DecoderDecode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderDecodeSELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderDecodeSEL, _gPID)))

#define FSBase64DecoderDecode2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderDecode2SELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderDecode2SEL, _gPID)))

#define FSBase64DecoderDecode3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSBase64DecoderDecode3SELPROTO)FRCOREROUTINE(FSBase64DecoderSEL,FSBase64DecoderDecode3SEL, _gPID)))

//*****************************
/* FileWriteHandler HFT functions */
//*****************************

#define FSFileWriteHandlerNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileWriteHandlerNewSELPROTO)FRCOREROUTINE(FSFileWriteHandlerSEL,FSFileWriteHandlerNewSEL, _gPID)))

#define FSFileWriteHandlerDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileWriteHandlerDestroySELPROTO)FRCOREROUTINE(FSFileWriteHandlerSEL,FSFileWriteHandlerDestroySEL, _gPID)))

//*****************************
/* XMLElement HFT functions */
//*****************************

#define FSXMLElementparse (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementparseSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementparseSEL, _gPID)))

#define FSXMLElementparse2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementparse2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementparse2SEL, _gPID)))

#define FSXMLElementNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementNewSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementNewSEL, _gPID)))

#define FSXMLElementNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementNew2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementNew2SEL, _gPID)))

#define FSXMLElementNew3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementNew3SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementNew3SEL, _gPID)))

#define FSXMLElementDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementDestroySELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementDestroySEL, _gPID)))

#define FSXMLElementGetTagName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetTagNameSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetTagNameSEL, _gPID)))

#define FSXMLElementGetNamespace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetNamespaceSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetNamespaceSEL, _gPID)))

#define FSXMLElementGetNamespaceURI (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetNamespaceURISELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetNamespaceURISEL, _gPID)))

#define FSXMLElementGetParent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetParentSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetParentSEL, _gPID)))

#define FSXMLElementCountAttrs (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementCountAttrsSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementCountAttrsSEL, _gPID)))

#define FSXMLElementGetAttrByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrByIndexSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrByIndexSEL, _gPID)))

#define FSXMLElementHasAttr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementHasAttrSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementHasAttrSEL, _gPID)))

#define FSXMLElementGetAttrValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrValueSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrValueSEL, _gPID)))

#define FSXMLElementGetAttrValue2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrValue2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrValue2SEL, _gPID)))

#define FSXMLElementGetAttrInteger (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrIntegerSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrIntegerSEL, _gPID)))

#define FSXMLElementGetAttrInteger2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrInteger2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrInteger2SEL, _gPID)))

#define FSXMLElementGetAttrFloat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrFloatSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrFloatSEL, _gPID)))

#define FSXMLElementGetAttrFloat2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetAttrFloat2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetAttrFloat2SEL, _gPID)))

#define FSXMLElementCountChildren (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementCountChildrenSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementCountChildrenSEL, _gPID)))

#define FSXMLElementGetChildType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetChildTypeSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetChildTypeSEL, _gPID)))

#define FSXMLElementGetContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetContentSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetContentSEL, _gPID)))

#define FSXMLElementGetElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetElementSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetElementSEL, _gPID)))

#define FSXMLElementGetElement2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetElement2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetElement2SEL, _gPID)))

#define FSXMLElementGetElement3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementGetElement3SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementGetElement3SEL, _gPID)))

#define FSXMLElementCountElements (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementCountElementsSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementCountElementsSEL, _gPID)))

#define FSXMLElementFindElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementFindElementSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementFindElementSEL, _gPID)))

#define FSXMLElementSetTag (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementSetTagSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementSetTagSEL, _gPID)))

#define FSXMLElementSetTag2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementSetTag2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementSetTag2SEL, _gPID)))

#define FSXMLElementSetAttrValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementSetAttrValueSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementSetAttrValueSEL, _gPID)))

#define FSXMLElementSetAttrValue2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementSetAttrValue2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementSetAttrValue2SEL, _gPID)))

#define FSXMLElementSetAttrValue3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementSetAttrValue3SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementSetAttrValue3SEL, _gPID)))

#define FSXMLElementRemoveAttr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementRemoveAttrSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementRemoveAttrSEL, _gPID)))

#define FSXMLElementAddChildElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementAddChildElementSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementAddChildElementSEL, _gPID)))

#define FSXMLElementAddChildContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementAddChildContentSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementAddChildContentSEL, _gPID)))

#define FSXMLElementInsertChildElement (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementInsertChildElementSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementInsertChildElementSEL, _gPID)))

#define FSXMLElementInsertChildContent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementInsertChildContentSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementInsertChildContentSEL, _gPID)))

#define FSXMLElementRemoveChildren (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementRemoveChildrenSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementRemoveChildrenSEL, _gPID)))

#define FSXMLElementRemoveChild (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementRemoveChildSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementRemoveChildSEL, _gPID)))

#define FSXMLElementOutputStream (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementOutputStreamSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementOutputStreamSEL, _gPID)))

#define FSXMLElementOutputStream2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementOutputStream2SELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementOutputStream2SEL, _gPID)))

#define FSXMLElementClone (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSXMLElementCloneSELPROTO)FRCOREROUTINE(FSXMLElementSEL,FSXMLElementCloneSEL, _gPID)))

//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* UTF8Decoder HFT functions */
//*****************************

#define FSUTF8DecoderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderNewSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderNewSEL, _gPID)))

#define FSUTF8DecoderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderDestroySELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderDestroySEL, _gPID)))

#define FSUTF8DecoderClear (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderClearSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderClearSEL, _gPID)))

#define FSUTF8DecoderInput (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderInputSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderInputSEL, _gPID)))

#define FSUTF8DecoderAppendChar (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderAppendCharSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderAppendCharSEL, _gPID)))

#define FSUTF8DecoderClearStatus (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderClearStatusSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderClearStatusSEL, _gPID)))

#define FSUTF8DecoderGetResult (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8DecoderGetResultSELPROTO)FRCOREROUTINE(FSUTF8DecoderSEL,FSUTF8DecoderGetResultSEL, _gPID)))

//*****************************
/* UTF8Encoder HFT functions */
//*****************************

#define FSUTF8EncoderNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderNewSELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderNewSEL, _gPID)))

#define FSUTF8EncoderDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderDestroySELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderDestroySEL, _gPID)))

#define FSUTF8EncoderInput (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderInputSELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderInputSEL, _gPID)))

#define FSUTF8EncoderAppendStr (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderAppendStrSELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderAppendStrSEL, _gPID)))

#define FSUTF8EncoderGetResult (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderGetResultSELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderGetResultSEL, _gPID)))

#define FSUTF8EncoderIsUTF8Data (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUTF8EncoderIsUTF8DataSELPROTO)FRCOREROUTINE(FSUTF8EncoderSEL,FSUTF8EncoderIsUTF8DataSEL, _gPID)))

//----------_V6----------
//*****************************
/* FileStream HFT functions */
//*****************************

#define FSFileStreamNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileStreamNewSELPROTO)FRCOREROUTINE(FSFileStreamSEL,FSFileStreamNewSEL, _gPID)))

#define FSFileStreamNew2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileStreamNew2SELPROTO)FRCOREROUTINE(FSFileStreamSEL,FSFileStreamNew2SEL, _gPID)))

#define FSFileStreamDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSFileStreamDestroySELPROTO)FRCOREROUTINE(FSFileStreamSEL,FSFileStreamDestroySEL, _gPID)))

//----------_V7----------
//*****************************
/* GUID HFT functions */
//*****************************

#define FSGUIDCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSGUIDCreateSELPROTO)FRCOREROUTINE(FSGUIDSEL,FSGUIDCreateSEL, _gPID)))

#define FSGUIDToString (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSGUIDToStringSELPROTO)FRCOREROUTINE(FSGUIDSEL,FSGUIDToStringSEL, _gPID)))

//----------_V8----------
//----------_V9----------
//*****************************
/* UUID HFT functions */
//*****************************

#define FSUUIDGenerate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDGenerateSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDGenerateSEL, _gPID)))

#define FSUUIDGenerateTime (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDGenerateTimeSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDGenerateTimeSEL, _gPID)))

#define FSUUIDGenerateRandom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDGenerateRandomSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDGenerateRandomSEL, _gPID)))

#define FSUUIDSetTsPath (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDSetTsPathSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDSetTsPathSEL, _gPID)))

#define FSUUIDSetState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDSetStateSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDSetStateSEL, _gPID)))

#define FSUUIDSetUserData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSUUIDSetUserDataSELPROTO)FRCOREROUTINE(FSUUIDSEL,FSUUIDSetUserDataSEL, _gPID)))

//*****************************
/* MapByteStringToPtr HFT functions */
//*****************************

#define FSMapByteStringToPtrNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrNewSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrNewSEL, _gPID)))

#define FSMapByteStringToPtrDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrDestroySELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrDestroySEL, _gPID)))

#define FSMapByteStringToPtrGetCount (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrGetCountSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrGetCountSEL, _gPID)))

#define FSMapByteStringToPtrIsEmpty (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrIsEmptySELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrIsEmptySEL, _gPID)))

#define FSMapByteStringToPtrLookup (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrLookupSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrLookupSEL, _gPID)))

#define FSMapByteStringToPtrSetAt (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrSetAtSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrSetAtSEL, _gPID)))

#define FSMapByteStringToPtrRemoveKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrRemoveKeySELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrRemoveKeySEL, _gPID)))

#define FSMapByteStringToPtrRemoveAll (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrRemoveAllSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrRemoveAllSEL, _gPID)))

#define FSMapByteStringToPtrGetStartPosition (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrGetStartPositionSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrGetStartPositionSEL, _gPID)))

#define FSMapByteStringToPtrGetNextAssoc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrGetNextAssocSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrGetNextAssocSEL, _gPID)))

#define FSMapByteStringToPtrGetNextValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrGetNextValueSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrGetNextValueSEL, _gPID)))

#define FSMapByteStringToPtrGetHashTableSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrGetHashTableSizeSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrGetHashTableSizeSEL, _gPID)))

#define FSMapByteStringToPtrInitHashTable (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrInitHashTableSELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrInitHashTableSEL, _gPID)))

#define FSMapByteStringToPtrHashKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FSMapByteStringToPtrHashKeySELPROTO)FRCOREROUTINE(FSMapByteStringToPtrSEL,FSMapByteStringToPtrHashKeySEL, _gPID)))

//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif