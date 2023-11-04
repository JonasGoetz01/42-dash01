# Define variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
LIBS_DIR = libs
BUILD_DIR = build
BIN_DIR = .
INCLUDES_DIR = includes

# Define source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Define object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

# Define libraries
LIBS = $(LIBS_DIR)/Makefile

# Define executable
EXEC = $(BIN_DIR)/marvin

# Define phony targets
.PHONY: all clean

# Define all target
all: $(EXEC)

# Define clean target
clean:
	rm -rf $(BUILD_DIR) $(EXEC)

# Define build directory
$(BUILD_DIR):
	mkdir -p $@

# Define object file rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

# Define libraries rule
$(LIBS):
	$(MAKE) -C $(LIBS_DIR)

# Define executable rule
$(EXEC): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $^ -o $@
