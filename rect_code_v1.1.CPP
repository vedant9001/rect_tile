#include <math.h>
#include <iostream.h>
#include<conio.h>
#include<stdlib.h>
//#include<dos.h>
//using namespace std;

int arr[2][100];
int fit_arr[3][100];//int fr_pos=0;
int layer[100];
int memo,sum=0;  int tlfx,tlfy,pos; int k=0;
int l,prod,lrg;

int var=0;

int it_fits(int size){

if ((tlfx>(lrg-size+1)) || (tlfy>(l-size+1) ))
return 0;

for(int i=tlfx;i<(tlfx+size);i++)
	if(layer[i])
		return 0;

return 1;
}

void adto_layer(int size,int&lsp)
{
int min=lrg; int les;lsp=0;
int i;

for(i=tlfx;i<(tlfx+size);i++)
 {layer[i]=size; }
// cout<<layer[i]<<" ";}

les=1;//tlfx+size-1;

//if((tlfx+size)>lrg)
//cout<<"entered : "<<size;
for(int a=1;a<=lrg;a++)
  if(min>layer[a])
  { min=layer[a]; les=a;} //les=a;
//cout<<" min :"<<min;
if(min)
for(a=1;a<=lrg;a++)
  layer[a]-=min;

lsp=min;

tlfy+=min;
tlfx=les;

/*
for(i=les;i<=lrg;i++)
if(layer[i]==0)
{tlfx=i;break;}
*/
}


void rem_layer(int size,int lsb)
{int i;

 if(lsb)
 for(i=1;i<=lrg;i++)
	 layer[i]+=lsb;

 for(i=tlfx;i<(tlfx+size);i++)
 {layer[i]=layer[i]-size;}

}


void recur_fit(){pos++;

int lsub;

if(pos<k)
{for(int i=l;i>=1;i--)
{
    if(arr[0][i])
    if(it_fits(i))
    {
	// cout<<endl<<" ::: report ::: ";

	  fit_arr[0][pos]=i;
	  fit_arr[1][pos]=tlfx;
	  fit_arr[2][pos]=tlfy;
	// cout<<"size : "<<fit_arr[0][pos]<<" cord x:"<<fit_arr[1][pos]<<" y:"<<fit_arr[2][pos];

	  adto_layer(i,lsub);

       //	  cout<<"size : "<<fit_arr[0][pos]<<" cord x:"<<tlfx<<" y:"<<tlfy;
	 // for(int q=1;q<=lrg;q++)
	  //cout<<"ly:"<<layer[q]<<" ";

      arr[0][i]--;

      recur_fit();

      arr[0][i]++;

     tlfx=fit_arr[1][pos];
     tlfy=fit_arr[2][pos];

     rem_layer(i,lsub);


     if(pos==1)  break;


    }
}
}

else
{
   for(int i=l;i>=1;i--)
   {
     if(arr[0][i] &&  it_fits(i) )
       {
		fit_arr[0][pos]=i;
		for(int q=1;q<=k;q++)
			cout<<fit_arr[0][q]<<" ,";
		cout<<"  digit  ::"<<k;
       //cout<<k;
       getch();
       exit(0);
	   }

   }
}


pos--;
}



void process_ans(){

    k=0; tlfx=1;tlfy=1; pos=0;

	int fltr=0;

	for(int x=lrg;x>=1;x--)
	{	layer[x]=0;
	if(x<=l)
	{if(arr[0][x] &&(k==0 || k==1))
	 fltr+=x;
	// cout<<x<<","<<arr[0][x]<<"| ";
	k+=arr[0][x];}
	}//delay(2000);
	//cout<<"digits :: "<<k<<endl;


    if(fltr<=lrg)
    {recur_fit();}
 //   cout<<"digits :: "<<k<<" :{ NO"<<endl;

}

int recur(int start,int dig)
{  memo++;

   for(int i=start;i>=1;i--)
   {
     sum+=arr[1][i];
      arr[0][i]++;
   // if(i==4&&memo==1)
     //cout<<"a";

    if( ((sum+(dig-memo)*arr[1][i])<prod) )//|| ((sum+(dig-memo))>prod) )
    {sum-=arr[1][i];
	arr[0][i]--;
       memo--;
	return -1;
    }

    var=sum+(dig-memo);

    if(memo<dig)
    { if(  ( var ) <= prod )
     {recur(i,dig);}//int ret used previously}
     // if(ret==-1){ continue;}
    //else if(ret==1) { memo--; return 1;}
   }

    else if(sum==prod)
   {
     process_ans();
      // do the later part here
   }

     sum-=arr[1][i];
	arr[0][i]--;

   }

memo--;
 return 0;
}





int main()
{int i;
    //int a=11,b=13,i;
     clrscr();

     l=24;lrg=25;

   // prod=l*lrg;

  /*  if(a<b)
	{l=a; lrg=b;}
    else
	{l=b; lrg=a;}
*/


    prod=l*lrg;

   // l=7;

    for(i=1;i<=l;i++)
    {   arr[0][i]=0;
	arr[1][i]=i*i;
    }


    memo =0;

   // int num=70;

for(i=1;i<=prod;i++){
recur(l,i);
}


getch();
    return 0;
}
