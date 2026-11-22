va_copy(dest, src);
va_copy(dest, src2);  // BAD!

va_copy(dest, src);
va_start(dest, var);  // BAD!

va_copy(dest, src);
va_end(dest);
va_copy(dest, src2);  // OK!

va_copy(dest, src);
va_end(dest);
va_start(dest, var);  // OK!
