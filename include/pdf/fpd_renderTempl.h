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
/* RenderOptions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderOptionsNew
 * @details Creates a new empty page rendering options object.
 * @param[in]  void 
 * @return   A new empty page rendering options object.
 * @note 
 */
INTERFACE(FPD_RenderOptions, FPDRenderOptionsNew, (void))

/**
 * @brief FPDRenderOptionsDestroy
 * @details Destroys the page rendering options object.
 * @param[in]  opts The input page rendering options object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsDestroy, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsGetColorMode
 * @details Gets display mode code.
 * @param[in]  opts The input page rendering options object.
 * @return   The display mode code.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderOptionsGetColorMode, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetColorMode
 * @details Sets display mode code.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  nClrMode The new mode code.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetColorMode, (FPD_RenderOptions opts,  FS_INT32 nClrMode))

/**
 * @brief FPDRenderOptionsGetBackColor
 * @details Gets the background color for gray mode (default: white).
 * @param[in]  opts The input page rendering options object.
 * @return   The background color for gray mode (default: white).
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenderOptionsGetBackColor, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetBackColor
 * @details Sets the background color for gray mode (default: white).
 * @param[in]  opts The input page rendering options object.
 * @param[in]  clr Input the background color for gray mode (default: white).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetBackColor, (FPD_RenderOptions opts,  FS_COLORREF clr))

/**
 * @brief FPDRenderOptionsGetForeColor
 * @details Gets the foreground color for gray mode (default: black).
 * @param[in]  opts The input page rendering options object.
 * @return   The foreground color for gray mode (default: black).
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenderOptionsGetForeColor, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetForeColor
 * @details Sets the foreground color for gray mode (default: black).
 * @param[in]  opts The input page rendering options object.
 * @param[in]  clr Input the foreground color for gray mode (default: black).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetForeColor, (FPD_RenderOptions opts,  FS_COLORREF clr))

/**
 * @brief FPDRenderOptionsGetRenderFlag
 * @details Gets render flags.
 * @param[in]  opts The input page rendering options object.
 * @return   The  render flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDRenderOptionsGetRenderFlag, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetRenderFlag
 * @details Sets  render flags.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  dwFlag Input render flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetRenderFlag, (FPD_RenderOptions opts,  FS_DWORD dwFlag))

/**
 * @brief FPDRenderOptionsGetAddtionalFlag
 * @details Gets additional flags depending on the device.
 * @param[in]  opts The input page rendering options object.
 * @return   The additional flags depending on the device.
 * @note 
 */
INTERFACE(FS_DWORD, FPDRenderOptionsGetAddtionalFlag, (FPD_RenderOptions opts))

/**
 * @brief FPDRenderOptionsSetAddtionalFlag
 * @details Sets additional flags depending on the device.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  dwFlag Input additional flags depending on the device.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetAddtionalFlag, (FPD_RenderOptions opts,  FS_DWORD dwFlag))

/**
 * @brief FPDRenderOptionsSetOCCHandler
 * @details Sets optional content context handler.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  OCCHandler Input optional content context handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsSetOCCHandler, (FPD_RenderOptions opts,  FPD_OCContextHandler OCCHandler))

/**
 * @brief FPDRenderOptionsTranslateColor
 * @details Translates a color.
 * @param[in]  opts The input page rendering options object.
 * @param[in]  argb The input color.
 * @return   The translated color.
 * @note 
 */
INTERFACE(FS_ARGB, FPDRenderOptionsTranslateColor, (FPD_RenderOptions opts,  FS_ARGB argb))

/**
 * @brief FPDRenderOptionsCreateOCContextHandler
 * @details Creates optional content context handler.
 * @param[in]  OCContext The input page rendering options object.
 * @return   FPD_OCContextHandler		Input optional content context handler.
 * @note 
 */
INTERFACE(FPD_OCContextHandler, FPDRenderOptionsCreateOCContextHandler, (FPD_OCContextCallBack OCContext))

/**
 * @brief FPDRenderOptionsDeleteOCContextHandler
 * @details Deletes optional content context handler.
 * @param[in]  OCCHandler Input optional content context handler to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderOptionsDeleteOCContextHandler, (FPD_OCContextHandler OCCHandler))

NumOfSelector(FPDRenderOptions)
ENDENUM

//*****************************
/* RenderContext HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderContextNew
 * @details Creates a new PDF rendering context object.
 * @param[in]  page The input page.
 * @param[in]  bFirstLayer Whether it's the first layer.
 * @return   A empty PDF rendering context object.
 * @note 
 */
