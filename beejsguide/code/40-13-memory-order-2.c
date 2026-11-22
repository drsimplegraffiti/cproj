atomic_int x = 0;

atomic_fetch_add_explicit(&x, 5, memory_order_seq_cst);
