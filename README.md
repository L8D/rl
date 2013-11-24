RL
==

RL is a simple stack-based programming language similar to FORTH.

Install
-------

RL only requires a C99 compiler. `gcc` is recommended and used in the
`Makefile`. To compile and use just type `make` and use the `rl` binary that is
generated.

```bash
$ make
gcc -Wall -std=c99 -Werror rl.c -o rl.o
ln -s rl.o rl
$ echo "10 10 + ." | ./rl
20
$
```
