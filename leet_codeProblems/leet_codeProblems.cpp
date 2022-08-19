#include <iostream>
#include<vector>
#include<numeric>
#include<string>
using namespace std;


class NumArray {

public:

    vector<int> pf;

    void numarray()
    {
        vector<int> nums = { -2, 0, 3, -5, 2, -1 };
        pf.clear();
        pf.push_back(nums[0]);

        for (int i = 1, j = i - 1;i < nums.size();i++,j++) 
            pf.push_back(nums[i] + pf[j]);
        
        cout << sumRange(0, 5);
       
        
    }

    int sumRange(int is, int js)
    {
        int r = is - 1;
        return is > 0 ? pf[js]-pf[r] : pf[js];
        
    }


};


void titleToNumber()
{
    string t = "FXSHRXW";
    int k = 1, val = 0, p;

    for (int i = t.size() - 1, p = 0;i >= 0;i--)
    {
        if (k)
        {
            k = 0;
            val += t[i] - 64;
        }
        else
        {
            p++;
            val += pow(26,p) * (t[i] - 64) ;
        }
    }

    cout<<val;


}


void substringIndex()
{
    string s = "mississippi", a = "issip";

    int i, j, k,idx,f=0;

    for (i = 0,k=0;i < s.size();i++)
    {
        if (s.size() < a.size())
            break;
        else if (s[i] == a[k])
        {
            idx = i;
            j = i + 1;
            k++;

            while (j < s.size() && k < a.size())
            {
                if (s[j] != a[k])
                {
                    k = 0;
                    break;
                }
                else
                {
                    j++;
                    k++;
                }
            }
            if (a[k] == NULL)
            {
                cout << "Is a substring -> starting index -> "<<idx;
                f = 1;
                break;
            }
        }
    }
    if(f!=1)
    cout << "not a substring";
}



void validParenthesis()
{
    string s = "{}[](";

    vector<int> sv ;
    char last;
    int i;

    for ( i = 0;i < s.size();i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            sv.push_back(s[i]);
        else
        {
            if (sv.empty())
                cout << "false break at empty if part ";
            else
            {
                last = sv[sv.size() - 1];
                sv.pop_back();
                if ( ! (s[i]==']' && last=='[' || s[i] == ')' && last == '('|| s[i] == '}' && last == '{') )
                {
                    cout << "not valid string";
                    break;
                }


            }
        }
    }
    if (s[i] == NULL && sv.empty())
        cout << "valid string";
    else
        cout << "invalid at last";


}


void longestPrefix()
{
    vector<string> s = { "dog","racecar","car" };
    string target = s[0];


    for (int j = 1;j < s.size();j++)
    {
        for (int i = 0;i < target.size()-1;i++)
        {
            if (target[i]!=s[j][i])
            {
                target.resize(i);
                break;
            }
        }
        if (target.empty())
            break;;
    }
    cout << target;

}



void negation_i()
{
    int A[10] = {1,2,0,4,-1,10};
    for (int i=0;A[i];i++)
    cout << i<<" "<<A[i]<<endl;

    for (int i = 0;A[i];i++)
    cout << i << " " << A[i] << endl;

}



void romanToInt() {
    string S = "MCMXCIV";
    int ans = 0, num = 0;
    for (int i = S.size() - 1; ~i; i--) {
        switch (S[i]) {
        case 'I': num = 1; break;
        case 'V': num = 5; break;
        case 'X': num = 10; break;
        case 'L': num = 50; break;
        case 'C': num = 100; break;
        case 'D': num = 500; break;
        case 'M': num = 1000; break;
        }
        if (4 * num < ans) ans -= num;
        else ans += num;

    }
    cout<< ans;
}

void isCovered()
{
    vector<vector<int>> rs ={{1,10},{10,20}};
    int l=21, r=21, c1=0,c2=1,i,f=0;

    // column count -> ranges[0].size()
    // row count -> ranges.size()

    for (i = 0;i < rs.size();i++)
    {
        if ((l >= rs[i][c1] && l <= rs[i][c2]) || (r >= rs[i][c1] && l <= rs[i][c2]))
        {
            cout << "true";
            f = 1;
            break;
        }
    }
    if (f != 1)
        cout << "false";




}


