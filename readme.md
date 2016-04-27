Essentia Guide (For MAC OS X, Linux might also work)

## INSTALL:

1. run(requires homebrew)
	
	`brew install pkg-config gcc readline sqlite gdbm freetype libpng`

2. run(requires homebrew)

	`brew install libyaml fftw ffmpeg libsamplerate libtag`


3. Download essentia from [their Github](https://github.com/MTG/essentia/archive/master.zip)

4. extract it

5. go into directory, run
	
	`./waf configure --mode=release --build-static --with-python --with-cpptests --with-examples --with-vamp --with-gaia`

6. run

	`./waf`

7. run 

	`sudo ./waf install`

8. Essentia is now installed. 

9. Put your own code in `src/` and run make at the root directory of this project.

10. Executable are at `build/`

## COMPILE YOUR OWN CODE:

replace @@@@@@@@@ with the file name:

	g++ -pipe -Wall -O2 -fPIC -I/usr/local/include/essentia/ -I/usr/local/include/essentia/scheduler/ -I/usr/local/include/essentia/streaming/  -I/usr/local/include/essentia/utils -I/usr/include/taglib -I/usr/local/include/gaia2 -I/usr/include/qt4 -I/usr/include/qt4/QtCore -D__STDC_CONSTANT_MACROS @@@@@@@@@.cpp -o @@@@@@@@@ -L/usr/local/lib -lessentia -lfftw3 -lyaml -lavcodec -lavformat -lavutil -lsamplerate -ltag -lfftw3f -lQtCore -lgaia2

