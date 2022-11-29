
#include <bits/stdc++.h>
using namespace std;


vector<int> allocation(vector<vector<int>> vect, vector<vector<int>> proj, 
vector<int> capacity){
    
    int project_no = capacity.size();
    int students = vect.size();
    //cout << project_no << students;
    vector<int> matching(students, -1);
    vector<int> mfree(project_no);
    
    for(int i=0;i<project_no;i++){
        mfree[i]=capacity[i];
    }
    //return mfree;
    int freecount = students;
    vector<vector<int>> allocate_proj(project_no);
    // cout << allocate_proj.size();
    for(int i=0;i<project_no;i++){
        for(int j=0;j<capacity[i];j++){
            allocate_proj[i].push_back(-1);
        }
    }
    //return matching;
    
    while(freecount>0){
        int m;
        for(m=0;m<students;m++){
         if(matching[m]==-1)
            break;
        }
        for(int i=0;i<project_no&&matching[m]==-1;i++){
            int pro = vect[m][i];
            if(mfree[pro]>0){
                matching[m] = pro;
                mfree[pro]--;
                for(int i=0;i<allocate_proj[pro].size();i++){
                    if(allocate_proj[pro][i]==-1){
                      allocate_proj[pro][i]=m;
                      break;
                    } 
                }
                freecount--;
            }
            else{
                int flag=0;
                for(int i=0;i<capacity[pro];i++){
                    if(proj[pro][i]==m) flag=1;
                }
                if(flag==0) continue;
                for(int i=0;i<allocate_proj[pro].size();i++){
                    int w = allocate_proj[pro][i];
                    int flag1=0;
                    for(int i=0;i<capacity[pro];i++){
                    if(proj[pro][i]==w) flag1=1;
                    }
                    if(flag1==0){
                        allocate_proj[pro][i]=m;
                        matching[m]=pro;
                        matching[w]=-1;
                    }
                }
            }
        }
    }
    for(int i=0;i<allocate_proj.size();i++){
        for(int j=0;j<allocate_proj[i].size();j++){
            cout << allocate_proj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return matching;
}


int main()
{
    vector<vector<int>> vect(12, vector<int> (3));
    vect={
        {0, 2, 1},
        {0, 1, 2},
        {2, 1, 0},
        {1, 2, 0},
        {2, 1, 0},
        {0, 1, 2},
        {1, 0, 2},
        {1, 2, 0},
        {0, 2, 1},
        {0, 1, 2},
        {2, 1, 0},
        {2, 0, 1},
    };
    vector<int> capacity(3);
    capacity= {4, 4, 4};
    // cout << vect.size();
    // cout << capacity.size();
    vector<vector<int>> proj(3);
    proj = {
        {0, 9, 5, 1},
        {1, 2, 9, 0},
        {6, 7, 8, 9},
    };
   // cout << proj[0].size();
    vector<int> ans(vect.size());
    ans = allocation(vect, proj, capacity);
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    return 0;
}