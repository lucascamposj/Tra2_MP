typedef enum
{
	ERRO, OK
}result;

typedef enum
{
	TRUE, FALSE
}boolean;

int RomanoArab(const char *);

result ArabCorrespondente(const char *, int *, int);

result RomanoValido(int *, int);