/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_docExpT.h
		
 - Types, macros, structures, etc. required to use the FPDLayer HFT.

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

#ifndef FPD_DOCEXPT_H
#define FPD_DOCEXPT_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FPD_PARSEREXPT_H
#include "fpd_parserExpT.h"
#endif

#ifndef FPD_OBJSEXPT_H
#include "fpd_objsExpT.h"
#endif

#ifndef FPD_RESOURCEEXPT_H
#include "fpd_resourceExpT.h"
#endif

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_RENDEREXPT_H
#include "fpd_renderExpT.h"
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* @OBJSTART FPD_Document */

/* @DEFGROUPSTART FPDLoadErrCodes */
	/**
	* @brief The error codes definitions for PDF loading.
	*/
/*@{*/
/** @brief Load document successfully. */
#define FPD_LOADERR_SUCCESS		0

/** @brief Out of memory. */
#define FPD_LOADERR_MEMORY		1

/** @brief Error of any kind, without specific reason. */
#define FPD_LOADERR_ERROR		2		

/** @brief Incorrect password. */
#define FPD_LOADERR_PASSWORD	3		

/** @brief Not PDF format. */
#define FPD_LOADERR_FORMAT		4

/** @brief File access error. */
#define FPD_LOADERR_FILE		5	

/** @brief Parameter error. */
#define FPD_LOADERR_PARAM		6

/** @brief Not in correct status. */
#define FPD_LOADERR_STATUS		7

/** @brief To be continued. */
#define FPD_LOADERR_TOBECONTINUED	8

/** @brief Not found. */
#define FPD_LOADERR_NOTFOUND	9
/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDDocPermissions */

	/**
	* @name PDF document permissions, according to PDF Reference, Table 3.20.
	* 1-2 bits must be zero, 7-8, 13-32 bits must be 1. 
	*/

	/*@{*/

	/**
	* @brief bit 3.
	*
	* <br><ul>
	* <li>- (Revision 2) Print the document.</li>
	* <li>- (Revision 3 or greater) Print the document (possibly not at the highest
	* quality level, depending on whether bit 12 is also set). </li>
	* </ul>
	*/
#define FPD_PERM_PRINT			0x0004
	/**
	* @brief bit 4. 
	*
	* Modify the contents of the document by operations other than 
	* those controlled by bits 6, 9, and 11.
	*/
#define FPD_PERM_MODIFY			0x0008
	/**
	* @brief bit 5.
	*
	* <br><ul>
	* <li>- (Revision 2) Copy or otherwise extract text and graphics from the 
	* document, including extracting text and graphics (in support of accessibility
	* to users with disabilities or for other purposes).</li>
	* <li>- (Revision 3 or greater) Copy or otherwise extract text and graphics 
	* from the document by operations other than that controlled by bit 10.</li>
	* </ul>
	*/
#define FPD_PERM_EXTRACT		0x0010
	/**
	* @brief bit 6. 
	*
	* Add or modify text annotations, fill in interactive form fields, and, 
	* if bit 4 is also set, create or modify interactive form fields (including signature fields).
	*/
#define FPD_PERM_ANNOT_FORM		0x0020
	/**
	* @brief bit 9. 
	*
	* (Revision 3 or greater) Fill in existing interactive form fields (including signature fields),
	* even if bit 6 is clear. 
	*/
#define FPD_PERM_FILL_FORM		0x0100
	/**
	* @brief bit 10. 
	*
	* (Revision 3 or greater) Extract text and graphics (in support of accessibility
	* to users with disabilities or for other purposes). 
	*/
#define FPD_PERM_EXTRACT_ACCESS	0x0200
	/**
	* @brief bit 11. 
	*
	* (Revision 3 or greater) Assemble the document (insert, rotate, or delete pages
	* and create bookmarks or thumbnail images), even if bit 4 is clear. 
	*/
#define FPD_PERM_ASSEMBLE		0x0400
	/**
	* @brief bit 12. 
	*
	* (Revision 3 or greater) Print the document to a representation from 
	* which a faithful digital copy of the PDF content could be generated. 
	* When this bit is clear (and bit 3 is set), printing is limited to a low-level
	* representation of the appearance, possibly of degraded quality. 
	* (See implementation note 25 in Appendix H.) 
	*/
#define FPD_PERM_PRINT_HIGH		0x0800

	/*@}*/ 

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDDocSaveFlags */

/**
 * @name Flags for saving PDF document.
 */
/*@{*/

/** @brief Default. */
#define FPD_SAVE_DEFAULT			0
/** @brief Incremental. */
#define FPD_SAVE_INCREMENTAL		1
/** @brief No original. */
#define FPD_SAVE_NO_ORIGINAL		2

/*@}*/

/* @DEFGROUPEND */


#ifndef FPD_DOCUMENT
#define	FPD_DOCUMENT
	/**
	* @brief The underlying PDF representation of a document.
	*
	* Each PDF document contains, among other things:<br>
	* <ul>
	* <li>- A tree of pages(<a>FPD_Page</a>).</li>
	* <li>- (Optional) Trees of bookmarks and articles.</li>
	* <li>- (Optional) Information and security dictionaries.</li>
	* </ul>
	* The FPD_Document object is the hidden object behind every FR_Document. 
	* Through FPD_Document objects, your application can perform most of the menu items for pages
	* from Foxit Phantom (delete, replace, and so on). Thumbnails and Bookmarks can be created and deleted
	* through this object. You can set and retrieve document information fields through this
	* object as well. The first page in a FPD_Document is page 0. See <a>FPDDocNew</a>, <a>FPDDocDestroy</a>, 
	* <a>FPDDocOpen</a>, <a>FPDDocOpenMemDocument</a>, <a>FPDDocClose</a>, <a>FPDPageGetDocument</a>.
	*/
	typedef struct _t_FPD_Document* FPD_Document;

#endif

/* @OBJEND */


