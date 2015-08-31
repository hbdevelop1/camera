

CC=g++
HBDBG=-ggdb3 
HBTEMP=-save-temps=obj

INCLUDE = -I/usr/include/ -I/usr/include/x86_64-linux-gnu/c++/4.8 -I/usr/include/c++/4.8
LIBDIR  = -L/usr/X11R6/lib 
LIBRARIES = -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm

OUT_EXE=a

FILES=lesson5.cpp
build: $(FILES)
	$(CC) $(HBDBG) $(INCLUDE) $(LIBDIR) $(FILES) -o $(OUT_EXE) $(LIBRARIES)


buildi: *.ii

*.ii:$(FILES1)
	$(CC) $(HBDBG) -P $(FILES1)


cleanall:
	rm -f *.o $(OUT_EXE) *.ii *.stackdump *.s

clean:
	rm -f *.o $(OUT_EXE)

rebuild: cleanall build
