C++ imgui Connect4
-----------

The imgui graphics library is not upgraded for conan 2.0 yet so to use this project follow these steps:

Uses python virtualenv.

    unzip conan-1.58.0.zip as conan_src
    cd conan_src
    pip install -e .

During the conan install I received many missing library messages such as `glu.pc`. I found the library and did `sudo apt install <libname>` using debian package url:

[This link](http://packages.debian.org/search?mode=exactfilename&searchon=contents&keywords=glu.pc)

There is also a cli version that forced the architecture to allow different UI implementation through the use of a core library for the game logic.