/* @OBJSTART FDF_Document */
#ifndef FPD_FDFDOCUMENT
#define	FPD_FDFDOCUMENT
	/**
	* @brief The underlying FDF (Form Data Format) representation of a document.The file
	* format used for interactive form data.
	*
    * An FDF file is structured in essentially the same way as a PDF file but contains
	* only those elements required for the export and import of interactive form and
	* annotation data. It consists of three required elements and one optional element:
	* For more information, see Section 8.6 in the PDF Reference".
	* The FDF document can be created from scratch, or
	* parsed from a file or memory block. See <a>FPDFDFDocNew</a>, <a>FPDFDFDocOpenFromFile</a>, 
	* <a>FPDFDFDocPareMemory</a>.
	*/
	typedef struct _t_FDF_Document* FDF_Document;
#endif

/* @OBJEND */


/* @OBJSTART FPD_NameTree */
#ifndef FPD_NAMETREE
#define FPD_NAMETREE
	/**
	* @brief The dictionary used to store all of the Named Destinations in a PDF file.
	*
	* A name tree is used to map FS ByteString to FPD Objects.You create a FPD_NameTree 
	* and locate it where you think is appropriate (perhaps under a page, but most 
	* often right under the catalog). See <a>FPDNameTreeNew</a>, <a>FPDNameTreeNew2</a>, <a>FPDNameTreeDestroy</a>.
	*/
	typedef struct _t_FPD_NameTree* FPD_NameTree;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Bookmark */
/* @DEFGROUPSTART FPDBookmarkFontFlags */

	/**
	* @name Bookmark font flags.
	*/
	/*@{*/

	/** @brief Italic style. */
#define FPD_BOOKMARK_ITALIC			1
	/** @brief Bold style. */
#define FPD_BOOKMARK_BOLD			2

	/*@}*/

/* @DEFGROUPEND */

#ifndef FPD_BOOKMARK
#define FPD_BOOKMARK
	/**
	* @brief A bookmark corresponds to an outline object in a PDF document 
	* (<Italic>see Section 8.2.2, Document Outline, in the PDF Reference</Italic>). 
	*
	* Each bookmark has a title that appears on screen, and an action that specifies what happens 
	* when a user clicks on the bookmark.<br>
	*
	* Bookmarks can either be created interactively by the user through the
	* Foxit Reader user interface or programmatically generated. The typical action for a
	* user-created bookmark is to move to another location in the current document,
	* although any action (see FPD_Action) can be specified. See <a>FPDBookmarkNew</a>, <a>FPDBookmarkDestroy</a>.
	*/
	typedef struct _t_FPD_Bookmark* FPD_Bookmark;
#endif
/* @OBJEND */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// Destinations
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_Dest */
/* @DEFGROUPSTART FPDDestinationZoomMode */

	/**
	* @name Zoom mode for PDF destination. '/FitB', '/FitBH', '/FitBV' is not supported currently.
	*/

	/*@{*/

	/**
	* @brief Left, top, zoom.
	*
	* With the coordinates (left, top) positioned at 
	* the upper-left corner of the window and the contents of the page 
	* magnified by the factor zoom. 
	*/
#define FPD_ZOOM_XYZ					1
	/**
	* @brief Fit page.
	*
	* With its contents magnified just enough to fit the entire page
	* within the window both horizontally and vertically.
	*/ 
#define FPD_ZOOM_FITPAGE				2
	/**
	* @brief Fit horizontal. 
	*
	* With the vertical coordinate top positioned at the top edge
	* of the window and the contents of the page magnified just enough to fit 
	* the entire width of the page within the window.
	*/
#define FPD_ZOOM_FITHORZ				3
	/**
	* @brief Fit vertical. 
	*
	* With the horizontal coordinate left positioned at the left edge
	* of the window and the contents of the page magnified just enough to fit the 
	* entire height of the page within the window.
	*/
#define FPD_ZOOM_FITVERT				4
	/**
	* @brief Fit rectangle. 
	*
	* With its contents magnified just enough 
	* to fit the rectangle specified by the coordinates left, bottom, right, and top
	* entirely within the window both horizontally and vertically.
	*/
#define FPD_ZOOM_FITRECT				5

	/*@}*/

/* @DEFGROUPEND */


#ifndef FPD_DEST
#define FPD_DEST
	/**
	* @brief Corresponding to a PDF Dest array. 
	*
	* It contains a reference to a page, a
	* rectangle on that page, and information specifying how to adjust the view to fit the
	* window's size and shape. See <a>FPDDestNew</a>, <a>FPDDestDestroy</a>, <a>FPDBookmarkGetDest</a>, 
	* <a>FPDActionGetDest</a>, <a>FPDActionSetDest</a>, <a>FPDLinkGetDest</a>.
	*/
	typedef struct _t_FPD_Dest* FPD_Dest;
#endif

/* @OBJEND */

