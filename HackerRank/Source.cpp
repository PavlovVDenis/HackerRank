//#include <bits/stdc++.h>
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<chrono>
#include<algorithm>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */
int diagonalDifference(vector<vector<int>> arr) {
    int sumMain = 0, size = arr.size() - 1;
    enum Diagonals { _MAIN = 0, _SLAVE };
     for (int variant = _MAIN; variant <= _SLAVE; variant++) {
        for (int i = 0; i < arr.size(); i++) {
            if (variant == _MAIN) { sumMain = sumMain + arr[i][i]; }
            else { sumMain = sumMain - arr[i][size - i]; };
        }
    }
    return abs(sumMain);
}

/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
void staircase(int n) {
    const string spaces100(101, ' '); // less 100 (from task)
    const string fill100(101, '#'); // less 100 (from task)
    for (int i = n; i > 0; i--) {
        cout << spaces100.substr(1, i-1) << fill100.substr(1, n-i+1) << endl;
    }
}

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
void miniMaxSum(vector<int> arr) {
    long long min = INT64_MAX;
    long long max = INT64_MIN;

    cout << "INT64_MIN=" << INT64_MIN << endl;
    cout << "INT64_MAX=" << INT64_MAX << endl;

    for (int i = 0; i < arr.size(); i++) {
        long long sum = 0;
        for (int k = 0; k < arr.size(); k++) {
            if (k != i) sum = sum + arr[k];
        }
        cout << "sum=" << sum << endl;
        if (sum > max)max = sum;
        if (sum < min)min = sum;
    }
    cout.setf(ios::fixed);
    cout.precision(0);
    cout << min << " " << max << endl;
}

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */
int birthdayCakeCandles(vector<int> candles) {
    int max = 0;
    for (int s : candles) if (s > max)max = s;
    int res = 0;
    for (int s : candles) if (s == max)res++;
    return res;
}

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s) {
    vector<string> timeParts;
    string temp = s;
    size_t found = temp.find(":");
    while (found != string::npos) {
        string sub = temp.substr(0, found);
        timeParts.push_back(sub);
        temp.erase(0, found + 1);
        found = temp.find(":");
    }
    if (!temp.empty()) {
        temp.pop_back();
        temp.pop_back();
        timeParts.push_back(temp);
    }

    bool isPM = s.find("PM") != string::npos;
    if (isPM && timeParts[0] != "12") {
        int hours = stoi(timeParts[0]);
        timeParts[0] = to_string(hours + 12);
    }
    if (timeParts[0] == "12" && !isPM) timeParts[0] = "00";
    
    string res = "";
    for (string s : timeParts) {
        res.append(s).append(":");
    }
    res.pop_back();

    return res;
}

/*
 * Complete the 'countApplesAndOranges' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER s
 *  2. INTEGER t
 *  3. INTEGER a
 *  4. INTEGER b
 *  5. INTEGER_ARRAY apples
 *  6. INTEGER_ARRAY oranges
 */
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int applesCount = 0;
    for (int ap : apples) if ((a + ap) >= s && (a + ap) <= t) applesCount++;
   
    int orangesCount = 0;
    for (int org : oranges) if ((b + org) >= s && (b + org) <= t) orangesCount++;

    cout << applesCount << " " << orangesCount << endl;
}

/*
 * Complete the 'kangaroo' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER x1
 *  2. INTEGER v1
 *  3. INTEGER x2
 *  4. INTEGER v2
 */
string kangaroo(int x1, int v1, int x2, int v2) {

    string res = "NO";

    if ((x1 > x2 && v1 >= v2)
        || (x2 > x1 && v2 >= v1)
        || (x1 == x2 && v1 != v2)) {
        return res;
    }
    else {
        int pos1 = x1;
        int pos2 = x2;
        for (int jump = 0; jump < 10000; jump++) {
            pos1 += v1;
            pos2 += v2;
            if (pos1 == pos2) {
                res = "YES";
                break;
            }
        }
    }

    return res;
}

