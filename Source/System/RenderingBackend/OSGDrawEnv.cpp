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

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"

#include "OSGDrawEnv.h"
#include "OSGState.h"
#include "OSGStateOverride.h"
#include "OSGBaseFunctions.h"
#include "OSGFullStateChunk.h"

#include "OSGShaderExecutableChunk.h"

OSG_USING_NAMESPACE

/*! \class OSG::OpenGLState
    \ingroup GrpSystemRenderingBackend
 */

OpenGLState::OpenGLState(void) :
#ifdef OSG_OGL_COREONLY
    _mModelViewProjection(    ),
    _mNormalMatrix       (    ),
#endif
    _mProjection         (    ),
    _mModelView          (    ),
    _uiTransformFeedback (0x00)
{
#ifdef OSG_OGL_COREONLY
    _mModelViewProjection.setIdentity();
    _mNormalMatrix       .setIdentity();
#endif
    _mProjection         .setIdentity();
    _mModelView          .setIdentity();
}

OpenGLState::~OpenGLState(void)
{
}

/*! \class OSG::DrawEnv
    \ingroup GrpSystemRenderingBackend
 */

/*-------------------------------------------------------------------------*/
/*                            Constructors                                 */

DrawEnv::DrawEnv(void) :
    _openGLState            (       ),
    _pRenderAction          (NULL   ),
    _cameraProjection       (       ),
    _cameraProjectionTrans  (       ),
    _cameraViewing          (       ),
    _cameraToWorld          (       ),
    _cameraDecoration       (       ),

    _objectToWorld          (       ),
    _worldToScreen          (       ),

    _vpCameraFullProjection (       ),
    _vpCameraProjection     (       ),
    _vpCameraProjectionTrans(       ),
    _vpCameraViewing        (       ),
    _vpCameraToWorld        (       ),
    _vpWorldToScreen        (       ),

    _cameraNear             (  1.f  ),
    _cameraFar              (  100.f),

    _iPixelLeft             (      0),
    _iPixelRight            (      1),
    _iPixelBottom           (      0),
    _iPixelTop              (      1),

    _uiTileFullSize         (       ),
    _vTileRegion            (       ),

    _bFull                  (   true),

    _iDrawerId              (-1     ),
    _iDrawableId            (-1     ),

    _uiLightState           (      0),

    _pWindow                (NULL   ),
    _pSGNode                (NULL   ),

    _pActiveState           (NULL   ),
    _pActiveStateOverride   (NULL   ),

    _uiNumStateChanges      (0      ),
    _uiNumChunkChanges      (0      ),
    _uiNumShaderChanges     (0      ),
    _uiNumShaderParamChanges(0      ),

    _pStatCollector         (NULL   ),

    _uiActiveShader         (0      ),
    _uiActiveFBO            (0      ),
    _eTargetBufferFormat    (GL_RGBA),
    _uiRequiredOGLFeature   (0      )
{
    _cameraProjection       .setIdentity();
    _cameraProjectionTrans  .setIdentity();
    _cameraViewing          .setIdentity();
    _cameraToWorld          .setIdentity();
    _cameraDecoration       .setIdentity();

    _objectToWorld          .setIdentity();

    _vpCameraFullProjection .setIdentity();
    _vpCameraProjection     .setIdentity();
    _vpCameraProjectionTrans.setIdentity();
    _vpCameraViewing        .setIdentity();
    _vpCameraToWorld        .setIdentity();
    _vpWorldToScreen        .setIdentity();
}

/*-------------------------------------------------------------------------*/
/*                             Destructor                                  */

DrawEnv::~DrawEnv(void)
{
}

void DrawEnv::calcViewportDimension(Real32 rLeft,
                                    Real32 rBottom,
                                    Real32 rRight,
                                    Real32 rTop,
                                    
                                    UInt16 iTargetWidth,
                                    UInt16 iTargetHeight)
{
    if(rLeft > 1.f)
        _iPixelLeft = Int32(rLeft);
    else
        _iPixelLeft = Int32(iTargetWidth * rLeft);

    if(rRight > 1.f)
        _iPixelRight = Int32(rRight);
    else
        _iPixelRight = Int32(iTargetWidth * rRight) - 1;


    if(rBottom > 1.f)
        _iPixelBottom = Int32(rBottom);
    else
        _iPixelBottom = Int32(iTargetHeight * rBottom);

    if(rTop > 1.f)
        _iPixelTop = Int32(rTop);
    else
        _iPixelTop = Int32(iTargetHeight * rTop) - 1;


    _bFull = ( (_iPixelLeft   == 0                ) &&
               (_iPixelRight  == iTargetWidth  - 1) &&
               (_iPixelBottom == 0                ) &&
               (_iPixelTop    == iTargetHeight - 1)  );
}

