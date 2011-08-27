//---------------------------------------------------------------------------
#include "turbulenceModelHolder.hpp"


//---------------------------------------------------------------------------
namespace Foam
{
namespace compressible
{
  turbulenceModelHolder::turbulenceModelHolder( 
    const boost::shared_ptr< turbulenceModel >& tm, 
    const volScalarFieldHolder& rho, 
    const volVectorFieldHolder& U,  
    const surfaceScalarFieldHolder& phi, 
    const basicThermoHolder& thermo )
    : turbulenceModelArgs( &rho, &U, &phi, &thermo )
    , boost::shared_ptr< turbulenceModel >( tm )
    , universalHolder()
  {}

  turbulenceModelHolder::turbulenceModelHolder()
    : turbulenceModelArgs()
    , boost::shared_ptr< turbulenceModel >()
    , universalHolder()
  {
#ifdef OUR_DEBUG
    cout << "~turbulenceModelHolder = " << this << nl;
#endif
  }

  universalHolder* turbulenceModelHolder::clone() const
  {
    return new turbulenceModelHolder( *this );
  }

  turbulenceModelHolder::~turbulenceModelHolder()
  {
#ifdef OUR_DEBUG
    cout << "~turbulenceModelHolder = " << this << nl;
#endif
  }
}//compressible
}//Foam

//---------------------------------------------------------------------------
