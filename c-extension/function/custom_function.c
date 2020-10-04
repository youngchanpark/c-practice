#define PY_SSIZE_T_CLEAN
#include <Python.h>


//Define a new exception object for our module
static PyObject *YCError;

/* 
All Python function arguments must have a pointer to self
and a pointer to args.
Q: Are the names arbitrary?
Q2: Where do they point to?
*/
static PyObject *
mysystem(PyObject *self, PyObject *args)
{
    const char *command; // Why a constant pointer?
    int sts; // status

    // We expect at least 1 string argument to this function
    if (!PyArg_ParseTuple(args, "s", &command)) // How can you give the address of the pointer variable when it hasn't even been initialised?
    // PyArg_ParseTuple is a Python C API function which checks the argument types
    // and converts them to C types. The return value is a positive or zero value for succes,
    // a -1 value fore failure.
    // It takes the args pointer and converts it to C "s"tring type,
    // and saves it to the command variable. You should not modify the
    // actual value, so the const is used!
        return NULL; // Return error!
    printf("HELLO WORLD!: %c", *command); // My addition
    sts = system(command); // Run the unix command here!
    printf("STATUS: %i", sts); // My addition
    if (sts < 0) { // If teh 
        PyErr_SetString(YCError, "My function errored"); // Raise my custom error?
        // PyErr_SetString is a Python C API function which sets the 
        // error indicator.
        return NULL;
    }
    return PyLong_FromLong(sts); // Convert the C integer value to Python's long int
}


static PyObject *
null_func(PyObject *self, PyObject *args)
{
    return NULL;
}

static PyObject *
null_func_with_err(PyObject *self, PyObject *args)
{
    printf("%s", args);
    PyErr_SetString(PyExc_BaseException, "My function errored");
    // https://docs.python.org/3/c-api/exceptions.html?highlight=pyerr_setstring#standard-exceptions
    return NULL;
}


static PyObject *
sum_func(PyObject *self, PyObject *args)
{   
    int a, b, c;
    a = PyTuple_GetItem(args, 0);
    b = PyTuple_GetItem(args, 1);
    c = PyTuple_GetItem(args, 2);
    printf("a: %i, b: %i, c: %i", a, b, c);
    return PyLong_FromLong(a + b + c);
}


// Add above function to method table
static PyMethodDef YcMethods[] = {

    {"system",  mysystem, METH_VARARGS, "function docstring?"},
    {"null",  null_func, METH_VARARGS, "Returns a NULL pointer"},
    {"null_with_err",  null_func_with_err, METH_VARARGS, "Returns a NULL pointer and raises an error"},
    {"mysum",  sum_func, METH_VARARGS, "Takes in three ints and returns sum"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// Add the method table to Python Module initialiser
static struct PyModuleDef ycmodule = {
    // PyModuleDef = Python Module Definition struct

    PyModuleDef_HEAD_INIT, // m_base: Always initialize this member to PyModuleDef_HEAD_INIT.
    "yc",   /* const char *m_name: Name for the new module. */
    NULL, // const char *m_doc: Docstring for the module; usually a docstring variable created with PyDoc_STRVAR is used.
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    YcMethods
};


// Creating the module?
PyMODINIT_FUNC
PyInit_yc(void)
{
    return PyModule_Create(&ycmodule); // The pointer to the module struct?
}





// int
// main(int argc, char *argv[])
// {
//     wchar_t *program = Py_DecodeLocale(argv[0], NULL);
//     if (program == NULL) {
//         fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
//         exit(1);
//     }

//     /* Add a built-in module, before Py_Initialize */
//     if (PyImport_AppendInittab("yc", PyInit_yc) == -1) {
//         fprintf(stderr, "Error: could not extend in-built modules table\n");
//         exit(1);
//     }

//     /* Pass argv[0] to the Python interpreter */
//     Py_SetProgramName(program); // Is `program` the interpreter?

//     /* Initialize the Python interpreter.  Required.
//        If this step fails, it will be a fatal error. */
//     Py_Initialize();

//     /* Optionally import the module; alternatively,
//        import can be deferred until the embedded script
//        imports it. */
//     pmodule = PyImport_ImportModule("yc");
//     if (!pmodule) {
//         PyErr_Print();
//         fprintf(stderr, "Error: could not import module 'yc'\n");
//     }


//     PyMem_RawFree(program);
//     return 0;
// }
