//* $Id:  $ */
//--------------------------------------------------
// Example macro to do analysis with the 
// analysis classes in PWG4PartCorr// Can be executed with Root and AliRoot
// Pay attention to the options and definitions// set in the lines below
//  Author : Gustavo Conesa Balbastre (INFN-LNF)
//-------------------------------------------------

enum anaModes {mLocal=0, mGRID=3};
//mLocal    = 0: Analyze locally files in your computer
//mGRID     = 3: Analyze files on GRID
//---------------------------------------------------------------------------
//Settings to read locally several files, only for "mLocal" mode
//The different values are default, they can be set with environmental 
//variables: INDIR, PATTERN, NFILES, respectivelly

// char * kInDir = "/a/a2/gc/data/lhc12d/";
// Int_t kFile = 16;
// Int_t kFile = 2; // Number of files

//   MC
// char * kInDir = "/a/a2/gc/datamc/lhc10f6a/";
// Int_t kFile = 1;

// char * kInDir = "/a/a2/gc/data11/p4-jan12/";

// char * kInDir = "/user/data/files/"; 

// char * kInDir = "/a/a2/gc/data10dp2/";

// char * kInDir = "/a/a2/gc/data11/11ap2-000146805/";

// char * kInDir = "/a1/test/sig6/data11/11ap2-000146805";


char * kInDir = "/a1/b2/dt/dt-pPb/run195480";  // p-Pb data

 Int_t kFile = 5;

// char * kInDir = "/a/a2/gc/data/lhc11c/153116/";


// char * kInDir = "/a/a2/gc/data10dp2/";
// char * kInDir = "/a/a2/gc/data/lhc12c/179920/";

char * kPattern = ""; // Data are in files kInDir/kPattern+i 




//---------------------------------------------------------------------------
//Collection file for grid analysis
char * kXML = "collection.xml";
// char * kXML = "mc10f6a_125156.xml";

//---------------------------------------------------------------------------
//Scale histograms from file. Change to kTRUE when xsection file exists
//Put name of file containing xsection 
//Put number of events per ESD file
//This is an specific case for normalization of Pythia files.
const Bool_t kGetXSectionFromFileAndScale = kFALSE ;
const char * kXSFileName = "pyxsec.root";

//---------------------------------------------------------------------------

const Bool_t kMC = kFALSE; //With real data kMC = kFALSE
const TString kInputData = "ESD"; //ESD, AOD, MC, deltaAOD
const Bool_t  outAOD = kFALSE; //Some tasks doesnt need it.
TString kTreeName;
const Bool_t kUsePAR = kFALSE; //set to kFALSE for libraries
const Int_t kFilter = kFALSE; //Use ESD filter

