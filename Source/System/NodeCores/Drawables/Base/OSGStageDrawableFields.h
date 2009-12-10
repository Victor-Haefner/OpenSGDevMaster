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
 *****************************************************************************
\*****************************************************************************/


#ifndef _OSGSTAGEDRAWABLEFIELDS_H_
#define _OSGSTAGEDRAWABLEFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE

class StageDrawable;

OSG_GEN_CONTAINERPTR(StageDrawable);

/*! \ingroup GrpSystemFieldTraits
    \ingroup GrpLibOSGSystem
 */
template <>
struct FieldTraits<StageDrawable *> :
    public FieldTraitsFCPtrBase<StageDrawable *>
{
  private:

    static DataType             _type;

  public:

    typedef FieldTraits<StageDrawable *>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

//    static const char *getSName(void) { return "SFStageDrawablePtr"; }
    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

//    static const char *getMName(void) { return "MFStageDrawablePtr"; }
};

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakStageDrawablePtr"; 
}

template<> inline
const Char8 *FieldTraits<StageDrawable *, 0>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdStageDrawablePtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<StageDrawable *,
                      RecordedRefCountPolicy  > SFRecStageDrawablePtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<StageDrawable *,
                      UnrecordedRefCountPolicy> SFUnrecStageDrawablePtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<StageDrawable *,
                      WeakRefCountPolicy      > SFWeakStageDrawablePtr;
/*! \ingroup GrpSystemFieldSFields */
typedef PointerSField<StageDrawable *,
                      NoRefCountPolicy        > SFUncountedStageDrawablePtr;


/*! \ingroup GrpSystemFieldMFields */
typedef PointerMField<StageDrawable *,
                      RecordedRefCountPolicy  > MFRecStageDrawablePtr;
/*! \ingroup GrpSystemFieldMFields */
typedef PointerMField<StageDrawable *,
                      UnrecordedRefCountPolicy> MFUnrecStageDrawablePtr;
/*! \ingroup GrpSystemFieldMFields */
typedef PointerMField<StageDrawable *,
                      WeakRefCountPolicy      > MFWeakStageDrawablePtr;
/*! \ingroup GrpSystemFieldMFields */
typedef PointerMField<StageDrawable *,
                      NoRefCountPolicy        > MFUncountedStageDrawablePtr;




#else // these are the doxygen hacks

/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFRecStageDrawablePtr : 
    public PointerSField<StageDrawable *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFUnrecStageDrawablePtr : 
    public PointerSField<StageDrawable *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFWeakStageDrawablePtr :
    public PointerSField<StageDrawable *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpSystemFieldSFields \ingroup GrpLibOSGSystem */
struct SFUncountedStageDrawablePtr :
    public PointerSField<StageDrawable *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpSystemFieldMFields \ingroup GrpLibOSGSystem */
struct MFRecStageDrawablePtr :
    public PointerMField<StageDrawable *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpSystemFieldMFields \ingroup GrpLibOSGSystem */
struct MFUnrecStageDrawablePtr :
    public PointerMField<StageDrawable *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemFieldMFields \ingroup GrpLibOSGSystem */
struct MFWeakStageDrawablePtr :
    public PointerMField<StageDrawable *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpSystemFieldMFields \ingroup GrpLibOSGSystem */
struct MFUncountedStageDrawablePtr :
    public PointerMField<StageDrawable *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGSTAGEDRAWABLEFIELDS_H_ */