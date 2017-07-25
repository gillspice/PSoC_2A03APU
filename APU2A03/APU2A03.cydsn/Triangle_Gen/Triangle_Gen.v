
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
// Generated on 04/11/2017 at 09:04
// Component: Triangle_Gen
module Triangle_Gen (
	output reg [3:0] oData,
	input   iClk,
	input   iEnable,
	input   iReset
);


//  output reg [3:0] oData;
//`#start body` -- edit after this line, do not edit this line
  reg mode;
  
  always @(posedge iClk or posedge iReset)
  begin
    if (iReset == 1)
    begin
      oData <= 4'b0000;
		mode <= 0;
    end else
    begin
	   if (iEnable)
		begin
        if (mode == 0)
		  begin
		    if (oData < 4'b1111) 
		      oData <= oData + 1;
		    else mode <= 1;
		  end else
		  begin
		    if (oData > 4'b0000) 
		      oData <= oData - 1;
		    else mode <= 0;
		  end
      end
    end
  end 
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
