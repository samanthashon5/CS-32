
bool pathExists(char maze[][10], int sr, int sc, int er, int ec)
{
    if(maze[sr][sc] == maze [er][ec])
    {
        return true;
    }

    maze[sr][sc] = '#';


    if(maze[sr - 1][sc] == '.')
    {
        if(pathExists(maze, sr - 1, sc, er, ec))
        {
            return true;
        }
    }

    if(maze[sr + 1][sc] == '.')
    {
        if(pathExists(maze, sr + 1, sc, er, ec))
        {
            return true;
        }
    }

    if(maze[sr][sc - 1] == '.')
    {
        if(pathExists(maze, sr, sc - 1, er, ec))
        {
            return true;
        }
    }

    if(maze[sr][sc + 1] == '.')
    {
        if(pathExists(maze, sr, sc + 1, er, ec))
        {
            return true;
        }
    }
    return false;
}
