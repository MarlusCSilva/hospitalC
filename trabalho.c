#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_char 126

// Documentos necessários do paciente.
typedef struct {
    char nome[MAX_char];
    int idade;
    char reponsavel[MAX_char];
    char sexo[MAX_char];
    char cor[MAX_char];
    char telefone[MAX_char];
    char peso[MAX_char];
    char altura[MAX_char];
    char dataNas[MAX_char];
    char localNascimento[MAX_char];
    char cpf[MAX_char];
    char sus[MAX_char];
    char correioEletronico[MAX_char];
    char cep[MAX_char];
    char rua[MAX_char];
    char bairro[MAX_char];
    char cidade[MAX_char];
    char estado[MAX_char];
    char locPrim[MAX_char];
    char diagnosticoAnterior[MAX_char];
    char dataTratamento[MAX_char];
    char tratamentoAnteiror[MAX_char];
    char locPtnm[MAX_char];
    char estadiamentoTumor[MAX_char];
    char tipoHistologico[MAX_char];
} CadastroPaciente;

typedef struct {
    char nome[MAX_char];
    char dataConsulta[MAX_char];
    char horaConsulta[MAX_char];
} Consulta;


// mostra a lista de pacientes
void listaPaciente(){
    CadastroPaciente cadastro;
    FILE *arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c              CADASTRADOS               %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    
    char linha[MAX_char];
    printf("             Lista de Nomes\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Nome: ") != NULL) {
            printf("- %s", linha + 6); 
        }
    }
    fclose(arquivo);
}

// mostra os dados de um paciente
void mostrarPaciente(){
    listaPaciente();
    int x;
     FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    CadastroPaciente cadastro;
    char nomePesquisa[MAX_char];
    printf("Digite o nome da pessoa a ser procurada: ");
    scanf("%s", nomePesquisa);

    int encontrada = 0;
    char linha[MAX_char];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (strstr(linha, "Nome: ") != NULL) {
            if (encontrada) {
                break; 
            }

            strcpy(cadastro.nome, linha + 6);
            cadastro.nome[strcspn(cadastro.nome, "\n")] = '\0';

        
            if (strcmp(nomePesquisa, cadastro.nome) == 0) {
                encontrada = 1;
            }
        }

        if (encontrada) {
            printf("%s", linha);
        }
    }

    if (!encontrada) {
        printf("Paciente não encontrado.\n");
    }

    fclose(arquivo);

    printf("\n[1]Tela Inicial  \n[2]Mostrar outro Paciente  \n[3]Sair  ");
    scanf("%d", &x);

    while(x > 3 || x < 1){
        system("cls");
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]Tela Inicial  \n[2]Mostrar outro Paciente  \n[3]Sair  ");
        scanf("%d", &x);
    }

    if(x == 1){
        return main();
    }
    if(x == 2){
        return mostrarPaciente();
    }
    if(x == 3){
        return 0;
    }
}

