# AcesEngine
Game Engine focused on board games with educational purposes. Made under the Universidad de Chile CC5512 class.

## To run the project
```
git clone https://github.com/diegoHurtadoG/AcesEngine.git
mkdir build
cd build
cmake ../AcesEngine
```

Go to 
```
AcesEngine/third_party/SFML/extlibs/bin/{Choose between x64 or x86}/
```
And copy the file openal32.dll to
```
build/source/engine/
```

Done that, you can build the solution in the Build directory.
The example can be found in
```
build/source/engine/shape_maker.exe
```
## Ignore the file content and go down until you find the last while lopp
There you can see how the example was made

To Make your own game, make a new file in the same engine/ directory and import the shape_maker.cpp file so the classes and functions are available to use.
