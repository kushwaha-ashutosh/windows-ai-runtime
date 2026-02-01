#include <iostream>
#include "ServiceBootstrap.h"
#include "../InferenceRuntime/Runtime.h"
#include "../SemanticSearch/SearchEngine.h"

int main(){
    std::cout<<"AI Platform starting..."<<std::endl;

    ServiceBootstrap bootstrap;
    if(bootstrap.initialize()!=0){
        std::cout<<"Service failed to initialize."<<std::endl;
        return 1;
    }

    std::cout<<"Service initialized successfully."<<std::endl;

    Runtime runtime;
    int result = runtime.run("hello ai platform");

    SearchEngine search;
    int searchResult = search.search("semantic search query");


    std::cout<<"Runtime result:"<< result<<std::endl;
    std::cout << "Search result: " << searchResult << std::endl;
    std::cout<<"Service is now running..."<<std::endl;


    while(true){
        //loop
    }

    return 0;
}
