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


#ifndef _OSGSKELETONFIELDS_H_
#define _OSGSKELETONFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGDynamicsDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE


class Skeleton;

OSG_GEN_CONTAINERPTR(Skeleton);
/*! \ingroup GrpDynamicsFieldTraits
    \ingroup GrpLibOSGDynamics
 */
template <>
struct FieldTraits<Skeleton *, nsOSG> :
    public FieldTraitsFCPtrBase<Skeleton *, nsOSG>
{
  private:

    static PointerType             _type;

  public:

    typedef FieldTraits<Skeleton *, nsOSG>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_DYNAMICS_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

};

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdSkeletonPtr"; 
}


/*! \ingroup GrpDynamicsFieldTraits
 */
template <>
struct FieldTraits<Skeleton *, nsOSG + 1> :
    public FieldTraitsFCPtrBase<Skeleton *, nsOSG + 1>
{
  private:

  public:
    typedef FieldTraits<Skeleton *, nsOSG + 1>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_DYNAMICS_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);
};

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakChildSkeletonPtr"; 
}

template<> inline
const Char8 *FieldTraits<Skeleton *, nsOSG + 1>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdChildSkeletonPtr"; 
}


/*! \ingroup GrpDynamicsFieldTraits
 */
template <>
struct FieldTraits<Skeleton *, nsOSG + 2> : 
    public FieldTraitsFCPtrBase<Skeleton *, nsOSG + 2>
{
  private:

    static  DataType                                _type;

  public:

    static const bool bIsPointerField = true;

    typedef FieldTraits<Skeleton *, nsOSG + 2> Self;


    enum             { Convertible = Self::NotConvertible };
    
    static OSG_DYNAMICS_DLLMAPPING
                 DataType &getType (void);

    static const Char8    *getSName(void) 
    {
        return "SFParentSkeletonPtr"; 
    }

    static const Char8    *getMName(void) 
    { 
        return "MFParentSkeletonPtr"; 
    }
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpDynamicsFieldSFields */
typedef PointerSField<Skeleton *,
                      RecordedRefCountPolicy, nsOSG  > SFRecSkeletonPtr;
/*! \ingroup GrpDynamicsFieldSFields */
typedef PointerSField<Skeleton *,
                      UnrecordedRefCountPolicy, nsOSG> SFUnrecSkeletonPtr;
/*! \ingroup GrpDynamicsFieldSFields */
typedef PointerSField<Skeleton *,
                      WeakRefCountPolicy, nsOSG      > SFWeakSkeletonPtr;
/*! \ingroup GrpDynamicsFieldSFields */
typedef PointerSField<Skeleton *,
                      NoRefCountPolicy, nsOSG        > SFUncountedSkeletonPtr;


/*! \ingroup GrpDynamicsFieldMFields */
typedef PointerMField<Skeleton *,
                      RecordedRefCountPolicy, nsOSG  > MFRecSkeletonPtr;
/*! \ingroup GrpDynamicsFieldMFields */
typedef PointerMField<Skeleton *,
                      UnrecordedRefCountPolicy, nsOSG> MFUnrecSkeletonPtr;
/*! \ingroup GrpDynamicsFieldMFields */
typedef PointerMField<Skeleton *,
                      WeakRefCountPolicy, nsOSG      > MFWeakSkeletonPtr;
/*! \ingroup GrpDynamicsFieldMFields */
typedef PointerMField<Skeleton *,
                      NoRefCountPolicy, nsOSG        > MFUncountedSkeletonPtr;



/*! \ingroup GrpDynamicsFieldSFields */
typedef ChildPointerSField<
          Skeleton *, 
          UnrecordedRefCountPolicy,
          nsOSG + 1             > SFUnrecChildSkeletonPtr;


/*! \ingroup GrpDynamicsFieldMFields */
typedef ChildPointerMField<
          Skeleton *, 
          UnrecordedRefCountPolicy,
          nsOSG + 1             > MFUnrecChildSkeletonPtr;


/*! \ingroup GrpDynamicsFieldSFields */
typedef ParentPointerSField<
          Skeleton *, 
          NoRefCountPolicy,
          nsOSG + 2    > SFParentSkeletonPtr;

/*! \ingroup GrpDynamicsFieldMFields */
typedef ParentPointerMField<
          Skeleton *, 
          NoRefCountPolicy,
          nsOSG + 2    > MFParentSkeletonPtr;



#else // these are the doxygen hacks

/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFRecSkeletonPtr : 
    public PointerSField<Skeleton *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFUnrecSkeletonPtr : 
    public PointerSField<Skeleton *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFWeakSkeletonPtr :
    public PointerSField<Skeleton *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFUncountedSkeletonPtr :
    public PointerSField<Skeleton *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFRecSkeletonPtr :
    public PointerMField<Skeleton *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFUnrecSkeletonPtr :
    public PointerMField<Skeleton *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFWeakSkeletonPtr :
    public PointerMField<Skeleton *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFUncountedSkeletonPtr :
    public PointerMField<Skeleton *,
                         NoRefCountPolicy        > {};



/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFUnrecChildSkeletonPtr :
    public ChildPointerSField<
        Skeleton *, 
        UnrecordedRefCountPolicy,
        nsOSG + 1             > {};


/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFUnrecChildSkeletonPtr :
    public ChildPointerMField<
        Skeleton *, 
        UnrecordedRefCountPolicy,
        nsOSG + 1             > {};


/*! \ingroup GrpDynamicsFieldSFields \ingroup GrpLibOSGDynamics */
struct SFParentSkeletonPtr :
    public ParentPointerSField<
        Skeleton *, 
        NoRefCountPolicy,
        nsOSG + 2    > {};

/*! \ingroup GrpDynamicsFieldMFields \ingroup GrpLibOSGDynamics */
struct MFParentSkeletonPtr :
    public  ParentPointerMField<
        Skeleton *, 
        NoRefCountPolicy,
        nsOSG + 2    > {};


#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGSKELETONFIELDS_H_ */
