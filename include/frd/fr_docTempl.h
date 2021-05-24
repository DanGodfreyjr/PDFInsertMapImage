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
/* Doc HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRDocOpenFromFile
 * @details Opens and displays a document form a file.
 * @param[in]  wszFile The file path.
 * @param[in]  szPassword The password with the file. It could be <a>NULL</a> if no password to pass.
 * @param[in]  bMakeVisible Whether the document will be made visible.
 * @param[in]  bAddToMRU Whether add the file path to the recent file list.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
 * @see FRDocClose
 * @see FRDocOpenFromPDDoc
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromFile, (FS_LPCWSTR wszFile,  FS_LPCSTR szPassword,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRDocOpenFromPDDoc
 * @details Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.
 * @param[in]  pddoc The <a>FR_Document</a> object to open.
 * @param[in]  lpwsTitle It is used as window's title.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	* <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
 * @see FRDocClose
 * @see FRDocOpenFromFile
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromPDDoc, (FPD_Document pddoc,  FS_LPCWSTR lpwsTitle))

/**
 * @brief FRDocFromPDDoc
 * @details Gets the  <a>FR_Docuemnt</a> associated with a <a>FPD_Document</a>.
 * @param[in]  pddoc The <a>FR_Docuemnt</a> whose <a>FR_Document</a> is to be returned.
 * @return   The <a>FR_Docuemnt</a> if a  <a>FR_Docuemnt</a> is already opened for this <a>FPD_Document</a>, otherwise <a>NULL</a>.
 * @note 
 * @see FRDocOpenFromFile
 * @see FRDocOpenFromPDDoc
 * @see FRDocGetPDDoc
 */
INTERFACE(FR_Document, FRDocFromPDDoc, (FPD_Document pddoc))

/**
 * @brief FRDocClose
 * @details Closes the document window.
 * @param[in]  doc The document to close.
 * @param[in]  bPromptToSave If <a>FALSE</a>, the document closed without prompting the user and without saving,
	* even if the document has been modified. If <a>TRUE</a>, it prompt the user to save the document if it has
	* been modified.
 * @param[in]  bDelay Delay closing the document or not.
 * @param[in]  bShowCancel If <a>FALSE</a>, it will not show cancle button when prompt to save.
 * @return   <a>TRUE</a> if the document colsed, <a>FALSE</a> if it did not. The document will always close if 
	* <param>bPromptToSave</param> is <a>FALSE</a>.
 * @note 
 * @see FRDocOpenFromFile
 * @see FRDocOpenFromPDDoc
 */
INTERFACE(FS_BOOL, FRDocClose, (FR_Document doc,  FS_BOOL bPromptToSave,  FS_BOOL bDelay,  FS_BOOL bShowCancel))

/**
 * @brief FRDocGetPDDoc
 * @details Gets the <a>FPD_Document</a> to associated with the specified <a>FR_Document</a>.
 * @param[in]  doc The document whose <a>FPD_Document</a> is obtained.
 * @return   The <a>FPD_Document</a> associated with <a>FR_Document</a>.
 * @note 
 * @see FRDocFromPDDoc
 * @see FRDocOpenFromPDDoc
 * @see FRPageViewGetPDPage
 */
INTERFACE(FPD_Document, FRDocGetPDDoc, (FR_Document doc))

/**
 * @brief FRDocSetCustomSecurity
 * @details Sets security using custom security handler and custom encryption.
	* Application should provide a full encryption dictionary (application can destroy it after this call),
	* and a custom encryption handler.
 * @param[in]  doc The input document.
 * @param[in]  encryptDict The Encrypt dictionary.
 * @param[in]  cryptoHandler The callbacks for crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @param[in]  clientHandler The user-supplied data.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocSetCustomSecurity, (FR_Document doc,  FPD_Object encryptDict,  FR_CryptoCallbacks cryptoHandler,  FS_BOOL bEncryptMetadata,  FS_LPVOID clientHandler))

/**
 * @brief FRDocDoSave
 * @details Saves a file, handling any user interface(for example, a Save File dialog box) if need.
 * @param[in]  doc The document to be saved.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save callback function.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @return   void
 * @note 
 * @see FRDocDoSaveAs
 * @see FRDocSetChangeMark
 */
INTERFACE(void, FRDocDoSave, (FR_Document doc,  FR_DocSaveProc proc,  void* pProcData,  FS_BOOL bShowProgressBar))

/**
 * @brief FRDocDoSaveAs
 * @details Displays a file dialog box which can be used to save the document as a new name.
 * @param[in]  doc The document.
 * @return   
 * @note 
 * @see FRDocDoSave
 */
INTERFACE(void, FRDocDoSaveAs, (FR_Document doc))

/**
 * @brief FRDocSetChangeMark
 * @details Sets the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	* if the value of the flag is valid, the Save button on File toolbar is enable, otherwise the Save button is 
	* disable.
 * @param[in]  doc The document.
 * @return   void
 * @note 
 * @see FRDocGetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(void, FRDocSetChangeMark, (FR_Document doc))

/**
 * @brief FRDocGetChangeMark
 * @details Checks whether the document is modified.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> if the document has been modified, <a>FALSE</a> if no change.
 * @note 
 * @see FRDocSetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(FS_BOOL, FRDocGetChangeMark, (FR_Document doc))

/**
 * @brief FRDocClearChangeMark
 * @details Invalidates all modification.
 * @param[in]  doc The document.
 * @return   void
 * @note 
 * @see FRDocGetChangeMark
 * @see FRDocSetChangeMark
 */
