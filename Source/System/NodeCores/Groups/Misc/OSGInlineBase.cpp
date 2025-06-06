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
 **     class Inline!
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



#include "OSGNode.h"                    // Root Class

#include "OSGInlineBase.h"
#include "OSGInline.h"

#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::Inline
    
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var std::string     InlineBase::_mfUrl
    
*/

/*! \var bool            InlineBase::_sfLoaded
    
*/

/*! \var Node *          InlineBase::_sfRoot
    
*/

/*! \var std::string     InlineBase::_sfGraphOp
    
*/

/*! \var std::string     InlineBase::_mfOptions
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<Inline *, nsOSG>::_type(
    "InlinePtr", 
    "RootGroupPtr", 
    Inline::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(Inline *, nsOSG)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           Inline *,
                           nsOSG)

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           Inline *,
                           nsOSG)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void InlineBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new MFString::Description(
        MFString::getClassType(),
        "url",
        "",
        UrlFieldId, UrlFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Inline::editHandleUrl),
        static_cast<FieldGetMethodSig >(&Inline::getHandleUrl));

    oType.addInitialDesc(pDesc);

    pDesc = new SFBool::Description(
        SFBool::getClassType(),
        "loaded",
        "",
        LoadedFieldId, LoadedFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Inline::editHandleLoaded),
        static_cast<FieldGetMethodSig >(&Inline::getHandleLoaded));

    oType.addInitialDesc(pDesc);

    pDesc = new SFUnrecNodePtr::Description(
        SFUnrecNodePtr::getClassType(),
        "root",
        "",
        RootFieldId, RootFieldMask,
        true,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Inline::editHandleRoot),
        static_cast<FieldGetMethodSig >(&Inline::getHandleRoot));

    oType.addInitialDesc(pDesc);

    pDesc = new SFString::Description(
        SFString::getClassType(),
        "graphOp",
        "",
        GraphOpFieldId, GraphOpFieldMask,
        false,
        (Field::SFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Inline::editHandleGraphOp),
        static_cast<FieldGetMethodSig >(&Inline::getHandleGraphOp));

    oType.addInitialDesc(pDesc);

    pDesc = new MFString::Description(
        MFString::getClassType(),
        "options",
        "",
        OptionsFieldId, OptionsFieldMask,
        false,
        (Field::MFDefaultFlags | Field::FStdAccess),
        static_cast<FieldEditMethodSig>(&Inline::editHandleOptions),
        static_cast<FieldGetMethodSig >(&Inline::getHandleOptions));

    oType.addInitialDesc(pDesc);
}


InlineBase::TypeObject InlineBase::_type(
    InlineBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&InlineBase::createEmptyLocal),
    reinterpret_cast<InitContainerF>(&Inline::initMethod),
    reinterpret_cast<ExitContainerF>(&Inline::exitMethod),
    reinterpret_cast<InitalInsertDescFunc>(&Inline::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "   name=\"Inline\"\n"
    "   parent=\"RootGroup\"\n"
    "   library=\"Group\"\n"
    "   pointerfieldtypes=\"both\"\n"
    "   structure=\"concrete\"\n"
    "   systemcomponent=\"true\"\n"
    "   parentsystemcomponent=\"true\"\n"
    "   isNodeCore=\"true\"\n"
    "   docGroupBase=\"GrpGroupMisc\"\n"
    "   >\n"
    "  <Field\n"
    "\t name=\"url\"\n"
    "\t type=\"std::string\"\n"
    "\t cardinality=\"multi\"\n"
    "\t visibility=\"external\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"loaded\"\n"
    "\t type=\"bool\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"internal\"\n"
    "\t access=\"public\"\n"
    "\t defaultValue=\"true\"\n"
    "\t >\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"root\"\n"
    "\t type=\"NodePtr\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"internal\"\n"
    "\t defaultValue=\"NULL\"\n"
    "\t access=\"protected\"\n"
    "\t >\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"graphOp\"\n"
    "\t type=\"std::string\"\n"
    "\t cardinality=\"single\"\n"
    "\t visibility=\"external\"\n"
    "\t defaultValue='\"default\"'\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "  <Field\n"
    "\t name=\"options\"\n"
    "\t type=\"std::string\"\n"
    "\t cardinality=\"multi\"\n"
    "\t visibility=\"external\"\n"
    "\t access=\"public\"\n"
    "\t >\n"
    "  </Field>\n"
    "</FieldContainer>\n",
    ""
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &InlineBase::getType(void)
{
    return _type;
}

const FieldContainerType &InlineBase::getType(void) const
{
    return _type;
}

UInt32 InlineBase::getContainerSize(void) const
{
    return sizeof(Inline);
}

/*------------------------- decorator get ------------------------------*/


