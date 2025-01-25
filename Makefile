# Common variables
CFLAGS = -g -static -O2
TARGET = toggle-case

# Variables for Linux target
CC_LINUX = gcc
TARGET_LINUX = $(TARGET)

# List of source files
SOURCES = $(TARGET).c

all: $(TARGET_LINUX)

# Build target for Linux
$(TARGET_LINUX): $(SOURCES)
	$(CC_LINUX) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TARGET_LINUX) $(TARGET_WIN)
