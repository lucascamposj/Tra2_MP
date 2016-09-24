#include <stdio.h>
#include <string.h>
#include "roman.h"
#include <gtest/gtest.h>

/**@brief Testa a função ArabCorrespondente.*/
/*Verifica se o retorno é OK caso os carecteres são válidos.
 *Também verifica se o retorno é igual a ERRO se houver algum caracter inválido.
 */

TEST (ArabCorrespondente, CaracteresValidos)
{
	int vetor[30];

	EXPECT_EQ (OK, ArabCorrespondente("MDCXI", vetor, 5));
	EXPECT_EQ (OK, ArabCorrespondente("MDCLXVI", vetor, 7));

	EXPECT_EQ (ERRO, ArabCorrespondente("MDCLJXVI", vetor, 8));
}

/**@brief Testa a condição sobre Algarismo Seguidos da função RomanoValido.*/
/**Verifica se o retorno é OK caso haja mais de 3 algarismos romanos iguais seguidos.
 * Caso contrário verifica se o retorno é igual a ERRO.
 */

TEST (RomanoValido, AlgarismosSeguidos)
{
	int vetor[30] = {10,1,1,1};

	EXPECT_EQ (OK, RomanoValido(vetor, 4));

	vetor[0] = 10;
	vetor[1] = 1;
	vetor[2] = 1;
	vetor[3] = 1;
	vetor[4] = 1;	

	EXPECT_EQ (ERRO, RomanoValido(vetor, 5));
}

/**@brief Testa a condição sobre Algarismo Anteriores da função RomanoValido.*/
/**Verifica se o retorno é OK, caso para cada algarismo, haja um algarismo anterior de maior valor,
 * desconsiderando o vizinho anterior.
 * Caso contrário verifica se o retorno é igual a ERRO.
 */

TEST (RomanoValido, AlgarismosAnteriores)
{
	int vetor[30] = {50,1,10};
	
	EXPECT_EQ (OK, RomanoValido(vetor, 3));

	vetor[0] = 10;
	vetor[1] = 1;
	vetor[2] = 1;
	vetor[3] = 5;
	vetor[4] = 100;
	EXPECT_EQ (ERRO, RomanoValido(vetor, 5));
}

/**@brief Testa a condição sobre Algarismo Especiais da função RomanoValido.*/
/**Verifica se o retorno é ERRO caso o haja um algorismo seguinte de V,L, ou D, maior.
 * Caso contrário verifica se o retorno é igual a OK.
 */

TEST (RomanoValido, AlgarismosEspeciais)
{
	int vetor[30] = {5,10,1};
	
	EXPECT_EQ (ERRO, RomanoValido(vetor, 3));

	vetor[0] = 1000;
	vetor[1] = 500;
	vetor[2] = 1000;
	EXPECT_EQ (ERRO, RomanoValido(vetor, 3));

	vetor[0] = 50;
	vetor[1] = 100;
	EXPECT_EQ (ERRO, RomanoValido(vetor, 2));

	vetor[0] = 500;
	vetor[1] = 100;
	EXPECT_EQ (OK, RomanoValido(vetor, 2));
}

/**@brief Testa a condição sobre a sintaxe, envolvendo subtração, de números romanos.*/
/**Verifica se o retorno é ERRO caso haja um número seguinte maior, diferente de 10 ou 5 vezes o seu valor.
 * Caso contrário verifica se o retorno é igual a OK.
 */

TEST (RomanoValido, Subtracao)
{
	int vetor[30] = {1,100};
	
	EXPECT_EQ (ERRO, RomanoValido(vetor, 3));

	vetor[0] = 1000;
	vetor[1] = 10;
	vetor[2] = 1000;
	EXPECT_EQ (ERRO, RomanoValido(vetor, 3));

	vetor[0] = 10;
	vetor[1] = 50;
	EXPECT_EQ (OK, RomanoValido(vetor, 2));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS(); 
}