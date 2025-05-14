#define PY_SSIZE_T_CLEAN

// need to install python development environment to access Python.h
#include <Python.h>

extern int add(int a, int b)
extern double multiply(double a, double b)

//wrapper for add function
static PyObject* py_add(PyObject* self, PyObject* args){
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b)){
        return NULL;
    }

    return PyLong_FromLong(add(a, b));
}

//wrapper for multiply function
static PyObject* py_multiply(PyObject* self, PyObject* args){
    double a, b;
    if (!PyArg_ParseTuple(args, "dd", &a, &b)){
        return NULL;
    }
    return PyFloat_FromDouble(multiply(a, b));
}


static PyMethodDef MathOpsMethods[] = {
    {"add", py_add, METH_VARARGS, "Add two integers"},
    {"multiply", py_multiply, METH_VARARGS, "Multiply two doubles"},
    {NULL, NULL, 0, NULL} // Sentinel
};

static struct PyModuleDef mathopsmodule = {
    PyModuleDef_HEAD_INIT,
    "mathops",
    "A module providing math operations in C",
    -1,
    MathOpsMethods
};

PyMODINIT_FUNC PyInit_mathops(void){
    return PyModule_Create(&mathopsmodule);
}