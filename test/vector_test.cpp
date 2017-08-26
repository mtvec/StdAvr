#include "gmock/gmock.h"

#include "sut/vector"

using namespace testing;

namespace
{

using some_type = int;

const sut::size_t some_size = 5;
const some_type some_value = 42;

}

TEST(a_vector, has_size_zero_when_default_constructed)
{
    auto vec = sut::vector<some_type>();

    ASSERT_THAT(vec.size(), Eq(0u));
}

TEST(a_vector, has_the_given_size_when_constructed)
{
    auto vec = sut::vector<some_type>(some_size, some_value);

    ASSERT_THAT(vec.size(), Eq(some_size));
}

TEST(a_vector, contains_only_elements_equal_to_the_given_value)
{
    auto vec = sut::vector<some_type>(3, some_value);

    ASSERT_THAT(vec, ElementsAreArray({some_value, some_value, some_value}));
}