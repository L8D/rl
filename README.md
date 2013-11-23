RL
==

RL is a simple stack-based programming language similar to FORTH.

Install
-------

```bash
$ make
gcc -Wall -std=c99 -Werror rl.c -o rl.o
ln -s rl.o rl
$ ./rl
> 5 2 * .
10
> ^D
$
```
