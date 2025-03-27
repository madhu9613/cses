/*You are given a playlist of a radio station since its establishment. The playlist has a total of n songs.
What is the longest sequence of successive songs where each song is unique?*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
 
    vector<int> songs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> songs[i];
    }
 
    unordered_set<int> uniqe(n);
    int left = 0, right = 0;
    int maxlength = 0;
    for (right = 0; right < n; right++)
    {
 
        // if the song we are going to add is already exist then ofcourse it will be at beginning as its how the algo is
        while (uniqe.count(songs[right]))
 
        {
            uniqe.insert(songs[right]);
 
            uniqe.erase(songs[left]);
 
            left++;
        }
 
        // i add the element;
        uniqe.insert(songs[right]);
        maxlength = max(maxlength, right - left + 1);
    }
 
    cout<<maxlength;
 
    return 0;
}