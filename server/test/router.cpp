//
// Created by Chaz on 8/14/2017.
//

#define BOOST_TEST_MODULE "Router"
#include "../router.h"
#include <boost/test/unit_test.hpp>

using namespace std::string_literals;

BOOST_AUTO_TEST_SUITE(utility_test_suite)

    BOOST_AUTO_TEST_SUITE(router_test_suite)
        BOOST_AUTO_TEST_CASE(router_add_constant_string)
        {
            api::router r;
            r.add_route<>("/test/path"s);
        }

        BOOST_AUTO_TEST_CASE(router_add_only_params)
        {
            api::router r;
            r.add_route<std::string, int>("/<string>/<int>"s);
        }

        BOOST_AUTO_TEST_CASE(router_add_const_and_params)
        {
            api::router r;
            r.add_route<int>("/character/get/<int>");
        }
    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
