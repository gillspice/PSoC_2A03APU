
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
// Generated on 04/12/2017 at 20:28
// Component: internal_period
module internal_period (
	output [10:0] oInternal_period,
	output  oSweep_silence,
	input   iClk,
	input  [10:0] iPeriod,
	input   iPeriod_reset,
	input   iSweep_mode,
	input   iSweep_refresh_rate_clk,
	input   iSweep_shift
);

//`#start body` -- edit after this line, do not edit this line
//-------------------------------------------------------------------------------------------------------
  //  INTERNAL PERIOD
  //-------------------------------------------------------------------------------------------------------
  
  reg [11:0] oInternal_period;
  reg silence;
  
  always @(posedge iClk or posedge iPeriod_reset)
  begin
    if (iPeriod_reset)
	 begin
	   oInternal_period <= iPeriod;
	 end
	 else
    begin
      if (iSweep_refresh_rate_clk)
	   begin
	     if (iSweep_mode == 0) oInternal_period <= oInternal_period + (oInternal_period >> iSweep_shift);
		  else oInternal_period <= oInternal_period - (oInternal_period >> iSweep_shift);
		  if (oInternal_period[11]) silence <=1;
		  else silence <=0;
	   end
    end
  end 
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
