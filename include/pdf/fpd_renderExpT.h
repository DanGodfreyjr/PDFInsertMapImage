/*********************************************************************

 Copyright (C) 2010 Foxit Corporation
 All rights reserved.
  
 NOTICE: Foxit permits you to use, modify, and distribute this file
 in accordance with the terms of the Foxit license agreement
 accompanying it. If you have received this file from a source other
 than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
	
 ---------------------------------------------------------------------
	  
fpd_renderExpT.h
		
 - Types, macros, structures, etc. required to use the FPDRender HFT.

*********************************************************************/

/**
 * @defgroup FPDLayer Foxit Portable Document Layer
 */

/*@{*/

/**
* @file
* @brief PDF render functions.
*/

#ifndef FPD_RENDEREXPT_H
#define FPD_RENDEREXPT_H

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

#ifndef FPD_PAGEEXPT_H
#include "fpd_pageExpT.h"
#endif

#ifndef FPD_PAGEOBJEXPT_H
#include "fpd_pageobjExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/** @addtogroup FPDRENDER */
/*@{*/

/* @OBJSTART FPD_RenderOptions */
/* @DEFGROUPSTART FPDRenderOptColorModeCodes */

/**
  * @name Color mode codes for render options. See <a>FPDRenderOptionsGetColorMode</a>, <a>FPDRenderOptionsSetColorMode</a>.
  */

/*@{*/

/** @brief Normal color mode. */
#define FPD_RENDER_COLOR_NORMAL		0
/** @brief Gray color mode: map colors to background/foreground. */
#define FPD_RENDER_COLOR_GRAY		1
/** @brief Two color mode: map white/black to background/foreground, other unchanged. */
#define FPD_RENDER_COLOR_TWOCOLOR	2
/** @brief Output alpha only, ignore color. */
#define FPD_RENDER_COLOR_ALPHA		3

/*@}*/

/* @DEFGROUPEND */

/* @DEFGROUPSTART FPDRenderOptBitmasksFlag */
/**
  * @name Flag bitmasks for render option. See <a>FPDRenderOptionsGetRenderFlag</a>, <a>FPDRenderOptionsSetRenderFlag</a>.
  */
/*@{*/

/** @brief Use ClearType-like anti-aliasing. */
#define FPD_RENDER_CLEARTYPE			0x01
/** @brief Always output text as graphics (path or bitmap), don't allow device font substitution. */
#define FPD_RENDER_PRINTGRAPHICTEXT		0x02
/** @brief Always use downsampling for image stretching. */
#define FPD_RENDER_FORCE_DOWNSAMPLE		0x04
/** @brief Print preview mode. */
#define FPD_RENDER_PRINTPREVIEW			0x08
/** @brief For clear type: choose BGR stripe device (most device using RGB). */
#define FPD_RENDER_BGR_STRIPE			0x10
/** @brief Always use halftone for image stretching. */
#define FPD_RENDER_FORCE_HALFTONE		0x40
/** @brief Always use anti-aliasing for rectangle drawing. */
#define FPD_RENDER_RECT_AA				0x80
/** @brief Limit image cache size. */
#define FPD_RENDER_LIMITEDIMAGECACHE	0x80000000
/*@}*/

/* @DEFGROUPEND */

/**
  * @brief Page rendering options. see CHAPTER 6 in PDF reference. See <a>FPDRenderOptionsNew</a>, <a>FPDRenderOptionsDestroy</a>.
  */
#ifndef FPD_RENDEROPTIONS
#define FPD_RENDEROPTIONS
	typedef struct _t_FPD_RenderOptions* FPD_RenderOptions;
#endif
/* @OBJEND */

/* @OBJSTART FPD_RenderDevice */

/**
  * @brief The base function set for render devices.
  *
  * This set provide all rendering features common to all output devices (including display, printer, and special devices like converters).
  * The render device makes use of Foxit Rendering Device Driver to do the actual output. See <a>FPDRenderDeviceNew</a>, <a>FPDRenderDeviceDestroy</a>.
  */
#ifndef FPD_RENDERDEVICE
#define FPD_RENDERDEVICE
	typedef struct _t_FPD_RenderDevice* FPD_RenderDevice;
#endif
/* @OBJEND */

/* @OBJSTART FPD_FxgeDevice */
/** @brief Foxit own FXGE rendering device, using the Foxit FXGE device driver.
 * Supporting output to following formats:<br>
 * <ul>
 * <li> 8bppMask: the output will be the alpha channel.</li>
 * <li> 8bppRgb without palette: the output will be grayscale.</li>
 * <li> Rgb, Rgb32: normal RGB output.</li>
 * <li> Argb: RGB with alpha channel output. </li>
 * </ul>
 */
/* @OBJEND */

/* @OBJSTART FPD_WindowsDevice */
/** @brief The rendering device based on Windows device driver.
 *
 */
/* @OBJEND */

/* @OBJSTART FPD_RenderContext */
/**
  * @brief Context for rendering a PDF page or a list of page objects.
  *
  * A PDF page can be divided into different layers, including the page content, annotations, and interactive form.
  * It's important to keep information about those layers if backdrop generation is required during transparency
  * rendering for devices not capable of fetching background.
  * 
  * A PDF rendering context also makes use of page caches, additional page resources, and rendering options.
  * See <a>FPDRenderContextNew</a>, <a>FPDRenderContextNew2</a>, <a>FPDRenderContextDestroy</a>.
  */
