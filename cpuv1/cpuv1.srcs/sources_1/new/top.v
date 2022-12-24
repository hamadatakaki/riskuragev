module top(
    input wire clk, rst_n,
    output wire uart_tx
);
    cpu cpu0(
        .clk(clk),
        .rst_n(rst_n),
        .uart_tx(uart_tx)
    );  
endmodule
