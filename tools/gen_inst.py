import argparse
from typing import Optional
import random


def option_atoi(s: Optional[str]) -> Optional[int]:
    return int(s) if s is not None else None


class RISCVInstruction:
    def __init__(self, op: str, rs1: Optional[int], rs2: Optional[int], rd: Optional[int]):
        self.op = op

        if rs1 is None:
            rs1 = random.randint(0, 31)

        if rs2 is None:
            rs2 = random.randint(0, 31)

        if rd is None:
            rd = random.randint(0, 31)

        self.rs1 = rs1
        self.rs2 = rs2
        self.rd = rd

        self.imm = 0

    def instruction(self):
        inst_type = RISCVInstruction.inst_form(self.op)
        opc, f3, f7 = RISCVInstruction.op_f3_f7(self.op)

        assert inst_type is not None

        if inst_type == "R":
            return RISCVInstruction.form_r(opc, f3, f7, self.rs1, self.rs2, self.rd)
        elif inst_type == "I":
            return RISCVInstruction.form_i(opc, f3, self.rs1, self.rd)
        elif inst_type == "S":
            return RISCVInstruction.form_s(opc, f3, self.rs1, self.rs2)
        elif inst_type == "B":
            return RISCVInstruction.form_b(opc, f3, self.rs1, self.rs2)
        elif inst_type == "U":
            return RISCVInstruction.form_u(opc, self.rd)
        elif inst_type == "J":
            return RISCVInstruction.form_j(opc, self.rd)
        elif inst_type == "SI":
            return RISCVInstruction.form_si(opc, f3, f7, self.rs1, self.rd)
        else:
            print("[warn] not reachable")

    @staticmethod
    def from_args(args):
        return RISCVInstruction(args.op, option_atoi(args.rs1), option_atoi(args.rs2), option_atoi(args.rd))

    @staticmethod
    def inst_form(op: str) -> Optional[str]:
        if op in ["ADD", "SUB", "SLL", "SLT", "SLTu", "XOR", "SRL", "SRA", "OR", "AND"]:
            return "R"
        elif op in ["ADDi", "SLTi", "SLTiu", "XORi", "ORi", "ANDi", "Lb", "Lh", "Lw", "Lbu", "Lhu", "JALR"]:
            return "I"
        elif op in ["Sb", "Sh", "Sw"]:
            return "S"
        elif op in ["Beq", "Bne", "Blt", "Bge", "Bltu", "Bgeu"]:
            return "B"
        elif op in ["LUi", "AUiPC"]:
            return "U"
        elif op in ["JAL"]:
            return "J"
        elif op in ["XORi", "ORi", "ANDi"]:
            return "SI"
        else:
            print("[warn] not reachable - inst_form()")
            return None

    @staticmethod
    def op_f3_f7(op: str):
        if op == "ADDi":
            return 19, 0, None
        elif op == "SLTi":
            return 19, 2, None
        elif op == "SLTiu":
            return 19, 3, None
        elif op == "XORi":
            return 19, 4, None
        elif op == "ORi":
            return 19, 6, None
        elif op == "ANDi":
            return 19, 7, None
        elif op == "SLLi":
            return 19, 1, 0
        elif op == "SRLi":
            return 19, 5, 0
        elif op == "SRAi":
            return 19, 5, 32

        elif op == "ADD":
            return 51, 0, 0
        elif op == "SUB":
            return 51, 0, 32
        elif op == "SLL":
            return 51, 1, 0
        elif op == "SLT":
            return 51, 2, 0
        elif op == "SLTu":
            return 51, 3, 0
        elif op == "XOR":
            return 51, 4, 0
        elif op == "SRL":
            return 51, 5, 0
        elif op == "SRA":
            return 51, 5, 32
        elif op == "OR":
            return 51, 6, 0
        elif op == "AND":
            return 51, 7, 0

        elif op == "LUi":
            return 55, None, None
        elif op == "AUiPC":
            return 23, None, None
        elif op == "JAL":
            return 111, None, None
        elif op == "JALR":
            return 103, 0, None

        elif op == "Beq":
            return 99, 0, None
        elif op == "Bne":
            return 99, 1, None
        elif op == "Blt":
            return 99, 4, None
        elif op == "Bge":
            return 99, 5, None
        elif op == "Bltu":
            return 99, 6, None
        elif op == "Bgeu":
            return 99, 7, None

        elif op == "Sb":
            return 35, 0, None
        elif op == "Sh":
            return 35, 1, None
        elif op == "Sw":
            return 35, 2, None

        elif op == "Lb":
            return 3, 0, None
        elif op == "Lh":
            return 3, 1, None
        elif op == "Lw":
            return 3, 2, None
        elif op == "Lbu":
            return 3, 4, None
        elif op == "Lhu":
            return 3, 5, None

        else:
            return None, None, None

    @staticmethod
    def form(inst_dec: int) -> str:
        return hex(inst_dec).replace("0x", "32'h")

    @staticmethod
    def form_r(opcode: int, f3: int, f7: int, rs1: int, rs2: int, rd: int) -> str:
        inst_dec = opcode + rd * 2 ** 7 + f3 * 2 ** 12 + \
            rs1 * 2 ** 15 + rs2 * 2 ** 20 + f7 * 2 ** 25

        return RISCVInstruction.form(inst_dec)

    @staticmethod
    def form_si(opcode: int, f3: int, f7: int, rs1: int, rd: int, imm: int = 0) -> str:
        inst_dec = opcode + rd * 2 ** 7 + f3 * 2 ** 12 + \
            rs1 * 2 ** 15 + imm * 2 ** 20 + f7 * 2 ** 25

        return RISCVInstruction.form(inst_dec)

    @staticmethod
    def form_i(opcode: int, f3: int, rs1: int, rd: int, imm: int = 0) -> str:
        inst_dec = opcode + rd * 2 ** 7 + f3 * 2 ** 12 + rs1 * 2 ** 15 + imm * 2 ** 20

        return RISCVInstruction.form(inst_dec)

    @staticmethod
    def form_s(opcode: int, f3: int, rs1: int, rs2: int, imm1: int = 0, imm2: int = 0) -> str:
        inst_dec = opcode + imm1 * 2 ** 7 + f3 * 2 ** 12 + \
            rs1 * 2 ** 15 + rs2 * 2 ** 20 + imm2 * 2 ** 25

        return RISCVInstruction.form(inst_dec)

    @staticmethod
    def form_b(opcode: int, f3: int, rs1: int, rs2: int, imm1: int = 0, imm2: int = 0, imm3: int = 0, imm4: int = 0) -> str:
        return RISCVInstruction.form_s(opcode, f3, rs1, rs2, imm1 + imm2 * 2, imm3 + imm4 * 2 ** 6)

    @staticmethod
    def form_u(opcode: int, rd: int, imm: int = 0) -> str:
        inst_dec = opcode + rd * 2 ** 7 + imm * 2 ** 12

        return RISCVInstruction.form(inst_dec)

    @staticmethod
    def form_j(opcode: int, rd: int, imm1: int = 0, imm2: int = 0, imm3: int = 0, imm4: int = 0) -> str:
        inst_dec = opcode + rd * 2 ** 7 + imm1 * 2 ** 12 + \
            imm2 * 2 ** 20 + imm3 * 2 ** 21 + imm4 * 2 ** 30

        return RISCVInstruction.form(inst_dec)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument("--op")
    parser.add_argument("--rs1")
    parser.add_argument("--rs2")
    parser.add_argument("--rd")

    args = parser.parse_args()

    for op in ["Sb", "Sh", "Sw", "Beq", "Bne", "Blt", "Bge", "Bltu", "Bgeu", "LUi", "AUiPC", "XORi", "ORi", "ANDi"]:
        # for op in ["ADDi", "SLTi", "SLTiu", "XORi", "ORi", "ANDi", "Lb", "Lh", "Lw", "Lbu", "Lhu", "JALR", "ADD", "SUB", "SLL", "SLT", "SLTu", "XOR", "SRL", "SRA", "OR", "AND"]:
        args.op = op
        inst = RISCVInstruction.from_args(args)
        print(inst.instruction())
