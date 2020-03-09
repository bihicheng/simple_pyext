from setuptools import setup, Extension, find_packages

NAME = 'foo'
VERSION = '1.0.0'
PACKAGES = ['', 'bar']
PACKAGE_DIR = {'a': 'bar'}
EXT_MODULES = [
    Extension(
        name='myprint',
        sources=['src/foo.cpp', 'src/PythonWrapAPI.cpp'],
        include_dirs=['src']
    )
]

install_requires = ['pycurl', 'xmltodict']
dependency_links = []
setup(
    name=NAME,
    version=VERSION,
    ext_modules=EXT_MODULES,
    package_dir=PACKAGE_DIR,
    packages=PACKAGES
)