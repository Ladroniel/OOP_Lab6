#include <gtest/gtest.h>
#include "Factory.h"
#include "Visitor.h"

TEST(FightTest, OrcKillsBear) {
    auto orc  = NPC_Factory::create("Orc", "o", 0, 0);
    auto bear = NPC_Factory::create("Bear", "b", 0, 0);

    FightVisitor v;
    EXPECT_TRUE(v.fight(*orc, *bear));
}

TEST(FightTest, BearDoesNotKillOrc) {
    auto orc  = NPC_Factory::create("Orc", "o", 0, 0);
    auto bear = NPC_Factory::create("Bear", "b", 0, 0);

    FightVisitor v;
    EXPECT_FALSE(v.fight(*bear, *orc));
}

TEST(FightTest, BearKillsSquirrel) {
    auto bear = NPC_Factory::create("Bear", "b", 0, 0);
    auto sq   = NPC_Factory::create("Squirrel", "s", 0, 0);

    FightVisitor v;
    EXPECT_TRUE(v.fight(*bear, *sq));
}

TEST(FightTest, SquirrelKillsNobody) {
    auto sq  = NPC_Factory::create("Squirrel", "s", 0, 0);
    auto orc = NPC_Factory::create("Orc", "o", 0, 0);

    FightVisitor v;
    EXPECT_FALSE(v.fight(*sq, *orc));
}
