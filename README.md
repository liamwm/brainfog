An interpreter for the programming language [Brainf***](https://en.wikipedia.org/wiki/Brainfuck) written in C.

My solution is neither time nor space-optimal - I did not prioritise efficiency as I wanted to use this exercise as a chance to learn more about interpreters and compilers. Therefore, my solution involves constructing a kind of [Abstract Syntax Tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree) from the input program. I hope to use this method to come up with a more sophisticated interpreter for a more complex language.

### Usage
Generate the binary:

```
make
```
Then use the interpreter like this:
```
./brainfog <path_to_bf_program>
```

There doesn't appear to be a universally agreed-upon file extension for Brainf*** - I have seen both `.bf` and `.b` used - nevertheless, you may name your text file whatever you want.