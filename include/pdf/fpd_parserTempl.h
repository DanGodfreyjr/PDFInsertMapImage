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
/* Parser HFT functions */
//*****************************

BEGINENUM
/**
 * @brief FPDParserNew
 * @details Creates a new PDF file parser. </Brief>The PDF file parser will parse entire PDF file and then build a <a>FPD_Document</a> object,
	* use <a>FPDParserGetDocument</a>() to get a <a>FPD_Document</a> object.
 * @param[in]  void 
 * @return   The newly created parser.
 * @note 
 */
INTERFACE(FPD_Parser, FPDParserNew, (void))

/**
 * @brief FPDParserDestroy
 * @details Destroy a PDF file parser.
 * @param[in]  parser The parser to be free.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserDestroy, (FPD_Parser parser))

/**
 * @brief FPDParserStartParse
 * @details Starts parsing from a file, ANSIC version. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  filename The file full path name that will be parsed.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParse, (FPD_Parser parser,  FS_LPCSTR filename,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseW
 * @details Starts parsing from a file, Unicode version. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  filename The file full path name that will be parsed.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseW, (FPD_Parser parser,  FS_LPCWSTR filename,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseFormMem
 * @details Starts parsing from memory block. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  pData The input memory block that contains the PDF file data.
 * @param[in]  nSize The size in bytes of the memory block.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseFormMem, (FPD_Parser parser,  FS_LPCBYTE pData,  FS_DWORD nSize,  FS_BOOL bReParse))

/**
 * @brief FPDParserStartParseCustomFile
 * @details Starts parsing a custom file. Use <a>FPDParserCloseParse</a>() to end the parsing.
 * @param[in]  parser The PDF file parser.
 * @param[in]  file The stream access interface. Use <a>FSFileReadHandlerNew</a>() to create a file access interface.
 * @param[in]  bReParse A flag indicates whether you will do reparsing.
 * @param[in]  bOwnFileRead A flag indicated whether <a>FPD_Parser</a> takes ownership of the file read structure (by calling <a>FSFileReadHandlerDestroy</a>() when parser cleans up).
 * @return   The status of PDF parsing. See <a>FPDParseErrCodes</a>
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartParseCustomFile, (FPD_Parser parser,  FS_FileReadHandler file,  FS_BOOL bReParse,  FS_BOOL bOwnFileRead))

/**
 * @brief FPDParserCloseParser
 * @details Closes the parser, as well as the file. If reparsing is used, the document will be kept.
 * @param[in]  parser The PDF file parser.
 * @param[in]  bReParse A flag indicates whether reparsing is used.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserCloseParser, (FPD_Parser parser,  FS_BOOL bReParse))

/**
 * @brief FPDParserGetPermissions
 * @details Gets the use permissions of a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The permission codes. See <a>FPDDocPermissions</a>.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetPermissions, (FPD_Parser parser))

/**
 * @brief FPDParserIsOwner
 * @details Tests whether the user has the owner permission of the document.
 * @param[in]  parser The PDF file parser.
 * @return   <a>TRUE</a> for owner permission, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsOwner, (FPD_Parser parser))

/**
 * @brief FPDParserSetPassword
 * @details Sets the password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetPassword, (FPD_Parser parser,  const FS_CHAR* password))

/**
 * @brief FPDParserGetPassword
 * @details Gets the password string.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outPassword A buffer to receive the password string.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserGetPassword, (FPD_Parser parser,  FS_ByteString* outPassword))

/**
 * @brief FPDParserGetTrailer
 * @details Gets the trailer dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The trailer dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetTrailer, (FPD_Parser parser))

/**
 * @brief FPDParserGetLastXRefOffset
 * @details Gets the offset of last xref.
 * @param[in]  parser The PDF file parser.
 * @return   The bytes of the xref offset.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetLastXRefOffset, (FPD_Parser parser))

/**
 * @brief FPDParserGetDocument
 * @details Gets the <a>FPD_Document</a> object which associate with a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FPD_Document, FPDParserGetDocument, (FPD_Parser parser))

/**
 * @brief FPDParserCountOtherTrailers
 * @details Gets the total number of the trailers in a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   The total number of the trailers in a PDF file.
 * @note 
 */
INTERFACE(FS_INT32, FPDParserCountOtherTrailers, (FPD_Parser parser))

