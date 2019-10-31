// -------------------------------------------------------------------------------------------------
//
//
// -------------------------------------------------------------------------------------------------
#pragma once
#include "gluecodium/Export.h"
#include "gluecodium/VectorHash.h"
#include <cstdint>
#include <vector>
namespace examples {
class _GLUECODIUM_CPP_EXPORT Arrays {
public:
    Arrays();
    virtual ~Arrays() = 0;
public:
    struct _GLUECODIUM_CPP_EXPORT SyncResult {
        uint64_t last_updated_time_stamp;
        uint32_t number_of_changes;
        SyncResult( );
        SyncResult( const uint64_t last_updated_time_stamp, const uint32_t number_of_changes );
    };
    using SyncResults = ::std::vector< ::examples::Arrays::SyncResult >;
public:
    static ::examples::Arrays::SyncResults explicit_array_method( const ::examples::Arrays::SyncResults& input );
    static ::std::vector< ::examples::Arrays::SyncResult > implicit_array_method( const ::std::vector< ::examples::Arrays::SyncResult >& input );
};
}