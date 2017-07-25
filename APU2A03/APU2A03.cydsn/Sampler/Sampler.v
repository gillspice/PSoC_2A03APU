
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
// Generated on 04/11/2017 at 16:53
// Component: Sampler
module Sampler (
	output  iSignal,
	output  oSignal,
	input   iClk
);

//`#start body` -- edit after this line, do not edit this line
  //-------------------------------------------------------------------------------------------------------
  //  REGISTERS
  //-------------------------------------------------------------------------------------------------------
  
  reg buffer_before;
  reg buffer_after;
   
  always @(posedge iClk)
  begin
    buffer_before <= iSignal;
  end
  
  always @(posedge iClk)
  begin
    buffer_after <= buffer_before;
  end
	
  assign oSignal = (buffer_before && !buffer_after);

//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
