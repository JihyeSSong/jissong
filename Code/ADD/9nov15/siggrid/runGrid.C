{
    // Load common libraries
    gSystem->Load("libCore.so");
    gSystem->Load("libTree.so");
    gSystem->Load("libGeom.so");
    gSystem->Load("libVMC.so");
    gSystem->Load("libPhysics.so");
    gSystem->Load("libSTEERBase");
    gSystem->Load("libESD");
    gSystem->Load("libAOD");
    gSystem->Load("libANALYSIS");
    gSystem->Load("libANALYSISalice");
    gSystem->Load("libANALYSISaliceBase");
    gSystem->Load("libCORRFW");
    gSystem->Load("libOADB");
    // Use AliRoot includes to compile our task
    gROOT->ProcessLine(".include $ALICE_ROOT/include");
    gROOT->ProcessLine(".include $ALICE_PHYSICS/include");
    
    // Create and configure the alien handler plugin
    gROOT->LoadMacro("CreateAlienHandler.C");
    AliAnalysisGrid *alienHandler = CreateAlienHandler();
    if (!alienHandler) return;
    
    // Create the analysis manager
    AliAnalysisManager *mgr = new AliAnalysisManager("testAnalysis");
    
    // Connect plug-in to the analysis manager
    mgr->SetGridHandler(alienHandler);
    
    //Create input handler
    AliESDInputHandler* esdH = new AliESDInputHandler();
    mgr->SetInputEventHandler(esdH);
    
    gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
    //Arguments: this is MC, yes; Reject Background, yes; Don't necessarily compute BG
    AliPhysicsSelectionTask* physSelTask = AddTaskPhysicsSelection(kFALSE);
    //physSelTask->SetAnalyzeMC();
    
    /* NOT NEEDED
    //---AliCentrality---------------------------------------------------------
    // load task itself
    gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskCentrality.C");
    // create centrality task, add to manager
    AliCentralitySelectionTask* centralityTask = AddTaskCentrality();
    //-------------------------------------------------------------------------
     */
    
    cout<<" Compiling Task..."<<endl;
    // compile our task
    gROOT->LoadMacro("AliAnalysisTaskSigma0.cxx++g");
    gROOT->LoadMacro("AliAnalysisTaskSigma0Spectra.cxx++g");

    //    gROOT->LoadMacro("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
    //    gROOT->LoadMacro("$ALICE_PHYSICS/master/../src/PWGGA/Hyperon/macros/Sigma0.C");

    gROOT->LoadMacro("$ALICE_PHYSICS/PWGGA/Hyperon/macros/Hyperon.C");
    //gROOT->LoadMacro("Hyperon.C");
    //    Hyperon("000236813.xml");
    Hyperon("mc10f6a_125156.xml");

};

/*
    //    gROOT->LoadMacro("/a0/soft/25oct15/aliphysics/master/src/PWGGA/Hyperon/macros/AddTaskCaloConv.C");
    //    gROOT->LoadMacro("AddTaskCaloConv.C");
    //    AddTaskCaloConv();

    Short_t       lCollidingSystems=0  
    // 0 = pp, 1 = AA;
    const TString lMasterJobSessionFlag = "";
    
    // create our task
    TString type = mgr->GetInputEventHandler()->GetDataType(); // can be "ESD" or "AOD"
    
    //AddTask: Should take care of everything transparently...
    //    AliMultSelectionTask *task = AddTaskMultSelection();
    //     AliSigma0Task *task = Hyperon();

    //User Case
    task->SetAddInfo(kTRUE);
    task->SetSaveCalibInfo(kTRUE); //cross-check information for debugging

    AliAnalysisTaskSigma0 *tasksig = AddTaskSigma0();

    
    // Enable debug printouts
    mgr->SetDebugLevel(9);
    
    if (!mgr->InitAnalysis())
        return;
    
    mgr->PrintStatus();
    // Start analysis in grid.
    mgr->StartAnalysis("grid");
};
*/
