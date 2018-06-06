void Hyperon(const char* dataset="collection.xml")
{
  /* $Id$ */
  TStopwatch timer;
  timer.Start();


    TStringToken libs("Core,Tree,Geom,VMC,Physics,Minuit,Gui,XMLParser,Minuit2,Proof,STEERBase,ESD,AOD,OADB,ANALYSIS,ANALYSISalice,CDB,RAWDatabase,STEER,CORRFW,PHOSUtils,PHOSbase,PHOSpi0Calib,PHOSrec,PHOSshuttle,PHOSsim", ",");
  while( libs.NextToken() )
    gSystem->Load( Form("lib%s", libs.Data()) );

  gSystem->Load("libTree");
  gSystem->Load("libGeom");
  gSystem->Load("libVMC");
  gSystem->Load("libPhysics");
  gSystem->Load("libPWGGAGammaConv");
  gSystem->Load("libPWGGAHyperon");
  
  //load analysis framework
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice"); //AliAnalysisTaskSE
  
  // Connect to alien
  TString token = gSystem->Getenv("GRID_TOKEN") ;
  if (1) // token == "OK" ) 
    TGrid::Connect("alien://");
  else 
    AliInfo("You are not connected to the GRID") ; 

  cout << "-5 Sigma0Analysis: processing collection " << dataset << endl;

  // Create the chain
  TChain* chain = new TChain("aodTree");

 cout << "-4 Sigma0Analysis: processing collection " << dataset << endl;


  TGridCollection * collection = dynamic_cast<TGridCollection*>(TAlienCollection::Open(dataset));

 cout << "-3 Sigma0Analysis: processing collection " << dataset << endl;

  
  TAlienResult* result = collection->GetGridResult("",0 ,0);

 cout << "-2 Sigma0Analysis: processing collection " << dataset << endl;


  TList* rawFileList = result->GetFileInfoList();

 cout << "-1 Sigma0Analysis: processing collection " << dataset << endl;
  
  for (Int_t counter=0 ; counter < rawFileList->GetEntries() ; counter++) {
    TFileInfo * fi =  static_cast<TFileInfo*>(rawFileList->At(counter)) ; 
    const char * rawFile = fi->GetCurrentUrl()->GetUrl() ;  
    printf("Processing %s\n", rawFile) ;
    chain->Add(rawFile);
    printf("Chain: %d entries.\n",chain->GetEntriesFast()); 
  }

 cout << "2 Sigma00Analysis: processing collection " << dataset << endl;

  // Make the analysis manager
  AliAnalysisManager *mgr = new AliAnalysisManager("Hyperon");
  mgr->SetCommonFileName("histos.root");
  

 cout << "3 Sigma00Analysis: processing collection " << dataset << endl;

  // AOD input handler
  AliESDInputHandler* esdH = new AliESDInputHandler();
  mgr->SetInputEventHandler(esdH);

   cout << "4 Sigma00Analysis: processing collection " << dataset << endl;


  // Debug level
  mgr->SetDebugLevel(2);

 cout << "5 Sigma00Analysis: processing collection " << dataset << endl;

  //   gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskCentrality.C"); 
  //   AliCentralitySelectionTask* taskCentrality = AddTaskCentrality(); 
 

   //   if (analysisMC)     taskCentrality->SetMCInput(); 

  // // Update it for Hyperon (YK 22.01.2015)
  // gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskEventplane.C");
  // AliEPSelectionTask *taskEP = AddTaskEventplane() ; 

  // gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskVZEROEPSelection.C");
  // AliVZEROEPSelectionTask *selTask = AddTaskVZEROEPSelection();  

  // Add my task
   //   AliAnalysisHyperon* task = new AliAnalysisHyperon();

   //AnalysisTaskSigma0* task = new AliAnalysisTaskSigma0();
   AliAnalysisTaskSE* task = new AliAnalysisTaskSigma0();
   mgr -> AddTask(task);

  // gROOT->LoadMacro("$ALICE_ROOT/PWGGA/PHOSTasks/PHOS_PbPb/AddTaskPHOSPi0Flow.C"); // Update it for Hyperon (YK 22.01.2015)
  // task = AddTaskPHOSPi0Flow();

 cout << "6 Sigma00Analysis: processing collection " << dataset << endl;


  // // Create containers for input/output
  AliAnalysisDataContainer *cinput   = mgr->GetCommonInputContainer(); 
  AliAnalysisDataContainer *coutput1 = mgr->CreateContainer("Hyperon",TList::Class(),AliAnalysisManager::kOutputContainer,"HyperonHist.root");
  
 cout << "7 Sigma00Analysis: processing collection " << dataset << endl;


  // // Connect input/output
  mgr->ConnectInput(task , 0, cinput);
  mgr->ConnectOutput(task, 1, coutput1);


 cout << "8 Sigma00Analysis: processing collection " << dataset << endl;
 
  if (mgr->InitAnalysis()) {
    mgr->PrintStatus();
    mgr->StartAnalysis("local", chain);
  }

cout << "9 Sigma00Analysis: processing collection " << dataset << endl;
 

  timer.Stop();
  timer.Print();
}
