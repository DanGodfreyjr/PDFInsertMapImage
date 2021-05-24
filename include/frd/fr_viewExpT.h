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

/** @file fr_viewExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRVIEW
 * @{
 */
#ifndef FR_VIEWEXPT_H
#define FR_VIEWEXPT_H

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FR_DocView */
#ifndef FR_DOCVIEW
#define FR_DOCVIEW
/**
* @brief A <a>FR_DocView</a> is the area of the Foxit Reader window that displays the contents of a document page. Every 
* <a>FR_DocView</a> may have more than one <a>FR_PageView</a>. It contains references to the <a>FPD_Document</a> 
* for the document being displayed. <br>
*
* <a>FR_DocView</a> has methods to display a page, select a zoom factor, scroll the page displayed inside, 
* control screen redrawing, and traverse the history stack that records where users have been in a document.<br>
* To get a <a>FR_PageView</a> which displayed in a <a>FR_DocView</a>, using <a>FRDocViewGetPageView</a> and 
* <a>FRDocViewGetPageViewAtPoint</a>.
*/
typedef struct _t_FR_DocView* FR_DocView;
#endif

/* @ENUMSTART */
/**
 * @brief A structure that defines the layout of a document. See <a>FRDocViewGetLayoutMode</a>.
 */
enum FRDOCVIEW_LAYOUTMODE
{

	FR_LAYOUTMODE_SINGLE = 0,			/**< Using single page mode. */
	
	FR_LAYOUTMODE_CONTINUOUS,			/**< Using one-column continue mode. */

	FR_LAYOUTMODE_FACING,				/**< Using facing mode. */

	FR_LAYOUTMODE_CONTINUOUS_FACING		/**< Using facing continue mode. */			
};
/* @ENUMEND */

/* @ENUMSTART */
/**
 * @brief Constants that specify the zoom strategy that Foxit Reader is to follow. See <a>FRDocViewGetZoomType</a>.
 */
enum FRDOCVIEW_ZOOMTYPE
{	
	FR_ZOOM_MODE_NONE = 0,				/**< None zoom type. */


	FR_ZOOM_MODE_ACTUAL_SCALE,			/**< No variable zoom (the zoom is a fixed value such as 1.0 for 100%). */


	FR_ZOOM_MODE_ACTUAL_SIZE,			/**< Actual size. */


	FR_ZOOM_MODE_FIT_PAGE,				/**< To keep entire page visible. */


	FR_ZOOM_MODE_FIT_WIDTH,				/**< Fits the page width to the window. */


	FR_ZOOM_MODE_FIT_HEIGHT,			/**< Fits the page height to the window. */


	FR_ZOOM_MODE_FIT_RECTANGLE,			/**< Fits rectangle. */

 
	FR_ZOOM_MODE_FIT_BOUNDINGBOX,		/**< Fits bounding box. */

	FR_ZOOM_MODE_FIT_VISIBLE,			/**< Fits visible. */

	FR_ZOOM_MODE_AUTOMATIC				/**< Automatic. */

};
/* @ENUMEND */

/* @DEFGROUPSTART FR_RotationFlags */

/**
 *
 * @brief The rotation flag for document view. See <a>FRDocViewGetRotation</a>.
 */
/*@{*/

/** @brief 0 degree (clockwise). */
#define  FR_ROTATE_POS_TOP           0

/** @brief 90 degree (clockwise). */
#define  FR_ROTATE_POS_RIGHT         1

/** @brief 270 degree (clockwise). */
#define  FR_ROTATE_POS_BOTTOM        2

/** @brief 180 degree (clockwise). */
#define  FR_ROTATE_POS_LEFT          3

/*@}*/
/* @DEFGROUPEND */

/* @STRUCTSTART FRDESTINFO */
/**
 * @brief Doc dest info.
 *
 */
