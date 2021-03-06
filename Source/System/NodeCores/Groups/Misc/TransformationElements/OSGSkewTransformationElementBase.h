/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 * contact: David Kabala (djkabala@gmail.com)                                *
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
 **     class SkewTransformationElement
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSKEWTRANSFORMATIONELEMENTBASE_H_
#define _OSGSKEWTRANSFORMATIONELEMENTBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGGroupDef.h"

//#include "OSGBaseTypes.h"

#include "OSGTransformationElement.h" // Parent

#include "OSGVecFields.h"               // RotationAxis type
#include "OSGSysFields.h"               // Angle type

#include "OSGSkewTransformationElementFields.h"

OSG_BEGIN_NAMESPACE


class SkewTransformationElement;

//! \brief SkewTransformationElement Base Class.

class OSG_GROUP_DLLMAPPING SkewTransformationElementBase : public TransformationElement
{
  public:

    typedef TransformationElement Inherited;
    typedef TransformationElement ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(SkewTransformationElement);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        RotationAxisFieldId = Inherited::NextFieldId,
        TranslationAxisFieldId = RotationAxisFieldId + 1,
        AngleFieldId = TranslationAxisFieldId + 1,
        NextFieldId = AngleFieldId + 1
    };

    static const OSG::BitVector RotationAxisFieldMask =
        (TypeTraits<BitVector>::One << RotationAxisFieldId);
    static const OSG::BitVector TranslationAxisFieldMask =
        (TypeTraits<BitVector>::One << TranslationAxisFieldId);
    static const OSG::BitVector AngleFieldMask =
        (TypeTraits<BitVector>::One << AngleFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFVec3f           SFRotationAxisType;
    typedef SFVec3f           SFTranslationAxisType;
    typedef SFReal32          SFAngleType;

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


                  SFVec3f             *editSFRotationAxis   (void);
            const SFVec3f             *getSFRotationAxis    (void) const;

                  SFVec3f             *editSFTranslationAxis(void);
            const SFVec3f             *getSFTranslationAxis (void) const;

                  SFReal32            *editSFAngle          (void);
            const SFReal32            *getSFAngle           (void) const;


                  Vec3f               &editRotationAxis   (void);
            const Vec3f               &getRotationAxis    (void) const;

                  Vec3f               &editTranslationAxis(void);
            const Vec3f               &getTranslationAxis (void) const;

                  Real32              &editAngle          (void);
                  Real32               getAngle           (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setRotationAxis   (const Vec3f &value);
            void setTranslationAxis(const Vec3f &value);
            void setAngle          (const Real32 value);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                Ptr MField Set                                */
    /*! \{                                                                 */

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

    static  SkewTransformationElementTransitPtr  create          (void);
    static  SkewTransformationElement           *createEmpty     (void);

    static  SkewTransformationElementTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  SkewTransformationElement            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  SkewTransformationElementTransitPtr  createDependent  (BitVector bFlags);

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

    SFVec3f           _sfRotationAxis;
    SFVec3f           _sfTranslationAxis;
    SFReal32          _sfAngle;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    SkewTransformationElementBase(void);
    SkewTransformationElementBase(const SkewTransformationElementBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~SkewTransformationElementBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

     GetFieldHandlePtr  getHandleRotationAxis    (void) const;
     EditFieldHandlePtr editHandleRotationAxis   (void);
     GetFieldHandlePtr  getHandleTranslationAxis (void) const;
     EditFieldHandlePtr editHandleTranslationAxis(void);
     GetFieldHandlePtr  getHandleAngle           (void) const;
     EditFieldHandlePtr editHandleAngle          (void);

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

            void execSync (      SkewTransformationElementBase *pFrom,
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
    void operator =(const SkewTransformationElementBase &source);
};

typedef SkewTransformationElementBase *SkewTransformationElementBaseP;

OSG_END_NAMESPACE

#endif /* _OSGSKEWTRANSFORMATIONELEMENTBASE_H_ */
