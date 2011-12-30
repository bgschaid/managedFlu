//  managedFlu - OpenFOAM C++ interactive functionality API
//  Copyright (C) 2011- Alexey Petrov
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
//  Author : Alexey PETROV, Andrey Simurzin


//---------------------------------------------------------------------------
#include "basicSourceListHolder.hpp"

//---------------------------------------------------------------------------
namespace Foam
{

  basicSourceListHolder::basicSourceListHolder( const fvMeshHolder& mesh, const dictionaryHolder& dict ) 
    : DependentHolder( Deps( &mesh, &dict ) )
    , boost::shared_ptr< basicSourceList >( new basicSourceList( *mesh, *dict ) )
  {}

  basicSourceListHolder::basicSourceListHolder() 
    : DependentHolder()
    , boost::shared_ptr< basicSourceList >()
  {}
  
  SimpleHolder* basicSourceListHolder::clone() const 
  {
    return new basicSourceListHolder( *this );
  }
  
  basicSourceListHolder::~basicSourceListHolder()
  {}

  void basicSourceListHolder::operator=( const boost::shared_ptr< basicSourceList >&  source )
  {
    boost::shared_ptr< basicSourceList >::operator=( source );
  }
  
  void basicSourceListHolder::operator()( const basicSourceListHolder& listHolder )
  {
    this->operator=( listHolder );
  }


}


//---------------------------------------------------------------------------
