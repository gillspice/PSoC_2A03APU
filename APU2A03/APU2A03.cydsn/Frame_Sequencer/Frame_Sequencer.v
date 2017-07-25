
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
// Generated on 04/11/2017 at 16:25
// Component: Frame_Sequencer
module Frame_Sequencer (
	output  oEnvelope_linear_clk,
	output  oIRQ_clk,
	output  oLength_sweep_clk,
	input   iClk,
	input   iMode,
	input   iReset
);

//`#start body` -- edit after this line, do not edit this line
 //-------------------------------------------------------------------------------------------------------
  //  PARAMETERS
  //-------------------------------------------------------------------------------------------------------
  
  parameter PAL_mode = 0;
  parameter PAL_sequence = 3;
  
  parameter NTSC_mode = 1;
  parameter NTSC_sequence = 4;
  
  //-------------------------------------------------------------------------------------------------------
  //  PORTS
  //-------------------------------------------------------------------------------------------------------
  
  input iClk;
  input iReset;
  input iMode;
  output oIRQ_clk;
  output oLength_sweep_clk;
  output reg oEnvelope_linear_clk;
  
  //-------------------------------------------------------------------------------------------------------
  //  CLOCK DIVIDER, Generating 240Hz
  //-------------------------------------------------------------------------------------------------------
    
  wire clk_240;
  wire [12:0] clk_240_divider;
  assign clk_240_divider = 13'd7439;  //1.78Mhz/240Hz - 1

  clock_divider #(
  	 .DIVIDER_WIDTH(13)
  ) frame_sequencer_divider (
    .iClk(iClk), 
	 .iReset(iReset),
	 .iEnable(1'b1),
	 .iDivider(clk_240_divider),
    .oClk(clk_240)
  );
	
  //-------------------------------------------------------------------------------------------------------
  //  SEQUENCER
  //-------------------------------------------------------------------------------------------------------
	 
  reg [2:0] counter;

  always @(posedge iClk or posedge iReset)
  begin
    if (iReset)
      counter <= 0;  
	 else 
	 begin
	   if (clk_240)
		begin
	     if (counter == 0)
		  begin
		    if (iMode == PAL_mode) 
	         counter <= PAL_sequence;
	       else 
	         counter <= NTSC_sequence;  
        end
		  else
		    counter <= counter - 1;
	   end
	 end
  end
  
  //-------------------------------------------------------------------------------------------------------
  //  OUTPUTS
  //-------------------------------------------------------------------------------------------------------
  
  sampler IRQ(
    .iClk(iClk),
	 .iSignal((counter == 3) && (iMode == PAL_mode)),
	 .oSignal(oIRQ_clk)
  );
  
  sampler length_sweep(
    .iClk(iClk),
	 .iSignal( (((counter == 1) || (counter == 3)) && (iMode == PAL_mode)) || (((counter == 0) || (counter == 2)) && (iMode == NTSC_mode)) ),
	 .oSignal(oLength_sweep_clk)
  );

  wire envelope_linear_delay;

  sampler envelope_linear(
    .iClk(iClk),
	 .iSignal(clk_240 & (counter < 4)),
	 .oSignal(envelope_linear_delay)
  );
  
  always @(posedge iClk or posedge iReset)
  begin
    if (iReset)
	   oEnvelope_linear_clk <= 0;
	 else oEnvelope_linear_clk <= envelope_linear_delay;
  end
//        Your code goes here

//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line
