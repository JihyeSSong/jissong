void SigmaStar_Spectra(){
    
    double pTbins[11] = {0.7, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0, 2.4, 3.0, 4.0, 6.0};
    //SigmaStar +
    TH1D *SigmaPstat = new TH1D("SigmaPstat","SigmaPstat", 10, pTbins);
    SigmaPstat->SetBinContent(1, 0.0063);
    SigmaPstat->SetBinContent(2, 0.0058);
    SigmaPstat->SetBinContent(3, 0.0047);
    SigmaPstat->SetBinContent(4, 0.0035);
    SigmaPstat->SetBinContent(5, 0.0027);
    SigmaPstat->SetBinContent(6, 0.002);
    SigmaPstat->SetBinContent(7, 0.0013);
    SigmaPstat->SetBinContent(8, 6.2E-4);
    SigmaPstat->SetBinContent(9, 2.1E-4);
    SigmaPstat->SetBinContent(10, 2.9E-5);
    
    SigmaPstat->SetBinError(1, 0.0003);
    SigmaPstat->SetBinError(2, 0.0002);
    SigmaPstat->SetBinError(3, 0.0002);
    SigmaPstat->SetBinError(4, 0.00013);
    SigmaPstat->SetBinError(5, 0.00010);
    SigmaPstat->SetBinError(6, 0.00008);
    SigmaPstat->SetBinError(7, 0.00004);
    SigmaPstat->SetBinError(8, 0.00002);
    SigmaPstat->SetBinError(9, 0.000006);
    SigmaPstat->SetBinError(10,0.000001);

    
    TH1D *SigmaPsys = new TH1D("SigmaPsys","SigmaPsys", 10, pTbins);
    SigmaPsys->SetBinContent(1, 0.0063);
    SigmaPsys->SetBinContent(2, 0.0058);
    SigmaPsys->SetBinContent(3, 0.0047);
    SigmaPsys->SetBinContent(4, 0.0035);
    SigmaPsys->SetBinContent(5, 0.0027);
    SigmaPsys->SetBinContent(6, 0.002);
    SigmaPsys->SetBinContent(7, 0.0013);
    SigmaPsys->SetBinContent(8, 6.2E-4);
    SigmaPsys->SetBinContent(9, 2.1E-4);
    SigmaPsys->SetBinContent(10, 2.9E-5);
    
    SigmaPsys->SetBinError(1, 0.0008);
    SigmaPsys->SetBinError(2, 0.0007);
    SigmaPsys->SetBinError(3, 0.0005);
    SigmaPsys->SetBinError(4, 0.00035);
    SigmaPsys->SetBinError(5, 0.00033);
    SigmaPsys->SetBinError(6, 0.00024);
    SigmaPsys->SetBinError(7, 0.00014);
    SigmaPsys->SetBinError(8, 0.00007);
    SigmaPsys->SetBinError(9, 0.000025);
    SigmaPsys->SetBinError(10,0.000004);
    
    
    //SigmaStar -

    TH1D *SigmaMstat = new TH1D("SigmaMstat","SigmaMstat", 10, pTbins);
    SigmaMstat->SetBinContent(1, 0.0071);
    SigmaMstat->SetBinContent(2, 0.0056);
    SigmaMstat->SetBinContent(3, 0.0051);
    SigmaMstat->SetBinContent(4, 0.0039);
    SigmaMstat->SetBinContent(5, 0.0031);
    SigmaMstat->SetBinContent(6, 0.0023);
    SigmaMstat->SetBinContent(7, 0.0013);
    SigmaMstat->SetBinContent(8, 7.2E-4);
    SigmaMstat->SetBinContent(9, 2.0E-4);
    SigmaMstat->SetBinContent(10, 3.2E-5);
    
    
    SigmaMstat->SetBinError(1, 0.0003);
    SigmaMstat->SetBinError(2, 0.0002);
    SigmaMstat->SetBinError(3, 0.0002);
    SigmaMstat->SetBinError(4, 0.0001);
    SigmaMstat->SetBinError(5, 0.0001);
    SigmaMstat->SetBinError(6, 0.00008);
    SigmaMstat->SetBinError(7, 0.00004);
    SigmaMstat->SetBinError(8, 0.00002);
    SigmaMstat->SetBinError(9, 0.000006);
    SigmaMstat->SetBinError(10,0.000002);
    
    
    TH1D *SigmaMsys = new TH1D("SigmaMsys","SigmaMsys", 10, pTbins);
    SigmaMsys->SetBinContent(1, 0.0071);
    SigmaMsys->SetBinContent(2, 0.0056);
    SigmaMsys->SetBinContent(3, 0.0051);
    SigmaMsys->SetBinContent(4, 0.0039);
    SigmaMsys->SetBinContent(5, 0.0031);
    SigmaMsys->SetBinContent(6, 0.0023);
    SigmaMsys->SetBinContent(7, 0.0013);
    SigmaMsys->SetBinContent(8, 7.2E-4);
    SigmaMsys->SetBinContent(9, 2.0E-4);
    SigmaMsys->SetBinContent(10, 3.2E-5);
    
    
    SigmaMsys->SetBinError(1, 0.0009);
    SigmaMsys->SetBinError(2, 0.0007);
    SigmaMsys->SetBinError(3, 0.0007);
    SigmaMsys->SetBinError(4, 0.0005);
    SigmaMsys->SetBinError(5, 0.0004);
    SigmaMsys->SetBinError(6, 0.00029);
    SigmaMsys->SetBinError(7, 0.00017);
    SigmaMsys->SetBinError(8, 0.00009);
    SigmaMsys->SetBinError(9, 0.000026);
    SigmaMsys->SetBinError(10,0.000004);
    
    //////////////////////////////// Anti sigma //////////////////////////////
    
    
    //SigmaStar +
    TH1D *Anti_SigmaPstat = new TH1D("Anti_SigmaPstat","Anti_SigmaPstat", 10, pTbins);
    Anti_SigmaPstat->SetBinContent(1, 0.0058);
    Anti_SigmaPstat->SetBinContent(2, 0.0055);
    Anti_SigmaPstat->SetBinContent(3, 0.004);
    Anti_SigmaPstat->SetBinContent(4, 0.0031);
    Anti_SigmaPstat->SetBinContent(5, 0.0025);
    Anti_SigmaPstat->SetBinContent(6, 0.0018);
    Anti_SigmaPstat->SetBinContent(7, 0.0013);
    Anti_SigmaPstat->SetBinContent(8, 5.9E-4);
    Anti_SigmaPstat->SetBinContent(9, 1.9E-4);
    Anti_SigmaPstat->SetBinContent(10, 3.2E-5);
    
    Anti_SigmaPstat->SetBinError(1, 0.0004);
    Anti_SigmaPstat->SetBinError(2, 0.0003);
    Anti_SigmaPstat->SetBinError(3, 0.0002);
    Anti_SigmaPstat->SetBinError(4, 0.00015);
    Anti_SigmaPstat->SetBinError(5, 0.00011);
    Anti_SigmaPstat->SetBinError(6, 0.00008);
    Anti_SigmaPstat->SetBinError(7, 0.00004);
    Anti_SigmaPstat->SetBinError(8, 0.00002);
    Anti_SigmaPstat->SetBinError(9, 0.000006);
    Anti_SigmaPstat->SetBinError(10,0.000002);
    
    
    
    
    TH1D *Anti_SigmaPsys = new TH1D("Anti_SigmaPsys","Anti_SigmaPsys", 10, pTbins);
    Anti_SigmaPsys->SetBinContent(1, 0.0058);
    Anti_SigmaPsys->SetBinContent(2, 0.0055);
    Anti_SigmaPsys->SetBinContent(3, 0.004);
    Anti_SigmaPsys->SetBinContent(4, 0.0031);
    Anti_SigmaPsys->SetBinContent(5, 0.0025);
    Anti_SigmaPsys->SetBinContent(6, 0.0018);
    Anti_SigmaPsys->SetBinContent(7, 0.0013);
    Anti_SigmaPsys->SetBinContent(8, 5.9E-4);
    Anti_SigmaPsys->SetBinContent(9, 1.9E-4);
    Anti_SigmaPsys->SetBinContent(10, 3.2E-5);
    
    Anti_SigmaPsys->SetBinError(1, 0.0006);
    Anti_SigmaPsys->SetBinError(2, 0.0007);
    Anti_SigmaPsys->SetBinError(3, 0.0004);
    Anti_SigmaPsys->SetBinError(4, 0.00031);
    Anti_SigmaPsys->SetBinError(5, 0.00028);
    Anti_SigmaPsys->SetBinError(6, 0.00018);
    Anti_SigmaPsys->SetBinError(7, 0.00013);
    Anti_SigmaPsys->SetBinError(8, 0.00007);
    Anti_SigmaPsys->SetBinError(9, 0.000024);
    Anti_SigmaPsys->SetBinError(10,0.000004);
    
    
    //Anti_SigmaStar -
    
    TH1D *Anti_SigmaMstat = new TH1D("Anti_SigmaMstat","Anti_SigmaMstat", 10, pTbins);
    Anti_SigmaMstat->SetBinContent(1, 0.0063);
    Anti_SigmaMstat->SetBinContent(2, 0.0054);
    Anti_SigmaMstat->SetBinContent(3, 0.0051);
    Anti_SigmaMstat->SetBinContent(4, 0.0038);
    Anti_SigmaMstat->SetBinContent(5, 0.003);
    Anti_SigmaMstat->SetBinContent(6, 0.0024);
    Anti_SigmaMstat->SetBinContent(7, 0.0013);
    Anti_SigmaMstat->SetBinContent(8, 6.2E-4);
    Anti_SigmaMstat->SetBinContent(9, 2.2E-4);
    Anti_SigmaMstat->SetBinContent(10, 2.8E-5);
    
    
    
    Anti_SigmaMstat->SetBinError(1, 0.0005);
    Anti_SigmaMstat->SetBinError(2, 0.0004);
    Anti_SigmaMstat->SetBinError(3, 0.0003);
    Anti_SigmaMstat->SetBinError(4, 0.0002);
    Anti_SigmaMstat->SetBinError(5, 0.0002);
    Anti_SigmaMstat->SetBinError(6, 0.00012);
    Anti_SigmaMstat->SetBinError(7, 0.00005);
    Anti_SigmaMstat->SetBinError(8, 0.00002);
    Anti_SigmaMstat->SetBinError(9, 0.000009);
    Anti_SigmaMstat->SetBinError(10,0.000002);
    
    
    TH1D *Anti_SigmaMsys = new TH1D("Anti_SigmaMsys","Anti_SigmaMsys", 10, pTbins);
    Anti_SigmaMsys->SetBinContent(1, 0.0063);
    Anti_SigmaMsys->SetBinContent(2, 0.0054);
    Anti_SigmaMsys->SetBinContent(3, 0.0051);
    Anti_SigmaMsys->SetBinContent(4, 0.0038);
    Anti_SigmaMsys->SetBinContent(5, 0.003);
    Anti_SigmaMsys->SetBinContent(6, 0.0024);
    Anti_SigmaMsys->SetBinContent(7, 0.0013);
    Anti_SigmaMsys->SetBinContent(8, 6.2E-4);
    Anti_SigmaMsys->SetBinContent(9, 2.2E-4);
    Anti_SigmaMsys->SetBinContent(10, 2.8E-5);
    
    
    
    Anti_SigmaMsys->SetBinError(1, 0.0011);
    Anti_SigmaMsys->SetBinError(2, 0.0008);
    Anti_SigmaMsys->SetBinError(3, 0.0008);
    Anti_SigmaMsys->SetBinError(4, 0.0006);
    Anti_SigmaMsys->SetBinError(5, 0.0005);
    Anti_SigmaMsys->SetBinError(6, 0.00038);
    Anti_SigmaMsys->SetBinError(7, 0.00019);
    Anti_SigmaMsys->SetBinError(8, 0.00011);
    Anti_SigmaMsys->SetBinError(9, 0.000035);
    Anti_SigmaMsys->SetBinError(10,0.000004);
    
    

    TFile *outputfile = new TFile("SigmaStar_Spectra.root", "RECREATE");
    SigmaPstat->Write("SigmaPstat");
    SigmaPsys->Write("SigmaPsys");
    
    SigmaMstat->Write("SigmaMstat");
    SigmaMsys->Write("SigmaMsys");
    
    Anti_SigmaPstat->Write("SigmaPstat");
    Anti_SigmaPsys->Write("SigmaPsys");
    
    Anti_SigmaMstat->Write("SigmaMstat");
    Anti_SigmaMsys->Write("SigmaMsys");

    

    
    
    
}
