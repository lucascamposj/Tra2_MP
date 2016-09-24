#include <stdio.h>
#include <string.h>
#include "roman.h"

/** @brief Realiza a soma e subtração correta de números romanos válidos 
 * para transformá-los em algarismos arábicos.
*/
/** @return Número arábico correspondente ao número romano inserido.
 *	@return -1, caso tenha sido verificado erro de formatação ou escrita do número romano.
 */
int RomanoArab(const char *rom_char)
{
	int rom_int[30]; /* Vetor que armazena os algarismos convertidos*/
	int i;
	int tam_s; /* Variável que armazena a quantidade de algarismos romanos inseridos*/
	int valor = 0; /* Variável que representa o valor arábico final*/

	tam_s = strlen(rom_char);

	/**
	 * Primeiramente, ocorre a verificação da validez dos números romanos inseridos.
	 */
	/** Utilizando as funções
	 * 	ArabicoCorrespondente e RomanoValido.
	 */
	if(ArabCorrespondente(rom_char,rom_int, tam_s) == OK)
		
		if(RomanoValido(rom_int, tam_s) == OK){
			
			/** Realiza a soma correta dos valores verificados.*/
			for (i = 0; i < (tam_s-1); i++)
			{		 
				/* Caso o próximo algarismo seja maior, subtrai.*/
				if (rom_int[i] < rom_int[i + 1])
					valor -= rom_int[i];
				/* Caso o próximo algarismo seja menor ou igual, soma.*/
				if (rom_int[i] >= rom_int[i + 1])
					valor += rom_int[i];
			} 
			valor += rom_int[tam_s-1];

			return valor;
		}
	return -1;
}


/**
* @brief Copia para um vetor de inteiros, os valores arábicos correspondentes a cada caracter.
* Além de verificar caso algum deles não pertença ao conjunto de algarismos romanos.
*/
/**@param rom_char Vetor de caracteres do número romano.
 * @param rom_int Vetor de números inteiros correspondentes ao algarismos romanos.
 * @param tam Quantidade de algarismos, tamanho da string inserida.
 */
/**@return Ok, caso todos os caracteres inseridos pertençam ao conjunto dos algarismo romanos.
 * @return ERRO, caso contrário.
 */ 

result ArabCorrespondente(const char *rom_char,int *rom_int,int tam)
{
	int i;

	/*Copia para o vetor de inteiros a representação dos algarismos em números arábicos, individualmente.*/
	for (i = 0; i < tam; i++)
	{
		switch(rom_char[i])
		{
			case 'M':
				rom_int[i] = 1000;
			break;

			case 'D':
				rom_int[i] = 500;
			break;

			case 'C':
				rom_int[i] = 100;
			break;

			case 'L':
				rom_int[i] = 50;
			break;

			case 'X':
				rom_int[i] = 10;
			break;

			case 'V':
				rom_int[i] = 5;
			break;

			case 'I':
				rom_int[i] = 1;
			break;

			/*Caso o caracter não represente um algarismo romano, retorna Erro*/
			default:
				return ERRO;
		}
	}
	/*Caso não tenho ocorrido caracteres inválidos. A função retorna OK. */
	return OK;
}

/**
* @brief Testa erros de sintaxe do algorismo romano inserido.
*/
/**@param rom_int Vetor de números inteiros correspondentes ao algarismos romanos.
 * @param tam_s Quantidade de algarismos, tamanho da string inserida.
 */
/**@return Ok, caso o algarismo romano inserido seja válido.
 * @return ERRO, caso contrário.
 */ 

result RomanoValido(int *rom_int,int tam_s)
{
	int i,j;
	boolean flag; /* Variável que verifica se controla a ocorrência de algarismos repitidos*/
	
	/* Verifica casos onde a mais de 3 algarismos iguais seguidos
	 */
	/* Exemplo de invalidez: VIIII
	 */
	for(i = 0, flag = TRUE; i <= (tam_s-4) && flag == TRUE; i++){
		flag = FALSE;
		for (j = i; j < i+4; j++)
			if(rom_int[i] != rom_int[j])
				flag = TRUE;
		if(flag == FALSE)
			return ERRO;
	}

	/* 	Verifica casos onde a partir do segundo algarismo anterior é menor.
	 */
	/*	Exemplo de invalidez: IIV
	 */
	for (i = 2; i < tam_s; i++){
		for(j = 2; (i-j) >= 0; j++){
			if(rom_int[i - j] < rom_int[i]) return ERRO;
		}
	}


	/*Verifica de casos onde ocorre subtração de algarismos inválidos.*/
	for (i = 1; i < tam_s; i++){
		/* Verifica de algarismos especiais V,L,D.
		 * Tais algarismos não podem aparecer antes de algarismos maiores.
		 */
		/* Exemplo de invalidez: VX.
		 */
		if(rom_int[i - 1] < rom_int[i] && (rom_int[i-1] == 5 || rom_int[i-1] == 50 || rom_int[i-1] == 500))
			return ERRO;
		/*	Verifica casos onde há subtração, que só pode ocorrer caso esteja subtraindo um décimo ou um quinto do valor verificado.
		 */
		/*	Exemplos de invalidez: IC, XM.
		 */
		if(rom_int[i-1] < rom_int[i] && rom_int[i-1] != (rom_int[i]/10) &&  rom_int[i-1] != (rom_int[i]/5))
			return ERRO;
	}	
	/*Caso não tenham ocorridos erros de formatação do número romano. A função retorna OK.*/
	return OK;
}
