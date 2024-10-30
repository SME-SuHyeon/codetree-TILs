#include <iostream>
using namespace std;

int  m, n, t, current_time;
int attack_x, attack_y;
int target_x, target_y;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int queueX[10005], queueY[1005], top, bottom;
void enqueX(int a)
{
    queueX[top] = a;
}
void enqueY(int a)
{
    queueY[top++] = a;
}
int dequeX()
{
    return queueX[bottom];
}
int dequeY()
{
    return queueY[bottom++];
}

struct M
{
    int str;
    int attack_time;
};
M map[30][30];
struct R
{
    int x;
    int y;
};
R route[30][30];
int relation[30][30];

void get()
{
    current_time = 0;
    cin >> n >> m >> t;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            cin >> map[x][y].str;
            map[x][y].attack_time = 0;
        }
}
void find_weak()
{
    int t_x = -1, t_y = -1, t_str = 50000, attack_time = -1;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[x][y].str != 0)//안 부서진 포탑만
            {
                if (map[x][y].str < t_str)//더 약한것
                {
                    t_x = x;
                    t_y = y;
                    t_str = map[x][y].str;
                    attack_time = map[x][y].attack_time;
                }
                else if (map[x][y].str == t_str)//힘이 같다면
                {
                    if (map[x][y].attack_time > attack_time)//공격을 가장 최근에 한 것
                    {
                        t_x = x;
                        t_y = y;
                        t_str = map[x][y].str;
                        attack_time = map[x][y].attack_time;
                    }
                    else if (attack_time == map[x][y].attack_time) // 시간도 같다면
                    {
                        if (x + y > t_x + t_y)//행열 합이 큰것
                        {
                            t_x = x;
                            t_y = y;
                            t_str = map[x][y].str;
                            attack_time = map[x][y].attack_time;
                        }
                        else if (x + y == t_x + t_y && x > t_x)//그 조차 같다면 열 값이 제일 큰 것
                        {
                            t_x = x;
                            t_y = y;
                            t_str = map[x][y].str;
                            attack_time = map[x][y].attack_time;
                        }
                    }
                }
            }
        }
    }
    map[t_x][t_y].attack_time = current_time;//이번에 공격하는 포탑
    attack_x = t_x;
    attack_y = t_y;
}
void find_target()
{
    int t_x = 100, t_y = 100, t_str = 0, attack_time = 100000;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (map[x][y].str != 0)//안 부서진 포탑만
            {
                if (map[x][y].str > t_str)//더 강한것
                {
                    t_x = x;
                    t_y = y;
                    t_str = map[x][y].str;
                    attack_time = map[x][y].attack_time;
                }
                else if (map[x][y].str == t_str)//힘이 같다면
                {
                    if (map[x][y].attack_time < attack_time)//공격을 가장 예전에 한 것
                    {
                        t_x = x;
                        t_y = y;
                        t_str = map[x][y].str;
                        attack_time = map[x][y].attack_time;
                    }
                    else if (attack_time == map[x][y].attack_time) // 시간도 같다면
                    {
                        if (x + y < t_x + t_y)//행열 합이 작은 것
                        {
                            t_x = x;
                            t_y = y;
                            t_str = map[x][y].str;
                            attack_time = map[x][y].attack_time;
                        }
                        else if (x + y == t_x + t_y && x < t_x)//그 조차 같다면 열 값이 제일 작은 것
                        {
                            t_x = x;
                            t_y = y;
                            t_str = map[x][y].str;
                            attack_time = map[x][y].attack_time;
                        }
                    }
                }
            }
        }
    }
    target_x = t_x;
    target_y = t_y;
}
int new_razor_attack()
{
    for(int y=0;y<n;y++)
        for (int x = 0; x < m; x++)
        {
            route[x][y].x = -1;
            route[x][y].y = -1;
        }
    top = bottom = 0;
    enqueX(attack_x);
    enqueY(attack_y);
    int found = 0;
    while (top != bottom&&found == 0)
    {
        int x = dequeX();
        int y = dequeY();

        for (int i = 0; i < 4; i++)
        {
            int nx = (x + dx[i] + m) % m;
            int ny = (y + dy[i] + n) % n;

            if (map[nx][ny].str != 0 && route[nx][ny].x == -1)
            {
                route[nx][ny].x = x;
                route[nx][ny].y = y;

                enqueX(nx);
                enqueY(ny);
                if (nx == target_x && ny == target_y)
                {
                    found = 1;
                    break;
                }
            }
        }
    }
    int x, y,nx,ny;
    if (found == 1)
    {
        nx = route[target_x][target_y].x;
        ny = route[target_x][target_y].y;
        while (not(nx == attack_x && ny == attack_y))
        {
            x = nx;
            y = ny;
            relation[x][y] = 1;
            map[x][y].str -= map[attack_x][attack_y].str / 2;

            if (map[x][y].str < 0)
                map[x][y].str = 0;

            nx = route[x][y].x;
            ny = route[x][y].y;
        }
        map[target_x][target_y].str -= map[attack_x][attack_y].str;
        if (map[target_x][target_y].str < 0)
            map[target_x][target_y].str = 0;
        return 1;
    }
    else
        return 0;
}
void bullet_attack()
{
    int b_dx[8] = { -1,0,1,1,1,0,-1,-1 };
    int b_dy[8] = { -1,-1,-1,0,1,1,1,0 };

    for (int i = 0; i < 8; i++)
    {
        int nx = target_x + b_dx[i];
        int ny = target_y + b_dy[i];

        nx += m;
        nx %= m;

        ny += n;
        ny %= n;

        if (not(nx == attack_x && ny == attack_y))
        {
            relation[nx][ny] = 1;

            if (map[nx][ny].str > 0)
                map[nx][ny].str -= map[attack_x][attack_y].str / 2;
            if (map[nx][ny].str < 0)
                map[nx][ny].str = 0;
        }
    }
    map[target_x][target_y].str -= map[attack_x][attack_y].str;
    if (map[target_x][target_y].str < 0)
        map[target_x][target_y].str = 0;
}
void ready_for_next()
{
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (map[x][y].str != 0 && relation[x][y] == 0)
                map[x][y].str++;
            relation[x][y] = 0;
        }
}
int check()
{
    int cnt = 0;
    for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            if (map[x][y].str != 0)
                cnt++;
        }
    return cnt;
}
int one_turn()
{
    find_weak();
    find_target();
    relation[attack_x][attack_y] = 1;
    relation[target_x][target_y] = 1;
    map[attack_x][attack_y].str += m + n;

    if (new_razor_attack() == 0)
    {
        bullet_attack();
    }
    ready_for_next();

    if (check() == 1)
        return 1;
    return 0;
}

int main()
{
    get();
    if (check() == 1)
    {
        find_target();
        printf("%d", map[target_x][target_y].str);
        return 0;
    }
    for (int i = 0; i < t; i++)
    {
        current_time++;
        if (one_turn() == 1)
            break;
    }

    find_target();
    printf("%d", map[target_x][target_y].str);
    return 0;
}