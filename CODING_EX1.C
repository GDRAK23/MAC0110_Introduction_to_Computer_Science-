
#include<stdio.h>

int main()
{
    /*Declarando,inicializando variaveis e setando o tabuleiro*/

    int tabuleiro,player,aux,aux2,aux3,aux4,aux5,aux6,aux7,aux8,aux9,aux10,p1,p2,p3,p4,p5,p6,p7,p8,p9;
    int result,move,victory,validator,winneraux,winner1,winner2,winner,i;

    printf("Jogo da Velha Dancarina\n\n");
    printf("Tabuleiro Inicial:\n");
    scanf("%d",&tabuleiro);

    aux=tabuleiro;
    validator=tabuleiro;
    victory=0;
    winner1=0;
    winner2=0;
    i=0;

    /*Validando a jogada*/

    while(validator!=0)
    {
        validator=validator/10;

        i=i+1;

    }

    if(i==9) /*#naovaiterjogo*/
    {
        victory=1;
        result=8;
    }
/******************************************************************************************************************************/

    /*Grande if, se passar dele tem jogo*/

    if(victory!=1)
    {
        p9=aux%10;aux=aux/10;p8=aux%10;aux=aux/10;p7=aux%10;aux=aux/10;p6=aux%10;aux=aux/10;p5=aux%10;aux=aux/10;

        p4=aux%10;aux=aux/10;p3=aux%10;aux=aux/10;p2=aux%10;aux=aux/10;p1=aux%10;

        /*Inicializacao do tabuleiro*/

        printf("\n%d | %d | %d\n",p1,p2,p3);
        printf("---+---+---\n");
        printf("%d | %d | %d\n",p4,p5,p6);
        printf("---+---+---\n");
        printf("%d | %d | %d\n",p7,p8,p9);

        /*Comeco do jogo, estabelecendo o loop*/

        player=1;

        while(victory!=1)
        {
            printf("(Jogador %d) Proxima jogada: \n\n",player);
            scanf("%d",&move);

            /*Giro*/

         if (move==0)
         {
            aux2=p4;p4=p7;p7=p8;p8=p9;p9=p6;
            p6=p3;p3=p2;p2=p1;p1=aux2;

            printf("\n%d | %d | %d\n",p1,p2,p3);
            printf("---+---+---\n");
            printf("%d | %d | %d\n",p4,p5,p6);
            printf("---+---+---\n");
            printf("%d | %d | %d\n\n",p7,p8,p9);

         }
            /*Fim  giro*/
/******************************************************************************************************************************/

            /*Deslize*/

        if (move>=1&&move<=8) /*Inumeros ifs pra setar as novas posicoes*/
        {
          if(move==1)

          {
            aux2=p9;p9=p8;p8=p7;p7=p6;p6=p5;p5=p4;p4=p3;p3=p2;p2=p1;p1=aux2;
          }

          if(move==2)

          {
           aux2=p9;aux3=p8;p9=p7;p8=p6;p7=p5;p6=p4;p5=p3;p4=p2;p3=p1;p2=aux2;p1=aux3;
          }

          if(move==3)

          {
           aux2=p9;aux3=p8;aux4=p7;p9=p6;p8=p5;p7=p4;p6=p3;p5=p2;p4=p1;p3=aux2;p2=aux3;p1=aux4;
          }

          if(move==4)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;p9=p5;p8=p4;p7=p3;p6=p2;p5=p1;p4=aux2;p3=aux3;p2=aux4;p1=aux5;
          }

          if(move==5)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;aux6=p5;p9=p4;p8=p3;p7=p2;p6=p1;p5=aux2;p4=aux3;p3=aux4;p2=aux5;p1=aux6;
          }

          if(move==6)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;aux6=p5;aux7=p4;p9=p3;p8=p2;p7=p1;p6=aux2;p5=aux3;p4=aux4;p3=aux5;p2=aux6;p1=aux7;
          }

          if(move==6)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;aux6=p5;aux7=p4;aux8=p3;p9=p2;p8=p1;p7=aux2;p6=aux3;p5=aux4;p4=aux5;p3=aux6;p2=aux7;p1=aux8;
          }

          if(move==7)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;aux6=p5;aux7=p4;aux8=p3;aux9=p2;p9=p1;p8=aux2;p7=aux3;p6=aux4;p5=aux5;p4=aux6;p3=aux7;p2=aux8;p1=aux9;
          }

          if(move==8)

          {
           aux2=p9;aux3=p8;aux4=p7;aux5=p6;aux6=p5;aux7=p4;aux8=p3;aux9=p2;aux10=p1;p9=aux2;p8=aux3;p7=aux4;p6=aux5;p5=aux6;p4=aux7;p3=aux8;p2=aux9;p1=aux10; /*E vem jogando do lado, do lado de cá*/
          }

            printf("\n%d | %d | %d\n",p1,p2,p3);
            printf("---+---+---\n");
            printf("%d | %d | %d\n",p4,p5,p6);
            printf("---+---+---\n");
            printf("%d | %d | %d\n\n",p7,p8,p9);

        } /*Fim Deslize*/

