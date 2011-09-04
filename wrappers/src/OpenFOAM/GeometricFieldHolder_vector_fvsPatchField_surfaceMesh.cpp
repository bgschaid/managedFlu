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
#ifndef GeometricFieldHolder_vector_fvsPatchField_surfaceMesh_cxx
#define GeometricFieldHolder_vector_fvsPatchField_surfaceMesh_cxx


//---------------------------------------------------------------------------
%{
  #include "wrappers/src/OpenFOAM/GeometricFieldHolder_vector_fvsPatchField_surfaceMesh.hh"
%}


//---------------------------------------------------------------------------
%import "wrappers/src/smart_tmp/smart_tmp_surfaceVectorField.cxx"

%include "wrappers/src/OpenFOAM/GeometricFieldHolder.hxx"

%include "surfaceFields.hpp"

%template ( GeometricFieldHolder_vector_fvsPatchField_surfaceMesh ) Foam::GeometricFieldHolder< Foam::vector, Foam::fvsPatchField, Foam::surfaceMesh >;

EXTEND_SURFACEVECTORFIELDHOLDER;


//---------------------------------------------------------------------------
%feature( "pythonappend" ) Foam::GeometricFieldHolder< Foam::vector, Foam::fvsPatchField, Foam::surfaceMesh >::SMARTPTR_PYAPPEND_GETATTR( GeometricFieldHolder_vector_fvsPatchField_surfaceMesh );

%extend Foam::GeometricFieldHolder< Foam::vector, Foam::fvsPatchField, Foam::surfaceMesh >
{
  SMARTPTR_EXTEND_ATTR( GeometricFieldHolder_vector_fvsPatchField_surfaceMesh );
}



//--------------------------------------------------------------------------------------
#endif
