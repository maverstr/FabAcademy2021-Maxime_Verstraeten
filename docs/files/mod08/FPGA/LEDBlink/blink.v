module blinking ( //new module
    input CLK,
    output [1:0] LED //2 LEDs
);
    reg data1 = 1'b1;
    reg [24:0] counter;
    reg state;
    
    assign LED[0] = state; //sets this pin to state
    assign LED[1] = data1; // sets this pin to high
    
    always @ (posedge CLK) begin
        counter <= counter + 1;
        state <= counter[24]; // <--data to change after 2^26 clock
    end

endmodule