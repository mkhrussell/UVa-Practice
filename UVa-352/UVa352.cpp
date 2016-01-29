/*************************************
a) A war eagle is represented by at least a single binary one.
b) Cells with adjacent sides on common vertices, which contain binary ones,
   comprise one war eagle. A very large image of one war eagle might contain all ones.
c) Distinct war eagles do not touch one another. This assumption is probably flawed,
   but the programmers are desperate.
d) There is no wrap-around. Pixels on the bottom are not adjacent to the top and the
   left is not adjacent to the right (unless, of course, there are only 2 rows or 2 columns)

Input and Output:
Write a program that reads images of pixels from the input file (a text file),
correctly counts the number of war eagles in the images and prints the image
number and war eagle count for that image on a single line in the output file (also a text file).
Use the format in the sample output. Do this for each image in the input file.
Each image will be preceded by a number indicating its square dimension. No dimension will exceed 25.

Input:
6
100100
001010
000000
110000
111000
010100

Output:
Image number 1 contains 3 war eagles.

**************************************/
#include <cstdio>

int dimention;
char G[26][26]; // No dimention will exeed 25
int nRegion;
int nImage;

void dfs(int i, int j)
{
    G[i][j] = '0';
    
    if((i - 1) >= 0 && (j - 1) >= 0 && G[i - 1][j - 1] == '1')
        dfs(i - 1, j - 1);
    if((i - 1) >= 0 && G[i - 1][j] == '1')
        dfs(i - 1, j);
    if((i - 1) >= 0 && (j + 1) < dimention && G[i - 1][j + 1] == '1')
        dfs(i - 1, j + 1);
    if((j + 1) < dimention && G[i][j + 1] == '1')
        dfs(i, j + 1);
    if((i + 1) < dimention && (j + 1) <  dimention && G[i + 1][j + 1] == '1')
        dfs(i + 1, j + 1);
    if((i + 1) < dimention && G[i + 1][j] == '1')
        dfs(i + 1, j);
    if((i + 1) < dimention && (j - 1) >= 0 && G[i + 1][j - 1] == '1')
        dfs(i + 1, j - 1);
    if((j - 1) >= 0 && G[i][j - 1] == '1')
        dfs(i, j - 1);
}

int main(int argc, char **argv)
{
    //freopen("../sample-input.txt","r",stdin); // Temporary input from file
    //freopen("../output.txt","w",stdout); // Temporary output to a file

    nImage = 1;
    while(scanf("%d", &dimention) != EOF)
    {
        for(int i = 0; i < dimention; i++)
        {
            scanf("%s", &G[i]);
        }

        nRegion = 0;
        for(int i = 0; i < dimention; i++)
        {
            for(int j = 0; j  < dimention; j++)
            {
                if(G[i][j] == '1'){
                    dfs(i, j);
                    nRegion++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", nImage, nRegion);        
        nImage++;
    }    

    return 0;
}
