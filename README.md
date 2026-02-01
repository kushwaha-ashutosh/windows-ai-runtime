# Windows AI Runtime

A Windows-first, local AI runtime platform built with a **C++ core** and a **C# API gateway**, designed to mirror real-world platform and systems engineering patterns used in large-scale products. This project focuses on **architecture, separation of concerns, and production readiness**, not model demos or UI experiments.

---

## 🚀 High-Level Overview

**Windows AI Runtime** is a modular system that exposes AI capabilities through a clean API layer while keeping performance-critical logic isolated in a native C++ runtime. It is built incrementally to demonstrate:

- How real platform services are structured
- How cross-language systems communicate safely
- How AI functionality fits into a production architecture

---

## 🧠 System Architecture
```
Client (HTTP)
    ↓
C# API Gateway
    ↓
(local process invocation)
    ↓
C++ Runtime (ServiceHost)
    ├── InferenceRuntime
    ├── SemanticSearch
    ├── AgentOrchestrator
    └── Telemetry
```

### Key Principles

- **Language boundaries are intentional**
- **Business logic lives in C++**
- **API layer contains no AI logic**
- **Observability is built-in, not bolted-on**

---

## 🧩 Components

### 1. ServiceHost (C++)
Owns the lifecycle of the runtime.
- Startup and initialization
- Long-running service loop
- Entry point for both service mode and CLI mode

### 2. InferenceRuntime (C++)
Defines the **AI inference boundary**.
- Currently implemented as a deterministic stub
- Designed to be replaced by real ONNX / ML inference
- Keeps model execution isolated from the rest of the system

### 3. SemanticSearch (C++)
Implements semantic-style search logic.
- Invoked by both the runtime and API
- Designed to consume inference outputs (e.g. embeddings)

### 4. AgentOrchestrator (C++)
Coordinates multi-step workflows.
- Represents agent-style execution
- Orchestrates calls to other components
- Contains no heavy computation itself

### 5. Telemetry (C++)
Centralized logging and observability.
- Cross-cutting concern
- No business logic
- Designed for future metrics / tracing integration

### 6. API Gateway (C#)
External interface for clients.
- HTTP-based
- Input validation
- Calls the C++ runtime via a strict process boundary
- Keeps API contracts stable while runtime evolves

---

## 🔄 Execution Modes

The C++ runtime supports **two execution modes**:

### Service Mode
```bash
windows_ai_runtime.exe
```
- Starts the long-running service
- Initializes all components
- Intended for daemon / background usage

### CLI Mode (used by API)
```bash
windows_ai_runtime.exe --search "hello"
```
- Executes a single task
- Writes result to stdout
- Exits immediately
- Enables simple and replaceable IPC

---

## 🔌 API Example

### Semantic Search Endpoint

**Request:**
```
GET /api/search?query=hello
```

**Response:**
```json
{
  "query": "hello",
  "result": 5
}
```

---

## 🏗️ Build & Run

### Prerequisites
- Windows
- CMake
- Ninja or MinGW
- .NET SDK (9.0+)

### Build C++ Runtime
```bash
cmake -S . -B build
cmake --build build
```
Produces: `build/windows_ai_runtime.exe`

### Run API Gateway
```bash
cd src/ApiGateway
dotnet run
```

---

## 🧪 Testing Strategy (Planned)

**Unit tests for:**
- InferenceRuntime
- SemanticSearch
- AgentOrchestrator

**API smoke tests for:**
- Gateway → runtime integration
- Failure-case testing (missing runtime, invalid input)

---

## ⚖️ Design Trade-offs

### Why C++ + C#?
- **C++** for performance, control, and systems-level ownership
- **C#** for rapid API development and strong Windows ecosystem support

### Why process-based IPC?

**Pros:**
- Strong isolation
- Simple debugging
- Clear ownership boundaries

**Cons:**
- Process startup cost
- Not ideal for high-throughput scenarios

**Future upgrade path:**
- Named pipes
- gRPC
- Shared memory

---

## 🚧 Current Limitations

- Inference is a deterministic stub (by design)
- No persistent state
- No authentication layer yet

These are intentional to prioritize architecture correctness before optimization.

---

## 🔮 Future Improvements

- Replace inference stub with ONNX Runtime
- Named-pipe IPC for high-throughput scenarios
- Model versioning & validation
- Structured telemetry & metrics
- Windows Service registration

---

## 🎯 Why This Project Exists

This project was built to demonstrate:

- Ownership of system design
- Production-first thinking
- Cross-language integration
- Realistic AI platform architecture