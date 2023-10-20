#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

// vetores globais
// posição do jogo e produtos
char jogos[3][30], produtora[3][20];



//arquivos
FILE * arquivojogo;
FILE * arquivoprodutora;


//FUNÇOES DE CONEXÃO

// funçao fechar conexão com o arquivo
void Fechar()
{
    fclose(arquivojogo);
    fclose(arquivoprodutora);
}

//funcao  string.h
int strcmp(const char* str1, const char* str2)
{

    int  diferente=0;

    for(int i = 0; ( str1[i] != '\0' || str2[i] != '\0' ); i++)
    {


        if(str1[i] != str2[i])
        {

            diferente = 1;

            //fim if
        }

        //fim se




        //fim for
    }

    return (diferente);
    //fim função
}
void strcpy(char* str1, char* str2)
{
    for(int i = 0; i<30; i++)
    {
        // passar do str2 para str1
        str1[i] = str2[i];
        //fim for
    }

    //fim função
}

//função gravar
void Gravar()
{
    //abrir conexão
    //diretorio e formato
    arquivojogo= fopen("jogos.txt", "w");
    arquivoprodutora = fopen("produtora.txt", "w");
    //escrever no arquivo gerado
    fwrite(jogos, 1, sizeof(jogos), arquivojogo);
    fwrite(produtora, 1, sizeof(produtora), arquivoprodutora);
    //fechar conexão
    Fechar();
    //fim função
}
//função passar para vetores
void Ler()
{
    //abrir conexão
    arquivojogo= fopen("jogos.txt", "r");
    arquivoprodutora = fopen("produtora.txt", "r");
    //leitura e passagem para o vetor
    fread(&jogos, sizeof(char), 100, arquivojogo);
    fread(&produtora, sizeof(char), 100, arquivoprodutora);
    //fechar conecção
    Fechar();

    //fim função
}

