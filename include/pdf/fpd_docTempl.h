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
 * @brief FPDDocNew
 * @details Creates a new empty document. </Brief> The only <a>FPD_Object</a> in the document will be a
	* Catalog dictionary. See <Italic>Section 3.6 in the PDF Reference</Italic>.
 * @param[in]  void 
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FPD_Document, FPDDocNew, (void))

/**
 * @brief FPDDocDestroy
 * @details Destroys the document created by <a>FPDDocNew</a>. When Foxit Reader opens the doc, it is taken over and 
	* don't destroy it.
 * @param[in]  doc The document to destroy.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocDestroy, (FPD_Document doc))

/**
 * @brief FPDDocOpen
 * @details Creates a new document from an existing PDF file. You must call <a>FPDDocClose</a>() once for every
	* successful open.
 * @param[in]  wszFilePath The input file full path name.
 * @param[in]  szPassword The input password string.
 * @return   The newly createddocument from an existing PDF file.
 * @note 
 */
INTERFACE(FPD_Document, FPDDocOpen, (FS_LPCWSTR wszFilePath,  FS_LPCSTR szPassword))

/**
 * @brief FPDDocOpenMemDocument
 * @details Creates a  document from memory block. You must call <a>FPDDocClose</a>() once for every
	* successful open.
 * @param[in]  dataBuf The input memory block.
 * @param[in]  size The size in bytes of the memory block.
 * @param[in]  szPassword The input password string.
 * @return   The newly created document from memory block.
 * @note 
 */
INTERFACE(FPD_Document, FPDDocOpenMemDocument, (void* dataBuf,  FS_INT32 size,  FS_LPCSTR szPassword))

/**
 * @brief FPDDocStartProgressiveLoad
 * @details Document loading is a progressive process. It might take a long time to
	* load a document, especially when a file is corrupted, FPDFEMB will try to recover the document contents by scanning the whole 
	* file. If "pause" parameter is provided, this function may return FPDFERR_TOBECONTINUED any time during the document loading.<br>
	* When <a>FPD_LOADERR_TOBECONTINUED</a> is returned, the "outPDDoc" parameter will still receive a valid document handle, however, 
	* no further operations can be performed on the document, except the <a>FPDDocContinueLoad</a>() function call, which resume the 
	* document loading.
 * @param[in]  fileRead The file access handler. Plug-ins should free the object after the document is parsed completely.
 * @param[in]  szPassword The input password string.
 * @param[in]  pause The pause handler. This can be <a>NULL</a> if you don't want to pause.
 * @param[out]  outPDDoc Receiving the document.
 * @return   The result code. See <a>FPDLoadErrCodes</a>.
 * @note 
 */
INTERFACE(FS_RESULT, FPDDocStartProgressiveLoad, (FS_FileReadHandler fileRead,  FS_LPCSTR szPassword,  FS_PauseHandler pause,  FPD_Document* outPDDoc))

/**
 * @brief FPDDocContinueLoad
 * @details Continue loading a PDF document. You must call <a>FPDDocClose</a>() once for every
	* successful open.
 * @param[in]  doc The PDF document.
 * @param[in]  pause The pause handler. This can be <a>NULL</a> if you don't want to pause.
 * @return   The result code. See <a>FPDLoadErrCodes</a>.
 * @note 
 */
INTERFACE(FS_RESULT, FPDDocContinueLoad, (FPD_Document doc,  FS_PauseHandler pause))

/**
 * @brief FPDDocClose
 * @details Closes the document returned by <a>FPDDocOpen</a>(), <a>FPDDocStartProgressiveLoad</a>() or <a>FPDDocOpenMemDocument</a>().
 * @param[in]  doc The document returned by <a>FPDDocOpen</a>(), <a>FPDDocStartProgressiveLoad</a>() or <a>FPDDocOpenMemDocument</a>().
 * @return   Error code. FPD_LOADERR_SUCCESS for success.
 * @note Call <a>FPDDocDestroy</a>() to release a document which created by <a>FPDDocNew</a>().
 */
INTERFACE(FS_RESULT, FPDDocClose, (FPD_Document doc))

/**
 * @brief FPDDocGetRoot
 * @details Gets root dictionary (document catalog dictionary) from a PDF document.
 * @param[in]  doc A PDF document.
 * @return   The root dictionary (document catalog dictionary).
 * @note 
 */
INTERFACE(FPD_Object, FPDDocGetRoot, (FPD_Document doc))

/**
 * @brief FPDDocGetInfo
 * @details Gets document info dictionary from a PDF document. Could be NULL.
 * @param[in]  doc A PDF document.
 * @return   The document info dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocGetInfo, (FPD_Document doc))

/**
 * @brief FPDDocGetID
 * @details Gets ID strings of the document. Could be empty.
 * @param[in]  doc A PDF document.
 * @param[out]  outID1 It receives the first ID string of the document.
 * @param[out]  outID2 It receives the second ID string of the document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocGetID, (FPD_Document doc,  FS_ByteString* outID1,  FS_ByteString* outID2))

/**
 * @brief FPDDocGetPageCount
 * @details Gets number of pages in this document.
 * @param[in]  doc 
 * @return   The page count.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocGetPageCount, (FPD_Document doc))

/**
 * @brief FPDDocGetPage
 * @details Gets page dictionary of a specified page of the document. Page index starts from zero for the first page.
 * @param[in]  doc A PDF document.
 * @param[in]  page_index Specifies the zero-based index of the page in the document.
 * @return   The specified page dictionary of the document.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocGetPage, (FPD_Document doc,  FS_INT32 page_index))

/**
 * @brief FPDDocGetPageIndex
 * @details Gets the page index from a indirect object number in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  objNum The input indirect object number int the document.
 * @return   The zero-based index of page in the document.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocGetPageIndex, (FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDocGetUserPermissions
 * @details Gets the user permission of the document.
 * @param[in]  doc The input PDF document.
 * @return   The user permission of the document.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDocGetUserPermissions, (FPD_Document doc))

/**
 * @brief FPDDocIsOwner
 * @details Whether the user has the owner permission of the document.
 * @param[in]  doc The input PDF document.
 * @return   <a>TRUE</a> for being owner.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocIsOwner, (FPD_Document doc))

/**
 * @brief FPDDocIsFormStream
 * @details Checks if an indirect object is a form stream or not, without actually loading the object.
 * @param[in]  doc A PDF document.
 * @param[in]  objnum The input indirect object number.
 * @param[out]  outIsFormStream It receive whether it's a form stream or not.
 * @return   Non-zero means determined, otherwise unknown.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocIsFormStream, (FPD_Document doc,  FS_DWORD objnum,  FS_BOOL* outIsFormStream))

/**
 * @brief FPDDocLoadFont
 * @details Loads a font from font dictionary in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  fontDict The input font dictionary.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDDocLoadFont, (FPD_Document doc,  FPD_Object fontDict))

/**
 * @brief FPDDocLoadColorSpace
 * @details Loads a color space from a PDF object in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  csObj The input PDF object.
 * @return   A PDF color space.
 * @note 
 */
INTERFACE(FPD_ColorSpace, FPDDocLoadColorSpace, (FPD_Document doc,  FPD_Object csObj))

/**
 * @brief FPDDocLoadPattern
 * @details Loads a pattern from a PDF object in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  csObj The input PDF object.
 * @param[in]  bShading Whether the pattern is a shading pattern or not.
 * @return   A PDF pattern.
 * @note 
 */
INTERFACE(FPD_Pattern, FPDDocLoadPattern, (FPD_Document doc,  FPD_Object csObj,  FS_BOOL bShading))

/**
 * @brief FPDDocLoadImageF
 * @details Loads an image from a PDF object in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  obj The input PDF object.
 * @param[in]  bCache Whether we will cache the image or not.
 * @return   A PDF image.
 * @note 
 */
INTERFACE(FPD_Image, FPDDocLoadImageF, (FPD_Document doc,  FPD_Object obj,  FS_BOOL bCache))

/**
 * @brief FPDDocLoadFontFile
 * @details Loads a PDF stream accessor from a PDF stream in the document.
 * @param[in]  doc A PDF document.
 * @param[in]  stm The input PDF stream.
 * @return   A PDF stream accessor.
 * @note 
 */
INTERFACE(FPD_StreamAcc, FPDDocLoadFontFile, (FPD_Document doc,  FPD_Object stm))

/**
 * @brief FPDDocGetInfoObjNum
 * @details Gets the number of info object.
 * @param[in]  doc The input PDF document.
 * @return   The number of info object.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDocGetInfoObjNum, (FPD_Document doc))

/**
 * @brief FPDDocGetRootObjNum
 * @details Gets the number of root object.
 * @param[in]  doc The input PDF document.
 * @return   The number of root object.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDocGetRootObjNum, (FPD_Document doc))

/**
 * @brief FPDDocEnumPages
 * @details Enumerates pages with user-supplied page enumeration handler.
 * @param[in]  doc A PDF document.
 * @param[in]  pEnumPageHandler The user-supplied page enumeration handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocEnumPages, (FPD_Document doc,  FPD_EnumPageHandler pEnumPageHandler))

/**
 * @brief FPDDocNewEnumPageHandler
 * @details Creates user-supplied page enumeration handler.
 * @param[in]  enumPage The user-supplied page enumeration struct.
 * @return   The user-supplied page enumeration handler.
 * @note 
 */
INTERFACE(FPD_EnumPageHandler, FPDDocNewEnumPageHandler, (FPD_EnumPage enumPage))

/**
 * @brief FPDDocDeleteEnumPageHandler
 * @details Deletes the user-supplied page enumeration handler.
 * @param[in]  pEnumPageHandler The user-supplied page enumeration handler.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocDeleteEnumPageHandler, (FPD_EnumPageHandler pEnumPageHandler))

/**
 * @brief FPDDocSetRootObjNum
 * @details Sets the root object number in the PDF document. Must be called for an empty document.
 * @param[in]  doc A empty PDF document.
 * @param[in]  RootObjNum The input root object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocSetRootObjNum, (FPD_Document doc,  FS_INT32 RootObjNum))

/**
 * @brief FPDDocSetInfoObjNum
 * @details Sets the info object number in the PDF document. Must be called for an empty document.
 * @param[in]  doc A empty PDF document.
 * @param[in]  InfoObjNum The input info object number.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocSetInfoObjNum, (FPD_Document doc,  FS_INT32 InfoObjNum))

/**
 * @brief FPDDocSetID
 * @details Sets the PDF file ID.
 * @param[in]  doc A PDF document.
 * @param[in]  szID1 The first file ID.
 * @param[in]  nLen1 The length of the first ID byte string.
 * @param[in]  szID2 The second file ID.
 * @param[in]  nLen2 The length of the second ID byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocSetID, (FPD_Document doc,  FS_LPCBYTE szID1,  FS_INT32 nLen1,  FS_LPCBYTE szID2,  FS_INT32 nLen2))

/**
 * @brief FPDDocAddWindowsFont
 * @details Imports a Windows font into the PDF document.
 * @param[in]  doc A PDF document.
 * @param[in]  pLogFont Points to a LOGFONT(WIN32) structure that defines the characteristics of the logical font.
 * @param[in]  bVert Whether the font is a vertical font or not.
 * @param[in]  bTranslateName Whether we will do font name translating or not.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDDocAddWindowsFont, (FPD_Document doc,  void* pLogFont,  FS_BOOL bVert,  FS_BOOL bTranslateName))

/**
 * @brief FPDDocAddWindowsFontW
 * @details Imports a Windows font into the PDF document.
 * @param[in]  doc A PDF document.
 * @param[in]  pLogFont Points to a LOGFONTW(WIN32) structure that defines the characteristics of the logical font.
 * @param[in]  bVert Whether the font is a vertical font or not.
 * @param[in]  bTranslateName Whether we will do font name translating or not.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDDocAddWindowsFontW, (FPD_Document doc,  void* pLogFont,  FS_BOOL bVert,  FS_BOOL bTranslateName))

/**
 * @brief FPDDocAddStandardFont
 * @details Adds a Type1 base-14 font to the PDF document.
 * @param[in]  doc A PDF document.
 * @param[in]  font The font name.
 * @param[in]  encoding The font encoding.
 * @return   
 * @note 
 */
INTERFACE(FPD_Font, FPDDocAddStandardFont, (FPD_Document doc,  const FS_CHAR* font,  FPD_FontEncoding encoding))

/**
 * @brief FPDDocBuildResourceList
 * @details Build a list of all resources of specified type in this document. On return,
	*            the array contains pointers to FPD_Object objects.
 * @param[in]  doc A PDF document.
 * @param[in]  type The name of specified type.
 * @param[out]  arr It will receive all resource objects of specified type in the document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocBuildResourceList, (FPD_Document doc,  const FS_CHAR* type,  FS_PtrArray arr))

/**
 * @brief FPDDocCreateNewPage
 * @details Creates a new page in the PDF document. Return the created page.
 * @param[in]  doc A PDF document.
 * @param[in]  iPage Specifies the zero-based index of page to be created.
 * @return   The created page dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocCreateNewPage, (FPD_Document doc,  FS_INT32 iPage))

/**
 * @brief FPDDocDeletePage
 * @details Deletes specified page in the PDF document.
 * @param[in]  doc A PDF document.
 * @param[in]  iPage Specifies the zero-based index of page to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocDeletePage, (FPD_Document doc,  FS_INT32 iPage))

/**
 * @brief FPDDocConvertIndirectObjects
 * @details Converts stream of dictionary members of an object to be indirect objects.
 * @param[in]  doc A PDF document.
 * @param[in]  obj The input PDF object.
 * @param[in]  bConvertStream Whether we will convert stream to indirect object or not.
 * @param[in]  bConvertDictionary Whether we will convert dictionary to indirect object or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocConvertIndirectObjects, (FPD_Document doc,  FPD_Object obj,  FS_BOOL bConvertStream,  FS_BOOL bConvertDictionary))

/**
 * @brief FPDDocGetPageContentModify
 * @details Gets a modifiable content stream for a page in the PDF document.
 * @param[in]  doc A PDF document.
 * @param[in]  page_dict The input page dictionary.
 * @return   An modifiable content stream for the page.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocGetPageContentModify, (FPD_Document doc,  FPD_Object page_dict))

/**
 * @brief FPDDocQuickSearch
 * @details Quick search an pattern for specified page in the PDF document.
 * @param[in]  doc The input PDF document.
 * @param[in]  page_index The zero-based page index to be searched.
 * @param[in]  pattern The pattern to search.
 * @param[in]  bCaseSensitive Whether the pattern matching is case sensitive.
 * @return   Non-zero means searched one successfully.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocQuickSearch, (FPD_Document doc,  FS_INT32 page_index,  FS_LPCWSTR pattern,  FS_BOOL bCaseSensitive))

/**
 * @brief FPDDocReloadPages
 * @details Reload page list. This can be used when document is progressively downloaded.
 * @param[in]  doc A PDF document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocReloadPages, (FPD_Document doc))

/**
 * @brief FPDDocLoadDoc
 * @details Internally used
 * @param[in]  doc The input PDF document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocLoadDoc, (FPD_Document doc))

/**
 * @brief FPDDocGetIndirectObject
 * @details Loads an indirect object by an object number.
 * @param[in]  doc The input document.
 * @param[in]  objNum The input object number.
 * @return   An indirect object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocGetIndirectObject, (FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDocGetIndirectType
 * @details Gets type of an document, without loading the object content.
 * @param[in]  doc The input document.
 * @param[in]  objNum The input object number.
 * @return   The type of the document.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocGetIndirectType, (FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDocAddIndirectObject
 * @details Adds an object to indirect object list. The new object number is returned.
 * @param[in]  doc The input document.
 * @param[in]  obj The input object.
 * @return   The new object number.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDocAddIndirectObject, (FPD_Document doc,  FPD_Object obj))

/**
 * @brief FPDDocReleaseIndirectObject
 * @details Sometimes, for saving memory space, we can release a loaded indirect object.
	*            However, use this with caution because the object pointer will become invalid.
 * @param[in]  doc The input document.
 * @param[in]  objNum The object number to release.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocReleaseIndirectObject, (FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDocDeleteIndirectObject
 * @details Deletes an indirect object. Use this function with caution!
 * @param[in]  doc The input document.
 * @param[in]  objNum The object number to delete.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocDeleteIndirectObject, (FPD_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDDocImportIndirectObject
 * @details Imports an object from its binary format.
	*            This is used when the PDF is fetched in "Progressive Downloading" fashion.
	*            After this function call, the data buffer can be destroyed.
	*            This object must not be encrypted.
 * @param[in]  doc The input document.
 * @param[in]  pBuffer The binary data for the document. It must be not encrypted.
 * @param[in]  size The size in bytes of the binary data.
 * @return   An object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocImportIndirectObject, (FPD_Document doc,  FS_LPBYTE pBuffer,  FS_DWORD size))

/**
 * @brief FPDDocImportExternalObject
 * @details Imports an object from external object collection as a new document.
	*            If the external object refers to other external indirect objects, those indirect objects
	*            are also imported.
	*            The mapping from old object number to new object number is updated during the import process.
 * @param[in]  doc The input document.
 * @param[in]  obj The object in external object collection.
 * @param[out]  mapping It updates the mapping from old object number to new object number.
 * @return   A new indirect object.
 * @note 
 */
INTERFACE(FPD_Object, FPDDocImportExternalObject, (FPD_Document doc,  FPD_Object obj,  FS_MapPtrToPtr mapping))

/**
 * @brief FPDDocInsertIndirectObject
 * @details Inserts an indirect object with specified object number.
	*			  This is used when the PDF is fetched in "Progressive Downloading" fashion, or parsing FDF.
	*            If an indirect object with the same object number exists, the previous one will be destroyed.
 * @param[in]  doc The input document.
 * @param[in]  objNum The new object number of the indirect object to insert.
 * @param[in]  obj The indirect object to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocInsertIndirectObject, (FPD_Document doc,  FS_DWORD objNum,  FPD_Object obj))

/**
 * @brief FPDDocGetLastobjNum
 * @details Gets last assigned indirect object number.
 * @param[in]  doc The input document.
 * @return   The number of the last object.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDocGetLastobjNum, (FPD_Document doc))

/**
 * @brief FPDDocReloadFileStreams
 * @details Reload all file based stream when we do reparsing.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocReloadFileStreams, (FPD_Document doc))

/**
 * @brief FPDDocGetStartPosition
 * @details Gets the start position of the indirect objects.
 * @param[in]  doc The input document.
 * @return   The start position of the indirect objects.
 * @note 
 */
INTERFACE(FS_POSITION, FPDDocGetStartPosition, (FPD_Document doc))

/**
 * @brief FPDDocGetNextAssoc
 * @details Accesses the indirect object of current position, and move the position to next.
 * @param[in]  doc The input document.
 * @param[in,out]  outPos Input current position and receive the next position.
 * @param[out]  outObjNum It receives the current object number.
 * @param[out]  outObject It receives the current indirect object pointer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocGetNextAssoc, (FPD_Document doc,  FS_POSITION* outPos,  FS_DWORD* outObjNum,  FPD_Object* outObject))

/**
 * @brief FPDDocIsModified
 * @details Checks if any of the indirect objects are modified, since loading from parser, or last ClearModified.
 * @param[in]  doc The input document.
 * @return   <a>TRUE</a> if the document is modified, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocIsModified, (FPD_Document doc))

/**
 * @brief FPDDocClearModified
 * @details Clears the modified flag.
 * @param[in]  doc The input document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocClearModified, (FPD_Document doc))

/**
 * @brief FPDDocSave
 * @details Writes the whole document into a new file.
 * @param[in]  doc The input document.
 * @param[in]  filename The output file name.
 * @param[in]  flags The saving flags. You can set FPD_SAVE_DEFAULT by default.
 * @param[in]  bEnable Whether to do data compressing.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocSave, (FPD_Document doc,  FS_LPCSTR filename,  FS_DWORD flags,  FS_BOOL bEnable))

/**
 * @brief FPDDocGetParser
 * @details Gets the PDF file parser associated with a <a>FPD_Document</a> object.
 * @param[in]  doc The input document.
 * @return   The PDF parser.
 * @note 
 */
INTERFACE(FPD_Parser, FPDDocGetParser, (FPD_Document doc))

/**
 * @brief FPDDocCheckSignature
 * @details Checks whether the document is signed or not.
 * @param[in]  doc The input document.
 * @return   <a>TRUE</a> if the document is signed, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_BOOL, FPDDocCheckSignature, (FPD_Document doc))

/**
 * @brief FPDDocGenerateFileID
 * @details Generates the ID of the PDF document.
 * @param[in]  dwSeed1 A seed value to initialize MT generator.
 * @param[in]  dwSeed2 A seed value to initialize MT generator.
 * @param[out]  pBuffer It receives the file ID.
 * @return   <a>TRUE</a> for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDDocGenerateFileID, (FS_DWORD dwSeed1,  FS_DWORD dwSeed2,  FS_LPDWORD pBuffer))

/**
 * @brief FPDDocGetReviewType
 * @details Gets the review type. 0:normal, 1:share, 2:email.
 * @param[in]  doc The document.
 * @return   The review type. 0:normal, 1:share, 2:email.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_INT32, FPDDocGetReviewType, (FPD_Document doc))

/**
 * @brief FPDDocIsPortfolio
 * @details Checks whether the document is a portfolio document or not.
 * @param[in]  doc The input PDF document.
 * @return   TRUE if the document is a portfolio document, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDDocIsPortfolio, (FPD_Document doc))

/**
 * @brief FPDDocRemoveUR3
 * @details Removes the UR3 signature.
 * @param[in]  doc The input PDF document.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(FS_BOOL, FPDDocRemoveUR3, (FPD_Document doc))

/**
 * @brief FPDDocAddFXFont
 * @details Adds the Foxit GE font to the PDF document. It will return a PDF font object.
 * @param[in]  doc The input PDF document.
 * @param[in]  pFXFont The input Foxit GE font object.
 * @param[in]  charset The input Charset ID.
 * @param[in]  bVert Whether it's a vertical writing font. For CJK charsets only.
 * @return   The PDF font object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.0.0
 */
INTERFACE(FPD_Font, FPDDocAddFXFont, (FPD_Document doc,  FPD_FXFont pFXFont,  FS_INT32 charset,  FS_BOOL bVert))

/**
 * @brief FPDDocGetIndirectObjsCount
 * @details Gets the indirect object count.
 * @param[in]  doc The input PDF document.
 * @return   The indirect object count.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1.0
 */
INTERFACE(FS_INT32, FPDDocGetIndirectObjsCount, (FPD_Document doc))

/**
 * @brief FPDDocSave2
 * @details Writes the whole document into a new file.
 * @param[in]  doc The input document.
 * @param[in]  wStrfilename The output file name,wide string type.
 * @param[in]  flags The saving flags. You can set FPD_SAVE_DEFAULT by default.
 * @param[in]  bEnable Whether to do data compressing.
 * @return   Non-zero means success, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FPDDocSave2, (FPD_Document doc,  FS_LPCWSTR wStrfilename,  FS_DWORD flags,  FS_BOOL bEnable))

/**
 * @brief FPDDocInsertDocumentAtPos
 * @details Inserts the document into the original document at the specified position.
 * @param[in]  doc The input document.
 * @param[in]  index The page index where the document will be inserted.
 * @param[in]  insertedDoc The inserted document.
 * @param[in]  pBookmarkTitle The input bookmark title. Set NULL as default.
 * @return   TRUE means success, otherwise failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 9.4.0
 */
INTERFACE(FS_BOOL, FPDDocInsertDocumentAtPos, (FPD_Document doc,  FS_INT32 index,  FPD_Document insertedDoc,  const FS_WCHAR* pBookmarkTitle))

NumOfSelector(FPDDoc)
ENDENUM

//*****************************
/* NameTree HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDNameTreeNew
 * @details Creates a name tree object from a root dictionary.
 * @param[in]  rootDict The root dictionary for the name tree (See Ref Table 3.28).
 * @return   A name tree object from a root dictionary.
 * @note 
 */
INTERFACE(FPD_NameTree, FPDNameTreeNew, (FPD_Object rootDict))

/**
 * @brief FPDNameTreeNew2
 * @details Creates a name tree object from a root dictionary.
 * @param[in]  doc The PDF document.
 * @param[in]  szCategory The category key name for name tree, like "Dests", "AP", etc. (See Ref Table 3.28).
 * @return   A name tree object from a root dictionary.
 * @note 
 */
