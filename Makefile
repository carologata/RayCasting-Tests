NAME	:= cub
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

build_mlx:
ifeq (,$(wildcard ./lib/MLX42/build/libmlx42.a))
	@cd lib && \
	git clone https://github.com/codam-coding-college/MLX42.git && \
	cd MLX42 && \
	sed -i 's/cmake_minimum_required (VERSION 3.18.0)/cmake_minimum_required (VERSION 3.16.0)/g' CMakeLists.txt && \
	if ! cmake -B build; then \
		echo "Failed to configure MLX42"; \
	else \
		cmake --build build -j4; \
	fi
endif

.PHONY: all, clean, fclean, re, libmlx