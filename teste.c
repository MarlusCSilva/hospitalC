#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_char 126

// Documentos necessários do paciente.
typedef struct {
    int dia, diaT, diaConsulta, mes, mesT, mesConsulta, ano, anoT, anoConsulta, idade;
    char telefone[MAX_char], sus[MAX_char], cpf[MAX_char], cep[MAX_char];
    float altura, peso;
    char nome[MAX_char];
    char sexo[MAX_char];
    char rua[MAX_char];
    char bairro[MAX_char];
    char cidade[MAX_char];
    char estado[MAX_char];
    char reponsavel[MAX_char];
    char locPrim[MAX_char];
    char diagnosticoAnterior[MAX_char];
    char cor[MAX_char];
    char localNascimento[MAX_char];
    char correioEletronico[MAX_char];
    char tipoHistologico[MAX_char];
    char estadiamentoTumor[MAX_char];
    char locPtnm[MAX_char];
    char tratamentoAnteiror[MAX_char];
    char horaConsulta[MAX_char];
} cadastroPaciente;

// mostra a lista de pacientes
void listaPaciente(){
    system("cls");
    int x;
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","r");
    cadastroPaciente cadastro;
    int indice = 0;

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }

    while(fread(&cadastro, sizeof(cadastroPaciente), 1, arquivo) == 1){
        printf("[%d] %s", indice+1, cadastro.nome);
        indice ++;
    }
    fclose(arquivo);

    printf("n%cmero do paciente que deseja ver: ", 163);
    scanf("%d", &x);
    mostrarPaciente(x-1);
}

void consultas(){
    int x, c;

     FILE *arquivo;
    arquivo = fopen("arquivo.txt","r");
    cadastroPaciente cadastro;
    int indice = 0;
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }

    system("cls");
    printf("[1]Agendar uma consulta  \n[2]Verificar consultas marcadas  \n[3]Verificar consulta marcada de um paciente [4]Tela Inicial");
    scanf("%d", &x);
    if(x == 1){
        printf("Dia: ");
        scanf("%d", &cadastro.diaConsulta);

        printf("M%cs: ", 136);
        scanf("%d", &cadastro.mesConsulta);
        printf("Hora xx:xx");

        printf("Ano: ");
        scanf("%d", &cadastro.anoConsulta);

        while ((c = getchar()) != '\n' && c != EOF);
        fgets(cadastro.horaConsulta, sizeof(cadastro.horaConsulta), stdin);

        printf("CONSULTA MARCADA COM SUCESSO!");
    }

    else if(x == 2){

    }
    fclose(arquivo);
}

// mostra os dados de um paciente
void mostrarPaciente(int indicePaciente){
    system("cls");
    FILE *arquivo;
    arquivo = fopen("arquivo.txt","r");
    cadastroPaciente cadastro;
    int indice = 0;
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
    }

    while(fread(&cadastro, sizeof(cadastroPaciente), 1, arquivo) == 1){
        if(indice == indicePaciente){
            printf("\n\nnome: %s", cadastro.nome);
            printf("data de nascimento: %d/%d/%d\n", cadastro.diaConsulta, cadastro.mes, cadastro.ano);
            printf("sexo: %s\n", cadastro.sexo);
            printf("Idade: %d\n", cadastro.idade);
            if(cadastro.idade < 18){
                printf("Nome responsavel: %d\n", cadastro.reponsavel);
            }
            printf("Raca/cor: %s\n", cadastro.cor);
            printf("CPF: %s\n", cadastro.cpf);
            printf("telefone: %s\n", cadastro.telefone);
            printf("SUS: %s\n", cadastro.sus);
            printf("CEP: %s\n", cadastro.cep);
            printf("Endere%co: Rua %s, Bairro %s, %s - %s", 135, cadastro.rua, cadastro.bairro, cadastro.cidade, cadastro.estado);
            break;
        }
        indice++;
    }
    fclose(arquivo);
}