INTERFACE(FPD_NameTree, FPDNameTreeNew2, (FPD_Document doc,  FS_LPCSTR szCategory))

/**
 * @brief FPDNameTreeDestroy
 * @details Destroys a name tree object created by FPDNameTreeNew or FPDNameTreeNew2.
 * @param[in]  nameTree A name tree object created by FPDNameTreeNew or FPDNameTreeNew2.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDNameTreeDestroy, (FPD_NameTree nameTree))

/**
 * @brief FPDNameTreeLookupValue
 * @details Lookup a PDF name tree node by index that contains the name, and return specified entry value.
 * @param[in]  nameTree A name tree object.
 * @param[in]  index The zero-based index of entry value.
 * @param[out]  outName The name to be searched.
 * @return   The value of specified entry of the found PDF name tree node.
 * @note 
 */
INTERFACE(FPD_Object, FPDNameTreeLookupValue, (FPD_NameTree nameTree,  FS_INT32 index,  FS_WideString* outName))

/**
 * @brief FPDNameTreeLookupValueByName
 * @details Lookup a PDF name tree node that contains the name, and return specified entry value.
 * @param[in]  nameTree A name tree object.
 * @param[in]  wszName The name to be searched.
 * @return   The value of specified entry of the found PDF name tree node.
 * @note 
 */
INTERFACE(FPD_Object, FPDNameTreeLookupValueByName, (FPD_NameTree nameTree,  FS_LPCWSTR wszName))

/**
 * @brief FPDNameTreeLookupNamedDest
 * @details Lookup PDF name destination.
 * @param[in]  nameTree A name tree object.
 * @param[in]  doc The document.
 * @param[in]  szName The input name.
 * @return   The corresponding destination.
 * @note 
 */
INTERFACE(FPD_Object, FPDNameTreeLookupNamedDest, (FPD_NameTree nameTree,  FPD_Document doc,  FS_LPSTR szName))

/**
 * @brief FPDNameTreeSetValue
 * @details Sets the entry value of specified PDF name tree node that contains specified name.
 * @param[in]  nameTree A name tree object.
 * @param[in]  doc The document.
 * @param[in]  szKey The key is entry in the names dictionary.
 * @param[in]  wszName The name to be searched.
 * @param[in]  value The input entry value.
 * @return   The index of the set value
 * @note 
 */
INTERFACE(FS_INT32, FPDNameTreeSetValue, (FPD_NameTree nameTree,  FPD_Document doc,  FS_LPCSTR szKey,  FS_LPCWSTR wszName,  FPD_Object value))

/**
 * @brief FPDNameTreeGetIndex
 * @details Gets index of the name in name tree.
 * @param[in]  nameTree A name tree object.
 * @param[in]  wszName The name to be searched.
 * @return   The index of the name If found csName. otherwise return -1.
 * @note 
 */
INTERFACE(FS_INT32, FPDNameTreeGetIndex, (FPD_NameTree nameTree,  FS_LPCWSTR wszName))

/**
 * @brief FPDNameTreeRemove
 * @details Removes the name and entry value by nIndex in name tree, if csName is empty. otherwise ignore nIndex.
 * @param[in]  nameTree A name tree object.
 * @param[in]  index The zero-based index of entry value.
 * @param[in]  wszName The name to be searched.
 * @return   The value nonzero if successful, otherwise 0.
 * @note 
 */
INTERFACE(FS_BOOL, FPDNameTreeRemove, (FPD_NameTree nameTree,  FS_INT32 index,  FS_LPCWSTR wszName))

/**
 * @brief FPDNameTreeGetCount
 * @details Gets the number of key-value pairs in name tree.
 * @param[in]  nameTree A name tree object.
 * @return   The number of key-value pairs.
 * @note 
 */
INTERFACE(FS_INT32, FPDNameTreeGetCount, (FPD_NameTree nameTree))

/**
 * @brief FPDNameTreeGetRoot
 * @details Gets the root dictionary of the tree.
 * @param[in]  nameTree A name tree object.
 * @return   The root dictionary of the tree.
 * @note 
 */
INTERFACE(FPD_Object, FPDNameTreeGetRoot, (FPD_NameTree nameTree))

NumOfSelector(FPDNameTree)
ENDENUM

//*****************************
/* Bookmark HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDBookmarkNew
 * @details Creates a PDF Bookmark object from a outline item dictionary.
 * @param[in]  outlineDict The input outline item dictionary.
 * @return   A PDF Bookmark object
 * @note 
 */
INTERFACE(FPD_Bookmark, FPDBookmarkNew, (FPD_Object outlineDict))

/**
 * @brief FPDBookmarkDestroy
 * @details Destroys a PDF Bookmark object created by FPDBookmarkNew.
 * @param[in]  bookmark A PDF Bookmark object created by FPDBookmarkNew.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDBookmarkDestroy, (FPD_Bookmark bookmark))

/**
 * @brief FPDBookmarkIsVaild
 * @details Tests wWhether the bookmark is valid.
 * @param[in]  bookmark The input bookmark.
 * @return   <a>TRUE</a> for being valid.
 * @note 
 */
INTERFACE(FS_BOOL, FPDBookmarkIsVaild, (FPD_Bookmark bookmark))

/**
 * @brief FPDBookmarkGetColorRef
 * @details Gets the color of a bookmark. In Windows COLORREF format: 0x00ggbbrr.
 * @param[in]  bookmark The input bookmark.
 * @return   The color of a bookmark.
 * @note 
 */
INTERFACE(FS_DWORD, FPDBookmarkGetColorRef, (FPD_Bookmark bookmark))

/**
 * @brief FPDBookmarkGetFontStyle
 * @details Gets the font style of a bookmark. Italic and/or bold.
 * @param[in]  bookmark The input bookmark.
 * @return   The font style of a bookmark.
 * @note 
 */
INTERFACE(FS_DWORD, FPDBookmarkGetFontStyle, (FPD_Bookmark bookmark))

/**
 * @brief FPDBookmarkGetTitle
 * @details Gets the title of a bookmark. A unicode encoded string is returned.
 * @param[in]  bookmark The input bookmark.
 * @param[out]  outTitle It receives the title of a bookmark.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDBookmarkGetTitle, (FPD_Bookmark bookmark,  FS_WideString* outTitle))

/**
 * @brief FPDBookmarkGetDest
 * @details Gets the destination of a bookmark.
 * @param[in]  bookmark The input bookmark.
 * @param[in]  doc The input PDF document.
 * @param[out]  outDest A PDF destination object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDBookmarkGetDest, (FPD_Bookmark bookmark,  FPD_Document doc,  FPD_Dest* outDest))

/**
 * @brief FPDBookmarkGetAction
 * @details Gets the PDF action of a bookmark.
 * @param[in]  bookmark The input bookmark.
 * @param[out]  outAction It receives the PDF action of a bookmark.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDBookmarkGetAction, (FPD_Bookmark bookmark,  FPD_Action* outAction))

/**
 * @brief FPDBookmarkGetDictionary
 * @details Gets the outline item dictionary.
 * @param[in]  bookmark The input bookmark.
 * @return   The outline item dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDBookmarkGetDictionary, (FPD_Bookmark bookmark))

/**
 * @brief FPDBookmarkGetFirstChild
 * @details Gets the first child bookmark of specified parent bookmark.
	*            If <param>pParent</param> is <a>NULL</a>, gets top level items.
 * @param[in]  doc The input PDF document.
 * @param[in]  parent The input parent bookmark.
 * @param[out]  outFirstChild The first child bookmark.
 * @return   <a>TRUE</a> if the child bookmark exist,otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDBookmarkGetFirstChild, (FPD_Document doc,  FPD_Bookmark parent,  FPD_Bookmark* outFirstChild))

/**
 * @brief FPDBookmarkGetNextSibling
 * @details Gets the next sibling bookmark of specified bookmark in the same level.
 * @param[in]  doc The input PDF document.
 * @param[in]  bookmark The input bookmark.
 * @param[out]  outNextSibling The next sibling bookmark.
 * @return   <a>TRUE</a> if the next sibling bookmark exist, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDBookmarkGetNextSibling, (FPD_Document doc,  FPD_Bookmark bookmark,  FPD_Bookmark* outNextSibling))

NumOfSelector(FPDBookmark)
ENDENUM

//*****************************
/* Dest HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDDestNew
 * @details Creates a PDF destination object from a PDF object.
 * @param[in]  obj The input PDF object.
 * @return   A PDF destination object
 * @note 
 */
INTERFACE(FPD_Dest, FPDDestNew, (FPD_Object obj))

/**
 * @brief FPDDestDestroy
 * @details Destroys a PDF destination object.
 * @param[in]  dest The input PDF destination object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDestDestroy, (FPD_Dest dest))

/**
 * @brief FPDDestGetRemoteName
 * @details Gets the remote name of named destination.
 * @param[in]  dest A PDF destination object.
 * @param[out]  pStrResult It receives the remote name of named destination.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDestGetRemoteName, (FPD_Dest dest,  FS_ByteString* pStrResult))

/**
 * @brief FPDDestGetPageIndex
 * @details Gets zero-based index of the page in the document.
 * @param[in]  doc The PDF document.
 * @param[in]  dest A PDF destination object.
 * @return   The zero-based index of the page referred to.
 * @note 
 */
INTERFACE(FS_INT32, FPDDestGetPageIndex, (FPD_Document doc,  FPD_Dest dest))

/**
 * @brief FPDDestGetPageObjNum
 * @details Gets the object number of the page.
 * @param[in]  dest A PDF destination object.
 * @return   The object number of the page.
 * @note 
 */
INTERFACE(FS_DWORD, FPDDestGetPageObjNum, (FPD_Dest dest))

/**
 * @brief FPDDestGetZoomMode
 * @details Gets the zoom mode of the destination.
 * @param[in]  dest A PDF destination object.
 * @return   The zoom mode of the destination.
 * @note 
 */
INTERFACE(FS_INT32, FPDDestGetZoomMode, (FPD_Dest dest))

/**
 * @brief FPDDestGetParam
 * @details Gets a param.
 * @param[in]  dest A PDF destination object.
 * @param[in]  index The zero-based index of the param.
 * @return   The param by index.
 * @note 
 */
INTERFACE(double, FPDDestGetParam, (FPD_Dest dest,  FS_INT32 index))

/**
 * @brief FPDDestGetPDFObject
 * @details Gets the PDF object of the destination.
 * @param[in]  dest A PDF destination object.
 * @param[out]  pObject It receives the PDF object of the destination.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDestGetPDFObject, (FPD_Dest dest,  FPD_Object* pObject))

NumOfSelector(FPDDest)
ENDENUM

//*****************************
/* OCContext HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDOCContextNew
 * @details Creates optional content context from a PDF document.
 * @param[in]  doc The input PDF document.
 * @param[in]  UsageType The intended usage type of optional content.
 * @return   An optional content context.
 * @note 
 */
INTERFACE(FPD_OCContext, FPDOCContextNew, (FPD_Document doc,  FPD_OCC_UsageType UsageType))

/**
 * @brief FPDOCContextDestroy
 * @details Destroys optional content context.
 * @param[in]  occ Optional content context.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCContextDestroy, (FPD_OCContext occ))

/**
 * @brief FPDOCContextGetDocument
 * @details Gets the PDF document in the optional content context.
 * @param[in]  occ The input optional content context.
 * @return   The PDF document in the optional content context.
 * @note 
 */
INTERFACE(FPD_Document, FPDOCContextGetDocument, (FPD_OCContext occ))

/**
 * @brief FPDOCContextGetUsageType
 * @details Gets the usage type of optional content.
 * @param[in]  occ The input optional content context.
 * @return   The usage type of optional content.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCContextGetUsageType, (FPD_OCContext occ))

/**
 * @brief FPDOCContextCheckOCGVisible
 * @details Checks whether the optional content group is visible or not.
 * @param[in]  occ The input optional content context.
 * @param[in]  OCGDict The optional content group dictionary.
 * @return   <a>TRUE</a> for being visible.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCContextCheckOCGVisible, (FPD_OCContext occ,  const FPD_Object OCGDict))

/**
 * @brief FPDOCContextResetOCContext
 * @details Resets the optional content context.
 * @param[in]  occ The input optional content context.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCContextResetOCContext, (FPD_OCContext occ))

/**
 * @brief FPDOCContextSetOCGState
 * @details Resets the optional content context.
 * @param[in]  occ The input optional content context.
 * @param[in]  ocgDict The input OCG dictionary.
 * @param[in]  bState The new state of the OCG.
 * @param[in]  bNotify Whether to notify or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCContextSetOCGState, (FPD_OCContext occ,  FPD_Object ocgDict,  FS_BOOL bState,  FS_BOOL bNotify))

NumOfSelector(FPDOCContext)
ENDENUM

//*****************************
/* OCGroup HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDOCGroupNew
 * @details Creates optional content group from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   Optional content group from a PDF dictionary.
 * @note 
 */
INTERFACE(FPD_OCGroup, FPDOCGroupNew, (FPD_Object dict))

/**
 * @brief FPDOCGroupDestroy
 * @details Destroys optional content group;
 * @param[in]  ocg Optional content group.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCGroupDestroy, (FPD_OCGroup ocg))

/**
 * @brief FPDOCGroupGetName
 * @details Gets the name of the OCG.
 * @param[in]  ocg Optional content group.
 * @param[out]  outName It will receive the name of the OCG.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetName, (FPD_OCGroup ocg,  FS_WideString* outName))

/**
 * @brief FPDOCGroupSetName
 * @details Sets the name of the OCG.
 * @param[in]  ocg Optional content group.
 * @param[in]  wszName The new OCG name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCGroupSetName, (FPD_OCGroup ocg,  FS_LPCWSTR wszName))

/**
 * @brief FPDOCGroupHasIntent
 * @details Does the OCG have the specified intent?
 * @param[in]  ocg Optional content group.
 * @param[in]  szIntent The input intent.
 * @return   Whether the OCG has the specified intent or not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupHasIntent, (FPD_OCGroup ocg,  FS_LPCSTR szIntent))

/**
 * @brief FPDOCGroupGetCreatorInfo
 * @details CreatorInfo entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outWstrCreator It receives that specifies the application that created the group.
 * @param[out]  outStrType It receives that specifies the type of content controlled by the group.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetCreatorInfo, (FPD_OCGroup ocg,  FS_WideString* outWstrCreator,  FS_ByteString* outStrType))

/**
 * @brief FPDOCGroupGetLanguageInfo
 * @details Language entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outInfo It receives that specifies a language and possibly a locale.
 * @param[out]  outPrefered It receives whether the language is a preferred language.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetLanguageInfo, (FPD_OCGroup ocg,  FS_ByteString* outInfo,  FS_BOOL* outPrefered))

/**
 * @brief FPDOCGroupGetExportState
 * @details Gets the export state of the OCG. Exports entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @return   The export state of the OCG.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetExportState, (FPD_OCGroup ocg))

/**
 * @brief FPDOCGroupGetZoomRange
 * @details Gets zoom entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outMin It receives the minimum recommended magnification factor.
 * @param[out]  outMax It receives the maximum recommended magnification factor
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetZoomRange, (FPD_OCGroup ocg,  FS_FLOAT* outMin,  FS_FLOAT* outMax))

/**
 * @brief FPDOCGroupGetPrintInfo
 * @details Gets print entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outType It receives that specifies the kind of content controlled by the group.
 * @param[out]  outState It receives the printing state of OCG.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetPrintInfo, (FPD_OCGroup ocg,  FS_ByteString* outType,  FS_BOOL* outState))

/**
 * @brief FPDOCGroupGetViewState
 * @details Gets the view state of the OCG. View entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @return   The view state of the OCG.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetViewState, (FPD_OCGroup ocg))

/**
 * @brief FPDOCGroupGetUserType
 * @details User entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outType It receives the user type of whom this OCG is primarily intended.
 * @param[out]  outUserArr It receives a string that represents the name(s) of the individual, position or organization.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetUserType, (FPD_OCGroup ocg,  FS_ByteString* outType,  FS_WideStringArray* outUserArr))

/**
 * @brief FPDOCGroupGetPageElementType
 * @details Gets PageElement entry of optional content usage dictionary.
 * @param[in]  ocg Optional content group.
 * @param[out]  outName It receives the page element type.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupGetPageElementType, (FPD_OCGroup ocg,  FS_ByteString* outName))

/**
 * @brief FPDOCGroupGetDictionary
 * @details Get the OCG dictionary.
 * @param[in]  ocg Optional content group.
 * @return   The OCG dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDOCGroupGetDictionary, (FPD_OCGroup ocg))

NumOfSelector(FPDOCGroup)
ENDENUM

//*****************************
/* OCGroupSet HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDOCGroupSetNew
 * @details Creates optional content group set from a PDF object.
 * @param[in]  obj A PDF object.
 * @return   An optional content group set.
 * @note 
 */
INTERFACE(FPD_OCGroupSet, FPDOCGroupSetNew, (FPD_Object obj))

/**
 * @brief FPDOCGroupSetDestroy
 * @details Destroys optional content group set.
 * @param[in]  ocgs Optional content group set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCGroupSetDestroy, (FPD_OCGroupSet ocgs))

/**
 * @brief FPDOCGroupSetCountElements
 * @details Gets the count of elements in the OCG set.
 * @param[in]  ocgs Optional content group set.
 * @return   The count of elements in the OCG set.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCGroupSetCountElements, (FPD_OCGroupSet ocgs))

/**
 * @brief FPDOCGroupSetIsSubGroupSet
 * @details Checks whether the specified element is a subgroup or not.
 * @param[in]  ocgs Optional content group set.
 * @param[in]  index The input zero-based element in the array.
 * @return   Non-zero means a subgroup, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupSetIsSubGroupSet, (FPD_OCGroupSet ocgs,  FS_INT32 index))

/**
 * @brief FPDOCGroupSetGetGroup
 * @details Gets a OCG from specified position.
 * @param[in]  ocgs Optional content group set.
 * @param[in]  index The input zero-based element in the array.
 * @param[out]  pOCGroup It receives the optional content group.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCGroupSetGetGroup, (FPD_OCGroupSet ocgs,  FS_INT32 index,  FPD_OCGroup* pOCGroup))

/**
 * @brief FPDOCGroupSetGetSubGroupSet
 * @details Gets a OCG set from specified position.
 * @param[in]  ocgs Optional content group set.
 * @param[in]  index The input zero-based element in the array.
 * @param[out]  pOCGroupSet It receives the optional content group set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCGroupSetGetSubGroupSet, (FPD_OCGroupSet ocgs,  FS_INT32 index,  FPD_OCGroupSet* pOCGroupSet))

/**
 * @brief FPDOCGroupSetFindGroup
 * @details Finds a OCG in the array.
 * @param[in]  ocgs Optional content group set.
 * @param[in]  groupDict The input OCG dictionary.
 * @return   The zero-based index in the array.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCGroupSetFindGroup, (FPD_OCGroupSet ocgs,  const FPD_Object groupDict))

/**
 * @brief FPDOCGroupSetGetSubGroupSetName
 * @details Gets the group set name.
 * @param[in]  ocgs Optional content group set.
 * @param[out]  outName It receives the name of the OCG set.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCGroupSetGetSubGroupSetName, (FPD_OCGroupSet ocgs,  FS_WideString* outName))

NumOfSelector(FPDOCGroupSet)
ENDENUM

//*****************************
/* OCNotify HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDOCNotifyFPD_OCNotifyNew
 * @details Creates a new OC notify interface.
 * @param[in]  proc A callback for Optional Content Notification FPD_OCNotify object.
 * @return   The OC notify interface.
 * @note 
 */
INTERFACE(FPD_OCNotify, FPDOCNotifyFPD_OCNotifyNew, (FPD_OCGStateChangedNotify proc))

/**
 * @brief FPDOCNotifyFPD_OCNotifyDestroy
 * @details Destroys the OC notify interface.
 * @param[in]  notify The OC notify interface.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCNotifyFPD_OCNotifyDestroy, (FPD_OCNotify notify))

NumOfSelector(FPDOCNotify)
ENDENUM

//*****************************
/* OCProperties HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDOCPropertiesNew
 * @details Creates optional content properties from a PDF document.
 * @param[in]  doc The input PDF document.
 * @return   Optional content properties.
 * @note 
 */
INTERFACE(FPD_OCProperties, FPDOCPropertiesNew, (FPD_Document doc))

/**
 * @brief FPDOCPropertiesDestroy
 * @details Destroys optional content properties.
 * @param[in]  ocprops Optional content properties.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCPropertiesDestroy, (FPD_OCProperties ocprops))

/**
 * @brief FPDOCPropertiesGetDocument
 * @details Gets the PDF document.
 * @param[in]  ocprops Optional content properties.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDOCPropertiesGetDocument, (FPD_OCProperties ocprops))

/**
 * @brief FPDOCPropertiesGetOCGroups
 * @details Retrieves all OCG objects for a document or a page.
	*            If iPageIndex equals to -1, all document level OCG objects are returned; 
	*            or all page level OCG objects are returned.
 * @param[in]  ocprops Optional content properties.
 * @param[out]  arrOCGs It receives all OCG objects in specified page.
 * @param[in]  page_index The input zero-based page index.
 * @return   The number of OCG retrieved.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCPropertiesGetOCGroups, (FPD_OCProperties ocprops,  FS_PtrArray* arrOCGs,  FS_INT32 page_index))

/**
 * @brief FPDOCPropertiesIsOCGroup
 * @details Determines whether a dictionary object is a valid OCG object.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  dict The input PDF dictionary.
 * @return   Non-zero means valid, otherwise invalid.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCPropertiesIsOCGroup, (FPD_OCProperties ocprops,  const FPD_Object dict))

/**
 * @brief FPDOCPropertiesRetrieveOCGPages
 * @details Retrieves all pages objects in which the specified pOCGDict is referenced.
	*            One OCG can be shared by several pages. pages is an array of page dictionary objects.
	*            The returned value is the count of the elements in pages array.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  dict The input OCG dictionary.
 * @param[out]  arrPages It receives all page dictionaries in which the specified OCG is referenced.
 * @return   The number of pages referenced.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCPropertiesRetrieveOCGPages, (FPD_OCProperties ocprops,  const FPD_Object dict,  FS_PtrArray* arrPages))

/**
 * @brief FPDOCPropertiesIsOCGInPage
 * @details Determines whether a OCG object is in a page or not.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  page_dict The input page dictionary.
 * @param[in]  ocg_dict The input OCG dictionary.
 * @return   Non-zero means in the page, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDOCPropertiesIsOCGInPage, (FPD_OCProperties ocprops,  const FPD_Object page_dict,  FPD_Object ocg_dict))

/**
 * @brief FPDOCPropertiesGetOCGroupOrder
 * @details Orders entry in optional content configuration dictionary.
	*            All document level OCG objects can be stored in an ordered tree object, this will be showed in UI.
 * @param[in]  ocprops Optional content properties.
 * @param[out]  pOCGroupSet It receives the OCG set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCPropertiesGetOCGroupOrder, (FPD_OCProperties ocprops,  FPD_OCGroupSet* pOCGroupSet))

/**
 * @brief FPDOCPropertiesCountConfigs
 * @details Gets the count of configuration dictionaries in the OCP.
 * @param[in]  ocprops Optional content properties.
 * @return   The count of configuration dictionaries in the OCP.
 * @note 
 */
INTERFACE(FS_INT32, FPDOCPropertiesCountConfigs, (FPD_OCProperties ocprops))

/**
 * @brief FPDOCPropertiesGetConfig
 * @details Gets a configuration dictionary in the OCP.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  index The input zero-based configuration dictionary index.
 * @return   A configuration dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDOCPropertiesGetConfig, (FPD_OCProperties ocprops,  FS_INT32 index))

/**
 * @brief FPDOCPropertiesAddOCNotify
 * @details Adds an user-supplied optional content notify interface to the OCP.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  ocgNotifyCallback The input user supplied notify interface to add.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCPropertiesAddOCNotify, (FPD_OCProperties ocprops,  FPD_OCNotify ocgNotifyCallback))

/**
 * @brief FPDOCPropertiesRemoveOCNotify
 * @details Removes an user-supplied optional content notify interface from OCP.
 * @param[in]  ocprops Optional content properties.
 * @param[in]  ocgNotifyCallback The input user supplied notify interface to remove.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDOCPropertiesRemoveOCNotify, (FPD_OCProperties ocprops,  FPD_OCNotify ocgNotifyCallback))

NumOfSelector(FPDOCProperties)
ENDENUM

//*****************************
/* LWinParam HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLWinParamNew
 * @details Creates windows launch param from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   Windows launch Param.
 * @note 
 */
