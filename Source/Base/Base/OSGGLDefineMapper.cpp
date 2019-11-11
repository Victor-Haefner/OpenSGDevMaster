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

//-------------------------------
//  Includes
//-------------------------------

#define OSG_COMPILE_GLDEFINEMAPPER

#include "OSGGLDefineMapper.h"

#include "OSGSingletonHolder.ins"

OSG_BEGIN_NAMESPACE

OSG_SINGLETON_INST(GLDefineMapperBase, addPostFactoryExitFunction)

//template class SingletonHolder<GLDefineMapperBase>;


GLenum GLDefineMapperBase::fromString(const Char8  *sval) const
{
    GLenum returnValue = 0x0000;

    if(sval == NULL)
        return returnValue;

    if((sval[0] != '\0' && sval[0] == 'G') &&
       (sval[1] != '\0' && sval[1] == 'L') &&
       (sval[2] != '\0' && sval[2] == '_')   )
    {
        MapToValue::const_iterator mIt = _mToValue.find(sval + 3);

        if(mIt != _mToValue.end())
        {
            returnValue = mIt->second;
        }
        else
        {
            FWARNING(("Unknow gl constant : %s\n", sval));
        }
    }
    else
    {
        returnValue = Inherited::fromString(sval);
    }

#if 0
    else if(sval[0] >= 48 && sval[0] <= 57)
    {
        returnValue = TypeTraits<GLenum>::getFromCString(sval);
    }
    else
    {
        MapToValue::const_iterator mIt = _mToValue.find(sval);

        if(mIt != _mToValue.end())
        {
            returnValue = mIt->second;
        }
        else
        {
            FWARNING(("Unknow gl constant : %s\n", sval));
        }
    }
#endif

    return returnValue;
}


GLDefineMapperBase::GLDefineMapperBase(void) :
    Inherited()
{
    initMaps();
}

GLDefineMapperBase::~GLDefineMapperBase(void)
{
}

OSG_END_NAMESPACE
