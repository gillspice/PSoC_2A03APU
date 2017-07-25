
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 04/12/2017 at 19:41
// Component: rectangle_generator
module rectangle_generator (
	output  oData,
	input   iClk,
	input   iDuty_cycle_reset,
	input  [1:0] iDuty_cycle_type,
	input   iEnable,
	input   iReset
);

//`#start body` -- edit after this line, do not edit this line
  //-------------------------------------------------------------------------------------------------------
  //  DUTY CYCLE TYPE
  //-------------------------------------------------------------------------------------------------------
  
 /* wire [15:0] duty_cycle0;
  wire [15:0] duty_cycle1;
  wire [15:0] duty_cycle2;
  wire [15:0] duty_cycle3;  
 
  assign duty_cycle0 = 16'b0011000000000000;
  assign duty_cycle1 = 16'b0011110000000000;
  assign duty_cycle2 = 16'b0011111111000000;
  assign duty_cycle3 = 16'b1100001111111111;*/
  
  reg [15:0] wave; 
  initial wave <= 127;
  
  
  always @(posedge iClk or posedge iDuty_cycle_reset or posedge iReset) // added ireset
  begin
    if (iDuty_cycle_reset )//|| iReset) //added ireset
      case (iDuty_cycle_type)
        0: wave <= 16'b0011000000000000;	
        1: wave <= 16'b0011110000000000;
        2: wave <= 16'b0011111111000000;
        3: wave <= 16'b1100001111111111;
      endcase
    else
    begin
	   if (iEnable) 
		  wave <= {wave[0],wave[15:1]};
    end
  end
  
  assign oData = wave[0];
  
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
