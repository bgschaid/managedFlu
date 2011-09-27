#ifndef fvMeshHolder_hpp
#define fvMeshHolder_hpp


//---------------------------------------------------------------------------
#include "DependentHolder.hpp"
#include "Deps.hpp"
#include "objectRegistryHolder.hpp"
#include "volFieldsFwd.hpp"
#include "surfaceFieldsFwd.hpp"

#include <fvMesh.H>
#include <boost/shared_ptr.hpp>


//---------------------------------------------------------------------------
namespace Foam
{
  class IOobjectHolder;
  
  class fvMeshHolder 
    : public objectRegistryHolder
    , public boost::shared_ptr< fvMesh >
  {
  public:
    fvMeshHolder( const IOobjectHolder& io );
    
    fvMeshHolder( fvMesh*, const Deps& );
    //fvMeshHolder( const fvMesh*, const Deps& );
    
    virtual SimpleHolder* clone() const;
    
    fvMeshHolder();
    ~fvMeshHolder();

    using boost::shared_ptr< fvMesh >::operator*;
    using boost::shared_ptr< fvMesh >::operator->;
    using boost::shared_ptr< fvMesh >::get;

  };
} // Foam


//---------------------------------------------------------------------------
#endif