INTERFACE(void, FRDocClearChangeMark, (FR_Document doc))

/**
 * @brief FRDocWillInsertPages
 * @details The document will be inserted some pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document to be inserted pages into.
 * @param[in]  iInserAt The page index for first inserted page.
 * @param[in]  nCount The page count for all inserted page.
 * @return   void
 * @note You can call this method before you start to insert some page into a FPD_Document object.<br>
	* The callback WillInsertPages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocWillInsertPages, (FR_Document doc,  FS_INT32 iInserAt,  FS_INT32 nCount))

/**
 * @brief FRDocDidInsertPages
 * @details The document was inserted some pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document to be inserted pages into.
 * @param[in]  iInserAt The page index for first inserted page.
 * @param[in]  nCount The page count for all inserted page.
 * @return   void
 * @note You can call this method after you inserted some page into a FPD_Document object.<br>
	* The callback DidInsertPages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocDidInsertPages, (FR_Document doc,  FS_INT32 iInserAt,  FS_INT32 nCount))

/**
 * @brief FRDocWillDeletePages
 * @details The document will delete any pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document whose page was deleted.
 * @param[in]  arrDelPage The index of the pages that has been deleted.
 * @return   void
 * @note You can call this method before you delete some page from a FPD_Document object.<br>
	* The callback WillDeletePages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.  	
	* Notes:
 */
INTERFACE(void, FRDocWillDeletePages, (FR_Document doc,  FS_WordArray arrDelPage))

/**
 * @brief FRDocDidDeletePages
 * @details The document was deleted any pages. This notification will be broadcast to
   	* all plug-ins.
 * @param[in]  doc The document whose page was deleted.
 * @param[in]  arrDelPage The index of the pages that has been deleted.
 * @return   void
 * @note You can call this method after you deleted some page from a FPD_Document object.<br>
	* The callback DidDeletePages() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.  	
	* Notes:
 */
INTERFACE(void, FRDocDidDeletePages, (FR_Document doc,  FS_WordArray arrDelPage))

/**
 * @brief FRDocWillRotatePage
 * @details The pages of <a>FR_Document</a> whose rotation attribute will be modified.
 * @param[in]  doc The document whose page's rotation attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method before you want to change some page's rotation attribute.<br>
	* The callback WillModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocWillRotatePage, (FR_Document doc,  int iPage))

/**
 * @brief FRDocDidRotatePage
 * @details The page of <a>FR_Document</a> whose rotation attribute was modified.
 * @param[in]  doc The document whose page's rotation attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method after you changed some page's rotation attribute.<br>
	* The callback DidModifyPageAttribute() descripted in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocDidRotatePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocWillResizePage
 * @details The pages of <a>FR_Document</a> whose attribute will be modified.
 * @param[in]  doc The document whose page's attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method before you want to change some page's rotation attribute.<br>
	* The callback WillModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocWillResizePage, (FR_Document doc,  int iPage))

/**
 * @brief FRDocDidResizePage
 * @details The page of <a>FR_Document</a> whose attribute was modified.
 * @param[in]  doc The document whose page's attribute was modified.
 * @param[in]  iPage The page index.
 * @return   void
 * @note You can call this method after you changed some page's rotation attribute.<br>
	* The callback DidModifyPageAttribute() descriped in struct FR_DocEventCallbacksRec
	* will be called by Reader.
 */
INTERFACE(void, FRDocDidResizePage, (FR_Document doc,  FS_INT32 iPage))

/**
 * @brief FRDocDoPrint
 * @details Performs the print operation, including user dialog box.
 * @param[in]  doc The document to print.
 * @return   void
 * @note 
 * @see FRDocPrintPages
 * @see FRDocDoPrintSilently
 * @see FRDocPrintSetup
 */
INTERFACE(void, FRDocDoPrint, (FR_Document doc))

/**
 * @brief FRDocPrintPages
 * @details Sets the first page and the last page to be printed.
 * @param[in]  doc The input document.
 * @param[in]  firstPage The index of first page to be printed.
 * @param[in]  lastPage The index of last page to be printed.
 * @return   void
 * @note 
 * @see FRDocDoPrint
 * @see FRDocDoPrintSilently
 */
INTERFACE(void, FRDocPrintPages, (FR_Document doc,  FS_INT32 firstPage,  FS_INT32 lastPage))

/**
 * @brief FRDocPrintSetup
 * @details Sets up the print.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 * @see FRDocDoPrint
 * @see FRDocDoPrintSilently
 * @see FRDocPrintPages
 */
INTERFACE(void, FRDocPrintSetup, (FR_Document doc))

/**
 * @brief FRDocCountDocViews
 * @details Gets the number of <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose view count is obtained.
 * @return   The number of <a>FR_DocView</a> for specified document.
 * @note 
 * @see FRDocGetDocView
 */
INTERFACE(FS_INT32, FRDocCountDocViews, (FR_Document doc))

/**
 * @brief FRDocGetDocView
 * @details Gets the specified <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose document view is obtained.
 * @param[in]  iView The index of a document view. The index range is 0 to (<a>FRDocCountDocViews</a>()-1).
 * @return   The specified <a>FR_DocView</a>.
 * @note 
 * @see FRDocGetCurrentDocView
 * @see FRDocCountDocViews
 */
INTERFACE(FR_DocView, FRDocGetDocView, (FR_Document doc,  FS_INT32 iView))

