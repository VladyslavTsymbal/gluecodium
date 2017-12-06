// -------------------------------------------------------------------------------------------------
//
// Copyright (C) 2017 HERE Global B.V. and/or its affiliated companies. All rights reserved.
//
// This software, including documentation, is protected by copyright controlled by
// HERE Global B.V. All rights are reserved. Copying, including reproducing, storing,
// adapting or translating, any or all of this material requires the prior written
// consent of HERE Global B.V. This material also contains confidential information,
// which may not be disclosed to others without prior written consent of HERE Global B.V.
//
// -------------------------------------------------------------------------------------------------
//
// Automatically generated. Do not modify. Your changes will be lost.
//
// -------------------------------------------------------------------------------------------------

#pragma once

#include <cstdint>


namespace smoke {

struct Point {
    double x = 0;
    double y = 0;
};
using PointTypeDef = ::smoke::Point;

using StorageId = uint64_t;
static const ::smoke::StorageId INVALID_STORAGE_ID = 0;

struct StructHavingAliasFieldDefinedBelow {
    ::smoke::StorageId field;
};
}
