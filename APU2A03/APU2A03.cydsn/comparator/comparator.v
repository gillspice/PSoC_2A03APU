
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
// Generated on 04/12/2017 at 19:51
// Component: comparator
module comparator (
	output  oChange,
	input   iClk,
	input  [1:0] iSignal
);

//`#start body` -- edit after this line, do not edit this line
  //-------------------------------------------------------------------------------------------------------
  //  PARAMETERS 
  //-------------------------------------------------------------------------------------------------------
  
  parameter WIDTH = 2;
//-------------------------------------------------------------------------------------------------------
  //  REGISTERS
  //-------------------------------------------------------------------------------------------------------

  reg [WIDTH - 1:0] buffer_before;

  always @(posedge iClk)
  begin
    buffer_before <= iSignal;
  end

  //-------------------------------------------------------------------------------------------------------
  //  OUTPUT
  //-------------------------------------------------------------------------------------------------------

  assign oChange = (buffer_before == iSignal) ? 0:1;
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
