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

#include "OSGPointerSFieldBase.h"

OSG_BEGIN_NAMESPACE

FieldType* PointerSFieldBase::_fieldType = 0;

void PointerSFieldBase::initFieldType() {
	if (!_fieldType) {
		_fieldType = new FieldType(
			"FieldContainerPtrSFieldBase",
			"Field",                    
			SFieldTraits::getType (),   
			FieldType::SingleField,
			FieldType::PtrField);
	}
}

// Warning: static member definition not called when compiling with emscripten
/*FieldType PointerSFieldBase::_fieldType(
    "FieldContainerPtrSFieldBase",
    "Field",                    
    SFieldTraits::getType (),   
    FieldType::SingleField,
    FieldType::PtrField);*/


const FieldType &PointerSFieldBase::getClassType(void)
{
    return *_fieldType;
}

OSG_END_NAMESPACE
