#include "../include/Observers.h"
#include <iostream>
#include <fstream>

void ConsoleObserver::onKill(const std::string&k,const std::string&v){
	std::cout<<k<<" убил "<<v<<std::endl;
}
void FileObserver::onKill(const std::string&k,const std::string&v){
	std::ofstream("log.txt",std::ios::app)<<k<<" убил "<<v<<"\n";
}
