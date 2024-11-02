# Secret-Sharing-Polynomial-Solver-Using-Lagrange-Interpolation

This repository contains a C program that implements a simplified version of Shamir's Secret Sharing algorithm. The program reads input from a JSON file, decodes `y` values from different bases, and uses Lagrange interpolation to find the constant term (`c`) of a polynomial.

## Overview
Shamir's Secret Sharing is an algorithm used for secure data splitting, where data is represented as a polynomial. This program calculates the constant term of the polynomial using given points, decoding the `y` values from various bases, and applying Lagrange interpolation to solve for the coefficients.

## Features
- Reads input points and their corresponding base-encoded `y` values from a JSON structure.
- Decodes `y` values from different bases (e.g., binary, hexadecimal).
- Calculates the constant term (`c`) using Lagrange interpolation.

## Requirements
- A C compiler (e.g., GCC)
- JSON parsing library for advanced use (optional)

## Usage
1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/shamir-secret-solver.git
   cd shamir-secret-solver

2. compile the code:
   ```bash
   gcc -o polynomial_solver polynomial_solver.c -lm
   
4. Run the program:
   ```bash
   ./polynomial_solver
## How It Works
The program reads x values and y values encoded in different bases.
It decodes y values to decimal using a custom baseToDecimal function.
Using the decoded values, the program calculates the constant term (c) of the polynomial using Lagrange interpolation.

## Compilation and Execution
1. Copy the code into a file named polynomial_solver.c.
2. Compile and link the program using:
   ```bash
   gcc -o polynomial_solver polynomial_solver.c -lm
4. Run the compiled program:
   ```bash
   ./polynomial_solver
