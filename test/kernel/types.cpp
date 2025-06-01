// test/kernel/types.cpp

#include <string>

#include <gtest/gtest.h>

#include <Machinish/kernel/type.h>

using namespace Machinish;

struct DummyType : Type_Base {
	std::string value;
	explicit DummyType(const std::string& v) : value(v) {}

	std::string to_string() const override {
		return "DummyType: " + value;
	}
};

TEST(TypeTest, ToStringWorks) {
	DummyType dummy("test_value");
	EXPECT_EQ(dummy.to_string(), "DummyType: test_value");
}