typedef struct   _fr_destinfo_
{  
	/** m_nLeft*/
	FS_INT32	m_nLeft;   
	/** m_nTop*/
	FS_INT32	m_nTop;  
	/** m_nWidth*/
	FS_INT32	m_nWidth;  
	/** m_nHeight*/
	FS_INT32	m_nHeight; 
	/** m_iPage*/
	FS_INT32	m_iPage; 
	/** m_nZoomToMode*/
	FS_INT32	m_nZoomToMode;  
	/** m_dbScale*/
	double		m_dbScale;   
	/** m_bPdfCord*/
    FS_BOOL		m_bPdfCord;  
	/** m_bLink*/
	FS_BOOL		m_bLink;        
}FRDESTINFO, *PFRDESTINFO;
/* @STRUCTEND */

/* @STRUCTSTART FRLayoutInfo */
/**
 * @brief The display information for document view.
 *
 */
typedef struct _page_layoutinfo_
{
	/** m_nRotate */
	FS_INT32	m_nRotate;
	/** m_nZoomMode */
	FS_INT32	m_nZoomMode;
	/** m_nShowMode */
	FS_INT32	m_nShowMode;
	/** m_nFacingCount */
	FS_INT32	m_nFacingCount;
	/** m_nMarginSize */
	FS_INT32	m_nMarginSize;
	/** m_dbZoom */
	double		m_dbZoom;
	/** m_bDispGrid */
	FS_BOOL		m_bDispGrid;
	/** m_bReserved */
	FS_BOOL		m_bReserved;
	/** m_bReplaceColor */
	FS_BOOL		m_bReplaceColor;
	/** m_bCoverPage */
	FS_BOOL		m_bCoverPage;	
	/** m_pDestInfo */
	PFRDESTINFO	m_pDestInfo;	
}FRLayoutInfo, *PFRLayoutInfo;
/* @STRUCTEND */

/* @OBJEND */

/* @OBJSTART FR_PageView */
#ifndef FR_PAGEVIEW
#define FR_PAGEVIEW
/**
 * @brief A <a>FR_PageView</a> is a view of a <a>FPD_Page</a> object. 
 * The page view is a part(always a rectangle area) of document view.
 *
 * A <a>FR_PageView</a> must associated with a <a>FPD_Page</a>, but a <a>FPD_Page</a> has more than one <a>FR_PageView</a> some times.
 * <a>FR_PageView</a> has methods to deal with annotations, transform coordinates, control screen redrawing.
 */
typedef struct _t_FR_PageView* FR_PageView;
#endif

/* @STRUCTSTART FR_WinPortRec */
/**
 * @brief A data structure for <Italic>Windows</Italic>. See <a>FRDocViewGetMachinePort</a>. See <a>FRDocViewReleaseMachinePort</a>.
 */
typedef struct _fr_winport_ 
{
	/** Handle to a window. */
	HWND	hWnd;
	/** Handle to a device context. */
	HDC		hDC;
}FR_WinPortRec, *FR_WinPort;
/* @STRUCTEND */

/* @ENUMSTART */
/** 
  * @brief The content change type. See <a>FRPageViewDidContentChanged3</a>.
  */
enum FR_ContentChangeType
{
	FR_ContentChangeType_None = 0,
	FR_ContentChangeType_Add,
	FR_ContentChangeType_Delete,
	FR_ContentChangeType_Modify
};
/* @ENUMEND */

/* @STRUCTSTART FR_ChangedContentRec */
/**
 * @brief A data structure to store the content changed in the page view. See <a>FRPageViewDidContentChanged3</a>.
 */
typedef struct _fr_changedcontent_
{
	void* pDocView;

	FS_INT32 nPageIndex;

	void* pPagepos;

	FS_BOOL bInFormXObject;

	FS_DWordArray arrayFormLayer;
}FR_ChangedContentRec, *FR_ChangedContent;
/* @STRUCTEND */

/* @OBJEND */

/* @OBJSTART FR_TextSelectTool */
#ifndef FR_TEXTSELECTTOOL
#define FR_TEXTSELECTTOOL
/**
 * @brief The text select tool is used to process the operation of text selecting in the doc view.
 */
typedef struct _t_FR_TextSelectTool* FR_TextSelectTool;
#endif
/* @OBJEND */

