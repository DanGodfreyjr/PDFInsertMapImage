/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_parserExpT.h
		
 - The basic PDF file parser, etc. required to use the FPDLayer HFT.

*********************************************************************/
/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/


/**
  * @addtogroup FPDDOCUMENT
  * @{
  */


/**
* @file
* @brief data types for PDDoc layer
*/


#ifndef FPD_PARSEREXPT_H
#define FPD_PARSEREXPT_H


#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "fpd_docExpT.h"
#endif



#ifdef __cplusplus
extern "C" {
#endif


/* @OBJSTART FPD_Parser */

/* @DEFGROUPSTART FPDParseErrCodes */
/**
 * @name Reasons for PDF parsing failure: returned by <a>FPDParserStartParse</a>() function.. 
 */
 /*@{*/

/** @brief no error. */
#define FPD_PARSE_ERROR_SUCCESS		0
/** @brief file error: not found or could not be opened. */
#define FPD_PARSE_ERROR_FILE		1
/** @brief format error: not a PDF or corrupted. */
#define FPD_PARSE_ERROR_FORMAT		2
/** @brief Invalid password. Please input again. */
#define FPD_PARSE_ERROR_PASSWORD	3
/** @brief This document is encrypted by some unsupported security handler. */
#define FPD_PARSE_ERROR_HANDLER		4
/** @brief This document is encrypted by digital certificate and current user doesn't have correct certificate. */ 
#define FPD_PARSE_ERROR_CERT		5

/*@}*/ 
/* @DEFGROUPEND */


/* @DEFGROUPSTART FPDParseContextFlags */
/**
 * @name Flags for parser context. 
 */
 /*@{*/

/** @brief Type only. */
#define FPD_PARSE_TYPEONLY	1
/** @brief No stream. */
#define FPD_PARSE_NOSTREAM	2

/*@}*/ 
/* @DEFGROUPEND */

/* @STRUCTSTART FPD_PARSE_CONTEXT */

#ifndef FPD_PARSE_CONTEXT_STRUCT
#define FPD_PARSE_CONTEXT_STRUCT
/** @brief Structure for parser context. */
typedef struct _FPD_PARSE_CONTEXT_
{
	/** The flags for parser context. */
	FS_BOOL		flags;
	/** The start position of the dictionary. */
	FS_DWORD	dictStart;
	/** The end position of the dictionary. */
	FS_DWORD	dictEnd;
	/** The start position of the data. */
	FS_DWORD	dataStart;
	/** The end position of the data. */
	FS_DWORD	dataEnd;
}FPD_PARSE_CONTEXT;

#endif






#ifndef FPD_PARSER
#define FPD_PARSER
	/**
	* @brief The PDF file parser to parse a pdf file to get a <a>FPD_Document</a>.
	*
	* Each PDF file need a FPD_Parser to parse the content, call <a>FPDParserStartParse</a> to
	* start to parse a file. See <a>FPDParserNew</a>, <a>FPDParserDestroy</a>.
	*/
	
	typedef struct _t_FPD_Parser* FPD_Parser;
#endif
/* @OBJEND */



#ifdef __cplusplus
};
#endif

#endif