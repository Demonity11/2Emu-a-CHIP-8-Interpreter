# 🚀 CHIP-8 Emulator (C++ / SFML)

A fully functional **CHIP-8** emulator developed as a personal project during my first semester of Computer Science at **UFERSA**. This project explores low-level CPU architecture, memory management, opcode implementation, and real-time graphics rendering.

## 🛠️ Technologies & Core Concepts

* **Language:** C++ (Modern standard)
* **Graphics & Input:** [SFML](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
* **Build System:** CMake
* **Concepts Applied:**
    * Instruction Cycle (Fetch-Decode-Execute).
    * Bitwise Operations & Masking.
    * Time Synchronization (500Hz CPU Clock & 60Hz Timers).
    * Memory Mapping and Stack Management.

## 🎮 Current Features

* [x] **Core CPU:** Accurate implementation of the standard CHIP-8 opcode set.
* [x] **Graphics:** 64x32 display rendering using SFML textures and pixel buffer mapping.
* [x] **Input Handling:** Real-time state management for the 16-key hexadecimal keypad (Pressed/Released states).
* [x] **ROM Compatibility:** Fully playable with classic ROMs like `IBM Logo.ch8` and `Cave.ch8`.
* [x] **Timing:** Precise synchronization of Delay and Sound timers.

## ⌨️ Key Mapping

The original 16-key hexadecimal keypad is mapped to the modern QWERTY layout for a seamless gaming experience:

| CHIP-8 Key | Modern Input |
| :--- | :--- |
| `1` `2` `3` `C` | `1` `2` `3` `4` |
| `4` `5` `6` `D` | `Q` `W` `E` `R` |
| `7` `8` `9` `E` | `A` `S` `D` `F` |
| `A` `0` `B` `F` | `Z` `X` `C` `V` |

## 🚀 Getting Started

### Prerequisites
* A modern C++ compiler (GCC, Clang, or MSVC).
* [SFML](https://www.sfml-dev.org/download.php) library installed.
* CMake (3.10 or higher).

### Build & Run
```bash
# Clone the repository
git clone https://github.com/YourUsername/CHIP-8-Emulator.git

# Build the project
mkdir build && cd build
cmake ..
cmake --build .

# Run the emulator
./CHIP8_Emulator
```

## 📐 Technical Implementation

The CPU runs at a fixed clock of **500Hz**, while the **Delay** and **Sound** timers decrement at **60Hz**. The display logic uses the `Dxyn` instruction, which renders sprites using XOR operations. If a pixel is erased during rendering, the `VF` register is set to 1, providing native support for collision detection.

## 📈 Roadmap

* [ ] **OOP Refactoring:** Transition to a full Object-Oriented architecture (Encapsulation and Classes).
* [ ] **Audio System:** Implement a square-wave "beep" using `sf::Sound`.
* [ ] **Dynamic Scaling:** Add support for window resizing with Aspect Ratio maintenance.
