#include "grupo2.h" // header local com todas as bibliotecas
void menu()//função mostra menu
{
	printf("|--------------------------------------------------|\n");
	printf("|========= ENCONTRA A PALAVRA ESCONDIDA ===========|\n");
	printf("|=================== CIDADES ======================|\n");
	printf("|================ 5 TENTATIVAS ====================|\n");
	printf("|--------------------------------------------------|\n");
}
char transformaNome(char* maiusculas) //função para mudar as letras para maiusculas
{
	for (int i = 0; i < strlen(maiusculas); i++) {
		if (maiusculas[i] >= 'a' && maiusculas[i] <= 'z')
			maiusculas[i] = maiusculas[i] - 32;
	}
}
void jogo(char nomeutilizador[]) // função jogo
{
	char arrayCidades[100][20] = { "lisboa","bragança","coimbra","santarem","evora", "alcobaça","aveiro", "fatima", "guimaraes", "portimao",
	"leiria","funchal", "estremoz", "matosinhos", "albufeira", "setubal", "portalegre", "sintra", "barcelos", "mirandela" };
	char palavras2[20];
	char tentaAcertar[20];
	char tentapalavra[20];
	char letrasInseridas[6];
	char letra;
	int num, opcao, tentativas = 0, acertou = 0, nPalavras = 20, tentaOutra = 0;
	int adicionarP = 1;
	//================== INICIO PROGRAMA ============================
	srand(time(NULL));
	//DECIDIR SE O USER QUER MAIS PALAVRAS NO ARRAY
	printf("Quer adicionar quantas palavras? ");
	scanf(" %d", &adicionarP); //recebe numero inteiro para se o utilizador quer adicionar palavras
	printf("===============================\n");
	for (int i = 0; i < adicionarP; i++) // Ciclo for até ao adicionar palavras(se for 0 da skip neste passo)
	{
		printf("%d Insira a palavra novas: ", i + 1); //insere a palavra, [i+1 é o numero da posição FOR]
		scanf(" %s", arrayCidades[nPalavras]); //guarda a palavra no arraycidades[posição nPalavras]
		printf("===============================\n");
		nPalavras++;//adiciona +1 ao nPalavras para guardar a palavra na próxima posição [nPalavras]
	}
	//FIM PALAVRAS DO USER NO ARRAY
	num = rand() % nPalavras; //gera palavra aleatoria com base na variavel nPalavras
	//printf("PALAVRA RANDOM : %s \n", arrayCidades[num]); //para efeitos de teste
	strcpy(palavras2, arrayCidades[num]); //copia a palavra na posição [num] para a variavel palavras2
	strcpy(tentapalavra, arrayCidades[num]); //copia a palavra na posição [num] para a variavel tentapalavra
	for (int i = 0; i < strlen(tentapalavra); i++) //define os carateres máximos da palavra
		tentapalavra[i] = '_'; //mete os underscores do tamanho da palavra
	memset(letrasInseridas, 0, 6); //Limpa os valores da variavel letrasInseridas -> Google
	do //FAZER
	{
		printf("%dª tentativa. \nInsira uma letra: \n->", tentativas + 1);//mostra as tentativas no %d
		scanf(" %c", &letra);//guarda o caratér na variável letra
		printf("===============================\n");
		if (letra >= 'A' && letra <= 'Z')//se letras maiusculas entre 'A' e 'Z'
			letra = letra + 32;//passa para letras minúsculas
			//===========INICIO LETRAS NO SITIO CERTO====================
		for (int i = 0; i < strlen(palavras2); i++) //ciclo para ver os valores no array da variavel palavras2
			if (letra == palavras2[i]) //se tiver uma letra = à palavra na posição [i] do
				tentapalavra[i] = letra; //a variavel tentapalavra [posição i] guarda a letra no sítio certo da palavra
		letrasInseridas[strlen(letrasInseridas)] = letra; //guarda as letras já escritas na variavel lentrasInserias
		printf("Jogo: %s\n", tentapalavra); // letras corretas e underscores que faltam para adivinhar a palavra
		printf("===============================\n");
		printf("Letras ja inseridas: %s \n", letrasInseridas); //letras ja inseridas
		printf("===============================\n");
		//====================INICIO VERIFICAÇÃO LETRAS==========================
		//VARIAVEL "tentapalavra" tem as letras guardadas na posição certa, e o que falta tem underscores
		if (strcmp(tentapalavra, palavras2) == 0) { //se as letras tentadas forem iguais à variavel palavras 2 (palavra escondida) retorna 0
			printf("PARABENS %s GANHOU!!\n", nomeutilizador); //ganhou
			printf("===============================\n");
			acertou = 1; //passa o acertou para 1 (está a 0 no início das variaveis)
		}
		printf("Quer adivinhar a palavra completa?\n");
		printf("1- Sim | 2 - Nao\n->");
		scanf(" %d", &opcao);//guarda opção variavel int
		printf("===============================\n");
		//=====================FIM VERIFICAÇÃO LETRAS=========================
		//====================INICIO VERIFICAÇÃO PALAVRA COMPLETA
		if (opcao == 1) {//Se opcao for 1
			printf("Introduza o nome da cidade completo: ");
			scanf(" %s", &tentaAcertar); //guarda string na variavel "tentaAcertar"
			for (int i = 0; i < strlen(tentaAcertar); i++) { //ciclo para ver o tamanho da palavra tentaAcertar
				if (tentaAcertar[i] >= 'A' && tentaAcertar[i] <= 'Z') //se letras maiusculas entre 'A' e 'Z'
					tentaAcertar[i] = tentaAcertar[i] + 32; //passa para letras minúsculas
			}
			printf("%s\n", tentaAcertar); //imprime a variavel tentaAcertar com letras minúsculas
			if (strcmp(tentaAcertar, palavras2) == 0) //se a palavra tentada for igual à variavel palavras 2 (palavra escondida) retorna 0
			{
				printf("PARABÉNS %s GANHOU!!!\n", nomeutilizador); //imprime nome utilizador a dizer que ganhou
				printf("===============================\n");
				acertou = 1; //variavel acertou passa a 1 (esta a 0 na declaração de variáveis
			}
			//====================FIM VERIFICAÇÃO PALAVRA COMPLETA
		}
		tentativas++; //conta sempre mais um nas tentativas caso a palavra seja tentada ou uma letra seja inserida
		if (tentativas >= 5 && acertou == 0) //SE tentativas forem maiores ou iguais que 5 (tentativas é iniciada a 1 na declaração de variáveis) E a variavel acertou for igual a 0
			printf("%s gastou as 5 tentativas PERDEU...\n", nomeutilizador); //gastou o numero de tentativas e perdeu, imprime nome utilizador
	} while (tentativas < 5 && acertou == 0); //fazer isto tudo enquanto a variavel tentativas forem menores que 5 e a variavel acertou for = 0
	//======================FIM PROGRAMA JOGO==================================
}
void main()
{
	int opcao;
	setlocale(LC_ALL, "Portuguese");
	char nome[30];
	menu();
	printf("Nome do jogador: "); //pede nome utilizador
	scanf("%29[^\n]s", nome); //guarda nome utilizador (array nome tem 30 caratéres disponíveis, daí o %29 e guarda em nome
	transformaNome(&nome); //chama a função transformaNome(envia o endereço do nome para a função transformaNome) para mudar as letras para maiusculas
	printf("Vamos começar a jogar %s\n", nome); //imprime nome de utilizador
	printf("===============================\n");
	jogo(nome); //chama função jogo e manda para lá o nome já transformado em MAIÚSCULAS
	do
	{
		printf("Quer jogar novamente? 1-Sim | 2-Não: ");
		scanf(" %d", &opcao); //Guarda numero inteiro
		system("cls");
		if (opcao != 1) //Se opção for diferente de 1
		{
			printf("===============================\n");
			printf("ATÉ À PRÓXIMA %s\n", nome); //imprime até à proxima e o nome
			printf("===============================\n");
		}
		else //Se a opção for igual a 1
		{
			jogo(nome); //chama a função jogo e o jogo recomeça
		}
	} while (opcao == 1); //fazer isto tudo enquanto a opção for igual a 1
	getch();
}