/*
 * Complete the 'breakingRecords' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY scores as parameter.
 */
vector<int> breakingRecords(vector<int> scores) {
    vector<int> maxScore;
    vector<int> minScore;
    for (int i = 0; i < scores.size(); i++) {
        if (i == 0) {
            maxScore.push_back(scores[i]);
            minScore.push_back(scores[i]);
        }
        else {
            if (scores[i] > maxScore[i - 1]) maxScore.push_back(scores[i]);
                else maxScore.push_back(maxScore[i - 1]);
            
            if (scores[i] < minScore[i - 1]) minScore.push_back(scores[i]);
               else minScore.push_back(minScore[i - 1]);
        }
    }

    vector<int> res = { 0, 0 };

    for (int i = 0; (i + 1) < scores.size(); i++) {
        if (maxScore[i] != maxScore[i + 1]) res[0]++;
        if (minScore[i] != minScore[i + 1]) res[1]++;
    }
 
    return res;
}

/*
 * Complete the 'birthday' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY s
 *  2. INTEGER d
 *  3. INTEGER m
 */
int birthday(vector<int> s, int d, int m) {

    if (m == 1 && s.size() == 1) return (s[0] == d);

    int count{ 0 };

    for (int i{ 0 }; (i + m) <= s.size(); i++) {
        int sum{ 0 };
        int k{ i };
        for (k = i; k < (i + m); k++) sum +=s[k];
        if (sum == d) count++;
    }

    return count;
}

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */
int divisibleSumPairs(int n, int k, vector<int> ar) {

    int count{ 0 };
    for (int i{ 0 }; i <= ar.size(); i++) {
        for (int j = i + 1; (j + 1) <= ar.size(); j++) {
            
            cout << "i= " << i << ", k= " << k << ", " << ar[i] << " + " << ar[j] << " = " << (ar[i] + ar[j])
                << ", %" << k << " = " << ((ar[i] + ar[j]) % k) << endl;
          
            if ((ar[i] + ar[j]) % k == 0) count++;
        }
    }
    return count;
}

/*
 * Complete the 'migratoryBirds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
int migratoryBirds(vector<int> arr) {
    map<int, int> mp;
    for (int s : arr) {
        map<int, int>::iterator i_map = mp.find(s);
        if (i_map == mp.end()) {
            mp[s] = 1;
        }
        else {
            mp[s] = i_map->second++;
        }
    }

    int freq{ 0 };
    for (auto& i_map : mp) {
        if (i_map.second > freq) {
            freq = i_map.second;
        }
    }

    map<int, int> res;
    for (auto& i_map : mp) {
        if (i_map.second == freq) {
            res[i_map.first] = freq;
        }
    }

    return res.begin()->first;
}

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */
string dayOfProgrammer(int year) {
    bool isJulian = year >= 1700 && year <= 1917;
    bool isUp = year == 1918;
    bool isLeap = isJulian ? (year % 4 == 0) : (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));

    int days = 31 + (isLeap ? 29 : 28) + 31 + 30 + 31 + 30 + 31 + 31;
    int res = 256 - days + (isUp ? 13 : 0);

    return to_string(res) + ".09." + to_string(year);
}

/*
 * Complete the 'bonAppetit' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY bill
 *  2. INTEGER k
 *  3. INTEGER b
 */
void bonAppetit(vector<int> bill, int k, int b) {
    int sum{ 0 };
    for (int i{ 0 }; i < bill.size(); i++) {
        if (i != k) sum += bill[i];
    }
    float res = b - (sum / 2);
    if (res > 0) cout << res << endl;
    else cout << "Bon Appetit" << endl;
}

