// test/kernel/basis/test_level.cpp

#include <gtest/gtest.h>
#include <variant>

#include <Machinish/kernel/basis/level.h>

using namespace Machinish::Kernel::Universe;

TEST(LevelTests, Zero) {
    Level l = zero();
    EXPECT_TRUE(std::holds_alternative<Zero>(l));
}

TEST(LevelTests, Succ) {
    Level base = zero();
    Level l = succ(base);
    EXPECT_TRUE(std::holds_alternative<Succ>(l));
    auto& s = std::get<Succ>(l);
    EXPECT_TRUE(s.pred != nullptr);
    EXPECT_TRUE(std::holds_alternative<Zero>(*s.pred));
}

TEST(LevelTests, Max) {
    Level a = zero();
    Level b = succ(a);
    Level m = max(a, b);
    EXPECT_TRUE(std::holds_alternative<Max>(m));
    auto& mm = std::get<Max>(m);
    EXPECT_TRUE(std::holds_alternative<Zero>(*mm.l1));
    EXPECT_TRUE(std::holds_alternative<Succ>(*mm.l2));
}
