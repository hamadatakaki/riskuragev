// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcpu.h for the primary calling header

#include "Vcpu.h"
#include "Vcpu__Syms.h"

//==========

VL_CTOR_IMP(Vcpu) {
    Vcpu__Syms* __restrict vlSymsp = __VlSymsp = new Vcpu__Syms(this, name());
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vcpu::__Vconfigure(Vcpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vcpu::~Vcpu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vcpu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcpu::eval\n"); );
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.v", 26, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vcpu::_eval_initial_loop(Vcpu__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("cpu.v", 26, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__1(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__1\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__ctr = (3U & ((IData)(1U) + (IData)(vlTOPp->cpu__DOT__ctr)));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__2(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__2\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__cpu__DOT__uart0__DOT__bitcount;
    SData/*8:0*/ __Vdly__cpu__DOT__uart0__DOT__shifter;
    // Body
    vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles;
    __Vdly__cpu__DOT__uart0__DOT__bitcount = vlTOPp->cpu__DOT__uart0__DOT__bitcount;
    __Vdly__cpu__DOT__uart0__DOT__shifter = vlTOPp->cpu__DOT__uart0__DOT__shifter;
    vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles 
        = ((IData)(vlTOPp->rst_n) ? ((IData)(1U) + vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles)
            : 0U);
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(vlTOPp->cpu__DOT__uart0__DOT__uart_busy)))) {
            __Vdly__cpu__DOT__uart0__DOT__bitcount = 0xbU;
        }
        if (((IData)(vlTOPp->cpu__DOT__uart0__DOT__sending) 
             & (~ (vlTOPp->cpu__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart0__DOT__bitcount 
                = (0xfU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__cpu__DOT__uart0__DOT__bitcount = 0U;
    }
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->cpu__DOT__uart_we) & (~ (IData)(
                                                             (0U 
                                                              != 
                                                              (7U 
                                                               & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                                  >> 1U))))))) {
            __Vdly__cpu__DOT__uart0__DOT__shifter = 
                (0x1feU & (vlTOPp->cpu__DOT__data_rs2 
                           << 1U));
        }
        if (((0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount)) 
             & (~ (vlTOPp->cpu__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__cpu__DOT__uart0__DOT__shifter = 
                (0x100U | (0xffU & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter) 
                                    >> 1U)));
            vlTOPp->cpu__DOT__uart_OUT_data = (1U & (IData)(vlTOPp->cpu__DOT__uart0__DOT__shifter));
        }
    } else {
        __Vdly__cpu__DOT__uart0__DOT__shifter = 0U;
        vlTOPp->cpu__DOT__uart_OUT_data = 1U;
    }
    vlTOPp->cpu__DOT__uart0__DOT__shifter = __Vdly__cpu__DOT__uart0__DOT__shifter;
    vlTOPp->cpu__DOT__uart0__DOT__bitcount = __Vdly__cpu__DOT__uart0__DOT__bitcount;
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart0__DOT__d = ((IData)(vlTOPp->rst_n)
                                        ? vlTOPp->cpu__DOT__uart0__DOT__dNxt
                                        : 0U);
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
                                               (7U 
                                                & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                          & (vlTOPp->cpu__DOT__uart0__DOT__d 
                                             + ((0x10000000U 
                                                 & vlTOPp->cpu__DOT__uart0__DOT__d)
                                                 ? 0x1c200U
                                                 : 0xfa0be100U)));
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__3(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__3\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    SData/*15:0*/ __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    IData/*31:0*/ __Vdly__cpu__DOT__fetcher0__DOT__pc;
    IData/*31:0*/ __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0;
    // Body
    __Vdly__cpu__DOT__fetcher0__DOT__pc = vlTOPp->cpu__DOT__fetcher0__DOT__pc;
    __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0 = 0U;
    __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 0U;
    __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 0U;
    __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 0U;
    __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 0U;
    if (((2U == (IData)(vlTOPp->cpu__DOT__ctr)) & (3U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction)))) {
        vlTOPp->cpu__DOT__main_memory0__DOT__data_r 
            = vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem
            [(0xffffU & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                         >> 2U))];
    }
    if ((3U == (IData)(vlTOPp->cpu__DOT__ctr))) {
        __Vdly__cpu__DOT__fetcher0__DOT__pc = ((1U 
                                                == (IData)(vlTOPp->cpu__DOT__fetcher_option))
                                                ? (vlTOPp->cpu__DOT__fetcher0__DOT__pc 
                                                   + vlTOPp->cpu__DOT__imm)
                                                : (
                                                   (2U 
                                                    == (IData)(vlTOPp->cpu__DOT__fetcher_option))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__data_rs1 
                                                    + vlTOPp->cpu__DOT__imm)
                                                    : 
                                                   ((IData)(4U) 
                                                    + vlTOPp->cpu__DOT__fetcher0__DOT__pc)));
    }
    if ((((3U == (IData)(vlTOPp->cpu__DOT__ctr)) & 
          (((0x63U != (0x7fU & vlTOPp->cpu__DOT__instruction)) 
            & (0x23U != (0x7fU & vlTOPp->cpu__DOT__instruction))) 
           & ((~ ((0x6fU == (0x7fU & vlTOPp->cpu__DOT__instruction)) 
                  | (0x67U == (0x7fU & vlTOPp->cpu__DOT__instruction)))) 
              | (0U != (0x1fU & (vlTOPp->cpu__DOT__instruction 
                                 >> 7U)))))) & (0U 
                                                != 
                                                (0x1fU 
                                                 & (vlTOPp->cpu__DOT__instruction 
                                                    >> 7U))))) {
        __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0 
            = ((3U == (0x7fU & vlTOPp->cpu__DOT__instruction))
                ? (((0x16U == (IData)(vlTOPp->cpu__DOT__instruction_code)) 
                    & (0xffffff00U == (vlTOPp->cpu__DOT__data_rs1 
                                       + vlTOPp->cpu__DOT__imm)))
                    ? vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles
                    : vlTOPp->cpu__DOT___data_rd_memory)
                : vlTOPp->cpu__DOT__data_rd_exec);
        __Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0 
            = (0x1fU & (vlTOPp->cpu__DOT__instruction 
                        >> 7U));
    }
    if (((2U == (IData)(vlTOPp->cpu__DOT__ctr)) & (0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction)))) {
        if ((1U & (IData)(vlTOPp->cpu__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0 
                = (0xffU & vlTOPp->cpu__DOT__main_memory0__DOT__data_w);
            __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 1U;
            __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 0U;
            __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0 
                = (0xffffU & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->cpu__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1 
                = (0xffU & (vlTOPp->cpu__DOT__main_memory0__DOT__data_w 
                            >> 8U));
            __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 1U;
            __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 8U;
            __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1 
                = (0xffffU & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->cpu__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2 
                = (0xffU & (vlTOPp->cpu__DOT__main_memory0__DOT__data_w 
                            >> 0x10U));
            __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 1U;
            __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2 
                = (0xffffU & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->cpu__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3 
                = (0xffU & (vlTOPp->cpu__DOT__main_memory0__DOT__data_w 
                            >> 0x18U));
            __Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 1U;
            __Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3 
                = (0xffffU & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
    }
    if (__Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0) {
        vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0))) 
                & vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v0)));
    }
    if (__Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1) {
        vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1))) 
                & vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v1)));
    }
    if (__Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2) {
        vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2))) 
                & vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v2)));
    }
    if (__Vdlyvset__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3) {
        vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3))) 
                & vlTOPp->cpu__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__cpu__DOT__main_memory0__DOT__ram0__DOT__mem__v3)));
    }
    if (((1U == (IData)(vlTOPp->cpu__DOT__ctr)) & (
                                                   ((0x37U 
                                                     != 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction)) 
                                                    & (0x17U 
                                                       != 
                                                       (0x7fU 
                                                        & vlTOPp->cpu__DOT__instruction))) 
                                                   & (0x6fU 
                                                      != 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction))))) {
        vlTOPp->cpu__DOT__data_rs1 = vlTOPp->cpu__DOT__register_file0__DOT__mem
            [(0x1fU & (vlTOPp->cpu__DOT__instruction 
                       >> 0xfU))];
    }
    if (((1U == (IData)(vlTOPp->cpu__DOT__ctr)) & (
                                                   ((0x33U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction)) 
                                                    | (0x63U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->cpu__DOT__instruction))) 
                                                   | (0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction))))) {
        vlTOPp->cpu__DOT__data_rs2 = vlTOPp->cpu__DOT__register_file0__DOT__mem
            [(0x1fU & (vlTOPp->cpu__DOT__instruction 
                       >> 0x14U))];
    }
    if (__Vdlyvset__cpu__DOT__register_file0__DOT__mem__v0) {
        vlTOPp->cpu__DOT__register_file0__DOT__mem[__Vdlyvdim0__cpu__DOT__register_file0__DOT__mem__v0] 
            = __Vdlyvval__cpu__DOT__register_file0__DOT__mem__v0;
    }
    if ((0U == (IData)(vlTOPp->cpu__DOT__ctr))) {
        vlTOPp->cpu__DOT__instruction = ((0x17fffU 
                                          >= (0x1ffffU 
                                              & (vlTOPp->cpu__DOT__fetcher0__DOT__pc 
                                                 >> 2U)))
                                          ? vlTOPp->cpu__DOT__fetcher0__DOT__rom0__DOT__mem
                                         [(0x1ffffU 
                                           & (vlTOPp->cpu__DOT__fetcher0__DOT__pc 
                                              >> 2U))]
                                          : 0U);
    }
    vlTOPp->cpu__DOT__fetcher0__DOT__pc = __Vdly__cpu__DOT__fetcher0__DOT__pc;
    vlTOPp->cpu__DOT__lhs_type = ((0x33U == (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                   ? 0U : ((((0x17U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))) 
                                            | (0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                            ? 1U : 
                                           ((0x37U 
                                             == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))
                                             ? 2U : 
                                            ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? ((0U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 0xfU)))
                                                  ? 2U
                                                  : 0U)
                                              : 3U))));
    vlTOPp->cpu__DOT__rhs_type = ((0x33U == (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                   ? 0U : ((((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))) 
                                            | (0x37U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                            ? 1U : 
                                           (((0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction)))
                                             ? 2U : 3U)));
    vlTOPp->cpu__DOT__instruction_code = ((0x37U == 
                                           (0x7fU & vlTOPp->cpu__DOT__instruction))
                                           ? 0xaU : 
                                          ((0x17U == 
                                            (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                            ? 0xbU : 
                                           ((0x6fU 
                                             == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))
                                             ? 0xcU
                                             : ((0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                                 ? 0xdU
                                                 : 
                                                ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x11U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x12U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x13U
                                                        : 0x3fU))))))
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x19U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x1aU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x1bU
                                                      : 0x3fU)))
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x14U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x15U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x16U
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x17U
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 0x18U
                                                         : 0x3fU)))))
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction))
                                                     ? 
                                                    ((0U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 2U
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 3U
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 4U
                                                         : 
                                                        ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 5U
                                                          : 
                                                         ((5U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((0x40000000U 
                                                            & vlTOPp->cpu__DOT__instruction)
                                                            ? 7U
                                                            : 6U)
                                                           : 
                                                          ((6U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 8U
                                                            : 
                                                           ((7U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 9U
                                                             : 0x3fU))))))))
                                                     : 
                                                    ((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction))
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlTOPp->cpu__DOT__instruction)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 2U
                                                        : 
                                                       ((2U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 3U
                                                         : 
                                                        ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 4U
                                                          : 
                                                         ((4U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 5U
                                                           : 
                                                          ((5U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((0x40000000U 
                                                             & vlTOPp->cpu__DOT__instruction)
                                                             ? 7U
                                                             : 6U)
                                                            : 
                                                           ((6U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 8U
                                                             : 
                                                            ((7U 
                                                              == 
                                                              (7U 
                                                               & (vlTOPp->cpu__DOT__instruction 
                                                                  >> 0xcU)))
                                                              ? 9U
                                                              : 0x3fU))))))))
                                                      : 0x3fU)))))))));
    vlTOPp->cpu__DOT__imm = (IData)((((0x37U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction)) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                      ? (QData)((IData)(
                                                        (0xfffff000U 
                                                         & vlTOPp->cpu__DOT__instruction)))
                                      : ((0x6fU == 
                                          (0x7fU & vlTOPp->cpu__DOT__instruction))
                                          ? (QData)((IData)(
                                                            ((0x100000U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xbU)) 
                                                             | ((0xff000U 
                                                                 & vlTOPp->cpu__DOT__instruction) 
                                                                | ((0x800U 
                                                                    & (vlTOPp->cpu__DOT__instruction 
                                                                       >> 9U)) 
                                                                   | (0x7feU 
                                                                      & (vlTOPp->cpu__DOT__instruction 
                                                                         >> 0x14U)))))))
                                          : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? (((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU))))
                                                  ? (QData)((IData)(
                                                                    (0x1fU 
                                                                     & (vlTOPp->cpu__DOT__instruction 
                                                                        >> 0x14U))))
                                                  : (QData)((IData)(
                                                                    ((0xfffff000U 
                                                                      & (VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->cpu__DOT__instruction 
                                                                                >> 0x1fU)))) 
                                                                         << 0xcU)) 
                                                                     | (0xfffU 
                                                                        & (vlTOPp->cpu__DOT__instruction 
                                                                           >> 0x14U))))))
                                              : (((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction)) 
                                                  | (3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction)))
                                                  ? (QData)((IData)(
                                                                    (0xfffU 
                                                                     & (vlTOPp->cpu__DOT__instruction 
                                                                        >> 0x14U))))
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? (QData)((IData)(
                                                                     ((0xfe0U 
                                                                       & (vlTOPp->cpu__DOT__instruction 
                                                                          >> 0x14U)) 
                                                                      | (0x1fU 
                                                                         & (vlTOPp->cpu__DOT__instruction 
                                                                            >> 7U)))))
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu__DOT__instruction 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      ((0x800U 
                                                                        & (vlTOPp->cpu__DOT__instruction 
                                                                           << 4U)) 
                                                                       | ((0x7e0U 
                                                                           & (vlTOPp->cpu__DOT__instruction 
                                                                              >> 0x14U)) 
                                                                          | (0x1eU 
                                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                                >> 7U)))))))
                                                    : VL_ULL(0))))))));
    vlTOPp->cpu__DOT__exec0__DOT__lhs = ((0U == (IData)(vlTOPp->cpu__DOT__lhs_type))
                                          ? vlTOPp->cpu__DOT__data_rs1
                                          : ((1U == (IData)(vlTOPp->cpu__DOT__lhs_type))
                                              ? vlTOPp->cpu__DOT__fetcher0__DOT__pc
                                              : 0U));
    vlTOPp->cpu__DOT__fetcher_option = ((1U & ((0xeU 
                                                == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                ? (vlTOPp->cpu__DOT__data_rs1 
                                                   == vlTOPp->cpu__DOT__data_rs2)
                                                : (
                                                   (0xfU 
                                                    == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__data_rs1 
                                                    != vlTOPp->cpu__DOT__data_rs2)
                                                    : 
                                                   ((0x10U 
                                                     == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                     ? 
                                                    VL_LTS_III(32,32,32, vlTOPp->cpu__DOT__data_rs1, vlTOPp->cpu__DOT__data_rs2)
                                                     : 
                                                    ((0x11U 
                                                      == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                      ? 
                                                     VL_GTES_III(32,32,32, vlTOPp->cpu__DOT__data_rs1, vlTOPp->cpu__DOT__data_rs2)
                                                      : 
                                                     ((0x12U 
                                                       == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                       ? 
                                                      (vlTOPp->cpu__DOT__data_rs1 
                                                       < vlTOPp->cpu__DOT__data_rs2)
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                        ? 
                                                       (vlTOPp->cpu__DOT__data_rs1 
                                                        >= vlTOPp->cpu__DOT__data_rs2)
                                                        : 0U)))))))
                                         ? 1U : ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 1U
                                                  : 
                                                 ((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? 2U
                                                   : 0U)));
    vlTOPp->cpu__DOT__exec0__DOT__alucode = (0xfU & 
                                             ((0xaU 
                                               > (IData)(vlTOPp->cpu__DOT__instruction_code))
                                               ? (IData)(vlTOPp->cpu__DOT__instruction_code)
                                               : ((0xeU 
                                                   > (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                   ? 0U
                                                   : 0xfU)));
    vlTOPp->cpu__DOT__uart_we = ((0xf6fff070U == (vlTOPp->cpu__DOT__data_rs1 
                                                  + vlTOPp->cpu__DOT__imm)) 
                                 & (0x23U == (0x7fU 
                                              & vlTOPp->cpu__DOT__instruction)));
    vlTOPp->cpu__DOT__exec0__DOT__rhs = ((0U == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                          ? vlTOPp->cpu__DOT__data_rs2
                                          : ((1U == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                              ? vlTOPp->cpu__DOT__imm
                                              : ((2U 
                                                  == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                                  ? 4U
                                                  : 0U)));
    vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
        = (vlTOPp->cpu__DOT__data_rs1 + vlTOPp->cpu__DOT__imm);
    vlTOPp->cpu__DOT__data_rd_exec = (IData)((VL_ULL(0x1ffffffff) 
                                              & ((0U 
                                                  == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                  + (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                   ? 
                                                  ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                   - (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->cpu__DOT__exec0__DOT__rhs))
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                     ? (QData)((IData)(
                                                                       VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__exec0__DOT__lhs, vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                      ? (QData)((IData)(
                                                                        (vlTOPp->cpu__DOT__exec0__DOT__lhs 
                                                                         < vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                       ? 
                                                      ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                       ^ (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                        ? 
                                                       ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                        >> 
                                                        (0x1fU 
                                                         & vlTOPp->cpu__DOT__exec0__DOT__rhs))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                         ? 
                                                        ((0x80000000U 
                                                          & vlTOPp->cpu__DOT__exec0__DOT__lhs)
                                                          ? 
                                                         (((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                           >> 
                                                           (0x1fU 
                                                            & vlTOPp->cpu__DOT__exec0__DOT__rhs)) 
                                                          | (~ 
                                                             (VL_ULL(0xffffffff) 
                                                              >> 
                                                              (0x1fU 
                                                               & vlTOPp->cpu__DOT__exec0__DOT__rhs))))
                                                          : 
                                                         ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                          >> 
                                                          (0x1fU 
                                                           & vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                         : 
                                                        ((8U 
                                                          == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                          ? 
                                                         ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                          | (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                           & (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                           : VL_ULL(0)))))))))))));
    vlTOPp->cpu__DOT__main_memory0__DOT__mask_store 
        = (0xfU & (((0U == (3U & (vlTOPp->cpu__DOT__instruction 
                                  >> 0xcU))) ? 1U : 
                    ((1U == (3U & (vlTOPp->cpu__DOT__instruction 
                                   >> 0xcU))) ? 3U : 0xfU)) 
                   << (3U & vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr)));
    vlTOPp->cpu__DOT__main_memory0__DOT__data_w = (
                                                   (0x1fU 
                                                    >= 
                                                    (0x18U 
                                                     & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                        << 3U)))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__data_rs2 
                                                    << 
                                                    (0x18U 
                                                     & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                        << 3U)))
                                                    : 0U);
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED 
        = (1U & (~ (vlTOPp->cpu__DOT__instruction >> 0xeU)));
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE 
        = (3U & (vlTOPp->cpu__DOT__instruction >> 0xcU));
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
        = ((0x1fU >= (0x18U & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->cpu__DOT__main_memory0__DOT__data_r 
                                           >> (0x18U 
                                               & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout 
        = ((1U == (IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
            ? ((IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                ? ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                           >> 0xfU)))) 
                                   << 0x10U)) | (0xffffU 
                                                 & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : (0xffffU & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
            : ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
                ? ((IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                    ? ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                               >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                    : (0xffU & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY));
    vlTOPp->cpu__DOT___data_rd_memory = vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout;
}

void Vcpu::_initial__TOP__4(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_initial__TOP__4\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles = 0U;
    vlTOPp->cpu__DOT__uart0__DOT__d = 0U;
    vlTOPp->cpu__DOT__uart_OUT_data = 1U;
    vlTOPp->cpu__DOT__uart0__DOT__bitcount = 0U;
    vlTOPp->cpu__DOT__uart0__DOT__shifter = 0U;
    vlTOPp->cpu__DOT__register_file0__DOT__mem[0U] = 0U;
    vlTOPp->cpu__DOT__ctr = 0xfU;
    vlTOPp->cpu__DOT__fetcher0__DOT__pc = 0x8000U;
}

void Vcpu::_settle__TOP__5(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_settle__TOP__5\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__lhs_type = ((0x33U == (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                   ? 0U : ((((0x17U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))) 
                                            | (0x67U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                            ? 1U : 
                                           ((0x37U 
                                             == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))
                                             ? 2U : 
                                            ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? ((0U 
                                                  == 
                                                  (0x1fU 
                                                   & (vlTOPp->cpu__DOT__instruction 
                                                      >> 0xfU)))
                                                  ? 2U
                                                  : 0U)
                                              : 3U))));
    vlTOPp->cpu__DOT__rhs_type = ((0x33U == (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                   ? 0U : ((((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))) 
                                            | (0x37U 
                                               == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                            ? 1U : 
                                           (((0x6fU 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction)) 
                                             | (0x67U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction)))
                                             ? 2U : 3U)));
    vlTOPp->cpu__DOT__instruction_code = ((0x37U == 
                                           (0x7fU & vlTOPp->cpu__DOT__instruction))
                                           ? 0xaU : 
                                          ((0x17U == 
                                            (0x7fU 
                                             & vlTOPp->cpu__DOT__instruction))
                                            ? 0xbU : 
                                           ((0x6fU 
                                             == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction))
                                             ? 0xcU
                                             : ((0x67U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                                 ? 0xdU
                                                 : 
                                                ((0x63U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU)))
                                                   ? 0xeU
                                                   : 
                                                  ((1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x11U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x12U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x13U
                                                        : 0x3fU))))))
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->cpu__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x19U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x1aU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x1bU
                                                      : 0x3fU)))
                                                   : 
                                                  ((3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x14U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x15U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x16U
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x17U
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 0x18U
                                                         : 0x3fU)))))
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction))
                                                     ? 
                                                    ((0U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->cpu__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 2U
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 3U
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 4U
                                                         : 
                                                        ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 5U
                                                          : 
                                                         ((5U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((0x40000000U 
                                                            & vlTOPp->cpu__DOT__instruction)
                                                            ? 7U
                                                            : 6U)
                                                           : 
                                                          ((6U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 8U
                                                            : 
                                                           ((7U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 9U
                                                             : 0x3fU))))))))
                                                     : 
                                                    ((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->cpu__DOT__instruction))
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->cpu__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlTOPp->cpu__DOT__instruction)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->cpu__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 2U
                                                        : 
                                                       ((2U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->cpu__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 3U
                                                         : 
                                                        ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->cpu__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 4U
                                                          : 
                                                         ((4U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->cpu__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 5U
                                                           : 
                                                          ((5U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((0x40000000U 
                                                             & vlTOPp->cpu__DOT__instruction)
                                                             ? 7U
                                                             : 6U)
                                                            : 
                                                           ((6U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 8U
                                                             : 
                                                            ((7U 
                                                              == 
                                                              (7U 
                                                               & (vlTOPp->cpu__DOT__instruction 
                                                                  >> 0xcU)))
                                                              ? 9U
                                                              : 0x3fU))))))))
                                                      : 0x3fU)))))))));
    vlTOPp->cpu__DOT__imm = (IData)((((0x37U == (0x7fU 
                                                 & vlTOPp->cpu__DOT__instruction)) 
                                      | (0x17U == (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction)))
                                      ? (QData)((IData)(
                                                        (0xfffff000U 
                                                         & vlTOPp->cpu__DOT__instruction)))
                                      : ((0x6fU == 
                                          (0x7fU & vlTOPp->cpu__DOT__instruction))
                                          ? (QData)((IData)(
                                                            ((0x100000U 
                                                              & (vlTOPp->cpu__DOT__instruction 
                                                                 >> 0xbU)) 
                                                             | ((0xff000U 
                                                                 & vlTOPp->cpu__DOT__instruction) 
                                                                | ((0x800U 
                                                                    & (vlTOPp->cpu__DOT__instruction 
                                                                       >> 9U)) 
                                                                   | (0x7feU 
                                                                      & (vlTOPp->cpu__DOT__instruction 
                                                                         >> 0x14U)))))))
                                          : ((0x13U 
                                              == (0x7fU 
                                                  & vlTOPp->cpu__DOT__instruction))
                                              ? (((1U 
                                                   == 
                                                   (7U 
                                                    & (vlTOPp->cpu__DOT__instruction 
                                                       >> 0xcU))) 
                                                  | (5U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->cpu__DOT__instruction 
                                                         >> 0xcU))))
                                                  ? (QData)((IData)(
                                                                    (0x1fU 
                                                                     & (vlTOPp->cpu__DOT__instruction 
                                                                        >> 0x14U))))
                                                  : (QData)((IData)(
                                                                    ((0xfffff000U 
                                                                      & (VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->cpu__DOT__instruction 
                                                                                >> 0x1fU)))) 
                                                                         << 0xcU)) 
                                                                     | (0xfffU 
                                                                        & (vlTOPp->cpu__DOT__instruction 
                                                                           >> 0x14U))))))
                                              : (((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction)) 
                                                  | (3U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->cpu__DOT__instruction)))
                                                  ? (QData)((IData)(
                                                                    (0xfffU 
                                                                     & (vlTOPp->cpu__DOT__instruction 
                                                                        >> 0x14U))))
                                                  : 
                                                 ((0x23U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? (QData)((IData)(
                                                                     ((0xfe0U 
                                                                       & (vlTOPp->cpu__DOT__instruction 
                                                                          >> 0x14U)) 
                                                                      | (0x1fU 
                                                                         & (vlTOPp->cpu__DOT__instruction 
                                                                            >> 7U)))))
                                                   : 
                                                  ((0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->cpu__DOT__instruction))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     (1U 
                                                                      & (vlTOPp->cpu__DOT__instruction 
                                                                         >> 0x1fU)))) 
                                                     << 0xcU) 
                                                    | (QData)((IData)(
                                                                      ((0x800U 
                                                                        & (vlTOPp->cpu__DOT__instruction 
                                                                           << 4U)) 
                                                                       | ((0x7e0U 
                                                                           & (vlTOPp->cpu__DOT__instruction 
                                                                              >> 0x14U)) 
                                                                          | (0x1eU 
                                                                             & (vlTOPp->cpu__DOT__instruction 
                                                                                >> 7U)))))))
                                                    : VL_ULL(0))))))));
    vlTOPp->uart_tx = vlTOPp->cpu__DOT__uart_OUT_data;
    vlTOPp->cpu__DOT__uart0__DOT__uart_busy = (0U != 
                                               (7U 
                                                & ((IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount) 
                                                   >> 1U)));
    vlTOPp->cpu__DOT__uart0__DOT__sending = (0U != (IData)(vlTOPp->cpu__DOT__uart0__DOT__bitcount));
    vlTOPp->cpu__DOT__uart0__DOT__dNxt = (0x1fffffffU 
                                          & (vlTOPp->cpu__DOT__uart0__DOT__d 
                                             + ((0x10000000U 
                                                 & vlTOPp->cpu__DOT__uart0__DOT__d)
                                                 ? 0x1c200U
                                                 : 0xfa0be100U)));
    vlTOPp->cpu__DOT__exec0__DOT__lhs = ((0U == (IData)(vlTOPp->cpu__DOT__lhs_type))
                                          ? vlTOPp->cpu__DOT__data_rs1
                                          : ((1U == (IData)(vlTOPp->cpu__DOT__lhs_type))
                                              ? vlTOPp->cpu__DOT__fetcher0__DOT__pc
                                              : 0U));
    vlTOPp->cpu__DOT__fetcher_option = ((1U & ((0xeU 
                                                == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                ? (vlTOPp->cpu__DOT__data_rs1 
                                                   == vlTOPp->cpu__DOT__data_rs2)
                                                : (
                                                   (0xfU 
                                                    == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__data_rs1 
                                                    != vlTOPp->cpu__DOT__data_rs2)
                                                    : 
                                                   ((0x10U 
                                                     == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                     ? 
                                                    VL_LTS_III(32,32,32, vlTOPp->cpu__DOT__data_rs1, vlTOPp->cpu__DOT__data_rs2)
                                                     : 
                                                    ((0x11U 
                                                      == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                      ? 
                                                     VL_GTES_III(32,32,32, vlTOPp->cpu__DOT__data_rs1, vlTOPp->cpu__DOT__data_rs2)
                                                      : 
                                                     ((0x12U 
                                                       == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                       ? 
                                                      (vlTOPp->cpu__DOT__data_rs1 
                                                       < vlTOPp->cpu__DOT__data_rs2)
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                        ? 
                                                       (vlTOPp->cpu__DOT__data_rs1 
                                                        >= vlTOPp->cpu__DOT__data_rs2)
                                                        : 0U)))))))
                                         ? 1U : ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->cpu__DOT__instruction))
                                                  ? 1U
                                                  : 
                                                 ((0x67U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->cpu__DOT__instruction))
                                                   ? 2U
                                                   : 0U)));
    vlTOPp->cpu__DOT__exec0__DOT__alucode = (0xfU & 
                                             ((0xaU 
                                               > (IData)(vlTOPp->cpu__DOT__instruction_code))
                                               ? (IData)(vlTOPp->cpu__DOT__instruction_code)
                                               : ((0xeU 
                                                   > (IData)(vlTOPp->cpu__DOT__instruction_code))
                                                   ? 0U
                                                   : 0xfU)));
    vlTOPp->cpu__DOT__uart_we = ((0xf6fff070U == (vlTOPp->cpu__DOT__data_rs1 
                                                  + vlTOPp->cpu__DOT__imm)) 
                                 & (0x23U == (0x7fU 
                                              & vlTOPp->cpu__DOT__instruction)));
    vlTOPp->cpu__DOT__exec0__DOT__rhs = ((0U == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                          ? vlTOPp->cpu__DOT__data_rs2
                                          : ((1U == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                              ? vlTOPp->cpu__DOT__imm
                                              : ((2U 
                                                  == (IData)(vlTOPp->cpu__DOT__rhs_type))
                                                  ? 4U
                                                  : 0U)));
    vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
        = (vlTOPp->cpu__DOT__data_rs1 + vlTOPp->cpu__DOT__imm);
    vlTOPp->cpu__DOT__data_rd_exec = (IData)((VL_ULL(0x1ffffffff) 
                                              & ((0U 
                                                  == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                  ? 
                                                 ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                  + (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                   ? 
                                                  ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                   - (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                   : 
                                                  ((2U 
                                                    == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                    ? 
                                                   ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                    << 
                                                    (0x1fU 
                                                     & vlTOPp->cpu__DOT__exec0__DOT__rhs))
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                     ? (QData)((IData)(
                                                                       VL_LTS_III(1,32,32, vlTOPp->cpu__DOT__exec0__DOT__lhs, vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                      ? (QData)((IData)(
                                                                        (vlTOPp->cpu__DOT__exec0__DOT__lhs 
                                                                         < vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                       ? 
                                                      ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                       ^ (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                       : 
                                                      ((6U 
                                                        == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                        ? 
                                                       ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                        >> 
                                                        (0x1fU 
                                                         & vlTOPp->cpu__DOT__exec0__DOT__rhs))
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                         ? 
                                                        ((0x80000000U 
                                                          & vlTOPp->cpu__DOT__exec0__DOT__lhs)
                                                          ? 
                                                         (((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                           >> 
                                                           (0x1fU 
                                                            & vlTOPp->cpu__DOT__exec0__DOT__rhs)) 
                                                          | (~ 
                                                             (VL_ULL(0xffffffff) 
                                                              >> 
                                                              (0x1fU 
                                                               & vlTOPp->cpu__DOT__exec0__DOT__rhs))))
                                                          : 
                                                         ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                          >> 
                                                          (0x1fU 
                                                           & vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                         : 
                                                        ((8U 
                                                          == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                          ? 
                                                         ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                          | (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                          : 
                                                         ((9U 
                                                           == (IData)(vlTOPp->cpu__DOT__exec0__DOT__alucode))
                                                           ? 
                                                          ((QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__lhs)) 
                                                           & (QData)((IData)(vlTOPp->cpu__DOT__exec0__DOT__rhs)))
                                                           : VL_ULL(0)))))))))))));
    vlTOPp->cpu__DOT__main_memory0__DOT__mask_store 
        = (0xfU & (((0U == (3U & (vlTOPp->cpu__DOT__instruction 
                                  >> 0xcU))) ? 1U : 
                    ((1U == (3U & (vlTOPp->cpu__DOT__instruction 
                                   >> 0xcU))) ? 3U : 0xfU)) 
                   << (3U & vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr)));
    vlTOPp->cpu__DOT__main_memory0__DOT__data_w = (
                                                   (0x1fU 
                                                    >= 
                                                    (0x18U 
                                                     & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                        << 3U)))
                                                    ? 
                                                   (vlTOPp->cpu__DOT__data_rs2 
                                                    << 
                                                    (0x18U 
                                                     & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                        << 3U)))
                                                    : 0U);
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED 
        = (1U & (~ (vlTOPp->cpu__DOT__instruction >> 0xeU)));
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE 
        = (3U & (vlTOPp->cpu__DOT__instruction >> 0xcU));
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
        = ((0x1fU >= (0x18U & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->cpu__DOT__main_memory0__DOT__data_r 
                                           >> (0x18U 
                                               & (vlTOPp->cpu__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout 
        = ((1U == (IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
            ? ((IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                ? ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                           >> 0xfU)))) 
                                   << 0x10U)) | (0xffffU 
                                                 & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : (0xffffU & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
            : ((0U == (IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
                ? ((IData)(vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                    ? ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                               >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                    : (0xffU & vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY));
    vlTOPp->cpu__DOT___data_rd_memory = vlTOPp->__Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout;
}

VL_INLINE_OPT void Vcpu::_sequent__TOP__6(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_sequent__TOP__6\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->cpu__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->__Vdly__cpu__DOT__hardware_counter0__DOT__cycles;
}

void Vcpu::_eval(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((~ (IData)(vlTOPp->clk)) & (IData)(vlTOPp->__Vclklast__TOP__clk))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vcpu::_eval_initial(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_initial\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vcpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::final\n"); );
    // Variables
    Vcpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vcpu::_eval_settle(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_settle\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vcpu::_change_request(Vcpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_change_request\n"); );
    Vcpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vcpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG

void Vcpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcpu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    cpu__DOT__ctr = VL_RAND_RESET_I(4);
    cpu__DOT__instruction = VL_RAND_RESET_I(32);
    cpu__DOT__instruction_code = VL_RAND_RESET_I(6);
    cpu__DOT__lhs_type = VL_RAND_RESET_I(2);
    cpu__DOT__rhs_type = VL_RAND_RESET_I(2);
    cpu__DOT__data_rs1 = VL_RAND_RESET_I(32);
    cpu__DOT__data_rs2 = VL_RAND_RESET_I(32);
    cpu__DOT__data_rd_exec = VL_RAND_RESET_I(32);
    cpu__DOT__imm = VL_RAND_RESET_I(32);
    cpu__DOT__fetcher_option = VL_RAND_RESET_I(2);
    cpu__DOT___data_rd_memory = VL_RAND_RESET_I(32);
    cpu__DOT____Vcellinp__main_memory0__addr = VL_RAND_RESET_I(32);
    cpu__DOT__uart_we = VL_RAND_RESET_I(1);
    cpu__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    cpu__DOT__fetcher0__DOT__pc = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<98304; ++__Vi0) {
            cpu__DOT__fetcher0__DOT__rom0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            cpu__DOT__register_file0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__exec0__DOT__alucode = VL_RAND_RESET_I(4);
    cpu__DOT__exec0__DOT__rhs = VL_RAND_RESET_I(32);
    cpu__DOT__exec0__DOT__lhs = VL_RAND_RESET_I(32);
    cpu__DOT__main_memory0__DOT__data_r = VL_RAND_RESET_I(32);
    cpu__DOT__main_memory0__DOT__data_w = VL_RAND_RESET_I(32);
    cpu__DOT__main_memory0__DOT__mask_store = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<65536; ++__Vi0) {
            cpu__DOT__main_memory0__DOT__ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    cpu__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    cpu__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    cpu__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    cpu__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    cpu__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY = VL_RAND_RESET_I(32);
    __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE = VL_RAND_RESET_I(2);
    __Vfunc_cpu__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED = VL_RAND_RESET_I(1);
    __Vdly__cpu__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
}
