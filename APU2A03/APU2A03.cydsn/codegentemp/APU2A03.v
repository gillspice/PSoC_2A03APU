// ======================================================================
// APU2A03.v generated from TopDesign.cysch
// 07/25/2017 at 10:20
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: PRS_v2_40
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PRS_v2_40"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PRS_v2_40\PRS_v2_40.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PRS_v2_40"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PRS_v2_40\PRS_v2_40.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: B_Counter_v3_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=3, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=0, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=255, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=255, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RunMode=1, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Length_Counter, CY_INSTANCE_SHORT_NAME=Length_Counter, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=Length_Counter, )
module Counter_v3_0_0 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 3;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 8;
    parameter RunMode = 1;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 3;
    defparam CounterUDB.CompareMode = 3;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 1;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=3, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=0, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=255, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=255, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RunMode=1, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Length_Counter_1, CY_INSTANCE_SHORT_NAME=Length_Counter_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=Length_Counter_1, )
module Counter_v3_0_1 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 3;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 8;
    parameter RunMode = 1;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 3;
    defparam CounterUDB.CompareMode = 3;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 1;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: Count7_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0\Count7_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\Count7_v1_0\Count7_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=1, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=255, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Tri_Divider, CY_INSTANCE_SHORT_NAME=Tri_Divider, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=Tri_Divider, )
module Counter_v3_0_2 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_47),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=3, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=4, CONTROL3=1, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=4095, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=4095, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Noise_Clk_Div, CY_INSTANCE_SHORT_NAME=Noise_Clk_Div, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=Noise_Clk_Div, )
module Counter_v3_0_3 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 3;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_47),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = Net_95;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=0, CompareMode=1, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=1, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, InitCounterValue=0, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=255, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=16, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UseInterrupt=true, VerilogSectionReplacementString=sC16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Counter_1, CY_INSTANCE_SHORT_NAME=Counter_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=Counter_1, )
module Counter_v3_0_4 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 0;
    parameter CompareMode = 1;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 16;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

    cy_psoc3_timer_v1_0 CounterHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_91),
        .kill(Net_82),
        .clock(clock),
        .tc(Net_48),
        .compare(Net_47),
        .interrupt(Net_42));

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_42;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_48;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));



endmodule

// Component: Triangle_Gen
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Triangle_Gen"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Triangle_Gen\Triangle_Gen.v"
`else
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Triangle_Gen"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Triangle_Gen\Triangle_Gen.v"
`endif

// Component: Linear_Counter
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Linear_Counter"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Linear_Counter\Linear_Counter.v"
`else
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Linear_Counter"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Linear_Counter\Linear_Counter.v"
`endif

// VDAC8_v1_90(Data_Source=1, Initial_Value=100, Strobe_Mode=1, VDAC_Range=4, VDAC_Speed=2, Voltage=1600, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=VDAC8_v1_90, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC8_Noise, CY_INSTANCE_SHORT_NAME=VDAC8_Noise, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=90, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=VDAC8_Noise, )
module VDAC8_v1_90_5 (
    strobe,
    data,
    vOut);
    input       strobe;
    input      [7:0] data;
    inout       vOut;
    electrical  vOut;

    parameter Data_Source = 1;
    parameter Initial_Value = 100;
    parameter Strobe_Mode = 1;

    electrical  Net_77;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;

    cy_psoc3_vidac8_v1_0 viDAC8 (
        .reset(Net_83),
        .idir(Net_81),
        .data(data[7:0]),
        .strobe(strobe),
        .vout(vOut),
        .iout(Net_77),
        .ioff(Net_82),
        .strobe_udb(strobe));
    defparam viDAC8.is_all_if_any = 0;
    defparam viDAC8.reg_data = 1;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_81));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_82));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_83));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_77));



