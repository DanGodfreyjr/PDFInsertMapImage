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

/** @file fr_docExpT.h.
 * 
 *  @brief .
 */

/**
 * @addtogroup FRDOCUMENT
 * @{
 */

#ifndef FR_DOCEXPT_H
#define FR_DOCEXPT_H


#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FR_VIEWEXPT_H
#include "fr_viewExpT.h"
#endif

#ifndef FPD_DOCEXPT_H
#include "../pdf/fpd_docExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

/* @OBJSTART FR_Document */
#ifndef FR_DOCUMENT
#define FR_DOCUMENT
/**
 * @brief A <a>FR_Document</a> is a view of a PDF document in a window.<br>
 *
 * Usually there is one <a>FR_Document</a> per displayed document, but some times(such as New Window), 
 * there may be two or more <a>FR_Document</a> per displayed document.
 * Unlike a <a>FPD_Document</a>, an <a>FR_Document</a> has a window associated with it. And a <a>FPD_Document</a> 
 * may have one or more associated <a>FR_Document</a>.<br>
 * 
 */
typedef struct _t_FR_Document* FR_Document;
#endif

/* @DEFGROUPSTART FRMenuEnableNames */
/**
 * @brief The macro definitions for the name of menu you want to enable. See <a>FRDocSetMenuEnableByName</a>.
 */
/*@{*/

/** @brief save as menu*/
#define FR_MENU_ENABLE_SAVEAS "SaveAs"

/** @brief email menu*/
#define FR_MENU_ENABLE_EMAIL "Email"

/** @brief snapshot menu*/
#define FR_MENU_ENABLE_SNAPSHOT "Snapshot"

/** @brief stamp menu*/
#define FR_MENU_ENABLE_STAMP "Stamp"
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FRDocTypes */
/**
 * @brief The macro definitions for the types of <a>FR_Document</a>. See <a>FRDocGetDocumentType</a>.
 */
/*@{*/

/** @brief The type is PDF.*/
#define FR_DOCTYPE_PDF				0

/** @brief The type dynimic xfa.*/
#define FR_DOCTYPE_DYNIMIC_XFA		1

/** @brief The type is static XFA.*/
#define FR_DOCTYPE_STATIC_XFA		2