#ifndef FPD_RENDERCONTEXT
#define FPD_RENDERCONTEXT
	typedef struct _t_FPD_RenderContext* FPD_RenderContext;
#endif
/* @OBJEND */

/* @OBJSTART FPD_ProgressiveRender */
/**
  * @brief The PDF progressive renderer.
  *
  * A progressive renderer that breaks the full rendering process into steps.
  * This class must be overloaded in order to pause a step whenever the application thinks necessary.
  * 
  * Application must first call Start() to start the rendering, then, when it's paused, the application
  * must call Continue() to continue the rendering, until status becomes Done or Failed.
  * 
  * To stop the rendering, simply destruct the renderer.
  * See <a>FPDProgressiveRenderNew</a>, <a>FPDProgressiveRenderDestroy</a>.
  */
#ifndef FPD_PROGRESSIVERENDER
#define FPD_PROGRESSIVERENDER
	typedef struct _t_FPD_ProgressiveRender* FPD_ProgressiveRender;
#endif
/* @OBJEND */

/* @OBJSTART FPD_PageRenderCache */
/** @brief Store all dispensable items used when rendering a page. See <a>FPD_BackgroundDraw</a>
  * Note: Currently we have image cache only.
  */
#ifndef FPD_PAGERENDERCACHE
#define FPD_PAGERENDERCACHE
	typedef struct _t_FPD_PageRenderCache* FPD_PageRenderCache;
#endif
/* @OBJEND */
	
/* @OBJSTART FPD_OCContextHandler */
/** 
  * @brief PDF optional content context interface. Used for holding a  <a>FPD_OCContextCallBack</a>.
  */ 	
#ifndef FPD_OCCONTEXTHANDLER
#define FPD_OCCONTEXTHANDLER
	typedef struct _t_FPD_OCContextHandler* FPD_OCContextHandler;
#endif

	
#ifndef FPD_OCCONTEXTCALLBACK
#define FPD_OCCONTEXTCALLBACK
/* @CALLBACKGROUPSTART FPD_OCContextCallBack */
/** 
  * @brief The PDF optional content context callback struct. See <a>FPD_OCContextHandler</a>.
  */ 
typedef struct __FPD_OCContextCallBack__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_OCContextCallBack</a>).  */
	unsigned long lStructSize;

	/* @CALLBACKSTART CheckOCGVisible */
	/**
	 * @brief Check whether a option content group is visible.
	 *
	 * @param[in] ocg		The optional content group dictionary.
	 * @return Non-zero means visible, otherwise invisible. 
	 */
	FS_BOOL (*CheckOCGVisible)(FPD_Object ocg);
	/* @CALLBACKEND */

	/* @CALLBACKSTART CheckObjectVisible */
	/** 
	* @brief Check whether an object is visible in this context
	*
	* @param[in] obj			Page object.
	* @return Non-zero means visible, otherwise invisible. 
	*/
	FS_BOOL (*CheckObjectVisible)(FPD_PageObject obj);
	/* @CALLBACKEND */
	
}FPD_OCContextCallBack,*PFPD_OCContextCallBack;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

/* @OBJSTART FPD_BackgroundDrawHandler */
/** @brief PDF background drawing interface. Use for holding a <a>FPD_BackgroundDraw</a>.
  */
#ifndef FPD_BACKGROUNDDRAWHANDLER
#define FPD_BACKGROUNDDRAWHANDLER
	typedef struct _t_FPD_BackgroundDrawHandler* FPD_BackgroundDrawHandler;
#endif

/* @CALLBACKGROUPSTART FPD_BackgroundDraw */
/** 
  * @brief PDF background drawing callback struct. See <a>FPD_BackgroundDrawHandler</a>.
  */
#ifndef FPD_BACKGROUNDDRAW
#define FPD_BACKGROUNDDRAW
typedef struct __FPD_BackgroundDraw__
{
	/* The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FPD_BackgroundDraw</a>).  */
	unsigned long lStructSize;


	/* @CALLBACKSTART OnDrawBackground */
	/**
	*  @brief The callback for drawing background region. 
	*
	* For custom background PDF rendering on a non-display device (like printers), it's often not possible
	* for rendering engine to get a background (for masked operations or transparent operations), therefore
	* the rendering application has to provide a routine to draw the custom background into a bitmap device.
	* In most cases, only portion of the background is needed. 
	* Default implementation fills white color.
	*
	* @param[in] bitmapDevice		The temporary bitmap device. The size of this device an be only portion of the rendering target device.
	* @param[in] original2Bitmap	The matrix from original device space to bitmap device space.
	* @return void
	* @note The bitmap device for rendering background might have different resolution from the original device,
	* for example, in order to reduce spooling size, we use lower resolution for rendering shading areas and
	* transparent images.
	*/
	void (*OnDrawBackground)(FPD_RenderDevice bitmapDevice,FS_AffineMatrix original2Bitmap);
	/* @CALLBACKEND */

}FPD_BackgroundDraw,*PFPD_BackgroundDraw;
#endif
/* @CALLBACKGROUPEND */
/* @OBJEND */

#ifdef __cplusplus
};
#endif

#endif

/*@}*/

/*@}*/