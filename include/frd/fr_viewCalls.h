/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FR_VIEWCALLS_H
#define FR_VIEWCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "fr_viewExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fr_viewImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fr_viewTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fr_viewImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fr_viewTempl.h"

//----------_V1----------
//*****************************
/* DocView HFT functions */
//*****************************

#define FRDocViewGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetDocumentSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetDocumentSEL, _gPID)))

#define FRDocViewCountPageViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewCountPageViewsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewCountPageViewsSEL, _gPID)))

#define FRDocViewGetPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetPageViewSEL, _gPID)))

#define FRDocViewGetPageViewAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetPageViewAtPointSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetPageViewAtPointSEL, _gPID)))

#define FRDocViewCountVisiblePageViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewCountVisiblePageViewsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewCountVisiblePageViewsSEL, _gPID)))

#define FRDocViewGetVisiblePageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetVisiblePageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetVisiblePageViewSEL, _gPID)))

#define FRDocViewGotoPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewSEL, _gPID)))

#define FRDocViewGotoPageViewByPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByPointSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByPointSEL, _gPID)))

#define FRDocViewGotoPageViewByRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByRectSEL, _gPID)))

#define FRDocViewGetCurrentPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetCurrentPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetCurrentPageViewSEL, _gPID)))

#define FRDocViewGetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetRotationSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetRotationSEL, _gPID)))

#define FRDocViewSetRotation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewSetRotationSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewSetRotationSEL, _gPID)))

#define FRDocViewGetLayoutMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetLayoutModeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetLayoutModeSEL, _gPID)))

#define FRDocViewSetLayoutMode (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewSetLayoutModeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewSetLayoutModeSEL, _gPID)))

#define FRDocViewGetZoom (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetZoomSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetZoomSEL, _gPID)))

#define FRDocViewGetZoomType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetZoomTypeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetZoomTypeSEL, _gPID)))

#define FRDocViewZoomTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewZoomToSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewZoomToSEL, _gPID)))

#define FRDocViewGoBack (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGoBackSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGoBackSEL, _gPID)))

#define FRDocViewGoForward (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGoForwardSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGoForwardSEL, _gPID)))

#define FRDocViewShowAnnots (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewShowAnnotsSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewShowAnnotsSEL, _gPID)))

#define FRDocViewProcAction (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewProcActionSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewProcActionSEL, _gPID)))

#define FRDocViewScrollTo (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewScrollToSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewScrollToSEL, _gPID)))

#define FRDocViewGetMaxScrollingSize (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetMaxScrollingSizeSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetMaxScrollingSizeSEL, _gPID)))

#define FRDocViewDrawNow (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDrawNowSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDrawNowSEL, _gPID)))

#define FRDocViewInvalidateRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewInvalidateRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewInvalidateRectSEL, _gPID)))

#define FRDocViewDrawRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDrawRectSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDrawRectSEL, _gPID)))

#define FRDocViewDoPopUpMenu (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewDoPopUpMenuSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewDoPopUpMenuSEL, _gPID)))

#define FRDocViewGetMachinePort (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetMachinePortSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetMachinePortSEL, _gPID)))

#define FRDocViewReleaseMachinePort (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewReleaseMachinePortSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewReleaseMachinePortSEL, _gPID)))

#define FRDocViewGetOCContext (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetOCContextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetOCContextSEL, _gPID)))

#define FRDocViewGetCurrentSnapshot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetCurrentSnapshotSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetCurrentSnapshotSEL, _gPID)))

#define FRDocViewGetThumbnailView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetThumbnailViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetThumbnailViewSEL, _gPID)))

#define FRDocViewGotoPageViewByState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGotoPageViewByStateSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGotoPageViewByStateSEL, _gPID)))

#define FRDocViewMovePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewMovePageSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewMovePageSEL, _gPID)))

#define FRDocViewIsValidPageView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewIsValidPageViewSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewIsValidPageViewSEL, _gPID)))

#define FRDocViewGetTagDocViewText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetTagDocViewTextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetTagDocViewTextSEL, _gPID)))

#define FRDocViewGetLRDocViewText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRDocViewGetLRDocViewTextSELPROTO)FRCOREROUTINE(FRDocViewSEL,FRDocViewGetLRDocViewTextSEL, _gPID)))

//*****************************
/* PageView HFT functions */
//*****************************

#define FRPageViewGetDocument (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetDocumentSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetDocumentSEL, _gPID)))

#define FRPageViewGetDocView (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetDocViewSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetDocViewSEL, _gPID)))

#define FRPageViewGetPDPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPDPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPDPageSEL, _gPID)))

