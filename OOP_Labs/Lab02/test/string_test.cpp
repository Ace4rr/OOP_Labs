#include <gtest/gtest.h>
#include "lab_02/string.hpp"

TEST(StringTest, DefaultConstructor) {
    String s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_STREQ(s.c_str(), "");
}

TEST(StringTest, RuleOfFiveCopyAndMove) {
    String a("hello");
    String b = a;
    EXPECT_STREQ(b.c_str(), "hello");

    String c = std::move(a);
    EXPECT_STREQ(c.c_str(), "hello");
    EXPECT_STREQ(a.c_str(), "");
}

TEST(StringVariantTest, CountOccurrencesBasic) {
    String str("ababab");
    String sub("ab");
    EXPECT_EQ(str.count_occurences(sub), 3);
}

TEST(StringVariantTest, CountOccurrencesNonOverlapping) {
    String str("abababa");
    String sub("aba");
    EXPECT_EQ(str.count_occurences(sub), 2);
}

TEST(StringVariantTest, CountOccurrencesEdgeCases) {
    String str("hello");
    String empty_sub("");
    String long_sub("hello world");

    EXPECT_EQ(str.count_occurences(empty_sub), 0);
    EXPECT_EQ(str.count_occurences(long_sub), 0);
}
