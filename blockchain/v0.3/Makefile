CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -ggdb3 -c
SRC=blockchain_create.c blockchain_serialize.c block_is_valid.c blockchain_deserialize.c block_create.c block_mine.c blockchain_destroy.c block_destroy.c hash_matches_difficulty.c blockchain_difficulty.c block_hash.c
OBJS=$(SRC:.c=.o)
NAME=libhblk_blockchain_v0.3.a
.PHONY: clean oclean
clean:
	rm *~ $(NAME)
oclean:
	rm $(OBJS)
libhblk_blockchain_v0.3.a: blockchain.h $(OBJS)
	ar rcs $(NAME) $(OBJS)
	make oclean