/**
 * @brief FRDocGetCurrentDocView
 * @details Gets the current showing <a>FR_DocView</a> for specified document.
 * @param[in]  doc The document whose document view is obtained.
 * @return   The current showing <a>FR_DocView</a>.
 * @note 
 * @see FRDocGetDocView
 */
INTERFACE(FR_DocView, FRDocGetCurrentDocView, (FR_Document doc))

/**
 * @brief FRDocGetPermissions
 * @details Gets permissions of a document.
 * @param[in]  doc The document whose user permission is obtained.
 * @return   The document permissions.
 * @note 
 * @see FRDocSetPermissions
 */
INTERFACE(FS_DWORD, FRDocGetPermissions, (FR_Document doc))

/**
 * @brief FRDocSetPermissions
 * @details Sets permissions to a document.
 * @param[in]  doc The document whose user permission is set.
 * @param[in]  dwPermission The new permission to set to the document.
 * @return   void
 * @note 
 * @see FRDocGetPermissions
 */
INTERFACE(void, FRDocSetPermissions, (FR_Document doc,  FS_DWORD dwPermission))

/**
 * @brief FRDocGetFilePath
 * @details Gets the file path of a document opened by Foxit Reader.
 * @param[in]  doc The document whose file path is set.
 * @param[in/out]  path A wide string object to receive the file path.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocGetFilePath, (FR_Document doc,  FS_WideString* path))

/**
 * @brief FRDocSetCurSelection
 * @details Sets the current selection handler by type.
 * @param[in]  doc The input document.
 * @param[in]  type The input type of the selection handler.
 * @param[in]  pSelectData The selection data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRDocSetCurSelection, (FR_Document doc,  FS_LPSTR type,  void* pSelectData))

/**
 * @brief FRDocAddToCurrentSelection
 * @details Adds the new data to the current selection data and returns the updated one.
 * @param[in]  doc The input document.
 * @param[in]  pCurData The current selection data.
 * @param[in]  pAddData The data to be added to the current selection handler.
 * @return   The updated selection data. It is <a>NULL</a> if failed.
 * @note 
 */
INTERFACE(void*, FRDocAddToCurrentSelection, (FR_Document doc,  void* pCurData,  void* pAddData))

/**
 * @brief FRDocRemoveFromSelection
 * @details Removes some data from the current selection data and returns the updated one.
 * @param[in]  doc The input document.
 * @param[in]  pCurData The current selection data.
 * @param[in]  pRemData The data to be removed from the current selection data.
 * @return   The updated selection data. It is <a>NULL</a> if failed.
 * @note 
 */
INTERFACE(void*, FRDocRemoveFromSelection, (FR_Document doc,  void* pCurData,  void* pRemData))

/**
 * @brief FRDocGetCurSelection
 * @details Gets the current selection handler.
 * @param[in]  doc The input document.
 * @return   The current selection handler.
 * @note 
 */
INTERFACE(void*, FRDocGetCurSelection, (FR_Document doc))

/**
 * @brief FRDocGetCurSelectionType
 * @details Gets the type of the current selection handler.
 * @param[in]  doc The input document.
 * @return   The type of the current selection handler.
 * @note 
 */
INTERFACE(FS_LPCSTR, FRDocGetCurSelectionType, (FR_Document doc))

/**
 * @brief FRDocShowSelection
 * @details Displays the current selection by calling the selection handler's <a>FRSelectionShowSelection</a>() 
	* callback. It does nothing if the document has no selection, or the current selection's handler has no 
	* <a>FRSelectionShowSelection</a>()  callback.
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionShowSelection</a>() callback.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocShowSelection, (FR_Document doc))

/**
 * @brief FRDocClearSelection
 * @details Clears and destroys the current selection by calling the appropriate selection server's 
    * <a>FRSelectionLosingSelection</a>().
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocClearSelection, (FR_Document doc))

/**
 * @brief FRDocDeleteSelection
 * @details Deletes the specified document's current selection, if possible. The selection is deleted if changing the 
	* selection is currently permitted, the selection handler has an <a>FRSelectionDoDelete</a>() callback, and the 
	* selection server's <a>FRSelectionCanDelete</a>() callback returns <a>TRUE</a>. If the selection handler does not 
	* have a <a>FRSelectionCanDelete</a>() callback, a default value of <a>TRUE</a> is used.
	* The selection is deleted by calling the selection handler's <a>FRSelectionDoDelete</a>() callback. 
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionDoDelete</a>() and 
    * <a>FRSelectionCanDelete</a>() callbacks.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocDeleteSelection, (FR_Document doc))

/**
 * @brief FRDocCopySelection
 * @details Copies the current selection to the clipboard, if possible. The selection is copied if the selection handler has 
	* a <a>FRSelectionDoCopy</a>() callback, and the selection handler's <a>FRSelectionCanCopy</a>() callback 
	* returns <a>TRUE</a>. If the selection server does not have a <a>FRSelectionCanCopy</a>() method, a default 
	* value of <a>TRUE</a> is used.
	* The selection is copied by calling the selection handler's <a>FRSelectionDoCopy</a>() callback. 
	* It only raises those exceptions raised by the selection handler's <a>FRSelectionDoCopy</a>() and 
    * <a>FRSelectionCanCopy</a>() callbacks.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocCopySelection, (FR_Document doc))

/**
 * @brief FRDocSetCurCapture
 * @details Set the current capture handler by type.
 * @param[in]  doc The input document.
 * @param[in]  type The type of the capture handler.
 * @param[in]  pCapData The capture data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRDocSetCurCapture, (FR_Document doc,  FS_LPSTR type,  void* pCapData))

/**
 * @brief FRDocGetCurCapture
 * @details Gets the current capture handler.
 * @param[in]  doc The input document.
 * @return   The current capture handler.
 * @note 
 */
