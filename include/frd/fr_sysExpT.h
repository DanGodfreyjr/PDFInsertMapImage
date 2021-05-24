/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.	

*********************************************************************/


/**
 * @defgroup FRLayer Foxit Reader Layer
 */

/*@{*/

/** @file fr_sysExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRSYS
 * @{
 */

#ifndef FR_SYSEXPT_H
#define FR_SYSEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @COMMONSTART */

/* @STRUCTSTART FR_MSGBOX_CHECKBOXPARAMS*/
#ifndef _FR_MSGBOX_CHECKBOXPARAMS
#define _FR_MSGBOX_CHECKBOXPARAMS
/**
* @brief A data structure representing the params of the check box on the message box.
*
*/
typedef struct __fr_msgbox_checkboxparams__
{
	/** Whether show the check box or not. */
	FS_BOOL bShowCheckBox;
	/** The text of the check box. */
	FS_LPCWSTR wszCheckBoxText;
	/** Whether the check box is checked or not. */
	FS_BOOL bIsChecked;
}FR_MSGBOX_CHECKBOXPARAMS, *PFR_MSGBOX_CHECKBOXPARAMS;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_WINDIB_Open_Args_ */
/** @brief A structure used to indicate how to open a new image file or stream. */
typedef struct _FR_WINDIB_Open_Args_
{
	/**A set of bit flags indicating how to use the structure.*/
    FS_INT32         flags;
    /** The first byte of the file in memory.*/
    const FS_BYTE*  memory_base;
	/** The size in bytes of the file in memory.*/
    FS_DWORD    memory_size;
    /** A pointer to an 16-bit file pathname. */
    FS_LPCWSTR  path_name;	
}FR_WINDIB_Open_Args;
/* @STRUCTEND */

/* @COMMONEND */

/* @OBJSTART FR_Sys*/
/**
 * @brief It is used to manage the APIs of system-dependent. See <a>FRSysLoadStandarCursor</a>, <a>FRSysGetCursor</a>, <a>FRSysSetCursor</a>.
 */
typedef struct _t_FR_Sys* FR_Sys;
/* @OBJEND */

/* @OBJSTART FR_Cursor */
#ifndef FR_CURSOR
#define FR_CURSOR
/**
 * @brief A data structure representing the cursor.
 */
typedef struct _t_FR_Cursor* FR_Cursor;
#endif


/* @DEFGROUPSTART FRCursorTypeFlags */
/**
 * @brief Flags used for windows stander cursor.
 */

/*@{*/

/**  
 * @brief Standard arrow cursor  See <a>FRSysLoadStandarCursor</a>.
 */
#define FR_CURSOR_TYPE_ARROW		0

/**  @brief Cross-hair cursor for selection  */
#define FR_CURSOR_TYPE_CROSS		1

/**  @brief Help cursor */
#define FR_CURSOR_TYPE_HELP			2

/**  @brief A four-pointed arrow. The cursor to use to resize a window.  */
#define FR_CURSOR_TYPE_SIZEALL		3

/**  @brief Two-headed arrow with ends at upper right and lower left. */
#define FR_CURSOR_TYPE_SIZENESW		4

/**  @brief Vertical two-headed arrow. */
#define FR_CURSOR_TYPE_SIZENS		5

/**  @brief Two-headed arrow with ends at upper left and lower right.  */
#define FR_CURSOR_TYPE_SIZENWSE		6
	
/**  @brief Horizontal two-headed arrow. */
#define FR_CURSOR_TYPE_SIZEWE		7
	
/**  @brief Arrow that points straight up. */
#define FR_CURSOR_TYPE_UPARROW		8

/**  @brief Hourglass cursor used when Windows performs a time-consuming task.  */
#define FR_CURSOR_TYPE_WAIT			9

/*@}*/
/* @DEFGROUPEND */


/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/*@}*/ 

/*@}*/ 