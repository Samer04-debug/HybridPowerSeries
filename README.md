# Hybrid-Parallel Framework for Logarithmic Power Series Computations

This repository implements a hybrid-parallel framework for optimizing logarithmic power series computations, as described in the paper *"A Hybrid-Parallel Framework for Optimizing Logarithmic Power Series Computations"* by Princess Mae Pangca, Stinnely Dagooc, and Samuel T. Cloma Jr. (University of Science and Technology of Southern Philippines, 2025). The framework leverages C++ with MPIR, FFTW, Eigen, and OpenMP to achieve high performance, with applications in signal processing, cryptography, and scientific computing.

## Overview

Logarithmic power series computations are essential for solving differential equations and modeling systems, but their slow convergence poses challenges. This framework combines:
- **Parallel Newton Iterations**: For cryptographic key generation (`ComputeYZ`).
- **Fast Fourier Transforms (FFT)**: For real-time 5G signal processing (`DivideAndConquer`).
- **Jacobian Linearization**: For stable scientific simulations (`SolveNonlinearSys`).
- **Adaptive Precision**: Reduces memory usage by 27%, enabling IoT deployment.

**Key Metrics** (for $n=1000$):
- **Runtime**: 0.52 seconds (40% faster than Newton-FFT’s 0.89s).
- **Memory**: 95 MB (27% less than Newton-FFT’s 130 MB).
- **Accuracy**: 99.3%.
- **FFT Operations**: 0.9 million.

## Prerequisites

- **Operating System**: Windows 10/11 (64-bit).
- **IDE**: Visual Studio 2022 Community Edition with C++ Desktop Development workload.
- **Dependencies**:
  - [MPIR](http://mpir.org/) (arbitrary-precision arithmetic, via vcpkg).
  - [FFTW](http://www.fftw.org/) (fast Fourier transforms).
  - [Eigen](http://eigen.tuxfamily.org/) (matrix operations).
  - OpenMP (included in Visual Studio).
- **Optional**: Python 3.12 with NumPy and Matplotlib for prototyping.

## Installation

1. **Install Visual Studio 2022**:
   - Download from [Visual Studio Downloads](https://visualstudio.microsoft.com/downloads/).
   - Select “Desktop development with C++” workload.
   - Include CMake tools and English language pack.

2. **Install vcpkg for MPIR**:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   .\vcpkg install mpir:x64-windows
   .\vcpkg integrate install
3. Install FFTW:
   - Download 64-bit precompiled DLLs from FFTW Windows.
   - Extract to C:\fftw.
   - Copy libfftw3-3.lib to C:\fftw\lib, fftw3.h to C:\fftw\include, and libfftw3-3.dll to your project’s output directory.
   - Install Eigen:
   - Download Eigen 3.4.0 from Eigen Downloads.
   - Extract to C:\eigen.