INTERFACE(void*, FRDocGetCurCapture, (FR_Document doc))

/**
 * @brief FRDocGetCurCaptureType
 * @details Gets the type of the current capture handler.
 * @param[in]  doc The input document.
 * @return   The type of the current capture handler.
 * @note 
 */
INTERFACE(FS_LPCSTR, FRDocGetCurCaptureType, (FR_Document doc))

/**
 * @brief FRDocReleaseCurCapture
 * @details Releases the current capture.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocReleaseCurCapture, (FR_Document doc))

/**
 * @brief FRDocSetMenuEnableByName
 * @details Set the menu enable or not.
 * @param[in]  doc The input document.
 * @param[in]  csName The menu you want to control.
 * @param[in]  bEnable Whether the menu is enable or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FRDocSetMenuEnableByName, (FR_Document doc,  FS_LPCSTR csName,  FS_BOOL bEnable))

/**
 * @brief FRDocGetParser
 * @details Gets the PDF file parser which is parsing current document.
 * @param[in]  doc The input document.
 * @return   A PDF file parser associated with current document.
 * @note 
 */
INTERFACE(FPD_Parser, FRDocGetParser, (FR_Document doc))

/**
 * @brief FRDocGetPDFCreator
 * @details Gets the PDF creator associated with current document.
 * @param[in]  doc The input document.
 * @return   A PDF creator associated with current document.
 * @note 
 */
INTERFACE(FPD_Creator, FRDocGetPDFCreator, (FR_Document doc))

/**
 * @brief FRDocDoPrintSilently
 * @details Performs the print operation, not including user dialog box.
 * @param[in]  doc The document to print.
 * @return   void
 * @note 
 * @see FRDocPrintPages
 * @see FRDocPrintSetup
 */
INTERFACE(void, FRDocDoPrintSilently, (FR_Document doc))

/**
 * @brief FRDocGetTextSelectTool
 * @details Gets the current text select tool for specified document.
 * @param[in]  doc The document object.
 * @return   The <a>FR_TextSelectTool</a> object of the <param>doc</param>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_TextSelectTool, FRDocGetTextSelectTool, (FR_Document doc))

/**
 * @brief FRDocGetDocumentType
 * @details Get the type of the document.
 * @param[in]  doc The document to get the type.
 * @return   The type of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocTypes
 */
INTERFACE(FS_INT32, FRDocGetDocumentType, (FR_Document doc))

/**
 * @brief FRDocCanSecurityMethodBeModified
 * @details Whether the security applied to the document can be modified or not.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocCanSecurityMethodBeModified, (FR_Document doc))

/**
 * @brief FRDocUpdateSecurityMethod
 * @details When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked if the document is encrypted.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocUpdateSecurityMethod, (FR_Document doc))

/**
 * @brief FRDocIsEncrypted
 * @details When this interface is invoked, the <a>FRSecurityMethodIsMyMethod</a> will be invoked.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for the document being encrypted, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocIsEncrypted, (FR_Document doc))

/**
 * @brief FRDocRemoveSecurityMethod
 * @details When this interface is invoked, the <a>FRSecurityMethodRemoveSecurityInfo</a> will be invoked.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for the security method of the document being removed, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterSecurityMethod
 */
INTERFACE(FS_BOOL, FRDocRemoveSecurityMethod, (FR_Document doc))

/**
 * @brief FRDocEnableRunScript
 * @details Whether the document can run script.
 * @param[in]  doc The document.
 * @param[in]  bIsEnable Whether the document can run script.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocEnableRunScript, (FR_Document doc,  FS_BOOL bIsEnable))

/**
 * @brief FRDocIsEnableRunScript
 * @details Whether the document can run script.
 * @param[in]  doc The document.
 * @return   Whether the document can run script.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocIsEnableRunScript, (FR_Document doc))

/**
 * @brief FRDocChangeDocShowTitle
 * @details Sets the main frame title and the document tab title.
 * @param[in]  doc The document.
 * @param[in]  lpwsShowTitle This value will be shown as the main frame title and the document tab title.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocChangeDocShowTitle, (FR_Document doc,  FS_LPCWSTR lpwsShowTitle))

/**
 * @brief FRDocIsMemoryDoc
 * @details Whether the document is a memory document or not.
 * @param[in]  doc The document.
 * @return   Whether the document is a memory document or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocIsMemoryDoc, (FR_Document doc))

/**
 * @brief FRDocGetCurrentSecurityMethodName
 * @details Gets the name of current security method.
 * @param[in]  doc The document.
 * @param[out]  outName It receives the name of current security method.
 * @return   The name of current security method.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocGetCurrentSecurityMethodName, (FR_Document doc,  FS_WideString* outName))

/**
 * @brief FRDocGetCurrentWndProvider
 * @details Gets the current window provider.
 * @param[in]  doc The document.
 * @return   The pointer to the current window provider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
 */
INTERFACE(void*, FRDocGetCurrentWndProvider, (FR_Document doc))

/**
 * @brief FRDocSetCurrentWndProvider
 * @details Sets the window provider.
 * @param[in]  doc The document.
 * @param[in]  pProvider The input window provider.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
 */
INTERFACE(void, FRDocSetCurrentWndProvider, (FR_Document doc,  void* pProvider))

