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
/* ExtensionHFTMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSExtensionHFTMgrNewHFT
 * @details Creates a new function table which can be filled with several functions.
 * @param[in]  numOfIntefaces The capacity of this new function table.
 * @return   A new function table.
 * @note 
 * @see FSExtensionHFTMgrAddHFT
 * @see FSExtensionHFTMgrGetHFT
 */
INTERFACE(FS_HFT, FSExtensionHFTMgrNewHFT, (FS_INT32 numOfIntefaces))

/**
 * @brief FSExtensionHFTMgrAddHFT
 * @details Adds a new function table.
 * @param[in]  hftName The name of function table, used to identify it.
 * @param[in]  version Version of this function table.
 * @param[in]  hft The instance to be added.
 * @return   If success, return <a>ERR_ADDHFT_NAMEEXIST</a>(1), else(hft not exist) return <a>ERR_ADDHFT_UNKNOWN</a>(0).
 * @note 
 * @see FSExtensionHFTMgrNewHFT
 */
INTERFACE(FS_INT32, FSExtensionHFTMgrAddHFT, (const FS_CHAR* hftName,  FS_INT32 version,  FS_HFT hft))

/**
 * @brief FSExtensionHFTMgrGetHFT
 * @details Gets the function table.
 * @param[in]  hftName The name of function table, used to identify it.
 * @param[in]  version Version of this function table.
 * @return   If exists, returns the instance, else returns <a>NULL</a>.
 * @note 
 * @see FSExtensionHFTMgrReplaceEntry
 */
INTERFACE(FS_HFT, FSExtensionHFTMgrGetHFT, (const FS_CHAR* hftName,  FS_INT32 version))

/**
 * @brief FSExtensionHFTMgrReplaceEntry
 * @details Replaces the entry by specified selector.
 * @param[in]  hft The function table which contains the entry to be replaced.
 * @param[in]  iSel The index of entry to be replaced.
 * @param[in]  newEntry The new entry to replaced.
 * @return   
 * @note 
 * @see FSExtensionHFTMgrGetEntry
 */
INTERFACE(void, FSExtensionHFTMgrReplaceEntry, (FS_HFT hft,  FS_INT32 iSel,  void* newEntry))

/**
 * @brief FSExtensionHFTMgrGetEntry
 * @details Gets the entry by specified selector.
 * @param[in]  hft The function table which contains several entries.
 * @param[in]  iSel The index of entry to be found.
 * @return   If entry exists, returns the instance, else returns <a>NULL</a>.
 * @note 
 * @see FSExtensionHFTMgrReplaceEntry
 */
INTERFACE(void*, FSExtensionHFTMgrGetEntry, (FS_HFT hft,  FS_INT32 iSel))

NumOfSelector(FSExtensionHFTMgr)
ENDENUM

//*****************************
/* AffineMatrix HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSAffineMatrixIsScaled
 * @details Whether this matrix has scaling (or translating) only. No rotating.
 * @param[in]  matrix The input matrix.
 * @return   <a>TRUE</a> for this matrix having scaling (or translating) only, no rotating. Otherwise not.
 * @note 
 * @see FSAffineMatrixScale
 */
INTERFACE(FS_BOOL, FSAffineMatrixIsScaled, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixIs90Rotated
 * @details Whether this matrix has rotating of 90, or -90 degrees.
 * @param[in]  matrix The input matrix.
 * @return   <a>TRUE</a> for this matrix having rotating, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FSAffineMatrixIs90Rotated, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixGetReverse
 * @details Gets the inverse matrix base on a source matrix.
 * @param[in]  src The input matrix.
 * @return   The inverse matrix base on a source matrix.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixGetReverse, (FS_AffineMatrix src))

/**
 * @brief FSAffineMatrixTransformPoint
 * @details Transforms a point.
 * @param[in]  matrix The input matrix.
 * @param[in]  x The input x-coordinate of the point
 * @param[in]  y The input y-coordinate of the point.
 * @param[out]  outX It receives the output transformed x-coordinate.
 * @param[out]  outY It receives the output transformed y-coordinate.
 * @return   void
 * @note 
 * @see FSAffineMatrixTransformRect
 * @see FSAffineMatrixTransformDistance
 */
INTERFACE(void, FSAffineMatrixTransformPoint, (FS_AffineMatrix matrix,  FS_FLOAT x,  FS_FLOAT y,  FS_FLOAT* outX,  FS_FLOAT* outY))

/**
 * @brief FSAffineMatrixTransformRect
 * @details Transforms a rectangle and return a bounding rectangle. </Brief> The result rectangle is always normalized.
 * @param[in]  matrix The input matrix.
 * @param[in]  rc Rectangle to transform.
 * @return   The result rectangle.
 * @note 
 * @see FSAffineMatrixTransformPoint
 * @see FSAffineMatrixTransformDistance
 */
INTERFACE(FS_FloatRect, FSAffineMatrixTransformRect, (FS_AffineMatrix matrix,  FS_FloatRect rc))

/**
 * @brief FSAffineMatrixConcat
 * @details Concatenates with another matrix.
 * @param[in]  matrix The input matrix.
 * @param[in]  src The input matrix.
 * @return   The result matrix.
 * @note 
 * @see FSAffineMatrixConcatInverse
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixConcat, (FS_AffineMatrix matrix,  FS_AffineMatrix src))

/**
 * @brief FSAffineMatrixTranslate
 * @details Translates the matrix.
 * @param[in]  matrix The input matrix.
 * @param[in]  x The x-direction delta value.
 * @param[in]  y The y-direction delta value.
 * @return   The result matrix.
 * @note 
 * @see FSAffineMatrixTranslateI
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixTranslate, (FS_AffineMatrix matrix,  FS_FLOAT x,  FS_FLOAT y))

/**
 * @brief FSAffineMatrixTranslateI
 * @details Translates the matrix using integer value.
 * @param[in]  matrix The input matrix.
 * @param[in]  x The x-direction delta integer value.
 * @param[in]  y The y-direction delta integer value.
 * @return   The result matrix.
 * @note 
 * @see FSAffineMatrixTranslate
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixTranslateI, (FS_AffineMatrix matrix,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FSAffineMatrixScale
 * @details Scales the matrix.
 * @param[in]  matrix The input matrix.
 * @param[in]  xScale The x-direction scale coefficient.
 * @param[in]  yScale The y-direction scale coefficient.
 * @return   The result matrix.
 * @note 
 * @see FSAffineMatrixIsScale
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixScale, (FS_AffineMatrix matrix,  FS_FLOAT xScale,  FS_FLOAT yScale))

/**
 * @brief FSAffineMatrixConcatInverse
 * @details Concatenates the inverse of another matrix.
 * @param[in]  matrix The input matrix.
 * @param[in]  src The input matrix, to be inversed.
 * @return   The result of a matrix concatenating another matrix inversed;
 * @note 
 * @see FSAffineMatrixConcat
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixConcatInverse, (FS_AffineMatrix matrix,  FS_AffineMatrix src))

/**
 * @brief FSAffineMatrixMatchRect
 * @details Gets a matrix that transforms a source rectangle to dest rectangle.
 * @param[in]  dest The dest rectangle
 * @param[in]  src The source rectangle.
 * @return   The matrix that transforms a source rectangle to dest rectangle.
 * @note 
 * @see FSAffineMatrix
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixMatchRect, (FS_FloatRect dest,  FS_FloatRect src))

/**
 * @brief FSAffineMatrixGetUnitRect
 * @details Gets a bounding rectangle of the parallelogram composing two unit vectors.
 * @param[in]  matrix The input matrix.
 * @return   The unit rectangle.
 * @note 
 * @see FSAffineMatrixGetUnitArea
 */
