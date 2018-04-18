// -------------------------------------------------------------------------------------------------
// Copyright (C) 2016-2018 HERE Europe B.V.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0
// License-Filename: LICENSE
//
// -------------------------------------------------------------------------------------------------

#pragma once

#include <string>
#include <vector>

namespace external
{
namespace even_more_external
{
struct AlienStructure
{
   int32_t int_field;
};
}

class ExternalStruct
{
public:
    std::string get_some_string( ) const;
    void set_some_string( const std::string& value );
    std::vector< int32_t > getSomeArray( ) const;
    void setSomeArray( const std::vector< int32_t >& value );
    even_more_external::AlienStructure madnessEnsues( ) const;
    void madnessEnsues( const even_more_external::AlienStructure& value );

public:
    std::string string_field;

private:
    std::string m_some_string;
    std::vector< int32_t > m_some_array;
    even_more_external::AlienStructure m_some_struct;
};

}
