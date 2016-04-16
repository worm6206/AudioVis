Essentia Guide (For MAC OS X, Linux might also work)

## INSTALL:

0.a. run(requires homebrew)
	
	brew install pkg-config gcc readline sqlite gdbm freetype libpng

0.b. run(requires homebrew)

	brew install libyaml fftw ffmpeg libsamplerate libtag


1. Get essentia from https://github.com/MTG/essentia

2. go into directory, run
	
	./waf configure --mode=release --build-static --with-python --with-cpptests --with-examples --with-vamp --with-gaia

3. run

	./waf

4. run 

	sudo ./waf install

## COMPILE YOUR OWN CODE:

replace @@@@@@@@@ with the file name:

	g++ -pipe -Wall -O2 -fPIC -I/usr/local/include/essentia/ -I/usr/local/include/essentia/scheduler/ -I/usr/local/include/essentia/streaming/  -I/usr/local/include/essentia/utils -I/usr/include/taglib -I/usr/local/include/gaia2 -I/usr/include/qt4 -I/usr/include/qt4/QtCore -D__STDC_CONSTANT_MACROS @@@@@@@@@.cpp -o @@@@@@@@@ -L/usr/local/lib -lessentia -lfftw3 -lyaml -lavcodec -lavformat -lavutil -lsamplerate -ltag -lfftw3f -lQtCore -lgaia2

