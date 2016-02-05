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

Example: backtrace.cpp
----------------------

Shows how to print a backtrace.

You can double check that it works with `gdb` or `lldb`:

    $ make backtrace
    $ gdb ./backtrace
    GNU gdb (GDB) 7.9.1
    ...
    (gdb) break backtrace
    Breakpoint 1 at 0x40086e: file backtrace.cpp, line 17.
    (gdb) r
    Starting program: .../backtrace

    Breakpoint 1, backtrace () at backtrace.cpp:17
    17        unw_getcontext(&context);
    (gdb) bt
    #0  backtrace () at backtrace.cpp:17
    #1  0x0000000000400a02 in fac (n=0) at backtrace.cpp:51
    #2  0x0000000000400a16 in fac (n=1) at backtrace.cpp:54
    #3  0x0000000000400a16 in fac (n=2) at backtrace.cpp:54
    #4  0x0000000000400a16 in fac (n=3) at backtrace.cpp:54
    #5  0x0000000000400a16 in fac (n=4) at backtrace.cpp:54
    #6  0x0000000000400a16 in fac (n=5) at backtrace.cpp:54
    #7  0x0000000000400a16 in fac (n=6) at backtrace.cpp:54
    #8  0x0000000000400a16 in fac (n=7) at backtrace.cpp:54
    #9  0x0000000000400a16 in fac (n=8) at backtrace.cpp:54
    #10 0x0000000000400a16 in fac (n=9) at backtrace.cpp:54
    #11 0x0000000000400a16 in fac (n=10) at backtrace.cpp:54
    #12 0x0000000000400a2a in main () at backtrace.cpp:60
    (gdb) c
    Continuing.
    #1  0x0000000000400a02 sp=0x00007fffffffd7b0 fac(int) + 0x16
    #2  0x0000000000400a16 sp=0x00007fffffffd7d0 fac(int) + 0x2a
    #3  0x0000000000400a16 sp=0x00007fffffffd7f0 fac(int) + 0x2a
    #4  0x0000000000400a16 sp=0x00007fffffffd810 fac(int) + 0x2a
    #5  0x0000000000400a16 sp=0x00007fffffffd830 fac(int) + 0x2a
    #6  0x0000000000400a16 sp=0x00007fffffffd850 fac(int) + 0x2a
    #7  0x0000000000400a16 sp=0x00007fffffffd870 fac(int) + 0x2a
    #8  0x0000000000400a16 sp=0x00007fffffffd890 fac(int) + 0x2a
    #9  0x0000000000400a16 sp=0x00007fffffffd8b0 fac(int) + 0x2a
    #10 0x0000000000400a16 sp=0x00007fffffffd8d0 fac(int) + 0x2a
    #11 0x0000000000400a16 sp=0x00007fffffffd8f0 fac(int) + 0x2a
    #12 0x0000000000400a2a sp=0x00007fffffffd910 main + 0xe
    #13 0x0000003a7101ed5d sp=0x00007fffffffd920 __libc_start_main + 0xfd
    #14 0x00000000004007a9 sp=0x00007fffffffd9e0 _start + 0x29

Interesting pointers
====================

  * "Deep Wizardry: Stack Unwinding",
    http://blog.reverberate.org/2013/05/deep-wizardry-stack-unwinding.html

License
=======

Made by Christian Stigen Larsen in 2016  
Put in the public domain.