void ana(Int_t mode=mGRID)
//void ana(Int_t mode=mLocal)
{
  // Main
  
  //--------------------------------------------------------------------
  // Load analysis libraries
  // Look at the method below, 
  // change whatever you need for your analysis case
  // ------------------------------------------------------------------
  LoadLibraries() ;
  // TGeoManager::Import("geometry.root") ; //need file "geometry.root" in local dir!!!!
  
  //-------------------------------------------------------------------------------------------------
  //Create chain from ESD and from cross sections files, look below for options.
  //-------------------------------------------------------------------------------------------------
  if(kInputData == "ESD") kTreeName = "esdTree" ;
  else if(kInputData.Contains("AOD")) kTreeName = "aodTree" ;
  else if (kInputData == "MC") kTreeName = "TE" ;
  else {
    cout<<"Wrong  data type "<<kInputData<<endl;
    break;
  }
  
  if(kFilter) outAOD = kTRUE;
  
  TChain *chain       = new TChain(kTreeName) ;
  TChain * chainxs = new TChain("Xsection") ;
  CreateChain(mode, chain, chainxs);  
  
  if(chain){
    AliLog::SetGlobalLogLevel(AliLog::kError);//Minimum prints on screen
    
    //--------------------------------------
    // Make the analysis manager
    //-------------------------------------
    AliAnalysisManager *mgr  = new AliAnalysisManager("Manager", "Manager");
    //AliAnalysisManager::SetUseProgressBar(kTRUE);
    //mgr->SetSkipTerminate(kTRUE);
    //mgr->SetNSysInfo(1);
    
    // MC handler
    if((kMC || kInputData == "MC") && !kInputData.Contains("AOD")){
      AliMCEventHandler* mcHandler = new AliMCEventHandler();
      mcHandler->SetReadTR(kFALSE);//Do not search TrackRef file
      mgr->SetMCtruthEventHandler(mcHandler);
      if( kInputData == "MC") {
	cout<<"MC INPUT EVENT HANDLER"<<endl;
	mgr->SetInputEventHandler(NULL);
      }
    }
    
    // AOD output handler
    if(kInputData!="deltaAOD" && outAOD){
      cout<<"Init output handler"<<endl;
      AliAODHandler* aodoutHandler   = new AliAODHandler();
      aodoutHandler->SetOutputFileName("aod.root");
      ////aodoutHandler->SetCreateNonStandardAOD();
      mgr->SetOutputEventHandler(aodoutHandler);
    }
    
    //input
    
    if(kInputData == "ESD"){
      // ESD handler
      AliESDInputHandler *esdHandler = new AliESDInputHandler();
      esdHandler->SetReadFriends(kFALSE);
      mgr->SetInputEventHandler(esdHandler);
      cout<<"ESD handler "<<mgr->GetInputEventHandler()<<endl;
    }
    else if(kInputData.Contains("AOD")){
      // AOD handler
      AliAODInputHandler *aodHandler = new AliAODInputHandler();
      mgr->SetInputEventHandler(aodHandler);
      if(kInputData == "deltaAOD") aodHandler->AddFriend("deltaAODPartCorr.root");
      cout<<"AOD handler "<<mgr->GetInputEventHandler()<<endl;
    }
    //mgr->RegisterExternalFile("deltaAODPartCorr.root");
    //mgr->SetDebugLevel(-1); // For debugging, do not uncomment if you want no messages.
    
    //-------------------------------------------------------------------------
    //Define task, put here any other task that you want to use.
    //-------------------------------------------------------------------------
    AliAnalysisDataContainer *cinput1 = mgr->GetCommonInputContainer();
    AliAnalysisDataContainer *coutput1;
    if(outAOD){
      
      coutput1 = mgr->GetCommonOutputContainer();
      
      if(kInputData=="ESD"){
	
	//	gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskPhysicsSelection.C");

	gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
	AliPhysicsSelectionTask* physSelTask = AddTaskPhysicsSelection();
	
	if(kFilter){

	  // Set of cuts
	  //for standard global track cuts
	  AliESDtrackCuts* esdTrackCutsGlobal =  AliESDtrackCuts::GetStandardITSTPCTrackCuts2009(kTRUE);
	  esdTrackCutsGlobal->SetName("StandardFromAliESDTrackCuts");
	  
	  //for TPC tracks only
	  //    AliESDtrackCuts* esdTrackCutsTPC =  AliESDtrackCuts::GetStandardTPCOnlyTrackCuts();
	  //      esdTrackCutsTPC->SetRequireTPCRefit(kTRUE); 
	  //      esdTrackCutsTPC->SetMinNClustersTPC(70);
	  
	  AliAnalysisFilter* trackFilter = new AliAnalysisFilter("trackFilter");
	  trackFilter->AddCuts(esdTrackCutsGlobal); 
	  //trackFilter->AddCuts(esdTrackCutsTPC); 
	  
	  gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskESDFilter.C");
	  AliAnalysisTaskESDfilter *taskesdfilter = AddTaskESDFilter(kFALSE);
	  esdfilter->SetTrackFilter(trackFilter);
	  kInputData = "AOD" ;
	  kTreeName = "aodTree" ;
	}
      }
    }



    //  gROOT->LoadMacro("$ALICE_ROOT/PWGGA/GammaConv/macros/AddTaskCaloConv.C");    // !!! NEW ALIROOT !!!

 gROOT->LoadMacro("$ALICE_PHYSICS/PWGGA/Hyperon/macros/AddTaskCaloConv.C");    // !!! NEW ALIROOT !!!


    //  gROOT->LoadMacro("$ALICE_PHYSICS/PWGGA/Hyperon/macros/Hyperon.C");  
 //  AliAnalysisTaskHyperon * taskHyperon = ();

   gROOT->LoadMacro("AliAnalysisTaskSigma0.cxx+g");
   //   gROOT->LoadMacro("AliAnalysisTaskSigma0Spectra.cxx+g");
   ///  gROOT->LoadMacro("AliAnalysisTaskSigma0Corr.cxx+g"); 
   // AliAnalysisTaskSigma0Corr *myTask = new AliAnalysisTaskSigma0Corr("AliAnalysisTaskSigma0Corr");
    
    AliAnalysisTaskSigma0 *myTask = new AliAnalysisTaskSigma0("AliAnalysisTaskSigma");

     if(!myTask) exit(-1);
    mgr->AddTask(myTask);
    
 // jihye AliAnalysisTaskCaloConv * taskCaloConv= ();


// jihye  TFile *fBadMap = TFile::Open("BadMap_LHC11a_pp2760.root");

 AliAnalysisDataContainer *cinput = mgr->GetCommonInputContainer();
    TString outputfile = AliAnalysisManager::GetCommonFileName();
 AliAnalysisDataContainer *coutput = mgr->CreateContainer("CaloConv", TList::Class(), AliAnalysisManager::kOutputContainer, Form("%s:PWGGA_CaloConv",outputfile.Data()));

    mgr->ConnectInput(myTask, 0, cinput);
    mgr->ConnectOutput(myTask, 1, coutput);


    
    //-----------------------
    // Run the analysis
    //-----------------------    
    mgr->InitAnalysis();
    mgr->PrintStatus();
    mgr->StartAnalysis("local",chain);

    cout <<" Analysis ended sucessfully "<< endl ;
    
  }
  else cout << "Chain was not produced ! "<<endl;

  
}

