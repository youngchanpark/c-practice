#define PY_SSIZE_T_CLEAN
#include <Python.h>


int main()
{
	
	PyObject *args, *pylong_int, *pylong_int_repr;
	long int c_int = 123;
	// long int from_py_int;
	const char* s;
	Py_INCREF(args);
	printf("Reference count: %zd\n", args->ob_refcnt); // %zd is a format for ssize_t types.
	// printf("Reference count: %zd", args.ob_refcnt);

	printf("C int: %i", 123);
	
	Py_INCREF(pylong_int);
	pylong_int = PyLong_FromLong(c_int);
	
	Py_INCREF(pylong_int_repr);
	pylong_int_repr = PyObject_Repr(pylong_int);
	
	s = PyUnicode_AsUTF8(pylong_int_repr);
	printf("Py int: %s", s);
	// args = Py_BuildValue("i", 123);

	// from_py_int = PyLong_AsLong(args);

	// printf("%ld", from_py_int);

	return 0;
}
