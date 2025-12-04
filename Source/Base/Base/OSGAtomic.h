/*---------------------------------------------------------------------------*\
 *                                OpenSG                                     *
 *                                                                           *
 *                                                                           *
 *             Copyright (C) 2000-2003 by the OpenSG Forum                   *
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

#ifndef _OSGATOMIC_H_
#define _OSGATOMIC_H_

#include "OSGBaseTypes.h"


OSG_BEGIN_NAMESPACE

/*! \ingroup GrpBaseBaseAtomicFn
 */

inline 
RefCountStore osgAtomicExchangeAndAdd(RefCountStore *pValue, 
                                      RefCountStore  rcDelta)
{
    auto* atomicPtr = reinterpret_cast<std::atomic<RefCountStore>*>(pValue);
    return atomicPtr->fetch_add(rcDelta, std::memory_order_relaxed);
}

/*! \ingroup GrpBaseBaseAtomicFn
 */

inline 
void osgAtomicIncrement(RefCountStore *pValue)
{
    auto* atomicPtr = reinterpret_cast<std::atomic<RefCountStore>*>(pValue);
    atomicPtr->fetch_add(1, std::memory_order_relaxed);
}

/*! \ingroup GrpBaseBaseAtomicFn
 */

inline 
void osgAtomicDecrement(RefCountStore *pValue)
{
    auto* atomicPtr = reinterpret_cast<std::atomic<RefCountStore>*>(pValue);
    atomicPtr->fetch_sub(1, std::memory_order_relaxed);
}

/*! \ingroup GrpBaseBaseAtomicFn
 */

inline
void osgSpinLock(UInt32 *pLock, UInt32 uiMask)
{
    auto* atomicPtr = reinterpret_cast<std::atomic<UInt32>*>(pLock);

    // spin until we can set the bits in uiMask
    UInt32 old = atomicPtr->fetch_or(uiMask, std::memory_order_acquire);
    while (old & uiMask)
    {
        old = atomicPtr->fetch_or(uiMask, std::memory_order_acquire);
    }
}

/*! \ingroup GrpBaseBaseAtomicFn
 */

inline
void osgSpinLockRelease(UInt32 *pLock, UInt32 uiInvMask)
{
    auto* atomicPtr = reinterpret_cast<std::atomic<UInt32>*>(pLock);
    atomicPtr->fetch_and(uiInvMask, std::memory_order_release);
}


OSG_END_NAMESPACE

#endif // _OSGATOMIC_H_