// Cabeçalho inicial.
void cabecalhoInicial() {
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c               BEM-VINDO                %c\n", 186, 186);
    printf("%c                AO COAC                 %c\n", 186, 186);
    printf("%c    CENTRO ONCOL%cGICO AURORA DE CURA    %c\n", 186, 224,186);
    printf("%c----------------------------------------%c\n", 186, 186);
    printf("%c       PREENCHA OS CAMPUS ABAIXO        %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}

// Cadastro dos Pacientes.
void cadasto(){
    system("cls");
    cabecalhoInicial();
    int sex, cor, c, d, e, tnm, ptnm;

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "a");
    if(arquivo == NULL){
        printf("erro ao executar arquivo");
    }

    while ((c = getchar()) != '\n' && c != EOF);
    cadastroPaciente cadastro;
    printf("Nome: ");
    fgets(cadastro.nome, sizeof(cadastro.nome), stdin);

    printf("idade: ");
    scanf("%d", &cadastro.idade);
    fflush;
    if(cadastro.idade < 18){
        printf("Nome do respons%cvel legal: ", 160);
        scanf("%s", cadastro.reponsavel);
        fflush;
    }

    printf("Sexo: \n[1]Masculino \n[2]Feminino  ");
    scanf("%d", &sex);
    if(sex == 1){
        strcpy(cadastro.sexo, "Masculino");
    }
    else if(sex == 2){
        strcpy(cadastro.sexo, "feminino");
    }

    printf("Cor/Ra%ca: \n[1]Branco(a)  \n[2]Preta(a)  \n[3]Amarelo(a)  \n[4]Pardo(a)  \n[5]Ind%cgena  \n[6]Sem informa%c%co  ", 135, 214, 135, 198);
    scanf( "%d", &cor);
    if(cor == 1){
        strcpy(cadastro.cor, "Branco(a)");
    }
    else if(cor == 2){
        strcpy(cadastro.cor, "Preto(a)");
    }
    else if(cor == 3){
        strcpy(cadastro.cor, "Amarelo(a)");
    }
    else if(cor == 4){
        strcpy(cadastro.cor, "Pardo(a)");
    }
    else if(cor == 5){
        strcpy(cadastro.cor, "indígena");
    }
    else if(cor == 6){
        strcpy(cadastro.cor, "Sem informcao");
    }
    system("cls");

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c   CARACTERISTICAS/ORIGEM DO PACIENTE   %c\n",186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    
    //origem do paciente.

    printf("Peso: ");
    scanf("%f", &cadastro.peso);

    printf("Altura: ");
    scanf("%f", &cadastro.altura);

    printf("Dia do nascimento: ");
    scanf("%d", &cadastro.dia);

    printf("M%cs de nascimento: ", 136);
    scanf("%d", &cadastro.mes);

    printf("Ano de nascimento: ");
    scanf("%d", &cadastro.ano);

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Local de nascimento: ");
    fgets(cadastro.localNascimento, sizeof(cadastro.localNascimento), stdin);

    printf("CPF: ");
    fgets(cadastro.cpf, sizeof(cadastro.cpf), stdin);
    
    printf("SUS: ");
    fgets(cadastro.sus, sizeof(cadastro.sus), stdin);
    
    printf("Correio Eletr%cnico: ", 147);
    fgets(cadastro.correioEletronico, sizeof(cadastro.correioEletronico), stdin);
    system("cls");

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c         Endere%co do paciente           %c\n",186, 135, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

    printf("CEP: ");
    fgets(cadastro.cep, sizeof(cadastro.cep), stdin);

    printf("Rua: ");
    fgets(cadastro.rua, sizeof(cadastro.rua), stdin);

    printf("Bairro: ");
    fgets(cadastro.bairro, sizeof(cadastro.bairro), stdin);

    printf("Cidade: ");
    fgets(cadastro.cidade, sizeof(cadastro.cidade), stdin);

    printf("Estado: ");
    fgets(cadastro.estado, sizeof(cadastro.estado), stdin);
    system("cls");

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c     CARACTERIZA%c%cO DO DIAGN%cSTICO      %c\n",186, 128, 199, 224, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    

    printf("          Data do diagn%cstico. \nDia: ", 162);
    scanf("%d", &cadastro.diaT);
    printf("M%cs: ", 136);
    scanf("%d", &cadastro.mesT);
    printf("Ano: ");
    scanf("%d", &cadastro.diaT);
    system("cls");

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c                SESS%cES                 %c\n",186, 229, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    

    printf("    Diagn%cstico e tratamento anteriores. \n[1]Sem Diag./Sem trat.  \n[2]Com Diag./Sem trat.  \n[3]Com Diag./Com trat.  \n[4]Outros  \n[5]Sem informa%cao  ", 162, 135);
    scanf("%d", &d);
    if(d == 1){
        strcpy(cadastro.diagnosticoAnterior, "Sem diagnóstico e sem tratamento");
    }
    else if(d == 2){
        strcpy(cadastro.diagnosticoAnterior, "Com diagnóstico e sem tratamento");
    }
    else if(d == 3){
        strcpy(cadastro.diagnosticoAnterior, "Com diagnóstico e com tratamento");
        printf("    Tratamento anterior feito: \n[1]Cirurgia  \n[2]Radioterapia  \n[3]Quimioterapia  \n[4]Hormonioterapia  \n[5]Transplate de Medula %cssea  \n[6]Imunoterapia  \n[7]Outro", 162);
        scanf("%d", &e);
        if(e == 1){
            strcpy(cadastro.tratamentoAnteiror, "Cirurgia");
        }
        if(e == 2){
            strcpy(cadastro.tratamentoAnteiror, "Radioterapia");
        }
        if(e == 3){
            strcpy(cadastro.tratamentoAnteiror, "Quimioterapia");
        }
        if(e == 4){
            strcpy(cadastro.tratamentoAnteiror, "Hormonioterapia");
        }
        if(e == 5){
            strcpy(cadastro.tratamentoAnteiror, "transplante de medula ossea");
        }
        if(e == 6){
            strcpy(cadastro.tratamentoAnteiror, "Imunoterapia");
        }
        if(e == 7){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Qual outro tratamento realizado ");
            fgets(cadastro.tratamentoAnteiror, sizeof(cadastro.tratamentoAnteiror), stdin);
        }
    }
    else if(d == 4){
        strcpy(cadastro.diagnosticoAnterior, "Outros");
    }
    else if(d == 5){
        strcpy(cadastro.diagnosticoAnterior, "Sem informacao");
    }
    system("cls");

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c                SESS%cES                 %c\n",186, 229, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    

    while ((c = getchar()) != '\n' && c != EOF);
    printf("Localiza%c%co pim%cria do tumor: ", 135, 198, 160);
    fgets(cadastro.locPrim, sizeof(cadastro.locPrim), stdin);

    printf("Tipo histol%cgico do tumor: ", 162);
    fgets(cadastro.tipoHistologico, sizeof(cadastro.tipoHistologico), stdin);

    printf("TNM? \n[1]SIM  \n[2]N%cO  ", 199);
    scanf("%d", &tnm);
    if(tnm == 1){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Estadiamento cl%cnico do tumos(tnm): ", 214);
        fgets(cadastro.estadiamentoTumor, sizeof(cadastro.estadiamentoTumor), stdin);
    }

    printf("TNM? \n[1]SIM  \n[2]N%cO", 199);
    scanf("%d", &ptnm);
    if(ptnm == 1){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Localiza%c%co de met%cstase a distancia: ", 135, 198, 160, 131);
        fgets(cadastro.locPtnm, sizeof(cadastro.locPtnm), stdin);
    }

    fwrite(&cadastro, sizeof(cadastroPaciente), 1, arquivo);
    fclose(arquivo);
}

int main(){
    int selecao;
    system("cls");
    printf("      Selecione o caminho.  \n[1]cadastrar um novo paciente  \n[2]Mostrar um paciente \n[3]Consultas/agendamentos ");
    scanf("%d", &selecao);

    switch(selecao){
        case 1:
            cadasto();
            break;

        case 2:
            listaPaciente();
        break;
    }
    return 0;
}