/**
 * @brief FPDParserGetOtherTrailerByIndex
 * @details Gets the specified trailer dictionary.
 * @param[in]  parser The PDF file parser.
 * @param[in]  index The index of trailer which will be obtained, the range is 0 to <a>FPDParserCountOtherTrailers</a>()-1.
 * @return   The specified trailer dictionary.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetOtherTrailerByIndex, (FPD_Parser parser,  FS_INT32 index))

/**
 * @brief FPDParserGetRootObjNum
 * @details Gets the object number of file catalog dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The object number of file root(catalog) dictionary.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetRootObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserGetInfoObjNum
 * @details Gets the object number of the file information dictionary.
 * @param[in]  parser The PDF file parser.
 * @return   The object number indicates the file information dictionary.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetInfoObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserGetIDArray
 * @details Gets the ID array in a PDF file.
 * @param[in]  parser The PDF file parser.
 * @return   A PDF array object which contain the IDs of a PDF file.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetIDArray, (FPD_Parser parser))

/**
 * @brief FPDParserGetEncryptDict
 * @details Gets the encrypt dictionary which contain encrypt information.
 * @param[in]  parser The PDF file parser.
 * @return   The encrypt dictionary object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserGetEncryptDict, (FPD_Parser parser))

/**
 * @brief FPDParserParseIndirectObject
 * @details Parses the indirect objects.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objList The <a>FPD_Document</a> object which contains all indirect objects.
 * @param[in]  objnum The object number.
 * @param[in]  pContext The parse context. See <a>FPD_PARSE_CONTEXT</a>.
 * @return   A PDF object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserParseIndirectObject, (FPD_Parser parser,  FPD_Document objList,  FS_DWORD objnum,  FPD_PARSE_CONTEXT* pContext))

/**
 * @brief FPDParserGetLastObjNum
 * @details Gets the lastest object number.
 * @param[in]  parser The PDF file parser.
 * @return   The object number of the last object in a PDF file.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetLastObjNum, (FPD_Parser parser))

/**
 * @brief FPDParserIsFormStream
 * @details Checks if an indirect object is a form stream or not, without actually loading the object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The stream object number.
 * @param[out]  bForm It receive whether it's a form stream or not.
 * @return   Non-zero means determined, otherwise unknown.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsFormStream, (FPD_Parser parser,  FS_DWORD objnum,  FS_BOOL* bForm))

/**
 * @brief FPDParserReloadFileStream
 * @details Reloads stream content of a specified stream object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  stream The stream object which content stream will be reload.
 * @return   <a>TRUE</a> for success, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserReloadFileStream, (FPD_Parser parser,  FPD_Object stream))

/**
 * @brief FPDParserDeleteIndirectObject
 * @details Deletes a indirect object form a file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number to be deleted.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserDeleteIndirectObject, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetLengthOfVersions
 * @details Gets the version's length of the file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  arrayLengths A DWORD array to receive the length of versions.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserGetLengthOfVersions, (FPD_Parser parser,  FS_DWordArray arrayLengths))

/**
 * @brief FPDParserGetObjectOffset
 * @details Gets offset of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The offset of the indirect object. For objects stored in object stream, this is the 
	* offset of the object stream.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetObjectOffset, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetObjectSize
 * @details Gets data size of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The data size, in bytes, of the indirect object. For objects stored in object stream, this is the 
	* data size of the object stream.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetObjectSize, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetObjectVersion
 * @details Gets the generation number of indirect object.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @return   The generation number of the indirect object.
 * @note 
 */
INTERFACE(int, FPDParserGetObjectVersion, (FPD_Parser parser,  FS_DWORD objnum))

/**
 * @brief FPDParserGetIndirectBinary
 * @details For faster file updating, we can get the binary form of an indirect object, then
	* directly output to destination file. In this case we must call the following
	* function to get the binary buffer.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @param[in]  buffer A binary buffer to receive bytes.
 * @return   void
 * @note This function can't be used for any updated PDF file.
 */
INTERFACE(void, FPDParserGetIndirectBinary, (FPD_Parser parser,  FS_DWORD objnum,  FS_BinaryBuf buffer))

/**
 * @brief FPDParserParseStreamPos
 * @details Gets position information for a stream:<br>
	* <ul>
	* <li>Start position (just before "<<") and end position (just after ">>") of the stream's dictionary</li>
	* <li>Start position (first byte) and end position (just after the last byte) of the stream's data</li>
	* </ul>
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The indirect object number.
 * @param[out]  dict_start Start position of the stream's dictionary.
 * @param[out]  dict_end End position of the stream's dictionary.
 * @param[out]  data_start Start position of the stream's data.
 * @param[out]  data_end End position of the stream's data.
 * @return   Non-zero means parse successfully, otherwise not.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserParseStreamPos, (FPD_Parser parser,  FS_DWORD objnum,  FS_DWORD* dict_start,  FS_DWORD* dict_end,  FS_DWORD* data_start,  FS_DWORD* data_end))

/**
 * @brief FPDParserParseIndirectObjectsAtRange
 * @details Gets the indirect objects in specify byte range.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objNum The indirect object number.
 * @param[in]  objPos The indirect object's start position.
 * @param[in]  dwPos The start position.
 * @param[in]  dwLen The length will be parsed.
 * @param[in]  context The parse context.
 * @return   Non_zero means parse successfully, otherwise not.
 * @note This function is bitwise search so very slow.
 */
