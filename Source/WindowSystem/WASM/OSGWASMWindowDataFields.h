/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2002 by the OpenSG Forum                   *
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

#ifndef _OSGWASMWINDOWDATAFIELDS_H_
#define _OSGWASMWINDOWDATAFIELDS_H_
#ifdef __sgi
#pragma once
#endif

typedef struct __GLXcontextRec *GLXContext;
typedef struct _XDisplay        Display;

#include "OSGConfig.h"

#include "OSGWindowWASMDef.h"

#include "OSGBaseTypes.h"
#include "OSGFieldTraits.h"

OSG_BEGIN_NAMESPACE

/*! \ingroup GrpWindowWASMFieldTraits
 */

typedef ::Display     *DisplayP;

/*! \ingroup GrpWindowWASMFieldTraits
 */
typedef unsigned long  X11Window;

/*! \ingroup GrpWindowWASMFieldTraits
    \ingroup GrpLibOSGWindowWASM
 */

template <>
struct FieldTraits<DisplayP, 2> : 
    public FieldTraitsPtrToStringTemplateBase<DisplayP, 2>
{
    static  DataType                 _type;                       
    typedef FieldTraits<DisplayP, 2>  Self;

    enum                        { Convertible = (Self::ToStringConvertible  |
                                                 Self::FromStringConvertible)};

    static       DataType &getType (void) { return _type;        }

    static const Char8    *getSName(void) { return "SFDisplayP"; }
    static const Char8    *getMName(void) { return "MFDisplayP"; }

    static bool      getFromCString(      DisplayP      &display,
                                    const Char8         *)
    {
        display = NULL;

        return true;
    }

    static void      putToString  (const      DisplayP &,
                                         std::string   &outStr)
    {
        outStr.assign("DisplayP");
    }
};


#if ( !defined(__GNUC__) || !defined(__linux) || ( !defined(__ia64) && !defined(__x86_64) && !defined(_ARCH_PPC64)) ) && (!defined(_MIPS_SZPTR) || _MIPS_SZPTR != 64)

/*! \ingroup GrpWindowWASMFieldTraits
    \ingroup GrpLibOSGWindowWASM
 */

template <>
struct FieldTraits<X11Window, 2> : 
    public FieldTraitsPtrToStringTemplateBase<X11Window, 2>
{
    static  DataType                  _type;                       
    typedef FieldTraits<X11Window, 2>  Self;

    enum                        { Convertible = (Self::ToStringConvertible  |
                                                 Self::FromStringConvertible)};

    static       DataType &getType (void) { return _type;         }

    static const Char8    *getSName(void) { return "SFX11Window"; }
    static const Char8    *getMName(void) { return "MFX11Window"; }

    static bool      getFromCString(      X11Window     &window,
                                    const Char8         *)
    {
        window = NULL;

        return true;
    }

    static void      putToString  (const      X11Window &,
                                         std::string    &outStr)
    {
        outStr.assign("X11Window");
    }
};
#endif

/*! \ingroup GrpWindowWASMFieldTraits
    \ingroup GrpLibOSGWindowWASM
 */

template <>
struct FieldTraits<GLXContext, 2> : 
    public FieldTraitsPtrToStringTemplateBase<GLXContext, 2>
{
    static  DataType                   _type;                       
    typedef FieldTraits<GLXContext, 2>  Self;

    enum                        { Convertible = (Self::ToStringConvertible  |
                                                 Self::FromStringConvertible)};

    static       DataType &getType (void) { return _type;          }

    static const Char8    *getSName(void) { return "SFGLXContext"; }
    static const Char8    *getMName(void) { return "MFGLXContext"; }

    static bool      getFromCString(      GLXContext    &context,
                                    const Char8         *)
    {
        context = NULL;

        return true;
    }

    static void      putToString  (const      GLXContext &,
                                         std::string     &outStr)
    {
        outStr.assign("GLXContext");
    }
};

#ifndef DOXYGEN_SHOULD_SKIP_THIS
/*! \ingroup GrpWindowWASMFieldSFields */
typedef SField<DisplayP, 2> SFDisplayP;

/*! \ingroup GrpWindowWASMFieldMFields */
typedef MField<DisplayP, 2> MFDisplayP;

#if ( !defined(__GNUC__) || !defined(__linux) || ( !defined(__ia64) && !defined(__x86_64) && !defined(_ARCH_PPC64)) ) && (!defined(_MIPS_SZPTR) || _MIPS_SZPTR != 64)

/*! \ingroup GrpWindowWASMFieldSFields */
typedef SField<X11Window, 2> SFX11Window;

/*! \ingroup GrpWindowWASMFieldMFields */
typedef MField<X11Window, 2> MFX11Window;

#else

/*! \ingroup GrpWindowWASMFieldSFields */
typedef SField<UInt64> SFX11Window;

/*! \ingroup GrpWindowWASMFieldMFields */
typedef MField<UInt64> MFX11Window;

#endif

/*! \ingroup GrpWindowWASMFieldSFields */
typedef SField<GLXContext, 2> SFGLXContext;

/*! \ingroup GrpWindowWASMFieldMFields */
typedef MField<GLXContext, 2> MFGLXContext;
#else // doxygen hacks
/*! \ingroup GrpWindowWASMFieldSFields */
struct SFDisplayP : public SField<DisplayP, 2> {};

/*! \ingroup GrpWindowWASMFieldMFields */
struct MFDisplayP : public MField<DisplayP, 2> {};

#if ( !defined(__GNUC__) || !defined(__linux) || ( !defined(__ia64) && !defined(__x86_64) && !defined(_ARCH_PPC64)) ) && (!defined(_MIPS_SZPTR) || _MIPS_SZPTR != 64)

/*! \ingroup GrpWindowWASMFieldSFields */
struct SFX11Window : public SField<X11Window, 2> {};

/*! \ingroup GrpWindowWASMFieldMFields */
struct MFX11Window : public MField<X11Window, 2> {};

#else

/*! \ingroup GrpWindowWASMFieldSFields */
struct SFX11Window : public SField<UInt64> {};

/*! \ingroup GrpWindowWASMFieldMFields */
struct MFX11Window : public MField<UInt64> {};

#endif

/*! \ingroup GrpWindowWASMFieldSFields */
struct SFGLXContext : public SField<GLXContext, 2> {};

/*! \ingroup GrpWindowWASMFieldMFields */
struct MFGLXContext : public MField<GLXContext, 2> {};
#endif



OSG_END_NAMESPACE

#endif /* _OSGWASMWINDOWDATAFIELDS_H_ */

