// name: 임형근
// student ID: 20201261
// description: calculates the shortest path of a knight from a given position in the chess board to another

#include <iostream>

#define ABS(a) ((a)>0 ? (a) : -(a))

bool pathfind(const int board_size, const int *start_pos, const int *end_pos, int *path, size_t *path_len, size_t depth=1, int *explored_path=nullptr) {
    if((start_pos[0] == end_pos[0]) && (start_pos[1] == end_pos[1])) {
        if((*path_len == 0) || (depth < *path_len)) {
            *path_len = depth;
            path[depth-1] = board_size * start_pos[1] + start_pos[0];
            return true;
        }
        return false;
    }
    if(depth > 20) {
        return false;
    }
    if(*path_len != 0) {
        if(ABS(end_pos[0]-start_pos[0]) > 2*(ABS(*path_len-depth)-1)) {
            return false;
        }
        if(ABS(end_pos[1]-start_pos[1]) > 2*(ABS(*path_len-depth)-1)) {
            return false;
        }
        if(depth >= *path_len) {
            return false;
        }
    }

    bool is_move_valid[8];
    const int move_lr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    const int move_ud[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int explored_path_material[20];
    if(explored_path == nullptr) {
        explored_path = explored_path_material;
    }
    for(size_t i=depth-1; i<20; i++) {
        explored_path[i] = -1;
    }

    for(size_t i=0; i<8; i++) {
        is_move_valid[i] = true;
        const int next_pos[2] = {start_pos[0]+move_lr[i], start_pos[1]+move_ud[i]};

        for(size_t j=0; explored_path[j]!=-1 && j<20; j++) {
            if(board_size * next_pos[1] + next_pos[0] == explored_path[j]) {
                is_move_valid[i] = false;
                break;
            }
        }
        if((next_pos[0] < 0) || (next_pos[0] >= board_size)) {
            is_move_valid[i] = false;
        }
        else if((next_pos[1] < 0) || (next_pos[1] >= board_size)) {
            is_move_valid[i] = false;
        }
    }

    explored_path[depth-1] = board_size * start_pos[1] + start_pos[0];
    bool is_there_any_path = false;
    for(size_t i=0; i<8; i++) {
        if(is_move_valid[i]) {
            const int next_pos[2] = {start_pos[0]+move_lr[i], start_pos[1]+move_ud[i]};
            is_there_any_path = is_there_any_path || pathfind(board_size, next_pos, end_pos, path, path_len, depth+1, explored_path);
        }
    }
    if(is_there_any_path) {
        path[depth-1] = board_size * start_pos[1] + start_pos[0];
    }
    return is_there_any_path;
}

int main() {
    using namespace std;

    int board_size;
    int start_pos[2];
    int end_pos[2];

    cout << "Size of board: " << flush;
    cin >> board_size;
    cout << "Start position: " << flush;
    for(size_t i=0; i<2; i++) {
        cin >> start_pos[i];
    }
    cout << "End position: " << flush;
    for(size_t i=0; i<2; i++) {
        cin >> end_pos[i];
    }

    int path[21];
    size_t path_len = 0;

    const bool is_there_path = pathfind(board_size, start_pos, end_pos, path, &path_len);
    if(is_there_path) {
        cout << "Can be done in " << path_len-1 << " moves" << endl;
        for(size_t i=0; i<path_len; i++) {
            const int x = path[i] % board_size;
            const int y = (int)(path[i] / board_size);
            cout << "(" << x << ", " << y << ')';
            if(i != path_len-1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } 
    else {
        cout << "The knight cannot move there" << endl;
    }

    return 0;
}