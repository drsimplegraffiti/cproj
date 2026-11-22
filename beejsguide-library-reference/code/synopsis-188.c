#include <stdlib.h>

// Pre-C23:

void *bsearch(const void *key, const void *base,
              size_t nmemb, size_t size,
              int (*compar)(const void *, const void *));
// C23:

QVoid *bsearch(const void *key, QVoid *base,
               size_t nmemb, size_t size,
               int (*compar)(const void *, const void *));
