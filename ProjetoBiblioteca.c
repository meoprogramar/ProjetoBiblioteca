#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <math.h>

char nomelogin[30]; //variavel global para saber a pessoa logada;

typedef struct{
    char nomefuncionario[30], senhafuncionario[30];
}FUNCIONARIO;

typedef struct{
    char codigolivro[30], nomelivro[30], nomeautor[30], area[30];
    int estoquelivro;
}LIVROS;

typedef struct{
    char codigoaluno[30], nomealuno[30], cpfaluno[30];
}ALUNOS;

typedef struct{
    char codigoalunoemprestimo[30], codigolivroemprestimo[30], nomelivroemprestimo[30];
    int dia, mes, ano, diad, mesd, anod;
}EMPRESTIMO;

//funcao que transforma a data em string para data em int;
datat(char* x, int *dd, int *mm, int *yy)
{
    char numeros[10]={'0','1','2','3','4','5','6','7','8','9'};
    int i, j, v[6], count=0, dia, dia2, mes, mes2, ano, ano2;

    for(i=0;i<11;i++)
    {
        if(i!=2 && i!=5)
        {
            for(j=0;j<11;j++)
            {
                if(x[i]==numeros[j])
                {
                    v[count]=j;
                    count++;
                }
            }
        }
    }
    for(i=0;i<6;i++)
    {
        if(i%2==0)
        {
            if(i==0)
            {
                mes=(v[i]*10);
            }
            if(i==2)
            {
                dia=(v[i]*10);
            }
            if(i==4)
            {
                ano=(v[i]*10);
            }
        }
        if(i%2==1)
        {
            if(i==1)
            {
                mes2=v[i];
            }
            if(i==3)
            {
                dia2=v[i];
            }
            if(i==5)
            {
                ano2=v[i];
            }
        }
    }
    *dd=dia+dia2;
    *mm=mes+mes2;
    *yy=ano+ano2;
}

//funcao que vai dar a data de devolucao;
datadevolucao(int dia, int mes, int ano, int *diad, int *mesd, int *anod)
{
    int v[12]={31,28,31,30,31,30,31,31,30,31,30,31}, i;
    for(i=0;i<12;i++)
    {
        if(mes==i+1)
        {
            if(dia+10<=v[i+1])
            {
                *diad=dia+10;
                *mesd=mes;
                *anod=ano;
            }
            else
            {
                *mesd=mes+1;
                *diad=((dia+10)-v[i]);
                *anod=ano;
                if(mes==12)
                {
                    *mesd=1;
                    *anod=ano+1;
                }
            }
        }
    }
}

//Funções de acrescentar espacos e tabs, e caracter c/ delay;
imprimircar (int quant, int delay, int an) //imprimir qualquer car c/ delay;
{
    int i;
    for(i=0;i<quant;i++)
    {
        Sleep(delay);
        printf("%c",an);
    }
}

//Funcao para pular linhas e espacos;
esp_tab (int quantesp, int quanttab)
{
    int i;
    for(i=0;i<quantesp;i++)
        printf("\n");
    for(i=0;i<quanttab;i++)
        printf(" ");
}

//Funcao para posicionar o ponteiro em alguma coordenada na tela;
gotoxy(int x, int y)
{
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

//função para preencher o visual do menu automatico;
visualdomenu ()
{
    system("color 30");
    esp_tab(2,10); imprimircar(1,0,218); imprimircar(60,0,196); imprimircar(1,0,191);
    esp_tab(1,10); imprimircar(1,0,179); printf(" BIBLIOTECA - Universidade Estadual da Paraiba"); esp_tab(0,14); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,60); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); printf(" Conta, %s.", nomelogin); esp_tab(0,29-strlen(nomelogin)); printf("%s, %s ",__DATE__,__TIME__); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,192); imprimircar(60,0,196); imprimircar(1,0,217);
    esp_tab(1,10); esp_tab(0,74); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191);
    esp_tab(1,10); imprimircar(1,0,218); imprimircar(36,0,196); imprimircar(37,0,196); imprimircar(1,0,179); esp_tab(0,21); imprimircar(1,0,179); imprimircar(1,0,196); imprimircar(1,0,191);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,73); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); esp_tab(0,1); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,97); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,179); esp_tab(0,43); esp_tab(0,38); imprimircar(1,0,218); imprimircar(13,0,196); imprimircar(1,0,191); esp_tab(0,1); imprimircar(1,0,179);
    esp_tab(1,10); imprimircar(1,0,192); imprimircar(81,0,196); imprimircar(1,0,179); esp_tab(0,13); imprimircar(1,0,179); imprimircar(1,0,196); imprimircar(1,0,217);
    esp_tab(1,92); imprimircar(1,0,192); imprimircar(13,0,196); imprimircar(1,0,217);
}

//função para tela de carregamento;
void telacarregando ()
{
    system("color f0");
    int i;
    gotoxy(40,12);
    char load[]="Carregando, aguarde por favor.", conc[]="  CONCLUIDO!";
    for(i=0;load[i]!='\0';i++)
    {
        Sleep(40);
        printf("%c",load[i]);
    }
    gotoxy(32,14);
    imprimircar(15,50,176);
    imprimircar(7,180,177);
    imprimircar(8,100,177);
    imprimircar(15,60,178);
    gotoxy(48,16);
    for(i=0;conc[i]!='\0';i++)
    {
        Sleep(20);
        printf("%c",conc[i]);
    }
    Sleep(1000);
    system("cls");
}

//funçao para tela de login;
void telalogin ()
{
    system("color 60");
    int i, j, tentativalogin=0;
    char senha[20], nome[20], ch, aux2;
    FUNCIONARIO aux;
    FILE *x;
    //abre o arquivo, se nao tiver nada no arquivo armazena dados do tipo scrutc funcionario com uma senha e um nome padrao para poder logar;
    x=fopen("funcionario.txt","ab+");
    if( (aux2=fgetc(x)) == EOF )
    {
        FUNCIONARIO aux={"admin","123456"}; //Senha padrao para login;
        fwrite(&aux,sizeof(FUNCIONARIO),1,x);
        fclose(x);
    }
    fclose(x);
    //parte visual do login;
    esp_tab(6,40); imprimircar(1,0,201); imprimircar(13,0,205); imprimircar(22,0,205); imprimircar(1,0,187);
    esp_tab(1,40); imprimircar(1,0,186); esp_tab(0,35); imprimircar(1,0,186);
    esp_tab(1,40); imprimircar(1,0,186); esp_tab(0,3); printf("LOGIN RESTRITO P/FUNCIONARIOS "); esp_tab(0,2); imprimircar(1,0,186);
    esp_tab(1,40); imprimircar(1,0,186); esp_tab(0,35); imprimircar(1,0,186);
    esp_tab(1,40); imprimircar(1,100,200); imprimircar(13,0,205); imprimircar(22,0,205); imprimircar(1,0,188);
    esp_tab(2,40); imprimircar(1,100,218); imprimircar(14,0,196); printf(" LOGIN "); imprimircar(14,0,196); imprimircar(1,0,191);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,100,218); imprimircar(23,0,196); imprimircar(1,0,191); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,0,179); esp_tab(0,1); printf("Nome: "); esp_tab(0,16); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,100,192); imprimircar(23,0,196); imprimircar(1,0,217); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,100,218); imprimircar(23,0,196); imprimircar(1,0,191); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,0,179); esp_tab(0,1); printf("Senha: "); esp_tab(0,15); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,0,179); esp_tab(0,5); imprimircar(1,100,192); imprimircar(23,0,196); imprimircar(1,0,217); esp_tab(0,5); imprimircar(1,0,179);
    esp_tab(1,40); imprimircar(1,100,192); imprimircar(35,0,196); imprimircar(1,0,217);
    //laço para verificar se o nome e a senha estao corretos, detalhe que o usuario só pode tentar 3 vezes;
    while(tentativalogin!=4)
    {
        i=0;
        gotoxy(54,14);
        printf("                ");
        gotoxy(55,17);
        printf("               ");
        gotoxy(54,14);
        gets(nome);
        gotoxy(55,17);
        while(ch!=13)
        {
            ch=getch();
            if(ch!=13)
            {
                putch('*');
                senha[i]=ch;
                i++;
            }
        }
        senha[i] = '\0';
        gotoxy(55,18);
        x=fopen("funcionario.txt","rb");
        while( fread(&aux, sizeof(FUNCIONARIO), 1, x)==1 )
        {
            if( !(strcmp(aux.nomefuncionario, nome)) && !(strcmp(aux.senhafuncionario, senha)) )
            {
                gotoxy(35,21);
                printf("                                                     ");
                gotoxy(44,21);
                imprimircar(10,25,177);
                imprimircar(5,110,177);
                imprimircar(15,50,176);
                esp_tab(2,50);
                printf("Login Bem-sucedido!");
                Sleep(1000);
                system("cls");
                fclose(x);
                strcpy(nomelogin,nome);
                return;
            }
        }
        esp_tab(3,39);
        printf("Dados incorretos, tente novamente! (%d/3)",tentativalogin+1);
        ch=0;
        senha[0]='\0';
        tentativalogin++;
        fclose(x);
    }
    system("color 07");
    gotoxy(32,21); imprimircar(1,0,201); imprimircar(51,0,205); imprimircar(1,0,187);
    esp_tab(1,32); imprimircar(1,0,186); esp_tab(0,1); printf("Tentativas excedidas, tente novamente mais tarde!"); esp_tab(0,1); imprimircar(1,0,186);
    esp_tab(1,32); imprimircar(1,0,200); imprimircar(51,0,205); imprimircar(1,0,188);
    Sleep(3000);
    exit(1);
}