INTERFACE(FPD_RenderContext, FPDRenderContextNew, (FPD_Page page,  FS_BOOL bFirstLayer))

/**
 * @brief FPDRenderContextNew2
 * @details Creates a new PDF rendering context object.
 * @param[in]  doc The PDF document.
 * @param[in]  pageCache The page render cache.
 * @param[in]  pageResources The Resources dictionary.
 * @param[in]  bFirstLayer Whether it's the first layer.
 * @return   A new PDF rendering context object.
 * @note 
 */
INTERFACE(FPD_RenderContext, FPDRenderContextNew2, (FPD_Document doc,  FPD_PageRenderCache pageCache,  FPD_Object pageResources,  FS_BOOL bFirstLayer))

/**
 * @brief FPDRenderContextDestroy
 * @details Destroys the PDF rendering context object.
 * @param[in]  context The input PDF rendering context object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDestroy, (FPD_RenderContext context))

/**
 * @brief FPDRenderContextDrawStream
 * @details Draws a page description stream.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  pStreamDataBuf The page description stream buffer.
 * @param[in]  stream_size The size in bytes of the page description stream. -1 for <a>NULL</a> terminated byte string.
 * @param[in]  displayMatrix The matrix from stream coords to device coords. Can be <a>NULL</a> if no transformation needed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawStream, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  const void* pStreamDataBuf,  FS_DWORD stream_size,  FS_AffineMatrix displayMatrix))

/**
 * @brief FPDRenderContextAppendPage
 * @details Append page to the current layer.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  objs The input page.
 * @param[in]  object2Device The matrix from object coords to device coords.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextAppendPage, (FPD_RenderContext context,  FPD_Page objs,  FS_AffineMatrix object2Device))

/**
 * @brief FPDRenderContextAppendForm
 * @details Append Form to the current layer.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  objs The input Form
 * @param[in]  object2Device The matrix from object coords to device coords
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextAppendForm, (FPD_RenderContext context,  FPD_Form objs,  FS_AffineMatrix object2Device))

/**
 * @brief FPDRenderContextSetBackground
 * @details Sets custom background drawing.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  BackgroundDrawHandler The background drawing handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextSetBackground, (FPD_RenderContext context,  FPD_BackgroundDrawHandler BackgroundDrawHandler))

/**
 * @brief FPDRenderContextCreateBackgroundDrawHandler
 * @details Creates the background drawing handler.
 * @param[in]  backgroundDraw The input background drawing handler structure.
 * @return   The background drawing handler.
 * @note 
 */
INTERFACE(FPD_BackgroundDrawHandler, FPDRenderContextCreateBackgroundDrawHandler, (FPD_BackgroundDraw backgroundDraw))

/**
 * @brief FPDRenderContextDeleteBackgroundDrawHandler
 * @details Deletes the background drawing handler.
 * @param[in]  backgroundDrawHandler The input background drawing handler structure.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDeleteBackgroundDrawHandler, (FPD_BackgroundDrawHandler backgroundDrawHandler))

/**
 * @brief FPDRenderContextRender
 * @details Do the real rendering. Optionally, rendering matrix can be modified by the last matrix.
 * @param[in]  context The input PDF rendering context object.
 * @param[in]  device The output device.
 * @param[in]  options The render options.
 * @param[in]  pFinalMatrix The final matrix to transform the result, Default value is <a>NULL</a>.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextRender, (FPD_RenderContext context,  FPD_RenderDevice device,  const FPD_RenderOptions options,  FS_AffineMatrix* pFinalMatrix))

/**
 * @brief FPDRenderContextDrawPage
 * @details Draws a list of page objects.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  objs The input page.
 * @param[in]  pObject2Device The matrix from object coords to device coords, can be NULL.
 * @param[in]  options The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawPage, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  FPD_Page objs,  FS_AffineMatrix* pObject2Device,  const FPD_RenderOptions options))

/**
 * @brief FPDRenderContextDrawForm
 * @details Draws a list of page objects.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @param[in]  objs The input Form.
 * @param[in]  pObject2Device The matrix from object coords to device coords, can be NULL.
 * @param[in]  options The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextDrawForm, (FPD_RenderContext context,  FPD_RenderDevice* outDevice,  FPD_Form objs,  FS_AffineMatrix* pObject2Device,  const FPD_RenderOptions options))

/**
 * @brief FPDRenderContextQuickDraw
 * @details Draws a rough preview (quick draw).
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outDevice The output device.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextQuickDraw, (FPD_RenderContext context,  FPD_RenderDevice* outDevice))

/**
 * @brief FPDRenderContextGetBackground
 * @details Gets background of a page object within the rendering context.
 * @param[in]  context The input PDF rendering context object.
 * @param[out]  outBitmapBuffer It receives the background bitmap.
 * @param[in]  obj The input page object.
 * @param[in]  options The render options.
 * @param[in]  pFinalMatrix The matrix from object coords to device coords.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderContextGetBackground, (FPD_RenderContext context,  FS_DIBitmap* outBitmapBuffer,  const FPD_PageObject obj,  const FPD_RenderOptions options,  FS_AffineMatrix* pFinalMatrix))

/**
 * @brief FPDRenderContextGetPageCache
 * @details Gets the page render cache.
 * @param[in]  context The input PDF rendering context object.
 * @return   The page render cache.
 * @note 
 */
