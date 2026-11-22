union u {
    int a;
    float b;
};

union u x0 = {1};  // Initialize the first field (a)

union u x0 = {.a=1};  // Initialize fields by name
union u x0 = {.b=2.2};

//union u x0 = {1, 2};       // ILLEGAL
//union u x0 = {.a=1, .b=2};  // ILLEGAL
