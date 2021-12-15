clang main.c glad_gl.c -Ofast -lglfw -lm -o snowling
i686-w64-mingw32-gcc main.c glad_gl.c -Ofast -Llib -lglfw3dll -lm -o snowling.exe
upx snowling
upx snowling.exe
