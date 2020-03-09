#include "foo.h"
#include <string>
#include <python3.6/Python.h>

using namespace std;

/*
Python Interface Wrap
*/
static PyObject *_myPrint(PyObject *self, PyObject *args)
{
    char *text;

    // 解析Python传过来的参数
    if(!PyArg_ParseTuple(args, "s", &text))
        return NULL;
    
    myPrint(text);
    return Py_None;
}


static PyMethodDef ExtestMethods[] = 
{
    {"myPrint", _myPrint, METH_VARARGS},
    {NULL, NULL},
};

static struct PyModuleDef printmodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
    "spam_doc", /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    ExtestMethods
};

PyMODINIT_FUNC
PyInit_myprint(void)
{
    // (void)Py_InitModule("myprint", ExtestMethods);
    return PyModule_Create(&printmodule);
}