#define FRPageViewGetPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageIndexSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageIndexSEL, _gPID)))

#define FRPageViewCountAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewCountAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewCountAnnotSEL, _gPID)))

#define FRPageViewGetCurrentMatrix (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetCurrentMatrixSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetCurrentMatrixSEL, _gPID)))

#define FRPageViewDevicePointToPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDevicePointToPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDevicePointToPageSEL, _gPID)))

#define FRPageViewDeviceRectToPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDeviceRectToPageSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDeviceRectToPageSEL, _gPID)))

#define FRPageViewPointToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewPointToDeviceSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewPointToDeviceSEL, _gPID)))

#define FRPageViewRectToDevice (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewRectToDeviceSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewRectToDeviceSEL, _gPID)))

#define FRPageViewIsVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewIsVisibleSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewIsVisibleSEL, _gPID)))

#define FRPageViewGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageRectSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageRectSEL, _gPID)))

#define FRPageViewGetPageVisibleRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageVisibleRectSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageVisibleRectSEL, _gPID)))

#define FRPageViewDidContentChanged (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChangedSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChangedSEL, _gPID)))

#define FRPageViewGetHWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetHWndSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetHWndSEL, _gPID)))

#define FRPageViewDidTextObjectChanged (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidTextObjectChangedSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidTextObjectChangedSEL, _gPID)))

#define FRPageViewGetAnnotByIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetAnnotByIndexSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetAnnotByIndexSEL, _gPID)))

#define FRPageViewGetPageState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageStateSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageStateSEL, _gPID)))

#define FRPageViewDeleteAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDeleteAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDeleteAnnotSEL, _gPID)))

#define FRPageViewGetFocusAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetFocusAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetFocusAnnotSEL, _gPID)))

#define FRPageViewGetPageScale (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetPageScaleSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetPageScaleSEL, _gPID)))

#define FRPageViewGetAnnotAtPoint (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetAnnotAtPointSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetAnnotAtPointSEL, _gPID)))

#define FRPageViewUpdateAllViews (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewUpdateAllViewsSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewUpdateAllViewsSEL, _gPID)))

#define FRPageViewAddAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewAddAnnotSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewAddAnnotSEL, _gPID)))

#define FRPageViewGetRenderOptions (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewGetRenderOptionsSELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewGetRenderOptionsSEL, _gPID)))

#define FRPageViewDidContentChanged2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChanged2SELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChanged2SEL, _gPID)))

#define FRPageViewDidContentChanged3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRPageViewDidContentChanged3SELPROTO)FRCOREROUTINE(FRPageViewSEL,FRPageViewDidContentChanged3SEL, _gPID)))

//*****************************
/* TextSelectTool HFT functions */
//*****************************

#define FRTextSelectToolCreate (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolCreateSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolCreateSEL, _gPID)))

#define FRTextSelectToolDestroyTextSelectTool (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDestroyTextSelectToolSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDestroyTextSelectToolSEL, _gPID)))

#define FRTextSelectToolGetSelectedText (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolGetSelectedTextSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolGetSelectedTextSEL, _gPID)))

#define FRTextSelectToolDrawSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDrawSelectionSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDrawSelectionSEL, _gPID)))

#define FRTextSelectToolClearSelection (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolClearSelectionSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolClearSelectionSEL, _gPID)))

#define FRTextSelectToolDoLButtonUp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoLButtonUpSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoLButtonUpSEL, _gPID)))

#define FRTextSelectToolDoLButtonDown (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoLButtonDownSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoLButtonDownSEL, _gPID)))

#define FRTextSelectToolDoLButtonDblClk (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoLButtonDblClkSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoLButtonDblClkSEL, _gPID)))

#define FRTextSelectToolDoRButtonUp (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoRButtonUpSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoRButtonUpSEL, _gPID)))

#define FRTextSelectToolDoMouseMove (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoMouseMoveSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoMouseMoveSEL, _gPID)))

#define FRTextSelectToolDoMouseWheel (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolDoMouseWheelSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolDoMouseWheelSEL, _gPID)))

#define FRTextSelectToolIsSelecting (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolIsSelectingSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolIsSelectingSEL, _gPID)))

#define FRTextSelectToolEnumTextObjectRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRTextSelectToolEnumTextObjectRectSELPROTO)FRCOREROUTINE(FRTextSelectToolSEL,FRTextSelectToolEnumTextObjectRectSEL, _gPID)))

//----------_V2----------
//----------_V3----------
//*****************************
/* ThumbnailView HFT functions */
//*****************************

#define FRThumbnailViewCountPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewCountPageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewCountPageSEL, _gPID)))

