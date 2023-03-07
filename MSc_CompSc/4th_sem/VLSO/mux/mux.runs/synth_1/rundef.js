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


ISEStep( "xst",
         "-ifn \"mux.xst\" -ofn \"mux.srp\" -intstyle ise" );



function EAInclude( EAInclFilename ) {
  var EAFso = new ActiveXObject( "Scripting.FileSystemObject" );
  var EAInclFile = EAFso.OpenTextFile( EAInclFilename );
  var EAIFContents = EAInclFile.ReadAll();
  EAInclFile.Close();
  return EAIFContents;
}
