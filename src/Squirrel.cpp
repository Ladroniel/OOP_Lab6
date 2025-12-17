#include "../include/Squirrel.h"
#include "../include/Visitor.h"

Squirrel::Squirrel(std::string n,int x,int y):NPC(n,x,y){}

std::string Squirrel::getType()const{return "Squirrel";}

void Squirrel::accept(NPCVisitor&v,NPC&e){v.fight(*this,e);}