INTERFACE(FPD_LWinParam, FPDLWinParamNew, (FPD_Object dict))

/**
 * @brief FPDLWinParamDestroy
 * @details Destroys windows launch param.
 * @param[in]  param Windows launch param.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamDestroy, (FPD_LWinParam param))

/**
 * @brief FPDLWinParamGetFileName
 * @details Gets the file name of the the application to be launched or the document to be opened or printed.
 * @param[in]  param Windows launch param.
 * @param[out]  outFileName It receives the file name
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamGetFileName, (FPD_LWinParam param,  FS_ByteString* outFileName))

/**
 * @brief FPDLWinParamSetFileName
 * @details Sets the file name in the windows launch param.
 * @param[in]  param Windows launch param.
 * @param[in]  szFile The new file name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamSetFileName, (FPD_LWinParam param,  FS_LPSTR szFile))

/**
 * @brief FPDLWinParamGetDefaultDirectory
 * @details Gets the default directory in standard DOS syntax.
 * @param[in]  param Windows launch param.
 * @param[out]  outDirectory The default directory in standard DOS syntax.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamGetDefaultDirectory, (FPD_LWinParam param,  FS_ByteString* outDirectory))

/**
 * @brief FPDLWinParamSetDefaultDirectory
 * @details Sets the default directory.
 * @param[in]  param Windows launch param.
 * @param[in]  szDirectory The new default directory.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamSetDefaultDirectory, (FPD_LWinParam param,  FS_LPSTR szDirectory))

/**
 * @brief FPDLWinParamGetOperation
 * @details Gets the operation to perform.
 * @param[in]  param Windows launch param.
 * @param[out]  outOperation It receives the operation to perform.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamGetOperation, (FPD_LWinParam param,  FS_ByteString* outOperation))

/**
 * @brief FPDLWinParamSetOperation
 * @details Sets the operation ASCII string.
 * @param[in]  param Windows launch param.
 * @param[in]  szOperation The new operation string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamSetOperation, (FPD_LWinParam param,  FS_LPSTR szOperation))

/**
 * @brief FPDLWinParamGetParam
 * @details Gets the param to be passed to the application designated by the F entry.
 * @param[in]  param Windows launch param.
 * @param[out]  outParam It receives the param to be passed to the application designated by the F entry.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamGetParam, (FPD_LWinParam param,  FS_ByteString* outParam))

/**
 * @brief FPDLWinParamSetParam
 * @details Sets the application Params.
 * @param[in]  param Windows launch param.
 * @param[in]  szParam The new application params.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLWinParamSetParam, (FPD_LWinParam param,  FS_LPSTR szParam))

/**
 * @brief FPDLWinParamGetDict
 * @details Gets the windows launch Param dictionary.
 * @param[in]  param Windows launch param.
 * @return   The windows launch param dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDLWinParamGetDict, (FPD_LWinParam param))

NumOfSelector(FPDLWinParam)
ENDENUM

//*****************************
/* ActionFields HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDActionFieldsNew
 * @details Creates PDF action fields from a PDF action.
 * @param[in]  action The input PDF action.
 * @return   PDF action fields.
 * @note 
 */
INTERFACE(FPD_ActionFields, FPDActionFieldsNew, (FPD_Action action))

/**
 * @brief FPDActionFieldsDestroy
 * @details Destroys PDF action fields.
 * @param[in]  actFields The input PDF action fields.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionFieldsDestroy, (FPD_ActionFields actFields))

/**
 * @brief FPDActionFieldsGetFieldsCount
 * @details Gets the count of action fields.
 * @param[in]  actFields The input PDF action fields.
 * @return   The count of action fields.
 * @note 
 */
INTERFACE(FS_DWORD, FPDActionFieldsGetFieldsCount, (FPD_ActionFields actFields))

/**
 * @brief FPDActionFieldsGetAllFields
 * @details Gets all fields in the action dictionary.
	*            outFieldObjects is an array of FPD_Object.
 * @param[in]  actFields The input PDF action fields.
 * @param[out]  outFieldObjects It receives all fields in the action dictionary.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionFieldsGetAllFields, (FPD_ActionFields actFields,  FS_PtrArray* outFieldObjects))

/**
 * @brief FPDActionFieldsGetField
 * @details Gets a field value.
	*			  returned object may be FPD_Object or FPD_String.
 * @param[in]  actFields The input PDF action fields.
 * @param[in]  index The zero-based field index.
 * @return   A PDF object.
 * @note 
 */
INTERFACE(FPD_Object, FPDActionFieldsGetField, (FPD_ActionFields actFields,  FS_DWORD index))

/**
 * @brief FPDActionFieldsInsertField
 * @details Inserts a field.
	*            field: it can be FPD_Object or FPD_String object,
	*            if need insert field as name(string), construct name as FPD_String object
 * @param[in]  actFields The input PDF action fields.
 * @param[in]  iInsertAt The zero-based field index to insert at.
 * @param[in]  field The field value.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionFieldsInsertField, (FPD_ActionFields actFields,  FS_DWORD iInsertAt,  const FPD_Object field))

/**
 * @brief FPDActionFieldsRemoveField
 * @details Removes a field from PDF action fields.
 * @param[in]  actFields The input PDF action fields.
 * @param[in]  index The zero-based field index to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionFieldsRemoveField, (FPD_ActionFields actFields,  FS_DWORD index))

/**
 * @brief FPDActionFieldsGetAction
 * @details Gets the PDF action dictionary.
 * @param[in]  actFields The input PDF action fields.
 * @return   The PDF action dictionary.
 * @note 
 */
INTERFACE(FPD_Action, FPDActionFieldsGetAction, (FPD_ActionFields actFields))

NumOfSelector(FPDActionFields)
ENDENUM

//*****************************
/* Action HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDActionNew
 * @details Creates a PDF action from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   A PDF action.
 * @note 
 */
INTERFACE(FPD_Action, FPDActionNew, (FPD_Object dict))

/**
 * @brief FPDActionNew2
 * @details Creates a PDF action with specified action type.
 * @param[in]  doc The input PDF document.
 * @param[in]  actionType The input action type.
 * @return   A PDF action.
 * @note 
 */
INTERFACE(FPD_Action, FPDActionNew2, (FPD_Document doc,  FPD_ActionType actionType))

/**
 * @brief FPDActionNew3
 * @details Creates a PDF action with specified action type name.
 * @param[in]  doc The input PDF document.
 * @param[in]  szType The input action type name.
 * @return   A PDF action.
 * @note 
 */
INTERFACE(FPD_Action, FPDActionNew3, (FPD_Document doc,  FS_LPSTR szType))

/**
 * @brief FPDActionDestroy
 * @details Destroys a PDF action.
 * @param[in]  action A PDF action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionDestroy, (FPD_Action action))

/**
 * @brief FPDActionGetTypeName
 * @details Gets the type name of the action.
 * @param[in]  action A PDF action.
 * @param[out]  outTypeName It receives the type name of the action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetTypeName, (FPD_Action action,  FS_ByteString* outTypeName))

/**
 * @brief FPDActionGetType
 * @details Gets the type of the action.
 * @param[in]  action A PDF action.
 * @return   The type of the action.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionGetType, (FPD_Action action))

/**
 * @brief FPDActionGetDest
 * @details Gets the destination.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[out]  outDest A PDF destination.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetDest, (FPD_Action action,  FPD_Document doc,  FPD_Dest* outDest))

/**
 * @brief FPDActionSetDest
 * @details Sets the destination.
 * @param[in]  action A PDF action.
 * @param[in]  dest Ref to a PDF destination.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetDest, (FPD_Action action,  const FPD_Dest dest))

/**
 * @brief FPDActionGetFilePath
 * @details Gets the file full path.
 * @param[in]  action A PDF action.
 * @param[out]  outName It receives the file full path.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetFilePath, (FPD_Action action,  FS_WideString* outName))

/**
 * @brief FPDActionSetFilePath
 * @details Sets the file full path.
 * @param[in]  action A PDF action.
 * @param[in]  wszFilePath The input file full path.
 * @param[in]  bIsURL Whether the file path is a URL or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetFilePath, (FPD_Action action,  FS_LPCWSTR wszFilePath,  FS_BOOL bIsURL))

/**
 * @brief FPDActionGetNewWindow
 * @details Checks whether to open the destination document in a new window or not.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for opening the destination document in a new window.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionGetNewWindow, (FPD_Action action))

/**
 * @brief FPDActionSetNewWindow
 * @details Sets the new window flag.
 * @param[in]  action A PDF action.
 * @param[in]  bNewWindow The flag which identifies whether to open the destination document in a new window or not.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetNewWindow, (FPD_Action action,  FS_BOOL bNewWindow))

/**
 * @brief FPDActionGetWinParam
 * @details Gets the windows launch param.
 * @param[in]  action A PDF action.
 * @param[out]  outWinParam The windows launch params.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetWinParam, (FPD_Action action,  FPD_LWinParam* outWinParam))

/**
 * @brief FPDActionSetWinParam
 * @details Sets the windows launch params.
 * @param[in]  action A PDF action.
 * @param[in]  param Ref to a windows launch param object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetWinParam, (FPD_Action action,  const FPD_LWinParam param))

/**
 * @brief FPDActionGetURI
 * @details Gets the URI(uniform resource identifier) of the PDF action.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[out]  outURL It receives the URI.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetURI, (FPD_Action action,  FPD_Document doc,  FS_ByteString* outURL))

/**
 * @brief FPDActionSetURI
 * @details Sets the URI of the PDF action.
 * @param[in]  action A PDF action.
 * @param[in]  szURI The input URI.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetURI, (FPD_Action action,  FS_LPSTR szURI))

/**
 * @brief FPDActionGetMouseMap
 * @details Gets the flag which indicates whether to track the mouse position when the URI is resolved.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for tracking the mouse position when the URI is resolved.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionGetMouseMap, (FPD_Action action))

/**
 * @brief FPDActionSetMouseMap
 * @details Sets the mouse-position-tracking flag.
 * @param[in]  action A PDF action.
 * @param[in]  bMap The new mouse-position-tracking flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetMouseMap, (FPD_Action action,  FS_BOOL bMap))

/**
 * @brief FPDActionGetWidgets
 * @details Gets the fields array.
 * @param[in]  action A PDF action.
 * @param[out]  outWidgets It receives the action fields.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetWidgets, (FPD_Action action,  FPD_ActionFields* outWidgets))

/**
 * @brief FPDActionGetHideStatus
 * @details Gets the hide status of a PDF action.
 * @param[in]  action A PDF action.
 * @return   The hide status of a PDF action.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionGetHideStatus, (FPD_Action action))

/**
 * @brief FPDActionSetHideStatus
 * @details Sets the hide status of a PDF action.
 * @param[in]  action A PDF action.
 * @param[in]  bHide The input hide status.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetHideStatus, (FPD_Action action,  FS_BOOL bHide))

/**
 * @brief FPDActionGetNameAction
 * @details Gets the name of named action.
 * @param[in]  action A PDF action.
 * @param[out]  outNamedAction It receives the name of named action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetNameAction, (FPD_Action action,  FS_ByteString* outNamedAction))

/**
 * @brief FPDActionSetNameAction
 * @details Sets the name of named action.
 * @param[in]  action A PDF action.
 * @param[in]  szName The  input name of named action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetNameAction, (FPD_Action action,  FS_LPCSTR szName))

/**
 * @brief FPDActionGetFlags
 * @details Gets the flags for action type SubmitForm, ResetForm.
 * @param[in]  action A PDF action.
 * @return   The flags for action type SubmitForm, ResetForm.
 * @note 
 */
INTERFACE(FS_DWORD, FPDActionGetFlags, (FPD_Action action))

/**
 * @brief FPDActionSetFlags
 * @details Sets the flags for action type SubmitForm, ResetForm.
 * @param[in]  action A PDF action.
 * @param[in]  dwFlags The input flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetFlags, (FPD_Action action,  FS_DWORD dwFlags))

/**
 * @brief FPDActionGetJavaScript
 * @details Gets the javascript script to be executed.
 * @param[in]  action A PDF action.
 * @param[out]  outJavaScript It receives the javascript script to be executed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetJavaScript, (FPD_Action action,  FS_WideString* outJavaScript))

/**
 * @brief FPDActionSetJavaScript
 * @details Sets the javascript with a byte string.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  szJavaScript The javascript in byte string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetJavaScript, (FPD_Action action,  FPD_Document doc,  FS_LPCSTR szJavaScript))

/**
 * @brief FPDActionSetJavaScriptW
 * @details Sets the javascript with a wide string.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  wszJavaScript The javascript in wide string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetJavaScriptW, (FPD_Action action,  FPD_Document doc,  FS_LPCWSTR wszJavaScript))

/**
 * @brief FPDActionCountRenditions
 * @details Gets the count of renditions.
 * @param[in]  action A PDF action.
 * @return   The count of renditions.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionCountRenditions, (FPD_Action action))

/**
 * @brief FPDActionGetRendition
 * @details Gets a rendition.
 * @param[in]  action A PDF action.
 * @param[in]  index The zero-based rendition index.
 * @param[out]  outRendition It receives the rendition.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetRendition, (FPD_Action action,  FS_INT32 index,  FPD_Rendition* outRendition))

/**
 * @brief FPDActionInsertRendition
 * @details Inserts a rendition.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  renditionDict The input rendition dictionary.
 * @param[in]  index The zero-based rendition index.
 * @return   The inserted index in the rendition array.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionInsertRendition, (FPD_Action action,  FPD_Document doc,  FPD_Object renditionDict,  FS_INT32 index))

/**
 * @brief FPDActionRemoveRendition
 * @details Removes a rendition.
 * @param[in]  action A PDF action.
 * @param[in]  renditionDict The input rendition dictionary.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionRemoveRendition, (FPD_Action action,  FPD_Object renditionDict))

/**
 * @brief FPDActionGetAnnot
 * @details Gets the annotation dictionary.
 * @param[in]  action A PDF action.
 * @return   The annotation dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDActionGetAnnot, (FPD_Action action))

/**
 * @brief FPDActionSetAnnot
 * @details Sets the annotation dictionary.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  annotDict The input annotation dictionary.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetAnnot, (FPD_Action action,  FPD_Document doc,  FPD_Object annotDict))

/**
 * @brief FPDActionGetOperationType
 * @details Gets the operation type.
 * @param[in]  action A PDF action.
 * @return   The operation type.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionGetOperationType, (FPD_Action action))

/**
 * @brief FPDActionSetOperationType
 * @details Sets the operation type.
 * @param[in]  action A PDF action.
 * @param[in]  iType The input operation type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetOperationType, (FPD_Action action,  FS_INT32 iType))

/**
 * @brief FPDActionGetSoundStream
 * @details Gets the sound stream object.
 * @param[in]  action A PDF action.
 * @return   The sound stream object.
 * @note 
 */
INTERFACE(FPD_Object, FPDActionGetSoundStream, (FPD_Action action))

/**
 * @brief FPDActionGetVolume
 * @details Gets the volume of the sound.  The volume at which to play the sound, in the range -1.0 to 1.0.
 * @param[in]  action A PDF action.
 * @return   The volume of the sound.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDActionGetVolume, (FPD_Action action))

/**
 * @brief FPDActionIsSynchronous
 * @details Checks whether to play the sound synchronously or asynchronously.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for playing the sound synchronously.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionIsSynchronous, (FPD_Action action))

/**
 * @brief FPDActionIsRepeat
 * @details Checks whether to repeat the sound indefinitely.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for repeating the sound indefinitely.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionIsRepeat, (FPD_Action action))

/**
 * @brief FPDActionIsMixPlay
 * @details Checks whether to mix this sound with any other sound already playing.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for mixing this sound with any other sound already playing.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionIsMixPlay, (FPD_Action action))

/**
 * @brief FPDActionCountOCGStates
 * @details Gets the count of OCG states.
 * @param[in]  action A PDF action.
 * @return   The count of OCG states.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionCountOCGStates, (FPD_Action action))

/**
 * @brief FPDActionGetOCGStates
 * @details Gets OCG array with specified state.
 * @param[in]  action A PDF action.
 * @param[in]  iIndex The zero-based OCG state index.
 * @param[out]  outState It receives the OCG state.
 * @param[out]  outArrOcgs It receives the OCG state.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionGetOCGStates, (FPD_Action action,  FS_INT32 iIndex,  FS_INT32* outState,  FS_PtrArray* outArrOcgs))

/**
 * @brief FPDActionInsertOCGStates
 * @details Inserts a OCG state.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  iIndex The OCG state index to insert at.
 * @param[in]  OCGState The OCG state to insert.
 * @param[in]  arrOcgs The OCG array.
 * @return   The number of states inserted.
 * @note 
 */
INTERFACE(FS_INT32, FPDActionInsertOCGStates, (FPD_Action action,  FPD_Document doc,  FS_INT32 iIndex,  FPD_OCGState OCGState,  const FS_PtrArray arrOcgs))

/**
 * @brief FPDActionReplaceOCGStates
 * @details Replaces a OCG state.
 * @param[in]  action A PDF action.
 * @param[in]  doc The input PDF document.
 * @param[in]  iIndex The start OCG state index to replace.
 * @param[in]  arrOcgs The OCG array.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionReplaceOCGStates, (FPD_Action action,  FPD_Document doc,  FS_INT32 iIndex,  const FS_PtrArray arrOcgs))

/**
 * @brief FPDActionRemoveOCGStates
 * @details Removes a OCG state.
 * @param[in]  action A PDF action.
 * @param[in]  index The OCG state index.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionRemoveOCGStates, (FPD_Action action,  FS_INT32 index))

/**
 * @brief FPDActionIsStatePreserved
 * @details Checks whether the radio-button state relationships between optional content groups apply or not.
 * @param[in]  action A PDF action.
 * @return   <a>TRUE</a> for the radio-button state relationships between optional content groups applying. Otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDActionIsStatePreserved, (FPD_Action action))

/**
 * @brief FPDActionSetStatePreserved
 * @details Sets the radio-button state relationships flag.
 * @param[in]  action A PDF action.
 * @param[in]  bPreserved The new flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionSetStatePreserved, (FPD_Action action,  FS_BOOL bPreserved))

/**
 * @brief FPDActionGetSubActionsCount
 * @details Gets the sub-action count.
 * @param[in]  action A PDF action.
 * @return   The sub-action count.
 * @note 
 */
INTERFACE(FS_DWORD, FPDActionGetSubActionsCount, (FPD_Action action))

/**
 * @brief FPDActionGetSubAction
 * @details Gets a sub-action.
 * @param[in]  action A PDF action.
 * @param[in]  index The zero-based sub-action index.
 * @param[]  out] outAction It receives the sub-action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionGetSubAction, (FPD_Action action,  FS_DWORD index,  FPD_Action* outAction))

/**
 * @brief FPDActionInsertSubAction
 * @details Inserts a sub-action at specified position.
 * @param[in]  action A PDF action.
 * @param[in]  index The zero-based sub-action index to insert at.
 * @param[in]  document The PDF document.
 * @param[in]  subAction The input sub-action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionInsertSubAction, (FPD_Action action,  FS_DWORD index,  FPD_Document document,  const FPD_Action subAction))

/**
 * @brief FPDActionRemoveSubAction
 * @details Removes a sub-action.
 * @param[in]  action A PDF action.
 * @param[in]  index The zero-based sub-action index.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionRemoveSubAction, (FPD_Action action,  FS_DWORD index))

/**
 * @brief FPDActionRemoveAllSubActions
 * @details Removes all sub-actions.
 * @param[in]  action A PDF action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDActionRemoveAllSubActions, (FPD_Action action))

/**
 * @brief FPDActionGetDict
 * @details Gets the PDF action dictionary.
 * @param[in]  action A PDF action.
 * @return   The PDF action dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDActionGetDict, (FPD_Action action))

NumOfSelector(FPDAction)
ENDENUM

//*****************************
/* AAction HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDAActionNew
 * @details Creates PDF additional-action from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   PDF additional-action.
 * @note 
 */
INTERFACE(FPD_AAction, FPDAActionNew, (FPD_Object dict))

/**
 * @brief FPDAActionDestroy
 * @details Destroys PDF additional-action.
 * @param[in]  aaction PDF additional-action
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAActionDestroy, (FPD_AAction aaction))

/**
 * @brief FPDAActionActionExist
 * @details Checks whether the specified additional-action type exists or not.
 * @param[in]  aaction PDF additional-action
 * @param[in]  eType The input additional-action type.
 * @return   Non-zero means exist, otherwise not exist.
 * @note 
 */
INTERFACE(FS_BOOL, FPDAActionActionExist, (FPD_AAction aaction,  FPD_AActionType eType))

/**
 * @brief FPDAActionGetAction
 * @details Gets an action from the additional-action with specified additional-action type.
 * @param[in]  aaction PDF additional-action
 * @param[in]  eType The input additional-action type.
 * @param[out]  outAction An action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAActionGetAction, (FPD_AAction aaction,  FPD_AActionType eType,  FPD_Action* outAction))

/**
 * @brief FPDAActionSetAction
 * @details Sets a additional-action of specified type.
 * @param[in]  aaction PDF additional-action
 * @param[in]  doc The PDF document.
 * @param[in]  eType The additional-action type.
 * @param[in]  action The input action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAActionSetAction, (FPD_AAction aaction,  FPD_Document doc,  FPD_AActionType eType,  const FPD_Action action))

/**
 * @brief FPDAActionRemoveAction
 * @details Removes a additional-action.
 * @param[in]  aaction PDF additional-action
 * @param[in]  eType The additional-action type to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAActionRemoveAction, (FPD_AAction aaction,  FPD_AActionType eType))

/**
 * @brief FPDAActionGetStartPos
 * @details Gets the start position of action list.
 * @param[in]  aaction PDF additional-action
 * @return   The start position of action list.
 * @note 
 */
INTERFACE(FS_POSITION, FPDAActionGetStartPos, (FPD_AAction aaction))

/**
 * @brief FPDAActionGetNextAction
 * @details Gets the current action and move the position to next position.
 * @param[in]  aaction PDF additional-action
 * @param[in,out]  outPos Input the current position and receive the next position.
 * @param[out]  outType Receive the additional-action type.
 * @param[out]  outAction Receive the current action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAActionGetNextAction, (FPD_AAction aaction,  FS_POSITION* outPos,  FPD_AActionType* outType,  FPD_Action* outAction))

/**
 * @brief FPDAActionGetDictionary
 * @details Gets the additional-action dictionary.
 * @param[in]  aaction PDF additional-action
 * @return   The additional-action dictionary.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FPD_Object, FPDAActionGetDictionary, (FPD_AAction aaction))

NumOfSelector(FPDAAction)
ENDENUM

//*****************************
/* DocJSActions HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDDocJSActionsNew
 * @details Creates document-level JavaScript actions from a PDF document.
 * @param[in]  doc The input PDF document.
 * @return   Document-level JavaScript actions.
 * @note 
 */
INTERFACE(FPD_DocJSActions, FPDDocJSActionsNew, (FPD_Document doc))

/**
 * @brief FPDDocJSActionsDestroy
 * @details Destroys document-level JavaScript actions.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocJSActionsDestroy, (FPD_DocJSActions jsActions))

/**
 * @brief FPDDocJSActionsCountJSActions
 * @details Gets the count of JavaScript actions.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @return   The count of JavaScript actions.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocJSActionsCountJSActions, (FPD_DocJSActions jsActions))

/**
 * @brief FPDDocJSActionsGetJSAction
 * @details Gets a JavaScript action with the position and the name.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @param[in]  index The zero-based JavaScipt action index.
 * @param[in]  wszName The name of the JavaScript action.
 * @param[out]  outAction A JavaScript action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocJSActionsGetJSAction, (FPD_DocJSActions jsActions,  FS_INT32 index,  FS_LPCWSTR wszName,  FPD_Action* outAction))

/**
 * @brief FPDDocJSActionsGetJSAction2
 * @details Gets a JavaScript action with the name.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @param[in]  wszName The name of the JavaScript action.
 * @param[out]  outAction A JavaScript action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDocJSActionsGetJSAction2, (FPD_DocJSActions jsActions,  FS_LPCWSTR wszName,  FPD_Action* outAction))

/**
 * @brief FPDDocJSActionsSetJSAction
 * @details Sets a JavaScript action.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @param[in]  wszName The name of the JavaScript action.
 * @param[in]  action The JavaScript action.
 * @return   The zero-based index of the JavaScript action.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocJSActionsSetJSAction, (FPD_DocJSActions jsActions,  FS_LPCWSTR wszName,  FPD_Action action))

/**
 * @brief FPDDocJSActionsFindJSAction
 * @details Finds a JavaScript action.
	*            return the position (zero based index), -1 means not found.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @param[in]  wszName The name of the JavaScript action.
 * @return   The zero-based index of the JavaScript action.
 * @note 
 */
