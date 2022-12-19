// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VCPU_H_
#define _VCPU_H_  // guard

#include "verilated.h"

//==========

class Vcpu__Syms;

//----------

VL_MODULE(Vcpu) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_OUT8(uart_tx,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*3:0*/ cpu__DOT__ctr;
    CData/*5:0*/ cpu__DOT__instruction_code;
    CData/*1:0*/ cpu__DOT__lhs_type;
    CData/*1:0*/ cpu__DOT__rhs_type;
    CData/*1:0*/ cpu__DOT__fetcher_option;
    CData/*0:0*/ cpu__DOT__uart_we;
    CData/*0:0*/ cpu__DOT__uart_OUT_data;
    CData/*3:0*/ cpu__DOT__exec0__DOT__alucode;
    CData/*3:0*/ cpu__DOT__main_memory0__DOT__mask_store;
    CData/*3:0*/ cpu__DOT__uart0__DOT__bitcount;
    CData/*0:0*/ cpu__DOT__uart0__DOT__uart_busy;
    CData/*0:0*/ cpu__DOT__uart0__DOT__sending;
    SData/*8:0*/ cpu__DOT__uart0__DOT__shifter;
    IData/*31:0*/ cpu__DOT__instruction;
    IData/*31:0*/ cpu__DOT__data_rs1;
    IData/*31:0*/ cpu__DOT__data_rs2;
    IData/*31:0*/ cpu__DOT__data_rd_exec;
    IData/*31:0*/ cpu__DOT__imm;
    IData/*31:0*/ cpu__DOT___data_rd_memory;
    IData/*31:0*/ cpu__DOT__fetcher0__DOT__pc;
    IData/*31:0*/ cpu__DOT__exec0__DOT__rhs;
    IData/*31:0*/ cpu__DOT__exec0__DOT__lhs;
    IData/*31:0*/ cpu__DOT__main_memory0__DOT__data_r;
    IData/*31:0*/ cpu__DOT__main_memory0__DOT__data_w;
    IData/*28:0*/ cpu__DOT__uart0__DOT__d;
    IData/*28:0*/ cpu__DOT__uart0__DOT__dNxt;
    IData/*31:0*/ cpu__DOT__hardware_counter0__DOT__cycles;
    IData/*31:0*/ cpu__DOT__fetcher0__DOT__rom0__DOT__mem[98304];
    IData/*31:0*/ cpu__DOT__register_file0__DOT__mem[32];
    IData/*31:0*/ cpu__DOT__main_memory0__DOT__ram0__DOT__mem[32768];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*1:0*/ __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE;
    CData/*0:0*/ __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst_n;
    IData/*31:0*/ cpu__DOT____Vcellinp__main_memory0__addr;
    IData/*31:0*/ __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout;
    IData/*31:0*/ __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY;
    IData/*31:0*/ __Vdly__cpu__DOT__hardware_counter0__DOT__cycles;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vcpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vcpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vcpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vcpu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vcpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vcpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vcpu__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vcpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__4(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vcpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vcpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vcpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
