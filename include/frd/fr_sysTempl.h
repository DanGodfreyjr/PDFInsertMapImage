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
/* Sys HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSysLoadStandarCursor
 * @details Loads a standard cursor by type.
 * @param[in]  nCursorType The type of the cursor. See <a>FRCursorTypeFlags</a>.
 * @return   The specified cursor loaded.
 * @note 
 * @see FRSysSetCursor
 * @see FRSysGetCursor
 */
INTERFACE(FR_Cursor, FRSysLoadStandarCursor, (FS_INT32 nCursorType))

/**
 * @brief FRSysGetCursor
 * @details Gets the current cursor.
 * @return   The current cursor.
 * @note 
 * @see FRSysSetCursor
 * @see FRSysLoadStandarCursor
 */
INTERFACE(FR_Cursor, FRSysGetCursor, (void))

/**
 * @brief FRSysSetCursor
 * @details Sets the current cursor.
 * @param[in]  cursor The input cursor to be set.
 * @return   void
 * @note 
 * @see FRSysGetCursor
 * @see FRSysLoadStandarCursor
 */
INTERFACE(void, FRSysSetCursor, (FR_Cursor cursor))

/**
 * @brief FRSysShowMessageBox
 * @details Creates, displays, and operates a message box. The message box contains an application-defined message 
	* and title, plus any combination of predefined icons and push buttons.
 * @param[in]  wszPrompt Pointer to a null-terminated string that contains the message to be displayed.
 * @param[in]  nType Specifies the contents and behavior of the dialog box. See the description about <Italic>MessageBox</Italic> from MSDN.
 * @param[in]  wszCaption Pointer to a null-terminated string that contains the dialog box title. If this parameter is NULL, the default title is used.
 * @param[in]  pCheckBoxParams Pointer to a data structure representing the params of the check box on the message box. If this parameter is NULL, the default value is used.
 * @param[in]  hParent The parent window.
 * @return   See the description about <Italic>MessageBox</Italic> from <Italic>MSDN</Italic>.
 * @note 
 */
INTERFACE(FS_INT32, FRSysShowMessageBox, (FS_LPCWSTR wszPrompt,  unsigned int nType,  FS_LPCWSTR wszCaption,  FR_MSGBOX_CHECKBOXPARAMS* pCheckBoxParams,  HWND hParent))

