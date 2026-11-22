/*
 * Chapter 18 - Basic Compiler (Mini Language to C)
 * compiler.c - tokenizes and parses CalcLang arithmetic expressions,
 * then generates equivalent C code.
 *
 * Supported grammar:
 *   expr  = term { ('+' | '-') term }
 *   term  = factor { ('*' | '/') factor }
 *   factor = NUM
 *
 * Compile: gcc compiler.c -o compiler
 * Run:     ./compiler
 */

#include <stdio.h>
#include <ctype.h>

typedef enum {
    NUM, PLUS, MINUS, STAR, SLASH, END
} TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

static const char* input;
static int index = 0;

static Token get_next_token(void) {
    Token token;
    char current_char = input[index];

    /* Skip whitespace */
    while (isspace((unsigned char)current_char)) {
        index++;
        current_char = input[index];
    }

    if (isdigit((unsigned char)current_char)) {
        token.type = NUM;
        token.value = 0;
        while (isdigit((unsigned char)current_char)) {
            token.value = token.value * 10 + (current_char - '0');
            index++;
            current_char = input[index];
        }
        return token;
    }

    if (current_char == '+') { token.type = PLUS; index++; return token; }
    if (current_char == '-') { token.type = MINUS; index++; return token; }
    if (current_char == '*') { token.type = STAR; index++; return token; }
    if (current_char == '/') { token.type = SLASH; index++; return token; }

    if (current_char == '\0') { token.type = END; return token; }

    /* Unexpected character */
    token.type = END;
    return token;
}

/* Forward declarations */
static int parse_expr(void);
static int parse_term(void);
static int parse_factor(void);

/* expr = term { ('+' | '-') term } */
static int parse_expr(void) {
    int result = parse_term();
    Token token = get_next_token();
    while (token.type == PLUS || token.type == MINUS) {
        int rhs = parse_term();
        if (token.type == PLUS) result += rhs;
        else result -= rhs;
        token = get_next_token();
    }
    index--; /* push back the non-operator token */
    return result;
}

/* term = factor { ('*' | '/') factor } */
static int parse_term(void) {
    int result = parse_factor();
    Token token = get_next_token();
    while (token.type == STAR || token.type == SLASH) {
        int rhs = parse_factor();
        if (token.type == STAR) result *= rhs;
        else result /= rhs;
        token = get_next_token();
    }
    index--;
    return result;
}

/* factor = NUM */
static int parse_factor(void) {
    Token token = get_next_token();
    if (token.type == NUM) {
        return token.value;
    }
    index--;
    return 0;
}

/* Evaluate expression and print result */
static int evaluate(const char* expr) {
    input = expr;
    index = 0;
    return parse_expr();
}

/* Generate C source code for the expression */
static void generate_code(const char* expr) {
    printf("#include <stdio.h>\n\n");
    printf("int main() {\n");
    printf("  printf(\"%d\\n\", %s);\n", evaluate(expr), expr);
    printf("  return 0;\n");
    printf("}\n");
}

int main(void) {
    const char* expr = "3 + 4 * 5";

    printf("Input expression: %s\n", expr);
    int result = evaluate(expr);
    printf("Evaluated result: %d\n\n", result);

    printf("Generated C code:\n");
    printf("-----------------\n");
    generate_code(expr);
    printf("-----------------\n");

    return 0;
}
