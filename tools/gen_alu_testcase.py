# `define ALU_ADD   4'd0
# `define ALU_SUB   4'd1
# `define ALU_SLL   4'd2
# `define ALU_SLT   4'd3
# `define ALU_SLTU  4'd4
# `define ALU_XOR   4'd5
# `define ALU_SRL   4'd6
# `define ALU_SRA   4'd7
# `define ALU_OR    4'd8
# `define ALU_AND   4'd9

import random


def one_test_case(op: str):
    lhs = random.randrange(0, 100)
    rhs = random.randrange(0, 20)
    if (lhs < rhs):
        lhs, rhs = rhs, lhs
    return f"`test_alu(`ALU_{op}, 32'd{lhs}, 32'd{rhs})"


if __name__ == '__main__':
    opes = ["ADD", "SUB", "SLL", "SLT", "SLTU",
            "XOR", "SRL", "SRA", "OR", "AND"]

    for op in opes:
        line = one_test_case(op)
        print(f"\t{line};")
