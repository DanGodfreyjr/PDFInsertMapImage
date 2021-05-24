/*****************************************************************************

Copyright (C) 2010 Foxit Corporation
All rights reserved.

NOTICE: Foxit permits you to use, modify, and distribute this file
in accordance with the terms of the Foxit license agreement
accompanying it. If you have received this file from a source other
than Foxit, then your use, modification, or distribution of it
 requires the prior written permission of Foxit.
 
*****************************************************************************/

#ifndef FDRM_DESCCALLS_H
#define FDRM_DESCCALLS_H

#ifndef FS_COMMON_H
#include "../basic/fs_common.h"
#endif

#ifndef FS_BASICEXPT_H
#include "../basic/fs_basicExpT.h"
#endif

#ifndef FS_STRINGEXPT_H
#include "../basic/fs_stringExpT.h"
#endif

#ifndef FDRM_DESCEXPT_H
#include "fdrm_descExpT.h"
#endif

#ifdef __cplusplus
extern "C"{
#endif

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function selectors in the file fdrm_descImpl.h
#define BEGINENUM enum{
#define NumOfSelector(name) name##InterfacesNum
#define ENDENUM };
#define INTERFACE(returnType,interfaceName,params) interfaceName##SEL,
#include "fdrm_descTempl.h"

#undef INTERFACE
#undef BEGINENUM
#undef NumOfSelector
#undef ENDENUM

// Define macros to generate function PROTO in the file fdrm_descImpl.h
#define BEGINENUM
#define NumOfSelector(name)
#define ENDENUM
#define INTERFACE(returnType,interfaceName, params) \
typedef returnType (*interfaceName##SELPROTO)params;
#include "fdrm_descTempl.h"

//----------_V1----------
//----------_V2----------
//*****************************
/* CategoryRead HFT functions */
//*****************************

#define FDRMCategoryReadCountSubCategories (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadCountSubCategoriesSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadCountSubCategoriesSEL, _gPID)))

#define FDRMCategoryReadGetSubCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetSubCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetSubCategorySEL, _gPID)))

#define FDRMCategoryReadFindSubCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadFindSubCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadFindSubCategorySEL, _gPID)))

#define FDRMCategoryReadGetParentCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetParentCategorySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetParentCategorySEL, _gPID)))

#define FDRMCategoryReadGetCategoryName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetCategoryNameSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetCategoryNameSEL, _gPID)))

#define FDRMCategoryReadCountAttributes (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadCountAttributesSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadCountAttributesSEL, _gPID)))

#define FDRMCategoryReadGetAttribute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetAttributeSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetAttributeSEL, _gPID)))

#define FDRMCategoryReadGetAttributeValue (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetAttributeValueSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetAttributeValueSEL, _gPID)))

#define FDRMCategoryReadGetCategoryData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadGetCategoryDataSELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadGetCategoryDataSEL, _gPID)))

#define FDRMCategoryReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryReadDestroySELPROTO)FRCOREROUTINE(FDRMCategoryReadSEL,FDRMCategoryReadDestroySEL, _gPID)))

//*****************************
/* CategoryWrite HFT functions */
//*****************************

#define FDRMCategoryWriteAddCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteAddCategorySELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteAddCategorySEL, _gPID)))

#define FDRMCategoryWriteAddCategory2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteAddCategory2SELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteAddCategory2SEL, _gPID)))

#define FDRMCategoryWriteSetAttribute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteSetAttributeSELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteSetAttributeSEL, _gPID)))

#define FDRMCategoryWriteRemoveAttribute (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteRemoveAttributeSELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteRemoveAttributeSEL, _gPID)))

#define FDRMCategoryWriteSetCategoryData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteSetCategoryDataSELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteSetCategoryDataSEL, _gPID)))

#define FDRMCategoryWriteRemoveCategory (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteRemoveCategorySELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteRemoveCategorySEL, _gPID)))

#define FDRMCategoryWriteRemoveCategory2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteRemoveCategory2SELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteRemoveCategory2SEL, _gPID)))

#define FDRMCategoryWriteRemoveCategory3 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteRemoveCategory3SELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteRemoveCategory3SEL, _gPID)))

#define FDRMCategoryWriteCastToCategoryRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteCastToCategoryReadSELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteCastToCategoryReadSEL, _gPID)))

#define FDRMCategoryWriteDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMCategoryWriteDestroySELPROTO)FRCOREROUTINE(FDRMCategoryWriteSEL,FDRMCategoryWriteDestroySEL, _gPID)))

//*****************************
/* DescData HFT functions */
//*****************************

#define FDRMDescDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataNewSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataNewSEL, _gPID)))

#define FDRMDescDataDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataDestroySELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataDestroySEL, _gPID)))

#define FDRMDescDataGetPackageName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataGetPackageNameSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataGetPackageNameSEL, _gPID)))

#define FDRMDescDataGetDefNameSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataGetDefNameSpaceSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataGetDefNameSpaceSEL, _gPID)))

#define FDRMDescDataGetFDRMNameSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataGetFDRMNameSpaceSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataGetFDRMNameSpaceSEL, _gPID)))

#define FDRMDescDataSetPackageName (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataSetPackageNameSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataSetPackageNameSEL, _gPID)))

#define FDRMDescDataSetDefNameSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataSetDefNameSpaceSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataSetDefNameSpaceSEL, _gPID)))

#define FDRMDescDataSetFDRMNameSpace (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescDataSetFDRMNameSpaceSELPROTO)FRCOREROUTINE(FDRMDescDataSEL,FDRMDescDataSetFDRMNameSpaceSEL, _gPID)))

//*****************************
/* ScriptData HFT functions */
//*****************************

#define FDRMScriptDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataNewSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataNewSEL, _gPID)))

#define FDRMScriptDataDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataDestroySELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataDestroySEL, _gPID)))

#define FDRMScriptDataGetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetDivisionSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetDivisionSEL, _gPID)))

#define FDRMScriptDataGetFormatOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetFormatOrgSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetFormatOrgSEL, _gPID)))

#define FDRMScriptDataGetFormatVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetFormatVerSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetFormatVerSEL, _gPID)))

#define FDRMScriptDataGetAppOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetAppOrgSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetAppOrgSEL, _gPID)))

#define FDRMScriptDataGetAppVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetAppVerSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetAppVerSEL, _gPID)))

#define FDRMScriptDataGetAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataGetAuthoritySELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataGetAuthoritySEL, _gPID)))

#define FDRMScriptDataSetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetDivisionSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetDivisionSEL, _gPID)))

#define FDRMScriptDataSetFormatOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetFormatOrgSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetFormatOrgSEL, _gPID)))

#define FDRMScriptDataSetFormatVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetFormatVerSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetFormatVerSEL, _gPID)))

#define FDRMScriptDataSetAppOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetAppOrgSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetAppOrgSEL, _gPID)))

#define FDRMScriptDataSetAppVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetAppVerSELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetAppVerSEL, _gPID)))

#define FDRMScriptDataSetAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMScriptDataSetAuthoritySELPROTO)FRCOREROUTINE(FDRMScriptDataSEL,FDRMScriptDataSetAuthoritySEL, _gPID)))

//*****************************
/* PresentationData HFT functions */
//*****************************

#define FDRMPresentationDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataNewSELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataNewSEL, _gPID)))

#define FDRMPresentationDataDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataDestroySELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataDestroySEL, _gPID)))

#define FDRMPresentationDataGetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataGetDivisionSELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataGetDivisionSEL, _gPID)))

#define FDRMPresentationDataGetAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataGetAuthoritySELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataGetAuthoritySEL, _gPID)))

#define FDRMPresentationDataSetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataSetDivisionSELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataSetDivisionSEL, _gPID)))

#define FDRMPresentationDataSetAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMPresentationDataSetAuthoritySELPROTO)FRCOREROUTINE(FDRMPresentationDataSEL,FDRMPresentationDataSetAuthoritySEL, _gPID)))

//*****************************
/* SignatureData HFT functions */
//*****************************

#define FDRMSignatureDataNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataNewSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataNewSEL, _gPID)))

#define FDRMSignatureDataDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataDestroySELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataDestroySEL, _gPID)))

#define FDRMSignatureDataGetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetDivisionSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetDivisionSEL, _gPID)))

#define FDRMSignatureDataGetAgentOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetAgentOrgSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetAgentOrgSEL, _gPID)))

#define FDRMSignatureDataGetAgentVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetAgentVerSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetAgentVerSEL, _gPID)))

#define FDRMSignatureDataGetFormatOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetFormatOrgSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetFormatOrgSEL, _gPID)))

#define FDRMSignatureDataGetFormatVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetFormatVerSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetFormatVerSEL, _gPID)))

#define FDRMSignatureDataGetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataGetKeySELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataGetKeySEL, _gPID)))

#define FDRMSignatureDataSetDivision (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetDivisionSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetDivisionSEL, _gPID)))

#define FDRMSignatureDataSetAgentOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetAgentOrgSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetAgentOrgSEL, _gPID)))

#define FDRMSignatureDataSetAgentVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetAgentVerSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetAgentVerSEL, _gPID)))

#define FDRMSignatureDataSetFormatOrg (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetFormatOrgSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetFormatOrgSEL, _gPID)))

#define FDRMSignatureDataSetFormatVer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetFormatVerSELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetFormatVerSEL, _gPID)))

#define FDRMSignatureDataSetKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMSignatureDataSetKeySELPROTO)FRCOREROUTINE(FDRMSignatureDataSEL,FDRMSignatureDataSetKeySEL, _gPID)))

//*****************************
/* DescRead HFT functions */
//*****************************

#define FDRMDescReadNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadNewSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadNewSEL, _gPID)))

#define FDRMDescReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadDestroySELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadDestroySEL, _gPID)))

#define FDRMDescReadLoad (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadLoadSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadLoadSEL, _gPID)))

#define FDRMDescReadVerifyDescriptor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadVerifyDescriptorSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadVerifyDescriptorSEL, _gPID)))

#define FDRMDescReadGetDescType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetDescTypeSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetDescTypeSEL, _gPID)))

#define FDRMDescReadGetScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetScriptSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetScriptSEL, _gPID)))

#define FDRMDescReadCountScripts (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadCountScriptsSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadCountScriptsSEL, _gPID)))

#define FDRMDescReadGetScript2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetScript2SELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetScript2SEL, _gPID)))

#define FDRMDescReadGetScriptData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetScriptDataSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetScriptDataSEL, _gPID)))

#define FDRMDescReadGetScriptParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetScriptParamsSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetScriptParamsSEL, _gPID)))

#define FDRMDescReadGetPresentation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetPresentationSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetPresentationSEL, _gPID)))

#define FDRMDescReadGetPresentationData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetPresentationDataSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetPresentationDataSEL, _gPID)))

#define FDRMDescReadGetPresentationParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetPresentationParamsSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetPresentationParamsSEL, _gPID)))

#define FDRMDescReadGetSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetSignatureSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetSignatureSEL, _gPID)))

#define FDRMDescReadGetSignatureData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetSignatureDataSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetSignatureDataSEL, _gPID)))

#define FDRMDescReadGetSignatureParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetSignatureParamsSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetSignatureParamsSEL, _gPID)))

#define FDRMDescReadGetSignatureData2 (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadGetSignatureData2SELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadGetSignatureData2SEL, _gPID)))

#define FDRMDescReadCheckSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadCheckSignatureSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadCheckSignatureSEL, _gPID)))

#define FDRMDescReadVerifyValidation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescReadVerifyValidationSELPROTO)FRCOREROUTINE(FDRMDescReadSEL,FDRMDescReadVerifyValidationSEL, _gPID)))

//*****************************
/* DescWrite HFT functions */
//*****************************

#define FDRMDescWriteNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteNewSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteNewSEL, _gPID)))

#define FDRMDescWriteDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteDestroySELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteDestroySEL, _gPID)))

#define FDRMDescWriteInitDescriptor (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteInitDescriptorSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteInitDescriptorSEL, _gPID)))

#define FDRMDescWriteRemoveScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteRemoveScriptSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteRemoveScriptSEL, _gPID)))

#define FDRMDescWriteAddScript (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteAddScriptSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteAddScriptSEL, _gPID)))

#define FDRMDescWriteSetScriptFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetScriptFormatSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetScriptFormatSEL, _gPID)))

#define FDRMDescWriteSetScriptApplication (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetScriptApplicationSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetScriptApplicationSEL, _gPID)))

#define FDRMDescWriteSetScriptAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetScriptAuthoritySELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetScriptAuthoritySEL, _gPID)))

#define FDRMDescWriteSetScriptParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetScriptParamsSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetScriptParamsSEL, _gPID)))

#define FDRMDescWriteRemovePresentation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteRemovePresentationSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteRemovePresentationSEL, _gPID)))

#define FDRMDescWriteAddPresentation (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteAddPresentationSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteAddPresentationSEL, _gPID)))

#define FDRMDescWriteSetPresentationAuthority (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetPresentationAuthoritySELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetPresentationAuthoritySEL, _gPID)))

#define FDRMDescWriteSetPresentationParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetPresentationParamsSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetPresentationParamsSEL, _gPID)))

#define FDRMDescWriteRemoveSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteRemoveSignatureSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteRemoveSignatureSEL, _gPID)))

#define FDRMDescWriteAddSignature (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteAddSignatureSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteAddSignatureSEL, _gPID)))

#define FDRMDescWriteSetSignatureAgent (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetSignatureAgentSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetSignatureAgentSEL, _gPID)))

#define FDRMDescWriteSetSignatureFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetSignatureFormatSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetSignatureFormatSEL, _gPID)))

#define FDRMDescWriteSetSignatureParams (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetSignatureParamsSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetSignatureParamsSEL, _gPID)))

#define FDRMDescWriteSetSignatureKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSetSignatureKeySELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSetSignatureKeySEL, _gPID)))

#define FDRMDescWriteSave (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteSaveSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteSaveSEL, _gPID)))

#define FDRMDescWriteCastToDescRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMDescWriteCastToDescReadSELPROTO)FRCOREROUTINE(FDRMDescWriteSEL,FDRMDescWriteCastToDescReadSEL, _gPID)))

//*****************************
/* FoacRead HFT functions */
//*****************************

#define FDRMFoacReadNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadNewSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadNewSEL, _gPID)))

#define FDRMFoacReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadDestroySELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadDestroySEL, _gPID)))

#define FDRMFoacReadGetDescRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetDescReadSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetDescReadSEL, _gPID)))

#define FDRMFoacReadVerifyFoac (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadVerifyFoacSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadVerifyFoacSEL, _gPID)))

#define FDRMFoacReadGetType (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetTypeSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetTypeSEL, _gPID)))

#define FDRMFoacReadGetSessionID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetSessionIDSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetSessionIDSEL, _gPID)))

#define FDRMFoacReadGetRequestID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetRequestIDSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetRequestIDSEL, _gPID)))

#define FDRMFoacReadGetRequestData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetRequestDataSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetRequestDataSEL, _gPID)))

#define FDRMFoacReadGetAnswerState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetAnswerStateSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetAnswerStateSEL, _gPID)))

#define FDRMFoacReadGetAnswerData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacReadGetAnswerDataSELPROTO)FRCOREROUTINE(FDRMFoacReadSEL,FDRMFoacReadGetAnswerDataSEL, _gPID)))

//*****************************
/* FoacWrite HFT functions */
//*****************************

#define FDRMFoacWriteNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteNewSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteNewSEL, _gPID)))

#define FDRMFoacWriteDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteDestroySELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteDestroySEL, _gPID)))

#define FDRMFoacWriteGetDescWrite (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteGetDescWriteSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteGetDescWriteSEL, _gPID)))

#define FDRMFoacWriteInitFoac (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteInitFoacSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteInitFoacSEL, _gPID)))

#define FDRMFoacWriteSetSessionID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteSetSessionIDSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteSetSessionIDSEL, _gPID)))

#define FDRMFoacWriteSetRequestID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteSetRequestIDSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteSetRequestIDSEL, _gPID)))

#define FDRMFoacWriteSetRequestData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteSetRequestDataSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteSetRequestDataSEL, _gPID)))

#define FDRMFoacWriteSetAnswerState (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteSetAnswerStateSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteSetAnswerStateSEL, _gPID)))

#define FDRMFoacWriteSetAnswerData (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteSetAnswerDataSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteSetAnswerDataSEL, _gPID)))

#define FDRMFoacWriteCastToFoacRead (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMFoacWriteCastToFoacReadSELPROTO)FRCOREROUTINE(FDRMFoacWriteSEL,FDRMFoacWriteCastToFoacReadSEL, _gPID)))

//*****************************
/* EnvelopeRead HFT functions */
//*****************************

#define FDRMEnvelopeReadNew (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadNewSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadNewSEL, _gPID)))

#define FDRMEnvelopeReadDestroy (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadDestroySELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadDestroySEL, _gPID)))

#define FDRMEnvelopeReadLoadEnvelope (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadLoadEnvelopeSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadLoadEnvelopeSEL, _gPID)))

#define FDRMEnvelopeReadGetFormat (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetFormatSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetFormatSEL, _gPID)))

#define FDRMEnvelopeReadGetApplication (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetApplicationSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetApplicationSEL, _gPID)))

#define FDRMEnvelopeReadGetEnvelopeSN (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetEnvelopeSNSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetEnvelopeSNSEL, _gPID)))

#define FDRMEnvelopeReadGetFileID (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetFileIDSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetFileIDSEL, _gPID)))

#define FDRMEnvelopeReadGetIssuer (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetIssuerSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetIssuerSEL, _gPID)))

#define FDRMEnvelopeReadGetConsumerId (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetConsumerIdSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetConsumerIdSEL, _gPID)))

#define FDRMEnvelopeReadCountAuthKeys (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadCountAuthKeysSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadCountAuthKeysSEL, _gPID)))

#define FDRMEnvelopeReadGetAuthKey (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetAuthKeySELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetAuthKeySEL, _gPID)))

#define FDRMEnvelopeReadCountLimits (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadCountLimitsSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadCountLimitsSEL, _gPID)))

#define FDRMEnvelopeReadGetLimit (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetLimitSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetLimitSEL, _gPID)))

#define FDRMEnvelopeReadCountRights (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadCountRightsSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadCountRightsSEL, _gPID)))

#define FDRMEnvelopeReadGetRight (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetRightSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetRightSEL, _gPID)))

#define FDRMEnvelopeReadGetCipher (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadGetCipherSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadGetCipherSEL, _gPID)))

#define FDRMEnvelopeReadValidateEnvelope (FS_ASSERT(_gpCoreHFTMgr->FRGetSDKVersion() >= SDK_VERSION),(*(FDRMEnvelopeReadValidateEnvelopeSELPROTO)FRCOREROUTINE(FDRMEnvelopeReadSEL,FDRMEnvelopeReadValidateEnvelopeSEL, _gPID)))

//----------_V3----------
//----------_V4----------
//----------_V5----------
//----------_V6----------
//----------_V7----------
//----------_V8----------
//----------_V9----------
//----------_V10----------
#ifdef __cplusplus
}
#endif

#endif