//funcao para visualizar os livros;
menulivrosvisualizar()
{
    LIVROS livro;
    FILE *x;
    char first_car;
    int i=0, z=0, y=0, count=0, livros=1;
    system("color 30");
    system("cls");
    gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
    gotoxy(10,2); imprimircar(1,0,179); printf(" LIVROS CADASTRADOS "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); printf(" 1. MENU PRINCIPAL / 2.MENU LIVROS "); imprimircar(1,0,179);
    gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);
    x=fopen("livros.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF)
    {
        system("cls");
        gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
        gotoxy(10,2); imprimircar(1,0,179); printf(" LIVROS CADASTRADOS "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); gotoxy(104,2); imprimircar(1,0,179);
        gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

        gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(41,12); imprimircar(1,0,179); gotoxy(46,12); printf(" LIVROS NAO CADASTRADOS"); gotoxy(73,12); imprimircar(1,0,179);
        gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
        gotoxy(41,14); imprimircar(1,0,179); gotoxy(48,14); printf(" Deseja cadastrar?"); gotoxy(73,14); imprimircar(1,0,179);
        gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(41,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(41,17); imprimircar(1,0,179); gotoxy(46,17); printf("1. SIM"); gotoxy(56,17); imprimircar(1,0,179);
        gotoxy(41,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(58,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(58,17); imprimircar(1,0,179); gotoxy(63,17); printf("2. NAO"); gotoxy(73,17); imprimircar(1,0,179);
        gotoxy(58,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menulivroscadastro(); break;
            case '2': menulivros(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros(); break;
        }
    }
    rewind(x);
    while( fread(&livro, sizeof(LIVROS), 1, x)==1 )
    {
        Sleep(100);
        if(i%2==0)
        {
            z=10;
            gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+6); imprimircar(1,0,179); printf(" Codigo: %s ", livro.codigolivro); esp_tab(0,29-strlen(livro.codigolivro)); printf("L%.4d ",livros); esp_tab(0,1-strlen(livro.codigolivro)); imprimircar(1,0,179);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", livro.nomelivro);  esp_tab(0,37-strlen(livro.nomelivro)); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,179); printf(" Autor: %s ", livro.nomeautor); esp_tab(0,36-strlen(livro.nomeautor)); imprimircar(1,0,179);
            gotoxy(z,y+9); imprimircar(1,0,179); printf(" Area: %s ", livro.area); esp_tab(0,37-strlen(livro.area)); imprimircar(1,0,179);
            gotoxy(z,y+10); imprimircar(1,0,179); printf(" Quant: %.4d ",livro.estoquelivro); esp_tab(0,32); imprimircar(1,0,179);
            gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        else
        {
            z=58;
            gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+6); imprimircar(1,0,179); printf(" Codigo: %s ", livro.codigolivro); esp_tab(0,29-strlen(livro.codigolivro)); printf("L%.4d ",livros); esp_tab(0,1-strlen(livro.codigolivro)); imprimircar(1,0,179);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", livro.nomelivro);  esp_tab(0,37-strlen(livro.nomelivro)); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,179); printf(" Autor: %s ", livro.nomeautor); esp_tab(0,36-strlen(livro.nomeautor)); imprimircar(1,0,179);
            gotoxy(z,y+9); imprimircar(1,0,179); printf(" Area: %s ", livro.area); esp_tab(0,37-strlen(livro.area)); imprimircar(1,0,179);
            gotoxy(z,y+10); imprimircar(1,0,179); printf(" Quant: %.4d ",livro.estoquelivro); esp_tab(0,32); imprimircar(1,0,179);
            gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        i++;
        count++;
        if(count==2)
        {
            count=0;
            y=y+7;
        }
    }
    fclose(x);
    switch(getch())
    {
        case '1':
            menuprincipal();
            break;

        case '2':
            menulivros();
            break;

        default:
            gotoxy(70,2); printf("\aOPCAO INVALIDA, VOLTANDO AO MENU!");
            Sleep(1550);
            menulivros();
            break;

    }
}

//funcao para editar os livros;
menulivroseditar()
{
    EMPRESTIMO emp;
    LIVROS aux;
    FILE *x, *e;
    char first_car, codigo[30];
    int c=0, i;
    system("cls");
    visualdomenu();
    gotoxy(88,8); printf(" EDITAR LIVROS ");
    x=fopen("livros.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" LIVROS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menulivroscadastro(); break;
            case '2': menulivros(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivroseditar(); break;
        }

    }
    fclose(x);

    gotoxy(41,10); printf("Digite o codigo do livro: ");
    gotoxy(40,11); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,12); imprimircar(1,0,179); gotoxy(42,12); printf("CODIGO: "); gotoxy(79,12); imprimircar(1,0,179);
    gotoxy(40,13); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(50,12);
    fflush(stdin);
    gets(codigo);

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    while( fread(&emp, sizeof(EMPRESTIMO), 1, e)==1)
    {
        if( strcmp(emp.codigolivroemprestimo,codigo)==0 )
            i=1;
    }
    if(i==1)
    {
        gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: "); esp_tab(0,29); imprimircar(1,0,179);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Autor:        EMPRESTADO"); esp_tab(0,13); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" Area: "); esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" LIVRO EM EMPRESTIMO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menulivroseditar(); break;
            case '2': menulivros(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros(); break;
        }
    }
    fclose(e);

    x=fopen("livros.txt","rb+");
    rewind(x);
    while( fread(&aux, sizeof(LIVROS), 1, x)==1 )
    {
        if( strcmp(codigo,aux.codigolivro)==0 )
        {
            c=1;
            gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: %s ", aux.codigolivro); esp_tab(0,28-strlen(aux.codigolivro)); imprimircar(1,0,179);
            gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: %s ", aux.nomelivro);  esp_tab(0,30-strlen(aux.nomelivro)); imprimircar(1,0,179);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Autor: %s ", aux.nomeautor); esp_tab(0,29-strlen(aux.nomeautor)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,179); printf(" Area: %s ", aux.area); esp_tab(0,30-strlen(aux.area)); imprimircar(1,0,179);
            gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: %.4d ",aux.estoquelivro); esp_tab(0,25); imprimircar(1,0,179);
            gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);

            gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
            gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf(" LIVRO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
            gotoxy(44,23); imprimircar(1,0,179); gotoxy(51,23); printf(" Deseja modificar?"); gotoxy(76,23); imprimircar(1,0,179);
            gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            gotoxy(94,26); printf("1.SIM/2.NAO"); gotoxy(107,26); fflush(stdin);
            switch(getch())
            {
                case '1':

                    gotoxy(50,15); printf("                            "); gotoxy(50,15); fflush(stdin); gets(aux.codigolivro);
                    gotoxy(48,16); printf("                            "); gotoxy(48,16); fflush(stdin); gets(aux.nomelivro);
                    gotoxy(49,17); printf("                            "); gotoxy(49,17); fflush(stdin); gets(aux.nomeautor);
                    gotoxy(48,18); printf("                            "); gotoxy(48,18); fflush(stdin); gets(aux.area);
                    gotoxy(49,19); printf("                            "); gotoxy(49,19); fflush(stdin); scanf("%d",&aux.estoquelivro);
                    fseek(x, ftell(x)-sizeof(LIVROS), 0);
                    fwrite(&aux, sizeof(LIVROS), 1, x);
                    fclose(x);

                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    gotoxy(44,24); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(53,22); printf("LIVRO EDITADO"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,179); gotoxy(47,23); printf("Deseja editar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
                    gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin); gotoxy(107,26);
                    switch(getch())
                    {
                        case '1': menulivroseditar(); break;
                        case '2': menulivros(); break;
                        default:

                            gotoxy(44,21); printf("                                 ");
                            gotoxy(44,22); printf("                                 ");
                            gotoxy(44,23); printf("                                 ");
                            gotoxy(44,24); printf("                                 ");
                            Sleep(100);
                            gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                            gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                            gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                            gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                            Sleep(1500);
                            menulivros();
                            break;
                    }

                case '2':

                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    gotoxy(44,24); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("LIVRO NAO EDITADO"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,179); gotoxy(51,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                    gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menulivros();
                    break;

                default:

                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    gotoxy(44,24); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                    gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menulivros(); break;
            }
        }
    }
    if(c==0)
    {
        gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: "); esp_tab(0,29); imprimircar(1,0,179);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Autor: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" Area: "); esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" LIVRO NAO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menulivroseditar(); break;
            case '2': menulivros(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros(); break;
        }
    }
}

//funcao para remover os livros;
menulivrosremover()
{
    EMPRESTIMO emp;
    LIVROS aux[100], aux2[100];
    FILE *x, *e;
    char first_car, codigo[30];
    int i=0, i2=0, c=0, j;
    system("cls");
    visualdomenu();
    gotoxy(87,8); printf(" REMOVER LIVROS ");

    x=fopen("livros.txt","rb");
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" LIVROS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menulivroscadastro(); break;
            case '2': menulivros(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivrosremover(); break;
        }

    }

    gotoxy(41,10); printf("Digite o codigo do livro: ");
    gotoxy(40,11); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,12); imprimircar(1,0,179); gotoxy(42,12); printf("CODIGO: "); gotoxy(79,12); imprimircar(1,0,179);
    gotoxy(40,13); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(50,12);
    fflush(stdin);
    gets(codigo);

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    while( fread(&emp, sizeof(EMPRESTIMO), 1, e)==1)
    {
        if( strcmp(emp.codigolivroemprestimo,codigo)==0 )
            i=1;
    }
    if(i==1)
    {
        gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: "); esp_tab(0,29); imprimircar(1,0,179);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Autor:        EMPRESTADO"); esp_tab(0,13); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" Area: "); esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" LIVRO EM EMPRESTIMO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menulivroseditar(); break;
            case '2': menulivros(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros(); break;
        }
    }
    fclose(e);

    rewind(x);
    while( fread(&aux[i], sizeof(LIVROS), 1, x)==1 )
    {
        if( strcmp(codigo,aux[i].codigolivro)==0 )
        {
            gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: %s ", aux[i].codigolivro); esp_tab(0,28-strlen(aux[i].codigolivro)); imprimircar(1,0,179);
            gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: %s ", aux[i].nomelivro);  esp_tab(0,30-strlen(aux[i].nomelivro)); imprimircar(1,0,179);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Autor: %s ", aux[i].nomeautor); esp_tab(0,29-strlen(aux[i].nomeautor)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,179); printf(" Area: %s ", aux[i].area); esp_tab(0,30-strlen(aux[i].area)); imprimircar(1,0,179);
            gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: %.4d ",aux[i].estoquelivro); esp_tab(0,25); imprimircar(1,0,179);
            gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
            c=1;
        }
        i++;
    }
    fclose(x);
    if(c==1)
    {
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf(" LIVRO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf(" Deseja excluir?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        gotoxy(107,26);
        switch(getch())
        {
            case '1':

                x=fopen("livros.txt","wb");
                rewind(x);
                for(j=0;j<i;j++)
                {
                    if( strcmp(codigo,aux[j].codigolivro)!=0 )
                    {
                        aux2[i2]=aux[j];
                        i2++;
                    }
                }
                for(j=0;j<i2;j++)
                {
                    fwrite(&aux2[j], sizeof(LIVROS), 1, x);
                }
                fclose(x);

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(53,22); printf("LIVRO REMOVIDO"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf("Deseja remover novamente?"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin);
                switch(getch())
                {
                    case '1': menulivrosremover(); break;
                    case '2': menulivros(); break;
                    default:

                        gotoxy(44,21); printf("                                 ");
                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        gotoxy(44,24); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                        gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menulivros();
                        break;
                }

            case '2':

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("LIVRO NAO EXCLUIDO"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(51,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros();
                break;

            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivros(); break;
        }
    }
    else
    {
        gotoxy(40,14); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,15); imprimircar(1,0,179); printf(" Codigo: "); esp_tab(0,29); imprimircar(1,0,179);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Autor: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" Area: "); esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,179); printf(" Quant: "); esp_tab(0,30); imprimircar(1,0,179);
        gotoxy(40,20); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" LIVRO NAO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menulivrosremover(); break;
            case '2': menulivros(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menulivrosremover(); break;

        }
    }
}

