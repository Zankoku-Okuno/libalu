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

- [x] portable checking ops for size_t: add, sub, mul
- [x] portable check-mode ops for uint{8,16,32,64}_t: add, sub, mul
- [x] portable check-mode ops for int{8,16,32,64}_t: add, sub, mul
- [x] portable check-mode ops for uintptr_t, intptr_t, ptrdiff_t: add, sub, mul
- [ ] fast gcc check-mode ops for size_t and {,u}int{8,16,32,64}_t: add, mul
- [ ] fast clang check-mode ops for size_t and {,u}int{8,16,32,64}_t: add, mul
- [x] portable div, mod, divmod operations
- [x] negation for signed int types
- [x] portable quot, rem, quotrem operations
- [ ] fast gcc/clang divmod and quotrem
- [ ] carry-mode: add, mul, neg
- [ ] logical operators (shl, shr, rot, bit test, popcount, ffs/ffz/fls/flz)
- [x] alignment functions (upto, backto)
- [ ] wrapping-mode arithmetic operators
- [ ] macros for ease-of-use



Here's a full list of what I'd like to do, moderately prioritized:
 * wrap, check overflow, carry overflow, possibly saturate
 * add, sub, mul, div, mod, divmod, quotrem, quot, rem
 * align_upto, align_backto
 * shift/rotate, popcount, find {first,last} {set,zero} bit
 * signed/unsigned 8,16,32,64-bit, `size_t`, `uintptr_t`, `intptr_t`, `ptrdiff_t`
 * portable (potentially slow) implementations
 * performant operations for x64, ARM, x32, possibly others
 * optimizable operations through gcc, clang, possibly others
 * ease-of-use macros

