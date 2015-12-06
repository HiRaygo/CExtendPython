// demo.cpp : 定义控制台应用程序的入口点。
//

#include "Python.h"

int add(int a, int b)
{
	return (a+b);
}
static PyObject *
demo_add(PyObject *self, PyObject *args)
{
    int ret;
    int a, b;
    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;
    ret = add(a, b);
    return Py_BuildValue("i", ret);
}
static PyMethodDef demoMethods[] = {
    {"add",  demo_add, METH_VARARGS, "add two numbers."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef demoModule = {
    PyModuleDef_HEAD_INIT,
    "demo",
    NULL,
    -1,
    demoMethods
};

PyMODINIT_FUNC
PyInit_demo(void)
{
    return PyModule_Create(&demoModule);
}

