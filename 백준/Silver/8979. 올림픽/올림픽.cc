#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct country
{
    int id;
    int gold;
    int silver;
    int bronze;
    int rank;
};

bool compare(country a, country b)
{
    if (a.gold == b.gold)
    {
        if (a.silver == b.silver)
        {
            return a.bronze > b.bronze;
        }
        else
        {
            return a.silver > b.silver;
        }
    }
    else
    {
        return a.gold > b.gold;
    }
}

int solve()
{

    int n, m;
    cin >> n >> m;
    vector<country> countrys;
    for (int i = 0; i < n; i++)
    {
        country input;
        int id;
        int gold;
        int silver;
        int bronze;
        cin >> id;
        cin >> gold;
        cin >> silver;
        cin >> bronze;
        input.id = id;
        input.gold = gold;
        input.silver = silver;
        input.bronze = bronze;
        countrys.push_back(input);
    }

    sort(countrys.begin(), countrys.end(), compare);

    int count1 = 0;
    int count2 = 0;
    for (int j = 0; j < n; j++)
    {
        

        count1++;
        count2++;

        if (j > 0 && (countrys[j].gold == countrys[j - 1].gold && countrys[j].bronze == countrys[j - 1].bronze && countrys[j].silver == countrys[j - 1].silver))
        {
            count1--;
        } else {
            count1 = count2;
        }

        if (countrys[j].id == m)
        {
            return count1;
        }

    }

    return -1;
}

int main()
{
    cout << solve();
}