//funcao para cadastrar os livros;
menulivroscadastro()
{
    char op='0';
    LIVROS livro;
    FILE *x;
    system("cls");
    visualdomenu();
    gotoxy(87,8); printf(" CADASTRAR LIVROS ");
    gotoxy(20,11); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(20,12); imprimircar(1,0,179); esp_tab(0,1); printf("Codigo: "); esp_tab(0,35); imprimircar(1,0,179);
    gotoxy(20,13); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(20,14); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(20,15); imprimircar(1,0,179); esp_tab(0,1); printf("Nome: "); esp_tab(0,37); imprimircar(1,0,179);
    gotoxy(20,16); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(20,17); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(20,18); imprimircar(1,0,179); esp_tab(0,1); printf("Autor: "); esp_tab(0,36); imprimircar(1,0,179);
    gotoxy(20,19); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(20,20); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(20,21); imprimircar(1,0,179); esp_tab(0,1); printf("Quantidade: "); esp_tab(0,31); imprimircar(1,0,179);
    gotoxy(20,22); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(95,26); imprimircar(10,0,0); gotoxy(94,26); printf("           ");
    gotoxy(70,11); imprimircar(1,0,218); printf(" AREA ");imprimircar(25,0,196); imprimircar(1,0,191);
    gotoxy(70,12); imprimircar(1,0,179); esp_tab(0,1); esp_tab(0,30); imprimircar(1,0,179);
    gotoxy(70,12); imprimircar(1,0,179); esp_tab(0,2); printf("1. Matematica"); esp_tab(0,3); printf("6. Logica"); esp_tab(0,4); imprimircar(1,0,179);
    gotoxy(70,13); imprimircar(1,0,179); esp_tab(0,2); printf("2. Calculo"); esp_tab(0,6); printf("7. Vetores"); esp_tab(0,3); imprimircar(1,0,179);
    gotoxy(70,14); imprimircar(1,0,179); esp_tab(0,2); printf("3. Computacao"); esp_tab(0,3); printf("8. OAC"); esp_tab(0,7); imprimircar(1,0,179);
    gotoxy(70,15); imprimircar(1,0,179); esp_tab(0,2); printf("4. Engenharia"); esp_tab(0,3); printf("9. TCS"); esp_tab(0,7); imprimircar(1,0,179);
    gotoxy(70,16); imprimircar(1,0,179); esp_tab(0,2); printf("5. Outra "); esp_tab(0,20); imprimircar(1,0,179);
    gotoxy(70,17); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
    gotoxy(30,12); fflush(stdin); gets(livro.codigolivro);
    gotoxy(28,15); fflush(stdin); gets(livro.nomelivro);
    gotoxy(29,18); fflush(stdin); gets(livro.nomeautor);
    gotoxy(34,21); fflush(stdin); scanf("%d",&livro.estoquelivro);
    gotoxy(82,16);
    fflush(stdin);
    op=getch();
    while(op<=48 || op>=59)
    {
        gotoxy(69,19); printf("                                  ");
        gotoxy(69,20); printf("                                  ");
        gotoxy(69,21); printf("                                  ");
        gotoxy(69,22); printf("                                  ");
        Sleep(50);
        gotoxy(70,19); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(70,20); imprimircar(1,0,186); gotoxy(102,20); imprimircar(1,0,186);
        gotoxy(70,21); imprimircar(1,0,186); gotoxy(102,21); imprimircar(1,0,186);
        gotoxy(70,22); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
        gotoxy(79,20); printf("OPCAO INVALIDA!");
        gotoxy(79,21); printf("Tente novamente");
        gotoxy(82,16);
        fflush(stdin);
        op=getch();
    }
    switch(op)
    {
        case '1': strcpy(livro.area,"Matematica"); break;
        case '2': strcpy(livro.area,"Calculo"); break;
        case '3': strcpy(livro.area,"Computacao"); break;
        case '4': strcpy(livro.area,"Engenharia"); break;
        case '5': fflush(stdin); gotoxy(81,16); printf(": "); gets(livro.area); break;
        case '6': strcpy(livro.area,"Logica"); break;
        case '7': strcpy(livro.area,"Vetores"); break;
        case '8': strcpy(livro.area,"OAC"); break;
        case '9': strcpy(livro.area,"TCS"); break;
    }
    fflush(stdin);

    //Salvar os dados da struct livro no arquivo;
    x=fopen("livros.txt","ab+");
    if( fwrite(&livro, sizeof(LIVROS), 1, x) )
    {
        gotoxy(70,19); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(70,20); imprimircar(1,0,186); gotoxy(78,20); printf("LIVRO ADICIONADO!"); gotoxy(102,20); imprimircar(1,0,186);
        gotoxy(70,21); imprimircar(1,0,186); gotoxy(73,21); printf("Deseja adicionar novamente?"); gotoxy(102,21); imprimircar(1,0,186);
        gotoxy(70,22); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    else
    {
        gotoxy(70,19); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(70,20); imprimircar(1,0,186); gotoxy(76,20); printf("FALHA AO ADICIONAR!"); gotoxy(102,20); imprimircar(1,0,186);
        gotoxy(70,21); imprimircar(1,0,186); gotoxy(73,21); printf("Deseja tentar novamente?"); gotoxy(102,21); imprimircar(1,0,186);
        gotoxy(70,22); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    fclose(x);

    gotoxy(95,26); imprimircar(10,0,0); gotoxy(94,26); printf("1.SIM/2.NAO"); op='0';
    gotoxy(107,26);
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1': menulivroscadastro(); break;
        case '2': menulivros(); break;
        default: gotoxy(70,23); printf("Opcao invalida, voltando ao menu!"); Sleep(2500); menulivros();
    }
}

//funcao menu dos livros;
menulivros()
{
    int i;
    char op;
    system("cls");
    visualdomenu();
    gotoxy(91,8); printf(" LIVROS ");
    gotoxy(30,11); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,12); imprimircar(1,0,179); esp_tab(0,2); printf("1. Cadastrar Livro(s)"); esp_tab(0,1); imprimircar(1,0,179);
    gotoxy(30,13); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,14); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,15); imprimircar(1,0,179); esp_tab(0,2); printf("2. Editar Livro(s)"); esp_tab(0,4); imprimircar(1,0,179);
    gotoxy(30,16); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,17); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,18); imprimircar(1,0,179); esp_tab(0,2); printf("3. Remover Livro(s)"); esp_tab(0,3); imprimircar(1,0,179);
    gotoxy(30,19); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,20); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,21); imprimircar(1,0,179); esp_tab(0,2); printf("4. Visualizar Livro(s)"); imprimircar(1,0,179);
    gotoxy(30,22); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(95,26); imprimircar(10,0,0); gotoxy(96,26); printf("5. MENU");
    gotoxy(65,14); printf("REGRA 1: Um aluno podera no"); gotoxy(65,15); printf("maximo realizar 2 emprestimos!");
    gotoxy(65,17); printf("REGRA 2: Um aluno podera passar"); gotoxy(65,18); printf("no maximo 10 dias com o livro!");
    gotoxy(107,26);
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1':
            fflush(stdin);
            menulivroscadastro();
            break;

        case '2':
            fflush(stdin);
            menulivroseditar();
            break;

        case '3':
            fflush(stdin);
            menulivrosremover();
            break;

        case '4':
            fflush(stdin);
            menulivrosvisualizar();
            break;

        case '5':
            fflush(stdin);
            menuprincipal();
            break;

        default:
            gotoxy(73,3); imprimircar(1,0,201); imprimircar(34,0,205); imprimircar(1,0,187);
            gotoxy(73,4); imprimircar(1,0,186); gotoxy(75,4); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!"); esp_tab(0,1); imprimircar(1,0,186);
            gotoxy(73,5); imprimircar(1,0,200); imprimircar(34,0,205); imprimircar(1,0,188);
            Sleep(1250);
            menuprincipal(); break;
    }
}

