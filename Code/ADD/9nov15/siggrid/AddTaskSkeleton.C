AliAnalysisTaskSkeleton *AddTaskSkeleton( const TString lMasterJobSessionFlag = "")
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
      ::Error("AddTaskSkeleton", "This task requires an input event handler");
      return NULL;
   }   
   TString type = mgr->GetInputEventHandler()->GetDataType(); // can be "ESD" or "AOD"

  // Create and configure the task
  AliAnalysisTaskSkeleton *taskAuxiliarySkeleton = new AliAnalysisTaskSkeleton("taskAuxiliarySkeleton");
  mgr->AddTask(taskAuxiliarySkeleton);
  TString outputFileName = AliAnalysisManager::GetCommonFileName();
   
  outputFileName += ":PWGLF_PPVsMult";
  if (mgr->GetMCtruthEventHandler()) outputFileName += "_MC";
   
  Printf("Set OutputFileName : \n %s\n", outputFileName.Data() );

  AliAnalysisDataContainer *coutputList = mgr->CreateContainer("cListSkeleton",
							     TList::Class(),
							     AliAnalysisManager::kOutputContainer,
							     outputFileName );

  mgr->ConnectInput (taskAuxiliarySkeleton, 0, mgr->GetCommonInputContainer());
  mgr->ConnectOutput(taskAuxiliarySkeleton, 1, coutputList);
  
  return taskAuxiliarySkeleton;
}   
