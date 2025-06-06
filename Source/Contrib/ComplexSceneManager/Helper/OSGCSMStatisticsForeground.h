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

#ifndef _OSGCSMSTATISTICSFOREGROUND_H_
#define _OSGCSMSTATISTICSFOREGROUND_H_
#ifdef __sgi
#pragma once
#endif

#include "OSGCSMStatisticsForegroundBase.h"
#include "OSGStatisticsForeground.h"

OSG_BEGIN_NAMESPACE

class CSMWindow;
class SimpleStatisticsForeground;

/*! \brief CSMStatisticsForeground class. See \ref
           PageContribCSMStatisticsForeground for a description.
*/

class OSG_CONTRIBCSM_DLLMAPPING CSMStatisticsForeground :
    public CSMStatisticsForegroundBase
{
  protected:

    /*==========================  PUBLIC  =================================*/

  public:

    typedef CSMStatisticsForegroundBase Inherited;
    typedef CSMStatisticsForeground     Self;

    /*---------------------------------------------------------------------*/
    /*! \name                      Sync                                    */
    /*! \{                                                                 */

    virtual void changed(ConstFieldMaskArg whichField,
                         UInt32            origin,
                         BitVector         details    );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    bool init(CSMWindow *pCSMWin);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */
    
    StatisticsForeground *getOSGForeground(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                     Output                                   */
    /*! \{                                                                 */

    virtual void dump(      UInt32     uiIndent = 0,
                      const BitVector  bvFlags  = 0) const;

    /*! \}                                                                 */
    /*=========================  PROTECTED  ===============================*/

  protected:

    // Variables should all be in CSMStatisticsForegroundBase.

    StatisticsForegroundUnrecPtr _pStatFG;

    /*---------------------------------------------------------------------*/
    /*! \name                  Constructors                                */
    /*! \{                                                                 */

    CSMStatisticsForeground(void);
    CSMStatisticsForeground(const CSMStatisticsForeground &source);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                   Destructors                                */
    /*! \{                                                                 */

    virtual ~CSMStatisticsForeground(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    void addElement(      SimpleStatisticsForeground *pStatFG,
                    const std::string                &szStatObj,
                    const std::string                &szStatElem,
                    const std::string                &szFormat  );

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    virtual void draw(DrawEnv *);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    virtual void resolveLinks(void);

    /*! \}                                                                 */
    /*---------------------------------------------------------------------*/
    /*! \name                      Init                                    */
    /*! \{                                                                 */

    static void initMethod(InitPhase ePhase);

    /*! \}                                                                 */
    /*==========================  PRIVATE  ================================*/

  private:

    friend class FieldContainer;
    friend class CSMStatisticsForegroundBase;

    // prohibit default functions (move to 'public' if you need one)
    void operator =(const CSMStatisticsForeground &source);
};

typedef CSMStatisticsForeground *CSMStatisticsForegroundP;

OSG_END_NAMESPACE

#include "OSGCSMStatisticsForegroundBase.inl"
#include "OSGCSMStatisticsForeground.inl"

#endif /* _OSGCSMSTATISTICSFOREGROUND_H_ */