//funcao para visualizar os alunos;
menualunosvisualizar()
{
    ALUNOS aluno;
    FILE *x;
    char first_car;
    int i=0, z=0, y=0, count=0, livros=1;
    system("color 30");
    system("cls");
    gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
    gotoxy(10,2); imprimircar(1,0,179); printf(" ALUNOS CADASTRADOS "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); printf(" 1. MENU PRINCIPAL / 2.MENU ALUNOS "); imprimircar(1,0,179);
    gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);
    x=fopen("alunos.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF)
    {
        system("cls");
        gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
        gotoxy(10,2); imprimircar(1,0,179); printf(" ALUNOS CADASTRADOS "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); gotoxy(104,2); imprimircar(1,0,179);
        gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

        gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(41,12); imprimircar(1,0,179); gotoxy(46,12); printf(" ALUNOS NAO CADASTRADOS"); gotoxy(73,12); imprimircar(1,0,179);
        gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
        gotoxy(41,14); imprimircar(1,0,179); gotoxy(48,14); printf(" Deseja cadastrar?"); gotoxy(73,14); imprimircar(1,0,179);
        gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(41,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(41,17); imprimircar(1,0,179); gotoxy(46,17); printf("1. SIM"); gotoxy(56,17); imprimircar(1,0,179);
        gotoxy(41,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(58,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(58,17); imprimircar(1,0,179); gotoxy(63,17); printf("2. NAO"); gotoxy(73,17); imprimircar(1,0,179);
        gotoxy(58,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menualunoscadastro(); break;
            case '2': menualunos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos(); break;
        }
    }
    rewind(x);
    while( fread(&aluno, sizeof(ALUNOS), 1, x)==1 )
    {
        Sleep(100);
        if(i%2==0)
        {
            z=10;
            gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula: %s ", aluno.codigoaluno); esp_tab(0,26-strlen(aluno.codigoaluno)); printf("A%.4d ",livros); esp_tab(0,1-strlen(aluno.codigoaluno)); imprimircar(1,0,179);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", aluno.nomealuno);  esp_tab(0,37-strlen(aluno.nomealuno)); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,179); printf(" CPF: %s ", aluno.cpfaluno); esp_tab(0,38-strlen(aluno.cpfaluno)); imprimircar(1,0,179);
            gotoxy(z,y+9); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        else
        {
            z=58;
            gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula: %s ", aluno.codigoaluno); esp_tab(0,26-strlen(aluno.codigoaluno)); printf("A%.4d ",livros); esp_tab(0,1-strlen(aluno.codigoaluno)); imprimircar(1,0,179);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", aluno.nomealuno);  esp_tab(0,37-strlen(aluno.nomealuno)); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,179); printf(" CPF: %s ", aluno.cpfaluno); esp_tab(0,38-strlen(aluno.cpfaluno)); imprimircar(1,0,179);
            gotoxy(z,y+9); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        i++;
        count++;
        if(count==2)
        {
            count=0;
            y=y+5;
        }
    }
    fclose(x);
    switch(getch())
    {
        case '1':
            menuprincipal();
            break;

        case '2':
            menualunos();
            break;

        default:
            gotoxy(70,2); printf("\aOPCAO INVALIDA, VOLTANDO AO MENU!");
            Sleep(1550);
            menualunos();
            break;
    }
}

//funcao para editar os alunos;
menualunoseditar()
{
    EMPRESTIMO emp;
    ALUNOS aux;
    FILE *x, *e;
    char first_car, codigo[30];
    int c=0, i;
    system("cls");
    visualdomenu();
    gotoxy(88,8); printf(" EDITAR ALUNOS ");
    x=fopen("alunos.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" ALUNOS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menualunoscadastro(); break;
            case '2': menualunos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunoseditar(); break;
        }

    }
    fclose(x);

    gotoxy(41,11); printf("Digite a matricula do aluno: ");
    gotoxy(40,12); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,13); imprimircar(1,0,179); gotoxy(42,13); printf("MATRICULA: "); gotoxy(79,13); imprimircar(1,0,179);
    gotoxy(40,14); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(53,13);
    fflush(stdin);
    gets(codigo);

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    while( fread(&emp, sizeof(EMPRESTIMO), 1, e)==1)
    {
        if( strcmp(emp.codigoalunoemprestimo,codigo)==0 )
            i=1;
    }
    if(i==1)
    {
        gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome:         EMPRESTIMO");  esp_tab(0,13); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: "); esp_tab(0,32); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" ALUNO EM EMPRESTIMO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menualunoseditar(); break;
            case '2': menualunos(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos(); break;
        }
    }
    fclose(e);

    x=fopen("alunos.txt","rb+");
    rewind(x);
    while( fread(&aux, sizeof(ALUNOS), 1, x)==1 )
    {
        if( strcmp(codigo,aux.codigoaluno)==0 )
        {
            c=1;
            gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: %s ", aux.codigoaluno); esp_tab(0,25-strlen(aux.codigoaluno)); imprimircar(1,0,179);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: %s ", aux.nomealuno);  esp_tab(0,30-strlen(aux.nomealuno)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: %s ", aux.cpfaluno); esp_tab(0,31-strlen(aux.cpfaluno)); imprimircar(1,0,179);
            gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);

            gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
            gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf(" ALUNO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
            gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf(" Deseja modificar?"); gotoxy(76,22); imprimircar(1,0,179);
            gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            gotoxy(94,26); printf("1.SIM/2.NAO"); gotoxy(107,26); fflush(stdin);
            switch(getch())
            {
                case '1':

                    gotoxy(52,16); printf("                          "); gotoxy(53,16); fflush(stdin); gets(aux.codigoaluno);
                    gotoxy(48,17); printf("                          "); gotoxy(48,17); fflush(stdin); gets(aux.nomealuno);
                    gotoxy(47,18); printf("                          "); gotoxy(47,18); fflush(stdin); gets(aux.cpfaluno);
                    fseek(x, ftell(x)-sizeof(ALUNOS), 0);
                    fwrite(&aux, sizeof(ALUNOS), 1, x);
                    fclose(x);

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(54,21); printf("ALUNO EDITADO"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf("Deseja editar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin); gotoxy(107,26);
                    switch(getch())
                    {
                        case '1': menualunoseditar(); break;
                        case '2': menualunos(); break;
                        default:

                            gotoxy(44,20); printf("                                 ");
                            gotoxy(44,21); printf("                                 ");
                            gotoxy(44,22); printf("                                 ");
                            gotoxy(44,23); printf("                                 ");
                            Sleep(100);
                            gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                            gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                            gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                            gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                            Sleep(1500);
                            menualunos();
                            break;
                    }

                case '2':

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf("ALUNO NAO EDITADO"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menualunos();
                    break;

                default:

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menualunos(); break;
            }
        }
    }
    if(c==0)
    {
        gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: "); esp_tab(0,32); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); printf("                                 ");
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        Sleep(100);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" ALUNO NAO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menualunoseditar(); break;
            case '2': menualunos(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos(); break;
        }
    }
}

//funcao para remover os alunos;
menualunosremover()
{
    EMPRESTIMO emp;
    ALUNOS aux[100], aux2[100];
    FILE *x, *e;
    char first_car, codigo[30];
    int i=0, i2=0, c=0, j;
    system("cls");
    visualdomenu();
    gotoxy(87,8); printf(" REMOVER ALUNOS ");

    x=fopen("alunos.txt","rb");
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" ALUNOS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menualunoscadastro(); break;
            case '2': menualunos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunosremover(); break;
        }

    }

    gotoxy(41,11); printf("Digite a matricula do aluno: ");
    gotoxy(40,12); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,13); imprimircar(1,0,179); gotoxy(42,13); printf("MATRICULA: "); gotoxy(79,13); imprimircar(1,0,179);
    gotoxy(40,14); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(53,13);
    fflush(stdin);
    gets(codigo);

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    while( fread(&emp, sizeof(EMPRESTIMO), 1, e)==1)
    {
        if( strcmp(emp.codigoalunoemprestimo,codigo)==0 )
            i=1;
    }
    if(i==1)
    {
        gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome:         EMPRESTIMO");  esp_tab(0,13); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: "); esp_tab(0,32); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" ALUNO EM EMPRESTIMO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menualunoseditar(); break;
            case '2': menualunos(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos(); break;
        }
    }
    fclose(e);

    rewind(x);
    while( fread(&aux[i], sizeof(ALUNOS), 1, x)==1 )
    {
        if( strcmp(codigo,aux[i].codigoaluno)==0 )
        {
            gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: %s ", aux[i].codigoaluno); esp_tab(0,25-strlen(aux[i].codigoaluno)); imprimircar(1,0,179);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: %s ", aux[i].nomealuno);  esp_tab(0,30-strlen(aux[i].nomealuno)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: %s ", aux[i].cpfaluno); esp_tab(0,31-strlen(aux[i].cpfaluno)); imprimircar(1,0,179);
            gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
            c=1;
        }
        i++;
    }
    fclose(x);

    if(c==1)
    {
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf(" ALUNO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf(" Deseja excluir?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        gotoxy(107,26);
        switch(getch())
        {
            case '1':

                x=fopen("alunos.txt","wb");
                rewind(x);
                for(j=0;j<i;j++)
                {
                    if( strcmp(codigo,aux[j].codigoaluno)!=0 )
                    {
                        aux2[i2]=aux[j];
                        i2++;
                    }
                }
                for(j=0;j<i2;j++)
                {
                    fwrite(&aux2[j], sizeof(ALUNOS), 1, x);
                }
                fclose(x);

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(53,21); printf("ALUNO REMOVIDO"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf("Deseja remover novamente?"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin);
                switch(getch())
                {
                    case '1': menualunosremover(); break;
                    case '2': menualunos(); break;
                    default:

                        gotoxy(44,20); printf("                                 ");
                        gotoxy(44,21); printf("                                 ");
                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menualunos();
                        break;
                }

            case '2':

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf("ALUNO NAO EXCLUIDO"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos();
                break;

            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunos(); break;
        }
    }
    else
    {
        gotoxy(40,15); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,16); imprimircar(1,0,179); printf(" Matricula: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,179); printf(" CPF: "); esp_tab(0,32); imprimircar(1,0,179);
        gotoxy(40,19); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); printf("                                 ");
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        Sleep(100);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" ALUNO NAO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menualunosremover(); break;
            case '2': menualunos(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menualunosremover(); break;

        }
    }
}

//funcao para cadastrar os alunos;
menualunoscadastro()
{
    char op='0';
    ALUNOS aluno;
    FILE *x;
    system("cls");
    visualdomenu();
    gotoxy(87,8); printf(" CADASTRAR ALUNOS ");

    gotoxy(38,11); printf("Preencha as informacoes do aluno abaixo: ");
    gotoxy(37,12); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,13); imprimircar(1,0,179); esp_tab(0,1); printf("Matricula: "); esp_tab(0,32); imprimircar(1,0,179);
    gotoxy(37,14); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,15); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,16); imprimircar(1,0,179); esp_tab(0,1); printf("Nome: "); esp_tab(0,37); imprimircar(1,0,179);
    gotoxy(37,17); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,18); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,19); imprimircar(1,0,179); esp_tab(0,1); printf("CPF: "); esp_tab(0,38); imprimircar(1,0,179);
    gotoxy(37,20); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(50,13); fflush(stdin); gets(aluno.codigoaluno);
    gotoxy(45,16); fflush(stdin); gets(aluno.nomealuno);
    gotoxy(44,19); fflush(stdin); gets(aluno.cpfaluno);
    gotoxy(82,16);

    fflush(stdin);

    //Salvar os dados da struct livro no arquivo;
    x=fopen("alunos.txt","ab+");
    if( fwrite(&aluno, sizeof(ALUNOS), 1, x) )
    {
        gotoxy(44,21); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(44,22); imprimircar(1,0,186); gotoxy(52,22); printf("ALUNO ADICIONADO!"); gotoxy(76,22); imprimircar(1,0,186);
        gotoxy(44,23); imprimircar(1,0,186); gotoxy(47,23); printf("Deseja adicionar novamente?"); gotoxy(76,23); imprimircar(1,0,186);
        gotoxy(44,24); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    else
    {
        gotoxy(44,21); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(44,22); imprimircar(1,0,186); gotoxy(52,22); printf("FALHA AO ADICIONAR!"); gotoxy(76,22); imprimircar(1,0,186);
        gotoxy(44,23); imprimircar(1,0,186); gotoxy(49,23); printf("Deseja tentar novamente?"); gotoxy(76,23); imprimircar(1,0,186);
        gotoxy(44,24); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    fclose(x);

    gotoxy(95,26); imprimircar(10,0,0); gotoxy(94,26); printf("1.SIM/2.NAO"); gotoxy(107,26); op='0';
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1': menualunoscadastro(); break;
        case '2': menualunos(); break;
        default: gotoxy(70,23); printf("Opcao invalida, voltando ao menu!"); Sleep(2500); menualunos();
    }
}

//funcao menu dos alunos;
menualunos()
{
    int i;
    char op;
    system("cls");
    visualdomenu();
    gotoxy(91,8); printf(" ALUNOS ");
    gotoxy(30,11); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,12); imprimircar(1,0,179); esp_tab(0,2); printf("1. Cadastrar Aluno(s)"); esp_tab(0,1); imprimircar(1,0,179);
    gotoxy(30,13); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,14); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,15); imprimircar(1,0,179); esp_tab(0,2); printf("2. Editar Aluno(s)"); esp_tab(0,4); imprimircar(1,0,179);
    gotoxy(30,16); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,17); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,18); imprimircar(1,0,179); esp_tab(0,2); printf("3. Remover Aluno(s)"); esp_tab(0,3); imprimircar(1,0,179);
    gotoxy(30,19); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(30,20); imprimircar(1,0,218); imprimircar(24,0,196); imprimircar(1,0,191);
    gotoxy(30,21); imprimircar(1,0,179); esp_tab(0,2); printf("4. Visualizar Aluno(s)"); imprimircar(1,0,179);
    gotoxy(30,22); imprimircar(1,0,192); imprimircar(24,0,196); imprimircar(1,0,217);
    gotoxy(95,26); imprimircar(10,0,0); gotoxy(96,26); printf("5. MENU");
    gotoxy(65,14); printf("REGRA 1: Um aluno podera no"); gotoxy(65,15); printf("maximo realizar 2 emprestimos!");
    gotoxy(65,17); printf("REGRA 2: Um aluno podera passar"); gotoxy(65,18); printf("no maximo 10 dias com o livro!");
    gotoxy(107,26);
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1':
            fflush(stdin);
            menualunoscadastro();
            break;

        case '2':
            fflush(stdin);
            menualunoseditar();
            break;

        case '3':
            fflush(stdin);
            menualunosremover();
            break;

        case '4':
            fflush(stdin);
            menualunosvisualizar();
            break;

        case '5':
            fflush(stdin);
            menuprincipal();
            break;

        default:
            gotoxy(73,3); imprimircar(1,0,201); imprimircar(34,0,205); imprimircar(1,0,187);
            gotoxy(73,4); imprimircar(1,0,186); gotoxy(75,4); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!"); esp_tab(0,1); imprimircar(1,0,186);
            gotoxy(73,5); imprimircar(1,0,200); imprimircar(34,0,205); imprimircar(1,0,188);
            Sleep(1250);
            menuprincipal(); break;
    }
}

