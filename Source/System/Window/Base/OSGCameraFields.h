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


#ifndef _OSGCAMERAFIELDS_H_
#define _OSGCAMERAFIELDS_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGConfig.h"
#include "OSGSystemDef.h"

#include "OSGFieldContainerFields.h"
#include "OSGPointerSField.h"
#include "OSGPointerMField.h"


OSG_BEGIN_NAMESPACE


class Camera;

OSG_GEN_CONTAINERPTR(Camera);
/*! \ingroup GrpSystemWindowFieldTraits
    \ingroup GrpLibOSGSystem
 */
template <>
struct FieldTraits<Camera *, nsOSG> :
    public FieldTraitsFCPtrBase<Camera *, nsOSG>
{
  private:

    static PointerType             _type;

  public:

    typedef FieldTraits<Camera *, nsOSG>  Self;

    enum                        { Convertible = NotConvertible };

    static OSG_SYSTEM_DLLMAPPING DataType &getType(void);

    template<typename RefCountPolicy> inline
    static const Char8    *getSName     (void);

    template<typename RefCountPolicy> inline
    static const Char8    *getMName     (void);

};

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getSName<RecordedRefCountPolicy>(void)
{
    return "SFRecCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getSName<UnrecordedRefCountPolicy>(void)
{
    return "SFUnrecCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getSName<WeakRefCountPolicy>(void)
{
    return "SFWeakCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getSName<NoRefCountPolicy>(void)
{
    return "SFUnrefdCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getMName<RecordedRefCountPolicy>(void)
{
    return "MFRecCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getMName<UnrecordedRefCountPolicy>(void)
{
    return "MFUnrecCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getMName<WeakRefCountPolicy>(void)
{
    return "MFWeakCameraPtr"; 
}

template<> inline
const Char8 *FieldTraits<Camera *, nsOSG>::getMName<NoRefCountPolicy>(void)
{
    return "MFUnrefdCameraPtr"; 
}


#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpSystemWindowFieldSFields */
typedef PointerSField<Camera *,
                      RecordedRefCountPolicy, nsOSG  > SFRecCameraPtr;
/*! \ingroup GrpSystemWindowFieldSFields */
typedef PointerSField<Camera *,
                      UnrecordedRefCountPolicy, nsOSG> SFUnrecCameraPtr;
/*! \ingroup GrpSystemWindowFieldSFields */
typedef PointerSField<Camera *,
                      WeakRefCountPolicy, nsOSG      > SFWeakCameraPtr;
/*! \ingroup GrpSystemWindowFieldSFields */
typedef PointerSField<Camera *,
                      NoRefCountPolicy, nsOSG        > SFUncountedCameraPtr;


/*! \ingroup GrpSystemWindowFieldMFields */
typedef PointerMField<Camera *,
                      RecordedRefCountPolicy, nsOSG  > MFRecCameraPtr;
/*! \ingroup GrpSystemWindowFieldMFields */
typedef PointerMField<Camera *,
                      UnrecordedRefCountPolicy, nsOSG> MFUnrecCameraPtr;
/*! \ingroup GrpSystemWindowFieldMFields */
typedef PointerMField<Camera *,
                      WeakRefCountPolicy, nsOSG      > MFWeakCameraPtr;
/*! \ingroup GrpSystemWindowFieldMFields */
typedef PointerMField<Camera *,
                      NoRefCountPolicy, nsOSG        > MFUncountedCameraPtr;




#else // these are the doxygen hacks

/*! \ingroup GrpSystemWindowFieldSFields \ingroup GrpLibOSGSystem */
struct SFRecCameraPtr : 
    public PointerSField<Camera *,
                         RecordedRefCountPolicy> {};
/*! \ingroup GrpSystemWindowFieldSFields \ingroup GrpLibOSGSystem */
struct SFUnrecCameraPtr : 
    public PointerSField<Camera *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemWindowFieldSFields \ingroup GrpLibOSGSystem */
struct SFWeakCameraPtr :
    public PointerSField<Camera *,
                         WeakRefCountPolicy> {};
/*! \ingroup GrpSystemWindowFieldSFields \ingroup GrpLibOSGSystem */
struct SFUncountedCameraPtr :
    public PointerSField<Camera *,
                         NoRefCountPolicy> {};


/*! \ingroup GrpSystemWindowFieldMFields \ingroup GrpLibOSGSystem */
struct MFRecCameraPtr :
    public PointerMField<Camera *,
                         RecordedRefCountPolicy  > {};
/*! \ingroup GrpSystemWindowFieldMFields \ingroup GrpLibOSGSystem */
struct MFUnrecCameraPtr :
    public PointerMField<Camera *,
                         UnrecordedRefCountPolicy> {};
/*! \ingroup GrpSystemWindowFieldMFields \ingroup GrpLibOSGSystem */
struct MFWeakCameraPtr :
    public PointerMField<Camera *,
                         WeakRefCountPolicy      > {};
/*! \ingroup GrpSystemWindowFieldMFields \ingroup GrpLibOSGSystem */
struct MFUncountedCameraPtr :
    public PointerMField<Camera *,
                         NoRefCountPolicy        > {};



#endif // these are the doxygen hacks

OSG_END_NAMESPACE

#endif /* _OSGCAMERAFIELDS_H_ */
