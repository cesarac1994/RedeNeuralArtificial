#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define linhas 2
#define colunas 12

char teste,tESTE=0;


/*
int atualizaPeso(int alfa, int t, int in, int pesoAnt){
  return alfa*t*in + pesoAnt;
}

int atualizaB(int Bant, int alfa, int t){
  return alfa*t + Bant;
}
*/

/*
-1 1 -1
 1 1 -1   ==>  -1 1 -1 1 1 -1 -1 1 -1 -1 1 -1
-1 1 -1
-1 1 -1

1  1 1
1 -1 1   ==>  1  1 1 1 -1 1 1 -1 1 1  1 1
1 -1 1
1  1 1

*/

int main(){
  int x[linhas][colunas]= {
	{-1, 1, -1, 1, 1, -1, -1, 1, -1, -1, 1, -1},
	{ 1,  1, 1, 1, -1, 1, 1, -1, 1, 1,  1, 1}};

  int w[colunas]= {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
  int b=-1;
  int t[linhas]={ 1, -1 }; //SAIDA DO OR
  int erro=10;
  int somatorio=0,saida;
  int yliq=0;
  int limiar=0;
  int alfa=1;
  int i,j,k;

  while(erro!=0){
     erro=0;
     for(i=0;i<linhas;i++){
       	somatorio=0;
       	yliq=0;
       	for(j=0;j<colunas;j++){
        	somatorio +=  w[j] * x[i][j];
       	}
       	yliq=b+somatorio;

       	if(yliq>=limiar)
        	 saida=1;
       	else
        	 saida=-1;
       //COMPARAÇÃO

       	if(t[i]!=saida){//NÃO PRECISA ATUALIZAR PESO
        	erro++;
         	for(j=0;j<colunas;j++){
            		w[j]+=alfa*t[i]*x[i][j];
	 	}
         	b=b+alfa*t[i];

     cout << "ITERACAO " << tESTE;
     tESTE++;
     scanf("%c",&teste);
     printf("\n\n");
     for(j=0;j<colunas;j++)
        cout<<"wnovo"<<j<<"="<<w[j]<<" ";
     cout<<endl<<endl;
       	}
     }
  }

  //////////////////NO FINAL A ENTRADA MUDA////////////////////////////////

  ///////////////////////////////////////////////////////
  //////////////////RESULTADO FINAL DOS PESOS/////////////////////////////////////
cout<<"\n============RESULTADO FINAL==============";
  for(j=0;j<colunas;j++)
    cout<<"\npeso"<<j<<"="<<w[j];
  cout<<"\nb="<<b<<endl;

cout<<"\n=============TESTE DA RNA================";
  for(i=0;i<linhas;i++){
	cout<<endl;
	yliq=0;
       	somatorio=0;
       	for(j=0;j<colunas;j++){
        	somatorio +=  w[j] * x[i][j];
       	}
       	yliq=b+somatorio;

       	if(yliq>=limiar)
        	 cout<<"saida=1";
       	else
        	 cout<<"saida=-1";
  }


return 0;
}
