#include "Telemetry.h"
#include <iostream>

void Telemetry::log(const std::string& message){
    std::cout<<"[Telemetry]"<<message<<std::endl;
}
