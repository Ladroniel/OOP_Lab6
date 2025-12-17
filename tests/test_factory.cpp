#include <gtest/gtest.h>
#include "Factory.h"

TEST(FactoryTest, CreateOrc) {
    auto npc = NPC_Factory::create("Orc", "orc1", 10, 20);

    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->getType(), "Orc");
    EXPECT_EQ(npc->getName(), "orc1");
    EXPECT_EQ(npc->getX(), 10);
    EXPECT_EQ(npc->getY(), 20);
}

TEST(FactoryTest, CreateBear) {
    auto npc = NPC_Factory::create("Bear", "bear", 1, 2);

    ASSERT_NE(npc, nullptr);
    EXPECT_EQ(npc->getType(), "Bear");
}
