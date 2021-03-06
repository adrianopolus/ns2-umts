/***********************************************************/
/*   Bypass.c  - contains the functions for the    */
/*                  physical layer.                        */
/***********************************************************/

#include "physic.h"


void Interference2::Bypass(physical_layer *PHY, char *packet,double **interface_pt)
{
  int i;
  double Ebno,p,rn;
  double BER[21]={3.09e-1, 2.90e-1, 2.48e-1, 2.19e-1, 1.82e-1, 1.46e-1, 1.07e-1, 8.81e-2, 5.61e-2, 4.84e-2,
		  3.15e-2, 2.47e-2, 1.14e-2, 8.59e-3, 5.38e-3, 2.49e-3, 1.06e-3, 4.17e-4, 1.05e-4, 2.44e-5,
		  1.28e-6};

  

  Ebno=-10*log10(2*PHY->n0/Ns);

  if(Ebno<=20)
    {
      p=BER[(int)Ebno];
      for(i=0;i<interface_pt[1][0];i++)
	{
	  rn= Uniform(PHY);
	  if(rn<p)
	    packet[i]=1-packet[i];
	}//for(i=0;i<interface_pt[1][0];i++){
    }// if(Ebno<=20){

  
}


void 	Interference2::Bypass_VTB(physical_layer *PHY, char *packet,double **interface_pt)
{
  int i;
  double Ebno,p,rn;
  double BER[21]={3.09e-1, 2.90e-1, 2.48e-1, 2.19e-1, 1.82e-1, 1.46e-1, 1.07e-1, 8.81e-2, 5.61e-2, 4.84e-2,
		  3.15e-2, 2.47e-2, 1.14e-2, 8.59e-3, 5.38e-3, 2.49e-3, 1.06e-3, 4.17e-4, 1.05e-4, 2.44e-5,
		  1.28e-6};
  
  
  
  Ebno=-10*log10(2*PHY->n0/Ns);

  if(Ebno<=20)
    {
      p=BER[(int)Ebno];

      for(i=0;i<interface_pt[1][0];i++)
	{
	  rn= Uniform(PHY);
	  if(rn<p)
	    packet[i]=1-packet[i];
	}//for(i=0;i<interface_pt[1][0];i++){
    }// if(Ebno<=20){


}



void 	Interference2::wBypass(physical_layer *PHY, char *packet,double **interface_pt)
{
  int i;
  double Ebno,p,rn;
  double BER[12]={1.86e-1, 1.40e-1, 1.0e-1, 6.79e-2, 4.32e-2, 2.16e-2, 9.37e-3, 3.21e-3, 9.09e-4, 1.77e-4,
		  2.26e-5, 1.47e-6};

  
  Ebno=-10*log10(2*PHY->n0/Ns);

  if(Ebno<=11)
    {
      p=BER[(int)Ebno];

      for(i=0;i<interface_pt[1][0];i++)
	{
	  rn= Uniform(PHY);;
	  if(rn<p)
	    packet[i]=1-packet[i];
	}//for(i=0;i<interface_pt[1][0];i++){
    }// if(Ebno<=11){


}


void 	Interference2::w11Bypass(physical_layer *PHY, char *packet,double **interface_pt)
{
  int i;
  double Ebno,p,rn,packetbuf;
  double BER[11]={1.69e-1, 1.19e-1, 7.58e-2, 4.08e-2, 2.03e-2, 7.71e-3, 3.03e-3, 9.09e-4, 1.51-4,
		  1.776e-5, 1.30e-6};
  
 
  Ebno=-10*log10(2*PHY->n0/Ns);

  packetbuf=interface_pt[1][0];
  interface_pt[1][0]=224;
  wBypass(PHY, packet, interface_pt); 
  interface_pt[1][0]=packetbuf;

  if(Ebno<=10)
    {
      p=BER[(int)Ebno];

      for(i=224*11;i<interface_pt[1][0]*11;i++)
	{
	  rn= Uniform(PHY);;
	  if(rn<p)
	    packet[i-224*10]=1-packet[i-224*10];
	}//for(i=0;i<interface_pt[1][0];i++){
    }// if(Ebno<=11){


}


