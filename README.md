### MooMoo - a file encoder/decoder

This project implements two commands in C, ```moo``` and ```unmoo```,
that will encode and decode a file in the **MooMoo** encoding scheme.
While not intended to be useful in and of itself, the program is an
example of how to structure a small to medium sized C command-line program.

Absolutely *blatantly* ripped off from <https://github.com/JnyJny/meowmeow/>

#### Requirements

- C compiler
- GNU make

#### Build

0. Clone

```bash
   $ git clone https://github.com/biggnome/MooMoo.git
```

1. Compile
```bash
   $ make
```

2. Run
```bash
   $ ./moo < clear_text > moo_text
   $ ./unmoo < moo_text | diff clear_text
   $
```

#### MooMoo Encoding Scheme

The **MooMoo** encoding scheme is direct rip-off of another encoding
scheme, [MooMoo Encode][1]. In short, each byte in file is encoded
into a string "mooomooo" where uppercase indicates a 1 and lowercase
is a zero, in this case the string encodes a zero. Consider these three
bytes:

```C
   unsigned char zeros = 0x0;
   unsigned char ones = 0xff;
   unsigned char camel = 0xA5;
```

- The value in ```zeros``` encodes to "mooomooo".
- The value in ```ones``` encodes to "MOOOMOOO".
- The value in ```camel``` encodes to "MoOomOoO.
   
[1]: http://www.jabberwocky.com/software/moomooencode.html
