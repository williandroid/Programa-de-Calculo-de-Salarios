//Programa de calculo de Salarios e Imposto de Renda.
//Esse programa agora contém um controle de versão
//
//


#include <stdio.h>
float mat[2][12];
int i;
int j;
float somaSalario = 0;
float salarioBruto = 0;
float salarioLiquido = 0;
float impostoDeRenda = 0;
float totalDeDesconto = 0;

//------------------------------------------------------------------------------
//Procedimento para zerar valores.
int zerarValores()
{
    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            mat[i][j] = 0;
        }
    }
}
//------------------------------------------------------------------------------
//Exibe a MATRIZ
int exibir()
{
    for(i=0;i<2;i++)
    {
        for(j=0;j<12;j++)
        {
            printf("%.0f ",mat[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
//------------------------------------------------------------------------------
//Procedimento de fazer as condições.
int condicoes()
{
    for(i=0;i<12;i++)
    {
        printf("Digite o Valor %d: ", i+1);
        scanf("%f", &mat[0][i]);
        if (mat[0][i]<50 || mat[0][i]>3000)
        { 
            i-=1;
            printf("Valor Invalido!!! Digite um novo Valor \n");
        }
    }   
    
    for(j=0; j<12; j++)
    {
        printf("Digite o Valor do Desconto %d: ", j+1);
        scanf("%f", &mat[1][j]);
        if(mat[1][j] < 10 || mat[1][j] > 600) 
        {
            j-=1;               
            printf("Valor Invalido!!! Digite um novo Valor \n");
        }                
    }
}
//------------------------------------------------------------------------------
//Calcula o salario Bruto.
int calculaSalarioBruto()
{
    for(i=0; i<12; i++)
    {
        salarioBruto += mat[0][i];      
    }        
}
//------------------------------------------------------------------------------
//Calcula o Imposto de Renda
int calculaImpostoDeRenda()
{
    if(salarioBruto >= 1499.16 && salarioBruto <= 2246.75)
    {
        impostoDeRenda=(salarioBruto * 7.5/100)-112.43;
    }
    else if(salarioBruto >= 2246.76 && salarioBruto <= 2995.70)
    {
        impostoDeRenda=(salarioBruto * 15/100)-280.94;
    }
    else if(salarioBruto >= 2995.71 && salarioBruto <= 3743.70)
    { 
        impostoDeRenda=(salarioBruto * 22.5/100)-505.62;
    }
    else if(salarioBruto > 3743.19)
    {
         impostoDeRenda=(salarioBruto *27.5/100)-692.78;
    }
}
//------------------------------------------------------------------------------
//Calcula o Total de Desconto
int calculaTotalDesconto()
{
        for(j=0; j<12; j++)
        {
             totalDeDesconto += mat[1][j];
 
        }
            totalDeDesconto += impostoDeRenda; 
}  

//------------------------------------------------------------------------------
//Calcula o Salario Liquido
int calculaSalarioLiquido()
{
    salarioLiquido = salarioBruto - totalDeDesconto;
}
//------------------------------------------------------------------------------
//Principal chamada de procedimentos
int main (void)
{

    zerarValores(); 
    condicoes();
    calculaSalarioBruto();
    calculaImpostoDeRenda();
    calculaTotalDesconto();
    calculaSalarioLiquido();
    exibir();
    printf("Salario Bruto %.2f\n", salarioBruto);
    printf("Salario Liquido %.2f\n", salarioLiquido);
    printf("Imposto de Renda %.2f\n", impostoDeRenda);
    printf("Total de Desconto %.2f\n\n\n\n", totalDeDesconto);
    system("pause");
    return 0;           
}
