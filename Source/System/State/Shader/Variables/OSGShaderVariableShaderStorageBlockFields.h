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
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSHADERVARIABLESHADERSTORAGEBLOCKFIELDS_H_
#define _OSGSHADERVARIABLESHADERSTORAGEBLOCKFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE


class ShaderVariableShaderStorageBlock;

OSG_GEN_CONTAINERPTR(ShaderVariableShaderStorageBlock);
/*! \ingroup GrpSystemShaderFieldTraits
    \ingroup GrpLibOSGSystem
 */
template <>
struct FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG> :
    public FieldTraitsFCPtrBase<ShaderVariableShaderStorageBlock *, nsOSG>
{
  private:

    static PointerType             _type;

  public:

    typedef FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

};

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakShaderVariableShaderStorageBlockPtr"; 
}

template<> inline
const Char8 *FieldTraits<ShaderVariableShaderStorageBlock *, nsOSG>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdShaderVariableShaderStorageBlockPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpSystemShaderFieldSFields */
typedef PointerSField<ShaderVariableShaderStorageBlock *,
                      RecordedRefCountPolicy, nsOSG  > SFRecShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldSFields */
typedef PointerSField<ShaderVariableShaderStorageBlock *,
                      UnrecordedRefCountPolicy, nsOSG> SFUnrecShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldSFields */
typedef PointerSField<ShaderVariableShaderStorageBlock *,
                      WeakRefCountPolicy, nsOSG      > SFWeakShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldSFields */
typedef PointerSField<ShaderVariableShaderStorageBlock *,
                      NoRefCountPolicy, nsOSG        > SFUncountedShaderVariableShaderStorageBlockPtr;


/*! \ingroup GrpSystemShaderFieldMFields */
typedef PointerMField<ShaderVariableShaderStorageBlock *,
                      RecordedRefCountPolicy, nsOSG  > MFRecShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldMFields */
typedef PointerMField<ShaderVariableShaderStorageBlock *,
                      UnrecordedRefCountPolicy, nsOSG> MFUnrecShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldMFields */
typedef PointerMField<ShaderVariableShaderStorageBlock *,
                      WeakRefCountPolicy, nsOSG      > MFWeakShaderVariableShaderStorageBlockPtr;
/*! \ingroup GrpSystemShaderFieldMFields */
typedef PointerMField<ShaderVariableShaderStorageBlock *,
                      NoRefCountPolicy, nsOSG        > MFUncountedShaderVariableShaderStorageBlockPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpSystemShaderFieldSFields \ingroup GrpLibOSGSystem */
struct SFRecShaderVariableShaderStorageBlockPtr : 
    public PointerSField<ShaderVariableShaderStorageBlock *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpSystemShaderFieldSFields \ingroup GrpLibOSGSystem */
struct SFUnrecShaderVariableShaderStorageBlockPtr : 
    public PointerSField<ShaderVariableShaderStorageBlock *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemShaderFieldSFields \ingroup GrpLibOSGSystem */
struct SFWeakShaderVariableShaderStorageBlockPtr :
    public PointerSField<ShaderVariableShaderStorageBlock *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpSystemShaderFieldSFields \ingroup GrpLibOSGSystem */
struct SFUncountedShaderVariableShaderStorageBlockPtr :
    public PointerSField<ShaderVariableShaderStorageBlock *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpSystemShaderFieldMFields \ingroup GrpLibOSGSystem */
struct MFRecShaderVariableShaderStorageBlockPtr :
    public PointerMField<ShaderVariableShaderStorageBlock *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpSystemShaderFieldMFields \ingroup GrpLibOSGSystem */
struct MFUnrecShaderVariableShaderStorageBlockPtr :
    public PointerMField<ShaderVariableShaderStorageBlock *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemShaderFieldMFields \ingroup GrpLibOSGSystem */
struct MFWeakShaderVariableShaderStorageBlockPtr :
    public PointerMField<ShaderVariableShaderStorageBlock *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpSystemShaderFieldMFields \ingroup GrpLibOSGSystem */
struct MFUncountedShaderVariableShaderStorageBlockPtr :
    public PointerMField<ShaderVariableShaderStorageBlock *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGSHADERVARIABLESHADERSTORAGEBLOCKFIELDS_H_ */