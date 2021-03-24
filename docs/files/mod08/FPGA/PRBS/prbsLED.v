// ====================================================================================
// 										  Define Module: PRBS GENERATOR
// ====================================================================================
module blinking (
    CLOCK_12, // 12MHz clock
    RST, // reset signal
    LEDs //5 LEDS
);
// ====================================================================================
// 										Port Declarations
// ====================================================================================
    input CLOCK_12; // 5Hz clock coming from clock divider module
    input RST; // reset signal
    output [4:0] LEDs ;//5 LEDS

// ====================================================================================
// 							   Parameters, Registers, and Wires
// ====================================================================================
    /* regs */
   parameter size = 5,
        TAP1 = 4, //taps taken from the shift register to XOR' them
        TAP2 = 3;
        
   reg [size-1:0] prbs_state;
   
    /* assign */
   assign LEDs[0] = prbs_state[0];
   assign LEDs[1] = prbs_state[1];
   assign LEDs[2] = prbs_state[2];
   assign LEDs[3] = prbs_state[3];
   assign LEDs[4] = prbs_state[4];
   
   ClkDiv_5Hz clkdiv ( //Getting the new clock from the clkdivider
	.CLK(CLOCK_12),
	.RST(RST),
	.CLKOUT(clk)
   );
    
   
//  ===================================================================================
// 							  				Implementation
//  ===================================================================================

   always @ (posedge clk or posedge RST) begin
     if (RST)
       prbs_state <= 1; //anything but the all 0s case is fine, otherwise it gets stuck (bad seed).
     else
       prbs_state <= {prbs_state,prbs_state[TAP1]^prbs_state[TAP2]}; //concatenation of the previous state and the XOR of two taps (shifting the bits in the register)
    end

endmodule


