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
 **     class BalancedMultiWindow!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>

#ifdef WIN32 
#pragma warning(disable: 4355) // turn off 'this' : used in base member initializer list warning
#pragma warning(disable: 4290) // disable exception specification warning
#endif

#include "OSGConfig.h"




#include "OSGBalancedMultiWindowBase.h"
#include "OSGBalancedMultiWindow.h"

#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::BalancedMultiWindow
    Load balanced sort first rendering for multiple windows
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var bool            BalancedMultiWindowBase::_sfBalance
    If true load balancing is eanbled. If falst it behaves like a
    MultiDisplayWindow 
*/

/*! \var bool            BalancedMultiWindowBase::_sfBestCut
    If true horizontal and vertical cuts are testet. Otherwise the longes side
    of a viewport is split. 
*/

/*! \var bool            BalancedMultiWindowBase::_sfShowBalancing
    Mark regions rendered by other hosts
*/

/*! \var UInt32          BalancedMultiWindowBase::_sfTileSize
    
*/

/*! \var bool            BalancedMultiWindowBase::_sfShort
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<BalancedMultiWindow *, nsOSG>::_type(
    "BalancedMultiWindowPtr", 
    "MultiDisplayWindowPtr", 
    BalancedMultiWindow::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(BalancedMultiWindow *, nsOSG)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void BalancedMultiWindowBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "balance",
        "If true load balancing is eanbled. If falst it behaves like a\n"
        "MultiDisplayWindow \n",
        BalanceFieldId, BalanceFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&BalancedMultiWindow::editHandleBalance),
        static_cast<FieldGetMethodSig >(&BalancedMultiWindow::getHandleBalance));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "bestCut",
        "If true horizontal and vertical cuts are testet. Otherwise the longes side\n"
        "of a viewport is split. \n",
        BestCutFieldId, BestCutFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&BalancedMultiWindow::editHandleBestCut),
        static_cast<FieldGetMethodSig >(&BalancedMultiWindow::getHandleBestCut));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "showBalancing",
        "Mark regions rendered by other hosts\n",
        ShowBalancingFieldId, ShowBalancingFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&BalancedMultiWindow::editHandleShowBalancing),
        static_cast<FieldGetMethodSig >(&BalancedMultiWindow::getHandleShowBalancing));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUInt32::Description(
        SFUInt32::getClassType(),
        "tileSize",
        "",
        TileSizeFieldId, TileSizeFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&BalancedMultiWindow::editHandleTileSize),
        static_cast<FieldGetMethodSig >(&BalancedMultiWindow::getHandleTileSize));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "short",
        "",
        ShortFieldId, ShortFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&BalancedMultiWindow::editHandleShort),
        static_cast<FieldGetMethodSig >(&BalancedMultiWindow::getHandleShort));

    oType.addInitialDesc(pDesc);
}


BalancedMultiWindowBase::TypeObject BalancedMultiWindowBase::_type(
    BalancedMultiWindowBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&BalancedMultiWindowBase::createEmptyLocal),
    reinterpret_cast<InitContainerF>(&BalancedMultiWindow::initMethod),
    reinterpret_cast<ExitContainerF>(&BalancedMultiWindow::exitMethod),
    reinterpret_cast<InitalInsertDescFunc>(&BalancedMultiWindow::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"BalancedMultiWindow\"\n"
    "   parent=\"MultiDisplayWindow\"\n"
    "   library=\"Cluster\"\n"
    "   pointerfieldtypes=\"none\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   decoratable=\"false\"\n"
    "   useLocalIncludes=\"true\"\n"
    "   docGroupBase=\"GrpClusterWindow\"\n"
    "   >\n"
    "  Load balanced sort first rendering for multiple windows\n"
    "  <Field\n"
    "\t name=\"balance\"\n"
    "\t type=\"bool\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue=\"true\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "\tIf true load balancing is eanbled. If falst it behaves like a\n"
    "\tMultiDisplayWindow \n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"bestCut\"\n"
    "\t type=\"bool\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue=\"true\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "\tIf true horizontal and vertical cuts are testet. Otherwise the longes side\n"
    "\tof a viewport is split. \n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"showBalancing\"\n"
    "\t type=\"bool\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue=\"false\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "\tMark regions rendered by other hosts\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"tileSize\"\n"
    "\t type=\"UInt32\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue=\"44\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"short\"\n"
    "\t type=\"bool\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue=\"true\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    "Load balanced sort first rendering for multiple windows\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &BalancedMultiWindowBase::getType(void)
{
    return _type;
}

const FieldContainerType &BalancedMultiWindowBase::getType(void) const
{
    return _type;
}

UInt32 BalancedMultiWindowBase::getContainerSize(void) const
{
    return sizeof(BalancedMultiWindow);
}

/*------------------------- decorator get ------------------------------*/