// funçao 1 Entrada
void Entrada()
{
    Ler();

    setlocale(LC_ALL, "Portuguese ");

    int add = 2, ocupado =0;

    for(int i = 0; i < 3 ; i++)
    {

        if ( jogos[i][0] == '\0')
        {
            // pergunta

            printf("\nDigite o nome do Jogo:", ocupado);
            // salva no veotr
            scanf("%s", jogos[i]);

            printf("\nDigite o nome da Produtora:");
            scanf("%s", produtora[i]);


            // add mais
            printf("Deseja adicionar mais um? (1- Sim, 2-Não) ");
            scanf("%d", &add);
            // fim if
            if(add == 2){
                //sair
                break;
                //fim esse se
            }
            //fim esse if
        }else{
            //caso o jogo[i] estiver com escrita add em ocupado
            ocupado++;
        }

    }
    //msg extra
    if(ocupado >2)
        {
            printf("\nNão há mais espaço para gravar\n");

        }

    // gravar no arquivo
    Gravar();
    system("pause");
    // fim funçao
}
// funçao 2 Listar
void Listar()
{
    //ler txt
    Ler();

    printf("\n __________________________________________ ");
    for (int i = 0; i < 3; i++)
    {
        // exibir lista
        printf("\n|Jogo:      %30s |", jogos[i]);
        printf("\n|Produtora: %30s |", produtora[i]);
        printf("\n|------------------------------------------|");
        // fim for
    }
    printf("\n|__________________________________________|\n");
    system("pause");
    // fim função
}
// função 3 Pesquisa
int PesquisaJogo()
{
    setlocale(LC_ALL, "Portuguese ");

    //ler arquivo
    Ler();

    //verificação
    int encontrado = 0, posi = 0;
    // pergunta
    char nome[30];


    printf("Qual o jogo?");
    scanf("%s", nome);
    for (int i = 0; i < 3; i++)
    {

        // strcmp (texto, texto) são iguais retorna 0
        if (strcmp(jogos[i], nome) == 0)
        {
            // avisar q foi encontrado
            encontrado = 1;
            // retorna o i
            posi = i;
            // fim if
        }
        // fim for
    }
    // msg de não encontrado
    if (encontrado == 0)
    {
        printf("\nJogo %s não encontrado\n", nome);
        posi= 5;
        // fim se
    }
    else
    {
        // exibir
        printf("\n __________________________________________");
        printf("\n|Jogo:      %30s |", jogos[posi]);
        printf(
            "\n|Produtora: %30s |\n|__________________________________________|",
            produtora[posi]);
        printf("\n");
    }
    system("pause");
    return(posi);

    // fim funcao
}
// função 4 Pesquisa produtora
void PesquisaProdutora()
{
    setlocale(LC_ALL, "Portuguese ");

    //ler arquivo
    Ler();

    int encontrado = 0;
    // bug do enter
    getchar();
    // pergunta
    printf("Qual a letra da produtora que você quer pesquisar?\n");
    char letra = getchar();

    for (int i = 0; i < 3; i++)
    {
        // strcmp (texto, texto) são iguais retorna 0
        if (produtora[i][0] == letra)
        {
            printf("\n __________________________________________");
            printf("\n|Jogo:      %30s |", jogos[i]);
            printf(
                "\n|Produtora: %30s |\n|__________________________________________|",
                produtora[i]);
            printf("\n");

            // avisar que foi encontrado
            encontrado = 1;
            // fim if
        }
        // fim for
    }
    if (encontrado == 0)
    {
        printf("\nNenhuma produtora encontrado com a letra %c\n", letra);
        // fim se
    }
    system("pause");
    // fim funcao
}
//função de mostrar seleção no 5 e 6
int mostrar(char* text)
{
    setlocale(LC_ALL, "Portuguese ");

    int op;
    //listar
    Listar();

    printf("%s",text);
    op = PesquisaJogo();

    return(op);
    //fim função
}
// função 5 Alterar
void Altera()
{
    setlocale(LC_ALL, "Portuguese ");


    int op, op2;
//fazer seleção e mostrar
    op = mostrar("\nQual quer alterar?\n");
    //se não foi encontrado op = 5
    if(op<5)
    {
        //fazer alteração

        printf("\nDigite o novo nome do Jogo:");
        // salva no veotr
        scanf("%s", jogos[op]);

        printf("\nDigite o novo nome da Produtora:");
        scanf("%s", produtora[op]);

        // gravar no arquivo
        Gravar();

        //confirm
        printf("\nAlteração feita com sucesso!\n");
        //fim if
    }
    system("pause");
    // fim função
}
//função 6 excluir
void Excluir()
{
    setlocale(LC_ALL, "Portuguese ");
    // fazer seleção e mostrar

    int selec = mostrar("\nQual quer excluir?\n");
    //se não foi encontrado op = 5
    if(selec<5)
    {
        //confirma
        int conf;
        do
        {
            printf("\nConfirma? (1 - sim 2 - não)");
            scanf("%d", &conf);
        }
        while(conf<1|| conf>2);
        if(conf == 1)
        {
            //excluindo

            jogos[selec][0] = '\0';
            produtora[selec][0] = '\0';


//fim se
        }


        // gravar no arquivo
        Gravar();

        //confirm
        printf("Excluido com sucesso!");
        //fim if-
    }
    system("pause");
    //fim função
}
// main
int main()   // principais do main  
{

    // entrada      
    int escolhaMenu, saida = 0;
    // para o usuário escolher sair   
    do
    {

        // inicio projeto       
        do
        {
            // alimentação
            system("cls");
            printf(
                "\nBem Vindo \nDeseja fazer:\n -----------------------\n|1 - Entrada "
                "de "
                "Dados   |\n|2 - Listar Dados       |\n|3 - Pesquisa jogo      |\n|4 - "
                "Pesquisar Produtora|\n|5 - Alterar Dados      |\n|6 - Excluir Dados   "
                "   |\n|7 - Sair               |\n -----------------------\n");
            scanf("%d", &escolhaMenu);

            if (escolhaMenu > 7 || escolhaMenu < 1)
            {

                printf("Erro! Opção Inválida");
            }
        }
        while(escolhaMenu > 7 || escolhaMenu < 1);
        // função
        switch (escolhaMenu)
        {
        // 1 entrada de dados
        case 1:
        {
            // chama funcao
            Entrada();
            // fim case
            break;
        }

        // 2 listar de dados
        case 2:
        {
            // chama funcao
            Listar();
            // fim case
            break;
        }
        // 3 pesquisa jogo
        case 3:
        {
            // chama funcao
            PesquisaJogo();
            // fim case
            break;
        }
        // 4 pesquisa produtora
        case 4:
        {
            // chama funcao
            PesquisaProdutora();
            // fim case
            break;
        }
        // 5 pesquisa produtora
        case 5:
        {
            // chama funcao
            Altera();
            // fim case
            break;
        }
        // 6 pesquisa produtora
        case 6:
        {
            // chama funcao
            Excluir();
            // fim case
            break;
        }
        // 7 se o usuário quer finalizar  
        case 7:
        {
            // saída
            saida = 1;
            // fim case
            break;
        }
            // fim switch
        }
    }
    while (saida == 0);

    printf("Obrigado por utilizar o programa");
}
