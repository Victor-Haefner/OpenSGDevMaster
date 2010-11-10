/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2006 by the OpenSG Forum                 *
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
 **     class AnimQuaternionBlender!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE


//! access the type of the class
inline
OSG::FieldContainerType &AnimQuaternionBlenderBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 AnimQuaternionBlenderBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 AnimQuaternionBlenderBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the AnimQuaternionBlender::_sfOutValue field.

inline
Quaternion &AnimQuaternionBlenderBase::editOutValue(void)
{
    editSField(OutValueFieldMask);

    return _sfOutValue.getValue();
}

//! Get the value of the AnimQuaternionBlender::_sfOutValue field.
inline
const Quaternion &AnimQuaternionBlenderBase::getOutValue(void) const
{
    return _sfOutValue.getValue();
}

//! Set the value of the AnimQuaternionBlender::_sfOutValue field.
inline
void AnimQuaternionBlenderBase::setOutValue(const Quaternion &value)
{
    editSField(OutValueFieldMask);

    _sfOutValue.setValue(value);
}

//! Get the value of the \a index element the AnimQuaternionBlender::_mfChannels field.
inline
AnimQuaternionChannel * AnimQuaternionBlenderBase::getChannels(const UInt32 index) const
{
    return _mfChannels[index];
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void AnimQuaternionBlenderBase::execSync (      AnimQuaternionBlenderBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (ChannelsFieldMask & whichField))
        _mfChannels.syncWith(pFrom->_mfChannels,
                                syncMode,
                                uiSyncInfo,
                                oOffsets);

    if(FieldBits::NoField != (OutValueFieldMask & whichField))
        _sfOutValue.syncWith(pFrom->_sfOutValue);
}
#endif


inline
const Char8 *AnimQuaternionBlenderBase::getClassname(void)
{
    return "AnimQuaternionBlender";
}
OSG_GEN_CONTAINERPTR(AnimQuaternionBlender);

OSG_END_NAMESPACE
