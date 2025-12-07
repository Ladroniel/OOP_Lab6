#pragma once
#include <memory>
#include "NPC.h"
class NPC_Factory{
public:static std::shared_ptr<NPC>create(const std::string&,const std::string&,int,int);
};