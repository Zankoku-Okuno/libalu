predithmatic
============

C library for predictable (no undefined behavior) arithmetic and logical operations.


Goals
-----

The C Standard, in the interests of portability, put lots of undefined behavior into the basic arithmetic operations.
In addition, they've targeted the lowest-common denominator by not allowing access to parts of the hardware such as the carry flag.

I understand the reasoning behind the committee's choice, but running into undefined behavior with normal C operators is easier than you think.
If you need a systems language and care about any choice of two from performance, security, or portability, then plain C operators are risky business.
The solutions to potential undefined behavior are well-known, so it's possible to audit a codebase with enough effort.

This library aims to make these sorts of audits unnecessary in C.
The operations in predithmatic are known to be portable and never perform undefined behavior.
The structure of this library allows for platform-specific optimizations to be made in the future.
With liberal inlining, these operations can be compiled down to run as efficiently as possible.

In practice, there are only a few kinds of behavior we want to get from our arithmetic:
wrapping, checking for overflow, and carrying overflow, each for the common C integer and unsigned integer types.
Casting between integer types can also trigger undefined behavoir, so we treat that here.
While we're at it, it might be convenient to have various bit-twiddling functions.


Building & Usage
----------------

This library is licensed under the 3-clause BSD license (see LICENSE file).

This library targets C99, not older versions of C.

Many of the functions in this library are the same except for a change in types.
To avoid repeatign so much C code, we therefore generate code for each operation using templates in `codegen`.
The generation itself is done with `generate.sh <operation> <type (short name)> <mode>`.

The templates are simple substitution templates.
There are four replaced variables:
  * `@T`: short name
  * `@TYPE`: name of C type
  * `@MAX`: maximum possible value
  * `@MIN`: minimum possible value
These variables are looked up using `types.data` based on the short name passed to `generate.sh`.
The database also contains a `LOCATION` column to switch templates bsed on the type.
The database is human-readable, so check that for more detail, especially the short names.
Note that tabs---not spaces---are used as column separators, so be sure to check your whitespace when editing the database.

Running `generate.sh` creates three files:
  * `<op>_<type><mode>.h`: a header file with the prototype
  * `<op>_<type><mode>.c`: a translation unit defining a symbol for the operation
  * `<op>_<type><mode>.inl.h`: a header file giving the inline definition
To use these operations in a C program:
  * include the prototypes you need (and any headers they require) near the top of the file
  * write your code
  * include the associated inline definitions at the end of the file
  * compile the translation units of operations your program uses
  * link those translation units with your porogram

Compiling the generated translation units is done with `compile.sh <translation unit>`.
Additional arguments can be passed to the compiler with `$CFLAGS`.


Contributing
------------

At this early stage, just hop in and send [pull requests](https://github.com/Zankoku-Okuno/predithmatic/pulls).
We can bring stuff up to coding standards after getting basic features in.

I want to keep this library uniformly licensed under the 3-clause BSD license, so those are the terms under which your pull requests will be merged.
I've chosen a permissive license because I want to help all software be more secure, even comercial software, since people do need it from time-to-time.

The only things I'm going to make sure you do are:
 * Rob Pike's [Simple rule](http://www.lysator.liu.se/c/pikestyle.html): include files should never include include files.
 * Never drop "optional" braces in `if`, `else`, `for`, &c.


Status
------

- [ ] portable arithmetic operations
    - [x] unsigned add, sub, mul, divmod
        - [x] carry, flag, wrap modes
    - [ ] signed neg, add, sub, mul, divmod, quotrem
        - [x] flag mode
        - [ ] carry, wrap modes
- [ ] portable alignment utilities
    - [x] unsigned carry, flag, wrap modes
    - [x] signed flag mode
    - [ ] signed carry, wrap modes
- [ ] machine/compiler-specific performance improvements
    - [ ] gcc
    - [ ] clang
    - [ ] _investigate_: cover which machines for when compiler not recognized or compiler doesn't recognize machine
- [ ] portable bit twiddle operators
    - [ ] shl, shr, rot, bit test, popcount, count leading/trailing zeros/ones
- [ ] saturating mode
    - [ ] unsigned arithmetic
    - [ ] signed arithmetic
- [ ] _investigate_: macros for ease-of-use