void  LoadLibraries() {
  
  //--------------------------------------
  // Load the needed libraries most of them already loaded by aliroot
  //--------------------------------------
  gSystem->Load("libTree.so");
  gSystem->Load("libGeom.so");
  gSystem->Load("libVMC.so");
  gSystem->Load("libXMLIO.so");
  gSystem->Load("libMatrix.so");
  gSystem->Load("libPhysics.so");

  gSystem->Load("libPHOSUtils");
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice"); //AliAnalysisTaskSE
  gSystem->Load("STEERBase");
  gSystem->Load("ESD");
  gSystem->Load("EMCALUtils");


    gROOT->ProcessLine(".include $ALICE_ROOT/include");
    gROOT->ProcessLine(".include $ALICE_PHYSICS/include");

   if(kUsePAR){
    //--------------------------------------------------------
    //If you want to use root and par files from aliroot
    //--------------------------------------------------------  
    //    SetupPar("STEERBase");
    //  SetupPar("ESD");
    //  SetupPar("AOD");
    //  SetupPar("ANALYSIS");
    //  SetupPar("ANALYSISalice");
    //  SetupPar("PHOSUtils");
    // SetupPar("EMCALUtils");
    //    SetupPar("PWG4PartCorrBase");
    // SetupPar("PWG4PartCorrDep");
     SetupPar("PWGGAGammaConv");
  }
  else{
    //--------------------------------------------------------
    // If you want to use already compiled libraries 
    // in the aliroot distribution
    //--------------------------------------------------------
    gSystem->Load("libSTEERBase.so");
    gSystem->Load("libESD.so");
    gSystem->Load("libAOD.so");
    gSystem->Load("libANALYSIS.so");
    gSystem->Load("libANALYSISalice.so");
    gSystem->Load("libPHOSUtils");
    gSystem->Load("libEMCALUtils");
    gSystem->Load("libPartCorrBase.so");
    gSystem->Load("libPartCorrDep.so");
    if(kFilter){
      gSystem->Load("libCORRFW.so");
      gSystem->Load("libPWG3base.so");
      gSystem->Load("libPWG3muon.so");
    }
  }
}

