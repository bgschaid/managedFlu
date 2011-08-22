#ifndef basicPsiThermoHolder_hpp
#define basicPsiThermoHolder_hpp


//---------------------------------------------------------------------------
#include "basicThermoArgs.hpp"
#include "basicThermoHolder.hpp"
#include "fvMeshHolder.hpp"

#include <basicPsiThermo.H>
#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  
  class basicPsiThermoHolder 
    : public basicThermoArgs
    , public boost::shared_ptr< basicPsiThermo >
    , public basicThermoHolder
  {
  public:
    basicPsiThermoHolder( const boost::shared_ptr< basicPsiThermo >&, const fvMeshHolder& );
    ~basicPsiThermoHolder();

    static basicPsiThermoHolder New( const fvMeshHolder& );
    
    using  boost::shared_ptr< basicPsiThermo >::operator*;
    using  boost::shared_ptr< basicPsiThermo >::operator->;
    using  basicThermoArgs::mesh;
  private:
    basicPsiThermoHolder(); // not implemented
    //basicPsiThermoHolder( const basicPsiThermoHolder& ); // not implemented
    void operator=( const basicPsiThermoHolder& ); // not implemented

  };
} // Foam


//---------------------------------------------------------------------------
#endif