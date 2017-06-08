#include <stdio.h>
#include <stdlib.h>
#define linhas 4
#define colunas 2

char teste,tESTE=0;


/*
int atualizaPeso(int alfa, int t, int in, int pesoAnt){
  return alfa*t*in + pesoAnt;
}

int atualizaB(int Bant, int alfa, int t){
  return alfa*t + Bant;
}
*/




int main(){
  int x[linhas][colunas]= {{-1,-1}, {-1,1}, {1,-1}, {1,1}};
  int w[colunas]= {-1,-1};
  int b=-1;
  int t[linhas]={  -1,   1,    1,    1 }; //SAIDA DO OR
  int i,j,k;
  int erro=10;
  int somatorio=0,saida;
  int yliq=0;
  int limiar=0;
  int alfa=1;

  while(erro!=0){
     erro=0;
     //x[0][0] = -1;
     //x[0][1] = -1;
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
/////MAQUIAGEM DE ITERAÃÃES
     printf("\n----------------------\nITERACAO %d ",tESTE);
     tESTE++;
     scanf("%c",&teste);
     printf("\n\n");
     for(j=0;j<colunas;j++)
         printf("pesoNovo%d=%d\n\n",j,w[j]);
     printf("\n\n------------------\n");

       	}


     }
 


  }

  //////////////////NO FINAL A ENTRADA MUDA////////////////////////////////

  ///////////////////////////////////////////////////////
  //////////////////RESULTADO FINAL DOS PESOS/////////////////////////////////////
  printf("==========RESULTADO FINAL===========");
  for(j=0;j<colunas;j++)
    printf("\npeso %d=%d",j,w[j]);
    printf("\nb=%d\n",b);
  printf("=========== TESTE DA RNA ===========");
  for(i=0;i<linhas;i++){
	printf("\n");
       	yliq=0;
	somatorio=0;
       	for(j=0;j<colunas;j++){
        	somatorio +=  w[j] * x[i][j];
       	}
       	yliq=b+somatorio;
       	if(yliq>=limiar)
        	 printf("saida=1");
       	else
        	 printf("saida=-1");

  }
    

return 0;
}
