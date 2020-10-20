#include <bits/stdc++.h>
using namespace std;

// Given arrival and departure timings, return the maximum number of guests you can meet2

// TC: O(nlogn)
// AS: O(n)
int getMaxGuests(int n, vector<int> arrival, vector<int> departure)
{
    vector<pair<int, int> > guests;
    for (int i = 0; i < n; ++i)
        guests.push_back(make_pair(arrival[i], departure[i]));
    sort(guests.begin(), guests.end());

    int maxguests = 1, curr = 1;
    for (int i = 1; i < n; ++i)
    {
        if (guests[i].first > guests[i - 1].second)
        {
            maxguests = max(maxguests, curr);
            curr = 1;
        }
        else
            curr += 1;
    }
    return maxguests;
}

// Optimised space
// TC: O(nlogn)
// AS: O(1)
int getMaxGuests1(int n, vector<int> arrival, vector<int> departure)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int maxguests = 1, curr = 1;
    int i = 1, j = 0;
    while (i < n && j < n - 1)
    {
        if (arrival[i] > departure[j])
            --curr, ++j;
        else
            ++curr, ++i;
        maxguests = max(maxguests, curr);
    }
    return maxguests;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arrival(n), departure(n);
    for (int i = 0; i < n; ++i)
        cin >> arrival[i];
    for (int i = 0; i < n; ++i)
        cin >> departure[i];
    int max_guests = getMaxGuests1(n, arrival, departure);
    cout << max_guests;
    return 0;
}