INTERFACE(FS_INT32, FPDDocJSActionsFindJSAction, (FPD_DocJSActions jsActions,  FS_LPCWSTR wszName))

/**
 * @brief FPDDocJSActionsRemoveJSAction
 * @details Removes a JavaScript action.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @param[in]  index The zero-based index of JavaScript action to be removed.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDocJSActionsRemoveJSAction, (FPD_DocJSActions jsActions,  FS_INT32 index))

/**
 * @brief FPDDocJSActionsGetDocument
 * @details Gets the PDF document.
 * @param[in]  jsActions The input document-level JavaScript actions.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDDocJSActionsGetDocument, (FPD_DocJSActions jsActions))

NumOfSelector(FPDDocJSActions)
ENDENUM

//*****************************
/* FileSpec HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFileSpecNew
 * @details Creates a new file specification object - dictionary object.
 * @param[in]  void 
 * @return   A new file specification object.
 * @note 
 */
INTERFACE(FPD_FileSpec, FPDFileSpecNew, (void))

/**
 * @brief FPDFileSpecNewFromObj
 * @details Creates a new file specification object from a PDF object.
 * @param[in]  obj The input PDF object.
 * @return   A new file specification object.
 * @note 
 */
INTERFACE(FPD_FileSpec, FPDFileSpecNewFromObj, (FPD_Object obj))

/**
 * @brief FPDFileSpecDestroy
 * @details Destroys a file specification object.
 * @param[in]  fileSpec A file specification object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFileSpecDestroy, (FPD_FileSpec fileSpec))

/**
 * @brief FPDFileSpecIsURL
 * @details Checks whether it's a URL or not.
	*            If is an URL, FPDFileSpecGetFileName gets the URL address.
 * @param[in]  fileSpec A file specification object.
 * @return   <a>TRUE</a> for being a URL, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFileSpecIsURL, (FPD_FileSpec fileSpec))

/**
 * @brief FPDFileSpecGetFileName
 * @details Gets the file name.
 * @param[in]  fileSpec A file specification object.
 * @param[out]  outFile It receives the file name.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFileSpecGetFileName, (FPD_FileSpec fileSpec,  FS_WideString* outFile))

/**
 * @brief FPDFileSpecGetFileStream
 * @details Gets a PDF stream from the file specification.
 * @param[in]  fileSpec A file specification object.
 * @return   The PDF stream object from the file specification.
 * @note 
 */
INTERFACE(FPD_Object, FPDFileSpecGetFileStream, (FPD_FileSpec fileSpec))

/**
 * @brief FPDFileSpecSetFileName
 * @details Sets the file name.
 * @param[in]  fileSpec A file specification object.
 * @param[in]  wszFile Input a file name.
 * @param[in]  bURL Whether the input file name is an URL.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFileSpecSetFileName, (FPD_FileSpec fileSpec,  FS_LPCWSTR wszFile,  FS_BOOL bURL))

/**
 * @brief FPDFileSpecSetEmbeddedFile
 * @details Sets an embedded file.
 * @param[in]  fileSpec A file specification object.
 * @param[in]  doc The PDF document.
 * @param[in]  pFileReadHandler The file access interface.
 * @param[in]  szFilePath The file path.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFileSpecSetEmbeddedFile, (FPD_FileSpec fileSpec,  FPD_Document doc,  FS_FileReadHandler pFileReadHandler,  FS_LPCWSTR szFilePath))

NumOfSelector(FPDFileSpec)
ENDENUM

//*****************************
/* MediaPlayer HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDMediaPlayerNew
 * @details Creates an empty media player information object.
 * @param[in]  void 
 * @return   An empty media player information object.
 * @note 
 */
INTERFACE(FPD_MediaPlayer, FPDMediaPlayerNew, (void))

/**
 * @brief FPDMediaPlayerNewFromDict
 * @details Creates an media player information object from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   An media player information object.
 * @note 
 */
INTERFACE(FPD_MediaPlayer, FPDMediaPlayerNewFromDict, (FPD_Object dict))

/**
 * @brief FPDMediaPlayerDestroy
 * @details Destroys the media player information object.
 * @param[in]  player The media player information object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMediaPlayerDestroy, (FPD_MediaPlayer player))

/**
 * @brief FPDMediaPlayerGetSoftwareURI
 * @details Gets the software URI.
 * @param[in]  player The media player information object.
 * @param[out]  outURL The software URI.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMediaPlayerGetSoftwareURI, (FPD_MediaPlayer player,  FS_ByteString* outURL))

/**
 * @brief FPDMediaPlayerSetSoftwareURI
 * @details Sets the software URI.
 * @param[in]  player The media player information object.
 * @param[in]  szURI The input software URI.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMediaPlayerSetSoftwareURI, (FPD_MediaPlayer player,  FS_LPCSTR szURI))

/**
 * @brief FPDMediaPlayerGetOSArray
 * @details Gets the OS array in the software identifier dictionary.
 * @param[in]  player The media player information object.
 * @param[out]  outOSArray It receives the OS array.
 * @return   The number of OS in the array.
 * @note 
 */
INTERFACE(FS_INT32, FPDMediaPlayerGetOSArray, (FPD_MediaPlayer player,  FS_ByteStringArray* outOSArray))

/**
 * @brief FPDMediaPlayerSetOSArray
 * @details Sets the OS array.
 * @param[in]  player The media player information object.
 * @param[in]  osArray The input OS array.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDMediaPlayerSetOSArray, (FPD_MediaPlayer player,  const FS_ByteStringArray osArray))

NumOfSelector(FPDMediaPlayer)
ENDENUM

//*****************************
/* Rendition HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDRenditionNew
 * @details Creates an empty rendition object.
 * @param[in]  void 
 * @return   An empty rendition object.
 * @note 
 */
INTERFACE(FPD_Rendition, FPDRenditionNew, (void))

/**
 * @brief FPDRenditionNewFromDict
 * @details Creates a rendition object from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   A rendition object.
 * @note 
 */
INTERFACE(FPD_Rendition, FPDRenditionNewFromDict, (FPD_Object dict))

/**
 * @brief FPDRenditionDestroy
 * @details Destroys a rendition object.
 * @param[in]  rendition The input rendition object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionDestroy, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionHasMediaClip
 * @details Checks whether the rendition dictionary has the C entry.
 * @param[in]  rendition The input rendition object.
 * @return   <a>TRUE</a> for the rendition dictionary having the C entry, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionHasMediaClip, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionGetRenditionName
 * @details Gets the rendition name.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outName The rendition name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetRenditionName, (FPD_Rendition rendition,  FS_WideString* outName))

/**
 * @brief FPDRenditionSetRenditionName
 * @details Sets the rendition name.
 * @param[in]  rendition The input rendition object.
 * @param[in]  wszName The input rendition name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetRenditionName, (FPD_Rendition rendition,  FS_LPCWSTR wszName))

/**
 * @brief FPDRenditionGetMediaClipName
 * @details Gets the media clip name.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outName The media clip name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetMediaClipName, (FPD_Rendition rendition,  FS_WideString* outName))

/**
 * @brief FPDRenditionSetMediaClipName
 * @details Sets the media clip name.
 * @param[in]  rendition The input rendition object.
 * @param[in]  wszName The input media clip name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMediaClipName, (FPD_Rendition rendition,  FS_LPCWSTR wszName))

/**
 * @brief FPDRenditionGetMediaClipFile
 * @details Gets the file specification of the actual media data.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outFileSpec The file specification of the actual media data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetMediaClipFile, (FPD_Rendition rendition,  FPD_FileSpec* outFileSpec))

/**
 * @brief FPDRenditionSetMediaClipFile
 * @details Sets the file specification of the actual media data.
 * @param[in]  rendition The input rendition object.
 * @param[in]  doc The input PDF document.
 * @param[in]  file The input file specification object.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMediaClipFile, (FPD_Rendition rendition,  FPD_Document doc,  FPD_FileSpec file))

/**
 * @brief FPDRenditionGetMediaClipContentType
 * @details Gets the content type (MIME type) of the media data.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outContentType The content type (MIME type) of the media data.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetMediaClipContentType, (FPD_Rendition rendition,  FS_ByteString* outContentType))

/**
 * @brief FPDRenditionSetMediaClipContentType
 * @details Sets the content type (MIME type) of the media data.
 * @param[in]  rendition The input rendition object.
 * @param[in]  szContentType The input content type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMediaClipContentType, (FPD_Rendition rendition,  FS_LPCSTR szContentType))

/**
 * @brief FPDRenditionGetPermission
 * @details Gets the media permission that indicates the circumstances under which it is acceptable 
	*			  to write a temporary file in order to play a media clip.
 * @param[in]  rendition The input rendition object.
 * @return   The media permission
 * @note 
 */
INTERFACE(FPD_MediaPermission, FPDRenditionGetPermission, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetPermission
 * @details Sets the media permission.
 * @param[in]  rendition The input rendition object.
 * @param[in]  ePermission The input media permission.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetPermission, (FPD_Rendition rendition,  FPD_MediaPermission ePermission))

/**
 * @brief FPDRenditionGetMediaDescriptions
 * @details Gets the text descriptions array that provides alternate text descriptions for 
	*            the media clip data in case it cannot be played.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outDescArray It receives the text descriptions array.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionGetMediaDescriptions, (FPD_Rendition rendition,  FS_WideStringArray* outDescArray))

/**
 * @brief FPDRenditionSetMediaDescriptions
 * @details Sets the text descriptions array.
 * @param[in]  rendition The input rendition object.
 * @param[in]  descArray The input text descriptions array.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMediaDescriptions, (FPD_Rendition rendition,  const FS_WideStringArray descArray))

/**
 * @brief FPDRenditionGetMediaBaseURL
 * @details Gets an absolute URL to be used as the base URL in resolving any relative URLs found within the media data.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outURL It receives the absolute URL.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetMediaBaseURL, (FPD_Rendition rendition,  FS_ByteString* outURL))

/**
 * @brief FPDRenditionSetMediaBaseURL
 * @details Sets the base URL.
 * @param[in]  rendition The input rendition object.
 * @param[in]  szBaseURL The input base URL.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMediaBaseURL, (FPD_Rendition rendition,  FS_LPCSTR szBaseURL,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionCountMediaPlayers
 * @details Gets the count of media players of specified type.
 * @param[in]  rendition The input rendition object.
 * @param[in]  ePlayerType The input media player type.
 * @return   The count of media player of specified type.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionCountMediaPlayers, (FPD_Rendition rendition,  FPD_MediaPlayerType ePlayerType))

/**
 * @brief FPDRenditionGetMediaPlayer
 * @details Gets a media player.
 * @param[in]  rendition The input rendition object.
 * @param[in]  ePlayerType The input media player type.
 * @param[in]  index The zero-based index in the specified media player type.
 * @param[out]  outMediaPlayer A media player.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionGetMediaPlayer, (FPD_Rendition rendition,  FPD_MediaPlayerType ePlayerType,  FS_INT32 index,  FPD_MediaPlayer* outMediaPlayer))

/**
 * @brief FPDRenditionAddMediaPlayer
 * @details Adds a media player.
 * @param[in]  rendition The input rendition object.
 * @param[in]  ePlayerType The input media player type.
 * @param[in]  player The input media player.
 * @return   The current count of specified media player type.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionAddMediaPlayer, (FPD_Rendition rendition,  FPD_MediaPlayerType ePlayerType,  FPD_MediaPlayer player))

/**
 * @brief FPDRenditionRemoveMediaPlayer
 * @details Removes a media player.
 * @param[in]  rendition The input rendition object.
 * @param[in]  ePlayerType The input media player type.
 * @param[in]  player The media player to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionRemoveMediaPlayer, (FPD_Rendition rendition,  FPD_MediaPlayerType ePlayerType,  FPD_MediaPlayer player))

/**
 * @brief FPDRenditionGetVolumn
 * @details Gets the volume that specifies the desired volume level as a percentage of recorded volume level.
 * @param[in]  rendition The input rendition object.
 * @return   The volume
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetVolumn, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetVolumn
 * @details Sets the volume.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iVolumn The input volume.
 * @param[in]  eParamType The media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetVolumn, (FPD_Rendition rendition,  FS_INT32 iVolumn,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionIsControlBarVisible
 * @details Checks to display a player-specific controller user interface (for example, play/pause/stop controls) when playing.
 * @param[in]  rendition The input rendition object.
 * @return   <a>TRUE</a> for being visible, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionIsControlBarVisible, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionEnableControlBarVisible
 * @details Sets the control bar visibility flag.
 * @param[in]  rendition The input rendition object.
 * @param[in]  bVisible The input visibility flag of the control bar.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionEnableControlBarVisible, (FPD_Rendition rendition,  FS_BOOL bVisible,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFitStyle
 * @details Gets the fit style (manner) in which the player should treat a visual media 
	*            type that does not exactly fit the rectangle in which it plays.
 * @param[in]  rendition The input rendition object.
 * @return   The fit style (manner).
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetFitStyle, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetFitStyle
 * @details Sets the fit style.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iFitStyle The input fit style.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFitStyle, (FPD_Rendition rendition,  FS_INT32 iFitStyle,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetDuration
 * @details Gets the intrinsic duration.
 * @param[in]  rendition The input rendition object.
 * @return   The intrinsic duration.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetDuration, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetDuration
 * @details Sets the intrinsic duration.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iDuration The input intrinsic duration.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetDuration, (FPD_Rendition rendition,  FS_INT32 iDuration,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionAutoPlay
 * @details Checks whether the media should automatically play when activated.
 * @param[in]  rendition The input rendition object.
 * @return   <a>TRUE</a> for the media automatically playing when activated, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionAutoPlay, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionEnableAutoPlay
 * @details Sets the auto-play flag.
 * @param[in]  rendition The input rendition object.
 * @param[in]  bAuto The input auto-play flag.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionEnableAutoPlay, (FPD_Rendition rendition,  FS_BOOL bAuto,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionRepeatCount
 * @details Gets the repeat count.
 * @param[in]  rendition The input rendition object.
 * @return   The repeat count.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionRepeatCount, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetRepeatCount
 * @details Sets the repeat count.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iCount The input repeat count.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetRepeatCount, (FPD_Rendition rendition,  FS_INT32 iCount,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetWindowStatus
 * @details Gets the window status(type) that the media object should play in.
 * @param[in]  rendition The input rendition object.
 * @return   0: floating window; 1: full screen; 2: hidden window; 3: child window.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetWindowStatus, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetWindowStatus
 * @details Sets the window status.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iStatus The input window status.0: floating window; 1: full screen; 2: hidden window; 3: child window.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetWindowStatus, (FPD_Rendition rendition,  FS_INT32 iStatus,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetBackgroundColor
 * @details Gets the background color for the rectangle in which the media is being played.
 * @param[in]  rendition The input rendition object.
 * @return   The background color for the rectangle in which the media is being played.
 * @note 
 */
