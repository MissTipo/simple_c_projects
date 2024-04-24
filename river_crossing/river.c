/**
(1,-1)(1,0)
(1,0)(2,0)
(1,0)(1,1)
(1,1)(2,1)
(1,1)(1,2)
(0,2)(1,2)
(0,2)(0,3)


3 3
001
100
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct Node {
  int row;
  int col;
  struct Node *parent;
  int rotations;
} Node;

Node *create_node(int row, int col, Node *parent, int rotations);
Node ***create_graph(int M, int N, char grid[MAX_ROWS][MAX_COLS]);
void BFS(Node ***graph, Node *source, Node * destination, int M, int N);
void print_solution(Node* destination);

int main() {
  int row;
  int col;
  scanf("%d %d", &row, &col);
  printf("%d %d\n", row, col);

  char M [row - 1][col + 1];
  for (int i = 0; i < row - 1; i++) {
    scanf("%s", M[i]);
  }

  for (int i = 0; i< row -1; i++) {
    printf("%s\n", M[i]);
  }

  int boards = 0;

  for (int i = 0; i < row -1; i++) {
    for (int j = 0; j < col; j++) {
      if (M[i][j] == '1')
        boards++;
    }
  }
  printf("%d\n", boards);

  int coords [boards][2];
  int k = 0;

  for (int i = 0; i < row -1; i++) {
    for (int j = 0; j < col; j++) {
      if (M[i][j] == '1')
      {
        coords[k][0] = i;
        coords[k][1] = j;
        k++;
      }
    }
  }

  for (int i = 0; i < boards; i++) {
    printf("(");
    for (int j = 0; j < 2; j++) {
      printf("%d", coords[i][j]);
      if (j == 0)
        printf(",");
    }
    printf(")\n");
  }

  int x = row, y = col;

  for (int i = 0; i < boards; i++) {
    if (coords[i][1] < y) {
      x = i;
      y = coords[i][1];
    }
  }
  printf("(%d,%d)\n", x, y);

  Node ***graph = create_graph(row, col, M);
  Node *source = create_node(-1, 0, NULL, 0);
  Node *destination = create_node(row - 1, col, NULL, 0);
  BFS(graph, source, destination, row, col);

  return 0;
}

Node *create_node(int row, int col, Node *parent, int rotations)
{
  Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> row = row;
    newNode -> col = col;
    newNode -> parent = parent;
    newNode -> rotations = rotations;
    return newNode;
}

Node ***create_graph(int M, int N, char grid[MAX_ROWS][MAX_COLS])
{
  Node ***graph = (Node***)malloc(M * sizeof(Node**));
  for (int i = 0; i < M; i++) {
    graph[i] = (Node**)malloc(N * sizeof(Node*));
    for (int j = 0; j < N; j++) {
      graph[i][j] = create_node(i, j, NULL, 0);
    }
  }
  for (int i = 0; i < M - 1; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == '1') {
        int row1 = i, row2 = i + 1;
        int col = j;
        graph[row1][col] = create_node(row1, col, NULL, 0);
        graph[row2][col] = create_node(row2, col, NULL, 0);
      }
    }
  }
  return graph;
}

void BFS(Node ***graph, Node *source, Node * destination, int M, int N)
{
  bool visited[MAX_ROWS][MAX_COLS];
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      visited[i][j] = false;
    }
  }
  Node **queue = (Node**)malloc(MAX_ROWS * N * sizeof(Node*));
  int left = 0, right = 0;

  queue[right] = source;
  visited[source->row][source->col] = true;

  while (left <= right) {
    Node * current = queue[left++];

    if (current -> row == destination -> row && current -> col == destination -> col) {
      printf("solution found with %d rotations\n", current -> rotations);
      print_solution(current);
      break;
    }
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int new_row = current -> row + i;
        int new_col = current -> col + j;

         if (new_row >= 0 && new_row < M && new_col >= 0 && new_col < N && !visited[new_row][new_col]) {
           if (graph[new_row][new_col] != NULL) {
             int new_rotations = current->rotations;
             if (i != 0 && j != 0)
               new_rotations++;
             visited[new_row][new_col] = true;
             graph[new_row][new_col]->parent = current;
             graph[new_row][new_col]->rotations = new_rotations;
             queue[++right] = graph[new_row][new_col];
           }
         }
      }
    }
  }
  if (left > right)
    printf("No solution found\n");
  free(queue);
}

void print_solution(Node* destination) {
    if (destination == NULL) {
        return;
    }

    print_solution(destination->parent);
    printf("(%d, %d) - ", destination->row, destination->col);
}
