# Basic C extension for python

This is a tutorial example for using C functions in python.
I use C extensions (as opposed to `ctypes`).
To compile the C code and use it in python, follow these steps:

1. Install C language pack on your machine. 

Ubuntu/Debian Linux: 
```bash
sudo apt-get update
sudo apt-get install build-essential
```

macOS:
```bash
xcode-select --install
```
Windows:

Download and install from https://www.mingw-w64.org/


This step ensures you have C compiler and tools.

2. Install Python development headers (necessary for C extensions)
Ubuntu/Debian:
```bash
sudo apt-get install python3-dev
```
macOS: 
Usually, the deveopment headers are included in installations from python.org or homebrew.

Windows:
When installing python from python.org, select "Custom Installation", and make sure to enable "Download debugging symbols" and "Download debug binaries".

3. Install setuptools and wheel via pip
```bash
pip install setuptools wheel
```

4. Compile the extension 
```bash
python setup.py build_ext --inplace
```
- `build_ext`: tells setuptools to build extension modules
- `--inplace`: Places the built extensions in the source directory instead of the build directory

During `build_ext`, 
- The C compiler is invoked to compile the .c files to .o objects
- The linker combines them into a shared libary (.so/.pyd/.dylib)
- Headers are automatically located using Python's include paths

A test example is included in the file `test_mathops.py`. 