/******************************************************************************************************************************/

        /*Verificando se houve vencedor*/

            if((p1==p2==p3) && (p1!=0 && p2!=0 && p3!=0)) /*1º Modo*/

            {
                victory=1;

                if(p1==p2==p3==1)
                {
                    winneraux=1;
                    result=1;
                }

                if(p1==p2==p3==2)
                {
                    winneraux=2;
                    result=1;
                }

                winner1=winneraux;

            }

            if((p1==p4==p7) && (p1!=0 && p4!=0 && p7!=0)) /*2º Modo*/

            {
                victory=1;

                if(p1==p4==p7==1)
                {
                    winneraux=1;
                    result=2;
                }

                if(p1==p4==p7==2)
                {
                    winneraux=2;
                    result=2;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }

            if((p1==p5==p9) && (p1!=0 && p5!=0 && p9!=0)) /*3º Modo*/

            {
                victory=1;

                if(p1==p5==p9==1)
                {
                    winneraux=1;
                    result=3;
                }

                if(p1==p5==p9==2)
                {
                    winneraux=2;
                    result=3;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }

            if((p9==p8==p7) && (p9!=0 && p8!=0 && p7!=0)) /*4º Modo*/

            {
                victory=1;

                if(p9==p8==p7==1)
                {
                    winneraux=1;
                    result=4;
                }

                if(p9==p8==p7==2)
                {
                    winneraux=2;
                    result=4;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }

            if((p9==p6==p3) &&  (p9!=0 && p6!=0 && p3!=0)) /*5º Modo*/

            {
                victory=1;

                if(p9==p6==p3==1)
                {
                    winneraux=1;
                    result=5;
                }

                if(p9==p6==p3==2)
                {
                    winneraux=2;
                    result=5;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }

            if((p6==p5==p4) && (p6!=0 && p5!=0 && p4!=0)) /*6º Modo*/

            {
                victory=1;

                if(p6==p5==p4==1)
                {
                    winneraux=1;
                    result=6;
                }

                if(p6==p5==p4==2)
                {
                    winneraux=2;
                    result=6;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }

            if((p3==p5==p7) && (p3!=0 && p5!=0 && p7!=0)) /*7º Modo*/

            {
                victory=1;

                if(p6==p5==p4==1)
                {
                    winneraux=1;
                    result=6;
                }

                if(p6==p5==p4==2)
                {
                    winneraux=2;
                    result=6;
                }

                if(winner1!=0)
                {
                    winner2=winneraux;
                }

                winner1=winneraux;
            }
            /******************************************************************************************************************************/
            /*Setando o jogador se nao houve vencedor*/

            if(player==1)
            {
                player=2;
            }

            else
            {
                player=1;
            }


        }
        /*Fim loop do jogo*/

    }
    /*Fim grande if*/

    /******************************************************************************************************************************/

    if(winner1!=0 && winner2!=0) /*Testando pra ver quem ganhou*/
    {
        result=9;
    }

    if(winner1!=0 && result!=8)
    {
        winner=winner1;
    }

    if(winner2!=0 && result!=8)
    {
        winner=winner2;
    }

    /*Setando a vitoria*/

    if(result==1)
    {
        printf("O jogador %d completou a 1a linha!\n",winner);
    }
    if(result==2)
    {
        printf("O jogador %d completou a 1a coluna!\n",winner);
    }
    if(result==3)
    {
        printf("O jogador %d completou a diagonal principal!\n",winner);
    }
    if(result==4)
    {
        printf("O jogador %d completou a ultima linha!\n",winner);
    }
    if(result==5)
    {
        printf("O jogador %d completou a ultima coluna!\n",winner);
    }
    if(result==6)
    {
        printf("O jogador %d completou a linha do meio!\n",winner);
    }
    if(result==7)
    {
        printf("O jogador %d completou a diagonal secundaria!\n",winner);
    }
    if(result==8)
    {
        printf("O jogo terminou empatado!");
    }
    if(result==9)
    {
        printf("Os dois ganharam!");
    }

    return 0;

} /*Fim main*/


