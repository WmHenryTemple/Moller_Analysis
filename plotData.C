void plotData(const char* filename){

 TFile * f1=new TFile(filename);
 TTree *tr1=(TTree*)f1->Get("h1");

  TCanvas *c1=new TCanvas("c1","RUN 1",0,0,450,250);
  c1->Divide(2,2);
  TCanvas *c2=new TCanvas("c2","RUN 2",450,0,700,250);
  c2->Divide(3,3);
  TCanvas *c3=new TCanvas("c3","ADC 1",1150,0,250,250);
  TCanvas *c4=new TCanvas("c4","ADC 2",0,300,650,250);
  c4->Divide(3,4);
  TCanvas *c5=new TCanvas("c5","TDC",650,300,500,250);
  c5->Divide(2,3);
  TCanvas *c6=new TCanvas("c6","SCAL 1",1150,300,250,250);
  c6->Divide(2,1);
  TCanvas *c7=new TCanvas("c7","SCAL 2",0,600,700,250);
  c7->Divide(4,4);
  TCanvas *c8=new TCanvas("c8","SCAL 3",700,600,700,250);
  c8->Divide(4,4);  

  //**********DRAW RUN BLOCK***********
  c1->cd(1);
  tr1->Draw("irun");
  c1->cd(2);
  tr1->Draw("idtyp");
  c1->cd(3);
  tr1->Draw("ievtyp");
  c1->cd(4);
  tr1->Draw("iret");  
  tr1->Draw("idtyp");
  char *name=new char[10];
  
  for(Int_t i=0;i<8;i++){
    sprintf(name,"itrig[%d]",i);
    c2->cd(i+1);
    tr1->Draw(name);
  }
  
  c2->cd(9);
  tr1->Draw("itick");
  
  //**********DRAW ADC BLOCK***********

  c3->cd();
  tr1->Draw("nadc");

  for(Int_t i=0;i<12;i++){
    sprintf(name,"iadc[%d]",i);
    c4->cd(i+1);
    tr1->Draw(name);
  }

  c5->cd(1);
  tr1->Draw("ntdc");
  c5->cd(2);
  tr1->Draw("itch");
  c5->cd(3);
  tr1->Draw("itim");
  c5->cd(4);
  tr1->Draw("ited");
  c5->cd(5);
  tr1->Draw("nhcha");
  c5->cd(6);
  tr1->Draw("ihit");  

  c6->cd(1);
  tr1->Draw("nsca");

  c6->cd(2);
  tr1->Draw("isca");  

  for(Int_t i=0;i<16;i++){
    sprintf(name,"isca[%d]",i);
    c7->cd(i+1);
    tr1->Draw(name);
  }

  for(Int_t i=16;i<32;i++){
    sprintf(name,"isca[%d]",i);
    c8->cd(i-15);
    tr1->Draw(name);
  }  


  return;
}
