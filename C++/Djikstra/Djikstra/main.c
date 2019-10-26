//
//  main.c
//  Djikstra
//
//  Created by Kunwar Rehan on 30/04/19.
//  Copyright © 2019 Kunwar Saaim. All rights reserved.
//

#include <stdio.h>
#define Max 100
#define Temp 0
#define Perm 1
#define infinity 9999
#define NIL -1

void findPath(int s, int v);
void Dijkstra(int s);
int min_temp(void);
void create_graph(void);

int n;
int adj[Max][Max];
int predecessor[Max];
int pathLength[Max];
int status[Max];

int main(int argc, const char * argv[]) {
    int s,v;
    
    create_graph();
    printf("Enter source vertex : ");
    scanf("%d",&s);
    Dijkstra(s);
    
    while (1) {
        printf("Enter destination vertex(-1 to quit) : ");
        scanf("%d",&v);
        if(v==-1)
            break;
        if(v<0 || v>=n)
            printf("This vertex does not exist\n");
        else if(v==s)
            printf("Source and destination vertices are same\n");
        else if(pathLength[v]==infinity)
            printf("There is no path from source to destination vertex\n");
        else
            findPath(s, v);
    }
    return 0;
}

void Dijkstra(int s){
    int i,current;
    
    for (i=0; i<n; i++) {
        predecessor[i]= NIL;
        pathLength[i] = infinity;
        status[i] = Temp;
    }
    
    pathLength[s] = 0;
    
    while (1) {
        current = min_temp();
        if (current==NIL) {
            return;
        }
        status[current]=Perm;
        
        for (i=0; i<n; i++) {
            if(adj[current][i]!=0 && status[i]==Temp)
                if (pathLength[current] + adj[current][i] < pathLength[i]) {
                    predecessor[i]=current;
                    pathLength[i] = pathLength[current]+ adj[current][i];
                }
        }
    }
    
}

int min_temp(){
    int i;
    int min = infinity;
    int k = NIL;
    for (i=0; i<n; i++) {
        if (status[i]==Temp && pathLength[i]<min) {
            min = pathLength[i];
            k =i;
        }
    }
    return k;
}

void findPath(int s, int v){
    int i,u;
    int path[Max];
    int shortdist =0;
    int count =0;
    
    while (v!=s) {
        count++;
        path[count]= v;
        u = predecessor[v];
        shortdist += adj[u][v];
        v=u;
    }
    count++;
    path[count]=s;
    printf("Shortest Path is : ");
    for (i=count; i>=1; i--) {
        printf("%d ",path[i]);
    }
    printf("\n Shortest distance is : %d\n",shortdist);
}

void create_graph(){
    
    int i,max_edges,origin,destin,wt;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    max_edges = n*(n-1);
    for (i=1; i<max_edges; i++) {
        printf("Enter edges %d(-1 -1 to quit) : ",i);
        scanf("%d %d",&origin,&destin);
        if ((origin==-1) && (destin==-1)) {
            break;
        }
        printf("Enter weight for this edge : ");
        scanf("%d",&wt);
        if (origin>=n || destin>=n || origin<0 || destin<0) {
            printf("Invalid Edge\n");
            i--;
        }
        else
            adj[origin][destin]= wt;
    }
}





























