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
/* Tool HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRToolNew
 * @details Creates a tool object.
 * @param[in]  name The tool name. It may not be <a>NULL</a>.
 * @param[in]  callbacks The event callbacks associate with a tool. When a event occurs, Reader will
	* call a corresponding callback function.
 * @return   The new tool object or <a>NULL</a> if the tool with the <param>name</param> is exist.
 * @note If the tool name has been used, <a>NULL</a> will return.
 * @see FRToolRelease
 * @see FRAppRegisterTool
 */
INTERFACE(FR_Tool, FRToolNew, (FS_LPCSTR name,  FR_ToolCallbacks callbacks))

/**
 * @brief FRToolRelease
 * @details Releases the specified tool.
 * @param[in]  tool The tool to release.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolRelease, (FR_Tool tool))

/**
 * @brief FRToolGetName
 * @details Gets the name of specified tool.
 * @param[in]  tool The tool object.
 * @param[out]  outName The tool name buffer,filled by Reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolGetName, (FR_Tool tool,  FS_ByteString* outName))

/**
 * @brief FRToolSetAssociatedMousePtHandlerType
 * @details Sets the type of associated mouse point handler.
 * @param[in]  tool The tool object.
 * @param[out]  lpsType The type of associated mouse point handler.
 * @return   void
 * @note 
 * @see FRAppRegisterMousePtHandler
 */
INTERFACE(void, FRToolSetAssociatedMousePtHandlerType, (FR_Tool tool,  FS_LPCSTR lpsType))

/**
 * @brief FRToolSetAssociatedSelectionHandlerType
 * @details Sets the type of associated selection handler.
 * @param[in]  tool The tool object.
 * @param[out]  lpsType The type of associated selection handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FRToolSetAssociatedSelectionHandlerType, (FR_Tool tool,  FS_LPCSTR lpsType))

NumOfSelector(FRTool)
ENDENUM

//*****************************
/* App HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRAppGetName
 * @details Gets the <a>FS_ByteString</a> corresponding to the application's name, which is the name 
	* of the file containing the Foxit Reader application.
 * @param[out]  outName The string buffer used to receive the name of application. It
	* will be filled by reader.
 * @return   void
 * @note 
 * @see FRAppGetTitle
 */
INTERFACE(void, FRAppGetName, (FS_ByteString* outName))

/**
 * @brief FRAppGetVersion
 * @details Gets the <a>FS_WideString</a> corresponding to the application's version. The Format of version 
	* information is XX.XX.XX.XX(major number.minor number.maintainence number.build number).
 * @param[out]  outVersion The string buffer used to receive the version information of application. 
	* It will be filled by reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppGetVersion, (FS_WideString* outVersion))

/**
 * @brief FRAppGetAppTitle
 * @details Gets the <a>FS_WideString</a> corresponding to the application's title.
 * @param[out]  outTitle The string buffer used to receive the title of application. 
	* It will be filled by reader.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note The user might have changed this, so do not use it to determine what the application is.
	* Use FRAppGetName instead.
 * @see FRAppGetName
 */
INTERFACE(FS_BOOL, FRAppGetAppTitle, (FS_WideString* outTitle))

/**
 * @brief FRAppGetAppDataPath
 * @details Gets the execution file path of current running reader.
 * @param[out]  outAppPath The string buffer used to receive the path which Foxit Reader used to 
	* store some application's data. It will be filled automaticly by reader.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppGetAppDataPath, (FS_WideString* outAppPath))

/**
 * @brief FRAppCanQuit
 * @details Gets the permission to decide whether you can quit.
 * @return   <a>TRUE</a> if foxit reader can quit, <a>FALSE</a> if cannot. The default version of the routine
	* always returns <a>TRUE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppCanQuit, (void))

/**
 * @brief FRAppCountToolbars
 * @details Gets the number of toolbars, including the flyout toolbars.
 * @return   The number of toolbar.
 * @note 
 * @see FRAppGetToolBar
 */
INTERFACE(FS_INT32, FRAppCountToolbars, (void))

/**
 * @brief FRAppGetToolBar
 * @details Gets the specified toolbar.
 * @param[in]  index The index of toolbar to obtain. The index range is 0 to (<a>FRAppCountToolbars</a>()-1).
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The <a>FR_ToolBar</a> object.
 * @note 
 * @see FRAppCountToolbars
 * @see FRAppGetToolBarByName
 */
INTERFACE(FR_ToolBar, FRAppGetToolBar, (FS_INT32 index,  void* pParentWnd))

/**
 * @brief FRAppGetToolBarByName
 * @details Gets toolbar created with the specified name, All toolbars(including flyout toolbar) can be obtained by the method.
 * @param[in]  csName The name of the toolbar.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The <a>FR_ToolBar</a>, or <a>NULL</a> if no <a>FR_ToolBar</a> was found with the specified name.
 * @note 
 * @see FRToolBarSetName
 */
INTERFACE(FR_ToolBar, FRAppGetToolBarByName, (FS_LPCSTR csName,  void* pParentWnd))

/**
 * @brief FRAppGetMenuBar
 * @details Gets Foxit Reader's menu bar.
 * @return   The menu bar.
 * @note 
 */
INTERFACE(FR_MenuBar, FRAppGetMenuBar, (void))

/**
 * @brief FRAppShowMenuBar
 * @details Shows/Hides menu bar.
 * @param[in]  bShow If <a>TRUE</a>, the menu bar will be show, <a>FALSE</a> to hide.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppShowMenuBar, (FS_BOOL bShow))

/**
 * @brief FRAppRegisterTool
 * @details Registers a tool into the Foxit Reader.
 * @param[in]  tool The <a>FR_Tool</a> object containing the tool's callbacks. This object
	* must not be freed after calling <a>FRAppRegisterTool</a>(), but must be remained.
 * @return   
 * @note 
 * @see FRToolNew
 * @see FRAppSetActiveTool
 */
INTERFACE(void, FRAppRegisterTool, (FR_Tool tool))

/**
 * @brief FRAppGetToolByName
 * @details Gets the <a>FR_Tool</a> object that was registered under specified name.
 * @param[in]  csName The tool name.
 * @return   The tool that was registered under name, or <a>NULL</a> if no match was found.
 * @note 
 * @see FRAppGetToolByIndex
 */
INTERFACE(FR_Tool, FRAppGetToolByName, (FS_LPCSTR csName))

/**
 * @brief FRAppCountTools
 * @details Gets the number of registered <a>FR_Tool</a> object.
 * @return   The number of tools.(Including built-in tools)
 * @note 
 * @see FRAppGetToolByIndex
 */
INTERFACE(FS_INT32, FRAppCountTools, (void))

/**
 * @brief FRAppGetToolByIndex
 * @details Gets the specified tool.
 * @param[in]  index The index of tool to obtain. The index range is 0 to (<a>FRAppCountTools</a>()-1).
 * @return   The specified tool.
 * @note 
 * @see FRAppGetToolByName
 * @see FRAppCountTools
 */
INTERFACE(FR_Tool, FRAppGetToolByIndex, (FS_INT32 index))

/**
 * @brief FRAppSetActiveTool
 * @details Sets the active tool. It does nothing if the specified tool is not currently enabled, The
	* <a>FRToolIsEnabled</a>() callback in <a>FR_ToolCallbacksRec</a> structure determines whether a tool is
	* enabled. If this callback is <a>NULL</a>, the tool is always enabled.
 * @param[in]  tool The tool to set as the active tool.
 * @param[in]  persistent A flag that indicates a preference as to whether the tool stays active after
	* it is used. <a>TRUE</a> is a hint that the tool should.if possible, stay active for an arbitrary number 
	* of operations (whatever that happens to be) rather than doing a one shot operation and restoring the 
	* prior active tool.
	*
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRAppRegisterTool
 * @see FRAppGetActiveTool
 */
INTERFACE(FS_BOOL, FRAppSetActiveTool, (FR_Tool tool,  FS_BOOL persistent))

/**
 * @brief FRAppGetActiveTool
 * @details Gets the active tool from the application.
 * @return   The active tool.
 * @note 
 * @see FRAppSetActiveTool
 * @see FRAppRegisterTool
 */
INTERFACE(FR_Tool, FRAppGetActiveTool, (void))

/**
 * @brief FRAppRegisterPreferencePageHandler
 * @details Registers the event notification to preference dialog.
 * @param[in]  preferPageCallbacks The callback set. Reader will call a corresponding callback when the 
	* preference dialog is to be show or to be destroy.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note You must also call <a>FRAppAddPreferencePage</a>() in the <a>FRPrefPageOnCreate</a>() callback to
	* add a preference page to Reader preference dialog.
	*
 * @see FRAppAddPreferencePage
 * @see FRAppShowPreferenceDlg
 */
INTERFACE(FS_BOOL, FRAppRegisterPreferencePageHandler, (FR_PreferPageCallbacks preferPageCallbacks))

/**
 * @brief FRAppAddPreferencePage
 * @details Adds a preference page into Reader preference dialog.
 * @param[in]  parent The parent window.
 * @param[in]  preferPage A platform-specific object.	In windows, it is a HWND handler.
 * @param[in]  title The title of the preference page. It will be displayed on the list box in
	* the left of preference dialog.
 * @return   <a>TRUE</a> for success, or <a>FALSE</a> if the preference page has existed or the title of the page
	* has been used.
 * @note You should call this method in the implementation of <a>FRPrefPageOnCreate</a>() callback.
 * @see FRAppRegisterPreferencePageHandler
 */
INTERFACE(FS_BOOL, FRAppAddPreferencePage, (HWND parent,  HWND preferPage,  FS_LPCWSTR title))

/**
 * @brief FRAppRegisterDocPropertyPageHandler
 * @details Registers the event notification to document properties dialog.
 * @param[in]  docProperPageCallbacks The callback set. Reader will call a corresponding callback when the 
	* document properties dialog is to be show or to be destroy.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note You must also call <a>FRAppAddDocPropertyPage</a>() in the <a>FRDocPropertyPageOnCreate</a>() callback to
	* add a property page to Reader document properties dialog.
 * @see FRAppAddDocPropertyPage
 */
INTERFACE(FS_BOOL, FRAppRegisterDocPropertyPageHandler, (FR_DocPropertypageCallbacks docProperPageCallbacks))

/**
 * @brief FRAppAddDocPropertyPage
 * @details Adds a document property page into Reader document properties dialog.
 * @param[in]  parent The parent window.
 * @param[in]  propertyPage A platform-specific object.	In windows, it is a <Italic>HWND</Italic> handler.
 * @param[in]  title The title of the document property page. It will be displayed on the 
	* tabsheet in the top of document properties dialog.
 * @return   <a>TRUE</a> for success, or <a>FALSE</a> if the property page has existed or the title of the page
	* has been used.
 * @note You should call this method in the implementation of <a>FRDocPropertyPageOnCreate</a>() callback.
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(FS_BOOL, FRAppAddDocPropertyPage, (HWND parent,  HWND propertyPage,  FS_LPCWSTR title))

/**
 * @brief FRAppRegisterNavPanelView
 * @details Registers a navigation panel view into the Foxit Reader.
 * @param[in]  panelViewCallbacks A panel page callback set. When the navigation panel occurs a event, reader will
	* call a corresponding callback to respond.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegisterNavPanelView, (FR_PanelViewCallbacks panelViewCallbacks))

/**
 * @brief FRAppRegisterAppEventHandler
 * @details Registers a user-supplied procedure set to call when some application level event occurs.
 * @param[in]  appEventCallbacks The callback set. Reader will call a corresponding callback when the app event occurs.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegisterAppEventHandler, (FR_AppEventCallbacks appEventCallbacks))

/**
 * @brief FRAppCountDocsOfPDDoc
 * @details Gets the number of document views. This method just only count the document view that for 
	* displaying PDF file type, does not count other document view for displaying other format file.
 * @return   The number of document views that is used to display PDF file type.
 * @note 
 * @see FRAppGetDocOfPDDoc
 */
INTERFACE(FS_INT32, FRAppCountDocsOfPDDoc, (void))

/**
 * @brief FRAppGetDocOfPDDoc
 * @details Gets the document view by specified index.
 * @param[in]  index The index of specified document view with a <a>FPD_Document</a> object.
	* The range is 0 to (CountDocsOfPDDoc()-1);
 * @return   A document window.
 * @note This method just return the document window which for displaying PDF file type, ignore other 
	* format file window.
 * @see FRAppCountDocsOfPDDoc
 * @see FRAppGetActiveDocOfPDDoc
 */
INTERFACE(FR_Document, FRAppGetDocOfPDDoc, (FS_INT32 index))

/**
 * @brief FRAppGetActiveDocOfPDDoc
 * @details Gets the top-most document window which for displaying PDF file type.
 * @return   The top-most document window which is used for displaying PDF file type, or <a>NULL</a> if
	* no documents are open. <a>NULL</a> is also returned while the top-most document window is not displaying
	* PDF file type and while a document is being opened.
 * @note 
 * @see FRAppGetDocOfPDDoc
 * @see FRAppSetActiveDocOfPDDoc
 */
INTERFACE(FR_Document, FRAppGetActiveDocOfPDDoc, ())

/**
 * @brief FRAppSetActiveDocOfPDDoc
 * @details Sets a document view to top-most.
 * @param[in]  doc The <a>FR_Document</a> object.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRAppGetActiveDocOfPDDoc
 * @see FRAppCountDocsOfPDDoc
 * @see FRAppGetDocOfPDDoc
 */
INTERFACE(FS_BOOL, FRAppSetActiveDocOfPDDoc, (FR_Document doc))

/**
 * @brief FRAppRegisterDocHandlerOfPDDoc
 * @details Registers a user-supplied event handler to document window.
 * @param[in]  docEventCallbacks The callback set. Reader will call a corresponding callback when the doc event occurs.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note The callbacks of FR Doc Event Handler just be called while the document window is displaying
	* PDF file type.
 */
INTERFACE(FS_BOOL, FRAppRegisterDocHandlerOfPDDoc, (FR_DocEventCallbacks docEventCallbacks))

/**
 * @brief FRAppIsFullScreen
 * @details Tests whether the application is running in full-screen mode.
 * @return   <a>TRUE</a> if the application is currently in full-screen mode, otherwise not.
 * @note 
 * @see FRAppShowFullScreen
 * @see FRAppEndFullScreen
 */
INTERFACE(FS_BOOL, FRAppIsFullScreen, (void))

/**
 * @brief FRAppShowFullScreen
 * @details Begins full-screen mode. In full-screen mode, all window borders, the menu bar, and the 
	* toolbar are hidden. All regions of the screen outside of the page view boundary are painted by specified
	* color.
	* <a>FRAppShowFullScreen</a>() is ignored if the application is already in full-screen mode, or if there are no
	* currently open documents.
 * @return   <a>TRUE</a> if the application enters full-screen mode; <a>FALSE</a> if it is already in 
	* full-screen mode or the user clicks the cancel button from dialog box describing how to exit the
	* full-screen mode.
 * @note 
 * @see FRAppEndFullScreen
 */
INTERFACE(FS_BOOL, FRAppShowFullScreen, (void))

/**
 * @brief FRAppEndFullScreen
 * @details Ends full-screen mode. It does nothing if the the application is not running in full-screen mode.
 * @return   <a>TRUE</a> if the application exit full-screen mode, otherwise not.
 * @note 
 * @see FRAppShowFullScreen
 */
INTERFACE(FS_BOOL, FRAppEndFullScreen, (void))

/**
 * @brief FRAppGetMousePos
 * @details Gets the mouse position. The mouse position is specified in screen coordinates.
 * @return   The <a>FS_DevicePoint</a> specified in screen coordinates.
 * @note 
 */
INTERFACE(FS_DevicePoint, FRAppGetMousePos, (void))

/**
 * @brief FRAppModalWindowIsOpen
 * @details A client should use this method to determine whether a modal window is open. 
	* There is a large (and ill-defined) group of actions that are illegal while a modal window is open, although 
	* these actions are not programmatically prevented by the Foxit Reader Viewer. While a modal dialog box is  
	* open, a client must not open documents, change pages, change views, close documents, change tools, or do 
	* anything that might disrupt the user or Foxit Reader viewer.
 * @return   <a>TRUE</a> if a modal window is open, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppModalWindowIsOpen, (void))

/**
 * @brief FRAppRegisterSecurityHandler
 * @details Registers a security handler. Invoked this interface to process the PDF documents that 
	* are encrypted by customer security handler.
 * @param[in]  name The name of the security handler.
 * @param[in]  callbacks The structure containing the security handler callback functions.
 * @return   void
 * @note 
 * @see FRAppUnRegisterSecurityHandler
 */
INTERFACE(void, FRAppRegisterSecurityHandler, (FS_LPCSTR name,  FR_SecurityCallbacks callbacks))

/**
 * @brief FRAppUnRegisterSecurityHandler
 * @details Unregisters a security handler.
 * @param[in]  name The name of the security handler.
 * @return   void
 * @note 
 * @see FRAppRegisterSecurityHandler
 */
INTERFACE(void, FRAppUnRegisterSecurityHandler, (FS_LPCSTR name))

/**
 * @brief FRAppGetPassPhrase
 * @details This interface is invoked by the plug-in to confirm that the host environment is Foxit Reader and is legal.
	*          The following steps show the procedure:<br>
	*			<ul>
	*			<li>1. Plug-in generates a random string of 128 byte length and encrypts it using the public key. </li>
	*			<li>2. Plug-in allocates one buffer of 128 bytes and calls <a>FRAppGetPassPhrase</a>() and passes the encrypted string.</li>
	*			<li>3. Foxit reader will decrypt the encrypted text using the private key and copy it to the buffer <param>pstrPlainText</param>.</li>
	*			<li>4. Plug-in matches the plain text against what it had generated. </li>
	*			</ul>
 * @param[in]  pstrEncryptedText An encrypted random string of 128 byte.
 * @param[out]  ppstrPlainText It receives the plain text from Foxit Reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppGetPassphrase, (FS_LPCSTR pstrEncryptedText,  FS_LPSTR* ppstrPlainText))

/**
 * @brief FRAppRegisterContentProvider
 * @details Registers a content provider so that the plug-in can process the protected document and provide decrypted
	* document data.
 * @param[in]  contentProviderCallbacks The content provider callbacks.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegisterContentProvider, (FR_ContentProviderCallbacks contentProviderCallbacks))

/**
 * @brief FRAppGetMainFrameWnd
 * @details Gets the main frame window of Foxit Reader.
 * @return   A <Italic>HWND</Italic> object for windows.
 * @note 
 */
INTERFACE(HWND, FRAppGetMainFrameWnd, (void))

/**
 * @brief FRAppAddUndoRedoItem
 * @details Adds a undo-redo item to the specified document.
 * @param[in]  lpwDescr The input description of the undo-redo item.
 * @param[in]  frDoc The specified document.
 * @param[in]  bEdit Whether the current operation is editing, for example, you add a typewriter and enter characters.
 * @param[in]  callbacks The user-supplied callbacks for implementing undo-redo.
 * @return   void
 * @note 
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
 */
