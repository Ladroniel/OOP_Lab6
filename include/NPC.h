#pragma once
#include <string>
class NPCVisitor;

class NPC {
protected:
    std::string name;
    int x, y;
public:
    NPC(std::string n, int xx, int yy);
    virtual ~NPC() = default;
    virtual std::string getType() const = 0;
    virtual void accept(NPCVisitor &v, NPC &enemy) = 0;
    std::string getName() const;
    int getX() const;
    int getY() const;
};
