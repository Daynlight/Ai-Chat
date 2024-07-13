git submodule update --remote

mkdir build
mkdir prod
cd build
cmake ..
cmake --build . --config Release
cmake --build . --config Debug
cp -r ./Debug/ ../prod/Debug/
cp -r ./Release/ ../prod/Release/