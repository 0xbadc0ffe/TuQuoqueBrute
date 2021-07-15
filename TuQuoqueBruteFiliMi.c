#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double frequenze[26];
short int gen=0;


double* genfreq(char* s){

   if(gen)
        return frequenze;

   int i=0;
   int n=0;

   while(*s){
       int v = (int) *s;
       if(v<65 || v>122 || (v>90 && v<97)){}
        // i=0;//negare su
       else{
          //printf("%c, %d %d\n\n",v,k,n);
          n++;
          if(v<91)
            frequenze[v-65]++;
          if(v>96)
            frequenze[v-97]++;
       }
     *s++;
   }

   for(i;i<26;i++)
       frequenze[i]/=n;
   //printf("%d %lf\n",n,freq[k]);
   gen =1;

   return frequenze;
}


double* freqk(char* s,int k){

   double* freq = genfreq(s);

   double* res=(double*) malloc(26*sizeof(double));
   int i =0;

   for(i;i<26;i++)
     res[i]=freq[(26+i-k)%26];

   return res;
}



int minK(char* s, double* sfreq){

  int i=0, m=0,j=0;
  double min=30,h=0;
  double* freq;

  for(i; i<26;i++){
    j=0;
    h=0;
    freq = freqk(s,i);
    //printf("%lf\n",freq[i]);

    for(j;j<26;j++)
       h-=freq[j]*log(sfreq[j]);//add log
       //printf("k= %d, Min= %lf, mk= %d\n",i,min,m);
    if(h<=min){
       min = h;
       m=i;
       //printf("k= %d, Min= %lf, mk= %d\n",i,min,m);
   }

   //printf("%d)  %lf %lf %d %lf %lf\n",i,freq[0],h,m, min,log(sfreq[i]));

   }

  return m;

}

//esempio: Fobi govv, iye nsn bowowlob Tevsec Mkockb. Grkd sc dro cew yp kvv droxewlobc pbyw yxo dy pybdi?

int main(int argv, char** args){

    char* s = (char*) malloc(4096*sizeof(char));

    scanf(" %[^\n]s",s);


    double sfreq[] ={0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015,
                     0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406,
                     0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056,
                     0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074 };

   // aggiungere modalità: encrypter, manuale, automatica (default), lista di soluzioni, mostrando entropia e/o frequenze
   // aggiungere importante: scelta dizionario
    int k = minK(s,sfreq); 

    printf("\nMinimo k: %d \n\n",k);

    while(*s){
        int v = *s;
    if(!(v<65 || v>122 || (v>90 && v<97))){
        //printf("%c ",(char)v);
        if(v<91-k)
            v=v+k;
        else
            if(v<91)
                v=v-26+k;
          if(v>96)
             if(v<123-k)
                 v=v+k;
             else
                if(v<123)
                   v=v-26+k;
     }
    printf("%c",(char)v);
    *s++;
    }


     printf("\n\n");
    //free(s);
}
