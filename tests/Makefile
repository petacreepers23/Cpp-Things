CFLAGS			:= -Wall
#LIBS_I 			:= pkg-config --libs-only-l gtest gmock

BIND			:= bin

ifeq ($(OS),Windows_NT)
	CC := x86_64-w64-mingw32-gcc
else
	CC := g++
	UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
		#LIBS_I := `pkg-config --libs-only-l gtest gmock`
		#LIBS_I := -lgtest -pthread /usr/local/lib/libgtest.a
		LIBS_I := -lgtest -pthread /usr/src/googletest/googletest/lib/libgtest.a

		# Compiling for Linux
    endif
    ifeq ($(UNAME_S),Darwin)
		# Compiling for Mac OS
	endif
endif



all: prepare googletest gtest test

prepare:
	mkdir -p $(BIND)

googletest:
	$(CC) $(CFLAGS) -c gtest-test.cpp -o $(BIND)/gtest-test.o

gtest:
	$(CC) $(CFLAGS) $(BIND)/gtest-test.o $(LIBS_I) -o $(BIND)/gtest-test

test:
	./$(BIND)/gtest-test

clean:
	rm -rf $(BIND)
