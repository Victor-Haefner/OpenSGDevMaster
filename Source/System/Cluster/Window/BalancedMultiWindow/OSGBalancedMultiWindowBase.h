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
 **     class BalancedMultiWindow
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGBALANCEDMULTIWINDOWBASE_H_
#define _OSGBALANCEDMULTIWINDOWBASE_H_
#ifdef __sgi
#pragma once
#endif


#include "OSGConfig.h"
#include "OSGClusterDef.h"

//#include "OSGBaseTypes.h"

#include "OSGMultiDisplayWindow.h" // Parent

#include "OSGSysFields.h"               // Balance type

#include "OSGBalancedMultiWindowFields.h"

OSG_BEGIN_NAMESPACE


class BalancedMultiWindow;

//! \brief BalancedMultiWindow Base Class.

class OSG_CLUSTER_DLLMAPPING BalancedMultiWindowBase : public MultiDisplayWindow
{
  public:

    typedef MultiDisplayWindow Inherited;
    typedef MultiDisplayWindow ParentContainer;

    typedef Inherited::TypeObject TypeObject;
    typedef TypeObject::InitPhase InitPhase;

    OSG_GEN_INTERNALPTR(BalancedMultiWindow);

    /*==========================  PUBLIC  =================================*/

  public:

    enum
    {
        BalanceFieldId = Inherited::NextFieldId,
        BestCutFieldId = BalanceFieldId + 1,
        ShowBalancingFieldId = BestCutFieldId + 1,
        TileSizeFieldId = ShowBalancingFieldId + 1,
        ShortFieldId = TileSizeFieldId + 1,
        NextFieldId = ShortFieldId + 1
    };

    static const OSG::BitVector BalanceFieldMask =
        (TypeTraits<BitVector>::One << BalanceFieldId);
    static const OSG::BitVector BestCutFieldMask =
        (TypeTraits<BitVector>::One << BestCutFieldId);
    static const OSG::BitVector ShowBalancingFieldMask =
        (TypeTraits<BitVector>::One << ShowBalancingFieldId);
    static const OSG::BitVector TileSizeFieldMask =
        (TypeTraits<BitVector>::One << TileSizeFieldId);
    static const OSG::BitVector ShortFieldMask =
        (TypeTraits<BitVector>::One << ShortFieldId);
    static const OSG::BitVector NextFieldMask =
        (TypeTraits<BitVector>::One << NextFieldId);
        
    typedef SFBool            SFBalanceType;
    typedef SFBool            SFBestCutType;
    typedef SFBool            SFShowBalancingType;
    typedef SFUInt32          SFTileSizeType;
    typedef SFBool            SFShortType;

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


                  SFBool              *editSFBalance        (void);
            const SFBool              *getSFBalance         (void) const;

                  SFBool              *editSFBestCut        (void);
            const SFBool              *getSFBestCut         (void) const;

                  SFBool              *editSFShowBalancing  (void);
            const SFBool              *getSFShowBalancing   (void) const;

                  SFUInt32            *editSFTileSize       (void);
            const SFUInt32            *getSFTileSize        (void) const;

                  SFBool              *editSFShort          (void);
            const SFBool              *getSFShort           (void) const;


                  bool                &editBalance        (void);
                  bool                 getBalance         (void) const;

                  bool                &editBestCut        (void);
                  bool                 getBestCut         (void) const;

                  bool                &editShowBalancing  (void);
                  bool                 getShowBalancing   (void) const;

                  UInt32              &editTileSize       (void);
                  UInt32               getTileSize        (void) const;

                  bool                &editShort          (void);
                  bool                 getShort           (void) const;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Field Set                                 */
    /*! \{                                                                 */

            void setBalance        (const bool value);
            void setBestCut        (const bool value);
            void setShowBalancing  (const bool value);
            void setTileSize       (const UInt32 value);
            void setShort          (const bool value);

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

    static  BalancedMultiWindowTransitPtr  create          (void);
    static  BalancedMultiWindow           *createEmpty     (void);

    static  BalancedMultiWindowTransitPtr  createLocal     (
                                               BitVector bFlags = FCLocal::All);

    static  BalancedMultiWindow            *createEmptyLocal(
                                              BitVector bFlags = FCLocal::All);

    static  BalancedMultiWindowTransitPtr  createDependent  (BitVector bFlags);

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

    SFBool            _sfBalance;
    SFBool            _sfBestCut;
    SFBool            _sfShowBalancing;
    SFUInt32          _sfTileSize;
    SFBool            _sfShort;

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    BalancedMultiWindowBase(void);
    BalancedMultiWindowBase(const BalancedMultiWindowBase &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~BalancedMultiWindowBase(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     onCreate                                */
    /*! \{                                                                 */


    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                    Generic Field Access                      */
    /*! \{                                                                 */

     GetFieldHandlePtr  getHandleBalance         (void) const;
     EditFieldHandlePtr editHandleBalance        (void);
     GetFieldHandlePtr  getHandleBestCut         (void) const;
     EditFieldHandlePtr editHandleBestCut        (void);
     GetFieldHandlePtr  getHandleShowBalancing   (void) const;
     EditFieldHandlePtr editHandleShowBalancing  (void);
     GetFieldHandlePtr  getHandleTileSize        (void) const;
     EditFieldHandlePtr editHandleTileSize       (void);
     GetFieldHandlePtr  getHandleShort           (void) const;
     EditFieldHandlePtr editHandleShort          (void);

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

            void execSync (      BalancedMultiWindowBase *pFrom,
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
    void operator =(const BalancedMultiWindowBase &source);
};

typedef BalancedMultiWindowBase *BalancedMultiWindowBaseP;

OSG_END_NAMESPACE

#endif /* _OSGBALANCEDMULTIWINDOWBASE_H_ */
