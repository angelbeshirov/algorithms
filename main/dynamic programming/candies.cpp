#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    vector<int> results(n, 0);

    results[0] = 1;
    results[n - 1] = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i - 1]) {
            results[i] = results[i - 1] + 1;
        } else if(i < n - 1 && arr[i] <= arr[i + 1]) {
            results[i] = 1; // arr[i] <= arr[i - 1]
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] > arr[i + 1] && arr[i] <= arr[i - 1]) {
            results[i] = results[i + 1] + 1;
        } else if(i > 0 && arr[i] <= arr[i - 1]) {
            results[i] = 1; // arr[i] <= arr[i - 1]
        }
    }

    long sum = 0;
    for(int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
        sum += results[i];
    }


    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
