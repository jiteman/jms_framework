/*
 * Copyright (c) 2014 Eran Pe'er.
 *
 * This program is made available under the terms of the MIT License.
 *
 * Created on Mar 10, 2014
 */
#pragma once

#include "MethodMockingContext.hpp"

#include <functional>


namespace fakeit {


    template<typename R, typename ... arglist>
    class MockingContext :
            public MethodMockingContext<R, arglist...> {
        MockingContext &operator=(const MockingContext &) = delete;

    public:

        MockingContext(typename MethodMockingContext<R, arglist...>::Context *stubbingContext)
                : MethodMockingContext<R, arglist...>(stubbingContext) {
        }

        MockingContext(MockingContext &) = default;

        MockingContext(MockingContext &&other)
                : MethodMockingContext<R, arglist...>(std::move(other)) {
        }

        MockingContext<R, arglist...> &setMethodDetails(std::string mockName, std::string methodName) {
            MethodMockingContext<R, arglist...>::setMethodDetails(mockName, methodName);
            return *this;
        }

        MockingContext<R, arglist...> &Using(const arglist &... args) {
            MethodMockingContext<R, arglist...>::setMatchingCriteria(args...);
            return *this;
        }

        template<class ...arg_matcher>
        MockingContext<R, arglist...> &Using(const arg_matcher &... arg_matchers) {
            MethodMockingContext<R, arglist...>::setMatchingCriteria(arg_matchers...);
            return *this;
        }

        MockingContext<R, arglist...> &Matching(std::function<bool(arglist &...)> matcher) {
            MethodMockingContext<R, arglist...>::setMatchingCriteria(matcher);
            return *this;
        }

        MockingContext<R, arglist...> &operator()(const arglist &... args) {
            MethodMockingContext<R, arglist...>::setMatchingCriteria(args...);
            return *this;
        }

        MockingContext<R, arglist...> &operator()(std::function<bool(arglist &...)> matcher) {
            MethodMockingContext<R, arglist...>::setMatchingCriteria(matcher);
            return *this;
        }

        void operator=(std::function<R(arglist &...)> method) {
            MethodMockingContext<R, arglist...>::setMethodBodyByAssignment(method);
        }

        template<typename U = R>
        typename std::enable_if<!std::is_reference<U>::value, void>::type operator=(const R &r) {
            auto method = [r](const typename fakeit::test_arg<arglist>::type...) -> R { return r; };
            MethodMockingContext<R, arglist...>::setMethodBodyByAssignment(method);
        }

        template<typename U = R>
        typename std::enable_if<std::is_reference<U>::value, void>::type operator=(const R &r) {
            auto method = [&r](const typename fakeit::test_arg<arglist>::type...) -> R { return r; };
            MethodMockingContext<R, arglist...>::setMethodBodyByAssignment(method);
        }
    };

    template<typename ... arglist>
    class MockingContext<void, arglist...> :
            public MethodMockingContext<void, arglist...> {
        MockingContext &operator=(const MockingContext &) = delete;

    public:

        MockingContext(typename MethodMockingContext<void, arglist...>::Context *stubbingContext)
                : MethodMockingContext<void, arglist...>(stubbingContext) {
        }

        MockingContext(MockingContext &) = default;

        MockingContext(MockingContext &&other)
                : MethodMockingContext<void, arglist...>(std::move(other)) {
        }

        MockingContext<void, arglist...> &setMethodDetails(std::string mockName, std::string methodName) {
            MethodMockingContext<void, arglist...>::setMethodDetails(mockName, methodName);
            return *this;
        }

        MockingContext<void, arglist...> &Using(const arglist &... args) {
            MethodMockingContext<void, arglist...>::setMatchingCriteria(args...);
            return *this;
        }

        template<class ...arg_matcher>
        MockingContext<void, arglist...> &Using(const arg_matcher &... arg_matchers) {
            MethodMockingContext<void, arglist...>::setMatchingCriteria(arg_matchers...);
            return *this;
        }

        MockingContext<void, arglist...> &Matching(std::function<bool(arglist &...)> matcher) {
            MethodMockingContext<void, arglist...>::setMatchingCriteria(matcher);
            return *this;
        }

        MockingContext<void, arglist...> &operator()(const arglist &... args) {
            MethodMockingContext<void, arglist...>::setMatchingCriteria(args...);
            return *this;
        }

        MockingContext<void, arglist...> &operator()(std::function<bool(arglist &...)> matcher) {
            MethodMockingContext<void, arglist...>::setMatchingCriteria(matcher);
            return *this;
        }

        void operator=(std::function<void(arglist &...)> method) {
            MethodMockingContext<void, arglist...>::setMethodBodyByAssignment(method);
        }

    };

 }
