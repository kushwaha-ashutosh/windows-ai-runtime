cmake_minimum_required(VERSION 3.16)

project(windows_ai_runtime LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(windows_ai_runtime
    src/ServiceHost/main.cpp
    src/ServiceHost/ServiceBootstrap.cpp
    src/InferenceRuntime/Runtime.cpp
    src/SemanticSearch/SearchEngine.cpp
    src/AgentOrchestrator/Orchestrator.cpp
    src/Telemetry/Telemetry.cpp
)

target_include_directories(windows_ai_runtime PRIVATE
    src/ServiceHost
    src/InferenceRuntime
    src/SemanticSearch
    src/AgentOrchestrator
    src/Telemetry
)
