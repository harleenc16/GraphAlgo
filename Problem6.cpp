//This code is submitted by Harleen Chaudhary
#include <iostream>
#include<queue>
#include<fstream>
#include<sstream>
#include <vector>
using namespace std; 

vector<string> mat;

vector<vector<int>> visited;


int xVal[4] = {1, -1 , 0 , 0};
int yVal[4] = {0 , 0 , 1 , -1};

bool isValid(int x , int y , int n)
{
    if (x >= 0 && x < n && y >= 0 && y < n  && (mat[x][y] == '1') && (visited[x][y] == 0) )
        return true;

    return false;
}


//performing bfs 
int bfs(int n)
{
    
    queue<pair<pair<int , int> , int>> que;

    que.push({{0, 0} , 1});
    visited[0][0] = 1;

    while (!que.empty())
    {
        pair<pair<int , int> , int> front = que.front();

        if ( (front.first.first == n - 1)  && (front.first.second == n - 1) )
        {
            return front.second;
        }

        que.pop();

       
        for (int i = 0 ; i < 4 ; i++)
        {
            int x = front.first.first + xVal[i];
            int y = front.first.second + yVal[i];

            int dist = front.second + 1;

            if (isValid(x , y , n))
            {
                que.push({{x, y} , dist});
                visited[x][y] = 1;
            }

        }
    }
    return 0;
}


int main(){

    fstream input;
    input.open("maze.txt" , ios::in);

    if (input.fail())
    {
      cout << "0"<<endl;
        return 0;
    }


    while (input.eof() == false)
    {
        string l;
        input >> l;
        mat.push_back(l);
    }

    int n  = mat.size();

    visited.assign(n , vector<int>(n , 0));

    int distance = bfs(n);

    cout  << distance << '\n';


    return 0;
}