endmodule

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: B_UART_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`endif

// UART_v2_50(Address1=0, Address2=0, BaudRate=31250, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, Enable_RX=1, Enable_RXIntInterrupt=1, Enable_TX=1, Enable_TXIntInterrupt=1, EnableHWAddress=0, EnIntRXInterrupt=true, EnIntTXInterrupt=true, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=false, InternalClock=true, InternalClockToleranceMinus=3.93736842105263, InternalClockTolerancePlus=3.93736842105263, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=true, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=250000, RXAddressMode=0, RXBufferSize=64, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=64, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=UART_v2_50, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MIDI1_UART, CY_INSTANCE_SHORT_NAME=MIDI1_UART, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=MIDI1_UART, )
module UART_v2_50_6 (
    cts_n,
    tx,
    rts_n,
    tx_en,
    clock,
    reset,
    rx,
    tx_interrupt,
    rx_interrupt,
    tx_data,
    tx_clk,
    rx_data,
    rx_clk);
    input       cts_n;
    output      tx;
    output      rts_n;
    output      tx_en;
    input       clock;
    input       reset;
    input       rx;
    output      tx_interrupt;
    output      rx_interrupt;
    output      tx_data;
    output      tx_clk;
    output      rx_data;
    output      rx_clk;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 1;
    parameter EnIntTXInterrupt = 1;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 0;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_isr_v1_0
		#(.int_type(2'b10))
		TXInternalInterrupt
		 (.int_signal(tx_interrupt));



	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("4000000000"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));



	cy_isr_v1_0
		#(.int_type(2'b10))
		RXInternalInterrupt
		 (.int_signal(rx_interrupt));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_50 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 0;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// USBFS_v3_10(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Audio">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="CDC">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Device">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor12">\r\n          <m_value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>6</iwManufacturer>\r\n            <iwProduct>7</iwProduct>\r\n            <sManufacturer>Cypress Semiconductor</sManufacturer>\r\n            <sProduct>USB MIDI</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>0</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>53810</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>2</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </m_value>\r\n          <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>6</iwManufacturer>\r\n            <iwProduct>7</iwProduct>\r\n            <sManufacturer>Cypress Semiconductor</sManufacturer>\r\n            <sProduct>USB MIDI</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>0</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>53810</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>1</iManufacturer>\r\n            <iProduct>2</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor17">\r\n              <m_value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>6</iwConfiguration>\r\n                <sConfiguration>Cypress Semiconductor</sConfiguration>\r\n                <wTotalLength>101</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>1</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>50</bMaxPower>\r\n              </m_value>\r\n              <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>6</iwConfiguration>\r\n                <sConfiguration>Cypress Semiconductor</sConfiguration>\r\n                <wTotalLength>101</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>1</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>50</bMaxPower>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="Interface21">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MIDI Interface Control</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MIDI Interface Control</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor22">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>8</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>0</bNumEndpoints>\r\n                        <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>MIDI Control Intf</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>8</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>0</bNumEndpoints>\r\n                        <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>MIDI Control Intf</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor24">\r\n                          <m_value d14p1:type="CyACHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>256</bcdADC>\r\n                            <wTotalLength>9</wTotalLength>\r\n                            <bInCollection>1</bInCollection>\r\n                            <baInterfaceNr>AQ==</baInterfaceNr>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyACHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>256</bcdADC>\r\n                            <wTotalLength>9</wTotalLength>\r\n                            <bInCollection>1</bInCollection>\r\n                            <baInterfaceNr>AQ==</baInterfaceNr>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="Interface25">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MIDI Interface Streaming</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>MIDI Interface Streaming</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor26">\r\n                      <m_value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>3</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>4</iInterface>\r\n                        <sInterface>MIDI Streaming Intf</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyAudioInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>1</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>3</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>4</iInterface>\r\n                        <sInterface>MIDI Streaming Intf</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor28">\r\n                          <m_value d14p1:type="CyMSHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>MS_HEADER</bDescriptorSubtype>\r\n                            <wTotalLength>37</wTotalLength>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyMSHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <bDescriptorSubtype>MS_HEADER</bDescriptorSubtype>\r\n                            <wTotalLength>37</wTotalLength>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor29">\r\n                          <m_value d14p1:type="CyMSInJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>6</bLength>\r\n                            <iwJack>10</iwJack>\r\n                            <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                            <bJackType>EMBEDDED</bJackType>\r\n                            <bJackID>1</bJackID>\r\n                            <iJack>5</iJack>\r\n                            <sJack>MIDI IN</sJack>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyMSInJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>6</bLength>\r\n                            <iwJack>10</iwJack>\r\n                            <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                            <bJackType>EMBEDDED</bJackType>\r\n                            <bJackID>1</bJackID>\r\n                            <iJack>5</iJack>\r\n                            <sJack>MIDI IN</sJack>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor30">\r\n                          <m_value d14p1:type="CyMSInJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>6</bLength>\r\n                            <iwJack>10</iwJack>\r\n                            <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                            <bJackType>EXTERNAL</bJackType>\r\n                            <bJackID>2</bJackID>\r\n                            <iJack>5</iJack>\r\n                            <sJack>MIDI IN</sJack>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyMSInJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>6</bLength>\r\n                            <iwJack>10</iwJack>\r\n                            <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                            <bJackType>EXTERNAL</bJackType>\r\n                            <bJackID>2</bJackID>\r\n                            <iJack>5</iJack>\r\n                            <sJack>MIDI IN</sJack>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor31">\r\n                          <m_value d14p1:type="CyMSOutJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwJack>11</iwJack>\r\n                            <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                            <bJackType>EMBEDDED</bJackType>\r\n                            <bJackID>3</bJackID>\r\n                            <bNrInputPins>1</bNrInputPins>\r\n                            <baSourceID>Ag==</baSourceID>\r\n                            <baSourcePin>AQ==</baSourcePin>\r\n                            <iJack>6</iJack>\r\n                            <sJack>MIDI OUT</sJack>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyMSOutJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwJack>11</iwJack>\r\n                            <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                            <bJackType>EMBEDDED</bJackType>\r\n                            <bJackID>3</bJackID>\r\n                            <bNrInputPins>1</bNrInputPins>\r\n                            <baSourceID>Ag==</baSourceID>\r\n                            <baSourcePin>AQ==</baSourcePin>\r\n                            <iJack>6</iJack>\r\n                            <sJack>MIDI OUT</sJack>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor32">\r\n                          <m_value d14p1:type="CyMSOutJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwJack>11</iwJack>\r\n                            <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                            <bJackType>EXTERNAL</bJackType>\r\n                            <bJackID>4</bJackID>\r\n                            <bNrInputPins>1</bNrInputPins>\r\n                            <baSourceID>AQ==</baSourceID>\r\n                            <baSourcePin>AQ==</baSourcePin>\r\n                            <iJack>6</iJack>\r\n                            <sJack>MIDI OUT</sJack>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyMSOutJackDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>AUDIO</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <iwJack>11</iwJack>\r\n                            <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                            <bJackType>EXTERNAL</bJackType>\r\n                            <bJackID>4</bJackID>\r\n                            <bNrInputPins>1</bNrInputPins>\r\n                            <baSourceID>AQ==</baSourceID>\r\n                            <baSourcePin>AQ==</baSourcePin>\r\n                            <iJack>6</iJack>\r\n                            <sJack>MIDI OUT</sJack>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor33">\r\n                          <m_value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>0</bInterval>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>32</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>0</bInterval>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>32</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes>\r\n                            <DescriptorNode Key="USBDescriptor34">\r\n                              <m_value d16p1:type="CyMSEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>5</bLength>\r\n                                <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                                <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                                <baAssocJackID>Aw==</baAssocJackID>\r\n                              </m_value>\r\n                              <Value d16p1:type="CyMSEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>5</bLength>\r\n                                <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                                <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                                <baAssocJackID>Aw==</baAssocJackID>\r\n                              </Value>\r\n                              <Nodes />\r\n                            </DescriptorNode>\r\n                          </Nodes>\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor35">\r\n                          <m_value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>0</bInterval>\r\n                            <bEndpointAddress>2</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>32</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyAudioEndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>9</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bInterval>0</bInterval>\r\n                            <bEndpointAddress>2</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>32</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes>\r\n                            <DescriptorNode Key="USBDescriptor36">\r\n                              <m_value d16p1:type="CyMSEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>5</bLength>\r\n                                <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                                <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                                <baAssocJackID>AQ==</baAssocJackID>\r\n                              </m_value>\r\n                              <Value d16p1:type="CyMSEndpointDescriptor" xmlns:d16p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                                <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                                <bLength>5</bLength>\r\n                                <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                                <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                                <baAssocJackID>AQ==</baAssocJackID>\r\n                              </Value>\r\n                              <Nodes />\r\n                            </DescriptorNode>\r\n                          </Nodes>\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DmaChannelPriority=3, DW_Hide_DmaAuto=true, DW_Hide_Usbv2Regs=true, DW_RegSize=8, DW_USB_CHGDET_CTRL=CR0, DW_USB_INTR_CAUSE_HI=CR0, DW_USB_INTR_CAUSE_LO=CR0, DW_USB_INTR_CAUSE_MED=CR0, DW_USB_INTR_LVL_SEL=CR0, DW_USB_INTR_SIE=CR0, DW_USB_INTR_SIE_MASK=CR0, DW_USB_LPM_CTRL=CR0, DW_USB_LPM_STAT=CR0, DW_USB_POWER_CTRL=CR0, EnableBatteryChargDetect=false, EnableCDCApi=true, EnableMidiApi=true, endpointMA=0, endpointMM=0, epDMAautoOptimization=false, extern_cls=false, extern_vbus=false, extern_vnd=false, extJackCount=0, Gen16bitEpAccessApi=true, HandleMscRequests=true, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="HIDReport">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, isrGroupArbiter=0, isrGroupBusReset=2, isrGroupEp0=1, isrGroupEp1=1, isrGroupEp2=1, isrGroupEp3=1, isrGroupEp4=1, isrGroupEp5=1, isrGroupEp6=1, isrGroupEp7=1, isrGroupEp8=1, isrGroupLpm=0, isrGroupSof=2, M0S8USBDSS_BLOCK_COUNT_1=0, max_interfaces_num=2, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Midi">\r\n      <Nodes>\r\n        <DescriptorNode Key="Interface21">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MIDI Interface Control</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MIDI Interface Control</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor22">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>8</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>0</bNumEndpoints>\r\n                <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>MIDI Control Intf</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>8</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>0</bNumEndpoints>\r\n                <bInterfaceSubClass>1</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>MIDI Control Intf</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor24">\r\n                  <m_value d10p1:type="CyACHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>256</bcdADC>\r\n                    <wTotalLength>9</wTotalLength>\r\n                    <bInCollection>1</bInCollection>\r\n                    <baInterfaceNr>AQ==</baInterfaceNr>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyACHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>256</bcdADC>\r\n                    <wTotalLength>9</wTotalLength>\r\n                    <bInCollection>1</bInCollection>\r\n                    <baInterfaceNr>AQ==</baInterfaceNr>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="Interface25">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MIDI Interface Streaming</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>MIDI Interface Streaming</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor26">\r\n              <m_value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>3</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>4</iInterface>\r\n                <sInterface>MIDI Streaming Intf</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyAudioInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>1</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>3</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>4</iInterface>\r\n                <sInterface>MIDI Streaming Intf</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor28">\r\n                  <m_value d10p1:type="CyMSHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>MS_HEADER</bDescriptorSubtype>\r\n                    <wTotalLength>37</wTotalLength>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyMSHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <bDescriptorSubtype>MS_HEADER</bDescriptorSubtype>\r\n                    <wTotalLength>37</wTotalLength>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor29">\r\n                  <m_value d10p1:type="CyMSInJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>6</bLength>\r\n                    <iwJack>10</iwJack>\r\n                    <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                    <bJackType>EMBEDDED</bJackType>\r\n                    <bJackID>1</bJackID>\r\n                    <iJack>5</iJack>\r\n                    <sJack>MIDI IN</sJack>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyMSInJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>6</bLength>\r\n                    <iwJack>10</iwJack>\r\n                    <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                    <bJackType>EMBEDDED</bJackType>\r\n                    <bJackID>1</bJackID>\r\n                    <iJack>5</iJack>\r\n                    <sJack>MIDI IN</sJack>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor30">\r\n                  <m_value d10p1:type="CyMSInJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>6</bLength>\r\n                    <iwJack>10</iwJack>\r\n                    <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                    <bJackType>EXTERNAL</bJackType>\r\n                    <bJackID>2</bJackID>\r\n                    <iJack>5</iJack>\r\n                    <sJack>MIDI IN</sJack>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyMSInJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>6</bLength>\r\n                    <iwJack>10</iwJack>\r\n                    <bDescriptorSubtype>MIDI_IN_JACK</bDescriptorSubtype>\r\n                    <bJackType>EXTERNAL</bJackType>\r\n                    <bJackID>2</bJackID>\r\n                    <iJack>5</iJack>\r\n                    <sJack>MIDI IN</sJack>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor31">\r\n                  <m_value d10p1:type="CyMSOutJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwJack>11</iwJack>\r\n                    <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                    <bJackType>EMBEDDED</bJackType>\r\n                    <bJackID>3</bJackID>\r\n                    <bNrInputPins>1</bNrInputPins>\r\n                    <baSourceID>Ag==</baSourceID>\r\n                    <baSourcePin>AQ==</baSourcePin>\r\n                    <iJack>6</iJack>\r\n                    <sJack>MIDI OUT</sJack>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyMSOutJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwJack>11</iwJack>\r\n                    <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                    <bJackType>EMBEDDED</bJackType>\r\n                    <bJackID>3</bJackID>\r\n                    <bNrInputPins>1</bNrInputPins>\r\n                    <baSourceID>Ag==</baSourceID>\r\n                    <baSourcePin>AQ==</baSourcePin>\r\n                    <iJack>6</iJack>\r\n                    <sJack>MIDI OUT</sJack>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor32">\r\n                  <m_value d10p1:type="CyMSOutJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwJack>11</iwJack>\r\n                    <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                    <bJackType>EXTERNAL</bJackType>\r\n                    <bJackID>4</bJackID>\r\n                    <bNrInputPins>1</bNrInputPins>\r\n                    <baSourceID>AQ==</baSourceID>\r\n                    <baSourcePin>AQ==</baSourcePin>\r\n                    <iJack>6</iJack>\r\n                    <sJack>MIDI OUT</sJack>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyMSOutJackDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>AUDIO</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <iwJack>11</iwJack>\r\n                    <bDescriptorSubtype>MIDI_OUT_JACK</bDescriptorSubtype>\r\n                    <bJackType>EXTERNAL</bJackType>\r\n                    <bJackID>4</bJackID>\r\n                    <bNrInputPins>1</bNrInputPins>\r\n                    <baSourceID>AQ==</baSourceID>\r\n                    <baSourcePin>AQ==</baSourcePin>\r\n                    <iJack>6</iJack>\r\n                    <sJack>MIDI OUT</sJack>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor33">\r\n                  <m_value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>0</bInterval>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>32</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>0</bInterval>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>32</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor34">\r\n                      <m_value d12p1:type="CyMSEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>5</bLength>\r\n                        <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                        <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                        <baAssocJackID>Aw==</baAssocJackID>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyMSEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>5</bLength>\r\n                        <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                        <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                        <baAssocJackID>Aw==</baAssocJackID>\r\n                      </Value>\r\n                      <Nodes />\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor35">\r\n                  <m_value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>0</bInterval>\r\n                    <bEndpointAddress>2</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>32</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyAudioEndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>9</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bInterval>0</bInterval>\r\n                    <bEndpointAddress>2</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>32</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor36">\r\n                      <m_value d12p1:type="CyMSEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>5</bLength>\r\n                        <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                        <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                        <baAssocJackID>AQ==</baAssocJackID>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyMSEndpointDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>CS_ENDPOINT</bDescriptorType>\r\n                        <bLength>5</bLength>\r\n                        <bDescriptorSubtype>MS_GENERAL</bDescriptorSubtype>\r\n                        <bNumEmbMIDIJack>1</bNumEmbMIDIJack>\r\n                        <baAssocJackID>AQ==</baAssocJackID>\r\n                      </Value>\r\n                      <Nodes />\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, Mode=false, mon_vbus=false, MscDescriptors=, MscLogicalUnitsNum=1, out_sof=false, Pid=F232, powerpad_vbus=false, PRIMITIVE_INSTANCE=USB, ProdactName=, ProdactRevision=, REG_SIZE=reg8, RemoveDmaAutoOpt=true, RemoveVbusPin=true, rm_arb_int=false, rm_dma_1=true, rm_dma_2=true, rm_dma_3=true, rm_dma_4=true, rm_dma_5=true, rm_dma_6=true, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=false, rm_ep_isr_2=false, rm_ep_isr_3=true, rm_ep_isr_4=true, rm_ep_isr_5=true, rm_ep_isr_6=true, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_lpm_int=true, rm_ord_int=true, rm_sof_int=false, rm_usb_int=false, SofTermEnable=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_0">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="String">\r\n      <Nodes>\r\n        <DescriptorNode Key="LANGID">\r\n          <m_value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </m_value>\r\n          <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor6">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor7">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USB MIDI</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USB MIDI</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor8">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>36</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI Control Intf</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>36</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI Control Intf</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor9">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>40</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI Streaming Intf</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>40</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI Streaming Intf</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor10">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI IN</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI IN</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor11">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI OUT</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MIDI OUT</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n    <DescriptorNode Key="SpecialString">\r\n      <Nodes>\r\n        <DescriptorNode Key="Serial">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="EE">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, UINT_TYPE=uint8, VbusDetectTermEnable=false, VendorName=, Vid=04B4, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=USBFS_v3_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=USBMIDI_1, CY_INSTANCE_SHORT_NAME=USBMIDI_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=USBMIDI_1, )
module USBFS_v3_10_7 (
    sof,
    vbusdet);
    output      sof;
    input       vbusdet;

    parameter epDMAautoOptimization = 0;

          wire  Net_1914;
          wire  Net_1915;
          wire  Net_1916;
          wire  Net_1917;
          wire  Net_1918;
          wire  Net_1919;
          wire [7:0] dma_request;
          wire  Net_1920;
          wire  Net_1921;
          wire  Net_1922;
          wire [7:0] Net_2039;
          wire  Net_2038;
          wire  Net_2037;
          wire  EPs_1_to_7_dma_complete;
          wire  Net_2036;
          wire  Net_2035;
          wire  Net_2034;
          wire  Net_2033;
          wire  Net_2032;
          wire  Net_2031;
          wire  Net_2030;
          wire  Net_2029;
          wire  Net_2028;
          wire  Net_2027;
          wire  Net_2026;
          wire  Net_2025;
          wire  Net_2024;
          wire [7:0] Net_1940;
          wire  Net_1939;
          wire  Net_1938;
          wire  Net_1937;
          wire  Net_1936;
          wire  Net_1935;
          wire  Net_1934;
          wire  Net_1933;
          wire  Net_1932;
          wire  Net_2047;
          wire  Net_1202;
          wire  dma_terminate;
          wire [7:0] Net_2040;
          wire  Net_1010;
    electrical  Net_1000;
    electrical  Net_597;
          wire  Net_1495;
          wire  Net_1498;
          wire  Net_1559;
          wire  Net_1567;
          wire  Net_1576;
          wire  Net_1579;
          wire  Net_1591;
          wire [7:0] dma_complete;
          wire  Net_1588;
          wire  Net_1876;
          wire [8:0] ep_int;
          wire  Net_1889;
          wire  busClk;
          wire  Net_95;


	cy_isr_v1_0
		#(.int_type(2'b10))
		dp_int
		 (.int_signal(Net_1010));


	wire [0:0] tmpOE__Dm_net;
	wire [0:0] tmpFB_0__Dm_net;
	wire [0:0] tmpIO_0__Dm_net;
	wire [0:0] tmpINTERRUPT_0__Dm_net;
	electrical [0:0] tmpSIOVREF__Dm_net;

	cy_psoc3_pins_v1_10
		#(.id("0d776c25-0fda-4bff-af2b-9962432af301/8b77a6c4-10a0-4390-971c-672353e2a49c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dm
		 (.oe(tmpOE__Dm_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dm_net[0:0]}),
		  .analog({Net_597}),
		  .io({tmpIO_0__Dm_net[0:0]}),
		  .siovref(tmpSIOVREF__Dm_net),
		  .interrupt({tmpINTERRUPT_0__Dm_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dm_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dp_net;
	wire [0:0] tmpFB_0__Dp_net;
	wire [0:0] tmpIO_0__Dp_net;
	electrical [0:0] tmpSIOVREF__Dp_net;

	cy_psoc3_pins_v1_10
		#(.id("0d776c25-0fda-4bff-af2b-9962432af301/618a72fc-5ddd-4df5-958f-a3d55102db42"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dp
		 (.oe(tmpOE__Dp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dp_net[0:0]}),
		  .analog({Net_1000}),
		  .io({tmpIO_0__Dp_net[0:0]}),
		  .siovref(tmpSIOVREF__Dp_net),
		  .interrupt({Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_psoc3_usb_v1_0 USB (
        .dp(Net_1000),
        .dm(Net_597),
        .sof_int(sof),
        .arb_int(Net_1889),
        .usb_int(Net_1876),
        .ept_int(ep_int[8:0]),
        .ord_int(Net_95),
        .dma_req(dma_request[7:0]),
        .dma_termin(dma_terminate));


	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_2
		 (.int_signal(ep_int[2]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_1
		 (.int_signal(ep_int[1]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_0
		 (.int_signal(ep_int[0]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		bus_reset
		 (.int_signal(Net_1876));



	cy_isr_v1_0
		#(.int_type(2'b10))
		arb_int
		 (.int_signal(Net_1889));



	cy_isr_v1_0
		#(.int_type(2'b10))
		sof_int
		 (.int_signal(sof));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign dma_complete[0] = Net_1922;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1922));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign dma_complete[1] = Net_1921;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1921));

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign dma_complete[2] = Net_1920;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1920));

	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign dma_complete[3] = Net_1919;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_1919));

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign dma_complete[4] = Net_1918;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign dma_complete[5] = Net_1917;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_1918));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_1917));

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign dma_complete[6] = Net_1916;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign dma_complete[7] = Net_1915;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1916));

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_1915));



endmodule

// Component: Sampler
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Sampler"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Sampler\Sampler.v"
`else
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Sampler"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\Sampler\Sampler.v"
`endif

// Component: clock_divider
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\clock_divider"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\clock_divider\clock_divider.v"
`else
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\clock_divider"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\clock_divider\clock_divider.v"
`endif

// Component: component01
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\component01"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\component01\component01.v"
`else
`define CY_BLK_DIR "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\component01"
`include "C:\Users\214016586\Documents\GitHub\PSoC_2A03APU\APU2A03\APU2A03.cydsn\component01\component01.v"
`endif

// Component: CyStatusReg_v1_90
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`endif

