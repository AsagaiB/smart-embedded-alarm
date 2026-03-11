
// custom_led_controller.v
// LED pattern generator controlled by HPS via switches

module custom_led_controller (
    input wire clk,
    input wire reset,
    input wire [3:0] control,
    output reg [7:0] led_out
);

    reg [31:0] counter;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 0;
            led_out <= 8'b00000000;
        end else begin
            counter <= counter + 1;

            case (control)
                4'b0001: led_out <= 8'b10101010;
                4'b0010: led_out <= 8'b01010101;
                4'b0011: led_out <= counter[23:16];
                default: led_out <= 8'b11110000;
            endcase
        end
    end

endmodule
