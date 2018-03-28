// Copyright (c) 2017 LiuLang. All rights reserved.
// Use of this source is governed by General Public License that can be found
// in the LICENSE file.

#include "base/string_util.h"
#include "third_party/gtest/include/gtest/gtest.h"

namespace bcloud {
namespace {

TEST(StringUtilTest, EncodeUri) {
  EXPECT_EQ(EncodeUri("Hello+World"), "Hello+World");
  EXPECT_EQ(EncodeUri("Hello World"), "Hello%20World");
}

TEST(StringUtilTest, EncodeUriComponent) {
  EXPECT_EQ(EncodeUriComponent("Hello+World"), "Hello%2BWorld");
  EXPECT_EQ(EncodeUriComponent("http://www.z.cn"), "http%3A%2F%2Fwww.z.cn");
}

}  // namespace
}  // namespace bcloud