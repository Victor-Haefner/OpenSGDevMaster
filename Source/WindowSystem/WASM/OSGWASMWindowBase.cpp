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
 **     class WASMWindow!
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




#include "OSGWASMWindowBase.h"
#include "OSGWASMWindow.h"

#include <boost/bind.hpp>

OSG_BEGIN_NAMESPACE

/***************************************************************************\
 *                            Description                                  *
\***************************************************************************/

/*! \class OSG::WASMWindow
    The class for X-based windows. See \ref PageWindowWASM for a description.
 */

/***************************************************************************\
 *                        Field Documentation                              *
\***************************************************************************/

/*! \var DisplayP        WASMWindowBase::_sfDisplay
    
*/

/*! \var X11Window       WASMWindowBase::_sfWindow
    
*/

/*! \var GLXContext      WASMWindowBase::_sfContext
    
*/

/*! \var Int32           WASMWindowBase::_sfFbConfigId
    
*/


/***************************************************************************\
 *                      FieldType/FieldTrait Instantiation                 *
\***************************************************************************/

#if !defined(OSG_DO_DOC) || defined(OSG_DOC_DEV)
PointerType FieldTraits<WASMWindow *, nsOSG>::_type(
    "WASMWindowPtr", 
    "WindowPtr", 
    WASMWindow::getClassType(),
    nsOSG);
#endif

OSG_FIELDTRAITS_GETTYPE_NS(WASMWindow *, nsOSG)

OSG_EXPORT_PTR_SFIELD_FULL(PointerSField,
                           WASMWindow *,
                           nsOSG)

OSG_EXPORT_PTR_MFIELD_FULL(PointerMField,
                           WASMWindow *,
                           nsOSG)

/***************************************************************************\
 *                         Field Description                               *
\***************************************************************************/

void WASMWindowBase::classDescInserter(TypeObject &oType)
{
    FieldDescriptionBase *pDesc = NULL;


    pDesc = new SFDisplayP::Description(
        SFDisplayP::getClassType(),
        "display",
        "",
        DisplayFieldId, DisplayFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&WASMWindow::editHandleDisplay),
        static_cast<FieldGetMethodSig >(&WASMWindow::getHandleDisplay));

    oType.addInitialDesc(pDesc);

    pDesc = new SFX11Window::Description(
        SFX11Window::getClassType(),
        "window",
        "",
        WindowFieldId, WindowFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&WASMWindow::editHandleWindow),
        static_cast<FieldGetMethodSig >(&WASMWindow::getHandleWindow));

    oType.addInitialDesc(pDesc);

    pDesc = new SFGLXContext::Description(
        SFGLXContext::getClassType(),
        "context",
        "",
        ContextFieldId, ContextFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&WASMWindow::editHandleContext),
        static_cast<FieldGetMethodSig >(&WASMWindow::getHandleContext));

    oType.addInitialDesc(pDesc);

    pDesc = new SFInt32::Description(
        SFInt32::getClassType(),
        "fbConfigId",
        "",
        FbConfigIdFieldId, FbConfigIdFieldMask,
        true,
        (Field::FClusterLocal),
        static_cast<FieldEditMethodSig>(&WASMWindow::editHandleFbConfigId),
        static_cast<FieldGetMethodSig >(&WASMWindow::getHandleFbConfigId));

    oType.addInitialDesc(pDesc);
}


