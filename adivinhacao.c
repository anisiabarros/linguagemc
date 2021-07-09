#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define PONTMAX 100
#define FACIL 25
#define MEDIO 15
#define DIFICIL 10


int main(){
    int x;
    int chance,i1, i2, n, nu,dif, pontT, prim, count, menor, maior, continuar, p;
    prim = 1;
    count=0;
    continuar = 1;

     while(continuar==1){

        printf("Qual o nivel de dificuldade voce gostaria de jogar?\n\n Para Facil: Digite 1,\n\n Para Medio: digite 2,\n\n Para Dificil: digite 3\n");
        scanf("%d", &dif);

        switch(dif){
                case 1: chance = FACIL;
                break;
                case 2: chance = MEDIO;
                break;
                case 3: chance = DIFICIL;
                break;
        }

         system("cls");
        printf("\t       Defina o intervalo de numeros: \n\tDo inicial ao numero final, que serao usados\n");
        scanf("%d %d", &i1, &i2);
        srand( (unsigned)time(NULL) );
        x = i1 + rand() % (i2 - i1);
        system("cls");

            do {
                if(prim){
                    printf("Digite um numero, entre %d e %d:         ", i1, i2);
                    scanf("%d", &n);
                    nu = n;
                    prim = 0;
                    chance--;
                    pontT = 100;
                    menor = i1;
                    maior = i2;


                }
                if(!prim){

                    if(n<x&&chance>0){
                        if (n>=menor)
                            menor = n+1;
                     }
                    if(n>x && chance>0){
                        if (n<=maior)
                            maior = n-1;
                     }
                    printf("Digite um numero, entre %d e %d:       ", menor, maior);
                    scanf("%d", &n);
                         if(n==nu){
                            printf("Voce ja digitou esse numero! tente outra vez\n");
                        } else{
                            nu = n;
                            chance--;
                            count++;
                        }
                    }


            }while(n != x && chance != 0);
            p = count;
            if(n==x){
                if (dif == 3){
                    if((count -5)>=0)
                      pontT = PONTMAX - ((count-5) *10) ;
                    if((count-5)<0)
                      pontT = PONTMAX;

                }else if(dif == 2){
                    if((count -7)>=0)
                       pontT = PONTMAX - ((count-7) *5) ;
                    if((count-7)<0)
                       pontT = PONTMAX;

                }else if (dif == 1){
                    if((count -10)>=0)
                       pontT = PONTMAX - ((count-10) *4) ;
                    if((count-10)<0)
                       pontT = PONTMAX;

                    }

                printf("\n\nVoce acertou, usou %d chances sua pontuacao foi %d pontos", count+1, pontT );
            }else if(n!=x){
                printf("\n\nVoce nao descobriu o numero, tente novamente mais tarde!\n");
            }

            printf("\n\n\tVoce deseja jogar mais uma vez? \n\tSe sim digite 1,\n\tSe nao deseja mais:  digite qualquer tecla\n");
            scanf("%d", &continuar);
            system("cls");
            if(continuar) {
                prim = 1;
                count=0;

            }
  }
return 0;
}
