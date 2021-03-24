// ====================================================================================
// 										  Define Module: CLOCK DIVIDER
// ====================================================================================
module ClkDiv_5Hz(
	CLK,
	RST,
	CLKOUT
);

// ====================================================================================
// 										Port Declarations
// ====================================================================================
   input CLK;		// 12MHz onboard clock
   input RST;		// Reset
   output CLKOUT;	// New clock output
   
   
// ====================================================================================
// 							   Parameters, Registers, and Wires
// ====================================================================================	
   reg clkToggle;
   //Need to divide (12Mhz->5Hz) and we toggle at each edge (factor 2) = 4,800,000 = 0x124F80(21 bits)
   // Current count value
   reg [20:0] clkCount = 21'h000000;
   // Value to toggle output clock at
   parameter [20:0] cntEndVal = 21'h124F80;
   assign CLKOUT = clkToggle;
   
//  ===================================================================================
// 							  				Implementation
//  ===================================================================================

		always @(posedge CLK or posedge RST)
			// Reset clock
			if (RST == 1'b1) begin
					clkToggle <= 1'b0;
					clkCount <= 21'h000000;
			end
			else begin
					if (clkCount == cntEndVal) begin
						clkToggle <= (~clkToggle); // toggle clock
						clkCount <= 21'h000000;
					end
					else begin
						clkCount <= clkCount + 1'b1; //increments counter
					end
			end
   
endmodule
