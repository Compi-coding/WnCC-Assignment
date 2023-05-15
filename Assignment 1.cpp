#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int N; //N = Number of participants
    cin >> N;
    long long int rollNumber[N];
    long long int skills[N][5]; //Order HTML, python, DSA, Java, SQL

    for(int i=0; i<N; i++)
    {
        cin >> rollNumber[i];
        for(int j=0; j<5; j++)
        {
            cin >> skills[i][j];
        }
    }

    long long int M; //M=Number of projects
    cin >> M;

    char project_name[M];
    long long int skilllevel[M][5]; //Required

    for(int i=0; i<M; i++)
    {
        cin >> project_name[i];
        for(int j=0; j<5; j++)
        {
            cin >> skilllevel[i][j];
        }
    }

    int eligibility[N][M][5];

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            for(int k=0; k<5; k++)
            {
                if(skills[i][k] == skilllevel[j][k]) eligibility[i][j][k] == 1; //1 = Can be a part but not a mentor
                else if(skills[i][k] > skilllevel[j][k]) eligibility[i][j][k] == 2; // 2 = Can be a part and a mentor as well if needed
                else if(skills[i][k] + 1 == skilllevel[j][k]) eligibility[i][j][k] == 3; //3 = Can take part if he/she gets a mentor
                else eligibility[i][j][k] == 0;
            }
        }
    }

    /*After this, I wanted to find all the possible allotments of a project by considering all 1's initially and replacing them by 2's and 3's.
    Doing that for all the projects will give me sets of project allotment, And then, I can write a code to find all the possible disjoint sets and make an array which will store the cardinality each disjoint set.
    Then I can use binary search to find the maximum number of that set, Which will give me the optimal number of projects to be completed. (Not able to code that part but the algorithm is clear in my mind*/
}
