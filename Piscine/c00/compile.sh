#!/bin/

FLAGS="-Wall -Wextra -Werror"

norminette -R CheckForbiddenSourceHeader

gcc $FLAGS -o test00 main00.c ex00/*.c
gcc $FLAGS -o test01 main01.c ex01/*.c
gcc $FLAGS -o test02 main02.c ex02/*.c
gcc $FLAGS -o test03 main03.c ex03/*.c
gcc $FLAGS -o test04 main04.c ex04/*.c
gcc $FLAGS -o test05 main05.c ex05/*.c
gcc $FLAGS -o test06 main06.c ex06/*.c
gcc $FLAGS -o test07 main07.c ex07/*.c
gcc $FLAGS -o test08 main08.c ex08/*.c