WASMWindowBase::TypeObject WASMWindowBase::_type(
    WASMWindowBase::getClassname(),
    Inherited::getClassname(),
    "NULL",
    nsOSG, //Namespace
    reinterpret_cast<PrototypeCreateF>(&WASMWindowBase::createEmptyLocal),
    reinterpret_cast<InitContainerF>(&WASMWindow::initMethod),
    reinterpret_cast<ExitContainerF>(&WASMWindow::exitMethod),
    reinterpret_cast<InitalInsertDescFunc>(&WASMWindow::classDescInserter),
    false,
    0,
    "<?xml version=\"1.0\"?>\n"
    "\n"
    "<FieldContainer\n"
    "    name=\"WASMWindow\"\n"
    "    parent=\"Window\"\n"
    "    library=\"WindowWASM\"\n"
    "    pointerfieldtypes=\"both\"\n"
    "    structure=\"concrete\"\n"
    "    systemcomponent=\"true\"\n"
    "    parentsystemcomponent=\"true\"\n"
    "    docGroupBase=\"GrpWindowWASM\"\n"
    "    >\n"
    "    The class for X-based windows. See \\ref PageWindowWASM for a description.\n"
    "    <Field\n"
    "        name=\"display\"\n"
    "        type=\"DisplayP\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"internal\"\n"
    "        defaultValue=\"NULL\"\n"
    "        fieldHeader=\"OSGWASMWindowDataFields.h\"\n"
    "        access=\"public\"\n"
    "        fieldFlags=\"FClusterLocal\"\n"
    "        >\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"window\"\n"
    "        type=\"X11Window\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"internal\"\n"
    "        defaultValue=\"NULL\"\n"
    "        fieldHeader=\"OSGWASMWindowDataFields.h\"\n"
    "        access=\"public\"\n"
    "        fieldFlags=\"FClusterLocal\"\n"
    "        >\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"context\"\n"
    "        type=\"GLXContext\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"internal\"\n"
    "        defaultValue=\"NULL\"\n"
    "        fieldHeader=\"OSGWASMWindowDataFields.h\"\n"
    "        access=\"public\"\n"
    "        fieldFlags=\"FClusterLocal\"\n"
    "        >\n"
    "    </Field>\n"
    "    <Field\n"
    "        name=\"fbConfigId\"\n"
    "        type=\"Int32\"\n"
    "        cardinality=\"single\"\n"
    "        visibility=\"internal\"\n"
    "        defaultValue=\"-1\"\n"
    "        access=\"public\"\n"
    "        fieldFlags=\"FClusterLocal\"\n"
    "        >\n"
    "    </Field>\n"
    "</FieldContainer>\n",
    "The class for X-based windows. See \\ref PageWindowWASM for a description.\n"
    );

/*------------------------------ get -----------------------------------*/

FieldContainerType &WASMWindowBase::getType(void)
{
    return _type;
}

const FieldContainerType &WASMWindowBase::getType(void) const
{
    return _type;
}

UInt32 WASMWindowBase::getContainerSize(void) const
{
    return sizeof(WASMWindow);
}

/*------------------------- decorator get ------------------------------*/


SFDisplayP *WASMWindowBase::editSFDisplay(void)
{
    editSField(DisplayFieldMask);

    return &_sfDisplay;
}

const SFDisplayP *WASMWindowBase::getSFDisplay(void) const
{
    return &_sfDisplay;
}


SFX11Window *WASMWindowBase::editSFWindow(void)
{
    editSField(WindowFieldMask);

    return &_sfWindow;
}

const SFX11Window *WASMWindowBase::getSFWindow(void) const
{
    return &_sfWindow;
}


SFGLXContext *WASMWindowBase::editSFContext(void)
{
    editSField(ContextFieldMask);

    return &_sfContext;
}

const SFGLXContext *WASMWindowBase::getSFContext(void) const
{
    return &_sfContext;
}


SFInt32 *WASMWindowBase::editSFFbConfigId(void)
{
    editSField(FbConfigIdFieldMask);

    return &_sfFbConfigId;
}

const SFInt32 *WASMWindowBase::getSFFbConfigId(void) const
{
    return &_sfFbConfigId;
}






/*------------------------------ access -----------------------------------*/

SizeT WASMWindowBase::getBinSize(ConstFieldMaskArg whichField)
{
    SizeT returnValue = Inherited::getBinSize(whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        returnValue += _sfDisplay.getBinSize();
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        returnValue += _sfWindow.getBinSize();
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        returnValue += _sfContext.getBinSize();
    }
    if(FieldBits::NoField != (FbConfigIdFieldMask & whichField))
    {
        returnValue += _sfFbConfigId.getBinSize();
    }

    return returnValue;
}