/* @OBJSTART FR_ThumbnailView */
#ifndef FR_THUMBNAILVIEW
#define FR_THUMBNAILVIEW
/**
 * @brief A <a>FR_ThumbnailView</a> is a view thumbnail view related to the document view. It displays the thumbnail of
 * the document in the page panel.
 *
 */
typedef struct _t_FR_ThumbnailView* FR_ThumbnailView;
#endif

/* @OBJEND */

/* @OBJSTART FR_ScrollBarThumbnailView */
#ifndef FR_SCROLLBARTHUMBNAILVIEW
#define FR_SCROLLBARTHUMBNAILVIEW
/**
*@brief
*/
typedef struct _t_FR_ScrollBarThumbnailView* FR_ScrollBarThumbnailView;
#endif
/* @OBJEND */

/* @OBJSTART FR_Annot */
#ifndef FR_ANNOT
#define FR_ANNOT
/**
 * @brief The UI layer annotation object.
 */
typedef struct _t_FR_Annot* FR_Annot;
#endif
/* @OBJEND */

/* @OBJSTART FR_ResourcePropertySource */
#ifndef FR_RESOURCEPROPERTYSOURCE
#define FR_RESOURCEPROPERTYSOURCE
/**
 * @brief The property source of the property box.
 */
typedef struct _t_FR_ResourcePropertySource* FR_ResourcePropertySource;
#endif
/* @OBJEND */

/* @OBJSTART FR_ResourcePropertyPage */
#ifndef FR_RESOURCEPROPERTYPAGE
#define FR_RESOURCEPROPERTYPAGE
/**
 * @brief The property page of the property box.
 */
typedef struct _t_FR_ResourcePropertyPage* FR_ResourcePropertyPage;
#endif
/* @OBJEND */

/* @OBJSTART FR_ResourcePropertyBox */
#ifndef FR_RESOURCEPROPERTYBOX
#define FR_RESOURCEPROPERTYBOX
/**
 * @brief The property box is used to edit the properties of objects, such as the annotations, the pages and so on. 
 * The Foxit Reader creates the property box so that many types of objects can reuse the same property box to edit the properties.
 */
typedef struct _t_FR_ResourcePropertyBox* FR_ResourcePropertyBox;
#endif

/* @DEFGROUPSTART FRSOURCETYPE */

/**
 * @brief The source type definitions.
 */

/*@{*/
/** @brief Unknown type. */
#define FR_SOURCE_TYPE_UNKNOWN			-1
/** @brief The source type is annotation. */
#define FR_SOURCE_TYPE_ANNOTS			0
/** @brief The source type is bookmark. */
#define FR_SOURCE_TYPE_BOOKMARK			1
/** @brief The source type is page. */
#define FR_SOURCE_TYPE_PAGE				2
/** @brief The source type is page objects. */
#define FR_SOURCE_TYPE_PAGEOBJECTS		3
/** @brief The source type is user. */
#define FR_SOURCE_TYPE_USER				4
/** @brief The source type is tag. */
#define FR_SOURCE_TYPE_TAG				5
/*@}*/
/* @DEFGROUPEND */

#ifndef FR_DOCUMENT
#define FR_DOCUMENT
typedef struct _t_FR_Document* FR_Document;
#endif

/* @CALLBACKGROUPSTART FR_ResourcePropertyNotifyCallbacksRec */
/**
 * @brief The callback set for property box. The callbacks are called by Foxit Reader when the events occur.
 */
typedef struct _fr_resourceproperty_notify_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyNotifyCallbacksRec</a>). */
	unsigned long	lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRResourcePropertyNotifyOnLockObjects */
	/**
     * @brief	It is called by foxit reader when the user clicks the check box to lock the source.
     * @param[in] clientData	The user-supplied data.
	 * @param[in] bLocked		Indicates whether to lock the source or not.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
	 * @see FRResourcePropertyBoxRegisterSourceType
     */	
	void (*FRResourcePropertyNotifyOnLockObjects)(FS_LPVOID clientData, FS_BOOL bLocked);
	/* @CALLBACKEND */

}FR_ResourcePropertyNotifyCallbacksRec, *FR_ResourcePropertyNotifyCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertySourceCallbacksRec */
/**
 * @brief The callback set for property source. The callbacks are called by Foxit Reader to deal with the source of the property box.
 * See <a>FRResourcePropertyBoxRegisterSourceType</a>.
 */
