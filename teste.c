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

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS(); 
}