//funcao para visualizar os funcionarios;
menufuncionariosvisualizar()
{
    FUNCIONARIO aluno;
    FILE *x;
    char first_car;
    int i=0, z=0, y=0, count=0, livros=1;
    system("color 30");
    system("cls");
    gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
    gotoxy(10,2); imprimircar(1,0,179); printf(" FUNC. CADASTRADOS  "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); printf("  1. MENU PRINCIPAL / 2.MENU FUNC. "); imprimircar(1,0,179);
    gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);
    x=fopen("funcionario.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF)
    {
        system("cls");
        gotoxy(10,1); imprimircar(1,0,218); imprimircar(20,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
        gotoxy(10,2); imprimircar(1,0,179); printf(" FUNC. CADASTRADOS  "); imprimircar(1,0,179); imprimircar(36,0,196); imprimircar(1,0,179); gotoxy(104,2); imprimircar(1,0,179);
        gotoxy(10,3); imprimircar(1,0,192); imprimircar(20,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

        gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(41,12); imprimircar(1,0,179); gotoxy(43,12); printf(" FUNCIONARIOS NAO CADASTRADOS"); gotoxy(73,12); imprimircar(1,0,179);
        gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
        gotoxy(41,14); imprimircar(1,0,179); gotoxy(48,14); printf(" Deseja cadastrar?"); gotoxy(73,14); imprimircar(1,0,179);
        gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(41,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(41,17); imprimircar(1,0,179); gotoxy(46,17); printf("1. SIM"); gotoxy(56,17); imprimircar(1,0,179);
        gotoxy(41,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(58,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(58,17); imprimircar(1,0,179); gotoxy(63,17); printf("2. NAO"); gotoxy(73,17); imprimircar(1,0,179);
        gotoxy(58,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menufuncionarioscadastro(); break;
            case '2': menufuncionarios(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionarios(); break;
        }
    }
    rewind(x);
    while( fread(&aluno, sizeof(FUNCIONARIO), 1, x)==1 )
    {
        Sleep(100);
        if(i%2==0)
        {
            z=10;
            gotoxy(z,y+6); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", aluno.nomefuncionario); esp_tab(0,31-strlen(aluno.nomefuncionario)); printf("F%.4d ", livros); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        else
        {
            z=58;
            gotoxy(z,y+6); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
            gotoxy(z,y+7); imprimircar(1,0,179); printf(" Nome: %s ", aluno.nomefuncionario); esp_tab(0,31-strlen(aluno.nomefuncionario)); printf("F%.4d ", livros); imprimircar(1,0,179);
            gotoxy(z,y+8); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);
            livros++;
        }
        i++;
        count++;
        if(count==2)
        {
            count=0;
            y=y+3;
        }
    }
    fclose(x);
    switch(getch())
    {
        case '1':
            menuprincipal();
            break;

        case '2':
            menufuncionarios();
            break;

        default:
            gotoxy(70,2); printf("\aOPCAO INVALIDA, VOLTANDO AO MENU!");
            Sleep(1550);
            menufuncionarios();
            break;
    }
}

//funcao para editar os funcionarios;
menufuncionarioseditar()
{
    FUNCIONARIO aux;
    FILE *x;
    char first_car, codigo[30];
    int c=0;
    system("cls");
    visualdomenu();
    gotoxy(88,8); printf("  EDITAR FUNC. ");
    x=fopen("funcionario.txt","rb");
    rewind(x);
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" FUNC. NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        switch(getch())
        {
            case '1': menufuncionarioscadastro(); break;
            case '2': menufuncionarios(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionarioseditar(); break;
        }

    }
    fclose(x);

    gotoxy(41,11); printf("Digite o nome do funcionario: ");
    gotoxy(40,12); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,13); imprimircar(1,0,179); gotoxy(42,13); printf("NOME: "); gotoxy(79,13); imprimircar(1,0,179);
    gotoxy(40,14); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(48,13);
    fflush(stdin);
    gets(codigo);

    x=fopen("funcionario.txt","rb+");
    rewind(x);
    while( fread(&aux, sizeof(FUNCIONARIO), 1, x)==1 )
    {
        if( strcmp(codigo,aux.nomefuncionario)==0 )
        {
            c=1;
            gotoxy(40,16); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: %s ", aux.nomefuncionario);  esp_tab(0,30-strlen(aux.nomefuncionario)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);

            gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
            gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf(" FUNC. ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
            gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf(" Deseja modificar?"); gotoxy(76,22); imprimircar(1,0,179);
            gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            gotoxy(94,26); printf("1.SIM/2.NAO"); gotoxy(107,26); fflush(stdin);
            switch(getch())
            {
                case '1':

                    gotoxy(48,17); printf("                          "); gotoxy(48,17); fflush(stdin); gets(aux.nomefuncionario);
                    fseek(x, ftell(x)-sizeof(FUNCIONARIO), 0);
                    fwrite(&aux, sizeof(FUNCIONARIO), 1, x);
                    fclose(x);

                    if(strcmp(codigo,nomelogin)==0)
                        strcpy(nomelogin,aux.nomefuncionario);

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(54,21); printf("FUNC. EDITADO"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf("Deseja editar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin); gotoxy(107,26);
                    switch(getch())
                    {
                        case '1': menufuncionarioseditar(); break;
                        case '2': menufuncionarios(); break;
                        default:

                            gotoxy(44,20); printf("                                 ");
                            gotoxy(44,21); printf("                                 ");
                            gotoxy(44,22); printf("                                 ");
                            gotoxy(44,23); printf("                                 ");
                            Sleep(100);
                            gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                            gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                            gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                            gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                            Sleep(1500);
                            menufuncionarios();
                            break;
                    }

                case '2':

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf("FUNC. NAO EDITADO"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menufuncionarios();
                    break;

                default:

                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menufuncionarios(); break;
            }
        }
    }
    if(c==0)
    {
        gotoxy(40,16); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); printf("                                 ");
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        Sleep(100);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" FUNC. NAO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menufuncionarioseditar(); break;
            case '2': menufuncionarios(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionarios(); break;
        }
    }
}

//funcao para remover os funcionarios;
menufuncionariosremover()
{
    FUNCIONARIO aux[100], aux2[100];
    FILE *x;
    char first_car, codigo[30];
    int i=0, i2=0, c=0, j;
    system("cls");
    visualdomenu();
    gotoxy(87,8); printf("  REMOVER FUNC. ");

    x=fopen("funcionario.txt","rb");
    if( (x==NULL) || (first_car=fgetc(x)) == EOF )
    {
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" FUNC. NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menufuncionarioscadastro(); break;
            case '2': menufuncionarios(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionariosremover(); break;
        }

    }

    gotoxy(41,11); printf("Digite o nome do funcionario: ");
    gotoxy(40,12); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
    gotoxy(40,13); imprimircar(1,0,179); gotoxy(42,13); printf("NOME: "); gotoxy(79,13); imprimircar(1,0,179);
    gotoxy(40,14); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
    gotoxy(48,13);
    fflush(stdin);
    gets(codigo);

    rewind(x);
    while( fread(&aux[i], sizeof(FUNCIONARIO), 1, x)==1 )
    {
        if( strcmp(codigo,aux[i].nomefuncionario)==0 )
        {
            gotoxy(40,16); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
            gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: %s ", aux[i].nomefuncionario);  esp_tab(0,30-strlen(aux[i].nomefuncionario)); imprimircar(1,0,179);
            gotoxy(40,18); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
            c=1;
        }
        i++;
    }
    fclose(x);

    if(c==1)
    {
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf(" FUNC. ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf(" Deseja excluir?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        gotoxy(107,26);
        switch(getch())
        {
            case '1':

                if(strcmp(codigo,nomelogin)==0)
                {
                    gotoxy(44,20); printf("                                 ");
                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,21); imprimircar(1,0,179); gotoxy(53,21); printf("FALHA AO REMOVER"); gotoxy(76,21); imprimircar(1,0,179);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(59-strlen(codigo),22); printf("%s esta logado",codigo); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin); Sleep(2500);
                    menufuncionarios();
                }

                x=fopen("funcionario.txt","wb");
                rewind(x);
                for(j=0;j<i;j++)
                {
                    if( strcmp(codigo,aux[j].nomefuncionario)!=0 )
                    {
                        aux2[i2]=aux[j];
                        i2++;
                    }
                }
                for(j=0;j<i2;j++)
                {
                    fwrite(&aux2[j], sizeof(FUNCIONARIO), 1, x);
                }
                fclose(x);

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(53,21); printf("FUNC. REMOVIDO"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf("Deseja remover novamente?"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin);
                switch(getch())
                {
                    case '1': menufuncionariosremover(); break;
                    case '2': menufuncionarios(); break;
                    default:

                        gotoxy(44,20); printf("                                 ");
                        gotoxy(44,21); printf("                                 ");
                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menufuncionarios();
                        break;
                }

            case '2':

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(51,21); printf("FUNC. NAO EXCLUIDO"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionarios();
                break;

            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionarios(); break;
        }
    }
    else
    {
        gotoxy(40,16); imprimircar(1,0,218); imprimircar(38,0,196); imprimircar(1,0,191);
        gotoxy(40,17); imprimircar(1,0,179); printf(" Nome: ");  esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(40,18); imprimircar(1,0,192); imprimircar(38,0,196); imprimircar(1,0,217);
        gotoxy(44,20); printf("                                 ");
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        Sleep(100);
        gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,21); imprimircar(1,0,179); gotoxy(49,21); printf(" FUNC. NAO ENCONTRADO!"); gotoxy(76,21); imprimircar(1,0,179);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf(" Deseja buscar novamente?"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menufuncionariosremover(); break;
            case '2': menufuncionarios(); break;
            default:

                gotoxy(44,20); printf("                                 ");
                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                Sleep(100);
                gotoxy(44,20); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,21); imprimircar(1,0,179); gotoxy(52,21); printf("OPCAO INVALIDA!"); gotoxy(76,21); imprimircar(1,0,179);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf("Voltando ao menu..."); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menufuncionariosremover(); break;
        }
    }
}

//funcao para cadastrar os funcionarios;
menufuncionarioscadastro()
{
    char op='0', senha[30], ch;
    int i=0;
    FUNCIONARIO func;
    FILE *x;
    system("cls");
    visualdomenu();
    gotoxy(85,8); printf("CADASTRAR FUNCIONARIO");

    gotoxy(38,11); printf("Preencha as informacoes do funcionario: ");
    gotoxy(37,12); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,13); imprimircar(1,0,179); esp_tab(0,1); printf("Nome: "); esp_tab(0,37); imprimircar(1,0,179);
    gotoxy(37,14); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,15); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,16); imprimircar(1,0,179); esp_tab(0,1); printf("Senha: "); esp_tab(0,36); imprimircar(1,0,179);
    gotoxy(37,17); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,18); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,19); imprimircar(1,0,179); esp_tab(0,1); printf("Confirmar Senha: "); esp_tab(0,26); imprimircar(1,0,179);
    gotoxy(37,20); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(45,13); fflush(stdin); gets(func.nomefuncionario);
    gotoxy(46,16); fflush(stdin);

    senha[i]='\0';
    ch='0';
    while(ch!=13)
    {
        ch=getch();
        if(ch!=13)
        {
            putch('*');
            senha[i]=ch;
            i++;
        }
    }
    senha[i] = '\0';
    strcpy(func.senhafuncionario,senha);

    gotoxy(56,19); fflush(stdin);
    i=0;
    senha[i]='\0';
    ch='0';

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13)
        {
            putch('*');
            senha[i]=ch;
            i++;
        }
    }
    senha[i] = '\0';

    while( strcmp(func.senhafuncionario,senha)!=0 )
    {
        gotoxy(56,19); printf("                        ");
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(44,22); imprimircar(1,0,186); gotoxy(52,22); printf("SENHAS DIFERENTES"); gotoxy(76,22); imprimircar(1,0,186);
        gotoxy(44,23); imprimircar(1,0,186); gotoxy(47,23); printf("Confirme a senha novamente!"); gotoxy(76,23); imprimircar(1,0,186);
        gotoxy(44,24); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188); gotoxy(56,19); fflush(stdin);

        i=0;
        senha[i]='\0';
        ch='0';
        while(ch!=13)
        {
            ch=getch();
            if(ch!=13)
            {
                putch('*');
                senha[i]=ch;
                i++;
            }
        }
        senha[i] = '\0';
    }
    fflush(stdin);
    //Salvar os dados da struct livro no arquivo;
    x=fopen("funcionario.txt","ab+");
    if( fwrite(&func, sizeof(FUNCIONARIO), 1, x) )
    {
        gotoxy(44,21); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(44,22); imprimircar(1,0,186); gotoxy(50,22); printf("FUNCIONARIO ADICIONADO!"); gotoxy(76,22); imprimircar(1,0,186);
        gotoxy(44,23); imprimircar(1,0,186); gotoxy(47,23); printf("Deseja adicionar novamente?"); gotoxy(76,23); imprimircar(1,0,186);
        gotoxy(44,24); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    else
    {
        gotoxy(44,21); imprimircar(1,0,201); imprimircar(31,0,205); imprimircar(1,0,187);
        gotoxy(44,22); imprimircar(1,0,186); gotoxy(52,22); printf("FALHA AO ADICIONAR!"); gotoxy(76,22); imprimircar(1,0,186);
        gotoxy(44,23); imprimircar(1,0,186); gotoxy(49,23); printf("Deseja tentar novamente?"); gotoxy(76,23); imprimircar(1,0,186);
        gotoxy(44,24); imprimircar(1,0,200); imprimircar(31,0,205); imprimircar(1,0,188);
    }
    fclose(x);

    gotoxy(95,26); imprimircar(10,0,0); gotoxy(94,26); printf("1.SIM/2.NAO"); gotoxy(107,26); op='0';
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1': menufuncionarioscadastro(); break;
        case '2': menufuncionarios(); break;
        default: gotoxy(70,23); printf("Opcao invalida, voltando ao menu!"); Sleep(2500); menufuncionarios();
    }
}

