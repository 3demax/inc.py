# The boolean values #f and #t will be represented as the boolean numbers
TRUE  = 0b01101111
FALSE = 0b00101111
NONE  = 0x3F
# We have chosen two numbers that differ by one bit
# only to make distinguishing booleans from other objects easy.
# An object can be masked with 0b10111111 to determine if these bits are 0b00101111


def compile_program(x):
    template = [
        '   .text',
        '   .p2align 4',
        '.globl	py_entry',
        '.type	py_entry, @function',
        'py_entry:',
        '   movl	${}, %eax',
        '   ret',
    ]
    if type(x) == int:
        val = x << 2
    elif type(x) == bool:
        val = TRUE if x else FALSE
    elif isinstance(x, type(None)):
        val = NONE
    return '\n'.join(template).format(str(val)) + '\n'


if __name__ == '__main__':
    code = compile_program(42)
    with open('code.s', 'w') as f:
        f.write(code)
