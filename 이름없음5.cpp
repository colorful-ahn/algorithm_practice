#include <iostream>

using namespace std;

 

const int MAX = 1000000000;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        long long X, Y;

        cin >> X >> Y;

 

        int Z = (Y * 100) / X;

        //È®·üÀÌ ¹Ù²ð ¼ö ¾ø´Â °æ¿ì

        if (Z >= 99)

        {

                 cout << -1 << "\n";

                 return 0;

        }

       

        int low = 0, high = MAX;

        int result = -1;

        while (low <= high)

        {

                 int mid = (low + high) / 2;

                 //ÀÌºÐÅ½»ö °á°ú È®·ü

                 int tempZ = (100 * (Y + mid)) / (X + mid);

                 if (Z >= tempZ)

                 {

                         result = mid + 1;

                         low = mid + 1;

                 }

                 else

                         high = mid - 1;

        }

        cout << result << "\n";

        return 0;

}