//funcao menu dos funcionarios;
menufuncionarios()
{
    int i;
    char op;
    system("cls");
    visualdomenu();
    gotoxy(89,8); printf(" FUNCIONARIOS ");
    gotoxy(25,11); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,12); imprimircar(1,0,179); esp_tab(0,2); printf("1. Cadastrar Funcionario(s)"); esp_tab(0,3); imprimircar(1,0,179);
    gotoxy(25,13); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(25,14); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,15); imprimircar(1,0,179); esp_tab(0,2); printf("2. Editar Funcionarios(s)"); esp_tab(0,5); imprimircar(1,0,179);
    gotoxy(25,16); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(25,17); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,18); imprimircar(1,0,179); esp_tab(0,2); printf("3. Remover Funcionarios(s)"); esp_tab(0,4); imprimircar(1,0,179);
    gotoxy(25,19); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(25,20); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,21); imprimircar(1,0,179); esp_tab(0,2); printf("4. Visualizar Funcionarios(s) "); imprimircar(1,0,179);
    gotoxy(25,22); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(95,26); imprimircar(10,0,0); gotoxy(96,26); printf("5. MENU");
    gotoxy(65,14); printf("REGRA 1: Um aluno podera no"); gotoxy(65,15); printf("maximo realizar 2 emprestimos!");
    gotoxy(65,17); printf("REGRA 2: Um aluno podera passar"); gotoxy(65,18); printf("no maximo 10 dias com o livro!");
    gotoxy(107,26);
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1':
            fflush(stdin);
            menufuncionarioscadastro();
            break;

        case '2':
            fflush(stdin);
            menufuncionarioseditar();
            break;

        case '3':
            fflush(stdin);
            menufuncionariosremover();
            break;

        case '4':
            fflush(stdin);
            menufuncionariosvisualizar();
            break;

        case '5':
            fflush(stdin);
            menuprincipal();
            break;

        default:
            gotoxy(73,3); imprimircar(1,0,201); imprimircar(34,0,205); imprimircar(1,0,187);
            gotoxy(73,4); imprimircar(1,0,186); gotoxy(75,4); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!"); esp_tab(0,1); imprimircar(1,0,186);
            gotoxy(73,5); imprimircar(1,0,200); imprimircar(34,0,205); imprimircar(1,0,188);
            Sleep(1250);
            menufuncionarios(); break;
    }
}

//funcao para devolver emprestimos;
menuemprestimosdevolucao()
{
    EMPRESTIMO aux[100], aux2[100];
    LIVROS livro;
    FILE *e, *liv;
    char first_car, mataluno[30], codliv[30];
    int i=0, i2=0, c=0, j;
    system("color 30");

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    if( (e==NULL) || (first_car=fgetc(e)) == EOF )
    {
        system("cls");
        visualdomenu();
        gotoxy(90,8); printf(" DEVOLUCAO ");
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(46,13); printf(" EMPRESTIMOS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimos(); break;
        }

    }
    fclose(e);

    system("cls");
    visualdomenu();
    gotoxy(90,8); printf(" DEVOLUCAO ");
    gotoxy(37,9); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,10); imprimircar(1,0,179); esp_tab(0,1); printf("Matricula Aluno: "); esp_tab(0,26); imprimircar(1,0,179);
    gotoxy(37,11); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,12); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,13); imprimircar(1,0,179); esp_tab(0,1); printf("Codigo Livro: "); esp_tab(0,29); imprimircar(1,0,179);
    gotoxy(37,14); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(56,10); fflush(stdin); gets(mataluno);
    gotoxy(53,13); fflush(stdin); gets(codliv);

    e=fopen("emprestimos.txt","rb");
    rewind(e);
    while( fread(&aux[i], sizeof(EMPRESTIMO), 1, e)==1 )
    {
        if( !(strcmp(mataluno,aux[i].codigoalunoemprestimo)) && !(strcmp(codliv,aux[i].codigolivroemprestimo)) )
        {
            gotoxy(37,15); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
            gotoxy(37,16); imprimircar(1,0,179); printf(" Matricula aluno: %s ", aux[i].codigoalunoemprestimo); esp_tab(0,25-strlen(aux[i].codigoalunoemprestimo)); imprimircar(1,0,179);
            gotoxy(37,17); imprimircar(1,0,179); printf(" Codigo Livro: %s ", aux[i].codigolivroemprestimo);  esp_tab(0,28-strlen(aux[i].codigolivroemprestimo)); imprimircar(1,0,179);
            gotoxy(37,18); imprimircar(1,0,179); printf(" Nome Livro: %s ", aux[i].nomelivroemprestimo); esp_tab(0,30-strlen(aux[i].nomelivroemprestimo)); imprimircar(1,0,179);
            gotoxy(37,19); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", aux[i].dia, aux[i].mes, aux[i].ano); esp_tab(0,17); imprimircar(1,0,179);
            gotoxy(37,20); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", aux[i].diad, aux[i].mesd, aux[i].anod); esp_tab(0,18); imprimircar(1,0,179);
            gotoxy(37,21); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
            c=1;
        }
        i++;
    }
    fclose(e);

    if(c==1)
    {
        gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(49,23); printf(" EMPRESTIMO ENCONTRADO!"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,179); gotoxy(52,24); printf(" Deseja devolver?"); gotoxy(76,24); imprimircar(1,0,179);
        gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        gotoxy(107,26);
        switch(getch())
        {
            case '1':

                e=fopen("emprestimos.txt","wb");
                rewind(e);
                for(j=0;j<i;j++)
                {
                    if( ((strcmp(mataluno,aux[j].codigoalunoemprestimo)) || (strcmp(codliv,aux[j].codigolivroemprestimo))) !=0 )
                    {
                        aux2[i2]=aux[j];
                        i2++;
                    }
                }
                for(j=0;j<i2;j++)
                {
                    fwrite(&aux2[j], sizeof(EMPRESTIMO), 1, e);
                }
                fclose(e);

                liv=fopen("livros.txt","rb+");
                while( fread(&livro, sizeof(LIVROS), 1, liv)==1 )
                {
                    if( strcmp(codliv, livro.codigolivro)==0 )
                    {
                        livro.estoquelivro=livro.estoquelivro+1;
                        fseek(liv, ftell(liv)-sizeof(LIVROS), 0);
                        fwrite(&livro, sizeof(LIVROS), 1, liv);
                        fclose(liv);
                    }
                }

                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                gotoxy(44,25); printf("                                 ");
                Sleep(100);
                gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(53,23); printf("DEVOLUCAO FEITA"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,179); gotoxy(48,24); printf("Deseja devolver novamente?"); gotoxy(76,24); imprimircar(1,0,179);
                gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217); fflush(stdin);
                switch(getch())
                {
                    case '1': menuemprestimosdevolucao(); break;
                    case '2': menuemprestimos(); break;
                    default:

                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        gotoxy(44,24); printf("                                 ");
                        gotoxy(44,25); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf("OPCAO INVALIDA!"); gotoxy(76,23); imprimircar(1,0,179);
                        gotoxy(44,24); imprimircar(1,0,179); gotoxy(52,24); printf("Voltando ao menu..."); gotoxy(76,24); imprimircar(1,0,179);
                        gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menuemprestimos();
                        break;
                }
                break;

            case '2':

                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                gotoxy(44,25); printf("                                 ");
                Sleep(100);
                gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(51,23); printf("DEVOLUCAO NAO FEITA"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,179); gotoxy(51,24); printf("Voltando ao menu..."); gotoxy(76,24); imprimircar(1,0,179);
                gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimos();
                break;

            default:

                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                gotoxy(44,25); printf("                                 ");
                Sleep(100);
                gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf("OPCAO INVALIDA!"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,179); gotoxy(50,24); printf("Voltando ao menu..."); gotoxy(76,24); imprimircar(1,0,179);
                gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimos(); break;
        }
    }
    else
    {
        gotoxy(37,15); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
        gotoxy(37,16); imprimircar(1,0,179); printf(" Matricula aluno: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(37,17); imprimircar(1,0,179); printf(" Codigo Livro: ");  esp_tab(0,29); imprimircar(1,0,179);
        gotoxy(37,18); imprimircar(1,0,179); printf(" Nome Livro: "); esp_tab(0,31); imprimircar(1,0,179);
        gotoxy(37,19); imprimircar(1,0,179); printf(" Data Emprestimo: "); esp_tab(0,26); imprimircar(1,0,179);
        gotoxy(37,20); imprimircar(1,0,179); printf(" Data Devolucao: "); esp_tab(0,27); imprimircar(1,0,179);
        gotoxy(37,21); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        gotoxy(44,25); printf("                                 ");
        Sleep(100);
        gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(46,23); printf(" EMPRESTIMO NAO ENCONTRADO!"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,179); gotoxy(48,24); printf(" Deseja buscar novamente?"); gotoxy(76,24); imprimircar(1,0,179);
        gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosdevolucao(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                gotoxy(44,25); printf("                                 ");
                Sleep(100);
                gotoxy(44,22); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(52,23); printf("OPCAO INVALIDA!"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,179); gotoxy(50,24); printf("Voltando ao menu..."); gotoxy(76,24); imprimircar(1,0,179);
                gotoxy(44,25); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosdevolucao(); break;
        }
    }
}

