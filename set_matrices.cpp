#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int col0=1;
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[0].size(); j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;

				if(j!=0)
				 matrix[0][j] = 0;
				else
					{col0 = 0;}
				  
			}
		}
	}

    for(int i=1; i<matrix.size(); i++){
      for (int j = 1; j < matrix[0].size(); j++) {
        if(matrix[i][j] != 0){
			if(matrix[i][0] == 0 || matrix[0][j]==0){
				matrix[i][j]=0;
			}
		}
      }
    }

	if(matrix[0][0] == 0){
		for(int i=0; i<matrix[0].size(); i++)
		{matrix[0][i] = 0;}
	}

	if(col0==0){
		for(int i=0; i<matrix.size(); i++)
	{	matrix[i][0] = 0;}
	}

        // set<pair<int,int>> mp;
    //     for(int i=0; i<matrix.size(); i++){
    //         for(int j=0; j<matrix[0].size(); j++){
    //             if(matrix[i][j] == 0){
    //                mp.insert({i,j});
    //             }
    //         }
    //     }
        
    //     for(auto it : mp){
    //         int r =it.first;
    //         int c = it.second;
    //         for(int i=0; i<matrix.size(); i++){
    //             matrix[i][c]=0;
    //         }
            
    //         for(int i=0; i<matrix[0].size(); i++){
    //             matrix[r][i]=0;
    //         }
    //     }
}