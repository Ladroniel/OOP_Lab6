#pragma once
#include <string>
class Observer{public:virtual void onKill(const std::string&,const std::string&)=0;};
class ConsoleObserver:public Observer{public:void onKill(const std::string&,const std::string&)override;};
class FileObserver:public Observer{public:void onKill(const std::string&,const std::string&)override;};