INTERFACE(void, FRAppAddUndoRedoItem, (FS_LPCWSTR lpwDescr,  FR_Document frDoc,  FS_BOOL bEdit,  FR_UndoRedoCallbacks callbacks))

/**
 * @brief FRAppRegisterPageHandlerOfPDDoc
 * @details Registers a page-level event callback set.
 * @param[in]  callbacks The callback set. Reader will call a corresponding callback when the page event occurs.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegisterPageHandlerOfPDDoc, (FR_PageEventCallbacks callbacks))

/**
 * @brief FRAppRegisterForContextMenuAddition
 * @details 
 * @param[in]  menuName The name of the context menu to modify. Its names can be one of the 
	* following:<br>
	* <ul><li>Name - Description</li>
	* <li>Page - The standard context menu for an FR_PageView.</li>
	* <li>Select - The context menu for selected text.</li>
	* <li>Snapshot - The context menu for snapshot of FR_PageView.</li>
 * @param[in]  proc The user-supplied procedure to call.
 * @param[in]  clientData A pointer to user-supplied data to pass to the procedure each time it 
	* is called.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegisterForContextMenuAddition, (FS_LPCSTR csName,  FRContextMenuPopUpProc proc,  void* pClientData))

/**
 * @brief FRAppRegisterSelectionHandler
 * @details Registers a new selection handler. Selection handlers allow the selection of items 
	* other than those that can be selected in the as-shipped Foxit viewer. For example, a selection handler 
	* could allow a user to select a sampled image.
    * This method can be used to replace an existing selection handler that handles the same selection type.
 * @param[in]  callbacks A structure containing the selection handler's callback functions. This structure 
    * must not be freed after calling <a>FRAppRegisterSelectionHandler</a>().
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note Call FRAppUnRegisterSelectionHandler to unregister the selection handler and release the memory.
 */
INTERFACE(FS_BOOL, FRAppRegisterSelectionHandler, (FR_SelectionCallbacks callbacks))

/**
 * @brief FRAppUnRegisterSelectionHandler
 * @details Unregisters the selection handler and releases the memory.
 * @param[in]  callbacks A structure containing the selection handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppUnRegisterSelectionHandler, (FR_SelectionCallbacks callbacks))

/**
 * @brief FRAppRegisterCaptureHandler
 * @details Registers the capture handler.
 * @param[in]  callbacks A structure containing the capture handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegisterCaptureHandler, (FR_CaptureCallbacks callbacks))

/**
 * @brief FRAppUnRegisterCaptureHandler
 * @details Unregisters the capture handler and releases the memory.
 * @param[in]  callbacks A structure containing the capture handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppUnRegisterCaptureHandler, (FR_CaptureCallbacks callbacks))

/**
 * @brief FRAppRegistryGetProfilePath
 * @details Gets the registry's profile path of the Foxit Reader.
 * @param[out]  outProfilePath It receives the registry's profile path of the Foxit Reader.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryGetProfilePath, (FS_WideString* outProfilePath))

/**
 * @brief FRAppRegistryWriteInt
 * @details Write int value to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  nValue The input int value.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteInt, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_INT32 nValue))

/**
 * @brief FRAppRegistryWriteBinary
 * @details Write binary value to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSection</param> can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  pData The input binary data.
 * @param[in]  nValue The size of the binary data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteBinary, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_LPBYTE pData,  unsigned int nBytes))

/**
 * @brief FRAppRegistryWriteString
 * @details Write string to the specified registry. If you want to set the value in registry like 
	* <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link"</Italic>,
	* <param>lpszSectio</param>n can be set as <Italic>"Create Link"</Italic>.
	* If you want to set the value in registry like <Italic>"HKEY_CURRENT_USER\Software\Foxit Software\Foxit Reader\plugins\Create Link\Annot\"</Italic>
	* <param>lpszSection</param> can be set as <Italic>"Create Link\\Annot"</Italic>.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[in]  lpszValue The input string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryWriteString, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_LPCWSTR lpszValue))

/**
 * @brief FRAppRegistryGetInt
 * @details Gets the int value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @return   The int value in the specified section.
 * @note 
 */
INTERFACE(UINT, FRAppRegistryGetInt, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry))

/**
 * @brief FRAppRegistryGetBinary
 * @details Gets the binary value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[out]  ppData It receives the binary data.
 * @param[out]  pBytes It receives the size of the binary data.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetBinary, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  unsigned char** ppData,  unsigned int* pBytes))

/**
 * @brief FRAppRegistryGetString
 * @details Gets the string value in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @param[out]  outString It receives the string.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetString, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry,  FS_WideString* outString))

/**
 * @brief FRAppRegistryGetEntryCount
 * @details Gets the entry count in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   The entry count in the specified section.
 * @note 
 */