INTERFACE(FS_BOOL, FPDParserParseIndirectObjectsAtRange, (FPD_Parser parser,  FS_DWordArray objNum,  FS_DWordArray objPos,  FS_DWORD dwPos,  FS_DWORD dwLen,  FPD_PARSE_CONTEXT* context))

/**
 * @brief FPDParserGetFileStreamOption
 * @details Get the file stream option.
	* <brief>Loading stream content into memory will improve performance for frequent access,
	* however, it will also consume a lot of memory space.
	* Therefore, we provide an option to leave stream content on file system, and read them
	* whenever we need them. If may reduce the performance a little bit, but greatly reduce
	* the memory consumption, especially when the file is big.
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserGetFileStreamOption, (FPD_Parser parser))

/**
 * @brief FPDParserSetFileStreamOption
 * @details Sets the file stream option.
 * @param[in]  parser The PDF file parser.
 * @param[in]  b A flag indicates whether the stream is a file stream.
 * @return   void
 * @note 
 */
INTERFACE(void, FPDParserSetFileStreamOption, (FPD_Parser parser,  FS_BOOL b))

/**
 * @brief FPDParserGetFileAccess
 * @details Gets the stream access interface.
 * @param[in]  parser The PDF file parser.
 * @return   A file access interface handler.
 * @note 
 */
INTERFACE(FS_FileReadHandler, FPDParserGetFileAccess, (FPD_Parser parser))

/**
 * @brief FPDParserGetFileVersion
 * @details Gets the file version. File version: 14 for 1.4, 15 for 1.5, ...
 * @param[in]  parser The PDF file parser.
 * @return   The new empty document.
 * @note 
 */
INTERFACE(FS_INT32, FPDParserGetFileVersion, (FPD_Parser parser))

/**
 * @brief FPDParserIsXRefStream
 * @details Tests whether cross reference stream is used.
 * @param[in]  parser The PDF file parser.
 * @return   <a>TRUE</a> for xref stream, otherwise <a>FALSE</a>.
 * @note 
 */
INTERFACE(FS_BOOL, FPDParserIsXRefStream, (FPD_Parser parser))

/**
 * @brief FPDParserParseIndirectObjectAt
 * @details Parses an indirect object specified by object position.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objList The <a>FPD_Document</a> object that contain the indirect objects.
 * @param[in]  pos The position specified the indirect object.
 * @param[in]  objnum The indirect object number.
 * @param[in]  pContext The parse context.
 * @return   A PDF object.
 * @note 
 */
INTERFACE(FPD_Object, FPDParserParseIndirectObjectAt, (FPD_Parser parser,  FPD_Document objList,  FS_DWORD pos,  FS_DWORD objnum,  FPD_PARSE_CONTEXT* pContext))

/**
 * @brief FPDParserStartAsynParse
 * @details Asynchronous parsing a custom file.
 * @param[in]  parser The PDF file parser.
 * @param[in]  pFile The stream access interface handler.
 * @param[in]  bReParse A flag indicates whether we will do reparsing.
 * @return   The status of PDF parsing.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserStartAsynParse, (FPD_Parser parser,  FS_FileReadHandler pFile,  FS_BOOL bReParse))

/**
 * @brief FPDParserGetFirstPageNo
 * @details Get the first page number.
 * @param[in]  parser The PDF file parser.
 * @return   The index of first page.
 * @note 
 */
INTERFACE(FS_DWORD, FPDParserGetFirstPageNo, (FPD_Parser parser))

