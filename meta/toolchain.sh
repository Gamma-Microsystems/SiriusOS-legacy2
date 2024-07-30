#!/bin/bash
LDVER=2.41
CCVER=13.2.0
ARCH=x86_64
ROOTCMD=sudo
THREADS=8

if [ ! -d ports-build ]; then
    mkdir ports-build
fi

if [ -d ports-build ]; then
    rm -rf ports-build
    mkdir ports-build
fi

cd ports-build
wget mirrors.kernel.org/gnu/binutils/binutils-$LDVER.tar.xz
wget mirrors.kernel.org/gnu/gcc/gcc-$CCVER/gcc-$CCVER.tar.xz
tar -xvf binutils-$LDVER.tar.xz
tar -xvf gcc-$CCVER.tar.xz
cd binutils-$LDVER
cp ../../../ports/binutils/0001-host-toolchain.patch .
patch -p1 < 0001-host-toolchain.patch
mkdir build && cd build
../configure --target=$ARCH-sirius --prefix=$HOME/opt/cross --with-sysroot --disable-nls --disable-werror
make -j$THREADS
$ROOTCMD make install
cd ../../
tar -xvf gcc-$CCVER.tar.xz
cd gcc-$CCVER
cp ../../../ports/gcc/0001-host-toolchain.patch .
patch -p1 < 0001-host-toolchain.patch
mkdir build && cd build
../configure --target=$ARCH-sirius --prefix=$HOME/opt/cross --disable-nls --enable-languages=c,c++ --without-headers
make all-gcc all-target-libgcc -j$THREADS
$ROOTCMD make install-gcc install-target-libgcc
