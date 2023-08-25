PYBINDPATH="../pybind11"
PYVERSION=3.7

if [ ! -d $PYBINDPATH ];then
    git clone https://github.com/pybind/pybind11.git
else
    echo "$PYBINDPATH has been installed"
fi

c++ -O3 -Wall -shared -std=c++14 -fPIC $(python3-config --includes) xiaobai.cpp -o xiaobai$(python3-config --extension-suffix) -I${PYBINDPATH}/include -I/usr/include/python$PYVERSION