/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
/** @brief The original type of the document. The real format of the opened document is PDF, but its wrapper format may be PPDF. See <a>FRDocGetOriginalType</a>.*/
enum FROriginalDocType
{
	FR_ORI_DOCTYPE_PDF = 0,			/**The original type of the document is PDF.*/
	FR_ORI_DOCTYPE_DYNAMIC_XFA = 1,	/**The original type of the document is dynamic XFA.*/
	FR_ORI_DOCTYPE_STATIC_XFA = 2,	/**The original type of the document is static PDF.*/
	FR_ORI_DOCTYPE_FDF = 3,			/**The original type of the document is FDF.*/
	FR_ORI_DOCTYPE_XDP = 4,			/**The original type of the document is XDP.*/
	FR_ORI_DOCTYPE_XFDF = 5,		/**The original type of the document is XFDF.*/
	FR_ORI_DOCTYPE_PPDF = 6			/**The original type of the document is PPDF.*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** @brief The source type of the document.*/
enum FRCreateDocSource
{
	FR_DOC_SOURCE_NORMAL = 0,				/**Normal.*/
	FR_DOC_SOURCE_BLANK = 1,				/**Blank.*/
	FR_DOC_SOURCE_FROM_FILE = 2,			/**From file.*/
	FR_DOC_SOURCE_FROM_MULTIPLE_FILES = 3,  /**From Multiple Files.*/
	FR_DOC_SOURCE_FROM_SCANNER = 4,		    /**From Scanner.*/
	FR_DOC_SOURCE_FROM_CLIPBOARD = 5,		/**From Clipboard.*/
	FR_DOC_SOURCE_PDF_PORTFOLIO = 6		    /**PDF Portfolio.*/
};
/* @ENUMEND */

/* @CALLBACKSTART FR_DocSaveAsProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> when performs <Italic>SaveAs</Italic>.
 * @param[in] frDoc The document to be saved as.
 * @param[in] pwszFilePath	The path where the document to be saved as.
 * @param[in] pProcData	The client data.
 * @return void
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 1.0
 * @see FRDocDoSave2
 */typedef void (*FR_DocSaveAsProc)(FR_Document frDoc, FS_LPCWSTR pwszFilePath, void* pProcData);
/* @CALLBACKEND */

/* @CALLBACKSTART FR_DocSaveProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> when performs <Italic>Save</Italic>.
 * @param[in] frDoc The document to be saved as.
 * @param[in] pwszFilePath	The path where the document to be saved.
 * @param[in] pProcData	The client data.
 * @return void
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.4
 * @see FRDocDoSave
 */
typedef void (*FR_DocSaveProc)(FR_Document frDoc, FS_LPCWSTR pwszFilePath, void* pProcData);
/* @CALLBACKEND */

/* @CALLBACKSTART FRInputPasswordProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> if you want to 
 * set the document password through interface instead of the password input dialog.
 * @param[in] frDoc			The document.
 * @param[out] bsPassword	It receives the password.
 * @param[out] bReset		It indicates whether <Italic>Foxit Reader</Italic> need to reset the password if the password is incorrect.
 * @return <a>TRUE</a> if the plug-in takes over the procedure, otherwise not.
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 2.1.0.2
 * @see FRDocSetInputPasswordProc
 */
typedef FS_BOOL (*FRInputPasswordProc)(FR_Document frDoc, FS_ByteString bsPassword, FS_BOOL* bReset);
/* @CALLBACKEND */

/* @CALLBACKSTART FRPasswordEncryptProc */
/**
 * @brief Prototype of callback function invoked by <Italic>Foxit Reader</Italic> if you want to 
 * set the document password through the password input dialog.
 * @param[in] frDoc			The document.
 * @param[in] nAction		<a>0</a> means user cancel protect. <a>1</a> means will start protecting document and can be canceled by <a>bCancel</a>
 *							parameter. <a>2</a> means the document finished protecting.
 * @param[out] bCancel		When <a>nAction</a> return <a>1</a>, set <a>TRUE</a> to cancel the protection.
 * @param[out] pVariable	This is a reserved parameter.
 * @return void.
 * @note
 * @since <a>SDK_LATEEST_VERSION</a> > 9.1
 * @see FRDocSetInputPasswordProc
 */
typedef void (*FRPasswordEncryptProc)(FR_Document frDoc, int nAction, BOOL *bCancel, void *pVariable);
/* @CALLBACKEND */
/* @OBJEND */

/* @COMMONSTART */

/* @DEFGROUPSTART FRSIGShowAPFlags */
/**
 * @brief The flag of showing appearance.
 */
/*@{*/
/** @brief Shows signer name on description. */
#define FR_SIG_SHOW_NAME					0x001
/** @brief Shows location on description. */
#define FR_SIG_SHOW_LOCATION				0x002
/** @brief Shows dn on description. */
#define FR_SIG_SHOW_DN						0x004
/** @brief Shows date on description. */
#define FR_SIG_SHOW_DATE					0x008
/** @brief Shows reason on description. */
#define FR_SIG_SHOW_REASON					0x010
/** @brief Shows label on description. */
#define FR_SIG_SHOW_LABEL					0x020
/** @brief Shows foxit logo on signature ap. */
#define FR_SIG_SHOW_FOXITFLOGO				0x040
/** @brief Shows all flags. */
#define FR_SIG_SHOW_ALL					FR_SIG_SHOW_NAME |	FR_SIG_SHOW_LOCATION |	FR_SIG_SHOW_DN | FR_SIG_SHOW_DATE | FR_SIG_SHOW_REASON | FR_SIG_SHOW_LABEL | FR_SIG_SHOW_FOXITFLOGO			
/*@}*/
/* @DEFGROUPEND */

/* @DEFGROUPSTART FRSIGVarifySignatureStates */
/**
 * @brief The state for verifying signature.
 */
/*@{*/
/** @brief The signature state is valid. */
#define FR_SIG_VERIFY_VALID					0x00000000
/** @brief The signature state is invalid. */
#define FR_SIG_VERIFY_INVALID				0x00000001
/** @brief The signature data is corrupted and can not be parsed successfully. */
#define FR_SIG_VERIFY_ERRORDATA				0x00000002
/** @brief The signature type is not supported. */
#define FR_SIG_VERIFY_NOSUPPORTWAY			0x00000003
/** @brief The signature data bytes is not in the expected range. */
#define FR_SIG_VERIFY_ERRORBYTERANGE		0x00000004
/** @brief The document is changed beyond the limits. */
#define FR_SIG_VERIFY_CHANGE				0x00000005
/** @brief The signature is not trusted. */
#define FR_SIG_VERIFY_INCREDIBLE			0x00000006

/** @brief The issuer is valid. */
#define FR_SIG_VERIFY_ISSUER_VALID			0x00010000
/** @brief The issuer is  unknown. */
#define FR_SIG_VERIFY_ISSUER_UNKNOW			0x00020000
/** @brief The certificate is revoked. */
#define FR_SIG_VERIFY_ISSUER_REVOKE			0x00040000
/** @brief The certificate is expired. */
#define FR_SIG_VERIFY_ISSUER_EXPIRE			0x00080000
/** @brief The issuer is unchecked. */
#define FR_SIG_VERIFY_ISSUER_UNCHECK		0x00100000
/** @brief The issuer is the current issuer. */
#define FR_SIG_VERIFY_ISSUER_CURRENT		0x00200000

/** @brief No timestamp. */
#define FR_SIG_TIMESTAMP_NONE				0x00400000
/** @brief It is the type of document timestamp. */
#define FR_SIG_TIMESTAMP_DOC				0x00800000
/** @brief The time stamp is valid. */
#define FR_SIG_TIMESTAMP_VALID				0x01000000
/** @brief The time stamp is invalid. */
#define FR_SIG_TIMESTAMP_INVALID			0x02000000
/** @brief The time stamp is expired. */
#define FR_SIG_TIMESTAMP_EXPIRE				0x04000000
/** @brief The issuer of the time stamp is unknown. */
#define FR_SIG_TIMESTAMP_ISSUER_ISUNKNOWN	0x08000000
/** @brief The issuer of the time stamp is valid. */
#define FR_SIG_TIMESTAMP_ISSUER_ISVALID		0x10000000
/*@}*/
/* @DEFGROUPEND */

/* @ENUMSTART */
/** 
  * @brief The handle of the result.
  */
enum FR_SG_HANDLE
{
	FR_SIG_HANDLE_SUCCESS,	/** Succeed.*/
	FR_SIG_HANDLE_FAIL,		/** Fail.*/
	FR_SIG_HANDLE_NONE		/** None.*/

};
/* @ENUMEND */

/* @STRUCTSTART FR_SignatureDictInfo*/
#ifndef FR_SIGNATURE_DICTINFO
#define FR_SIGNATURE_DICTINFO
/**
* @brief Data structure for signature dictionary info.
*
*/
typedef struct __FR_SignatureDictInfo__
{
	__FR_SignatureDictInfo__()
	{
		memset(wsName, 0, 128*sizeof(wchar_t));
		memset(wsDate, 0, 128*sizeof(wchar_t)); 
		memset(wsReason, 0, 256*sizeof(wchar_t));
		memset(wsLocation, 0, 256*sizeof(wchar_t));
		memset(wsFilter, 0, 128*sizeof(wchar_t));
	}

	/** The signer. */
	wchar_t					wsName[128];
	/** The signing date. */
	wchar_t					wsDate[128];
	/** The reason for signing. */
	wchar_t					wsReason[256];
	/** The location for signing. */
	wchar_t					wsLocation[256];
	/** The sub-filter of the signing. */
	wchar_t					wsFilter[128];
}FR_SignatureDictInfo;
#endif
/* @STRUCTEND */

/* @ENUMSTART */
/** 
  * @brief The icon type of showing graphic on signature appearance.
  */
enum FR_SG_ICONTYPE
{
	FR_SGIT_NONE,			/** None. */
	FR_SGIT_GRAPHICS,		/** The type is graphic.*/
	FR_SGIT_NAME			/** The type is name.*/
};
/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief The text direction on signature appearance.
  */
enum FR_SG_TEXTDIR
{
	FR_SGTD_AUTO,			/** Auto. */
	FR_SGTD_LEFTTORIGHT,	/** Left to right. */
	FR_SGTD_RIGHTTOLEFT		/** Right to left. */

};
/* @ENUMEND */

/* @ENUMSTART */
/** 
  * @brief The definition for signature permission.
  */
enum FR_SG_PERMISSION
{
	FR_APG_NONE,		/** None. */
	FR_APG_ONE,			/** No changes allowed. */
	FR_APG_TWO,			/** Form fill-in and digital signatures. */
	FR_APG_THREE,		/** Annotations, form fill-in, and digital signatures. */
	FR_APG_LOCK			/** Lock document. */

};
/* @ENUMEND */

/* @STRUCTSTART FR_SignatureInfo*/
#ifndef FR_SIGNATURE_INFO
#define FR_SIGNATURE_INFO
/**
* @brief You have to fill the signature info when you want to sign the PDF.
*
*/
typedef struct __FR_SignatureInfo__
{
	__FR_SignatureInfo__()
	{
		memset(wsCN, 0, 64*sizeof(FS_WCHAR));
		memset(wsO, 0, 64*sizeof(FS_WCHAR)); 
		memset(wsOU, 0, 64*sizeof(FS_WCHAR));
		memset(wsE, 0, 128*sizeof(FS_WCHAR));
		memset(wsC, 0, 64*sizeof(FS_WCHAR));
		lShowFlag = FR_SIG_SHOW_ALL;
		TextDir = FR_SGTD_AUTO; 
		Icontype = FR_SGIT_NAME;
		memset(ImagePath, 0, 260); 
		nImageOpt  = 100;
		PermissionType = FR_APG_NONE;
		lEstimateSignData = 0;
		bDocTimeStamp = false;
	}

	/**  */
	FS_WCHAR				wsCN[64];
	/**  */
	FS_WCHAR				wsO[64];
	/**  */
	FS_WCHAR				wsOU[64];
	/**  */
	FS_WCHAR				wsE[128];
	/**  */
	FS_WCHAR				wsC[64];

	/**  */
	FR_SignatureDictInfo	SignDictInfo;

	/** The flag for showing appearance. See <a>FRSIGShowAPFlags</a>. */
	unsigned long			lShowFlag;

	/**  */
	FR_SG_ICONTYPE			Icontype;
	/**  */
	FR_SG_TEXTDIR			TextDir;
	/**  */
	FR_SG_PERMISSION		PermissionType;
	/**  */
	FS_WCHAR				ImagePath[260];

	/** The image opacity. */
	FS_INT32				nImageOpt;

	/**  */
	unsigned long			lEstimateSignData;

	/**  */
	FS_BOOL					bDocTimeStamp;

}FR_SignatureInfo;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_SignatureTimestamp*/
#ifndef FR_SIGNATURE_TIMESTAMP
#define FR_SIGNATURE_TIMESTAMP
/**
* @brief The definition of the signature timestamp.
*
*/
typedef struct __FR_SignatureTimestamp__
{

	__FR_SignatureTimestamp__()
	{
		dwLowDateTime = 0;
		dwHighDateTime = 0;
	}
	/**  */
	FS_DWORD dwLowDateTime;
	/**  */
	FS_DWORD dwHighDateTime;

}FR_SignatureTimestamp;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_SignatureTimestampServer*/
#ifndef FR_SIGNATURE_TIMESTAMP_SERVER
#define FR_SIGNATURE_TIMESTAMP_SERVER
/**
* @brief The definition of the signature timestamp server info.
*
*/
typedef struct __FR_SignatureTimestampServer__
{
	__FR_SignatureTimestampServer__()
	{
		memset(wsServerURL, 0, 2048 * sizeof(FS_WCHAR));
		memset(wsUserName, 0, 128 * sizeof(FS_WCHAR));
		memset(wsPassWord, 0, 128 * sizeof(FS_WCHAR));
	}
	/** The server URL. */
	FS_WCHAR wsServerURL[2048];

	/** The user name. */
	FS_WCHAR wsUserName[128];

	/** The password. */
	FS_WCHAR wsPassWord[128];
}FR_SignatureTimestampServer;
#endif
/* @STRUCTEND */

/* @STRUCTSTART FR_SignaturePosInfo*/
#ifndef FR_SIGNATURE_POSINFO
#define FR_SIGNATURE_POSINFO
/**
* @brief You have to fill the signature position info when you want to sign the PDF.
*
*/
typedef struct __FR_SignaturePosInfo__
{
	__FR_SignaturePosInfo__()
	{
		pPDFDoc = NULL;
		nPageIndex = -1;
		nLeft = nRight = nTop = nBottom = 0;
		memset(FileSavePath, 0, 260 * sizeof(FS_WCHAR));
	}
	FPD_Document	pPDFDoc;
	FS_INT32		nPageIndex;

	FS_INT32		nLeft;
	FS_INT32		nRight;
	FS_INT32		nTop;
	FS_INT32		nBottom;
	FS_WCHAR		FileSavePath[260];
}FR_SignaturePosInfo;
#endif
/* @STRUCTEND */

/* @CALLBACKGROUPSTART FR_SignatureHandlerCallbacksRec */

/**
* @brief A callback set for signature handler.
*/
typedef struct _fr_signaturehandler_callbacks_
{    
	/** The size of data structure. It must be set to <Italic>sizeof</Italic>(<a>FR_SignatureHandlerCallbacksRec</a>). */
	unsigned long lStructSize;

	/** The user-supplied data. */
	FS_LPVOID		clientData;

	/* @CALLBACKSTART FRSignatureHandlerGetName */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to provide the name of the signature handler.
	*
	* @param[in] clientData	The user-supplied data.
	* @return The name of the signature handler.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	char* (*FRSignatureHandlerGetName)(FS_LPVOID clientData);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerSignData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to pass the data to be signed to the plug-in.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[in] pData2BSigned		The data to be signed.
	* @param[in] ulData2BSignedLen	The length of the data to be signed.
	* @param[out] pPSignedData		Pass the signed data back to the framework.
	* @param[out] pulSignedDataLen	Pass the length of the signed data back to the framework.
	* @return The result of signing the data.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE (*FRSignatureHandlerSignData)(FS_LPVOID clientData, const unsigned char* pData2BSigned, unsigned long ulData2BSignedLen, unsigned char** pPSignedData, unsigned long* pulSignedDataLen);
	/* @CALLBACKEND */
	
	/* @CALLBACKSTART FRSignatureHandlerTimeStampDate */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to receive the timestamp date from plug-in.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[out] pSgTimeStampDate	Receives the timestamp date from plug-in.
	* @return The result of getting the timestamp date.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE (*FRSignatureHandlerTimeStampDate)(FS_LPVOID clientData, FR_SignatureTimestamp* pSgTimeStampDate);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerVerifyData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to pass the data to the plug-in. Then the plug-in can takes over the process for verifying the signed data.
	*
	* @param[in] clientData			The user-supplied data.
	* @param[in] pSignedData		The signed data.
	* @param[in] ulSignedDataLen	The length of the signed data.
	* @param[in] pData2BSigned		The source data that is signed.
	* @param[in] ulDataT2BSignedLen	The length of the source data that is signed.
	* @param[out] outVerifyState	Pass the verifying state back to framework. See <a>FRSIGVarifySignatureStates</a>.
	* @param[out] hCertContext		The certificate context. It will be passed to <a>FRSignatureHandlerShowStateUI</a>;
	* @return The result of verifying the data. If the plug-in returns <a>FR_SIG_HANDLE_NONE</a>, the Foxit Reader will verify the data by default method.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE (*FRSignatureHandlerVerifyData)(FS_LPVOID clientData, const unsigned char* pSignedData, unsigned long ulSignedDataLen, 
														const unsigned char* pData2BSigned, unsigned long ulDataT2BSignedLen, FS_DWORD* outVerifyState, void** hCertContext);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerShowStateUI */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to show the state UI. The plug-in can create its own UI.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] nVerifyState	The verifying state.
	* @param[in] pWnd			The parent window of the state UI. It represents the <Italic>MFC CWnd*</Italic>.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[in] pSignDictInfo	The signature dictionary info.
	* @return The result of showing state UI.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE (*FRSignatureHandlerShowStateUI)(FS_LPVOID clientData, const FS_DWORD nVerifyState, void* pWnd, void* hCertContext, FR_SignatureDictInfo* pSignDictInfo);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerCanClear */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to check whether the signature can be cleared or not.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @param[out] bCanClear		Whether the signature can be cleared or not.
	* @return The result of this checking.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.2.2
	*/
	FR_SG_HANDLE (*FRSignatureHandlerCanClear)(FS_LPVOID clientData, void* hCertContext, FS_BOOL* bCanClear);
	/* @CALLBACKEND */

