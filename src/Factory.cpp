#include "../include/Factory.h"
#include "../include/Orc.h"
#include "../include/Bear.h"
#include "../include/Squirrel.h"
std::shared_ptr<NPC>NPC_Factory::create(const std::string&t,const std::string&n,int x,int y){
	if(t=="Orc")return std::make_shared<Orc>(n,x,y);
	if(t=="Bear")return std::make_shared<Bear>(n,x,y);
	if(t=="Squirrel")return std::make_shared<Squirrel>(n,x,y);
	return nullptr;
}