INTERFACE(FPD_PageRenderCache, FPDRenderContextGetPageCache, (FPD_RenderContext context))

NumOfSelector(FPDRenderContext)
ENDENUM

//*****************************
/* ProgressiveRender HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDProgressiveRenderNew
 * @details Creates a new empty PDF progressive renderer object.
 * @param[in]  void 
 * @return   A new empty PDF progressive renderer object.
 * @note 
 */
INTERFACE(FPD_ProgressiveRender, FPDProgressiveRenderNew, (void))

/**
 * @brief FPDProgressiveRenderDestroy
 * @details Destroys the PDF progressive renderer object.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderDestroy, (FPD_ProgressiveRender render))

/**
 * @brief FPDProgressiveRenderStart
 * @details Starts rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @param[in]  context The render context.
 * @param[in]  device The output device.
 * @param[in]  options The render options.
 * @param[in]  pauseHandler The pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderStart, (FPD_ProgressiveRender render,  FPD_RenderContext context,  FPD_RenderDevice* device,  const FPD_RenderOptions options,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDProgressiveRenderContinue
 * @details Continue rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @param[in]  pauseHandler The pause handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderContinue, (FPD_ProgressiveRender render,  FS_PauseHandler pauseHandler))

/**
 * @brief FPDProgressiveRenderEstimateProgress
 * @details Estimates percentage of progress.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   An estimated percentage of progress.
 * @note 
 */
INTERFACE(FS_INT32, FPDProgressiveRenderEstimateProgress, (FPD_ProgressiveRender render))

/**
 * @brief FPDProgressiveRenderClear
 * @details Gets ready for next rendering.
 * @param[in]  render The input PDF progressive renderer object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDProgressiveRenderClear, (FPD_ProgressiveRender render))

NumOfSelector(FPDProgressiveRender)
ENDENUM

//*****************************
/* RenderDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenderDeviceNew
 * @details Creates a new empty render device object.
 * @param[in]  void 
 * @return   A new empty render device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDRenderDeviceNew, (void))

/**
 * @brief FPDRenderDeviceDestroy
 * @details Destroys the render device object.
 * @param[in]  dc The input render device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceDestroy, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceStartRendering
 * @details Starts rendering.
 * @param[in]  dc The input render device object.
 * @return   Non-zero means success, otherwise failure.
 * @note Called only once for each rendering job.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStartRendering, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceEndRendering
 * @details End rendering.
 * @param[in]  dc The input render device object.
 * @return   Non-zero means success, otherwise failure.
 * @note Called only once for each rendering job.
 */
INTERFACE(void, FPDRenderDeviceEndRendering, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceSaveState
 * @details Saves all graphic states.
 * @param[in]  dc The input render device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceSaveState, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceRestoreState
 * @details Restores all graphic states.
 * @param[in]  dc The input render device object.
 * @param[in]  bKeepSaved Whether to keep the restored states saved in buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceRestoreState, (FPD_RenderDevice dc,  FS_BOOL bKeepSaved))

