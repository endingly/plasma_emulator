# Plasma Emulator

The project is aimed to develop a C++ emulator for plasma physics calculations. And now, it is still in the early stage of development.

## 0. build pre-requisites

- C++20 compiler
- vcpkg
- Addtionally, if you want to use Intel MKL, you need to install it and set the environment variable `MKLROOT` to the installation directory. And set `USE_MKL_BACKEND=ON` in cmake file (default is `OFF`).

## 1. submodules

## 1.1 dependencies and relationship of submodules

- chempars
  - core
- common
  - fmt (from vcpkg)
- core
  - units (from vcpkg)
  - eigen3 (from vcpkg)
  - intel-mkl (from vcpkg, optional)
- parallel
  - cutlass (from vcpkg, optional)

### 1.2 chempars

a C++ library for parsing chemical equations and performing chemical calculations (only plasma, electrolysis).

In academia, we usually need to analyze particle reaction equations like this

$$
\mathrm{e} + \mathrm{Ar^+} \rightarrow \mathrm{Ar^*},\ 4.0\times10^{-13}\mathrm{T_e}^{-0.5}\ \mathrm{cm^{-3}s^{-1}}
$$

The number after the formula refers to the threshold of the reaction.

the chemical equation displayed format is usually in the form of

```text
e + Ar^+ -> Ar^*, excitation , 4.0e-13 1/(cm^3 * s)
```

the text is part of file like `toml`, `yaml` or `json` usually.

### 1.3 common

a C++ library for common data structures and algorithms. This library can be regarded as a submodule of the core.

now it contains:

- log
- config file parser
- config argument data structure
- some utils functions

### 1.4 core

The core library is the core of the emulator. It contains the basic data structures and algorithms for plasma physics calculations.

now it contains:

1. a basic units system
2. a basic vector and matrix library based on Eigen3
3. a basic plasma physics equation solver (TODO)

### 1.5 parallel (Experimental)

a basic parallel library based on CUTLASS (optional).

The main goal of the library is to provide faster speed than Eigen3 with Intel-MKL backend in situations where data is particularly large.
