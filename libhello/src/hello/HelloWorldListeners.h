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

#pragma once

#include "hello/Calculator.h"

#include <mutex>
#include <vector>

namespace hello
{
class HelloCalculatorListener : public CalculatorListener
{
public:
    HelloCalculatorListener( ) = default;
    ~HelloCalculatorListener( ) = default;

public:
    /**
     * The method to call on the listener when the calculation is done
     */
    void onCalculationResult( const double calculationResult ) override;

    /**
     * The method to call on the listener when the background calculation
     * is done
     */
    void onCalculationInBackgroundResult( const double calculationResult ) override;
};

class HelloCalculator : public Calculator
{
public:
    HelloCalculator( ) = default;
    ~HelloCalculator( ) = default;

    /**
     * register listener to calculateInBackground results notifications
     */
    void registerListener(
        const ::std::shared_ptr< ::hello::CalculatorListener >& listener ) override;

    /**
     * unregister listener to calculateInBackground results notifications
     */
    void unregisterListener(
        const ::std::shared_ptr< ::hello::CalculatorListener >& listener ) override;

    /**
     * Compute the Euclidean distance between two positions.
     *     It is guaranteed that listener will be called before method returns
     */
    void calculate( const ::hello::Calculator::Position& fromPosition,
                    const ::hello::Calculator::Position& toPosition,
                    const ::std::shared_ptr< ::hello::CalculatorListener >& listener ) override;

    /**
     * start computing the Euclidean distance between two positions and notify the registered
     *     listeners when it is done
     */
    void calculateInBackground( const ::hello::Calculator::Position& fromPosition,
                                const ::hello::Calculator::Position& toPosition ) override;

private:
    ::std::vector< ::std::shared_ptr< ::hello::CalculatorListener > > m_listeners;
    ::std::mutex m_listeners_mutex;
};
}