void WASMWindowBase::copyToBin(BinaryDataHandler &pMem,
                                  ConstFieldMaskArg  whichField)
{
    Inherited::copyToBin(pMem, whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        _sfDisplay.copyToBin(pMem);
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        _sfWindow.copyToBin(pMem);
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        _sfContext.copyToBin(pMem);
    }
    if(FieldBits::NoField != (FbConfigIdFieldMask & whichField))
    {
        _sfFbConfigId.copyToBin(pMem);
    }
}

void WASMWindowBase::copyFromBin(BinaryDataHandler &pMem,
                                    ConstFieldMaskArg  whichField)
{
    Inherited::copyFromBin(pMem, whichField);

    if(FieldBits::NoField != (DisplayFieldMask & whichField))
    {
        editSField(DisplayFieldMask);
        _sfDisplay.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (WindowFieldMask & whichField))
    {
        editSField(WindowFieldMask);
        _sfWindow.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (ContextFieldMask & whichField))
    {
        editSField(ContextFieldMask);
        _sfContext.copyFromBin(pMem);
    }
    if(FieldBits::NoField != (FbConfigIdFieldMask & whichField))
    {
        editSField(FbConfigIdFieldMask);
        _sfFbConfigId.copyFromBin(pMem);
    }
}

//! create a new instance of the class
WASMWindowTransitPtr WASMWindowBase::createLocal(BitVector bFlags)
{
    WASMWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyLocal(bFlags);

        fc = dynamic_pointer_cast<WASMWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class, copy the container flags
WASMWindowTransitPtr WASMWindowBase::createDependent(BitVector bFlags)
{
    WASMWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopyDependent(bFlags);

        fc = dynamic_pointer_cast<WASMWindow>(tmpPtr);
    }

    return fc;
}

//! create a new instance of the class
WASMWindowTransitPtr WASMWindowBase::create(void)
{
    WASMWindowTransitPtr fc;

    if(getClassType().getPrototype() != NULL)
    {
        FieldContainerTransitPtr tmpPtr =
            getClassType().getPrototype()-> shallowCopy();

        fc = dynamic_pointer_cast<WASMWindow>(tmpPtr);
    }

    return fc;
}