/**
 * @brief FRDocGetWndProviderByName
 * @details Gets the window provider by name.
 * @param[in]  doc The document.
 * @param[in]  lpsName The Specified name of the window provider.
 * @return   The window provider.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
 */
INTERFACE(void*, FRDocGetWndProviderByName, (FR_Document doc,  FS_LPCSTR lpsName))

/**
 * @brief FRDocGetReviewType
 * @details Gets the review type.
 * @param[in]  doc The document.
 * @return   The review type.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FRDocGetReviewType, (FR_Document doc))

/**
 * @brief FRDocSetReviewType
 * @details Sets the review type.
 * @param[in]  doc The document.
 * @param[in]  nType The input review type.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocSetReviewType, (FR_Document doc,  FS_INT32 nType))

/**
 * @brief FRDocSetAppPermissions
 * @details Sets the application permission.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  dwPermission The input application permission.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRDocSetAppPermissions, (FR_Document doc,  FS_DWORD dwPermission))

/**
 * @brief FRDocGetAppPermissions
 * @details Checks whether the user has the specified application permission or not.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The specified permission.
 * @return   <a>TRUE</a> if the user has the specified application permission.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetAppPermissions, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocGetAppPermissionsII
 * @details Gets the application permissions.
 * @param[in]  doc The document whose user permission is obtained.
 * @return   The application permissions.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FRDocGetAppPermissionsII, (FR_Document doc))

/**
 * @brief FRDocGetPermissionsII
 * @details Checks whether the document has the permission.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The input permission to check.
 * @return   <a>TRUE</a> means the document has the permission, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetPermissionsII, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocGetMergedPermissions
 * @details Checks whether the document has the permission.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[in]  iPermission The specified permission.
 * @return   <a>TRUE</a> means the document has the permission, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocGetMergedPermissions, (FR_Document doc,  FS_INT32 iPermission))

/**
 * @brief FRDocKillFocusAnnot
 * @details Kills the focus annot.
 * @param[in]  doc The document.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRDocKillFocusAnnot, (FR_Document doc))

/**
 * @brief FRDocSetPropertiesPDFVersion
 * @details Sets the PDF version that will be shown in the properties dialog.
 * @param[in]  doc The document.
 * @param[in]  lpwsPDFVersion The input PDF version that will be shown in the properties dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRDocSetPropertiesPDFVersion, (FR_Document doc,  FS_LPCWSTR lpwsPDFVersion))

/**
 * @brief FRDocSetPropertiesFilePath
 * @details Sets the file path that will be shown in the properties dialog.
 * @param[in]  doc The document.
 * @param[in]  lpwsFilePath The input file path that will be shown in the properties dialog.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRDocSetPropertiesFilePath, (FR_Document doc,  FS_LPCWSTR lpwsFilePath))

/**
 * @brief FRDocDoSaveAs2
 * @details Displays a file dialog box which can be used to save the document as a new name.
 * @param[in]  doc The document.
 * @param[in]  pwszFilePath The path where the document to be saved as.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save-as callback function.
 * @param[in]  bSaveAsTempFile Sets it FALSE as default.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 * @see FR_DocSaveAsProc
 */
INTERFACE(FS_BOOL, FRDocDoSaveAs2, (FR_Document doc,  FS_LPCWSTR pwszFilePath,  FR_DocSaveAsProc proc,  void* pProcData,  FS_BOOL bSaveAsTempFile,  FS_BOOL bShowProgressBar))

/**
 * @brief FRDocShowSaveProgressCancelButton
 * @details Sets to show the save progress cancel button or not.
 * @param[in]  doc The document.
 * @param[in]  bShow Whether to show the save progress cancel button.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(void, FRDocShowSaveProgressCancelButton, (FR_Document doc,  FS_BOOL bShow))

/**
 * @brief FRDocSetInputPasswordProc
 * @details Sets the prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.
 * @param[in]  doc The input document.
 * @param[in]  proc Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the password.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.2
 */
INTERFACE(void, FRDocSetInputPasswordProc, (FR_Document doc,  FRInputPasswordProc proc))

/**
 * @brief FRDocCheckInDocumentOLE
 * @details Checks whether the document is opened by OLE. For example, the document is embedded	in <Italic>MS Office Word</Italic>.
 * @param[in]  doc The input document.
 * @return   True means the document is opened by OLE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FRDocCheckInDocumentOLE, (FR_Document doc))

/**
 * @brief FRDocIsShowInBrowser
 * @details Checks whether the document is opened in browser.
 * @param[in]  doc The input document.
 * @return   True means the document is opened in browser.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FRDocIsShowInBrowser, (FR_Document doc))

/**
 * @brief FRDocGetUIParentWnd
 * @details Gets the UI parent window.
 * @param[in]  doc The input document.
 * @return   A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void*, FRDocGetUIParentWnd, (FR_Document doc))

/**
 * @brief FRDocGetDocFrameHandler
 * @details Gets the frame handler associated with the document.
 * @param[in]  doc The input document.
 * @return   The frame handler associated with the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(HWND, FRDocGetDocFrameHandler, (FR_Document doc))

/**
 * @brief FRDocCreateNewViewByWndProvider
 * @details Creates the new view by <a>FR_WndProviderCallbacksRec</a>.
 * @param[in]  doc The input document.
 * @param[in]  lpsName The Specified name of the window provider.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterWndProvider
 */
INTERFACE(void, FRDocCreateNewViewByWndProvider, (FR_Document doc,  FS_LPCSTR lpsName))