SFBool *BalancedMultiWindowBase::editSFBalance(void)
{
    editSField(BalanceFieldMask);

    return &_sfBalance;
}

const SFBool *BalancedMultiWindowBase::getSFBalance(void) const
{
    return &_sfBalance;
}


SFBool *BalancedMultiWindowBase::editSFBestCut(void)
{
    editSField(BestCutFieldMask);

    return &_sfBestCut;
}

const SFBool *BalancedMultiWindowBase::getSFBestCut(void) const
{
    return &_sfBestCut;
}


SFBool *BalancedMultiWindowBase::editSFShowBalancing(void)
{
    editSField(ShowBalancingFieldMask);

    return &_sfShowBalancing;
}

const SFBool *BalancedMultiWindowBase::getSFShowBalancing(void) const
{
    return &_sfShowBalancing;
}


SFUInt32 *BalancedMultiWindowBase::editSFTileSize(void)
{
    editSField(TileSizeFieldMask);

    return &_sfTileSize;
}

const SFUInt32 *BalancedMultiWindowBase::getSFTileSize(void) const
{
    return &_sfTileSize;
}


SFBool *BalancedMultiWindowBase::editSFShort(void)
{
    editSField(ShortFieldMask);

    return &_sfShort;
}

const SFBool *BalancedMultiWindowBase::getSFShort(void) const
{
    return &_sfShort;
}






/*------------------------------ access -----------------------------------*/

SizeT BalancedMultiWindowBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (BalanceFieldMask & whichField))
    {
        returnValue += _sfBalance.getBinSize();
    }
    if(FieldBits::NoField != (BestCutFieldMask & whichField))
    {
        returnValue += _sfBestCut.getBinSize();
    }
    if(FieldBits::NoField != (ShowBalancingFieldMask & whichField))
    {
        returnValue += _sfShowBalancing.getBinSize();
    }
    if(FieldBits::NoField != (TileSizeFieldMask & whichField))
    {
        returnValue += _sfTileSize.getBinSize();
    }
    if(FieldBits::NoField != (ShortFieldMask & whichField))
    {
        returnValue += _sfShort.getBinSize();
    }

    return returnValue;
}

void BalancedMultiWindowBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (BalanceFieldMask & whichField))
    {
        _sfBalance.copyToBin(pMem);
    }
    if(FieldBits::NoField != (BestCutFieldMask & whichField))
    {
        _sfBestCut.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShowBalancingFieldMask & whichField))
    {
        _sfShowBalancing.copyToBin(pMem);
    }
    if(FieldBits::NoField != (TileSizeFieldMask & whichField))
    {
        _sfTileSize.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ShortFieldMask & whichField))
    {
        _sfShort.copyToBin(pMem);
    }
}

void BalancedMultiWindowBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (BalanceFieldMask & whichField))
    {
        editSField(BalanceFieldMask);
        _sfBalance.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (BestCutFieldMask & whichField))
    {
        editSField(BestCutFieldMask);
        _sfBestCut.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShowBalancingFieldMask & whichField))
    {
        editSField(ShowBalancingFieldMask);
        _sfShowBalancing.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (TileSizeFieldMask & whichField))
    {
        editSField(TileSizeFieldMask);
        _sfTileSize.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ShortFieldMask & whichField))
    {
        editSField(ShortFieldMask);
        _sfShort.copyFromBin(pMem);
    }
}

