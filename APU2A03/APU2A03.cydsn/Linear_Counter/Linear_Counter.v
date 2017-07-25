
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
// Generated on 04/11/2017 at 14:49
// Component: Linear_Counter
module Linear_Counter (
	output  oData,
	input   iClk,
	input   iControl_flag,
	input  [6:0] iDuration,
	input   iReset,
    input   iEnable
);

//`#start body` -- edit after this line, do not edit this line
//-------------------------------------------------------------------------------------------------------
  //  HALT FLAG
  //-------------------------------------------------------------------------------------------------------
    
  reg halt_flag;
	 
 /* always @(posedge iClk or posedge iReset)
  begin
	 if (iReset == 1)
	   halt_flag <= 1;
	 //else
     // if (!iControl_flag) halt_flag <= 0;
  end
*/  
  //-------------------------------------------------------------------------------------------------------
  //  COUNTER
  //-------------------------------------------------------------------------------------------------------
 
  reg [6:0] counter;
 
  always @(posedge iClk or posedge iReset)
  begin
    if (iReset) halt_flag <= 1;
	 else if (iEnable == 1) begin
	     	 if (halt_flag) begin
			  counter <= iDuration;
			  if (!iControl_flag) halt_flag <= 0; 
		    end else if (counter > 0) counter <= counter - 1;
		   end
  end
  
  //-------------------------------------------------------------------------------------------------------
  //  OUTPUT
  //-------------------------------------------------------------------------------------------------------
  
  assign oData = (counter > 0) ? 1:0;
  
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
