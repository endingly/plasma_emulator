# Plasma Emulator

The project is aimed to develop a C++ emulator for plasma physics calculations. And now, it is still in the early stage of development.

## 0. build pre-requisites

- C++20 compiler
- vcpkg
- Addtionally, if you want to use Intel MKL, you need to install it and set the environment variable `MKLROOT` to the installation directory. And set `USE_MKL_BACKEND=ON` in cmake file (default is `OFF`).

## 1. submodules

### 1.1 chempars

a C++ library for parsing chemical equations and performing chemical calculations (only plasma, electrolysis).

In academia, we usually need to analyze particle reaction equations like this

$$
\mathrm{e} + \mathrm{Ar^+} \rightarrow \mathrm{Ar^*},\ 4.0\times10^{-13}\mathrm{T_e}^{-0.5}\ \mathrm{cm^{-3}s^{-1}}
$$

The number after the formula refers to the threshold of the reaction.

the chemical equation displayed format is usually in the form of

```text
e + Ar^+ -> Ar^*, 4.0e-13 cm^3/s
```

the text is part of file like `toml`, `yaml` or `json` usually.

### 1.2 common
  
a C++ library for common data structures and algorithms.

now it contains:

- log
- units calculate and convert system
- config file parser
- config argument data structure
- some utils functions