INTERFACE(FS_COLORREF, FPDRenditionGetBackgroundColor, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetBackgroundColor
 * @details Sets the background color.
 * @param[in]  rendition The input rendition object.
 * @param[in]  color The input background color.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetBackgroundColor, (FPD_Rendition rendition,  FS_COLORREF color,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetBackgroundOpacity
 * @details Gets the background opacity.
 * @param[in]  rendition The input rendition object.
 * @return   The background opacity.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDRenditionGetBackgroundOpacity, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetBackgroundOpacity
 * @details Sets the background opacity.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iOpacity The input background opacity.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetBackgroundOpacity, (FPD_Rendition rendition,  FS_FLOAT iOpacity,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetMonitor
 * @details Gets the monitor specifier that specifies which monitor in a multi-monitor 
	*            system a floating or full-screen window should appear on.
 * @param[in]  rendition The input rendition object.
 * @return   The monitor specifier
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetMonitor, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetMonitor
 * @details Sets the monitor specifier.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iMonitor The input monitor specifier.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetMonitor, (FPD_Rendition rendition,  FS_INT32 iMonitor,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowSize
 * @details Gets the floating window's width and height.
 * @param[in]  rendition The input rendition object.
 * @param[out]  iWidth It receives the floating window's width.
 * @param[out]  iHeight It receives the floating window's height.
 * @return   <a>TRUE</a>: returned size is available; <a>FALSE</a>: not available.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionGetFloatingWindowSize, (FPD_Rendition rendition,  FS_INT32* iWidth,  FS_INT32* iHeight))

/**
 * @brief FPDRenditionSetFloatingWindowSize
 * @details Sets the floating window's width and height.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iWidth The width of the floating window.
 * @param[in]  iHeight The height of the floating window.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowSize, (FPD_Rendition rendition,  FS_INT32 iWidth,  FS_INT32 iHeight,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowRelativeType
 * @details Gets the window type relative to which the floating window should be positioned.
 * @param[in]  rendition The input rendition object.
 * @return   0: document window; 1: application window; 2: full virtual desktop; 3: monitor screen.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetFloatingWindowRelativeType, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetFloatingWindowRelativeType
 * @details Sets the window relative type.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iType The input window relative type. 0: document window; 1: application window; 2: full virtual desktop; 3: monitor screen.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowRelativeType, (FPD_Rendition rendition,  FS_INT32 iType,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowPosition
 * @details Gets the floating window position.
 * @param[in]  rendition The input rendition object.
 * @return   0: upper left; 1: upper center; 2: upper right; 3: center left; 4: center; 5: center right; 6: lower left; 7: lower center; 8: lower right.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetFloatingWindowPosition, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetFloatingWindowPosition
 * @details Sets the floating window position.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iPosition The input floating window position. 0: upper left; 1: upper center; 2: upper right; 3: center left; 4: center; 5: center right; 6: lower left; 7: lower center; 8: lower right.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowPosition, (FPD_Rendition rendition,  FS_INT32 iPosition,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowOffscreen
 * @details Gets what should occur if the floating window is positioned totally or partially off screen.
 * @param[in]  rendition The input rendition object.
 * @return   0: nothing; 1: move or resize; 2: consider the object non-viable.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetFloatingWindowOffscreen, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetFloatingWindowOffscreen
 * @details Sets the action Function.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iOffscreen The input action Function.0: nothing; 1: move or resize; 2: consider the object non-viable.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowOffscreen, (FPD_Rendition rendition,  FS_INT32 iOffscreen,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionHasFloatingWindowTitleBar
 * @details Checks whether the floating window should have a title bar.
 * @param[in]  rendition The input rendition object.
 * @return   <a>TRUE</a> for the floating window having a title bar.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionHasFloatingWindowTitleBar, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionEnableFloatingWindowTitleBar
 * @details Sets the title bar visibility flag.
 * @param[in]  rendition The input rendition object.
 * @param[in]  bVisible The input visibility flag.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionEnableFloatingWindowTitleBar, (FPD_Rendition rendition,  FS_BOOL bVisible,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionHasFloatingWindowCloseButton
 * @details Checks whether the floating window should include user interface elements that allow a user to close a floating window.
 * @param[in]  rendition The input rendition object.
 * @return   <a>TRUE</a> for the floating window including user interface elements, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionHasFloatingWindowCloseButton, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionEnableFloatingWindowCloseButton
 * @details Sets the visibility flag of close-button.
 * @param[in]  rendition The input rendition object.
 * @param[in]  bVisible The input visibility flag.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionEnableFloatingWindowCloseButton, (FPD_Rendition rendition,  FS_BOOL bVisible,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowResizeType
 * @details Checks whether the floating window may be resized by a user.
 * @param[in]  rendition The input rendition object.
 * @return   0: may not be resized; 1: resize with aspect ratio; 2: resize anyway.
 * @note 
 */
INTERFACE(FS_INT32, FPDRenditionGetFloatingWindowResizeType, (FPD_Rendition rendition))

/**
 * @brief FPDRenditionSetFloatingWindowResizeType
 * @details Sets the floating window resizing type.
 * @param[in]  rendition The input rendition object.
 * @param[in]  iType The input floating window resizing type. 0: may not be resized; 1: resize with aspect ratio; 2: resize anyway.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowResizeType, (FPD_Rendition rendition,  FS_INT32 iType,  FPD_MediaPlayParamType eParamType))

/**
 * @brief FPDRenditionGetFloatingWindowTitle
 * @details Gets the multi-language text array providing text to display on the floating window's title bar.
 * @param[in]  rendition The input rendition object.
 * @param[out]  outTitleArray It receives the multi-language text array.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDRenditionGetFloatingWindowTitle, (FPD_Rendition rendition,  FS_WideStringArray* outTitleArray))

/**
 * @brief FPDRenditionSetFloatingWindowTitle
 * @details Sets the multi-language text array to provide text for title bar.
 * @param[in]  rendition The input rendition object.
 * @param[in]  titleArray The input multi-language text array.
 * @param[in]  eParamType The input media play param type.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDRenditionSetFloatingWindowTitle, (FPD_Rendition rendition,  FS_WideStringArray titleArray,  FPD_MediaPlayParamType eParamType))

NumOfSelector(FPDRendition)
ENDENUM

//*****************************
/* Link HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDLinkNew
 * @details Creates a PDF link from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   A PDF link.
 * @note 
 */
INTERFACE(FPD_Link, FPDLinkNew, (FPD_Object dict))

/**
 * @brief FPDLinkDestroy
 * @details Destroys a PDF link.
 * @param[in]  link The input PDF link.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkDestroy, (FPD_Link link))

/**
 * @brief FPDLinkGetLinkAtPoint
 * @details Gets the link at specified point. The point is specified in user space. 
	*            <a>NULL</a> for no link at that point.
 * @param[in]  doc The input PDF document.
 * @param[in]  page The input PDF page.
 * @param[in]  x The input x-coordinate of the point.
 * @param[in]  y The input y-coordinate of the point.
 * @param[out]  outLink It receives the link at specified point.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkGetLinkAtPoint, (FPD_Document doc,  FPD_Page page,  FS_FLOAT x,  FS_FLOAT y,  FPD_Link* outLink))

/**
 * @brief FPDLinkCountLinks
 * @details Gets the count of links in specified page.
 * @param[in]  doc The input PDF document.
 * @param[in]  page The input PDF page.
 * @return   The count of links in the page.
 * @note 
 */
INTERFACE(FS_INT32, FPDLinkCountLinks, (FPD_Document doc,  FPD_Page page))

/**
 * @brief FPDLinkGetLink
 * @details Gets a PDF link.
 * @param[in]  doc The input PDF document.
 * @param[in]  page The input PDF page.
 * @param[in]  index The zero-based link index int the page.
 * @param[out]  outLink It receives the link by index.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkGetLink, (FPD_Document doc,  FPD_Page page,  FS_INT32 index,  FPD_Link* outLink))

/**
 * @brief FPDLinkGetRect
 * @details Gets the rectangle in which the link should be activated.
 * @param[in]  link The input link.
 * @return   The rectangle in which the link should be activated.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDLinkGetRect, (FPD_Link link))

/**
 * @brief FPDLinkGetDest
 * @details Gets the destination of the link.
 * @param[in]  link The input PDF link.
 * @param[in]  doc The input PDF document.
 * @param[out]  outDest The destination of the link.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkGetDest, (FPD_Link link,  FPD_Document doc,  FPD_Dest* outDest))

/**
 * @brief FPDLinkGetAction
 * @details Gets the action of the link.
 * @param[in]  link The input PDF link.
 * @param[out]  outAction The action of the link.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDLinkGetAction, (FPD_Link link,  FPD_Action* outAction))

NumOfSelector(FPDLink)
ENDENUM

//*****************************
/* Annot HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDAnnotNew
 * @details Creates an annotation from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   An annotation.
 * @note 
 */
INTERFACE(FPD_Annot, FPDAnnotNew, (FPD_Object dict))

/**
 * @brief FPDAnnotDestroy
 * @details Destroys an annotation.
 * @param[in]  annot The input annotation.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotDestroy, (FPD_Annot annot))

/**
 * @brief FPDAnnotGetAnnotDict
 * @details Gets the annotation dictionary. We store all information within the original annotation dictionary.
 * @param[in]  annot The input annotation.
 * @return   The annotation dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDAnnotGetAnnotDict, (FPD_Annot annot))

/**
 * @brief FPDAnnotGetSubType
 * @details Gets the annotation type name.
 * @param[in]  annot The input annotation.
 * @param[out]  outSubType It receives the annotation type name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotGetSubType, (FPD_Annot annot,  FS_ByteString* outSubType))

/**
 * @brief FPDAnnotGetFlags
 * @details Gets the annotation flags.
 * @param[in]  annot The input annotation.
 * @return   The annotation flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDAnnotGetFlags, (FPD_Annot annot))

/**
 * @brief FPDAnnotGetRect
 * @details Gets annotation bounding box in user space.
 * @param[in]  annot The input annotation.
 * @return   The bounding box of the annotation.
 * @note 
 */
INTERFACE(FS_FloatRect, FPDAnnotGetRect, (FPD_Annot annot))

/**
 * @brief FPDAnnotDrawAppearance
 * @details Draws annotation's appearance, using default appearance rules.
 * @param[in]  annot The input annotation.
 * @param[in]  page The page it belongs to.
 * @param[in]  dc The device to draw on.
 * @param[in]  matrix The transformation matrix from user space to device space.
 * @param[in]  eMode The input appearance mode.
 * @param[in]  opts The render options.
 * @return   <a>TRUE</a> if the appearance successfully found and drawn.
 * @note 
 */
INTERFACE(FS_BOOL, FPDAnnotDrawAppearance, (FPD_Annot annot,  const FPD_Page page,  FPD_RenderDevice dc,  FS_AffineMatrix matrix,  FPD_AnnotAppearanceMode eMode,  const FPD_RenderOptions opts))

/**
 * @brief FPDAnnotDrawInContext
 * @details Draws annotation's appearance in rendering context.
 * @param[in]  annot The input annotation.
 * @param[in]  page The page it belongs to.
 * @param[in]  context The context to draw in.
 * @param[in]  matrix The transformation matrix from user space to device space.
 * @param[in]  eMode The input appearance mode.
 * @return   <a>TRUE</a> if the appearance successfully found and drawn.
 * @note 
 */
INTERFACE(FS_BOOL, FPDAnnotDrawInContext, (FPD_Annot annot,  const FPD_Page page,  const FPD_RenderContext context,  FS_AffineMatrix matrix,  FPD_AnnotAppearanceMode eMode))

/**
 * @brief FPDAnnotClearCachedAP
 * @details Clears all cached appearance, when the application changed any appearance settings.
 * @param[in]  annot The input annotation.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotClearCachedAP, (FPD_Annot annot))

/**
 * @brief FPDAnnotDrawBorder
 * @details Draws border of the annotation, using border settings within the dictionary.
 * @param[in]  annot The input annotation.
 * @param[in]  dc The device to draw on.
 * @param[in]  matrix The transformation matrix from user space to device space.
 * @param[in]  opts The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotDrawBorder, (FPD_Annot annot,  FPD_RenderDevice dc,  FS_AffineMatrix matrix,  const FPD_RenderOptions opts))

/**
 * @brief FPDAnnotCountIRTNotes
 * @details Gets the count of annotations in "in reply to" annotation list.
 * @param[in]  annot The input annotation.
 * @return   The count of annotations in "in reply to" annotation list.
 * @note 
 */
INTERFACE(FS_INT32, FPDAnnotCountIRTNotes, (FPD_Annot annot))

/**
 * @brief FPDAnnotGetIRTNote
 * @details Gets an "in reply to" annotation.
 * @param[in]  annot The input annotation.
 * @param[in]  index The zero-based index in the "in reply to" annotation list.
 * @return   An "in reply to" annotation.
 * @note 
 */
INTERFACE(FPD_Annot, FPDAnnotGetIRTNote, (FPD_Annot annot,  FS_INT32 index))

/**
 * @brief FPDAnnotGetAPForm
 * @details Gets an appearance stream.
 * @param[in]  annot The input annotation.
 * @param[in]  page The page it belongs to.
 * @param[in]  eMode The input appearance mode.
 * @return   A PDF form.
 * @note 
 */
INTERFACE(FPD_Form, FPDAnnotGetAPForm, (FPD_Annot annot,  const FPD_Page page,  FPD_AnnotAppearanceMode eMode))

NumOfSelector(FPDAnnot)
ENDENUM

//*****************************
/* AnnotList HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDAnnotListNew
 * @details Creates an annotation list from a PDF page.
 * @param[in]  page The input PDF page.
 * @return   An annotation list.
 * @note 
 */
INTERFACE(FPD_AnnotList, FPDAnnotListNew, (FPD_Page page))

/**
 * @brief FPDAnnotListDestroy
 * @details Destroys an annotation list.
 * @param[in]  annotList The input annotation list.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListDestroy, (FPD_AnnotList annotList))

/**
 * @brief FPDAnnotListDisplayAnnots
 * @details Display all annotations with specified object to DC transformation.
 * @param[in]  annotList The input annotation list.
 * @param[in]  page The page it belongs to.
 * @param[in]  dc The device to draw on.
 * @param[in]  matrix The transformation matrix from objects space to device space.
 * @param[in]  bShowWidget Whether to show widget or not.
 * @param[in]  opts The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListDisplayAnnots, (FPD_AnnotList annotList,  const FPD_Page page,  FPD_RenderDevice dc,  FS_AffineMatrix matrix,  FS_BOOL bShowWidget,  FPD_RenderOptions opts))

/**
 * @brief FPDAnnotListDisplayAnnotsEx
 * @details Adds annotations to render job list, used in printing for transparency support.
 * @param[in]  annotList The input annotation list.
 * @param[in]  pPage The page it belongs to.
 * @param[in]  context The context to draw in.
 * @param[in]  bPrinting Whether to print or not.
 * @param[in]  matrix The transformation matrix from objects space to device space.
 * @param[in]  bShowWidget Whether to show widget or not.
 * @param[in]  opts The render options.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListDisplayAnnotsEx, (FPD_AnnotList annotList,  const FPD_Page pPage,  FPD_RenderContext context,  FS_BOOL bPrinting,  FS_AffineMatrix matrix,  FS_BOOL bShowWidget,  FPD_RenderOptions opts))

/**
 * @brief FPDAnnotListGetAt
 * @details Gets an annotation at specified position.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index in the annotation list.
 * @return   An annotation.
 * @note 
 */
INTERFACE(FPD_Annot, FPDAnnotListGetAt, (FPD_AnnotList annotList,  FS_INT32 index))

/**
 * @brief FPDAnnotListCount
 * @details Gets the count of annotations in the annotation list.
 * @param[in]  annotList The input annotation list.
 * @return   The count of annotations in the annotation list.
 * @note 
 */
INTERFACE(FS_INT32, FPDAnnotListCount, (FPD_AnnotList annotList))

/**
 * @brief FPDAnnotListGetIndex
 * @details Gets the annotation's index.
 * @param[in]  annotList The input annotation list.
 * @param[in]  annot The input annotation.
 * @return   The zero-based index in the annotation list.
 * @note 
 */
INTERFACE(FS_INT32, FPDAnnotListGetIndex, (FPD_AnnotList annotList,  FPD_Annot annot))

/**
 * @brief FPDAnnotListRemoveAll
 * @details Removes all the annotations.
 * @param[in]  annotList The input annotation list.
 * @return   void
 * @note Operations to the annotation list will be reflected in the PDF document structure.
	*            For example, the "Annots" array of page dictionary will get changed.
 */
INTERFACE(void, FPDAnnotListRemoveAll, (FPD_AnnotList annotList))

/**
 * @brief FPDAnnotListReplace
 * @details Replaces the specified position with a new annotation.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index in the annotation list.
 * @param[in]  annot The new annotation.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListReplace, (FPD_AnnotList annotList,  FS_INT32 index,  FPD_Annot annot))

/**
 * @brief FPDAnnotListInsert
 * @details Inserts BEFORE the index, if index equals to current count, then append.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index to insert before.
 * @param[in]  annot The annotation to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListInsert, (FPD_AnnotList annotList,  FS_INT32 index,  FPD_Annot annot))

/**
 * @brief FPDAnnotListRemove
 * @details Removes an annotation.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index of the annotation to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListRemove, (FPD_AnnotList annotList,  FS_INT32 index))

/**
 * @brief FPDAnnotListRemoveTemp
 * @details Removes from list only, not from page.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index of the annotation to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListRemoveTemp, (FPD_AnnotList annotList,  FS_INT32 index))

/**
 * @brief FPDAnnotListMoveToFirst
 * @details Moves an annotation to the first of the annotation list.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index of the annotation to be moved.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListMoveToFirst, (FPD_AnnotList annotList,  FS_INT32 index))

/**
 * @brief FPDAnnotListMoveToLast
 * @details Moves an annotation to the last of the annotation list.
 * @param[in]  annotList The input annotation list.
 * @param[in]  index The zero-based index of the annotation to be moved.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListMoveToLast, (FPD_AnnotList annotList,  FS_INT32 index))

/**
 * @brief FPDAnnotListMoveTo
 * @details Moves an annotation to specified position.
 * @param[in]  annotList The input annotation list.
 * @param[in]  annot The annotation to be moved.
 * @param[in]  iNewIndex The new position to move to.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDAnnotListMoveTo, (FPD_AnnotList annotList,  FPD_Annot annot,  FS_INT32 iNewIndex))

/**
 * @brief FPDAnnotListGetDocument
 * @details Gets the PDF document.
 * @param[in]  annotList The input annotation list.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDAnnotListGetDocument, (FPD_AnnotList annotList))

/**
 * @brief FPDAnnotListSetFixedIconParams
 * @details Enable to show icon annotations as fixed size (NoZoom or NoRotate flag).
 * @param[in]  annotList The input annotation list.
 * @param[in]  nFixedIconType Indicates how to display fixed annotations.
	* 0 is to show as normal annotations, ignore NoZoom or NoRotate flag,
	* and 1 is to show as fixed scaling size, <param>sx</param> and <param>sy</param> specifies scaling fractors in x and y axes,
	* and 2 is to show as fixed device size which is specified by <param>sx</param> and <param>sy</param> in device units.
 * @param[in]  sx Fixed scaling size or fixed device size according to the value of <param>nFixedIconType</param> in x axis.
 * @param[in]  sy Fixed scaling size or fixed device size according to the value of <param>nFixedIconType</param> in y axis.
 * @param[in]  nRotate Page rotation, valid values are 0, 1, 2, 3, same as <a>FPDPageGetDisplayMatrix</a>.
 * @return   The PDF document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FPDAnnotListSetFixedIconParams, (FPD_AnnotList annotList,  FS_INT32 nFixedIconType,  FS_FLOAT sx,  FS_FLOAT sy,  FS_INT32 nRotate))

/**
 * @brief FPDAnnotListGetAnnotMatrix
 * @details Gets annotation transformation matrix from page space to device space.
 * @param[in]  annotList The input annotation list.
 * @param[in]  pAnnotDict Annotation's dictionary object.
 * @param[in]  pUser2Device Current displaying transformation matrix.
 * @param[out]  outMatrix Annotation matrix to display.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FPDAnnotListGetAnnotMatrix, (FPD_AnnotList annotList,  FPD_Object pAnnotDict,  FS_AffineMatrix pUser2Device,  FS_AffineMatrix* outMatrix))

/**
 * @brief FPDAnnotListGetAnnotRect
 * @details Gets annotation rectangle in device coordinates.
 * @param[in]  annotList The input annotation list.
 * @param[in]  pAnnotDict Annotation's dictionary object.
 * @param[in]  pUser2Device Transformation matrix from user space to device space.
 * @param[out]  outAnnotRC Annotation rectangle in device coordinates.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1.0.0
 */
INTERFACE(void, FPDAnnotListGetAnnotRect, (FPD_AnnotList annotList,  FPD_Object pAnnotDict,  FS_AffineMatrix pUser2Device,  FS_FloatRect* outAnnotRC))

NumOfSelector(FPDAnnotList)
ENDENUM

//*****************************
/* DefaultAppearance HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDDefaultAppearanceNew
 * @details Creates from a default appearance string that containing a sequence of valid 
    *            page-content graphics or text state operators that define such properties as the field's 
	*            text size and color.
 * @param[in]  szAppearance The input default appearance string.
 * @return   Default appearance interpreter, serves for DA entry in form field dictionary.
 * @note 
 */
INTERFACE(FPD_DefaultAppearance, FPDDefaultAppearanceNew, (FS_LPCSTR szAppearance))

/**
 * @brief FPDDefaultAppearanceDestroy
 * @details Destroys default appearance interpreter.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceDestroy, (FPD_DefaultAppearance defAppearance))

/**
 * @brief FPDDefaultAppearanceHasFont
 * @details Checks whether a font has been used in the appearance.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @return   <a>TRUE</a> for a font having been used in the appearance, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDefaultAppearanceHasFont, (FPD_DefaultAppearance defAppearance))

/**
 * @brief FPDDefaultAppearanceGetFontString
 * @details Gets the font instruction in the appearance string.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[out]  outFontString It receives the font instruction in the appearance string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetFontString, (FPD_DefaultAppearance defAppearance,  FS_ByteString* outFontString))

/**
 * @brief FPDDefaultAppearanceGetFont
 * @details Gets the font.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[out]  outFontNameTag It receives font name tag of font.
 * @param[out]  outFontSize It receives the font size of the font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetFont, (FPD_DefaultAppearance defAppearance,  FS_ByteString* outFontNameTag,  FS_FLOAT* outFontSize))

/**
 * @brief FPDDefaultAppearanceSetFont
 * @details Sets the font name tag and size of the font.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[in]  szFontNameTag The font name tag of the font.
 * @param[in]  fFontSize The size of the font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceSetFont, (FPD_DefaultAppearance defAppearance,  FS_LPSTR szFontNameTag,  FS_FLOAT fFontSize))

/**
 * @brief FPDDefaultAppearanceHasColor
 * @details Checks whether a color has been used in the appearance.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[in]  bStrokingOperation Whether the stroking color to be checked.
 * @return   Non-zero means having one, otherwise having none.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDefaultAppearanceHasColor, (FPD_DefaultAppearance defAppearance,  FS_BOOL bStrokingOperation))

/**
 * @brief FPDDefaultAppearanceGetColorString
 * @details Gets the color instruction in the appearance string.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[in]  bStrokingOperation Whether the stroking color instruction to be fetched.
 * @param[out]  outColorString The color instruction in the appearance string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetColorString, (FPD_DefaultAppearance defAppearance,  FS_BOOL bStrokingOperation,  FS_ByteString* outColorString))

/**
 * @brief FPDDefaultAppearanceGetColorInclueCMYK
 * @details Gets the color (including CMYK).
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[out]  pIclrType It receives the color type.
 * @param[out]  fc[4] It receives the color values of components.
 * @param[in]  bStrokingOperation Whether the stroking color to be fetched.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetColorInclueCMYK, (FPD_DefaultAppearance defAppearance,  FS_INT32* pIclrType,  FS_FLOAT fc[4],  FS_BOOL bStrokingOperation))

/**
 * @brief FPDDefaultAppearanceGetColor
 * @details Gets the color (not including CMYK).
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[out]  pClr It receives the color.
 * @param[out]  pIclrType It receives the color type.
 * @param[in]  bStrokingOperation Whether the stroking color to be fetched.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetColor, (FPD_DefaultAppearance defAppearance,  FS_ARGB* pClr,  FS_INT32* pIclrType,  FS_BOOL bStrokingOperation))

/**
 * @brief FPDDefaultAppearanceSetColor
 * @details Sets the color.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[in]  clr The input color.
 * @param[in]  iClrType The input color type.
 * @param[in]  bStrokingOperation Whether the stroking color to be set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceSetColor, (FPD_DefaultAppearance defAppearance,  FS_ARGB clr,  FS_INT32 iClrType,  FS_BOOL bStrokingOperation))

/**
 * @brief FPDDefaultAppearanceHasTextMatrix
 * @details Checks whether a text matrix has been used in the appearance.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @return   <a>TRUE</a> for a text matrix having been used in the appearance, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDDefaultAppearanceHasTextMatrix, (FPD_DefaultAppearance defAppearance))

/**
 * @brief FPDDefaultAppearanceGetTextMatrixString
 * @details Gets the text matrix instruction in the appearance string.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[out]  outMatrixString It receives the text matrix instruction in the appearance string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceGetTextMatrixString, (FPD_DefaultAppearance defAppearance,  FS_ByteString* outMatrixString))

/**
 * @brief FPDDefaultAppearanceGetTextMatrix
 * @details Gets the text matrix.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @return   The text matrix.
 * @note 
 */
INTERFACE(FS_AffineMatrix, FPDDefaultAppearanceGetTextMatrix, (FPD_DefaultAppearance defAppearance))

/**
 * @brief FPDDefaultAppearanceSetTextMatrix
 * @details Sets the text matrix.
 * @param[in]  defAppearance The input default appearance interpreter.
 * @param[in]  matrix The input text matrix.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDDefaultAppearanceSetTextMatrix, (FPD_DefaultAppearance defAppearance,  FS_AffineMatrix matrix))

NumOfSelector(FPDDefaultAppearance)
ENDENUM

//*****************************
/* FormNotify HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFormNotifyNew
 * @details Creates a form notify object.
	* See: FPDInterFormGetFormNotify
	* See: FPDInterFormSetFormNotify
	* See: FPDFormNotifyDestroy
 * @param[in]  callbacks The callback set.
 * @return   A newly form notify object.
 * @note 
 */
INTERFACE(FPD_FormNotify, FPDFormNotifyNew, (FPD_FormNotifyCallbacks callbacks))

/**
 * @brief FPDFormNotifyDestroy
 * @details Destroys a form notify object.
 * @param[in]  formNotify The <a>FPD_FormNotify</a> object to be destroied.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormNotifyDestroy, (FPD_FormNotify formNotify))

NumOfSelector(FPDFormNotify)
ENDENUM

//*****************************
/* InterForm HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDInterFormNew
 * @details Creates a form from a document. The bUpdateAP param specifies whether we need to 
	*            regenerate appearance streams for the fields.
 * @param[in]  doc The PDF document.
 * @param[in]  bUpdateAP Whether we need to regenerate appearance streams for fields.
 * @return   A PDF interactive form.
 * @note 
 */
INTERFACE(FPD_InterForm, FPDInterFormNew, (FPD_Document doc,  FS_BOOL bUpdateAP))

/**
 * @brief FPDInterFormDestroy
 * @details Destroys a PDF interactive form.
 * @param[in]  form The input PDF interactive form.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormDestroy, (FPD_InterForm form))

/**
 * @brief FPDInterFormEnableUpdateAP
 * @details Change the auto-update-appearance flag.
 * @param[in]  bUpdateAP the input auto-update-appearance flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormEnableUpdateAP, (FS_BOOL bUpdateAP))

/**
 * @brief FPDInterFormUpdatingAPEnabled
 * @details Checks whether need to update appearance automatically.
 * @param[in]  void 
 * @return   <a>TRUE</a> for needing to update appearance automatically.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormUpdatingAPEnabled, (void))

/**
 * @brief FPDInterFormGenerateNewResourceName
 * @details Generate a new resource tag name, especially for ExtGState, ColorSpace, Font, etc.
 * @param[in]  resDict An existing resource dictionary.
 * @param[in]  csType Specifies resource type to generate a new name string, currently,
	*							it can be ExtGState, ColorSpace, Font, any other is no sense.
 * @param[in]  iMinLen The minimum length of the resource name.
 * @param[in]  csPrefix A prefix string to add in the head of he new resource name.
 * @param[out]  outName A resource tag name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormGenerateNewResourceName, (const FPD_Object resDict,  FS_LPCSTR csType,  FS_INT32 iMinLen,  FS_LPSTR csPrefix,  FS_ByteString* outName))

/**
 * @brief FPDInterFormAddSystemDefaultFont
 * @details Adds the system default font.
 * @param[in]  doc The PDF document.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddSystemDefaultFont, (const FPD_Document doc))

/**
 * @brief FPDInterFormAddSystemFont
 * @details Adds a system font with font name and character set. ANSI version.
 * @param[in]  doc The PDF document.
 * @param[in]  szFontName The input font name.
 * @param[in]  iCharSet The input character set.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddSystemFont, (const FPD_Document doc,  FS_LPSTR szFontName,  FS_BYTE iCharSet))

/**
 * @brief FPDInterFormAddSystemFontW
 * @details Adds a system font with font name and character set. Unicode version.
 * @param[in]  doc The PDF document.
 * @param[in]  wszFontName he input font name.
 * @param[in]  iCharSet The input character set.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddSystemFontW, (const FPD_Document doc,  FS_LPWSTR wszFontName,  FS_BYTE iCharSet))

/**
 * @brief FPDInterFormAddStandardFont
 * @details Adds a standard font with font name.
 * @param[in]  doc The PDF document.
 * @param[in]  szFontName The input font name.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddStandardFont, (const FPD_Document doc,  FS_LPSTR szFontName))

/**
 * @brief FPDInterFormGetNativeFont
 * @details Gets the native font name with a character set and a logical font structure.
 * @param[in]  iCharSet The input character set.
 * @param[out]  pLogFont It receives the font information. Points to LOGFONTA structure.
 * @param[out]  outFont The font name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormGetNativeFont, (FS_BYTE iCharSet,  FS_LPVOID pLogFont,  FS_ByteString* outFont))

/**
 * @brief FPDInterFormGetNativeFont2
 * @details Gets the native font name with a logical font structure.
 * @param[out]  pLogFont It receives the font information. Points to LOGFONTA structure.
 * @param[out]  outFont The font name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormGetNativeFont2, (FS_LPVOID pLogFont,  FS_ByteString* outFont))

/**
 * @brief FPDInterFormAddNativeFont
 * @details Adds a native font with a character set.
 * @param[in]  iCharSet The input character set.
 * @param[in]  doc The PDF document.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddNativeFont, (FS_BYTE iCharSet,  const FPD_Document doc))

/**
 * @brief FPDInterFormAddNativeFont2
 * @details Adds the native font of the PDF document.
 * @param[in]  doc The PDF document.
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddNativeFont2, (const FPD_Document doc))

/**
 * @brief FPDInterFormValidateFieldName
 * @details Checks the field name of specified type is valid or not, receives the valid field name when it's invalid.
 * @param[in]  form The input PDF interactive form.
 * @param[in,out]  inOutNewFieldName Input a field name and receives the valid field name.
 * @param[in]  iType The field type. uses FPD_FORM_FIELDTYPE_X macros.
 * @return   Non-zero means the input field name is valid, otherwise invalid.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormValidateFieldName, (FPD_InterForm form,  FS_WideString* inOutNewFieldName,  FS_INT32 iType))

/**
 * @brief FPDInterFormValidateFieldName2
 * @details Checks the field name for the input field is valid or not, receives the valid field name when it's invalid.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input field.
 * @param[in,out]  inOutNewFieldName Input a field name and receives the valid field name.
 * @return   Non-zero means the input field name is valid, otherwise invalid.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormValidateFieldName2, (FPD_InterForm form,  const FPD_FormField field,  FS_WideString* inOutNewFieldName))

/**
 * @brief FPDInterFormValidateFieldName3
 * @details Checks the field name for the input control is valid or not, receives the valid field name when it's invalid.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  control The input control.
 * @param[in,out]  inOutNewFieldName Input a field name and receives the valid field name.
 * @return   Non-zero means the input field name is valid, otherwise invalid.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormValidateFieldName3, (FPD_InterForm form,  const FPD_FormControl control,  FS_WideString* inOutNewFieldName))

/**
 * @brief FPDInterFormNewField
 * @details Creates and add a field in form, param iType uses FPD_FORM_FIELDTYPE_X macros.
	*            inOutFieldName is in/out param. If succeed, csFieldName is the validated field full name.
 * @param[in]  form The input PDF interactive form.
 * @param[in,out]  inOutFieldName Input a field name and receives the valid field full name.
 * @param[in]  iType The input field type.
 * @return   A form field.
 * @note 
 */
INTERFACE(FPD_FormField, FPDInterFormNewField, (FPD_InterForm form,  FS_WideString* inOutFieldName,  FS_INT32 iType))

/**
 * @brief FPDInterFormNewControl
 * @details Creates and add a control in form, param iType uses FPD_FORM_FIELDTYPE_X macros.
	*            inOutFieldName is in/out param. If succeed, inOutFieldName is the validated field full name.
 * @param[in]  form The input PDF interactive form.
 * @param[in,out]  inOutFieldName Input a field name and receives the valid field full name.
 * @param[in]  iType The input field type.
 * @return   A form control.
 * @note This Function will call NewField if necessary.
	*            Use this Function to create a control and use returned object to initialize Widget.
 */
INTERFACE(FPD_FormControl, FPDInterFormNewControl, (FPD_InterForm form,  FS_WideString* inOutFieldName,  FS_INT32 iType))

/**
 * @brief FPDInterFormCountFields
 * @details Gets the count of specified fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszFieldName The input field name to be matched.
	*  -empty means for all fields; or system will match the field name.
	*  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
 * @return   The count of fields with specified field name to be matched.
 * @note 
 */
INTERFACE(FS_DWORD, FPDInterFormCountFields, (FPD_InterForm form,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormGetField
 * @details Gets a form field.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  index The zero-based field index in the matched field array.
 * @param[in]  wszFieldName The field name to be matched.
	*  -empty means for all fields; or system will match the field name.
	*  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
 * @return   A form field.
 * @note 
 */
INTERFACE(FPD_FormField, FPDInterFormGetField, (FPD_InterForm form,  FS_DWORD index,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormGetAllFieldNames
 * @details Gets all field names in the form.
 * @param[in]  form The input PDF interactive form.
 * @param[out]  outAllFieldNames It receives all field names in the form.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormGetAllFieldNames, (FPD_InterForm form,  FS_WideStringArray* outAllFieldNames))

/**
 * @brief FPDInterFormIsValidFormField
 * @details Checks whether a pointer is a form field pointer.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  pField The input pointer.
 * @return   Non-zero means it's a form field pointer, otherwise is not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormIsValidFormField, (FPD_InterForm form,  const void* pField))

/**
 * @brief FPDInterFormGetFieldByDict
 * @details Retrieves the field by field dictionary.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  fieldDict The input form field dictionary.
 * @return   A form field.
 * @note 
 */
INTERFACE(FPD_FormField, FPDInterFormGetFieldByDict, (FPD_InterForm form,  FPD_Object fieldDict))

/**
 * @brief FPDInterFormCountControls
 * @details Gets the count of specified controls.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszFieldName The input field name to be matched.
	*  -empty means for all fields; or system will match the field name.
	*  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
 * @return   The count of controls with specified field name to be matched.
 * @note 
 */
INTERFACE(FS_DWORD, FPDInterFormCountControls, (FPD_InterForm form,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormGetControl
 * @details Gets a form control.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  index The zero-based control index in the matched control array.
 * @param[in]  wszFieldName The field name to be matched.
	*  -empty means for all fields; or system will match the field name.
	*  -as shortest string, for example, text1 will match text1.0, text1.2.0, etc. but text1 will not match test10 or test11.1..
 * @return   A form control.
 * @note 
 */
INTERFACE(FPD_FormControl, FPDInterFormGetControl, (FPD_InterForm form,  FS_DWORD index,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormIsValidFormControl
 * @details Checks whether a pointer is a form control pointer.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  pControl The input pointer.
 * @return   Non-zero means it's a form control pointer, otherwise is not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormIsValidFormControl, (FPD_InterForm form,  const void* pControl))

/**
 * @brief FPDInterFormCountPageControls
 * @details Gets the count of controls in specified page.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  page The input PDF page.
 * @return   The count of controls in specified page.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormCountPageControls, (FPD_InterForm form,  FPD_Page page))

/**
 * @brief FPDInterFormGetPageControl
 * @details Gets a control in specified page.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  page The input PDF page.
 * @param[in]  index The zero-based control index in the page.
 * @return   A control int the page.
 * @note 
 */
INTERFACE(FPD_FormControl, FPDInterFormGetPageControl, (FPD_InterForm form,  FPD_Page page,  FS_INT32 index))

/**
 * @brief FPDInterFormGetControlAtPoint
 * @details Retrieves the control by mouse position.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  page The input PDF page.
 * @param[in]  pdfX The x-coordinate of mouse position in user space.
 * @param[in]  pdfY The y-coordinate of mouse position in user space.
 * @return   A control.
 * @note 
 */
INTERFACE(FPD_FormControl, FPDInterFormGetControlAtPoint, (FPD_InterForm form,  FPD_Page page,  FS_FLOAT pdfX,  FS_FLOAT pdfY))

/**
 * @brief FPDInterFormGetControlByDict
 * @details Retrieves the control by widget dictionary.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  widgetDict The input widget dictionary.
 * @return   A control.
 * @note 
 */
INTERFACE(FPD_FormControl, FPDInterFormGetControlByDict, (FPD_InterForm form,  FPD_Object widgetDict))

/**
 * @brief FPDInterFormRenameField
 * @details Rename a field's full name. The field identified by it's old full name.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszOldName The field's old name.
 * @param[in,out]  inOutNewName Input the field's new name and receive the validated field full name, if success.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormRenameField, (FPD_InterForm form,  FS_LPWSTR wszOldName,  FS_WideString* inOutNewName))

/**
 * @brief FPDInterFormRenameField2
 * @details Rename a field's full name.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input field.
 * @param[in,out]  inOutNewName Input the field's new name and receive the validated field full name.if success.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormRenameField2, (FPD_InterForm form,  FPD_FormField field,  FS_WideString* inOutNewName))

/**
 * @brief FPDInterFormRenameControl
 * @details Rename a control's full name.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  pControl The input control.
 * @param[in,out]  inOutNewName Input the control's new name and receive the validated control full name.if success.
 * @return   <a>TRUE</a> for success, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormRenameControl, (FPD_InterForm form,  FPD_FormControl pControl,  FS_WideString* inOutNewName))

/**
 * @brief FPDInterFormDeleteField
 * @details Deletes a field with specified field name.
	*            If csName is empty, means for all fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszFieldName The input field name.
 * @return   void
 * @note When delete fields, all controls assigned to them will be deleted too.
 */
INTERFACE(void, FPDInterFormDeleteField, (FPD_InterForm form,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormDeleteField2
 * @details Deletes a field.
	*            Field object will be deleted if success.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input field.
 * @return   void
 * @note When delete fields, all controls assigned to them will be deleted too.
 */
INTERFACE(void, FPDInterFormDeleteField2, (FPD_InterForm form,  FPD_FormField field))

/**
 * @brief FPDInterFormDeleteControl
 * @details Deletes a control.
	*            control object will be deleted if success.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  control The input control.
 * @return   void
 * @note When delete controls, corresponding fields will be deleted only when they have no any control associated
	*  with them. If csFieldName is empty, it means to all fields or controls.
 */
INTERFACE(void, FPDInterFormDeleteControl, (FPD_InterForm form,  FPD_FormControl control))

/**
 * @brief FPDInterFormCountInternalFields
 * @details Gets the count of specified internal fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszFieldName The input field name to be matched.
	*  -If empty, this will retrieve all internal field dictionaries from the root list of the whole form.
	*  -If has value, all internal fields which names match the csfieldName will return.
 * @return   The count of internal fields with specified field name to be matched.
 * @note 
 */
INTERFACE(FS_DWORD, FPDInterFormCountInternalFields, (FPD_InterForm form,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormGetInternalField
 * @details Gets an internal field.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  index The zero-based internal field index in the matched internal field array.
 * @param[in]  wszFieldName The field name to be matched.
	*  -If empty, this will retrieve all internal field dictionaries from the root list of the whole form.
	*  -If has value, all internal fields which names match the csfieldName will return.
 * @return   The internal field dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDInterFormGetInternalField, (FPD_InterForm form,  FS_DWORD index,  FS_LPWSTR wszFieldName))

/**
 * @brief FPDInterFormGetDocument
 * @details Gets the PDF document.
 * @param[in]  form The input PDF interactive form.
 * @return   The PDF document.
 * @note 
 */
INTERFACE(FPD_Document, FPDInterFormGetDocument, (FPD_InterForm form))

/**
 * @brief FPDInterFormGetFormDict
 * @details Gets the AcroForm dictionary.
 * @param[in]  form The input PDF interactive form.
 * @return   The AcroForm dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDInterFormGetFormDict, (FPD_InterForm form))

/**
 * @brief FPDInterFormNeedConstructAP
 * @details Checks whether to construct appearance streams and appearance dictionaries for all widget annotations in the document.
 * @param[in]  form The input PDF interactive form.
 * @return   <a>TRUE</a> for constructing appearance streams and appearance dictionaries, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormNeedConstructAP, (FPD_InterForm form))

/**
 * @brief FPDInterFormNeedConstructAP2
 * @details Sets the construct flag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  bNeedAP The input construct flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormNeedConstructAP2, (FPD_InterForm form,  FS_BOOL bNeedAP))

/**
 * @brief FPDInterFormCountFieldsInCalculationOrder
 * @details The count of all fields in CO array.
 * @param[in]  form The input PDF interactive form.
 * @return   The count of all fields in CO array.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormCountFieldsInCalculationOrder, (FPD_InterForm form))

/**
 * @brief FPDInterFormGetFieldInCalculationOrder
 * @details Gets a form field from the calculation array.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  index The zero-based field index in the CO array.
 * @return   A form field.
 * @note 
 */
INTERFACE(FPD_FormField, FPDInterFormGetFieldInCalculationOrder, (FPD_InterForm form,  FS_INT32 index))

/**
 * @brief FPDInterFormFindFieldInCalculationOrder
 * @details Finds a form field in the CO array.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input form field.
 * @return   The zero-based index of the specified field in the CO array. -1 means not found.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormFindFieldInCalculationOrder, (FPD_InterForm form,  const FPD_FormField field))

/**
 * @brief FPDInterFormInsertFieldInCalculationOrder
 * @details Inserts a form field to the CO array.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input form field.
 * @param[in]  index The zero-based field index in the CO array to insert at.
 * @return   The zero-based index of the inserted field. -1 means failed.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormInsertFieldInCalculationOrder, (FPD_InterForm form,  const FPD_FormField field,  FS_INT32 index))

/**
 * @brief FPDInterFormMoveFieldInCalculationOrder
 * @details Moves a form field in the CO array to another position.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input form field.
 * @param[in]  iNewIndex The new zero-based field index in the CO array.
 * @return   The current index of specified field. -1 means failed.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormMoveFieldInCalculationOrder, (FPD_InterForm form,  const FPD_FormField field,  FS_INT32 iNewIndex))

/**
 * @brief FPDInterFormRemoveFieldInCalculationOrder
 * @details Removes a field in the CO array.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  field The input form field to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormRemoveFieldInCalculationOrder, (FPD_InterForm form,  const FPD_FormField field))

/**
 * @brief FPDInterFormCountFormFonts
 * @details Gets the count of font resources.
 * @param[in]  form The input PDF interactive form.
 * @return   The count of font resources.
 * @note 
 */
INTERFACE(FS_DWORD, FPDInterFormCountFormFonts, (FPD_InterForm form))

/**
 * @brief FPDInterFormGetFormFont
 * @details Gets a PDF font from the font resources.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  index The zero-based font index in the font resources.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetFormFont, (FPD_InterForm form,  FS_DWORD index,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormGetFormFont2
 * @details Gets a PDF font with specified name tag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szNameTag the name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetFormFont2, (FPD_InterForm form,  FS_LPSTR szNameTag))

/**
 * @brief FPDInterFormGetFormFont3
 * @details Finds a PDF font with specified font name.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szFontName The input font name.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetFormFont3, (FPD_InterForm form,  FS_LPSTR szFontName,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormGetNativeFormFont
 * @details Gets a native-form font with a character set.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  iCharSet The input character set.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetNativeFormFont, (FPD_InterForm form,  FS_BYTE iCharSet,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormGetNativeFormFont2
 * @details Gets the native-form font.
 * @param[in]  form The input PDF interactive form.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetNativeFormFont2, (FPD_InterForm form,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormFindFormFont
 * @details Finds a font with font pointer.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  font The input PDF font.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   Non-zero means found, otherwise not found.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormFindFormFont, (FPD_InterForm form,  const FPD_Font font,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormFindFormFont2
 * @details Finds a font with font name. ANSI version.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szFontName The input font name.
 * @param[out]  outFont It receives the found PDF font.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   Non-zero means found, otherwise not found.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormFindFormFont2, (FPD_InterForm form,  FS_LPSTR szFontName,  FPD_Font* outFont,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormFindFormFont3
 * @details Finds a font with font name. Unicode version.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  wszFontName The input font name.
 * @param[out]  outFont It receives the found PDF font.
 * @param[out]  outNameTag It receives the name tag of the font, such as /Helv (get rid of slash).
 * @return   Non-zero means found, otherwise not found.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormFindFormFont3, (FPD_InterForm form,  FS_LPWSTR wszFontName,  FPD_Font* outFont,  FS_ByteString* outNameTag))

/**
 * @brief FPDInterFormAddFormFont
 * @details Adds a form font with specified name tag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  font The input PDF font.
 * @param[in,out]  inOutNameTag Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormAddFormFont, (FPD_InterForm form,  const FPD_Font font,  FS_ByteString* inOutNameTag))

/**
 * @brief FPDInterFormAddNativeFormFont
 * @details Adds a native form font with specified name tag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  iCharSet The input character set.
 * @param[in,out]  inOutNameTag Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddNativeFormFont, (FPD_InterForm form,  FS_BYTE iCharSet,  FS_ByteString* inOutNameTag))

/**
 * @brief FPDInterFormAddNativeFormFont2
 * @details Adds the native form font.
 * @param[in]  form The input PDF interactive form.
 * @param[in,out]  inOutNameTag Input a name tag and receive a valid name tag of the font, such as /Helv (get rid of slash).
 * @return   A PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormAddNativeFormFont2, (FPD_InterForm form,  FS_ByteString* inOutNameTag))

/**
 * @brief FPDInterFormRemoveFormFont
 * @details Removes a form font with font pointer.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  font The input PDF font pointer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormRemoveFormFont, (FPD_InterForm form,  const FPD_Font font))

/**
 * @brief FPDInterFormRemoveFormFont2
 * @details Removes a form font with specified name tag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szNameTag The input name tag of the font, such as /Helv (get rid of slash).
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormRemoveFormFont2, (FPD_InterForm form,  FS_LPCSTR szNameTag))

/**
 * @brief FPDInterFormGetDefaultAppearance
 * @details Gets the default appearance interpreter.
 * @param[in]  form The input PDF interactive form.
 * @param[out]  outDefAP The default appearance interpreter.
 * @return   void
 * @note Do not forget to save default appearance after you change any setting in it when you
	*   retrieve an object of FPD_DefaultAppearance by GetDefaultAppearance method.
 */
INTERFACE(void, FPDInterFormGetDefaultAppearance, (FPD_InterForm form,  FPD_DefaultAppearance* outDefAP))

/**
 * @brief FPDInterFormSetDefaultAppearance
 * @details Sets the default appearance interpreter.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  cDA The input default appearance interpreter.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormSetDefaultAppearance, (FPD_InterForm form,  const FPD_DefaultAppearance cDA))

/**
 * @brief FPDInterFormGetDefaultFormFont
 * @details Gets the default form font.
 * @param[in]  form The input PDF interactive form.
 * @return   The default form font.
 * @note 
 */
INTERFACE(FPD_Font, FPDInterFormGetDefaultFormFont, (FPD_InterForm form))

/**
 * @brief FPDInterFormSetDefaultFormFont
 * @details Sets the default form font.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  font The input font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormSetDefaultFormFont, (FPD_InterForm form,  const FPD_Font font))

/**
 * @brief FPDInterFormGetFormAlignment
 * @details Gets the form alignment.
 * @param[in]  form The input PDF interactive form.
 * @return   alignment value: 
	*   <ul>
	*   <li>0 - left alignment, the default setting.</li>
	*   <li>1 - centered.</li>
	*   <li>2 - right alignment.</li>
	*   </ul>
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormGetFormAlignment, (FPD_InterForm form))

/**
 * @brief FPDInterFormSetFormAlignment
 * @details Sets the form alignment.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  iAlignment The input form alignment type.
	*   <ul>
	*   <li>0 - left alignment, the default setting.</li>
	*   <li>1 - centered,</li>
	*   <li>2 - right alignment.</li>
	*   </ul>
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormSetFormAlignment, (FPD_InterForm form,  FS_INT32 iAlignment))

/**
 * @brief FPDInterFormCheckRequiredFields
 * @details Checks the required fields' checked flag.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  fields The input form fields array. fields is the array of FPD_FormField.
 * @param[in]  bIncludeOrExclude Whether to include or exclude the required fields.
 * @return   The checked form field.
 * @note 
 */
INTERFACE(FPD_FormField, FPDInterFormCheckRequiredFields, (FPD_InterForm form,  const FS_PtrArray fields,  FS_BOOL bIncludeOrExclude))

/**
 * @brief FPDInterFormExportToFDF
 * @details Exports the interactive form to a FDF format file.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szPDFPath The input FDF file full path.
 * @return   A FDF document.
 * @note 
 */
INTERFACE(FDF_Document, FPDInterFormExportToFDF, (FPD_InterForm form,  FS_LPCWSTR szPDFPath))

/**
 * @brief FPDInterFormExportToFDF2
 * @details Exports the interactive form to a FDF format file, include or exclude some fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  szPDFPath The input FDF file full path.
 * @param[in]  fields The input form fields array. fields is the array of FPD_FormField.
 * @param[in]  bIncludeOrExclude Whether to include or exclude the form fields.
 * @return   A FDF document.
 * @note 
 */
INTERFACE(FDF_Document, FPDInterFormExportToFDF2, (FPD_InterForm form,  FS_LPCWSTR szPDFPath,  FS_PtrArray fields,  FS_BOOL bIncludeOrExclude))

/**
 * @brief FPDInterFormImportFromFDF
 * @details Imports a FDF document.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  FDFDoc The input FDF document.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormImportFromFDF, (FPD_InterForm form,  const FDF_Document FDFDoc,  FS_BOOL bNotify))

/**
 * @brief FPDInterFormResetForm
 * @details Resets form fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  fields The input form fields array. Fields is the array of FPD_FormField.
 * @param[in]  bIncludeOrExclude Whether to include or exclude the form fields.
 * @param[in]  bNotify Whether to do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormResetForm, (FPD_InterForm form,  const FS_PtrArray fields,  FS_BOOL bIncludeOrExclude,  FS_BOOL bNotify))

/**
 * @brief FPDInterFormResetForm2
 * @details Resets all form fields.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  bNotify Whether to do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormResetForm2, (FPD_InterForm form,  FS_BOOL bNotify))

/**
 * @brief FPDInterFormReloadForm
 * @details Reload the interactive form.
 * @param[in]  form The input PDF interactive form.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormReloadForm, (FPD_InterForm form))

/**
 * @brief FPDInterFormGetFormNotify
 * @details Gets the form notify handler.
 * @param[in]  form The input PDF interactive form.
 * @return   A form notify handler.
 * @note 
 */
INTERFACE(FPD_FormNotify, FPDInterFormGetFormNotify, (FPD_InterForm form))

/**
 * @brief FPDInterFormSetFormNotify
 * @details Sets the form notify handler.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  pNotify The notify callbacks.
 * @return   A previous form notify handler.
 * @note 
 */
INTERFACE(void, FPDInterFormSetFormNotify, (FPD_InterForm form,  FPD_FormNotify formNotify))

/**
 * @brief FPDInterFormGetPageWithWidget
 * @details Retrieves the next or previous page for the page specified by iCurPage.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  iCurPage The current page index.
 * @param[in]  bNext Whether to retrieve the next or previous page.
 * @return   The next or previous page index.
 * @note 
 */
INTERFACE(FS_INT32, FPDInterFormGetPageWithWidget, (FPD_InterForm form,  FS_INT32 iCurPage,  FS_BOOL bNext))

/**
 * @brief FPDInterFormIsUpdated
 * @details Checks whether the form is updated.
 * @param[in]  form The input PDF interactive form.
 * @return   <a>TRUE</a> for the form being updated.
 * @note 
 */
INTERFACE(FS_BOOL, FPDInterFormIsUpdated, (FPD_InterForm form))

/**
 * @brief FPDInterFormClearUpdatedFlag
 * @details Clears the updated flag.
 * @param[in]  form The input PDF interactive form.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormClearUpdatedFlag, (FPD_InterForm form))

/**
 * @brief FPDInterFormFixPageFields
 * @details Supplement some form field from a page
 * @param[in]  form The input PDF interactive form.
 * @param[in]  page The input page dictionary.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDInterFormFixPageFields, (FPD_InterForm form,  FPD_Page page))

/**
 * @brief FPDInterFormAddControl
 * @details Adds a control to the PDF interactive form with a widget.
 * @param[in]  form The input PDF interactive form.
 * @param[in]  fieldDict The input field dictionary.
 * @param[in]  pWidgetDict The input widget dictionary.
 * @return   A form control.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FPD_FormControl, FPDInterFormAddControl, (FPD_InterForm form,  const FPD_Object fieldDict,  const FPD_Object pWidgetDict))

NumOfSelector(FPDInterForm)
ENDENUM

//*****************************
/* FormField HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFormFieldGetFullName
 * @details Gets the full name of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outName The full name of the field.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetFullName, (FPD_FormField formField,  FS_WideString* outName))

/**
 * @brief FPDFormFieldGetType
 * @details Gets the type of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The type of the field.
 * @note 
 */
INTERFACE(FPD_FormFieldType, FPDFormFieldGetType, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetFlags
 * @details Gets the field flags.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The field flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFormFieldGetFlags, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetInterForm
 * @details Gets the interactive form which it belongs to.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The interactive form which it belongs to.
 * @note 
 */
INTERFACE(FPD_InterForm, FPDFormFieldGetInterForm, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetFieldDict
 * @details Gets the field dictionary.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The field dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormFieldGetFieldDict, (FPD_FormField formField))

/**
 * @brief FPDFormFieldResetField
 * @details Resets the form field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldResetField, (FPD_FormField formField,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldCountControls
 * @details Gets the count of controls belongs to this field.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The count of controls belongs to this field.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldCountControls, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetControl
 * @details Gets a control.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The input zero-based control index in the field.
 * @return   A form control.
 * @note 
 */
INTERFACE(FPD_FormControl, FPDFormFieldGetControl, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldGetControlIndex
 * @details Gets the index of a control.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  control The input form control.
 * @return   The index of the control in the field.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetControlIndex, (FPD_FormField formField,  FPD_FormControl control))

/**
 * @brief FPDFormFieldGetFieldType
 * @details Gets the field type.
 * @param[in]  formField The input PDF interactive form field.
 * @return   Types like FPD_FORM_FIELDTYPE_xxxx
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetFieldType, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetAdditionalAction
 * @details Gets the additional action of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outAAction The additional action of the field.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetAdditionalAction, (FPD_FormField formField,  FPD_AAction* outAAction))

/**
 * @brief FPDFormFieldSetAdditionalAction
 * @details Sets the additional action of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  aa The input additional action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetAdditionalAction, (FPD_FormField formField,  FPD_AAction aa))

/**
 * @brief FPDFormFieldGetAlternateName
 * @details Gets the alternate field name to be used in place of the actual
	*            field name wherever the field must be identified in the user interface.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outName The alternate field name
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetAlternateName, (FPD_FormField formField,  FS_WideString* outName))

/**
 * @brief FPDFormFieldSetAlternateName
 * @details Sets the alternate field name. ANSI version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  szName The input alternate field name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetAlternateName, (FPD_FormField formField,  FS_LPCSTR szName))

/**
 * @brief FPDFormFieldSetAlternateNameW
 * @details Sets the alternate field name. Unicode version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszName The input alternate field name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetAlternateNameW, (FPD_FormField formField,  FS_LPCWSTR wszName))

/**
 * @brief FPDFormFieldGetMappingName
 * @details Gets the mapping name to be used when exporting interactive form field data from the document.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outName The mapping name
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetMappingName, (FPD_FormField formField,  FS_WideString* outName))

/**
 * @brief FPDFormFieldSetMappingName
 * @details Sets the mapping name. ANSI version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  szName The input mapping name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetMappingName, (FPD_FormField formField,  FS_LPCSTR szName))

/**
 * @brief FPDFormFieldSetMappingNameW
 * @details Sets the mapping name. Unicode version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszName The input mapping name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetMappingNameW, (FPD_FormField formField,  FS_LPCWSTR wszName))

/**
 * @brief FPDFormFieldGetFieldFlags
 * @details Gets the field flags.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The field flags.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFormFieldGetFieldFlags, (FPD_FormField formField))

/**
 * @brief FPDFormFieldSetFieldFlags
 * @details Sets the field flags.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  dwFlags The input field flags.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetFieldFlags, (FPD_FormField formField,  FS_DWORD dwFlags))

/**
 * @brief FPDFormFieldGetDefaultStyle
 * @details Gets the default style string.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outStyle The default style string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetDefaultStyle, (FPD_FormField formField,  FS_ByteString* outStyle))

/**
 * @brief FPDFormFieldSetDefaultStyle
 * @details Sets the default style string.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  szDefaultStyle The input default style string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetDefaultStyle, (FPD_FormField formField,  FS_LPSTR szDefaultStyle))

/**
 * @brief FPDFormFieldGetRichTextString
 * @details Gets the rich text string.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outText The rich text string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetRichTextString, (FPD_FormField formField,  FS_WideString* outText))

/**
 * @brief FPDFormFieldSetRichTextString
 * @details Sets the rich text string. ANSI version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  szRichText The input rich text string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetRichTextString, (FPD_FormField formField,  FS_LPCSTR szRichText))

/**
 * @brief FPDFormFieldSetRichTextStringW
 * @details Sets the rich text string. Unicode version.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszRichText The input rich text string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetRichTextStringW, (FPD_FormField formField,  FS_LPCWSTR wszRichText))

/**
 * @brief FPDFormFieldGetValue
 * @details Gets the value of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outValue The value of the field.
 * @return   void
 * @note *  <ul>
	*  <li>For a text field, the value is the text string;</li>
	*  <li>For a rich text field, the value is the rich text XML element;</li>
	*  <li>For a file field, the value is the path name of the file;</li>
	*  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	*  <li>For a list box field, the value is the value of first selected item, if any;</li>
	*  <li>For a comb box field, the value is the text string.</li>
	*  </ul>
 */
INTERFACE(void, FPDFormFieldGetValue, (FPD_FormField formField,  FS_WideString* outValue))

/**
 * @brief FPDFormFieldGetDefaultValue
 * @details Gets the default value of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[out]  outValue The default value of the field.
 * @return   void
 * @note *  <ul>
	*  <li>For a text field, the value is the text string;</li>
	*  <li>For a rich text field, the value is the rich text XML element;</li>
	*  <li>For a file field, the value is the path name of the file;</li>
	*  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	*  <li>For a list box field, the value is the value of first selected item, if any;</li>
	*  <li>For a comb box field, the value is the text string.</li>
	*  </ul>
 */
INTERFACE(void, FPDFormFieldGetDefaultValue, (FPD_FormField formField,  FS_WideString* outValue))

/**
 * @brief FPDFormFieldSetValue
 * @details Sets the value of the field. not applicable to non-unison radio box.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszValue The input field value.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note *  <ul>
	*  <li>For a text field, the value is the text string;</li>
	*  <li>For a rich text field, the value is the rich text XML element;</li>
	*  <li>For a file field, the value is the path name of the file;</li>
	*  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	*  <li>For a list box field, the value is the value of first selected item, if any;</li>
	*  <li>For a comb box field, the value is the text string.</li>
	*  </ul>
 */
INTERFACE(FS_BOOL, FPDFormFieldSetValue, (FPD_FormField formField,  FS_LPCWSTR wszValue,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldSetDefaultValue
 * @details Sets the default value of the field.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszValue The input default field value.
 * @return   Non-zero means success, otherwise failure.
 * @note *  <ul>
	*  <li>For a text field, the value is the text string;</li>
	*  <li>For a rich text field, the value is the rich text XML element;</li>
	*  <li>For a file field, the value is the path name of the file;</li>
	*  <li>For a radio button or check box field, the value is value string of the selected button;</li>
	*  <li>For a list box field, the value is the value of first selected item, if any;</li>
	*  <li>For a comb box field, the value is the text string.</li>
	*  </ul>
 */
INTERFACE(FS_BOOL, FPDFormFieldSetDefaultValue, (FPD_FormField formField,  FS_LPCWSTR wszValue))

/**
 * @brief FPDFormFieldGetMaxLen
 * @details Gets the maximum length of the field's text, in characters.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The maximum length of the field's text, in characters.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetMaxLen, (FPD_FormField formField))

/**
 * @brief FPDFormFieldSetMaxLen
 * @details Sets the maximum length of the field's text, in characters.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  iMaxLen The input maximum length.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetMaxLen, (FPD_FormField formField,  FS_INT32 iMaxLen))

/**
 * @brief FPDFormFieldCountSelectedItems
 * @details Gets the count of selected items.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The count of selected items.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldCountSelectedItems, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetSelectedIndex
 * @details Gets the selected item index in the item array(include selected and unselected).
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The item index in the selected item array.
 * @return   The item index in all item array(include selected and unselected).
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetSelectedIndex, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldClearSelection
 * @details Clears the selection.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldClearSelection, (FPD_FormField formField,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldIsItemSelected
 * @details Checks whether the specified item has been selected.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based item index in the item array.
 * @return   Non-zero means selected, otherwise unselected.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldIsItemSelected, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldSetItemSelection
 * @details Sets the selection flag of specified item.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based item index in the item array.
 * @param[in]  bSelected The input selection flag.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldSetItemSelection, (FPD_FormField formField,  FS_INT32 index,  FS_BOOL bSelected,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldIsItemDefaultSelected
 * @details Checks whether the specified item's default selection flag is set.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based item index in the item array.
 * @return   Non-zero means default selected, otherwise default unselected.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldIsItemDefaultSelected, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldSetItemDefaultSelection
 * @details Sets the default selection flag of specified item.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based item index in the item array.
 * @param[in]  bSelected The input default selection flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetItemDefaultSelection, (FPD_FormField formField,  FS_INT32 index,  FS_BOOL bSelected))

/**
 * @brief FPDFormFieldGetDefaultSelectedItem
 * @details Gets the default selected item index.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The default selected item index.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetDefaultSelectedItem, (FPD_FormField formField))

/**
 * @brief FPDFormFieldCountOptions
 * @details Gets the count of options.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The count of options.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldCountOptions, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetOptionLabel
 * @details Gets the label of specified option.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based option index.
 * @param[out]  outLabel The label of the option.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetOptionLabel, (FPD_FormField formField,  FS_INT32 index,  FS_WideString* outLabel))

/**
 * @brief FPDFormFieldGetOptionValue
 * @details Gets the value of specified option.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based option index.
 * @param[out]  outValue The value of the option.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldGetOptionValue, (FPD_FormField formField,  FS_INT32 index,  FS_WideString* outValue))

/**
 * @brief FPDFormFieldInsertOption
 * @details Inserts an option at specified position.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszOptLabel The label of the option.
 * @param[in]  index The option index to insert at.
 * @param[in]  bNotify Whether do notifying.
 * @return   The inserted option index.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldInsertOption, (FPD_FormField formField,  FS_LPWSTR wszOptLabel,  FS_INT32 index,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldFindOption
 * @details Finds an option by the label.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  wszOptLabel The label of the option to be found.
 * @return   The index of the found option.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldFindOption, (FPD_FormField formField,  FS_LPWSTR wszOptLabel))

/**
 * @brief FPDFormFieldFindOptionValue
 * @details Finds an option by it's value.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  csOptValue The value of the option to be found.
 * @param[in]  iStartIndex The start option index to find.
 * @return   The index of the found option.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldFindOptionValue, (FPD_FormField formField,  FS_LPCWSTR csOptValue,  FS_INT32 iStartIndex))

/**
 * @brief FPDFormFieldSetOptionLabel
 * @details Sets the option label.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based index of the option.
 * @param[in]  wszOptLabel The new option label.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldSetOptionLabel, (FPD_FormField formField,  FS_INT32 index,  FS_LPCWSTR wszOptLabel,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldSetOptionValue
 * @details Sets the option value.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based index of the option.
 * @param[in]  wszOptValue The new option label.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldSetOptionValue, (FPD_FormField formField,  FS_INT32 index,  FS_LPCWSTR wszOptValue,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldDeleteOption
 * @details Deletes an option.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The zero-based index of the option to be deleted.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldDeleteOption, (FPD_FormField formField,  FS_INT32 index,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldClearOptions
 * @details Clears all options.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldClearOptions, (FPD_FormField formField,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldCheckControl
 * @details Checks a control.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  iControlIndex The index of the control.
 * @param[in]  bChecked The input check state.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldCheckControl, (FPD_FormField formField,  FS_INT32 iControlIndex,  FS_BOOL bChecked,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldDefaultCheckControl
 * @details Checks a control's default check state.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  iControlIndex The index of the control.
 * @param[in]  bChecked the input check state.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldDefaultCheckControl, (FPD_FormField formField,  FS_INT32 iControlIndex,  FS_BOOL bChecked))

/**
 * @brief FPDFormFieldUpdateUnisonStatus
 * @details Resets or recreate Opt array list and AP stream, for RadioButton only.
	*            This is used whenever unison status is changed.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  bNotify Whether do notifying.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldUpdateUnisonStatus, (FPD_FormField formField,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldGetTopVisibleIndex
 * @details Gets the top visible option index.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The top visible option index.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetTopVisibleIndex, (FPD_FormField formField))

/**
 * @brief FPDFormFieldSetTopVisibleIndex
 * @details Sets the top visible option index.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index The input option index.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormFieldSetTopVisibleIndex, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldCountSelectedOptions
 * @details Gets the count of option indices in the "I" entry list.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The count of option indices in the "I" entry list.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldCountSelectedOptions, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetSelectedOptionIndex
 * @details Gets the index of a selection option in all option array.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  index zero-based index in "I" entry list.
 * @return   The index in all option array.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormFieldGetSelectedOptionIndex, (FPD_FormField formField,  FS_INT32 index))

/**
 * @brief FPDFormFieldIsOptionSelected
 * @details Checks whether specified option has been selected.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  iOptIndex zero-based index of option in Opt list.
 * @return   Non-zero means selected, otherwise unselected.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldIsOptionSelected, (FPD_FormField formField,  FS_INT32 iOptIndex))

/**
 * @brief FPDFormFieldSelectOption
 * @details Sets specified option to be selected.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  iOptIndex zero-based index of option in Opt list.
 * @param[in]  bSelected The input selection flag.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldSelectOption, (FPD_FormField formField,  FS_INT32 iOptIndex,  FS_BOOL bSelected,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldClearSelectedOptions
 * @details Clears selected options to be unselected.
 * @param[in]  formField The input PDF interactive form field.
 * @param[in]  bNotify Whether do notifying.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormFieldClearSelectedOptions, (FPD_FormField formField,  FS_BOOL bNotify))

/**
 * @brief FPDFormFieldGetFontSize
 * @details Gets the font size.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The font size.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDFormFieldGetFontSize, (FPD_FormField formField))

/**
 * @brief FPDFormFieldGetFont
 * @details Gets the font.
 * @param[in]  formField The input PDF interactive form field.
 * @return   The PDF font.
 * @note 
 */
INTERFACE(FPD_Font, FPDFormFieldGetFont, (FPD_FormField formField))

NumOfSelector(FPDFormField)
ENDENUM

//*****************************
/* IconFit HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDIconFitNew
 * @details Creates a PDF icon fit from a PDF dictionary.
 * @param[in]  dict The input PDF dictionary.
 * @return   A PDF icon fit.
 * @note 
 */
INTERFACE(FPD_IconFit, FPDIconFitNew, (FPD_Object dict))

/**
 * @brief FPDIconFitDestroy
 * @details Destroys a PDF icon fit.
 * @param[in]  iconFit The input PDF icon fit.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitDestroy, (FPD_IconFit iconFit))

/**
 * @brief FPDIconFitGetScaleMethod
 * @details Gets the scale method.
 * @param[in]  iconFit The input PDF icon fit.
 * @return   The scale method.
 * @note 
 */
INTERFACE(FS_INT32, FPDIconFitGetScaleMethod, (FPD_IconFit iconFit))

/**
 * @brief FPDIconFitSetScaleMethod
 * @details Sets the scale method.
 * @param[in]  iconFit The input PDF icon fit.
 * @param[in]  eScaleFunction The new scale method.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitSetScaleMethod, (FPD_IconFit iconFit,  FPD_IconScaleMethod eScaleFunction))

/**
 * @brief FPDIconFitIsProportionalScale
 * @details Checks whether the scaling is proportional.
 * @param[in]  iconFit The input PDF icon fit.
 * @return   <a>TRUE</a> for the scaling being proportional.
 * @note 
 */
INTERFACE(FS_BOOL, FPDIconFitIsProportionalScale, (FPD_IconFit iconFit))

/**
 * @brief FPDIconFitProportionalScale
 * @details Change the proportional scaling flag.
 * @param[in]  iconFit The input PDF icon fit.
 * @param[in]  bScale Whether the proportional scaling flag to be set.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitProportionalScale, (FPD_IconFit iconFit,  FS_BOOL bScale))

/**
 * @brief FPDIconFitGetIconPosition
 * @details Gets the the fraction of leftover space to allocate at the left and bottom of the icon.
 * @param[in]  iconFit The input PDF icon fit.
 * @param[out]  outLeft It receives the x-direction fraction.
 * @param[out]  outBottom It receives the y-direction fraction.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitGetIconPosition, (FPD_IconFit iconFit,  FS_FLOAT* outLeft,  FS_FLOAT* outBottom))

/**
 * @brief FPDIconFitSetIconPosition
 * @details Sets the the fraction of leftover space to allocate at the left and bottom of the icon.
 * @param[in]  iconFit The input PDF icon fit.
 * @param[in]  fLeft The input x-direction fraction.
 * @param[in]  fBottom The input y-direction fraction.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitSetIconPosition, (FPD_IconFit iconFit,  FS_FLOAT fLeft,  FS_FLOAT fBottom))

/**
 * @brief FPDIconFitGetFittingBounds
 * @details Gets the fiting-bound flag which indicates that the button appearance should be scaled to fit 
    *            fully within the bounds of the annotation without taking into consideration the line 
	*            width of the border.
 * @param[in]  iconFit The input PDF icon fit.
 * @return   The fiting-bound flag
 * @note 
 */
INTERFACE(FS_BOOL, FPDIconFitGetFittingBounds, (FPD_IconFit iconFit))

/**
 * @brief FPDIconFitSetFittingBounds
 * @details Sets the fitting-bound flag.
 * @param[in]  iconFit The input PDF icon fit.
 * @param[in]  bFitBounds The input fitting bound flag.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDIconFitSetFittingBounds, (FPD_IconFit iconFit,  FS_BOOL bFitBounds))

/**
 * @brief FPDIconFitGetDict
 * @details Gets the icon fit dictionary.
 * @param[in]  iconFit The input PDF icon fit.
 * @return   The icon fit dictionary.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.2.2
 */
INTERFACE(FPD_Object, FPDIconFitGetDict, (FPD_IconFit iconFit))

NumOfSelector(FPDIconFit)
ENDENUM

//*****************************
/* FormControl HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFormControlGetType
 * @details Gets the field type.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   A PDF interactive form control.
 * @note 
 */
INTERFACE(FPD_FormFieldType, FPDFormControlGetType, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlGetInterForm
 * @details Gets the interactive form it belongs to.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The interactive form it belongs to.
 * @note 
 */
INTERFACE(FPD_InterForm, FPDFormControlGetInterForm, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlGetField
 * @details Gets the field it belongs to.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The field it belongs to.
 * @note 
 */
INTERFACE(FPD_FormField, FPDFormControlGetField, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlGetWidget
 * @details Gets the widget annotation dictionary.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The widget annotation dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormControlGetWidget, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlGetRect
 * @details Gets the rectangle of the widget.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outRect The rectangle of the widget.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetRect, (FPD_FormControl formContrl,  FS_FloatRect* outRect))

/**
 * @brief FPDFormControlDrawControl
 * @details Draws the form control.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  device The device to draw on.
 * @param[in]  matrix The transformation matrix from form control space to device space.
 * @param[in]  page The PDF page it belongs to.
 * @param[in]  eMode The input appearance mode.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlDrawControl, (FPD_FormControl formContrl,  FPD_RenderDevice device,  FS_AffineMatrix matrix,  FPD_Page page,  FPD_AnnotAppearanceMode eMode))

/**
 * @brief FPDFormControlGetCheckedAPState
 * @details Gets the checked state appearance string.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outState The checked state appearance string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetCheckedAPState, (FPD_FormControl formContrl,  FS_ByteString* outState))

/**
 * @brief FPDFormControlGetExportValue
 * @details Gets the export mapping name.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outValue The export mapping name.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetExportValue, (FPD_FormControl formContrl,  FS_WideString* outValue))

/**
 * @brief FPDFormControlSetExportValue
 * @details Sets the export mapping name.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  wszValue The input export name.
 * @param[in]  bNotify Whether do notifying.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetExportValue, (FPD_FormControl formContrl,  FS_LPCWSTR wszValue,  FS_BOOL bNotify))

/**
 * @brief FPDFormControlIsChecked
 * @details Checks whether the control is checked.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   <a>TRUE</a> for the control being checked.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormControlIsChecked, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlIsDefaultChecked
 * @details Checks whether the control is default checked.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   <a>TRUE</a> for the contro being default checked.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormControlIsDefaultChecked, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlGetHighlightingMode
 * @details Gets the highlighting mode.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The highlighting mode.
 * @note 
 */
INTERFACE(FPD_FormCtrlHighlightingMode, FPDFormControlGetHighlightingMode, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetHighlightingMode
 * @details Sets the highlighting mode.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  eHLMode The input highlighting mode.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetHighlightingMode, (FPD_FormControl formContrl,  FPD_FormCtrlHighlightingMode eHLMode))

/**
 * @brief FPDFormControlHasMKEntry
 * @details Checks whether the specified entry exist in the appearance characteristics dictionary.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  szEntry The input entry name.
 * @return   Non-zero means exist, otherwise not exist.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFormControlHasMKEntry, (FPD_FormControl formContrl,  FS_LPSTR szEntry))

/**
 * @brief FPDFormControlRemoveMKEntry
 * @details Removes a entry in the appearance characteristics dictionary.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  szEntry The input entry name to be removed.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlRemoveMKEntry, (FPD_FormControl formContrl,  FS_LPSTR szEntry))

/**
 * @brief FPDFormControlGetRotation
 * @details Gets the number of degrees by which the widget annotation is rotated 
	*            counterclockwise relative to the page. The value must be a multiple of 90.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The number of degrees.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormControlGetRotation, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetRotation
 * @details Sets the rotation.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iDegree The input number of degrees to rotated counterclockwise.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetRotation, (FPD_FormControl formContrl,  FS_INT32 iDegree))

/**
 * @brief FPDFormControlGetBorderColor
 * @details Gets the border color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  iColorType It receives the color type.
 * @return   The FX_ARGB color.
 * @note 
 */
INTERFACE(FS_ARGB, FPDFormControlGetBorderColor, (FPD_FormControl formContrl,  FS_INT32* iColorType))

/**
 * @brief FPDFormControlGetOriginalBorderColor
 * @details Gets an original color component of the border color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  index The component index of the original color.
 * @return   The value of the component.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDFormControlGetOriginalBorderColor, (FPD_FormControl formContrl,  FS_INT32 index))

/**
 * @brief FPDFormControlGetOriginalBorderColor2
 * @details Gets the original color of the border.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outColorType It receives the color type.
 * @param[out]  outFc[4] It receives the values of the components.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetOriginalBorderColor2, (FPD_FormControl formContrl,  FS_INT32* outColorType,  FS_FLOAT outFc[4]))

/**
 * @brief FPDFormControlSetBorderColor
 * @details Sets the border color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iColorType The input color type.
 * @param[in]  color The FS_ARGB value of the input color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetBorderColor, (FPD_FormControl formContrl,  FS_INT32 iColorType,  FS_ARGB color))

/**
 * @brief FPDFormControlGetBackgroundColor
 * @details Gets the background color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outColorType It receives the color type.
 * @return   The FS_ARGB color.c
 * @note 
 */
INTERFACE(FS_ARGB, FPDFormControlGetBackgroundColor, (FPD_FormControl formContrl,  FS_INT32* outColorType))

/**
 * @brief FPDFormControlGetOriginalBackgroundColor
 * @details Gets an original color component of the background color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  index The component index of the original color.
 * @return   The value of the component.
 * @note 
 */
INTERFACE(FS_FLOAT, FPDFormControlGetOriginalBackgroundColor, (FPD_FormControl formContrl,  FS_INT32 index))

/**
 * @brief FPDFormControlGetOriginalBackgroundColor2
 * @details Gets the original color of the background.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outColorType It receives the color type.
 * @param[out]  fc[4] It receives the values of the components.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetOriginalBackgroundColor2, (FPD_FormControl formContrl,  FS_INT32* outColorType,  FS_FLOAT fc[4]))

/**
 * @brief FPDFormControlSetBackgroundColor
 * @details Sets the background color.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iColorType The input color type.
 * @param[in]  color The FS_ARGB value of the input color.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetBackgroundColor, (FPD_FormControl formContrl,  FS_INT32 iColorType,  FS_ARGB color))

/**
 * @brief FPDFormControlGetNormalCaption
 * @details Gets the widget annotation's normal caption.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outCaption The widget annotation's normal caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetNormalCaption, (FPD_FormControl formContrl,  FS_WideString* outCaption))

/**
 * @brief FPDFormControlSetNormalCaption
 * @details Sets the widget annotation's normal caption. ANSI version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  szCaption The input normal caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetNormalCaption, (FPD_FormControl formContrl,  FS_LPCSTR szCaption))

/**
 * @brief FPDFormControlSetNormalCaptionW
 * @details Sets the widget annotation's normal caption. Unicode version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  wszCaption The input normal caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetNormalCaptionW, (FPD_FormControl formContrl,  FS_LPCWSTR wszCaption))

/**
 * @brief FPDFormControlGetRolloverCaption
 * @details Gets the widget annotation's rollover caption.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outCaption The widget annotation's rollover caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetRolloverCaption, (FPD_FormControl formContrl,  FS_WideString* outCaption))

/**
 * @brief FPDFormControlSetRolloverCaption
 * @details Sets the widget annotation's rollover caption. ANSI version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  szCaption The input rollover caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetRolloverCaption, (FPD_FormControl formContrl,  FS_LPCSTR szCaption))

/**
 * @brief FPDFormControlSetRolloverCaptionW
 * @details Sets the widget annotation's rollover caption. Unicode version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  wszCaption The input rollover caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetRolloverCaptionW, (FPD_FormControl formContrl,  FS_LPCWSTR wszCaption))

/**
 * @brief FPDFormControlGetDownCaption
 * @details Gets the widget annotation's alternate (down) caption.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outCaption The widget annotation's alternate (down) caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetDownCaption, (FPD_FormControl formContrl,  FS_WideString* outCaption))

/**
 * @brief FPDFormControlSetDownCaption
 * @details Sets the widget annotation's down caption. ANSI version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  szCaption The input down caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetDownCaption, (FPD_FormControl formContrl,  FS_LPCSTR szCaption))

/**
 * @brief FPDFormControlSetDownCaptionW
 * @details Sets the widget annotation's down caption. Unicode version.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  wszCaption The input down caption.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetDownCaptionW, (FPD_FormControl formContrl,  FS_LPCWSTR wszCaption))

/**
 * @brief FPDFormControlGetNormalIcon
 * @details Gets the widget annotation's normal icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The widget annotation's normal icon.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormControlGetNormalIcon, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetNormalIcon
 * @details Sets the widget annotation's normal icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iconStm The input PDF stream of normal icon.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetNormalIcon, (FPD_FormControl formContrl,  const FPD_Object iconStm))

/**
 * @brief FPDFormControlGetRolloverIcon
 * @details Gets the widget annotation's rollover icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The widget annotation's rollover icon.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormControlGetRolloverIcon, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetRolloverIcon
 * @details Sets the widget annotation's rollover icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iconStream The input PDF stream of rollover icon.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetRolloverIcon, (FPD_FormControl formContrl,  const FPD_Object iconStream))

/**
 * @brief FPDFormControlGetDownIcon
 * @details Gets the widget annotation's down icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The widget annotation's down icon.
 * @note 
 */
INTERFACE(FPD_Object, FPDFormControlGetDownIcon, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetDownIcon
 * @details Sets the widget annotation's down icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iconStream The input PDF stream of down icon.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetDownIcon, (FPD_FormControl formContrl,  const FPD_Object iconStream))

/**
 * @brief FPDFormControlGetIconFit
 * @details Gets the icon fit of the widget.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outIconFit The icon fit of the widget.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetIconFit, (FPD_FormControl formContrl,  FPD_IconFit* outIconFit))

/**
 * @brief FPDFormControlSetIconFit
 * @details Sets the icon fit of the widget.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  cIF The input icon fit.
 * @param[in]  pObjs The indirect object collection.
 * @return   void
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDFormControlSetIconFit, (FPD_FormControl formContrl,  const FPD_IconFit cIF,  void* pObjs))

/**
 * @brief FPDFormControlGetTextPosition
 * @details Gets where to position the text of the widget annotation's caption relative to its icon.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The text position.
 * @note 
 */
INTERFACE(FS_INT32, FPDFormControlGetTextPosition, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetTextPosition
 * @details Sets the text position.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iPos The input text position.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetTextPosition, (FPD_FormControl formContrl,  FS_INT32 iPos))

/**
 * @brief FPDFormControlGetAction
 * @details Gets the action to be performed when the annotation is activated.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outAction The action to be performed when the annotation is activated.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetAction, (FPD_FormControl formContrl,  FPD_Action* outAction))

/**
 * @brief FPDFormControlSetAction
 * @details Sets the action to be performed when the annotation is activated.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  action The input action.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetAction, (FPD_FormControl formContrl,  const FPD_Action action))

/**
 * @brief FPDFormControlGetAdditionalAction
 * @details Gets the additional-actions defining the annotation's behavior in response to various trigger events.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  pAAction It receives the additional-actions.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlGetAdditionalAction, (FPD_FormControl formContrl,  FPD_AAction* pAAction))

/**
 * @brief FPDFormControlSetAdditionalAction
 * @details Sets the additional-actions.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  aaction The input additional-actions.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetAdditionalAction, (FPD_FormControl formContrl,  const FPD_AAction aaction))

/**
 * @brief FPDFormControlGetDefaultAppearance
 * @details Gets the default appearance.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[out]  outDefAP The default appearance.
 * @return   void
 * @note Do not forget to save default appearance after you change any setting in it when you
	*		retrieve an object of FPD_DefaultAppearance by GetDefaultAppearance method.
 */
INTERFACE(void, FPDFormControlGetDefaultAppearance, (FPD_FormControl formContrl,  FPD_DefaultAppearance* outDefAP))

/**
 * @brief FPDFormControlSetDefaultAppearance
 * @details Sets the default appearance.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  cDA The input default appearance.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetDefaultAppearance, (FPD_FormControl formContrl,  const FPD_DefaultAppearance cDA))

/**
 * @brief FPDFormControlGetDefaultControlFont
 * @details Gets the default font of the control.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The default font of the control.
 * @note 
 */
INTERFACE(FPD_Font, FPDFormControlGetDefaultControlFont, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetDefaultControlFont
 * @details Sets the default font of the control.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  font The input PDF font.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFormControlSetDefaultControlFont, (FPD_FormControl formContrl,  const FPD_Font font))

/**
 * @brief FPDFormControlGetControlAlignment
 * @details Gets the alignment of the control.
 * @param[in]  formContrl The input PDF interactive form control.
 * @return   The alignment of the control.
	*  <ul><li>0 - left alignment, the default setting.</li>
	*  <li>1 - centered, </li>
	*  <li>2 - right alignment. </li></ul>
 * @note 
 */
INTERFACE(FS_INT32, FPDFormControlGetControlAlignment, (FPD_FormControl formContrl))

/**
 * @brief FPDFormControlSetControlAlignment
 * @details Sets the alignment of the control.
 * @param[in]  formContrl The input PDF interactive form control.
 * @param[in]  iAlignment The input alignment.
	*  0 - left alignment, the default setting.
	*  1 - centered, 
	*  2 - right alignment.
 * @return   void.
 * @note 
 */
INTERFACE(void, FPDFormControlSetControlAlignment, (FPD_FormControl formContrl,  FS_INT32 iAlignment))

NumOfSelector(FPDFormControl)
ENDENUM

//*****************************
/* FDFDoc HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDFDFDocNew
 * @details Creates a new empty FDF document.
 * @return   A new empty FDF document.
 * @note 
 */
INTERFACE(FDF_Document, FPDFDFDocNew, ())

/**
 * @brief FPDFDFDocOpenFromFile
 * @details Loads a FDF document from a file.
 * @param[in]  strFilePath The input file full path.
 * @return   The FDF document.
 * @note 
 */
INTERFACE(FDF_Document, FPDFDFDocOpenFromFile, (FS_LPCSTR strFilePath))

/**
 * @brief FPDFDFDocPareMemory
 * @details Loads a FDF document from a memory block.
 * @param[in]  memoryBlock The input memory block.
 * @param[in]  size The size in bytes of the block.
 * @return   The FDF document.
 * @note 
 */
INTERFACE(FDF_Document, FPDFDFDocPareMemory, (FS_LPCBYTE memoryBlock,  FS_DWORD size))

/**
 * @brief FPDFDFDocDestroy
 * @details Destroys The FDF document.
 * @param[in]  doc The input FDF document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocDestroy, (FDF_Document doc))

/**
 * @brief FPDFDFDocWriteFile
 * @details Writes the content of this FDF document to a file.
 * @param[in]  doc The input FDF document.
 * @param[in]  strFilePath The file full path to write to.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFDFDocWriteFile, (FDF_Document doc,  FS_LPCSTR strFilePath))

/**
 * @brief FPDFDFDocGetRoot
 * @details Gets root dictionary of the FDF document. All other data can be fetched from this root.
 * @param[in]  doc The input FDF document.
 * @return   Root dictionary of the FDF document.
 * @note 
 */
INTERFACE(FPD_Object, FPDFDFDocGetRoot, (FDF_Document doc))

/**
 * @brief FPDFDFDocGetWin32Path
 * @details Gets file path of attached PDF document, if any. Different platform has different format.
 * @param[in]  doc The input FDF document.
 * @param[out]  outPath The file path of attached PDF document, if any.
 * @return   Root dictionary of the FDF document.
 * @note 
 */
INTERFACE(void, FPDFDFDocGetWin32Path, (FDF_Document doc,  FS_WideString* outPath))

/**
 * @brief FPDFDFDocGetIndirectObject
 * @details Loads an indirect object by an object number.
 * @param[in]  doc The input memory document.
 * @param[in]  objNum The input object number.
 * @return   An memory document.
 * @note 
 */
INTERFACE(FPD_Object, FPDFDFDocGetIndirectObject, (FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDFDFDocGetIndirectType
 * @details Gets type of an memory document, without loading the object content.
 * @param[in]  doc The input memory document.
 * @param[in]  objNum The input object number.
 * @return   The type of the memory document.
 * @note 
 */
INTERFACE(FS_INT32, FPDFDFDocGetIndirectType, (FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDFDFDocAddIndirectObject
 * @details Adds an object to indirect object list. The new object number is returned.
 * @param[in]  doc The input memory document.
 * @param[in]  obj The input object.
 * @return   The new object number.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFDFDocAddIndirectObject, (FDF_Document doc,  FPD_Object obj))

/**
 * @brief FPDFDFDocReleaseIndirectObject
 * @details Sometimes, for saving memory space, we can release a loaded memory document.
	*            However, use this with caution because the object pointer will become invalid.
 * @param[in]  doc The input memory document.
 * @param[in]  objNum The object number to release.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocReleaseIndirectObject, (FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDFDFDocDeleteIndirectObject
 * @details Deletes an memory document. Use this function with caution!
 * @param[in]  doc The input memory document.
 * @param[in]  objNum The object number to delete.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocDeleteIndirectObject, (FDF_Document doc,  FS_DWORD objNum))

/**
 * @brief FPDFDFDocImportIndirectObject
 * @details Imports an object from its binary format.
	*            This is used when the PDF is fetched in "Progressive Downloading" fashion.
	*            After this function call, the data buffer can be destroyed.
	*            This object must not be encrypted.
 * @param[in]  doc The input memory document.
 * @param[in]  pBuffer The binary data for the memory document. It must be not encrypted.
 * @param[in]  size The size in bytes of the binary data.
 * @return   An object.
 * @note 
 */
INTERFACE(FPD_Object, FPDFDFDocImportIndirectObject, (FDF_Document doc,  FS_LPCBYTE pBuffer,  FS_DWORD size))

/**
 * @brief FPDFDFDocImportExternalObject
 * @details Imports an object from external object collection as a new memory document.
	*            If the external object refers to other external indirect objects, those indirect objects
	*            are also imported.
	*            The mapping from old object number to new object number is updated during the import process.
 * @param[in]  doc The input memory document.
 * @param[in]  obj The object in external object collection.
 * @param[out]  mapping It updates the mapping from old object number to new object number.
 * @return   A new memory document.
 * @note 
 */
INTERFACE(FPD_Object, FPDFDFDocImportExternalObject, (FDF_Document doc,  FPD_Object obj,  FS_MapPtrToPtr mapping))

/**
 * @brief FPDFDFDocInsertIndirectObject
 * @details Inserts an indirect object with specified object number.
	*			  This is used when the PDF is fetched in "Progressive Downloading" fashion, or parsing FDF.
	*            If an indirect object with the same object number exists, the previous one will be destroyed.
 * @param[in]  doc The input memory document.
 * @param[in]  objNum The new object number of the indirect object to insert.
 * @param[in]  obj The indirect object to insert.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocInsertIndirectObject, (FDF_Document doc,  FS_DWORD objNum,  FPD_Object obj))

/**
 * @brief FPDFDFDocGetLastobjNum
 * @details Gets last assigned indirect object number.
 * @param[in]  doc The input memory document.
 * @return   Last assigned indirect object number.
 * @note 
 */
INTERFACE(FS_DWORD, FPDFDFDocGetLastobjNum, (FDF_Document doc))

/**
 * @brief FPDFDFDocReloadFileStreams
 * @details Reload all file based stream when we do reparsing.
 * @param[in]  doc The input memory document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocReloadFileStreams, (FDF_Document doc))

/**
 * @brief FPDFDFDocGetStartPosition
 * @details Gets the start position of the indirect objects.
 * @param[in]  doc The input memory document.
 * @return   The start position of the indirect objects.
 * @note 
 */
INTERFACE(FS_POSITION, FPDFDFDocGetStartPosition, (FDF_Document doc))

/**
 * @brief FPDFDFDocGetNextAssoc
 * @details Accesses the indirect object of current position, and move the position to next.
 * @param[in]  doc The input memory document.
 * @param[in,out]  outPos Input current position and receive the next position.
 * @param[out]  outObjNum It receives the current object number.
 * @param[out]  outObject It receives the current indirect object pointer.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocGetNextAssoc, (FDF_Document doc,  FS_POSITION* outPos,  FS_DWORD* outObjNum,  FPD_Object* outObject))

/**
 * @brief FPDFDFDocIsModified
 * @details Checks if any of the indirect objects are modified, since loading from parser, or last ClearModified.
 * @param[in]  doc The input memory document.
 * @return   <a>TRUE</a> for the indirect objects are modified, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFDFDocIsModified, (FDF_Document doc))

/**
 * @brief FPDFDFDocClearModified
 * @details Clears the modified flag.
 * @param[in]  doc The input memory document.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDFDFDocClearModified, (FDF_Document doc))

/**
 * @brief FPDFDFDocWriteBuf
 * @details Writes the content of this FDF document to a memory block.
 * @param[in]  doc The input document.
 * @param[out]  outBuf It will receive the content of this PDF document.
 * @return   <a>TRUE</a> means success, otherwise failure.
 * @note 
 */
INTERFACE(FS_BOOL, FPDFDFDocWriteBuf, (FDF_Document doc,  FS_ByteString* outBuf))

/**
 * @brief FPDFDFDocGetAnnotCount
 * @details Count annotations in a FDF document by specific filter.
 * @param[in]  doc The input document.
 * @param[in]  szFilter Pointer to a filter string. 
	*						It can be NULL, otherwise it must be like "Text" or "Text, Link, Circle".
 * @return   The count of annotations.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_INT32, FPDFDFDocGetAnnotCount, (FDF_Document doc,  FS_LPCSTR szFilter))

/**
 * @brief FPDFDFDocGetAnnotDict
 * @details Get an annotation dictionary from FDF document by specific filter and index.
 * @param[in]  doc The input document.
 * @param[in]  szFilter Pointer to a filter string. 
	*						It can be NULL, otherwise it must be like "Text" or "Text, Link, Circle".
 * @param[in]  nIndex A zero-based annotation index based on the annotations which are specified by filter.
 * @return   The FDF annotation dictionary.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FPD_Object, FPDFDFDocGetAnnotDict, (FDF_Document doc,  FS_LPCSTR szFilter,  FS_INT32 nIndex))

/**
 * @brief FPDFDFDocGetAnnotPageIndex
 * @details Get the zero-based index of PDF page on which the original PDF annotation locates.
 * @param[in]  fdfAnnotDict The FDF annotation dictionary.
 * @return   The zero-based index of PDF page.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_INT32, FPDFDFDocGetAnnotPageIndex, (FPD_Object fdfAnnotDict))

/**
 * @brief FPDFDFDocExportAnnotToPDFPage
 * @details Export an annotation object loaded from a FDF document into a PDF page.
 * @param[in]  doc The input document.
 * @param[in]  fdfAnnotDict The FDF annotation dictionary.
 * @param[in]  pdfDoc The PDF document to which the FDF annotation is exported.
 * @param[in]  pdfPage The PDF page to which the FDF annotation is exported.
 * @param[out]  arrAnnotDict The pointer array to receive generated PDF annotation dictionaries.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDFDFDocExportAnnotToPDFPage, (FDF_Document doc,  FPD_Object fdfAnnotDict,  FPD_Document pdfDoc,  FPD_Page pdfPage,  FS_PtrArray* arrAnnotDict))

/**
 * @brief FPDFDFDocImportPDFAnnot
 * @details Import an annotation from PDF document.
 * @param[in]  doc The input document.
 * @param[in]  pdfAnnotDict The PDF annotation dictionary to be imported.
 * @param[in]  nPageIndex The zero-based index of PDF page on which the annotation locates.
 * @return   Non-zero means success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(FS_BOOL, FPDFDFDocImportPDFAnnot, (FDF_Document doc,  FPD_Object pdfAnnotDict,  FS_INT32 nPageIndex))

/**
 * @brief FPDFDFDocSetPDFPath
 * @details Set the path of PDF document to FDF document.
 * @param[in]  doc The input document.
 * @param[in]  wszPDFPath The PDF path.
 * @return   
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 */
INTERFACE(void, FPDFDFDocSetPDFPath, (FDF_Document doc,  FS_LPCWSTR wszPDFPath))

NumOfSelector(FPDFDFDoc)
ENDENUM

//----------_V2----------
//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//*****************************
/* ConnectedInfo HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDConnectedInfoNew
 * @details Creates the connected PDF info object.
 * @param[in]  fpdDoc The input document.
 * @return   The connected PDF info object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(FPD_ConnectedInfo, FPDConnectedInfoNew, (FPD_Document fpdDoc))

/**
 * @brief FPDConnectedInfoDestroy
 * @details Destroys the connected PDF info object.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FPDConnectedInfoDestroy, (FPD_ConnectedInfo connectedInfo))

/**
 * @brief FPDConnectedInfoSetId
 * @details Sets the Id of the connected PDF info object.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  nIdType The input Id type.
 * @param[in]  bsURI The input URI.
 * @param[in]  bsCert The input certificate. This param is reserved now.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FPDConnectedInfoSetId, (FPD_ConnectedInfo connectedInfo,  FS_INT32 nIdType,  FS_ByteString bsURI,  FS_ByteString bsCert))

/**
 * @brief FPDConnectedInfoGetId
 * @details Gets the Id of the connected PDF info object.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  nIdType The input Id type.
 * @param[out]  outURI It receives the URI.
 * @param[out]  outCert It receives the certificate. This param is reserved now.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoGetId, (FPD_ConnectedInfo connectedInfo,  FS_INT32 nIdType,  FS_ByteString* outURI,  FS_ByteString* outCert))

/**
 * @brief FPDConnectedInfoIsConnectedPDF
 * @details Checks whether the PDF document is a connected PDF or not.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @return   TRUE if the PDF document is a connected PDF, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoIsConnectedPDF, (FPD_ConnectedInfo connectedInfo))

/**
 * @brief FPDConnectedInfoIsConnectedPDF2
 * @details Checks whether the PDF document is a connected PDF or not.
 * @param[in]  fpdDoc The input PDF document.
 * @return   TRUE if the PDF document is a connected PDF, otherwise not.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoIsConnectedPDF2, (FPD_Document fpdDoc))

/**
 * @brief FPDConnectedInfoSetTracking
 * @details Sets the tracking type. This interface is reserved now.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  track The input tracking type.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FPDConnectedInfoSetTracking, (FPD_ConnectedInfo connectedInfo,  FS_INT32 track))

/**
 * @brief FPDConnectedInfoGetTracking
 * @details Gets the tracking type. This interface is reserved now.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[out]  outTrack It receives the tracking type.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoGetTracking, (FPD_ConnectedInfo connectedInfo,  FS_INT32* outTrack))

/**
 * @brief FPDConnectedInfoUpdate
 * @details Updates the connected PDF info.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  bOpenAction Whether to add open action to ConnectedPDF document or not. Sets it FALSE as default.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.1
 */
INTERFACE(void, FPDConnectedInfoUpdate, (FPD_ConnectedInfo connectedInfo,  FS_BOOL bOpenAction))

/**
 * @brief FPDConnectedInfoSetEncryptOffline
 * @details Sets whether the encrypted connected PDF is offline or not.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  bOffline The input offline flag parameter.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FPDConnectedInfoSetEncryptOffline, (FPD_ConnectedInfo connectedInfo,  FS_BOOL bOffline))

/**
 * @brief FPDConnectedInfoSetEncryptEnvelope
 * @details Sets envelope string to encrypt dictionary.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  bsEnvelope The input offline envelope.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(void, FPDConnectedInfoSetEncryptEnvelope, (FPD_ConnectedInfo connectedInfo,  FS_ByteString bsEnvelope))

/**
 * @brief FPDConnectedInfoGetEncryptOffline
 * @details Sets envelope string to encrypt dictionary.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[out]  outIsOffline It receives the result whether the encrypted connected PDF is offline or not.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoGetEncryptOffline, (FPD_ConnectedInfo connectedInfo,  FS_BOOL* outIsOffline))

/**
 * @brief FPDConnectedInfoGetEncryptEnvelope
 * @details Gets the offline envelope.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[out]  outEnvelope It receives the offline envelope.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoGetEncryptEnvelope, (FPD_ConnectedInfo connectedInfo,  FS_ByteString* outEnvelope))

/**
 * @brief FPDConnectedInfoSetOpenActionURL
 * @details Sets OpenAction javascript server URL.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  lpsURL The input sever URL.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 7.3.1
 */
INTERFACE(FS_BOOL, FPDConnectedInfoSetOpenActionURL, (FPD_ConnectedInfo connectedInfo,  FS_LPCSTR lpsURL))

/**
 * @brief FPDConnectedInfoSetOpenActionURL2
 * @details Sets OpenAction javascript server URL.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  nType Sees <a>FPDConnectedOpenActionURLTypes</a> definitions.
 * @param[in]  lpsURL The input sever URL.
 * @return   TRUE for success, otherwise failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 */
INTERFACE(FS_BOOL, FPDConnectedInfoSetOpenActionURL2, (FPD_ConnectedInfo connectedInfo,  FS_INT32 nType,  FS_LPCSTR lpsURL))

/**
 * @brief FPDConnectedInfoCheckSettingOpenAction
 * @details Checks whether the OpenAction javascript server URL is set or not.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  nType Sees <a>FPDConnectedOpenActionURLTypes</a> definitions.
 * @param[in]  lpsURL The input sever URL.
 * @return   TRUE if the OpenAction javascript server URL is set.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.0.2
 */
INTERFACE(FS_BOOL, FPDConnectedInfoCheckSettingOpenAction, (FPD_ConnectedInfo connectedInfo,  FS_INT32 nType,  FS_LPCSTR lpsURL))

/**
 * @brief FPDConnectedInfoDeleteOpenAction
 * @details Deletes ConnectedPDF info in OpenAction.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.2.1
 */
INTERFACE(void, FPDConnectedInfoDeleteOpenAction, (FPD_ConnectedInfo connectedInfo))

/**
 * @brief FPDConnectedInfoSetEndpoint
 * @details Sets the URL of connected PDF web services.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[in]  lpsEndPoint The input URL of connected PDF web services.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3
 */
INTERFACE(void, FPDConnectedInfoSetEndpoint, (FPD_ConnectedInfo connectedInfo,  FS_LPCSTR lpsEndPoint))

/**
 * @brief FPDConnectedInfoGetEndpoint
 * @details Gets the URL of connected PDF web services.
 * @param[in]  connectedInfo The input connected PDF info object.
 * @param[out]  outEndPoint It receives the URL of connected PDF web services.
 * @return   TRUE if success, FALSE if failed.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3
 */
INTERFACE(FS_BOOL, FPDConnectedInfoGetEndpoint, (FPD_ConnectedInfo connectedInfo,  FS_ByteString* outEndPoint))

NumOfSelector(FPDConnectedInfo)
ENDENUM

//----------_V8----------
//----------_V9----------
//----------_V10----------
//*****************************
/* WrapperDoc HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDWrapperDocNew
 * @details Create the wrapper document object.
 * @param[in]  fpdDoc The input document.
 * @return   The wrapper document object.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FPD_WrapperDoc, FPDWrapperDocNew, (FPD_Document fpdDoc))

/**
 * @brief FPDWrapperDocDestroy
 * @details Destroys the wrapper document object.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @return   void.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(void, FPDWrapperDocDestroy, (FPD_WrapperDoc wrapperDoc))

/**
 * @brief FPDWrapperDocGetWrapperType
 * @details Whether the document is a wrapper document or normal.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @return   -1 for error;
	*			<a>PDF_WRAPPERTYPE_NO</a> for no wrapper document;
	*			<a>PDF_WRAPPERTYPE_FOXIT</a> for Foxit wrapper document;
	*			<a>PDF_WRAPPERTYPE_PDF2</a> for PDF2.0 wrapper document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_INT32, FPDWrapperDocGetWrapperType, (FPD_WrapperDoc wrapperDoc))

/**
 * @brief FPDWrapperDocGetCryptographicFilter
 * @details Get the details of the cryptographic filter needed to decrypt the encrypted payload.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @param[out]  wsGraphicFilter The name of the cryptographic filter.
 * @param[out]  fVersion The version number of the cryptographic filter, if present; Otherwise, 0.
 * @return   TRUE if success, otherwise return FALSE.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FPDWrapperDocGetCryptographicFilter, (FPD_WrapperDoc wrapperDoc,  FS_WideString *wsGraphicFilter,  FS_FLOAT *fVersion))

/**
 * @brief FPDWrapperDocGetPayLoadSize
 * @details Get the file size of the uncompressed encrypted payload document.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @return   The size of payload;
 * @note if no "size" key, return -1;
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_INT64, FPDWrapperDocGetPayLoadSize, (FPD_WrapperDoc wrapperDoc))

/**
 * @brief FPDWrapperDocGetPayloadFileName
 * @details Get the file name for encrypted payload documents which shall include the name of the
	*			cryptographic filter needed to decrypt the document.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @param[out]  wsFileName The file name for encrypted payload documents.
 * @return   TRUE if success, otherwise return FALSE.
 * @note The name must not contain or be derived from the encrypted payload's actual file name.
	*			This is to avoid potential disclosure of sensitive information in the original filename.
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FPDWrapperDocGetPayloadFileName, (FPD_WrapperDoc wrapperDoc,  FS_WideString *wsFileName))

/**
 * @brief FPDWrapperDocStartGetPayload
 * @details Get the embedded encrypted payload document's file stream.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @param[out]  pPayload The embedded encrypted payload document's file stream.
 * @param[in]  pPause The user-supplied pause object.
 * @return   TRUE, to be continued, otherwise, finished.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_BOOL, FPDWrapperDocStartGetPayload, (FPD_WrapperDoc wrapperDoc,  FS_FileWriteHandler *pPayload,  FS_PauseHandler pPause))

/**
 * @brief FPDWrapperDocContinue
 * @details Continue getting the embedded encrypted payload document's file stream.
 * @param[in]  wrapperDoc The input wrapper document object.
 * @param[in]  pPause The user-supplied pause object.
 * @return   Negative value if failure, 0 if finishes, and positive value if need to be continued.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 8.3.1
 */
INTERFACE(FS_INT32, FPDWrapperDocContinue, (FPD_WrapperDoc wrapperDoc,  FS_PauseHandler pPause))

NumOfSelector(FPDWrapperDoc)
ENDENUM

