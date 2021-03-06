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

#ifndef _OSGANIMMATRIXBLENDER_H_
#define _OSGANIMMATRIXBLENDER_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGAnimMatrixBlenderBase.h"

OSG_BEGIN_NAMESPACE

/*! \brief AnimMatrixBlender class. See \ref
           PageDynamicsAnimMatrixBlender for a description.
*/

class OSG_DYNAMICS_DLLMAPPING AnimMatrixBlender : public AnimMatrixBlenderBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef AnimMatrixBlenderBase Inherited;
    typedef AnimMatrixBlender     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                  Frame Task Interface                        */
    /*! \{                                                                 */

    virtual bool init    (void                      );
    virtual void frame   (Time oTime, UInt32 uiFrame);
    virtual void shutdown(void                      );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                       Setup                                  */
    /*! \{                                                                 */

    virtual void addChannel(      AnimChannel         *channel   );
    virtual void subChannel(      AnimChannel         *channel   );

    virtual void connectTo (      AttachmentContainer *container,
                            const std::string         &fieldName );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in AnimMatrixBlenderBase.

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    AnimMatrixBlender(void);
    AnimMatrixBlender(const AnimMatrixBlender &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~AnimMatrixBlender(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class AnimMatrixBlenderBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const AnimMatrixBlender &source);
};

typedef AnimMatrixBlender *AnimMatrixBlenderP;

OSG_END_NAMESPACE

#include "OSGAnimMatrixBlenderBase.inl"
#include "OSGAnimMatrixBlender.inl"

#endif /* _OSGANIMMATRIXBLENDER_H_ */