Matrix DrawEnv::calcTileDecorationMatrix(void) const
{
    Vec4f vTileRegion = this->getTileRegion();

    Vec2u vTileFullSize   = this->getTileFullSize();

    if(vTileRegion[0] < 0)
        vTileRegion[0] = -vTileRegion[0] / vTileFullSize[0];
        
    if(vTileRegion[1] < 0)
        vTileRegion[1] = -vTileRegion[1] / vTileFullSize[0];
        
    if(vTileRegion[3] < 0)
        vTileRegion[3] = -vTileRegion[3] / vTileFullSize[1];
        
    if(vTileRegion[2] < 0)
        vTileRegion[2] = -vTileRegion[2] / vTileFullSize[1];

    // scale the wanted part from the decoration matrix
    Real32 xs = 1.f / (vTileRegion[1] - vTileRegion[0]);
    Real32 ys = 1.f / (vTileRegion[3] - vTileRegion[2]);

    Matrix result( xs,  0, 0, -(vTileRegion[0] * 2 - 1) * xs - 1,  
                    0, ys, 0, -(vTileRegion[2] * 2 - 1) * ys - 1,  
                    0,  0, 1, 0, 
                    0,  0, 0, 1);


    return result;
}

void DrawEnv::deactivateState(void)
{
    if(_pActiveState == NULL)
        return;

    StateChunk *pChunk = _pActiveState->getChunk(State::FullStateIndex);

    if(pChunk != NULL)
    {
        FullStateChunk *pFullChunk = 
            dynamic_cast<FullStateChunk *>(pChunk);

        OSG_ASSERT(pFullChunk != NULL);

        pFullChunk->deactivate(this, _pActiveState, _pActiveStateOverride);
    }
    else
    {
        if(_pActiveStateOverride != NULL)
        {
            deactivate(_pActiveState, _pActiveStateOverride);
        }
        else
        {
            deactivate(_pActiveState);
        }
    }

    _pActiveState         = NULL;
    _pActiveStateOverride = NULL;
}

