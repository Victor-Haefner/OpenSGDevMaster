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

//---------------------------------------------------------------------------
//  Includes
//---------------------------------------------------------------------------

#include <cstdlib>
#include <cstdio>

#include "OSGConfig.h"
#include "OSGGL.h"
#include "OSGGLEXT.h"
#include "OSGGLFuncProtos.h"

#include "OSGLayeredTextureBuffer.h"
#include "OSGWindow.h"
#include "OSGDrawEnv.h"
#include "OSGTextureObjChunk.h"
#include "OSGImage.h"

OSG_BEGIN_NAMESPACE

typedef void (OSG_APIENTRY *osgGlFramebufferTextureProc) (GLenum target, 
                                                          GLenum attachment, 
                                                          GLuint texture, 
                                                          GLint  level     );


UInt32 LayeredTextureBuffer::_uiGeoShader4_extension         = 
    Window::invalidExtensionID;

UInt32 LayeredTextureBuffer::_uiFramebuffer_object_extension = 
    Window::invalidExtensionID;

UInt32 LayeredTextureBuffer::_uiFuncFramebufferTexture       =  
    Window::invalidFunctionID;

UInt32 LayeredTextureBuffer::_uiFuncGenerateMipmap           =  
    Window::invalidFunctionID;

// Documentation for this class is emited in the
// OSGLayeredTextureBufferBase.cpp file.
// To modify it, please change the .fcd file (OSGLayeredTextureBuffer.fcd) and
// regenerate the base file.

void LayeredTextureBuffer::bind(DrawEnv *pEnv, UInt32 index)
{
    Window *pWindow = pEnv->getWindow();

    if(_sfTexture.getValue() != NULL)
    {
        pWindow->validateGLObject(_sfTexture.getValue()->getGLId(), pEnv);

        GLenum target;

        if(getTexTarget() != GL_NONE)
        {
            target = getTexTarget();
        }
        else
        {
            target = _sfTexture.getValue()->determineTextureTarget(pWindow);
        }
            
        switch(target)
        {
            case GL_TEXTURE_CUBE_MAP_ARRAY:
            case GL_TEXTURE_2D_ARRAY:
            case GL_TEXTURE_3D:
            {
                OSGGETGLFUNCBYID_GL3( glFramebufferTexture,
                                      osgGlFramebufferTexture,
                                     _uiFuncFramebufferTexture,
                                      pWindow);

                osgGlFramebufferTexture(
                    GL_FRAMEBUFFER, 
                    index,
                    pWindow->getGLObjectId(_sfTexture.getValue()->getGLId()),
                    0);
            }
            break;
        }
    }
}

void LayeredTextureBuffer::validate(DrawEnv *pEnv)
{
    Window *pWindow = pEnv->getWindow();

    if(_sfTexture.getValue() != NULL)
    {
        pWindow->validateGLObject(_sfTexture.getValue()->getGLId(), pEnv);
    }
}

void LayeredTextureBuffer::resizeBuffers(UInt32 uiWidth, UInt32 uiHeight)
{
    TextureObjChunk *pTex = this->getTexture();

    if(pTex == NULL)
        return;

    Image *pImg = pTex->getImage();

    if(pImg == NULL)
        return;

    pImg->set(pImg->getPixelFormat(), //Image::OSG_RGB_PF, 
              uiWidth, 
              uiHeight,
              pImg->getDepth      (),
              pImg->getMipMapCount(),
              pImg->getFrameCount (),
              pImg->getFrameDelay (),
              NULL,
              pImg->getDataType   (), //Image::OSG_UINT8_IMAGEDATA,
              false,
              pImg->getSideCount  ());
}

GLenum LayeredTextureBuffer::getBufferFormat(void) const
{
    TextureObjChunk *pTex = this->getTexture();

    if(pTex == NULL)
        return GL_NONE;

    if(pTex->getInternalFormat() != GL_NONE)
        return pTex->getInternalFormat();

    Image *pImg = pTex->getImage();

    if(pImg == NULL)
        return GL_NONE;

    return pImg->getPixelFormat();
}