void SetupPar(char* pararchivename)
{
  //Load par files, create analysis libraries
  //For testing, if par file already decompressed and modified
  //classes then do not decompress.
 
  TString cdir(Form("%s", gSystem->WorkingDirectory() )) ; 
  TString parpar(Form("%s.par", pararchivename)) ; 
//  if ( gSystem->AccessPathName(parpar.Data()) ) {
//    gSystem->ChangeDirectory(gSystem->Getenv("ALICE_ROOT")) ;
//     TString processline(Form(".! make %s", parpar.Data())) ; 
//     gROOT->ProcessLine(processline.Data()) ;
//     gSystem->ChangeDirectory(cdir) ; 
//     processline = Form(".! mv $ALICE_ROOT/%s .", parpar.Data()) ;
//     gROOT->ProcessLine(processline.Data()) ;
//   } 
  if ( gSystem->AccessPathName(pararchivename) ) {  
    TString processline = Form(".! tar xvzf %s",parpar.Data()) ;
    gROOT->ProcessLine(processline.Data());
  }
  
  TString ocwd = gSystem->WorkingDirectory();
  gSystem->ChangeDirectory(pararchivename);
  
  // check for BUILD.sh and execute
  if (!gSystem->AccessPathName("PROOF-INF/BUILD.sh")) {
    printf("*******************************\n");
    printf("*** Building PAR archive    ***\n");
    cout<<pararchivename<<endl;
    printf("*******************************\n");
    
    if (gSystem->Exec("PROOF-INF/BUILD.sh")) {
      Error("runProcess","Cannot Build the PAR Archive! - Abort!");
      return -1;
    }
  }
  // check for SETUP.C and execute
  if (!gSystem->AccessPathName("PROOF-INF/SETUP.C")) {
    printf("*******************************\n");
    printf("*** Setup PAR archive       ***\n");
    cout<<pararchivename<<endl;
    printf("*******************************\n");
    gROOT->Macro("PROOF-INF/SETUP.C");
  }
  
  gSystem->ChangeDirectory(ocwd.Data());
  printf("Current dir: %s\n", ocwd.Data());
}


void CreateChain(const anaModes mode, TChain * chain, TChain * chainxs){
  //Fills chain with data
  TString ocwd = gSystem->WorkingDirectory();
  
  //---------------------------------------
  //Local files analysis
  //---------------------------------------
  if(mode == mLocal){    
    //If you want to add several ESD files sitting in a common directory INDIR
    //Specify as environmental variables the directory (INDIR), the number of files 
    //to analyze (NFILES) and the pattern name of the directories with files (PATTERN)

    if(gSystem->Getenv("INDIR"))  
      kInDir = gSystem->Getenv("INDIR") ; 
    else cout<<"INDIR not set, use default: "<<kInDir<<endl;	
    
    if(gSystem->Getenv("PATTERN"))   
      kPattern = gSystem->Getenv("PATTERN") ; 
    else  cout<<"PATTERN not set, use default: "<<kPattern<<endl;
    
    if(gSystem->Getenv("NFILES"))
      kFile = atoi(gSystem->Getenv("NFILES")) ;
    else cout<<"NFILES not set, use default: "<<kFile<<endl;
    
    //Check if env variables are set and are correct
    if ( kInDir  && kFile) {
      printf("Get %d files from directory %s\n",kFile,kInDir);
      if ( ! gSystem->cd(kInDir) ) {//check if ESDs directory exist
	printf("%s does not exist\n", kInDir) ;
	return ;
      }

      //if(gSystem->Getenv("XSFILE"))  
      //kXSFileName = gSystem->Getenv("XSFILE") ; 
      //else cout<<" XS file name not set, use default: "<<kXSFileName<<endl;	
      char * kGener = gSystem->Getenv("GENER");
      if(kGener) {
	cout<<"GENER "<<kGener<<endl;
	if(!strcmp(kGener,"PYTHIA")) kXSFileName = "pyxsec.root";
	else if(!strcmp(kGener,"HERWIG")) kXSFileName = "hexsec.root";
	else cout<<" UNKNOWN GENER, use default: "<<kXSFileName<<endl;
      }
      else cout<<" GENER not set, use default xs file name: "<<kXSFileName<<endl;

      cout<<"INDIR   : "<<kInDir<<endl;
      cout<<"NFILES  : "<<kFile<<endl;
      cout<<"PATTERN : " <<kPattern<<endl;
      cout<<"XSFILE  : "<<kXSFileName<<endl;

      TString datafile="";
      if(kInputData == "ESD") datafile = "AliESDs.root" ;
      else if(kInputData.Contains("AOD")) datafile = "AliAOD.root" ;
      else if(kInputData == "MC")  datafile = "galice.root" ;
      
      //Loop on ESD files, add them to chain
      Int_t event =0;
      Int_t skipped=0 ; 
      char file[120] ;
      char filexs[120] ;
      
      for (event = 0 ; event < kFile ; event++) {
	sprintf(file, "%s/%s%d/%s", kInDir,kPattern,event,datafile.Data()) ; 
	sprintf(filexs, "%s/%s%d/%s", kInDir,kPattern,event,kXSFileName) ; 
	TFile * fESD = 0 ; 
	//Check if file exists and add it, if not skip it
	if ( fESD = TFile::Open(file)) {
	  if ( fESD->Get(kTreeName) ) { 
	    printf("++++ Adding %s\n", file) ;
	    chain->AddFile(file);
	    chainxs->Add(filexs) ; 
	  }
	}
	else { 
	  printf("---- Skipping %s\n", file) ;
	  skipped++ ;
	}
      }
      printf("number of entries # %lld, skipped %d\n", chain->GetEntries(), skipped*100) ; 	
    }
    else {
      TString input = "AliESDs.root" ;
      cout<<">>>>>> No list added, take a single file <<<<<<<<< "<<input<<endl;
      chain->AddFile(input);
    }
    
  }// local files analysis
  
  //------------------------------
  //GRID xml files
  //-----------------------------
  else if(mode == mGRID){
    //Get colection file. It is specified by the environmental
    //variable XML

    if(gSystem->Getenv("XML") )
      kXML = gSystem->Getenv("XML");
    else
      sprintf(kXML, "collection.xml") ; 
    
    if (!TFile::Open(kXML)) {
      printf("No collection file with name -- %s -- was found\n",kXML);
      return ;
    }
    else cout<<"XML file "<<kXML<<endl;

    //Load necessary libraries and connect to the GRID
    gSystem->Load("libNetx.so") ; 
    gSystem->Load("libRAliEn.so"); 
    TGrid::Connect("alien://") ;

    //Feed Grid with collection file
    //TGridCollection * collection =  (TGridCollection*)gROOT->ProcessLine(Form("TAlienCollection::Open(\"%s\", 0)", kXML));
    TGridCollection * collection = (TGridCollection*) TAlienCollection::Open(kXML);
    if (! collection) {
      AliError(Form("%s not found", kXML)) ; 
      return kFALSE ; 
    }
    TGridResult* result = collection->GetGridResult("",0 ,0);
   
    // Makes the ESD chain 
    printf("*** Getting the Chain       ***\n");
    for (Int_t index = 0; index < result->GetEntries(); index++) {
      TString alienURL = result->GetKey(index, "turl") ; 
      cout << "================== " << alienURL << endl ; 
      chain->Add(alienURL) ; 
      alienURL.ReplaceAll("AliESDs.root",kXSFileName);
      chainxs->Add(alienURL) ; 
    }
  }// xml analysis
  
  gSystem->ChangeDirectory(ocwd.Data());
}

