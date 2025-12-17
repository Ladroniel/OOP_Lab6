#include "../include/Visitor.h"

bool FightVisitor::fight(NPC&a,NPC&b){
	std::string A=a.getType(),B=b.getType();
	if(A=="Orc"&&(B=="Orc"||B=="Bear"))return true;
	if(A=="Bear"&&B=="Squirrel")return true;
	return false;
}
