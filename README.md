# Building

> emcc -lembind -o show_primes.js primes.cpp

# Running

1) Start a local server e.g. by using python:

> python -m http.server

2) Open a browser at localhost:8000/show_primes.html

# Task

- Make a C++ function that finds the prime numbers less than 5000. Use C++17 and nothing newer.

- Make the function available from JavaScript

- Using either a webworker or pthread ensure that the code executes in the background.

- The results should be represented by populating a list on a webpage.

# Notes

Build outputs are included in the repository for convenience.
Test environment was Firefox 136.
The code was built with emsdk v4.0.5.
