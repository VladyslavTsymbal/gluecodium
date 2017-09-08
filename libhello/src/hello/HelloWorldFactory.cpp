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

#include "hello/HelloWorldFactory.h"

#include "HelloWorldInstances.h"

namespace hello
{

::std::shared_ptr< ::hello::SimpleInstantiable >
createSimple( )
{
    return ::std::make_shared< ::hello::HelloWorldSimpleInstantiable >( );
}

::std::shared_ptr< ::hello::NestedInstantiable >
createNested( const ::std::shared_ptr< ::hello::SimpleInstantiable >& simpleInstanceRef )
{
    return ::std::make_shared< ::hello::HelloWorldNestedInstantiable >( simpleInstanceRef );
}
}
