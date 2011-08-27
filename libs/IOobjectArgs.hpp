#ifndef IOobjectArgs_hpp
#define IOobjectArgs_hpp


//---------------------------------------------------------------------------
#include "universalArgs.hpp"
#include "universalHolder.hpp"

#include <IOobject.H>
#include <objectRegistry.H>
#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  class IOobjectArgs
    : public universalArgs
  {
  protected:
    IOobjectArgs( const universalHolder* );
    IOobjectArgs();

  };
} // Foam


//---------------------------------------------------------------------------
#endif
