# PhySim - Physics Simulation Engine

A real-time physics simulation engine built with OpenGL, designed to visualize and simulate various physics phenomena. PhySim aims to provide an educational and interactive platform for understanding fundamental physics concepts through visual simulations.

## 🎯 Project Vision

PhySim is being developed as a comprehensive physics simulation engine that will eventually support multiple physics phenomena. The project is structured to be modular and extensible, allowing for easy addition of new simulation types.

### Current Focus
As I'm currently learning OpenGL, the initial development focuses on implementing well-defined, individual physics simulations:

- **Simple Pendulum** - Harmonic motion and damping effects
- **Projectile Motion** - Trajectory calculations with air resistance
- **Gravitational Systems** - Point mass interactions
- **Relative Gravity** - Multi-body gravitational dynamics
- **Collision Physics** - Elastic and inelastic collisions
- **Wave Mechanics** - String vibrations and wave propagation

### Future Goals
- Multi-simulation environment with real-time switching
- Interactive parameter adjustment during runtime
- 3D physics simulations
- Advanced rendering techniques (lighting, shadows, textures)
- Physics equation overlays and educational annotations
- Export capabilities for simulation data and videos

## 🚀 Getting Started

### Prerequisites

Before building PhySim, ensure you have the following dependencies installed:

#### Ubuntu/Debian:
```bash
sudo apt update
sudo apt install build-essential cmake pkg-config
sudo apt install libglfw3-dev libglm-dev libgl1-mesa-dev
```

#### Fedora/RHEL:
```bash
sudo dnf install gcc-c++ cmake pkgconfig
sudo dnf install glfw-devel glm-devel mesa-libGL-devel
```

#### Arch Linux:
```bash
sudo pacman -S base-devel cmake pkgconfig
sudo pacman -S glfw glm mesa
```

### Clone and Build

1. **Clone the repository:**
   ```bash
   git clone https://github.com/LovelyLeopard/PhySim.git
   cd PhySim
   ```

2. **Build the project:**
   
   **Option A: One-shot build script (Recommended)**
   ```bash
   ./scripts/physim.bash
   ./app/bin/physim
   ```
   
   **Option B: Using project aliases**
   ```bash
   source scripts/alias.txt
   physim-build
   physim-run
   ```
   
   **Option C: Manual build process**
   ```bash
   source scripts/setupBuild.bash
   source scripts/setupRun.bash
   mkdir -p build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=../app
   make -j$(nproc) install
   cd ../app
   ./bin/physim
   ```

### Available Commands (After sourcing aliases)

```bash
# Build the entire project
physim-build

# Run the simulation
physim-run

# Clean build artifacts
physim-clean
```

## 🏗️ Project Structure

```
PhySim/
├── src/                    # Source code
│   └── main.cpp           # Main application entry point
├── include/               # Header files (future physics engine components)
├── scripts/               # Build and development scripts
│   ├── physim.bash       # Main build script
│   ├── setupBuild.bash   # Build environment setup
│   ├── setupRun.bash     # Runtime environment setup
│   ├── buildAndInstall.bash # Build and install process
│   └── alias.txt         # Project-specific aliases
├── build/                 # Build directory (generated)
├── app/                   # Installation directory (generated)
│   └── bin/physim        # Compiled executable
├── CMakeLists.txt         # CMake configuration
└── README.md             # This file
```

## 🔧 Development Workflow

### Branch Strategy
- `main` - Production-ready releases
- `develop` - Active development branch
- `feature/*` - Individual feature development

### Contributing
1. Fork the repository
2. Create a feature branch from `develop`
3. Make your changes
4. Submit a Pull Request to `develop`

### Build System
The project uses CMake with custom scripts for development convenience:
- **Work-safe**: Scripts don't modify your global shell environment
- **Flexible**: Multiple build options for different workflows
- **Portable**: Works across different Linux distributions

## 🎮 Current Features

### Basic OpenGL Window
- GLFW window management
- OpenGL context initialization
- Basic rendering loop with blue background
- Cross-platform compatibility

### Planned Simulations

#### Phase 1 (Current Development)
- [ ] Simple Pendulum with adjustable parameters
- [ ] Projectile motion with drag
- [ ] Basic gravitational attraction

#### Phase 2 (Future)
- [ ] Multi-body systems
- [ ] Collision detection and response
- [ ] Real-time parameter adjustment UI

#### Phase 3 (Advanced)
- [ ] 3D simulations
- [ ] Advanced rendering effects
- [ ] Physics equation displays

## 🛠️ Technical Details

### Dependencies
- **OpenGL** - Graphics rendering
- **GLFW** - Window management and input handling
- **GLM** - Mathematics library for graphics
- **CMake** - Build system

### Platform Support
- Linux (Primary development platform)
- Windows (Planned)
- macOS (Planned)

## 📚 Learning Resources

This project serves as a learning platform for:
- OpenGL graphics programming
- Real-time physics simulation
- C++ game/simulation engine development
- Mathematical modeling of physical systems

## 📄 License

This project is open source. License details to be determined.

## 🤝 Contributing

Contributions are welcome! Whether you're interested in:
- Adding new physics simulations
- Improving rendering quality
- Optimizing performance
- Writing documentation
- Reporting bugs

Please feel free to open issues or submit pull requests.

## 📞 Contact

For questions, suggestions, or collaboration opportunities, please open an issue on GitHub.

---

**Note**: PhySim is currently in early development. The API and project structure may change as development progresses.