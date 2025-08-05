#  Vole Machine Simulator

A complete simulation of a basic Vole Machine architecture using C++ and Qt. This project visually demonstrates how a minimal computer architecture operates — including CPU cycles, memory operations, instruction decoding, and register behavior — through a simple GUI.

---

##  Overview

The Vole Machine is a conceptual educational processor with:

- A **CPU** with registers and ALU
- A **Control Unit (CU)** to decode and control execution
- A simple **Main Memory** of 256 bytes
- A GUI built using **Qt** for interaction and visualization

---

##  Features

- Load instructions into memory (e.g., `0x20 0xF1`)
- Instruction decoding and execution
- GUI to:
  - Step through instructions
  - Display register & memory content
  - Run entire programs
- Clear modular structure (CPU, CU, Memory, etc.)

---

##  Project Structure
vole-machine/

├── CPU.cpp / CPU.h # Arithmetic and register logic

├── CU.cpp / CU.h # Control Unit: Decodes and controls CPU actions

├── helperFunction.cpp/.h # Utility functions used across modules

├── mainMemory.cpp / .h # Main memory implementation (256 bytes)

├── memoryUnit.cpp / .h # Abstraction for memory operations

├── volemachine.cpp / .h # VoleMachine: ties all components together

├── machinesimulator.cpp / .h # Qt GUI logic and event handlers

├── machinesimulator.ui # Qt Designer file for the GUI

├── machine.h # High-level machine interface (CPU + Memory + CU)
└── main.cpp # App entry point


---

##  Getting Started

###  Requirements

- **Qt Creator**
- **Qt 6+**
- **C++17+ compatible compiler**

###  Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/HamzaOmarSaad/GUI-for-vole_machine-final.git
   cd vole-machine

2-Open the .pro or CMake project in Qt Creator

3-Select your Kit (e.g., Desktop x86-windows-msvc2022-pe-64bit)

4-Click Build and Run

---
##  Instruction Format
Each instruction consists of 2 bytes:

Copy
Edit
0x20 0x11
First byte: Opcode + target register

Second byte: Immediate value or memory address

Example
Bytes	   Meaning
0x20	   Opcode 2 (load), Register 0
0x11	   Load value 0x11 into Register 0

---
## GUI Preview


---
##  Usage
Load Program: Use GUI or load a .txt file containing instructions.

Step Execution: Click "Step" to execute one instruction.

Run All: Click "Run" to execute till end of memory.

Reset: Clears all registers and memory.

---
## Educational Value
This project is great for:

Learning how CPUs and control units work

Understanding memory/register interaction

Debugging binary-level instructions

Practicing Qt GUI development in C++

---
## Authors
Yahia Nassar       Hamza Omar      Amr khaled
