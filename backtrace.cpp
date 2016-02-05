#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#define UNW_LOCAL_ONLY
#include <libunwind.h>

#include <cxxabi.h>

#include <stdio.h>
#include <stdlib.h>

void backtrace()
{
  unw_cursor_t cursor;
  unw_context_t context;

  unw_getcontext(&context);
  unw_init_local(&cursor, &context);

  int n=0;
  while ( unw_step(&cursor) ) {
    unw_word_t ip, sp, off;

    unw_get_reg(&cursor, UNW_REG_IP, &ip);
    unw_get_reg(&cursor, UNW_REG_SP, &sp);

    char symbol[256] = {"<unknown>"};
    char *name = symbol;

    if ( !unw_get_proc_name(&cursor, symbol, sizeof(symbol), &off) ) {
      int status;
      if ( (name = abi::__cxa_demangle(symbol, NULL, NULL, &status)) == 0 )
        name = symbol;
    }

    printf("#%-2d 0x%016" PRIxPTR " sp=0x%016" PRIxPTR " %s + 0x%" PRIxPTR "\n",
        ++n,
        static_cast<uintptr_t>(ip),
        static_cast<uintptr_t>(sp),
        name,
        static_cast<uintptr_t>(off));

    if ( name != symbol )
      free(name);
  }
}

int fac(int n)
{
  if ( n == 0 ) {
    backtrace();
    return 1;
  } else {
    return n*fac(n-1);
  }
}

int main()
{
  fac(10);
  return 0;
}
