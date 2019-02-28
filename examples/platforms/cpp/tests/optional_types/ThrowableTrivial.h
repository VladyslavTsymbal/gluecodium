// -------------------------------------------------------------------------------------------------
// Copyright (C) 2016-2019 HERE Europe B.V.
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

#include <initializer_list>
#include <stdexcept>
#include <string>

namespace test
{
class ThrowableTrivial
{
public:
    class Exception : std::logic_error
    {
    public:
        explicit Exception( )
            : logic_error( "Test" )
        {
        }
    };

    ThrowableTrivial( )
    {
        throw Exception( );
    }

    ThrowableTrivial( std::initializer_list< int >, std::string )
    {
        throw Exception( );
    }

    ThrowableTrivial( bool throw_exception )
    {
        if ( throw_exception )
        {
            throw Exception( );
        }
    }

    ThrowableTrivial( const ThrowableTrivial& other )
    {
        throw Exception( );
    }

    ThrowableTrivial( ThrowableTrivial&& other )
    {
        throw Exception( );
    }

    ThrowableTrivial( const ThrowableTrivial&& other )
    {
        throw Exception( );
    }

    ThrowableTrivial&
    operator=( const ThrowableTrivial& other )
    {
        throw Exception( );
    }

    ThrowableTrivial&
    operator=( ThrowableTrivial&& other )
    {
        throw Exception( );
    }

    ThrowableTrivial&
    operator=( const ThrowableTrivial&& other )
    {
        throw Exception( );
    }
};
}