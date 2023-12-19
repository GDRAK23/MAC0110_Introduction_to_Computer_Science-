#include<stdio.h>
#define MAX 128

/*************************************************************/

/*                                                           */

/*   Guilherme Augusto Martins          Nº USP 7199162       */

/*   Exercício-Programa 3                                    */

/*   Professora:Leliane Barros                               */

/*                                                           */

/*************************************************************/

/*Funcoes auxiliares*/

void zere_tabuleiro(int tabuleiro[MAX][MAX],int nlin,int ncol)
{
    int lin,col;

    for (lin=0; lin<nlin; lin++)
    {
        for(col=0; col<ncol; col++)
        {
            tabuleiro[lin][col]=0;
        }
    }
}

void copie_matriz(int origem[MAX][MAX], int destino[MAX][MAX],int nlin, int ncol)
{
    int lin,col;

    for (lin=0; lin<nlin; lin++)
    {
        for(col=0; col<ncol; col++)
        {
            destino[lin][col]=origem[lin][col];
        }

    }

}

void leia_configuracao_inicial(int *tabuleiro[MAX][MAX], int *nlin,int *ncol)
{




}

void imprima_tabuleiro(int tabuleiro [MAX][MAX],int nlin, int ncol)
{
    int lin,col,max=0,ndig=0,n_tracos,aux,aux2,aux3;

    /*Estabalecendo o max da matriz tabuleiro*/

    for(lin=0; lin<nlin; lin++)
    {
        for(col=0; col<ncol; col++)
        {
            if(tabuleiro[lin][col]>max)
            {
                max=tabuleiro[lin][col];
            }
        }
    }

    /*Contando seus digitos*/

    if(max==0)
    {
        ndig=1;
    }

    else
    {
        while(max>0)

        {
            max=max/10;

            ndig=ndig+1;

        }

    }

    n_tracos=ndig+2;

    /*Inicio Matriz*/

    /*Recuo inicial*/
    aux3=n_tracos;

    while(aux3!=0)
    {
        printf(" ");

        aux3=aux3-1;
    }

    /*Colunas*/

    for(col=0; col<ncol; col++)
    {
        printf("%*d",ndig,col);

        printf("  ");
    }

    printf("\n");

    printf("  ");

    printf("+");

    aux2=0;

    while(aux2<ncol)
    {
        for(aux=1; aux<=n_tracos; aux++)
        {
            printf("-");
        }

        printf("+");

        aux2=aux2+1;

    }
    printf("\n");

    /*Meio*/

    for(lin=0; lin<nlin; lin++)
    {
        for(col=0; col<ncol; col++)
        {

            if(col==0)

            {
                printf("%*d ",ndig,lin);
                printf("| %*d ",ndig,tabuleiro[lin][col]);
            }
            else
                printf("| %*d |",ndig,tabuleiro[lin][col]);
        }
        printf("\n");

        /*Tracejado*/

        printf("  ");

        printf("+");

        aux2=0;

        while(aux2<ncol)
        {
            for(aux=1; aux<=n_tracos; aux++)
            {
                printf("-");
            }

            printf("+");

            aux2=aux2+1;

        }
        printf("\n");
    }

    printf("\n\n");
}