INTERFACE(FS_FloatRect, FSAffineMatrixGetUnitRect, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixGetUnitArea
 * @details Gets area of the parallelogram composing two unit vectors.
 * @param[in]  matrix The input matrix.
 * @return   The unit area
 * @note 
 * @see FSAffineMatrixGetUnitRect
 */
INTERFACE(FS_FLOAT, FSAffineMatrixGetUnitArea, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixGetXUnit
 * @details Gets the x-direction unit size.
 * @param[in]  matrix The input matrix.
 * @return   The x-direction unit size.
 * @note 
 * @see FSAffineMatrixGetYUnit
 */
INTERFACE(FS_FLOAT, FSAffineMatrixGetXUnit, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixGetYUnit
 * @details Gets the y-direction unit size.
 * @param[in]  matrix The input matrix.
 * @return   The y-direction unit size.
 * @note 
 * @see FSAffineMatrixGetXUnit
 */
INTERFACE(FS_FLOAT, FSAffineMatrixGetYUnit, (FS_AffineMatrix matrix))

/**
 * @brief FSAffineMatrixTransformDistance
 * @details Transforms a distance.
 * @param[in]  matrix The input matrix.
 * @param[in]  distance The input distance.
 * @return   The transformed distance.
 * @note 
 * @see FSAffineMatrixTransformRect
 * @see FSAffineMatrixTransformPoint
 */
INTERFACE(FS_FLOAT, FSAffineMatrixTransformDistance, (FS_AffineMatrix matrix,  FS_FLOAT distance))

/**
 * @brief FSAffineMatrixRotate
 * @details Rotates the matrix.
 * @param[in]  matrix The input matrix.
 * @param[in]  fRadian Rotation angle in radian.
 * @param[in]  bPrepended If it's TRUE, a rotation matrix is multiplied at left side, or at right side. Sets it FALSE as default.
 * @return   The result matrix.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FSAffineMatrixRotate, (FS_AffineMatrix matrix,  FS_FLOAT fRadian,  FS_BOOL bPrepended))

NumOfSelector(FSAffineMatrix)
ENDENUM

//*****************************
/* DIBitmap HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSDIBitmapNew
 * @details Creates a bitmap. Optionally an external buffer provided by caller can be used. Using
	* <a>FSDIBitmapCreate</a>() to initialize after a bitmap object is created.
 * @return   A <a>FS_DIBitmap</a> object.
 * @note The buffer should be kept by caller during the existence of the bitmap.
 * @see FSDIBitmapClear
 * @see FSDIBitmapCreate
 * @see FSDIBitmapDestroy
 */
INTERFACE(FS_DIBitmap, FSDIBitmapNew, (void))

/**
 * @brief FSDIBitmapCreate
 * @details Actually create the <Italic>DIB</Italic>. Optionally the <Italic>DIB</Italic> can use external buffer provided by caller.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  width The width of the bitmap.
 * @param[in]  height The height of the bitmap.
 * @param[in]  format The format of the bitmap.
 * @param[in]  pBuffer The data buffer of the bitmap.
 * @param[in]  pitch Specified row pitch in bytes.
 * @return   void
 * @note The buffer should be kept by caller during the existence of the bitmap.
 * @see FSDIBitmapNew
 * @see FSDIBitmapClear
 * @see FSDIBitmapDestroy
 */
INTERFACE(void, FSDIBitmapCreate, (FS_DIBitmap bitmap,  FS_INT32 width,  FS_INT32 height,  FS_DIB_Format format,  FS_LPBYTE pBuffer,  FS_INT32 pitch))

/**
 * @brief FSDIBitmapDestroy
 * @details Destroys the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   void
 * @note 
 * @see FSDIBitmapCreate
 * @see FSDIBitmapNew
 */
INTERFACE(void, FSDIBitmapDestroy, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetWidth
 * @details Gets the width of the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   The width of the bitmap.
 * @note 
 * @see FSDIBitmapGetHeight
 */
INTERFACE(FS_INT32, FSDIBitmapGetWidth, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetHeight
 * @details Gets the height of the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   The height of the bitmap.
 * @note 
 * @see FSDIBitmapGetWidth
 */
INTERFACE(FS_INT32, FSDIBitmapGetHeight, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetFormat
 * @details Gets the format of the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   The format of the bitmap.
 * @note 
 */
INTERFACE(FS_DIB_Format, FSDIBitmapGetFormat, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetPitch
 * @details Gets the specified row pitch of the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   The row pitch of the bitmap.
 * @note 
 */
INTERFACE(FS_DWORD, FSDIBitmapGetPitch, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetPalette
 * @details Gets the palette of the bitmap.
 * @param[in]  bitmap The input bitmap.
 * @return   The palette of the bitmap.
 * @note 
 */
INTERFACE(FS_ARGB*, FSDIBitmapGetPalette, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetBuffer
 * @details Gets a buffer for whole <Italic>DIB</Italic>. Only in-memory DIB can supply such a buffer.
 * @param[in]  bitmap The input bitmap.
 * @return   A buffer for the whole <Italic>DIB</Italic>.
 * @note 
 */
INTERFACE(FS_LPBYTE, FSDIBitmapGetBuffer, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetScanline
 * @details Fetches a single scan line.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  line The zero-based line number. [0, height).
 * @return   A pointer to the scan line.
 * @note 
 * @see FSDIBitmapDownSampleScanline
 */
INTERFACE(FS_LPBYTE, FSDIBitmapGetScanline, (FS_DIBitmap bitmap,  FS_INT32 line))

/**
 * @brief FSDIBitmapDownSampleScanline
 * @details Downs sample a scanline, for quick stretching.
	*            </Brief> The down-sampled result would be either 8bpp (for mask and grayscale), 24bpp or 32bpp.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  line The zero-based line number.
 * @param[in,out]  destScan The destination scanline buffer to receive down-sample result.
 * @param[in]  destBpp The destination bits per pixel.
 * @param[in]  destWidth The destination width of pixels in the scanline.
 * @param[in]  bFlipX Whether to flip the bitmap in x-direction.
 * @param[in]  clipLeft Clip start of the destination scanline.
 * @param[in]  clipWidth Clip width of the destination scanline.
 * @return   void
 * @note 
 * @see FSDIBitmapGetScanline
 */
INTERFACE(void, FSDIBitmapDownSampleScanline, (FS_DIBitmap bitmap,  FS_INT32 line,  FS_LPBYTE destScan,  FS_INT32 destBpp,  FS_INT32 destWidth,  FS_BOOL bFlipX,  FS_INT32 clipLeft,  FS_INT32 clipWidth))

/**
 * @brief FSDIBitmapTakeOver
 * @details Takeovers a bitmap.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  srcBitmap The input source bitmap.
 * @return   void
 * @note After taking-over, the source bitmap will contain an empty bitmap, and this bitmap will contain all data of the source bitmap.
 */
INTERFACE(void, FSDIBitmapTakeOver, (FS_DIBitmap bitmap,  FS_DIBitmap srcBitmap))

/**
 * @brief FSDIBitmapConvertFormat
 * @details Converts a bitmap. All informations in the old bitmap are retained.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  format The destination bitmap format.
 * @return   void
 * @note Supported conversion:
	*            <ul>
	*              - <li>1bppMask => 8bppMask;</li>
	*              - <li>1bppRgb => Rgb / Rgb32 / Argb;</li>
	*              - <li>8bppRgb => Rgb / Rgb32 / Argb;</li>
	*              - <li>Rgb / Rgb32 => 8bppRgb;</li>
	*              - <li>Rgb => Rgb32 / Argb;</li>
	*              - <li>Rgb32 => Rgb / Argb</li>
	*             </ul>
 */
INTERFACE(void, FSDIBitmapConvertFormat, (FS_DIBitmap bitmap,  FS_DIB_Format format))

/**
 * @brief FSDIBitmapClear
 * @details Fills the whole bitmap with specified color. For alpha mask bitmaps, only the alpha value is taken.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  argb The specified color to fill.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDIBitmapClear, (FS_DIBitmap bitmap,  FS_ARGB argb))

/**
 * @brief FSDIBitmapGetPixel
 * @details Gets pixel ARGB value.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  x The x-coordinate in bitmap.
 * @param[in]  y The y-coordinate in bitmap.
 * @return   The pixel ARGB value.
 * @note For alpha mask bitmaps, only the alpha value of returned value is valid.
 * @see FSDIBitmapSetPixel
 */
INTERFACE(FS_DWORD, FSDIBitmapGetPixel, (FS_DIBitmap bitmap,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FSDIBitmapSetPixel
 * @details Sets pixel ARGB value.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  x The x-coordinate in bitmap.
 * @param[in]  y The y-coordinate in bitmap.
 * @param[in]  argb The input pixel ARGB value.
 * @return   void
 * @note For alpha mask bitmaps, only the alpha value is taken.
 * @see FSDIBitmapGetPixel
 */
INTERFACE(void, FSDIBitmapSetPixel, (FS_DIBitmap bitmap,  FS_INT32 x,  FS_INT32 y,  FS_ARGB argb))

/**
 * @brief FSDIBitmapLoadChannel
 * @details Loads a full channel from a source bitmap to this bitmap.
	*            </Brief>The source bitmap can be any format, but must have specified source channel.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destChannel The destination channel.
 * @param[in]  srcBitmap The DIB source.
 * @param[in]  srcChannel The source channel.
 * @return   void
 * @note If the destination channel is a color channel (R/G/B), then the this bitmap must be a colored image.
	*            If the destination channel is the alpha channel, and this bitmap doesn't have an alpha channel.
	*            it will be expanded with the alpha mask loaded. If this bitmap has already an alpha channel,
	*            then the previous alpha data will be replaced.
	*            If the source bitmap doesn't have same size as this bitmap, the source bitmap will stretched
	*            to match the destination size before channel transferring.
	*
 * @see FSDIBitmapLoadChannel2
 */
INTERFACE(void, FSDIBitmapLoadChannel, (FS_DIBitmap bitmap,  FS_DIB_Channel destChannel,  const FS_DIBitmap srcBitmap,  FS_DIB_Channel srcChannel))

/**
 * @brief FSDIBitmapLoadChannel2
 * @details Sets a full channel to specified value (0-255).
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destChannel The destination channel.
 * @param[in]  value The value to fill channel.
 * @return   void
 * @note This bitmap must be in Rgb, Rgb32, or Argb format.
 * @see FSDIBitmapLoadChannel
 */
INTERFACE(void, FSDIBitmapLoadChannel2, (FS_DIBitmap bitmap,  FS_DIB_Channel destChannel,  FS_INT32 value))

/**
 * @brief FSDIBitmapMultiplyAlpha
 * @details Multiplies alpha data with addition alpha (0-255).
 * @param[in]  bitmap The input bitmap.
 * @param[in]  alpha The alpha value to multiply with.
 * @return   void
 * @note Applicable to all formats:
	*            If this is an alpha mask (1bppMask or 8bppMask), the result will be a 8bppMask with mask data modified;
	*            If this is an image without alpha channel, the bitmap will be expanded to include an alpha channel with new alpha data;
	*            If this is an image with alpha channel, then the alpha value will be multiplied into existing alpha data.
 * @see FSDIBitmapMultiplyAlpha2
 */
INTERFACE(void, FSDIBitmapMultiplyAlpha, (FS_DIBitmap bitmap,  FS_INT32 alpha))

/**
 * @brief FSDIBitmapMultiplyAlpha2
 * @details Multiplies existing alpha data with another alpha mask.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  alphaMask The alpha mask to multiply with.
 * @return   void
 * @note Applicable to all destination formats:
	*            If this is an alpha mask (1bppMask or 8bppMask), the result will be a 8bppMask with mask data multiplied;
	*            If this is an image without alpha channel, the bitmap will be expanded to include an alpha channel with new alpha data;
	*            If this is an image with alpha channel, then the alpha value will be multiplied into existing alpha data.
	*            If the source mask doesn't have same size as this bitmap, the source mask will stretched
	*            to match the destination size before multiplying.
 * @see FSDIBitmapMultiplyAlpha
 */
INTERFACE(void, FSDIBitmapMultiplyAlpha2, (FS_DIBitmap bitmap,  const FS_DIBitmap alphaMask))

/**
 * @brief FSDIBitmapTransferBitmap
 * @details Transforms pixels from another bitmap into specified position.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destLeft The x-coordinate in destination bitmap.
 * @param[in]  destTop The y-coordinate in destination bitmap.
 * @param[in]  width The area width to transfer.
 * @param[in]  height The area height to transfer.
 * @param[in]  srcBitmap The DIB source.
 * @param[in]  srcLeft The x-coordinate in source bitmap.
 * @param[in]  srcTop The y-coordinate in source bitmap.
 * @return   void
 * @note The destination and source bitmaps can have different format, but need to be compatible.
	*            "width" and "height" parameters can not be negative. 
	*            Positions will be automatically clipped if out of source or destination bitmap region.
	*            The destination region will be replaced by data from the source bitmap.
 * @see FSDIBitmap
 */
INTERFACE(void, FSDIBitmapTransferBitmap, (FS_DIBitmap bitmap,  FS_INT32 destLeft,  FS_INT32 destTop,  FS_INT32 width,  FS_INT32 height,  const FS_DIBitmap srcBitmap,  FS_INT32 srcLeft,  FS_INT32 srcTop))

/**
 * @brief FSDIBitmapTransferMask
 * @details Transfers (portion of) an alpha mask (with source color) to this bitmap.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destLeft The x-coordinate in destination bitmap.
 * @param[in]  destTop The y-coordinate in destination bitmap.
 * @param[in]  width The area width to transfer.
 * @param[in]  height The area height to transfer.
 * @param[in]  mask The mask source.
 * @param[in]  argb The source color.
 * @param[in]  srcLeft The x-coordinate in source bitmap.
 * @param[in]  srcTop The y-coordinate in source bitmap.
 * @return   void
 * @note Applicable to Argb formats only. The changed portion will be replaced (not blended).
	*            The mask parameter must point to an alpha mask bitmap (1bppMask or 8bppMask).
 * @see FSDIBitmapCompositeBitmap
 * @see FSDIBitmapCompositeMask
 * @see FSDIBitmapCompositeRect
 */
INTERFACE(void, FSDIBitmapTransferMask, (FS_DIBitmap bitmap,  FS_INT32 destLeft,  FS_INT32 destTop,  FS_INT32 width,  FS_INT32 height,  const FS_DIBitmap mask,  FS_ARGB argb,  FS_INT32 srcLeft,  FS_INT32 srcTop))

/**
 * @brief FSDIBitmapCompositeBitmap
 * @details Composites and blend source bitmap into this <param>bitmap</param>.<br></brief>
	* This bitmap can be Rgb/Rgb32/Argb bitmap, and source bitmap can be any kind of bitmap (except masks).<br>
	* This bitmap can also be an 8bppMask, in this case only alpha channel from the source bitmap is composited.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destLeft The x-coordinate in destination bitmap.
 * @param[in]  destTop The y-coordinate in destination bitmap.
 * @param[in]  width The area width to composite.
 * @param[in]  height The area height to composite.
 * @param[in]  srcBitmap The source bitmap.
 * @param[in]  srcLeft The x-coordinate in source bitmap.
 * @param[in]  srcTop The y-coordinate in source bitmap.
 * @param[in]  blend_type The blend type. Decleared in <a>FSDIBlendTypes</a> group.
 * @return   void
 * @note 
 * @see FSDIBitmapCompositeMask
 * @see FSDIBitmapCompositeRect
 */
INTERFACE(void, FSDIBitmapCompositeBitmap, (FS_DIBitmap bitmap,  FS_INT32 destLeft,  FS_INT32 destTop,  FS_INT32 width,  FS_INT32 height,  const FS_DIBitmap srcBitmap,  FS_INT32 src_left,  FS_INT32 src_top,  FS_INT32 blend_type))

/**
 * @brief FSDIBitmapCompositeRect
 * @details Composites a fixed color into a rectangle area.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destLeft The x-coordinate of the left-top corner.
 * @param[in]  destTop The y-coordinate of the left-top corner.
 * @param[in]  width The area width.
 * @param[in]  height The area height.
 * @param[in]  argb The fixed color.
 * @return   void
 * @note Applicable to 8bppMask/Rgb/Rgb32/Argb formats only.
 * @see FSDIBitmapCompositeBitmap
 * @see FSDIBitmapTransferMask
 * @see FSDIBitmapCompositeMask
 */
INTERFACE(void, FSDIBitmapCompositeRect, (FS_DIBitmap bitmap,  FS_INT32 destLeft,  FS_INT32 destTop,  FS_INT32 width,  FS_INT32 height,  FS_ARGB argb))

/**
 * @brief FSDIBitmapGammaAdjust
 * @details Gamma adjustment.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  bInvert Whether reverse gamma adjustment or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDIBitmapGammaAdjust, (FS_DIBitmap bitmap,  FS_BOOL bInvert))

/**
 * @brief FSDIBitmapConvertColorScale
 * @details Converts current bitmap to a color scale bitmap. The DIB format won't be changed.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  forecolor The input forecolor.
 * @param[in]  backcolor The input backcolor.
 * @return   void
 * @note Color scale means all colors are a scale from forecolor to backcolor.
	*            If forecolor is black and backcolor is white, that's gray scale
	*            Doesn't work with masks.
 */
INTERFACE(void, FSDIBitmapConvertColorScale, (FS_DIBitmap bitmap,  FS_COLORREF forecolor,  FS_COLORREF backcolor))

/**
 * @brief FSDIBitmapDitherFS
 * @details Floyd-Steinberg dithering for (portion of) the bitmap, using a palette.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  pPalette The input palette color.
 * @param[in]  palSize The input palette size.
 * @param[in]  pRect The input rect for ditherning.
 * @return   void
 * @note Currently only 8-bit gray scale bitmap is supported!
 */
INTERFACE(void, FSDIBitmapDitherFS, (FS_DIBitmap bitmap,  FS_ARGB* pPalette,  FS_INT32 palSize,  FS_Rect* pRect))

/**
 * @brief FSDIBitmapGetBPP
 * @details Gets the number of bits per pixel.
 * @param[in]  bitmap The input bitmap.
 * @return   The number of bits per pixel.
 * @note 
 */
INTERFACE(FS_INT32, FSDIBitmapGetBPP, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapIsAlphaMask
 * @details Checks whether the bitmap is an alpha mask (either 1bpp bitmask or 8bpp gray scale).
 * @param[in]  bitmap The input bitmap.
 * @return   <a>TRUE</a> for bitmap being an alpha mask.
 * @note 
 */
INTERFACE(FS_BOOL, FSDIBitmapIsAlphaMask, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapHasAlpha
 * @details Checks if it's a bitmap with alpha channel.
 * @param[in]  bitmap The input bitmap.
 * @return   Non-zero means it has a alpha channel, otherwise has not.
 * @note Alpha masks return <a>FALSE</a>.
 */
INTERFACE(FS_BOOL, FSDIBitmapHasAlpha, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapIsOpaqueImage
 * @details Checks if it's a solid (opaque) image.
 * @param[in]  bitmap The input bitmap.
 * @return   Non-zero means it is a solid (opaque) image, otherwise is not.
 * @note 
 */
INTERFACE(FS_BOOL, FSDIBitmapIsOpaqueImage, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetPaletteSize
 * @details Gets the number of palette entries.
 * @param[in]  bitmap The input bitmap.
 * @return   The number of palette entries.
 * @note 
 */
INTERFACE(FS_INT32, FSDIBitmapGetPaletteSize, (FS_DIBitmap bitmap))

/**
 * @brief FSDIBitmapGetPaletteArgb
 * @details Gets palette entry with specified palette entry index.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  index Zero-based palette entry index of the palette.
 * @return   A palette entry value.
 * @note 
 * @see FSDIBitmapSetPaletteArgb
 */
INTERFACE(FS_ARGB, FSDIBitmapGetPaletteArgb, (FS_DIBitmap bitmap,  FS_INT32 index))

/**
 * @brief FSDIBitmapSetPaletteArgb
 * @details Changes a specified palette entry.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  index Zero-based palette entry index of the palette.
 * @param[in]  argb The new value the entry.
 * @return   void
 * @note 
 * @see FSDIBitmapGetPaletteArgb
 */
INTERFACE(void, FSDIBitmapSetPaletteArgb, (FS_DIBitmap bitmap,  FS_INT32 index,  FS_ARGB argb))

/**
 * @brief FSDIBitmapClone
 * @details Clones a bitmap. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  pClip The clipping region of source bitmap
 * @return   A cloned bitmap.
 * @note Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
 * @see FSDIBitmapCloneConvert
 */
INTERFACE(FS_DIBitmap, FSDIBitmapClone, (FS_DIBitmap bitmap,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapCloneConvert
 * @details Converts a bitmap, but clone first. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  format The destination bitmap format.
 * @param[in]  pClip The clipping region of source bitmap.
 * @return   The cloned bitmap.
 * @note Optionally a clipping region in bitmap coordinates can be specified to limit the size of result bitmap.
 * @see FSDIBitmapClone
 */
INTERFACE(FS_DIBitmap, FSDIBitmapCloneConvert, (FS_DIBitmap bitmap,  FS_DIB_Format format,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapGetAlphaMask
 * @details Gets alpha mask from a bitmap. Returns a 8bpp alpha mask. The returned value must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  pClip The clipping region of source bitmap.
 * @return   An alpha mask.
 * @note Applicable to Argb format only.
	*            Optionally a clipping region in bitmap coordinates can be specified to limit the size of result mask.
 */
INTERFACE(FS_DIBitmap, FSDIBitmapGetAlphaMask, (FS_DIBitmap bitmap,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapStretchTo
 * @details Stretches this bitmap into a new bitmap with different size. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  destWidth The width of the destination bitmap.
 * @param[in]  destHeight The height of the destination bitmap.
 * @param[in]  flags Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags
 * @param[in]  pClip The clipping region of destination bitmap.
 * @return   A new bitmap with different size.
 * @note If dest width or dest height is negative, the bitmap will be flipped.
	*            If a 1bpp bitmap is stretched, it will become either a RGB bitmap, if it's a colored bitmap;
	*            or a 8bpp gray scale mask if it's a bit mask.
	*            Stretching can be done in down-sample mode, which doesn't do interpolation so significantly faster
	*            especially when stretching big images into small ones.
	*            Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.
 */
INTERFACE(FS_DIBitmap, FSDIBitmapStretchTo, (FS_DIBitmap bitmap,  FS_INT32 destWidth,  FS_INT32 destHeight,  FS_DWORD flags,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapTransformTo
 * @details Transforms this bitmap. A new transformed bitmap is returned. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  pMatrix The transformation matrix.
 * @param[out]  outLeft Receives x-coordinate of the left-top corner of the result bitmap in destination coords.
 * @param[out]  outTop Receives y-coordinate of the left-top corner of the result bitmap in destination coords.
 * @param[in]  flags Stretching flags. It can use <a>FS_DIB_DOWNSAMPLE</a> and <a>FS_DIB_INTERPOL</a> flags.
 * @param[in]  pClip The clipping region of destination bitmap.
 * @return   A new transformed bitmap.
 * @note This bitmap can be colored bitmap, or an alpha mask. In case of colored bitmap,
	*             certain transformation (rotating or skewing) will cause the return bitmap as ARGB, no matter
	*             what the source bitmap format is.
	*             If a 1bpp bitmap is transformed, it will become either a RGB bitmap, if it's a colored bitmap;
	*             or a 8bpp gray scale mask if it's a bit mask.
	*             The dimension of returned bitmap always match the dimension of the matrix.
	*             Transformation can be done in down-sample mode, which doesn't do interpolation so significantly faster
	*             especially when transforming big images into small ones.
	*             Optionally a clipping region in result bitmap coordinates can be specified to limit the size of result bitmap.
	*             The position of left-top corner (in destination coordinates) of the result bitmap is also returned.
 */
INTERFACE(FS_DIBitmap, FSDIBitmapTransformTo, (FS_DIBitmap bitmap,  FS_AffineMatrix* pMatrix,  FS_INT32* outLeft,  FS_INT32* outTop,  FS_DWORD flags,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapSwapXY
 * @details Swaps X,Y coordinations of the bitmap. The image can also be flipped at the same time. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  bXFlip Whether to flip the bitmap in x-direction.
 * @param[in]  bYFlip Whether to flip the bitmap in y-direction.
 * @param[in]  pClip The clipping region of destination bitmap.
 * @return   A new bitmap.
 * @note Optionally a clipping region (in destination bitmap coordinates) can be specified to limit the size of result.
	*            This function can be used to rotate the bitmap 90 or 270 degree.
	*            Suppose the original image has the following 4 pixels:
	*			  
	*            +---+---+
	*			  | 1 | 2 |
	*			  +---+---+
	*			  | 3 | 4 |
	*			  +---+---+
	*			  Then, depends on value of <param>bXFlip</param> and <param>bYFlip</param>, the result would look like this:
	*				 
	*			  if bXFlip = FALSE, bYFlip = FALSE:
	*			  +---+---+
	*			  | 1 | 3 |
	*			  +---+---+
	*			  | 2 | 4 |
	*			  +---+---+
	*					
	*			  if bXFlip = TRUE, bYFlip = FALSE:
	*			  +---+---+
	*			  | 3 | 1 |
	*			  +---+---+
	*			  | 4 | 2 |
	*			  +---+---+
	*					
	*			  if bxflip = false, byflip = true:
	*			  +---+---+
	*			  | 2 | 4 |
	*			  +---+---+
	*			  | 1 | 3 |
	*			  +---+---+
	*					
	*			  if bxflip = true, byflip = true:
	*			  +---+---+
	*			  | 4 | 2 |
	*			  +---+---+
	*			  | 3 | 1 |
	*			  +---+---+
 */
INTERFACE(FS_DIBitmap, FSDIBitmapSwapXY, (FS_DIBitmap bitmap,  FS_BOOL bXFlip,  FS_BOOL bYFlip,  FS_Rect* pClip))

/**
 * @brief FSDIBitmapFlipImage
 * @details Flips image. The returned bitmap must be destroyed by <a>FSDIBitmapDestroy</a>().
 * @param[in]  bitmap The input bitmap.
 * @param[in]  bXFlip Whether to flip the bitmap in x-direction.
 * @param[in]  bYFlip Whether to flip the bitmap in y-direction.
 * @return   A flipped bitmap.
 * @note 
 */
INTERFACE(FS_DIBitmap, FSDIBitmapFlipImage, (FS_DIBitmap bitmap,  FS_BOOL bXFlip,  FS_BOOL bYFlip))

/**
 * @brief FSDIBitmapLoadFromPNGIcon
 * @details Loads a bitmap from a PNG file.
 * @param[in]  pwsFilePath The input PNG file path.
 * @return   The bitmap loaded.
 * @note 
 */
INTERFACE(FS_DIBitmap, FSDIBitmapLoadFromPNGIcon, (FS_LPCWSTR pwsFilePath))

/**
 * @brief FSDIBitmapLoadFromPNGIcon2
 * @details Loads a bitmap from a buffer.
 * @param[in]  handler The file access handler. The core API will take over the handler and release it. The plug-in do not need to release it.
 * @return   The bitmap loaded.
 * @note 
 */
INTERFACE(FS_DIBitmap, FSDIBitmapLoadFromPNGIcon2, (FS_FileReadHandler handler))

/**
 * @brief FSDIBitmapCopy
 * @details Copy from a DIB source, including bitmap info and all pixel data.
	* This DIBitmap must be newly constructed.
 * @param[in]  bitmap The input bitmap.
 * @param[in]  src The DIB source.
 * @return   TRUE for success, FALSE for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FSDIBitmapCopy, (FS_DIBitmap bitmap,  FS_DIBitmap src))

/**
 * @brief FSDIBitmapLoadInfo
 * @details Loads a bitmap attribute from a buffer.
 * @param[in]  handler The file access handler.
 * @param[in]  imageType The image type.
 * @return   The bitmap attribute loaded.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapDestroyDIBAttribute
 */
INTERFACE(FS_DIBAttribute, FSDIBitmapLoadInfo, (FS_FileReadHandler handler,  FS_DIB_IMAGE_TYPE imageType))

/**
 * @brief FSDIBitmapDestroyDIBAttribute
 * @details Destroys the input bitmap attribute object. Otherwise the plug-in will cause the memory leak problem.
 * @param[in]  attr The input bitmap attribute object to be destroyed.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapLoadInfo
 */
INTERFACE(void, FSDIBitmapDestroyDIBAttribute, (FS_DIBAttribute attr))

/**
 * @brief FSDIBitmapGetXDPI
 * @details Gets the horizontal resolution attribute of the bitmap.
 * @param[in]  attr The input bitmap attribute object.
 * @return   The horizontal resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value.
 * @note JBIG2 cannot get DPI information now.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapLoadInfo
 */
INTERFACE(FS_INT32, FSDIBitmapGetXDPI, (FS_DIBAttribute attr))

/**
 * @brief FSDIBitmapGetYDPI
 * @details Gets the Vertical resolution attribute of the bitmap.
 * @param[in]  attr The input bitmap attribute object.
 * @return   The vertical resolution, -1 means the bitmap doesn't contain this information, 0 or 1 means the user should use default DPI value.
 * @note JBIG2 cannot get DPI information now.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapLoadInfo
 */
INTERFACE(FS_INT32, FSDIBitmapGetYDPI, (FS_DIBAttribute attr))

/**
 * @brief FSDIBitmapGetDPIUnit
 * @details Gets the resolution unit, described by <a>FS_DIB_RESUNIT</a>.
 * @param[in]  attr The input bitmap attribute object.
 * @return   The resolution unit.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapLoadInfo
 */
INTERFACE(FS_WORD, FSDIBitmapGetDPIUnit, (FS_DIBAttribute attr))

/**
 * @brief FSDIBitmapGetExifInfo
 * @details Gets the exchangeable image file information of camera in JPEG file.
 * @param[in]  attr The input bitmap attribute object.
 * @param[in]  tag The input tag of the exchangeable image file information of camera in JPEG file, described by <a>FSDIBEXIFTAG</a>.
 * @param[out]  val The output value of the exchangeable image file information.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSDIBitmapLoadInfo
 */
INTERFACE(FS_BOOL, FSDIBitmapGetExifInfo, (FS_DIBAttribute attr,  FS_WORD tag,  FS_LPVOID val))

/**
 * @brief FSDIBitmapLoadFromPNGIcon3
 * @details Loads a bitmap from a instance handle.
 * @param[in]  hInstance The input plug-in instance handle.
 * @param[in]  lpwsName The input name of PNG resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @return   The bitmap loaded.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_DIBitmap, FSDIBitmapLoadFromPNGIcon3, (HINSTANCE hInstance,  FS_LPCWSTR lpwsName))

/**
 * @brief FSDIBitmapLoadFromImage
 * @details Loads a bitmap from a buffer.
 * @param[in]  handler The file access handler.
 * @return   The bitmap loaded.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_DIBitmap, FSDIBitmapLoadFromImage, (FS_FileReadHandler handler))

NumOfSelector(FSDIBitmap)
ENDENUM

//*****************************
/* MapPtrToPtr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSMapPtrToPtrNew
 * @details Creates an empty ptr-to-ptr map.
 * @param[in]  nBlockSize The internal block
 * @return   An empty ptr-to-ptr map.
 * @note 
 */
INTERFACE(FS_MapPtrToPtr, FSMapPtrToPtrNew, (FS_INT32 nBlockSize))

/**
 * @brief FSMapPtrToPtrDestroy
 * @details Destroys a ptr-to-ptr map.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   void
 * @note 
 */
INTERFACE(void, FSMapPtrToPtrDestroy, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrGetCount
 * @details Gets the number of elements.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   The number of elements in the map.
 * @note 
 */
INTERFACE(FS_INT32, FSMapPtrToPtrGetCount, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrIsEmpty
 * @details Tests whether the <param>map</param> is empty.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   <a>TRUE</a> for map being empty. <a>FALSE</a> otherwise.
 * @note 
 */
INTERFACE(FS_BOOL, FSMapPtrToPtrIsEmpty, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrLookup
 * @details Lookups by a key.
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in]  key The key to lookup.
 * @param[out]  outValue A ref of a typeless pointer to receive the found value.
 * @return   <a>TRUE</a> for value being found. <a>FALSE</a> otherwise.
 * @note 
 */
INTERFACE(FS_BOOL, FSMapPtrToPtrLookup, (FS_MapPtrToPtr map,  void* key,  void** outValue))

/**
 * @brief FSMapPtrToPtrGetValueAt
 * @details Retrieves a value pointer by a key
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in]  key The key to specify a value.
 * @return   A value. <a>NULL</a> if the key is not found.
 * @note 
 */
INTERFACE(void*, FSMapPtrToPtrGetValueAt, (FS_MapPtrToPtr map,  void* key))

/**
 * @brief FSMapPtrToPtrSetAt
 * @details Adds a new (key, value) pair. Adds if not exist, otherwise modify.
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in]  key The key to specify a position.
 * @param[in]  newValue The new value.
 * @return   void
 * @note 
 */
INTERFACE(void, FSMapPtrToPtrSetAt, (FS_MapPtrToPtr map,  void* key,  void* newValue))

/**
 * @brief FSMapPtrToPtrRemoveKey
 * @details Removes existing (key, value) pair.
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in]  key The key to remove.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FSMapPtrToPtrRemoveKey, (FS_MapPtrToPtr map,  void* key))

/**
 * @brief FSMapPtrToPtrRemoveAll
 * @details Removes all the (key, value) pairs in the map.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   void
 * @note 
 */
INTERFACE(void, FSMapPtrToPtrRemoveAll, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrGetStartPosition
 * @details Gets the first key-value pair position, iterating all (key, value) pairs.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   The first key-value pair position in the map
 * @note 
 */
INTERFACE(FS_POSITION, FSMapPtrToPtrGetStartPosition, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrGetNextAssoc
 * @details Gets the current association and sets the position to next association.
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in,out]  inOutNextPosition Input a position, and receive the next association position.
 * @param[out]  outKey (Filled by this method)Receive a key.
 * @param[out]  outValue (Filled by this method)Receive a value.
 * @return   void
 * @note 
 */
INTERFACE(void, FSMapPtrToPtrGetNextAssoc, (FS_MapPtrToPtr map,  FS_POSITION* inOutNextPosition,  void** outKey,  void** outValue))

/**
 * @brief FSMapPtrToPtrGetHashTableSize
 * @details Gets the internal hash table size. Advanced features for derived classes.
 * @param[in]  map The input ptr-to-ptr map.
 * @return   The hash table size.
 * @note 
 */
INTERFACE(FS_DWORD, FSMapPtrToPtrGetHashTableSize, (FS_MapPtrToPtr map))

/**
 * @brief FSMapPtrToPtrInitHashTable
 * @details Initializes the hash table
 * @param[in]  map The input ptr-to-ptr map.
 * @param[in]  hashSize Initializes the hash table size.
 * @param[in]  bAllocNow Does it Now allocate the hash table? No-zero means yes, otherwise not.
 * @return   void
 * @note 
 */
INTERFACE(void, FSMapPtrToPtrInitHashTable, (FS_MapPtrToPtr map,  FS_DWORD hashSize,  FS_BOOL bAllocNow))

NumOfSelector(FSMapPtrToPtr)
ENDENUM

//*****************************
/* PtrArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSPtrArrayNew
 * @details Creates a new empty pointer array.
 * @param[in]  void 
 * @return   A new empty pointer array.
 * @note 
 */
INTERFACE(FS_PtrArray, FSPtrArrayNew, (void))

/**
 * @brief FSPtrArrayDestroy
 * @details Destroys a pointer array.
 * @param[in]  arr The input pointer array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayDestroy, (FS_PtrArray arr))

/**
 * @brief FSPtrArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input pointer array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSPtrArrayGetSize, (FS_PtrArray arr))

/**
 * @brief FSPtrArrayGetUpperBound
 * @details Gets the upper bound in the array, actually the maximum valid index.
 * @param[in]  arr The input pointer array.
 * @return   The upper bound.
 * @note 
 */
INTERFACE(FS_INT32, FSPtrArrayGetUpperBound, (FS_PtrArray arr))

/**
 * @brief FSPtrArraySetSize
 * @details Changes the allocated size and the growing amount.
 * @param[in]  arr The input pointer array.
 * @param[in]  nNewSize The new size in elements expected.
 * @param[in]  nGrowBy The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArraySetSize, (FS_PtrArray arr,  FS_INT32 nNewSize,  FS_INT32 nGrowBy))

/**
 * @brief FSPtrArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input pointer array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayRemoveAll, (FS_PtrArray arr))

/**
 * @brief FSPtrArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   An element.
 * @note 
 */
INTERFACE(void*, FSPtrArrayGetAt, (FS_PtrArray arr,  FS_INT32 index))

/**
 * @brief FSPtrArraySetAt
 * @details Overwrites an element specified by an index number.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[in]  newItem An element
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArraySetAt, (FS_PtrArray arr,  FS_INT32 index,  void* newItem))

/**
 * @brief FSPtrArraySetAtGrow
 * @details Sets an element value at specified position. Potentially grow the array.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArraySetAtGrow, (FS_PtrArray arr,  FS_INT32 index,  void* newItem))

/**
 * @brief FSPtrArrayAdd
 * @details Adds an element at the tail. Potentially grow the array.
 * @param[in]  arr The input pointer array.
 * @param[in]  newItem The input element.
 * @return   The added element's index in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSPtrArrayAdd, (FS_PtrArray arr,  void* newItem))

/**
 * @brief FSPtrArrayAppend
 * @details Appends an array.
 * @param[in]  arr The input pointer array.
 * @param[in]  srcArr The input array.
 * @return   The old size in elements.
 * @note 
 */
INTERFACE(FS_INT32, FSPtrArrayAppend, (FS_PtrArray arr,  const FS_PtrArray srcArr))

/**
 * @brief FSPtrArrayCopy
 * @details Copies from an array.
 * @param[in]  arr The input pointer array.
 * @param[in]  srcArr The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayCopy, (FS_PtrArray arr,  FS_PtrArray srcArr))

/**
 * @brief FSPtrArrayGetDataPtr
 * @details Gets a pointer to the specified element in the array. Direct pointer access.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @return   A pointer to the specified element.
 * @note 
 */
INTERFACE(void**, FSPtrArrayGetDataPtr, (FS_PtrArray arr,  FS_INT32 index))

/**
 * @brief FSPtrArrayInsertAt
 * @details Inserts one or more continuous element at specified position.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  newItem Specifies the element value to insert.
 * @param[in]  nCount Specifies the count of the element to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayInsertAt, (FS_PtrArray arr,  FS_INT32 index,  void* newItem,  FS_INT32 nCount))

/**
 * @brief FSPtrArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input pointer array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  nCount Specifies the count of element to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayRemoveAt, (FS_PtrArray arr,  FS_INT32 index,  FS_INT32 nCount))

/**
 * @brief FSPtrArrayInsertNewArrayAt
 * @details Inserts an array at specified position.
 * @param[in]  arr The input pointer array.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to insert at.
 * @param[in]  newArray The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPtrArrayInsertNewArrayAt, (FS_PtrArray arr,  FS_INT32 nStartIndex,  FS_PtrArray newArray))

/**
 * @brief FSPtrArrayFind
 * @details Finds an element from specified position to last
 * @param[in]  arr The input pointer array.
 * @param[in]  item The input element.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to find.
 * @return   An index of the found element. It can be -1 for finding none.
 * @note 
 */
INTERFACE(FS_INT32, FSPtrArrayFind, (FS_PtrArray arr,  void* item,  FS_INT32 nStartIndex))

NumOfSelector(FSPtrArray)
ENDENUM

//*****************************
/* ByteArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSByteArrayNew
 * @details Creates a new empty byte array.
 * @param[in]  void 
 * @return   A new empty byte array.
 * @note 
 */
INTERFACE(FS_ByteArray, FSByteArrayNew, (void))

/**
 * @brief FSByteArrayDestroy
 * @details Destroys a byte array.
 * @param[in]  arr The input byte array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayDestroy, (FS_ByteArray arr))

/**
 * @brief FSByteArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input byte array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSByteArrayGetSize, (FS_ByteArray arr))

/**
 * @brief FSByteArrayGetUpperBound
 * @details Gets the upper bound in the array, actually the maximum valid index.
 * @param[in]  arr The input byte array.
 * @return   The upper bound.
 * @note 
 */
INTERFACE(FS_INT32, FSByteArrayGetUpperBound, (FS_ByteArray arr))

/**
 * @brief FSByteArraySetSize
 * @details Changes the allocated size and the growing amount.
 * @param[in]  arr The input byte array.
 * @param[in]  nNewSize The new size in elements expected.
 * @param[in]  nGrowBy The growing amount in elements expected. <param>nGrowBy</param> can be -1 for the growing amount unchanged.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArraySetSize, (FS_ByteArray arr,  FS_INT32 nNewSize,  FS_INT32 nGrowBy))

/**
 * @brief FSByteArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input byte array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayRemoveAll, (FS_ByteArray arr))

/**
 * @brief FSByteArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   An element
 * @note 
 */
INTERFACE(FS_BYTE, FSByteArrayGetAt, (FS_ByteArray arr,  FS_INT32 index))

/**
 * @brief FSByteArraySetAt
 * @details Overwrites an element specified by an index number.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[in]  newItem An element
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArraySetAt, (FS_ByteArray arr,  FS_INT32 index,  FS_BYTE newItem))

/**
 * @brief FSByteArraySetAtGrow
 * @details Sets an element value at specified position. Potentially grow the array.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArraySetAtGrow, (FS_ByteArray arr,  FS_INT32 index,  FS_BYTE newItem))

/**
 * @brief FSByteArrayAdd
 * @details Adds an element at the tail. Potentially grow the array
 * @param[in]  arr The input byte array.
 * @param[in]  newItem The input element.
 * @return   The added element's index in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSByteArrayAdd, (FS_ByteArray arr,  FS_BYTE newItem))

/**
 * @brief FSByteArrayAppend
 * @details Appends an array.
 * @param[in]  arr The input byte array.
 * @param[in]  srcArr The input array.
 * @return   The old size in elements.
 * @note 
 */
INTERFACE(FS_INT32, FSByteArrayAppend, (FS_ByteArray arr,  const FS_ByteArray srcArr))

/**
 * @brief FSByteArrayCopy
 * @details Copies from an array.
 * @param[in]  arr The input byte array.
 * @param[in]  srcArr The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayCopy, (FS_ByteArray arr,  FS_ByteArray srcArr))

/**
 * @brief FSByteArrayGetDataPtr
 * @details Gets a pointer to the specified element in the array. Direct pointer access.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @return   A pointer to the specified element.
 * @note 
 */
INTERFACE(FS_BYTE*, FSByteArrayGetDataPtr, (FS_ByteArray arr,  FS_INT32 index))

/**
 * @brief FSByteArrayInsertAt
 * @details Inserts one or more continuous element at specified position.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  newItem Specifies the element value to insert.
 * @param[in]  nCount Specifies the count of the element to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayInsertAt, (FS_ByteArray arr,  FS_INT32 index,  FS_BYTE newItem,  FS_INT32 nCount))

/**
 * @brief FSByteArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input byte array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  nCount Specifies the count of element to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayRemoveAt, (FS_ByteArray arr,  FS_INT32 index,  FS_INT32 nCount))

/**
 * @brief FSByteArrayInsertNewArrayAt
 * @details Inserts an array at specified position.
 * @param[in]  arr The input byte array.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to insert at.
 * @param[in]  newArray The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteArrayInsertNewArrayAt, (FS_ByteArray arr,  FS_INT32 nStartIndex,  FS_ByteArray newArray))

/**
 * @brief FSByteArrayFind
 * @details Finds an element from specified position to last
 * @param[in]  arr The input byte array.
 * @param[in]  item The input element.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to find.
 * @return   An index of the found element. It can be -1 for finding none.
 * @note 
 */
INTERFACE(FS_INT32, FSByteArrayFind, (FS_ByteArray arr,  FS_BYTE item,  FS_INT32 nStartIndex))

NumOfSelector(FSByteArray)
ENDENUM

//*****************************
/* WordArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSWordArrayNew
 * @details Creates a new empty word array.
 * @param[in]  void 
 * @return   A new empty word array.
 * @note 
 */
INTERFACE(FS_WordArray, FSWordArrayNew, (void))

/**
 * @brief FSWordArrayDestroy
 * @details Destroys a word array.
 * @param[in]  arr The input word array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayDestroy, (FS_WordArray arr))

/**
 * @brief FSWordArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input word array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSWordArrayGetSize, (FS_WordArray arr))

/**
 * @brief FSWordArrayGetUpperBound
 * @details Gets the upper bound in the array, actually the maximum valid index.
 * @param[in]  arr The input word array.
 * @return   The upper bound.
 * @note 
 */
INTERFACE(FS_INT32, FSWordArrayGetUpperBound, (FS_WordArray arr))

/**
 * @brief FSWordArraySetSize
 * @details Changes the allocated size and the growing amount.
 * @param[in]  arr The input word array.
 * @param[in]  nNewSize The new size in elements expected.
 * @param[in]  nGrowBy The growing amount in elements expected. <param>nGrowBy</param> can be -1 for the growing amount unchanged.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArraySetSize, (FS_WordArray arr,  FS_INT32 nNewSize,  FS_INT32 nGrowBy))

/**
 * @brief FSWordArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input word array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayRemoveAll, (FS_WordArray arr))

/**
 * @brief FSWordArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   An element
 * @note 
 */
INTERFACE(FS_WORD, FSWordArrayGetAt, (FS_WordArray arr,  FS_INT32 index))

/**
 * @brief FSWordArraySetAt
 * @details Overwrites an element specified by an index number.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[in]  newItem An element
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArraySetAt, (FS_WordArray arr,  FS_INT32 index,  FS_WORD newItem))

/**
 * @brief FSWordArraySetAtGrow
 * @details Sets an element value at specified position. Potentially growing the array.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArraySetAtGrow, (FS_WordArray arr,  FS_INT32 index,  FS_WORD newItem))

/**
 * @brief FSWordArrayAdd
 * @details Adds an element at the tail. Potentially growing the array
 * @param[in]  arr The input word array.
 * @param[in]  newItem The input element.
 * @return   The added element's index.
 * @note 
 */
INTERFACE(FS_INT32, FSWordArrayAdd, (FS_WordArray arr,  FS_WORD newItem))

/**
 * @brief FSWordArrayAppend
 * @details Appends an array.
 * @param[in]  arr The input word array.
 * @param[in]  srcArr The input array.
 * @return   The old size in elements.
 * @note 
 */
INTERFACE(FS_INT32, FSWordArrayAppend, (FS_WordArray arr,  const FS_WordArray srcArr))

/**
 * @brief FSWordArrayCopy
 * @details Copies from an array.
 * @param[in]  arr The input word array.
 * @param[in]  srcArr The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayCopy, (FS_WordArray arr,  FS_WordArray srcArr))

/**
 * @brief FSWordArrayGetDataPtr
 * @details Gets a pointer to the specified element in the array. Direct pointer access.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @return   A pointer to the specified element.
 * @note 
 */
INTERFACE(FS_WORD*, FSWordArrayGetDataPtr, (FS_WordArray arr,  FS_INT32 index))

/**
 * @brief FSWordArrayInsertAt
 * @details Inserts one or more continuous element at specified position.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  newItem Specifies the element value to insert.
 * @param[in]  nCount Specifies the count of the element to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayInsertAt, (FS_WordArray arr,  FS_INT32 index,  FS_WORD newItem,  FS_INT32 nCount))

/**
 * @brief FSWordArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input word array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  nCount Specifies the count of element to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayRemoveAt, (FS_WordArray arr,  FS_INT32 index,  FS_INT32 nCount))

/**
 * @brief FSWordArrayInsertNewArrayAt
 * @details Inserts an array at specified position.
 * @param[in]  arr The input word array.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to insert at.
 * @param[in]  newArray The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWordArrayInsertNewArrayAt, (FS_WordArray arr,  FS_INT32 nStartIndex,  FS_WordArray newArray))

/**
 * @brief FSWordArrayFind
 * @details Finds an element from specified position to last
 * @param[in]  arr The input word array.
 * @param[in]  item The input element.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to find.
 * @return   An index of the found element. It can be -1 for found none.
 * @note 
 */
INTERFACE(FS_INT32, FSWordArrayFind, (FS_WordArray arr,  FS_WORD item,  FS_INT32 nStartIndex))

NumOfSelector(FSWordArray)
ENDENUM

//*****************************
/* DWordArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSDWordArrayNew
 * @details Creates a new empty DWord array.
 * @param[in]  void 
 * @return   A new empty DWord array.
 * @note 
 */
INTERFACE(FS_DWordArray, FSDWordArrayNew, (void))

/**
 * @brief FSDWordArrayDestroy
 * @details Destroys a double word array.
 * @param[in]  arr The input DWord array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayDestroy, (FS_DWordArray arr))

/**
 * @brief FSDWordArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input DWord array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSDWordArrayGetSize, (FS_DWordArray arr))

/**
 * @brief FSDWordArrayGetUpperBound
 * @details Gets the upper bound in the array. actually the maximum valid index.
 * @param[in]  arr The input DWord array.
 * @return   The upper bound.
 * @note 
 */
INTERFACE(FS_INT32, FSDWordArrayGetUpperBound, (FS_DWordArray arr))

/**
 * @brief FSDWordArraySetSize
 * @details Changes the allocated size and the grow amount.
 * @param[in]  arr The input DWord array.
 * @param[in]  nNewSize The new size in elements expected.
 * @param[in]  nGrowBy The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArraySetSize, (FS_DWordArray arr,  FS_INT32 nNewSize,  FS_INT32 nGrowBy))

/**
 * @brief FSDWordArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input DWord array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayRemoveAll, (FS_DWordArray arr))

/**
 * @brief FSDWordArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   An element
 * @note 
 */
INTERFACE(FS_DWORD, FSDWordArrayGetAt, (FS_DWordArray arr,  FS_INT32 index))

/**
 * @brief FSDWordArraySetAt
 * @details Overwrites an element specified by an index number.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[in]  newItem An element
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArraySetAt, (FS_DWordArray arr,  FS_INT32 index,  FS_DWORD newItem))

/**
 * @brief FSDWordArraySetAtGrow
 * @details Sets an element value at specified position. Potentially growing the array.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArraySetAtGrow, (FS_DWordArray arr,  FS_INT32 index,  FS_DWORD newItem))

/**
 * @brief FSDWordArrayAdd
 * @details Adds an element at the tail. Potentially growing the array
 * @param[in]  arr The input DWord array.
 * @param[in]  newItem The input element.
 * @return   The added element's index.
 * @note 
 */
INTERFACE(FS_INT32, FSDWordArrayAdd, (FS_DWordArray arr,  FS_DWORD newItem))

/**
 * @brief FSDWordArrayAppend
 * @details Appends an array.
 * @param[in]  arr The input DWord array.
 * @param[in]  srcArr The input array.
 * @return   The old size in elements.
 * @note 
 */
INTERFACE(FS_INT32, FSDWordArrayAppend, (FS_DWordArray arr,  const FS_DWordArray srcArr))

/**
 * @brief FSDWordArrayCopy
 * @details Copies from an array.
 * @param[in]  arr The input DWord array.
 * @param[in]  srcArr The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayCopy, (FS_DWordArray arr,  FS_DWordArray srcArr))

/**
 * @brief FSDWordArrayGetDataPtr
 * @details Gets a pointer to the specified element in the array. Direct pointer access.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @return   A pointer to the specified element.
 * @note 
 */
INTERFACE(FS_DWORD*, FSDWordArrayGetDataPtr, (FS_DWordArray arr,  FS_INT32 index))

/**
 * @brief FSDWordArrayInsertAt
 * @details Inserts one or more continuous element at specified position.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  newItem Specifies the element value to insert.
 * @param[in]  nCount Specifies the count of the element to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayInsertAt, (FS_DWordArray arr,  FS_INT32 index,  FS_DWORD newItem,  FS_INT32 nCount))

/**
 * @brief FSDWordArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input DWord array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  nCount Specifies the count of element to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayRemoveAt, (FS_DWordArray arr,  FS_INT32 index,  FS_INT32 nCount))

/**
 * @brief FSDWordArrayInsertNewArrayAt
 * @details Insets an array at specified position.
 * @param[in]  arr The input DWord array.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to insert at.
 * @param[in]  newArray The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSDWordArrayInsertNewArrayAt, (FS_DWordArray arr,  FS_INT32 nStartIndex,  FS_DWordArray newArray))

/**
 * @brief FSDWordArrayFind
 * @details Finds an element from specified position to last
 * @param[in]  arr The input DWord array.
 * @param[in]  item The input element.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to find.
 * @return   An index of the found element. It can be -1 for found none.
 * @note 
 */
INTERFACE(FS_INT32, FSDWordArrayFind, (FS_DWordArray arr,  FS_DWORD item,  FS_INT32 nStartIndex))

NumOfSelector(FSDWordArray)
ENDENUM

//*****************************
/* ByteStringArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSByteStringArrayNew
 * @details Creates a new empty byte-string array.
 * @param[in]  void 
 * @return   A new empty byte-string array.
 * @note 
 */
INTERFACE(FS_ByteStringArray, FSByteStringArrayNew, (void))

/**
 * @brief FSByteStringArrayDestroy
 * @details Destroys the byte-string array.
 * @param[in]  arr The input byte-string array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayDestroy, (FS_ByteStringArray arr))

/**
 * @brief FSByteStringArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input byte-string array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[out]  outByteString It retrieves an element specified by an index number.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayGetAt, (FS_ByteStringArray arr,  FS_INT32 index,  FS_ByteString* outByteString))

/**
 * @brief FSByteStringArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input byte-string array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSByteStringArrayGetSize, (FS_ByteStringArray arr))

/**
 * @brief FSByteStringArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input byte-string array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayRemoveAll, (FS_ByteStringArray arr))

/**
 * @brief FSByteStringArrayAdd
 * @details Adds an element at the tail. Potentially growing the array
 * @param[in]  arr The input byte-string array.
 * @param[in]  newItem The input element.
 * @param[in]  newItem The length.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayAdd, (FS_ByteStringArray arr,  FS_LPSTR newItem,  FS_INT32 nLen))

/**
 * @brief FSByteStringArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input byte-string array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayRemoveAt, (FS_ByteStringArray arr,  FS_INT32 index))

/**
 * @brief FSByteStringArrayAdd2
 * @details Add a copy of an existing object to the array.
 * @param[in]  arr The input byte-string array.
 * @param[in]  bsNew The new byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSByteStringArrayAdd2, (FS_ByteStringArray arr,  FS_ByteString bsNew))

/**
 * @brief FSByteStringArrayGetDataPtr
 * @details The pointer to the specified element.
 * @param[in]  arr The input byte-string array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   Gets the pointer to the specified element.
 * @note 
 */
INTERFACE(FS_ByteString, FSByteStringArrayGetDataPtr, (FS_ByteStringArray arr,  FS_INT32 index))

NumOfSelector(FSByteStringArray)
ENDENUM

//*****************************
/* WideStringArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSWideStringArrayNew
 * @details Creates a new empty wide-string array.
 * @param[in]  void 
 * @return   A new empty wide-string array.
 * @note 
 */
INTERFACE(FS_WideStringArray, FSWideStringArrayNew, (void))

/**
 * @brief FSWideStringArrayDestroy
 * @details Destroys the wide-string array.
 * @param[in]  arr The input wide-string array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringArrayDestroy, (FS_WideStringArray arr))

/**
 * @brief FSWideStringArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input wide-string array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[out]  outWideString Retrieves an element specified by an index number.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringArrayGetAt, (FS_WideStringArray arr,  FS_INT32 index,  FS_WideString* outWideString))

/**
 * @brief FSWideStringArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input wide-string array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSWideStringArrayGetSize, (FS_WideStringArray arr))

/**
 * @brief FSWideStringArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input wide-string array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringArrayRemoveAll, (FS_WideStringArray arr))

/**
 * @brief FSWideStringArrayAdd
 * @details Adds an element at the tail. Potentially growing the array
 * @param[in]  arr The input wide-string array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringArrayAdd, (FS_WideStringArray arr,  FS_LPCWSTR newItem))

/**
 * @brief FSWideStringArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input wide-string array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSWideStringArrayRemoveAt, (FS_WideStringArray arr,  FS_INT32 index))

NumOfSelector(FSWideStringArray)
ENDENUM

//*****************************
/* CodeTransformation HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSCodeTransformationNameDecode
 * @details Decode a name from it lexical form, From a buffered name of lexical form.
 * @param[in]  orig The input buffered name of lexical form.
 * @param[out]  outDecodedName The decoded name.
 * @return   void
 * @note 
 */
INTERFACE(void, FSCodeTransformationNameDecode, (FS_ByteString orig,  FS_ByteString* outDecodedName))

/**
 * @brief FSCodeTransformationNameEncode
 * @details Encode a name to lexical form (to be used for output).
 * @param[in]  orig The input name.
 * @param[out]  outDecodedName A lexical form of the name.
 * @return   void
 * @note 
 */
INTERFACE(void, FSCodeTransformationNameEncode, (FS_ByteString orig,  FS_ByteString* outDecodedName))

/**
 * @brief FSCodeTransformationEncodeString
 * @details A PDF formatted string (including () or <>).
 * @param[in]  src The input string.
 * @param[in]  bHex Whether we will do hex-encoding.
 * @param[out]  outEncodedString The PDF formatted string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSCodeTransformationEncodeString, (FS_ByteString src,  FS_BOOL bHex,  FS_ByteString* outEncodedString))

/**
 * @brief FSCodeTransformationDecodeText
 * @details Decode PDF encoded text string into a Unicode encoded string, from a byte string.
 * @param[in]  str The input PDF encoded text string.
 * @param[in]  charMap The input character mapping.
 * @param[out]  outDecodeText A Unicode encoded string.
 * @return   void
 * @note If no char map specified, PDFDocEncoding is used.
 */
INTERFACE(void, FSCodeTransformationDecodeText, (FS_ByteString str,  FS_CharMap charMap,  FS_WideString* outDecodeText))

/**
 * @brief FSCodeTransformationDecodeText2
 * @details Decode PDF encoded text string into a Unicode encoded string, from a memory block.
 * @param[in]  pData The input PDF encoded text buffer.
 * @param[in]  size The size in bytes of the buffer.
 * @param[in]  charMap The input character mapping.
 * @param[out]  outDecodeText A Unicode encoded string.
 * @return   void
 * @note If no char map specified, PDFDocEncoding is used.
 */
INTERFACE(void, FSCodeTransformationDecodeText2, (FS_LPBYTE pData,  FS_DWORD size,  FS_CharMap charMap,  FS_WideString* outDecodeText))

/**
 * @brief FSCodeTransformationEncodeText
 * @details Encode a Unicode text string (UTF-16LE) into PDF encoding.
 * @param[in]  pString The input Unicode text string (UTF-16LE).
 * @param[in]  len The length of the input unicode string. -1 for zero-terminated Unicode string.
 * @param[in]  charMap The input character mapping.
 * @param[out]  outEncodeText The PDF encoded string.
 * @return   void
 * @note If no char map specified, PDFDocEncoding is used.
 */
INTERFACE(void, FSCodeTransformationEncodeText, (FS_LPWORD pString,  FS_INT32 len,  FS_CharMap charMap,  FS_ByteString* outEncodeText))

/**
 * @brief FSCodeTransformationFlateEncodeProc
 * @details Flate encode algorithm.
 * @param[in]  src_buf The source data.
 * @param[in]  src_size The size in bytes of the source data.
 * @param[out]  dest_buf It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the encoded data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FSCodeTransformationFlateDecodeProc
 */
INTERFACE(void, FSCodeTransformationFlateEncodeProc, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationFlateDecodeProc
 * @details Flate decode algorithm.
 * @param[in]  src_buf The source encoded data.
 * @param[in]  src_size The size in bytes of the source encoded data.
 * @param[out]  dest_buf It will receive the decoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the decoded data.
 * @return   The size in bytes of source data consumed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FSCodeTransformationFlateEncodeProc
 */
INTERFACE(FS_DWORD, FSCodeTransformationFlateDecodeProc, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationRunLengthDecodeProc
 * @details Run-length decode algorithm.
 * @param[in]  src_buf The source encoded data.
 * @param[in]  src_size The size in bytes of the source encoded data.
 * @param[out]  dest_buf It will receive the decoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the decoded data.
 * @return   The size in bytes of source data consumed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FSCodeTransformationRunLengthEncodeProc
 */
INTERFACE(FS_DWORD, FSCodeTransformationRunLengthDecodeProc, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationRunLengthEncodeProc
 * @details Run-length encode algorithm.
 * @param[in]  src_buf The source data.
 * @param[in]  src_size The size in bytes of the source data.
 * @param[out]  dest_buf It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the encoded data.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FSCodeTransformationRunLengthDecodeProc
 */
INTERFACE(FS_BOOL, FSCodeTransformationRunLengthEncodeProc, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationMemFree
 * @details Free the pointer;
 * @param[in]  pointer The pointer to free;
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSCodeTransformationMemFree, (void* pointer))

/**
 * @brief FSCodeTransformationBasicModuleA85Encode
 * @details A85 encode algorithm. This interface is for internal use only now.
 * @param[in]  src_buf The source data.
 * @param[in]  src_size The size in bytes of the source data.
 * @param[out]  dest_buf It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the encoded data.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FSCodeTransformationBasicModuleA85Encode, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationFlateModuleEncode
 * @details Flate module encode. This interface is for internal use only now.
 * @param[in]  src_buf The source data.
 * @param[in]  src_size The size in bytes of the source data.
 * @param[out]  dest_buf It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the encoded data.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FSCodeTransformationFlateModuleEncode, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

/**
 * @brief FSCodeTransformationFlateModuleEncode2
 * @details Flate module encode. This interface is for internal use only now.
 * @param[in]  src_buf The source data.
 * @param[in]  src_size The size in bytes of the source data.
 * @param[in]  predictor The input predictor.
 * @param[in]  Colors The input colors.
 * @param[in]  BitsPerComponent The input bits per component.
 * @param[in]  Columns The input columns.
 * @param[out]  dest_buf It will receive the encoded data. It must be released by <a>FSCodeTransformationMemFree</a>.
 * @param[out]  dest_size It will receive the size in bytes of the encoded data.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FSCodeTransformationFlateModuleEncode2, (FS_LPCBYTE src_buf,  FS_DWORD src_size,  FS_INT32 predictor,  FS_INT32 Colors,  FS_INT32 BitsPerComponent,  FS_INT32 Columns,  FS_LPBYTE* dest_buf,  FS_DWORD* dest_size))

NumOfSelector(FSCodeTransformation)
ENDENUM

//*****************************
/* FloatRectArray HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSFloatRectArrayNew
 * @details Creates a new empty float rectangle array.
 * @param[in]  void 
 * @return   A new empty float rectangle array.
 * @note 
 */
INTERFACE(FS_FloatRectArray, FSFloatRectArrayNew, (void))

/**
 * @brief FSFloatRectArrayDestroy
 * @details Destroys the float rectangle array.
 * @param[in]  arr The input float rectangle array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayDestroy, (FS_FloatRectArray arr))

/**
 * @brief FSFloatRectArrayGetSize
 * @details Gets the number of elements in the array.
 * @param[in]  arr The input float rectangle array.
 * @return   The number of elements in the array.
 * @note 
 */
INTERFACE(FS_INT32, FSFloatRectArrayGetSize, (FS_FloatRectArray arr))

/**
 * @brief FSFloatRectArrayGetUpperBound
 * @details Gets the upper bound in the array. actually the maximum valid index.
 * @param[in]  arr The input float rectangle array.
 * @return   The upper bound.
 * @note 
 */
INTERFACE(FS_INT32, FSFloatRectArrayGetUpperBound, (FS_FloatRectArray arr))

/**
 * @brief FSFloatRectArraySetSize
 * @details Changes the allocated size and the grow amount.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  nNewSize The new size in elements expected.
 * @param[in]  nGrowBy The grow amount in elements expected, nGrowBy can be -1 for the grow amount unchanged.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArraySetSize, (FS_FloatRectArray arr,  FS_INT32 nNewSize,  FS_INT32 nGrowBy))

/**
 * @brief FSFloatRectArrayRemoveAll
 * @details Cleans up the array.
 * @param[in]  arr The input float rectangle array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayRemoveAll, (FS_FloatRectArray arr))

/**
 * @brief FSFloatRectArrayGetAt
 * @details Retrieves an element specified by an index number.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @return   An element
 * @note 
 */
INTERFACE(FS_FloatRect, FSFloatRectArrayGetAt, (FS_FloatRectArray arr,  FS_INT32 index))

/**
 * @brief FSFloatRectArraySetAt
 * @details Overwrites an element specified by an index number.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  index Specifies the zero-based index of the element.
 * @param[in]  newItem An element
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArraySetAt, (FS_FloatRectArray arr,  FS_INT32 index,  FS_FloatRect newItem))

/**
 * @brief FSFloatRectArraySetAtGrow
 * @details Sets an element value at specified position. Potentially growing the array.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  index Specifies the zero-based index of element in the array.
 * @param[in]  newItem The input element.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArraySetAtGrow, (FS_FloatRectArray arr,  FS_INT32 index,  FS_FloatRect newItem))

/**
 * @brief FSFloatRectArrayAdd
 * @details Adds an element at the tail. Potentially growing the array
 * @param[in]  arr The input float rectangle array.
 * @param[in]  newItem The input element.
 * @return   The added element's index.
 * @note 
 */
INTERFACE(FS_INT32, FSFloatRectArrayAdd, (FS_FloatRectArray arr,  FS_FloatRect newItem))

/**
 * @brief FSFloatRectArrayAppend
 * @details Appends an array.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  srcArr The input array.
 * @return   The old size in elements.
 * @note 
 */
INTERFACE(FS_INT32, FSFloatRectArrayAppend, (FS_FloatRectArray arr,  const FS_FloatRectArray srcArr))

/**
 * @brief FSFloatRectArrayCopy
 * @details Copies from an array.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  srcArr The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayCopy, (FS_FloatRectArray arr,  FS_FloatRectArray srcArr))

/**
 * @brief FSFloatRectArrayInsertAt
 * @details Insets one or more continuous element at specified position.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  newItem Specifies the element value to insert.
 * @param[in]  nCount Specifies the count of the element to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayInsertAt, (FS_FloatRectArray arr,  FS_INT32 index,  FS_FloatRect newItem,  FS_INT32 nCount))

/**
 * @brief FSFloatRectArrayRemoveAt
 * @details Removes a number of elements at specified position.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  index Specifies the zero-based index in the array.
 * @param[in]  nCount Specifies the count of element to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayRemoveAt, (FS_FloatRectArray arr,  FS_INT32 index,  FS_INT32 nCount))

/**
 * @brief FSFloatRectArrayInsertNewArrayAt
 * @details Insets an array at specified position.
 * @param[in]  arr The input float rectangle array.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to insert at.
 * @param[in]  newArray The input array.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFloatRectArrayInsertNewArrayAt, (FS_FloatRectArray arr,  FS_INT32 nStartIndex,  FS_FloatRectArray newArray))

/**
 * @brief FSFloatRectArrayFind
 * @details Finds an element from specified position to last
 * @param[in]  arr The input float rectangle array.
 * @param[in]  item The input element.
 * @param[in]  nStartIndex Specifies the zero-based index of start element to find.
 * @return   An index of the found element. It can be -1 for found none.
 * @note 
 */
INTERFACE(FS_INT32, FSFloatRectArrayFind, (FS_FloatRectArray arr,  FS_FloatRect item,  FS_INT32 nStartIndex))

NumOfSelector(FSFloatRectArray)
ENDENUM

//*****************************
/* BinaryBuf HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSBinaryBufNew
 * @details Creates a new empty binary buffer.
 * @param[in]  void 
 * @return   A new empty binary buffer.
 * @note 
 */
INTERFACE(FS_BinaryBuf, FSBinaryBufNew, (void))

/**
 * @brief FSBinaryBufDestroy
 * @details Destroys the binary buffer.
 * @param[in]  buf The input binary buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufDestroy, (FS_BinaryBuf buf))

/**
 * @brief FSBinaryBufClear
 * @details Sets the binary buffer to be empty.
 * @param[in]  buf The input binary buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufClear, (FS_BinaryBuf buf))

/**
 * @brief FSBinaryBufEstimateSize
 * @details Changes the allocated buffer size, and set the allocation step if <param>allocstep</param> is non-zero.
 * @param[in]  buf The input binary buffer.
 * @param[in]  size The new size expected.
 * @param[in]  allocStep The new allocation step. If <param>allocstep</param> is 0, then the allocation step will not change.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufEstimateSize, (FS_BinaryBuf buf,  FS_StrSize size,  FS_StrSize allocStep))

/**
 * @brief FSBinaryBufAppendBlock
 * @details Appends a binary buffer block.
 * @param[in]  buf The input binary buffer.
 * @param[in]  pBuf A pointer to a binary buffer block.
 * @param[in]  size The size in bytes of the buffer block.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufAppendBlock, (FS_BinaryBuf buf,  void* pBuf,  FS_StrSize size))

/**
 * @brief FSBinaryBufAppendFill
 * @details Appends a byte for specified number times. Not a byte-by-byte processing, but a byte filling processing internally.
 * @param[in]  buf The input binary buffer.
 * @param[in]  byte The input byte.
 * @param[in]  count Number of times.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufAppendFill, (FS_BinaryBuf buf,  FS_BYTE byte,  FS_StrSize count))

/**
 * @brief FSBinaryBufAppendString
 * @details Appends a non-buffered byte string.
 * @param[in]  buf The input binary buffer.
 * @param[in]  str A no-buffered byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufAppendString, (FS_BinaryBuf buf,  FS_CHAR* str))

/**
 * @brief FSBinaryBufAppendByte
 * @details Appends a single byte.
 * @param[in]  buf The input binary buffer.
 * @param[in]  byte A single byte.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufAppendByte, (FS_BinaryBuf buf,  FS_BYTE byte))

/**
 * @brief FSBinaryBufInsertBlock
 * @details Insert a binary buffer block at the specified position.
 * @param[in]  buf The input binary buffer.
 * @param[in]  pos Specifies the zero-based index of the position in the binary buffer.
 * @param[in]  pBuf A pointer to a binary buffer block.
 * @param[in]  size The size in bytes of the buffer block.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufInsertBlock, (FS_BinaryBuf buf,  FS_StrSize pos,  const void* pBuf,  FS_StrSize size))

/**
 * @brief FSBinaryBufAttachData
 * @details Attach to a buffer (this buffer will belong to this object). The buffer must be allocated by FS_Alloc.
 * @param[in]  buf The input binary buffer.
 * @param[in]  pBuf A pointer to a binary buffer.
 * @param[in]  size The size in bytes of the buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufAttachData, (FS_BinaryBuf buf,  void* pBuf,  FS_StrSize size))

/**
 * @brief FSBinaryBufCopyData
 * @details Copies from another buffer.
 * @param[in]  buf The input binary buffer.
 * @param[in]  pBuf The input another buffer.
 * @param[in]  size The size in bytes of the buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufCopyData, (FS_BinaryBuf buf,  const void* pBuf,  FS_StrSize size))

/**
 * @brief FSBinaryBufTakeOver
 * @details Takeover another buffer.
 * @param[in]  buf The input binary buffer.
 * @param[in]  other Another buffer
 * @return   void
 * @note It attaches to the source FS_BinaryBuf object's buffer; The source FS_BinaryBuf object
	*   has detached the buffer.
 */
INTERFACE(void, FSBinaryBufTakeOver, (FS_BinaryBuf buf,  FS_BinaryBuf other))

/**
 * @brief FSBinaryBufDelete
 * @details Delete a inter-zone buffer defining by parameters start_index and count in the binary buffer.
 * @param[in]  buf The input binary buffer.
 * @param[in]  startIndex Specifies the zero-based index of the start position to be deleted in the binary buffer.
 * @param[in]  count Specifies the length in bytes to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufDelete, (FS_BinaryBuf buf,  FS_INT32 startIndex,  FS_INT32 count))

/**
 * @brief FSBinaryBufGetBuffer
 * @details Gets a byte pointer to the binary buffer.
 * @param[in]  buf The input binary buffer.
 * @return   A byte pointer to the binary buffer.
 * @note 
 */
INTERFACE(FS_LPBYTE, FSBinaryBufGetBuffer, (FS_BinaryBuf buf))

/**
 * @brief FSBinaryBufGetSize
 * @details Gets the length of the binary buffer.
 * @param[in]  buf The input binary buffer.
 * @return   The length in bytes of the binary buffer.
 * @note 
 */
INTERFACE(FS_StrSize, FSBinaryBufGetSize, (FS_BinaryBuf buf))

/**
 * @brief FSBinaryBufGetByteString
 * @details Gets a byte string from the buffer.
 * @param[in]  buf The input binary buffer.
 * @param[out]  outString A byte string result.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufGetByteString, (FS_BinaryBuf buf,  FS_ByteString* outString))

/**
 * @brief FSBinaryBufDetachBuffer
 * @details Detachs the buffer. Just set buffer pointer to NULL, and set the binary buffer size to zero.
 * @param[in]  buf The input binary buffer.
 * @return   void
 * @note 
 */
INTERFACE(void, FSBinaryBufDetachBuffer, (FS_BinaryBuf buf))

NumOfSelector(FSBinaryBuf)
ENDENUM

//*****************************
/* PauseHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSPauseHandlerCreate
 * @details Creates the pause handler.
 * @param[in]  pause The input pause handler structure.
 * @return   The newly created pause handler.
 * @note 
 */
INTERFACE(FS_PauseHandler, FSPauseHandlerCreate, (FS_Pause pause))

/**
 * @brief FSPauseHandlerDestroy
 * @details Destroys the pause handler.
 * @param[in]  pauseHandler The input pause handler to be destroyed.
 * @return   void
 * @note 
 */
INTERFACE(void, FSPauseHandlerDestroy, (FS_PauseHandler pauseHandler))

NumOfSelector(FSPauseHandler)
ENDENUM

//*****************************
/* FileReadHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSFileReadHandlerNew
 * @details Creates the file access handler.
 * @param[in]  fileRead The input file read callbacks.
 * @return   The file access interface.
 * @note 
 */
INTERFACE(FS_FileReadHandler, FSFileReadHandlerNew, (FS_FileRead fileRead))

/**
 * @brief FSFileReadHandlerDestroy
 * @details Frees  file read handler.
 * @param[in]  fileReadHander The file access handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FSFileReadHandlerDestroy, (FS_FileReadHandler fileReadHander))

/**
 * @brief FSFileReadHandlerGetSize
 * @details GetS total size of the file.
 * @param[in]  fileReadHander The file access handler.
 * @return   File size, in bytes..
 * @note 
 */
INTERFACE(FS_DWORD, FSFileReadHandlerGetSize, (FS_FileReadHandler fileReadHander))

/**
 * @brief FSFileReadHandlerReadBlock
 * @details Reads a data block from the file.
 * @param[in]  fileReadHander The file access handler.
 * @param[in,out]  buffer Pointer to a buffer receiving read data.
 * @param[in]  offset Byte offset for the block, from beginning of the file.
 * @param[in]  size Number of bytes for the block.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> for failure.
 * @note 
 */
INTERFACE(FS_BOOL, FSFileReadHandlerReadBlock, (FS_FileReadHandler fileReadHander,  void* buffer,  FS_DWORD offset,  FS_DWORD size))

/**
 * @brief FSFileReadHandlerNew2
 * @details Creates the file access handler from file path name.
 * @param[in]  fileRead The input file read callbacks.
 * @return   The file access interface.
 * @note 
 */
INTERFACE(FS_FileReadHandler, FSFileReadHandlerNew2, (FS_LPCSTR filename))

/**
 * @brief FSFileReadHandlerNew3
 * @details Creates the file access handler from file path name(UNICODE).
 * @param[in]  fileRead The input file read callbacks.
 * @return   The file access interface.
 * @note 
 */
INTERFACE(FS_FileReadHandler, FSFileReadHandlerNew3, (FS_LPCWSTR filename))

NumOfSelector(FSFileReadHandler)
ENDENUM

//*****************************
/* StreamWriteHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSStreamWriteHandlerNew
 * @details Creates the stream access handler.
 * @param[in]  streamWrite The input stream write callbacks.
 * @return   The stream access interface.
 * @note 
 */
INTERFACE(FS_StreamWriteHandler, FSStreamWriteHandlerNew, (FS_StreamWrite streamWrite))

/**
 * @brief FSStreamWriteHandlerDestroy
 * @details Frees stream write handler.
 * @param[in]  streamWritehandler The stream access handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FSStreamWriteHandlerDestroy, (FS_StreamWriteHandler streamWritehandler))

/**
 * @brief FSStreamWriteHandlerWriteBlock
 * @details Write a block data.
 * @param[in]  streamWritehandler The stream access handler.
 * @param[in]  pData The block data.
 * @param[in]  size The length in bytes of the block data.
 * @return   <a>TRUE</a> for success, <a>FALSE</a> for failure.
 * @note 
 */
INTERFACE(FS_BOOL, FSStreamWriteHandlerWriteBlock, (FS_StreamWriteHandler streamWritehandler,  const void* pData,  FS_DWORD size))

NumOfSelector(FSStreamWriteHandler)
ENDENUM

//----------_V2----------
//*****************************
/* Base64Encoder HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSBase64EncoderNew
 * @details Creates the Base64 encoder object.
 * @param[in]  wEqual The input character used as a suffix purposes. Sets it <Italic>=</Italic> as default.
 * @return   The Base64 encoder object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderDestroy
 */
INTERFACE(FS_Base64Encoder, FSBase64EncoderNew, (FS_WCHAR wEqual))

/**
 * @brief FSBase64EncoderDestroy
 * @details Destroys the input Base64 encoder object.
 * @param[in]  encoder The input Base64 encoder object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderNew
 */
INTERFACE(void, FSBase64EncoderDestroy, (FS_Base64Encoder encoder))

/**
 * @brief FSBase64EncoderSetEncoder
 * @details Sets external Base64 encoder.
 * @param[in]  encoder The input Base64 encoder object.
 * @param[in]  pEncodeProc Callback function address to provide an external encoder. Sets it as NULL if need use default Base64 encoder.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderNew
 */
INTERFACE(void, FSBase64EncoderSetEncoder, (FS_Base64Encoder encoder,  FS_LPBase64EncodeProc* pEncodeProc))

/**
 * @brief FSBase64EncoderEncode
 * @details Encodes byte data array into a wide character array.
 * @param[in]  encoder The input Base64 encoder object.
 * @param[in]  pSrc Source byte data array to encode.
 * @param[in]  iSrcLen The length of source byte array, in bytes.
 * @param[out]  pDst Destination pointer of wide character array.
 * @return   Returns the length of total data stored in destination buffer, in wide characters. If <param>pDst</param> is a NULL pointer, it returns the necessary buffer size in wide characters.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderNew
 */
INTERFACE(FS_INT32, FSBase64EncoderEncode, (FS_Base64Encoder encoder,  FS_LPCBYTE pSrc,  FS_INT32 iSrcLen,  FS_LPWSTR pDst))

/**
 * @brief FSBase64EncoderEncode2
 * @details Encodes byte string into a wide string.
 * @param[in]  encoder The input Base64 encoder object.
 * @param[in]  src Source byte string to encode.
 * @param[out]  out_Dst Destination wide string to store encoded data. Creates it by <a>FSWideStringNew</a>.
 * @return   Returns the length of total data stored in destination, in wide characters.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderNew
 */
INTERFACE(FS_INT32, FSBase64EncoderEncode2, (FS_Base64Encoder encoder,  const FS_ByteString src,  FS_WideString* out_Dst))

/**
 * @brief FSBase64EncoderEncode3
 * @details Encodes byte string into a UTF-8 byte string.
 * @param[in]  encoder The input Base64 encoder object.
 * @param[in]  src Source byte string to encode.
 * @param[out]  out_Dst Destination byte string to store encoded data. Creates it by <a>FSByteStringNew</a>.
 * @return   Returns the length of total data stored in destination, in bytes.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64EncoderNew
 */
INTERFACE(FS_INT32, FSBase64EncoderEncode3, (FS_Base64Encoder encoder,  const FS_ByteString src,  FS_ByteString* out_Dst))

NumOfSelector(FSBase64Encoder)
ENDENUM

//*****************************
/* Base64Decoder HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSBase64DecoderNew
 * @details Creates the Base64 decoder object.
 * @param[in]  wEqual The input character used as a suffix purposes. Sets it <Italic>=</Italic> as default.
 * @return   The Base64 decoder object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderDestroy
 */
INTERFACE(FS_Base64Decoder, FSBase64DecoderNew, (FS_WCHAR wEqual))

/**
 * @brief FSBase64DecoderDestroy
 * @details Destroys the input Base64 decoder object.
 * @param[in]  decoder The input Base64 decoder object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderNew
 */
INTERFACE(void, FSBase64DecoderDestroy, (FS_Base64Decoder decoder))

/**
 * @brief FSBase64DecoderSetDecoder
 * @details Sets external Base64 decoder.
 * @param[in]  decoder The input Base64 decoder object.
 * @param[in]  pDecodeProc Callback function address to provide an external decoder. Sets it as NULL if need use default Base64 decoder.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderNew
 */
INTERFACE(void, FSBase64DecoderSetDecoder, (FS_Base64Decoder decoder,  FS_LPBase64DecodeProc pDecodeProc))

/**
 * @brief FSBase64DecoderDecode
 * @details Decodes wide character array into byte buffer.
 * @param[in]  decoder The input Base64 decoder object.
 * @param[in]  pSrc Source wide character array to decode.
 * @param[in]  iSrcLen The length of source wide character array, in wide characters.
 * @param[out]  pDst Destination pointer of byte data array.
 * @return   Returns the length of total data stored in destination buffer, in bytes. If <param>pDst</param> is a NULL pointer, it returns the necessary buffer size in bytes.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderNew
 */
INTERFACE(FS_INT32, FSBase64DecoderDecode, (FS_Base64Decoder decoder,  FS_LPCWSTR pSrc,  FS_INT32 iSrcLen,  FS_LPBYTE pDst))

/**
 * @brief FSBase64DecoderDecode2
 * @details Decodes wide string into a byte string.
 * @param[in]  decoder The input Base64 decoder object.
 * @param[in]  src Source wide character string to decode.
 * @param[out]  out_Dst Destination byte string to store decoded data.
 * @return   Returns the length of total data stored in destination, in bytes.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderNew
 */
INTERFACE(FS_INT32, FSBase64DecoderDecode2, (FS_Base64Decoder decoder,  const FS_WideString src,  FS_ByteString* out_Dst))

/**
 * @brief FSBase64DecoderDecode3
 * @details Decodes UTF-8 byte string into a byte string.
 * @param[in]  decoder The input Base64 decoder object.
 * @param[in]  src Source UTF-8 byte string to decode.
 * @param[out]  out_Dst Destination byte string to store decoded data.
 * @return   Returns the length of total data stored in destination, in bytes.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSBase64DecoderNew
 */
INTERFACE(FS_INT32, FSBase64DecoderDecode3, (FS_Base64Decoder decoder,  const FS_ByteString src,  FS_ByteString* out_Dst))

NumOfSelector(FSBase64Decoder)
ENDENUM

//*****************************
/* FileWriteHandler HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSFileWriteHandlerNew
 * @details Creates the file access handler for writing.
 * @param[in]  fileWrite The input file write callbacks.
 * @return   The file access interface for writing.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSFileWriteHandlerDestroy
 */
INTERFACE(FS_FileWriteHandler, FSFileWriteHandlerNew, (FS_FileWrite fileWrite))

/**
 * @brief FSFileWriteHandlerDestroy
 * @details Destroys the input file write handler.
 * @param[in]  handler The input file write handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSFileWriteHandlerNew
 */
INTERFACE(void, FSFileWriteHandlerDestroy, (FS_FileWriteHandler handler))

NumOfSelector(FSFileWriteHandler)
ENDENUM

//*****************************
/* XMLElement HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSXMLElementparse
 * @details Constructs an XML element using data in specified buffer.
	* The buffer can be discarded immediately after construction finished, because at this time,
	* all data have been loaded into the element (and its descendant element).
 * @param[in]  pBuffer The input buffer.
 * @param[in]  size The size in bytes of the input buffer.
 * @param[in]  bSaveSpaceChars Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
 * @param[out]  pParsedSize It receives the parsed size. Sets it NULL as default if you don't want to receive it.
 * @return   The XML element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementparse2
 */
INTERFACE(FS_XMLElement, FSXMLElementparse, (const void* pBuffer,  FS_DWORD size,  FS_BOOL bSaveSpaceChars,  FS_DWORD* pParsedSize))

/**
 * @brief FSXMLElementparse2
 * @details Parses XML contents from a <a>FS_FileReadHandler</a> object.
	* The <a>FS_FileReadHandler</a> object can be discarded immediately after construction finished, because at this time,
	* all data have been loaded into the element (and its descendant element).
 * @param[in]  fileReadHander The input file access object. Creates it by <a>FSFileReadHandlerNew</a>.
 * @param[in]  bSaveSpaceChars Indicates whether need save space characters in content string, TRUE if save, or FALSE. Sets it FALSE as default.
 * @param[out]  pParsedSize It receives the parsed size. Sets it NULL as default if you don't want to receive it.
 * @return   The XML element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementparse
 */
INTERFACE(FS_XMLElement, FSXMLElementparse2, (FS_FileReadHandler fileReadHander,  FS_BOOL bSaveSpaceChars,  FS_DWORD* pParsedSize))

/**
 * @brief FSXMLElementNew
 * @details Creates an empty XML element, with a qualified namespace and tag name.
 * @param[in]  qSpace Qualified namespace, or empty if no namespace or default namespace is used.
 * @param[in]  tagName The input tag name.
 * @return   An empty XML element, with a qualified namespace and tag name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementDestroy
 */
INTERFACE(FS_XMLElement, FSXMLElementNew, (FS_LPCSTR qSpace,  FS_LPCSTR tagName))

/**
 * @brief FSXMLElementNew2
 * @details Creates an empty element, with qualified tag name.
 * @param[in]  tagName Qualified tag name.
 * @return   An empty element, with qualified tag name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementDestroy
 */
INTERFACE(FS_XMLElement, FSXMLElementNew2, (FS_LPCSTR tagName))

/**
 * @brief FSXMLElementNew3
 * @details Creates an empty element.
 * @return   An empty element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementDestroy
 */
INTERFACE(FS_XMLElement, FSXMLElementNew3, ())

/**
 * @brief FSXMLElementDestroy
 * @details Destroys the input XML element.
 * @param[in]  XMLElement The input XML element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementNew
 * @see FSXMLElementNew2
 * @see FSXMLElementNew3
 */
INTERFACE(void, FSXMLElementDestroy, (FS_XMLElement XMLElement))

/**
 * @brief FSXMLElementGetTagName
 * @details Gets the tag name of the XML element.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  bQualified Indicates whether return a qualified tag name or not.
 * @param[out]  outTagName It receives the tag name. If <param>bQualified</param> is TRUE, the tag name is with qualified namespace, or only local tag name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementNew
 */
INTERFACE(void, FSXMLElementGetTagName, (FS_XMLElement XMLElement,  FS_BOOL bQualified,  FS_ByteString* outTagName))

/**
 * @brief FSXMLElementGetNamespace
 * @details Gets the namespace of the XML element.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  bQualified Indicates whether return a qualified namespace or full URI namespace.
 * @param[out]  outNamespace It receives the name space. If <param>bQualified</param> is TRUE, returns qualified namespace value, or full URI value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementNew
 */
INTERFACE(void, FSXMLElementGetNamespace, (FS_XMLElement XMLElement,  FS_BOOL bQualified,  FS_ByteString* outNamespace))

/**
 * @brief FSXMLElementGetNamespaceURI
 * @details Gets the full URI value for a qualified namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name Qualified namespace.
 * @param[out]  outNamespaceURI It receives the full URI value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetNamespace
 */
INTERFACE(void, FSXMLElementGetNamespaceURI, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_ByteString* outNamespaceURI))

/**
 * @brief FSXMLElementGetParent
 * @details Gets the parent element of the input XML element.
 * @param[in]  XMLElement The input XML element.
 * @return   The parent XML element of the input XML element..
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountChildren
 */
INTERFACE(FS_XMLElement, FSXMLElementGetParent, (FS_XMLElement XMLElement))

/**
 * @brief FSXMLElementCountAttrs
 * @details Gets the count of attributes of the input XML element.
 * @param[in]  XMLElement The input XML element.
 * @return   The count of attributes of the input XML element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrByIndex
 */
INTERFACE(FS_DWORD, FSXMLElementCountAttrs, (FS_XMLElement XMLElement))

/**
 * @brief FSXMLElementGetAttrByIndex
 * @details Gets the attribute by index.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Index of the attribute (start from 0).
 * @param[out]  space It receives the qualified namespace of attribute name.
 * @param[out]  name It receives the attribute name (local name).
 * @param[out]  value It receive the attribute value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountAttrs
 */
INTERFACE(void, FSXMLElementGetAttrByIndex, (FS_XMLElement XMLElement,  FS_INT32 index,  FS_ByteString* space,  FS_ByteString* name,  FS_WideString* value))

/**
 * @brief FSXMLElementHasAttr
 * @details Determines whether a qualified attribute exists or not.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  qName The input qualified attribute name.
 * @return   <a>TRUE</a> if attribute exists, <a>FALSE</a> if doesn't exist.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountAttrs
 * @see FSXMLElementGetAttrByIndex
 */
INTERFACE(FS_BOOL, FSXMLElementHasAttr, (FS_XMLElement XMLElement,  FS_LPCSTR qName))

/**
 * @brief FSXMLElementGetAttrValue
 * @details Gets attribute value without a namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[out]  attribute It receive the attribute value.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementHasAttr
 * @see FSXMLElementGetAttrValue2
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrValue, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_WideString* attribute))

/**
 * @brief FSXMLElementGetAttrValue2
 * @details Gets attribute value. Encoded in UTF-16LE format.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  name The qualified attribute name.
 * @param[out]  attribute It receive the attribute value, A UTF-16LE wide string.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrValue
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrValue2, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR name,  FS_WideString* attribute))

/**
 * @brief FSXMLElementGetAttrInteger
 * @details Gets an integer from a particular attribute without a namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[out]  attribute It receives the attribute value, a integer value.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrInteger2
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrInteger, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_INT32* attribute))

/**
 * @brief FSXMLElementGetAttrInteger2
 * @details Gets an integer from a particular attribute, using a namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  name The local name for the attribute.
 * @param[out]  attribute It receives the attribute value, a integer value.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrInteger
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrInteger2, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR name,  FS_INT32* attribute))

/**
 * @brief FSXMLElementGetAttrFloat
 * @details Gets a float from a particular attribute without a namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[out]  attribute It receives the attribute value, a float value.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrFloat2
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrFloat, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_FLOAT* attribute))

/**
 * @brief FSXMLElementGetAttrFloat2
 * @details Gets an float from a particular attribute, using a namespace.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  name The local name for the attribute.
 * @param[out]  attribute It receives the attribute value, a float value.
 * @return   Whether the attribute exists or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrFloat
 */
INTERFACE(FS_BOOL, FSXMLElementGetAttrFloat2, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR name,  FS_FLOAT* attribute))

/**
 * @brief FSXMLElementCountChildren
 * @details Gets the number of children of this element, including content segments and sub-elements.
 * @param[in]  XMLElement The input XML element.
 * @return   The number of children.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetChildType
 */
INTERFACE(FS_DWORD, FSXMLElementCountChildren, (FS_XMLElement XMLElement))

/**
 * @brief FSXMLElementGetChildType
 * @details Gets the type of a child, it can be either a content segment, or a sub-element.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index in children array.
 * @return   The type of specified child.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountChildren
 */
INTERFACE(FS_Child_Type, FSXMLElementGetChildType, (FS_XMLElement XMLElement,  FS_DWORD index))

/**
 * @brief FSXMLElementGetContent
 * @details Gets a content segment. If this child is an element, <param>outContent</param> will receive nothing.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index in children array.
 * @param[out]  outContent It receives the content.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetChildType
 */
INTERFACE(void, FSXMLElementGetContent, (FS_XMLElement XMLElement,  FS_DWORD index,  FS_WideString* outContent))

/**
 * @brief FSXMLElementGetElement
 * @details Gets a particular child element. If this child is not an element, NULL will be returned.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index in children array.
 * @return   A child element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetChildType
 * @see FSXMLElementGetElement2
 */
INTERFACE(FS_XMLElement, FSXMLElementGetElement, (FS_XMLElement XMLElement,  FS_DWORD index))

/**
 * @brief FSXMLElementGetElement2
 * @details Gets an element with particular tag. If more than one element with the same tag, only the first one is returned.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  tag The local name for the tag.
 * @return   An element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetElement
 */
INTERFACE(FS_XMLElement, FSXMLElementGetElement2, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR tag))

/**
 * @brief FSXMLElementGetElement3
 * @details Gets an element with particular tag, and specified index if more than one elements with the same tag.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  tag The input tag.
 * @param[in]  index Specifies the zero-based index of element with particular tag.
 * @return   An element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetElement
 * @see FSXMLElementGetElement2
 */
INTERFACE(FS_XMLElement, FSXMLElementGetElement3, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR tag,  FS_INT32 index))

/**
 * @brief FSXMLElementCountElements
 * @details Counts number of elements with particular tag.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  space The qualified namespace.
 * @param[in]  tag The local name for the tag.
 * @return   The count number of elements with the input tag.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetElement
 * @see FSXMLElementGetElement2
 * @see FSXMLElementGetElement3
 */
INTERFACE(FS_DWORD, FSXMLElementCountElements, (FS_XMLElement XMLElement,  FS_LPCSTR space,  FS_LPCSTR tag))

/**
 * @brief FSXMLElementFindElement
 * @details Finds an element and returns its index.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  pChild The input child element.
 * @return   The index number of child element, -1 if not found.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountElements
 */
INTERFACE(FS_DWORD, FSXMLElementFindElement, (FS_XMLElement XMLElement,  FS_XMLElement pChild))

/**
 * @brief FSXMLElementSetTag
 * @details Sets the tag name of the element.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  qSpace The qualified namespace for the tag.
 * @param[in]  tagname The input tag name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetTagName
 */
INTERFACE(void, FSXMLElementSetTag, (FS_XMLElement XMLElement,  FS_LPCSTR qSpace,  FS_LPCSTR tagname))

/**
 * @brief FSXMLElementSetTag2
 * @details Sets the tag name of the element.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  qTagName The input tag name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetTagName
 * @see FSXMLElementSetTag
 */
INTERFACE(void, FSXMLElementSetTag2, (FS_XMLElement XMLElement,  FS_LPCSTR qTagName))

/**
 * @brief FSXMLElementSetAttrValue
 * @details Sets attribute with a wide string.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[in]  value The input wide string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrValue
 */
INTERFACE(void, FSXMLElementSetAttrValue, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_WideString value))

/**
 * @brief FSXMLElementSetAttrValue2
 * @details Sets attribute with an integer.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[in]  value The input integer.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrInteger
 */
INTERFACE(void, FSXMLElementSetAttrValue2, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_INT32 value))

/**
 * @brief FSXMLElementSetAttrValue3
 * @details Sets attribute with a float.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @param[in]  value The input float.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementGetAttrFloat
 * @see FSXMLElementGetAttrFloat2
 */
INTERFACE(void, FSXMLElementSetAttrValue3, (FS_XMLElement XMLElement,  FS_LPCSTR name,  FS_FLOAT value))

/**
 * @brief FSXMLElementRemoveAttr
 * @details Removes an attribute.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  name The qualified attribute name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FSXMLElementRemoveAttr, (FS_XMLElement XMLElement,  FS_LPCSTR name))

/**
 * @brief FSXMLElementAddChildElement
 * @details Adds an element to the child list (at the last position).
 * @param[in]  XMLElement The input XML element.
 * @param[in]  pElement The input element.
 * @return   void
 * @note The child element can't be directly destroyed any more.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountChildren
 */
INTERFACE(void, FSXMLElementAddChildElement, (FS_XMLElement XMLElement,  FS_XMLElement pElement))

/**
 * @brief FSXMLElementAddChildContent
 * @details Adds a content child.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  content The input content.
 * @param[in]  bCDATA Whether the content is CDATA or not. Sets it <a>FALSE</a> as default.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementCountChildren
 * @see FSXMLElementAddChildElement
 */
INTERFACE(void, FSXMLElementAddChildContent, (FS_XMLElement XMLElement,  FS_WideString content,  FS_BOOL bCDATA))

/**
 * @brief FSXMLElementInsertChildElement
 * @details Inserts a child element before the specified index
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index of element in the child array.
 * @param[in]  pElement The input element.
 * @return   void
 * @note The child element can't be directly destroyed any more.
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementAddChildElement
 */
INTERFACE(void, FSXMLElementInsertChildElement, (FS_XMLElement XMLElement,  FS_DWORD index,  FS_XMLElement pElement))

/**
 * @brief FSXMLElementInsertChildContent
 * @details Inserts a content segment before the specified index.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index of element in the child array.
 * @param[in]  content The input content.
 * @param[in]  bCDATA Whether the content is CDATA or not. Sets it <a>FALSE</a> as default.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementAddChildContent
 */
INTERFACE(void, FSXMLElementInsertChildContent, (FS_XMLElement XMLElement,  FS_DWORD index,  FS_WideString content,  FS_BOOL bCDATA))

/**
 * @brief FSXMLElementRemoveChildren
 * @details Remove all children.
 * @param[in]  XMLElement The input XML element.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementRemoveChild
 */
INTERFACE(void, FSXMLElementRemoveChildren, (FS_XMLElement XMLElement))

/**
 * @brief FSXMLElementRemoveChild
 * @details Removes a specified child item (element or content).
 * @param[in]  XMLElement The input XML element.
 * @param[in]  index Specifies the zero-based index of element in the child array.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementRemoveChildren
 */
INTERFACE(void, FSXMLElementRemoveChild, (FS_XMLElement XMLElement,  FS_DWORD index))

/**
 * @brief FSXMLElementOutputStream
 * @details Outputs to a XML stream.
 * @param[in]  XMLElement The input XML element.
 * @param[out]  output It receives the XML stream.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementOutputStream2
 */
INTERFACE(void, FSXMLElementOutputStream, (FS_XMLElement XMLElement,  FS_ByteString* output))

/**
 * @brief FSXMLElementOutputStream2
 * @details Outputs through the file write handler.
 * @param[in]  XMLElement The input XML element.
 * @param[in]  handler The input file write handler. Creates it by <a>FSFileWriteHandlerNew</a>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FSXMLElementOutputStream
 */
INTERFACE(void, FSXMLElementOutputStream2, (FS_XMLElement XMLElement,  FS_FileWriteHandler handler))

/**
 * @brief FSXMLElementClone
 * @details Clones the specified XML element.
 * @param[in]  XMLElement The input XML element.
 * @return   The cloned XML element.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 * @see FSXMLElementparse2
 */
INTERFACE(FS_XMLElement, FSXMLElementClone, (FS_XMLElement XMLElement))

NumOfSelector(FSXMLElement)
ENDENUM

//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* UTF8Decoder HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSUTF8DecoderNew
 * @details Creates a new UTF8 decoder object.
 * @param[in]  void 
 * @return   The UTF8 decoder object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_UTF8Decoder, FSUTF8DecoderNew, (void))

/**
 * @brief FSUTF8DecoderDestroy
 * @details Destroys the UTF8 decoder object.
 * @param[in]  decoder The input UTF8 decoder.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderDestroy, (FS_UTF8Decoder decoder))

/**
 * @brief FSUTF8DecoderClear
 * @details Clears the decoding status and sets the output wide text buffer to be empty.
 * @param[in]  decoder The input UTF8 decoder.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderClear, (FS_UTF8Decoder decoder))

/**
 * @brief FSUTF8DecoderInput
 * @details Inputs a byte.
 * @param[in]  decoder The input UTF8 decoder.
 * @param[in]  byte The input byte.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderInput, (FS_UTF8Decoder decoder,  FS_BYTE byte))

/**
 * @brief FSUTF8DecoderAppendChar
 * @details Appends characters to wide text buffer.
 * @param[in]  decoder The input UTF8 decoder.
 * @param[in]  ch The input character.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderAppendChar, (FS_UTF8Decoder decoder,  FS_DWORD ch))

/**
 * @brief FSUTF8DecoderClearStatus
 * @details Clears the decoding status.
 * @param[in]  decoder The input UTF8 decoder.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderClearStatus, (FS_UTF8Decoder decoder))

/**
 * @brief FSUTF8DecoderGetResult
 * @details Gets the result.
 * @param[in]  decoder The input UTF8 decoder.
 * @param[out]  outResult It receives the result.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8DecoderGetResult, (FS_UTF8Decoder decoder,  FS_WideString* outResult))

NumOfSelector(FSUTF8Decoder)
ENDENUM

//*****************************
/* UTF8Encoder HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSUTF8EncoderNew
 * @details Creates a new UTF8 encoder object.
 * @param[in]  void 
 * @return   The UTF8 encoder object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_UTF8Encoder, FSUTF8EncoderNew, (void))

/**
 * @brief FSUTF8EncoderDestroy
 * @details Destroys the UTF8 encoder object.
 * @param[in]  encoder The input UTF8 encoder.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8EncoderDestroy, (FS_UTF8Encoder encoder))

/**
 * @brief FSUTF8EncoderInput
 * @details Inputs a unicode.
 * @param[in]  encoder The input UTF8 encoder.
 * @param[in]  unicode The input unicode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8EncoderInput, (FS_UTF8Encoder encoder,  FS_WCHAR unicode))

/**
 * @brief FSUTF8EncoderAppendStr
 * @details Appends a non-buffered byte string.
 * @param[in]  encoder The input UTF8 encoder.
 * @param[in]  str A non-buffered byte string.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8EncoderAppendStr, (FS_UTF8Encoder encoder,  FS_ByteString str))

/**
 * @brief FSUTF8EncoderGetResult
 * @details Gets the result.
 * @param[in]  encoder The input UTF8 encoder.
 * @param[out]  str It receives the result.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FSUTF8EncoderGetResult, (FS_UTF8Encoder encoder,  FS_ByteString* outResult))

/**
 * @brief FSUTF8EncoderIsUTF8Data
 * @details Checks whether a data buffer is UTF-8 encoded or not.
 * @param[in]  pData The pointer to the data buffer.
 * @param[in,out]  pLen The pointer to the length of the data buffer, in bytes. When this function returns, it stores the number of bytes scanned.
 * @return   TRUE if all data is UTF-8 encoded, FALSE if the data is not UTF-8 format..
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FSUTF8EncoderIsUTF8Data, (FS_LPCBYTE pData,  FS_INT32* pLen))

NumOfSelector(FSUTF8Encoder)
ENDENUM

//----------_V6----------
//*****************************
/* FileStream HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSFileStreamNew
 * @details Creates the file stream object.
 * @param[in]  callbacks The input callback set for file stream reading and writing.
 * @return   The file stream object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_FileStream, FSFileStreamNew, (FS_FileStreamCallbacks callbacks))

/**
 * @brief FSFileStreamNew2
 * @details Creates the file stream object.
 * @param[in]  filename The input file path.
 * @param[in]  dwModes The input file mode. See the definition of FSFileMode.
 * @param[in]  reserved It is a reserved parameter. Must set it as NULL.
 * @return   The file stream object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(FS_FileStream, FSFileStreamNew2, (FS_LPCWSTR filename,  FS_DWORD dwModes,  void* reserved))

/**
 * @brief FSFileStreamDestroy
 * @details Destroys the file stream object.
 * @param[in]  fileStream The input file stream object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 */
INTERFACE(void, FSFileStreamDestroy, (FS_FileStream fileStream))

NumOfSelector(FSFileStream)
ENDENUM

//----------_V7----------
//*****************************
/* GUID HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSGUIDCreate
 * @details Creates a GUID, version 4.
 * @param[out]  pGUID Pointer to store the returned GUID value, cannot be NULL.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FSGUIDCreate, (FS_LPGUID pGUID))

/**
 * @brief FSGUIDToString
 * @details FormatS GUID to a string.
 * @param[in]  pGUID Pointer to a valid GUID value, cannot be NULL.
 * @param[out]  outStr It receives the GUID string.
 * @param[in]  bSeparator If TRUE, GUID string will include '-' separating characters.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FSGUIDToString, (FS_LPGUID pGUID,  FS_ByteString* outStr,  FS_BOOL bSeparator))

NumOfSelector(FSGUID)
ENDENUM

//----------_V8----------
//----------_V9----------
//*****************************
/* UUID HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSUUIDGenerate
 * @details Generates a UUID.
 * @param[out]  outID It receives the ID.
 * @param[in]  userData The input user data.
 * @param[in,out]  outLastState It receives the last state of the ID.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDGenerate, (FS_ByteString* outID,  FS_INT32 userData,  FS_ByteString* outLastState))

/**
 * @brief FSUUIDGenerateTime
 * @details Generates a UUID constructed by time.
 * @param[out]  outID It receives the ID.
 * @param[in]  userData The input user data.
 * @param[in,out]  outLastState It receives the last state of the ID.
 * @param[in]  bOnlyUid Whether generates the ID only or not.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDGenerateTime, (FS_ByteString* outID,  FS_INT32 userData,  FS_ByteString* outLastState,  FS_BOOL bOnlyUid))

/**
 * @brief FSUUIDGenerateRandom
 * @details Generates a UUID randomly.
 * @param[out]  outID It receives the ID.
 * @param[in]  userData The input user data.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDGenerateRandom, (FS_ByteString* outID,  FS_INT32 userData))

/**
 * @brief FSUUIDSetTsPath
 * @details Sets the Ts path.
 * @param[in]  bsTsPath The input Ts path.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDSetTsPath, (FS_ByteString bsTsPath))

/**
 * @brief FSUUIDSetState
 * @details Sets the last state.
 * @param[in]  bsLastState The input last state.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDSetState, (FS_ByteString bsLastState))

/**
 * @brief FSUUIDSetUserData
 * @details Sets the user data.
 * @param[in]  bsUserData The input user data.
 * @return   The type of the UUID. See the definition of <a>FSUUIDType</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_INT32, FSUUIDSetUserData, (FS_ByteString bsUserData))

NumOfSelector(FSUUID)
ENDENUM

//*****************************
/* MapByteStringToPtr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FSMapByteStringToPtrNew
 * @details Creates an empty bytestring-to-ptr map with specified block size.
 * @param[in]  nBlockSize The internal block. Sets it 10 as default.
 * @return   An empty bytestring-to-ptr map.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_MapByteStringToPtr, FSMapByteStringToPtrNew, (FS_INT32 nBlockSize))

/**
 * @brief FSMapByteStringToPtrDestroy
 * @details Destroys the bytestring-to-ptr map.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSMapByteStringToPtrDestroy, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrGetCount
 * @details Gets the number of elements.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   The number of elements in the map.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_INT32, FSMapByteStringToPtrGetCount, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrIsEmpty
 * @details Tests whether the <param>map</param> is empty.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   <a>TRUE</a> for map being empty. <a>FALSE</a> otherwise.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FSMapByteStringToPtrIsEmpty, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrLookup
 * @details Looks up by a key.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in]  key The key to lookup.
 * @param[out]  outValue A ref of a typeless pointer to receive the found value.
 * @return   <a>TRUE</a> for value being found. <a>FALSE</a> otherwise.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FSMapByteStringToPtrLookup, (FS_MapByteStringToPtr map,  FS_ByteString key,  void** outValue))

/**
 * @brief FSMapByteStringToPtrSetAt
 * @details Adds a new (key, value) pair. Adds if not exist, otherwise modify.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in]  key The key to specify a position.
 * @param[in]  newValue The new value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSMapByteStringToPtrSetAt, (FS_MapByteStringToPtr map,  FS_ByteString key,  void* newValue))

/**
 * @brief FSMapByteStringToPtrRemoveKey
 * @details Removes existing (key, value) pair.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in]  key The key to remove.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FSMapByteStringToPtrRemoveKey, (FS_MapByteStringToPtr map,  FS_ByteString key))

/**
 * @brief FSMapByteStringToPtrRemoveAll
 * @details Removes all the (key, value) pairs in the map.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSMapByteStringToPtrRemoveAll, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrGetStartPosition
 * @details Gets the first key-value pair position, iterating all (key, value) pairs.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   The first key-value pair position in the map
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_POSITION, FSMapByteStringToPtrGetStartPosition, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrGetNextAssoc
 * @details Gets the current association and sets the position to next association.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in,out]  inOutNextPosition Input a position, and receive the next association position.
 * @param[out]  outKey (Filled by this method)Receive a key.
 * @param[out]  outValue (Filled by this method)Receive a value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSMapByteStringToPtrGetNextAssoc, (FS_MapByteStringToPtr map,  FS_POSITION* inOutNextPosition,  FS_ByteString* outKey,  void** outValue))

/**
 * @brief FSMapByteStringToPtrGetNextValue
 * @details Gets the current value and sets the position to next association.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in,out]  inOutNextPosition Input a position, and receive the next association position.
 * @return   The value.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_LPVOID, FSMapByteStringToPtrGetNextValue, (FS_MapByteStringToPtr map,  FS_POSITION* inOutNextPosition))

/**
 * @brief FSMapByteStringToPtrGetHashTableSize
 * @details Gets the internal hash table size. Advanced features for derived classes.
 * @param[in]  map The input bytestring-to-ptr map.
 * @return   The hash table size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_DWORD, FSMapByteStringToPtrGetHashTableSize, (FS_MapByteStringToPtr map))

/**
 * @brief FSMapByteStringToPtrInitHashTable
 * @details Initializes the hash table.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in]  hashSize Initializes the hash table size.
 * @param[in]  bAllocNow Does it Now allocate the hash table? No-zero means yes, otherwise not. Sets it TRUE as default.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FSMapByteStringToPtrInitHashTable, (FS_MapByteStringToPtr map,  FS_DWORD hashSize,  FS_BOOL bAllocNow))

/**
 * @brief FSMapByteStringToPtrHashKey
 * @details Routine used to user-provided hash keys.
 * @param[in]  map The input bytestring-to-ptr map.
 * @param[in]  key The key used to produce the hash key.
 * @return   A hash value.
 * @note Overwrite-able: special non-virtual (see map implementation for details).
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_DWORD, FSMapByteStringToPtrHashKey, (FS_MapByteStringToPtr map,  FS_ByteString key))

NumOfSelector(FSMapByteStringToPtr)
ENDENUM

//----------_V10----------
