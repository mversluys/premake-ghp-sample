# Premake GHP Sample

This is a sample project that demonstrates how to use Premake and GitHub Packages.

Requires premake5 which can be found here http://github.com/premake/premake-core/releases

### Ensure the submodule was pulled

    git submodule init
    git submodule update

### Run premake

    premake5 gmake

### Build it

    cd build
    make

### Run it

    bin/Debug/sample-project 

### Test it

    curl http://localhost:9000

