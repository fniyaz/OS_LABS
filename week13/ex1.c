#include <stdio.h>
#include <stdlib.h>


int main ()
{

	//READING INPUT

	FILE *inp = fopen ("input.txt", "r");
	FILE *opt = fopen ("output.txt", "w");
	
	int pn, rn;
	fscanf(inp, "%d %d", &pn, &rn);

	int *E = malloc (rn * sizeof (int)), *A = malloc (rn * sizeof (int));
	for(int i = 0; i < rn; i++)
		fscanf (inp, "%d", &E[i]);
	for(int i = 0; i < rn; i++)
		fscanf (inp, "%d", &A[i]);

	int **C = malloc (pn * sizeof (int*));
	for (int j = 0; j < pn; j++)
	{
		C[j] = malloc (rn * sizeof (int));
		for (int i = 0; i < rn; i++)
			fscanf (inp, "%d", &C[j][i]);
	}

	int **R = malloc (pn * sizeof (int*));
	for (int j = 0; j < pn; j++)
	{
		R[j] = malloc (rn * sizeof (int));
		for (int i = 0; i < rn; i++)
			fscanf (inp, "%d", &R[j][i]);
	}


	//ALGORITHM

	char *mark = malloc (pn);
	for (int i = 0; i < pn; i++)
		mark[i] = 0;

	char condition = 1;
	while (condition)
	{
		condition = 0;
		for (int j = 0; j < pn; j++)
			if (!mark[j])
			{
				char skip = 0;
				for (int i = 0; i < rn; i++)
				{
					if (R[j][i] > A[i])
						skip = 1;
				}
				if (!skip)
				{
					mark[j] = 1;
					condition = 1;
					for (int i = 0; i < rn; i++)
						A[i] += C[j][i];
				}
			}
	}

	//OUTPUT

	int DL = 0;
	for (int j = 0; j < pn; j++)
		if (!mark[j])
			DL++;

	if (DL)
		fprintf(opt, "Deadlocked: %d\n", DL);
	else
		fprintf(opt, "No deadlock\n");

	//FREEING?

	fclose (inp);
	fclose (opt);

	free (E);
	free (A);
	free (mark);
	for (int j = 0; j < pn; j++){
		free (C[j]);
		free (R[j]);
	}
	free (C);
	free (R);

	return 0;
}