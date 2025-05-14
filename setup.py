from setuptools import setup, Extension


module = Extension(
    name="mathops",
    sources=["mathops_module.c", "mathops.c"]
)

setup(
    name="MathOps",
    version="0.0.1",
    description="Math Operations in C",
    ext_modules=[module]
)