	/* @CALLBACKSTART FRSignatureHandlerShowSignProperties */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to show the signing properties. The plug-in can create its own UI.
	*
	* @param[in] clientData		The user-supplied data.
	* @param[in] pSignedData		The signed data.
	* @param[in] ulSignedDataLen	The length of the signed data.
	* @param[in] pData2BSigned		The source data that is signed.
	* @param[in] ulDataT2BSignedLen	The length of the source data that is signed.
	* @param[in] pWnd			The parent window of the property UI. It represents the <Italic>MFC CWnd*</Italic>.
	* @param[in] pSignDictInfo	The signature dictionary info.
	* @param[in] hCertContext	The certificate context from <a>FRSignatureHandlerVerifyData</a>.
	* @return The result of showing the signing property UI.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 7.3
	*/
	FR_SG_HANDLE (*FRSignatureHandlerShowSignProperties)(FS_LPVOID clientData, const unsigned char* pSignedData, unsigned long ulSignedDataLen, 
		const unsigned char* pData2BSigned, unsigned long ulDataT2BSignedLen, void* pWnd, FR_SignatureDictInfo* pSignDictInfo, void* hCertContext);
	/* @CALLBACKEND */

	/* @CALLBACKSTART RSignatureHandlerRleaseSignData */
	/**
	* @brief A callback for signature handler.
	*
	* It is called to by Foxit Reader to Rlease the data to be signed.
	*
	* @param[in] pPSignedData		The data to be Rleased.
	* @param[in] pulSignedDataLen	The length of the data to be Rleased.
	* @note
	* @since <a>SDK_LATEEST_VERSION</a> > 9.1
	*/
	void (*FRSignatureHandlerRleaseSignData)(unsigned char **pPSignedData, unsigned long *pulSignedDataLen);
	/* @CALLBACKEND */
}FR_SignatureHandlerCallbacksRec, *FR_SignatureHandlerCallbacks;
/* @CALLBACKGROUPEND */