void MinValueSumStepSum()
{
    vector<int> nums = { 2,3,5,-5,-1 };
    int pfs = nums[0],mins=INT_MAX;
    
    for (int i = 0;i < nums.size();i++)
    {
        if (i != 0)
            pfs += nums[i];
        if (mins > pfs)
            mins = pfs;
    }
    int x= (mins > 0)?1: abs(mins) +1 ;
    cout << x;

}


void sumOddSubArray()
{
    vector<int> arr = { 10,11,12 };
    vector<int> pfsum(arr.size());
    int j,sum,r;
    pfsum[0] = arr[0];
    for (int i = 1;i < arr.size();i++)
    {
        j = i - 1;
        pfsum[i] = pfsum[j] + arr[i];
    }
    sum = pfsum[arr.size()-1];

    for (int i = 0;i < arr.size();i++)
    {
        j = i + 2;
        r = i - 1;
        while (j < arr.size())
        {
            i > 0 ? sum += pfsum[j] - pfsum[r] : sum += pfsum[j];
            j += 2;
        }

    }

    cout << sum;


}

void runningsum2()
{
    vector<int>nums = { 2,3,-1,8,4 };

        vector<int>left(nums.size());
        vector<int>right(nums.size());

        int sum = 0;

        //finding sum of left side upto each index
        for (int i = 0;i < nums.size();i++) {
            left[i] = sum;
            sum += nums[i];
        }
        sum = 0;

        //similarly finding sum of right side upto each index
        for (int i = nums.size() - 1;i >= 0;i--) {
            right[i] = sum;
            sum += nums[i];
        }

        int ans = -1;

        // checking at which index both
        // left[i]==right[i]
        // if not found any left[i]==right[i]
        // than ans=-1 will return.

        for (int i = 0;i < nums.size();i++) {
            if (left[i] == right[i]) {
                ans = i;
                break;       //use break if (left[i]==right[i]) then come out from loop
            }
        }
        cout<<ans;
    }


void runningSum()
{
    int A[5] = { 1,1,1,1,1 },j;
    //partial_sum(A, A + 5, A);

    vector<int> B = {2,3,-1,8,4},p(B.size()), s(B.size());
    //partial_sum(B.begin(), B.begin()+5, B); wrong method with vector

    vector<int>::iterator i;
    vector<int>::reverse_iterator ir;
    
    i = p.begin()+1;
    ir = s.rbegin() + 1;
    partial_sum(B.begin(), B.begin()+B.size()-1, i);
    partial_sum(B.rbegin(), B.rbegin() + B.size()-1,ir);
    

    cout << "prefix" << endl;
    for (auto x : p)
        cout << x<<endl;
    cout << "suffix" << endl;
    for (auto x : s)
        cout << x << endl;


}

void pivotIndex1()
{
    vector<int> A = { 1,7,3,6,5,6 };

    int sum = 0, rsum, lsum = 0;

    sum = accumulate(A.begin(), A.end(), 0);
    
    
    rsum = sum;
    for (int i = 0;i < A.size();i++)
    {
        rsum = rsum - A[i];
        if (rsum == lsum)
        {
            cout << i;
            break;
        }

        lsum += A[i];
    }

}


void pivotIndex()
{

    vector<int> A = { 1,7,3,6,5,6 };

    int sum = 0,rsum,lsum=0;

    for (int i = 0;i < A.size();i++)
        sum += A[i];
    //cout << sum;
    rsum = sum;
    for (int i = 0;i < A.size();i++)
    {
        rsum = rsum - A[i];
        if (rsum == lsum)
        {
            cout << i;
            break;
        }

        lsum += A[i];
    }

}

int main()
{
    //pivotIndex();
    //pivotIndex1();
    //runningSum();
    
    //sumOddSubArray();

    
    /*NumArray a;
    a.numarray();*/

    //MinValueSumStepSum();


    //isCovered();

    //romanToInt();

    //negation_i();

    //longestPrefix();

    //validParenthesis();

    //substringIndex();


    titleToNumber();


}
