#include <cxxabi.h>
#include <libunwind.h>
#include <stdio.h>
#include <stdlib.h>

void backtrace()
{
  unw_cursor_t cursor;
  unw_context_t context;

  unw_getcontext(&context);
  unw_init_local(&cursor, &context);

  while ( unw_step(&cursor) ) {
    unw_word_t ip, sp, off;

    unw_get_reg(&cursor, UNW_REG_IP, &ip);
    unw_get_reg(&cursor, UNW_REG_SP, &sp);

    char symbol[256] = {"<unknown>"};
    char *name = symbol;

    if ( !unw_get_proc_name(&cursor, symbol, sizeof(symbol), &off) ) {
      int status;
      if ( (name = abi::__cxa_demangle(symbol, nullptr, nullptr, &status)) == 0 )
        name = symbol;
    }

    printf("ip=%p sp=%p %s + %p\n", reinterpret_cast<void*>(ip),
        reinterpret_cast<void*>(sp), name, reinterpret_cast<void*>(off));

    if ( name != symbol )
      free(name);
  }
}

int fac(int n)
{
  if ( n == 0 ) {
    printf("Backtrace:\n");
    backtrace();
    return 1;
  } else {
    printf("fac(%d)\n", n);
    return n*fac(n-1);
  }
}

int main()
{
  printf("10! = %d\n", fac(10));
  return 0;
}
