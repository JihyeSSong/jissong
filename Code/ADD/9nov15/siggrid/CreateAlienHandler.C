
AliAnalysisGrid* CreateAlienHandler()
{
// Check if user has a valid token, otherwise make one. This has limitations.
// One can always follow the standard procedure of calling alien-token-init then
//   source /tmp/gclient_env_$UID in the current shell.
    // if (!AliAnalysisGrid::CreateToken()) return NULL;
    AliAnalysisAlien *plugin = new AliAnalysisAlien();
// Set the run mode (can be "full", "test", "offline", "submit" or "terminate")
    //plugin->SetOverwriteMode(kFALSE);
    plugin->SetRunMode("test");
// Set versions of used packages
    plugin->SetAPIVersion("V1.1x");
    plugin->SetROOTVersion("v5-34-30-alice3-5");
    plugin->SetAliROOTVersion("v5-06-41-3");
    plugin->SetAliPhysicsVersion("vAN-20150930-1");

    TString includes_str = "-Wno-deprecated -I$. -I$CGAL_DIR/include -I$FASTJET/include -I$ROOTSYS/include -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include";
    plugin->AddIncludePath(includes_str.Data()); // for grid running

// Declare input data to be processed.
// Method 1: Create automatically XML collections using alien 'find' command.
// Define production directory LFN
    plugin->SetGridDataDir("/alice/data/2015/LHC15f");
    // On real reconstructed data:
// plugin->SetGridDataDir("/alice/data/2009/LHC09d");
// Set data search pattern
    plugin->SetDataPattern("*pass2/*ESDs.root");
// Data pattern for reconstructed data
//   plugin->SetDataPattern("*ESDs/pass4/*ESDs.root");
    plugin->SetRunPrefix("000");   // real data
    //It's been ages that I've tried this. Maybe it is no longer crap.
    //plugin->SetUseSubmitPolicy();

    //195344, 195346, 195351, 195389, 195390

    TString runnumbers[] = {
        "226062"
    };

    //Int_t numberofruns = sizeof(runnumbers)/sizeof(Int_t);
    Int_t numberofruns=1;

    for(int atrun = 0; atrun<numberofruns; atrun++) {
        plugin->AddRunNumber(runnumbers[atrun]);
    }

//  plugin->AddDataFile("188362.xml");
//  plugin->AddDataFile("188359.xml");

//   plugin->AddRunNumber(104065);  // real data
//   plugin->SetOutputSingleFolder("output");
    plugin->SetOutputToRunNo();
// Method 2: Declare existing data files (raw collections, xml collections, root file)
// If no path mentioned data is supposed to be in the work directory (see SetGridWorkingDir())
// XML collections added via this method can be combined with the first method if
// the content is compatible (using or not tags)
//   plugin->AddDataFile("tag.xml");
//   plugin->AddDataFile("/alice/data/2008/LHC08c/000057657/raw/Run57657.Merged.RAW.tag.root");
// Define alien work directory where all files will be copied. Relative to alien $HOME
    plugin->SetGridWorkingDir("MultSelectionTest-02-3");
// Declare alien output directory. Relative to working directory.
    plugin->SetGridOutputDir("output"); // In this case will be $HOME/work/output
// Declare the analysis source files names separated by blancs. To be compiled runtime
// using ACLiC on the worker nodes.
    //plugin->AddAdditionalLibrary(""); //pp-vs-mult utils

    plugin->SetAnalysisSource("AliAnalysisTaskSigma0.cxx");
// Declare all libraries (other than the default ones for the framework. These will be
// loaded by the generated analysis macro. Add all extra files (task .cxx/.h) here.
    plugin->SetAdditionalLibs("libOADB.so AliAnalysisTaskSigma0.h AliAnalysisTaskSigma0.cxx");

// Declare the output file names separated by blancs.
// (can be like: file.root or file.root@ALICE::Niham::File)
//   plugin->SetOutputFiles("lambda0recooutput.root");
    plugin->SetDefaultOutputs();
// Optionally define the files to be archived.
//   plugin->SetOutputArchive("log_archive.zip:stdout,stderr@ALICE::NIHAM::File root_archive.zip:*.root@ALICE::NIHAM::File");
//   plugin->SetOutputArchive("log_archive.zip:stdout,stderr");
// Optionally set a name for the generated analysis macro (default MyAnalysis.C)
    plugin->SetAnalysisMacro("AliSigma0SelectionTest.C");
// Optionally set maximum number of input files/subjob (default 100, put 0 to ignore)
    plugin->SetSplitMaxInputFileNumber(50);
// Optionally modify the executable name (default analysis.sh)
    plugin->SetExecutable("AliSigma0SelectionTest.sh");
// Optionally set number of failed jobs that will trigger killing waiting sub-jobs.
//   plugin->SetMaxInitFailed(5);
// Optionally resubmit threshold.
//   plugin->SetMasterResubmitThreshold(90);
// Optionally set time to live (default 30000 sec)
    plugin->SetTTL(45000);
// Optionally set input format (default xml-single)
    plugin->SetInputFormat("xml-single");
// Optionally modify the name of the generated JDL (default analysis.jdl)
    plugin->SetJDLName("AliSigma0SelectionTest.jdl");
// Optionally modify job price (default 1)
    plugin->SetPrice(1);
// Optionally modify split mode (default 'se')
    plugin->SetSplitMode("se");
//configure to merge files sequentially rather than all-at-once
    //plugin->SetMergeViaJDL();
    plugin->SetMaxMergeFiles(60);
    plugin->SetNtestFiles(1);
    return plugin;
}
