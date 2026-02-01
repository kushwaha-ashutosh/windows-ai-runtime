#include <iostream>
#include "ServiceBootstrap.h"
#include "../InferenceRuntime/Runtime.h"
#include "../SemanticSearch/SearchEngine.h"
#include "../AgentOrchestrator/Orchestrator.h"

int main(){
    std::cout<<"AI Platform starting..."<<std::endl;

    ServiceBootstrap bootstrap;
    if(bootstrap.initialize()!=0){
        std::cout<<"Service failed to initialize."<<std::endl;
        return 1;
    }

    std::cout<<"Service initialized successfully."<<std::endl;

    Runtime runtime;
    SearchEngine search;
    Orchestrator agent;


    int runtimeResult = runtime.run("hello windows ai runtime");
    int searchResult = search.search("semantic search query");
    int agentResult = agent.executeTask("summarize search results");

    std::cout << "Runtime result: " << runtimeResult << std::endl;
    std::cout << "Search result: " << searchResult << std::endl;
    std::cout << "Agent result: " << agentResult << std::endl;

    std::cout << "Service is now running..." << std::endl;


    while(true){
        //loop
    }

    return 0;
}