void 	Interference2::IntBypassB(physical_layer *PHY, char *packet,double **interface_pt,int collision_number)
{
  int i,n,index;
  double d2,lp,pr2,pt2,CAIRdb,p,rn,df;

  double BER0[17]={2.5e-1, 1e-1, 7.9e-2, 6e-2, 3.8e-2, 2e-2, 1.7e-2, 8e-3, 1.42e-3,5e-4,0};

  double BER1[17]={3.0e-1, 2e-1, 2.3e-1, 2e-1, 1.0e-1, 8e-2, 4.7e-2, 3e-2, 2.32e-2, 1e-2, 8e-3, 5e-3, 5e-4,0};
				
  double BER2[17]={3.0e-1, 2.8e-1, 2.0e-1, 1.2e-1, 1.0e-1, 8e-2, 5.7e-2, 4e-2, 2.70e-2, 1e-2, 9e-3, 5e-3, 5.7e-4,0};

  double BER3[21]={3.6e-1, 3e-1, 3.0e-1, 3e-1, 2.5e-1, 2e-1, 1.7e-1, 1e-1, 9.80e-2, 7e-2, 6e-2, 5e-2, 3.0e-2, 2e-2, 1.1e-2, 7e-3, 5.5e-3, 3e-3, 1e-3,5e-4,0};

  double wBER0[350]={3.69e-001, 3.56e-001, 3.74e-001, 3.20e-001, 3.01e-001, 2.90e-001, 2.58e-001, 2.91e-001, 2.53e-001, 2.49e-001, 2.35e-001, 1.93e-001, 1.77e-001, 1.98e-001, 1.90e-001, 1.78e-001, 1.69e-001, 1.52e-001, 1.32e-001, 1.23e-001, 1.14e-001, 1.00e-001, 9.35e-002, 8.34e-002, 7.61e-002, 6.84e-002, 6.27e-002, 5.49e-002, 4.42e-002, 3.95e-002, 3.39e-002, 3.04e-002, 2.66e-002, 2.21e-002, 1.73e-002, 1.30e-002, 1.06e-002, 8.27e-003, 6.64e-003, 5.96e-003, 5.34e-003, 4.69e-003, 3.43e-003, 1.28e-003, 3.99e-004, 0.00e+000
		     /*46*/	  ,4.11e-001, 4.24e-001, 4.17e-001, 3.99e-001, 4.08e-001, 3.72e-001, 3.77e-001, 3.54e-001, 3.51e-001, 3.34e-001, 2.96e-001, 3.04e-001, 2.73e-001, 2.45e-001, 2.23e-001, 1.90e-001, 1.75e-001, 1.64e-001, 1.42e-001, 1.34e-001, 1.23e-001, 1.19e-001, 1.09e-001, 1.05e-001, 9.62e-002, 8.59e-002, 7.86e-002, 7.25e-002, 6.16e-002, 5.58e-002, 5.03e-002, 4.48e-002, 3.95e-002, 3.23e-002, 2.61e-002, 2.09e-002, 1.75e-002, 1.57e-002, 1.31e-002, 1.06e-002, 9.84e-003, 7.59e-003, 4.93e-003, 2.05e-003, 7.40e-004, 0.00e+000
		     /*92*/	  ,3.82e-001, 3.85e-001, 3.61e-001, 3.48e-001, 3.62e-001, 3.32e-001, 3.11e-001, 3.19e-001, 2.91e-001, 2.84e-001, 2.65e-001, 2.84e-001, 2.71e-001, 2.33e-001, 2.13e-001, 1.99e-001, 1.81e-001, 1.58e-001, 1.37e-001, 1.28e-001, 1.18e-001, 1.17e-001, 1.08e-001, 9.95e-002, 9.09e-002, 8.28e-002, 7.69e-002, 7.02e-002, 6.24e-002, 5.28e-002, 4.69e-002, 4.19e-002, 3.77e-002, 3.10e-002, 2.57e-002, 2.05e-002, 1.83e-002, 1.58e-002, 1.39e-002, 1.02e-002, 8.28e-003, 6.79e-003, 5.51e-003, 3.24e-003, 1.62e-005, 0.00e+000
		     /*138*/	  ,4.05e-001, 4.22e-001, 3.57e-001, 3.87e-001, 3.88e-001, 4.12e-001, 3.42e-001, 3.42e-001, 3.28e-001, 3.23e-001, 2.89e-001, 2.51e-001, 2.48e-001, 2.21e-001, 1.95e-001, 1.79e-001, 1.61e-001, 1.45e-001, 1.35e-001, 1.27e-001, 1.18e-001, 1.11e-001, 1.05e-001, 9.28e-002, 8.76e-002, 7.87e-002, 6.98e-002, 6.27e-002, 5.50e-002, 4.83e-002, 4.26e-002, 3.61e-002, 2.66e-002, 2.27e-002, 1.89e-002, 1.66e-002, 1.47e-002, 1.20e-002, 1.04e-002, 8.63e-003, 5.49e-003, 3.03e-003, 1.11e-003, 1.30e-004, 0.00e+000, 0.00e+000
		     /*184*/	  ,3.74e-001, 3.62e-001, 3.38e-001, 3.44e-001, 3.06e-001, 2.80e-001, 2.89e-001, 2.54e-001, 2.42e-001, 2.58e-001, 2.59e-001, 2.34e-001, 2.42e-001, 1.93e-001, 1.76e-001, 1.54e-001, 1.30e-001, 1.23e-001, 1.19e-001, 1.08e-001, 1.04e-001, 9.54e-002, 8.89e-002, 7.93e-002, 7.25e-002, 6.60e-002, 6.01e-002, 5.09e-002, 4.52e-002, 3.95e-002, 3.37e-002, 2.91e-002, 2.28e-002, 1.88e-002, 1.67e-002, 1.54e-002, 1.26e-002, 1.04e-002, 7.28e-003, 6.33e-003, 4.81e-003, 2.66e-003, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000
		     /*230*/	  ,4.03e-001, 3.97e-001, 3.87e-001, 3.41e-001, 3.41e-001, 3.22e-001, 3.02e-001, 2.57e-001, 2.29e-001, 2.06e-001, 2.00e-001, 1.74e-001, 1.68e-001, 1.48e-001, 1.36e-001, 1.25e-001, 1.12e-001, 9.77e-002, 8.53e-002, 7.73e-002, 6.81e-002, 5.89e-002, 5.03e-002, 4.21e-002, 3.45e-002, 2.93e-002, 2.43e-002, 2.06e-002, 1.68e-002, 1.42e-002, 1.07e-002, 7.88e-003, 4.42e-003, 4.06e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000
		     /*276*/	  ,3.70e-001, 3.29e-001, 3.23e-001, 2.95e-001, 2.64e-001, 2.34e-001, 2.29e-001, 2.01e-001, 1.70e-001, 1.54e-001, 1.49e-001, 1.38e-001, 1.17e-001, 1.07e-001, 9.39e-002, 8.20e-002, 7.34e-002, 6.47e-002, 5.56e-002, 4.35e-002, 3.43e-002, 2.90e-002, 2.50e-002, 2.17e-002, 1.87e-002, 1.63e-002, 1.24e-002, 9.69e-003, 5.93e-003, 1.99e-003, 4.55e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};

  double wBER7[150]={3.95e-001, 3.94e-001, 3.79e-001, 3.77e-001, 3.50e-001, 3.37e-001, 3.31e-001, 3.31e-001, 3.20e-001, 3.13e-001, 3.01e-001, 2.93e-001, 2.78e-001, 2.65e-001, 2.50e-001, 2.35e-001, 2.20e-001, 2.03e-001, 1.89e-001, 1.71e-001, 1.40e-001, 1.31e-001, 1.23e-001, 1.11e-001, 1.05e-001, 9.99e-002, 9.17e-002, 8.52e-002, 7.93e-002, 6.98e-002, 5.99e-002, 5.54e-002, 5.04e-002, 4.46e-002, 3.93e-002, 3.23e-002, 2.57e-002, 2.01e-002, 1.62e-002, 1.40e-002, 1.37e-002, 1.17e-002, 9.76e-003, 8.16e-003, 5.37e-003, 2.80e-003, 1.40e-003, 0.00e+000, 0.00e+000, 0.00e+000
		     /*50*/	  ,4.16e-001, 3.92e-001, 4.02e-001, 3.68e-001, 3.87e-001, 3.66e-001, 3.41e-001, 3.29e-001, 2.97e-001, 2.78e-001, 2.61e-001, 2.39e-001, 2.12e-001, 1.81e-001, 1.71e-001, 1.54e-001, 1.42e-001, 1.30e-001, 1.23e-001, 1.13e-001, 1.06e-001, 9.91e-002, 8.67e-002, 8.38e-002, 7.46e-002, 6.75e-002, 5.87e-002, 4.80e-002, 4.25e-002, 3.95e-002, 3.37e-002, 2.73e-002, 2.17e-002, 1.84e-002, 1.64e-002, 1.34e-002, 1.08e-002, 8.13e-003, 6.38e-003, 5.41e-003, 3.36e-003, 6.36e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000
		     /*100*/	  ,3.12e-001, 2.71e-001, 2.56e-001, 2.49e-001, 2.38e-001, 2.28e-001, 1.95e-001, 1.72e-001, 1.48e-001, 1.38e-001, 1.31e-001, 1.24e-001, 1.15e-001, 1.06e-001, 9.95e-002, 9.06e-002, 8.70e-002, 7.91e-002, 6.83e-002, 5.73e-002, 5.01e-002, 4.51e-002, 3.83e-002, 3.23e-002, 2.58e-002, 2.17e-002, 1.88e-002, 1.65e-002, 1.42e-002, 1.06e-002, 8.77e-003, 6.91e-003, 6.14e-003, 2.86e-003, 1.30e-005, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};

  double wBER10[50]={3.52e-001, 3.40e-001, 3.19e-001, 3.07e-001, 2.99e-001, 2.85e-001, 2.86e-001, 2.62e-001, 2.49e-001, 2.24e-001, 2.13e-001, 1.94e-001, 1.67e-001, 1.43e-001, 1.42e-001, 1.25e-001, 1.22e-001, 1.15e-001, 1.06e-001, 9.68e-002, 9.16e-002, 8.45e-002, 7.45e-002, 6.33e-002, 5.68e-002, 5.11e-002, 4.54e-002, 3.92e-002, 3.34e-002, 2.59e-002, 1.92e-002, 1.82e-002, 1.49e-002, 1.31e-002, 1.10e-002, 9.44e-003, 7.47e-003, 6.00e-003, 2.58e-003, 5.03e-004, 0.00e+000};

  double wBER11[50]={2.78e-001, 2.45e-001, 2.26e-001, 2.02e-001, 1.87e-001, 1.75e-001, 1.65e-001, 1.55e-001, 1.54e-001, 1.34e-001, 1.21e-001, 1.19e-001, 1.05e-001, 9.28e-002, 8.11e-002, 7.15e-002, 6.37e-002, 5.67e-002, 4.68e-002, 3.89e-002, 3.18e-002, 2.71e-002, 2.40e-002, 2.02e-002, 1.64e-002, 1.28e-002, 9.83e-003, 7.57e-003, 4.76e-003, 1.76e-003, 0.00e+000 };

    
  for(n=0;n<interface_pt[1][0] ; n++)
    {			
      for(i=1;i<= collision_number;i++)
	{
	  if ( (interface_pt[0][i]<=n) && (n< (interface_pt[0][i]+interface_pt[1][i])) )
	    {
	      d2=interface_pt[5][i];
	      pt2 = 1e-3*interface_pt[3][i];

	      if (d2<=8)
		lp= 32.45+20*log10(2.4*d2);
	      else if (d2>8)
		lp= 58.3+33*log10(d2/8.);

	      pr2 = 10*log10(pt2)-lp;
	      CAIRdb= 10*log10(PHY->pr1)-pr2;

	      if((interface_pt[2][i] == 1.)||(interface_pt[2][i] == 4.))
		{
		  df = interface_pt[4][0] - interface_pt[4][i];

		  if (df<0)
		    df=-df;
		  if (df==0)
		    {
		      if(CAIRdb<0)
			CAIRdb=0;
		      if(CAIRdb>=10)
			CAIRdb=10;

		      index=(int)(CAIRdb+.5);
		      p=BER0[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==0){*/
		  if (df==1)
		    {
		      if(CAIRdb<-12)
			CAIRdb=-12;
		      if(CAIRdb>=1)
			CAIRdb=1;

		      index=(int)(CAIRdb+12+.5);
		      p=BER1[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==1){*/
		  if (df==2)
		    {
		      if(CAIRdb<-44)
			CAIRdb=-44;
		      if(CAIRdb>=-31)
			CAIRdb=-31;

		      index=(int)(CAIRdb+44+.5);
		      p=BER2[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		  if (df==3)
		    {
		      if(CAIRdb<-80)
			CAIRdb=-80;
		      if(CAIRdb>=-60)
			CAIRdb=-60;

		      index=(int)(CAIRdb+80+.5);
		      p=BER3[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==3){*/				
		}/*end if*/
	      else if ((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.))
		{
		  df = interface_pt[4][0] - interface_pt[4][i];

		  if (df<0)
		    df=-df;
		  if ((df>=0)&&(df<=6))
		    {
		      if(CAIRdb<-16)
			CAIRdb=-16;
		      if(CAIRdb>=6.5)
			CAIRdb=6.5;

		      index=(int)(2*(CAIRdb+16))+(int)(df*46);
		      p=wBER0[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==0){*/
		  if ((df>=7)&&(df<=9))
		    {
		      if(CAIRdb<-22)
			CAIRdb=-22;
		      if(CAIRdb>=2.5)
			CAIRdb=2.5;

		      index=(int)(2*(CAIRdb+22))+(int)((df-7)*50);
		      p=wBER7[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		  if (df==10)
		    {
		      if(CAIRdb<-30)
			CAIRdb=-30;
		      if(CAIRdb>=-10)
			CAIRdb=-10;

		      index=(int)(2*(CAIRdb+30));
		      p=wBER10[index];
		      rn=rand()/(double)RAND_MAX;

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		  if (df==11)
		    {
		      if(CAIRdb<-36)
			CAIRdb=-36;
		      if(CAIRdb>=-21)
			CAIRdb=-21;

		      index=(int)(2*(CAIRdb+36));
		      p=wBER11[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		}/* end else if*/
	    }/* end if*/
	}/*	for(i=1;i<= intcollision_number;i++){*/
    }/*for(n=0;n<interface_pt[1][0] ; n++) {*/
	

}


void 	Interference2::IntBypassB_VTB(physical_layer *PHY, char *packet,double **interface_pt,int collision_number)
{
  int i,n,index;
  double d2,lp,pr2,pt2,CAIRdb,p,rn,df;

  double wBER0[350]={3.32e-001, 3.23e-001, 3.21e-001, 3.13e-001, 3.12e-001, 2.91e-001, 2.74e-001, 2.63e-001, 2.52e-001, 1.99e-001, 1.61e-001, 9.52e-002, 3.38e-002, 9.67e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*22*/            ,5.00e-001, 4.99e-001, 5.00e-001, 5.00e-001, 5.01e-001, 5.09e-001, 5.01e-001, 5.04e-001, 4.95e-001, 4.91e-001, 4.71e-001, 4.65e-001, 4.41e-001, 4.02e-001, 3.41e-001, 2.46e-001, 1.43e-001, 5.74e-002, 7.30e-003, 2.60e-004, 0.00e+000, 0.00e+000 
		     /*44*/            ,4.93e-001, 5.04e-001, 4.94e-001, 4.97e-001, 5.00e-001, 4.96e-001, 5.00e-001, 5.07e-001, 4.97e-001, 4.93e-001, 4.84e-001, 4.73e-001, 4.48e-001, 4.08e-001, 3.46e-001, 2.55e-001, 1.54e-001, 5.64e-002, 1.53e-002, 1.09e-003, 0.00e+000, 0.00e+000
		     /*66*/            ,3.65e-001, 3.75e-001, 3.52e-001, 3.49e-001, 3.53e-001, 3.30e-001, 3.28e-001, 3.20e-001, 3.14e-001, 2.83e-001, 2.73e-001, 2.50e-001, 1.98e-001, 1.27e-001, 6.03e-002, 1.67e-002, 2.11e-003, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*88*/            ,5.09e-001, 4.97e-001, 5.04e-001, 5.04e-001, 4.80e-001, 4.69e-001, 4.48e-001, 4.07e-001, 3.45e-001, 2.65e-001, 1.57e-001, 6.49e-002, 1.81e-002, 2.97e-003, 7.94e-005, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*110*/           ,4.93e-001, 4.86e-001, 4.89e-001, 4.72e-001, 4.59e-001, 4.42e-001, 4.02e-001, 3.70e-001, 3.18e-001, 2.83e-001, 2.48e-001, 1.97e-001, 1.28e-001, 5.58e-002, 1.48e-002, 1.75e-003, 1.44e-005, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*132*/           ,4.69e-001, 4.62e-001, 4.53e-001, 4.30e-001, 3.97e-001, 3.58e-001, 3.29e-001, 3.01e-001, 2.86e-001, 2.63e-001, 2.19e-001, 1.62e-001, 9.04e-002, 3.01e-002, 5.79e-003, 5.63e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000
		     /*154*/           ,4.85e-001, 4.73e-001, 4.60e-001, 4.29e-001, 3.80e-001, 2.96e-001, 1.97e-001, 9.28e-002, 2.90e-002, 6.25e-003, 2.45e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*176*/           ,3.11e-001, 3.00e-001, 2.85e-001, 2.63e-001, 2.31e-001, 1.75e-001, 1.00e-001, 3.54e-002, 8.30e-003, 5.77e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*198*/           ,4.59e-001, 4.33e-001, 3.89e-001, 3.19e-001, 2.25e-001, 1.26e-001, 3.95e-002, 7.14e-003, 4.04e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000 
		     /*220*/           ,1.34e-001, 4.63e-002, 1.15e-002, 9.74e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};


    
  for(n=0;n<interface_pt[1][0] ; n++)
    {
      for(i=1;i<= collision_number;i++)
	{
	  if ( (interface_pt[0][i]<=n) && (n< (interface_pt[0][i]+interface_pt[1][i])) )
	    {
	      d2=interface_pt[5][i];
	      pt2 = 1e-3*interface_pt[3][i];

	      if (d2<=8)
		lp= 32.45+20*log10(2.4*d2);
	      else if (d2>8)
		lp= 58.3+33*log10(d2/8.);

	      pr2 = 10*log10(pt2)-lp;
	      CAIRdb= 10*log10(PHY->pr1)-pr2;

	      if (n == 0) printf("CAIRdb = %f\n",CAIRdb);

	      if ((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.))
		{
		  df = interface_pt[4][0] - interface_pt[4][i];

		  if (df<0)
		    df=-df;
		  if ((df>=0)&&(df<=10))
		    {
		      if(CAIRdb<-22)
			CAIRdb=-22;
		      if(CAIRdb>=-2)
			CAIRdb=-2;

		      index=(int)(CAIRdb+22.5)+(int)(df*22);
		      p=wBER0[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*end if if ((df>=0)&&(df<=10)){*/
		}/* end if ((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.)){*/
	    }/* end if ( (interface_pt[0][i]<=n) && (n< (interface_pt[0][i]+interface_pt[1][i])) ){*/
	}/*	for(i=1;i<= intcollision_number;i++){*/
    }/*for(n=0;n<interface_pt[1][0] ; n++) {*/
		
}

 
double  Interference2::Uniform( physical_layer *PHY)
{
  double m1;
  
  
  PHY->x1 = (171 *  PHY->x1)%30269;
  PHY->x2 = (172 *  PHY->x2)%30307;
  PHY->x3 = (170 *  PHY->x3)%30323;
  m1 = fmod( ((double)(PHY->x1)/30269. + (double)(PHY->x2)/30307. + (double)(PHY->x3)/30323.), 1.);

  return (m1);
}  /* end  */


void 	Interference2::IntBypassW(physical_layer *PHY, char *packet,double **interface_pt,int collision_number) 
{
  int i,n,index;
  double d2,lp,pr2,pt2,CAIRdb,p,rn,df;

  double BER0[150]={	3.56e-001, 3.31e-001, 2.86e-001, 2.58e-001, 2.06e-001, 1.41e-001, 8.27e-002, 2.21e-002, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,	
			/*18*/		5.00e-001, 5.05e-001, 4.98e-001, 4.77e-001, 4.67e-001, 4.50e-001, 4.40e-001, 4.23e-001, 4.07e-001, 3.60e-001, 3.03e-001, 2.12e-001, 1.28e-001, 4.69e-002, 6.09e-003, 0.00e+000, 0.00e+000, 0.00e+000,
			/*36*/		4.90e-001, 4.91e-001, 4.85e-001, 4.75e-001, 4.61e-001, 4.47e-001, 4.32e-001, 4.12e-001, 3.71e-001, 3.28e-001, 2.50e-001, 1.61e-001, 7.46e-002, 1.25e-002, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
			/*54*/		4.93e-001, 4.87e-001, 4.67e-001, 4.53e-001, 4.53e-001, 4.27e-001, 4.10e-001, 3.73e-001, 3.26e-001, 2.40e-001, 1.53e-001, 7.07e-002, 1.57e-002, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
			/*72*/		4.83e-001, 4.69e-001, 4.63e-001, 4.44e-001, 4.20e-001, 3.94e-001, 3.50e-001, 2.96e-001, 1.94e-001, 1.10e-001, 3.54e-002, 1.73e-003, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
			/*90*/		4.56e-001, 4.40e-001, 4.18e-001, 3.90e-001, 3.19e-001, 2.51e-001, 1.58e-001, 6.89e-002, 4.16e-002, 1.39e-002, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
			/*108*/		4.02e-001, 3.65e-001, 2.78e-001, 1.81e-001, 6.96e-002, 2.97e-002, 5.81e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};

  double BER7[50]={ 5.06e-001, 4.93e-001, 4.77e-001, 4.63e-001, 4.41e-001, 4.37e-001, 4.07e-001, 3.73e-001, 3.23e-001, 2.49e-001, 1.59e-001, 6.95e-002, 8.56e-003, 0.00e+000, 0.00e+000, 0.00e+000,
		    /*17*/			  4.31e-001, 4.07e-001, 3.68e-001, 3.19e-001, 2.47e-001, 1.70e-001, 7.04e-002, 2.33e-002, 7.14e-005, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};


  double BER9[50]={4.81e-001, 4.66e-001, 4.52e-001, 4.35e-001, 3.99e-001, 3.65e-001, 3.03e-001, 2.44e-001, 1.71e-001, 6.56e-002, 3.34e-002, 1.92e-003, 0.00e+000, 0.00e+000};

  double wwBER[17]={	8.0e-002, 7.70e-002, 7.50e-002, 7.00e-002, 6.90e-002, 6.70e-002, 6.57e-002,  6.40e-002, 6.20e-002, 5.50e-002, 5.200e-002, 4.90e-002, 3.70e-002, 3.57e-002, 2.00e-002, 1.08e-002, 0};

  
 

  for(n=0;n<interface_pt[1][0] ; n++)
    {
      for(i=1;i<= collision_number;i++)
	{
	  if ( (interface_pt[0][i]<=n) && (n< (interface_pt[0][i]+interface_pt[1][i])) )
	    {
	      d2=interface_pt[5][i];
	      pt2 = 1e-3*interface_pt[3][i];

	      if (d2<=8)
		lp= 32.45+20*log10(2.4*d2);
	      else if (d2>8)
		lp= 58.3+33*log10(d2/8.);

	      pr2 = 10*log10(pt2)-lp;
	      CAIRdb= 10*log10(PHY->pr1)-pr2;
	      df = interface_pt[4][0] - interface_pt[4][i];

	      if (df<0)
		df=-df;
	      if((interface_pt[2][i] == 1.)||(interface_pt[2][i] == 4.))
		{
		  if ((df>=0)&&(df<=6))
		    {
		      if(CAIRdb<-19)
			CAIRdb=-19;
		      if(CAIRdb>=-2)
			CAIRdb=-2;

		      index=(int)(CAIRdb+19+.5)+(int)(df*18);
		      p=BER0[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==0){*/
		  if ((df>=7)&&(df<=8))
		    {
		      if(CAIRdb<-29)
			CAIRdb=-29;
		      if(CAIRdb>=-14)
			CAIRdb=-14;

		      index=(int)(CAIRdb+29+.5)+(int)((df-7)*17);
		      p=BER7[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		  if (df==9)
		    {
		      if(CAIRdb<-39)
			CAIRdb=-39;
		      if(CAIRdb>=-26)
			CAIRdb=-26;

		      index=(int)(CAIRdb+39+.5);
		      p=BER9[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n]=1-packet[n];
		    }/*if (df==2){*/
		}/*if((interface_pt[2][i] == 1.)||(interface_pt[2][i] == 4.)){*/
	      if((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.))
		{
		  if(CAIRdb<-15)
		    CAIRdb=-15;
		  if(CAIRdb>=1)
		    CAIRdb=1;

		  index=(int)(CAIRdb+15.5);
		  p=wwBER[index];
		  rn= Uniform(PHY);

		  if(rn<p)
		    packet[n]=1-packet[n];
		}/*	if((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.)){*/
	    }/* end if*/
	}/*	for(i=1;i<= intcollision_number;i++){*/
    }/*for(n=0;n<interface_pt[1][0] ; n++) {*/
		

}


void 	Interference2::IntBypassW11(physical_layer *PHY, char *packet,double **interface_pt,int collision_number)
{
  int i,n,index;
  double d2,lp,pr2,pt2,CAIRdb,p,rn,df;
  double packetbuf;

  double w11BER0[150]={3.63e-001, 3.64e-001, 3.47e-001, 3.43e-001, 3.23e-001, 3.03e-001, 2.84e-001, 2.64e-001, 2.49e-001, 2.31e-001, 2.15e-001, 1.91e-001, 1.66e-001, 1.32e-001, 9.13e-002, 6.17e-002, 3.73e-002, 2.11e-002, 2.43e-003, 0.00e+000, 0.00e+000, 
		       /*21*/	   3.70e-001, 3.59e-001, 3.42e-001, 3.34e-001, 3.18e-001, 3.07e-001, 2.92e-001, 2.68e-001, 2.49e-001, 2.27e-001, 2.06e-001, 1.86e-001, 1.61e-001, 1.33e-001, 1.00e-001, 6.59e-002, 3.13e-002, 1.05e-002, 2.77e-004, 0.00e+000, 0.00e+000,
		       /*42*/	   3.66e-001, 3.53e-001, 3.29e-001, 3.25e-001, 3.16e-001, 3.01e-001, 2.94e-001, 2.62e-001, 2.44e-001, 2.21e-001, 1.95e-001, 1.74e-001, 1.43e-001, 1.15e-001, 8.24e-002, 4.58e-002, 1.41e-002, 1.55e-003, 0.00e+000, 0.00e+000, 0.00e+000,			   
		       /*63*/	   3.43e-001, 3.28e-001, 3.15e-001, 3.18e-001, 2.93e-001, 2.75e-001, 2.58e-001, 2.45e-001, 2.24e-001, 1.98e-001, 1.77e-001, 1.47e-001, 1.11e-001, 7.83e-002, 4.76e-002, 2.13e-002, 5.75e-003, 1.40e-004, 0.00e+000, 0.00e+000, 0.00e+000,
		       /*84*/	   3.42e-001, 3.20e-001, 3.19e-001, 3.03e-001, 2.80e-001, 2.52e-001, 2.31e-001, 2.12e-001, 1.89e-001, 1.65e-001, 1.35e-001, 1.03e-001, 7.03e-002, 3.86e-002, 1.21e-002, 1.57e-003, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
		       /*105*/	   3.15e-001, 3.07e-001, 2.84e-001, 2.65e-001, 2.35e-001, 2.25e-001, 1.89e-001, 1.65e-001, 1.37e-001, 1.04e-001, 7.12e-002, 4.07e-002, 1.04e-002, 1.32e-003, 3.33e-006, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 
		       /*126*/	   2.64e-001, 2.58e-001, 2.41e-001, 2.07e-001, 1.87e-001, 1.58e-001, 1.32e-001, 9.53e-002, 6.33e-002, 2.86e-002, 4.68e-003, 4.33e-005, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000}; 
																					
  double w11BER7[150]={3.28e-001, 3.17e-001, 3.00e-001, 2.97e-001, 2.84e-001, 2.63e-001, 2.40e-001, 2.21e-001, 1.98e-001, 1.78e-001, 1.51e-001, 1.19e-001, 8.02e-002, 4.91e-002, 2.28e-002, 1.82e-003, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000,
		       /*21*/	   2.72e-001, 2.61e-001, 2.27e-001, 2.10e-001, 1.81e-001, 1.57e-001, 1.18e-001, 8.58e-002, 5.99e-002, 3.52e-002, 8.83e-003, 4.23e-004, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000, 0.00e+000};

  double w11BER9[50]={3.30e-001, 3.43e-001, 3.13e-001, 3.27e-001, 2.99e-001, 2.75e-001, 2.42e-001, 2.49e-001, 2.20e-001, 2.06e-001, 1.60e-001, 1.40e-001, 1.04e-001, 8.10e-002, 4.40e-002, 2.50e-002, 6.33e-003, 2.67e-003, 0.00e+000, 0.00e+000, 0.00e+000}; 

  double w11BER10[50]={1.82e-001, 1.63e-001, 1.43e-001, 1.07e-001, 2.79e-001, 2.64e-001, 2.43e-001, 2.04e-001, 8.69e-002, 7.11e-002, 4.68e-002, 2.83e-002, 1.57e-002, 5.64e-003, 1.01e-003, 0.00e+000, 0.00e+000 };

  double wwBER[10]=  {2.00e-001, 9.63e-002, 5.43e-002, 4.47e-002, 2.49e-002, 8.24e-003, 4.63e-003, 3.64e-003, 0e+000 };

  
  
  
  packetbuf=interface_pt[1][0];
  interface_pt[1][0]=224;
  IntBypassW(PHY, packet, interface_pt,collision_number); 
  interface_pt[1][0]=packetbuf;

  for(n=224*11;n<(int)(interface_pt[1][0]*11) ; n++)
    {
      for(i=1;i<= collision_number;i++)
	{
	  if ( (interface_pt[0][i]*11<=n) && (n< (int)( (interface_pt[0][i]+interface_pt[1][i])*11) ) )
	    {
	      d2=interface_pt[5][i];
	      pt2 = 1e-3*interface_pt[3][i];

	      if (d2<=8)
		lp= 32.45+20*log10(2.4*d2);
	      else if (d2>8)
		lp= 58.3+33*log10(d2/8.);

	      pr2 = 10*log10(pt2)-lp;
	      CAIRdb= 10*log10(PHY->pr1)-pr2;
	      df = interface_pt[4][0] - interface_pt[4][i];

	      if (df<0)
		df=-df;

	      if((interface_pt[2][i] == 1.)||(interface_pt[2][i] == 4.))
		{
		  if ((df>=0)&&(df<=6))
		    {
		      if(CAIRdb<-6)
			CAIRdb=-6;
		      if(CAIRdb>=4)
			CAIRdb=4;

		      index=(int)(2*(CAIRdb+6))+(int)(df*21);
		      p=w11BER0[index];
		      rn= Uniform(PHY);

		      if(rn<p)
			packet[n-224*10]=1-packet[n-224*10];
		    }/*if (df==0){*/

		  if ((df>=7)&&(df<=8))
		    {
		      if(CAIRdb<-10)
			CAIRdb=-10;
		      if(CAIRdb>=0)
			CAIRdb=0;

		      index=(int)(2*(CAIRdb+10))+(int)((df-7)*21);
		      p=w11BER7[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n-224*10]=1-packet[n-224*10];
		    }/*if (df==2){*/

		  if (df==9)
		    {
		      if(CAIRdb<-16)
			CAIRdb=-16;
		      if(CAIRdb>=-6)
			CAIRdb=-6;

		      index=(int)(2*(CAIRdb+16));
		      p=w11BER9[index];
		      rn=rand()/(double)RAND_MAX;

		      if(rn<p)
			packet[n-224*10]=1-packet[n-224*10];
		    }/*if (df==2){*/

		  if (df==10)
		    {
		      if(CAIRdb<-20)
			CAIRdb=-20;
		      if(CAIRdb>=-12)
			CAIRdb=-12;

		      index=(int)(2*(CAIRdb+20));
		      p=w11BER10[index];
		      rn=Uniform(PHY);

		      if(rn<p)
			packet[n-224*10]=1-packet[n-224*10];
		    }/*if (df==2){*/
		}/*if((interface_pt[2][i] == 1.)||(interface_pt[2][i] == 4.)){*/

	      if((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.))
		{
		  if(CAIRdb<0)
		    CAIRdb=0;
		  if(CAIRdb>=8)
		    CAIRdb=8;

		  index=(int)(CAIRdb+.5);
		  p=wwBER[index];
		  rn= Uniform(PHY);

		  if(rn<p)
		    packet[n-224*10]=1-packet[n-224*10];
		}/*if((interface_pt[2][i] == 2.)||(interface_pt[2][i] == 3.)){*/
	    }/* end else if*/
	}/*	for(i=1;i<= intcollision_number;i++){*/
    }/*for(n=0;n<interface_pt[1][0] ; n++) {*/
		
		
}
