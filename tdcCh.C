#include<iostream>
#include<fstream>
#include<TFile.h>
#include<TTree.h>
#include<TRoot.h>
#include<TCanvas.h>

int tdcCh(){
 
 TFile * f1=new TFile("../raw-ntup/moller_data_16018.root"); 
 TFile * f2=new TFile("../raw-ntup/moller_data_16013.root");
 TFile * f3=new TFile("../raw-ntup/moller_data_led_16023.root"); 
 TTree *tr1=(TTree*)f1->Get("h1");
 TTree *tr2=(TTree*)f2->Get("h1");
 TTree *tr3=(TTree*)f3->Get("h1"); 

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
   TH2F *h2=new TH2F("h2","Channel # vs TDC hits time",21*2,-.05,20.5,2001,-0.5,2000.5);

   TH1F *h3=new TH1F("h3","Channel # with hits",21,-0.5,20.5);
   TH1F *h4=new TH1F("h4","Channel # with hits",21,-0.5,20.5);
   TH1F *h5=new TH1F("h5","Channel # with hits",21,-0.5,20.5);   

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
   for (Int_t j=0;j<ntdc;j++)
     {
       h2->Fill(itch[j],itim[j]);
       h3->Fill(itch[j]);
     }
   }
  nentries=tr2->GetEntries();
   tr2->SetBranchAddress("irun", &irun, &b_irun);
   tr2->SetBranchAddress("idtyp", &idtyp, &b_idtyp);
   tr2->SetBranchAddress("ievtyp", &ievtyp, &b_ievtyp);
   tr2->SetBranchAddress("iret", &iret, &b_iret);
   tr2->SetBranchAddress("itrig", itrig, &b_itrig);
   tr2->SetBranchAddress("itick", &itick, &b_itick);
   tr2->SetBranchAddress("nadc", &nadc, &b_nadc);
   tr2->SetBranchAddress("iadc", iadc, &b_iadc);
   tr2->SetBranchAddress("ntdc", &ntdc, &b_ntdc);
   tr2->SetBranchAddress("itch", itch, &b_itch);
   tr2->SetBranchAddress("itim", itim, &b_itim);
   tr2->SetBranchAddress("ited", ited, &b_ited);
   tr2->SetBranchAddress("nhcha", &nhcha, &b_nhcha);
   tr2->SetBranchAddress("ihit", ihit, &b_ihit);
   tr2->SetBranchAddress("nsca", &nsca, &b_nsca);
   tr2->SetBranchAddress("isca", isca, &b_isca);



   
   for(Int_t i=0;i<nentries;i++){
   event[i]=i+1;
   tr2->GetEntry(i);
   for (Int_t j=0;j<ntdc;j++)
     {
              h4->Fill(itch[j]);

		}
   }
  nentries=tr3->GetEntries();
      tr3->SetBranchAddress("irun", &irun, &b_irun);
   tr3->SetBranchAddress("idtyp", &idtyp, &b_idtyp);
   tr3->SetBranchAddress("ievtyp", &ievtyp, &b_ievtyp);
   tr3->SetBranchAddress("iret", &iret, &b_iret);
   tr3->SetBranchAddress("itrig", itrig, &b_itrig);
   tr3->SetBranchAddress("itick", &itick, &b_itick);
   tr3->SetBranchAddress("nadc", &nadc, &b_nadc);
   tr3->SetBranchAddress("iadc", iadc, &b_iadc);
   tr3->SetBranchAddress("ntdc", &ntdc, &b_ntdc);
   tr3->SetBranchAddress("itch", itch, &b_itch);
   tr3->SetBranchAddress("itim", itim, &b_itim);
   tr3->SetBranchAddress("ited", ited, &b_ited);
   tr3->SetBranchAddress("nhcha", &nhcha, &b_nhcha);
   tr3->SetBranchAddress("ihit", ihit, &b_ihit);
   tr3->SetBranchAddress("nsca", &nsca, &b_nsca);
   tr3->SetBranchAddress("isca", isca, &b_isca);



   
   for(Int_t i=0;i<nentries;i++){
   event[i]=i+1;
   tr3->GetEntry(i);
   for (Int_t j=0;j<ntdc;j++)
     {
       h5->Fill(itch[j]);
		}
   }

   TCanvas *c1=new TCanvas("c1","Ticks vs Event#",0,0,600,800);

   h3->SetLineColor(kBlack);
   h4->SetLineColor(kRed);
   h5->SetLineColor(kBlue);   
   h3->Draw();

   //   h4->Draw("same");

   h5->Draw("same");   

   TLegend *leg=new TLegend();
   leg->AddEntry("h3","Data run","lp");
   //   leg->AddEntry("h4","Tune run","lp");
   leg->AddEntry("h5","LED run","lp");   
   leg->Draw();
  
  return 0;
}
