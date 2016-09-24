#include <stdio.h>
#include <string.h>
#include "roman.h"

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