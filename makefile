STATIC=lhashh.a

CC = gcc
CFLAGS = -Wall -Winline -pipe

SRC = func/lhashhin.c \
	func/lhashhout.c \
	func/lhashhmk.c \
	func/lhashhdy.c \
	func/lhashhprint.c \
	func/lhashhpall.c \
	func/lhashhrm.c \
	func/hash/lhashhdjb2.c \
	func/hash/lhashhoaat.c \
	func/hash/lhashhfnv.c 

OBJ = $(SRC:.c=.o)

$(STATIC): $(OBJ)
	@echo "[Link (Static)]"
	@ar rcs $@ $^

.c.o:
	@echo [Compile] $<
	@$(CC) -D LHASHH_RM_DEF_FOR_OBJ_COMP -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(STATIC)

.PHONY: test
test: 
	gcc test/lhashhtst.c -o test/a.out $(STATIC)



