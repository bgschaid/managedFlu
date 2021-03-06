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
#include "twoPhaseMixtureHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{
  
  twoPhaseMixtureHolder::twoPhaseMixtureHolder( const volVectorFieldHolder& U, 
                                                const surfaceScalarFieldHolder& phi,
                                                const word& alpha1Name )
    : DependentHolder( Deps( &U, &phi ) )
    , boost::shared_ptr< twoPhaseMixture >( new twoPhaseMixture( U(), phi(), alpha1Name ) )
  {
    transportModelHolder::operator=( boost::shared_ptr< twoPhaseMixture >( *this ) );
  }
    
  twoPhaseMixtureHolder::twoPhaseMixtureHolder() 
    : transportModelHolder()
    , boost::shared_ptr< twoPhaseMixture >()
  {}

  void twoPhaseMixtureHolder::operator=( const boost::shared_ptr< twoPhaseMixture >& bt ) 
  {
    boost::shared_ptr< twoPhaseMixture >::operator=( bt );
    transportModelHolder::operator=( bt );
  }

  SimpleHolder* twoPhaseMixtureHolder::clone() const
  {
    return new twoPhaseMixtureHolder( *this );
  }
  
  void twoPhaseMixtureHolder::operator()( const twoPhaseMixtureHolder& model )
  {
    this->operator=( model );
  }
  
  twoPhaseMixtureHolder::~twoPhaseMixtureHolder()
  {}
}


//---------------------------------------------------------------------------
