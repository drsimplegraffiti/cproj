/*
 * Chapter 17 - Maze Generator & Solver
 * maze.c - generates a maze with DFS and solves it with BFS.
 * Pure C implementation (no C++ STL).
 *
 * Compile: gcc maze.c -o maze
 * Run:     ./maze
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH  21
#define HEIGHT 21

static int maze[HEIGHT][WIDTH];
static int visited[HEIGHT][WIDTH];

/* Directions: up, right, down, left */
static int dx[] = {-1, 0, 1, 0};
static int dy[] = {0, 1, 0, -1};

typedef struct {
    int x, y;
} Point;

/* Simple queue for BFS */
typedef struct {
    Point data[HEIGHT * WIDTH];
    int head, tail;
} Queue;

static void queue_init(Queue* q) {
    q->head = 0;
    q->tail = 0;
}

static void queue_push(Queue* q, Point p) {
    q->data[q->tail++] = p;
}

static Point queue_pop(Queue* q) {
    return q->data[q->head++];
}

static int queue_empty(Queue* q) {
    return q->head == q->tail;
}

static int is_valid(int x, int y) {
    return x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH;
}

/* Initialize all cells as walls */
static void initialize_maze(void) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            maze[i][j] = 1;
}

/* DFS-based recursive maze generation */
static void dfs(int x, int y) {
    maze[x][y] = 0; /* carve path */

    /* Shuffle directions randomly */
    int order[4] = {0, 1, 2, 3};
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int tmp = order[i];
        order[i] = order[r];
        order[r] = tmp;
    }

    for (int i = 0; i < 4; i++) {
        int d = order[i];
        int nx = x + dx[d] * 2;
        int ny = y + dy[d] * 2;
        if (is_valid(nx, ny) && maze[nx][ny] == 1) {
            /* Remove wall between current and next cell */
            maze[x + dx[d]][y + dy[d]] = 0;
            dfs(nx, ny);
        }
    }
}

static void print_maze(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf(maze[i][j] == 1 ? "#" : " ");
        }
        printf("\n");
    }
}

/* BFS-based maze solver */
static int solve_maze(Point start, Point end) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            visited[i][j] = 0;

    Queue q;
    queue_init(&q);

    visited[start.x][start.y] = 1;
    queue_push(&q, start);

    /* parent tracking for path reconstruction */
    Point parent[HEIGHT][WIDTH];

    while (!queue_empty(&q)) {
        Point current = queue_pop(&q);

        if (current.x == end.x && current.y == end.y) {
            /* Reconstruct path */
            Point path[HEIGHT * WIDTH];
            int path_len = 0;
            Point at = end;
            while (!(at.x == start.x && at.y == start.y)) {
                path[path_len++] = at;
                at = parent[at.x][at.y];
            }
            path[path_len++] = start;

            /* Mark path in maze with '.' */
            for (int i = 0; i < path_len; i++) {
                if (!(path[i].x == start.x && path[i].y == start.y) &&
                    !(path[i].x == end.x && path[i].y == end.y)) {
                    maze[path[i].x][path[i].y] = 2;
                }
            }
            return 1;
        }

        for (int d = 0; d < 4; d++) {
            int nx = current.x + dx[d];
            int ny = current.y + dy[d];
            if (is_valid(nx, ny) && maze[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                parent[nx][ny] = current;
                queue_push(&q, (Point){nx, ny});
            }
        }
    }
    return 0;
}

int main(void) {
    srand(time(NULL));

    Point start = {1, 1};
    Point end = {HEIGHT - 2, WIDTH - 2};

    initialize_maze();
    dfs(1, 1);
    maze[start.x][start.y] = 0;
    maze[end.x][end.y] = 0;

    printf("=== Generated Maze (DFS) ===\n");
    print_maze();

    if (solve_maze(start, end)) {
        printf("\n=== Solved Maze (BFS) ===\n");
        printf("# = wall, space = path, . = solution\n");
        print_maze();
        printf("\nPath found from start to end!\n");
    } else {
        printf("\nNo path found.\n");
    }

    return 0;
}