/**
 * @brief FPDRenderDeviceGetWidth
 * @details Gets the device width.
 * @param[in]  dc The input render device object.
 * @return   The device width.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetWidth, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetHeight
 * @details Gets the device height.
 * @param[in]  dc The input render device object.
 * @return   The device height.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetHeight, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetBPP
 * @details Gets the bits per pixel.
 * @param[in]  dc The input render device object.
 * @return   The bits per pixel.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceGetBPP, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetRenderCaps
 * @details Gets the render capabilities.
 * @param[in]  dc The input render device object.
 * @return   The render capabilities.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetRenderCaps, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceGetDeviceCapsXY
 * @details Gets the render capabilities.
 * @param[in]  dc The input render device object.
 * @param[in]  id The input device capability ID
 * @return   The render capabilities.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetDeviceCapsXY, (FPD_RenderDevice dc,  FS_INT32 id))

/**
 * @brief FPDRenderDeviceGetBitmap
 * @details Gets the bitmap of the device.
 * @param[in]  dc The input render device object.
 * @return   The bitmap of the device.
 * @note 
 */
INTERFACE(FS_DIBitmap, FPDRenderDeviceGetBitmap, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceSetBitmap
 * @details Sets the bitmap to the device.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input bitmap
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceSetBitmap, (FPD_RenderDevice dc,  FS_DIBitmap bitmap))

/**
 * @brief FPDRenderDeviceSetPixel
 * @details Sets or composite a pixel.
 * @param[in]  dc The input render device object.
 * @param[in]  x The x-coordinate of the pixel.
 * @param[in]  y The y-coordinate of the pixel.
 * @param[in]  argb The color of the pixel.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetPixel, (FPD_RenderDevice dc,  FS_INT32 x,  FS_INT32 y,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceSetClip_Rect
 * @details Sets a clipping rectangle.
 * @param[in]  dc The input render device object.
 * @param[in]  rect The input clipping rectangle.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetClip_Rect, (FPD_RenderDevice dc,  const FS_Rect rect))

/**
 * @brief FPDRenderDeviceCreateCompatibleBitmap
 * @details Creates a compatible bitmap.
 * @param[in]  dc The input render device object.
 * @param[in,out]  inoutDIB It receives the created bitmap data.
 * @param[in,out]  width The bitmap width.
 * @param[in,out]  height The bitmap height.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(void, FPDRenderDeviceCreateCompatibleBitmap, (FPD_RenderDevice dc,  FS_DIBitmap* inoutDIB,  FS_INT32 width,  FS_INT32 height))

/**
 * @brief FPDRenderDeviceFillRect
 * @details Fills a rectangle.
 * @param[in]  dc The input render device object.
 * @param[in,out]  pRect The input rectangle
 * @param[in,out]  fill_argb The color to fill.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceFillRect, (FPD_RenderDevice dc,  const FS_Rect* pRect,  FS_ARGB fill_argb))

/**
 * @brief FPDRenderDeviceDrawCosmeticLine
 * @details Draws a single pixel (device dependent) line.
 * @param[in]  dc The input render device object.
 * @param[in]  x1 The x-coordinate of the start point.
 * @param[in]  y1 The y-coordinate of the start point.
 * @param[in]  x2 The x-coordinate of the end point.
 * @param[in]  y2 The y-coordinate of the end point.
 * @param[in]  argb The line color.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawCosmeticLine, (FPD_RenderDevice dc,  FS_FLOAT x1,  FS_FLOAT y1,  FS_FLOAT x2,  FS_FLOAT y2,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceGetDIBits
 * @details Loads device buffer into a DIB.
 * @param[in]  dc The input render device object.
 * @param[out]  bitmap It receives the loaded device buffer.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceGetDIBits, (FPD_RenderDevice dc,  FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top))

/**
 * @brief FPDRenderDeviceSetDIBits
 * @details Outputs a colored DIB, pixel-to-pixel.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input colored DIB.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  blend_type Blend mode.
 * @return   Non-zero means success, otherwise failure.
 * @note When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
	* When non-normal blending type is used, device capability <a>FSRC_BLEND_MODE</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetDIBits, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 blend_type))

/**
 * @brief FPDRenderDeviceStretchDIBits
 * @details Stretches a colored DIB onto the device.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The input colored DIB.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  dest_width The destinate width in the device.
 * @param[in]  dest_height The destinate height in the device.
 * @param[in]  flags The stretching flags.
 * @return   Non-zero means success, otherwise failure.
 * @note When ARGB bitmap is specified, device capability <a>FSRC_ALPHA_IMAGE</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStretchDIBits, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 dest_width,  FS_INT32 dest_height,  FS_DWORD flags))

/**
 * @brief FPDRenderDeviceSetBitMask
 * @details Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The inpput mask.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  argb The color to be masked.
 * @return   Non-zero means success, otherwise failure.
 * @note If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	*        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MAS>K</a or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetBitMask, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceStretchBitMask
 * @details Outputs masked bitmap. The bitmap can be a monochrome bitmask, or a 8-bit alpha mask.
 * @param[in]  dc The input render device object.
 * @param[in]  bitmap The inpput mask.
 * @param[in]  left The x-coordinate in the device.
 * @param[in]  top The y-coordinate in the device.
 * @param[in]  dest_width The destinate width in the device.
 * @param[in]  dest_height The destinate height in the device.
 * @param[in]  argb The color to be masked.
 * @param[in]  flags The stretching flags.
 * @return   Non-zero means success, otherwise failure.
 * @note If the mask is monochrome, device capability <a>FSRC_BIT_MASK</a> or <a>FSRC_GET_BITS</a> is required.
	*        If the mask is an alpha mask, device capability <a>FSRC_ALPHA_MASK</a> or <a>FSRC_GET_BITS</a> is required.
 */