INTERFACE(FS_INT32, FRAppRegistryGetEntryCount, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryGetEntryName
 * @details Gets the entry name in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  nIndex The specified index.
 * @param[out]  outName It receives the entry name.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppRegistryGetEntryName, (FS_LPCWSTR lpszSection,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRAppRegistryRemoveSection
 * @details Removes the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryRemoveSection, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryRemoveEntry
 * @details Removes the specified entry.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  lpszEntry The input registry entry.
 * @return   void
 * @note 
 */
INTERFACE(void, FRAppRegistryRemoveEntry, (FS_LPCWSTR lpszSection,  FS_LPCWSTR lpszEntry))

/**
 * @brief FRAppGetGEModule
 * @details Gets the app GE module.
 * @return   The app GE module.
 * @note 
 */
INTERFACE(void*, FRAppGetGEModule, (void))

/**
 * @brief FRAppGetModuleMgr
 * @details Gets the app module manager.
 * @return   The app module manager.
 * @note 
 */
INTERFACE(void*, FRAppGetModuleMgr, (void))

/**
 * @brief FRAppCreateAnEmptyFrameWnd
 * @details Creates a new frame window.
 * @param[in]  title The title of the frame which will be created.
 * @param[in]  bMakeVisible A flag indicate whether to show the frame.
 * @param[in]  notify The notifies for new window.
 * @return   The handler of the newly created frame.
 * @note 
 */
INTERFACE(HWND, FRAppCreateAnEmptyFrameWnd, (FS_WideString title,  FS_BOOL bMakeVisible,  FR_EmptyFramWndNotifies notify))

/**
 * @brief FRAppIsRunEmbedded
 * @details Tests whether the Foxit Reader is running embedded or not.
 * @return   <a>TRUE</a> for running embedded, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppIsRunEmbedded, (void))

/**
 * @brief FRAppRegisterExtraPrintInfoProvider
 * @details Register the printing notifies.
 * @param[in]  callbacks The callbacks which will be broadcast.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRAppRegisterExtraPrintInfoProvider, (FR_ExtraPrintInfoProviderCallbacks callbacks))

/**
 * @brief FRAppIsRibbonMode
 * @details Tests whether current toolbar mode is tabbed mode.
 * @return   <a>TRUE</a> if current toolbar mode is tabbed mode, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppIsRibbonMode, (void))

/**
 * @brief FRAppGetStartMenuOfTabbedToobarMode
 * @details Gets the start menu which is in tabbed toolbar mode.
 * @return   A <a>FR_Menu</a> object indicates the start menu of tabbed toolbar mode. <a>NULL</a> if
	*				current toolbar mode is not tabbed mode.
 * @note If a <a>FR_Menu</a> is added into a exist menu in commonent toolbar mode, and need add into the start menu,
	*		call <a>FRAppIsRibbonMode</a>() first, then call <a>FRAppGetStartMenuOfTabbedToobarMode</a>() to get the start
	*		menu and add the menu item to start menu again.
 */
INTERFACE(FR_Menu, FRAppGetStartMenuOfTabbedToobarMode, (void))

/**
 * @brief FRAppRegisterTaskPaneView
 * @details Registers callback set for a task pane view.
 * @param[in]  callbacks The callback set for a task pane view.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppShowTaskPane
 */
INTERFACE(FS_BOOL, FRAppRegisterTaskPaneView, (FR_TaskPaneViewCallbacks paneView))

/**
 * @brief FRAppShowTaskPane
 * @details Shows or hidden a task panel view.
 * @param[in]  nameOfPaneView The name of the pane view which would be shown or hidden.
 * @param[in]  bShow A flag indicates whether the pane view specified by <param>nameOfPaneView</param> should be
	* shown or hidden.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterTaskPaneView
 */
INTERFACE(void, FRAppShowTaskPane, (FS_LPSTR nameOfPaneView,  FS_BOOL bShow))

/**
 * @brief FRAppGetTaskPaneWndHandleByDoc
 * @details Gets the window handle of the task pane.
 * @param[in]  frDoc The document associated with the task pane.
 * @return   The window handle of the task pane.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterTaskPaneView
 */
INTERFACE(HWND, FRAppGetTaskPaneWndHandleByDoc, (FR_Document frDoc))

/**
 * @brief FRAppCommandLineHasSwitch
 * @details Checks whether the <param>pwszSwitch</param> exists.
 * @param[in]  pwszSwitch The switch name to be checked.
 * @return   <a>TRUE</a> if the switch exists, otherwise <a>FALSE</a>
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppOnRunCommandLine
 */
INTERFACE(FS_BOOL, FRAppCommandLineHasSwitch, (FS_LPCWSTR pwszSwitch))

/**
 * @brief FRAppCommandLineGetSafeArgument
 * @details Gets the specified argument. If the specified argument is not existing, the default value will be returned.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @param[in]  iIndex The index of the arguments.
 * @param[in]  pwszDefault The default value of argument. If the specified argument is not existing, the default value will be returned.
 * @param[out]  outArgument It receives the argument.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppCommandLineGetSafeArgument, (FS_LPCWSTR pwszSwitch,  FS_INT32 iIndex,  FS_LPCWSTR pwszDefault,  FS_WideString* outArgument))

/**
 * @brief FRAppCommandLineGetArgument
 * @details Gets the specified argument.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @param[in]  iIndex The index of the arguments.
 * @param[out]  outArgument It receives the argument.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppCommandLineGetArgument, (FS_LPCWSTR pwszSwitch,  FS_INT32 iIndex,  FS_WideString* outArgument))

/**
 * @brief FRAppCommandLineGetArgumentCount
 * @details Gets the count of the argument.
 * @param[in]  pwszSwitch The switch name to which the argument belongs.
 * @return   The count of the argument.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FRAppCommandLineGetArgumentCount, (FS_LPCWSTR pwszSwitch))

/**
 * @brief FRAppRegisterWinMSGHandler
 * @details Registers callback set for a windows MSG handler.
 * @param[in]  callbacks The callback set for a windows MSG handler.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppRegisterWinMSGHandler, (FR_WinMSGCallbacks callbacks))

/**
 * @brief FRAppGetRecentFileList
 * @details Gets the recent opened file list.
 * @param[out]  pArrFileList It receives the recent opened file list.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppGetRecentFileList, (FS_WideStringArray* pArrFileList))

/**
 * @brief FRAppAddFileToRecentFileList
 * @details Adds the recent opened file path to the list.
 * @param[in]  lpszPathName The recent opened file path.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppAddFileToRecentFileList, (FS_LPCWSTR lpszPathName))

/**
 * @brief FRAppClearRecentFileList
 * @details Clears the recent opened file list.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppClearRecentFileList, ())

/**
 * @brief FRAppRegisterSecurityMethod
 * @details Registers the security method that you can manage your security method.
 * @param[in]  cllbcks The callback set for security method.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppRegisterSecurityMethod, (FR_SecurityMethodCallbacks cllbcks))

/**
 * @brief FRAppPopDocPropertyPage
 * @details Pops up the doc property pages.
 * @param[in]  PageShowName The property page you want to display.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(void, FRAppPopDocPropertyPage, (FS_LPCWSTR PageShowName))

/**
 * @brief FRAppCountDocPropertyPages
 * @details Counts the doc property pages.
 * @param[in]  hParent The parent window.
 * @return   The count of doc property pages.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterDocPropertyPageHandler
 */
INTERFACE(FS_INT32, FRAppCountDocPropertyPages, (HWND hParent))

/**
 * @brief FRAppCheckModuleLicense
 * @details Checks whether you have license to the module.
 * @param[in]  lpwszModuleName The input module name.
 * @return   Returns <a>TRUE</a> if you have license to the module.
 * @note This is an internal interface.
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppCheckModuleLicense, (FS_LPCWSTR lpwszModuleName))

/**
 * @brief FRAppRegisterOwnerFileType
 * @details Adds a file type to Foxit Reader. You can control the process of owner file type, 
	* such as opening, saving, sending email and so on.
 * @param[in]  callbacks The callback set for the owner file type handler.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppRegisterOwnerFileType, (FR_OwnerFileTypeHandlerCallbacks callbacks))

/**
 * @brief FRAppRegistryGetKeyCounts
 * @details Gets the counts of key for the specified section.
 * @param[in]  lpszSection The input registry section.
 * @return   The counts of key for the specified section.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegistryGetProfilePath
 */
INTERFACE(FS_INT32, FRAppRegistryGetKeyCounts, (FS_LPCWSTR lpszSection))

/**
 * @brief FRAppRegistryGetKeyName
 * @details Gets the key name in the specified section.
 * @param[in]  lpszSection The input registry section.
 * @param[in]  nIndex The specified index.
 * @param[out]  outName It receives the key name.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegistryGetProfilePath
 */
INTERFACE(FS_BOOL, FRAppRegistryGetKeyName, (FS_LPCWSTR lpszSection,  FS_INT32 nIndex,  FS_WideString* outName))

/**
 * @brief FRAppGetRibbonBar
 * @details Gets Foxit Reader's ribbon bar.
 * @param[in]  pParentWnd A pointer to the parent window. It represents the <Italic>MFC CWnd*</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_RibbonBar, FRAppGetRibbonBar, (void* pParentWnd))

/**
 * @brief FRAppGetRibbonBarBackGroundColor
 * @details Gets the back ground color of ribbon bar.
 * @return   The back ground color of ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBarBackGroundColor, (void))

/**
 * @brief FRAppGetRibbonBarBtnBackGroundColor
 * @details Gets the back ground color of ribbon bar button.
 * @param[in]  bIsHighlighted Whether the button is highlighted.
 * @param[in]  bIsPressed Whether the button is pressed.
 * @return   The back ground color of ribbon bar button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBarBtnBackGroundColor, (FS_BOOL bIsHighlighted,  FS_BOOL bIsPressed))

/**
 * @brief FRAppLoadLibrary
 * @details Load the library.
 * @param[in]  lpwsFileName Specifies the file name of library.
 * @param[in]  nDirectoryType The directory type.
 * @return   The library handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void*, FRAppLoadLibrary, (FS_LPCWSTR lpwsFileName,  FRDirectoryType nDirectoryType))

/**
 * @brief FRAppIsCurDocShowInBrowser
 * @details Tests whether the current document is opened in browser or not.
 * @return   <a>TRUE</a> for running in browser, otherwise <a>FALSE</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppIsCurDocShowInBrowser, ())

/**
 * @brief FRAppRemoveFileFromRecentFileList
 * @details Removes the recent opened file path from the list.
 * @param[in]  nIndex The index of recent opened file path to be removed.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 */
INTERFACE(void, FRAppRemoveFileFromRecentFileList, (FS_INT32 nIndex))

/**
 * @brief FRAppCreateCustomRecentFileList
 * @details Creates a custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  lpwsFileExt The extension of files that will be added to the recent file list.
 * @param[in]  pItemBitmap The icon that will be displayed in front of the recent file list label.
 * @param[in]  lpwsLabel The input label of recent file list.
 * @param[in]  nMaxSize The input max size of recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppCreateCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFileExt,  FS_DIBitmap pItemBitmap,  FS_LPCWSTR lpwsLabel,  FS_INT32 nMaxSize))

/**
 * @brief FRAppRemoveFileFromCustomRecentFileList
 * @details Removes the recent file path from the specified recent file list.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list from which the recent file path will be removed.
 * @param[in]  lpwsFilePath The recent file path that will be removed.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppRemoveFileFromCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath))

/**
 * @brief FRAppAddFileToCustomRecentFileList
 * @details Adds the recent file to the custom recent file list.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list which the recent file path will be added to.
 * @param[in]  lpwsFilePath The recent file path that will be added.
 * @param[in]  lpwsFileTitle Instead of the file path, the title will be displayed in the recent file list.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @param[in]  exeProc When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
 * @param[in]  clientData The client data that will be passed to the callback.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppAddFileToCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath,  FS_LPCWSTR lpwsFileTitle,  FS_LPCWSTR lpwsFileTooltip,  FRAppCustomRecentFileExecuteProc exeProc,  void* clientData))

/**
 * @brief FRAppClearCustomRecentFileList
 * @details Clears the recent files from the recent file list.
 * @param[in]  csRecentListName The name that specifies the custom recent file list whose recent files will be cleared.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(void, FRAppClearCustomRecentFileList, (FS_LPCSTR lpsRecentFileListName))

/**
 * @brief FRAppRegisterMousePtHandler
 * @details Registers the mouse point handler.
 * @param[in]  callbacks A structure containing the mouse point handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @see FRToolSetAssociatedMousePtHandlerType
 */
INTERFACE(FS_BOOL, FRAppRegisterMousePtHandler, (FR_MousePtCallbacks callbacks))

/**
 * @brief FRAppUnRegisterMousePtHandler
 * @details Unregisters the mouse point handler and releases the memory.
 * @param[in]  callbacks A structure containing the mouse point handler's callback functions.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FRAppUnRegisterMousePtHandler, (FR_MousePtCallbacks callbacks))

/**
 * @brief FRAppIsLicenseValidOrInTrial
 * @details Checks whether the license is valid or is in trial.
 * @return   Checks whether the license is valid or is in trial.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRAppIsLicenseValidOrInTrial, ())

/**
 * @brief FRAppShowPreferenceDlg
 * @details Shows the preference dialog.
 * @param[in]  lpwsTabTitle 
 * @return   The result when user clicks ok button or cancel button.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterPreferencePageHandler
 */
INTERFACE(FS_INT32, FRAppShowPreferenceDlg, (FS_LPCWSTR lpwsTabTitle))

/**
 * @brief FRAppUndoRedoIsEditing
 * @details Checks whether the document is being edited.
 * @param[in]  frDoc The specified document.
 * @return   <a>TRUE</a> means the document is being edited, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
 */
INTERFACE(FS_BOOL, FRAppUndoRedoIsEditing, (FR_Document frDoc))

/**
 * @brief FRAppUndoRedoBeginEdit
 * @details When you begin to edit detail content, such as text, and you don't want to save all the editing operation to save memory, 
	* you can invoke this interface. We call it the editing mode undo-redo control.
 * @param[in]  frDoc The specified document.
 * @param[in]  pExitEditProc The callback will be invoked when you exit the editing mode. Then you can release the data.
 * @param[in]  clientData The client data passed to the exiting callback.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoEndEdit
 */
INTERFACE(void, FRAppUndoRedoBeginEdit, (FR_Document frDoc,  FRAppUndoRedoExitEditProc pExitEditProc,  void* clientData))

/**
 * @brief FRAppUndoRedoEndEdit
 * @details When you exit the editing mode, invoke this interface to exit the editing mode undo-redo control.
 * @param[in]  frDoc The specified document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoBeginEdit
 */
INTERFACE(void, FRAppUndoRedoEndEdit, (FR_Document frDoc))

/**
 * @brief FRAppRegisterWndProvider
 * @details Registers a window provider to create a window above the document view. 
	* There are already some windows above the document view, such as PDF view, text view, ruler view.
 * @param[in]  callbacks The input callbacks used to control the window, it tells you when to create the window handle, when to show the window, when to scroll the window, and so on.
 * @return   The returned value is reserved.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocSetCurrentWndProvider
 * @see FRDocGetCurrentWndProvider
 * @see FRAppUnRegisterWndProvider
 */
INTERFACE(void*, FRAppRegisterWndProvider, (FR_WndProviderCallbacks callbacks))

/**
 * @brief FRAppUnRegisterWndProvider
 * @details Unregisters the window provider by name.
 * @param[in]  name The input name of the window provider.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRAppRegisterWndProvider
 */
INTERFACE(FS_BOOL, FRAppUnRegisterWndProvider, (FS_LPCSTR name))

/**
 * @brief FRAppGetEditionType
 * @details Gets the edition type. There are five types, Business, Standard, Express, Enterprise and Free.
 * @param[out]  outType It receives the type value.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FRAppGetEditionType, (FS_ByteString* outType))

/**
 * @brief FRAppGetRecentFileListSize
 * @details Gets the recent file list size.
 * @return   The recent file list size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppGetRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFileListSize, (void))

/**
 * @brief FRAppGetModuleFileName
 * @details Gets the module file name of application.
 * @param[out]  outModuleFileName The string buffer used to receive the module file name of application.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRAppGetModuleFileName, (FS_WideString* outModuleFileName))

/**
 * @brief FRAppGetToolbarLocked
 * @details Checks whether the toolbar is locked.
 * @return   <a>TRUE</a> means the toolbar is locked.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppSetToolbarLocked
 */
INTERFACE(FS_BOOL, FRAppGetToolbarLocked, (void))

/**
 * @brief FRAppSetToolbarLocked
 * @details Sets the toolbar to be locked or not.
 * @param[in]  bLock <a>TRUE</a> means the toolbar will be locked, otherwise not.
 * @param[in]  bRecalcLayout <a>TRUE</a> means the layout of toolbar will be recalced, otherwise not. Sets it <a>TRUE</a> as default.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppSetToolbarLocked
 */
INTERFACE(void, FRAppSetToolbarLocked, (FS_BOOL bLock,  FS_BOOL bRecalcLayout))

/**
 * @brief FRAppRegisterCmdMsgEventHandler
 * @details Registers a callbacks called by the Foxit Reader to route and dispatch command messages and to handle the update of command user-interface objects, such as menu, toolbar.
 * @param[in]  callbacks The input callbacks.
 * @return   The cmd msg event handler can be used to unregister by <a>FRAppUnRegisterCmdMsgEventHandler</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppUnRegisterCmdMsgEventHandler
 */
INTERFACE(void*, FRAppRegisterCmdMsgEventHandler, (FR_CmdMsgEventCallbacks callbacks))

/**
 * @brief FRAppUnRegisterCmdMsgEventHandler
 * @details Unregisters the input cmd msg event.
 * @param[in]  cmdMsgEventHandler The input cmd msg event handler returned by <a>FRAppRegisterCmdMsgEventHandler</a>.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterCmdMsgEventHandler
 */
INTERFACE(FS_BOOL, FRAppUnRegisterCmdMsgEventHandler, (void* cmdMsgEventHandler))

/**
 * @brief FRAppRemoveTaskPanelByName
 * @details Removes the specified task panel.
 * @param[in]  nameOfPaneView The input name of task panel to be removed.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterTaskPaneView
 * @see FRAppShowTaskPane
 */
INTERFACE(FS_BOOL, FRAppRemoveTaskPanelByName, (FS_LPSTR nameOfPaneView))

/**
 * @brief FRAppDisableAllPanel
 * @details Disables all the navigation panels or not.
 * @param[in]  bDisable <a>TRUE</a> means all the navigation panels will be disabled, otherwise not.
 * @param[in]  hFrameWnd The child frame window. Set it as NULL to use the current child frame window.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 */
INTERFACE(void, FRAppDisableAllPanel, (FS_BOOL bDisable,  HWND hFrameWnd))

/**
 * @brief FRAppIsDisableAllPanel
 * @details Checks whether all the panels are disabled.
 * @param[in]  hFrameWnd The child frame window. Set it as NULL to use the current child frame window.
 * @return   <a>TRUE</a> means all the panels are disabled, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppDisableAllPanel
 */
INTERFACE(FS_BOOL, FRAppIsDisableAllPanel, (HWND hFrameWnd))

/**
 * @brief FRAppGetPageContextMenuPos
 * @details Gets the position of context menu on the page view.
 * @param[out]  outPoint It receives the position.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterForContextMenuAddition
 */
INTERFACE(FS_BOOL, FRAppGetPageContextMenuPos, (FS_DevicePoint* outPoint))

/**
 * @brief FRAppOnCmdMsgByName
 * @details Routes and dispatches command messages from plug-ins to plug-ins
 * @param[in]  lpsName The name of menu or toolbar whose command messages need to be routed and dispatched.
 * @param[in]  nCode References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
 * @param[in]  pExtra References to <Italic>MFC CCmdTarget::OnCmdMsg</Italic>.
 * @param[in]  pHandlerInfo It represents the <Italic>MFC</Italic> struct <Italic>AFX_CMDHANDLERINFO</Italic>.
 * @return   Nonzero if the message is handled; otherwise 0.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppRegisterCmdMsgEventHandler
 */
INTERFACE(FS_BOOL, FRAppOnCmdMsgByName, (FS_LPCSTR lpsName,  FS_INT32 nCode,  void* pExtra,  void* pHandlerInfo))

/**
 * @brief FRAppSetOwnUndoMode
 * @details Sets the own undo mode.
 * @param[in]  frDoc The input document.
 * @param[in]  bOwnUndoMode <a>TRUE</a> if you want to sets the own undo mode, otherwise not.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
 */
INTERFACE(void, FRAppSetOwnUndoMode, (FR_Document frDoc,  FS_BOOL bOwnUndoMode))

/**
 * @brief FRAppExitOwnUndoMode
 * @details Exits the own undo mode.
 * @param[in]  frDoc The input document.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRAppAddUndoRedoItem
 * @see FRAppUndoRedoIsEditing
 * @see FRAppUndoRedoBeginEdit
 * @see FRAppUndoRedoEndEdit
 */
INTERFACE(void, FRAppExitOwnUndoMode, (FR_Document frDoc))

/**
 * @brief FRAppRegisterActionHandler
 * @details Registers an action handler. The callbacks are called by Foxit Reader when the Foxit Reader will do the actions. You 
	* can implement your own process to customize the action process.
 * @param[in]  callbacks The callbacks for action handler.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_BOOL, FRAppRegisterActionHandler, (FR_ActionHandlerCallbacks callbacks))

/**
 * @brief FRAppRedrawRecentFileList
 * @details Redraws the recent file list in Ribbon mode.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 */
INTERFACE(FS_BOOL, FRAppRedrawRecentFileList, (void))

/**
 * @brief FRAppSetCustomRecentFileListLabel
 * @details Sets the label of the custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  lpwsLabel The input label of recent file list.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListLabel, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsLabel))

/**
 * @brief FRAppSetCustomRecentFileListItemBitmap
 * @details Sets the icon that will be displayed in front of the recent file list label.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  pItemBitmap The icon that will be displayed in front of the recent file list label.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemBitmap, (FS_LPCSTR lpsRecentFileListName,  FS_DIBitmap pItemBitmap))

/**
 * @brief FRAppSetCustomRecentFileListMaxSize
 * @details Sets the max size of recent file list item.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nMaxSize The input max size of recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListMaxSize, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nMaxSize))

/**
 * @brief FRAppSetCustomRecentFileListItemTitle
 * @details Sets the title of the recent file list item.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nIndex The index of the recent file list item.
 * @param[in]  lpwsFileTitle The title of the recent file list item.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemTitle, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex,  FS_LPCWSTR lpwsFileTitle))

/**
 * @brief FRAppSetCustomRecentFileListItemTooltip
 * @details Sets the tooltip of the recent file.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @param[in]  nIndex The index of the recent file list item.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_BOOL, FRAppSetCustomRecentFileListItemTooltip, (FS_LPCSTR lpsRecentFileListName,  FS_INT32 nIndex,  FS_LPCWSTR lpwsFileTooltip))

/**
 * @brief FRAppGetCustomRecentFileListItemCount
 * @details Gets the item count of the custom recent file list.
 * @param[in]  lpsRecentFileListName The input custom recent file list name.
 * @return   The item count of the custom recent file list.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.3
 * @see FRAppCreateCustomRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetCustomRecentFileListItemCount, (FS_LPCSTR lpsRecentFileListName))

/**
 * @brief FRAppIsRTLLanguage
 * @details Checks whether the current language of app is right-to-left or not.
 * @return   TRUE if the current language of app is right-to-left, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FRAppIsRTLLanguage, (void))

/**
 * @brief FRAppGetOEMVersion
 * @details Gets the OEM version name.
 * @param[out]  outOEMVersion It receives the OEM version name. See <a>FROEMVersion</a>.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FRAppGetOEMVersion, (FS_ByteString* outOEMVersion))

/**
 * @brief FRAppRegisterDataCollectionHadler
 * @details Registers the data collection handler to collect the data as you need.
 * @param[in]  callbacks The callbacks for data collection handler.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppCollectNormalData
 */
INTERFACE(void, FRAppRegisterDataCollectionHadler, (FR_DataCollectionHandlerCallbacks callbacks))

/**
 * @brief FRAppGetUIParentWndByTaskPane
 * @details Gets the UI parent window handle.
 * @param[in]  taskPaneHwnd The window handle of the task pane.
 * @return   The UI parent window handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRAppRegisterTaskPaneView
 */
INTERFACE(HWND, FRAppGetUIParentWndByTaskPane, (HWND taskPaneHwnd))

/**
 * @brief FRAppAdvWndSetCustomize
 * @details Sets whether to customize the advertisement.
 * @param[in]  bCustomize Whether to customize the advertisement.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(void, FRAppAdvWndSetCustomize, (FS_BOOL bCustomize))

/**
 * @brief FRAppGetAdvWnd
 * @details Gets the window handle to show the advertisement.
 * @return   The window handle to show the advertisement.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(HWND, FRAppGetAdvWnd, ())

/**
 * @brief FRAppShowAdvWnd
 * @details Shows the advertisement window or not.
 * @param[in]  nAdvWidth The width of the advertisement window. Sets it as 0 to hide the advertisement window.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRAppShowAdvWnd, (FS_INT32 nAdvWidth))

/**
 * @brief FRAppRegisterPOEventHandler
 * @details Registers a callbacks called by the Foxit Reader to do the page organizing, such as adding pages, deleting pages, replacing pages and so on.
 * @param[in]  callbacks The input callbacks.
 * @return   TRUE for success, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see 
 */
INTERFACE(FS_BOOL, FRAppRegisterPOEventHandler, (FR_POEventCallbacks callbacks))

/**
 * @brief FRAppCreateBlankDoc
 * @details Creates a blank document.
 * @param[in]  fWidth The width of the page in the blank document.
 * @param[in]  fHeight The height of the page in the blank document.
 * @return   The blank document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(FR_Document, FRAppCreateBlankDoc, (FS_FLOAT fWidth,  FS_FLOAT fHeight))

/**
 * @brief FRAppGetLocalFontName
 * @details Gets the local font name.
 * @param[out]  outFontName It receives the local font name.
 * @return   The local font name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRAppGetLocalFontName, (FS_WideString* outFontName))

/**
 * @brief FRAppReLoadStartPage
 * @details Reloads the start page.
 * @param[in]  lpwsPath The input path of the start page.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 * @see 
 */
INTERFACE(void, FRAppReLoadStartPage, (FS_LPCWSTR lpwsPath))

/**
 * @brief FRAppSetRecentFileListImageByExt
 * @details Sets the image of the file in the recent file list.
 * @param[in]  lpwsFileExt The input file extension name, of which you want to change the image in the recent file list.
 * @param[in]  fileImage The input image.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 */
INTERFACE(FS_BOOL, FRAppSetRecentFileListImageByExt, (FS_LPCWSTR lpwsFileExt,  FS_DIBitmap fileImage))

/**
 * @brief FRAppGetCurMeasurementUnits
 * @details Gets the current measurement unites.
 * @return   The current measurement unites.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 3.0
 */
INTERFACE(FS_INT32, FRAppGetCurMeasurementUnits, (void))

/**
 * @brief FRAppGetNavPanelViewByName
 * @details Gets the window handle of the navigation panel view.
 * @param[in]  hChildfrm The child frame the navigation panel belongs to. You can invoke <a>FRDocGetDocFrameHandler</a> to get the child frame.
 * @param[in]  lpsName The input name of the navigation panel.
 * @return   The window handle of the navigation panel view.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppRegisterNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(HWND, FRAppGetNavPanelViewByName, (HWND hChildfrm,  FS_LPCSTR lpsName))

/**
 * @brief FRAppGetNavPanelNameByIndex
 * @details Gets the name of the navigation panel.
 * @param[in]  nIndex The input index of the navigation panel.
 * @param[out]  outName It receives the name of the navigation panel.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppRegisterNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(void, FRAppGetNavPanelNameByIndex, (FS_INT32 nIndex,  FS_ByteString* outName))

/**
 * @brief FRAppGetNavPanelCount
 * @details Gets the count of the navigation panel.
 * @return   The count of the navigation panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 * @see FRAppRegisterNavPanelView
 * @see FRAppDisableAllPanel
 */
INTERFACE(FS_INT32, FRAppGetNavPanelCount, ())

/**
 * @brief FRAppGetStartAppMode
 * @details Gets the app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
 * @return   The app starting mode, 0 for not open any documents, and 1 for opening some documents at the same time.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_INT32, FRAppGetStartAppMode, ())

/**
 * @brief FRAppRestartProcess
 * @details Restarts the process of Foxit Reader or Foxit PhantomPDF.
 * @param[in]  bReOpenFile Whether to reopen the files or not.
 * @param[in]  bDelay Whether to delay the request or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRAppRestartProcess, (FS_BOOL bReOpenFile,  FS_BOOL bDelay))

/**
 * @brief FRAppGetStatusBarBkGroundColor
 * @details Gets the back ground color of status bar in ribbon mode.
 * @return   The back ground color of status bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_COLORREF, FRAppGetStatusBarBkGroundColor, ())

/**
 * @brief FRAppGetStatusBarBkGroundPath
 * @details Gets the path of the back ground color picture of the status bar in classic mode.
 * @param[out]  outPath It receives the path of the back ground color picture of the status bar in classic mode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRAppGetStatusBarBkGroundPath, (FS_WideString* outPath))

/**
 * @brief FRAppCountAllTypesVisibleDocuments
 * @details Gets the count of the visible documents of all types, including the start page.
 * @return   The count of the visible documents of all types, including the start page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_INT32, FRAppCountAllTypesVisibleDocuments, ())

/**
 * @brief FRAppAddFileToCustomRecentFileList2
 * @details Adds the recent file to the custom recent file list. Registers the Ribbon recent file event handler to catch the pinning and removing event, 
	* so that the plug-in can update the data layer.
 * @param[in]  lpsRecentFileListName The name that specifies the custom recent file list which the recent file path will be added to.
 * @param[in]  lpwsFilePath The recent file path that will be added.
 * @param[in]  lpwsFileTitle Instead of the file path, the title will be displayed in the recent file list.
 * @param[in]  lpwsFileTooltip The tooltip of the recent file.
 * @param[in]  exeProc When the recent file item is clicked, the callback will be invoked, unless you set it as NULL.
 * @param[in]  bEnableRemoveItem Whether the item can be removed or not.
 * @param[in]  nPinned The status of the pin, 0 for not pinned, 1 for pinned, 2 for not display the pin button.
 * @param[in]  clientData The client data that will be passed to the callback.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppCreateCustomRecentFileList
 * @see FRAppRegisterRibbonRecentFileEventHandler
 */
INTERFACE(FS_BOOL, FRAppAddFileToCustomRecentFileList2, (FS_LPCSTR lpsRecentFileListName,  FS_LPCWSTR lpwsFilePath,  FS_LPCWSTR lpwsFileTitle,  FS_LPCWSTR lpwsFileTooltip,  FRAppCustomRecentFileExecuteProc exeProc,  FS_BOOL bEnableRemoveItem,  FS_INT32 nPinned,  void* clientData))

/**
 * @brief FRAppRegisterRibbonRecentFileEventHandler
 * @details Registers a callbacks set for Ribbon recent file list event handler.
 * @param[in]  callbacks The input callbacks for Ribbon recent file list event handler.
 * @return   The pointer to Ribbon recent file list event handler can be destroyed by <a>FRAppDestroyRibbonRecentFileEventHandler</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppDestroyRibbonRecentFileEventHandler
 */
INTERFACE(void*, FRAppRegisterRibbonRecentFileEventHandler, (FR_RibbonRecentFileEventCallbacks callbacks))

/**
 * @brief FRAppDestroyRibbonRecentFileEventHandler
 * @details Destroys the Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
 * @param[in]  eventHandler The pointer to Ribbon recent file list event handler returned by <a>FRAppRegisterRibbonRecentFileEventHandler</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppRegisterRibbonRecentFileEventHandler
 */
INTERFACE(void, FRAppDestroyRibbonRecentFileEventHandler, (void* eventHandler))

/**
 * @brief FRAppSetMetadataOption
 * @details Sets the option to the document to control whether the metadata is to be compressed or not.
 * @param[in]  bCompress The input option value, true: compress, false: uncompress.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void, FRAppSetMetadataOption, (FS_BOOL bCompress))

/**
 * @brief FRAppSetSubscriptionProvider
 * @details Registers a callbacks set for subscription provider.
 * @param[in]  callbacks The input callbacks for subscription provider.
 * @return   The pointer to subscription provider can be destroyed by <a>FRAppDestroySubscriptionProvider</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppDestroySubscriptionProvider
 */
INTERFACE(void*, FRAppSetSubscriptionProvider, (FR_SubscriptionProviderCallbacks callbacks))

/**
 * @brief FRAppDestroySubscriptionProvider
 * @details Destroys the subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
 * @param[in]  subscriptionProvider The pointer to subscription provider returned by <a>FRAppSetSubscriptionProvider</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see FRAppSetSubscriptionProvider
 */
INTERFACE(void, FRAppDestroySubscriptionProvider, (void* subscriptionProvider))

/**
 * @brief FRAppGetKeyfileStartAndExpireDate
 * @details Gets the start date and the expire date of the key file.
 * @param[out]  outStartDate It receives the start date.
 * @param[out]  outExpireDate It receives the expire date.
 * @param[out]  outExpire Whether the key file expired or not.
 * @return   TRUE for success, otherwise the key file does not exist or is invalid.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(FS_BOOL, FRAppGetKeyfileStartAndExpireDate, (FS_WideString* outStartDate,  FS_WideString* outExpireDate,  FS_BOOL* outExpire))

/**
 * @brief FRAppGetRibbonCategoryColor
 * @details Gets the back ground color of ribbon category.
 * @return   The back ground color of ribbon category.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonCategoryColor, (void))

/**
 * @brief FRAppGetRibbonElementColor
 * @details Gets the back ground color of ribbon element.
 * @param[out]  clrCheckButton The color when the button is selected.
 * @param[out]  clrCheckHighlight The color when the mouse is over the selected button.
 * @param[out]  clrHightButton The color when the mouse is over the none-selected button.
 * @param[out]  clrPressButton The color when the button is being clicked.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_BOOL, FRAppGetRibbonElementColor, (FS_COLORREF* clrCheckButton,  FS_COLORREF* clrCheckHighlight,  FS_COLORREF* clrHightButton,  FS_COLORREF* clrPressButton))

/**
 * @brief FRAppGetRibbonBaseBorderColor
 * @details Gets the back ground color of ribbon base border.
 * @return   The back ground color of ribbon base border.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonBaseBorderColor, (void))

/**
 * @brief FRAppGetRecentFolderListSize
 * @details Gets the recent folder list size.
 * @return   The recent folder list size.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppGetRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFolderListSize, (void))

/**
 * @brief FRAppCreateEmptyFrameViewEventHandler
 * @details Creates the empty frame view event handler. Registers it through <a>FRAppCreateAnEmptyFrameWnd2</a>.Destroys it through <a>FRAppDestroyEmptyFrameViewEventHandler</a>;
 * @param[in]  callbacks The callbacks for the event handler of the empty frame window view.
 * @return   The <a>FR_EmptyFrameWndViewEventHandler</a> object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateAnEmptyFrameWnd2
 * @see FRAppDestroyEmptyFrameViewEventHandler
 */
INTERFACE(FR_EmptyFrameWndViewEventHandler, FRAppCreateEmptyFrameViewEventHandler, (FR_EmptyFrameWndViewEventHandlerCallbacks callbacks))

/**
 * @brief FRAppDestroyEmptyFrameViewEventHandler
 * @details Destroys the event handler of the empty frame window view
 * @param[in]  eventHandler The input event handler of the empty frame window view.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateAnEmptyFrameWnd2
 * @see FRAppCreateEmptyFrameViewEventHandler
 */
INTERFACE(void, FRAppDestroyEmptyFrameViewEventHandler, (FR_EmptyFrameWndViewEventHandler eventHandler))

/**
 * @brief FRAppCreateAnEmptyFrameWnd2
 * @details Creates a new frame window.
 * @param[in]  lpwsTitle The title of the frame which will be created.
 * @param[in]  lpwsPathName The input document path associated with the view.
 * @param[in]  eventHandler The input empty frame window view event handler.
 * @param[in]  bCreatePanel Whether to create the associated navigation panel or not. Sets it FALSE as default.
 * @param[in]  bMakeVisible A flag indicate whether to show the frame.
 * @param[in]  bAddToMRU Determines whether the file name is added to the most recently used (MRU) file list. Sets it FALSE as default.
 * @return   The handler of the newly created frame.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see FRAppCreateEmptyFrameViewEventHandler
 * @see FRAppDestroyEmptyFrameViewEventHandler
 */
INTERFACE(HWND, FRAppCreateAnEmptyFrameWnd2, (FS_LPCWSTR lpwsTitle,  FS_LPCWSTR lpwsPathName,  FR_EmptyFrameWndViewEventHandler eventHandler,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRAppIsReadMode
 * @details Checks whether Foxit Reader is in reading mode or not.
 * @return   <a>TRUE</a> if Foxit Reader is in reading mode, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppExitReadMode
 */
INTERFACE(FS_BOOL, FRAppIsReadMode, ())

/**
 * @brief FRAppExitReadMode
 * @details Exits the reading mode.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppIsReadMode
 */
INTERFACE(void, FRAppExitReadMode, ())

/**
 * @brief FRAppGetCurrentChildFrm
 * @details Gets the current child frame handle.
 * @return   The current child frame handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(HWND, FRAppGetCurrentChildFrm, ())

/**
 * @brief FRAppCollectDocActionData
 * @details The plug-in can invoke this interface to notify the other module to collect the action data.
 * @param[in]  frDoc The specified<a>FR_Document</a>.
 * @param[in]  lpwsOperatorType The specified operator type.
 * @param[in]  lpwsOperator The operator value.
 * @param[in]  valueMap The operator value map.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRDocOnDocCollectActionData
 */
INTERFACE(void, FRAppCollectDocActionData, (FR_Document frDoc,  FS_LPCWSTR lpwsOperatorType,  FS_LPCWSTR lpwsOperator,  FS_MapPtrToPtr valueMap))

/**
 * @brief FRAppActiveChildFrame
 * @details Activates the specified child frame.
 * @param[in]  hChildFrame The input child frame handle to be activated.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRAppActiveChildFrame, (HWND hChildFrame))

/**
 * @brief FRAppCollectNormalData
 * @details Notifies the other modules to collect some normal data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  lpwsContent The content to be collected.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRAppRegisterDataCollectionHadler
 */
INTERFACE(void, FRAppCollectNormalData, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_LPCWSTR lpwsContent))

/**
 * @brief FRAppSetMainframeShow
 * @details Sets whether the main frame will be shown or not when Foxit Reader starts up.
 * @param[in]  bShow Whether the main frame will be shown or not when Foxit Reader starts up.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(void, FRAppSetMainframeShow, (FS_BOOL bShow))

/**
 * @brief FRAppGetMainframeShow
 * @details Checks whether the main frame will be shown or not when Foxit Reader starts up.
 * @return   Whether the main frame will be shown or not when Foxit Reader starts up.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see 
 */
INTERFACE(FS_BOOL, FRAppGetMainframeShow, ())

/**
 * @brief FRAppGetRibbonTooltipBorderColor
 * @details Gets the border color of the ribbon tooltip.
 * @return   The border color of the ribbon tooltip.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 */
INTERFACE(FS_COLORREF, FRAppGetRibbonTooltipBorderColor, (void))

/**
 * @brief FRAppGetRecentFileIndex
 * @details Gets the index of the specified recent file.
 * @param[in]  lpszPathName The recent opened file path.
 * @param[in]  bFolder Whether the path is a file or a folder.
 * @return   The index of the specified recent file.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 * @see FRAppGetRecentFileList
 * @see FRAppAddFileToRecentFileList
 * @see FRAppClearRecentFileList
 * @see FRAppRemoveFileFromRecentFileList
 */
INTERFACE(FS_INT32, FRAppGetRecentFileIndex, (FS_LPCWSTR lpszPathName,  FS_BOOL bFolder))

/**
 * @brief FRAppFZipUnzip
 * @details Unzips the .fzip file to the specified dest path.
 * @param[in]  lpszFZipPath The input .fzip file path.
 * @param[in]  lpszDestPath The dest path.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_BOOL, FRAppFZipUnzip, (FS_LPCWSTR lpszFZipPath,  FS_LPCWSTR lpszDestPath))

/**
 * @brief FRAppIsJSEnabled
 * @details Checks whether the javascript is enabled or not.
 * @return   TRUE if the javascript is enabled, otherwise FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(FS_BOOL, FRAppIsJSEnabled, ())

/**
 * @brief FRAppSetEnableJS
 * @details Sets the javascript to be enabled or not.
 * @param[in]  bEnable Sets the javascript to be enabled or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRAppSetEnableJS, (FS_BOOL bEnable))

/**
 * @brief FRAppCollectNormalData2
 * @details Notifies the other modules to collect some normal data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  lpwsContent The content to be collected.
 * @param[in]  nLevel The detail level of the data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see FRAppRegisterDataCollectionHadler
 */
INTERFACE(void, FRAppCollectNormalData2, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_LPCWSTR lpwsContent,  FS_INT32 nLevel))

/**
 * @brief FRAppCollectBitmapData
 * @details Notifies the other modules to collect some bitmap data.
 * @param[in]  lpwsFunction The function to be collected.
 * @param[in]  lpwsAction The function to be collected.
 * @param[in]  pBitmap The bitmap to be collected.
 * @param[in]  nLevel The detail level of the data.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see FRAppRegisterDataCollectionHadler
 */
INTERFACE(void, FRAppCollectBitmapData, (FS_LPCWSTR lpwsFunction,  FS_LPCWSTR lpwsAction,  FS_DIBitmap pBitmap,  FS_INT32 nLevel))

/**
 * @brief FRAppIsNeedCollectData
 * @details Whether the cPDF data is need collected or not.
 * @return   TRUE if the cPDF data is need collected.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 */
INTERFACE(FS_BOOL, FRAppIsNeedCollectData, ())

/**
 * @brief FRAppIsFipsMode
 * @details Whether the system is in Federal Information Processing Standard environment or not.
 * @return   TRUE if the system is in Federal Information Processing Standard environment.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 * @see 
 */
INTERFACE(FS_BOOL, FRAppIsFipsMode, ())

/**
 * @brief FRAppAddNavPanelView
 * @details Adds a navigation panel view into the Foxit Reader. The navigation panel view can be added after reader has started up.
 * @param[in]  panelViewCallbacks A panel view callback set invoked by reader to add a panel view to navigation panel.
 * @param[in]  nPos The position in the navigation panel.
 * @return   The returned value should be released by <a>FRAppReleaseNavPanelView</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void*, FRAppAddNavPanelView, (FR_PanelViewCallbacks panelViewCallbacks,  FS_INT32 nPos))

/**
 * @brief FRAppReleaseNavPanelView
 * @details Releases the navigation panel view returned by <a>FRAppAddNavPanelView</a>.
 * @param[in]  pNavPanelView Returned by <a>FRAppAddNavPanelView</a>.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.2
 */
INTERFACE(void, FRAppReleaseNavPanelView, (void* pNavPanelView))

/**
 * @brief FRAppAddFileAttachment
 * @details Add a embed file to current document with The file path.
 * @param[in]  frDoc The specified document.
	* param[in]: lpwsAttachFilePath		The file path for add.
 * @return   Non-zero means succeed, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppAddFileAttachment, (FR_Document frDoc,  FS_LPCWSTR lpwsAttachFilePath))

/**
 * @brief FRAppOpenFileAttachment
 * @details open a embed file.
 * @param[in]  pDict The FileAttachment dictionary.
	* param[in]: nPage		The Page index.
	* param[in]: bAnnot	Is FileAttachment Annot.
 * @return   Non-zero means succeed, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.5
 */
INTERFACE(FS_BOOL, FRAppOpenFileAttachment, (FPD_Object pDict,  FS_INT32 nPage,  FS_BOOL bAnnot,  FS_LPCWSTR wsFileName))

/**
 * @brief FRAppIsPDF2Doc
 * @details whether it is 2.0 pdf document
 * @param[in]  pSourDoc The specified document.
 * @return   Non-zero means is 2.0 pdf document, otherwise means not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppIsPDF2Doc, (FPD_Document pSourDoc))

/**
 * @brief FRAppConvertToPDF
 * @details convert file to Pdf file.
 * @param[in]  lpwsFile The Original File.
 * @param[in]  lpwsDest The Dest File.
 * @param[in]  hWnd The hWnd,default NULL.
 * @param[in]  bShowProgressBar If show the progress bar.
 * @param[in]  bConvertToCPDF If need convert to CPDF File.
 * @param[in]  bDelDestFile If need delete the Dest File when convert failed.
 * @return   zero means successful, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRAppConvertToPDFA
 */
INTERFACE(FS_INT32, FRAppConvertToPDF, (FS_LPCWSTR lpwsFile,  FS_LPCWSTR lpwsDest,  HWND hWnd,  FS_BOOL bShowProgressBar,  FS_BOOL bConvertToCPDF,  FS_BOOL bDelDestFile))

/**
 * @brief FRAppRegisterPDFAPluginHandler
 * @details The callbacks of pdfa Handler just be called while the document was saved to pdfa.
 * @param[in]  pdfaPluginHandlerCallbacks The callback set. Reader will call a corresponding callback when save to pdfa occurs.
 * @return   <a>TRUE</a> means successful, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppRegisterPDFAPluginHandler, (FR_PDFAPluginHandlerCallbacks pdfaPluginHandlerCallbacks))

/**
 * @brief FRAppConvertToPDFA
 * @details Converts file to PDFA file.
 * @param[in]  frDoc The specified document.
 * @param[in]  fswsSaveAsFileName The dest document path to be saved.
 * @param[in]  pVersion The PDFA version to be converted.
 * @return   Zero means successful, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRAppConvertToPDF
 */
INTERFACE(FS_INT32, FRAppConvertToPDFA, (FR_Document frDoc,  const FS_WideString fswsSaveAsFileName,  const FRPDFA_PDFVersion pVersion))

/**
 * @brief FRAppAddLog
 * @details Outputs log information.
 * @param[in]  nLevel The specified log level.
 * @param[in]  wsMsg The input log message.
 * @param[in]  file The file where the log is added. Use __FILE__ as default.
 * @param[in]  nLine The code line where the log is added. Use __LINE__ as default.
 * @param[in]  function The function where the log is added. use __FUNCTION__ as default.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRAppAddLog, (FR_LOG_LEVEL nLevel,  FS_WideString wsMsg,  const FS_CHAR* file,  FS_INT32 nLine,  const FS_CHAR* function))

/**
 * @brief FRAppIsReaderOnlyMode
 * @details 
 * @param[in]  hWnd 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_BOOL, FRAppIsReaderOnlyMode, (HWND hWnd))

/**
 * @brief FRAppGetMainFrameWndCount
 * @details 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FS_INT32, FRAppGetMainFrameWndCount, ())

/**
 * @brief FRAppGetMainFrameWndByIndex
 * @details 
 * @param[in]  nIndex 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void*, FRAppGetMainFrameWndByIndex, (FS_INT32 nIndex))

/**
 * @brief FRAppGetModelessParentWnd
 * @details 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(HWND, FRAppGetModelessParentWnd, ())

/**
 * @brief FRAppIsMainfrmActivating
 * @details 
 * @param[in]  hWnd 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(BOOL, FRAppIsMainfrmActivating, (HWND hWnd))

/**
 * @brief FRAppGetRibbonBar2
 * @details Gets Foxit Reader's ribbon bar.
 * @param[in]  hWnd A handle to the parent window. It represents the <Italic>MFC HWND</Italic>. Sets it to NULL as default.
	* You can get the parent window through <a>FRDocGetUIParentWnd</a>.
 * @return   The ribbon bar.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(FR_RibbonBar, FRAppGetRibbonBar2, (HWND hWnd))

/**
 * @brief FRAppRefreshLayerPanelView
 * @details 
 * @param[in]  pCpdfDoc 
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.1
 */
INTERFACE(void, FRAppRefreshLayerPanelView, (FPD_Document pCpdfDoc))

/**
 * @brief FRAppRegisterDRMSecurityHandler
 * @details Registers a security handler. Invoked this interface to process the PDF documents that 
	* are encrypted by customer security handler.
	* Since: <a>SDK_LATEEST_VERSION</a> > 9.5
 * @param[in]  name The name of the security handler.
 * @param[in]  callbacks The structure containing the security handler callback functions.
 * @return   void
 * @note 
 * @see FRAppUnRegisterSecurityHandler
 */
INTERFACE(void, FRAppRegisterDRMSecurityHandler, (FS_LPCSTR name,  FR_DRMSecurityCallbacks callbacks))

INTERFACE(void, FRAppAddECMFileDialog, (FS_LPCWSTR lpwPluginName, FS_LPCWSTR lpwPluginHftName, FS_LPCWSTR lpwTitle, FRAppFileDialogECMOpenProc openproc, FRAppFileDialogECMSaveProc saveproc, void* clientdata))
INTERFACE(void, FRAppECMFileDialogAddMenuItem, (void* pFileDialog, FRDECMFileDialogType type))
INTERFACE(void, FRAppECMFileDialogItemSelected, (FS_LPCWSTR wsSrcFilePath, void* pFileDialog, void* pIFileDialog, DWORD dwIDCtl, DWORD dwIDItem, FRDECMFileDialogType type))
INTERFACE(void*, FRAppGetECMFileDialog, (FRDECMFileDialogType type, FS_LPCWSTR wsSrcFilePath, BOOL bOpenFileDialog, FS_LPCWSTR lpszDefExt, FS_LPCWSTR lpszFileName, DWORD dwFlags, FS_LPCWSTR lpszFilter, void* pParentWnd, DWORD dwSize, BOOL bVistaStyle))

NumOfSelector(FRApp)
ENDENUM

//*****************************
/* Language HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRLanguageCreate
 * @details Creates a new <a>FR_Language</a> object.
 * @param[in]  hInstance The input plug-in instance handle.
 * @return   The <a>FR_Language</a> object created.
 * @note 
 */
INTERFACE(FR_Language, FRLanguageCreate, (HINSTANCE hInstance))

/**
 * @brief FRLanguageRelease
 * @details Releases the <a>FR_Language</a> object created by <a>FRLanguageCreate</a>().
 * @param[in]  language The input <a>FR_Language</a> object to be released.
 * @return   void
 * @note 
 * @see FRLanguageCreate
 */
INTERFACE(void, FRLanguageRelease, (FR_Language language))

/**
 * @brief FRLanguageChange
 * @details Changes the language of plug-in according to the input language ID. 
	* Plug-in can change the language when the <a>FRAppOnLangUIChange</a>() app event occurs.
	* You can get the current Foxit Reader language ID by <a>FRLanguageGetCurrentID</a>(), 
	* so that the language of plug-in can be the same as the Foxit Reader.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  nID The input language ID.
 * @return   void
 * @note 
 * @see FRLanguageGetCurrentID
 */
INTERFACE(void, FRLanguageChange, (FR_Language language,  FS_INT32 nID))

/**
 * @brief FRLanguageGetCurrentID
 * @details Gets the current language ID of Foxit Reader.
 * @return   The current language ID of Foxit Reader.
 * @note 
 * @see FRLanguageChange
 */
INTERFACE(FS_INT32, FRLanguageGetCurrentID, ())

/**
 * @brief FRLanguageTranslateMenu
 * @details Translates the language of menu to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hMenu The input menu handle to be translated.
 * @param[in]  pzResName The input name of menu resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateMenu, (FR_Language language,  HMENU hMenu,  FS_LPCWSTR pzResName))

/**
 * @brief FRLanguageTranslateDialog
 * @details Translates the language of dialog to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hWnd The input dialog handle to be translated.
 * @param[in]  pzResName The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateDialog, (FR_Language language,  HWND hWnd,  FS_LPCWSTR pzResName))

/**
 * @brief FRLanguageLoadString
 * @details Loads the specified string. Set the <param>buffer</param> <a>NULL</a> to get the length of the string.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  nId Specifies the integer identifier of the string to be loaded.
 * @param[out]  buffer It receives the string loaded.
 * @param[in]  len Specifies the length of the <param>buffer</param> in bytes.
 * @return   The length of the string in bytes.
 * @note 
 */
INTERFACE(FS_INT32, FRLanguageLoadString, (FR_Language language,  FS_INT32 nId,  void* buffer,  FS_INT32 len))

/**
 * @brief FRLanguageLoadVersionRes
 * @details Loads the file description and the legal copyright of the plug-in.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[out]  outFileDes It receives the file description.
 * @param[out]  outLegalCopyright It receives the legal copyright.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FRLanguageLoadVersionRes, (FR_Language language,  FS_WideString* outFileDes,  FS_WideString* outLegalCopyright))

/**
 * @brief FRLanguageGetLocalLangName
 * @details Gets the local language name.
 * @param[out]  outName It receives the local language name.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FRLanguageGetLocalLangName, (FS_WideString* outName))

/**
 * @brief FRLanguageTranslateDialog2
 * @details Translates the language of dialog to another through <param>language</param>.
 * @param[in]  language The input <a>FR_Language</a> object.
 * @param[in]  hWnd The input dialog handle to be translated.
 * @param[in]  pzResName The input name of dialog resource. The <Italic>MAKEINTRESOURCE</Italic> macro can be used to create this value.
 * @param[in]  bAutoAdpt Whether to adapt to the DPI setting or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FRLanguageTranslateDialog2, (FR_Language language,  HWND hWnd,  FS_LPCWSTR pzResName,  FS_BOOL bAutoAdpt))

/**
 * @brief FRLanguageModifyLogFont
 * @details Modifies the attributes of a font to match the system language when the application language matches the system language, 
	* otherwise the font name will be set Tahoma as default.
 * @param[in,out]  lf The input attributes of a font to be modified.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FRLanguageModifyLogFont, (LOGFONT* lf))

/**
 * @brief FRLanguageFormatEx
 * @details Formats a translated string so that the arguments list can match the format.
 * @param[out]  outFormat It receives the format string.
 * @param[in]  lpszFormat Specifies a format-control string.
 * @param[in]  ... arguments list.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(void, FRLanguageFormatEx, (FS_WideString* outFormat,  FS_LPCWSTR lpszFormat,  ...))

/**
 * @brief FRLanguageJSPluginGetMessage
 * @details Gets the message string for javascript plug-in.
 * @param[in]  lpsModuleName The input javascript plug-in module name.
 * @param[in]  lpsMessageName The input message name.
 * @param[out]  outMessage It receives the message string.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.1
 */
INTERFACE(void, FRLanguageJSPluginGetMessage, (FS_LPCSTR lpsModuleName,  FS_LPCSTR lpsMessageName,  FS_WideString* outMessage))

NumOfSelector(FRLanguage)
ENDENUM

//*****************************
/* UIProgress HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRUIProgressCreate
 * @details Creates a new <a>FR_UIProgress</a> object.
 * @param[in]  hParent The parent window handle of the progress bar.
 * @param[in]  bShowCancelButton Whether to show the cancel button on the progress bar.
 * @return   The <a>FR_UIProgress</a> object created.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FR_UIProgress, FRUIProgressCreate, (HWND hParent,  FS_BOOL bShowCancelButton))

/**
 * @brief FRUIProgressSetText
 * @details Set the text shown in the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  lpText The text shown in the progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetText, (FR_UIProgress UIProgress,  FS_LPCWSTR lpText))

/**
 * @brief FRUIProgressSetRange
 * @details Set the range of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  nLower The minimize value of the range.
 * @param[in]  nUpper The maximize value of the range.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetRange, (FR_UIProgress UIProgress,  FS_INT32 nLower,  FS_INT32 nUpper))

/**
 * @brief FRUIProgressSetCurrValue
 * @details Set the current value of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  nPos The current value of the progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressSetCurrValue, (FR_UIProgress UIProgress,  FS_INT32 nPos))

/**
 * @brief FRUIProgressPeekAndPump
 * @details Peek and pump.
 * @param[in]  UIProgress The input progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressPeekAndPump, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressIsCancelled
 * @details Whether the progress bar is cancelled or not.
 * @param[in]  UIProgress The input progress bar.
 * @return   Whether the progress bar is cancelled or not.
 * @note 
 */
INTERFACE(FS_BOOL, FRUIProgressIsCancelled, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressGetCurrentValue
 * @details The current value of the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @return   Get the current value of the progress bar.
 * @note 
 */
INTERFACE(FS_INT32, FRUIProgressGetCurrentValue, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressDestroy
 * @details Destroy the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @return   void.
 * @note 
 */
INTERFACE(void, FRUIProgressDestroy, (FR_UIProgress UIProgress))

/**
 * @brief FRUIProgressDoCancel
 * @details To cancel the progress bar.
 * @param[in]  UIProgress The input progress bar.
 * @param[in]  bKill Whether to kill the progress bar.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FRUIProgressDoCancel, (FR_UIProgress UIProgress,  FS_BOOL bKill))

/**
 * @brief FRUIProgressCreate2
 * @details Creates a new <a>FR_UIProgress</a> object.
 * @param[in]  hParent The parent window handle of the progress bar.
 * @param[in]  bShowCancelButton Whether to show the cancel button on the progress bar.
 * @param[in]  bRevertFocus Whether to revert the focus to the original focused window.
 * @return   The <a>FR_UIProgress</a> object created.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FR_UIProgress, FRUIProgressCreate2, (HWND hParent,  FS_BOOL bShowCancelButton,  FS_BOOL bRevertFocus))

NumOfSelector(FRUIProgress)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//*****************************
/* Internal HFT functions */
//*****************************

BEGINENUM
INTERFACE(FS_BOOL, FRInternalDoPrintCommentSummary, (FR_Document doc,  FS_LPCWSTR lpFilePath))

INTERFACE(FS_BOOL, FRInternalOptimizerModuleFlatDocument, (FPD_Document pSourDoc,  FS_INT32* pPageAry,  FS_INT32 pageSize,  void* xUserData))

INTERFACE(FS_BOOL, FRInternalGlobalWndOpenPassWord, (FS_WideString wsFileName,  FS_BOOL bOwnerPass,  FS_WideString* wsPassWord))

INTERFACE(FS_BOOL, FRInternalGlobalWndCheckFileSize, (FPD_Document pDoc,  FS_WideString wsFilePath,  FS_BOOL bShowMsgBox,  FS_INT32* nChoice,  FS_BOOL bShowCheckBox,  FS_BOOL* bChecked,  FS_INT32 nPageLimit,  FS_INT32 nFileSizeLimit))

INTERFACE(FS_BOOL, FRInternalOpenCertifiedPDF, (FPD_Parser parser,  FS_LPCWSTR lpwsPDFPath))

INTERFACE(void*, FRInternalPWLWndCreationParamNew, ())

INTERFACE(void, FRInternalPWLWndCreationParamSetFontMap, (void* pCreationParam,  FR_Edit_FontMap fontMap))

INTERFACE(void, FRInternalPWLWndCreationParamSetFontIndex, (void* pCreationParam,  FS_INT32 nFontIndex))

INTERFACE(void, FRInternalPWLWndCreationParamSetFlag, (void* pCreationParam,  FS_DWORD dwFlags))

INTERFACE(void, FRInternalPWLWndCreationParamSetFontSize, (void* pCreationParam,  FS_FLOAT fFontSize))

INTERFACE(void, FRInternalPWLWndCreationParamSetTextColor, (void* pCreationParam,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FRInternalPWLWndCreationParamSetTextColorII, (void* pCreationParam,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndCreationParamSetRect, (void* pCreationParam,  FS_FloatRect rect))

INTERFACE(void, FRInternalPWLWndCreationParamDestroy, (void* pCreationParam))

INTERFACE(void*, FRInternalPWLWndEditNew, (void* pCreationParam))

INTERFACE(void, FRInternalPWLWndEditSetTextColor, (void* pEdit,  FS_INT32 r,  FS_INT32 g,  FS_INT32 b))

INTERFACE(void, FRInternalPWLWndEditSetTextColorII, (void* pEdit,  FS_INT32 type,  FS_FLOAT color1,  FS_FLOAT color2,  FS_FLOAT color3,  FS_FLOAT color4))

INTERFACE(void, FRInternalPWLWndEditSetText, (void* pEdit,  FS_LPCWSTR csText))

INTERFACE(void, FRInternalPWLWndEditGetContentRect, (void* pEdit,  FS_FloatRect* pRect))

INTERFACE(void, FRInternalPWLWndEditGeneratePageObjects, (void* pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy,  FS_PtrArray* outObjArray))

INTERFACE(void, FRInternalPWLWndEditGeneratePageObjectsII, (void* pEdit,  void* pPageObjects,  FS_FLOAT xx,  FS_FLOAT yy))

INTERFACE(void, FRInternalPWLWndEditDestroy, (void* pEdit))

INTERFACE(void, FRInternalSetReviewJS, (FR_Document frDoc,  FS_LPCWSTR lpwsScriptName,  FS_LPCWSTR lpwsScript))

INTERFACE(void, FRInternalGetReviewJS, (FR_Document frDoc,  FS_WideString* cwScriptName,  FS_WideString* cwScript))

INTERFACE(FS_BOOL, FRInternalRemoveReviewJS, (FR_Document frDoc,  FS_LPCWSTR lpwsScriptName))

INTERFACE(FS_BOOL, FRInternalExportAnnotToXFDF, (void* pAnnot,  FS_XMLElement xmlElement))

INTERFACE(void*, FRInternalImprotAnnotFromXFDF, (FR_Document frDoc,  FS_XMLElement xmlAnnot,  FS_BOOL bSendAnnotChangeToNotify))

INTERFACE(void, FRInternalEnableAnnot, (void* pAnnot,  FS_BOOL bEnable))

INTERFACE(FS_BOOL, FRInternalDeleteAnnot, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCWSTR lpwsAnnotName,  FS_BOOL bSendAnnotChangeToNotify))

INTERFACE(FS_BOOL, FRInternalUpdateAnnotAuthor, (FR_Document frDoc,  FS_LPCWSTR lpwsAuthorName))

INTERFACE(FS_BOOL, FRInternalUpdateAnnotAuthor2, (FR_Annot frAnnot,  FS_LPCWSTR lpwsAuthorName))

INTERFACE(void*, FRInternalSetIcommentsAnnotNotify, (FR_CommentsAnnotOprtNotifyCallbacks callbacks))

INTERFACE(FS_BOOL, FRInternalRemoveIcommentsAnnotNotify, (void* pNotify))

INTERFACE(void, FRInternalShowChildScrollBar, (FS_BOOL bShow,  HWND hParentWnd))

INTERFACE(void, FRInternalChangeZoomScaleInfo, (double dbScale,  FS_BOOL bReDraw))

INTERFACE(FS_BOOL, FRInternalAdvEditing, (FS_INT32 iPage,  FS_FloatRect pdfRect))

INTERFACE(FS_BOOL, FRInternalToolbarModuleGetSysFontFaceName, (FS_LPCWSTR lpwsScriptName,  FS_WideString* outName))

INTERFACE(FR_VTWordPlace, FRInternalWordPlaceNew, (FS_INT32 nSecIndex,  FS_INT32 nLineIndex,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalWordPlaceDestroy, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetDefault, (FR_VTWordPlace wordPlace))

INTERFACE(FS_BOOL, FRInternalWordPlaceEqual, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceWordCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceLineCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(FS_INT32, FRInternalWordPlaceSecCmp, (FR_VTWordPlace wordPlace,  FR_VTWordPlace destWordPlace))

INTERFACE(void, FRInternalWordPlaceSetSectionIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nSecIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetSectionIndex, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetLineIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nLineIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetLineIndex, (FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalWordPlaceSetWordIndex, (FR_VTWordPlace wordPlace,  FS_INT32 nWordIndex))

INTERFACE(FS_INT32, FRInternalWordPlaceGetWordIndex, (FR_VTWordPlace wordPlace))

INTERFACE(FR_VTWordRange, FRInternalWordRangeNew, ())

INTERFACE(void, FRInternalWordRangeDestroy, (FR_VTWordRange wordRange))

INTERFACE(void, FRInternalWordRangeSetDefault, (FR_VTWordRange wordRange))

INTERFACE(void, FRInternalWordRangeSet, (FR_VTWordRange wordRange,  FR_VTWordPlace begin,  FR_VTWordPlace end))

INTERFACE(void, FRInternalWordRangeSetBeginPos, (FR_VTWordRange wordRange,  FR_VTWordPlace begin))

INTERFACE(void, FRInternalWordRangeSetEndPos, (FR_VTWordRange wordRange,  FR_VTWordPlace end))

INTERFACE(FS_BOOL, FRInternalWordRangeIsExist, (FR_VTWordRange wordRange))

INTERFACE(FS_BOOL, FRInternalWordRangeEqual, (FR_VTWordRange wordRange,  FR_VTWordRange destWordRange))

INTERFACE(void, FRInternalWordRangeSwapWordPlace, (FR_VTWordRange wordRange))

INTERFACE(FR_VTWordPlace, FRInternalWordRangeGetBeginPos, (FR_VTWordRange wordRange))

INTERFACE(FR_VTWordPlace, FRInternalWordRangeGetEndPos, (FR_VTWordRange wordRange))

INTERFACE(FR_VTSecProps, FRInternalSecPropsNew, (FS_FLOAT lineLeading,  FS_FLOAT lineIndent,  FS_INT32 alignment,  FS_BOOL softreturn,  FS_BOOL bRTL))

INTERFACE(FR_VTSecProps, FRInternalSecPropsNewII, (FR_VTSecProps otherSecProps))

INTERFACE(void, FRInternalSecPropsDestroy, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetLineLeading, (FR_VTSecProps secProps,  FS_FLOAT lineLeading))

INTERFACE(FS_FLOAT, FRInternalSecPropsGetLineLeading, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetLineIndent, (FR_VTSecProps secProps,  FS_FLOAT lineIndent))

INTERFACE(FS_FLOAT, FRInternalSecPropsGetLineIndent, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetAlignment, (FR_VTSecProps secProps,  FS_INT32 alignment))

INTERFACE(FS_INT32, FRInternalSecPropsGetAlignment, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetSoftReturn, (FR_VTSecProps secProps,  FS_BOOL softreturn))

INTERFACE(FS_BOOL, FRInternalSecPropsGetSoftReturn, (FR_VTSecProps secProps))

INTERFACE(void, FRInternalSecPropsSetRTL, (FR_VTSecProps secProps,  FS_BOOL bRTL))

INTERFACE(FS_BOOL, FRInternalSecPropsGetRTL, (FR_VTSecProps secProps))

INTERFACE(FR_VTWordProps, FRInternalWordPropsNew, (FS_INT32	fontIndex,  FS_FLOAT fontSize,  FS_COLORREF wordColor,  FS_INT32 scriptType,  FS_INT32 wordStyle,  FS_FLOAT charSpace,  FS_FLOAT horzScale,  FS_FLOAT xOffset,  FS_FLOAT yOffset,  FS_COLORREF strokeColor,  FS_INT32 renderingMode,  FS_FLOAT lineWidth,  FS_FLOAT wordspace,  FS_DWORD dwCharCode,  short nAlphal))

INTERFACE(FR_VTWordProps, FRInternalWordPropsNewII, (FR_VTWordProps otherWordProps))

INTERFACE(void, FRInternalWordPropsDestroy, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetFontIndex, (FR_VTWordProps wordProps,  FS_INT32 fontIndex))

INTERFACE(FS_INT32, FRInternalWordPropsGetFontIndex, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetFontSize, (FR_VTWordProps wordProps,  FS_FLOAT fontSize))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetFontSize, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordColor, (FR_VTWordProps wordProps,  FS_COLORREF wordColor))

INTERFACE(FS_COLORREF, FRInternalWordPropsGetWordColor, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetStrokeColor, (FR_VTWordProps wordProps,  FS_COLORREF dwStrokeColor))

INTERFACE(FS_COLORREF, FRInternalWordPropsGetStrokeColor, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetScriptType, (FR_VTWordProps wordProps,  FS_INT32 nScriptType))

INTERFACE(FS_INT32, FRInternalWordPropsGetScriptType, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordStyle, (FR_VTWordProps wordProps,  FS_INT32 nWordStyle))

INTERFACE(FS_INT32, FRInternalWordPropsGetWordStyle, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetCharSpace, (FR_VTWordProps wordProps,  FS_FLOAT fCharSpace))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetCharSpace, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetHorzScale, (FR_VTWordProps wordProps,  FS_FLOAT fHorzScale))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetHorzScale, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetXOffset, (FR_VTWordProps wordProps,  FS_FLOAT fXOffset))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetXOffset, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetYOffset, (FR_VTWordProps wordProps,  FS_FLOAT fYOffset))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetYOffset, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetRenderingMode, (FR_VTWordProps wordProps,  FS_INT32 nRenderingMode))

INTERFACE(FS_INT32, FRInternalWordPropsGetRenderingMode, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetClientData, (FR_VTWordProps wordProps,  FS_DWORD dwClientData))

INTERFACE(FS_DWORD, FRInternalWordPropsGetClientData, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetLineWidth, (FR_VTWordProps wordProps,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetLineWidth, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetWordSpace, (FR_VTWordProps wordProps,  FS_FLOAT fWordSpace))

INTERFACE(FS_FLOAT, FRInternalWordPropsGetWordSpace, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetCharCode, (FR_VTWordProps wordProps,  FS_DWORD dwCharCode))

INTERFACE(FS_DWORD, FRInternalWordPropsGetCharCode, (FR_VTWordProps wordProps))

INTERFACE(void, FRInternalWordPropsSetAlpha, (FR_VTWordProps wordProps,  short nAlpha))

INTERFACE(short, FRInternalWordPropsGetAlpha, (FR_VTWordProps wordProps))

INTERFACE(FR_VTWord, FRInternalWordNew, ())

INTERFACE(void, FRInternalWordDestroy, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWord, (FR_VTWord VTWord,  FS_WORD word))

INTERFACE(FS_WORD, FRInternalWordGetWord, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordDisplay, (FR_VTWord word,  FS_WORD WordDisplay))

INTERFACE(FS_WORD, FRInternalWordGetWordDisplay, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetBidiOrder, (FR_VTWord word,  short nBidiOrder))

INTERFACE(short, FRInternalWordGetBidiOrder, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetCharset, (FR_VTWord word,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FRInternalWordGetCharset, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordPlace, (FR_VTWord word,  FR_VTWordPlace WordPlace))

INTERFACE(FR_VTWordPlace, FRInternalWordGetWordPlace, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordPoint, (FR_VTWord word,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalWordGetWordPoint, (FR_VTWord word,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FRInternalWordSetAscent, (FR_VTWord word,  FS_FLOAT fAscent))

INTERFACE(FS_FLOAT, FRInternalWordGetAscent, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetDescent, (FR_VTWord word,  FS_FLOAT fDescent))

INTERFACE(FS_FLOAT, FRInternalWordGetDescent, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWidth, (FR_VTWord word,  FS_FLOAT fWidth))

INTERFACE(FS_FLOAT, FRInternalWordGetWidth, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetFontIndex, (FR_VTWord word,  FS_INT32 nFontIndex))

INTERFACE(FS_INT32, FRInternalWordGetFontIndex, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetFontSize, (FR_VTWord word,  FS_FLOAT fFontSize))

INTERFACE(FS_FLOAT, FRInternalWordGetFontSize, (FR_VTWord word))

INTERFACE(void, FRInternalWordSetWordProps, (FR_VTWord word,  FR_VTWordProps wordProps))

INTERFACE(FR_VTWordProps, FRInternalWordGetWordProps, (FR_VTWord word))

INTERFACE(FR_VTLine, FRInternalLineNew, ())

INTERFACE(void, FRInternalLineDestroy, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetStartWordPlace, (FR_VTLine line,  FR_VTWordPlace lineplace))

INTERFACE(FR_VTWordPlace, FRInternalLineGetStartWordPlace, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetEndWordPlace, (FR_VTLine line,  FR_VTWordPlace lineEnd))

INTERFACE(FR_VTWordPlace, FRInternalLineGetEndWordPlace, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetOriginalPosition, (FR_VTLine line,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalLineGetOriginalPosition, (FR_VTLine line,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(void, FRInternalLineSetWidth, (FR_VTLine line,  FS_FLOAT fLineWidth))

INTERFACE(FS_FLOAT, FRInternalLineGetWidth, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetAscent, (FR_VTLine line,  FS_FLOAT fLineAscent))

INTERFACE(FS_FLOAT, FRInternalLineGetAscent, (FR_VTLine line))

INTERFACE(void, FRInternalLineSetDescent, (FR_VTLine line,  FS_FLOAT fLineDescent))

INTERFACE(FS_FLOAT, FRInternalLineGetDescent, (FR_VTLine line))

INTERFACE(FR_VTSection, FRInternalSectionNew, ())

INTERFACE(void, FRInternalSectionDestroy, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetStartWordPlace, (FR_VTSection section,  FR_VTWordPlace secplace))

INTERFACE(FR_VTWordPlace, FRInternalSectionGetStartWordPlace, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetRect, (FR_VTSection section,  FS_FloatRect rect))

INTERFACE(FS_FloatRect, FRInternalSectionGetRect, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetSectionProperties, (FR_VTSection section,  FR_VTSecProps SecProps))

INTERFACE(FR_VTSecProps, FRInternalSectionGetSectionProperties, (FR_VTSection section))

INTERFACE(void, FRInternalSectionSetWordProperties, (FR_VTSection section,  FR_VTWordProps WordProps))

INTERFACE(FR_VTWordProps, FRInternalSectionGetWordProperties, (FR_VTSection section))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextWord, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevWord, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextLine, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevLine, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorNextSection, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorPrevSection, (FR_VariableText_Iterator iterator))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetWord, (FR_VariableText_Iterator iterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalVTIteratorSetWord, (FR_VariableText_Iterator iterator,  FR_VTWord word))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetLine, (FR_VariableText_Iterator iterator,  FR_VTLine* outLine))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetSection, (FR_VariableText_Iterator iterator,  FR_VTSection* outSection))

INTERFACE(FS_BOOL, FRInternalVTIteratorSetSection, (FR_VariableText_Iterator iterator,  FR_VTSection section))

INTERFACE(void, FRInternalVTIteratorSetAt, (FR_VariableText_Iterator iterator,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalVTIteratorSetAtII, (FR_VariableText_Iterator iterator,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVTIteratorGetAt, (FR_VariableText_Iterator iterator,  FR_VTWordPlace* outWordPlace))

INTERFACE(FS_BOOL, FRInternalVTIteratorGetDisplayWord, (FR_VariableText_Iterator iterator,  FR_VTWord* outWord))

INTERFACE(FR_VariableText, FRInternalVariableTextNew, ())

INTERFACE(void, FRInternalVariableTextDestroy, (FR_VariableText variableText))

INTERFACE(FR_VariableText_Provider, FRInternalVariableTextProviderNew, (FR_VariableTextProviderCallbacks callbacks))

INTERFACE(void, FRInternalVariableTextProviderDestroy, (FR_VariableText_Provider provider))

INTERFACE(FR_VariableText_Provider, FRInternalVariableTextSetProvider, (FR_VariableText variableText,  FR_VariableText_Provider provider))

INTERFACE(FR_VariableText_Iterator, FRInternalVariableTextGetIterator, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetPlateRect, (FR_VariableText variableText,  FS_FloatRect rect,  FS_BOOL bVerticalWriting))

INTERFACE(FS_BOOL, FRInternalVariableTextIsVerticalWriting, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetAlignment, (FR_VariableText variableText,  FS_INT32 nFormat))

INTERFACE(void, FRInternalVariableTextSetPasswordChar, (FR_VariableText variableText,  FS_WORD wSubWord))

INTERFACE(void, FRInternalVariableTextSetLimitChar, (FR_VariableText variableText,  FS_INT32 nLimitChar))

INTERFACE(void, FRInternalVariableTextSetCharArray, (FR_VariableText variableText,  FS_INT32 nCharArray))

INTERFACE(void, FRInternalVariableTextSetCharSpace, (FR_VariableText variableText,  FS_FLOAT fCharSpace))

INTERFACE(void, FRInternalVariableTextSetWordSpace, (FR_VariableText variableText,  FS_FLOAT fWordSpace))

INTERFACE(void, FRInternalVariableTextSetHorzScale, (FR_VariableText variableText,  FS_FLOAT fHorzScale))

INTERFACE(void, FRInternalVariableTextSetMultiLine, (FR_VariableText variableText,  FS_BOOL bMultiLine))

INTERFACE(void, FRInternalVariableTextSetAutoReturn, (FR_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FRInternalVariableTextSetAutoFontSize, (FR_VariableText variableText,  FS_BOOL bAuto))

INTERFACE(void, FRInternalVariableTextSetFontSize, (FR_VariableText variableText,  FS_FLOAT fFontSize))

INTERFACE(void, FRInternalVariableTextSetLineLeading, (FR_VariableText variableText,  FS_FLOAT fLineLeading))

INTERFACE(void, FRInternalVariableTextSetRichText, (FR_VariableText variableText,  FS_BOOL bRichText))

INTERFACE(void, FRInternalVariableTextSetDirectionRTL, (FR_VariableText variableText,  FS_BOOL bRTL,  FR_VTWordRange PlaceRange))

INTERFACE(void, FRInternalVariableTextInitialize, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsValid, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsRichText, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextRearrangeAll, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextRearrangePart, (FR_VariableText variableText,  FR_VTWordRange PlaceRange))

INTERFACE(void, FRInternalVariableTextResetAll, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextSetText, (FR_VariableText variableText,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps))

INTERFACE(void, FRInternalVariableTextInsertWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_WORD word,  FS_INT32 charset,  FR_VTWordProps pWordProps,  FS_BOOL bNeedTransform,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextInsertSection, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextInsertText, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps pSecProps,  FR_VTWordProps pWordProps,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextDeleteWords, (FR_VariableText variableText,  FR_VTWordRange PlaceRange,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextDeleteWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextBackSpaceWord, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(FS_FloatRect, FRInternalVariableTextGetPlateRect, (FR_VariableText variableText))

INTERFACE(FS_FloatRect, FRInternalVariableTextGetContentRect, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetTotalWords, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetFontSize, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetAlignment, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetWordSpace, (FR_VariableText variableText))

INTERFACE(FS_WORD, FRInternalVariableTextGetPasswordChar, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetCharArray, (FR_VariableText variableText))

INTERFACE(FS_INT32, FRInternalVariableTextGetLimitChar, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsMultiLine, (FR_VariableText variableText))

INTERFACE(FS_BOOL, FRInternalVariableTextIsAutoReturn, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetHorzScale, (FR_VariableText variableText))

INTERFACE(FS_FLOAT, FRInternalVariableTextGetCharSpace, (FR_VariableText variableText))

INTERFACE(void, FRInternalVariableTextGetBeginWordPlace, (FR_VariableText variableText,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetEndWordPlace, (FR_VariableText variableText,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetPrevWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetNextWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextSearchWordPlace, (FR_VariableText variableText,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetUpWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetDownWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetLineBeginPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetLineEndPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetSectionBeginPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextGetSectionEndPlace, (FR_VariableText variableText,  FR_VTWordPlace place,  FR_VTWordPlace* outPlace))

INTERFACE(void, FRInternalVariableTextUpdateWordPlace, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVariableTextAjustLineHeader, (FR_VariableText variableText,  FR_VTWordPlace place,  FS_BOOL bPrevOrNext,  FR_VTWordPlace* outPlace))

INTERFACE(FS_INT32, FRInternalVariableTextWordPlaceToWordIndex, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(void, FRInternalVariableTextWordIndexToWordPlace, (FR_VariableText variableText,  FS_INT32 index,  FR_VTWordPlace* outPlace))

INTERFACE(FS_BOOL, FRInternalVariableTextIsSectionComplexScript, (FR_VariableText variableText,  FR_VTWordPlace place))

INTERFACE(FS_BOOL, FRInternalVariableTextIsVerticalFont, (FR_VariableText variableText,  FS_INT32 nFontindex))

INTERFACE(FR_Edit_FontMap, FRInternalEditFontMapGetDocFontMap, (FPD_Document fpdDoc))

INTERFACE(void, FRInternalEditFontMapEncodeFontAlias, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_ByteString* outAlias))

INTERFACE(void, FRInternalEditFontMapGetFontName, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_ByteString* outName))

INTERFACE(FS_INT32, FRInternalEditFontMapGetCharset, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(void*, FRInternalEditFontMapGetFXFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FPD_Font, FRInternalEditFontMapGetPDFFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWordArray unicodeArray,  FS_BOOL bEmbedFont))

INTERFACE(FS_INT32, FRInternalEditFontMapGetCharWidthF, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD charcode,  FS_INT32 level))

INTERFACE(FS_INT32, FRInternalEditFontMapCharCodeFromUnicode, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_WORD word))

INTERFACE(FS_DWORD, FRInternalEditFontMapGlyphFromCharCode, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD charcode))

INTERFACE(FS_INT32, FRInternalEditFontMapCharSetFromUnicode, (FR_Edit_FontMap editFontMap,  FS_WORD word,  FS_INT32 nOldCharset))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndexByUnicode, (FR_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FS_BOOL bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndex, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FS_BOOL bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_BOOL, FRInternalIsEmbedded, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalSetFXFMEditFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalGlyphFromCharCode2, (FR_Edit_FontMap editFontMap,  FS_WCHAR* wcUnicodes,  FS_INT32 nUnicodeCount,  FS_DWordArray* outGlyphs,  FS_DWordArray* outGlyhCounts))

INTERFACE(FS_INT32, FRInternalEditFontMapAddFXFont, (FR_Edit_FontMap editFontMap,  void* pFXFont,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FS_INT32, FRInternalEditFontMapAddPDFFont, (FR_Edit_FontMap editFontMap,  FPD_Font fpdFont,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset))

INTERFACE(FPD_Document, FRInternalEditFontMapGetDocument, (FR_Edit_FontMap editFontMap))

INTERFACE(FS_INT32, FRInternalEditFontMapLoadAllFontByDict, (FR_Edit_FontMap editFontMap,  FR_PageView frPageView,  FPD_Object annotDict,  FS_LPCSTR lpsApType))

INTERFACE(FS_BOOL, FRInternalEditFontMapCheckCharacterIsSupported, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex,  FS_DWORD dwUnicode))

INTERFACE(FS_BOOL, FRInternalEditFontMapGetStandardFont, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_ByteString* outStandardFont))

INTERFACE(FS_BOOL, FRInternalEditFontMapIsExternalEmbedFont, (FR_Edit_FontMap editFontMap,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextWord, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextLine, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorNextSection, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevWord, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevLine, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorPrevSection, (FR_Edit_Iterator editIterator))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetWord, (FR_Edit_Iterator editIterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetDisplayWord, (FR_Edit_Iterator editIterator,  FR_VTWord* outWord))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetLine, (FR_Edit_Iterator editIterator,  FR_VTLine* outLine))

INTERFACE(FS_BOOL, FRInternalEditIteratorGetSection, (FR_Edit_Iterator editIterator,  FR_VTSection* outSection))

INTERFACE(void, FRInternalEditIteratorSetAt, (FR_Edit_Iterator editIterator,  FS_INT32 nWordIndex))

INTERFACE(void, FRInternalEditIteratorSetAtII, (FR_Edit_Iterator editIterator,  FR_VTWordPlace place))

INTERFACE(void, FRInternalEditIteratorGetAt, (FR_Edit_Iterator editIterator,  FR_VTWordPlace* outWordPlace))

INTERFACE(FR_Edit, FRInternalEditIteratorGetEdit, (FR_Edit_Iterator editIterator))

INTERFACE(FR_Edit, FRInternalEditNew, ())

INTERFACE(void, FRInternalEditDel, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetFontMap, (FR_Edit edit,  FR_Edit_FontMap fontMap,  FS_INT32 nDefaultFontIndex))

INTERFACE(void, FRInternalEditSetVTProvider, (FR_Edit edit,  FR_VariableText_Provider provider))

INTERFACE(void*, FRInternalEditSetNotify, (FR_Edit edit,  FR_EditNotifyCallbacks callbacks))

INTERFACE(void*, FRInternalEditSetOprNotify, (FR_Edit edit,  FR_EditOprNotifyCallbacks callbacks))

INTERFACE(FR_Edit_Iterator, FRInternalEditGetIterator, (FR_Edit edit))

INTERFACE(FR_VariableText, FRInternalEditGetVariableText, (FR_Edit edit))

INTERFACE(FR_Edit_FontMap, FRInternalEditGetFontMap, (FR_Edit edit))

INTERFACE(void, FRInternalEditInitialize, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetPlateRect, (FR_Edit edit,  FS_FloatRect rect,  FS_BOOL bPaint,  FS_BOOL bVerticalWriting))

INTERFACE(void, FRInternalEditSetScrollPos, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(FS_BOOL, FRInternalEditIsVerticalWriting, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetAlignmentH, (FR_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAlignmentV, (FR_Edit edit,  FS_INT32 nFormat,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetPasswordChar, (FR_Edit edit,  FS_WORD wSubWord,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetLimitChar, (FR_Edit edit,  FS_INT32 nLimitChar,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetCharArray, (FR_Edit edit,  FS_INT32 nCharArray,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetCharSpace, (FR_Edit edit,  FS_FLOAT fCharSpace,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetWordSpace, (FR_Edit edit,  FS_FLOAT fWordSpace,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetHorzScale, (FR_Edit edit,  FS_FLOAT fHorzScale,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetLineLeading, (FR_Edit edit,  FS_FLOAT fLineLeading,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetMultiLine, (FR_Edit edit,  FS_BOOL bMultiLine,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoReturn, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoFontSize, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetAutoScroll, (FR_Edit edit,  FS_BOOL bAuto,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetFontSize, (FR_Edit edit,  FS_FLOAT fFontSize,  FS_BOOL bPaint))

INTERFACE(void, FRInternalEditSetTextOverflow, (FR_Edit edit,  FS_BOOL bAllowed,  FS_BOOL bPaint))

INTERFACE(void, FRInternalSetDirectionRTL, (FR_Edit edit,  FS_BOOL bRTL,  FS_BOOL bApplyAllSection,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditIsRichText, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetRichText, (FR_Edit edit,  FS_BOOL bRichText,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextFont, (FR_Edit edit,  FS_LPCSTR lpsFontName,  FS_INT32 nFontIndex))

INTERFACE(FS_BOOL, FRInternalSetRichTextIsBold, (FR_Edit edit,  FS_BOOL bBold,  FS_BOOL bNeedToReaderingMode))

INTERFACE(FS_BOOL, FRInternalSetRichTextIsItalic, (FR_Edit edit,  FS_BOOL bItalic))

INTERFACE(FS_BOOL, FRInternalEditSetRichFontSize, (FR_Edit edit,  FS_FLOAT fFontSize))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextColor, (FR_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextStrokeColor, (FR_Edit edit,  FS_COLORREF dwColor))

INTERFACE(FS_BOOL, FRInternalEditSetRichRenderingMode, (FR_Edit edit,  FS_INT32 nRenderingMode))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextScript, (FR_Edit edit,  FS_INT32 nScriptType))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextUnderline, (FR_Edit edit,  FS_BOOL bUnderline))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextCrossout, (FR_Edit edit,  FS_BOOL bCrossout))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextCharSpace, (FR_Edit edit,  FS_FLOAT fCharSpace))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextWordSpace, (FR_Edit edit,  FS_FLOAT fWordSpace))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextHorzScale, (FR_Edit edit,  FS_FLOAT fHorzScale))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextLineLeading, (FR_Edit edit,  FS_FLOAT fLineLeading))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextLineIndent, (FR_Edit edit,  FS_FLOAT fLineIndent))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextAlignment, (FR_Edit edit,  FS_INT32 nAlignment))

INTERFACE(FS_BOOL, FRInternalEditSetRichTextSoftReturn, (FR_Edit edit,  FS_BOOL bEnable))

INTERFACE(void, FRInternalEditSetSel, (FR_Edit edit,  FS_INT32 nStartChar,  FS_INT32 nEndChar))

INTERFACE(void, FRInternalEditGetSel, (FR_Edit edit,  FS_INT32* nStartChar,  FS_INT32* nEndChar))

INTERFACE(void, FRInternalEditSelectAll, (FR_Edit edit))

INTERFACE(void, FRInternalEditSelectNone, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetCaret, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetCaretWordPlace, (FR_Edit edit,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSelText, (FR_Edit edit,  FS_WideString* outText))

INTERFACE(void, FRInternalEditGetText, (FR_Edit edit,  FS_WideString* outText))

INTERFACE(void, FRInternalEditGetRichTextXML, (FR_Edit edit,  FS_LPCWSTR ds,  FS_BOOL bSaveLineFeed,  FS_WideString* outXML))

INTERFACE(FS_BOOL, FRInternalEditIsSelected, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetScrollPos, (FR_Edit edit,  FS_FLOAT* x,  FS_FLOAT* y))

INTERFACE(FS_FloatRect, FRInternalEditGetPlateRect, (FR_Edit edit))

INTERFACE(FS_FloatRect, FRInternalEditGetContentRect, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetVisibleWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditGetWholeWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditGetSelectWordRange, (FR_Edit edit,  FR_VTWordRange* outWordRange))

INTERFACE(void, FRInternalEditOnMouseDown, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnMouseMove, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_UP, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_DOWN, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_LEFT, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_RIGHT, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_HOME, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditOnVK_END, (FR_Edit edit,  FS_BOOL bShift,  FS_BOOL bCtrl))

INTERFACE(void, FRInternalEditSetText, (FR_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps))

INTERFACE(void, FRInternalEditSetRichTextByXML, (FR_Edit edit,  FS_LPCWSTR xml,  FS_LPCWSTR ds,  FS_INT32 charset))

INTERFACE(FS_BOOL, FRInternalEditInsertWord, (FR_Edit edit,  FS_WORD word,  FS_INT32 charset,  FR_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FRInternalEditInsertReturn, (FR_Edit edit,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps,  FS_BOOL bPaint))

INTERFACE(FS_BOOL, FRInternalEditInsertText, (FR_Edit edit,  FS_LPCWSTR text,  FS_INT32 charset,  FR_VTSecProps secProps,  FR_VTWordProps pWordProps,  FS_BOOL bPaint,  FS_BOOL bNeedTransform))

INTERFACE(FS_BOOL, FRInternalEditBackspace, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditDelete, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditClear, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditRedo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditUndo, (FR_Edit edit))

INTERFACE(void, FRInternalEditSetCaret, (FR_Edit edit,  FS_INT32 nPos))

INTERFACE(void, FRInternalEditPaint, (FR_Edit edit))

INTERFACE(void, FRInternalEditEnableRefresh, (FR_Edit edit,  FS_BOOL bRefresh))

INTERFACE(void, FRInternalEditRefreshWordRange, (FR_Edit edit,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditEnableUndo, (FR_Edit edit,  FS_BOOL bUndo))

INTERFACE(void, FRInternalEditEnableNotify, (FR_Edit edit,  FS_BOOL bNotify))

INTERFACE(void, FRInternalEditEnableOprNotify, (FR_Edit edit,  FS_BOOL bNotify))

INTERFACE(FS_INT32, FRInternalEditWordPlaceToWordIndex, (FR_Edit edit,  FR_VTWordPlace wordPlace))

INTERFACE(void, FRInternalEditWordIndexToWordPlace, (FR_Edit edit,  FS_INT32 index,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetLineBeginPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetLineEndPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSectionBeginPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditGetSectionEndPlace, (FR_Edit edit,  FR_VTWordPlace wordPlace,  FR_VTWordPlace* outWordPlace))

INTERFACE(void, FRInternalEditSearchWordPlace, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordPlace* outWordPlace))

INTERFACE(FS_FLOAT, FRInternalEditGetFontSize, (FR_Edit edit))

INTERFACE(FS_WORD, FRInternalEditGetPasswordChar, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetCharArray, (FR_Edit edit))

INTERFACE(FS_FLOAT, FRInternalEditGetHorzScale, (FR_Edit edit))

INTERFACE(FS_FLOAT, FRInternalEditGetCharSpace, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetRangeText, (FR_Edit edit,  FR_VTWordRange wordRange,  FS_WideString* outText))

INTERFACE(FS_BOOL, FRInternalEditIsTextFull, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditCanUndo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditCanRedo, (FR_Edit edit))

INTERFACE(void, FRInternalEditResetUndo, (FR_Edit edit))

INTERFACE(FS_BOOL, FRInternalEditIsModified, (FR_Edit edit))

INTERFACE(FS_INT32, FRInternalEditGetTotalWords, (FR_Edit edit))

INTERFACE(void*, FRInternalEditAddUndoItem, (FR_Edit edit,  FR_EditUndoItemCallbacks callbacks))

INTERFACE(void, FRInternalBeginGroupUndo, (FR_Edit edit,  FS_LPCWSTR lpwsTitle))

INTERFACE(void, FRInternalEndGroupUndo, (FR_Edit edit))

INTERFACE(void, FRInternalEditSaveLineOffset, (FR_Edit edit))

INTERFACE(void, FRInternalEditGetEditAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_ByteString* outStream))

INTERFACE(void, FRInternalEditGetRichEditAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_BOOL bContinuous,  FS_WORD SubWord,  FR_EDIT_FontData* outFontDataArray,  FS_INT32* outFontDataArrayCount,  FS_ByteString* outStream,  FS_ByteString pPathStream))

INTERFACE(void, FRInternalEditGetSelectAppearanceStream, (FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_ByteString* outStream))

INTERFACE(void, FRInternalEditDrawEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_COLORREF crTextFill,  FS_COLORREF crTextStroke,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditDrawUnderline, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_COLORREF color,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange))

INTERFACE(void, FRInternalEditDrawRichEdit, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_AffineMatrix text2Uer))

INTERFACE(void, FRInternalEditGeneratePageObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_COLORREF crText,  FS_PtrArray* outTextObjectArray))

INTERFACE(void, FRInternalEditGenerateRichPageObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_PtrArray* outTextObjectArray,  FS_POSITION* outPos,  FS_PtrArray* outPathObjectArray))

INTERFACE(void, FRInternalEditGenerateUnderlineObjects, (void* pPageObjects,  FR_Edit edit,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_COLORREF color))

INTERFACE(void, FRInternalEditGetRichTextPlainText, (FS_LPCWSTR xml,  FS_WideString* outText))

INTERFACE(FR_Touchup, FRInternalGetTouchup, ())

INTERFACE(void, FRInternalBeginEditTextObject, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView frPageView,  FR_Text_Object_OP* objList,  FS_INT32 nObjListCount,  FR_Text_Object_OP_Result* pOutResult))

INTERFACE(void, FRInternalEndEditTextObject, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView frPageView,  FR_Text_Object_OP* objList,  FS_INT32 nObjListCount,  FR_Text_Object_OP_Result* pOutResult))

INTERFACE(void, FRInternalEmailUtilSendMailUseConfig, (FS_LPCWSTR toRecipientList,  FS_LPCWSTR ccRecipientList,  FS_LPCWSTR bccRecipientList,  FS_LPCWSTR subject,  FS_LPCWSTR message,  FS_LPCWSTR attachmentPath,  FS_LPCWSTR attachmentName,  HWND hWndParent,  FS_BOOL asyncMode,  FS_BOOL showUI,  FR_EmailUtilSendMailCallbacks eventHandler,  FS_INT32 *errorCode,  FS_INT32 *specificErrorCode,  FS_WideString *localizedErrorMessage))

INTERFACE(void, FRInternalEmailUtilShowAddressBook, (FS_WideStringArray *toRecipients,  FS_WideStringArray *ccRecipients,  FS_WideStringArray *bccRecipients,  HWND hWndParent,  FS_INT32 editFields,  FS_INT32 *errorCode,  FS_INT32 *specificErrorCode,  FS_WideString *localizedErrorMessage))

INTERFACE(FS_BOOL, FRInternalIsKeyAndTrialValid, ())

INTERFACE(FS_BOOL, FRInternalCheckLicense, ())

INTERFACE(FS_BOOL, FRInternalEditIsPunctuation, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsCJK, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsLatin, (FS_DWORD word))

INTERFACE(FS_BOOL, FRInternalEditIsNeedToConvertSpace, (FS_DWORD word))

INTERFACE(void, FRInternalGetCustomString, (FS_LPCSTR lpsKey,  FS_WideString* outValue))

INTERFACE(void, FRInternalEditDestroyNotify, (void* editNotify))

INTERFACE(void, FRInternalEditDestroyOprNotify, (void* editOprNotify))

INTERFACE(void, FRInternalSetDocReviewIdentity, (FR_Document frDoc,  FS_LPCWSTR lpwsIdName,  FS_LPCWSTR lpwsIdEmailAddr))

INTERFACE(void, FRInternalGetDocReviewIdentityName, (FR_Document frDoc,  FS_WideString* outIdName))

INTERFACE(void, FRInternalGetDocReviewIdentityEmail, (FR_Document frDoc,  FS_WideString* outIdEmailAddr))

INTERFACE(FS_BOOL, FRInternalHasVisibleTextObj, (FR_Touchup touchup,  FR_Document frDoc,  FR_PageView pageView,  FS_BOOL bPopDlg))

INTERFACE(FR_ProfStore, FRInternalGetProfStoreManager, ())

INTERFACE(FS_BOOL, FRInternalProfStoreGetString, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideString* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreGetInt, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  DWORD* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreGetBoolean, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpRegKey,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_BOOL* outValue,  FS_BOOL bUseDefValue))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumAllKeyName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyValueName, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyValueName))

INTERFACE(FS_BOOL, FRInternalProfStoreEnumKeyValue, (FR_ProfStore profStore,  FS_LPCWSTR lpRegSection,  FS_LPCWSTR lpXmlSection,  FS_LPCWSTR lpXmlKey,  FS_LPCSTR lpAttrib,  FS_WideStringArray* outArrKeyValue))

INTERFACE(void, FRInternalGWL10NHelperAutoResizeDropWidth, (void* pComboBox))

INTERFACE(void, FRInternalGWL10NHelperResetItemDropWidth, (void* pCWnd))

INTERFACE(HWND, FRInternalGetActivePopupMenuMessageWnd, ())

INTERFACE(void, FRInternalGetPhoneNumber, (FS_WideString* wsSales,  FS_WideString* wsSupport))

INTERFACE(void, FRInternalGetEditionTitle, (FS_WideString* wsExpress,  FS_WideString* wsStandard,  FS_WideString* wsBusiness))

INTERFACE(void, FRInternalGetEmail, (FS_WideString* wsSales,  FS_WideString* wsSupport))

INTERFACE(FS_BOOL, FRInternalEditGetWordLatinSmallLigature, (FS_DWORD* src,  FS_INT32 nSrcCount,  FS_DWORD* outDest,  int* outDstCount))

INTERFACE(FPD_Document, FRInternalGetClonedDoc, (FPD_Document pSrcDoc))

INTERFACE(void, FRInternalEditFontMapReleaseDocFontMap, (FPD_Document fpdDoc))

INTERFACE(void*, FRInternalCreateActionWizardHandlerMgr, (FR_ActionWizardHandlerMgrCallbacks callbacks))

INTERFACE(void, FRInternalDestroyActionWizardHandlerMgr, (void* actionWizardHandlerMgr))

INTERFACE(void, FRInternalSetActionWizardHandlerMgr, (void* pActionWizardHandlerMgr))

INTERFACE(void*, FRInternalGetActionWizardHandlerMgr, ())

INTERFACE(FR_ActionWizardHandler, FRInternalCreateActionWizardHandler, (FR_ActionWizardHandlerCallbacks callbacks))

INTERFACE(void, FRInternalDestroyActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalRegisterActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalUnRegisterActionWizardHandler, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(void, FRInternalActionWizardHandlerGetName, (FR_ActionWizardHandler actionWizardHandler,  FS_ByteString outName))

INTERFACE(void, FRInternalActionWizardHandlerGetCommandName, (FR_ActionWizardHandler actionWizardHandler,  FS_ByteString outCommandName))

INTERFACE(FS_INT32, FRInternalActionWizardHandlerGetPresetFlag, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerSetting, (FR_ActionWizardHandler actionWizardHandler,  FS_XMLElement pXML,  HWND hWnd))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerExecute, (FR_ActionWizardHandler actionWizardHandler,  FS_XMLElement pXML,  FS_BOOL bpromptUser,  FRActionWizardExcuteStatus* outStatus))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerGetTitle, (FR_ActionWizardHandler actionWizardHandler,  FS_LPCSTR lpsName,  FS_WideString outTitle))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerNeedReopen, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerNeedChangeExecuteDoc, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_BOOL, FRInternalExportAnnotToXFDF2, (void* pAnnot,  FS_XMLElement xmlElement,  FS_BOOL bShareReview))

INTERFACE(void*, FRInternalImprotAnnotFromXFDF2, (FR_Document frDoc,  FS_XMLElement xmlAnnot,  FS_BOOL bSendAnnotChangeToNotify,  FS_BOOL bShareReview,  FS_ByteString bsUserId,  FS_BOOL* pbEditing))

INTERFACE(FS_BOOL, FRInternalSubscribeShowRibbonUI, (FRSubscriptionFlowName subWorkflowName))

INTERFACE(FS_BOOL, FRInternalSubscribeStartWorkflow, (FRSubscriptionFlowName subWorkflowName,  FS_WideString outReturnValue))

INTERFACE(FS_BOOL, FRInternalSubscribeIsLicenseRevoked, ())

INTERFACE(FS_BOOL, FRInternalSubscribeShowFlash, ())

INTERFACE(FR_CPDFPluginProvider, FRInternalCPDFPluginProviderSet, (FR_CPDFPluginProviderCallbacks callbacks))

INTERFACE(void, FRInternalCPDFPluginProviderDestroy, (FR_CPDFPluginProvider loginProvider))

INTERFACE(FR_CPDFPluginProvider, FRInternalCPDFPluginProviderGet, ())

INTERFACE(FS_BOOL, FRInternalCPDFPluginProviderShowConnectedPDFAdDialog, (FR_CPDFPluginProvider loginProvider))

INTERFACE(FS_INT32, FRInternalGetRemainDays, ())

INTERFACE(FS_DWORD, FRInternalCommentsAnnotSetUpdateServerTime, (FR_Document frDoc,  FS_XMLElement pAnnot))

INTERFACE(void, FRInternalGetLicenseSN, (FS_WideString* outSN))

INTERFACE(FS_INT32, FRInternalGetKeyfileType, ())

INTERFACE(void, FRInternalGetFormatSymbolString, (FS_LPCWSTR str,  FS_BOOL bInput,  FS_BOOL bSeperate,  FS_WideString* outResult))

INTERFACE(void, FRInternalGetLocalFormatTimeString, (SYSTEMTIME* sys,  FS_WideString* outFormat))

INTERFACE(FS_INT32, FRInternalConvertToPDFGetFileType, (FS_LPCWSTR lpwsFile))

INTERFACE(void, FRInternalGetFileFilter, (unsigned long uFilter,  FS_WideString* outFilter))

INTERFACE(FS_BOOL, FRInternalRegisterDocHandlerOfPDDocForActionWizard, (FR_DocEventForActionWizardCallbacks docEventCallbacks))

INTERFACE(void, FRInternalCommentsAnnotSetIconState, (FR_Document frDoc,  FS_INT32 nPageIndex,  FS_LPCWSTR lpwsAnnotName,  FRCommentsAnnotIconState nIconState))

INTERFACE(void, FRInternalGetAnnotInputFontName, (FS_WideString* outFontName))

INTERFACE(FS_BOOL, FRInternalIsDisableCPDF, ())

INTERFACE(FS_BOOL, FRInternalRunJSPluginByFlag, (FS_DWORD dwFlag))

INTERFACE(FS_BOOL, FRInternalRunJSPluginByName, (FS_LPCSTR lpsName))

INTERFACE(FS_BOOL, FRInternalIsJSPanelActivated, (FS_LPCSTR lpsName))

INTERFACE(void, FRInternalExpandJSPanel, (FS_LPCSTR lpsName,  FS_BOOL bExpand))

INTERFACE(void*, FRInternalEditSetDrawNotify, (FR_Edit edit,  FR_EditDrawNotifyCallbacks callbacks))

INTERFACE(void, FRInternalEditDestroyDrawNotify, (void* editDrawNotify))

INTERFACE(void, FRInternalEmailUtilRegisterPreSendMailHandler, (FR_EmailUtilPreSendMailCallbacks eventHandler))

INTERFACE(void, FRInternalGetCurEditonTitle, (FS_WideString* outTitle))

INTERFACE(FS_BOOL, FRInternalIsDisableInternet, (FS_BOOL bShowDisableMessageBox))

INTERFACE(FS_BOOL, FRInternalIsUseSystemSelectionColor, ())

INTERFACE(void, FRInternalEditSetSelBkColor, (FR_Edit edit,  FS_ARGB color))

INTERFACE(void, FRInternalEditDrawRichEdit2, (FPD_RenderDevice pDevice,  FS_AffineMatrix user2Device,  FR_Edit edit,  FS_FloatRect rcClip,  FS_FLOAT x,  FS_FLOAT y,  FR_VTWordRange wordRange,  FS_AffineMatrix text2Uer,  FS_COLORREF cShowColor))

INTERFACE(FS_BOOL, FRInternalIsJSPluginDisabled, (FS_LPCSTR lpsName))

INTERFACE(FS_INT32, FRInternalGetAccReadingOrderMode, ())

INTERFACE(FS_BOOL, FRInternalIsAccOverrideReadingOrder, ())

INTERFACE(FS_INT32, FRInternalGetDocAccReadingOrder, (FR_Document frDoc))

INTERFACE(FS_INT32, FRInternalGetDocAccReadingMode, (FR_Document frDoc))

INTERFACE(void, FRInternalSetReadActivateStatus, (FS_BOOL bActivateRead))

INTERFACE(FS_BOOL, FRInternalGetReadActivateStatus, ())

INTERFACE(FR_WIPPluginProvider, FRInternalWIPPluginProviderSet, (FR_WIPPluginProviderCallbacks callbacks))

INTERFACE(void, FRInternalWIPPluginProviderDestroy, (FR_WIPPluginProvider loginProvider))

INTERFACE(FR_WIPPluginProvider, FRInternalWIPPluginProviderGet, ())

INTERFACE(FS_BOOL, FRInternalWIPPluginProviderAllowedPaste, ())

INTERFACE(FS_BOOL, FRInternalThemeCheckHCMT, ())

INTERFACE(void, FRInternalThemeGetTextColor, (FS_COLORREF* clrText))

INTERFACE(void, FRInternalThemeGetDisableTextColor, (FS_COLORREF* clrDisableTextColor))

INTERFACE(void, FRInternalThemeGetHyperlinkTextColor, (FS_COLORREF* clrText))

INTERFACE(void, FRInternalThemeGetSelectedTextColor, (FS_COLORREF* clrTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetButtonTextColor, (FS_COLORREF* clrBtnTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetTooltipColor, (FS_COLORREF* clrTextColor,  FS_COLORREF* clrBackgroundColor))

INTERFACE(void, FRInternalThemeGetBackgroundColor, (FS_COLORREF* clrBkColor))

INTERFACE(void, FRInternalEmailUtilRegisterAttachmentNameModifier, (FR_EmailUtilAttachmentNameModifier modifier))

INTERFACE(void, FRInternalGetAppSaveAsLocation, (FS_WideString wsFullPath))

INTERFACE(void, FRInternalLoadJSPlugin, (FS_BOOL bSlient))

INTERFACE(FS_BOOL, FRInternalActionWizardHandlerIsEnableExecute, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(void, FRInternalActionWizardHandlerExecuteDone, (FR_ActionWizardHandler actionWizardHandler))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndexByUnicode2, (FR_Edit_FontMap editFontMap,  FS_WCHAR wUnicode,  FS_LPCSTR lpsDefaultFontName,  FS_DWORD dwFontStyle,  FS_INT32 nCharSet,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FS_INT32, FRInternalEditFontMapGetFontIndex2, (FR_Edit_FontMap editFontMap,  FS_LPCSTR lpsFontName,  FS_INT32 nCharset,  FS_DWORD dwFontStyle,  FS_BOOL bAdd,  FRFMTribool bNeedEmbed,  FS_BOOL bVertical))

INTERFACE(FR_Compare_Results*, FRInternalCompareGetDifInfos, (FPD_Page pageOld,  FPD_Page pageNew,  FS_INT32 nOpt))

INTERFACE(void, FRInternalCompareReleaseDifInfos, (FR_Compare_Results* pCompareResults))

INTERFACE(void, FRInternalCompareDrawNoteAP, (FPD_Document pDocument,  FPD_Object pAnnotDic,  FS_INT32 nNoteType,  FS_FLOAT x,  FS_FLOAT y))

INTERFACE(void, FRInternalGetCreationDate, (FPD_Document pDocument,  FS_WideString outCreationDate))

INTERFACE(void, FRInternalSetReadStatus, (FS_BOOL bActivateRead))

INTERFACE(FS_BOOL, FRInternalGetReadStatus, ())

NumOfSelector(FRInternal)
ENDENUM

//*****************************
/* SpellCheck HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRSpellCheckNew
 * @details Creates a <a>FR_SpellCheck</a> object used to check spelling.
 * @param[in]  lpwsModuleName The input module name.
 * @return   A new <a>FR_SpellCheck</a> object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRSpellCheckDestroy
 * @see FRSpellCheckCheckWord
 */
INTERFACE(FR_SpellCheck, FRSpellCheckNew, (FS_LPCWSTR lpwsModuleName))

/**
 * @brief FRSpellCheckDestroy
 * @details Destroys the input <a>FR_SpellCheck</a> object.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRSpellCheckDestroy, (FR_SpellCheck spellCheck))

/**
 * @brief FRSpellCheckCheckWord
 * @details Checks whether the input words are correct or not.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @param[in]  sWord The input words to be checked.
 * @return   <a>TRUE</a> if the words are checked correctly, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(FS_BOOL, FRSpellCheckCheckWord, (FR_SpellCheck spellCheck,  FS_LPCWSTR sWord))

/**
 * @brief FRSpellCheckSuggestWords
 * @details Input the words to get its suggested words.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @param[in]  sWord The input words.
 * @param[out]  outSuggest It receives the suggested words.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRSpellCheckSuggestWords, (FR_SpellCheck spellCheck,  FS_LPCWSTR sWord,  FS_WideStringArray* outSuggest))

/**
 * @brief FRSpellCheckIgnore
 * @details Ignores the input words that will not be checked.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @param[in]  sWord The input words to be ignored.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see 
 */
INTERFACE(void, FRSpellCheckIgnore, (FR_SpellCheck spellCheck,  FS_LPCWSTR sWord))

/**
 * @brief FRSpellCheckCheckString
 * @details Checks the spelling of the input byte string and receives the errors.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @param[in]  csString The input byte string that will be checked.
 * @param[out]  outErrBufArr It receives the errors.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRSpellCheckCheckWord
 */
INTERFACE(void, FRSpellCheckCheckString, (FR_SpellCheck spellCheck,  FS_WideString sString,  FS_WideStringArray* outErrBufArr))

/**
 * @brief FRSpellCheckAddDic
 * @details Adds the new words to the dictionary.
 * @param[in]  spellCheck The input <a>FR_SpellCheck</a> object.
 * @param[in]  sWord The input new words.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.0
 * @see FRSpellCheckNew
 */
INTERFACE(void, FRSpellCheckAddDic, (FR_SpellCheck spellCheck,  FS_LPCWSTR sWord))

NumOfSelector(FRSpellCheck)
ENDENUM

//----------_V6----------
//----------_V7----------
//*****************************
/* HTMLMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRHTMLMgrGet
 * @details Gets the <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
 * @return   The <a>FR_HTMLMgr</a> object is used to manage the HTML windows in <Italic>Foxit Reader</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FR_HTMLMgr, FRHTMLMgrGet, (void))

/**
 * @brief FRHTMLMgrRegisterHTMLEventHandler
 * @details Registers the HTML event handler.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  callbacks The callback set for HTML window event handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRHTMLMgrRegisterHTMLEventHandler, (FR_HTMLMgr mgr,  FR_HTMLEventCallbacks callbacks))

/**
 * @brief FRHTMLMgrOpenHTMLFromNewTab
 * @details Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  bCreatePanel Whether to create the navigation panel or not.
 * @param[in]  bMakeVisible Determines whether to make the HTML window visible or not.
 * @param[in]  bAddToMRU Determines whether the filename is added to the most recently used (MRU) file list.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLFromNewTab, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU))

/**
 * @brief FRHTMLMgrOpenHTMLDocument
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  hParentWnd The parent window of the HTML window.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLDocument, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  HWND hParentWnd))

/**
 * @brief FRHTMLMgrGetActiveHtmlView
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @return   The pointer to <Italic>MFC CHtmlView</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void*, FRHTMLMgrGetActiveHtmlView, (FR_HTMLMgr mgr))

/**
 * @brief FRHTMLMgrRegisterFoxitBrowserEventHandler
 * @details Registers the Foxit browser event handler to receive the event notifications.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  callbacks The callback set for Foxit browser event handler.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 */
INTERFACE(FS_BOOL, FRHTMLMgrRegisterFoxitBrowserEventHandler, (FR_HTMLMgr mgr,  FR_FoxitBrowserEventCallbacks callbacks))

/**
 * @brief FRHTMLMgrSetFoxitBrowserHome
 * @details Sets the home URL of the Foxit browser.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 */
INTERFACE(void, FRHTMLMgrSetFoxitBrowserHome, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL))

/**
 * @brief FRHTMLMgrSetFavoritesLink
 * @details Sets the favorite link to Foxit favorite bar.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpName The displaying name of the favorite link.
 * @param[in]  lpURL The input URL of the favorite link.
 * @param[in]  lpUrlIcon The URL of the displaying icon.
 * @param[in]  bAdd Whether to add the favorite link or to delete it.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2
 * @see 
 */
INTERFACE(void, FRHTMLMgrSetFavoritesLink, (FR_HTMLMgr mgr,  FS_LPCWSTR lpName,  FS_LPCWSTR lpUrl,  FS_LPCWSTR lpUrlIcon,  FS_BOOL bAdd))

/**
 * @brief FRHTMLMgrGetHtmlViewFromHandle
 * @details Gets a new HTML window from the window handle.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  hWnd The input HTML view handle.
 * @return   The pointer to <Italic>MFC CHtmlView</Italic>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 * @see 
 */
INTERFACE(void*, FRHTMLMgrGetHtmlViewFromHandle, (FR_HTMLMgr mgr,  HWND hWnd))

/**
 * @brief FRHTMLMgrOpenHTMLFromNewTab2
 * @details Opens a new HTML window. Foxit Reader will create a new tab for the new HTML window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  bCreatePanel Whether to create the navigation panel or not.
 * @param[in]  bMakeVisible Determines whether to make the HTML window visible or not.
 * @param[in]  bAddToMRU Determines whether the filename is added to the most recently used (MRU) file list.
 * @param[in]  hIcon The icon added to the tab band.
 * @param[in]  bHideURL Whether to hide the URL or not.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLFromNewTab2, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  FS_BOOL bCreatePanel,  FS_BOOL bMakeVisible,  FS_BOOL bAddToMRU,  HICON hIcon,  FS_BOOL bHideURL))

/**
 * @brief FRHTMLMgrOpenHTMLDocument2
 * @details Opens a new HTML window on the specified parent window.
 * @param[in]  mgr The input HTML manager object.
 * @param[in]  lpURL The input URL to be opened in the HTML window.
 * @param[in]  lpTitle The title of the frame which will be created.
 * @param[in]  hParentWnd The parent window of the HTML window.
 * @param[in]  bHideURL Whether to hide the URL or not.
 * @return   The handle of the HTML window.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3
 * @see 
 */
INTERFACE(HWND, FRHTMLMgrOpenHTMLDocument2, (FR_HTMLMgr mgr,  FS_LPCWSTR lpURL,  FS_LPCWSTR lpTitle,  HWND hParentWnd,  FS_BOOL bHideURL))

NumOfSelector(FRHTMLMgr)
ENDENUM

//*****************************
/* PanelMgr HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRPanelMgrGetPanelMgrFromChildFrm
 * @details Gets the specified panel manager.
 * @param[in]  hChildFrm The specified child frame.
 * @return   The specified panel manager.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FR_PanelMgr, FRPanelMgrGetPanelMgrFromChildFrm, (HWND hChildFrm))

/**
 * @brief FRPanelMgrNewPanelMgr
 * @details Creates an instance of the panel manager. You have to invoke <a>FRPanelMgrCreate</a> then.
 * @param[in]  hParentWnd The input parent window.
 * @return   The new panel manager.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
 */
INTERFACE(FR_PanelMgr, FRPanelMgrNewPanelMgr, (HWND hParentWnd))

/**
 * @brief FRPanelMgrDeletePanelMgr
 * @details Deletes the panel manager.
 * @param[in]  hParentWnd The input panel manager.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrDeletePanelMgr, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrCreatePanelEventHandler
 * @details Creates the pointer to the panel event handler.
 * @param[in]  callbacks A callback set for the panel event handler.
 * @return   The pointer to the panel event handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
 */
INTERFACE(void*, FRPanelMgrCreatePanelEventHandler, (FR_PanelEventCallbacks callbacks))

/**
 * @brief FRPanelMgrDestroyPanelEventHandler
 * @details Destroys the panel event handler.
 * @param[in]  panelEventHandler The pointer to the panel event handler.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrCreate
 */
INTERFACE(void, FRPanelMgrDestroyPanelEventHandler, (void* panelEventHandler))

/**
 * @brief FRPanelMgrCreate
 * @details Creates the panel manager after <a>FRPanelMgrNewPanelMgr</a>.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  pParentWnd The input parent window.
 * @param[in]  nTablocation Specifies the tab location.
 * @param[in]  dwEnabledAlignment Specifies the enabled alignment. References to MFC ControlBar styles.
 * @param[in]  panelEventHandler The input panel event handler to receive the event occurred.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see FRPanelMgrNewPanelMgr
 */
INTERFACE(FS_BOOL, FRPanelMgrCreate, (FR_PanelMgr panelMgr,  void* pParentWnd,  FS_INT32 nTablocation,  FS_DWORD dwEnabledAlignment,  void* panelEventHandler))

/**
 * @brief FRPanelMgrDockToFrameWindow
 * @details Docks the panel to the frame window.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  dwAlignment Specifies the alignment. References to MFC ControlBar styles.
 * @return   True for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrDockToFrameWindow, (FR_PanelMgr panelMgr,  FS_DWORD dwAlignment))

/**
 * @brief FRPanelMgrAddPanel
 * @details Adds a panel.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csToolTip The tool tip of the panel.
 * @param[in]  csText The display text of the panel.
 * @param[in]  csName The name of the panel.
 * @param[in]  pBitmap The icon of the panel.
 * @param[in]  bInitialShow Whether to show the panel at the first time.
 * @param[in]  bDockBottom Whether the panel is docked to the bottom or not.
 * @return   The handle to the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRPanelMgrAddPanel, (FR_PanelMgr panelMgr,  FS_LPCWSTR csToolTip,  FS_LPCWSTR csText,  FS_LPCSTR csName,  FS_DIBitmap pBitmap,  FS_BOOL bInitialShow,  FS_BOOL bDockBottom))

/**
 * @brief FRPanelMgrShowAllPanel
 * @details Shows all the panels or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  bShow Shows all the panels or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrShowAllPanel, (FR_PanelMgr panelMgr,  FS_BOOL bShow))

/**
 * @brief FRPanelMgrShowPanelByName
 * @details Shows the specified panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @param[in]  bShow Shows the panel or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrShowPanelByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_BOOL bShow))

/**
 * @brief FRPanelMgrResetAllPanels
 * @details Resets all the panels.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrResetAllPanels, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelHwndByName
 * @details Gets the window handle to the panel by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   The window handle to the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRPanelMgrGetPanelHwndByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrIsAllPanelHide
 * @details Checks whether all the panels are hidden or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if all the panels are hidden, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrIsAllPanelHide, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrHasPanelFloating
 * @details Checks whether any panel is floating or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if any panel is floating, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrHasPanelFloating, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrIsPanelHide
 * @details Checks whether the specified panel is hidden or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the specified panel is hidden, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelHide, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrGetParentFrame
 * @details Gets the parent window handle.
 * @param[in]  panelMgr The input panel manager.
 * @return   The parent window handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRPanelMgrGetParentFrame, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetEnabledAlignment
 * @details Gets the enabled alignment. References to MFC ControlBar styles.
 * @param[in]  panelMgr The input panel manager.
 * @return   The enabled alignment. References to MFC ControlBar styles.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_DWORD, FRPanelMgrGetEnabledAlignment, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelViewByName
 * @details Gets the specified panel view handle.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   The specified panel view handle.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(HWND, FRPanelMgrGetPanelViewByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrGetPanelNameByIndex
 * @details Gets the specified panel name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  nIndex Specifies the index of the panel.
 * @return   The specified panel name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_LPCSTR, FRPanelMgrGetPanelNameByIndex, (FR_PanelMgr panelMgr,  FS_INT32 nIndex))

/**
 * @brief FRPanelMgrGetPanelCount
 * @details Gets the panel count.
 * @param[in]  panelMgr The input panel manager.
 * @return   The panel count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_INT32, FRPanelMgrGetPanelCount, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrGetPanelTabRectByPt
 * @details Gets the rectangle of the panel tab by point.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  x The horizon position.
 * @param[in]  y The vertical position.
 * @param[out]  outRtTab It receives the rectangle of the panel tab.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrGetPanelTabRectByPt, (FR_PanelMgr panelMgr,  FS_INT32 x,  FS_INT32 y,  FS_Rect* outRtTab))

/**
 * @brief FRPanelMgrGetPanelTabNameByPt
 * @details Gets the panel name by point.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  x The horizon position.
 * @param[in]  y The vertical position.
 * @return   The panel name.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_LPCSTR, FRPanelMgrGetPanelTabNameByPt, (FR_PanelMgr panelMgr,  FS_INT32 x,  FS_INT32 y))

/**
 * @brief FRPanelMgrGetPanelTabRectByName
 * @details Gets the rectangle of the panel tab by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @param[out]  outRtTab It receives the rectangle of the panel tab.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrGetPanelTabRectByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_Rect* outRtTab))

/**
 * @brief FRPanelMgrHidePanelTabByName
 * @details Hides the specified panel by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrHidePanelTabByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrHasHistory
 * @details Checks whether the customer has configured the panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @return   TRUE if the customer has configured the panel, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrHasHistory, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrLockAllPanel
 * @details Locks all the panels.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 * @see 
 */
INTERFACE(void, FRPanelMgrLockAllPanel, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrShowPanelByName2
 * @details Shows the specified panel or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @param[in]  bShow Shows the panel or not.
 * @param[in]  bActive Activates the panel or not.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 */
INTERFACE(void, FRPanelMgrShowPanelByName2, (FR_PanelMgr panelMgr,  FS_LPCSTR csName,  FS_BOOL bShow,  FS_BOOL bActive))

/**
 * @brief FRPanelMgrIsPanelSpreadOut
 * @details Checks whether the panel is spread out or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the panel is spread out.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelSpreadOut, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrAddPanel2
 * @details Adds a panel.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csToolTip The tool tip of the panel.
 * @param[in]  csText The display text of the panel.
 * @param[in]  csName The name of the panel.
 * @param[in]  pBitmap The icon of the panel.
 * @param[in]  bInitialShow Whether to show the panel at the first time.
 * @param[in]  bDockBottom Whether the panel is docked to the bottom or not.
 * @param[in]  nPos The position where the panel will be added.
 * @return   The handle to the panel.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.0.1
 * @see 
 */
INTERFACE(HWND, FRPanelMgrAddPanel2, (FR_PanelMgr panelMgr,  FS_LPCWSTR csToolTip,  FS_LPCWSTR csText,  FS_LPCSTR csName,  FS_DIBitmap pBitmap,  FS_BOOL bInitialShow,  FS_BOOL bDockBottom,  FS_INT32 nPos))

/**
 * @brief FRPanelMgrRedockAllFloatToInitial
 * @details All floating panel is restored to the left side.
 * @param[in]  panelMgr The input panel manager.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.0
 * @see 
 */
INTERFACE(void, FRPanelMgrRedockAllFloatToInitial, (FR_PanelMgr panelMgr))

/**
 * @brief FRPanelMgrIsPanelFloating
 * @details Checks whether the panel is floating or not.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName Specifies the name of the panel.
 * @return   TRUE if the panel is floating.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.0
 * @see 
 */
INTERFACE(FS_BOOL, FRPanelMgrIsPanelFloating, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

/**
 * @brief FRPanelMgrShrinkPanelByName
 * @details Shrink the specified panel by name.
 * @param[in]  panelMgr The input panel manager.
 * @param[in]  csName The input panel name.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 10.0
 * @see 
 */
INTERFACE(void, FRPanelMgrShrinkPanelByName, (FR_PanelMgr panelMgr,  FS_LPCSTR csName))

NumOfSelector(FRPanelMgr)
ENDENUM

//----------_V8----------
//----------_V9----------
//*****************************
/* CloudLoginProvider HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FRCloudLoginProviderSet
 * @details Sets the service provider of cloud login.
 * @param[in]  callbacks The callback set for the service provider of cloud login.
 * @return   The <a>* FR_CloudLoginProvider</a> object represents the service provider of cloud login. Destroys it by invoking <a>FRCloudLoginProviderDestroy</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderDestroy
 */
INTERFACE(FR_CloudLoginProvider, FRCloudLoginProviderSet, (FR_CloudLoginProviderCallbacks callbacks))

/**
 * @brief FRCloudLoginProviderDestroy
 * @details Destroys the service provider of cloud login.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(void, FRCloudLoginProviderDestroy, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderGet
 * @details Gets the service provider of cloud login.
 * @return   The service provider of cloud login.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(FR_CloudLoginProvider, FRCloudLoginProviderGet, ())

/**
 * @brief FRCloudLoginProviderIsLogIn
 * @details Checks whether the user has logged in or not.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE indicates that the user has logged in, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderIsLogIn, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderSignIn
 * @details Signs into the cloud.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderSignIn, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderSignOut
 * @details Signs out the cloud.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderSignOut, (FR_CloudLoginProvider loginProvider))

/**
 * @brief FRCloudLoginProviderGetUserInfo
 * @details Gets the user information.
 * @param[in]  loginProvider The input service provider of cloud login.
 * @param[out]  pUserInfo It receives the user information.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 * @see FRCloudLoginProviderSet
 */
INTERFACE(FS_BOOL, FRCloudLoginProviderGetUserInfo, (FR_CloudLoginProvider loginProvider,  FR_Login_UserInfo* pUserInfo))

NumOfSelector(FRCloudLoginProvider)
ENDENUM

//----------_V10----------
