from setuptools import setup, Extension

custom_module = Extension(name = 'custom', sources = ['custom.c'])

setup(
    name = 'CustomType'
    , version = '0.0.1'
    , ext_modules = [custom_module]
)
