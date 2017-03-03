# moos-bluerov
This repository include code needed to run a Bluerov2 in MCLab using Qualisys and MOOS. 
The code is intended to be used with custom PX4 firmware loaded on the pixhawk.

 Build Instructions
=============================================================================


To build on Linux and Apple platforms, execute the build script within this
directory:

    $ ./build.sh

To build without using the supplied script, execute the following commands
within this directory:

    $ mkdir -p build
    $ cd build
    $ cmake ../
    $ make
    $ cd ..
    
