/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: dirk@opensg.org, gerrit.voss@vossg.org, carsten_neumann@gmx.net  *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                License                                    *
 *                                                                           *
 * This library is free software; you can redistribute it and/or modify it   *
 * under the terms of the GNU Library General Public License as published    *
 * by the Free Software Foundation, version 2.                               *
 *                                                                           *
 * This library is distributed in the hope that it will be useful, but       *
 * WITHOUT ANY WARRANTY; without even the implied warranty of                *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU         *
 * Library General Public License for more details.                          *
 *                                                                           *
 * You should have received a copy of the GNU Library General Public         *
 * License along with this library; if not, write to the Free Software       *
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.                 *
 *                                                                           *
\*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*\
 *                                Changes                                    *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
 *                                                                           *
\*---------------------------------------------------------------------------*/

/*****************************************************************************\
 *****************************************************************************
 **                                                                         **
 **                  This file is automatically generated.                  **
 **                                                                         **
 **          Any changes made to this file WILL be lost when it is          **
 **           regenerated, which can become necessary at any time.          **
 **                                                                         **
 **     Do not change this file, changes should be done in the derived      **
 **     class FishEyeProjectorData
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGFISHEYEPROJECTORDATABASE_H_
#define _OSGFISHEYEPROJECTORDATABASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGEffectGroupsDef.h"

//#include "OSGBaseTypes.h"

#include "OSGStageData.h" // Parent

#include "OSGFrameBufferObjectFields.h" // RenderTarget type
#include "OSGTextureObjChunkFields.h"   // Textures type
#include "OSGSysFields.h"               // TextureRes type
#include "OSGBaseFields.h"              // TextureFormat type
#include "OSGCameraFields.h"            // Camera type

#include "OSGFishEyeProjectorDataFields.h"

OSG_BEGIN_NAMESPACE


class FishEyeProjectorData;

//! \brief FishEyeProjectorData Base Class.

class OSG_EFFECTGROUPS_DLLMAPPING FishEyeProjectorDataBase : public StageData
{
  public:

    typedef StageData Inherited;
    typedef StageData ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(FishEyeProjectorData);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        RenderTargetFieldId = Inherited::NextFieldId,
        TexturesFieldId = RenderTargetFieldId + 1,
        TextureResFieldId = TexturesFieldId + 1,
        TextureFormatFieldId = TextureResFieldId + 1,
        CameraFieldId = TextureFormatFieldId + 1,
        NextFieldId = CameraFieldId + 1
    };

    static const OSG::BitVector RenderTargetFieldMask =
        (TypeTraits<BitVector>::One << RenderTargetFieldId);
    static const OSG::BitVector TexturesFieldMask =
        (TypeTraits<BitVector>::One << TexturesFieldId);
    static const OSG::BitVector TextureResFieldMask =
        (TypeTraits<BitVector>::One << TextureResFieldId);
    static const OSG::BitVector TextureFormatFieldMask =
        (TypeTraits<BitVector>::One << TextureFormatFieldId);
    static const OSG::BitVector CameraFieldMask =
        (TypeTraits<BitVector>::One << CameraFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFUnrecFrameBufferObjectPtr SFRenderTargetType;
    typedef MFUnrecTextureObjChunkPtr MFTexturesType;
    typedef SFUInt32          SFTextureResType;
    typedef SFGLenum          SFTextureFormatType;
    typedef SFUnrecCameraPtr  SFCameraType;

    /*---------------------------------------------------------------------*/
    /*! \name                    Class Get                                 */
    /*! \{                                                                 */

    static FieldContainerType &getClassType   (void);
    static UInt32              getClassTypeId (void);
    static UInt16              getClassGroupId(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                FieldContainer Get                            */
    /*! \{                                                                 */

    virtual       FieldContainerType &getType         (void);
    virtual const FieldContainerType &getType         (void) const;

    virtual       UInt32              getContainerSize(void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Get                                 */
    /*! \{                                                                 */

            const SFUnrecFrameBufferObjectPtr *getSFRenderTarget   (void) const;
                  SFUnrecFrameBufferObjectPtr *editSFRenderTarget   (void);
            const MFUnrecTextureObjChunkPtr *getMFTextures       (void) const;
                  MFUnrecTextureObjChunkPtr *editMFTextures       (void);

                  SFUInt32            *editSFTextureRes     (void);
            const SFUInt32            *getSFTextureRes      (void) const;

                  SFGLenum            *editSFTextureFormat  (void);
            const SFGLenum            *getSFTextureFormat   (void) const;
            const SFUnrecCameraPtr    *getSFCamera         (void) const;
                  SFUnrecCameraPtr    *editSFCamera         (void);


                  FrameBufferObject * getRenderTarget   (void) const;

                  TextureObjChunk * getTextures       (const UInt32 index) const;

                  UInt32              &editTextureRes     (void);
                  UInt32               getTextureRes      (void) const;

                  GLenum              &editTextureFormat  (void);
            const GLenum              &getTextureFormat   (void) const;

                  Camera * getCamera         (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setRenderTarget   (FrameBufferObject * const value);
            void setTextureRes     (const UInt32 value);
            void setTextureFormat  (const GLenum &value);
            void setCamera         (Camera * const value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr Field Set                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

    void pushToTextures            (TextureObjChunk * const value   );
    void assignTextures           (const MFUnrecTextureObjChunkPtr &value);
    void removeFromTextures (UInt32               uiIndex );
    void removeObjFromTextures(TextureObjChunk * const value   );
    void clearTextures              (void                         );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Binary Access                              */
    /*! \{                                                                 */

    virtual SizeT  getBinSize (ConstFieldMaskArg  whichField);
    virtual void   copyToBin  (BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);
    virtual void   copyFromBin(BinaryDataHandler &pMem,
                               ConstFieldMaskArg  whichField);


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Construction                               */
    /*! \{                                                                 */

    static  FishEyeProjectorDataTransitPtr  create          (void);
    static  FishEyeProjectorData           *createEmpty     (void);

    static  FishEyeProjectorDataTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  FishEyeProjectorData            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  FishEyeProjectorDataTransitPtr  createDependent  (BitVector bFlags);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Copy                                   */
    /*! \{                                                                 */

    virtual FieldContainerTransitPtr shallowCopy     (void) const;
    virtual FieldContainerTransitPtr shallowCopyLocal(
                                       BitVector bFlags = FCLocal::All) const;
    virtual FieldContainerTransitPtr shallowCopyDependent(
                                                      BitVector bFlags) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    static TypeObject _type;

    static       void   classDescInserter(TypeObject &oType);
    static const Char8 *getClassname     (void             );

    /*---------------------------------------------------------------------*/
    /*! \name                      Fields                                  */
    /*! \{                                                                 */

    SFUnrecFrameBufferObjectPtr _sfRenderTarget;
    MFUnrecTextureObjChunkPtr _mfTextures;
    SFUInt32          _sfTextureRes;
    SFGLenum          _sfTextureFormat;
    SFUnrecCameraPtr  _sfCamera;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    FishEyeProjectorDataBase(void);
    FishEyeProjectorDataBase(const FishEyeProjectorDataBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~FishEyeProjectorDataBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */

    void onCreate(const FishEyeProjectorData *source = NULL);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

     GetFieldHandlePtr  getHandleRenderTarget    (void) const;
     EditFieldHandlePtr editHandleRenderTarget   (void);
     GetFieldHandlePtr  getHandleTextures        (void) const;
     EditFieldHandlePtr editHandleTextures       (void);
     GetFieldHandlePtr  getHandleTextureRes      (void) const;
     EditFieldHandlePtr editHandleTextureRes     (void);
     GetFieldHandlePtr  getHandleTextureFormat   (void) const;
     EditFieldHandlePtr editHandleTextureFormat  (void);
     GetFieldHandlePtr  getHandleCamera          (void) const;
     EditFieldHandlePtr editHandleCamera         (void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual void execSyncV(      FieldContainer    &oFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);

            void execSync (      FishEyeProjectorDataBase *pFrom,
                                 ConstFieldMaskArg  whichField,
                                 AspectOffsetStore &oOffsets,
                                 ConstFieldMaskArg  syncMode  ,
                           const UInt32             uiSyncInfo);
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Aspect Create                            */
    /*! \{                                                                 */

#ifdef OSG_MT_CPTR_ASPECT
    virtual FieldContainer *createAspectCopy(
                                    const FieldContainer *pRefAspect) const;
#endif

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Edit                                   */
    /*! \{                                                                 */
    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Sync                                   */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:
    /*---------------------------------------------------------------------*/

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const FishEyeProjectorDataBase &source);
};

typedef FishEyeProjectorDataBase *FishEyeProjectorDataBaseP;

OSG_END_NAMESPACE

#endif /* _OSGFISHEYEPROJECTORDATABASE_H_ */
