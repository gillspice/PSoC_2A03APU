
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
// Generated on 04/13/2017 at 16:15
// Component: component01
module component01 (
	output [11:0] oPeriod_shift,
	input  [11:0] iPeriod,
	input  [2:0] iSweep_shift,
    input iEnable
);

reg [11:0]period_shift;

//`#start body` -- edit after this line, do not edit this line
always @ iEnable
begin
    period_shift <= iPeriod >> iSweep_shift;
end
//        Your code goes here
assign oPeriod_shift = period_shift;
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
