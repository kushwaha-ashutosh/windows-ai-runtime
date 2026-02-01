#include <iostream>
#include "ServiceBootstrap.h"
#include "../InferenceRuntime/Runtime.h"
#include "../SemanticSearch/SearchEngine.h"
#include "../AgentOrchestrator/Orchestrator.h"
#include "../Telemetry/Telemetry.h"
#include "../AgentOrchestrator/Orchestrator.h"

#include <string>


int main(int argc, char* argv[]) {
    // -------- CLI MODE (used by API Gateway) --------
    if (argc >= 3 && std::string(argv[1]) == "--search") {
        std::string query = argv[2];

        SearchEngine search;
        int result = search.search(query);

        std::cout << result;   // IMPORTANT: stdout only
        return 0;
    }

    if (argc >= 3 && std::string(argv[1]) == "--agent") {
    std::string task = argv[2];

    Orchestrator agent;
    int result = agent.executeTask(task);

    std::cout << result; // stdout only
    return 0;
}


    



    // -------- SERVICE MODE (normal startup) --------
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
