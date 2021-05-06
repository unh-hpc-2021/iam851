
#ifndef WTIME_H
#define WTIME_H

#include <sys/time.h>
#include <stdlib.h>

static inline double
Wtime(void)
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec + tv.tv_usec / 1e6;
}

#endif
