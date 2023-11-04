# Define variables
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
LIBS_DIR = libs
BUILD_DIR = build
BIN_DIR = .
INCLUDES_DIR = includes

GET_NEXT_LINE_DIR = $(LIBS_DIR)/get_next_line
GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/get_next_line.a

PRINTF_DIR = $(LIBS_DIR)/printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

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

get_next_line:
	@$(MAKE) -C $(GET_NEXT_LINE_DIR)

ft_printf:
	@$(MAKE) -C $(PRINTF_DIR)

# Define object file rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR) get_next_line ft_printf
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

# Define libraries
LIBS = $(GET_NEXT_LINE) $(PRINTF)

# Define executable rule
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

re: clean all
