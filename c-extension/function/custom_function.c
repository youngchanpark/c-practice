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
yc_func(PyObject *self, PyObject *args)
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


// Add above function to method table
static PyMethodDef YcMethods[] = {

    {"system",  yc_func, METH_VARARGS,
     "function docstring?"},

    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// Add the method table to Python Module initialiser
static struct PyModuleDef ycmodule = {
    // PyModuleDef = Python Module Definition 
    PyModuleDef_HEAD_INIT,
    "yc",   /* name of module */
    // spam_doc, /* module documentation, may be NULL */
    NULL,
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
