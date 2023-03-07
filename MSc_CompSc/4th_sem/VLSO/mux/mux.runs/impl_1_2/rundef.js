//
// PlanAhead(TM)
// rundef.js: a PlanAhead-generated ExploreAhead Script for WSH 5.1/5.6
// Copyright 1986-1999, 2001-2010 Xilinx, Inc. All Rights Reserved.
//

var WshShell = new ActiveXObject( "WScript.Shell" );
var ProcEnv = WshShell.Environment( "Process" );
var PathVal = ProcEnv("PATH");
if ( PathVal.length == 0 ) {
  PathVal = "C:\\Xilinx\\12.3\\ISE_DS\\ISE\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\ISE\\lib\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\lib\\nt;";
} else {
  PathVal = "C:\\Xilinx\\12.3\\ISE_DS\\ISE\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\ISE\\lib\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\bin\\nt;C:\\Xilinx\\12.3\\ISE_DS\\common\\lib\\nt;" + PathVal;
}

ProcEnv("PATH") = PathVal;

var RDScrFP = WScript.ScriptFullName;
var RDScrN = WScript.ScriptName;
var RDScrDir = RDScrFP.substr( 0, RDScrFP.length - RDScrN.length - 1 );
var ISEJScriptLib = RDScrDir + "/ISEWrap.js";
eval( EAInclude(ISEJScriptLib) );


ISEStep( "ngdbuild",
         "-intstyle ise -p xc6vlx75tff484-1 -uc \"mux.ucf\" \"mux.edf\"" );
ISEStep( "map",
         "-intstyle ise -w \"mux.ngd\"" );
ISEStep( "par",
         "-intstyle ise \"mux.ncd\" -w \"mux_routed.ncd\"" );
ISEStep( "trce",
         "-intstyle ise -o \"mux.twr\" -v 30 -l 30 \"mux_routed.ncd\" \"mux.pcf\"" );
ISEStep( "xdl",
         "-secure -ncd2xdl -nopips \"mux_routed.ncd\" \"mux_routed.xdl\"" );



function EAInclude( EAInclFilename ) {
  var EAFso = new ActiveXObject( "Scripting.FileSystemObject" );
  var EAInclFile = EAFso.OpenTextFile( EAInclFilename );
  var EAIFContents = EAInclFile.ReadAll();
  EAInclFile.Close();
  return EAIFContents;
}
