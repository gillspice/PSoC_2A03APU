
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
// Generated on 04/10/2017 at 20:20
// Component: volume_generator
module volume_generator (
	output [3:0] oData,
	input   iClk,
	input   iEnable,
	input   iEnable_Loop,
	input  [3:0] iVolume_or_decay_rate,
    input  iReset,
    input  iEnvelope_clk
);

//`#start body` -- edit after this line, do not edit this line
//-------------------------------------------------------------------------------------------------------
  //  ENVELOPE CLOCK
  //-------------------------------------------------------------------------------------------------------

//  wire envelope_clk;
  
//  clock_divider #(
//  	 .DIVIDER_WIDTH(4)
//  ) clk_decay (
//    .iClk(iClk), 
//	 .iReset(iReset),
//	 .iEnable(iEnvelope_clk),
//	 .iDivider(iVolume_or_decay_rate),
//    .oClk(envelope_clk)
 // );
  
  //-------------------------------------------------------------------------------------------------------
  //  INTERNAL VOLUME REGISTER
  //-------------------------------------------------------------------------------------------------------

  reg [3:0] internal_volume;
  
  always @(posedge iClk or posedge iReset)
  begin
    if (iReset) internal_volume <= 4'b1111;//iVolume_or_decay_rate;
	 else
    begin
      if (iEnvelope_clk)
      begin		
        if (internal_volume == 0)
	     begin  
		    if (iEnable_Loop) internal_volume <= 4'b1111;
	     end else
	     internal_volume <= internal_volume - 1;
		end
    end
  end
  
  //-------------------------------------------------------------------------------------------------------
  //  OUTPUT
  //-------------------------------------------------------------------------------------------------------
  
  assign oData = (iEnable) ? internal_volume:iVolume_or_decay_rate;
  	
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