/**
 * @brief FRDocLoadAnnots
 * @details Loads annotation(s) for an opening PDF document.
 * @param[in]  doc The input document.
 * @param[in]  arrAnnotDict The pointer array holding the annotation dictionaries to be loaded.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FRDocLoadAnnots, (FR_Document doc,  FS_PtrArray arrAnnotDict))

/**
 * @brief FRDocGetDocShowTitle
 * @details Gets the title shown as the main frame title and the document tab title.
 * @param[in]  doc The document.
 * @param[out]  outTitle It receives the title shown as the main frame title and the document tab title.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 */
INTERFACE(void, FRDocGetDocShowTitle, (FR_Document doc,  FS_WideString* outTitle))

/**
 * @brief FRDocDoSave2
 * @details Saves a file, handling any user interface(for example, a Save File dialog box) if need.
 * @param[in]  doc The document to be saved.
 * @param[in]  proc Callback function.
 * @param[in]  pProcData The client data. It will be passed to the save callback function.
 * @param[in]  bShowProgressBar Whether to show the progress bar or not.
 * @param[in]  bDoPDFOptimize Whether to optimize the PDF or not.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocDoSave
 * @see FRDocDoSaveAs
 * @see FRDocSetChangeMark
 */
INTERFACE(FS_BOOL, FRDocDoSave2, (FR_Document doc,  FR_DocSaveProc proc,  void* pProcData,  FS_BOOL bShowProgressBar,  FS_BOOL bDoPDFOptimize))

/**
 * @brief FRDocResetDocTitleColor
 * @details Resets the document title color in the document tab.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocSetDocTitleColor
 */
INTERFACE(void, FRDocResetDocTitleColor, (FR_Document doc))

/**
 * @brief FRDocSetDocTitleColor
 * @details Sets the document title color in the document tab.
 * @param[in]  doc The input document.
 * @param[in]  clrDocTitle The input color value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocResetDocTitleColor
 */
INTERFACE(void, FRDocSetDocTitleColor, (FR_Document doc,  FS_COLORREF clrDocTitle))

/**
 * @brief FRDocGetOriginalType
 * @details Gets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @param[in]  doc The input document.
 * @return   The original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocSetOriginalType
 */
INTERFACE(FROriginalDocType, FRDocGetOriginalType, (FR_Document doc))

/**
 * @brief FRDocSetOriginalType
 * @details Sets the original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF.
 * @param[in]  doc The input document.
 * @param[in]  oriDocType The input original type of the document.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0.0.0
 * @see FRDocGetOriginalType
 */
INTERFACE(void, FRDocSetOriginalType, (FR_Document doc,  FROriginalDocType oriDocType))

/**
 * @brief FRDocSetFocusAnnot
 * @details Sets the focus annotation.
 * @param[in]  doc The input document.
 * @param[in]  pFocusAnnot The input annotation.
 * @param[in]  bDelay Whether to delay the setting or not. The default value is FALSE.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocSetFocusAnnot, (FR_Document doc,  FR_Annot pFocusAnnot,  FS_BOOL bDelay))

/**
 * @brief FRDocGenerateUR3Permission
 * @details Generates the UR3 signature. Usage rights signatures are used to enable additional interactive features that are not available by
	* default in a particular viewer application (such as Adobe Reader). See PDF reference for more details.
 * @param[in]  doc The input document.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocGenerateUR3Permission, (FR_Document doc))

/**
 * @brief FRDocHasRedactAnnot
 * @details Checks whether the document is marked for redaction or not.
 * @param[in]  doc The input document.
 * @return   TRUE if the document is marked for redaction, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocHasRedactAnnot, (FR_Document doc))

/**
 * @brief FRDocGenerateRedactions
 * @details Generates a redacted document and it will be saved to <param>wsFilePath</param>.
 * @param[in]  doc The input document.
 * @param[out]  wsFilePath It receives the path of the document redacted.
 * @return   TRUE for success, otherwise for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FRDocGenerateRedactions, (FR_Document doc,  FS_WideString* wsFilePath))

/**
 * @brief FRDocReloadPage
 * @details Reloads the specified page.
 * @param[in]  doc The input document.
 * @param[in]  iPage The specified page index.
 * @param[in]  bDisableGoto Whether to prevent going to the specified page view. Sets it FALSE as default.
 * @return   TRUE for success, otherwise for failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRDocReloadPage, (FR_Document doc,  FS_INT32 iPage,  FS_BOOL bDisableGoto))

/**
 * @brief FRDocForbidChangeMark
 * @details Forbid setting the modify flag. Reader has a built-in flag that indicate whether a document has been modified,
	* if the value of the flag is valid, the Save button is enable, otherwise the Save button is 
	* disable.
 * @param[in]  doc The document.
 * @param[in]  bForbid Whether to forbid setting the modify flag or not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
 * @see FRDocSetChangeMark
 * @see FRDocGetChangeMark
 * @see FRDocClearChangeMark
 */
INTERFACE(void, FRDocForbidChangeMark, (FR_Document doc,  FS_BOOL bForbid))

