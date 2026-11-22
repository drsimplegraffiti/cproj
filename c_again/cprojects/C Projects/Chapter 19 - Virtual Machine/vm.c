/*
 * Chapter 19 - Virtual Machine in C
 * vm.c - stack-based virtual machine executing a mini bytecode language.
 *
 * Instruction set:
 *   PUSH <value>  - push value onto stack      (0x01)
 *   ADD           - pop two, add, push result   (0x02)
 *   SUB           - pop two, subtract, push     (0x03)
 *   MUL           - pop two, multiply, push     (0x04)
 *   PRINT         - pop top and print           (0x05)
 *   0x00          - end of program (halt)
 *
 * Compile: gcc vm.c -o vm
 * Run:     ./vm
 */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 256

typedef enum {
    PUSH  = 0x01,
    ADD   = 0x02,
    SUB   = 0x03,
    MUL   = 0x04,
    PRINT = 0x05,
    HALT  = 0x00
} Instruction;

typedef struct {
    int stack[STACK_SIZE];
    int sp;            /* stack pointer */
    unsigned char* bytecode;
    int pc;            /* program counter */
} VM;

static void vm_init(VM* vm, unsigned char* bytecode) {
    vm->sp = -1;
    vm->bytecode = bytecode;
    vm->pc = 0;
}

static void push(VM* vm, int value) {
    if (vm->sp < STACK_SIZE - 1) {
        vm->stack[++(vm->sp)] = value;
    } else {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
}

static int pop(VM* vm) {
    if (vm->sp >= 0) {
        return vm->stack[(vm->sp)--];
    } else {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
}

static void vm_execute(VM* vm) {
    while (vm->bytecode[vm->pc] != HALT) {
        unsigned char instruction = vm->bytecode[vm->pc++];

        switch (instruction) {
            case PUSH: {
                int value = vm->bytecode[vm->pc++];
                push(vm, value);
                break;
            }
            case ADD: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a + b);
                break;
            }
            case SUB: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a - b);
                break;
            }
            case MUL: {
                int b = pop(vm);
                int a = pop(vm);
                push(vm, a * b);
                break;
            }
            case PRINT: {
                int value = pop(vm);
                printf("%d\n", value);
                break;
            }
            default:
                fprintf(stderr, "Unknown instruction 0x%x\n", instruction);
                exit(1);
        }
    }
}

int main(void) {
    /* Sample bytecode: PUSH 3, PUSH 4, PUSH 5, ADD, PRINT
       Stack: [3,4,5] -> ADD pops 5+4=9, stack [3,9] -> PRINT prints 9 */
    unsigned char bytecode[] = {PUSH, 3, PUSH, 4, PUSH, 5, ADD, PRINT, HALT};

    VM vm;
    vm_init(&vm, bytecode);

    printf("Executing bytecode program:\n");
    printf("  PUSH 3, PUSH 4, PUSH 5, ADD, PRINT\n");
    printf("Output:\n");
    vm_execute(&vm);

    return 0;
}
