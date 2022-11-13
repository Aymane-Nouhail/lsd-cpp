// A simple representation of graph using STL
#include <bits/stdc++.h>
using namespace std;
 
// A utility function to add an edge in an
// undirected graph.
struct graph
{
    int row;
    int column;
    int ** head;
};
typedef struct graph graph;

graph createGraph(int n)
{
    graph M={0,0,NULL};
    M.row=n;
    M.column=n;
    M.head=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<M.row;i++)
        M.head[i]=(int *)malloc(n*sizeof(double));
    for(int i=0;i<M.row;i++){
        for(int j=0;j<M.column;j++)
            M.head[i][j] = 0;
    }
    return M;
}
void addEdge(graph *T, int i, int j)
{
    T->head[i][j] = 1;
    T->head[j][i] = 1;
}
void freeGraph(graph *M)
{
    if(M->head!=NULL)
    {
        for(int i=0;i<M->row;i++)
        {
            if(M->head[i]!=NULL)
                free(M->head[i]);
        }
        free(M->head);
    }
    return;
}

void printGraph(graph M)
{
    if(M.head==NULL)
    {
        printf("|  |\n");
        return;
    }
    printf("     c0   ");
    for(int i=1;i<M.column-1;i++)
        printf("c%d   ",i);
    printf("c%d\n",M.column-1);
    for(int i=0;i<M.row;i++)
    {
        if(i==0) printf("S ");
        if(i==M.column-1) printf("c%d ",M.column-1);
        if(i>0 && i<M.column-1) printf("c%d",i);
        printf(" | ");
        for(int j=0;j<M.column-1;j++)
            //printf("%d    ",M.head[i][j]);
            cout << M.head[i][j] << "    " ;
        //printf("%d |\n\n",M.head[i][M.column-1]);
        cout << M.head[i][M.column-1] << " |\n\n";
    }
    printf("\n");
    return;
}
// Driver code
int main()
{
    int i, j;
    graph T = createGraph(5); 
    addEdge(&T,1,2);
    printGraph(T);
    return 0;
}