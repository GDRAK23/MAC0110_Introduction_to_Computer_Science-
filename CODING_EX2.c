#include<stdio.h>
#include "funcoes-wav.c"
#define EPSILON 1e-14
#define PI 3.14159265358979323846

/*************************************************************/

/*                                                           */

/*   Guilherme Augusto Martins          Nº USP 7199162       */

/*   Exercício-Programa 2                                    */

/*   Professora:Leliane Barros                               */

/*                                                           */

/*************************************************************/

/*Funções auxiliares*/

double sen(double x)
{
    double sine,fatorial,potencia,iteracao,n,p_,f_,signal;

    iteracao=1;
    n=0;
    sine=0;

    while(iteracao*iteracao>=EPSILON*EPSILON)
    {
        if (n==0) /*primeira iteracao*/
        {
            potencia=x;
            fatorial=1;
            signal=1;
        }

        if (n==1) /*segunda iteracao*/

        {
            potencia=(x*x*x);
            fatorial=6;
            signal=-1;
        }

        if(n>1) /*demais iteracoes*/

        {
            fatorial=f_=p_=((2*n)+1);             /*atribuicoes iniciais*/
            potencia=x;
            signal=signal*-1;

            while(p_>1) /*laço da potencia,percorrido n-1 vezes*/
            {
                potencia=potencia*x;

                p_=p_-1;

            }

            while(f_>1) /*laço do fatorial*/

            {
                fatorial=fatorial*(f_-1);

                f_=f_-1;

            }

        }

        iteracao=signal*(potencia/fatorial);

        sine=sine+iteracao;

        n=n+1;

    }
    return sine;
}
double potencia_de_euler(double x)
{
    double exponencial,fatorial,potencia,iteracao,n,p_,f_;

    iteracao=1;
    n=0;
    exponencial=0;

    while(iteracao*iteracao>=EPSILON*EPSILON)
    {
        if (n==0) /*primeira iteracao*/
        {
            potencia=1;
            fatorial=1;
        }

        if (n==1) /*segunda iteracao*/

        {
            potencia=x;
            fatorial=1;
        }

        if(n>1) /*demais iteracoes*/

        {
            fatorial=f_=p_=n;             /*atribuicoes iniciais*/
            potencia=x;

            while(p_>1) /*laço da potencia,percorrido n-1 vezes*/
            {
                potencia=potencia*x;

                p_=p_-1;

            }

            while(f_>1) /*laço do fatorial*/

            {
                fatorial=fatorial*(f_-1);

                f_=f_-1;

            }

        }

        iteracao=(potencia/fatorial);

        exponencial=exponencial+iteracao;

        n=n+1;

    }
    return exponencial;
}
double ln(double x)
{
    double log_natural,iteracao_1,iteracao_2;

    iteracao_1=1;

    while((iteracao_2-iteracao_1)*(iteracao_2-iteracao_1)>=EPSILON*EPSILON)

    {
        iteracao_2=(iteracao_1-1)+(x/(potencia_de_euler(iteracao_1)));

        iteracao_1=(iteracao_2-1)+(x/(potencia_de_euler(iteracao_2)));
    }

    log_natural=iteracao_1;

    return log_natural;
}
double oscilador(double amplitude,double fase)
{
    double osc_sen;

    osc_sen=amplitude*sen(fase);

    return osc_sen;

}
double novafase (double frequencia,double fase)
{
    double nova_fase;

    nova_fase=(fase+(((2*PI)*frequencia)/TAXA_AMOSTRAGEM));

    /*Verifica se o angulo gerado está no intervalo 0,2pi*/

    while(nova_fase>=2*PI)

    {
        nova_fase=nova_fase-(2*PI);
    }

    return nova_fase;
}

/*Programa principal*/

int main()

{
    char nomesaida[60];

    double duracao_total,amostra,duracao,altura,volume,frequencia,amplitude,fase,arg_freq,arg_amp;

    int numero_total_de_amostras,numero_parcial_amostras;

    FILE *saida_wav ;

    printf("Entre com o nome do arquivo de saida:\n\n");
    scanf("%s",nomesaida);

    printf("Entre com duracao do arquivo de saida:\n\n");
    scanf("%lf",&duracao_total);

    printf("Entre com o seguinte parametro: Duracao da amostra:\n\n");
    scanf("%lf",&amostra);

    printf("Entre com o seguinte parametro: Altura:\n Onde:\n 0<=Altura<=120\n\n");
    scanf("%lf",&altura);

    printf("Entre com o seguinte parametro: Volume:\n Onde:\n 0<=Volume<=1\n\n");
    scanf("%lf",&volume);


    /*Calculos iniciais*/

    numero_total_de_amostras=TAXA_AMOSTRAGEM*duracao_total; /*Total de amostras no arquivo wav*/

    numero_parcial_amostras=0;

    /*Calculando os valores dos parametros e argumentos*/

    arg_freq=(altura/12)*ln(2);

    arg_amp=((10*volume)-(10))*ln(2);

    frequencia= potencia_de_euler(ln(27.5))+potencia_de_euler(arg_freq); /*Depende da altura*/

    amplitude= potencia_de_euler(arg_amp);/*Depende do volume*/

    /*Cria e escreve o cabecalho do arquivo wav*/

    saida_wav=fopen(nomesaida,"wb");

    escreve_cabecalho_wav(saida_wav,numero_total_de_amostras);

    fase=0;

    /*Gera as amostras pelo oscilador e as escreve no arquivo wav.*/

    while(numero_parcial_amostras<=numero_total_de_amostras)

    {
        amostra=oscilador(amplitude,fase);

        escreve_amostra(saida_wav,amostra);

        escreve_amostra(saida_wav,amostra);

        fase=novafase(frequencia,fase);

        numero_parcial_amostras=numero_parcial_amostras+1;

        printf("%d \n\n",numero_parcial_amostras);
    }

    /*Finaliza o processo*/

    fclose(saida_wav);

    printf("Arquivo wav gerado com sucesso!\n\n");

    return 0;
}
