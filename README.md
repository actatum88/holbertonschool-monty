Learning about Stacks, Queues, FIFO, LIFO for Holberton School Tulsa, Oklahoma.

The goal of this project is to create an interpreter for Monty ByteCodes files.

## Tasks
0. Implement the push and pall opcodes.
1. Implement the pint opcode.
2. Implement the pop opcode.
3. Implement the swap opcode.
4. Implement the add opcode.
5. Implement the nop opcode.

## Examples

<pre><code>atatum/dcorley:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
atatum/dcorley:~/monty$
</pre></code>

<pre><code>atatum/dcorley:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
atatum/dcorley:~/monty$
</pre></code>

## File Descriptions
* **monty.h - Header file that contains all the prototypes and the struct used to make the Monty interpreter functional.
* **main.c - Main function file that executes the Monty interpreter. It utilizies the prototype: "" . It returns: 
* **ops.c - Contains the opcodes push & pall.
* **errcat.c - Contains the errcat function to write to sh-style error messages.
* **opcode.c - Contains the pint function to write to the top of the stack.



##Authors
Alexandra Tatum & Dave Corley