//________________________________________________
void GetAverageXsection(TTree * tree, Double_t & xs, Float_t & ntr)
{
  // Read the PYTHIA statistics from the file pyxsec.root created by
  // the function WriteXsection():
  // integrated cross section (xsection) and
  // the  number of Pyevent() calls (ntrials)
  // and calculate the weight per one event xsection/ntrials
  // The spectrum calculated by a user should be
  // multiplied by this weight, something like this:
  // TH1F *userSpectrum ... // book and fill the spectrum
  // userSpectrum->Scale(weight)
  //
  // Yuri Kharlov 19 June 2007
  // Gustavo Conesa 15 April 2008
  Double_t xsection = 0;
  UInt_t    ntrials = 0;
  xs = 0;
  ntr = 0;
  
  Int_t nfiles =  tree->GetEntries()  ;
  if (tree && nfiles > 0) {
    tree->SetBranchAddress("xsection",&xsection);
    tree->SetBranchAddress("ntrials",&ntrials);
    for(Int_t i = 0; i < nfiles; i++){
      tree->GetEntry(i);
      xs += xsection ;
      ntr += ntrials ;
      cout << "xsection " <<xsection<<" ntrials "<<ntrials<<endl; 
    }
    
    xs =   xs /  nfiles;
    ntr =  ntr / nfiles;
    cout << "-----------------------------------------------------------------"<<endl;
    cout << "Average of "<< nfiles<<" files: xsection " <<xs<<" ntrials "<<ntr<<endl; 
    cout << "-----------------------------------------------------------------"<<endl;
  } 
  else cout << " >>>> Empty tree !!!! <<<<< "<<endl;
  
}