INTERFACE(FS_BOOL, FPDRenderDeviceStretchBitMask, (FPD_RenderDevice dc,  const FS_DIBitmap bitmap,  FS_INT32 left,  FS_INT32 top,  FS_INT32 dest_width,  FS_INT32 dest_height,  FS_ARGB argb,  FS_DWORD flags))

/**
 * @brief FPDRenderDeviceGetDitherBits
 * @details Gets the dither bits.
 * @param[in]  dc The input render device object.
 * @return   The dither bits.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenderDeviceGetDitherBits, (FPD_RenderDevice dc))

/**
 * @brief FPDRenderDeviceDrawTextString
 * @details Draws a text string, using Windows style parameters.
 * @param[in]  dc The input render device object.
 * @param[in]  left x position, in device coordinate.
 * @param[in]  top y position, in device coordinate.
 * @param[in]  font The input font.
 * @param[in]  height height of the character cell, in pixels.
 * @param[in]  str a string using font encoding.
 * @param[in]  argb color and alpha value, in 0xaarrggbb format.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenderDeviceDrawTextString, (FPD_RenderDevice dc,  FS_INT32 left,  FS_INT32 top,  FPD_Font font,  FS_INT32 height,  FS_LPCSTR str,  FS_ARGB argb))

/**
 * @brief FPDRenderDeviceDrawTextString2
 * @details Draws a text string using PDF style parameters.
 * @param[in]  dc The input render device object.
 * @param[in]  originX x position of the origin (for first character), in device coord.
 * @param[in]  originY y position of the origin (for first character), in device coord.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize number of points for the font em square.
 * @param[in]  matrix a matrix from text space to device space, used for font rotation,
	*                          scaling and skewing. Can be NULL for identity matrix.
	*                          If specified, the "e" and "f" coefficients (for translation) are ignored.
 * @param[in]  str a string using font encoding.
 * @param[in]  fillArgb color and alpha value, in 0xaarrggbb format. 0 for not filling.
 * @param[in]  strokeArgb color for stroking text. 0 for not stroking.
 * @param[in]  graphState required for stroking.
 * @param[in]  opts rendering options, like clear-type flag.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDRenderDeviceDrawTextString2, (FPD_RenderDevice dc,  FS_FLOAT originX,  FS_FLOAT originY,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix matrix,  FS_ByteString str,  FS_ARGB fillArgb,  FS_ARGB strokeArgb,  const FPD_GraphState graphState,  const FPD_RenderOptions opts))

/**
 * @brief FPDRenderDeviceDrawTextPath
 * @details Draws text path.
 * @param[in]  dc The input render device object.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  text2User The matrix from text coordinate to user coordinate.
 * @param[in]  user2Device The matrix from user coordinate  to user coordinate.
 * @param[in]  graphState Graphic state, for pen attributes.
 * @param[in]  fillArgb Fill color.
 * @param[in]  strokeArgb Stroke color
 * @param[in]  clippingPath The clipping path to add to.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawTextPath, (FPD_RenderDevice dc,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix text2User,  FS_AffineMatrix user2Device,  const FPD_GraphState graphState,  FS_ARGB fillArgb,  FS_ARGB strokeArgb,  FPD_Path clippingPath))

/**
 * @brief FPDRenderDeviceDrawNormalText
 * @details Draws normal text.
 * @param[in]  dc The input render device object.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  text2Device The matrix from text coordinate to device coordinate.
 * @param[in]  fillArgb The fill color used to fill the text.
 * @param[in]  opts The render options.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawNormalText, (FPD_RenderDevice dc,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix text2Device,  FS_ARGB fillArgb,  const FPD_RenderOptions opts))

/**
 * @brief FPDRenderDeviceDrawType3Text
 * @details Draws type3 text.
 * @param[in]  dc The input render device object.
 * @param[in]  pContext The input render context.
 * @param[in]  pOptions The input render options.
 * @param[in]  pStates1 The input graphic states.
 * @param[in]  nChars The number of characters in the text.
 * @param[in]  pCharCodesBuf The character codes.
 * @param[in]  pCharPosBuf The character positions.
 * @param[in]  font The Type3 font will be used to draw text.
 * @param[in]  fontSize The font size.
 * @param[in]  pTextToDevice The pointer of  matrix from text coordinate to device coordinate.
 * @param[in]  fillArgb The fill color use to fill the text.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawType3Text, (FPD_RenderDevice dc,  FPD_RenderContext pContext,  FPD_RenderOptions pOptions,  FPD_PageObject pStates1,  FS_INT32 nChars,  FS_DWORD* pCharCodesBuf,  FS_FLOAT* pCharPosBuf,  FPD_Font font,  FS_FLOAT fontSize,  FS_AffineMatrix* pTextToDevice,  FS_ARGB fillArgb))

/**
 * @brief FPDRenderDeviceDrawPath
 * @details Draw a path. If either <param>fill_argb</param> or <param>stroke_argb</param> is used and with 
	* alpha value between 0 and 255, then device capability FSRC_ALPHA_PATH or FSRC_GET_BITS is required.
 * @param[in]  dc The input render device object.
 * @param[in]  path Path info.
 * @param[in]  pObject2Device Optional transformation.
 * @param[in]  graphState Graphic state, for pen attributes.
 * @param[in]  fill_color Fill color.
 * @param[in]  stroke_color Stroke color.
 * @param[in]  fill_mode Fill mode, FSFILL_WINDING or FSFILL_ALTERNATE. 0 for not filled. Also FSFILL_FULLCOVER or FSFILL_RECT_AA bit can be used with fill mode.
 * @param[in]  bAntiAlias Uses anti-alias if the driver supports.
 * @param[in]  alpha_flag The flag indicates color type and alpha value, each components 8 bits.
	* alpha_flag == (stroke_alpha<<16)|(color_type<<8)|fill_alpha
	* color type: 0 for rgb, 1 for cmyk
 * @param[in]  pIccTransform The color transform handle.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDRenderDeviceDrawPath, (FPD_RenderDevice dc,  FPD_Path path,  FS_AffineMatrix pObject2Device,  FPD_GraphState graphState,  FS_DWORD fill_color,  FS_DWORD stroke_color,  FS_INT32 fill_mode,  FS_BOOL bAntiAlias,  FS_INT32 alpha_flag,  void* pIccTransform))

/**
 * @brief FPDRenderDeviceSetClip_PathFill
 * @details Set clipping path using filled region.
 * @param[in]  dc The input render device object.
 * @param[in]  path The input path info.
 * @param[in]  pObject2Device Optional transformation.
 * @param[in]  fill_mode Fill mode, <a>FSFILL_WINDING</a> or <a>FSFILL_ALTERNATE</a>.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDRenderDeviceSetClip_PathFill, (FPD_RenderDevice dc,  FPD_Path path,  FS_AffineMatrix pObject2Device,  FS_INT32 fill_mode))

NumOfSelector(FPDRenderDevice)
ENDENUM

//*****************************
/* FxgeDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFxgeDeviceNew
 * @details Creates a new empty GE rendering device object.
 * @return   A new empty GE rendering device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDFxgeDeviceNew, ())

/**
 * @brief FPDFxgeDeviceCreate
 * @details Creates a new bitmap and attach to this device.
 * @param[in]  dc The input GE rendering device object.
 * @param[in]  width The bitmap width.
 * @param[in]  height The bitmap height
 * @param[in]  format The bitmap format.
 * @param[in]  ditherBits The optional dithering bits. 0 for no dithering
 * @return   void
 * @note The bitmap will be destroyed when the device destructs.
 */
