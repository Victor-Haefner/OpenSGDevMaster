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
 **     class ShaderVariableOSG!
 **                                                                         **
 *****************************************************************************
\*****************************************************************************/

OSG_BEGIN_NAMESPACE



//! access the type of the class
inline
OSG::FieldContainerType &ShaderVariableOSGBase::getClassType(void)
{
    return _type;
}

//! access the numerical type of the class
inline
OSG::UInt32 ShaderVariableOSGBase::getClassTypeId(void)
{
    return _type.getId();
}

inline
OSG::UInt16 ShaderVariableOSGBase::getClassGroupId(void)
{
    return _type.getGroupId();
}

/*------------------------------ get -----------------------------------*/

//! Get the value of the ShaderVariableOSG::_sfOsgVarType field.

inline
UInt32 &ShaderVariableOSGBase::editOsgVarType(void)
{
    editSField(OsgVarTypeFieldMask);

    return _sfOsgVarType.getValue();
}

//! Get the value of the ShaderVariableOSG::_sfOsgVarType field.
inline
      UInt32  ShaderVariableOSGBase::getOsgVarType(void) const
{
    return _sfOsgVarType.getValue();
}

//! Set the value of the ShaderVariableOSG::_sfOsgVarType field.
inline
void ShaderVariableOSGBase::setOsgVarType(const UInt32 value)
{
    editSField(OsgVarTypeFieldMask);

    _sfOsgVarType.setValue(value);
}


#ifdef OSG_MT_CPTR_ASPECT
inline
void ShaderVariableOSGBase::execSync (      ShaderVariableOSGBase *pFrom,
                                        ConstFieldMaskArg  whichField,
                                        AspectOffsetStore &oOffsets,
                                        ConstFieldMaskArg  syncMode,
                                  const UInt32             uiSyncInfo)
{
    Inherited::execSync(pFrom, whichField, oOffsets, syncMode, uiSyncInfo);

    if(FieldBits::NoField != (OsgVarTypeFieldMask & whichField))
        _sfOsgVarType.syncWith(pFrom->_sfOsgVarType);
}
#endif


inline
const Char8 *ShaderVariableOSGBase::getClassname(void)
{
    return "ShaderVariableOSG";
}
OSG_GEN_CONTAINERPTR(ShaderVariableOSG);

OSG_END_NAMESPACE