/* @OBJSTART FPD_OCContext */
/* @ENUMSTART */
	/** 
	* @name The usage type of optional content. See <a>FPDOCContextNew</a>.
	*/

	/*@{*/
	enum FPD_OCC_UsageType 
	{
		View = 0, /**< Used for a viewer . */
		Design, /**< Used to represent a document designer's structural organization of artwork. */
		Print,	/**< Used for printing. */
		Export	/**< Used for exporting. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	* @name State, for action type SetOCGState. See <a>FPDActionCountOCGStates</a>, <a>FPDActionGetOCGStates</a>, 
	* <a>FPDActionInsertOCGStates</a>, <a>FPDActionReplaceOCGStates</a>, <a>FPDActionRemoveOCGStates</a>.
	*/

	/*@{*/

	enum FPD_OCGState 
	{
		ON = 0,		/**< Sets the state of subsequent groups to ON. */
		OFF,		/**< Sets the state of subsequent groups to OFF. */
		Toggle		/**< Reverses the state of subsequent groups. */
	};

	/*@}*/
/* @ENUMEND */

#ifndef FPD_OCCONTEXT
#define FPD_OCCONTEXT
	/**
	* @brief A FPD_OCContext is an object that keeps track the on/off states of all of the OCGs
	* in a document.
	*
	* There can be more than one FPD_OCContext object, representing different combinations of OCG
	* states. The FPD_Document contains an internal FPD_OCContext that is used for on-screen 
	* drawing and as the default state used for any other drawing or content enumeration. <br>
	* Clients can change the states of OCGs within any FPD_OCContext. Clients can
	* build (and save in the PDF file) FPD_OCContext objects with their own combination of OCG 
	* states, and issue drawing or enumeration commands using their own FPD_OCContext instead of 
	* the document's internal FPD_OCContext. See <a>FPDOCContextNew</a>, <a>FPDOCContextDestroy</a>, 
	* <a>FPDOCContextGetDocument</a>, <a>FPDOCContextGetUsageType</a>, <a>FPDOCContextCheckOCGVisible</a>, 
	*<a>FPDOCContextResetOCContext</a>.
	*/
	typedef struct _t_FPD_OCContext* FPD_OCContext;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCGroup */
#ifndef FPD_OCGROUP
#define FPD_OCGROUP
	/**
	* @brief A FPD_OCGroup represents a named object whose state can be toggled in a user 
	* interface to affect changes in visibility of content.
	* 
	* The FPD_OCGroup object represents an optional-content group. This corresponds to a PDF OCG
	* dictionary representing a collection of graphic objects that can be made visible or invisible.
	* Any graphic content of the PDF can be made optional, including page contents, XObjects, and 
	* annotations. The specific content objects in the group have an OC entry in the PDF. 
	* See <a>FPDOCGroupNew</a>, <a>FPDOCGroupDestroy</a>, <a>FPDOCGroupSetIsSubGroupSet</a>.
	*/
	typedef struct _t_FPD_OCGroup* FPD_OCGroup;
#endif

/* @CALLBACKSTART FPD_OCGStateChangedNotify */
/** 
 * @brief A callback for Optional Content Notification <a>FPD_OCNotify</a> object. Triggered when OCG 
 * state has been changed.
 *
 * @param[in] doc		The PDF document.
 * @param[in] ocg		The optional content group object.
 * @param[in] bVisible	Whether the OCG is visible.
 * @return void
 * @note
	*/
	typedef void (*FPD_OCGStateChangedNotify)(FPD_Document doc, FPD_OCGroup ocg, FS_BOOL bVisible);	
/* @CALLBACKEND */
/* @OBJEND */

/* @OBJSTART FPD_OCGroupSet */
#ifndef FPD_OCGROUPSET
#define FPD_OCGROUPSET
	/**
	* @brief A set of mutually exclusive OCGs. See <a>FPDOCGroupSetNew</a>, <a>FPDOCGroupSetDestroy</a>, <a>FPDOCGroupSetIsSubGroupSet</a>, 
	*<a>FPDOCGroupSetGetGroup</a>, <a>FPDOCGroupSetFindGroup</a>.
	*/
	typedef struct _t_FPD_OCGroupSet* FPD_OCGroupSet;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCNotify */
#ifndef FPD_OCNOTIFY
#define FPD_OCNOTIFY
	/** 
	 * @brief Optional Content Notification Interface. See <a>FPDOCNotifyFPD_OCNotifyNew</a>, 
	 * <a>FPDOCNotifyFPD_OCNotifyDestroy</a>, <a>FPDOCPropertiesAddOCNotify</a>, <a>FPDOCPropertiesRemoveOCNotify</a>.
	 */
	typedef struct _t_FPD_OCNotify* FPD_OCNotify;
#endif
/* @OBJEND */

/* @OBJSTART FPD_OCProperties */
#ifndef FPD_OCPROPERTIES
#define FPD_OCPROPERTIES
	/**
	 * @brief The optional content properties dictionary for a document. See <a>FPDOCPropertiesNew</a>, 
	 * <a>FPDOCPropertiesDestroy</a>, <a>FPDOCPropertiesCountConfigs</a>, <a>FPDOCPropertiesGetConfig</a>, 
	 * <a>FPDOCPropertiesAddOCNotify</a>, <a>FPDOCPropertiesRemoveOCNotify</a>.
	 */
	typedef struct _t_FPD_OCProperties* FPD_OCProperties;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Action */
#ifndef FPD_ACTION
#define FPD_ACTION
	/** @brief Actions are what happens when a user clicks on a link or bookmark.  
	*
	* In addition,the Foxit Reader allows a document to have an action that is executed 
	* automatically when the document is opened. See <a>FPDActionNew</a>, <a>FPDActionNew2</a>, 
	* <a>FPDActionNew3</a>, <a>FPDActionDestroy</a>, <a>FPDAActionGetAction</a>, <a>FPDAActionGetNextAction</a>, 
	* <a>FPDDocJSActionsGetJSAction2</a>, <a>FPDLinkGetAction</a>, <a>FPDBookmarkGetAction</a>.
	*/
	typedef struct _t_FPD_Action* FPD_Action;
#endif

/* @DEFGROUPSTART FPDActionTypeNamed */
	/**
	* @name macros define, for action type Named.
	*/
	/*@{*/	

	/** @brief Go to the next page of the document. */
#define FPD_NAMED_NEXTPAGE		1
	/** @brief Go to the previous page of the document. */
#define FPD_NAMED_PREVPAGE		2
	/** @brief Go to the first page of the document. */
#define FPD_NAMED_FIRSTPAGE		3
	/** @brief Go to the last page of the document. */
#define FPD_NAMED_LASTPAGE		4

	/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDJavaScriptString */
/**
* @name macro for JavaScript string.
*/

/*@{*/
/** @brief macro for JavaScript string, maximum length. */
#define FPD_JS_MAXLENGTH			64
/*@}*/
/* @DEFGROUPEND */


/* @ENUMSTART */
	/**
	* @brief PDF Action Type Enumeration. See <a>FPDActionNew2</a>.
	*/

	enum FPD_ActionType
	{
		UnknownType = 0,/**< Unknown action type. */
		GoTo,			/**< Go-To Actions. */ 
		GoToR,			/**< Remote Go-To Actions. */
		GoToE,			/**< Embedded Go-To Actions. */
		Launch,			/**< Launch Actions. */
		Thread,			/**< Thread Actions. */
		URI,			/**< URI Actions. */
		Sound,			/**< Sound Actions. */
		Movie,			/**< Movie Actions. */
		Hide,			/**< Hide Actions. */
		Named,			/**< Named Actions. */
		SubmitForm,		/**< Submit-Form Actions. */
		ResetForm,		/**< Reset-Form Actions. */
		ImportData,		/**< Import-Data Actions. */
		JavaScript,		/**< JavaScript Actions. */
		SetOCGState,	/**< Set-OCG-State Actions. */
		Rendition,		/**< Rendition Actions. */
		Trans,			/**< Transition Actions. */
		GoTo3DView		/**< Go-To-3D-View Actions. */
};

/* @ENUMEND */

/* @OBJEND */


/* @OBJSTART FPD_LWinParam */
#ifndef FPD_LWINPARAM
#define FPD_LWINPARAM
	/** @brief A FPD_LWinParam represents a set of parameter on Windows desktop to launch an   
	* application or open or print a document. It is used by launch actions. See <a>FPDLWinParamNew</a>, 
	* <a>FPDLWinParamDestroy</a>, <a>FPDActionGetWinParam</a>.
	*
	*/
	typedef struct _t_FPD_LWinParam* FPD_LWinParam;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ActionFields */
#ifndef FPD_ACTIONFIELDS
#define FPD_ACTIONFIELDS
	/** 
	* @brief FPD_ActionFields represents the /Fields entry in submit-form actions dictionary.
	* We can use a FPD_ActionFields object to get field's information easily. See <a>FPDActionFieldsNew</a>, 
	* <a>FPDActionFieldsDestroy</a>, <a>FPDActionGetWidgets</a>.
	*/
	typedef struct _t_FPD_ActionFields* FPD_ActionFields;
#endif
/* @OBJEND */

/* @OBJSTART FPD_AAction */
#ifndef FPD_AACTION
#define FPD_AACTION 
	/** @brief Additional-action extends a set of events that can trigger the execution of an
	* actions. It is specified in /AA entry in a annotation, page object, interactive form
	* or document catalog. See <a>FPDAActionNew</a>, <a>FPDAActionDestroy</a>, 
	* <a>FPDFormFieldGetAdditionalAction</a>, <a>FPDFormControlGetAdditionalAction</a>.
	*
	*/
	typedef struct _t_FPD_AAction* FPD_AAction;
#endif

/* @ENUMSTART */
	/** @brief Additional-action type enumeration. */
	enum FPD_AActionType
	{
		CursorEnter = 0,	/**< E, cursor enters annotation, arbitrary action. */
		CursorExit,			/**< X, cursor exits annotation, arbitrary action. */
		ButtonDown,			/**< D, mouse button is pressed, arbitrary action. */
		ButtonUp,			/**< U, mouse button is released, arbitrary action. */
		GetInputFocus,		/**< Fo, annotation get input focus, arbitrary action. */
		LoseInputFocus,		/**< Bl, annotation loses input focus, arbitrary action. */
		PageOpen,			/**< PO, page is opened, executed after O, arbitrary action. */
		PageClose,			/**< PC, page is closed, executed before C, arbitrary action. */
		PageVisible,		/**< PV, page becomes visible, arbitrary action. */
		PageInvisible,		/**< PI, page is no longer visible, arbitrary action. */

		// additional actions defined in a page's dictionary.
		OpenPage,			/**< O, page is opened, arbitrary action. */
		ClosePage,			/**< C, page is closed, arbitrary action. */

		// additional actions defined in a form field's dictionary.
		KeyStroke,			/**< K, user types a key-stroke into field, JavaScript action. */
		Format,				/**< F, field is to be formatted, JavaScript action. */
		Validate,			/**< V, field is to be validated, JavaScript action. */
		Calculate,			/**< C, recalculate value, JavaScript action. */

		// additional actions defined in the document catalog's dictionary.
		CloseDocument,		/**< DC, before closing document, JavaScript action. */
		SaveDocument,		/**< WS, before saving document, JavaScript action. */
		DocumentSaved,		/**< DS, after saving document, JavaScript action. */
		PrintDocument,		/**< WP, before printing document, JavaScript action. */
		DocumentPrinted		/**< DP, after printing document, JavaScript action. */
	};
/* @ENUMEND */
/* @OBJEND */

/* @OBJSTART FPD_DocJSActions */
#ifndef FPD_DOCJSACTIONS
#define FPD_DOCJSACTIONS
	/** @brief A JavaScript action causes a script to be complied and executed by the JavaScript
	* interpreter. See <a>FPDDocJSActionsNew</a>, <a>FPDDocJSActionsDestroy</a>.
	*
	*/
	typedef struct _t_FPD_DocJSActions* FPD_DocJSActions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Link */
#ifndef FPD_LINK
#define FPD_LINK
	/** @brief A FPD_Link corresponds to a link annotation(see Sections 8.4.5, Annotation Types,
	* in the PDF Reference). See <a>FPDLinkNew</a>, <a>FPDLinkDestroy</a>
	* <a>FPDLinkGetLinkAtPoint</a>, <a>FPDLinkGetLink</a>.
	*
	*/
	typedef struct _t_FPD_Link* FPD_Link;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Annot */
/* @DEFGROUPSTART FPDAnnotationFlagBits */
	/**
	* @name Annotation flag bits.
	*/
	/*@{*/

	/**
	* @brief If set, do not display the annotation if it does not belong to one of the standard
	* annotation types and no annotation handler is available. If clear, display 
	* such an unknown annotation using an appearance stream specified by its appearance dictionary, if any.
	*/
#define FPD_ANNOTFLAG_INVISIBLE			1
	/**
	* @brief If set, do not display or print the annotation or allow it to interact 
	* with the user, regardless of its annotation type or whether an annotation 
	* handler is available.
	*/
#define FPD_ANNOTFLAG_HIDDEN			2
	/**
	* @brief If set, print the annotation when the page is printed. If clear, never 
	* print the annotation, regardless of whether it is displayed on the screen.
	*/
#define FPD_ANNOTFLAG_PRINT				4
	/**
	* @brief If set, do not scale the annotation's appearance to match the magnification of the page. 
	*/
#define FPD_ANNOTFLAG_NOZOOM			8
	/**
	* @brief If set, do not rotate the annotation's appearance to match the rotation of the page. 
	*/
#define FPD_ANNOTFLAG_NOROTATE			0x10
	/**
	* @brief If set, do not display the annotation on the screen or allow it to interact with the user.
	*/ 
#define FPD_ANNOTFLAG_NOVIEW			0x20
	/**
	* @brief If set, do not allow the annotation to interact with the user.
	*/
#define FPD_ANNOTFLAG_READONLY			0x40
	/**
	* @brief If set, do not allow the annotation to be deleted or its properties (including position and size) to be modified by the user. 
	*/
#define FPD_ANNOTFLAG_LOCKED			0x80
	/**
	* @brief If set, invert the interpretation of the NoView flag for certain events.
	*/
#define FPD_ANNOTFLAG_TOGGLENOVIEW		0x100

	/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
    /**
	* @brief Appearance mode enumeration of annotation. See <a>FPDAnnotDrawAppearance</a>, 
	* <a>FPDAnnotGetAPForm</a>, <a>FPDFormControlDrawControl</a>.
	*/
	enum FPD_AnnotAppearanceMode	
	{
		NormalAppearanceMode,		/**< Used when the annotation is not interacting with the user. This appearance is also used for printing the annotation. */
		RolloverAppearanceMode,		/**< Used when the user moves the cursor into the annotation's active area without pressing the mouse button. */ 
		DownAppearanceMode			/**< Used when the mouse button is pressed or held down within the annotation's active area. */
	};
/* @ENUMEND */


#ifndef FPD_ANNOT
#define FPD_ANNOT
	/** @brief An annotation on a page in a PDF file. See <a>FPDAnnotNew</a>, <a>FPDAnnotDestroy</a>
	* <a>FRAnnotGetPDAnnot</a>, <a>FPDAnnotListGetAt</a>.
	*
	*/
	typedef struct _t_FPD_Annot* FPD_Annot;
#endif
/* @OBJEND */

/* @OBJSTART FPD_AnnotList */
#ifndef FPD_ANNOTLIST
#define FPD_ANNOTLIST
	/** @brief An annotation accessor. See <a>FPDAnnotListNew</a>, <a>FPDAnnotListDestroy</a>.
	*
	*/
	typedef struct _t_FPD_AnnotList* FPD_AnnotList;
#endif
/* @OBJEND */

/* @OBJSTART FPD_DefaultAppearance */
#ifndef FPD_DEFUALTAPPEARANCE
#define FPD_DEFUALTAPPEARANCE

/*@brief Default appearance interpreter, serves for DA entry in form field dictionary.*/
	typedef struct _t_FPD_DefaultAppearance* FPD_DefaultAppearance;
#endif
/* @OBJEND */

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// Forms
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_FormControl */
#ifndef FPD_FORMCONTROL
#define FPD_FORMCONTROL
	/** @brief A FPD_FormControl is an appearance controller, it used to draw an annotation's
	* presentation on the page or set the appearance data to change an annotation's appearance.
	* See <a>FPDInterFormNewControl</a>, <a>FPDInterFormGetControl</a>, <a>FPDInterFormGetPageControl</a>, 
	* <a>FPDInterFormGetControlAtPoint</a>, <a>FPDInterFormGetControlByDict</a>, <a>FPDInterFormDeleteControl</a>.
	*
	*/
	typedef struct _t_FPD_FormControl* FPD_FormControl;
#endif

/* @DEFGROUPSTART FPDFieldTypes */
	/**
	* @name macros definition for field types in CreateControl method.
	* Note: They are used in some interfaces about FPD_InterForm, especially for JavaScript.
	*/
	/*@{*/

	/** @brief Unknown. */
#define FPD_FORM_FIELDTYPE_UNKNOWN			0
	/** @brief Push button. */
#define FPD_FORM_FIELDTYPE_PUSHBUTTON		1
	/** @brief Check box. */
#define FPD_FORM_FIELDTYPE_CHECKBOX			2
	/** @brief Radio button. */
#define FPD_FORM_FIELDTYPE_RADIOBUTTON		3
	/** @brief Combo box. */
#define FPD_FORM_FIELDTYPE_COMBOBOX			4
	/** @brief List box. */
#define FPD_FORM_FIELDTYPE_LISTBOX			5
	/** @brief Text field. */
#define FPD_FORM_FIELDTYPE_TEXTFIELD		6
	/** @brief Signature. */
#define FPD_FORM_FIELDTYPE_SIGNATURE		7

	/*@}*/

/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_FormField */
#ifndef FPD_FORMFIELD
#define FPD_FORMFIELD
	/** @brief A field in a interactive form. See <a>FPDInterFormNewField</a>, 
	* <a>FPDInterFormGetField</a>, <a>FPDInterFormGetFieldByDict</a>, 
	* <a>FPDInterFormDeleteField</a>, <a>FPDInterFormDeleteField2</a>.
	*/
	typedef struct _t_FPD_FormField* FPD_FormField;
#endif

/* @DEFGROUPSTART FPDFormFieldFlags */
	/**
	* @name Form field flags.
	*/
	/*@{*/

	/** @brief This field is read only, no editing allowed. */
#define FPD_FORM_FIELD_READONLY		0x01
	/** @brief This field is required when submit. */
#define FPD_FORM_FIELD_REQUIRED		0x02
	/** @brief Don't export the field when submitting. Not supported for now. */
#define FPD_FORM_FIELD_NOEXPORT		0x04

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDRadioButtonAdditionalFlags */

	/**
	* @name Additional flags for radio button fields.
	*/
	/*@{*/

	/**
	* @brief For radio button only: if set, one radio button has to be selected at any time;
	* Otherwise, when the selected radio button is clicked, it will be turned off,
	* (leaving no radio button selected at this time).
	*/
#define FPD_FORM_RADIO_NOTOGGLEOFF	0x100
	/**
	* @brief If set, radio buttons with same value in a field will be turned on or off
	* in unison (either all one, or all off). If cleared, all buttons are 
	* mutually exclusive.
	*/
#define FPD_FORM_RADIO_UNISON		0x200

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDTextFieldsAdditionalFlags */

	/**
	* @name Additional flags for text fields.
	*/
	/*@{*/

	/** @brief Multiple lines. */
#define FPD_FORM_TEXT_MULTILINE		0x100
	/** @brief This is a password field. Password shouldn't be displayed or exported. */
#define FPD_FORM_TEXT_PASSWORD		0x200
	/**
	* @brief Do not scroll (vertically for multi-line field, or horizontally for
	* single-line field). If the field is full, no more text is accepted.
	*/
#define FPD_FORM_TEXT_NOSCROLL		0x400
	/**
	* @brief If set, this field is arranged in a number of equally spaced positions
	* ("combs"), the number of positions is determined by MaxLen parameter.
	*/
#define FPD_FORM_TEXT_COMB			0x800

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDComboBoxFieldsAdditionalFlags */

	/**
	* @name Additional flags for combo box fields.
	*/
	/*@{*/

	/**
	* @brief (Meaningful only when FORMCHOICE_COMBO flag is set): if set, the combo box
	* includes an editable text control, otherwise, it's only a drop list.
	*/
#define FPD_FORM_COMBO_EDIT			0x100

	/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDListBoxFieldsAdditionalFlags */

	/**
	* @name Additional flags for list box fields.
	*/
	/*@{*/

	/** @brief If set, more than one items can be selected. */
#define FPD_FORM_LIST_MULTISELECT	0x100

	/*@}*/

/* @DEFGROUPEND */

/* @ENUMSTART */
	/**
	  * @name PDF interactive form field type enumeration. See <a>FPDFormFieldGetType</a>.
	  */

	/*@{*/

	enum FPD_FormFieldType 
	{
		FormField_Unknown,			/**< unsupported or invalid field. */
		FormField_PushButton,		/**< push button without any value. */
		FormField_RadioButton,		/**< a group of radio buttons, at most one item can be selected. */
		FormField_CheckBox,			/**< check box with on/off states. */
		FormField_TextField,		/**< single line or multi-line texts. */
		FormField_RichText,			/**< rich text (using XML to store rich text). */
		FormField_File,				/**< file content. */
		FormField_ListBox,			/**< list box, single or multiple selections. */
		FormField_ComboBox,			/**< combo box with or without the edit box. */
		FormField_Sign				/**< digital signature. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	  * @name Scale method enumeration. 
	  * @brief The circumstances under which the icon should be scaled inside the annotation rectangle. See <a>FPDIconFitSetScaleMethod</a>.
	  */

	/*@{*/

	enum FPD_IconScaleMethod
	{
		IconScaleMethod_Always = 0,		/**< A, Always scale. */
		IconScaleMethod_Bigger,			/**< B, Scale only when the icon is bigger than the annotation rectangle. */
		IconScaleMethod_Smaller,		/**< S, Scale only when the icon is smaller then the annotation rectangle. */
		IconScaleMethod_Never			/**< N, Never scale. */
	};
	/*@}*/
/* @ENUMEND */

/* @DEFGROUPSTART FPDFormFieldTextPosition */

	/**
	* @name Text Position definition, for "TP" entry in MK of Widget dictionary.
	*/
	/*@{*/

	/** @brief no icon, caption only. */
#define FPD_TEXT_POS_CAPTION		0
	/** @brief no caption, icon only. */
#define FPD_TEXT_POS_ICON		1
	/** @brief caption below the icon. */
#define FPD_TEXT_POS_BELOW		2
	/** @brief caption above the icon. */
#define FPD_TEXT_POS_ABOVE		3
	/** @brief caption to the right of the icon. */
#define FPD_TEXT_POS_RIGHT		4
	/** @brief caption to the left of the icon. */
#define FPD_TEXT_POS_LEFT		5
	/** caption overlaid directly on the icon. */
#define FPD_TEXT_POS_OVERLAID	6

	/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */

	/**
	  * @brief HighLighting mode definition, for annotation or control. See <a>FPDFormControlGetHighlightingMode</a>.
	  */

	/*@{*/

	enum FPD_FormCtrlHighlightingMode	
	{
		FormCtrlHL_None = 0,	/**< (None) No highlighting. */

		FormCtrlHL_Invert,		/**< (Invert) Invert the contents of the annotation rectangle. */

		FormCtrlHL_Outline,		/**< (Outline) Invert the annotation's border. */

        /**< (Push) Display the annotation's down appearance, if any; 
		If no down appearance is defined, offset the contents of the annotation rectangle 
		to appear as if it were being pushed below the surface of the page. */
		FormCtrlHL_Push,		
								
		FormCtrlHL_ToggleMode		/**< (Toggle) Same as P (which is preferred). */
	};

	/*@}*/
/* @ENUMEND */

/* @OBJEND */

/* @OBJSTART FPD_InterForm */

/* @DEFGROUPSTART FPDInterFormColorTypes */
	/**
	* @name macros definition for color types in interactive form.
	* used for color operator like G/g, RG/rg, K/k, or "BC"/"BG" entries in MK of Widget dictionary, etc...
	*/
	/*@{*/

	/** @brief Transparent. */
#define FPD_CLRTYPE_TRANSPARENT		0
	/** @brief Gray. */
#define FPD_CLRTYPE_GRAY			1
	/** @brief RGB. */
#define FPD_CLRTYPE_RGB				2
	/** @brief CMYK. */
#define FPD_CLRTYPE_CMYK			3

	/*@}*/
/* @DEFGROUPEND */

#ifndef FPD_INTERFORM
#define FPD_INTERFORM
	/** @brief A PDF interactive form (AcroForm) object. 
	*
	* It is a collection of fields for gathering
	* information interactively form user. A FPD_Document object may contain any number of fields 
	* appearing on any combination of pages, all of which make up a single, global interactive 
	* form spanning the entire document.
	*
	* @note FPD_InterForm should not be confused with <a>FPD_Form</a> object, <a>FPD_Form</a> is a form XObjects.
	* See <a>FPDInterFormNew</a>, <a>FPDInterFormDestroy</a>.
	*/
	typedef struct _t_FPD_InterForm* FPD_InterForm;
#endif
/* @OBJEND */

/* @OBJSTART FPD_IconFit */
#ifndef FPD_ICONFIT
#define FPD_ICONFIT
	/** @brief A FPD_IconFit represents a set of icon that specifying how to display the widget
	*	annotation's icon within its annotation rectangle. See <a>FPDIconFitNew</a>, <a>FPDIconFitDestroy</a>.
	*
	*/
	typedef struct _t_FPD_IconFit* FPD_IconFit;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FormNotify */
#ifndef FPD_FORMNOTIFY
#define FPD_FORMNOTIFY
	/** @brief A object representing a form notify handler. 
	*
	* It is a event trigger for modifying form element. See <a>FPDInterFormGetFormNotify</a>, <a>FPDInterFormSetFormNotify</a>.
	*/
	typedef struct _t_FPD_FormNotify* FPD_FormNotify;
#endif

/* @CALLBACKGROUPSTART FPD_FormNotifyCallbacks */
	/** @brief A set of callbacks for PDF form notify handler. */
	typedef struct _fpd_formnotify_callbacks_
	{
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_FormNotifyCallbacksRec</a>) */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART BeforeValueChange */
		/**
		* @brief Triggered before a value changing.
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field which will be changed.
		* @param[in] csValue	The value to change to.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeValueChange)(FS_LPVOID clientData, FPD_FormField field, FS_WideString csValue);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterValueChange */
		/**
		* @brief Triggered after a value changed.
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field which was just changed.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterValueChange)(FS_LPVOID clientData, FPD_FormField field);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeSelectionChange */
		/**
		* @brief Triggered before the selection changing.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field who's selection will be changed.
		* @param[in] csValue	The option label to change to.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeSelectionChange)(FS_LPVOID clientData, FPD_FormField field, FS_WideString csValue);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterSelectionChange */
		/**
		* @brief Triggered after the selection changed.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field		The field who's selection was just changed.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterSelectionChange)(FS_LPVOID clientData, FPD_FormField field);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterCheckedStatusChange */
		/**
		* @brief Triggered after the checked status changed.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] field			The field who's checked status was just changed.
		* @param[in] statusArray	The changed status array.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterCheckedStatusChange)(FS_LPVOID clientData, FPD_FormField field, FS_ByteArray statusArray);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeFormReset */
		/**
		* @brief Triggered before form resetting.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form to reset.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeFormReset)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterFormReset */
		/**
		* @brief Triggered after form reset.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form who has just reset.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterFormReset)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART BeforeFormImportData */
		/**
		* @brief Triggered before form importing data.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form to import data.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*BeforeFormImportData)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

		/* @CALLBACKSTART AfterFormImportData */
		/**
		* @brief Triggered after form data imported.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] form		The interactive form who has just imported data.
		* @return Non-zero means event resolved.
		* @note
		*/
		FS_INT32		(*AfterFormImportData)(FS_LPVOID clientData, FPD_InterForm form);
		/* @CALLBACKEND */

	}FPD_FormNotifyCallbacksRec, *FPD_FormNotifyCallbacks;
/* @CALLBACKGROUPEND */
/* @OBJEND */


/* @OBJSTART FPD_MediaPlayer */
/* @ENUMSTART */
	/**
	  * @brief PDF media permission type enumeration.
	  *
	  * Indicates the circumstances under which it is acceptable to write a temporary file in order to play a media clip.
	  * See <a>FPDRenditionGetPermission</a>.
	  */

	/*@{*/

	enum FPD_MediaPermission 
	{
		TempNever = 0,		/**< Never allowed. */
		TempExtract,		/**< Allowed only if the document permissions allow content extraction. */
		TempAccess,			/**< Allowed only if the document permissions allow content extraction, including for accessibility purposes. */
		TempAlways			/**< Always allowed. */
	};

	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/** 
	  * @name PDF media play parameter type enumeration. See <a>FPDRenditionSetVolumn</a>.
	  */

	/*@{*/
	enum FPD_MediaPlayParamType 
	{
		MustBeHonored = 0,		/**< Must be honored for the media play parameters to be considered viable. */
		BestEffort				/**< Need only be honored in a "best effort" sense. */
	};
	/*@}*/
/* @ENUMEND */

/* @ENUMSTART */
	/**
	  * @name Enumeration of PDF media player classified type in PDF Media Players dictionary. See <a>FPDRenditionCountMediaPlayers</a>, 
	  * <a>FPDRenditionGetMediaPlayer</a>, <a>FPDRenditionAddMediaPlayer</a>, <a>FPDRenditionRemoveMediaPlayer</a>.
	  */

	/*@{*/
	enum FPD_MediaPlayerType
	{
		MustUsed = 0,		/**< Which must be used in playing the associated media object. */
		Available,			/**< Which may be used in playing the associated media object. */
		NotUsed				/**< Which must not be used in playing the associated media object. */
	};
	/*@}*/
/* @ENUMEND */

#ifndef FPD_MEDIAPLAYER
#define FPD_MEDIAPLAYER
	/** @brief A media player information object. See <a>FPDMediaNew</a>, <a>FPDMediaNewFromDict</a>, <a>FPDMediaDestroy</a>.
	*
	*/

	typedef struct _t_FPD_MediaPlayer* FPD_MediaPlayer;
#endif
/* @OBJEND */

/* @OBJSTART FPD_Rendition */
#ifndef FPD_RENDITION
#define FPD_RENDITION
	/** @brief A Rendition object. See <a>FPDRenditionNew</a>, <a>FPDRenditionNewFromDict</a>, <a>FPDRenditionDestroy</a>.
	*/
	typedef struct _t_FPD_Rendition* FPD_Rendition;
#endif
/* @OBJEND */


	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	// File access
	//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

/* @OBJSTART FPD_FileSpec */
#ifndef FPD_FILESPEC
#define FPD_FILESPEC
	
/*@brief PDF file specification object.
 *A FPD_FileSpec corresponds to the PDF file specification object (see Section 3.10, File 
 *Specifications, in the PDF Reference). It is used to specify a file in an action.
 */
	typedef struct _t_FPD_FileSpec* FPD_FileSpec;

#endif
/* @OBJEND */
	
/* @OBJSTART FPD_EnumPageHandler */
#ifndef FPD_ENUMPAGEHANDLER
#define FPD_ENUMPAGEHANDLER
  /** @brief A handler to enumerate the count of pages for a document. See <a>FPDDocNewEnumPageHandler</a>, <a>FPDDocDeleteEnumPageHandler</a>.
	*
	*/
	typedef struct _t_FPD_EnumPageHandler* FPD_EnumPageHandler;
#endif

/* @CALLBACKGROUPSTART FPD_EnumPage */
#ifndef FPD_ENUMPAGE
#define FPD_ENUMPAGE
	/** @brief A callback for <a>FPD_EnumPageHandler</a>. See <a>FPDDocEnumPages</a>.
	*/
	typedef struct
	{	
		/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_EnumPage</a>).  */
		unsigned long lStructSize;

		/** The user-supplied data. */
		FS_LPVOID		clientData;

		/* @CALLBACKSTART EnumPage */
		/**
		* @brief Enumerates page function for call back.
		*
		* Enumerates page function for call back. Returns <a>TRUE</a> if you want the enumeration to continue.
		*
		* @param[in] clientData	The user-supplied data.
		* @param[in] pageDict	The page dictionary. 
		* @return Non-zero means you want the enumeration to continue, otherwise want not.
		* @note
		*/
		FS_BOOL (*EnumPage)(FS_LPVOID clientData, FPD_Object pageDict);
		/* @CALLBACKEND */
	}FPD_EnumPage,*PFPD_EnumPage;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_ConnectedInfo */
