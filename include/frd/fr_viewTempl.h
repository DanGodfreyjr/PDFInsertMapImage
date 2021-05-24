/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

//----------_V1----------
//*****************************
/* DocView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRDocViewGetDocument
 * @details Gets the <a>FR_Document</a> associated with specifed document view..
 * @param[in]  docView The document view whose <a>FR_Document</a>is obtained.
 * @return   The <a>FR_Document</a> associated with the document view.
 * @note 
 * @see FRDocGetDocView
 * @see FRDocGetCurrentDocView
 * @see FRDocViewGetPageView
 * @see FRPageViewGetDocument
 */
INTERFACE(FR_Document, FRDocViewGetDocument, (FR_DocView docView))

/**
 * @brief FRDocViewCountPageViews
 * @details Gets the number of page views for the specified document view.
 * @param[in]  docView The document view whose page view count is obtained.
 * @return   The number of <a>FR_PageView</a> object associated with the document view.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewCountVisiblePageViews
 */
INTERFACE(FS_INT32, FRDocViewCountPageViews, (FR_DocView docView))

/**
 * @brief FRDocViewGetPageView
 * @details Gets the specified <a>FR_PageView</a> for specified document view.
 * @param[in]  docView The document view whose <a>FR_PageView</a> is obtained.
 * @param[in]  iPage The index of page view to obtain. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @return   The specified <a>FR_PageView</a> of the document view.
 * @note 
 * @see FRDocViewCountPageViews
 * @see FRDocViewGetVisiblePageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetPageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGetPageViewAtPoint
 * @details Gets a specified <a>FR_PageView</a> with a point which is underlying to the area of page view.
 * @param[in]  docView The document view whose <a>FR_PageView</a> is obtained.
 * @param[in]  point The point of screen coordinate system to obtain a page view.
 * @return   The specified <a>FR_PageView</a> of the document view if the point is in the area of the page view, otherwise 
	* <a>NULL</a>.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewGetVisiblePageView
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetPageViewAtPoint, (FR_DocView docView,  FS_DevicePoint point))

/**
 * @brief FRDocViewCountVisiblePageViews
 * @details Gets the number of visible page views for specified document view.
 * @param[in]  docView The document view whose page view count is obtained.
 * @return   The number of visible page views.
 * @note 
 * @see FRDocViewCountPageViews
 */
INTERFACE(FS_INT32, FRDocViewCountVisiblePageViews, (FR_DocView docView))

/**
 * @brief FRDocViewGetVisiblePageView
 * @details Gets the specified visible page.
 * @param[in]  docView The document view whose page view is obtained.
 * @param[in]  iPage The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
 * @return   The specified <a>FR_PageView</a>	of the document view.
 * @note 
 * @see FRDocViewGetPageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetCurrentPageView
 */
