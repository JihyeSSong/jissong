AliAnalysisTaskSigma0 *AddTaskSigma0( const TString lMasterJobSessionFlag = "")
{
// Creates, configures and attaches to the train a cascades check task.
   // Get the pointer to the existing analysis manager via the static access method.
   //==============================================================================
   AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
   if (!mgr) {
      ::Error("AddTaskStrangenessVsMultiplicity", "No analysis manager to connect to.");
      return NULL;
   }   

   // Check the analysis type using the event handlers connected to the analysis manager.
   //==============================================================================
   if (!mgr->GetInputEventHandler()) {
      ::Error("AddTaskSigma0", "This task requires an input event handler");
      return NULL;
   }   
   TString type = mgr->GetInputEventHandler()->GetDataType(); // can be "ESD" or "AOD"

  // Create and configure the task
  AliAnalysisTaskSigma0 *taskAuxiliarySigma0 = new AliAnalysisTaskSigma0("taskAuxiliarySigma0");
  mgr->AddTask(taskAuxiliarySigma0);
  TString outputFileName = AliAnalysisManager::GetCommonFileName();
   
  outputFileName += ":PWGLF_PPVsMult";
  if (mgr->GetMCtruthEventHandler()) outputFileName += "_MC";
   
  Printf("Set OutputFileName : \n %s\n", outputFileName.Data() );

  AliAnalysisDataContainer *coutputList = mgr->CreateContainer("cListSkeleton",
							     TList::Class(),
							     AliAnalysisManager::kOutputContainer,
							     outputFileName );

  mgr->ConnectInput (taskAuxiliarySigma0, 0, mgr->GetCommonInputContainer());
  mgr->ConnectOutput(taskAuxiliarySigma0, 1, coutputList);
  
  return taskAuxiliarySigma0;
}   
