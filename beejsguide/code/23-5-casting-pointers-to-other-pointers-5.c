int a = 0x12345678;
short b = *((short *)&a);   // Violates strict aliasing