/* @STRUCTSTART FR_SignatureBaseInfo*/
#ifndef FR_SIGNATURE_BASEINFO
#define FR_SIGNATURE_BASEINFO
/**
* @brief <a>FR_SignatureBaseInfo</a> represents the base info of the signature, including the time, the name, the state and so on. You 
* can get the base info of the signature through <a>FRCustomSignatureGetSignatureBaseInfo</a>.
*
*/
typedef struct __FR_SignatureBaseInfo__
{

	__FR_SignatureBaseInfo__()
	{
		memset(wsSignedAutorName, 0, 128*sizeof(wchar_t));
		memset(wsSignatureName, 0, 128*sizeof(wchar_t));
		bSignedField = FALSE;
		nSignedPageIndex = 0;
		bVerified = FALSE;
		dwVerifyState = 0;
	}

	/** The time when the signature was signed. */
	FILETIME	ftSignedTime;

	/** The time before which the signature is invalid. */
	FILETIME	ftValidTimeNotBefore;

	/** The time after which the signature is invalid. */
	FILETIME	ftValidTimeNotAfter;

	/** The author name. */
	wchar_t		wsSignedAutorName[128];

	/** The signature name. */
	wchar_t		wsSignatureName[128];

	/** Whether it is a signed field or not. */
	FS_BOOL		bSignedField;

	/** The index of the page where the signature was signed. */
	FS_INT32	nSignedPageIndex;

	/** The verifying state. */
	FS_DWORD    dwVerifyState;

	/** Whether the signature has been verified or not. */
	FS_BOOL		bVerified;
}FR_SignatureBaseInfo;
#endif
/* @STRUCTEND */

/* @COMMONEND */

#ifdef __cplusplus
};
#endif

#endif
/* @} */ 

/* @} */ 