/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */
int sockMerchant(int n, vector<int> ar) {
    map<int, int> mp;
    for (auto& s : ar) {
        map<int, int>::iterator i_map = mp.find(s);
        if (i_map == mp.end()) mp.insert(make_pair(s, 1));
        else mp.insert(make_pair(s, i_map->second++));
    }
    int res{ 0 };
    for (auto& s : mp) {
        res = res + (s.second / 2);
    }
    return res;
}

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */
int pageCount(int n, int p) {

    if (p == 1 || p == n) return 0;

    int center = (n / 2);
    //cout << "Total " << center << " spreads of our book" << endl;
    //int centerSpread = center / 2;
    //cout << "Center spread is " << centerSpread << endl;
    int pageSpread = p / 2;
    //cout << "Page " << p << " in the " << pageSpread << " spread" << endl;
    //cout << "Forward flip is " << pageSpread << endl;
    //cout << "Backward flip is " << (center - pageSpread) << endl;

    //for (int i = 0; i <= center; i++) {
    //    cout << "Spread #" << i << ": ";
    //    if (i == 0) {
    //        cout << "1" << endl;
    //        continue;
    //    }
    //    if (i * 2 <= n) cout << (i * 2);
    //    if (((i * 2) + 1) <= n) cout << "   " << ((i * 2) + 1);
    //    cout << endl;
    //}

    return min(pageSpread, (center - pageSpread));
}

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */
int countingValleys(int steps, string path) {
    
    int currLevel = 0;
    int res = 0;
    bool startCount = false;

    for (int i = 0; i < path.size(); i++) {
        currLevel += (path[i] == 'D') ? -1 : 1;
        if (currLevel < 0) startCount = true;    
        if (startCount && currLevel == 0) {
            res++;
            startCount = false;
        }
    }
    return res;
}

/*
 * Complete the getMoneySpent function below.
 */
int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    return 0;
}

// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    int x_z = abs(x - z);
    int y_z = abs(y - z);
    if (x_z == y_z) return "Mouse C";
    if (x_z < y_z) return "Cat A";
    return "Cat B";
}

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
int pickingNumbers(vector<int> a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        vector<int> newArr;
        newArr.push_back(a[i]);
        
        for (int k = 0; k < a.size(); k++) {
            if (i == k) continue;
            bool add = true;
            for (int nA : newArr) {
                if (abs(nA - a[k]) > 1) {
                    add = false;
                    break;
                }
            }
            if (add) newArr.push_back(a[k]);
        }

        if (newArr.size() > res) res = newArr.size();
    }
    return res;
}

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<pair<int, int>> ranked_pair;
    int rank = 0;
    int prevRank = 0;
    for (auto& r : ranked) {
        if (r != prevRank) rank++;
        ranked_pair.push_back(make_pair(r, rank));
        prevRank = r;
    }
    int rankedSize = ranked_pair.size();

    vector<int> res;

    for (auto& p : player) {

        if (p > ranked_pair[0].first) {
            res.push_back(1);
            continue;
        }
        if (p < ranked_pair[rankedSize - 1].first) {
            res.push_back(ranked_pair[rankedSize - 1].second + 1);
            continue;
        }
        if (p == ranked_pair[rankedSize - 1].first) {
            res.push_back(ranked_pair[rankedSize - 1].second);
            continue;
        }

        bool gotcha = false;
        int lft = 0;
        int rgh = rankedSize - 1;
        int middle;
        while (lft <= rgh && gotcha != true) {
            middle = (lft + rgh) / 2;
            if (ranked_pair[middle].first > p && ranked_pair[middle + 1].first < p) { 
                gotcha = true; 
                res.push_back(ranked_pair[middle].second + 1);
            }
            if (ranked_pair[middle].first == p && ranked_pair[middle + 1].first < p) { 
                gotcha = true; 
                res.push_back(ranked_pair[middle].second);
            }
            if (ranked_pair[middle].first >= p) lft = middle + 1;
            else rgh = middle - 1;
        }
    }
    return res;
}

/*
 * Complete the 'hurdleRace' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY height
 */
int hurdleRace(int k, vector<int> height) {
    int maxUnits = k;
    for (auto& h : height) {
        if (h > maxUnits) maxUnits = h;
    }
    return maxUnits == k ? 0 : (maxUnits - k);
}

