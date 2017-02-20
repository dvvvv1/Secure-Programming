all: PNG_Fuzzing_Script default

PNG_Fuzzing_Script: PNG_Fuzzing_Script.o
	g++ -o PNG_Fuzzing_Script PNG_Fuzzing_Script.cpp
default: clean

clean:
	rm -f *.o *~