INTERFACE(void, FPDFxgeDeviceCreate, (FPD_RenderDevice dc,  FS_INT32 width,  FS_INT32 height,  FS_DIB_Format format,  FS_INT32 ditherBits))

/**
 * @brief FPDFxgeDeviceDestroy
 * @details Destroys the GE rendering device object.
 * @param[in]  dc The input GE rendering device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFxgeDeviceDestroy, (FPD_RenderDevice dc))

/**
 * @brief FPDFxgeDeviceAttach
 * @details Attach a bitmap.
 * @param[in]  dc The input GE rendering device object.
 * @param[in]  bitmap The input bitmap to be attached.
 * @param[in]  ditherBits The input dither bits.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFxgeDeviceAttach, (FPD_RenderDevice dc,  FS_DIBitmap bitmap,  FS_INT32 ditherBits))

NumOfSelector(FPDFxgeDevice)
ENDENUM

//*****************************
/* WindowsDevice HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDWindowsDeviceNew
 * @details Creates a new empty Windows device object.
 * @param[in]  windowsDC The input Windows device.
 * @return   A new empty Windows rendering device object.
 * @note 
 */
INTERFACE(FPD_RenderDevice, FPDWindowsDeviceNew, (void* windowsDC))

/**
 * @brief FPDWindowsDeviceDestroy
 * @details Destroys the PDF Windows device object.
 * @param[in]  dc The input PDF Windows device object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDWindowsDeviceDestroy, (FPD_RenderDevice dc))

NumOfSelector(FPDWindowsDevice)
ENDENUM

//*****************************
/* PageRenderCache HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDPageRenderCacheNew
 * @details Creates a new empty page rendering cache object.
 * @param[in]  page The input PDF page.
 * @return   A new empty page rendering cache object.
 * @note 
 */
