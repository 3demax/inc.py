import os

from compiler import compile_program


def compile(ast):
    code = compile_program(ast)
    with open('code.s', 'w') as f:
        f.write(code)
    os.system('gcc -m32 -Wall code.s runtime.c -o test')
    os.system('./test > out.txt')
    with open('out.txt') as f:
        text = f.read()
    return text


if __name__ == '__main__':
    cases = [
        [0, "0\n"],
        [1, "1\n"],
        [-1, "-1\n"],
        [10, "10\n"],
        [-10, "-10\n"],
        [2736, "2736\n"],
        [-2736, "-2736\n"],
        [536870911, "536870911\n"],
        [-536870912, "-536870912\n"],
    ]
    for input, expected in cases:
        result = compile(input)
        try:
            assert result == expected
        except:
            print('{} => {}, expected {}'.format(input, result, expected))

    cases = [
        [True, "True\n"],
        [False, "False\n"],
        [None, "None\n"],
    ]
    for input, expected in cases:
        result = compile(input)
        try:
            assert result == expected
        except:
            print('{} => {}, expected {}'.format(input, result, expected))