#ifndef FPD_CONNECTEDINFO
#define FPD_CONNECTEDINFO
	/** @brief The connected PDF info object can get connected PDF document ID and version ID etc.
	* Typical usage of this object is to get and set connected PDF info.
	*
	*/
	typedef struct _t_FPD_ConnectedInfo* FPD_ConnectedInfo;
#endif

/* @DEFGROUPSTART FPDConnectedInfoIdTypes */
	/**
	* @brief The Id types of connected PDF info object.
	*/
/*@{*/
/** @brief It is document Id. */
#define FPD_CONNECT_DOCUMENTID					0x01

/** @brief It is version Id. */
#define FPD_CONNECT_VERSIONID					0x02

/** @brief It is review Id. */
#define FPD_CONNECT_REVIEWID					0x03
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDConnectedInfoTrackingTypes */
	/**
	* @brief The tracking types of connected PDF info object.
	*/
/*@{*/
/** @brief Tracking printing. */
#define FPD_CONNECT_PRINTING	0x0001

/** @brief Tracking filling form. */
#define FPD_CONNECT_FORMFILL	0x0002

/** @brief Tracking commenting. */
#define FPD_CONNECT_COMMENT		0x0004

/** @brief Tracking pages. */
#define FPD_CONNECT_PAGES		0x0008