INTERFACE(FPD_PageRenderCache, FPDPageRenderCacheNew, (FPD_Page page))

/**
 * @brief FPDPageRenderCacheDestroy
 * @details Destroys the page rendering cache object.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheDestroy, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheClearAll
 * @details Clears all items in the cache.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheClearAll, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheClearImageData
 * @details Clears image data.
 * @param[in]  cache The input page rendering cache object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheClearImageData, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheEstimateSize
 * @details Gets estimated size of the total cache.
 * @param[in]  cache The input page rendering cache object.
 * @return   Estimated size of the total cache.
 * @note The application can use some strategy for dispense page caches according the memory size they occupy.
 */
INTERFACE(FS_DWORD, FPDPageRenderCacheEstimateSize, (FPD_PageRenderCache cache))

/**
 * @brief FPDPageRenderCacheGetCachedBitmap
 * @details Gets cached items
 * @param[in]  cache The input page rendering cache object.
 * @param[in]  stream The stream of the bitmap.
 * @param[out]  outBitmap It retrieves the bitmap.
 * @param[out]  outMask It retrieves the mask.
 * @param[out]  outMatteColor It retrieves the matte color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheGetCachedBitmap, (FPD_PageRenderCache cache,  FPD_Object stream,  FS_DIBitmap* outBitmap,  FS_DIBitmap* outMask,  FS_DWORD* outMatteColor))

/**
 * @brief FPDPageRenderCacheResetBitmap
 * @details Resets the image cache or force the cache to be expired
 * @param[in]  cache The input page rendering cache object.
 * @param[in]  stream The stream of the bitmap.
 * @param[in]  bitmap Input the bitmap.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDPageRenderCacheResetBitmap, (FPD_PageRenderCache cache,  FPD_Object stream,  const FS_DIBitmap bitmap))

NumOfSelector(FPDPageRenderCache)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
