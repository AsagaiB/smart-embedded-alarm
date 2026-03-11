
// top.v
// Basic DE10-Standard top-level wrapper

module top (
    input wire CLOCK_50,
    input wire [3:0] SW,
    output wire [7:0] LED
);

    custom_led_controller u0 (
        .clk(CLOCK_50),
        .reset(1'b0),
        .control(SW),
        .led_out(LED)
    );

endmodule