MFString *InlineBase::editMFUrl(void)
{
    editMField(UrlFieldMask, _mfUrl);

    return &_mfUrl;
}

const MFString *InlineBase::getMFUrl(void) const
{
    return &_mfUrl;
}


SFBool *InlineBase::editSFLoaded(void)
{
    editSField(LoadedFieldMask);

    return &_sfLoaded;
}

const SFBool *InlineBase::getSFLoaded(void) const
{
    return &_sfLoaded;
}


//! Get the Inline::_sfRoot field.
const SFUnrecNodePtr *InlineBase::getSFRoot(void) const
{
    return &_sfRoot;
}

SFUnrecNodePtr      *InlineBase::editSFRoot           (void)
{
    editSField(RootFieldMask);

    return &_sfRoot;
}

//! Get the value of the Inline::_sfRoot field.
Node * InlineBase::getRoot(void) const
{
    return _sfRoot.getValue();
}

//! Set the value of the Inline::_sfRoot field.
void InlineBase::setRoot(Node * const value)
{
    editSField(RootFieldMask);

    _sfRoot.setValue(value);
}


SFString *InlineBase::editSFGraphOp(void)
{
    editSField(GraphOpFieldMask);

    return &_sfGraphOp;
}

const SFString *InlineBase::getSFGraphOp(void) const
{
    return &_sfGraphOp;
}


MFString *InlineBase::editMFOptions(void)
{
    editMField(OptionsFieldMask, _mfOptions);

    return &_mfOptions;
}

const MFString *InlineBase::getMFOptions(void) const
{
    return &_mfOptions;
}






/*------------------------------ access -----------------------------------*/

SizeT InlineBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
    {
        returnValue += _mfUrl.getBinSize();
    }
    if(FieldBits::NoField != (LoadedFieldMask & whichField))
    {
        returnValue += _sfLoaded.getBinSize();
    }
    if(FieldBits::NoField != (RootFieldMask & whichField))
    {
        returnValue += _sfRoot.getBinSize();
    }
    if(FieldBits::NoField != (GraphOpFieldMask & whichField))
    {
        returnValue += _sfGraphOp.getBinSize();
    }
    if(FieldBits::NoField != (OptionsFieldMask & whichField))
    {
        returnValue += _mfOptions.getBinSize();
    }

    return returnValue;
}

void InlineBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
    {
        _mfUrl.copyToBin(pMem);
    }
    if(FieldBits::NoField != (LoadedFieldMask & whichField))
    {
        _sfLoaded.copyToBin(pMem);
    }
    if(FieldBits::NoField != (RootFieldMask & whichField))
    {
        _sfRoot.copyToBin(pMem);
    }
    if(FieldBits::NoField != (GraphOpFieldMask & whichField))
    {
        _sfGraphOp.copyToBin(pMem);
    }
    if(FieldBits::NoField != (OptionsFieldMask & whichField))
    {
        _mfOptions.copyToBin(pMem);
    }
}

void InlineBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (UrlFieldMask & whichField))
    {
        editMField(UrlFieldMask, _mfUrl);
        _mfUrl.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (LoadedFieldMask & whichField))
    {
        editSField(LoadedFieldMask);
        _sfLoaded.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (RootFieldMask & whichField))
    {
        editSField(RootFieldMask);
        _sfRoot.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (GraphOpFieldMask & whichField))
    {
        editSField(GraphOpFieldMask);
        _sfGraphOp.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (OptionsFieldMask & whichField))
    {
        editMField(OptionsFieldMask, _mfOptions);
        _mfOptions.copyFromBin(pMem);
    }
}