void consultas(){
    int c, x;

    FILE *arquivo;
    Consulta cadConsultas;
    int indice = 0;

    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c              AGENDAMENTOS              %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    
    printf("\n[1]Agendar uma consulta  \n[2]Verificar consultas marcadas  \n[3]Tela Inicial  \n[4]Sair  ");
    scanf("%d", &x);

    while(x > 4 || x < 1){
        system("cls");
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]Agendar uma consulta  \n[2]Verificar consultas marcadas  \n[3]Tela Inicial \n[4]Sair  ");
        scanf("%d", &x);
    }


    if(x == 1){
        arquivo = fopen("consultas.txt","a");
        if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        }   

        while ((c = getchar()) != '\n' && c != EOF);
        printf("Nome: ");
        fgets(cadConsultas.nome, sizeof(cadConsultas.nome), stdin);
        printf("Data: ");
        fgets(cadConsultas.dataConsulta, sizeof(cadConsultas.dataConsulta), stdin);
        printf("Hora: ");
        fgets(cadConsultas.horaConsulta, sizeof(cadConsultas.horaConsulta), stdin);

        fprintf(arquivo, "Nome: %s", cadConsultas.nome);
        fprintf(arquivo, "Data da Consulta: %s", cadConsultas.dataConsulta);
        fprintf(arquivo, "Hora da Consulta: %s", cadConsultas.horaConsulta);
        fprintf(arquivo, "\n");

        fclose(arquivo);

        printf("CONSULTA MARCADA COM SUCESSO!");
        
        int y;
        printf("\n[1]Voltar  \n[2]Tela Inicial  \n[3]Sair  ");
        scanf("%d", &y);

        while(y < 1 || y > 3){
            printf("Op%c%co inv%clida",135, 198, 160);
            printf("\n[1]Voltar  \n[2]Tela Inicial  \n[3]Sair  ");
            scanf("%d", &y);
        }
        if(y == 1){
            return consultas();
        }

        else if(y == 2){
            return main();
        }
        else if(y == 3){
            return 0;
        }
    }

    else if(x == 2){

        arquivo = fopen("consultas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    system("cls");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205 , 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("%c              CADASTRADOS               %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

    char linha[MAX_char];
    while (fgets(linha, MAX_char, arquivo) != NULL) {
        printf("%s", linha);
    }

    int y;
        printf("\n[1]Voltar  \n[2]Tela Inicial  \n[3]Sair  ");
        scanf("%d", &y);

        while(y < 1 || y > 3){
            printf("Op%c%co inv%clida",135, 198, 160);
            printf("\n[1]Voltar  \n[2]Tela Inicial  \n[3]Sair  ");
            scanf("%d", &y);
        }
        if(y == 1){
            return consultas();
        }

        else if(y == 2){
            return main();
        }
        else if(y == 3){
            return 0;
        }
    }

    else if(x == 3){
        return main();
    }

    else if(x == 4){
        return 0;
    }
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
    int sexo, cor, indiceDiagnostico, indiceTratamento, tnm, ptnm, selecao, c;

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "a");

    if(arquivo == NULL){
        printf("erro ao executar arquivo");
    }

    while ((c = getchar()) != '\n' && c != EOF);
    CadastroPaciente cadastro;
    printf("Nome: ");
    fgets(cadastro.nome, sizeof(cadastro.nome), stdin);

    printf("Idade: ");
    scanf("%d", &cadastro.idade);
    fflush;
    if(cadastro.idade < 18){
        printf("Nome do respons%cvel legal: ", 160);
        scanf("%s", cadastro.reponsavel);
        fflush;
    }
    else{
        strcpy(cadastro.reponsavel, "NAO");
    }

    printf("Sexo: \n[1]Masculino \n[2]Feminino  ");
    scanf("%d", &sexo);

    while(sexo < 1 || sexo > 2){
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\nSexo: \n[1]Masculino \n[2]Feminino  ");
        scanf("%d", &sexo);
    }

    if(sexo == 1){
        strcpy(cadastro.sexo, "Masculino");
    }
    else if(sexo == 2){
        strcpy(cadastro.sexo, "feminino");
    }

    printf("Cor/Ra%ca: \n[1]Branco(a)  \n[2]Preta(a)  \n[3]Amarelo(a)  \n[4]Pardo(a)  \n[5]Ind%cgena  \n[6]Sem informa%c%co  ", 135, 214, 135, 198);
    scanf( "%d", &cor);

    while(cor < 1 || cor > 6){
        printf("Op%c%co inv%clida",135, 198, 160);  
        printf("\nCor/Ra%ca: \n[1]Branco(a)  \n[2]Preta(a)  \n[3]Amarelo(a)  \n[4]Pardo(a)  \n[5]Ind%cgena  \n[6]Sem informa%c%co  ", 135, 214, 135, 198);
        scanf("%d", &cor);
    }

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
    printf("%c               PREENCHA                 %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    
    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nDigite teu telefone: ");
    fgets(cadastro.telefone, sizeof(cadastro.telefone), stdin);
    fflush(stdin);

    printf("Peso: ");
    fgets(cadastro.peso, sizeof(cadastro.peso), stdin);

    printf("Altura: ");
    fgets(cadastro.altura, sizeof(cadastro.altura), stdin);

    printf("Data do nascimento: ");
    fgets(cadastro.dataNas, sizeof(cadastro.dataNas), stdin);

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
    printf("%c         ENDERE%cO DO PACIENTE           %c\n",186, 128, 186);
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
    printf("%c           FICHA HOSPITALAR             %c\n", 186, 186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    

    printf("DIAGN%cSTICO E TRATAMENTO ANTERIORES \n[1]Sem Diag./Sem trat.  \n[2]Com Diag./Sem trat.  \n[3]Com Diag./Com trat.  \n[4]Outros  \n[5]Sem informa%cao  ", 224, 135);
    scanf("%d", &indiceDiagnostico);

    while(indiceDiagnostico < 1 || indiceDiagnostico > 5){
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]Sem Diag./Sem trat.  \n[2]Com Diag./Sem trat.  \n[3]Com Diag./Com trat.  \n[4]Outros  \n[5]Sem informa%cao  ", 162, 135);
        scanf("%d", &indiceDiagnostico);
    }
    if(indiceDiagnostico == 1){
        strcpy(cadastro.diagnosticoAnterior, "Sem diagn%cstico e sem tratamento");
        strcpy(cadastro.dataTratamento, "NAO");
        strcpy(cadastro.tratamentoAnteiror, "NAO");
    }
    else if(indiceDiagnostico == 2){
        strcpy(cadastro.diagnosticoAnterior, "Com diagn%cstico e sem tratamento");
        printf("Data do diagn%cstico anterior do tumor \ndia: ", 162);
        fgets(cadastro.dataTratamento, sizeof(cadastro.dataTratamento), stdin);
        strcpy(cadastro.tratamentoAnteiror, "NAO");
    }
    else if(indiceDiagnostico == 3){
        strcpy(cadastro.diagnosticoAnterior, "Com diagnóstico e com tratamento");

        printf("Data do diagn%cstico anterior do tumor \ndia: ", 162);
        fgets(cadastro.dataTratamento, sizeof(cadastro.dataTratamento), stdin);

        printf("        Tratamento anterior feito \n[1]Cirurgia  \n[2]Radioterapia  \n[3]Quimioterapia  \n[4]Hormonioterapia  \n[5]Transplate de Medula %cssea  \n[6]Imunoterapia  \n[7]Outro", 162);
        scanf("%d", &indiceTratamento);

        while(indiceTratamento < 1 || indiceTratamento > 7){
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]Cirurgia  \n[2]Radioterapia  \n[3]Quimioterapia  \n[4]Hormonioterapia  \n[5]Transplate de Medula %cssea  \n[6]Imunoterapia  \n[7]Outro", 162);
        scanf("%d", &indiceTratamento);
        }

        if(indiceTratamento == 1){
            strcpy(cadastro.tratamentoAnteiror, "Cirurgia");
        }
        if(indiceTratamento == 2){
            strcpy(cadastro.tratamentoAnteiror, "Radioterapia");
        }
        if(indiceTratamento == 3){
            strcpy(cadastro.tratamentoAnteiror, "Quimioterapia");
        }
        if(indiceTratamento == 4){
            strcpy(cadastro.tratamentoAnteiror, "Hormonioterapia");
        }
        if(indiceTratamento == 5){
            strcpy(cadastro.tratamentoAnteiror, "transplante de medula ossea");
        }
        if(indiceTratamento == 6){
            strcpy(cadastro.tratamentoAnteiror, "Imunoterapia");
        }
        if(indiceTratamento == 7){
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Qual outro tratamento realizado ");
            fgets(cadastro.tratamentoAnteiror, sizeof(cadastro.tratamentoAnteiror), stdin);
        }
    }
    else if(indiceDiagnostico == 4){
        strcpy(cadastro.diagnosticoAnterior, "Outros");
        strcpy(cadastro.dataTratamento, "NAO");
        strcpy(cadastro.tratamentoAnteiror, "NAO");
    }
    else if(indiceDiagnostico == 5){
        strcpy(cadastro.diagnosticoAnterior, "Sem informacao");
        strcpy(cadastro.dataTratamento, "NAO");
        strcpy(cadastro.tratamentoAnteiror, "NAO");
    }

    while ((c = getchar()) != '\n' && c != EOF);
    printf("\nLocaliza%c%co pim%cria do tumor: ", 135, 198, 160);
    fgets(cadastro.locPrim, sizeof(cadastro.locPrim), stdin);

    printf("Tipo histol%cgico do tumor: ", 162);
    fgets(cadastro.tipoHistologico, sizeof(cadastro.tipoHistologico), stdin);

    printf("TNM? \n[1]SIM  \n[2]N%cO  ", 199);
    scanf("%d", &tnm);

    while(tnm < 1 || tnm > 2){
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]SIM  \n[2]N%cO  ", 199);
        scanf("%d", &tnm);
    }
    if(tnm == 1){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Estadiamento cl%cnico do tumos(tnm): ", 214);
        fgets(cadastro.estadiamentoTumor, sizeof(cadastro.estadiamentoTumor), stdin);
    }
    else if(tnm == 2){
        strcpy(cadastro.estadiamentoTumor, "NAO");
    }

    printf("pTNM? \n[1]SIM  \n[2]N%cO", 199);
    scanf("%d", &ptnm);

    while(ptnm < 1 || ptnm > 2){
        printf("Op%c%co inv%clida",135, 198, 160);
        printf("\n[1]SIM  \n2]N%cO  ", 199);
        scanf("%d", &ptnm);
    }
    if(ptnm == 1){
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Localiza%c%co de met%cstase a dist%cncia: ", 135, 198, 160, 131);
        fgets(cadastro.locPtnm, sizeof(cadastro.locPtnm), stdin);
    }
    if(ptnm == 2){
        strcpy(cadastro.locPtnm, "NAO");
    }

    fprintf(arquivo, "Nome: %s", cadastro.nome);
    fprintf(arquivo, "Idade: %d", cadastro.idade);
    fprintf(arquivo, "\nNome Responsável: %s", cadastro.reponsavel);
    fprintf(arquivo, "\nCor/Raca: %s", cadastro.cor);
    fprintf(arquivo, "\nTelefone: %s", cadastro.telefone);
    fprintf(arquivo, "Peso: %s", cadastro.peso);
    fprintf(arquivo, "Altura: %s", cadastro.altura);
    fprintf(arquivo, "Data de Nascimento: %s", cadastro.dataNas);
    fprintf(arquivo, "Local Nascimento: %s", cadastro.localNascimento);
    fprintf(arquivo, "CPF: %s", cadastro.cpf);
    fprintf(arquivo, "SUS: %s", cadastro.sus);
    fprintf(arquivo, "Correio Eletronico: %s", cadastro.correioEletronico);
    fprintf(arquivo, "CEP: %s", cadastro.cep);
    fprintf(arquivo, "Rua: %s", cadastro.rua);
    fprintf(arquivo, "Bairro: %s", cadastro.bairro);
    fprintf(arquivo, "Cidade: %s", cadastro.cidade);
    fprintf(arquivo, "Estado: %s", cadastro.estado);
    fprintf(arquivo, "Localizacao Primaria do Tumor: %s", cadastro.locPrim);
    fprintf(arquivo, "Diagnostico Anterior: %s", cadastro.diagnosticoAnterior);
    fprintf(arquivo, "\nData tratamento Anterior: %s", cadastro.dataTratamento);
    fprintf(arquivo, "\nTratamento Anterior Realizado: %s", cadastro.tratamentoAnteiror);
    fprintf(arquivo, "\nLocalizacao de Metastase a Distancia: %s", cadastro.locPtnm);
    fprintf(arquivo, "Estadiamento do Tumor: %s\n", cadastro.estadiamentoTumor);
    fprintf(arquivo, "Tipo Histologico do Tumor: %s", cadastro.tipoHistologico);
    fprintf(arquivo, "\n");

    fclose(arquivo);

    system("cls");
    printf("PACIENTE CADASTRADO COM SUCESSO");
    printf("\n[1]Tela Inicial  \n[2]Cadastrar novo Paciente  \n[3]sair  ");
    scanf("%d", &selecao);

    while(selecao < 1 || selecao > 3){
            printf("Op%c%co inv%clida",135, 198, 160);
            printf("\n[1]Tela inicial  \n[2]Cadastrar novo Paciente  \n[3]Sair  ");
            scanf("%d", &selecao);
        }

    if(selecao == 1){
        return main();
    }

    if(selecao == 3){
        return cadasto();
    }

    if(selecao == 3){
        return 0;
    }
}

int main(){
    FILE *arquivo;
    int numPessoas;
    int numPessoa;
    int selecao;
    system("cls");
    cabecalhoInicial();
    printf("          Selecione o caminho  \n[1]cadastrar um novo paciente  \n[2]Mostrar dados de um paciente \n[3]Consultas/agendamentos  \n[4]Sair  ");
    scanf("%d", &selecao);
    fflush;

    switch(selecao){
        case 1:
            cadasto();
            break;
    
        case 2:
            mostrarPaciente();
        break;

        case 3:
            consultas();
            break;

        case 4:
            return 0;

        default:
            return main();
            break;
    }
    return 0;
}