/** @brief Tracking bookmarks. */
#define FPD_CONNECT_BOOKMARKS	0x0010

/** @brief Tracking copying. */
#define FPD_CONNECT_COPY		0x0020

/** @brief Tracking signing. */
#define FPD_CONNECT_SIGN		0x0040

/** @brief Tracking extracting. */
#define FPD_CONNECT_EXTRACT		0x0080
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDConnectedOpenActionURLTypes */
	/**
	* @brief The open action URL types of connected PDF info object.
	*/
/*@{*/
/** @brief Update open message. */
#define FPD_CONNECT_SUBMIT_UPDATE				0x01
/** @brief Receives open message. */
#define FPD_CONNECT_SUBMIT_RECEIVE				0x02
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

/* @OBJSTART FPD_WrapperDoc */
#ifndef FPD_WRAPPERDOC
#define FPD_WRAPPERDOC
	typedef struct _t_FPD_WrapperDoc* FPD_WrapperDoc;

/* @DEFGROUPSTART FPDWrapperDocGetWrapperType */
	/**
	* @brief The Id types of connected PDF info object.
	*/
/*@{*/
	/** @brief Normal document. */
#define  FPD_WRAPPERTYPE_NO		 0
	/** @brief For Foxit wrapper document. */
#define  FPD_WRAPPERTYPE_FOXIT	 1
	/** @brief For PDF2.0 wrapper document. */
#define  FPD_WRAPPERTYPE_PDF2	 2
#endif
/*@}*/
/* @DEFGROUPEND */

/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif
/*@}*/ 


/*@}*/