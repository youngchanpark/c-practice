from setuptools import setup, Extension

custom_module = Extension(name = 'yc', sources = ['custom_function.c'])

setup(
    name = 'yc_c_func'
    , version = '0.0.1'
    , ext_modules = [custom_module]
)
