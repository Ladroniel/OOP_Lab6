#include <gtest/gtest.h>
#include "Observers.h"

class TestObserver : public Observer {
public:
    bool called = false;
    std::string killer, victim;

    void onKill(const std::string& k, const std::string& v) override {
        called = true;
        killer = k;
        victim = v;
    }
};

TEST(ObserverTest, ObserverIsCalled) {
    TestObserver obs;

    obs.onKill("Orc_1", "Bear_2");

    EXPECT_TRUE(obs.called);
    EXPECT_EQ(obs.killer, "Orc_1");
    EXPECT_EQ(obs.victim, "Bear_2");
}