typedef struct _fr_resourceproperty_source_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertySourceCallbacksRec</a>). */
	unsigned long	lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRResourcePropertySourceGetFRDocument */
	/**
     * @brief	It is called by foxit reader to get the <a>FR_Document</a> object.
     * @param[in] clientData	The user-supplied data.
     * @return The <a>FR_Document</a> object.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FR_Document (*FRResourcePropertySourceGetFRDocument)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceCountSelectObjects */
	/**
     * @brief	It is called by foxit reader to get the cout of the selected objects.
     * @param[in] clientData	The user-supplied data.
     * @return The cout of the selected objects.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_INT32 (*FRResourcePropertySourceCountSelectObjects)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceGetSelectObject */
	/**
     * @brief	It is called by foxit reader to get the selected object by index.
     * @param[in] clientData	The user-supplied data.
	 * @param[in] index			The specified index.
     * @return The selected object.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void* (*FRResourcePropertySourceGetSelectObject)(FS_LPVOID clientData, FS_INT32 index);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceGetSelectObjectType */
	/**
     * @brief	It is called by foxit reader to get the types of the selected objects.
     * @param[in] clientData	The user-supplied data.
	 * @param[out] outArray		It receives the types.
     * @return The returned value is reserved.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_INT32 (*FRResourcePropertySourceGetSelectObjectType)(FS_LPVOID clientData, FS_ByteStringArray outArray);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceIsLockedObjectExisted */
	/**
     * @brief	It is called by foxit reader to check whether the locked object exists.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the locked object exists, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertySourceIsLockedObjectExisted)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceIsDisabledObjectExisted */
	/**
     * @brief	It is called by foxit reader to check whether the disabled object exists.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the disabled object exists, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertySourceIsDisabledObjectExisted)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceIsPropertyBoxEnabled */
	/**
     * @brief	It is called by foxit reader to check whether the property box is enabled.
     * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsObjectType	The specified object type.
     * @return <a>TRUE</a> if the property box is enabled, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertySourceIsPropertyBoxEnabled)(FS_LPVOID clientData, FS_LPCSTR lpsObjectType);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceGetPropertyBoxTitle */
	/**
     * @brief	It is called by foxit reader to get the title of the property box.
     * @param[in] clientData	The user-supplied data.
	 * @param[in] lpsObjectType	The specified object type.
	 * @param[out] outTitle		It receives the title of the property box.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertySourceGetPropertyBoxTitle)(FS_LPVOID clientData, FS_LPCSTR lpsObjectType, FS_WideString outTitle);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceCanExistedSetDefaultButton */
	/**
     * @brief	It is called by foxit reader to determine whether to show the check box to set current properties as default.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> if the check box is to be shown, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertySourceCanExistedSetDefaultButton)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertySourceOnBoxClose */
	/**
     * @brief	It is called by foxit reader when the property box is closed.
     * @param[in] clientData		The user-supplied data.
	 * @param[in] nType				The source type.
	 * @param[in] bSetDefaultButton	Whether the check box is checked or not.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertySourceOnBoxClose)(FS_LPVOID clientData, FS_INT32 nType, FS_INT32 bSetDefaultButton);
	/* @CALLBACKEND */

}FR_ResourcePropertySourceCallbacksRec, *FR_ResourcePropertySourceCallbacks;
/* @CALLBACKGROUPEND */

/* @CALLBACKGROUPSTART FR_ResourcePropertyPageCallbacksRec */
/**
 * @brief The callback set for property page. The callbacks are called by Foxit Reader to add new property page to the property box.
 * You can register the callbacks through <a>FRResourcePropertyBoxRegisterPropertyPage</a>.
 */