// Component: BShiftReg_v2_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\BShiftReg_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\BShiftReg_v2_30\BShiftReg_v2_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\BShiftReg_v2_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\BShiftReg_v2_30\BShiftReg_v2_30.v"
`endif

// ShiftReg_v2_30(ControlRegUsageReplacemetString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DefSi=0, Direction=1, FifoSize=4, InterruptSource=0, Length=16, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, UseInputFifo=false, UseInterrupt=false, UseOutputFifo=false, UseShiftIn=false, UseShiftOut=true, VerilogSectionReplacementString=sC16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ShiftReg_v2_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=rectangle_generator, CY_INSTANCE_SHORT_NAME=rectangle_generator, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=rectangle_generator, )
module ShiftReg_v2_30_8 (
    shift_in,
    load,
    store,
    clock,
    reset,
    shift_out,
    interrupt);
    input       shift_in;
    input       load;
    input       store;
    input       clock;
    input       reset;
    output      shift_out;
    output      interrupt;

    parameter Direction = 1;
    parameter FifoSize = 4;
    parameter Length = 16;

          wire  Net_2;
          wire  Net_1;
          wire  Net_350;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_350 = Net_1;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1));

    OneTerminal OneTerminal_1 (
        .o(Net_2));

    BShiftReg_v2_30 bSR (
        .shiftIn(Net_350),
        .load(load),
        .shiftOut(shift_out),
        .store(store),
        .clock(clock),
        .reset(reset),
        .interrupt(interrupt));
    defparam bSR.DefSi = 0;
    defparam bSR.Direction = 1;
    defparam bSR.FifoSize = 4;
    defparam bSR.InterruptSource = 0;
    defparam bSR.Length = 16;
    defparam bSR.UseInputFifo = 0;
    defparam bSR.UseInterrupt = 0;
    defparam bSR.UseOutputFifo = 0;



endmodule

// top
module top ;

          wire  Net_528;
          wire  Net_524;
          wire  Net_523;
          wire  Net_522;
          wire  Net_583;
          wire  Net_582;
          wire  Net_581;
          wire  Net_580;
          wire  Net_579;
          wire  Net_577;
          wire  Net_576;
          wire  Net_575;
          wire  Net_574;
          wire  Net_607;
          wire  Net_606;
          wire  Net_605;
          wire  Net_604;
          wire  Net_603;
          wire  Net_602;
          wire  Net_601;
          wire  Length_Clk;
          wire  Net_600;
          wire  Net_599;
          wire  Net_598;
          wire  Net_472;
          wire  Net_471;
          wire  Net_470;
          wire  Net_469;
          wire  Net_468;
          wire  Net_467;
          wire  Net_466;
          wire  Net_465;
          wire  Net_464;
          wire [6:0] oData;
          wire  Net_463;
          wire  Net_461;
          wire  Net_460;
          wire  Net_459;
          wire  Net_458;
          wire  Net_457;
          wire  Net_456;
          wire  Net_455;
          wire  DAC_Clock;
          wire  Net_454;
          wire  Net_453;
          wire  Net_452;
          wire [6:0] Net_428;
          wire  Clock179;
          wire  Net_427;
          wire  Net_425;
          wire  Net_424;
          wire  Net_369;
          wire [11:0] period;
          wire  Net_368;
          wire  Net_367;
          wire  Net_366;
          wire  Net_365;
          wire  Net_364;
          wire  Net_363;
          wire  Net_362;
          wire [6:0] duration;
          wire  Net_361;
          wire  Net_360;
          wire  Net_359;
          wire  Net_358;
          wire  Net_357;
          wire [7:0] Tri_aud;
          wire  Net_356;
          wire  Net_355;
          wire  Length_sweep_clk;
          wire  Net_354;
          wire  Net_331;
          wire  Net_330;
          wire [3:0] Tri_Data;
          wire  Net_391;
          wire [6:0] Net_390;
          wire  Net_389;
          wire  Net_387;
          wire [6:0] Net_177;
          wire  Net_206;
          wire [7:0] audio_out;
          wire  Net_174;
          wire  Net_445;
          wire  Net_444;
          wire  Net_443;
          wire  Net_442;
          wire  Net_441;
          wire  Net_440;
          wire  Net_439;
          wire  Net_437;
          wire  Net_314;
          wire  Net_239;
          wire  Net_238;
          wire  Net_237;
          wire  Net_236;
          wire  Net_235;
          wire  Net_234;
          wire  Net_233;
          wire  Net_232;
          wire  Net_274;
          wire  Net_273;
          wire  Net_272;
          wire  Net_271;
          wire  Net_270;
          wire  Net_269;
          wire  Net_268;
          wire  Net_266;
          wire  Net_168;
          wire  Net_207;
          wire  Net_164;
          wire [11:0] period_shift;
          wire  Net_284;
          wire  Net_283;
          wire  Net_282;
          wire  Net_281;
          wire  Net_280;
          wire  Net_279;
          wire  Net_277;
          wire  Net_39;
          wire  Net_19;
          wire  Net_18;
          wire  Net_17;
          wire  Net_16;
          wire  Net_15;
          wire  Net_14;
          wire  Net_202;
          wire  Net_612;
          wire [2:0] Net_571;
          wire  Net_526;
          wire  Net_529;
          wire  Net_525;
          wire  Net_393;
          wire  Net_436;
          wire  Net_430;
          wire  Net_431;
          wire  Net_449;
          wire  Net_433;
          wire  Net_386;
          wire  Net_342;
          wire  Net_261;
          wire  Net_275;
          wire  Net_287;
          wire  Net_264;
          wire  Net_329;
          wire  Net_262;
    electrical  Net_315;
          wire  Net_301;
          wire  Net_304;
          wire  Net_303;
          wire  Net_205;
          wire  Net_243;
          wire  Net_230;
          wire  Net_1;
          wire  Net_11;
          wire  Net_107;
          wire  Net_10;
          wire  Net_62;
          wire  Net_4;

    PRS_v2_40 LFSR (
        .enable(Net_1),
        .clock(Clock179),
        .bitstream(Net_62),
        .reset(Net_4));
    defparam LFSR.Resolution = 14;
    defparam LFSR.RunMode = 0;
    defparam LFSR.TimeMultiplexing = 0;
    defparam LFSR.WakeupBehaviour = 1;

    Counter_v3_0_0 Length_Counter (
        .reset(Net_10),
        .tc(Net_11),
        .comp(Net_202),
        .clock(Clock179),
        .interrupt(Net_14),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Length_Clk));
    defparam Length_Counter.CaptureMode = 0;
    defparam Length_Counter.ClockMode = 3;
    defparam Length_Counter.CompareMode = 3;
    defparam Length_Counter.CompareStatusEdgeSense = 1;
    defparam Length_Counter.EnableMode = 0;
    defparam Length_Counter.ReloadOnCapture = 0;
    defparam Length_Counter.ReloadOnCompare = 0;
    defparam Length_Counter.ReloadOnOverUnder = 1;
    defparam Length_Counter.ReloadOnReset = 1;
    defparam Length_Counter.Resolution = 8;
    defparam Length_Counter.RunMode = 1;
    defparam Length_Counter.UseInterrupt = 1;


	cy_clock_v1_0
		#(.id("9bcb1815-6cc0-4beb-9199-515306aecc87"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("558659217.877095"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_179
		 (.clock_out(Clock179));


	wire [0:0] tmpOE__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	wire [0:0] tmpINTERRUPT_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_1
		 (.oe(tmpOE__Pin_1_net),
		  .y({1'b0}),
		  .fb({Length_Clk}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net),
		  .interrupt({tmpINTERRUPT_0__Pin_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Counter_v3_0_1 Length_Counter_1 (
        .reset(Net_275),
        .tc(Net_304),
        .comp(Net_277),
        .clock(Clock179),
        .interrupt(Net_279),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(Length_Clk));
    defparam Length_Counter_1.CaptureMode = 0;
    defparam Length_Counter_1.ClockMode = 3;
    defparam Length_Counter_1.CompareMode = 3;
    defparam Length_Counter_1.CompareStatusEdgeSense = 1;
    defparam Length_Counter_1.EnableMode = 0;
    defparam Length_Counter_1.ReloadOnCapture = 0;
    defparam Length_Counter_1.ReloadOnCompare = 0;
    defparam Length_Counter_1.ReloadOnOverUnder = 1;
    defparam Length_Counter_1.ReloadOnReset = 1;
    defparam Length_Counter_1.Resolution = 8;
    defparam Length_Counter_1.RunMode = 1;
    defparam Length_Counter_1.UseInterrupt = 1;

    Count7_v1_0 volume_generator (
        .en(Net_243),
        .load(1'b0),
        .clock(Clock179),
        .reset(1'b0),
        .cnt(oData[6:0]),
        .tc(Net_168));
    defparam volume_generator.EnableSignal = 1;
    defparam volume_generator.LoadSignal = 0;

    assign Net_230 = 1'h0;

    Counter_v3_0_2 Tri_Divider (
        .reset(Net_264),
        .tc(Net_262),
        .comp(Net_266),
        .clock(Clock179),
        .interrupt(Net_268),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Tri_Divider.CaptureMode = 0;
    defparam Tri_Divider.ClockMode = 0;
    defparam Tri_Divider.CompareMode = 1;
    defparam Tri_Divider.CompareStatusEdgeSense = 1;
    defparam Tri_Divider.EnableMode = 0;
    defparam Tri_Divider.ReloadOnCapture = 0;
    defparam Tri_Divider.ReloadOnCompare = 0;
    defparam Tri_Divider.ReloadOnOverUnder = 1;
    defparam Tri_Divider.ReloadOnReset = 1;
    defparam Tri_Divider.Resolution = 16;
    defparam Tri_Divider.RunMode = 0;
    defparam Tri_Divider.UseInterrupt = 1;

    assign Net_4 = 1'h0;

    Counter_v3_0_3 Noise_Clk_Div (
        .reset(Net_230),
        .tc(Net_1),
        .comp(Net_232),
        .clock(Clock179),
        .interrupt(Net_233),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Noise_Clk_Div.CaptureMode = 0;
    defparam Noise_Clk_Div.ClockMode = 3;
    defparam Noise_Clk_Div.CompareMode = 1;
    defparam Noise_Clk_Div.CompareStatusEdgeSense = 1;
    defparam Noise_Clk_Div.EnableMode = 0;
    defparam Noise_Clk_Div.ReloadOnCapture = 0;
    defparam Noise_Clk_Div.ReloadOnCompare = 0;
    defparam Noise_Clk_Div.ReloadOnOverUnder = 1;
    defparam Noise_Clk_Div.ReloadOnReset = 1;
    defparam Noise_Clk_Div.Resolution = 16;
    defparam Noise_Clk_Div.RunMode = 0;
    defparam Noise_Clk_Div.UseInterrupt = 1;


    assign Net_107 = Net_62 & Net_11;

    assign Net_10 = 1'h0;


    assign Tri_aud[7] = Tri_Data[3] & Net_301;


    assign audio_out[7] = oData[3] & Net_107;


    assign audio_out[6] = oData[2] & Net_107;


    assign audio_out[5] = oData[1] & Net_107;


    assign audio_out[4] = oData[0] & Net_107;


    assign Tri_aud[6] = Tri_Data[2] & Net_301;


    assign Tri_aud[5] = Tri_Data[1] & Net_301;


    assign Tri_aud[4] = Tri_Data[0] & Net_301;


    assign Net_301 = Net_303 & Net_304;

    assign audio_out[3:0] = 4'h0;


	cy_clock_v1_0
		#(.id("481ab755-0a35-44b0-9e5a-7b8c044e43f2"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("4000000000"),
		  .is_direct(0),
		  .is_digital(1))
		DAC_Clk
		 (.clock_out(DAC_Clock));


	wire [0:0] tmpOE__Noise_Out_net;
	wire [0:0] tmpFB_0__Noise_Out_net;
	wire [0:0] tmpIO_0__Noise_Out_net;
	wire [0:0] tmpINTERRUPT_0__Noise_Out_net;
	electrical [0:0] tmpSIOVREF__Noise_Out_net;

	cy_psoc3_pins_v1_10
		#(.id("77715107-f8d5-47e5-a629-0fb83101ac6b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Noise_Out
		 (.oe(tmpOE__Noise_Out_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Noise_Out_net[0:0]}),
		  .analog({Net_315}),
		  .io({tmpIO_0__Noise_Out_net[0:0]}),
		  .siovref(tmpSIOVREF__Noise_Out_net),
		  .interrupt({tmpINTERRUPT_0__Noise_Out_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Noise_Out_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Counter_v3_0_4 Counter_1 (
        .reset(Net_436),
        .tc(Net_386),
        .comp(Net_437),
        .clock(Clock179),
        .interrupt(Net_439),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(1'b1),
        .count(1'b0));
    defparam Counter_1.CaptureMode = 0;
    defparam Counter_1.ClockMode = 0;
    defparam Counter_1.CompareMode = 1;
    defparam Counter_1.CompareStatusEdgeSense = 1;
    defparam Counter_1.EnableMode = 0;
    defparam Counter_1.ReloadOnCapture = 0;
    defparam Counter_1.ReloadOnCompare = 0;
    defparam Counter_1.ReloadOnOverUnder = 1;
    defparam Counter_1.ReloadOnReset = 1;
    defparam Counter_1.Resolution = 16;
    defparam Counter_1.RunMode = 0;
    defparam Counter_1.UseInterrupt = 1;

	wire [0:0] tmpOE__Pin_6_net;
	wire [0:0] tmpIO_0__Pin_6_net;
	wire [0:0] tmpINTERRUPT_0__Pin_6_net;
	electrical [0:0] tmpSIOVREF__Pin_6_net;

	cy_psoc3_pins_v1_10
		#(.id("fdb3550c-04c2-49b3-aa69-6fce14562892"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_6
		 (.oe(tmpOE__Pin_6_net),
		  .y({1'b0}),
		  .fb({Net_205}),
		  .io({tmpIO_0__Pin_6_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_6_net),
		  .interrupt({tmpINTERRUPT_0__Pin_6_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_6_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    Count7_v1_0 Noise_Vol_Clk_Div (
        .en(Net_205),
        .load(1'b0),
        .clock(Clock179),
        .reset(1'b0),
        .cnt(Net_177[6:0]),
        .tc(Net_243));
    defparam Noise_Vol_Clk_Div.EnableSignal = 1;
    defparam Noise_Vol_Clk_Div.LoadSignal = 0;

    Triangle_Gen Triangle_Gen_1 (
        .iClk(Clock179),
        .iReset(Net_261),
        .iEnable(Net_262),
        .oData(Tri_Data[3:0]));

    Linear_Counter Linear_Counter_1 (
        .iClk(Clock179),
        .iReset(Net_287),
        .iControl_flag(Net_329),
        .iDuration(duration[6:0]),
        .oData(Net_303),
        .iEnable(Net_342));

    VDAC8_v1_90_5 VDAC8_Noise (
        .strobe(DAC_Clock),
        .data(audio_out[7:0]),
        .vOut(Net_315));
    defparam VDAC8_Noise.Data_Source = 1;
    defparam VDAC8_Noise.Initial_Value = 100;
    defparam VDAC8_Noise.Strobe_Mode = 1;

    Count7_v1_0 Count7_1 (
        .en(Net_386),
        .load(1'b0),
        .clock(Clock179),
        .reset(1'b0),
        .cnt(Net_390[6:0]),
        .tc(Net_391));
    defparam Count7_1.EnableSignal = 1;
    defparam Count7_1.LoadSignal = 0;

    CyControlReg_v1_80 Control_Reg_1 (
        .control_1(duration[1]),
        .control_2(duration[2]),
        .control_3(duration[3]),
        .control_0(duration[0]),
        .control_4(duration[4]),
        .control_5(duration[5]),
        .control_6(duration[6]),
        .control_7(Net_329),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_1.Bit0Mode = 0;
    defparam Control_Reg_1.Bit1Mode = 0;
    defparam Control_Reg_1.Bit2Mode = 0;
    defparam Control_Reg_1.Bit3Mode = 0;
    defparam Control_Reg_1.Bit4Mode = 0;
    defparam Control_Reg_1.Bit5Mode = 0;
    defparam Control_Reg_1.Bit6Mode = 0;
    defparam Control_Reg_1.Bit7Mode = 0;
    defparam Control_Reg_1.BitValue = 0;
    defparam Control_Reg_1.BusDisplay = 0;
    defparam Control_Reg_1.ExtrReset = 0;
    defparam Control_Reg_1.NumOutputs = 8;

    assign Tri_aud[3:0] = 4'h0;

    assign Net_264 = 1'h0;

    assign Net_261 = 1'h0;

    assign Net_287 = 1'h0;

    assign Net_275 = 1'h0;

    assign Net_342 = 1'h1;

    UART_v2_50_6 MIDI1_UART (
        .cts_n(1'b0),
        .tx(Net_355),
        .rts_n(Net_356),
        .tx_en(Net_357),
        .clock(1'b0),
        .reset(1'b0),
        .rx(Net_360),
        .tx_interrupt(Net_361),
        .rx_interrupt(Net_362),
        .tx_data(Net_363),
        .tx_clk(Net_364),
        .rx_data(Net_365),
        .rx_clk(Net_366));
    defparam MIDI1_UART.Address1 = 0;
    defparam MIDI1_UART.Address2 = 0;
    defparam MIDI1_UART.EnIntRXInterrupt = 1;
    defparam MIDI1_UART.EnIntTXInterrupt = 1;
    defparam MIDI1_UART.FlowControl = 0;
    defparam MIDI1_UART.HalfDuplexEn = 0;
    defparam MIDI1_UART.HwTXEnSignal = 0;
    defparam MIDI1_UART.NumDataBits = 8;
    defparam MIDI1_UART.NumStopBits = 1;
    defparam MIDI1_UART.ParityType = 0;
    defparam MIDI1_UART.RXEnable = 1;
    defparam MIDI1_UART.TXEnable = 1;

	wire [0:0] tmpOE__MIDI_IN1_net;
	wire [0:0] tmpIO_0__MIDI_IN1_net;
	wire [0:0] tmpINTERRUPT_0__MIDI_IN1_net;
	electrical [0:0] tmpSIOVREF__MIDI_IN1_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MIDI_IN1
		 (.oe(tmpOE__MIDI_IN1_net),
		  .y({1'b0}),
		  .fb({Net_360}),
		  .io({tmpIO_0__MIDI_IN1_net[0:0]}),
		  .siovref(tmpSIOVREF__MIDI_IN1_net),
		  .interrupt({tmpINTERRUPT_0__MIDI_IN1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MIDI_IN1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MIDI_OUT1_net;
	wire [0:0] tmpFB_0__MIDI_OUT1_net;
	wire [0:0] tmpIO_0__MIDI_OUT1_net;
	wire [0:0] tmpINTERRUPT_0__MIDI_OUT1_net;
	electrical [0:0] tmpSIOVREF__MIDI_OUT1_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MIDI_OUT1
		 (.oe(tmpOE__MIDI_OUT1_net),
		  .y({Net_367}),
		  .fb({tmpFB_0__MIDI_OUT1_net[0:0]}),
		  .io({tmpIO_0__MIDI_OUT1_net[0:0]}),
		  .siovref(tmpSIOVREF__MIDI_OUT1_net),
		  .interrupt({tmpINTERRUPT_0__MIDI_OUT1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MIDI_OUT1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_367 = ~Net_355;

    USBFS_v3_10_7 USBMIDI_1 (
        .sof(Net_368),
        .vbusdet(1'b0));
    defparam USBMIDI_1.epDMAautoOptimization = 0;

    assign Net_612 = 1'h1;

    Sampler Sampler_length_sweep (
        .iClk(Clock179),
        .oSignal(Length_sweep_clk),
        .iSignal(Net_393));


    assign Net_525 = Clock179 & Net_433;

    clock_divider clock_divider_2 (
        .iReset(Net_430),
        .iEnable(Net_431),
        .iDivider(period[10:0]),
        .oClk(Net_433),
        .iClk(Clock179));

    Count7_v1_0 Count7_2 (
        .en(1'b1),
        .load(1'b0),
        .clock(Clock179),
        .reset(1'b0),
        .cnt(Net_428[6:0]),
        .tc(Net_449));
    defparam Count7_2.EnableSignal = 0;
    defparam Count7_2.LoadSignal = 0;

    CyControlReg_v1_80 Control_Reg_2 (
        .control_1(Net_452),
        .control_2(Net_453),
        .control_3(Net_454),
        .control_0(Net_455),
        .control_4(Net_456),
        .control_5(Net_457),
        .control_6(Net_458),
        .control_7(Net_459),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(period[7:0]));
    defparam Control_Reg_2.Bit0Mode = 0;
    defparam Control_Reg_2.Bit1Mode = 0;
    defparam Control_Reg_2.Bit2Mode = 0;
    defparam Control_Reg_2.Bit3Mode = 0;
    defparam Control_Reg_2.Bit4Mode = 0;
    defparam Control_Reg_2.Bit5Mode = 0;
    defparam Control_Reg_2.Bit6Mode = 0;
    defparam Control_Reg_2.Bit7Mode = 0;
    defparam Control_Reg_2.BitValue = 0;
    defparam Control_Reg_2.BusDisplay = 1;
    defparam Control_Reg_2.ExtrReset = 0;
    defparam Control_Reg_2.NumOutputs = 8;

    CyControlReg_v1_80 Control_Reg_3 (
        .control_1(Net_463),
        .control_2(Net_464),
        .control_3(Net_465),
        .control_0(Net_466),
        .control_4(Net_467),
        .control_5(Net_468),
        .control_6(Net_469),
        .control_7(Net_470),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(period[10:8]));
    defparam Control_Reg_3.Bit0Mode = 0;
    defparam Control_Reg_3.Bit1Mode = 0;
    defparam Control_Reg_3.Bit2Mode = 0;
    defparam Control_Reg_3.Bit3Mode = 0;
    defparam Control_Reg_3.Bit4Mode = 0;
    defparam Control_Reg_3.Bit5Mode = 0;
    defparam Control_Reg_3.Bit6Mode = 0;
    defparam Control_Reg_3.Bit7Mode = 0;
    defparam Control_Reg_3.BitValue = 0;
    defparam Control_Reg_3.BusDisplay = 1;
    defparam Control_Reg_3.ExtrReset = 0;
    defparam Control_Reg_3.NumOutputs = 3;

    assign Net_431 = 1'h1;

    assign Net_430 = 1'h0;

	wire [0:0] tmpOE__Pin_3_net;
	wire [0:0] tmpFB_0__Pin_3_net;
	wire [0:0] tmpIO_0__Pin_3_net;
	wire [0:0] tmpINTERRUPT_0__Pin_3_net;
	electrical [0:0] tmpSIOVREF__Pin_3_net;

	cy_psoc3_pins_v1_10
		#(.id("3d933fdb-027f-4b11-b406-8fc17f87275d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_3
		 (.oe(tmpOE__Pin_3_net),
		  .y({Net_449}),
		  .fb({tmpFB_0__Pin_3_net[0:0]}),
		  .io({tmpIO_0__Pin_3_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_3_net),
		  .interrupt({tmpINTERRUPT_0__Pin_3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    CyControlReg_v1_80 Control_Reg_4 (
        .control_1(Net_598),
        .control_2(Net_599),
        .control_3(Net_600),
        .control_0(Net_601),
        .control_4(Net_602),
        .control_5(Net_603),
        .control_6(Net_604),
        .control_7(Net_605),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(Net_571[2:0]));
    defparam Control_Reg_4.Bit0Mode = 0;
    defparam Control_Reg_4.Bit1Mode = 0;
    defparam Control_Reg_4.Bit2Mode = 0;
    defparam Control_Reg_4.Bit3Mode = 0;
    defparam Control_Reg_4.Bit4Mode = 0;
    defparam Control_Reg_4.Bit5Mode = 0;
    defparam Control_Reg_4.Bit6Mode = 0;
    defparam Control_Reg_4.Bit7Mode = 0;
    defparam Control_Reg_4.BitValue = 0;
    defparam Control_Reg_4.BusDisplay = 1;
    defparam Control_Reg_4.ExtrReset = 0;
    defparam Control_Reg_4.NumOutputs = 3;

	wire [0:0] tmpOE__Pin_2_net;
	wire [0:0] tmpFB_0__Pin_2_net;
	wire [0:0] tmpIO_0__Pin_2_net;
	wire [0:0] tmpINTERRUPT_0__Pin_2_net;
	electrical [0:0] tmpSIOVREF__Pin_2_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Pin_2
		 (.oe(tmpOE__Pin_2_net),
		  .y({Net_529}),
		  .fb({tmpFB_0__Pin_2_net[0:0]}),
		  .io({tmpIO_0__Pin_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_2_net),
		  .interrupt({tmpINTERRUPT_0__Pin_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_436 = 1'h0;

    assign Net_393 = 1'h0;

    assign period[11] = 1'h0;

    component01 component01_1 (
        .iPeriod(period[11:0]),
        .iSweep_shift(Net_571[2:0]),
        .oPeriod_shift(period_shift[11:0]),
        .iEnable(Net_612));

    CyStatusReg_v1_90 Status_Reg_1 (
        .status_0(1'b0),
        .status_1(1'b0),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Clock179),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_583),
        .status_bus(period_shift[7:0]));
    defparam Status_Reg_1.Bit0Mode = 0;
    defparam Status_Reg_1.Bit1Mode = 0;
    defparam Status_Reg_1.Bit2Mode = 0;
    defparam Status_Reg_1.Bit3Mode = 0;
    defparam Status_Reg_1.Bit4Mode = 0;
    defparam Status_Reg_1.Bit5Mode = 0;
    defparam Status_Reg_1.Bit6Mode = 0;
    defparam Status_Reg_1.Bit7Mode = 0;
    defparam Status_Reg_1.BusDisplay = 1;
    defparam Status_Reg_1.Interrupt = 0;
    defparam Status_Reg_1.MaskValue = 0;
    defparam Status_Reg_1.NumInputs = 8;

    ShiftReg_v2_30_8 rectangle_generator (
        .shift_in(1'b0),
        .load(1'b0),
        .store(1'b0),
        .clock(Net_525),
        .reset(Net_526),
        .shift_out(Net_529),
        .interrupt(Net_528));
    defparam rectangle_generator.Direction = 1;
    defparam rectangle_generator.FifoSize = 4;
    defparam rectangle_generator.Length = 16;

    assign Net_526 = 1'h0;



endmodule

