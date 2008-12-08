/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
 *                                                                           *
 *                            www.opensg.org                                 *
 *                                                                           *
 *   contact: dirk@opensg.org, gerrit.voss@vossg.org, jbehr@zgdv.de          *
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
 **     class ShaderVariableVec3f!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <boost/assign/list_of.hpp>

#include <OSGConfig.h>




#include "OSGShaderVariableVec3fBase.h"
#include "OSGShaderVariableVec3f.h"

#include "boost/bind.hpp"

#ifdef WIN32 // turn off 'this' : used in base member initializer list warning
#pragma warning(disable:4355)
#endif

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::ShaderVariableVec3f
    
 */

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

/*! \var Vec3f           ShaderVariableVec3fBase::_sfValue
    parameter value
*/


void ShaderVariableVec3fBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFVec3f::Description(
        SFVec3f::getClassType(),
        "value",
        "parameter value\n",
        ValueFieldId, ValueFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&ShaderVariableVec3f::editHandleValue),
        static_cast<FieldGetMethodSig >(&ShaderVariableVec3f::getHandleValue));

    oType.addInitialDesc(pDesc);
}


ShaderVariableVec3fBase::TypeObject ShaderVariableVec3fBase::_type(
    ShaderVariableVec3fBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    0,
    reinterpret_cast<PrototypeCreateF>(&ShaderVariableVec3fBase::createEmptyLocal),
    ShaderVariableVec3f::initMethod,
    ShaderVariableVec3f::exitMethod,
    reinterpret_cast<InitalInsertDescFunc>(&ShaderVariableVec3fBase::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "\tname=\"ShaderVariableVec3f\"\n"
    "\tparent=\"ShaderValueVariable\"\n"
    "\tlibrary=\"System\"\n"
    "\tpointerfieldtypes=\"both\"\n"
    "\tstructure=\"concrete\"\n"
    "\tsystemcomponent=\"true\"\n"
    "\tparentsystemcomponent=\"true\"\n"
    "\tdecoratable=\"false\"\n"
    "\tuseLocalIncludes=\"false\"\n"
    ">\n"
    "\t<Field\n"
    "\t\tname=\"value\"\n"
    "\t\ttype=\"Vec3f\"\n"
    "\t\tcardinality=\"single\"\n"
    "\t\tvisibility=\"external\"\n"
    "\t\taccess=\"public\"\n"
    "\t>\n"
    "\tparameter value\n"
    "\t</Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &ShaderVariableVec3fBase::getType(void)
{
    return _type;
}

const FieldContainerType &ShaderVariableVec3fBase::getType(void) const
{
    return _type;
}

UInt32 ShaderVariableVec3fBase::getContainerSize(void) const
{
    return sizeof(ShaderVariableVec3f);
}

/*------------------------- decorator get ------------------------------*/


SFVec3f *ShaderVariableVec3fBase::editSFValue(void)
{
    editSField(ValueFieldMask);

    return &_sfValue;
}

const SFVec3f *ShaderVariableVec3fBase::getSFValue(void) const
{
    return &_sfValue;
}






/*------------------------------ access -----------------------------------*/

UInt32 ShaderVariableVec3fBase::getBinSize(ConstFieldMaskArg whichField)
{
    UInt32 returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        returnValue += _sfValue.getBinSize();
    }

    return returnValue;
}

void ShaderVariableVec3fBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyToBin(pMem);
    }
}

void ShaderVariableVec3fBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (ValueFieldMask & whichField))
    {
        _sfValue.copyFromBin(pMem);
    }
}

//! create a new instance of the class
ShaderVariableVec3fTransitPtr ShaderVariableVec3fBase::createLocal(BitVector bFlags)
{
    ShaderVariableVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<ShaderVariableVec3f>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
ShaderVariableVec3fTransitPtr ShaderVariableVec3fBase::createDependent(BitVector bFlags)
{
    ShaderVariableVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<ShaderVariableVec3f>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
ShaderVariableVec3fTransitPtr ShaderVariableVec3fBase::create(void)
{
    ShaderVariableVec3fTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<ShaderVariableVec3f>(tmpPtr);
    }

    return fc;
}

ShaderVariableVec3f *ShaderVariableVec3fBase::createEmptyLocal(BitVector bFlags)
{
    ShaderVariableVec3f *returnValue;

    newPtr<ShaderVariableVec3f>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
ShaderVariableVec3f *ShaderVariableVec3fBase::createEmpty(void)
{
    ShaderVariableVec3f *returnValue;

    newPtr<ShaderVariableVec3f>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr ShaderVariableVec3fBase::shallowCopyLocal(
    BitVector bFlags) const
{
    ShaderVariableVec3f *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderVariableVec3f *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderVariableVec3fBase::shallowCopyDependent(
    BitVector bFlags) const
{
    ShaderVariableVec3f *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const ShaderVariableVec3f *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr ShaderVariableVec3fBase::shallowCopy(void) const
{
    ShaderVariableVec3f *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const ShaderVariableVec3f *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

ShaderVariableVec3fBase::ShaderVariableVec3fBase(void) :
    Inherited(),
    _sfValue                  ()
{
}

ShaderVariableVec3fBase::ShaderVariableVec3fBase(const ShaderVariableVec3fBase &source) :
    Inherited(source),
    _sfValue                  (source._sfValue                  )
{
}


/*-------------------------- destructors ----------------------------------*/

ShaderVariableVec3fBase::~ShaderVariableVec3fBase(void)
{
}


GetFieldHandlePtr ShaderVariableVec3fBase::getHandleValue           (void) const
{
    SFVec3f::GetHandlePtr returnValue(
        new  SFVec3f::GetHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId)));

    return returnValue;
}

EditFieldHandlePtr ShaderVariableVec3fBase::editHandleValue          (void)
{
    SFVec3f::EditHandlePtr returnValue(
        new  SFVec3f::EditHandle(
             &_sfValue,
             this->getType().getFieldDesc(ValueFieldId)));


    editSField(ValueFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void ShaderVariableVec3fBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    ShaderVariableVec3f *pThis = static_cast<ShaderVariableVec3f *>(this);

    pThis->execSync(static_cast<ShaderVariableVec3f *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *ShaderVariableVec3fBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    ShaderVariableVec3f *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const ShaderVariableVec3f *>(pRefAspect),
                  dynamic_cast<const ShaderVariableVec3f *>(this));

    return returnValue;
}
#endif

void ShaderVariableVec3fBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
DataType FieldTraits<ShaderVariableVec3f *>::_type("ShaderVariableVec3fPtr", "ShaderValueVariablePtr");
#endif

OSG_FIELDTRAITS_GETTYPE(ShaderVariableVec3f *)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           ShaderVariableVec3f *,
                           0);

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           ShaderVariableVec3f *,
                           0);

OSG_END_NAMESPACE