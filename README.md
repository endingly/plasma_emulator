# Chempars

Chempars is a C++ library for parsing chemical equations and performing chemical calculations (only plasma, electrolysis).

In academia, we usually need to analyze particle reaction equations like this

$$
\mathrm{e} + \mathrm{Ar^+} -> \mathrm{Ar^*},\ 4.0\times10^{-13}\mathrm{T_e}^{-0.5}\ \mathrm{cm^{-3}s^{-1}}
$$

The number after the formula refers to the threshold of the reaction.

the chemical equation displayed format is usually in the form of

```text
e + Ar^+ -> Ar^*, 4.0e-13 cm^3/s
```

the text is part of file like `toml`, `yaml` or `json` usually.