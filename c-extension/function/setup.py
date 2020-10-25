from setuptools import setup, Extension

custom_module = Extension(name = 'yc', sources = ['custom_function.c'])
# custom_module = Extension(name = 'yc', sources = ['minimal.c'])

setup(
    name = 'yc_c_func'
    , version = '0.0.1'
    , ext_modules = [custom_module]
)