typedef struct _fr_resourceproperty_page_callbacks_
{
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_ResourcePropertyPageCallbacksRec</a>). */
	unsigned long	lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRResourcePropertyPageSetPropertyBox */
	/**
     * @brief	It is called by foxit reader to pass the property box to the plug-in.
     * @param[in] clientData		The user-supplied data.
	 * @param[in] pPropertyBox		The property box.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertyPageSetPropertyBox)(FS_LPVOID clientData, FR_ResourcePropertyBox pPropertyBox);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageGetPageTitle */
	/**
     * @brief	It is called by foxit reader to get the title of the property page.
     * @param[in] clientData		The user-supplied data.
	 * @param[out] outTitle			It receives the title of the property page.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertyPageGetPageTitle)(FS_LPVOID clientData, FS_WideString outTitle);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageGetPageName */
	/**
     * @brief	It is called by foxit reader to get the name of the property page.
     * @param[in] clientData		The user-supplied data.
	 * @param[out] outName			It receives the name of the property page.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertyPageGetPageName)(FS_LPVOID clientData, FS_WideString outName);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageGetSequenceNumber */
	/**
     * @brief	It is called by foxit reader to get the sequence number of the property page.
     * @param[in] clientData		The user-supplied data.
     * @return The sequence number of the property page.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_INT32 (*FRResourcePropertyPageGetSequenceNumber)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageIsSourceSupported */
	/**
     * @brief	It is called by foxit reader to check whether the source is supported.
     * @param[in] clientData		The user-supplied data.
	 * @param[in] nSource			The source type.
	 * @param[in] pSourceFunc		The property source.
     * @return <a>TRUE</a> if the souce is supported, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertyPageIsSourceSupported)(FS_LPVOID clientData, FS_INT32 nSource, FR_ResourcePropertySource pSourceFunc);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageUpdatePage */
	/**
     * @brief	It is called by foxit reader to notify the plug-in to update the property page.
     * @param[in] clientData The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertyPageUpdatePage)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageGetPageHWnd */
	/**
     * @brief	It is called by foxit reader to get the window handle of the property page.
     * @param[in] clientData The user-supplied data.
     * @return The window handle of the property page.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	HWND (*FRResourcePropertyPageGetPageHWnd)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageGetPageSize */
	/**
     * @brief	It is called by foxit reader to get the size of the property page.
     * @param[in] clientData	The user-supplied data.
	 * @param[out] outCX		It receives the width of the property page.
	 * @param[out] outCY		It receives the height of the property page.
     * @return <a>TRUE</a> for success, otherwise the property page will use the default size.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertyPageGetPageSize)(FS_LPVOID clientData, FS_INT32* outCX, FS_INT32* outCY);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageCreatePage */
	/**
     * @brief	It is called by foxit reader to notify the plug-in to create the property page.
     * @param[in] clientData	The user-supplied data.
	 * @param[] hParent			The parent window handle.
     * @return <a>TRUE</a> for success, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertyPageCreatePage)(FS_LPVOID clientData, HWND hParent);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageOnDeactive */
	/**
     * @brief	It is called by foxit reader to notify the plug-in to deactivate the property page.
     * @param[in] clientData	The user-supplied data.
     * @return <a>TRUE</a> for success, otherwise not.
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	FS_BOOL (*FRResourcePropertyPageOnDeactive)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRResourcePropertyPageOnLangUIChange */
	/**
     * @brief	It is called by foxit reader to notify the plug-in to change the language of the property page.
     * @param[in] clientData	The user-supplied data.
     * @return void
     * @note
	 * @since <a>SDK_LATEEST_VERSION</a> > 2.0
     */
	void (*FRResourcePropertyPageOnLangUIChange)(FS_LPVOID clientData);
	/* @CALLBACKEND */
}FR_ResourcePropertyPageCallbacksRec, *FR_ResourcePropertyPageCallbacks;
/* @CALLBACKGROUPEND */

/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif //FR_VIEWEXPT_H
/*@}*/ 

/*@}*/ 
