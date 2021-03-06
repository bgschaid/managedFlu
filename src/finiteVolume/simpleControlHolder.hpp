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
#include "common.hpp"
#if FOAM_VERSION( <, 020000 )
#define simpleControlHolder_hpp
#endif


//---------------------------------------------------------------------------
#ifndef simpleControlHolder_hpp
#define simpleControlHolder_hpp


//---------------------------------------------------------------------------
#include "DependentHolder.hpp"
#include "Deps.hpp"
#include "fvMeshHolder.hpp"

#include <simpleControl.H>
#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  
  class simpleControlHolder 
    : virtual public DependentHolder
    , public boost::shared_ptr< simpleControl >
  {
  public:
    simpleControlHolder( fvMeshHolder& mesh );
    ~simpleControlHolder();
    
    virtual SimpleHolder* clone() const;
    
    using  boost::shared_ptr< simpleControl >::operator*;
    using  boost::shared_ptr< simpleControl >::operator->;

  private:
    simpleControlHolder(); // not implemented
    //simpleControlHolder( const simpleControlHolder& ); // not implemented
    void operator=( const simpleControlHolder& ); // not implemented

  };
} // Foam


//---------------------------------------------------------------------------
#endif
