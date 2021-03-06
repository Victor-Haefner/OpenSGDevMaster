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


#ifndef _OSGINVERSETRANSFORMFIELDS_H_
#define _OSGINVERSETRANSFORMFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGGroupDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE


class InverseTransform;

OSG_GEN_CONTAINERPTR(InverseTransform);
/*! \ingroup GrpGroupMiscFieldTraits
    \ingroup GrpLibOSGGroup
 */
template <>
struct FieldTraits<InverseTransform *, nsOSG> :
    public FieldTraitsFCPtrBase<InverseTransform *, nsOSG>
{
  private:

    static PointerType             _type;

  public:

    typedef FieldTraits<InverseTransform *, nsOSG>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_GROUP_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

};

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakInverseTransformPtr"; 
}

template<> inline
const Char8 *FieldTraits<InverseTransform *, nsOSG>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdInverseTransformPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpGroupMiscFieldSFields */
typedef PointerSField<InverseTransform *,
                      RecordedRefCountPolicy, nsOSG  > SFRecInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldSFields */
typedef PointerSField<InverseTransform *,
                      UnrecordedRefCountPolicy, nsOSG> SFUnrecInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldSFields */
typedef PointerSField<InverseTransform *,
                      WeakRefCountPolicy, nsOSG      > SFWeakInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldSFields */
typedef PointerSField<InverseTransform *,
                      NoRefCountPolicy, nsOSG        > SFUncountedInverseTransformPtr;


/*! \ingroup GrpGroupMiscFieldMFields */
typedef PointerMField<InverseTransform *,
                      RecordedRefCountPolicy, nsOSG  > MFRecInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldMFields */
typedef PointerMField<InverseTransform *,
                      UnrecordedRefCountPolicy, nsOSG> MFUnrecInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldMFields */
typedef PointerMField<InverseTransform *,
                      WeakRefCountPolicy, nsOSG      > MFWeakInverseTransformPtr;
/*! \ingroup GrpGroupMiscFieldMFields */
typedef PointerMField<InverseTransform *,
                      NoRefCountPolicy, nsOSG        > MFUncountedInverseTransformPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpGroupMiscFieldSFields \ingroup GrpLibOSGGroup */
struct SFRecInverseTransformPtr : 
    public PointerSField<InverseTransform *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpGroupMiscFieldSFields \ingroup GrpLibOSGGroup */
struct SFUnrecInverseTransformPtr : 
    public PointerSField<InverseTransform *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpGroupMiscFieldSFields \ingroup GrpLibOSGGroup */
struct SFWeakInverseTransformPtr :
    public PointerSField<InverseTransform *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpGroupMiscFieldSFields \ingroup GrpLibOSGGroup */
struct SFUncountedInverseTransformPtr :
    public PointerSField<InverseTransform *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpGroupMiscFieldMFields \ingroup GrpLibOSGGroup */
struct MFRecInverseTransformPtr :
    public PointerMField<InverseTransform *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpGroupMiscFieldMFields \ingroup GrpLibOSGGroup */
struct MFUnrecInverseTransformPtr :
    public PointerMField<InverseTransform *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpGroupMiscFieldMFields \ingroup GrpLibOSGGroup */
struct MFWeakInverseTransformPtr :
    public PointerMField<InverseTransform *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpGroupMiscFieldMFields \ingroup GrpLibOSGGroup */
struct MFUncountedInverseTransformPtr :
    public PointerMField<InverseTransform *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGINVERSETRANSFORMFIELDS_H_ */
