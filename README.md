predithmatic
============

C library for predictable (no undefined behavior) arithmetic and logical operations.


Goals
-----

The C Standard, in the interests of portability, put lots of undefined behavior into the basic arithmetic operations.
In addition, they've targeted the lowest-common denominator by not allowing access to parts of the hardware such as the carry flag.
This cripples programs that care about performance, security, and portability.
Running into these undefined behaviors is common, so it's hard to audit a code base;
when (not if) you (hopefully not an attacker) do find the problem, you have a choice between portability and performance.
Then, even though the solutions are well-known, it seems no one has bothered to package it up into a library, so you have to reimplement this wheel yourself.

In practice, there are only a few kinds of behavior we want to get from our arithmetic:
wrapping, checking for overflow, and carrying overflow, each for word sizes of the form `8 * 2^n`.
There could be a library for this; there should be a library for this; there must be a library for this.
I couldn't find it, so it's time to fix this situation.


Usage
-----

This library is licensed under the 3-clause BSD license (see LICENSE file).

TODO figure out build system

Include the general header `<type>.h`, your choice of platform's header `<type>-<platform>.h` and their (documented at top of file) requirements anywhere you use the operations for the type.
In case any of the operations was not inlined, compile your choice of platform's source file `<type>-<platform>.c`, and link it into your object(s).

This library targets C99, not older versions of C.


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
- [ ] portable quot, rem, quotrem operations
- [ ] fast gcc/clang divmod and quotrem
- [ ] carry-mode: add, mul, neg
- [ ] logical operators (shl, shr, rot, bit test, popcount, ffs/ffz/fls/flz)
- [x] alignment functions (upto, backto)
- [ ] wrapping-mode arithmetic operators
- [ ] macros for ease-of-use



Here's a full list of what I'd like to do, moderately prioritized:
 * wrap, check overflow, carry overflow, possibly saturate
 * add, sub, mul, div, rem, divmod, quotrem
 * align_upto, align_backto
 * shift/rotate, popcount, find {first,last} {set,zero} bit
 * signed/unsigned 8,16,32,64-bit, `size_t`, `uintptr_t`, `intptr_t`, `ptrdiff_t`
 * portable (potentially slow) implementations
 * performant operations for x64, ARM, x32, possibly others
 * optimizable operations through gcc, clang, possibly others
 * ease-of-use macros