void DrawEnv::activateState(State         *pNewState,
                            StateOverride *pNewStateOverride)
{
    if(pNewState != NULL)
    {
        StateChunk *pNewChunk = pNewState->getChunk(State::FullStateIndex);

        if(_pActiveState != NULL)
        {
            StateChunk *pActiveChunk = 
                _pActiveState->getChunk(State::FullStateIndex);

            if(pNewChunk != NULL && pActiveChunk != NULL)
            {
                FullStateChunk *pFullChunk = 
                    dynamic_cast<FullStateChunk *>(pNewChunk);

                OSG_ASSERT(pFullChunk != NULL);

                pFullChunk->changeFrom( this,
                                        pNewState,
                                        pNewStateOverride,
                                       _pActiveState,
                                       _pActiveStateOverride);

                ++_uiNumStateChanges;
                
                _pActiveState         = pNewState;
                _pActiveStateOverride = pNewStateOverride;
            }
            else if(pNewChunk != NULL && pActiveChunk == NULL)
            {
                FullStateChunk *pFullChunk = 
                    dynamic_cast<FullStateChunk *>(pNewChunk);

                OSG_ASSERT(pFullChunk != NULL);

                if(_pActiveStateOverride != NULL)
                {
                    deactivate(_pActiveState, _pActiveStateOverride);
                }
                else
                {
                    deactivate(_pActiveState);
                }
                pFullChunk->activate(this, pNewState, pNewStateOverride);

                ++_uiNumStateChanges;

                _pActiveState         = pNewState;
                _pActiveStateOverride = pNewStateOverride;
            }
            else if(pNewChunk == NULL && pActiveChunk != NULL)
            {
                FullStateChunk *pFullChunk = 
                    dynamic_cast<FullStateChunk *>(pActiveChunk);

                OSG_ASSERT(pFullChunk != NULL);

                pFullChunk->deactivate(this, 
                                       _pActiveState, _pActiveStateOverride);
        
                if(pNewStateOverride != NULL)
                {
                    activate(pNewState, pNewStateOverride);
                }
                else
                {
                    activate(pNewState);
                }

                _pActiveState         = pNewState;
                _pActiveStateOverride = pNewStateOverride;
            }
            else
            {
                if(pNewState         != _pActiveState        ||
                   pNewStateOverride != _pActiveStateOverride )
                {
                    if(pNewStateOverride != NULL)
                    {
                        if(_pActiveStateOverride != NULL)
                        {
                            changeTo( pNewState,     pNewStateOverride,
                                     _pActiveState, _pActiveStateOverride);
                        }
                        else
                        {
                            changeTo( pNewState,     pNewStateOverride,
                                     _pActiveState                    );
                        }
                    }
                    else if(_pActiveStateOverride != NULL)
                    {
                        changeTo( pNewState, 
                                 _pActiveState, 
                                 _pActiveStateOverride);
                    }
                    else
                    {
                        changeTo(pNewState, _pActiveState);
                    }
                    
                    _pActiveState         = pNewState;
                    _pActiveStateOverride = pNewStateOverride;
                }
                else
                {
                    if(_pActiveStateOverride != NULL)
                    {
                        updateChunk(_pActiveState, 
                                    _pActiveStateOverride);
                    }
                    else
                    {
                        updateChunk(_pActiveState);
                    }
                }
            }
        }
        else
        {
            if(pNewChunk != NULL)
            {
                FullStateChunk *pFullChunk = 
                    dynamic_cast<FullStateChunk *>(pNewChunk);

                OSG_ASSERT(pFullChunk != NULL);

                pFullChunk->activate(this, pNewState, pNewStateOverride);

                ++_uiNumStateChanges;
            }
            else
            {
                if(pNewStateOverride != NULL)
                {
                    activate(pNewState, pNewStateOverride);
                }
                else
                {
                    activate(pNewState);
                }
            }

            _pActiveState         = pNewState;
            _pActiveStateOverride = pNewStateOverride;
        }
    }
}



void DrawEnv::activate(State *pState)
{
    pState->activate(this);

    ++_uiNumStateChanges;
}