/*
 * Complete the 'designerPdfViewer' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h
 *  2. STRING word
 */
int designerPdfViewer(vector<int> h, string word) {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int wordSize = word.size();
    int maxHeight = 0;
    for (int i = 0; i < wordSize; i++) {
        int pos = alphabet.find(word[i]);
        if (h[pos] > maxHeight) maxHeight = h[pos];
    }
    return wordSize * maxHeight;
}

/*
 * Complete the 'angryProfessor' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY a
 */
string angryProfessor(int k, vector<int> a) {
    int countInTime = 0;
    for (auto& aa : a) {
        if (aa <= 0) countInTime++;
    }
    return countInTime < k ? "YES" : "NO";
}

/*
 * Complete the 'beautifulDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER i
 *  2. INTEGER j
 *  3. INTEGER k
 */
int beautifulDays(int i, int j, int k) {
    int res = 0;
    for (int num = i; num <= j; num++) {
        int number = num;
        int reverseNumber = 0;
        while (number != 0) {
            reverseNumber = (reverseNumber * 10) + (number % 10);
            number = number / 10;
        }
        if (abs(num - reverseNumber) % k == 0) res++;
    }
    return res;
}

/*
 * Complete the 'viralAdvertising' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */
int viralAdvertising(int n) {
    int res = 0;
    int shared = 5;
    for (int i = 1; i <= n; i++) {
        if (i != 1) 
            shared = (shared / 2) * 3;
        res += (shared / 2);
     }
    return res;
}

/*
 * Complete the 'saveThePrisoner' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER s
 */
int saveThePrisoner(int n, int m, int s) {
    
    // Only for debug {
    int prisoner = s;
    for (int i = 1; i <= m; i++) {
        if (i < m) prisoner++;
        if (prisoner > n) prisoner = 1;
    }
    cout << "Last prisoner is #" << prisoner << endl;
/*
    prisoner = (m % n + s) % n;
    prisoner--;
*/

    int i = n;
    int vib;
    int start = 0;
    int counter = 0;
    while (i > 1)
    {
        counter++;
        vib = (m % i + start) % i;
        if (!vib) vib = i;
        vib--;
        cout << "Out player " << vib << " on step " << counter << endl;
        //if (player[vib] == 1) break;
        start = vib;
        //player.erase(player.begin() + vib);
        i--;
    }
    cout << " new-new vib = " << vib << endl;

    if (prisoner < 0) prisoner = 1;
    cout << "(NEW) Last prisoner is #" << prisoner << endl;
    return prisoner;
}

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string superReducedString(string s) {
    // aaabccddd -> abccddd -> abddd -> abd
    string res(s);
    int i = 0;
    while ((i + 1) < res.size() && res.size() > 0) {
        if (res[i] == res[i + 1]) {
            res.erase(i, 2);
            i = 0;
        }
        else {
            i++;
        }
    }
    return res.empty() ? "Empty String" : res;
}

/*
 * Complete the 'camelcase' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int camelcase(string s) {
    int res = 1;
    for (int i = 0; i < s.size(); i++) {
        int charCode = (int)s[i];
        cout << s[i] << " - " << charCode << endl;
        if (65 <= charCode && charCode <= 90) res++;
    }
    return res;
}

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */
int minimumNumber(int n, string password) {

    vector<string> passwordRules = {
        "0123456789",
        "abcdefghijklmnopqrstuvwxyz",
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
        "!@#$%^&*()-+"
    };

    int res = 0;
    for (auto& pr : passwordRules) {
        bool passRule = false;
        for (int i = 0; i < password.size(); i++) {
            if (pr.find(password[i]) != string::npos) {
                passRule = true;
                break;
            }
        }
        if(!passRule) res++;
    }
    
    int delta = 6 - (n + res);
    if (delta > 0) res = res + delta;

    return res;
}

int main()
{
    string pas = "#HackerRank";
    cout << "For password [" << pas << "] need " << minimumNumber(pas.size(), pas) << " characters" << endl;
}
