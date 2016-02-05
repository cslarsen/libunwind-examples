libunwind examples
==================

A few libunwind examples:

  * backtrace.cpp --- shows a demangled backtrace.
  * more to come ...

Build instructions
==================

On OSX, you should be able to just build as is. On other systems, you need to
link with `-lunwind`. You also need `cxxabi.h`, part of libstdc++.

I've used `-O0` for the examples, because llvm is surprisingly good at doing
tail call elimination.

Interesting pointers
====================

  * "Deep Wizardry: Stack Unwinding",
    http://blog.reverberate.org/2013/05/deep-wizardry-stack-unwinding.html

License
=======

Made by Christian Stigen Larsen in 2016  
Put in the public domain.
