#include "../include/NPC.h"

NPC::NPC(std::string n,int xx,int yy):name(n),x(xx),y(yy){}

std::string NPC::getName()const{return name;}

int NPC::getX()const{return x;}
int NPC::getY()const{return y;}
