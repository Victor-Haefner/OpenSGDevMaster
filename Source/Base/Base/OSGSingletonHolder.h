/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *           Copyright (C) 2003, by the OpenSG Forum                         *
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

#ifndef _OSGSINGLETONHOLDER_H_
#define _OSGSINGLETONHOLDER_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGBaseTypes.h"
#include "OSGLog.h"

OSG_BEGIN_NAMESPACE

/*! \ingroup GrpBaseBaseHelper
    \ingroup GrpBaseBase
    \ingroup GrpLibOSGBase
    \nohierarchy
 */

template<class SingletonT>
class SingletonHolder
{
    /*==========================  PUBLIC  =================================*/

    typedef SingletonHolder<SingletonT> Self;

  public:

    typedef SingletonT Singleton;

    /*---------------------------------------------------------------------*/
    /*! \name                      access                                  */
    /*! \{                                                                 */

    static SingletonT *the    (bool destroy = false);
    static bool        destroy(void);

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Constructors                               */
    /*! \{                                                                 */

    static SingletonT* init(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructor                                 */
    /*! \{                                                                 */

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    /*!\brief prohibit default function (move to 'public' if needed) */
    SingletonHolder(const SingletonHolder &source);
    /*!\brief prohibit default function (move to 'public' if needed) */
    void operator =(const SingletonHolder &source);
};

template<class SingletonT> inline
SingletonT *SingletonHolder<SingletonT>::the(bool destroy)        
{      
    static SingletonT *_the = NULL;

    if (destroy) _the = NULL;                                                 
    else if(_the == NULL) _the = init();                    
                                                          
    return _the;                                          
}                                                         


OSG_END_NAMESPACE

#endif /* _OSGSINGLETONHOLDER_H_ */
