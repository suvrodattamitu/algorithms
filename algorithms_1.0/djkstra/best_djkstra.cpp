//https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/description/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rep0(i,n) for(ll i = 0; i < n; i++)
#define rep1(i,n) for(ll i = 1; i <= n; i++)
#define rrep0(i, n) for(ll i = n-1; i >= 0; i--)
#define rrep1(i, n) for(ll i = n; i >= 0; i--)
#define all(a) (a.begin()), (a.end())
#define memo(a) memset(a, -1, sizeof(a));
#define put(n) (cout << n << endl)
#define get(n) (cin >> n)
#define len(x) ((ll)x.size()) 
#define pb push_back
const ll MOD = 1000000007;
const long long oo = 1e16;
const ll MX = (1LL<<60);
const int LOG = 60;
const ll N = 1e5+10;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        ll startX = start[0] , startY = start[1];
        ll targetX = target[0] , targetY = target[1];
        if(startX == targetX && startY == targetY) return 0;

        priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq; //{CostToReachXY, X, Y}
        pq.push({0, startX, startY});

        map<pair<ll, ll>, ll> cost; /* {{X:CoOrdinate,Y:CoOrdinate}, minCostToXY} */
        cost[{startX, startY}] = 0; /* Starting Co-Ordinstes : Initially 0 */
        cost[{targetX, targetY}] = oo; /* Target Co-ordinates : Initially Unreachable */

        while(!pq.empty()) {
            auto [currCost, currX, currY] = pq.top();
            pq.pop();

            /* If Reached Target */
            if(currX == targetX && currY == targetY) return currCost;

            /* Directly to target */
            if(cost[{targetX, targetY}] > currCost + abs(currX - targetX) + abs(currY - targetY)) {
                /* Total Cost = Current Cost + |X1-X2| + |Y1-Y2| */
                cost[{targetX,targetY}] = currCost + abs(currX - targetX) + abs(currY - targetY);
                pq.push({cost[{targetX, targetY}], targetX, targetY}); 
            }

            /* Via Special Road */
            for(auto road : specialRoads){ 
                /* Total Cost = Current Cost + Cost To Reach Special Road + Cost To Cross The Special Road */
                int toReachCost = currCost + abs(currX - road[0]) + abs(currY - road[1]) + road[4];
                if(cost.find({road[2], road[3]}) == cost.end() || cost[{road[2], road[3]}] > toReachCost) {
                    cost[{road[2], road[3]}] = toReachCost;
                    pq.push({toReachCost, road[2], road[3]});
                }
            }
        }

        return -1;
    }
};