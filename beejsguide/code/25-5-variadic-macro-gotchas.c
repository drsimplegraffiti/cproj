va_start(va, format);          // may contain {
int rv = vprintf(format, va);
va_end(va);                    // may contain }

return rv;
