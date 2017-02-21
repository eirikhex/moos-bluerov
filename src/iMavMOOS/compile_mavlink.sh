echo "Starting"

## make custom build directory
mkdir -p lib_build

cd lib_build

# run cmake for mavcon library
cmake ../../../../src/iMavMOOS/libmavconn/
# make in current folder
make

# copy library to MOOS lib folder
cp libmavconn.a ../../../../lib
cp libmavconn.a ../../../lib

# copy library header to MOOS include folder
cp -R ../../../../src/iMavMOOS/libmavconn/include/mavconn ../../../include

cd ..