/**
 * @brief FPDParserGetSecurityPermissions
 * @details Gets permission settings of the document.
 * @param[in]  parser The PDF file parser.
 * @return   The permission settings of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_DWORD, FPDParserGetSecurityPermissions, (FPD_Parser parser))

/**
 * @brief FPDParserIsSecurityOwner
 * @details Checks whether the current user is owner of the document.
 * @param[in]  parser The PDF file parser.
 * @return   Whether the current user is owner of the document.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserIsSecurityOwner, (FPD_Parser parser))

/**
 * @brief FPDParserGetSecurityCryptInfo
 * @details Gets encryption information including standard algorithm and key.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outCipher Receives cipher identifier (FPD_CIPHER_NONE, FPD_CIPHER_RC4 or FPD_CIPHER_AES).
 * @param[out]  outBuffer Receives a pointer to the key buffer.
 * @param[out]  outKeylen Receives number of bytes in the key.
 * @return   <a>TRUE</a> if successful. <a>FALSE</a> if no standard key info is provided or failure.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserGetSecurityCryptInfo, (FPD_Parser parser,  FS_INT32* outCipher,  FS_LPCBYTE* outBuffer,  FS_INT32* outKeylen))

/**
 * @brief FPDParserIsMetadataEncryptedBySecurity
 * @details Checks whether document metadata needs to be encrypted.
 * @param[in]  parser The PDF file parser.
 * @return   Whether document metadata needs to be encrypted.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserIsMetadataEncryptedBySecurity, (FPD_Parser parser))

/**
 * @brief FPDParserGetStandardSecurityUserPassword
 * @details Gets user password from an owner password.
 * @param[in]  parser The PDF file parser.
 * @param[in]  owner_pass The owner password pointer.
 * @param[in]  pass_size The length of the owner password.
 * @param[out]  outUserPsswrd Receives number of bytes in the key.
 * @return   It receives the correspond user password for this standard security handler.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(void, FPDParserGetStandardSecurityUserPassword, (FPD_Parser parser,  FS_LPCBYTE owner_pass,  FS_DWORD pass_size,  FS_ByteString* outUserPsswrd))

/**
 * @brief FPDParserGetStandardSecurityVersion
 * @details Gets the version of standard security.
 * @param[in]  parser The PDF file parser.
 * @return   The version of standard security.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FPDParserGetStandardSecurityVersion, (FPD_Parser parser))

/**
 * @brief FPDParserGetStandardSecurityRevision
 * @details Gets the revision of standard security.
 * @param[in]  parser The PDF file parser.
 * @return   The revision of standard security.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_INT32, FPDParserGetStandardSecurityRevision, (FPD_Parser parser))

/**
 * @brief FPDParserCheckStandardSecurityPassword
 * @details Checks whether the password is verified successfully.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password pointer.
 * @param[in]  pass_size The size of the password.
 * @param[in]  bOwner Whether check the owner password.
 * @param[out]  key Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
 * @return   <a>FALSE</a> for invalid password, <a>TRUE</a> for password verified.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 1.0
 */
INTERFACE(FS_BOOL, FPDParserCheckStandardSecurityPassword, (FPD_Parser parser,  FS_LPCBYTE password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

/**
 * @brief FPDParserCheckEmbeddedSecurity
 * @details Checks the access to the encrypted embedded file stream.
 * @param[in]  parser The PDF file parser.
 * @param[in]  name The name of the crypt filter that should be used by default when encrypting embedded file streams.
 * @return   The returned value can refer to <a>FPDParseErrCodes</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_DWORD, FPDParserCheckEmbeddedSecurity, (FPD_Parser parser,  FS_LPCSTR name))

/**
 * @brief FPDParserLoadAttachmentStream
 * @details Loads the attachment stream.
 * @param[in]  parser The PDF file parser.
 * @param[in]  objnum The object number of the attachment stream.
 * @param[out]  outStremObj It receives the pointer to the loaded attachment stream object.
 * @return   The returned value can refer to <a>FPDParseErrCodes</a>.
 * @note 
 * @since   <a>SDK_LATEEST_VERSION</a> > 2.1
 */
INTERFACE(FS_DWORD, FPDParserLoadAttachmentStream, (FPD_Parser parser,  FS_DWORD objnum,  FPD_Object* outStremObj))

/**
 * @brief FPDParserSetUnicodePassword
 * @details Set the unicode password of standard encryption for the parser.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input unicode password string.
 * @return   Zero means the unicode password strings include invalid characters.
 * @note Only the PDF2.0 supports for the Unicode-based passwords.
 */
INTERFACE(FS_BOOL, FPDParserSetUnicodePassword, (FPD_Parser parser,  const FS_WCHAR* password))

/**
 * @brief FPDParserGetUnicodePassword
 * @details Get the Unicode-based passwords.
 * @param[in]  parser The PDF file parser.
 * @param[out]  outPassword A buffer to receive the Unicode-based password string.
 * @return   void
 * @note Only the PDF2.0 supports for the Unicode-based passwords.
 */
INTERFACE(void, FPDParserGetUnicodePassword, (FPD_Parser parser,  FS_WideString* outPassword))

/**
 * @brief FPDParserCheckPassword
 * @details Check whether the password is verified successfully.
 * @param[in]  parser The PDF file parser.
 * @param[in]  password The input password pointer.
 * @param[in]  pass_size The size of the password.
 * @param[in]  bOwner Whether check the owner password
 * @param[out]  key Pointer to key buffer to receive the encryption key. NULL for don't calculate the key.
 * @return   FALSE for invalid password, TRUE for password verified.
 * @note Only the PDF2.0 supports for the Unicode-based CheckPassword.
 */
INTERFACE(FS_INT32, FPDParserCheckPassword, (FPD_Parser parser,  FS_LPCWSTR password,  FS_DWORD pass_size,  FS_BOOL bOwner,  FS_LPBYTE* key))

NumOfSelector(FPDParser)
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
