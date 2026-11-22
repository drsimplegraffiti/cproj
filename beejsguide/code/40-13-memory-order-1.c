atomic_int x = 0;

atomic_fetch_add(&x, 5);  // Sequential consistency, the default
