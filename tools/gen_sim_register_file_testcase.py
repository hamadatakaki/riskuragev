def gen_instructions(n_line: int) -> str:
    rs1 = n_line
    rs2 = 31 - n_line

    inst = rs2 * 2 ** 20 + rs1 * 2 ** 15 + 19

    return format(inst, "#010x")[2:]


def gen_register_data(n_line):
    ud = n_line // 16
    v = n_line % 16
    inst = int((16 ** 4 - 1) / (16 - 1))
    inst *= v
    if ud == 1:
        inst *= 16 ** 4

    return format(inst, "#010x")[2:]


if __name__ == "__main__":
    for i in range(32):
        print(gen_instructions(i))

    print()

    for i in range(32):
        print(gen_register_data(i))
