/*
both cases passed without UF, by just decrement count on merging adjacent triangles
[" /","/ "], [" /","  "]
Counting Logic: In your code, you're decrementing the count after merging adjacent cells. However, if you're maintaining the count, you don't need to perform the union operation. Instead, you should count the number of distinct roots after the unions are performed.

counting doesnt work because, one triangle is merged twice with the same block. once from the top and once from the left.

["/\\","\\/"]
expected: 5. actual op: 4



two approaches:
1. do union find and count the no of unique parents
2. keep count of parents. if union merged, decr count. if already union'd, ignore.

*/
class Solution {
public:
    void cleanStr(string & s){
        int i = 0, j = 0;
        cout << "clean str " << s << ". len:" << s.length() << endl;
        while (i < s.length()){
            s[j] = s[i];
            if(s[i] == '\\'){ 
                i++;
            }
            j++;
            i++;
        }
        // terminate the string
        s[j] = '\0';
        cout << "after clean str " << s << ". len:" << s.length() << endl;
    }
    int id(int r, int c, int q){
        // 1000 wont cut it for quadrant. go for higher number.
        // max value for row is 30. 30 * 100 = 3000. 
        // [20][0]1st quadrant has same value as [0][0] 3rd quadrant
        // 20 * 100 + 0 + 1 * 1000 = 3000 = 0 * 100 + 0 + 3 * 1000
        return r * 100 + c + q * 100000; 
    }

    int ufind(map<int, int> & parent, int a) {
        int x = a;

        while(a != parent[a]){
            a = parent[a];
        }

        parent[x] = a;

        return a;
    }

    bool unionf(map<int, int> &parent, map<int, int> &rank, int a, int b ){
        int pA = ufind(parent, a);
        int pB = ufind(parent, b);

        if(pA == pB){
            return false;
        }

        if(rank[pA] > rank[pB]){
            parent[pB] = pA;
            rank[pA] += rank[pB];
        } else {
            parent[pA] = pB;
            rank[pB] += rank[pA];
        }

        return true;
    } 

    int regionsBySlashes(vector<string>& grid) {
        map<int, int> parent;
        map<int, int> rank;
        // if you are maintaining the count, why union? if already union'd, ignore
        // keep this count in class variable so that unionf function can maintain it
        int count = 0;

        for (int i = 0 ; i < grid.size(); i++){
            string s = grid[i];
            cout << "\"" << s << "\"" << s.length()<< endl;
            // this isnt a raw literal. escape characters are considered as one single character.
           // cleanStr(s);
            for(int j = 0; j < s.length(); j++){
                // if(s[j] == '\') j++;
                parent[id(i,j,1)] = id(i, j, 1);
                rank[id(i, j, 1)] = 1;
                parent[id(i,j,2)] = id(i, j, 2);
                rank[id(i, j, 2)] = 1;
                parent[id(i,j,3)] = id(i, j, 3);
                rank[id(i, j, 3)] = 1;
                parent[id(i,j,4)] = id(i, j, 4);
                rank[id(i, j, 4)] = 1;
                count += 4;
                cout << "adding a cell "<<s[j] << "," << count << "," << i << ":" << j << endl;

                if(s[j] == '/'){
                    bool merged = unionf(parent, rank, id(i, j, 1), id(i, j, 2));
                    // if (merged)
                        count--;
                    merged = unionf(parent, rank, id(i, j, 3), id(i, j, 4));
                    // if (merged)
                        count--;
                    cout << "merging fwd slash"<< count << endl;
                } else if(s[j] == '\\'){
                    bool merged =unionf(parent, rank, id(i, j, 1), id(i, j, 4));
                    // if (merged)
                        count--;
                    merged =unionf(parent, rank, id(i, j, 2), id(i, j, 3));
                    // if (merged)
                        count--;
                    cout << "merging back slash"<< count << endl;
                } else if(s[j] == ' '){
                    bool merged = unionf(parent, rank, id(i, j, 1), id(i, j, 2));
                    // if (merged)
                        count--;
                    merged = unionf(parent, rank, id(i, j, 3), id(i, j, 4));
                    // if (merged)
                        count--;
                    merged = unionf(parent, rank, id(i, j, 1), id(i, j, 3));
                    // if (merged)
                        count--;
                    // merged = unionf(parent, rank, id(i, j, 1), id(i, j, 3));
                    cout << "merging all"<< count << endl;
                }

                // dont have to check what slash is present in previous cells. they are adjacent anyway
                if (i - 1 >= 0 ){
                    bool merged = unionf(parent, rank, id(i, j, 4), id(i-1, j, 2));
                    // if (merged)
                        count--;
                    cout << "merging prev row"<< count << endl;
                }
                if (j - 1 >= 0) {
                    bool merged  = unionf(parent, rank, id(i, j, 3), id(i, j-1, 1));
                    // need to check only when merging with adjacent cells
                    if (merged)
                        count--;
                    cout << "merging prev col"<< count << endl;
                }
        }
    }
    // you could also count the no of unique parents after union'ing
    return count;
    }
};