int espalhe(int tabuleiro[MAX][MAX],int ativacao[MAX][MAX],int nlin, int ncol, int instante, int *novosativados)
{
    int lin,col,vizinhos,ativacoes,graos,count_activated,count_spread=0,total_instante=0,first_act=0,aux_instante=0;
    int copia_tabuleiro[MAX][MAX];

    copie_matriz(tabuleiro,copia_tabuleiro,nlin,ncol);

    for (lin=0; lin<nlin; lin++)
    {
        for(col=0; col<ncol; col++)
        {
            /*_____Cantos_____*/

            /*(0,0)*/
            if((lin==0)&&(col==0))
            {
                vizinhos=2;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin][col+1]=(tabuleiro[lin][col+1])+1;
                    tabuleiro[lin+1][col]=(tabuleiro[lin+1][col])+1;
                    tabuleiro[lin][col]=(tabuleiro[lin][col])-vizinhos;

                    total_instante=total_instante+1; /*Registra a activacao no instante*/

                    if (ativacao[lin][col]==-1) /*Registra o instante no qual a casa foi activada pela primeira vez*/
                    {
                        ativacao[lin][col]=instante;

                        first_act=first_act+1;
                    }
                }
            }

            /*(0,n-1)*/
            if((lin==0)&&(col==(ncol-1)))
            {
                vizinhos=2;

                if((tabuleiro[lin][col]>=vizinhos)&&(copia_tabuleiro[lin][col]>=vizinhos))

                {
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin+1][col]=tabuleiro[lin+1][col]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*(n-1,0)*/
            if((lin==(nlin-1))&&(col==0))
            {
                vizinhos=2;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))

                {
                    tabuleiro[lin][col+1]=tabuleiro[lin][col+1]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*(n-1,n-1)*/
            if((lin==(nlin-1)&&((col==(ncol-1)))))
            {
                vizinhos=2;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))

                {
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*_____Bordas_____*/

            /*(0,0<col<ncol-1)*/
            if((lin==0)&&(col>0)&&(col<ncol-1))
            {
                vizinhos=3;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin][col+1]=tabuleiro[lin][col+1]+1;
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin+1][col]=tabuleiro[lin+1][col]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*(nlin-1,0<col<ncol-1)*/
            if((lin==nlin-1)&&(col>0)&&(col<ncol-1))
            {
                vizinhos=3;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin][col+1]=tabuleiro[lin][col+1]+1;
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*(0<lin<nlin-1,0)*/
            if((lin>0)&&(lin<nlin-1)&&(col==0))
            {
                vizinhos=3;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin+1][col]=tabuleiro[lin+1][col]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col+1]=tabuleiro[lin][col+1]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*(0<lin<nlin-1,ncol-1)*/
            if((lin>0)&&(lin<nlin-1)&&(col==ncol-1))
            {
                vizinhos=3;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin+1][col]=tabuleiro[lin+1][col]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*_____Resto_____*/

            if((lin>1)&&(lin<nlin-2)&&(col>1)&&(col<ncol-2))
            {
                vizinhos=4;

                if(tabuleiro[lin][col]>=vizinhos&&(copia_tabuleiro[lin][col]>=vizinhos))
                {
                    tabuleiro[lin+1][col]=tabuleiro[lin+1][col]+1;
                    tabuleiro[lin-1][col]=tabuleiro[lin-1][col]+1;
                    tabuleiro[lin][col+1]=tabuleiro[lin][col+1]+1;
                    tabuleiro[lin][col-1]=tabuleiro[lin][col-1]+1;
                    tabuleiro[lin][col]=tabuleiro[lin][col]-vizinhos;

                    total_instante=total_instante+1;

                    if (ativacao[lin][col]==-1)
                    {
                        ativacao[lin][col]=instante;
                        first_act=first_act+1;
                    }
                }
            }

            /*Atualizando a variavel de controle de espalhamentos*/

            aux_instante=aux_instante+1;

            /*Envia para o endereco inserido no argumento o numero de primeiras ativacoes nesse instante*/

            *novosativados=first_act;

        }  /*Fim For Colunas*/

    }   /*Fim For Linhas*/

    return total_instante;

}/*Fim F4*/

/*Programa principal*/

int main()

