#include<iostream>
#include<fstream>
#include<TFile.h>
#include<TTree.h>
#include<TRoot.h>
#include<TCanvas.h>

int scalarDiff(){
 
 TFile * f1=new TFile("../raw-ntup/moller_data_16018.root");
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
   TH1F *myhist[16];
   myhist[0] = new TH1F("h01","Scalar Increments",10001,-0.5,10000.5);
   myhist[1] = new TH1F("h02","Scalar Increments",10001,-0.5,10000.5);
   myhist[2] = new TH1F("h03","Scalar Increments",10001,-0.5,10000.5);
   myhist[3] = new TH1F("h04","Scalar Increments",10001,-0.5,10000.5);
   myhist[4] = new TH1F("h05","Scalar Increments",10001,-0.5,10000.5);
   myhist[5] = new TH1F("h06","Scalar Increments",10001,-0.5,10000.5);
   myhist[6] = new TH1F("h07","Scalar Increments",10001,-0.5,10000.5);
   myhist[7] = new TH1F("h08","Scalar Increments",10001,-0.5,10000.5);
   myhist[8] = new TH1F("h09","Scalar Increments",10001,-0.5,10000.5);
   myhist[9] = new TH1F("h010","Scalar Increments",10001,-0.5,10000.5);
   myhist[10] = new TH1F("h011","Scalar Increments",10001,-0.5,10000.5);
   myhist[11] = new TH1F("h012","Scalar Increments",10001,-0.5,10000.5);
   myhist[12] = new TH1F("h013","Scalar Increments",10001,-0.5,10000.5);
   myhist[13] = new TH1F("h014","Scalar Increments",10001,-0.5,10000.5);
   myhist[14] = new TH1F("h015","Scalar Increments",10001,-0.5,10000.5);
   myhist[15] = new TH1F("h016","Scalar Increments",10001,-0.5,10000.5);
   
   
   
   Int_t jcdiff[16];
   Int_t jcprev[16];   
   Int_t ncyc=0;
   Int_t cntr=0;
   char *name=new char[10];
   
   for(Int_t i=0;i<nentries;i++){

     tr1->GetEntry(i);

     for(Int_t j=0;j<16;j++){

     jcdiff[j]=isca[j]-jcprev[j];
     jcprev[j]=isca[j];

     if(jcdiff[j] != 0){
     cout << j << "\t Diff: " << jcdiff[j] << endl;
     myhist[j]->Fill(jcdiff[j]);
     }
     
     }
       event[i]=i+1;
       tick[i]=itick;

   }
   //	 asym=(Float_t)num/denom;
   //	 cout <<num<<"   "<<denom<< "   The asymmetry is:"<<asym<<endl;
   cout<<"number of cycles"<<ncyc<<endl;
   cout << "Last tick minus first tick is "<<tick[nentries-1]-tick[0]<<endl;
  TCanvas *c1=new TCanvas("c1","Ticks vs Event#",0,0,600,800);
  TGraph *gr1=new TGraph(nentries,event,tick);
   
  c1->Divide(3,4);
  c1->cd(1);
  myhist[0]->Draw();
  c1->cd(2);
  myhist[1]->Draw();
  c1->cd(3);
  myhist[2]->Draw();
  c1->cd(4);
  myhist[3]->Draw();
  c1->cd(5);
  myhist[4]->Draw();
  c1->cd(6);
  myhist[5]->Draw();
  c1->cd(7);
  myhist[9]->Draw();
  c1->cd(8);
  myhist[10]->Draw();
  c1->cd(9);
  myhist[11]->Draw();
  c1->cd(10);
  myhist[14]->Draw();  
  return 0;
}
