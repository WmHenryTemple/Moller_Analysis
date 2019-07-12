#include<iostream>
#include<fstream>
#include<TFile.h>
#include<TTree.h>
#include<TRoot.h>
#include<TCanvas.h>

int tick(){
 
  // TFile * f1=new TFile("../raw-ntup/moller_data_16018.root");
 TFile * f1=new TFile("moller16700.root"); 
 TTree *tr1=(TTree*)f1->Get("h1");
 Int_t nentries=tr1->GetEntries();
 Int_t event[nentries];
 Int_t tick[nentries];
 // Declaration of leaf types
 UShort_t        irun;
 UChar_t         idtyp;
 UChar_t         ievtyp;
 Int_t           iret;
 UChar_t         itrig[8];
 Int_t           itick;
 Int_t           nadc;
 UShort_t        iadc[36];   //[nadc]
 Int_t           ntdc;
 UShort_t        itch[4096];   //[ntdc]
 UShort_t        itim[4096];   //[ntdc]
 UChar_t         ited[4096];   //[ntdc]
 Int_t           nhcha;
 UShort_t        ihit[10];   //[nhcha]
 Int_t           nsca;
 Int_t           isca[33];   //[nsca]

 // List of branches
 TBranch        *b_irun;   //!
 TBranch        *b_idtyp;   //!
 TBranch        *b_ievtyp;   //!
 TBranch        *b_iret;   //!
 TBranch        *b_itrig;   //!
 TBranch        *b_itick;   //!
 TBranch        *b_nadc;   //!
 TBranch        *b_iadc;   //!
 TBranch        *b_ntdc;   //!
 TBranch        *b_itch;   //!
 TBranch        *b_itim;   //!
 TBranch        *b_ited;   //!
 TBranch        *b_nhcha;   //!
 TBranch        *b_ihit;   //!
 TBranch        *b_nsca;   //!
 TBranch        *b_isca;   //!

    tr1->SetBranchAddress("irun", &irun, &b_irun);
   tr1->SetBranchAddress("idtyp", &idtyp, &b_idtyp);
   tr1->SetBranchAddress("ievtyp", &ievtyp, &b_ievtyp);
   tr1->SetBranchAddress("iret", &iret, &b_iret);
   tr1->SetBranchAddress("itrig", itrig, &b_itrig);
   tr1->SetBranchAddress("itick", &itick, &b_itick);
   tr1->SetBranchAddress("nadc", &nadc, &b_nadc);
   tr1->SetBranchAddress("iadc", iadc, &b_iadc);
   tr1->SetBranchAddress("ntdc", &ntdc, &b_ntdc);
   tr1->SetBranchAddress("itch", itch, &b_itch);
   tr1->SetBranchAddress("itim", itim, &b_itim);
   tr1->SetBranchAddress("ited", ited, &b_ited);
   tr1->SetBranchAddress("nhcha", &nhcha, &b_nhcha);
   tr1->SetBranchAddress("ihit", ihit, &b_ihit);
   tr1->SetBranchAddress("nsca", &nsca, &b_nsca);
   tr1->SetBranchAddress("isca", isca, &b_isca);
 
   for(Int_t i=0;i<nentries;i++){
   event[i]=i+1;
   tr1->GetEntry(i);
   tick[i]=itick;
   cout<<event[i]<<"\t"<<tick[i]<<endl;
   }
   cout << "Last tick minus first tick is "<<tick[nentries-1]-tick[0]<<endl;
  TCanvas *c1=new TCanvas("c1","Ticks vs Event#",0,0,600,800);
  TGraph *gr1=new TGraph(nentries,event,tick);
  gr1->Draw("ap");




  
  return 0;
}
