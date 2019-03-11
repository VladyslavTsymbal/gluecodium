// -------------------------------------------------------------------------------------------------
//
//
// -------------------------------------------------------------------------------------------------
//
// Automatically generated. Do not modify. Your changes will be lost.
//
// -------------------------------------------------------------------------------------------------

#pragma once

#include <cstdint>
#include <vector>

namespace examples {

class Arrays {
public:
    virtual ~Arrays() = 0;
public:
struct SyncResult {
    uint64_t last_updated_time_stamp;
    uint32_t number_of_changes;
};
using SyncResults = ::std::vector< ::examples::Arrays::SyncResult >;

public:
static ::examples::Arrays::SyncResults explicit_array_method( const ::examples::Arrays::SyncResults& input );
static ::std::vector< ::examples::Arrays::SyncResult > implicit_array_method( const ::std::vector< ::examples::Arrays::SyncResult >& input );

};

}