INTERFACE(FR_PageView, FRDocViewGetVisiblePageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGotoPageView
 * @details Goes to specified page, retaining the current display mode. It invalidates the display, but not
	* always perform an immediately redraw.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @return   void
 * @note 
 * @see FRDocViewGotoPageViewByPoint
 * @see FRDocViewGotoPageViewByRect
 */
INTERFACE(void, FRDocViewGotoPageView, (FR_DocView docView,  FS_INT32 iPage))

/**
 * @brief FRDocViewGotoPageViewByPoint
 * @details Goes to specified page and scroll page view to the location specified by <param>left</param> and <param>top</param>, retaining the 
	* current display mode. It invalidates the display, but not always perform an immediately redraw.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @param[in]  left The x-coordinate to scroll to. Specified in PDF space coordinates.
 * @param[in]  top The y-coordinate to scroll to. Specified in PDF space coordinates.
 * @return   void
 * @note 
 * @see FRDocViewGotoPageView
 * @see FRDocViewGotoPageViewByRect
 */
INTERFACE(void, FRDocViewGotoPageViewByPoint, (FR_DocView docView,  FS_INT32 iPage,  FS_FLOAT left,  FS_FLOAT top))

/**
 * @brief FRDocViewGotoPageViewByRect
 * @details Goes to specified page view and scroll to center of the rectangle. It always change the zoom level if necessary.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The index of the visible page. The index range is 0 to (<a>FRDocViewCountVisiblePageViews</a>()-1).
 * @param[in]  rect The rectangle that is completely visible.
 * @return   void
 * @note 
 * @see FRDocViewGotoPageView
 * @see FRDocViewGotoPageViewByPoint
 */
INTERFACE(void, FRDocViewGotoPageViewByRect, (FR_DocView docView,  FS_INT32 iPage,  FS_FloatRect rect))

/**
 * @brief FRDocViewGetCurrentPageView
 * @details Gets current page view that is visible in screen.
 * @param[in]  docView The document.
 * @return   Current <a>FR_PageView</a> that is visible in screen.
 * @note If more than one page may be visible. use FRDocViewCountVisiblePageViews() and FRDocViewGetVisiblePageView() instead.
 * @see FRDocViewGetPageView
 * @see FRDocViewGetPageViewAtPoint
 * @see FRDocViewGetGetVisiblePageView
 */
INTERFACE(FR_PageView, FRDocViewGetCurrentPageView, (FR_DocView docView))

/**
 * @brief FRDocViewGetRotation
 * @details Gets the rotation factor.
 * @param[in]  docView The document view to obtain rotation factor.
 * @return   A integer described in group <a>FR_RotationFlags</a>.
 * @note 
 * @see 
 */
INTERFACE(FS_INT32, FRDocViewGetRotation, (FR_DocView docView))

/**
 * @brief FRDocViewSetRotation
 * @details Sets the rotation factor.
 * @param[in]  docView The document view to obtain rotation factor.
 * @param[in]  nFlag A integer described in group <a>FR_RotationFlags</a>.
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRDocViewSetRotation, (FR_DocView docView,  FS_INT32 nFlag))

/**
 * @brief FRDocViewGetLayoutMode
 * @details Gets the page layout mode.
 * @param[in]  docView The document view whose layout mode is obtained.
 * @return   The current page layout mode, a <a>FRDOC_LAYOUTMODE</a> enumeration value.
 * @note 
 */
INTERFACE(FRDOCVIEW_LAYOUTMODE, FRDocViewGetLayoutMode, (FR_DocView docView))

/**
 * @brief FRDocViewSetLayoutMode
 * @details Sets the page layout mode for a document view.
 * @param[in]  docView The document view whose layout mode is set.
 * @param[in]  mode The new layout mode for document view.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewSetLayoutMode, (FR_DocView docView,  FRDOCVIEW_LAYOUTMODE mode))

/**
 * @brief FRDocViewGetZoom
 * @details Gets the current zoom for page view. The zoom factor is point-to-point, not point-to-pixel.
 * @param[in]  docView The document view.
 * @return   The current zoom for page view.
 * @note Current zoom, as a fixed number measured in units in which 1.0 is 100% zoom.
 * @see FRDocViewGetZoomType
 * @see FRDocViewZoomTo
 */
INTERFACE(FS_FLOAT, FRDocViewGetZoom, (FR_DocView docView))

/**
 * @brief FRDocViewGetZoomType
 * @details Gets the current zoom type.
 * @param[in]  docView The document view.
 * @return   Current zoom type.
 * @note 
 * @see FRDocViewGetZoom
 * @see FRDocViewZoomTo
 */
INTERFACE(FRDOCVIEW_ZOOMTYPE, FRDocViewGetZoomType, (FR_DocView docView))

/**
 * @brief FRDocViewZoomTo
 * @details Sets the zoom factor and zoom type to specified page view.
 * @param[in]  docView The document view.
 * @param[in]  mode The zoom mode to set.
 * @param[in]  scale The zoom factor, specified as a magnification factor(for example,
	* 1.0 displays the document at actual size). This is ignore unless iFittype parameter is
	* <a>FR_ZOOM_MODE_ACTUAL_SCALE</a> or <a>FR_ZOOM_MODE_NONE</a>.
 * @return   void
 * @note 
 * @see FRDocViewGetZoom
 * @see FRDocViewGetZoomType
 */
INTERFACE(void, FRDocViewZoomTo, (FR_DocView docView,  FRDOCVIEW_ZOOMTYPE mode,  FS_FLOAT scale))

/**
 * @brief FRDocViewGoBack
 * @details Goes to the previous view on the view stack, if a previous view exist.
 * @param[in]  docView The document view.
 * @return   void
 * @note 
 * @see FRDocViewGoForward
 */
INTERFACE(void, FRDocViewGoBack, (FR_DocView docView))

/**
 * @brief FRDocViewGoForward
 * @details Goes to the next view on the view stack, if a next view exist.
 * @param[in]  docView The document view.
 * @return   void
 * @note 
 * @see FRDocViewGoBack
 */
INTERFACE(void, FRDocViewGoForward, (FR_DocView docView))

/**
 * @brief FRDocViewShowAnnots
 * @details If <param>bShow</param> is set <a>TRUE</a>, the annotations will be shown. Otherwise not. This interface is not available in version 1.0.
 * @param[in]  docView The document view.
 * @param[in]  annots The array of annotations to be shown.
 * @param[in]  bShow Whether to show or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewShowAnnots, (FR_DocView docView,  FS_PtrArray* annots,  FS_BOOL bShow))

/**
 * @brief FRDocViewProcAction
 * @details Performs a specified action.
 * @param[in]  docView The document view.
 * @param[in]  action A <a>FPD_Action</a> object to be performed.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewProcAction, (FR_DocView docView,  FPD_Action action))

/**
 * @brief FRDocViewScrollTo
 * @details Scrolls the specified document view to location specified by <param>x</param> and <param>y</param>.
 * @param[in]  docView The document view to scroll.
 * @param[in]  x The x-coordinate to scroll to, specified in device space coordinates.
 * @param[in]  y The y-coordinate to scroll to, specified in device space coordinates.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewScrollTo, (FR_DocView docView,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRDocViewGetMaxScrollingSize
 * @details Gets the maximum scrolling size of the document view.
 * @param[in]  docView The input document view.
 * @param[out]  outWidth It receives the horizontal maximum scrolling size.
 * @param[out]  outHeight It receives the vertical maximum scrolling size.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocViewGetMaxScrollingSize, (FR_DocView docView,  FS_INT32* outWidth,  FS_INT32* outHeight))

/**
 * @brief FRDocViewDrawNow
 * @details Forces specified document view to redraw.
 * @param[in]  docView The document view to redraw.
 * @return   void
 * @note 
 * @see FRDocViewInvalidateRect
 */
INTERFACE(void, FRDocViewDrawNow, (FR_DocView docView))

/**
 * @brief FRDocViewInvalidateRect
 * @details Redraws the specified area of document view immediately.
 * @param[in]  docView The document view in which a region is invalidated.
 * @param[in]  rect The rectangle to invalidate, specified in device space coordinates.
 * @return   void
 * @note 
 * @see FRDocViewDrawNow
 */
INTERFACE(void, FRDocViewInvalidateRect, (FR_DocView docView,  FS_Rect rect))

/**
 * @brief FRDocViewDrawRect
 * @details Draws rectangle in the doc view.
 * @param[in]  docView The input doc view.
 * @param[in]  rect The input rectangle.
 * @param[in]  fill_argb The color to fill.
 * @param[in]  bCompose Whether to compose or not.
 * @return   void
 * @note 
 * @see FRDocViewDrawLine
 * @see FRDocViewDrawRectOutline
 * @see FRDocViewDrawPolygon
 * @see FRDocViewDrawPolygonOutline
 */
INTERFACE(void, FRDocViewDrawRect, (FR_DocView docView,  FS_Rect rect,  FS_ARGB fill_argb,  FS_BOOL bCompose))

/**
 * @brief FRDocViewDoPopUpMenu
 * @details Displays the given menu as a pop-up menu anchored at <param>xHi</param>t and <param>yHit</param>, which are in device
	* space coordinates relative to <param>docView</param>.
 * @param[in]  docView The document view in which the menu appears.
 * @param[in]  menu The displayed menu.
 * @param[in]  xHit The x-coordinate of the upper left corner of the menu.
 * @param[in]  yHit The y-coordinate of the upper left corner of the menu.
 * @return   The menu item clicked by user.
 * @note 
 * @see FRMenuTrackPopup
 */
INTERFACE(FR_MenuItem, FRDocViewDoPopUpMenu, (FR_DocView docView,  FR_Menu menu,  FS_INT32 xHit,  FS_INT32 yHit))

/**
 * @brief FRDocViewGetMachinePort
 * @details Gets the platform-specific object needed to draw into page view using a platform's native 
	* graphic calls. In Win32 OS, it is a <a>FR_WinPort</a> object which contain the <Italic>HWND</Italic> handler and 
	* the device context. When done, release it using <a>FRDocViewReleaseMachinePort</a>().
 * @param[in]  docView The document view whose <Italic>HWND</Italic> handler and device context are obtained.
 * @return   The <a>FR_WinPort</a> object.
 * @note 
 * @see FRDocViewReleaseMachinePort
 */
INTERFACE(FR_WinPort, FRDocViewGetMachinePort, (FR_DocView docView))

/**
 * @brief FRDocViewReleaseMachinePort
 * @details Releases a <a>FR_WinPort</a> that acquired form page view using <a>FRDocViewGetMachinePort</a>().
 * @param[in]  docView The document view whose <Italic>HWND</Italic> handler and device context are released.
 * @param[in]  port The platform-dependent object to release.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRDocViewGetMachinePort
 */
INTERFACE(FS_BOOL, FRDocViewReleaseMachinePort, (FR_DocView docView,  FR_WinPort port))

/**
 * @brief FRDocViewGetOCContext
 * @details Gets the <Italic>OCG</Italic> context of Reader doc view.
 * @param[in]  docView The document view whose ocg context are obtained.
 * @return   The <Italic>OCG</Italic> context of Reader doc view.
 * @note 
 */
INTERFACE(FPD_OCContext, FRDocViewGetOCContext, (FR_DocView docView))

/**
 * @brief FRDocViewGetCurrentSnapshot
 * @details Gets current snapshot image that generated by using snapshot tool.
 * @param[in]  docView The document view whose snapshot image are obtained.
 * @return   A <a>FS_DIBitmap</a> object indicates current snapshot image. This <a>FS_DIBitmap</a> object must be destroied by calling
	* <a>FSDIBitmapDestroy</a>().
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRDocViewGetCurrentSnapshot, (FR_DocView docView))

/**
 * @brief FRDocViewGetThumbnailView
 * @details Gets the thumbnail view related to the input document view.
 * @param[in]  docView The input document view.
 * @return   A <a>FR_ThumbnailView</a> object related to the input document view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_ThumbnailView, FRDocViewGetThumbnailView, (FR_DocView docView))

/**
 * @brief FRDocViewGotoPageViewByState
 * @details Goes to the page view by state.
 * @param[in]  docView The document view whose page view to go to.
 * @param[in]  iPage The specified page index. The index range is 0 to (<a>FRDocViewCountPageViews</a>()-1).
 * @param[in]  iFitType The input fit type.
 * @param[in]  destArray The input destination array.
 * @param[in]  destArrayCount The count of the destination array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRDocViewGotoPageViewByPoint
 * @see FRDocViewGotoPageViewByRect
 */
INTERFACE(void, FRDocViewGotoPageViewByState, (FR_DocView docView,  FS_INT32 iPage,  FS_INT32 iFitType,  FS_FLOAT* destArray,  FS_INT32 destArrayCount))

/**
 * @brief FRDocViewMovePage
 * @details Moves the page.
 * @param[in]  docView The document view.
 * @param[in]  ptDest The dest point.
 * @param[in]  ptSrc The source point.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRDocViewMovePage, (FR_DocView docView,  FS_DevicePoint ptDest,  FS_DevicePoint ptSrc))

/**
 * @brief FRDocViewIsValidPageView
 * @details Checks whether the page view is valid or not.
 * @param[in]  docView The document view.
 * @param[in]  pPageView The page view.
 * @return   TRUE if the page view is valid, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocViewIsValidPageView, (FR_DocView docView,  FR_PageView pPageView))

/**
 * @brief FRDocViewGetTagDocViewText
 * @details Gets the text of a page in Tag Order.
 * @param[in]  docView The document view.
 * @param[out]  outText It receives the text got.
 * @param[in]  nCount The count of page text to get, -1 for the end of the page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewGetTagDocViewText, (FR_DocView docView,  FS_WideString* outText,  FS_INT32 nCount))

/**
 * @brief FRDocViewGetLRDocViewText
 * @details Gets the text of a page in LR Order.
 * @param[in]  docView The document view.
 * @param[out]  outText It receives the text got.
 * @param[in]  nCount The count of page text to get, -1 for the end of the page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRDocViewGetLRDocViewText, (FR_DocView docView,  FS_WideString* outText,  FS_INT32 nCount))

NumOfSelector(FRDocView)
ENDENUM

//*****************************
/* PageView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPageViewGetDocument
 * @details Gets the <a>FR_Document</a> for the document currently displayed in specified pageview.
 * @param[in]  pv The page view whose <a>FR_Document</a> is obtained.
 * @return   The <a>FR_Document</a> for <param>pv</param>.
 * @note 
 * @see FRDocViewGetDocument
 * @see FRPageViewGetDocView
 */
INTERFACE(FR_Document, FRPageViewGetDocument, (FR_PageView pv))

/**
 * @brief FRPageViewGetDocView
 * @details Gets the <a>FR_DocView</a> for specified pageview.
 * @param[in]  pv The page view whose <a>FR_DocView</a> is obtained.
 * @return   The <a>FR_DocView</a> for <param>pv</param>.
 * @note 
 * @see FRDocGetDocView
 * @see FRDocGetCurrentDocView
 * @see FRDocViewGetPageView
 */
INTERFACE(FR_DocView, FRPageViewGetDocView, (FR_PageView pv))

/**
 * @brief FRPageViewGetPDPage
 * @details Gets a <a>FPD_Page</a> currently displayed in the specified page view. This do not new a
	* <a>FPD_Page</a> object. Do not use this result across methods that might change the current page.
	* To obtain a value that can be used across such calls, use <a>FPD_PageNew</a> instead.
 * @param[in]  pv The page view whose <a>FPD_Page</a> is obtained.
 * @return   <a>FPD_Page</a> displayed in <param>pv</param>,	or <a>NULL</a> if no valid <a>FPD_Page</a>
	* associated with <param>pv</param>.
 * @note 
 * @see FRDocGetPDDoc
 */
INTERFACE(FPD_Page, FRPageViewGetPDPage, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageIndex
 * @details Gets the current page number.
 * @param[in]  pv The page view whose current page number is obtained.
 * @return   The current page number, or <a>NULL</a> if <param>pv</param> is invalid. The first page number of a document
	* is page 0.
 * @note 
 */
INTERFACE(FS_INT32, FRPageViewGetPageIndex, (FR_PageView pv))

/**
 * @brief FRPageViewCountAnnot
 * @details Gets the number of annotations associated with specified page view. This interface is not available in version 1.0.
 * @param[in]  pv The page view whose annotation count is obtained.
 * @return   The number of annotations associated with <param>pv</param>.
 * @note 
 */
INTERFACE(FS_INT32, FRPageViewCountAnnot, (FR_PageView pv))

/**
 * @brief FRPageViewGetCurrentMatrix
 * @details Gets the current matrix of page view.
 * @param[in]  pv The page view whose matrix is obtained.
 * @return   Current matrix of <param>pv</param>.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FRPageViewGetCurrentMatrix, (FR_PageView pv))

/**
 * @brief FRPageViewDevicePointToPage
 * @details Transforms a point's coordinate from device space to user space.
 * @param[in]  pv The page view for which the point's coordinates are transformed from device space to user space.
 * @param[in]  window_x The x-coordinate of the point to transform, specified in device space coordinates.
 * @param[in]  window_y The y-coordinate of the point to transform, specified in device space coordinates.
 * @param[out]  outPt (Filled by this method) A pointer to a point whose user space coordinates corresponding
	* <param>window_x</param> and <param>window_y</param>.
 * @return   void
 * @note 
 * @see FRPageViewDeviceRectToPage
 * @see FRPageViewPointToDevice
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewDevicePointToPage, (FR_PageView pv,  FS_INT32 window_x,  FS_INT32 window_y,  FS_FloatPoint* outPt))

/**
 * @brief FRPageViewDeviceRectToPage
 * @details Transforms a rectangle from device space to user space.
 * @param[in]  pv The page view for which the rectangle is transformed from device space to user space.
 * @param[in]  rect A pointer to device space rectangle whose coordinates are transformed to user space.
 * @param[out]  outRect (Filled by this method) A pointer to a user space rectangle corresponding <param>rect</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see FRPageViewPointToDevice
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewDeviceRectToPage, (FR_PageView pv,  const FS_Rect* rect,  FS_FloatRect* outRect))

/**
 * @brief FRPageViewPointToDevice
 * @details Transforms a point from user space to device space.
 * @param[in]  pv The page view for which the point's coordinates are transformed from user space to device space.
 * @param[in]  pt A pointer to a <a>FS_FloatPoint</a> whose coordinates, specified in device space coordinates, are transformed.
 * @param[out]  out_window_x (Filled by the method) The x-coordinate of the device space point corresponding to <param>pt</param>.
 * @param[out]  out_window_y (Filled by the method) The y-coordinate of the device space point corresponding to <param>pt</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see DeviceRectToPage
 * @see FRPageViewRectToDevice
 */
INTERFACE(void, FRPageViewPointToDevice, (FR_PageView pv,  const FS_FloatPoint* pt,  FS_INT32* out_window_x,  FS_INT32* out_window_y))

/**
 * @brief FRPageViewRectToDevice
 * @details Transforms a rectangle from user space to device space.
 * @param[in]  pv The page view for which the rectangle is transformed from user space to device space.
 * @param[in]  rect A pointer to user space rectangle whose coordinates are transformed to device space.
 * @param[out]  outRect (Filled by this method) A pointer to a device space rectangle corresponding <param>rect</param>.
 * @return   void
 * @note 
 * @see DevicePointToPage
 * @see DeviceRectToPage
 * @see FRPageViewPointToDevice
 */
INTERFACE(void, FRPageViewRectToDevice, (FR_PageView pv,  const FS_FloatRect* rect,  FS_Rect* outRect))

/**
 * @brief FRPageViewIsVisible
 * @details Gets a flag that indicate whether a page view is visible.
 * @param[in]  pv The page view to adjust whether it is visible.
 * @return   <a>TRUE</a> if <param>pv</param> is visible, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FRPageViewIsVisible, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageRect
 * @details Gets the current bounding-box of specified page view.
 * @param[in]  pv The page view whose bounding-box to obtained.
 * @return   The current bounding-box for <param>pv</param>.
 * @note The page bounding-box specified in device space coordinates.
 * @see FRPageViewGetPageVisibleRect
 */
INTERFACE(FS_Rect, FRPageViewGetPageRect, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageVisibleRect
 * @details Gets the current visible region of specified page view.
 * @param[in]  pv The page view whose visible rectangle to obtained.
 * @return   A rectangle specified in user space, instead of the current visible region of <param>pv</param>.
 * @note If the specified page view is invisible, the returned rectangle is empty.
 * @see FRPageViewGetPageRect
 */
INTERFACE(FS_FloatRect, FRPageViewGetPageVisibleRect, (FR_PageView pv))

/**
 * @brief FRPageViewDidContentChanged
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
	* The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged, (FR_PageView pv,  FS_BOOL bReLoadPage))

/**
 * @brief FRPageViewGetHWnd
 * @details Gets the HWND handler in which a page view is displaying.
 * @param[in]  pv The page view which HWND will be obtained.
 * @return   The HWND handler of <param>pv</param>.
 * @note 
 * @see 
 */
INTERFACE(HWND, FRPageViewGetHWnd, (FR_PageView pv))

/**
 * @brief FRPageViewDidTextObjectChanged
 * @details The text objects of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose text objects of <a>FPD_Page</a> has been modified.
 * @return   void
 * @note 
 * @see 
 */
INTERFACE(void, FRPageViewDidTextObjectChanged, (FR_PageView pv))

/**
 * @brief FRPageViewGetAnnotByIndex
 * @details Gets the annotation by index.
 * @param[in]  pv The input page view object.
 * @param[in]  index The specified index of the annotations.
 * @return   The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewGetAnnotByIndex, (FR_PageView pv,  FS_INT32 index))

/**
 * @brief FRPageViewGetPageState
 * @details Gets the page state. Sets <param>outDestArray</param> NULL to get the count of the destination array first.
 * @param[in]  pv The input page view object.
 * @param[out]  outFitType It receives the fit type.
 * @param[out]  outDestArray It receives the destination array.
 * @param[out]  outDestArrayCount It receives the count of the destination array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRPageViewGetPageState, (FR_PageView pv,  FS_INT32* outFitType,  FS_FLOAT* outDestArray,  FS_INT32* outDestArrayCount))

/**
 * @brief FRPageViewDeleteAnnot
 * @details Deletes the specified annotation.
 * @param[in]  pv The input page view object.
 * @param[in]  frAnnot The input annotation to be deleted.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRPageViewDeleteAnnot, (FR_PageView pv,  FR_Annot frAnnot))

/**
 * @brief FRPageViewGetFocusAnnot
 * @details Gets the focus annotation.
 * @param[in]  pv The input page view object.
 * @return   The focus annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewGetFocusAnnot, (FR_PageView pv))

/**
 * @brief FRPageViewGetPageScale
 * @details Gets the page scale.
 * @param[in]  pv The input page view object.
 * @return   The page scale.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see 
 */
INTERFACE(FS_FLOAT, FRPageViewGetPageScale, (FR_PageView pv))

/**
 * @brief FRPageViewGetAnnotAtPoint
 * @details Gets the annotation at the specified point.
 * @param[in]  pv The input page view object.
 * @param[in]  point The input point where to get the annotation.
 * @param[in]  pszSubType Specifies the sub type of the annotation you want to get. You can set it NULL as default.
 * @return   The specified annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewGetAnnotAtPoint, (FR_PageView pv,  FS_DevicePoint point,  FS_LPCSTR pszSubType))

/**
 * @brief FRPageViewUpdateAllViews
 * @details Updates all the page views where the annotation is shown.
 * @param[in]  pv The input page view object.
 * @param[in]  frAnnot The input annotation you want to update.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(void, FRPageViewUpdateAllViews, (FR_PageView pv,  FR_Annot frAnnot))

/**
 * @brief FRPageViewAddAnnot
 * @details Adds the annotation to the page.
 * @param[in]  pv The input page view object.
 * @param[in]  annotDict The input annotation dictionary you want to add.
 * @param[in]  nIndex The index where you want to add the annotation. Sets it -1 as default.
 * @return   The UI layer annotation object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FR_Annot, FRPageViewAddAnnot, (FR_PageView pv,  FPD_Object annotDict,  FS_INT32 nIndex))

/**
 * @brief FRPageViewGetRenderOptions
 * @details Gets the rendering options.
 * @param[in]  pv The input page view object.
 * @return   The rendering options.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 */
INTERFACE(FPD_RenderOptions, FRPageViewGetRenderOptions, (FR_PageView pv))

/**
 * @brief FRPageViewDidContentChanged2
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
	* The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @param[in]  bResizePageNotify Checks whether to broadcast the notification of page resizing.
 * @param[in]  pChangeData It indicates what data is changed.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged2, (FR_PageView pv,  FS_BOOL bReLoadPage,  FS_BOOL bResizePageNotify,  void* pChangeData))

/**
 * @brief FRPageViewDidContentChanged3
 * @details The content of <a>FPD_Page</a> of the <param>pv</param> has been modified. Foxit Reader will broadcast some notifications to plug-ins.
 * @param[in]  pv The page view whose <a>FPD_Page</a> has been modified.
 * @param[in]  bReLoadPage A flag to force reader to reload the page data. If <a>TRUE</a>, Foxit Reader will reload the page data and reparse the page.
	* The flag must be <a>TRUE</a> and call <a>FPDPageGenerateContent</a>() befor calling this method if the <a>FPD_Page</a> whose content is modified is not using <a>FRPageViewGetPDPage</a>() to obtain.
 * @param[in]  bResizePageNotify Checks whether to broadcast the notification of page resizing.
 * @param[in]  objArray It indicates what data is changed. The value type in the array is <a>FR_ChangedContent</a>.
 * @param[in]  changeType The content change type.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see 
 */
INTERFACE(void, FRPageViewDidContentChanged3, (FR_PageView pv,  FS_BOOL bReLoadPage,  FS_BOOL bResizePageNotify,  FS_PtrArray objArray,  FR_ContentChangeType changeType))

NumOfSelector(FRPageView)
ENDENUM

//*****************************
/* TextSelectTool HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRTextSelectToolCreate
 * @details Creates the text select tool which is used to process the operation of text selecting in the doc view.
 * @param[in]  doc The input doc where the operation of text selecting occurs.
 * @return   The text select tool.
 * @note 
 * @see 
 */
INTERFACE(FR_TextSelectTool, FRTextSelectToolCreate, (FR_Document doc))

/**
 * @brief FRTextSelectToolDestroyTextSelectTool
 * @details Destroys the text select tool created from <a>FRTextSelectToolCreate</a>.
 * @param[in]  textSelectTool The input text select tool.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDestroyTextSelectTool, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolGetSelectedText
 * @details Gets the selected text.
 * @param[in]  textSelectTool The input text select tool.
 * @param[out]  outText It receives the text selected.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolGetSelectedText, (FR_TextSelectTool textSelectTool,  FS_WideString* outText))

/**
 * @brief FRTextSelectToolDrawSelection
 * @details Draws the area where the text is selected in black color.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  docView The input doc view where do the operation of text selecting.
 * @param[in]  winPort The platform-depend things.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDrawSelection, (FR_TextSelectTool textSelectTool,  FR_DocView docView,  FR_WinPort winPort))

/**
 * @brief FRTextSelectToolClearSelection
 * @details Clears the area where the text is selected.
 * @param[in]  textSelectTool The input text select tool.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolClearSelection, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolDoLButtonUp
 * @details Does the mouse left button up operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse left button up operation.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDoLButtonUp, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoLButtonDown
 * @details Does the mouse left button down operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDoLButtonDown, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoLButtonDblClk
 * @details Does the mouse left button double-click operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDoLButtonDblClk, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoRButtonUp
 * @details Does the mouse right button up operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDoRButtonUp, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoMouseMove
 * @details Does the mouse move operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   
 * @note 
 * @see 
 */
INTERFACE(void, FRTextSelectToolDoMouseMove, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolDoMouseWheel
 * @details Does the mouse wheel operation.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageView The input page view where do the operation of text selecting.
 * @param[in]  point The input point where do the mouse operation.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolDoMouseWheel, (FR_TextSelectTool textSelectTool,  FR_PageView pageView,  FS_DevicePoint point))

/**
 * @brief FRTextSelectToolIsSelecting
 * @details Checks whether the mouse is selecting text.
 * @param[in]  textSelectTool The input text select tool.
 * @return   <a>TRUE</a> means the mouse is selecting text.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolIsSelecting, (FR_TextSelectTool textSelectTool))

/**
 * @brief FRTextSelectToolEnumTextObjectRect
 * @details Enumerates the text object rectangles. Invokes this interface first to get the count of the rectangles by setting 
	* <param>outRectArray</param> as <a>NULL</a>. Then allocates the buffer for the rectangle array.
 * @param[in]  textSelectTool The input text select tool.
 * @param[in]  pageIndex The input page index.
 * @param[out]  outRectArray It receives the rectangle array of text object.
 * @param[out]  nCount It receives the count of the rectangle array.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see 
 */
INTERFACE(FS_BOOL, FRTextSelectToolEnumTextObjectRect, (FR_TextSelectTool textSelectTool,  FS_INT32 pageIndex,  FS_FloatRect** outRectArray,  FS_INT32* nCount))

NumOfSelector(FRTextSelectTool)
ENDENUM

//----------_V2----------
//----------_V3----------
//*****************************
/* ThumbnailView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRThumbnailViewCountPage
 * @details Gets the count of page displayed in the thumbnail view.
 * @param[in]  tv The input thumbnail view.
 * @return   The count of page displayed in the thumbnail view.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_INT32, FRThumbnailViewCountPage, (FR_ThumbnailView tv))

/**
 * @brief FRThumbnailViewCountVisiblePage
 * @details Gets the count of visible page displayed in the thumbnail view.
 * @param[in]  tv The input thumbnail view.
 * @return   The count of visible page displayed in the thumbnail view.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_INT32, FRThumbnailViewCountVisiblePage, (FR_ThumbnailView tv))

/**
 * @brief FRThumbnailViewGetPageRect
 * @details Gets the rectangle of specified visible page.
 * @param[in]  tv The input thumbnail view.
 * @param[in]  nPage The index of visible pages.
 * @return   The rectangle of specified visible page.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FS_Rect, FRThumbnailViewGetPageRect, (FR_ThumbnailView tv,  FS_INT32 nPage))

/**
 * @brief FRThumbnailViewGetVisiblePageRange
 * @details Gets the index of visible page range.
 * @param[in]  tv The input thumbnail view.
 * @param[out]  nFrom It receives the starting index of visible pages.
 * @param[out]  nTo It receives the ending index of visible pages.
 * @return   void
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(void, FRThumbnailViewGetVisiblePageRange, (FR_ThumbnailView tv,  FS_INT32* nFrom,  FS_INT32* nTo))

/**
 * @brief FRThumbnailViewGetPDPage
 * @details Gets a <a>FPD_Page</a> object.
 * @param[in]  tv The input thumbnail view.
 * @param[in]  nPage The index of page.
 * @return   The <a>FPD_Page</a> object.
 * @note 
 * @see FRDocViewGetThumbnailView
 */
INTERFACE(FPD_Page, FRThumbnailViewGetPDPage, (FR_ThumbnailView tv,  FS_INT32 nPage))

NumOfSelector(FRThumbnailView)
ENDENUM

//----------_V4----------
//----------_V5----------
//*****************************
/* Annot HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAnnotGetPDFAnnot
 * @details Gets the data layer PDF annotation.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @return   The data layer PDF annotation.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FPD_Annot, FRAnnotGetPDFAnnot, (FR_Annot frAnnot))

/**
 * @brief FRAnnotGetType
 * @details Gets the type of the annotation.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outType It receives the type of the annotation.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAnnotGetType, (FR_Annot frAnnot,  FS_ByteString* outType))

/**
 * @brief FRAnnotGetSubType
 * @details Gets the sub type of the annotation.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[out]  outSubType It receives the sub type of the annotation.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAnnotGetSubType, (FR_Annot frAnnot,  FS_ByteString* outSubType))

/**
 * @brief FRAnnotSetVisible
 * @details Sets the annotation to be visible or not.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  bShow It indicates whether the annotation is visible.
 * @return   void
 * @note You must call this interface in <a>FRPageViewOnWillParsePage</a> callback.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(void, FRAnnotSetVisible, (FR_Annot frAnnot,  FS_BOOL bShow))

/**
 * @brief FRAnnotGetPageVew
 * @details Gets the associated page view.
 * @param[in]  frAnnot The input UI layer annotation object.
 * @param[in]  nIndex The specified page view index.
 * @return   The associated page view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FR_PageView, FRAnnotGetPageVew, (FR_Annot frAnnot,  FS_INT32 nIndex))

NumOfSelector(FRAnnot)
ENDENUM

//*****************************
/* ResourcePropertyBox HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRResourcePropertyBoxGet
 * @details Gets the property box. The Foxit Reader creates the property box so that many types of objects can reuse the same property box 
	* to edit the properties. For example, the objects can be annotations, pages and so on.
 * @return   The property box. It is used to edit the properties of objects, such as the annotations, the pages and so on.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_ResourcePropertyBox, FRResourcePropertyBoxGet, ())

/**
 * @brief FRResourcePropertyBoxRegisterPropertyPage
 * @details Registers the callbacks used to add the new property page to the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input callbacks used to add the new property page to the property box.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxRegisterPropertyPage, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPageCallbacks pPage))

/**
 * @brief FRResourcePropertyBoxRegisterSourceType
 * @details Registers the source type.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @param[in]  bLockButton Indicates whether to show the check box used to lock the source.
 * @param[in]  pSourceFunc The input callbacks used to deal with the source of the property box.
 * @param[in]  pNotifyFunc The input callbacks that will be called when events occur.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxRegisterSourceType, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource,  FS_BOOL bLockButton,  FR_ResourcePropertySourceCallbacks pSourceFunc,  FR_ResourcePropertyNotifyCallbacks pNotifyFunc))

/**
 * @brief FRResourcePropertyBoxGetSourceType
 * @details Gets the source type of the property box.
 * @param[in]  rpBox The input property box object.
 * @return   The source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_INT32, FRResourcePropertyBoxGetSourceType, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetSourceFunc
 * @details Gets the specified property source.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   The property source.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_ResourcePropertySource, FRResourcePropertyBoxGetSourceFunc, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxUpdatePropertyBox
 * @details Updates the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxUpdatePropertyBox, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxOpenPropertyBox
 * @details Opens the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The specified source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxOpenPropertyBox, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource))

/**
 * @brief FRResourcePropertyBoxClosePropertyBox
 * @details Closes the property box.
 * @param[in]  rpBox The input property box object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxClosePropertyBox, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxIsPropertyBoxVisible
 * @details Checks whether the property box is visible or not.
 * @param[in]  rpBox The input property box object.
 * @return   <a>TRUE</a> if the property box is visible, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRResourcePropertyBoxIsPropertyBoxVisible, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetWnd
 * @details Gets the window handle of the property box.
 * @param[in]  rpBox The input property box object.
 * @return   The window handle of the property box.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(HWND, FRResourcePropertyBoxGetWnd, (FR_ResourcePropertyBox rpBox))

/**
 * @brief FRResourcePropertyBoxGetPropertyPage
 * @details Gets the property page by name.
 * @param[in]  rpBox The input property box object.
 * @param[in]  lpwsName The specified name of the property page.
 * @return   The property page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FR_ResourcePropertyPage, FRResourcePropertyBoxGetPropertyPage, (FR_ResourcePropertyBox rpBox,  FS_LPCWSTR lpwsName))

/**
 * @brief FRResourcePropertyBoxSetCurrentPropertyPage
 * @details Sets the current property page.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input property page.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxSetCurrentPropertyPage, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPage pPage))

/**
 * @brief FRResourcePropertyBoxRegisterPropertyPage2
 * @details Registers the callbacks used to add the new property page to the property box.
 * @param[in]  rpBox The input property box object.
 * @param[in]  pPage The input callbacks used to add the new property page to the property box.
 * @return   The page object that needs to be destroyed by <a>FRResourcePropertyBoxDestroyPage</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void*, FRResourcePropertyBoxRegisterPropertyPage2, (FR_ResourcePropertyBox rpBox,  FR_ResourcePropertyPageCallbacks pPage))

/**
 * @brief FRResourcePropertyBoxDestroyPage
 * @details Destroys the page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
 * @param[in]  pPage The page object returned by <a>FRResourcePropertyBoxRegisterPropertyPage2</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxDestroyPage, (void* pPage))

/**
 * @brief FRResourcePropertyBoxRegisterSourceType2
 * @details Registers the source type.
 * @param[in]  rpBox The input property box object.
 * @param[in]  nSource The input source type. See the definitions of <Italic>FRSOURCETYPE</Italic>.
 * @param[in]  bLockButton Indicates whether to show the check box used to lock the source.
 * @param[in]  pSourceFunc The input callbacks used to deal with the source of the property box.
 * @param[in]  pNotifyFunc The input callbacks that will be called when events occur.
 * @return   The source object that needs to be destroyed by <a>FRResourcePropertyBoxDestroySource</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void*, FRResourcePropertyBoxRegisterSourceType2, (FR_ResourcePropertyBox rpBox,  FS_INT32 nSource,  FS_BOOL bLockButton,  FR_ResourcePropertySourceCallbacks pSourceFunc,  FR_ResourcePropertyNotifyCallbacks pNotifyFunc))

/**
 * @brief FRResourcePropertyBoxDestroySource
 * @details Destroys the source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
 * @param[in]  pPage The source object returned by <a>FRResourcePropertyBoxRegisterSourceType2</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRResourcePropertyBoxDestroySource, (void* pSource))

NumOfSelector(FRResourcePropertyBox)
ENDENUM

//----------_V6----------
//*****************************
/* ScrollBarThumbnailView HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRScrollBarThumbnailViewGetCurPageIndex
 * @details Gets the index of page displayed in the scroll bar thumbnail view.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The index of page displayed in the scroll bar thumbnail view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_INT32, FRScrollBarThumbnailViewGetCurPageIndex, (FR_ScrollBarThumbnailView tv))

/**
 * @brief FRScrollBarThumbnailViewGetPageRect
 * @details Gets the rectangle of specified visible page.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The rectangle of specified visible page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_Rect, FRScrollBarThumbnailViewGetPageRect, (FR_ScrollBarThumbnailView tv))

/**
 * @brief FRScrollBarThumbnailViewGetPDPage
 * @details Gets a <a>FPD_Page</a> object.
 * @param[in]  tv The input scrollbar thumbnail view.
 * @return   The <a>FPD_Page</a> object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FPD_Page, FRScrollBarThumbnailViewGetPDPage, (FR_ScrollBarThumbnailView tv))

NumOfSelector(FRScrollBarThumbnailView)
ENDENUM

//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
