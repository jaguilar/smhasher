#include "pstdint.h"

#define to_signed_hash(v) ((intptr_t)v)

inline void string_hash_indices_n(void *_key, int len, uint32_t seed, intptr_t *_h)
{
  const char *key = (char *)_key;
  uintptr_t i, h, h2;

  h = seed;
  i = 0;
  while (i < len) {
    int c = key[i++];
    h += (h << 5) + h + c;
  }

  if (_h)
    *_h = to_signed_hash(h);
}

void Racket_test( const void* key, int len, uint32_t seed, void * out ) {
    string_hash_indices_n((void*)key, len, seed, (intptr_t*)out);
}