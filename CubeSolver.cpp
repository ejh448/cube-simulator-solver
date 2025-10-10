#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>



using namespace std;

/*
 All Moves:
    face_rotation_right:         complete
    face_rotation_left:          complete
    right_column_rotation_up:    complete
    right_column_rotation_down:  complete
    left_column_rotation_up:     complete
    left_column_rotation_down:   complete
    top_row_rotation_right:      complete
    top_row_rotation_left:       complete
    bottom_row_rotation_right:   complete
    bottomn_row_rotation_left:   complete
    front_face_rotation_right:   complete
    front_face_rotation_left:    complete
    back_face_rotation_right:    complete
    back_face_rotation_left:     complete
*/

class Cube{
    public:
        const int LENGTH = 3;
        int front[3][3];
        int top[3][3];
        int bottom[3][3];
        int back[3][3];
        int left[3][3];
        int right[3][3];
    
    Cube()
    {
        fill_face(front,  1);
        fill_face(top,    2);
        fill_face(back,   3);
        fill_face(bottom, 4);
        fill_face(left,   5);
        fill_face(right,  6);
    }

    void rotate_right(int face[3][3])
    {
        int temp[3][3];

        for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                 temp[j][LENGTH - 1 - i] = face[i][j];
            }
        }

        for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                face[i][j] = temp[i][j];
            }
        }
    }

    void rotate_left(int face[3][3])
    {
        int temp[3][3];
        
        for (int i = 0; i < LENGTH; i++)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                temp[LENGTH - 1 - j][i] = face[i][j];
            }
        }

         for (int i = 0; i < LENGTH; i++)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                face[i][j] = temp[i][j];
            }
        }
    }

    void right_column_up_rotation()
    {
        int temp_front[3];
        int temp_top[3];
        int temp_back[3];
        int temp_bottom[3];
        //NEED TO ROTATE RIGHT SIDE
        //cout << "\n";
        
        //ASSUMES FROM FRONT FACE
        for (int i = 0; i < LENGTH; i++)
        {
            //gets all on right side
            temp_front[i] = front[i][2];    // -> top
            temp_top[i] = top[i][2];        // -> back
            temp_back[i] = back[i][2];      // -> bottom
            temp_bottom[i] = bottom[i][2];  // -> front
        }
        
        //moves all right columns up one face
        for (int i = 0; i < LENGTH; i++)
        {
            top[i][2] = temp_front[i];
            back[i][2] = temp_top[i]; 
            bottom[i][2] = temp_back[i];
            front[i][2] = temp_bottom[i];
        }

        //need to rotate the right side
        rotate_right(right);

        //cout << "\nfront:\n", print_face(front), cout << "\ntop:\n", print_face(top), cout << "\nback:\n", print_face(back), cout << "\nbottom:\n", print_face(bottom);

    }

    void right_column_down_rotation()
    {
        int temp_front[3];
        int temp_top[3];
        int temp_back[3];
        int temp_bottom[3];

        for (int i = 0; i < LENGTH; i++)
        {
            //gets all on right side
            temp_front[i] = front[i][2];   // -> bottom
            temp_top[i] = top[i][2];       // -> front
            temp_back[i] = back[i][2];     // -> top
            temp_bottom[i] = bottom[i][2]; // -> back
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[i][2] = temp_back[i];
            back[i][2] = temp_bottom[i]; 
            bottom[i][2] = temp_front[i];
            front[i][2] = temp_top[i];
        }

        rotate_left(right);

        //cout << "\nfront:\n", print_face(front), cout << "\ntop:\n", print_face(top), cout << "\nback:\n", print_face(back), cout << "\nbottom:\n", print_face(bottom);


    }

    void left_column_up_rotation()
    {
        int temp_front[3];
        int temp_top[3];
        int temp_back[3];
        int temp_bottom[3];
        
        //cout << "\n";
        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[i][0];    // -> top
            temp_top[i] = top[i][0];        // -> back
            temp_back[i] = back[i][0];      // -> bottom
            temp_bottom[i] = bottom[i][0];  // -> front
        }

        //moves all right columns up one face
        for (int i = 0; i < LENGTH; i++)
        {
            top[i][0] = temp_front[i];
            back[i][0] = temp_top[i]; 
            bottom[i][0] = temp_back[i];
            front[i][0] = temp_bottom[i];
        }

        //need to rotate the right side
        rotate_left(left);
        //cout << "\nfront:\n", print_face(front), cout << "\ntop:\n", print_face(top), cout << "\nback:\n", print_face(back), cout << "\nbottom:\n", print_face(bottom);
    }

    void left_column_down_rotation()
    {
        int temp_front[3];
        int temp_top[3];
        int temp_back[3];
        int temp_bottom[3];

        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[i][0];    // -> bottom
            temp_top[i] = top[i][0];        // -> front
            temp_back[i] = back[i][0];      // -> top
            temp_bottom[i] = bottom[i][0];  // -> back
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[i][0] = temp_back[i];
            back[i][0] = temp_bottom[i]; 
            bottom[i][0] = temp_front[i];
            front[i][0] = temp_top[i];
        }
        
        rotate_right(left);
        
       // cout << "\nfront:\n", print_face(front), cout << "\ntop:\n", print_face(top), cout << "\nback:\n", print_face(back), cout << "\nbottom:\n", print_face(bottom);

    }

    void top_row_right_rotation()
    {
        int temp_front[3];
        int temp_left[3];
        int temp_right[3];
        int temp_back[3];

        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[0][i];    // -> left
            temp_left[i] = left[0][i];      // -> back
            temp_back[i] = back[0][i];      // -> right
            temp_right[i] = right[0][i];    // -> front
        }

        for (int i = 0; i < LENGTH; i++)
        {
            front[0][i] = temp_right[i];
            left[0][i] = temp_front[i]; 
            back[0][i] = temp_left[i];
            right[0][i] = temp_back[i];
        }
        
        rotate_right(top);
        
        //cout << "\nfront:\n", print_face(front), cout << "\nleft:\n", print_face(left), cout << "\nback:\n", print_face(back), cout << "\nright:\n", print_face(right);
    }

    void top_row_left_rotation()
    {
        int temp_front[3];
        int temp_left[3];
        int temp_right[3];
        int temp_back[3];

        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[0][i];    // -> right
            temp_left[i] = left[0][i];      // -> front
            temp_back[i] = back[0][i];      // -> left
            temp_right[i] = right[0][i];    // -> back
        }

        for (int i = 0; i < LENGTH; i++)
        {
            front[0][i] = temp_left[i];
            left[0][i] = temp_back[i]; 
            back[0][i] = temp_right[i];
            right[0][i] = temp_front[i];
        }
        
        rotate_left(top);
        
        //cout << "\nfront:\n", print_face(front), cout << "\nleft:\n", print_face(left), cout << "\nback:\n", print_face(back), cout << "\nright:\n", print_face(right);
    }

    void bottom_row_left_rotation()
    {
        int temp_front[3];
        int temp_left[3];
        int temp_right[3];
        int temp_back[3];

        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[2][i];    // -> right
            temp_left[i] = left[2][i];      // -> front
            temp_back[i] = back[2][i];      // -> left
            temp_right[i] = right[2][i];    // -> back
        }

            
        for (int i = 0; i < LENGTH; i++) {
            front[2][i] = temp_right[i];
            left[2][i]  = temp_front[i];
            back[2][i]  = temp_left[i];
            right[2][i] = temp_back[i];
        }

        rotate_right(bottom);
        
        //cout << "\nfront:\n", print_face(front), cout << "\nleft:\n", print_face(left), cout << "\nback:\n", print_face(back), cout << "\nright:\n", print_face(right);
    }

    void bottom_row_right_rotation()
    {
        int temp_front[3];
        int temp_left[3];
        int temp_right[3];
        int temp_back[3];

        for (int i = 0; i < LENGTH; i++)
        {
            temp_front[i] = front[2][i];    // -> right
            temp_left[i] = left[2][i];      // -> front
            temp_back[i] = back[2][i];      // -> left
            temp_right[i] = right[2][i];    // -> back
        }

        for (int i = 0; i < LENGTH; i++) {
            front[2][i] = temp_left[i];
            left[2][i]  = temp_back[i];
            back[2][i]  = temp_right[i];
            right[2][i] = temp_front[i];
        }
        
        rotate_left(bottom);
        
        //cout << "\nfront:\n", print_face(front), cout << "\nleft:\n", print_face(left), cout << "\nback:\n", print_face(back), cout << "\nright:\n", print_face(right);
    }

    void front_face_right_rotation()
    {
        int temp_top[3];
        int temp_left[3];
        int temp_right[3];
        int temp_bottom[3];

        //rotate the front face right first
        rotate_right(front);

        //then we nee to get the bottom row on the top
        //the left column on the right side
        //the top row on the bottom
        //the right column on the left side
        for (int i = 0; i < LENGTH; i++)
        {
             temp_top[i] = top[2][i];       // need to get the bottom row of the top face
             temp_right[i] = right[i][0];   // need to get the left column of the right face
             temp_bottom[i] = bottom[0][i]; // need to get the top row of the bottom face
             temp_left[i] = left[i][2];     // need to get the right column of the left face
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[2][i] = temp_left[i];
            right[i][0] = temp_top[i];
            bottom[0][i] = temp_right[i];
            left[i][2] = temp_bottom[i];
        }
    }

    void front_face_left_rotation()
    {
        int temp_top[3];
        int temp_left[3];
        int temp_right[3];
        int temp_bottom[3];

        //rotate the front face left first
        rotate_left(front);

        for (int i = 0; i < LENGTH; i++)
        {
             temp_top[i] = top[2][i];       // need to get the bottom row of the top face
             temp_right[i] = right[i][0];   // need to get the left column of the right face
             temp_bottom[i] = bottom[0][i]; // need to get the top row of the bottom face
             temp_left[i] = left[i][2];     // need to get the right column of the left face
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[2][i] = temp_right[i]; //top needs to become the temp_right
            right[i][0] = temp_bottom[i]; //right needs to become temp_bottom
            bottom[0][i] = temp_left[i]; //bottom needs to become temp_left
            left[i][2] = temp_top[i]; //left needs to become temp_top
        }

    }

    void back_face_right_rotation()
    {
        int temp_top[3];
        int temp_left[3];
        int temp_right[3];
        int temp_bottom[3];

        //rotate the back face right first
        rotate_right(back);

        for (int i = 0; i < LENGTH; i++)
        {
             temp_top[i] = top[0][i];         //need to get top row on top face
             temp_right[i] = right[i][2];     //need to get right column on the right face
             temp_bottom[i] = bottom[2][i];   //need to get the bottom row on the bottom face
             temp_left[i] = left[i][0];       //need to get left column on the left face     
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[0][i] = temp_right[LENGTH - 1 - i];
            right[i][2] = temp_bottom[i];
            bottom[2][i] = temp_left[LENGTH - 1 - i];
            left[i][0] = temp_top[i];
        }
    }
    
    void back_face_left_rotation()
    {
        int temp_top[3];
        int temp_left[3];
        int temp_right[3];
        int temp_bottom[3];

        rotate_left(back);

        for (int i = 0; i < LENGTH; i++)
        {
            temp_top[i] = top[0][i];
            temp_right[i] = right[i][2];
            temp_bottom[i] = bottom[2][i];
            temp_left[i] = left[i][0];
        }

        for (int i = 0; i < LENGTH; i++)
        {
            top[0][i] = temp_left[i];
            right[i][2] = temp_top[LENGTH - 1 - i];
            bottom[2][i] = temp_right[i];
            left[i][0] = temp_bottom[LENGTH - 1 - i];
        }
    }

    void fill_face(int face[3][3], int value)
    {
        for(int i = 0; i < LENGTH; i++)
        {
            for(int j = 0; j < LENGTH; j++)
            {
                face[i][j] = value;
            }
        }
    }

    void print_face(int face[3][3])
    {
         for(int i = 0; i < LENGTH; i++)
        {
            cout << "\n";
            for(int j = 0; j < LENGTH; j++)
            {
                cout << face[i][j];
            }
        }
        cout << "\n";
    }

    bool check_face(int face[3][3])
    {
        int check = face[1][1]; //middle block
        //cout << "check :" << check << "\n";
        for (int i = 0; i < LENGTH; i++)
        {
             for (int j = 0; j < LENGTH; j++)
            {
                if (face[i][j] != check)
                {
                    //cout << "\nFALSE\n";
                    return false;
                }
            }
        }
        //cout << "\nTRUE\n";
        return true;
    }

    bool check_cross(int face[3][3])
    {
        int check = face[1][1]; //middle block
        if (face[0][1] == check && face[1][0] == check && face[2][1] == check && face[1][2] == check)
        {
            return true;
        }
        return false;
    }

    void manual_insert_faces()
    {
        int answer;
        for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter front face: " << i << ":" << j << "\n";
                cin >> answer;
                front[i][j] = answer;
            }
        }
        //check_face(front);

        for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter left face: " << i << ":" << j << "\n";
                cin >> answer;
                left[i][j] = answer;
            }
        }

        for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter back face: " << i << ":" << j << "\n";
                cin >> answer;
                back[i][j] = answer;
            }
        }

         for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter right face: " << i << ":" << j << "\n";
                cin >> answer;
                right[i][j] = answer;
            }
        }

         for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter top face: " << i << ":" << j << "\n";
                cin >> answer;
                top[i][j] = answer;
            }
        }

         for (int i = 0; i < LENGTH; i++)
        {
            for (int j = 0; j < LENGTH; j++)
            {
                cout << "Please Enter bottom face: " << i << ":" << j << "\n";
                cin >> answer;
                bottom[i][j] = answer;
            }
        }
        cout << "\nfront:\n", print_face(front), cout << "\ntop:\n", print_face(top), cout << "\nback:\n", print_face(back), cout << "\nbottom:\n", print_face(bottom), cout << "\nleft:\n", print_face(left), cout << "\right:\n", print_face(right);
    }

    void solve_cross()
    {
        bool solved = false;
        random_device random_seed;
        mt19937 gen(random_seed());
        uniform_int_distribution<> dis(1, 12);
        
        int safety = 0;

        while (!solved)
        {
            int move = dis(gen);

            switch (move) {
                case 1: top_row_left_rotation(); break;
                case 2: top_row_right_rotation(); break;
                case 3: bottom_row_left_rotation(); break;
                case 4: bottom_row_right_rotation(); break;
                case 5: right_column_down_rotation(); break;
                case 6: right_column_up_rotation(); break;
                case 7: left_column_up_rotation(); break;
                case 8: left_column_down_rotation(); break;
                case 9: front_face_right_rotation(); break;
                case 10: front_face_left_rotation(); break;
                case 11: back_face_left_rotation(); break;
                case 12: back_face_right_rotation(); break;
            }

            safety++;

            solved = check_cross(front);
    }

    if (solved)
    {
        cout << "Cross solved\n";
        print_cube_net();
        cout << "SAFETY: " << safety << "\n";
    }
    else
    {
        cout << "TOO MANY MOVES...\n";
    }

}


    bool solve_edges()
    {
        return ((right[1][0] == right[1][1]) &&
                (bottom[0][1] == bottom[1][1]) &&
                (left[1][2] == left[1][1]) &&
                (top[2][1] == top[1][1]));
    }

    bool set_corners()
    {
        //possibly need to check for the edges?
        bool solved = false;
        while (!solved)
        {
            right_column_down_rotation();
            bottom_row_left_rotation();
            right_column_up_rotation();
            bottom_row_right_rotation();
            solved = (right[0][0] == right[1][1] && right[2][0] == right[1][1]) &&
                (left[0][2] == left[1][1] && left[2][2] == left[1][1]) &&
                (top[2][0] == top[1][1] && top[2][2] == top[1][1]) &&
                (bottom[0][0] == bottom[1][1] && bottom[0][2] == bottom [1][1]);
        }
        return true;
    }

    void print_cube_net()
    {
        auto print_row = [&](int face[3][3], int row) {
            for (int j = 0; j < LENGTH; j++)
                cout << face[row][j] << " ";
        };

        cout << "\nCUBE STATE (Net Layout):\n\n";

        // Top face
        for (int i = 0; i < LENGTH; i++) {
            cout << "      ";      // indentation to center top
            print_row(top, i);
            cout << "\n";
        }

        // Left, Front, Right, Back faces
        for (int i = 0; i < LENGTH; i++) {
            print_row(left, i); cout << "  ";
            print_row(front, i); cout << "  ";
            print_row(right, i); cout << "  ";
            print_row(back, i);
            cout << "\n";
        }

        // Bottom face
        for (int i = 0; i < LENGTH; i++) {
            cout << "      ";
            print_row(bottom, i);
            cout << "\n";
        }

        cout << "\n";
    }

};



    
int main()
{
    Cube cube;
    // Front
    cube.front[0][0]=1; cube.front[0][1]=1; cube.front[0][2]=2;
    cube.front[1][0]=2; cube.front[1][1]=1; cube.front[1][2]=3;
    cube.front[2][0]=2; cube.front[2][1]=4; cube.front[2][2]=5;

    // Back
    cube.back[0][0]=6; cube.back[0][1]=3; cube.back[0][2]=4;
    cube.back[1][0]=6; cube.back[1][1]=5; cube.back[1][2]=6;
    cube.back[2][0]=4; cube.back[2][1]=5; cube.back[2][2]=4;

    // Left
    cube.left[0][0]=1; cube.left[0][1]=4; cube.left[0][2]=3;
    cube.left[1][0]=5; cube.left[1][1]=3; cube.left[1][2]=1;
    cube.left[2][0]=1; cube.left[2][1]=1; cube.left[2][2]=6;

    // Right
    cube.right[0][0]=5; cube.right[0][1]=5; cube.right[0][2]=1;
    cube.right[1][0]=5; cube.right[1][1]=6; cube.right[1][2]=2;
    cube.right[2][0]=3; cube.right[2][1]=3; cube.right[2][2]=5;

    // Top
    cube.top[0][0]=3; cube.top[0][1]=1; cube.top[0][2]=2;
    cube.top[1][0]=3; cube.top[1][1]=2; cube.top[1][2]=2;
    cube.top[2][0]=2; cube.top[2][1]=4; cube.top[2][2]=3;

    // Bottom
    cube.bottom[0][0]=5; cube.bottom[0][1]=6; cube.bottom[0][2]=4;
    cube.bottom[1][0]=6; cube.bottom[1][1]=4; cube.bottom[1][2]=2;
    cube.bottom[2][0]=6; cube.bottom[2][1]=4; cube.bottom[2][2]=6;

    cube.solve_cross();

    return 0;
}