/**
 * @brief FRDocOpenFromPDDoc2
 * @details Opens and returns a <a>FR_Document</a> view of <a>PD_Document</a>.
 * @param[in]  pddoc The <a>FR_Document</a> object to open.
 * @param[in]  lpwsTitle It is used as window's title.
 * @param[in]  bDelPDFDoc Whether the framework must delete the <a>FPD_Document</a> object or not. If the plug-in 
	* deletes the <a>FPD_Document</a> object through <a>FPDParserDestroy</a>(), sets it FALSE.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
	* <a>FRDocClose</a>() should be used in place of <a>FPDDocClose</a>() after FRDocOpenFromPDDoc() is called.
	* <a>FRDocClose</a>() will decrement the FPDDoc appropriately and free document-related resources.
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 * @see FRDocClose
 * @see FRDocOpenFromFile
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromPDDoc2, (FPD_Document pddoc,  FS_LPCWSTR lpwsTitle,  FS_BOOL bDelPDFDoc))

/**
 * @brief FRDocGetCreateDocSource
 * @details Gets the source type of the document.
 * @param[in]  doc The document.
 * @return   The source type of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FRCreateDocSource, FRDocGetCreateDocSource, (FR_Document doc))

/**
 * @brief FRDocSetCreateDocSource
 * @details Sets the source type of the document.
 * @param[in]  doc The document.
 * @param[in]  sourceType The input source type of the document.
 * @param[in]  lpwsSourceFileName The input source file name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(void, FRDocSetCreateDocSource, (FR_Document doc,  FRCreateDocSource sourceType,  FS_LPCWSTR lpwsSourceFileName))

/**
 * @brief FRDocGetCreateDocSourceFileName
 * @details Gets the source file name.
 * @param[in]  doc The document.
 * @param[out]  outSourceFileName It receives the source file name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(void, FRDocGetCreateDocSourceFileName, (FR_Document doc,  FS_WideString* outSourceFileName))

/**
 * @brief FRDocParsePage
 * @details Parses the specified page.
 * @param[in]  doc The document.
 * @param[in]  nPageIndex The specified page index.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_BOOL, FRDocParsePage, (FR_Document doc,  FS_INT32 nPageIndex))

/**
 * @brief FRDocIsValidAnnot
 * @details Checks whether the annotation is valid or not.
 * @param[in]  doc The document.
 * @param[in]  frAnnot The input annotation to be checked.
 * @return   TRUE if the annotation is valid.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_BOOL, FRDocIsValidAnnot, (FR_Document doc,  FR_Annot frAnnot))

/**
 * @brief FRDocIsWillReopen
 * @details Checks whether the document is to be reopened after it is closed.
 * @param[in]  doc The document.
 * @return   TRUE if the document is to be reopened.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 */
INTERFACE(FS_BOOL, FRDocIsWillReopen, (FR_Document doc))

/**
 * @brief FRDocOpenFromFile2
 * @details Opens and displays a document form a file.
 * @param[in]  wszFile The file path.
 * @param[in]  szPassword The password with the file. It could be <a>NULL</a> if no password to pass.
 * @param[in]  bMakeVisible Whether the document will be made visible.
 * @param[in]  bAddToMRU Whether add the file path to the recent file list.
 * @param[in]  bCheckCertPassword Whether prompt a password input dialog to check the password of the certificate used to encrypt the document.
 * @return   The document that was opened. It returns <a>NULL</a> if Reder failed to open document.
 * @note Do not open and then immediately close a FR_Document without letting least once event loop complete.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @see FRDocClose
 * @see FRDocOpenFromPDDoc
 * @see FRDocFromPDDoc
 */
INTERFACE(FR_Document, FRDocOpenFromFile2, (FS_LPCWSTR wszFile,  FS_LPCSTR szPassword,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU,  BOOL bCheckCertPassword))

/**
 * @brief FRDocGetSignaturePermissions
 * @details Gets the signature permissions of a document.
 * @param[in]  doc The document whose user permission is obtained.
 * @param[out]  pdwPermissions The document permissions.
 * @return   <a>TRUE</a> if the document is signed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 */
INTERFACE(FS_BOOL, FRDocGetSignaturePermissions, (FR_Document doc,  FS_DWORD *pdwPermissions))

/**
 * @brief FRDocConvertPdfToOtherFormat
 * @details Convert Pdf document to other format document.
 * @param[in]  wsSrcPath The source file which need to be converted.
 * @param[in]  wsDesPath The destination file path.
 * @param[in]  pageAry The pages need to be converted. if it is NULL ,will convert the whole document.
 * @param[in]  wsFileExt The format need to be convert. Support: docx, doc, xlsx, xls, html, pptx, rtf.
 * @param[in]  wsPwd The password of encrypt the document. if it is empty, will not encrypt the document.
 * @param[in]  bShowProgress Whether or not show the convert progress bar.
 * @return   <a>TRUE</a> converted sucessful.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FRDocConvertPdfToOtherFormat, (FS_LPCWSTR wsSrcPath,  FS_LPCWSTR wsDesPath,  FS_DWordArray pageAry,  FS_LPCWSTR wsFileExt,  FS_LPCWSTR wsPwd,  BOOL bShowProgress))

/**
 * @brief FRDocDoPassWordEncrypt
 * @details Set the document password through the password input dialog.
 * @param[in]  frDoc The document to protected.
 * @param[in]  proc Prototype of callback function invoked by <Italic>Foxit Reader</Italic> to receive the protecting status.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRDocDoPassWordEncrypt, (FR_Document frDoc,  FRPasswordEncryptProc proc))

/**
 * @brief FRDocIsInProtectedViewMode
 * @details Check if the document is in protected view mode.
 * @param[in]  frDoc The document to protected.
 * @return   <a>TRUE</a> means in the protected view mode.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRDocIsInProtectedViewMode, (FR_Document frDoc))

/**
 * @brief FRDocGetCreateDocSourceFilePath
 * @details Gets the source file path.
 * @param[in]  doc The document.
 * @param[out]  outSourceFilePath It receives the source file path.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRDocGetCreateDocSourceFilePath, (FR_Document doc,  FS_WideString* outSourceFilePath))

/**
 * @brief FRDocIsImageBasedDocument
 * @details Check if the document is Image Based Document.
 * @param[in]  frDoc The document.
 * @return   <a>TRUE</a> means the document is Image Based Document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.2
 */