#define FRThumbnailViewCountVisiblePage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewCountVisiblePageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewCountVisiblePageSEL, _gPID)))

#define FRThumbnailViewGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetPageRectSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetPageRectSEL, _gPID)))

#define FRThumbnailViewGetVisiblePageRange (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetVisiblePageRangeSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetVisiblePageRangeSEL, _gPID)))

#define FRThumbnailViewGetPDPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRThumbnailViewGetPDPageSELPROTO)FRCOREROUTINE(FRThumbnailViewSEL,FRThumbnailViewGetPDPageSEL, _gPID)))

//----------_V4----------
//----------_V5----------
//*****************************
/* Annot HFT functions */
//*****************************

#define FRAnnotGetPDFAnnot (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetPDFAnnotSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetPDFAnnotSEL, _gPID)))

#define FRAnnotGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetTypeSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetTypeSEL, _gPID)))

#define FRAnnotGetSubType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetSubTypeSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetSubTypeSEL, _gPID)))

#define FRAnnotSetVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotSetVisibleSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotSetVisibleSEL, _gPID)))

#define FRAnnotGetPageVew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRAnnotGetPageVewSELPROTO)FRCOREROUTINE(FRAnnotSEL,FRAnnotGetPageVewSEL, _gPID)))

//*****************************
/* ResourcePropertyBox HFT functions */
//*****************************

#define FRResourcePropertyBoxGet (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxGetSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxGetSEL, _gPID)))

#define FRResourcePropertyBoxRegisterPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxRegisterPropertyPageSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxRegisterPropertyPageSEL, _gPID)))

#define FRResourcePropertyBoxRegisterSourceType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxRegisterSourceTypeSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxRegisterSourceTypeSEL, _gPID)))

#define FRResourcePropertyBoxGetSourceType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxGetSourceTypeSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxGetSourceTypeSEL, _gPID)))

#define FRResourcePropertyBoxGetSourceFunc (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxGetSourceFuncSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxGetSourceFuncSEL, _gPID)))

#define FRResourcePropertyBoxUpdatePropertyBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxUpdatePropertyBoxSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxUpdatePropertyBoxSEL, _gPID)))

#define FRResourcePropertyBoxOpenPropertyBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxOpenPropertyBoxSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxOpenPropertyBoxSEL, _gPID)))

#define FRResourcePropertyBoxClosePropertyBox (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxClosePropertyBoxSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxClosePropertyBoxSEL, _gPID)))

#define FRResourcePropertyBoxIsPropertyBoxVisible (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxIsPropertyBoxVisibleSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxIsPropertyBoxVisibleSEL, _gPID)))

#define FRResourcePropertyBoxGetWnd (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxGetWndSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxGetWndSEL, _gPID)))

#define FRResourcePropertyBoxGetPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxGetPropertyPageSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxGetPropertyPageSEL, _gPID)))

#define FRResourcePropertyBoxSetCurrentPropertyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxSetCurrentPropertyPageSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxSetCurrentPropertyPageSEL, _gPID)))

#define FRResourcePropertyBoxRegisterPropertyPage2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxRegisterPropertyPage2SELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxRegisterPropertyPage2SEL, _gPID)))

#define FRResourcePropertyBoxDestroyPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxDestroyPageSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxDestroyPageSEL, _gPID)))

#define FRResourcePropertyBoxRegisterSourceType2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxRegisterSourceType2SELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxRegisterSourceType2SEL, _gPID)))

#define FRResourcePropertyBoxDestroySource (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRResourcePropertyBoxDestroySourceSELPROTO)FRCOREROUTINE(FRResourcePropertyBoxSEL,FRResourcePropertyBoxDestroySourceSEL, _gPID)))

//----------_V6----------
//*****************************
/* ScrollBarThumbnailView HFT functions */
//*****************************

#define FRScrollBarThumbnailViewGetCurPageIndex (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRScrollBarThumbnailViewGetCurPageIndexSELPROTO)FRCOREROUTINE(FRScrollBarThumbnailViewSEL,FRScrollBarThumbnailViewGetCurPageIndexSEL, _gPID)))

#define FRScrollBarThumbnailViewGetPageRect (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRScrollBarThumbnailViewGetPageRectSELPROTO)FRCOREROUTINE(FRScrollBarThumbnailViewSEL,FRScrollBarThumbnailViewGetPageRectSEL, _gPID)))

#define FRScrollBarThumbnailViewGetPDPage (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FRScrollBarThumbnailViewGetPDPageSELPROTO)FRCOREROUTINE(FRScrollBarThumbnailViewSEL,FRScrollBarThumbnailViewGetPDPageSEL, _gPID)))

//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif