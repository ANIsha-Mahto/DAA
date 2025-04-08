#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 40
#define INF INT_MAX

char* vertex_name[V] = {
    "Source", "CGU", "KV", "Lingaraj Temple", "Odisha State Museum", "Nandankanan", "Khandagiri Caves",
    "Bhubaneswar Railway Station", "BDA City Centre", "Vani Vihar", "Patia", "Janpath", "Dhauli Hill",
    "Rajpath", "Rasulgarh", "Bhubaneswar Airport", "Shree Lingaraj Temple", "Jayadev Vihar", "Bapuji Nagar",
    "Master Canteen", "Acharya Vihar", "Baramunda", "Nayapalli", "Chandrasekharpur", "Kalinga Stadium",
    "Kharavela Nagar", "BJB College", "Sainik School", "Cuttack Road", "Patrapada", "Bhubaneswar Club",
    "KIIT University", "CRPF Square", "Dhauligiri", "VSS Nagar", "Bhabinipur", "Palasuni", "Ghatikia",
    "KISS", "Puri Road"
};

int graph[V][V] = {0};

void initializeGraph() {
    // Sample few connections for demo; add more as needed
    graph[0][1] = 50;  graph[1][0] = 50;  // Source - CGU
    graph[1][2] = 30;  graph[2][1] = 30;  // CGU - KV
    graph[2][3] = 40;  graph[3][2] = 40;  // KV - Lingaraj Temple
    graph[1][7] = 20;  graph[7][1] = 20;  // CGU - Railway Station
    graph[7][8] = 70;  graph[8][7] = 70;  // Railway Station - BDA City Centre
    graph[8][10] = 60; graph[10][8] = 60; // BDA City Centre - Patia
    // Add remaining edges similarly
}

int minDistance(int dist[], int visited[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int src, int dist[], int parent[]) {
    int visited[V] = {0};

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
    }
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%s", vertex_name[j]);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %s", vertex_name[j]);
}

int main() {
    initializeGraph();

    printf("Available Locations:\n");
    for (int i = 0; i < V; i++)
        printf("%2d - %s\n", i, vertex_name[i]);

    int destination;
    printf("\nEnter destination code (0 to %d): ", V - 1);
    scanf("%d", &destination);

    if (destination < 0 || destination >= V) {
        printf("Invalid destination.\n");
        return 1;
    }

    int dist[V], parent[V];
    dijkstra(0, dist, parent); // Source is vertex 0

    printf("\nShortest Path from Source to %s:\n", vertex_name[destination]);
    printPath(parent, destination);
    printf("\nTotal Cost: %d\n", dist[destination]);

    return 0;
}
