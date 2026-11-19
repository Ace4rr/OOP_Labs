#include "lab_02/string.hpp"

#include <gtest/gtest.h>
#include <sstream>

TEST(StringTest, DefaultConstructor) {
    String s;
    EXPECT_EQ(s.size(), 0);
    EXPECT_GE(s.capacity(), 1);
    EXPECT_STREQ(s.c_str(), "");
}

TEST(StringTest, CStringConstructor) {
    String s("hello");
    EXPECT_EQ(s.size(), 5);
    EXPECT_STREQ(s.c_str(), "hello");
}

TEST(StringTest, NullptrConstructor) {
    String s(nullptr);
    EXPECT_EQ(s.size(), 0);
    EXPECT_STREQ(s.c_str(), "");
}

TEST(StringTest, CopyConstructor) {
    String original("hello");
    String copy(original);

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_STREQ(copy.c_str(), "hello");
}

TEST(StringTest, MoveConstructor) {
    String a("hello");
    String b(std::move(a));

    EXPECT_STREQ(b.c_str(), "hello");
    EXPECT_EQ(a.size(), 0);
    EXPECT_STREQ(a.c_str(), "");
}

TEST(StringTest, CopyAssignment) {
    String a("first");
    String b("second");
    b = a;

    EXPECT_STREQ(b.c_str(), "first");
    EXPECT_STREQ(a.c_str(), "first");
}

TEST(StringTest, SelfAssignment) {
    String a("hello");
    a = a;

    EXPECT_STREQ(a.c_str(), "hello");
    EXPECT_EQ(a.size(), 5);
}

TEST(StringTest, MoveAssignment) {
    String a("hello");
    String b;
    b = std::move(a);

    EXPECT_STREQ(b.c_str(), "hello");
    EXPECT_EQ(a.size(), 0);
    EXPECT_STREQ(a.c_str(), "");
}

TEST(StringTest, PushBackAndGrowth) {
    String s;
    s.push_back('a');
    s.push_back('b');
    s.push_back('c');

    EXPECT_EQ(s.size(), 3);
    EXPECT_STREQ(s.c_str(), "abc");
}

TEST(StringTest, AppendAndPrint) {
    String s("Hello");
    s.append(", World!");

    EXPECT_STREQ(s.c_str(), "Hello, World!");

    std::ostringstream oss;
    s.print(oss);
    EXPECT_EQ(oss.str(), "Hello, World!");
}

TEST(StringTest, FindSubstring) {
    String s("Hello, World!");

    EXPECT_EQ(s.find("World"), 7);
    EXPECT_EQ(s.find("not_found"), static_cast<std::size_t>(-1));
}

TEST(StringVariantTest, CountOccurrencesBasic) {
    String str("ababab");
    String sub("ab");
    EXPECT_EQ(str.count_occurrences(sub), 3);
}

TEST(StringVariantTest, CountOccurrencesNonOverlapping) {
    String str("abababa");
    String sub("aba");
    EXPECT_EQ(str.count_occurrences(sub), 2);
}

TEST(StringVariantTest, CountOccurrencesEdgeCases) {
    String str("hello");
    String empty_sub("");
    String long_sub("hello world");

    EXPECT_EQ(str.count_occurrences(empty_sub), 0);
    EXPECT_EQ(str.count_occurrences(long_sub), 0);
    EXPECT_EQ(str.count_occurrences(String("x")), 0);
}