{
    int tabuleiro[MAX][MAX],ativacao[MAX][MAX],m,n,lin,col,instante=0,finito=0,infinito=0,nunca_ativadas=0,ativados_inst;
    int auxiliar[MAX][MAX],teste_inf=0,teste_fin=0,n_graos=0,espalhamentos=0,new_act,ativacao_parcial=0,end=0;
    float porcent=0;

    /*Zerando o tabuleiro*/

    zere_tabuleiro(tabuleiro,m,n);

    /*Lendo as configuracoes iniciais do matriz*/

    printf("Simulador de monte de areia.\nConfiguracao inicial:\n");

    printf("Entre com o numero de linhas do tabuleiro:\n");
    scanf("%d",&m);

    printf("Entre com o numero de colunas do tabuleiro:\n");
    scanf("%d",&n);

    /*Preenchendo a matriz*/

    for (lin=0; lin<m; lin++)
    {
        for(col=0; col<n; col++)
        {
            printf("Entre com o numero de graos de areia na posicao:\nTabuleiro[%d][%d]\n",lin,col);
            scanf("%d",&tabuleiro[lin][col]);
        }
    }

    /*Inicializando a matriz ativação*/

    for (lin=0; lin<m; lin++)
    {
        for(col=0; col<n; col++)
        {
            ativacao[lin][col]=-1;
        }
    }

    /*Contando o numero de graos*/

    for(lin=0; lin<m; lin++)
    {
        for(col=0; col<n; col++)
        {
            n_graos=n_graos+tabuleiro[lin][col];
        }
    }

    /*Fazendo o espalhamento ate a definicao sobre a finitude do sistema*/

    while(end==0)
    {
        /*Teste finito*/

        copie_matriz(tabuleiro,auxiliar,m,n);

        /*Imprimindo tabuleiro inicial*/

        printf("Instante %d:\n",instante);

        imprima_tabuleiro(tabuleiro,m,n);

        /*Numero de espalhamentos e novos ativados no instante*/

        ativados_inst=espalhe(tabuleiro,ativacao,m,n,instante,&new_act);

        instante=instante+1;

        espalhamentos=espalhamentos+ativados_inst;

        /*Contando as novas ativacoes instante a instante*/

        ativacao_parcial=ativacao_parcial+new_act;

        /*Varrendo a matriz para verificar se houve variacao de graos de um instante para outro*/

        teste_fin=0;

        for (lin=0; lin<m; lin++)
        {
            for(col=0; col<n; col++)
            {
                if(auxiliar[lin][col]==tabuleiro[lin][col])
                {
                    teste_fin=teste_fin+1;
                }
            }

        }

        /*Se nao houver a variacao no total de graos por casa,o sistema atingiu uma configuracao estavel,ou seja e finito*/
        if(teste_fin==(m*n))
        {
            nunca_ativadas=(m*n)-ativacao_parcial;

            /*Calcula porcentagem de nunca activadas*/

            porcent=((float)(nunca_ativadas)/(float)(m*n));

            porcent=porcent*100;

            finito=1;

            end=1;
        }

        /*Teste infinito*/

        /*Se todas as casas ja foram ativadas, entao o sistema e infinito*/

        if((ativacao_parcial==(m*n))&&(teste_fin!=(m*n)))
        {
            infinito=1;

            end=1;
        }

    }
    /*Fim do while principal*/

    /*Matriz que satisfez as propriedades*/
    printf("Instante %d:\n",instante);

    imprima_tabuleiro(tabuleiro,m,n);

    /*Relatorio final*/

    /*1*/printf("Tabuleiro %d x %d, %d graos\n",m,n,n_graos);

    /*2*/printf("Simulacao encerrada no instante %d.\n",instante);

    /*3*/printf("Total de espalhamentos ao longo do processo: %d\n",espalhamentos);

    /*4*/printf("Total de casas nunca ativadas: %d (%.2f%%)\n",nunca_ativadas,porcent);

    /*5*/if(infinito==1)
    {
        printf("Sistema infinito\n");
    }
    if(finito==1)
    {
        printf("Sistema finito\n");
    }

    /*6*/printf("Configuracao quando detectado:\n");

    imprima_tabuleiro(tabuleiro,m,n);

    /*7*/printf("Primeiro instante de ativacao de cada casa:\n");
    imprima_tabuleiro(ativacao,m,n);

    return  0;
}
