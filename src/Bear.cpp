#include "../include/Bear.h"
#include "../include/Visitor.h"

Bear::Bear(std::string n,int x,int y):NPC(n,x,y){}

std::string Bear::getType()const{return "Bear";}

void Bear::accept(NPCVisitor&v,NPC&e){v.fight(*this,e);}
