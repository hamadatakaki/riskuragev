// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VL_CTOR_IMP(Vtop) {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vtop::~Vtop() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vtop::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("top.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("top.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__cpu0__DOT__ctr;
    // Body
    __Vdly__top__DOT__cpu0__DOT__ctr = vlTOPp->top__DOT__cpu0__DOT__ctr;
    if (vlTOPp->rst_n) {
        __Vdly__top__DOT__cpu0__DOT__ctr = 0U;
    }
    __Vdly__top__DOT__cpu0__DOT__ctr = (3U & ((IData)(1U) 
                                              + (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)));
    vlTOPp->top__DOT__cpu0__DOT__ctr = __Vdly__top__DOT__cpu0__DOT__ctr;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__2\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*3:0*/ __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount;
    SData/*8:0*/ __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter;
    // Body
    vlTOPp->__Vdly__top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles;
    __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount 
        = vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount;
    __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter 
        = vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__shifter;
    vlTOPp->__Vdly__top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles 
        = ((IData)(vlTOPp->rst_n) ? ((IData)(1U) + vlTOPp->top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles)
            : 0U);
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->top__DOT__cpu0__DOT__uart_we) 
             & (~ (IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__uart_busy)))) {
            __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount = 0xbU;
        }
        if (((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__sending) 
             & (~ (vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount 
                = (0xfU & ((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount) 
                           - (IData)(1U)));
        }
    } else {
        __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount = 0U;
    }
    if (vlTOPp->rst_n) {
        if (((IData)(vlTOPp->top__DOT__cpu0__DOT__uart_we) 
             & (~ (IData)((0U != (7U & ((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount) 
                                        >> 1U))))))) {
            __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter 
                = (0x1feU & (vlTOPp->top__DOT__cpu0__DOT__data_rs2 
                             << 1U));
        }
        if (((0U != (IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount)) 
             & (~ (vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d 
                   >> 0x1cU)))) {
            __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter 
                = (0x100U | (0xffU & ((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__shifter) 
                                      >> 1U)));
            vlTOPp->top__DOT__cpu0__DOT__uart_OUT_data 
                = (1U & (IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__shifter));
        }
    } else {
        __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter = 0U;
        vlTOPp->top__DOT__cpu0__DOT__uart_OUT_data = 1U;
    }
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__shifter 
        = __Vdly__top__DOT__cpu0__DOT__uart0__DOT__shifter;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount 
        = __Vdly__top__DOT__cpu0__DOT__uart0__DOT__bitcount;
    vlTOPp->uart_tx = vlTOPp->top__DOT__cpu0__DOT__uart_OUT_data;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d = ((IData)(vlTOPp->rst_n)
                                                   ? vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__dNxt
                                                   : 0U);
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__uart_busy 
        = (0U != (7U & ((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount) 
                        >> 1U)));
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__sending 
        = (0U != (IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount));
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__dNxt = 
        (0x1fffffffU & (vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d 
                        + ((0x10000000U & vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d)
                            ? 0x1c200U : 0xfa0be100U)));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    CData/*4:0*/ __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2;
    SData/*15:0*/ __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3;
    IData/*31:0*/ __Vdly__top__DOT__cpu0__DOT__fetcher0__DOT__pc;
    IData/*31:0*/ __Vdlyvval__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0;
    // Body
    __Vdly__top__DOT__cpu0__DOT__fetcher0__DOT__pc 
        = vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc;
    __Vdlyvset__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 0U;
    __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 0U;
    __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 0U;
    __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 0U;
    if (((2U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)) 
         & (3U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)))) {
        vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_r 
            = vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
            [(0xffffU & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                         >> 2U))];
    }
    if (vlTOPp->rst_n) {
        __Vdly__top__DOT__cpu0__DOT__fetcher0__DOT__pc = 0x8000U;
    }
    if ((3U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr))) {
        __Vdly__top__DOT__cpu0__DOT__fetcher0__DOT__pc 
            = ((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__fetcher_option))
                ? (vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc 
                   + vlTOPp->top__DOT__cpu0__DOT__imm)
                : ((2U == (IData)(vlTOPp->top__DOT__cpu0__DOT__fetcher_option))
                    ? (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                       + vlTOPp->top__DOT__cpu0__DOT__imm)
                    : ((IData)(4U) + vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc)));
    }
    if ((((3U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)) 
          & (((0x63U != (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
              & (0x23U != (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
             & ((~ ((0x6fU == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                    | (0x67U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)))) 
                | (0U != (0x1fU & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                   >> 7U)))))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                      >> 7U))))) {
        __Vdlyvval__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0 
            = ((3U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                ? (((0x16U == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code)) 
                    & (0xffffff00U == (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                       + vlTOPp->top__DOT__cpu0__DOT__imm)))
                    ? vlTOPp->top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles
                    : vlTOPp->top__DOT__cpu0__DOT___data_rd_memory)
                : vlTOPp->top__DOT__cpu0__DOT__data_rd_exec);
        __Vdlyvset__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0 = 1U;
        __Vdlyvdim0__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0 
            = (0x1fU & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                        >> 7U));
    }
    if (((2U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)) 
         & (0x23U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)))) {
        if ((1U & (IData)(vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0 
                = (0xffU & vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w);
            __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 1U;
            __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0 = 0U;
            __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0 
                = (0xffffU & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((2U & (IData)(vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1 
                = (0xffU & (vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w 
                            >> 8U));
            __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 1U;
            __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1 = 8U;
            __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1 
                = (0xffffU & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((4U & (IData)(vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2 
                = (0xffU & (vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w 
                            >> 0x10U));
            __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 1U;
            __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2 = 0x10U;
            __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2 
                = (0xffffU & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
        if ((8U & (IData)(vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store))) {
            __Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3 
                = (0xffU & (vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w 
                            >> 0x18U));
            __Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 1U;
            __Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3 = 0x18U;
            __Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3 
                = (0xffffU & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                              >> 2U));
        }
    }
    if (__Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0) {
        vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0))) 
                & vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0]) 
               | ((IData)(__Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0) 
                  << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v0)));
    }
    if (__Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1) {
        vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1))) 
                & vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1]) 
               | ((IData)(__Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1) 
                  << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v1)));
    }
    if (__Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2) {
        vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2))) 
                & vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2]) 
               | ((IData)(__Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2) 
                  << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v2)));
    }
    if (__Vdlyvset__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3) {
        vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem[__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3] 
            = (((~ ((IData)(0xffU) << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3))) 
                & vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
                [__Vdlyvdim0__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3]) 
               | ((IData)(__Vdlyvval__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3) 
                  << (IData)(__Vdlyvlsb__top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem__v3)));
    }
    if (((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)) 
         & (((0x37U != (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
             & (0x17U != (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
            & (0x6fU != (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))))) {
        vlTOPp->top__DOT__cpu0__DOT__data_rs1 = vlTOPp->top__DOT__cpu0__DOT__register_file0__DOT__mem
            [(0x1fU & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                       >> 0xfU))];
    }
    if (((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr)) 
         & (((0x33U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
             | (0x63U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
            | (0x23U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))))) {
        vlTOPp->top__DOT__cpu0__DOT__data_rs2 = vlTOPp->top__DOT__cpu0__DOT__register_file0__DOT__mem
            [(0x1fU & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                       >> 0x14U))];
    }
    if (__Vdlyvset__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0) {
        vlTOPp->top__DOT__cpu0__DOT__register_file0__DOT__mem[__Vdlyvdim0__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0] 
            = __Vdlyvval__top__DOT__cpu0__DOT__register_file0__DOT__mem__v0;
    }
    if ((0U == (IData)(vlTOPp->top__DOT__cpu0__DOT__ctr))) {
        vlTOPp->top__DOT__cpu0__DOT__instruction = 
            ((0x17fffU >= (0x1ffffU & (vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc 
                                       >> 2U))) ? vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__rom0__DOT__mem
             [(0x1ffffU & (vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc 
                           >> 2U))] : 0U);
    }
    vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc 
        = __Vdly__top__DOT__cpu0__DOT__fetcher0__DOT__pc;
    vlTOPp->top__DOT__cpu0__DOT__lhs_type = ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                              ? 0U : 
                                             ((((0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                | (0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
                                               | (0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                               ? 1U
                                               : ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                   ? 2U
                                                   : 
                                                  ((0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xfU)))
                                                     ? 2U
                                                     : 0U)
                                                    : 3U))));
    vlTOPp->top__DOT__cpu0__DOT__rhs_type = ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                              ? 0U : 
                                             ((((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
                                               | (0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                               ? 1U
                                               : ((
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                   | (0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                   ? 2U
                                                   : 3U)));
    vlTOPp->top__DOT__cpu0__DOT__instruction_code = 
        ((0x37U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
          ? 0xaU : ((0x17U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                     ? 0xbU : ((0x6fU == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                ? 0xcU : ((0x67U == 
                                           (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                           ? 0xdU : 
                                          ((0x63U == 
                                            (0x7fU 
                                             & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                            ? ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                    >> 0xcU)))
                                                ? 0xeU
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x11U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x12U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x13U
                                                        : 0x3fU))))))
                                            : ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x19U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x1aU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x1bU
                                                      : 0x3fU)))
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x14U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x15U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x16U
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x17U
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 0x18U
                                                         : 0x3fU)))))
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? 
                                                    ((0U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 2U
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 3U
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 4U
                                                         : 
                                                        ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 5U
                                                          : 
                                                         ((5U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((0x40000000U 
                                                            & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                            ? 7U
                                                            : 6U)
                                                           : 
                                                          ((6U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 8U
                                                            : 
                                                           ((7U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 9U
                                                             : 0x3fU))))))))
                                                     : 
                                                    ((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 2U
                                                        : 
                                                       ((2U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 3U
                                                         : 
                                                        ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 4U
                                                          : 
                                                         ((4U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 5U
                                                           : 
                                                          ((5U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((0x40000000U 
                                                             & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                             ? 7U
                                                             : 6U)
                                                            : 
                                                           ((6U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 8U
                                                             : 
                                                            ((7U 
                                                              == 
                                                              (7U 
                                                               & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                  >> 0xcU)))
                                                              ? 9U
                                                              : 0x3fU))))))))
                                                      : 0x3fU)))))))));
    vlTOPp->top__DOT__cpu0__DOT__imm = (IData)((((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                 | (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                 ? (QData)((IData)(
                                                                   (0xfffff000U 
                                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                 : 
                                                ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                  ? (QData)((IData)(
                                                                    ((0x100000U 
                                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                         >> 0xbU)) 
                                                                     | ((0xff000U 
                                                                         & vlTOPp->top__DOT__cpu0__DOT__instruction) 
                                                                        | ((0x800U 
                                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                               >> 9U)) 
                                                                           | (0x7feU 
                                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x14U)))))))
                                                  : 
                                                 ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                   ? 
                                                  (((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU))) 
                                                    | (5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU))))
                                                    ? (QData)((IData)(
                                                                      (0x1fU 
                                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                          >> 0x14U))))
                                                    : (QData)((IData)(
                                                                      ((0xfffff000U 
                                                                        & (VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x1fU)))) 
                                                                           << 0xcU)) 
                                                                       | (0xfffU 
                                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                             >> 0x14U))))))
                                                   : 
                                                  (((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                    | (3U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                    ? (QData)((IData)(
                                                                      (0xfffU 
                                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                          >> 0x14U))))
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? (QData)((IData)(
                                                                       ((0xfe0U 
                                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                            >> 0x14U)) 
                                                                        | (0x1fU 
                                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                              >> 7U)))))
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 
                                                     (((QData)((IData)(
                                                                       (1U 
                                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                           >> 0x1fU)))) 
                                                       << 0xcU) 
                                                      | (QData)((IData)(
                                                                        ((0x800U 
                                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                             << 4U)) 
                                                                         | ((0x7e0U 
                                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x14U)) 
                                                                            | (0x1eU 
                                                                               & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 7U)))))))
                                                      : VL_ULL(0))))))));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs = 
        ((0U == (IData)(vlTOPp->top__DOT__cpu0__DOT__lhs_type))
          ? vlTOPp->top__DOT__cpu0__DOT__data_rs1 : 
         ((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__lhs_type))
           ? vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc
           : 0U));
    vlTOPp->top__DOT__cpu0__DOT__fetcher_option = (
                                                   (1U 
                                                    & ((0xeU 
                                                        == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                        ? 
                                                       (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                        == vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                         ? 
                                                        (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                         != vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                         : 
                                                        ((0x10U 
                                                          == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                          ? 
                                                         VL_LTS_III(32,32,32, vlTOPp->top__DOT__cpu0__DOT__data_rs1, vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                          : 
                                                         ((0x11U 
                                                           == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                           ? 
                                                          VL_GTES_III(32,32,32, vlTOPp->top__DOT__cpu0__DOT__data_rs1, vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                           : 
                                                          ((0x12U 
                                                            == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                            ? 
                                                           (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                            < vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                            : 
                                                           ((0x13U 
                                                             == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                             ? 
                                                            (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                             >= vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                             : 0U)))))))
                                                    ? 1U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? 1U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 2U
                                                      : 0U)));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode 
        = (0xfU & ((0xaU > (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                    ? (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code)
                    : ((0xeU > (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                        ? 0U : 0xfU)));
    vlTOPp->top__DOT__cpu0__DOT__uart_we = ((0xf6fff070U 
                                             == (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                 + vlTOPp->top__DOT__cpu0__DOT__imm)) 
                                            & (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs = 
        ((0U == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
          ? vlTOPp->top__DOT__cpu0__DOT__data_rs2 : 
         ((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
           ? vlTOPp->top__DOT__cpu0__DOT__imm : ((2U 
                                                  == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
                                                  ? 4U
                                                  : 0U)));
    vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
        = (vlTOPp->top__DOT__cpu0__DOT__data_rs1 + vlTOPp->top__DOT__cpu0__DOT__imm);
    vlTOPp->top__DOT__cpu0__DOT__data_rd_exec = (IData)(
                                                        (VL_ULL(0x1ffffffff) 
                                                         & ((0U 
                                                             == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                             ? 
                                                            ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                             + (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                              ? 
                                                             ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                              - (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                              : 
                                                             ((2U 
                                                               == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                               ? 
                                                              ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                               << 
                                                               (0x1fU 
                                                                & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))
                                                               : 
                                                              ((3U 
                                                                == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                ? (QData)((IData)(
                                                                                VL_LTS_III(1,32,32, vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs, vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                : 
                                                               ((4U 
                                                                 == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                 ? (QData)((IData)(
                                                                                (vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs 
                                                                                < vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                 : 
                                                                ((5U 
                                                                  == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                  ? 
                                                                 ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                  ^ (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                  : 
                                                                 ((6U 
                                                                   == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                   ? 
                                                                  ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))
                                                                   : 
                                                                  ((7U 
                                                                    == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                    ? 
                                                                   ((0x80000000U 
                                                                     & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)
                                                                     ? 
                                                                    (((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)) 
                                                                     | (~ 
                                                                        (VL_ULL(0xffffffff) 
                                                                         >> 
                                                                         (0x1fU 
                                                                          & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))))
                                                                     : 
                                                                    ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                    : 
                                                                   ((8U 
                                                                     == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                     ? 
                                                                    ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                     | (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                     : 
                                                                    ((9U 
                                                                      == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                      ? 
                                                                     ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                      & (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                      : VL_ULL(0)))))))))))));
    vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store 
        = (0xfU & (((0U == (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                  >> 0xcU))) ? 1U : 
                    ((1U == (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                   >> 0xcU))) ? 3U : 0xfU)) 
                   << (3U & vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr)));
    vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w 
        = ((0x1fU >= (0x18U & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->top__DOT__cpu0__DOT__data_rs2 
                                           << (0x18U 
                                               & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED 
        = (1U & (~ (vlTOPp->top__DOT__cpu0__DOT__instruction 
                    >> 0xeU)));
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE 
        = (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
        = ((0x1fU >= (0x18U & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_r 
                                           >> (0x18U 
                                               & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout 
        = ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
            ? ((IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                ? ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                           >> 0xfU)))) 
                                   << 0x10U)) | (0xffffU 
                                                 & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : (0xffffU & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
            : ((0U == (IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
                ? ((IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                    ? ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                               >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                    : (0xffU & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY));
    vlTOPp->top__DOT__cpu0__DOT___data_rd_memory = vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout;
}

void Vtop::_initial__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__4\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*159:0*/ __Vtemp1[5];
    WData/*159:0*/ __Vtemp2[5];
    // Body
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x64617461U;
    __Vtemp1[2U] = 0x61726b5fU;
    __Vtemp1[3U] = 0x6f72656dU;
    __Vtemp1[4U] = 0x2e2f63U;
    VL_READMEM_N(true, 32, 65536, 0, VL_CVT_PACK_STR_NW(5, __Vtemp1)
                 , vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles = 0U;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d = 0U;
    vlTOPp->top__DOT__cpu0__DOT__uart_OUT_data = 1U;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount = 0U;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__shifter = 0U;
    vlTOPp->top__DOT__cpu0__DOT__register_file0__DOT__mem[0U] = 0U;
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x636f6465U;
    __Vtemp2[2U] = 0x61726b5fU;
    __Vtemp2[3U] = 0x6f72656dU;
    __Vtemp2[4U] = 0x2e2f63U;
    VL_READMEM_N(true, 32, 98304, 0, VL_CVT_PACK_STR_NW(5, __Vtemp2)
                 , vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__rom0__DOT__mem
                 , 0, ~VL_ULL(0));
    vlTOPp->top__DOT__cpu0__DOT__ctr = 0xfU;
    vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc = 0x8000U;
}

void Vtop::_settle__TOP__5(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__5\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__cpu0__DOT__lhs_type = ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                              ? 0U : 
                                             ((((0x17U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                | (0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
                                               | (0x67U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                               ? 1U
                                               : ((0x37U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                   ? 2U
                                                   : 
                                                  ((0x13U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (0x1fU 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xfU)))
                                                     ? 2U
                                                     : 0U)
                                                    : 3U))));
    vlTOPp->top__DOT__cpu0__DOT__rhs_type = ((0x33U 
                                              == (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                              ? 0U : 
                                             ((((0x13U 
                                                 == 
                                                 (0x7fU 
                                                  & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))) 
                                               | (0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                               ? 1U
                                               : ((
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                   | (0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                   ? 2U
                                                   : 3U)));
    vlTOPp->top__DOT__cpu0__DOT__instruction_code = 
        ((0x37U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
          ? 0xaU : ((0x17U == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                     ? 0xbU : ((0x6fU == (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                ? 0xcU : ((0x67U == 
                                           (0x7fU & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                           ? 0xdU : 
                                          ((0x63U == 
                                            (0x7fU 
                                             & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                            ? ((0U 
                                                == 
                                                (7U 
                                                 & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                    >> 0xcU)))
                                                ? 0xeU
                                                : (
                                                   (1U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0xfU
                                                    : 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x10U
                                                     : 
                                                    ((5U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x11U
                                                      : 
                                                     ((6U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x12U
                                                       : 
                                                      ((7U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x13U
                                                        : 0x3fU))))))
                                            : ((0x23U 
                                                == 
                                                (0x7fU 
                                                 & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                ? (
                                                   (0U 
                                                    == 
                                                    (7U 
                                                     & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                        >> 0xcU)))
                                                    ? 0x19U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x1aU
                                                     : 
                                                    ((2U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x1bU
                                                      : 0x3fU)))
                                                : (
                                                   (3U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                    ? 
                                                   ((0U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU)))
                                                     ? 0x14U
                                                     : 
                                                    ((1U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0x15U
                                                      : 
                                                     ((2U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 0x16U
                                                       : 
                                                      ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 0x17U
                                                        : 
                                                       ((5U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 0x18U
                                                         : 0x3fU)))))
                                                    : 
                                                   ((0x13U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? 
                                                    ((0U 
                                                      == 
                                                      (7U 
                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                          >> 0xcU)))
                                                      ? 0U
                                                      : 
                                                     ((1U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 2U
                                                       : 
                                                      ((2U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 3U
                                                        : 
                                                       ((3U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 4U
                                                         : 
                                                        ((4U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 5U
                                                          : 
                                                         ((5U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 
                                                          ((0x40000000U 
                                                            & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                            ? 7U
                                                            : 6U)
                                                           : 
                                                          ((6U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 8U
                                                            : 
                                                           ((7U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 9U
                                                             : 0x3fU))))))))
                                                     : 
                                                    ((0x33U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 
                                                     ((0U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU)))
                                                       ? 
                                                      ((0x40000000U 
                                                        & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                        ? 1U
                                                        : 0U)
                                                       : 
                                                      ((1U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                            >> 0xcU)))
                                                        ? 2U
                                                        : 
                                                       ((2U 
                                                         == 
                                                         (7U 
                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                             >> 0xcU)))
                                                         ? 3U
                                                         : 
                                                        ((3U 
                                                          == 
                                                          (7U 
                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                              >> 0xcU)))
                                                          ? 4U
                                                          : 
                                                         ((4U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                               >> 0xcU)))
                                                           ? 5U
                                                           : 
                                                          ((5U 
                                                            == 
                                                            (7U 
                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                >> 0xcU)))
                                                            ? 
                                                           ((0x40000000U 
                                                             & vlTOPp->top__DOT__cpu0__DOT__instruction)
                                                             ? 7U
                                                             : 6U)
                                                            : 
                                                           ((6U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                 >> 0xcU)))
                                                             ? 8U
                                                             : 
                                                            ((7U 
                                                              == 
                                                              (7U 
                                                               & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                  >> 0xcU)))
                                                              ? 9U
                                                              : 0x3fU))))))))
                                                      : 0x3fU)))))))));
    vlTOPp->top__DOT__cpu0__DOT__imm = (IData)((((0x37U 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                 | (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                 ? (QData)((IData)(
                                                                   (0xfffff000U 
                                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                 : 
                                                ((0x6fU 
                                                  == 
                                                  (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                  ? (QData)((IData)(
                                                                    ((0x100000U 
                                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                         >> 0xbU)) 
                                                                     | ((0xff000U 
                                                                         & vlTOPp->top__DOT__cpu0__DOT__instruction) 
                                                                        | ((0x800U 
                                                                            & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                               >> 9U)) 
                                                                           | (0x7feU 
                                                                              & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x14U)))))))
                                                  : 
                                                 ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                   ? 
                                                  (((1U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                         >> 0xcU))) 
                                                    | (5U 
                                                       == 
                                                       (7U 
                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                           >> 0xcU))))
                                                    ? (QData)((IData)(
                                                                      (0x1fU 
                                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                          >> 0x14U))))
                                                    : (QData)((IData)(
                                                                      ((0xfffff000U 
                                                                        & (VL_NEGATE_I((IData)(
                                                                                (1U 
                                                                                & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x1fU)))) 
                                                                           << 0xcU)) 
                                                                       | (0xfffU 
                                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                             >> 0x14U))))))
                                                   : 
                                                  (((0x67U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction)) 
                                                    | (3U 
                                                       == 
                                                       (0x7fU 
                                                        & vlTOPp->top__DOT__cpu0__DOT__instruction)))
                                                    ? (QData)((IData)(
                                                                      (0xfffU 
                                                                       & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                          >> 0x14U))))
                                                    : 
                                                   ((0x23U 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? (QData)((IData)(
                                                                       ((0xfe0U 
                                                                         & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                            >> 0x14U)) 
                                                                        | (0x1fU 
                                                                           & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                              >> 7U)))))
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 
                                                     (((QData)((IData)(
                                                                       (1U 
                                                                        & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                           >> 0x1fU)))) 
                                                       << 0xcU) 
                                                      | (QData)((IData)(
                                                                        ((0x800U 
                                                                          & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                             << 4U)) 
                                                                         | ((0x7e0U 
                                                                             & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 0x14U)) 
                                                                            | (0x1eU 
                                                                               & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                                                                >> 7U)))))))
                                                      : VL_ULL(0))))))));
    vlTOPp->uart_tx = vlTOPp->top__DOT__cpu0__DOT__uart_OUT_data;
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__uart_busy 
        = (0U != (7U & ((IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount) 
                        >> 1U)));
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__sending 
        = (0U != (IData)(vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__bitcount));
    vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__dNxt = 
        (0x1fffffffU & (vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d 
                        + ((0x10000000U & vlTOPp->top__DOT__cpu0__DOT__uart0__DOT__d)
                            ? 0x1c200U : 0xfa0be100U)));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs = 
        ((0U == (IData)(vlTOPp->top__DOT__cpu0__DOT__lhs_type))
          ? vlTOPp->top__DOT__cpu0__DOT__data_rs1 : 
         ((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__lhs_type))
           ? vlTOPp->top__DOT__cpu0__DOT__fetcher0__DOT__pc
           : 0U));
    vlTOPp->top__DOT__cpu0__DOT__fetcher_option = (
                                                   (1U 
                                                    & ((0xeU 
                                                        == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                        ? 
                                                       (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                        == vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                        : 
                                                       ((0xfU 
                                                         == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                         ? 
                                                        (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                         != vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                         : 
                                                        ((0x10U 
                                                          == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                          ? 
                                                         VL_LTS_III(32,32,32, vlTOPp->top__DOT__cpu0__DOT__data_rs1, vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                          : 
                                                         ((0x11U 
                                                           == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                           ? 
                                                          VL_GTES_III(32,32,32, vlTOPp->top__DOT__cpu0__DOT__data_rs1, vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                           : 
                                                          ((0x12U 
                                                            == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                            ? 
                                                           (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                            < vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                            : 
                                                           ((0x13U 
                                                             == (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                                                             ? 
                                                            (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                             >= vlTOPp->top__DOT__cpu0__DOT__data_rs2)
                                                             : 0U)))))))
                                                    ? 1U
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                     ? 1U
                                                     : 
                                                    ((0x67U 
                                                      == 
                                                      (0x7fU 
                                                       & vlTOPp->top__DOT__cpu0__DOT__instruction))
                                                      ? 2U
                                                      : 0U)));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode 
        = (0xfU & ((0xaU > (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                    ? (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code)
                    : ((0xeU > (IData)(vlTOPp->top__DOT__cpu0__DOT__instruction_code))
                        ? 0U : 0xfU)));
    vlTOPp->top__DOT__cpu0__DOT__uart_we = ((0xf6fff070U 
                                             == (vlTOPp->top__DOT__cpu0__DOT__data_rs1 
                                                 + vlTOPp->top__DOT__cpu0__DOT__imm)) 
                                            & (0x23U 
                                               == (0x7fU 
                                                   & vlTOPp->top__DOT__cpu0__DOT__instruction)));
    vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs = 
        ((0U == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
          ? vlTOPp->top__DOT__cpu0__DOT__data_rs2 : 
         ((1U == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
           ? vlTOPp->top__DOT__cpu0__DOT__imm : ((2U 
                                                  == (IData)(vlTOPp->top__DOT__cpu0__DOT__rhs_type))
                                                  ? 4U
                                                  : 0U)));
    vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
        = (vlTOPp->top__DOT__cpu0__DOT__data_rs1 + vlTOPp->top__DOT__cpu0__DOT__imm);
    vlTOPp->top__DOT__cpu0__DOT__data_rd_exec = (IData)(
                                                        (VL_ULL(0x1ffffffff) 
                                                         & ((0U 
                                                             == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                             ? 
                                                            ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                             + (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                              ? 
                                                             ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                              - (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                              : 
                                                             ((2U 
                                                               == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                               ? 
                                                              ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                               << 
                                                               (0x1fU 
                                                                & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))
                                                               : 
                                                              ((3U 
                                                                == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                ? (QData)((IData)(
                                                                                VL_LTS_III(1,32,32, vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs, vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                : 
                                                               ((4U 
                                                                 == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                 ? (QData)((IData)(
                                                                                (vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs 
                                                                                < vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                 : 
                                                                ((5U 
                                                                  == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                  ? 
                                                                 ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                  ^ (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                  : 
                                                                 ((6U 
                                                                   == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                   ? 
                                                                  ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                   >> 
                                                                   (0x1fU 
                                                                    & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))
                                                                   : 
                                                                  ((7U 
                                                                    == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                    ? 
                                                                   ((0x80000000U 
                                                                     & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)
                                                                     ? 
                                                                    (((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                      >> 
                                                                      (0x1fU 
                                                                       & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)) 
                                                                     | (~ 
                                                                        (VL_ULL(0xffffffff) 
                                                                         >> 
                                                                         (0x1fU 
                                                                          & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs))))
                                                                     : 
                                                                    ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                     >> 
                                                                     (0x1fU 
                                                                      & vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                    : 
                                                                   ((8U 
                                                                     == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                     ? 
                                                                    ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                     | (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                     : 
                                                                    ((9U 
                                                                      == (IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__alucode))
                                                                      ? 
                                                                     ((QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__lhs)) 
                                                                      & (QData)((IData)(vlTOPp->top__DOT__cpu0__DOT__exec0__DOT__rhs)))
                                                                      : VL_ULL(0)))))))))))));
    vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__mask_store 
        = (0xfU & (((0U == (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                  >> 0xcU))) ? 1U : 
                    ((1U == (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                                   >> 0xcU))) ? 3U : 0xfU)) 
                   << (3U & vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr)));
    vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_w 
        = ((0x1fU >= (0x18U & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->top__DOT__cpu0__DOT__data_rs2 
                                           << (0x18U 
                                               & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED 
        = (1U & (~ (vlTOPp->top__DOT__cpu0__DOT__instruction 
                    >> 0xeU)));
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE 
        = (3U & (vlTOPp->top__DOT__cpu0__DOT__instruction 
                 >> 0xcU));
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
        = ((0x1fU >= (0x18U & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                               << 3U))) ? (vlTOPp->top__DOT__cpu0__DOT__main_memory0__DOT__data_r 
                                           >> (0x18U 
                                               & (vlTOPp->top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr 
                                                  << 3U)))
            : 0U);
    vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout 
        = ((1U == (IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
            ? ((IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                ? ((0xffff0000U & (VL_NEGATE_I((IData)(
                                                       (1U 
                                                        & (vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                           >> 0xfU)))) 
                                   << 0x10U)) | (0xffffU 
                                                 & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : (0xffffU & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
            : ((0U == (IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE))
                ? ((IData)(vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED)
                    ? ((0xffffff00U & (VL_NEGATE_I((IData)(
                                                           (1U 
                                                            & (vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY 
                                                               >> 7U)))) 
                                       << 8U)) | (0xffU 
                                                  & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                    : (0xffU & vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY))
                : vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY));
    vlTOPp->top__DOT__cpu0__DOT___data_rd_memory = vlTOPp->__Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout;
}

VL_INLINE_OPT void Vtop::_sequent__TOP__6(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__6\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles 
        = vlTOPp->__Vdly__top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles;
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
    vlTOPp->_initial__TOP__4(vlSymsp);
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
}
#endif  // VL_DEBUG

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    uart_tx = VL_RAND_RESET_I(1);
    top__DOT__cpu0__DOT__ctr = VL_RAND_RESET_I(4);
    top__DOT__cpu0__DOT__instruction = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__instruction_code = VL_RAND_RESET_I(6);
    top__DOT__cpu0__DOT__lhs_type = VL_RAND_RESET_I(2);
    top__DOT__cpu0__DOT__rhs_type = VL_RAND_RESET_I(2);
    top__DOT__cpu0__DOT__data_rs1 = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__data_rs2 = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__data_rd_exec = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__imm = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__fetcher_option = VL_RAND_RESET_I(2);
    top__DOT__cpu0__DOT___data_rd_memory = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT____Vcellinp__main_memory0__addr = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__uart_we = VL_RAND_RESET_I(1);
    top__DOT__cpu0__DOT__uart_OUT_data = VL_RAND_RESET_I(1);
    top__DOT__cpu0__DOT__fetcher0__DOT__pc = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<98304; ++__Vi0) {
            top__DOT__cpu0__DOT__fetcher0__DOT__rom0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            top__DOT__cpu0__DOT__register_file0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__cpu0__DOT__exec0__DOT__alucode = VL_RAND_RESET_I(4);
    top__DOT__cpu0__DOT__exec0__DOT__rhs = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__exec0__DOT__lhs = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__main_memory0__DOT__data_r = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__main_memory0__DOT__data_w = VL_RAND_RESET_I(32);
    top__DOT__cpu0__DOT__main_memory0__DOT__mask_store = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<65536; ++__Vi0) {
            top__DOT__cpu0__DOT__main_memory0__DOT__ram0__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }}
    top__DOT__cpu0__DOT__uart0__DOT__bitcount = VL_RAND_RESET_I(4);
    top__DOT__cpu0__DOT__uart0__DOT__shifter = VL_RAND_RESET_I(9);
    top__DOT__cpu0__DOT__uart0__DOT__uart_busy = VL_RAND_RESET_I(1);
    top__DOT__cpu0__DOT__uart0__DOT__sending = VL_RAND_RESET_I(1);
    top__DOT__cpu0__DOT__uart0__DOT__d = VL_RAND_RESET_I(29);
    top__DOT__cpu0__DOT__uart0__DOT__dNxt = VL_RAND_RESET_I(29);
    top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__MEMORY = VL_RAND_RESET_I(32);
    __Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__TYPE = VL_RAND_RESET_I(2);
    __Vfunc_top__DOT__cpu0__DOT__main_memory0__DOT__MEMORY_RESHAPE__0__IS_SIGNED = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__cpu0__DOT__hardware_counter0__DOT__cycles = VL_RAND_RESET_I(32);
}
