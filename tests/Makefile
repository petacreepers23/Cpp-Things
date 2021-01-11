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
		LIBS_I := -lgtest -lgtest_main -lpthread /usr/local/lib/libgtest.a /usr/local/lib/libgtest_main.a

		# Compiling for Linux
    endif
    ifeq ($(UNAME_S),Darwin)
		# Compiling for Mac OS
	endif
endif



all: prepare gtest test

prepare:
	mkdir -p $(BIND)

gtest:
	$(CC) $(CFLAGS) $(LIBS_I) -g gtest-test.C -o $(BIND)/gtest-test

test:
	./$(BIND)/gtest-test

clean:
	rm -rf $(BIND)