//! create a new instance of the class
BalancedMultiWindowTransitPtr BalancedMultiWindowBase::createLocal(BitVector bFlags)
{
    BalancedMultiWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<BalancedMultiWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
BalancedMultiWindowTransitPtr BalancedMultiWindowBase::createDependent(BitVector bFlags)
{
    BalancedMultiWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<BalancedMultiWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
BalancedMultiWindowTransitPtr BalancedMultiWindowBase::create(void)
{
    BalancedMultiWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<BalancedMultiWindow>(tmpPtr);
    }

    return fc;
}

BalancedMultiWindow *BalancedMultiWindowBase::createEmptyLocal(BitVector bFlags)
{
    BalancedMultiWindow *returnValue;

    newPtr<BalancedMultiWindow>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
BalancedMultiWindow *BalancedMultiWindowBase::createEmpty(void)
{
    BalancedMultiWindow *returnValue;

    newPtr<BalancedMultiWindow>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr BalancedMultiWindowBase::shallowCopyLocal(
    BitVector bFlags) const
{
    BalancedMultiWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const BalancedMultiWindow *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr BalancedMultiWindowBase::shallowCopyDependent(
    BitVector bFlags) const
{
    BalancedMultiWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const BalancedMultiWindow *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr BalancedMultiWindowBase::shallowCopy(void) const
{
    BalancedMultiWindow *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const BalancedMultiWindow *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

BalancedMultiWindowBase::BalancedMultiWindowBase(void) :
    Inherited(),
    _sfBalance                (bool(true)),
    _sfBestCut                (bool(true)),
    _sfShowBalancing          (bool(false)),
    _sfTileSize               (UInt32(44)),
    _sfShort                  (bool(true))
{
}

BalancedMultiWindowBase::BalancedMultiWindowBase(const BalancedMultiWindowBase &source) :
    Inherited(source),
    _sfBalance                (source._sfBalance                ),
    _sfBestCut                (source._sfBestCut                ),
    _sfShowBalancing          (source._sfShowBalancing          ),
    _sfTileSize               (source._sfTileSize               ),
    _sfShort                  (source._sfShort                  )
{
}


/*-------------------------- destructors ----------------------------------*/

BalancedMultiWindowBase::~BalancedMultiWindowBase(void)
{
}


GetFieldHandlePtr BalancedMultiWindowBase::getHandleBalance         (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfBalance,
             this->getType().getFieldDesc(BalanceFieldId),
             const_cast<BalancedMultiWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr BalancedMultiWindowBase::editHandleBalance        (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfBalance,
             this->getType().getFieldDesc(BalanceFieldId),
             this));


    editSField(BalanceFieldMask);

    return returnValue;
}

GetFieldHandlePtr BalancedMultiWindowBase::getHandleBestCut         (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfBestCut,
             this->getType().getFieldDesc(BestCutFieldId),
             const_cast<BalancedMultiWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr BalancedMultiWindowBase::editHandleBestCut        (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfBestCut,
             this->getType().getFieldDesc(BestCutFieldId),
             this));


    editSField(BestCutFieldMask);

    return returnValue;
}

GetFieldHandlePtr BalancedMultiWindowBase::getHandleShowBalancing   (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShowBalancing,
             this->getType().getFieldDesc(ShowBalancingFieldId),
             const_cast<BalancedMultiWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr BalancedMultiWindowBase::editHandleShowBalancing  (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShowBalancing,
             this->getType().getFieldDesc(ShowBalancingFieldId),
             this));


    editSField(ShowBalancingFieldMask);

    return returnValue;
}

GetFieldHandlePtr BalancedMultiWindowBase::getHandleTileSize        (void) const
{
    SFUInt32::GetHandlePtr returnValue(
        new  SFUInt32::GetHandle(
             &_sfTileSize,
             this->getType().getFieldDesc(TileSizeFieldId),
             const_cast<BalancedMultiWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr BalancedMultiWindowBase::editHandleTileSize       (void)
{
    SFUInt32::EditHandlePtr returnValue(
        new  SFUInt32::EditHandle(
             &_sfTileSize,
             this->getType().getFieldDesc(TileSizeFieldId),
             this));


    editSField(TileSizeFieldMask);

    return returnValue;
}

GetFieldHandlePtr BalancedMultiWindowBase::getHandleShort           (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfShort,
             this->getType().getFieldDesc(ShortFieldId),
             const_cast<BalancedMultiWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr BalancedMultiWindowBase::editHandleShort          (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfShort,
             this->getType().getFieldDesc(ShortFieldId),
             this));


    editSField(ShortFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void BalancedMultiWindowBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    BalancedMultiWindow *pThis = static_cast<BalancedMultiWindow *>(this);

    pThis->execSync(static_cast<BalancedMultiWindow *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *BalancedMultiWindowBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    BalancedMultiWindow *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const BalancedMultiWindow *>(pRefAspect),
                  dynamic_cast<const BalancedMultiWindow *>(this));

    return returnValue;
}
#endif

void BalancedMultiWindowBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE
