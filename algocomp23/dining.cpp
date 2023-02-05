#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(priority_queue<pair<int, int> > coders, int middle_food_id, int type, int new_food_id)
{
    int index;
    if (type == 1)
    {
        index = 
        index = coders.index(min(coders))
        removed = coders[index]
        coders[index] = middle_food_id
        middle_food_id = new_food_id
        print(removed, index+1)
    }
    else
    {

    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    priority_queue<pair<int, int> > coders;
    int n, m, middle_food_id, food_id, i, type, new_food_id;;
    cin >> n >> m >> middle_food_id;

    for ( i = 1; i <= n; i++)
    {
        cin >> food_id;
        coders.push(make_pair(food_id, i))
    }
    for ( i = 0; i < m; i++)
    {
        cin >> type >> new_food_id;
        solve(coders, middle_food_id, type, new_food_id);
    }
    return 0;
}