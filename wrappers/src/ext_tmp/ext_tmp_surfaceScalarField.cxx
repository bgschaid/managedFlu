//  pythonFlu - Python wrapping for OpenFOAM C++ API
//  Copyright (C) 2010- Alexey Petrov
//  Copyright (C) 2009-2010 Pebble Bed Modular Reactor (Pty) Limited (PBMR)
// 
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
// 
//  See http://sourceforge.net/projects/pythonflu
//
//  Author : Alexey PETROV


//---------------------------------------------------------------------------
#ifndef ext_tmp_surfaceScalarField_cxx
#define ext_tmp_surfaceScalarField_cxx


//---------------------------------------------------------------------------
%module "wrappers.src.ext_tmp.ext_tmp_surfaceScalarField";
%{
  #include "ext_tmp/ext_tmp_surfaceScalarField.hh"
%}


//---------------------------------------------------------------------------
//%import "ext_tmp/ext_tmp.hxx"

%import "Foam/src/finiteVolume/fvMesh/fvMeshes.cxx"


//---------------------------------------------------------------------------
%template ( ext_tmp_surfaceScalarField ) Foam::ext_tmp< Foam::surfaceScalarField >;

%extend Foam::ext_tmp< Foam::surfaceScalarField >
{
  SMARTPTR_EXTEND_OPERATOR_EQ( Foam::scalar );
}


//---------------------------------------------------------------------------
SCALAR_EXT_TMP_GEOMETRIC_FIELD_TEMPLATE_FUNC( Foam::surfaceScalarField, Foam::fvsPatchField, Foam::surfaceMesh );


//---------------------------------------------------------------------------
#endif
