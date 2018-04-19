//
void RunRebin(){
    
    int Particle = 2;
    //0:pion
    //1:proton
    //2:sigma*
    
    
    if(Particle==0){
    TFile* f=TFile::Open("Light_Spectra.root");
    TH1D* hSpectrum_stat0 = (TH1D*)f->Get("Pion_AantiPion_stat");
    hSpectrum_stat0->Scale(0.5);
    
    TH1D* hSpectrum_sys0 = (TH1D*)f->Get("Pion_AantiPion_sys");
    hSpectrum_sys0->Scale(0.5);
    }
    else if(Particle==1){
        TFile* f=TFile::Open("Light_Spectra.root");
        TH1D* hSpectrum_stat0 = (TH1D*)f->Get("Proton_AntiProton_stat");
        hSpectrum_stat0->Scale(0.5);
        
        TH1D* hSpectrum_sys0 = (TH1D*)f->Get("Proton_AntiProton_sys");
        hSpectrum_sys0->Scale(0.5);
        
    }
    else if(Particle==2){
        TFile* f=TFile::Open("SigmaStar_Spectra.root");
        
        TH1D* hSpectrum_stat0 = (TH1D*)f->Get("SigmaPstat");
        TH1D* hSpectrum_stat1 = (TH1D*)f->Get("SigmaMstat");
        TH1D* hSpectrum_stat2 = (TH1D*)f->Get("Anti_SigmaPstat");
        TH1D* hSpectrum_stat3 = (TH1D*)f->Get("Anti_SigmaMstat");
        hSpectrum_stat0->Add(hSpectrum_stat1);
        hSpectrum_stat0->Add(hSpectrum_stat2);
        hSpectrum_stat0->Add(hSpectrum_stat3);
        hSpectrum_stat0->Scale(0.25);
        
        TH1D* hSpectrum_sys0 = (TH1D*)f->Get("SigmaPsys");
        TH1D* hSpectrum_sys1 = (TH1D*)f->Get("SigmaMsys");
        TH1D* hSpectrum_sys2 = (TH1D*)f->Get("Anti_SigmaPsys");
        TH1D* hSpectrum_sys3 = (TH1D*)f->Get("Anti_SigmaMsys");
        hSpectrum_sys0->Add(hSpectrum_sys1);
        hSpectrum_sys0->Add(hSpectrum_sys2);
        hSpectrum_sys0->Add(hSpectrum_sys3);
        hSpectrum_sys0->Scale(0.25);
        
        
    }
    
    TH1F* hi[1];
    hi[0] = (TH1F*)hSpectrum_stat0->Clone("hi[0]");
    hi[1] = (TH1F*)hSpectrum_sys0->Clone("hi[1]");

    int n=2;
    int dofit=1;

    int bin=8;
    double bins[9]={1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8};


    TH1F* ht=(TH1F*) hi[0]->Clone("ht");
    for(int j=1;j<=ht->GetNbinsX();j++) ht->SetBinError(j,sqrt(pow(hi[0]->GetBinError(j),2)+pow(hi[1]->GetBinError(j),2)));
        
    TH1F* hf[1];
    hf[0] = new TH1F("rebinned_stat","",bin,bins);
    hf[1] = new TH1F("rebinned_sys","",bin,bins);

    TF1* g=new TF1("fit","[0]*exp([1]*x)",0.,10.);
    g->SetParameters(1.,-1.);
    gROOT->LoadMacro("RebinSpectrum.C");
    RebinSpectrum(hi,hf,g,n,dofit,ht);
    
    Double_t xAxis1[10] = {0,1.1, 1.6, 2, 2.4, 2.8, 3.4, 4, 5, 8};
    TH1D *Spectrum_stat = new TH1D("Spectrum_stat","",9, xAxis1);
    TH1D *Spectrum_sys = new TH1D("Spectrum_sys","",9, xAxis1);

    for(int k=2; k<11; k++){
        Spectrum_stat->SetBinContent(k,hf[0]->GetBinContent(k-1));
        Spectrum_stat->SetBinError(k,hf[0]->GetBinError(k-1));
        
        Spectrum_sys->SetBinContent(k,hf[1]->GetBinContent(k-1));
        Spectrum_sys->SetBinError(k,hf[1]->GetBinError(k-1));
    }

    TFile *fileout = TFile::Open(Form("Spectrum_rebin%d.root",Particle),"RECREATE");
    hi[0]->Write("stat");
    hi[1]->Write("sys");
    hf[0]->Write("rebinned_stat");
    hf[1]->Write("rebinned_sys");
    Spectrum_stat->Write("Spectrum_stat");
    Spectrum_sys->Write("Spectrum_sys");
    fileout->Close();


    
    
}