WASMWindow *WASMWindowBase::createEmptyLocal(BitVector bFlags)
{
    WASMWindow *returnValue;

    newPtr<WASMWindow>(returnValue, bFlags);

    returnValue->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

//! create an empty new instance of the class, do not copy the prototype
WASMWindow *WASMWindowBase::createEmpty(void)
{
    WASMWindow *returnValue;

    newPtr<WASMWindow>(returnValue, Thread::getCurrentLocalFlags());

    returnValue->_pFieldFlags->_bNamespaceMask &=
        ~Thread::getCurrentLocalFlags();

    return returnValue;
}


FieldContainerTransitPtr WASMWindowBase::shallowCopyLocal(
    BitVector bFlags) const
{
    WASMWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const WASMWindow *>(this), bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~bFlags;

    return returnValue;
}

FieldContainerTransitPtr WASMWindowBase::shallowCopyDependent(
    BitVector bFlags) const
{
    WASMWindow *tmpPtr;

    newPtr(tmpPtr, dynamic_cast<const WASMWindow *>(this), ~bFlags);

    FieldContainerTransitPtr returnValue(tmpPtr);

    tmpPtr->_pFieldFlags->_bNamespaceMask = bFlags;

    return returnValue;
}

FieldContainerTransitPtr WASMWindowBase::shallowCopy(void) const
{
    WASMWindow *tmpPtr;

    newPtr(tmpPtr,
           dynamic_cast<const WASMWindow *>(this),
           Thread::getCurrentLocalFlags());

    tmpPtr->_pFieldFlags->_bNamespaceMask &= ~Thread::getCurrentLocalFlags();

    FieldContainerTransitPtr returnValue(tmpPtr);

    return returnValue;
}




/*------------------------- constructors ----------------------------------*/

WASMWindowBase::WASMWindowBase(void) :
    Inherited(),
    _sfDisplay                (DisplayP(NULL)),
    _sfWindow                 (X11Window(NULL)),
    _sfContext                (GLXContext(NULL)),
    _sfFbConfigId             (Int32(-1))
{
}

WASMWindowBase::WASMWindowBase(const WASMWindowBase &source) :
    Inherited(source),
    _sfDisplay                (source._sfDisplay                ),
    _sfWindow                 (source._sfWindow                 ),
    _sfContext                (source._sfContext                ),
    _sfFbConfigId             (source._sfFbConfigId             )
{
}


/*-------------------------- destructors ----------------------------------*/

WASMWindowBase::~WASMWindowBase(void)
{
}


GetFieldHandlePtr WASMWindowBase::getHandleDisplay         (void) const
{
    SFDisplayP::GetHandlePtr returnValue(
        new  SFDisplayP::GetHandle(
             &_sfDisplay,
             this->getType().getFieldDesc(DisplayFieldId),
             const_cast<WASMWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr WASMWindowBase::editHandleDisplay        (void)
{
    SFDisplayP::EditHandlePtr returnValue(
        new  SFDisplayP::EditHandle(
             &_sfDisplay,
             this->getType().getFieldDesc(DisplayFieldId),
             this));


    editSField(DisplayFieldMask);

    return returnValue;
}

GetFieldHandlePtr WASMWindowBase::getHandleWindow          (void) const
{
    SFX11Window::GetHandlePtr returnValue(
        new  SFX11Window::GetHandle(
             &_sfWindow,
             this->getType().getFieldDesc(WindowFieldId),
             const_cast<WASMWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr WASMWindowBase::editHandleWindow         (void)
{
    SFX11Window::EditHandlePtr returnValue(
        new  SFX11Window::EditHandle(
             &_sfWindow,
             this->getType().getFieldDesc(WindowFieldId),
             this));


    editSField(WindowFieldMask);

    return returnValue;
}

GetFieldHandlePtr WASMWindowBase::getHandleContext         (void) const
{
    SFGLXContext::GetHandlePtr returnValue(
        new  SFGLXContext::GetHandle(
             &_sfContext,
             this->getType().getFieldDesc(ContextFieldId),
             const_cast<WASMWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr WASMWindowBase::editHandleContext        (void)
{
    SFGLXContext::EditHandlePtr returnValue(
        new  SFGLXContext::EditHandle(
             &_sfContext,
             this->getType().getFieldDesc(ContextFieldId),
             this));


    editSField(ContextFieldMask);

    return returnValue;
}

GetFieldHandlePtr WASMWindowBase::getHandleFbConfigId      (void) const
{
    SFInt32::GetHandlePtr returnValue(
        new  SFInt32::GetHandle(
             &_sfFbConfigId,
             this->getType().getFieldDesc(FbConfigIdFieldId),
             const_cast<WASMWindowBase *>(this)));

    return returnValue;
}

EditFieldHandlePtr WASMWindowBase::editHandleFbConfigId     (void)
{
    SFInt32::EditHandlePtr returnValue(
        new  SFInt32::EditHandle(
             &_sfFbConfigId,
             this->getType().getFieldDesc(FbConfigIdFieldId),
             this));


    editSField(FbConfigIdFieldMask);

    return returnValue;
}


#ifdef OSG_MT_CPTR_ASPECT
void WASMWindowBase::execSyncV(      FieldContainer    &oFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    WASMWindow *pThis = static_cast<WASMWindow *>(this);

    pThis->execSync(static_cast<WASMWindow *>(&oFrom),
                    whichField,
                    oOffsets,
                    syncMode,
                    uiSyncInfo);
}
#endif


#ifdef OSG_MT_CPTR_ASPECT
FieldContainer *WASMWindowBase::createAspectCopy(
    const FieldContainer *pRefAspect) const
{
    WASMWindow *returnValue;

    newAspectCopy(returnValue,
                  dynamic_cast<const WASMWindow *>(pRefAspect),
                  dynamic_cast<const WASMWindow *>(this));

    return returnValue;
}
#endif

void WASMWindowBase::resolveLinks(void)
{
    Inherited::resolveLinks();


}


OSG_END_NAMESPACE