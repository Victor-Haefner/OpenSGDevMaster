/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *               Copyright (C) 2000-2013 by the OpenSG Forum                 *
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
 **     class AnimChannel!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &AnimChannelBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 AnimChannelBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 AnimChannelBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the AnimChannel::_sfWeight field.

inline
Real32 &AnimChannelBase::editWeight(void)
{
    editSField(WeightFieldMask);

    return _sfWeight.getValue();
}

//! Get the value of the AnimChannel::_sfWeight field.
inline
      Real32  AnimChannelBase::getWeight(void) const
{
    return _sfWeight.getValue();
}

//! Set the value of the AnimChannel::_sfWeight field.
inline
void AnimChannelBase::setWeight(const Real32 value)
{
    editSField(WeightFieldMask);

    _sfWeight.setValue(value);
}
//! Get the value of the AnimChannel::_sfInValue field.

inline
Real32 &AnimChannelBase::editInValue(void)
{
    editSField(InValueFieldMask);

    return _sfInValue.getValue();
}

//! Get the value of the AnimChannel::_sfInValue field.
inline
      Real32  AnimChannelBase::getInValue(void) const
{
    return _sfInValue.getValue();
}

//! Set the value of the AnimChannel::_sfInValue field.
inline
void AnimChannelBase::setInValue(const Real32 value)
{
    editSField(InValueFieldMask);

    _sfInValue.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void AnimChannelBase::execSync (      AnimChannelBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (AnimationFieldMask & whichField))
        _sfAnimation.syncWith(pFrom->_sfAnimation);

    if(FieldBits::NoField != (WeightFieldMask & whichField))
        _sfWeight.syncWith(pFrom->_sfWeight);

    if(FieldBits::NoField != (InValueFieldMask & whichField))
        _sfInValue.syncWith(pFrom->_sfInValue);
}
#endif


inline
const Char8 *AnimChannelBase::getClassname(void)
{
    return "AnimChannel";
}
OSG_GEN_CONTAINERPTR(AnimChannel);

OSG_END_NAMESPACE