//! create a new instance of the class
InlineTransitPtr InlineBase::createLocal(BitVector bFlags)
{
    InlineTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<Inline>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
InlineTransitPtr InlineBase::createDependent(BitVector bFlags)
{
    InlineTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<Inline>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
InlineTransitPtr InlineBase::create(void)
{
    InlineTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<Inline>(tmpPtr);
    }

    return fc;
}

Inline *InlineBase::createEmptyLocal(BitVector bFlags)
{
    Inline *returnValue;

    newPtr<Inline>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
Inline *InlineBase::createEmpty(void)
{
    Inline *returnValue;

    newPtr<Inline>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr InlineBase::shallowCopyLocal(
    BitVector bFlags) const
{
    Inline *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Inline *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr InlineBase::shallowCopyDependent(
    BitVector bFlags) const
{
    Inline *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const Inline *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr InlineBase::shallowCopy(void) const
{
    Inline *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const Inline *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

InlineBase::InlineBase(void) :
    Inherited(),
    _mfUrl                    (),
    _sfLoaded                 (bool(true)),
    _sfRoot                   (NULL),
    _sfGraphOp                (std::string("default")),
    _mfOptions                ()
{
}

InlineBase::InlineBase(const InlineBase &source) :
    Inherited(source),
    _mfUrl                    (source._mfUrl                    ),
    _sfLoaded                 (source._sfLoaded                 ),
    _sfRoot                   (NULL),
    _sfGraphOp                (source._sfGraphOp                ),
    _mfOptions                (source._mfOptions                )
{
}


/*-------------------------- destructors ----------------------------------*/

InlineBase::~InlineBase(void)
{
}

void InlineBase::onCreate(const Inline *source)
{
    Inherited::onCreate(source);

    if(source != NULL)
    {
        Inline *pThis = static_cast<Inline *>(this);

        pThis->setRoot(source->getRoot());
    }
}

GetFieldHandlePtr InlineBase::getHandleUrl             (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfUrl,
             this->getType().getFieldDesc(UrlFieldId),
             const_cast<InlineBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InlineBase::editHandleUrl            (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfUrl,
             this->getType().getFieldDesc(UrlFieldId),
             this));


    editMField(UrlFieldMask, _mfUrl);

    return returnValue;
}

GetFieldHandlePtr InlineBase::getHandleLoaded          (void) const
{
    SFBool::GetHandlePtr returnValue(
        new  SFBool::GetHandle(
             &_sfLoaded,
             this->getType().getFieldDesc(LoadedFieldId),
             const_cast<InlineBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InlineBase::editHandleLoaded         (void)
{
    SFBool::EditHandlePtr returnValue(
        new  SFBool::EditHandle(
             &_sfLoaded,
             this->getType().getFieldDesc(LoadedFieldId),
             this));


    editSField(LoadedFieldMask);

    return returnValue;
}

GetFieldHandlePtr InlineBase::getHandleRoot            (void) const
{
    SFUnrecNodePtr::GetHandlePtr returnValue(
        new  SFUnrecNodePtr::GetHandle(
             &_sfRoot,
             this->getType().getFieldDesc(RootFieldId),
             const_cast<InlineBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InlineBase::editHandleRoot           (void)
{
    SFUnrecNodePtr::EditHandlePtr returnValue(
        new  SFUnrecNodePtr::EditHandle(
             &_sfRoot,
             this->getType().getFieldDesc(RootFieldId),
             this));

    returnValue->setSetMethod(
        boost::bind(&Inline::setRoot,
                    static_cast<Inline *>(this), _1));

    editSField(RootFieldMask);

    return returnValue;
}

GetFieldHandlePtr InlineBase::getHandleGraphOp         (void) const
{
    SFString::GetHandlePtr returnValue(
        new  SFString::GetHandle(
             &_sfGraphOp,
             this->getType().getFieldDesc(GraphOpFieldId),
             const_cast<InlineBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InlineBase::editHandleGraphOp        (void)
{
    SFString::EditHandlePtr returnValue(
        new  SFString::EditHandle(
             &_sfGraphOp,
             this->getType().getFieldDesc(GraphOpFieldId),
             this));


    editSField(GraphOpFieldMask);

    return returnValue;
}

GetFieldHandlePtr InlineBase::getHandleOptions         (void) const
{
    MFString::GetHandlePtr returnValue(
        new  MFString::GetHandle(
             &_mfOptions,
             this->getType().getFieldDesc(OptionsFieldId),
             const_cast<InlineBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr InlineBase::editHandleOptions        (void)
{
    MFString::EditHandlePtr returnValue(
        new  MFString::EditHandle(
             &_mfOptions,
             this->getType().getFieldDesc(OptionsFieldId),
             this));


    editMField(OptionsFieldMask, _mfOptions);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void InlineBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inline *pThis = static_cast<Inline *>(this);

    pThis->execSync(static_cast<Inline *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *InlineBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    Inline *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const Inline *>(pRefAspect),
                  dynamic_cast<const Inline *>(this));

    return returnValue;
}
#endif

void InlineBase::resolveLinks(void)
{
    Inherited::resolveLinks();

    static_cast<Inline *>(this)->setRoot(NULL);

#ifdef OSG_MT_CPTR_ASPECT
    AspectOffsetStore oOffsets;

    _pAspectStore->fillOffsetArray(oOffsets, this);
#endif

#ifdef OSG_MT_CPTR_ASPECT
    _mfUrl.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
#ifdef OSG_MT_CPTR_ASPECT
    _mfOptions.terminateShare(Thread::getCurrentAspect(),
                                      oOffsets);
#endif
}


OSG_END_NAMESPACE