void DrawEnv::activate(State         *pState,
                       StateOverride *pOverride)
{
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  (); 

    StateOverride::ChunkStoreConstIt     overIt = pOverride->begin();

    Int32                     ind    = 0;
    UInt32                    cind   = osgMin(State::SkipNumChunks, 
                                              pState->getMFChunks()->size32());

    UInt32 const              climit = pState->getCoreGLChunkLimit(); 

    OSG_SKIP_IT    (cIt, cind);

// TODO: hack, no idea how this index juggling is supposed to work..
//  this hack was added to enable face culling (PolygonChunk)
#ifdef __EMSCRIPTEN__
    for(cind = 0; (cIt != cEnd) ; ++cIt, ++cind) {
	if(*cIt != NULL && (*cIt)->getIgnore() == false)
            {
                (*cIt)->activate(this, 0);
            }
    }
#endif

    for(; (cIt != cEnd) && (cind < climit); ++cIt, ++cind)
    {
        if(overIt != pOverride->end() && overIt->first == cind)
        {
            if(overIt->second->getIgnore() == false)
            {
                overIt->second->activate(this, UInt32(ind));
            }

            ++overIt;
        }
        else
        {
            if(*cIt != NULL && (*cIt)->getIgnore() == false)
            {
                (*cIt)->activate(this, UInt32(ind));
            }
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
            ind = 0;
    }

    while(overIt != pOverride->end())
    {
        if(overIt->first >= climit)
            break;

        if(overIt->second->getIgnore() == false)
        {
            overIt->second->activate(this,
                                     UInt32(overIt->first -
                                            overIt->second->getClassId()));
        }

        ++overIt;
    }

    ++_uiNumStateChanges;
}

void DrawEnv::changeTo(State         *pState,
                       State         *pOld)
{
    if(pState != pOld)
    {
        pState->changeFrom(this, pOld);

        ++_uiNumStateChanges;
    }
}

void DrawEnv::changeTo(State         *pState,
                       State         *pOld,
                       StateOverride *pOldOverride)
{
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  (); 

    StateOverride::ChunkStoreConstIt     overIt = pOldOverride->begin();

    Int32                     ind    = 0;
    UInt32                    i;
    UInt32                    cind   = osgMin(State::SkipNumChunks, 
                                              pState->getMFChunks()->size32());

    UInt32 const              climit = pState->getCoreGLChunkLimit();

    StateChunk               *n      = NULL;

    OSG_SKIP_IT(cIt, cind);
   
    for(; (cIt != cEnd) && (cind < climit); ++cIt, ++cind)
    {
        StateChunk *o = pOld->getChunk(cind);

        n  = *cIt;

        if(overIt != pOldOverride->end() && overIt->first == cind)
        {
            o = overIt->second;
            ++overIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(o != NULL && o->getIgnore() == false)
            {
                n->changeFrom(this, o, UInt32(ind));
            }
            else
            {
                n->activate(this, UInt32(ind));
            }
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
        {
            ind = 0;
        }
    }

    if(ind >= StateChunkClass::getNumSlots(cind))
        ind = 0;

    cind = osgMax(cind, State::SkipNumChunks);

    for(i = cind; (i < pOld->getMFChunks()->size32()) && (i < climit); ++i)
    {
        StateChunk *o = pOld->getChunk(i);

        if(overIt != pOldOverride->end() && overIt->first == cind)
        {
            if(overIt->second->getIgnore() == false)
            {
                overIt->second->deactivate(this, UInt32(ind));
            }

            ++overIt;
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(i))
        {
            ind = 0;
        }
    }

    while(overIt != pOldOverride->end())
    {
        if(overIt->first >= climit)
            break;

        if(overIt->second->getIgnore() == false)
        {
            overIt->second->deactivate(this,
                                       UInt32(overIt->first -
                                              overIt->second->getClassId()));
        }

        ++overIt;
    }

    ++_uiNumStateChanges;
}

void DrawEnv::changeTo(State         *pState,
                       StateOverride *pOverride,
                       State         *pOld)
{
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  (); 

    StateOverride::ChunkStoreConstIt     overIt = pOverride->begin();

    Int32                     ind    = 0;
    UInt32                    i;
    UInt32                    cind   = osgMin(State::SkipNumChunks, 
                                              pState->getMFChunks()->size32());

    UInt32 const              climit = pState->getCoreGLChunkLimit();

    StateChunk               *n      = NULL;

    OSG_SKIP_IT(cIt, cind);

    for(; (cIt != cEnd) && (cind < climit); ++cIt, ++cind)
    {
        StateChunk *o = pOld->getChunk(cind);
                    n = *cIt;

        if(overIt != pOverride->end() && overIt->first == cind)
        {
            n = overIt->second;
            ++overIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(o != NULL && o->getIgnore() == false)
            {
                n->changeFrom(this, o, UInt32(ind));
            }
            else
            {
                n->activate(this, UInt32(ind));
            }
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
        {
            ind = 0;
        }
    }

    if(ind >= StateChunkClass::getNumSlots(cind))
        ind = 0;

    cind = osgMax(cind, State::SkipNumChunks);

    for(i = cind; (i < pOld->getMFChunks()->size32()) && (i < climit); ++i)
    {
        StateChunk *o = pOld->getChunk(i);

        n = NULL;

        if(overIt != pOverride->end() && overIt->first == cind)
        {
            n = overIt->second;
            ++overIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(o != NULL && o->getIgnore() == false)
            {
                n->changeFrom(this, o, UInt32(ind));
            }
            else
            {
                n->activate(this, UInt32(ind));
            }
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(i))
        {
            ind = 0;
        }
    }

    while(overIt != pOverride->end())
    {
        if(overIt->first >= climit)
            break;

        if(overIt->second->getIgnore() == false)
        {
            overIt->second->activate(this,
                                     UInt32(overIt->first -
                                            overIt->second->getClassId()));
        }

        ++overIt;
    }

    ++_uiNumStateChanges;
}

void DrawEnv::changeTo(State         *pState,
                       StateOverride *pOverride,
                       State         *pOld,
                       StateOverride *pOldOverride)
{
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  (); 

    StateOverride::ChunkStoreConstIt     newOverIt = pOverride  ->begin();
    StateOverride::ChunkStoreConstIt     oldOverIt = pOldOverride->begin();

    Int32                     ind    = 0;
    UInt32                    i;
    UInt32                    cind   = osgMin(State::SkipNumChunks, 
                                              pState->getMFChunks()->size32());

    UInt32 const              climit = pState->getCoreGLChunkLimit();

    StateChunk               *n      = NULL;

    OSG_SKIP_IT(cIt, cind);

    for(; (cIt != cEnd) && (cind < climit); ++cIt, ++cind)
    {
        StateChunk *o = pOld->getChunk(cind);
                    n = *cIt;

        if(oldOverIt != pOldOverride->end() && oldOverIt->first == cind)
        {
            o = oldOverIt->second;
            ++oldOverIt;
        }

        if(newOverIt != pOverride->end() && newOverIt->first == cind)
        {
            n = newOverIt->second;
            ++newOverIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(o != NULL && o->getIgnore() == false)
            {
                n->changeFrom(this, o, UInt32(ind));
            }
            else
            {
                n->activate(this, UInt32(ind));
            }
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
        {
            ind = 0;
        }
    }


    if(ind >= StateChunkClass::getNumSlots(cind))
        ind = 0;

    cind = osgMax(cind, State::SkipNumChunks);

    for(i = cind; (i < pOld->getMFChunks()->size32()) && (i < climit); ++i)
    {
        StateChunk *o = pOld->getChunk(i);
        n = NULL;

        if(oldOverIt != pOldOverride->end() && oldOverIt->first == cind)
        {
            o = oldOverIt->second;
            ++oldOverIt;
        }

        if(newOverIt != pOverride->end() && newOverIt->first == cind)
        {
            n = newOverIt->second;
            ++newOverIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(o != NULL && o->getIgnore() == false)
            {
                n->changeFrom(this, o, UInt32(ind));
            }
            else
            {
                n->activate(this, UInt32(ind));
            }
        }
        else if(o != NULL && o->getIgnore() == false)
        {
            o->deactivate(this, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(i))
        {
            ind = 0;
        }
    }

    while(oldOverIt != pOldOverride->end())
    {
        if(oldOverIt->first >= climit)
            break;

        n = NULL;

        if(newOverIt        != pOverride->end() &&
           newOverIt->first == oldOverIt->first  )
        {
            n = newOverIt->second;
            ++newOverIt;
        }

        if(n != NULL && n->getIgnore() == false)
        {
            if(oldOverIt->second->getIgnore() == false)
            {
                n->changeFrom(this,
                              oldOverIt->second,
                              UInt32(oldOverIt->first -
                                     oldOverIt->second->getClassId()));
            }
            else
            {
                n->activate(this,
                            UInt32(oldOverIt->first -
                                   oldOverIt->second->getClassId()));
            }
        }
        else if(oldOverIt->second->getIgnore() == false)
        {
            oldOverIt->second->deactivate(
                this,
                  UInt32(oldOverIt->first -
                         oldOverIt->second->getClassId()));
        }

        ++oldOverIt;
    }


    while(newOverIt != pOverride->end())
    {
        if(newOverIt->first >= climit)
            break;

        if(newOverIt->second->getIgnore() == false)
        {
            newOverIt->second->activate(this,
                                        UInt32(
                                            newOverIt->first -
                                            newOverIt->second->getClassId()));
        }

        ++newOverIt;
    }

    ++_uiNumStateChanges;
}

void DrawEnv::deactivate(State *pState)
{
    if(pState != NULL)
        pState->deactivate(this);
}

void DrawEnv::deactivate(State         *pState,
                         StateOverride *pOverride  )
{
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  ();

    StateOverride::ChunkStoreConstIt     overIt = pOverride->begin();

    Int32                     ind    = 0;
    UInt32                    cind   = osgMin(State::SkipNumChunks, 
                                              pState->getMFChunks()->size32());

    UInt32 const              climit = pState->getCoreGLChunkLimit();

    OSG_SKIP_IT(cIt, cind);

    for(; (cIt != cEnd) && (cind < climit); ++cIt, ++cind)
    {
        if(overIt != pOverride->end() && overIt->first == cind)
        {
            if(overIt->second->getIgnore() == false)
            {
                overIt->second->deactivate(this, UInt32(ind));
            }

            ++overIt;
        }
        else
        {
            if(*cIt != NULL && (*cIt)->getIgnore() == false)
            {
                (*cIt)->deactivate(this, UInt32(ind));
            }
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
            ind = 0;
    }

    while(overIt !=  pOverride->end())
    {
        if(overIt->first >= climit)
            break;

        if(overIt->second->getIgnore() == false)
        {
            overIt->second->deactivate(this,
                                       UInt32(overIt->first -
                                              overIt->second->getClassId()));
        }

        ++overIt;
    }
}

void DrawEnv::update(State *pState)
{
#if 0
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  ();

    Int32                     ind  = 0;
    UInt32                    cind = osgMin(State::SkipNumChunks, 
                                            pState->getMFChunks()->size32());

    OSG_SKIP_IT(cIt, cind);

    for(; cIt != cEnd && cind < State::UpdateBelow; ++cIt, ++cind)
    {
        if(*cIt != NULL && (*cIt)->getIgnore() == false)
        {
            (*cIt)->changeFrom(this, *cIt, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
            ind = 0;
    }
#endif
}

void DrawEnv::update(State         *pState,
                     StateOverride *pOverride)
{
#if 0
    MFUnrecStateChunkPtr::const_iterator cIt  = pState->getMFChunks()->begin();
    MFUnrecStateChunkPtr::const_iterator cEnd = pState->getMFChunks()->end  ();

    StateOverride::ChunkStoreConstIt     overIt = pOverride->begin();

    Int32                     ind  = 0;
    UInt32                    cind = osgMin(State::SkipNumChunks, 
                                            pState->getMFChunks()->size32());
    StateChunk               *c    = NULL;

    OSG_SKIP_IT(cIt, cind);

    for(; cIt != cEnd && cind < State::UpdateBelow; ++cIt, ++cind)
    {
        if(overIt != pOverride->end() && overIt->first == cind)
        {
            c = overIt->second;
            ++overIt;
        }
        else
        {
            c = *cIt;
        }

        if(c != NULL && c->getIgnore() == false)
        {
            c->changeFrom(this, c, UInt32(ind));
        }

        if(++ind >= StateChunkClass::getNumSlots(cind))
            ind = 0;
    }
#endif
}

void DrawEnv::updateChunk(State *pState)
{
    StateChunk   *c      = pState->getChunk(State::UpdateChunk);
    UInt32 const  climit = pState->getCoreGLChunkLimit();
   
    if(c != NULL && c->getIgnore() == false && c->getClassId() < climit)
    {
        (c)->changeFrom(this, c, UInt32(0));
    }

    c = pState->getChunk(ShaderExecutableChunk::getStaticClassId());

    if(c != NULL && c->getIgnore() == false && c->getClassId() < climit)
    {
        (c)->changeFrom(this, c, UInt32(0));
    }
}

void DrawEnv::updateChunk(State         *pState,
                          StateOverride *pOverride)
{
    if(pOverride->size() == 0)
    {
        return updateChunk(pState);
    }

    const UInt32 climit = pState->getCoreGLChunkLimit();


    StateChunk                       *c  = NULL;
    StateOverride::ChunkStoreConstIt oIt = pOverride->begin();


    if(oIt->first == State::UpdateChunk)
    {
        c = oIt->second;
        ++oIt;
    }
    else
    {
        pState->getChunk(State::UpdateChunk);
    }

    if(c != NULL && c->getIgnore() == false && c->getClassId() < climit)
    {
        c->changeFrom(this, c, UInt32(0));
        return;
    }


    if(oIt        != pOverride->end()                         && 
       oIt->first ==ShaderExecutableChunk::getStaticClassId()  )
    {
        c = oIt->second;
        ++oIt;
    }
    else
    {
        c = pState->getChunk(ShaderExecutableChunk::getStaticClassId());
    }

    if(c != NULL && c->getIgnore() == false && c->getClassId() < climit)
    {
        
        c->updateObjectDependencies(this);
    }
}
