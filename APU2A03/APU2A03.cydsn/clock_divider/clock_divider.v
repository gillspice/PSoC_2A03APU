    
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
// Generated on 04/10/2017 at 19:39
// Component: clock_divider
module clock_divider (
	input   iClk,
    input   iReset,
    input   iEnable,
	input  [10:0] iDivider,
	output  oClk
);

//`#start body` -- edit after this line, do not edit this line
 parameter DIVIDER_WIDTH = 11;
//        Your code goes here
//-------------------------------------------------------------------------------------------------------
  //  PORTS
  //-------------------------------------------------------------------------------------------------------
  
//  input iClk;
//  input iReset;
//  input iEnable;
 // input [DIVIDER_WIDTH-1:0] iDivider;
//  output oClk;
  
  reg [DIVIDER_WIDTH-1:0] counter;
    
  always @(posedge iClk or posedge iReset)
  begin
    if (iReset)
	   counter <= iDivider;
    else
	   if (iEnable)
		begin
	     if (counter == 0) 
	       counter <= iDivider;
        else 
		    counter <= counter - 1;
	  end
  end
  
  //-------------------------------------------------------------------------------------------------------
  //  OUTPUT
  //-------------------------------------------------------------------------------------------------------
  
  

  
  reg buffer_before;
  reg buffer_after;
   
  always @(posedge iClk)
  begin
    buffer_before <= (counter == 0);
  end
  
  always @(posedge iClk)
  begin
    buffer_after <= buffer_before;
  end
	
  
  //Warning: if iDivider is 0, there will be no phase shift, otherwise the outpu signal will be one cycle late!
  assign oClk = (iDivider == 0) ? iEnable:(buffer_before && !buffer_after);

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
