#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'maximumProfit' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY price as parameter.
 */
/*
선택할 수 있는 가짓수는 2가지이다. 일부를 팔거나, 아니면 1주를 사거나.
제일 비싼거 앞의 녀석들은 뭐어차피 다 사고 비쌀 때 파는게 맞다. 가격이 동일한 게 있어도 상관없다. 제일 마지막에 있는 비싼 녀석을 기준으로 한다.
그렇다면 그 이후는? 남아있는 것들 중에 그렇게 또 하면 된다. 그리디한 방식이다.
마지막엔 결국 하나가 남거나 다 끝날것이다. 하나가 남으면? 무시하면 된다. 결국 그때 팔아도 손해인 녀석이다.
시간복잡도는? 50만개의 순서를 알아야한다. priority_queue를 통해 logn으로 찾아내자.(만드는 건 n의 시간 소요)\
뺄 때를 위해 부분합도 만들어두자.
*/
long maximumProfit(vector<int> price) {
long sum[500000];
long answer=0;
priority_queue<pair<int,int>>q;
sum[0]=price[0];
for(int i=0;i<price.size();i++)
{if(i>0){sum[i]=sum[i-1]+price[i];}
q.push(make_pair(price[i],i));}
int lastselledindex=-1;
while(1)
{
int nowprice=q.top().first;
int nowindex=q.top().second;
q.pop();
if(nowindex>lastselledindex)
{
answer+=nowprice*(nowindex-lastselledindex-1);
answer-=(sum[nowindex-1]-sum[lastselledindex]);
lastselledindex=nowindex;}
if(lastselledindex==price.size()-1)break;
}
return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string price_temp_temp;
        getline(cin, price_temp_temp);

        vector<string> price_temp = split(rtrim(price_temp_temp));

        vector<int> price(n);

        for (int i = 0; i < n; i++) {
            int price_item = stoi(price_temp[i]);

            price[i] = price_item;
        }

        long profit = maximumProfit(price);

        fout << profit << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
