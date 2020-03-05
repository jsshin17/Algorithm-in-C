#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

ifstream fi;
ofstream fo;

vector<pair<pair<int, int>, pair<int, int> > > tarps; // lowend_x, lowend_y, highend_x, highend_y

int n;
int l, r;
int p=987654321;

vector<pair<pair<int, int>, pair<int, int> > > tarps_new; // low_y, direction, x_Start, x_end

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    int op = a.first*b.second + b.first*c.second + c.first*a.second;
    op -= (a.second*b.first + b.second*c.first + c.second*a.first);
    if (op > 0)return 1;
    else if (op == 0)return 0;
    else return -1;
}

bool isIntersect(pair<pair<int, int>, pair<int, int> > x, pair<pair<int, int>, pair<int, int> > y) {
    pair<int, int> a = x.first;
    pair<int, int> b = x.second;
    pair<int, int> c = y.first;
    pair<int, int> d = y.second;
    int ab = ccw(a, b, c)*ccw(a, b, d);
    int cd = ccw(c, d, a)*ccw(c, d, b);
    if (ab == 0 && cd == 0) {
        if (a > b)swap(a, b);
        if (c > d)swap(c, d);
        return c <= b&&a <= d;
    }
    return ab <= 0 && cd <= 0;
}

bool cmp(pair<pair<int, int>, pair<int, int> > x, pair<pair<int, int>, pair<int, int> > y)
{
    return x.first.second<y.first.second;
}
void invalid()
{
    for(int i=0; i<n; i++)
    {
        if(tarps[i].first.second==tarps[i].second.second) // when the horizontal line is given as the input
        {fo<<"Invalid input : tarps is not slanted"<<endl;
            exit(0);
        }
        for(int j=i+1; j<n; j++)
        {
            if(isIntersect(tarps[i], tarps[j]))// when the tarps intersect
            {
                fo<<"Invalid input : tarps intersect"<<endl;
                exit(0);
            }
        }
    }
}

int main()
{
    fi.open("testInput.txt");
    fo.open("testOutput.txt");
    fi>>l>>r>>n;
    for(int i=0; i<n; i++)
    {
        int low_x, low_y, high_x, high_y;
        fi>>low_x>>low_y>>high_x>>high_y;
        tarps.push_back(make_pair(make_pair(low_x, low_y), make_pair(high_x, high_y)));
    }
    fo<<"Smallest no. of punctures required : ";
    invalid();
    sort(tarps.begin(), tarps.end(), cmp); //sort the tarps based on the low_y to get a foothold of searching from the bottom
    for(int i=0; i<n; i++) // save the starting point and end point of the line, direction and the low_end y coordinate to change the slanted tarp to the horizontalline.
    {
        int dir;
        if(tarps[i].first.first>tarps[i].second.first) dir=0;//direction : right
        else dir=1;//direction : left
        tarps_new.push_back(make_pair(make_pair(tarps[i].first.second, dir), make_pair(min(tarps[i].first.first, tarps[i].second.first), max(tarps[i].first.first, tarps[i].second.first))));
    }
    for(int i=0; i<=n; i++) //how many direction change?
    {
        for(int j=l; j<=r; j++) //vineyard start point to end point
        {
            int cur_p=0;
            int cur_x=j;
            int cur_n=i;
            for(int k=0; k<n; k++)//start from bottom
            {
                if(!(tarps_new[k].second.first<=cur_x && cur_x<=tarps_new[k].second.second)) continue;
                if(cur_n!=0)
                {

                }
                else
                {
                    cur_p++;
                }
            }
            if(cur_p<p) p=cur_p;
        }
    }
    
    fo<<p<<endl;
    
    fi.close();
    fo.close();
    return 0;
}