/**
 * @brief FRSysInstallDialogSkinTheme
 * @details The dialog can install the skin theme of <Italic>Foxit Reader</Italic> to keep the same.
	* Invokes this interface in the <Italic>CReader_Dialog::OnInitDialog</Italic> routine of the dialog.
 * @param[in]  hWnd The dialog to install skin theme of <Italic>Foxit Reader</Italic>.
 * @return   <a>True</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRSysInstallDialogSkinTheme, (HWND hWnd))

/**
 * @brief FRSysInstallDialogScrollBar
 * @details Installs the dialog scroll bar.
 * @param[in]  hWnd The dialog to install the scroll bar.
 * @return   <a>True</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysInstallDialogScrollBar, (HWND hWnd))

/**
 * @brief FRSysGetSkinCount
 * @details Gets the count of skins for Foxit Reader.
 * @return   The count of skins for Foxit Reader.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_INT32, FRSysGetSkinCount, ())

/**
 * @brief FRSysGetSkinNameByIndex
 * @details Gets the skin name by index.
 * @param[in]  nIndex The input index.
 * @param[out]  outName It receives the name of the skin.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(void, FRSysGetSkinNameByIndex, (FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRSysSetActiveSkinByIndex
 * @details Sets the active skin by index.
 * @param[in]  nIndex The input index.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysSetActiveSkinByIndex, (FS_INT32 nIndex))

/**
 * @brief FRSysSetActiveSkinByName
 * @details Sets the active skin by name.
 * @param[in]  nIndex The input name of the skin.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.0.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSysSetActiveSkinByName, (FS_LPCWSTR lpwsName))

NumOfSelector(FRSys)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* WindowsDIB HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRWindowsDIBNew
 * @details Constructs a DIB that can be efficiently interact with Windows device.
	* Currently the constructed DIB will always in <a>FS_DIB_Rgb</a> format.
 * @param[in]  hDC The input windows device context.
 * @param[in]  width The bimtap width.
 * @param[in]  height The bitmap height.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBNew, (HDC hDC,  FS_INT32 width,  FS_INT32 height))

/**
 * @brief FRWindowsDIBDestroy
 * @details Destroys the input DIB bitmap.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBDestroy, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBGetBitmapInfo
 * @details Get Windows bitmap info structure.
	* The result is a binary string that can be used at a <Italic>BITMAPINFO</Italic> structure.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[out]  outInfo It receives the windows bitmap info structure for the DIB.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBGetBitmapInfo, (FS_DIBitmap pBitmap,  FS_ByteString* outInfo))

/**
 * @brief FRWindowsDIBLoadFromBuf
 * @details Constructs a bitmap from existing data.
 * @param[in]  pbmi The windows bitmap info structure.
 * @param[in]  pData The bitmap data.
 * @return   A bitmap from existing data.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromBuf, (BITMAPINFO* pbmi,  void* pData))

/**
 * @brief FRWindowsDIBGetDDBitmap
 * @details Converts to device compatible bitmap.
 * @param[in]  pBitmap The input DIB.
 * @param[in]  hDC The input DC.
 * @return   A device dependent bitmap compatible with the input DC.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HBITMAP, FRWindowsDIBGetDDBitmap, (FS_DIBitmap pBitmap,  HDC hDC))

/**
 * @brief FRWindowsDIBLoadFromDDB
 * @details Load DI bitmap from DDB. If <param>hDC</param> is NULL, system display DC will be used.
 * @param[in]  hDC The input DC.
 * @param[in]  hBitmap The input device dependent bitmap.
 * @param[in]  pPalette The bmp's palette, applicable to 1bppRgb and 8bppRgb formats.
 * @param[in]  size The palette's size.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromDDB, (HDC hDC,  HBITMAP hBitmap,  FS_DWORD* pPalette,  FS_DWORD size))

/**
 * @brief FRWindowsDIBLoadFromFile
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  filename The input full file path.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromFile, (FS_LPCWSTR filename))

/**
 * @brief FRWindowsDIBLoadFromFileII
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  filename The input full file path.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadFromFileII, (FS_LPCSTR filename))

/**
 * @brief FRWindowsDIBLoadDIBitmap
 * @details Load DI bitmap from file. Unicode version. Without GDI+ support, we supports only BMP file.
	* With GDI support, we support much more.
 * @param[in]  args The input full file path or memory.
 * @return   A DIB.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DIBitmap, FRWindowsDIBLoadDIBitmap, (FR_WINDIB_Open_Args args))

/**
 * @brief FRWindowsDIBGetDC
 * @details Gets the DC.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   The DC.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HDC, FRWindowsDIBGetDC, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBGetWindowsBitmap
 * @details Gets the bitmap.
 * @param[in]  pBitmap The input DIB bitmap.
 * @return   The bitmap handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(HBITMAP, FRWindowsDIBGetWindowsBitmap, (FS_DIBitmap pBitmap))

/**
 * @brief FRWindowsDIBLoadFromDevice
 * @details Loads from a device.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[in]  hDC The input windows device context.
 * @param[in]  left The x-coordinate in the windows DC.
 * @param[in]  top The y-coordinate in the windows DC.
 * @return   The bitmap.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBLoadFromDevice, (FS_DIBitmap pBitmap,  HDC hDC,  FS_INT32 left,  FS_INT32 top))

/**
 * @brief FRWindowsDIBSetToDevice
 * @details Outputs to a device.
 * @param[in]  pBitmap The input DIB bitmap.
 * @param[in]  hDC The input windows device context.
 * @param[in]  left The x-coordinate in the windows DC.
 * @param[in]  top The y-coordinate in the windows DC.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRWindowsDIBSetToDevice, (FS_DIBitmap pBitmap,  HDC hDC,  FS_INT32 left,  FS_INT32 top))

NumOfSelector(FRWindowsDIB)
ENDENUM

//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