//funcao para visualizar emprestimos;
menuemprestimosvisualizar()
{
    EMPRESTIMO e;
    FILE *x;

    float multa;
    char first_car, data[9], aluno[30], livro[30];
    int i=0, z=0, y=0, count=0, dia, mes, ano, case2=0;

    x=fopen("emprestimos.txt","rb");
    system("color 30");
    if( (x==NULL) || (first_car=fgetc(x)) == EOF)
    {
        system("cls");
        gotoxy(10,1); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
        gotoxy(10,2); imprimircar(1,0,179); printf("VISUALIZAR EMPRESTIMO"); imprimircar(1,0,179); imprimircar(35,0,196); imprimircar(1,0,179); gotoxy(104,2); imprimircar(1,0,179);
        gotoxy(10,3); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

        gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(41,12); imprimircar(1,0,179); gotoxy(43,12); printf(" EMPRESTIMOS NAO CADASTRADOS"); gotoxy(73,12); imprimircar(1,0,179);
        gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
        gotoxy(41,14); imprimircar(1,0,179); gotoxy(48,14); printf(" Deseja cadastrar?"); gotoxy(73,14); imprimircar(1,0,179);
        gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(41,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(41,17); imprimircar(1,0,179); gotoxy(46,17); printf("1. SIM"); gotoxy(56,17); imprimircar(1,0,179);
        gotoxy(41,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(58,16); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(58,17); imprimircar(1,0,179); gotoxy(63,17); printf("2. NAO"); gotoxy(73,17); imprimircar(1,0,179);
        gotoxy(58,18); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimos(); break;
        }
    }
    rewind(x);

    system("cls");
    gotoxy(10,1); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
    gotoxy(10,2); imprimircar(1,0,179); printf("VISUALIZAR EMPRESTIMO"); imprimircar(1,0,179); imprimircar(35,0,196); imprimircar(1,0,179); printf("                                   "); imprimircar(1,0,179);
    gotoxy(10,3); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

    _strdate(data);
    datat(data, &dia, &mes, &ano);

    gotoxy(35,10); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(35,11); imprimircar(1,0,179); esp_tab(0,1); printf("1. Visualizar por aluno: "); esp_tab(0,18); imprimircar(1,0,179);
    gotoxy(35,12); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(35,13); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(35,14); imprimircar(1,0,179); esp_tab(0,1); printf("2. Visualizar por livro: "); esp_tab(0,18); imprimircar(1,0,179);
    gotoxy(35,15); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(35,16); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(35,17); imprimircar(1,0,179); esp_tab(0,1); printf("3. Visualizar todos os emprestimos"); esp_tab(0,9); imprimircar(1,0,179);
    gotoxy(35,18); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217); fflush(stdin);
    switch(getch())
    {
        case '1':

            gotoxy(62,11); gets(aluno);
            system("cls");
            gotoxy(10,1); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
            gotoxy(10,2); imprimircar(1,0,179); printf("VISUALIZAR EMPRESTIMO"); imprimircar(1,0,179); imprimircar(35,0,196); imprimircar(1,0,179); printf("  1. MENU PRINCIPAL / 2.MENU FUNC. "); imprimircar(1,0,179);
            gotoxy(10,3); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);
            while( fread(&e, sizeof(EMPRESTIMO), 1, x)==1 )
            {
                if( strcmp(aluno, e.codigoalunoemprestimo)==0 )
                {
                    case2=1;
                    Sleep(100);
                    if(i%2==0)
                    {
                        z=10;
                        gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                        gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                        gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                        gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                        if(ano>=e.anod)
                        {
                            if( mes>e.mesd)
                            {
                                gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                            }
                            else
                            {
                                if(mes=e.mesd)
                                    if(dia>e.diad)
                                        gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                            }
                        }
                    }
                    else
                    {
                        z=58;
                        gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                        gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                        gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                        gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                        if(ano>=e.anod)
                        {
                            if( mes>e.mesd)
                            {
                                gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                            }
                            else
                            {
                                if(mes=e.mesd)
                                    if(dia>e.diad)
                                        gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                            }
                        }
                    }
                    i++;
                    count++;
                    if(count==2)
                    {
                        count=0;
                        y=y+7;
                    }
                }
            }
            if(case2==0)
            {
                gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(41,12); imprimircar(1,0,179); gotoxy(46,13); printf(" ALUNO SEM EMPRESTIMO"); gotoxy(73,12); imprimircar(1,0,179);
                gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
                gotoxy(41,14); imprimircar(1,0,179); gotoxy(73,14); imprimircar(1,0,179);
                gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            }
            gotoxy(103,2);
            break;

        case '2':

            gotoxy(62,14); gets(livro);
            system("cls");
            gotoxy(10,1); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
            gotoxy(10,2); imprimircar(1,0,179); printf("VISUALIZAR EMPRESTIMO"); imprimircar(1,0,179); imprimircar(35,0,196); imprimircar(1,0,179); printf("  1. MENU PRINCIPAL / 2.MENU FUNC. "); imprimircar(1,0,179);
            gotoxy(10,3); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);
            while( fread(&e, sizeof(EMPRESTIMO), 1, x)==1 )
            {
                if( strcmp(livro, e.codigolivroemprestimo)==0 )
                {
                    case2=1;
                    Sleep(100);
                    if(i%2==0)
                    {
                        z=10;
                        gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                        gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                        gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                        gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                        if(ano>=e.anod)
                        {
                            if( mes>e.mesd)
                            {
                                gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                            }
                            else
                            {
                                if(mes=e.mesd)
                                    if(dia>e.diad)
                                        gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                            }
                        }
                    }
                    else
                    {
                        z=58;
                        gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                        gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                        gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                        gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                        gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                        if(ano>=e.anod)
                        {
                            if( mes>e.mesd)
                            {
                                gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                            }
                            else
                            {
                                if(mes=e.mesd)
                                    if(dia>e.diad)
                                        gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                            }
                        }
                    }
                    i++;
                    count++;
                    if(count==2)
                    {
                        count=0;
                        y=y+7;
                    }
                }
            }
            if(case2==0)
            {
                gotoxy(41,11); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(41,12); imprimircar(1,0,179); gotoxy(45,13); printf("  LIVRO SEM EMPRESTIMO"); gotoxy(73,12); imprimircar(1,0,179);
                gotoxy(41,13); imprimircar(1,0,179); gotoxy(73,13); imprimircar(1,0,179);
                gotoxy(41,14); imprimircar(1,0,179); gotoxy(73,14); imprimircar(1,0,179);
                gotoxy(41,15); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            }
            gotoxy(103,2);
            break;

        case '3':

            system("cls");
            gotoxy(10,1); imprimircar(1,0,218); imprimircar(21,0,196); imprimircar(1,0,191); gotoxy(68,1); imprimircar(1,0,218); imprimircar(35,0,196); imprimircar(1,0,191);
            gotoxy(10,2); imprimircar(1,0,179); printf("VISUALIZAR EMPRESTIMO"); imprimircar(1,0,179); imprimircar(35,0,196); imprimircar(1,0,179); printf("  1. MENU PRINCIPAL / 2.MENU FUNC. "); imprimircar(1,0,179);
            gotoxy(10,3); imprimircar(1,0,192); imprimircar(21,0,196); imprimircar(1,0,217); gotoxy(68,3); imprimircar(1,0,192); imprimircar(35,0,196); imprimircar(1,0,217);

            while( fread(&e, sizeof(EMPRESTIMO), 1, x)==1 )
            {
                Sleep(100);
                if(i%2==0)
                {
                    z=10;
                    gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                    gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                    gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                    gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                    if(ano>=e.anod)
                    {
                        if( mes>e.mesd)
                        {
                            gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                        }
                        else
                        {
                            if(mes=e.mesd)
                                if(dia>e.diad)
                                    gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                        }
                    }
                }
                else
                {
                    z=58;
                    gotoxy(z,y+5); imprimircar(1,0,218); imprimircar(45,0,196); imprimircar(1,0,191);
                    gotoxy(z,y+6); imprimircar(1,0,179); printf(" Matricula aluno: %s ", e.codigoalunoemprestimo); esp_tab(0,26-strlen(e.codigoalunoemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+7); imprimircar(1,0,179); printf(" Codigo Livro: %s ", e.codigolivroemprestimo);  esp_tab(0,29-strlen(e.codigolivroemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+8); imprimircar(1,0,179); printf(" Nome Livro: %s ", e.nomelivroemprestimo); esp_tab(0,31-strlen(e.nomelivroemprestimo)); imprimircar(1,0,179);
                    gotoxy(z,y+9); imprimircar(1,0,179); printf(" Data Emprestimo: %.2d/%.2d/%.2d ", e.dia, e.mes, e.ano); esp_tab(0,18); imprimircar(1,0,179);
                    gotoxy(z,y+10); imprimircar(1,0,179); printf(" Data Devolucao: %.2d/%.2d/%.2d ", e.diad, e.mesd, e.anod); esp_tab(0,19); imprimircar(1,0,179);
                    gotoxy(z,y+11); imprimircar(1,0,192); imprimircar(45,0,196); imprimircar(1,0,217);

                    if(ano>=e.anod)
                    {
                        if( mes>e.mesd)
                        {
                            gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (((mes-e.mesd)*30) + (dia-e.diad)*1.00) ) );
                        }
                        else
                        {
                            if(mes=e.mesd)
                                if(dia>e.diad)
                                    gotoxy(z+30,y+6); printf(" MULTA: R$%.2f", fabs( (dia-e.diad)*1.00 ) );
                        }
                    }
                }
                i++;
                count++;
                if(count==2)
                {
                    count=0;
                    y=y+7;
                }
            }
            gotoxy(103,2);
            break;

        default:

            gotoxy(71,2); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!");
            Sleep(1500);
            menuemprestimosvisualizar(); break;
    }

    fclose(x);
    fflush(stdin);
    switch(getch())
    {
        case '1':
            menuprincipal();
            break;

        case '2':
            menuemprestimos();
            break;

        default:
            gotoxy(70,2); printf("\aOPCAO INVALIDA, VOLTANDO AO MENU!");
            Sleep(1550);
            menuemprestimos();
            break;
    }
}

