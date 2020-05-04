# the compiler: gcc for C program, define as g++ for C++
CC=g++
# extension of the source files
EXT=cc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS= -g -Wall

# the build target executable:
TARGET=ejemplo

# commands
FNAME=$(TARGET).$(EXT)

all: $(TARGET)

$(TARGET): $(FNAME)
	$(CC) $(CFLAGS) -o $(TARGET) $(FNAME)
clean:
	$(RM) $(TARGET)
run:
	./$(TARGET)
