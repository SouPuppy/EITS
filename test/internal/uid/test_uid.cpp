// test/internal/uid/test_uid.cpp

#include "internal/uid/uid.h"
#include <gtest/gtest.h>
#include <set>

using namespace EITS::Internal;

TEST(UIDGeneratorTest, MonotonicIncrease) {
    UIDGenerator gen(1);
    uint64_t prev = gen.next();
    for (int i = 0; i < 1000; ++i) {
        uint64_t next = gen.next();
        EXPECT_GT(next, prev);
        prev = next;
    }
}

TEST(UIDGeneratorTest, NoDuplicates) {
    UIDGenerator gen(2);
    std::set<uint64_t> ids;
    for (int i = 0; i < 4096; ++i) {
        auto id = gen.next();
        EXPECT_TRUE(ids.insert(id).second);
    }
}

TEST(UIDGeneratorTest, MachineIDEncoding) {
    UIDGenerator gen(0x123); // binary: 0001 0010 0011
    uint64_t id = gen.next();
    uint64_t encoded = (id >> 12) & 0x3FF;
    EXPECT_EQ(encoded, 0x123 & 0x3FF);
}