void LayeredTextureBuffer::processPreDeactivate(DrawEnv *pEnv, UInt32 index)
{
#if 0
    if(_sfReadBack.getValue() == true)
    {
        TextureObjChunk *pTexObj = this->getTexture();
        
        if(pTexObj == NULL)
            return;
        
        Image *pTexImg = pTexObj->getImage();
                    
        if(pTexImg->getData() == NULL)
        {
            SINFO << "TextureBuffer::render: (Re)Allocating image "
                  << "for read-back."
                  << endLog;
            
            pTexImg->set(pTexImg->getPixelFormat(),
                         pTexImg->getWidth      (),
                         pTexImg->getHeight     (),
                         pTexImg->getDepth      (),
                         pTexImg->getMipMapCount(),
                         pTexImg->getFrameCount (),
                         pTexImg->getFrameDelay (),
                         NULL,
                         pTexImg->getDataType   (),
                         true,
                         pTexImg->getSideCount  () );
        }

        UInt32  mipMapLevel = _sfLevel.getValue();
        UInt32  frame       = 0;
        UInt32  side        = 0;
        GLenum  target;
        Window *pWindow = pEnv->getWindow();

        if(_sfTexTarget.getValue() != GL_NONE)
        {
            target = _sfTexTarget.getValue();
        }
        else
        {
            target = _sfTexture.getValue()->determineTextureTarget(pWindow);
        }

        switch(target)
        {
            case GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB:
                side = 0;
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB:
                side = 1;
                break;
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB:
                side = 2;
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB:
                side = 3;
                break;
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB:
                side = 4;
                break;
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB:
                side = 5;
                break;
        }

        // select GL_COLORATTACHMENTn and read data into image
#ifndef OSG_OGL_ES2
        glReadBuffer(index);
#endif
        glReadPixels(0, 0, 
                     pTexImg->getWidth      (),
                     pTexImg->getHeight     (),
                     pTexImg->getPixelFormat(),
                     pTexImg->getDataType   (),
                     pTexImg->editData      (mipMapLevel, frame, side));
        
#ifndef OSG_OGL_ES2
        glReadBuffer(GL_NONE);
#endif
    }
#endif
}

void LayeredTextureBuffer::processPostDeactivate(DrawEnv *pEnv)
{
    Window *win = pEnv->getWindow();

    // If there are TextureBuffers with mipmap filters attached,
    // the mipmaps need to be regenerated
    TextureObjChunk *pTexObj = this->getTexture();
        
    if(pTexObj == NULL)
        return;
        
    GLenum target = pTexObj->determineTextureTarget(win);
    if((target                  == GL_TEXTURE_CUBE_MAP_ARRAY ||
        target                  == GL_TEXTURE_2D_ARRAY       ||
        target                  == GL_TEXTURE_3D               )   &&
       (pTexObj->getMinFilter() == GL_NEAREST_MIPMAP_NEAREST ||
        pTexObj->getMinFilter() == GL_LINEAR_MIPMAP_NEAREST  ||
        pTexObj->getMinFilter() == GL_NEAREST_MIPMAP_LINEAR  ||
        pTexObj->getMinFilter() == GL_LINEAR_MIPMAP_LINEAR     )   )
    {
        OSGGETGLFUNCBYID_GL3_ES( glGenerateMipmap,
                                 osgGlGenerateMipmap,
                                _uiFuncGenerateMipmap,
                                 win);

        glBindTexture(target, win->getGLObjectId(pTexObj->getGLId()));

        osgGlGenerateMipmap(target);
    }
}

/*----------------------- constructors & destructors ----------------------*/

LayeredTextureBuffer::LayeredTextureBuffer(void) :
    Inherited()
{
}

LayeredTextureBuffer::LayeredTextureBuffer(const LayeredTextureBuffer &source) :
    Inherited(source)
{
}

LayeredTextureBuffer::~LayeredTextureBuffer(void)
{
}

/*----------------------------- class specific ----------------------------*/

void LayeredTextureBuffer::initMethod(InitPhase ePhase)
{
    Inherited::initMethod(ePhase);

    if(ePhase == TypeObject::SystemPost)
    {
        _uiGeoShader4_extension = 
            Window::registerExtension("GL_ARB_geometry_shader4");

        _uiFramebuffer_object_extension = 
            Window::registerExtension("GL_ARB_framebuffer_object");

        _uiFuncFramebufferTexture =
            Window::registerFunction (
                 OSG_DLSYM_UNDERSCORE"glFramebufferTexture", 
                _uiGeoShader4_extension);

        _uiFuncGenerateMipmap =
            Window::registerFunction (
                 OSG_DLSYM_UNDERSCORE"glGenerateMipmap",
                _uiFramebuffer_object_extension);
    }

}

void LayeredTextureBuffer::changed(ConstFieldMaskArg whichField, 
                                   UInt32            origin,
                                   BitVector         details)
{
    Inherited::changed(whichField, origin, details);
}

void LayeredTextureBuffer::dump(      UInt32    , 
                                const BitVector ) const
{
    SLOG << "Dump TextureBuffer NI" << std::endl;
}

OSG_END_NAMESPACE
