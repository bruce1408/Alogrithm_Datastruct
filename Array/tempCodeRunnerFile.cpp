for (int i=0;i<firstDim;i++)
        {
            for (int j=0;j<secondDim;j++)
            {
                if (A[i][j] == 1) A[i][j]=0;
                else A[i][j] = 1;
            }
        }