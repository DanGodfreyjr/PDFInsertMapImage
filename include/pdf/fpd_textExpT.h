/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_textExpT.h
		
 - Types, macros, structures, etc. 

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @file
* @brief Text extracting and searching, Link extracting.
*/

/** @addtogroup FPDTEXT*/
/*@{*/
#ifndef FPD_TEXTEXPT_H
#define FPD_TEXTEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FPD_ProgressiveSearch */
/* @DEFGROUPSTART FPDSearchingStatus */
/** 
  * @name Searching status for progressive searching. See <a>FPDProgressiveSearchGetStatus</a>.
  */

/*@{*/

/** @brief Ready. */
#define FPD_SCH_STATUS_READY		 0 
/** @brief To be continued. */
#define FPD_SCH_STATUS_TOBECONTINUED 1 
/** @brief Found. */
#define FPD_SCH_STATUS_FOUND		 2 
/** @brief Not found. */
#define FPD_SCH_STATUS_NOTFOUND		 3 
/** @brief Failed. */
#define FPD_SCH_STATUS_FAILED		 4 
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDSearchFlags */
/**
* @name Search flags. See <a>FPDTextPageFindFindFirst</a>, <a>FPDTextPageFindFindNext</a>, <a>FPDTextPageFindFindPrev</a>.
*/

/*@{*/

/** @brief Whether to match the character case(upper/lower).*/
#define FPD_TEXT_MATCHCASE      0x00000001

/** @brief Whether to match the whole word for the search pattern.*/
#define FPDTEXT_MATCHWHOLEWORD 0x00000002

/** @brief Whether to do consecutive searching. */
#define FPDTEXT_CONSECUTIVE	0x00000004

/*@}*/
/* @DEFGROUPEND */

/**
  * @brief A progressive search facility for stream-based text searching inside a single page.
  * See <a>FPDProgressiveSeaarchNew</a>, <a>FPDProgressiveSeaarchDestroy</a>.
  */
#ifndef FPD_PROGRESSIVESEARCH
#define FPD_PROGRESSIVESEARCH
typedef struct _t_FPD_ProgressiveSearch* FPD_ProgressiveSearch;
#endif
/* @OBJEND */

/* @OBJSTART FPD_TextPage */
/* @DEFGROUPSTART FPDCharInfoFlag */
/**
  * @name char info flag.
  */

/*@{*/

/** @brief error. */
#define FPD_CHAR_ERROR		   -1	
/** @brief normal. */
#define FPD_CHAR_NORMAL			0	
/** @brief generated. */
#define FPD_CHAR_GENERATED		1
/** @brief ununicode. */
#define FPD_CHAR_UNUNICODE		2	

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FPD_CHAR_INFO */
/** @brief Character info for TextPage. */
typedef struct 
{
	/**  Unicode for the character. */
	FS_WCHAR			m_Unicode;	
	
	/** Character's flag. */
	FS_BOOL				m_Flag;	
	
	/**  The font size. */
	FS_FLOAT			m_FontSize;	
	
	/** The x-coordinate of the origin position. */
	FS_FLOAT			m_OriginX;	
	
	/** The y-coordinate of the origin position. */
	FS_FLOAT			m_OriginY;
	
	/** The character box. int page space. */
	FS_FloatRect		m_CharBox;
	
	/**  Which text object it belongs to. */
	FPD_PageObject		m_pTextObj;	
	
	/**  The matrix. */
	FS_AffineMatrix		m_Matrix;		
} FPD_CHAR_INFO;
/* @STRUCTEND */

/* @DEFGROUPSTART FPDTextPageFlags */
/**
  * @name Flags for creating text page. See <a>FPDTextNew</a>.
  */
/*@{*/

/** @brief Stream order. */
#define FPD_TEXT_STREAM_ORDER	0

/** @brief Display(appearance) order. */
#define FPD_TEXT_DISPLAY_ORDER	1

/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDTextDirectionsType */
/**
  * @name Directions type. See <a>FPDTextGetOrderByDirection</a>.
  */
/*@{*/

/** @brief Left direction. */
#define FPD_TEXT_LEFT			-1
/** @brief Right direction. */
#define FPD_TEXT_RIGHT			1
/** @brief Up direction. */
#define FPD_TEXT_UP				-2
/** @brief Down direction. */
#define FPD_TEXT_DOWN			2

/*@}*/
/* @DEFGROUPEND */

/** 
  * @brief Text page for PDF text processing. See <a>FPDTextNew</a>, <a>FPDTextDestroy</a>.
  */
#ifndef FPD_TEXTPAGE
#define FPD_TEXTPAGE
typedef struct _t_FPD_TextPage* FPD_TextPage;
#endif
/* @OBJEND */

/* @OBJSTART FPD_TextPageFind */
/**
  * @brief To find a text in a page. See <a>FPDTextPageFindNew</a>, <a>FPDTextPageFindDestroy</a>.
  */
#ifndef FPD_TEXTPAGEFIND
#define FPD_TEXTPAGEFIND
typedef struct _t_FPD_TextPageFind* FPD_TextPageFind;
#endif
/* @OBJEND */

/* @OBJSTART FPD_LinkExtract */
/** 
  * @brief A link extractor for accessing links. See <a>FPDLinkExtractNew</a>, <a>FPDLinkExtractDestroy</a>.
  */
#ifndef FPD_LINKEXTRACT
#define FPD_LINKEXTRACT
typedef struct _t_FPD_LinkExtract* FPD_LinkExtract;
#endif
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/*@}*/

/*@}*/
