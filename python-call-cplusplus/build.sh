if [ ! -d "./pybind11" ];then
    git clone https://github.com/pybind/pybind11.git
else
    echo "pybind11 is exist"
fi

export PYTHONPATH=$PYTHONPATH:./pybind11
c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3-config --includes) cpplib.cpp -o cpplib$(python3-config --extension-suffix) -I./pybind11/include -I/usr/include/python3.7