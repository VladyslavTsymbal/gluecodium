// -------------------------------------------------------------------------------------------------
//
//
// -------------------------------------------------------------------------------------------------
//
// Automatically generated. Do not modify. Your changes will be lost.
//
// -------------------------------------------------------------------------------------------------

#pragma once

#include "examples/Structs.h"
#include <cstdint>

namespace examples {

class StructsInheritance {
public:
    virtual ~StructsInheritance() = 0;

public:
struct SyncResultInherited: public ::examples::Structs::SyncResult {
    int32_t id;

    SyncResultInherited( );
    SyncResultInherited( const uint64_t last_updated_time_stamp, const uint32_t number_of_changes, const int32_t id );
};

public:
virtual ::examples::StructsInheritance::SyncResultInherited method_with_inherited_type( const ::examples::StructsInheritance::SyncResultInherited& input ) = 0;

};

}