INTERFACE(FS_BOOL, FRDocIsImageBasedDocument, (FR_Document frDoc))

/**
 * @brief FRDocSetDocEncrypted
 * @details Indicates whether the document is encrypted or not.
 * @param[in]  frDoc The document.
 * @param[in]  bEncrypted Indicates whether the document is encrypted or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.2
 */
INTERFACE(void, FRDocSetDocEncrypted, (FR_Document frDoc,  FS_BOOL bEncrypted))

/**
 * @brief FRDocIsVisible
 * @details Checks whether the opened document is visible or not.
 * @param[in]  frDoc The document.
 * @return   Whether the opened document is visible or not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.3
 */
INTERFACE(FS_BOOL, FRDocIsVisible, (FR_Document frDoc))

/**
 * @brief FRDocSetDRMSecurity
 * @details Sets security using custom security handler and custom encryption.
	* Application should provide a full encryption dictionary (application can destroy it after this call),
	* and a custom encryption handler.
 * @param[in]  doc The input document.
 * @param[in]  encryptDict The Encrypt dictionary.
 * @param[in]  cryptoHandler The callbacks for crypto handler.
 * @param[in]  bEncryptMetadata Whether to encrypt the metadata.
 * @param[in]  clientHandler The user-supplied data.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(void, FRDocSetDRMSecurity, (FR_Document doc,  FPD_Object encryptDict,  FR_DRMCryptoCallbacks cryptoHandler,  FS_BOOL bEncryptMetadata,  FS_LPVOID clientHandler))

NumOfSelector(FRDoc)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//*****************************
/* CustomSignature HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCustomSignatureGenerateSignInfo
 * @details Signs a PDF document with the <a>FR_SignatureInfo</a> and <a>FR_SignaturePosInfo</a>. You have to register the signature 
	* handler by <a>FRCustomSignatureRegisterSignatureHandler</a>to sign the data, otherwise the data will be signed with the default standard method.
 * @param[in]  pSgInfo To fill the signature info.
 * @param[in]  pSgPosInfo To fill the signature position info.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureGenerateSignInfo, (FR_SignatureInfo* pSgInfo,  FR_SignaturePosInfo* pSgPosInfo))

/**
 * @brief FRCustomSignatureGetDefaultServer
 * @details Gets the default timestamp server.
 * @param[out]  pSgTMServer It receives the default timestamp server.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureGetDefaultServer, (FR_SignatureTimestampServer* pSgTMServer))

/**
 * @brief FRCustomSignatureCreateSignatureHandler
 * @details Creates the signature handler. Registers it by <a>FRCustomSignatureRegisterSignatureHandler</a>. Destroys it by <a>FRCustomSignatureDestroySignatureHandler</a>.
 * @param[in]  callbacks The callback set for signature handler.
 * @return   The pointer to the signature handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void*, FRCustomSignatureCreateSignatureHandler, (FR_SignatureHandlerCallbacks callbacks))

/**
 * @brief FRCustomSignatureRegisterSignatureHandler
 * @details Registers the signature handler. You can customize the process signing the data and the process verifying the digital signature.
 * @param[in]  pSignatureHandler The input pointer to signature handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRCustomSignatureRegisterSignatureHandler, (void* pSignatureHandler))

/**
 * @brief FRCustomSignatureDestroySignatureHandler
 * @details Destroys the signature handler returned by <a>FRCustomSignatureCreateSignatureHandler</a>.
 * @param[in]  pSignatureHandler The input pointer to signature handler.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(void, FRCustomSignatureDestroySignatureHandler, (void* pSignatureHandler))

/**
 * @brief FRCustomSignatureSetSignatureVerify
 * @details Verifies the specified signature.
 * @param[in]  frDoc The input document.
 * @param[in]  pSignedData The signed data.
 * @param[in]  ulSignedDataLen The length of the signed data.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 */
INTERFACE(FS_BOOL, FRCustomSignatureSetSignatureVerify, (FR_Document frDoc,  const unsigned char* pSignedData,  unsigned long ulSignedDataLen))

/**
 * @brief FRCustomSignatureGetDocSigatureCount
 * @details Gets the signature count.
 * @param[in]  frDoc The input document.
 * @return   The signature count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_INT32, FRCustomSignatureGetDocSigatureCount, (FR_Document frDoc))

/**
 * @brief FRCustomSignatureGetSignatureBaseInfo
 * @details Gets the specified base info of the signature.
 * @param[in]  frDoc The input document.
 * @param[in]  nIndex The index of the signature.
 * @param[out]  pInfo It receives the base info of the signature.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRCustomSignatureGetSignatureBaseInfo, (FR_Document frDoc,  FS_INT32 nIndex,  FR_SignatureBaseInfo* pInfo))

/**
 * @brief FRCustomSignatureClearSignature
 * @details Clears the specified signature.
 * @param[in]  frDoc The input document.
 * @param[in]  nIndex The index of the signature.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0
 */
INTERFACE(FS_BOOL, FRCustomSignatureClearSignature, (FR_Document frDoc,  FS_INT32 nIndex))

NumOfSelector(FRCustomSignature)
ENDENUM

//----------_V9----------
//----------_V10----------
