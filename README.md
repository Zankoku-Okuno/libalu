predithmatic
============

C library for predictable (no undefined behavior) arithmetic and logical operations.


Goals
-----

The C Standard, in the interests of portability, put lots of undefined behavior into the basic arithmetic operations.
In addition, they've targeted the lowest-common denominator by not allowing access to parts of the hardware such as the carry flag.

The reasoning behind the committee's choice does make good sense, but running into undefined behavior with normal C operators is easier than you think.
If you need a systems language and care about any choice of two from performance, security, or portability, then plain C operators are risky business.
The solutions to potential undefined behavior are well-known, so it's possible to audit a codebase with enough effort.

This library aims to make these time-consuming audits unnecessary in C.
The operations in predithmatic are known to be portable and never perform undefined behavior.
The structure of this library allows for platform-specific optimizations to be made in the future.
With liberal inlining, these operations can be compiled down to run as efficiently as possible.

In practice, there are only a few kinds of behavior we want to get from our arithmetic:
wrapping, checking for overflow, and carrying overflow, each for the common C integer and unsigned integer types.
Casting between integer types can also trigger undefined behavior, so we treat that here.
While we're at it, it might be convenient to have various bit-twiddling functions.

Usage
-----

Predithmatic defines a number of structs and functions.
Each function is of the form `<operation><mode>_<type>`.

The mode can be `F` (flag problems), `W` (wrap), `C` (carry/borrow), or `S` (saturate).
NOTE: At the moment, signed types only support `F` mode, and `S` mode is unsupported.
Operations include common arithmetic, logical, or bit-twiddle operations.
One special operation, which has no mode, is the `precision_<type>` operation, which returns the number of bits of precision in unsigned integer types.
Several types are supported under short names (e.g. `i32`, `i64`, `u8`); see `codegen/types.data` for a database of supported types.

Consistent use of these operations will avoid all undefined, unspecified, or implementation-defined behavior mandated in the C standard.
For more information on these undefined behaviors, see [SEI CERT C Coding Standard](https://resources.sei.cmu.edu/library/asset-view.cfm?assetid=454220), sections INT30-C through INT36-C.
Of particular note is that division by zero in `divmod` and `quotrem` is handled by returning a `.mod`/`.rem` member of `0` (except in `F` mode, where the `sticky_bit` is set).
Otherwise, the most common cause of error is overflow or unintended wrapping in the result, which is handled in the obvious way relative to the mode.


The product of building predithmatic (see below), are in the `include` and `lib` directories.
For each operation, in each mode, in each size, there are corresponding `include/<op><mode>_<type>.h`, `include/<op><mode>_<type>.inl.h`, and `lib/<op><mode>_<type>.o`.
There are a number of additional headers for structs (`<struct>_<type>.h`).
None of these headers include other headers, but they do note their dependencies space-separated in a line starting with `// DEPS: `.

The `.h` headers define structs and prototypes and so should be included before your code.
The `.inl.h` headers define inline functions and should be included wherever you wish to take advantage of inline optimizations (almost everywhere).
My personal preference is to include these `.inl.h` headers after your code so that if your code relies on implementation detail it will fail to compile.

Once your code has compiled, statically link it against any the `.o` files corresponding to any `.h` files you used.
Failure to do so could result in linker errors when building an executable.

There are also headers `precision.h` and `precision.inl.h` which include all the precision operations.
In the future, there will be more convenience headers that aggregate commonly-used-together operations.


Building
--------

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

Running `generate.sh` creates up to three files:
  * `<op>_<type><mode>.h`: a header file with the prototypes
  * `<op>_<type><mode>.c`: a translation unit defining symbols for the operations
  * `<op>_<type><mode>.inl.h`: a header file giving the inline definitions
Compiling the generated translation units is done with `compile.sh <translation unit>`.
Additional arguments can be passed to the compiler with `$CFLAGS`. FIXME: that seems not to work.


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
    - [ ] precision
        - [ ] signed
        - [x] unsigned
- [ ] portable alignment utilities
    - [x] unsigned carry, flag, wrap modes
    - [x] signed flag mode
    - [ ] signed carry, wrap modes
- [ ] conversion operations
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
