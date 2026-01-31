#include <iostream>
#include "ServiceBootstrap.h"

int main(){
    std::cout<<"AI Platform starting..."<<std::endl;
    ServiceBootstrap bootstrap;
    int status=bootstrap.initialize();

    if(status!=0){
        std::cout<<"Service failed to initialize."<<std::endl;
        return 1;
    }
    std::cout<<"Service initialized successfully."<<std::endl;
    std::cout<<"Service is now running..."<<std::endl;

    while(true){
        //loop
    }
    return 0;
}
