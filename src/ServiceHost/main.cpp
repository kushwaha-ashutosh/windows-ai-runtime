#include <iostream>
#include "ServiceBootstrap.h"
#include "../InferenceRuntime/Runtime.h"
#include "../SemanticSearch/SearchEngine.h"
#include "../AgentOrchestrator/Orchestrator.h"
#include "../Telemetry/Telemetry.h"

int main(){

    Telemetry::log("AI Runtime starting...");

    ServiceBootstrap bootstrap;
    if(bootstrap.initialize()!=0){
        Telemetry::log("Service failed to initialize.");
        return 1;
    }

    Telemetry::log("Service initialized successfully.");

    std::cout<<"Service initialized successfully."<<std::endl;

    Runtime runtime;
    SearchEngine search;
    Orchestrator agent;

    int runtimeResult = runtime.run("hello windows ai runtime");
    Telemetry::log("Runtime executed.");

    int searchResult = search.search("semantic search query");
    Telemetry::log("Search executed.");

    int agentResult = agent.executeTask("summarize search results");
    Telemetry::log("Agent executed.");

    std::cout << "Runtime result: " << runtimeResult << std::endl;
    std::cout << "Search result: " << searchResult << std::endl;
    std::cout << "Agent result: " << agentResult << std::endl;

    Telemetry::log("Service is now running...");



    while(true){
        //loop
    }

    return 0;
}