//funcao de efetuar novos emprestimos;
menuemprestimosnovo()
{
    LIVROS livro;
    ALUNOS aluno;
    EMPRESTIMO e, x;
    FILE *liv, *al, *emp;
    char codigoal[30], nomeliv[30], codigoliv[30], first_car, data[9];
    int count=0, dia, mes, ano, diad, mesd, anod, i=0, estoque;

    al=fopen("alunos.txt","rb");
    if( (al==NULL) || (first_car=fgetc(al)) == EOF )
    {
        system("cls");
        visualdomenu();
        gotoxy(88,8); printf("NOVO EMPRESTIMO");
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" ALUNOS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menualunoscadastro(); break;
            case '2': menuemprestimos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }
    fclose(al);

    liv=fopen("livros.txt","rb");
    if( (liv==NULL) || (first_car=fgetc(liv)) == EOF )
    {
        system("cls");
        visualdomenu();
        gotoxy(88,8); printf("NOVO EMPRESTIMO");
        gotoxy(44,12); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,13); imprimircar(1,0,179); gotoxy(49,13); printf(" LIVROS NAO CADASTRADOS"); gotoxy(76,13); imprimircar(1,0,179);
        gotoxy(44,14); imprimircar(1,0,179); gotoxy(76,14); imprimircar(1,0,179);
        gotoxy(44,15); imprimircar(1,0,179); gotoxy(52,15); printf(" Deseja cadastrar?"); gotoxy(76,15); imprimircar(1,0,179);
        gotoxy(44,16); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);

        gotoxy(44,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(44,18); imprimircar(1,0,179); gotoxy(49,18); printf("1. SIM"); gotoxy(59,18); imprimircar(1,0,179);
        gotoxy(44,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217);

        gotoxy(61,17); imprimircar(1,0,218); imprimircar(14,0,196); imprimircar(1,0,191);
        gotoxy(61,18); imprimircar(1,0,179); gotoxy(66,18); printf("2. NAO"); gotoxy(76,18); imprimircar(1,0,179);
        gotoxy(61,19); imprimircar(1,0,192); imprimircar(14,0,196); imprimircar(1,0,217); fflush(stdin);

        switch(getch())
        {
            case '1': menulivroscadastro(); break;
            case '2': menuemprestimos(); break;
            default:
                gotoxy(44,17); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,18); imprimircar(1,0,179); gotoxy(45,18); printf("OPCAO INVALIDA, TENTE NOVAMENTE!"); gotoxy(76,18); imprimircar(1,0,179);
                gotoxy(44,19); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }
    fclose(liv);

    system("cls");
    visualdomenu();
    gotoxy(88,8); printf("NOVO EMPRESTIMO");
    gotoxy(38,11); printf("Preencha as informacoes do emprestimo: ");
    gotoxy(37,12); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,13); imprimircar(1,0,179); esp_tab(0,1); printf("Matricula do Aluno: "); esp_tab(0,23); imprimircar(1,0,179);
    gotoxy(37,14); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,15); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,16); imprimircar(1,0,179); esp_tab(0,1); printf("Codigo do Livro: "); esp_tab(0,26); imprimircar(1,0,179);
    gotoxy(37,17); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(37,18); imprimircar(1,0,218); imprimircar(44,0,196); imprimircar(1,0,191);
    gotoxy(37,19); imprimircar(1,0,179); esp_tab(0,1); printf("Nome do Livro: "); esp_tab(0,28); imprimircar(1,0,179);
    gotoxy(37,20); imprimircar(1,0,192); imprimircar(44,0,196); imprimircar(1,0,217);
    gotoxy(59,13); fflush(stdin); gets(e.codigoalunoemprestimo);

    emp=fopen("emprestimos.txt","rb");
    while( fread(&x, sizeof(EMPRESTIMO), 1, emp)==1 )
    {
        if( strcmp(x.codigoalunoemprestimo, e.codigoalunoemprestimo)==0 )
        {
            i++;
        }
    }
    fclose(emp);
    if(i>=2)
    {
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf("ALUNO COM MAX EMPRESTIMOS!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(49,23); printf("Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }

    al=fopen("alunos.txt","rb");
    rewind(al);
    while( fread(&aluno, sizeof(ALUNOS), 1, al)==1 )
    {
        if( strcmp(e.codigoalunoemprestimo,aluno.codigoaluno)==0 )
        {
            count=1;
        }
    }
    fclose(al);

    if(count==1)
    {
        gotoxy(56,16); fflush(stdin); gets(e.codigolivroemprestimo);
        liv=fopen("livros.txt","rb");
        rewind(liv);
        while( fread(&livro, sizeof(LIVROS), 1, liv)==1 )
        {
            if( strcmp(e.codigolivroemprestimo,livro.codigolivro)==0 )
            {
                estoque=livro.estoquelivro;
                count=2;
            }
        }
        fclose(liv);
    }
    else
    {
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" ALUNO NAO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }

    if(count==2)
    {
        gotoxy(54,19); fflush(stdin); gets(e.nomelivroemprestimo);
        liv=fopen("livros.txt","rb");
        rewind(liv);
        while( fread(&livro, sizeof(LIVROS), 1, liv)==1 )
        {
            if( strcmp(e.nomelivroemprestimo,livro.nomelivro)==0 )
            {
                count=3;
            }
        }
        fclose(liv);
    }
    else
    {
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" CODIGO NAO ENCONTRADO!"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }

    emp=fopen("emprestimos.txt","rb");
    while( fread(&x, sizeof(EMPRESTIMO), 1, emp)==1 )
    {
        if( (strcmp(x.codigoalunoemprestimo, e.codigoalunoemprestimo)==0) && (strcmp(x.nomelivroemprestimo, e.nomelivroemprestimo)==0) )
        {
            gotoxy(44,21); printf("                                 ");
            gotoxy(44,22); printf("                                 ");
            gotoxy(44,23); printf("                                 ");
            gotoxy(44,24); printf("                                 ");
            Sleep(100);
            gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
            gotoxy(44,22); imprimircar(1,0,179); gotoxy(48,22); printf("FALHA: EMPRESTIMO JA FEITO"); gotoxy(76,22); imprimircar(1,0,179);
            gotoxy(44,23); imprimircar(1,0,179); gotoxy(49,23); printf("Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
            gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
            gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
            switch(getch())
            {
                case '1': menuemprestimosnovo(); break;
                case '2': menuemprestimos(); break;
                default:

                    gotoxy(44,21); printf("                                 ");
                    gotoxy(44,22); printf("                                 ");
                    gotoxy(44,23); printf("                                 ");
                    gotoxy(44,24); printf("                                 ");
                    Sleep(100);
                    gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                    gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                    gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                    gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                    Sleep(1500);
                    menuemprestimosnovo(); break;
            }
        }
    }
    fclose(emp);

    if(estoque==0)
    {
        gotoxy(44,21); printf("                                 ");
        gotoxy(44,22); printf("                                 ");
        gotoxy(44,23); printf("                                 ");
        gotoxy(44,24); printf("                                 ");
        Sleep(100);
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(51,22); printf(" LIVRO SEM ESTOQUE"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }

    if(count==3)
    {
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" EMPRESTIMO DISPONIVEL"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(46,23); printf(" Deseja finalizar emprestimo?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1':

                _strdate(data);
                datat(data,&e.dia,&e.mes,&e.ano);
                datadevolucao(e.dia, e.mes, e.ano, &e.diad, &e.mesd, &e.anod);
                emp=fopen("emprestimos.txt","ab+");
                fwrite(&e, sizeof(EMPRESTIMO), 1, emp);
                fclose(emp);

                liv=fopen("livros.txt","rb+");
                while( fread(&livro, sizeof(LIVROS), 1, liv)==1 )
                {
                    if( strcmp(e.codigolivroemprestimo, livro.codigolivro)==0 )
                    {
                        livro.estoquelivro=livro.estoquelivro-1;
                        fseek(liv, ftell(liv)-sizeof(LIVROS), 0);
                        fwrite(&livro, sizeof(LIVROS), 1, liv);
                        fclose(liv);
                    }
                }

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(49,22); printf(" EMPRESTIMO REALIZADO"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(46,23); printf(" Deseja emprestar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
                switch(getch())
                {
                    case '1': menuemprestimosnovo(); break;
                    case '2': menuemprestimos(); break;
                    default:

                        gotoxy(44,21); printf("                                 ");
                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        gotoxy(44,24); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                        gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menuemprestimos(); break;
                }
                break;


            case '2':

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(47,22); printf(" EMPRESTIMO NAO REALIZADO"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(46,23); printf(" Deseja emprestar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
                switch(getch())
                {
                    case '1': menuemprestimosnovo(); break;
                    case '2': menuemprestimos(); break;
                    default:

                        gotoxy(44,21); printf("                                 ");
                        gotoxy(44,22); printf("                                 ");
                        gotoxy(44,23); printf("                                 ");
                        gotoxy(44,24); printf("                                 ");
                        Sleep(100);
                        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                        gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                        gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                        Sleep(1500);
                        menuemprestimos(); break;
                }
                break;


            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }
    else
    {
        gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
        gotoxy(44,22); imprimircar(1,0,179); gotoxy(50,22); printf(" NOME NAO ENCONTRADO"); gotoxy(76,22); imprimircar(1,0,179);
        gotoxy(44,23); imprimircar(1,0,179); gotoxy(48,23); printf(" Deseja buscar novamente?"); gotoxy(76,23); imprimircar(1,0,179);
        gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
        gotoxy(94,26); printf("1.SIM/2.NAO"); fflush(stdin);
        switch(getch())
        {
            case '1': menuemprestimosnovo(); break;
            case '2': menuemprestimos(); break;
            default:

                gotoxy(44,21); printf("                                 ");
                gotoxy(44,22); printf("                                 ");
                gotoxy(44,23); printf("                                 ");
                gotoxy(44,24); printf("                                 ");
                Sleep(100);
                gotoxy(44,21); imprimircar(1,0,218); imprimircar(31,0,196); imprimircar(1,0,191);
                gotoxy(44,22); imprimircar(1,0,179); gotoxy(52,22); printf("OPCAO INVALIDA!"); gotoxy(76,22); imprimircar(1,0,179);
                gotoxy(44,23); imprimircar(1,0,179); gotoxy(50,23); printf("Voltando ao menu..."); gotoxy(76,23); imprimircar(1,0,179);
                gotoxy(44,24); imprimircar(1,0,192); imprimircar(31,0,196); imprimircar(1,0,217);
                Sleep(1500);
                menuemprestimosnovo(); break;
        }
    }
}

//funcao menu de emprestimos;
menuemprestimos()
{
    int i;
    char op;
    system("cls");
    visualdomenu();
    gotoxy(89,8); printf(" EMPRESTIMO ");
    gotoxy(25,12); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,13); imprimircar(1,0,179); esp_tab(0,2); printf("1. Novo emprestimo"); esp_tab(0,12); imprimircar(1,0,179);
    gotoxy(25,14); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(25,15); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,16); imprimircar(1,0,179); esp_tab(0,2); printf("2. Confirmar Devolucao"); esp_tab(0,8); imprimircar(1,0,179);
    gotoxy(25,17); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(25,18); imprimircar(1,0,218); imprimircar(32,0,196); imprimircar(1,0,191);
    gotoxy(25,19); imprimircar(1,0,179); esp_tab(0,2); printf("3. Visualizar Emprestimos"); esp_tab(0,5); imprimircar(1,0,179);
    gotoxy(25,20); imprimircar(1,0,192); imprimircar(32,0,196); imprimircar(1,0,217);
    gotoxy(95,26); imprimircar(10,0,0); gotoxy(96,26); printf("4. MENU");
    gotoxy(65,14); printf("REGRA 1: Um aluno podera no"); gotoxy(65,15); printf("maximo realizar 2 emprestimos!");
    gotoxy(65,17); printf("REGRA 2: Um aluno podera passar"); gotoxy(65,18); printf("no maximo 10 dias com o livro!");
    gotoxy(107,26);
    fflush(stdin);
    op=getch();
    switch(op)
    {
        case '1':
            fflush(stdin);
            menuemprestimosnovo();
            break;

        case '2':
            fflush(stdin);
            menuemprestimosdevolucao();
            break;

        case '3':
            fflush(stdin);
            menuemprestimosvisualizar();
            break;

        case '4':
            fflush(stdin);
            menuprincipal();
            break;

        default:
            gotoxy(73,3); imprimircar(1,0,201); imprimircar(34,0,205); imprimircar(1,0,187);
            gotoxy(73,4); imprimircar(1,0,186); gotoxy(75,4); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!"); esp_tab(0,1); imprimircar(1,0,186);
            gotoxy(73,5); imprimircar(1,0,200); imprimircar(34,0,205); imprimircar(1,0,188);
            Sleep(1250);
            menuemprestimos(); break;
    }
}

//funcao que produz a tela final do programa (exit);
telasaida()
{
    system("cls");
    system("color F0");
    gotoxy(37,10); imprimircar(1,0,218); imprimircar(49,0,196); imprimircar(1,0,191);
    gotoxy(37,11); imprimircar(1,0,179); gotoxy(87,11); imprimircar(1,0,179);
    gotoxy(37,12); imprimircar(1,0,179); gotoxy(40,12); printf("Creditos: Estevao Arruda Borba S. Guimaraes %c",184); gotoxy(87,12); imprimircar(1,0,179);
    gotoxy(37,13); imprimircar(1,0,179); gotoxy(50,13); printf("99131-0693 / meoprogramar@gmail.com",184); gotoxy(87,13); imprimircar(1,0,179);
    gotoxy(37,14); imprimircar(1,0,179); gotoxy(87,14); imprimircar(1,0,179);
    gotoxy(37,15); imprimircar(1,0,179); gotoxy(41,15); printf("Programa desenvolvido na disciplina de LP1"); gotoxy(87,15); imprimircar(1,0,179);
    gotoxy(37,16); imprimircar(1,0,179); gotoxy(56,16); printf("Linguagem C"); gotoxy(87,16); imprimircar(1,0,179);
    gotoxy(37,17); imprimircar(1,0,179); gotoxy(87,17); imprimircar(1,0,179);
    gotoxy(37,18); imprimircar(1,0,192); imprimircar(49,0,196); imprimircar(1,0,217);
    gotoxy(40,20);
    imprimircar(15,90,176);
    imprimircar(7,110,177);
    imprimircar(8,60,177);
    imprimircar(15,80,178);
    Sleep(1500);
    system("cls");
    system("color 0f");
    exit(1);
}

//função menu principal;
menuprincipal ()
{
    int i;
    system("color 30");
    system("cls");
    gotoxy(49,12); printf("Carregando...");
    gotoxy(32,14);
    imprimircar(15,2,176);
    imprimircar(7,3,177);
    imprimircar(8,2,177);
    imprimircar(15,1,178);
    system("cls");
    visualdomenu();
    gotoxy(88,8); printf(" MENU PRINCIPAL ");
    gotoxy(26,10); printf("1. LIVROS"); gotoxy(67,10); printf("3. EMPRESTIMOS");
    gotoxy(30,12); printf("%c Cadastrar Livros",254); gotoxy(71,12); printf("%c Novo Emprestimo",254);
    gotoxy(30,13); printf("%c Editar Livros",254); gotoxy(71,13); printf("%c Confirmar Devolucao",254);
    gotoxy(30,14); printf("%c Remover Livros",254); gotoxy(71,14); printf("%c Visualizar Emprestimos",254);
    gotoxy(30,15); printf("%c Visualizar Livros",254);
    gotoxy(26,18); printf("2. ALUNOS"); gotoxy(67,18); printf("4. FUNCIONARIOS");
    gotoxy(30,20); printf("%c Cadastrar Aluno",254); gotoxy(71,20); printf("%c Cadastrar Funcionario",254);
    gotoxy(30,21); printf("%c Remover Aluno",254); gotoxy(71,21); printf("%c Remover Funcionario",254);
    gotoxy(30,22); printf("%c Editar Aluno",254); gotoxy(71,22); printf("%c Editar Funcionario",254);
    gotoxy(30,23); printf("%c Visualizar Alunos",254); gotoxy(71,23); printf("%c Visualizar Funcionarios",254);
    gotoxy(96,26); printf("5. SAIR");
    gotoxy(107,26);
    switch( getch() )
    {
        case '1':
            fflush(stdin);
            menulivros();
            break;

        case '2':
            fflush(stdin);
            menualunos();
            break;

        case '3':
            fflush(stdin);
            menuemprestimos();
            break;

        case '4':
            fflush(stdin);
            menufuncionarios();
            break;

        case '5':
            telasaida();

        default:

            gotoxy(73,3); imprimircar(1,0,201); imprimircar(34,0,205); imprimircar(1,0,187);
            gotoxy(73,4); imprimircar(1,0,186); gotoxy(75,4); printf("\aOPCAO INVALIDA, TENTE NOVAMENTE!"); esp_tab(0,1); imprimircar(1,0,186);
            gotoxy(73,5); imprimircar(1,0,200); imprimircar(34,0,205); imprimircar(1,0,188);
            Sleep(1250);
            menuprincipal(); break;
    }
}

main()
{
    telacarregando();
    telalogin();
    menuprincipal();
}
